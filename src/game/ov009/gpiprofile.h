#ifndef GAME_OV009_GPIPROFILE_H
#define GAME_OV009_GPIPROFILE_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of gpiprofile.c, prototypes copied from their definitions. */

#include "../ov009/gpi_types.h"

int gpiProfilesTableHash(void *elem, int numBuckets);
int gpiProfilesTableCompare(void *a, void *b);
void gpiProfilesTableFree(void * arg);
int gpiInitProfiles(void ** connection);
int gpiProcessNewProfile(void **connection, GPIOperation *operation, char *input);
GPIProfile *gpiProfileListAdd(void **connection, int id);
int gpiGetProfile(void ** connection, int profileid, GPIProfile ** pProfile);
int gpiProcessDeleteProfle(void **connection, GPIOperation *operation, char *input);
void gpiRemoveProfileByID(void ** connection, int profileid);
void gpiRemoveProfile(void ** connection, GPIProfile * profile);
int gpiCheckProfileForUser(void * unused, GPIProfile * profile, void * udata);
int gpiFindProfileByUser(void ** connection, char * nick, char * email, GPIProfile ** profile);
int gpiProfileMapCallback(void *elem, void *mapDataArg);
int gpiProfileMap(void ** connection, int (*func)(void *, GPIProfile *, void *), void * data);
int gpiCheckForBuddy(void * unused, GPIProfile * profile, void * udata);
GPIProfile *gpiFindBuddy(void ** connection, int blockIndex);
void gpiRemoveBuddyStatus(GPIBuddyStatus * buddyStatus);
void gpiRemoveBuddyStatusInfo(GPIBuddyStatusInfo * buddyStatusInfo);
int gpiCanFreeProfile(GPIProfile *p);
int gpiProcessRecvBlockedList(void **connection, char *input);
/* END mkheaders: generated region */

#endif
