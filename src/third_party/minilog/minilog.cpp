#include "minilog.h"

minilog minilog::inst_;

minilog::minilog() : pLocker_(NULL)
{
}

minilog::~minilog()
{
}

void minilog::set_locker(minilog_mutex_interface *pLocker)
{
	pLocker_ = pLocker;
}

std::string minilog::getbuf()
{
	std::string bufstr;
	if(pLocker_ != NULL)
		pLocker_->lock();

	bufstr = buf_.str();
	buf_.str("");

	if(pLocker_ != NULL)
		pLocker_->unlock();

	return bufstr;
}

