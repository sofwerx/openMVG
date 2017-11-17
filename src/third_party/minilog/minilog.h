#ifndef MINILOG_H
#define MINILOG_H

#include <sstream>

#define USE_MINILOG

#if defined(USE_MINILOG)
#	define MLOG minilog::inst()
#else
#	define MLOG std::cout
#endif

class minilog_mutex_interface
{
public:
	minilog_mutex_interface()
	{
	}

	virtual ~minilog_mutex_interface()
	{
	}

	virtual void lock() = 0;
	virtual void unlock() = 0;
};

class minilog
{
public:
	minilog();

	~minilog();

	void set_locker(minilog_mutex_interface *pLocker);

	template<typename T>
	minilog &operator << (const T &t)
	{
		if(pLocker_ != NULL)
			pLocker_->lock();

		buf_ << t;

		if(pLocker_ != NULL)
			pLocker_->unlock();

		return *this;
	}
	minilog & operator << (std::ostream& (*F)(std::ostream&))
	{
		F(buf_);
		return *this;
	}

	std::string getbuf();

	static minilog &inst() { return inst_; }

private:
	std::ostringstream buf_;
	minilog_mutex_interface *pLocker_;

	static minilog inst_;
};

#endif
