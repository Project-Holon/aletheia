/*
 * file:     gpiprofile.c
 * unit:     yes
 * function: gpiProfilesTableHash, gpiProfilesTableCompare, gpiProfilesTableFree, gpiInitProfiles, gpiProcessNewProfile, gpiProfileListAdd, gpiGetProfile, gpiProcessDeleteProfle, gpiRemoveProfileByID, gpiRemoveProfile, gpiCheckProfileForUser, gpiFindProfileByUser, gpiProfileMapCallback, gpiProfileMap, gpiCheckForBuddy, gpiFindBuddy, gpiRemoveBuddyStatus, gpiRemoveBuddyStatusInfo, gpiCanFreeProfile, gpiProcessRecvBlockedList
 * address:  0x0218F9F8
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   gsifree                          0x0217EAE0 arm
 *   ArrayFree                        0x021841B0 arm
 *   gpiFreeInfoCache                 0x0218D71C arm
 *   TableNew                         0x02184610 arm
 *   gpiProfilesTableHash             0x0218F9F8 arm
 *   gpiCheckForError  0x0219329c  arm   ov009
 *   strncmp  0x020949f4  arm
 *   gpiSetError  0x02193710  arm   ov009
 *   gpiCallErrorCallback  0x02189d78  arm   ov009
 *   gpiValueForKey  0x02193418  arm   ov009
 *   atoi  0x020964e0  arm
 *   gsimalloc  0x0217eab0  arm   ov009
 *   gpiSetErrorString  0x02193734  arm   ov009
 *   gpiAddCallback  0x02189dfc  arm   ov009
 *   gpiRemoveOperation  0x0218e240  arm   ov009
 *   gGpiProfileResponsePr     0x021a51d0  data
 *   gGpiProfileErrorUnexpectedData     0x021a51d8  data
 *   gGpiProfileKeyProfileId     0x021a5208  data
 *   gGpiProfileErrorOutOfMemory     0x021a5214  data
 *   gpiGetProfile  0x0218FD9C  arm  ov009
 *   TableEnter  0x0218474C  arm  ov009
 *   TableLookup                      0x0218482C arm
 *   gGpiProfileResponseDpr     0x021a5224  data
 *   TableRemove                      0x021847BC arm
 *   TableRemove  0x021847BC  arm
 *   strcmp                           0x020948E0 arm
 *   TableMapSafe2                    0x021848E4 arm
 *   gpiProfileMapCallback            0x0218FFE0 arm
 *   gpiCheckForBlock                 0x0219003C arm
 *   gpiValueForKeyWithIndex  0x02193378  arm  ov009
 *   strstr  0x02094B20  arm
 *   gpiBuddyDeletedLocally  0x02189300  arm  ov009
 *   gGpiProfileKeyBlk     0x021A522C  data
 *   gGpiProfileKeyList     0x021A5234  data
 *   gGpiProfileComma     0x021A523C  data
 */
#include "gpi_types.h"

extern void gsifree(void * ptr);
extern void ArrayFree(void * array);
extern void gpiFreeInfoCache(GPIProfile * profile);
extern void * TableNew(int elemSize, int nBuckets, int (*hashFn)(void *, int), int (*compFn)(void *, void *), void (*freeFn)(void *));
extern int gpiCheckForError(int *connection, const char *input, int fatal);
extern int strncmp(const u8 *s1, const u8 *s2, unsigned int n);
extern void gpiSetError(int *connection, int result, int errorString);
extern int gpiCallErrorCallback(int *connection, int a1, int a2);
extern int gpiValueForKey(const char *command, const char *key, char *value, int valueLen);
extern int atoi(const char *s);
extern void *gsimalloc(unsigned long size);
extern void gpiSetErrorString(int *p, int b);
extern int gpiAddCallback(void **connection, GPICallback callback, void *arg, GPIOperation *operation, int type);
extern void gpiRemoveOperation(void **connection, GPIOperation *operation);
extern int gpiGetProfile(void **connection, int profileid, GPIProfile **pProfile);
extern void TableEnter(void *table, void *newElem);
extern void * TableLookup(void * table, void * elemKey);
extern int TableRemove(void * table, void * delElem);
extern int strcmp(const char * a, const char * b);
extern void * TableMapSafe2(void * table, int (*cb)(void *, void *), void * udata);
extern int gpiCheckForBlock(void * unused, GPIProfile * profile, void * udata);
extern int gpiValueForKeyWithIndex(char *command, char *key, int *index, char *value, int len);
extern char *strstr(const char *s1, const char *s2);
extern int gpiBuddyDeletedLocally(void **connection, int id, int isDeleted);
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
void gpiProfileMapCallback(int a, int *p);
int gpiProfileMap(void ** connection, int (*func)(void *, GPIProfile *, void *), void * data);
int gpiCheckForBuddy(void * unused, GPIProfile * profile, void * udata);
GPIProfile * gpiFindBuddy(void ** connection, int blockIndex);
void gpiRemoveBuddyStatus(GPIBuddyStatus * buddyStatus);
void gpiRemoveBuddyStatusInfo(GPIBuddyStatusInfo * buddyStatusInfo);
int gpiCanFreeProfile(char *p);
int gpiProcessRecvBlockedList(void **connection, char *input);
extern char gGpiProfileResponsePr[];
extern char gGpiProfileErrorUnexpectedData[];
extern char gGpiProfileKeyProfileId[];
extern char gGpiProfileErrorOutOfMemory[];
extern char gGpiProfileResponseDpr[];
extern char gGpiProfileKeyBlk[];
extern char gGpiProfileKeyList[];
extern char gGpiProfileComma[];







/*
 * Hash table callback: bucket index of a profile, its id modulo the bucket count.
 */
int gpiProfilesTableHash(void *elem, int numBuckets)
{
    return *(int *)elem % numBuckets;
}






int gpiProfilesTableCompare(void *a, void *b)
{
	return *(int *)a - *(int *)b;
}







void gpiProfilesTableFree(void * arg)
{
	GPIProfile * profile = (GPIProfile *)arg;

	if (profile->buddyStatus != 0)
	{
		gsifree(profile->buddyStatus->statusString);
		profile->buddyStatus->statusString = 0;
		gsifree(profile->buddyStatus->locationString);
		profile->buddyStatus->locationString = 0;
		gsifree(profile->buddyStatus);
		profile->buddyStatus = 0;
	}
	if (profile->buddyStatusInfo != 0)
	{
		gsifree(profile->buddyStatusInfo->richStatus);
		profile->buddyStatusInfo->richStatus = 0;
		gsifree(profile->buddyStatusInfo->gameType);
		profile->buddyStatusInfo->gameType = 0;
		gsifree(profile->buddyStatusInfo->gameVariant);
		profile->buddyStatusInfo->gameVariant = 0;
		gsifree(profile->buddyStatusInfo->gameMapName);
		profile->buddyStatusInfo->gameMapName = 0;
		if (profile->buddyStatusInfo->extendedInfoKeys != 0)
		{
			ArrayFree(profile->buddyStatusInfo->extendedInfoKeys);
			profile->buddyStatusInfo->extendedInfoKeys = 0;
		}
		gsifree(profile->buddyStatusInfo);
		profile->buddyStatusInfo = 0;
	}
	gpiFreeInfoCache(profile);
	gsifree(profile->authSig);
	profile->authSig = 0;
	gsifree(profile->peerSig);
	profile->peerSig = 0;
}







int gpiInitProfiles(void ** connection)
{
	GPIConnection * iconnection = (GPIConnection *)*connection;
	int result = 0;

	iconnection->profileList.numBuddies = 0;
	iconnection->profileList.numBlocked = 0;
	iconnection->profileList.num = 0;
	iconnection->profileList.profileTable = TableNew(0x30, 0x20, gpiProfilesTableHash, gpiProfilesTableCompare, gpiProfilesTableFree);
	if (iconnection->profileList.profileTable != 0)
		result = 1;
	return result;
}







/*
 * sdk:      gpiProcessNewProfile (libdwcgsgp.TWL.HYB.a gpiprofile.o)
 */
int gpiProcessNewProfile(void **connection, GPIOperation *operation, char *input)
{
    char buffer[16];
    int pid;
    GPICallback callback;
    GPNewProfileResponseArg *arg;
    int __result__;

    if (gpiCheckForError((int *)connection, input, 1))
        return 4;
    if (strncmp((const u8 *)input, (const u8 *)gGpiProfileResponsePr, 5) != 0) {
        gpiSetError((int *)connection, 1, (int)gGpiProfileErrorUnexpectedData);
        __result__ = 3;
        gpiCallErrorCallback((int *)connection, __result__, 1);
        return __result__;
    }
    if (!gpiValueForKey(input, gGpiProfileKeyProfileId, buffer, 16)) {
        gpiSetError((int *)connection, 1, (int)gGpiProfileErrorUnexpectedData);
        __result__ = 3;
        gpiCallErrorCallback((int *)connection, __result__, 1);
        return __result__;
    }
    pid = atoi(buffer);
    callback = operation->callback;
    if (callback.callback != 0) {
        arg = (GPNewProfileResponseArg *)gsimalloc(sizeof(GPNewProfileResponseArg));
        if (arg == 0) {
            gpiSetErrorString((int *)connection, (int)gGpiProfileErrorOutOfMemory);
            return 1;
        }
        arg->profile = pid;
        arg->result = 0;
        __result__ = gpiAddCallback(connection, callback, arg, operation, 0);
        if (__result__ != 0)
            return __result__;
    }
    gpiRemoveOperation(connection, (GPIOperation *)operation);
    return 0;
}






GPIProfile *gpiProfileListAdd(void **connection, int id)
{
    GPIConnection *profileList = (GPIConnection *)*connection;
    GPIProfile *pProfile;

    if (id <= 0)
        return 0;
    if (gpiGetProfile(connection, id, &pProfile))
        return pProfile;
    {
        GPIProfile profile = {0};

        profile.profileId = id;
        profile.userId = 0;
        profile.cache = 0;
        profile.authSig = 0;
        profile.peerSig = 0;
        profile.requestCount = 0;
        profile.deletedLocally = 0;
        TableEnter(profileList->profileList.profileTable, &profile);
        profileList->profileList.num++;
    }
    if (gpiGetProfile(connection, id, &pProfile))
        return pProfile;
    return 0;
}






int gpiGetProfile(void ** connection, int profileid, GPIProfile ** pProfile)
{
	GPIConnection * iconnection = (GPIConnection *)*connection;
	GPIProfile profileTemp;
	GPIProfile * profile;

	profileTemp.profileId = profileid;
	profile = (GPIProfile *)TableLookup(iconnection->profileList.profileTable, &profileTemp);
	if (pProfile)
		*pProfile = profile;
	return profile != 0;
}







/*
 * sdk:      gpiProcessDeleteProfle (libdwcgsgp.TWL.HYB.a gpiprofile.o)
 */
int gpiProcessDeleteProfle(void **connection, GPIOperation *operation, char *input)
{
    GPIConnection *iconnection = (GPIConnection *)*connection;
    GPICallback callback;
    GPDeleteProfileResponseArg *arg;
    int __result__;

    if (gpiCheckForError((int *)connection, input, 1))
        return 4;
    if (strncmp((const u8 *)input, (const u8 *)gGpiProfileResponseDpr, 5) != 0) {
        gpiSetError((int *)connection, 1, (int)gGpiProfileErrorUnexpectedData);
        gpiCallErrorCallback((int *)connection, 3, 1);
        return 3;
    }
    callback = operation->callback;
    if (operation->callback.callback != 0) {
        arg = (GPDeleteProfileResponseArg *)gsimalloc(sizeof(GPDeleteProfileResponseArg));
        if (arg == 0) {
            gpiSetErrorString((int *)connection, (int)gGpiProfileErrorOutOfMemory);
            return 1;
        }
        arg->profile = iconnection->profileid;
        arg->result = 0;
        __result__ = gpiAddCallback(connection, callback, arg, operation, 0);
        if (__result__ != 0)
            return __result__;
    }
    gpiRemoveOperation(connection, (GPIOperation *)operation);
    return 0;
}







void gpiRemoveProfileByID(void ** connection, int profileid)
{
	GPIConnection * iconnection = (GPIConnection *)*connection;
	GPIProfile * profile;

	if (gpiGetProfile(connection, profileid, &profile))
		TableRemove(iconnection->profileList.profileTable, profile);
}







void gpiRemoveProfile(void ** connection, GPIProfile * profile)
{
	GPIConnection * iconnection = (GPIConnection *)*connection;

	TableRemove(iconnection->profileList.profileTable, profile);
}





int gpiCheckProfileForUser(void * unused, GPIProfile * profile, void * udata)
{
	GPIFindProfileByUserData * data = (GPIFindProfileByUserData *)udata;
	GPIInfoCache * info = profile->cache;

	if (info != 0
	    && strcmp(data->nick, info->nick) == 0
	    && strcmp(data->email, info->email) == 0)
	{
		*(data->profile) = profile;
		data->found = 1;
		return 0;
	}
	return 1;
}





int gpiFindProfileByUser(void ** connection, char * nick, char * email, GPIProfile ** profile)
{
	GPIFindProfileByUserData data;

	data.nick = nick;
	data.email = email;
	data.profile = profile;
	data.found = 0;
	gpiProfileMap(connection, gpiCheckProfileForUser, &data);
	if (!data.found)
		*profile = 0;
	return 0;
}



/*
 * Calls the handler the object carries on its three words.
 */
void gpiProfileMapCallback(int a, int *p)
{
    ((void (*)(int, int, int))p[1])(p[0], a, p[2]);
}




int gpiProfileMap(void ** connection, int (*func)(void *, GPIProfile *, void *), void * data)
{
	GPIProfileMapData mapData;
	GPIConnection * iconnection = (GPIConnection *)*connection;

	mapData.connection = connection;
	mapData.func = func;
	mapData.data = data;
	if (TableMapSafe2(iconnection->profileList.profileTable, (int (*)(void *, void *))gpiProfileMapCallback, &mapData) == 0)
		return 1;
	return 0;
}




int gpiCheckForBuddy(void * unused, GPIProfile * profile, void * udata)
{
	GPIFindProfileData * data = (GPIFindProfileData *)udata;

	if (profile->buddyStatus != 0 && data->blockIndex == profile->buddyStatus->buddyIndex)
	{
		data->profile = profile;
		return 0;
	}
	if (profile->buddyStatusInfo != 0 && data->blockIndex == profile->buddyStatusInfo->buddyIndex)
	{
		data->profile = profile;
		return 0;
	}
	return 1;
}



GPIProfile * gpiFindBuddy(void ** connection, int blockIndex)
{
	GPIFindProfileData data;

	data.blockIndex = blockIndex;
	data.profile = 0;
	gpiProfileMap(connection, gpiCheckForBlock, &data);
	return data.profile;
}



void gpiRemoveBuddyStatus(GPIBuddyStatus * buddyStatus)
{
	gsifree(buddyStatus->locationString);
	buddyStatus->locationString = 0;
	gsifree(buddyStatus->statusString);
	buddyStatus->statusString = 0;
	gsifree(buddyStatus);
}



void gpiRemoveBuddyStatusInfo(GPIBuddyStatusInfo * buddyStatusInfo)
{
	gsifree(buddyStatusInfo->richStatus);
	buddyStatusInfo->richStatus = 0;
	gsifree(buddyStatusInfo->gameType);
	buddyStatusInfo->gameType = 0;
	gsifree(buddyStatusInfo->gameVariant);
	buddyStatusInfo->gameVariant = 0;
	gsifree(buddyStatusInfo->gameMapName);
	buddyStatusInfo->gameMapName = 0;
	ArrayFree(buddyStatusInfo->extendedInfoKeys);
	buddyStatusInfo->extendedInfoKeys = 0;
	gsifree(buddyStatusInfo);
}


/*
 * True when the block is non-null and all six pointers at +0x10, +8, +0xc,
 * +0x1c, +0x14 and +0x20 are null.
 */
int gpiCanFreeProfile(char *p)
{
    if (p != 0
        && *(int *)(p + 0x10) == 0
        && *(int *)(p + 8) == 0
        && *(int *)(p + 0xc) == 0
        && *(int *)(p + 0x1c) == 0
        && *(int *)(p + 0x14) == 0
        && *(int *)(p + 0x20) == 0)
        return 1;
    return 0;
}



/*
 * sdk:      gpiProcessRecvBlockedList (libdwcgsgp.TWL.HYB.a gpiprofile.o)
 */
int gpiProcessRecvBlockedList(void **connection, char *input)
{
    int i;
    unsigned int j;
    int num;
    int index;
    char c;
    char *str;
    char buffer[512];
    GPIProfile *profile;
    int profileid;
    GPIConnection *iconnection;

    index = 0;
    iconnection = (GPIConnection *)*connection;

    if (gpiCheckForError((int *)connection, input, 1))
        return 4;

    if (!gpiValueForKeyWithIndex(input, gGpiProfileKeyBlk, &index, buffer, sizeof(buffer))) {
        gpiSetError((int *)connection, 1, (int)gGpiProfileErrorUnexpectedData);
        gpiCallErrorCallback((int *)connection, 3, 1);
        return 3;
    }
    num = atoi(buffer);

    str = strstr(input, gGpiProfileKeyList);
    if (!str) {
        gpiSetError((int *)connection, 1, (int)gGpiProfileErrorUnexpectedData);
        gpiCallErrorCallback((int *)connection, 3, 1);
        return 3;
    }
    index += 6;

    for (i = 0; i < num; i++) {
        if (i == 0) {
            for (j = 0; (j < sizeof(buffer)) && ((c = str[j + 6]) != '\0') && (c != ','); j++)
                buffer[j] = c;
            buffer[j] = '\0';
            index += j;
        } else {
            if (!gpiValueForKeyWithIndex(input, gGpiProfileComma, &index, buffer, sizeof(buffer))) {
                gpiSetError((int *)connection, 1, (int)gGpiProfileErrorUnexpectedData);
                gpiCallErrorCallback((int *)connection, 3, 1);
                return 3;
            }
        }

        profileid = atoi(buffer);
        profile = gpiProfileListAdd(connection, profileid);
        if (!profile) {
            gpiSetErrorString((int *)connection, (int)gGpiProfileErrorOutOfMemory);
            return 1;
        }
        profile->blocked = 1;
        profile->blockIndex = iconnection->profileList.numBlocked++;
        gpiBuddyDeletedLocally(connection, profileid, 1);
    }

    return 0;
}
