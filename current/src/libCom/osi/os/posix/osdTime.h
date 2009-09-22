/*************************************************************************\
* Copyright (c) 2002 The University of Chicago, as Operator of Argonne
*     National Laboratory.
* Copyright (c) 2002 The Regents of the University of California, as
*     Operator of Los Alamos National Laboratory.
* EPICS BASE Versions 3.13.7
* and higher are distributed subject to a Software License Agreement found
* in file LICENSE that is included with this distribution. 
\*************************************************************************/

/*
 * osdTime.h,v 1.8.2.1 2004/01/30 01:25:16 jhill Exp
 *
 * Author: Jeff Hill
 */

#ifndef osdTimeh
#define osdTimeh

#include <unistd.h>

#ifndef _POSIX_TIMERS
	struct timespec {
		time_t tv_sec; /* seconds since some epoch */
		long tv_nsec; /* nanoseconds within the second */
	};
#endif /* ifndef _POSIX_TIMERS */

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

epicsShareFunc void epicsShareAPI
    convertDoubleToWakeTime(double timeout,struct timespec *wakeTime);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* ifndef osdTimeh */

