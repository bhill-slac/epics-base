/*************************************************************************\
* Copyright (c) 2002 The University of Chicago, as Operator of Argonne
*     National Laboratory.
* Copyright (c) 2002 The Regents of the University of California, as
*     Operator of Los Alamos National Laboratory.
* EPICS BASE Versions 3.13.7
* and higher are distributed subject to a Software License Agreement found
* in file LICENSE that is included with this distribution. 
\*************************************************************************/
/* iocClock.h for RTEMS */

/* Author:  Marty Kraimer Date:  16JUN2000 */
/* Modified:   Sheng Peng Date:  08OCT2006 */

#include "epicsTime.h"

#ifndef iocClockh
#define iocClockh

#ifdef __cplusplus
extern "C" {
#endif

typedef int (*pepicsTimeGetCurrent)(epicsTimeStamp *pDest);
typedef int (*pepicsTimeGetEvent)(epicsTimeStamp *pDest,int eventNumber);

void iocClockInit(void);
void iocClockRegister(pepicsTimeGetCurrent getCurrent,pepicsTimeGetEvent getEvent);

int systemTimeGetCurrent(epicsTimeStamp *pDest);
int systemTimeGetEvent(epicsTimeStamp *pDest, int eventNumber);

#ifdef __cplusplus
}
#endif

#endif /* ifndef iocClockh */