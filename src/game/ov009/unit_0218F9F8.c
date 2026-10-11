/*
 * file:     unit_0218F9F8.c
 * unit:     yes
 * function: func_0218F9F8, func_0218FA0C, func_0218FA1C, func_0218FB14, func_0218FB68, func_0218FCD8, gpiGetProfile, func_0218FDD8, func_0218FEF0, func_0218FF24, func_0218FF38, func_0218FF98, func_0218FFE0, func_0218FFFC, func_0219003C, func_0219008C, func_021900BC, func_021900EC, func_02190140, func_02190188
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
 *   func_0219329C  0x0219329c  arm   ov009
 *   func_020949F4  0x020949f4  arm
 *   func_02193710  0x02193710  arm   ov009
 *   func_02189D78  0x02189d78  arm   ov009
 *   func_02193418  0x02193418  arm   ov009
 *   func_020964E0  0x020964e0  arm
 *   func_0217EAB0  0x0217eab0  arm   ov009
 *   func_02193734  0x02193734  arm   ov009
 *   func_02189DFC  0x02189dfc  arm   ov009
 *   func_0218E240  0x0218e240  arm   ov009
 *   g_021A51D0     0x021a51d0  data
 *   g_021A51D8     0x021a51d8  data
 *   g_021A5208     0x021a5208  data
 *   g_021A5214     0x021a5214  data
 *   func_0218FD9C  0x0218FD9C  arm  ov009
 *   func_0218474C  0x0218474C  arm  ov009
 *   TableLookup                      0x0218482C arm
 *   g_021A5224     0x021a5224  data
 *   TableRemove                      0x021847BC arm
 *   func_021847BC  0x021847BC  arm
 *   strcmp                           0x020948E0 arm
 *   TableMapSafe2                    0x021848E4 arm
 *   gpiProfileMapCallback            0x0218FFE0 arm
 *   gpiCheckForBlock                 0x0219003C arm
 *   func_02193378  0x02193378  arm  ov009
 *   func_02094B20  0x02094B20  arm
 *   func_02189300  0x02189300  arm  ov009
 *   g_021A522C     0x021A522C  data
 *   g_021A5234     0x021A5234  data
 *   g_021A523C     0x021A523C  data
 */
#include "gpi_types.h"

extern unsigned long long func_0209C0A4(int v);
extern void gsifree(void * ptr);
extern void ArrayFree(void * array);
extern void gpiFreeInfoCache(GPIProfile * profile);
extern void * TableNew(int elemSize, int nBuckets, int (*hashFn)(void *, int), int (*compFn)(void *, void *), void (*freeFn)(void *));
extern int gpiProfilesTableHash(void * arg, int numBuckets);
extern int func_0219329C(int *connection, const char *input, int fatal);
extern int func_020949F4(const u8 *s1, const u8 *s2, unsigned int n);
extern void func_02193710(int *connection, int result, int errorString);
extern int func_02189D78(int *connection, int a1, int a2);
extern int func_02193418(const char *command, const char *key, char *value, int valueLen);
extern int func_020964E0(const char *s);
extern void *func_0217EAB0(unsigned long size);
extern void func_02193734(int *p, int b);
extern int func_02189DFC(void **connection, GPICallback callback, void *arg, GPIOperation *operation, int type);
extern void func_0218E240(void **connection, GPIOperation *operation);
extern int func_0218FD9C(void **connection, int profileid, GPIProfile **pProfile);
extern void func_0218474C(void *table, void *newElem);
extern void * TableLookup(void * table, void * elemKey);
extern int TableRemove(void * table, void * delElem);
extern void func_021847BC(int v);
extern int strcmp(const char * a, const char * b);
extern void * TableMapSafe2(void * table, int (*cb)(void *, void *), void * udata);
extern int gpiProfileMapCallback(void * arg, void * udata);
extern int gpiCheckForBlock(void * unused, GPIProfile * profile, void * udata);
extern int func_02193378(char *command, char *key, int *index, char *value, int len);
extern char *func_02094B20(const char *s1, const char *s2);
extern int func_02189300(void **connection, int id, int isDeleted);
int func_0218F9F8(int *p);
int gpiProfilesTableCompare(void *a, void *b);
void gpiProfilesTableFree(void * arg);
int gpiInitProfiles(void ** connection);
int func_0218FB68(void **connection, GPIOperation *operation, char *input);
GPIProfile *func_0218FCD8(void **connection, int id);
int gpiGetProfile(void ** connection, int profileid, GPIProfile ** pProfile);
int func_0218FDD8(void **connection, GPIOperation *operation, char *input);
void gpiRemoveProfileByID(void ** connection, int profileid);
void func_0218FF24(const int *p, void *profile);
int gpiCheckProfileForUser(void * unused, GPIProfile * profile, void * udata);
int gpiFindProfileByUser(void ** connection, char * nick, char * email, GPIProfile ** profile);
void func_0218FFE0(int a, int *p);
int gpiProfileMap(void ** connection, int (*func)(void *, GPIProfile *, void *), void * data);
int gpiCheckForBuddy(void * unused, GPIProfile * profile, void * udata);
GPIProfile * gpiFindBlockedProfile(void ** connection, int blockIndex);
void gpiRemoveBuddyStatus(GPIBuddyStatus * buddyStatus);
void gpiRemoveBuddyStatusInfo(GPIBuddyStatusInfo * buddyStatusInfo);
int func_02190140(char *p);
int func_02190188(void **connection, char *input);
extern char g_021A51D0[];
extern char g_021A51D8[];
extern char g_021A5208[];
extern char g_021A5214[];
extern char g_021A5224[];
extern char g_021A522C[];
extern char g_021A5234[];
extern char g_021A523C[];







/*
 * The high word of the 64-bit word the call on the pointed-to word returns.
 */
int func_0218F9F8(int *p)
{
    return (int)(func_0209C0A4(*p) >> 32);
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
int func_0218FB68(void **connection, GPIOperation *operation, char *input)
{
    char buffer[16];
    int pid;
    GPICallback callback;
    GPNewProfileResponseArg *arg;
    int __result__;

    if (func_0219329C((int *)connection, input, 1))
        return 4;
    if (func_020949F4((const u8 *)input, (const u8 *)g_021A51D0, 5) != 0) {
        func_02193710((int *)connection, 1, (int)g_021A51D8);
        __result__ = 3;
        func_02189D78((int *)connection, __result__, 1);
        return __result__;
    }
    if (!func_02193418(input, g_021A5208, buffer, 16)) {
        func_02193710((int *)connection, 1, (int)g_021A51D8);
        __result__ = 3;
        func_02189D78((int *)connection, __result__, 1);
        return __result__;
    }
    pid = func_020964E0(buffer);
    callback = operation->callback;
    if (callback.callback != 0) {
        arg = (GPNewProfileResponseArg *)func_0217EAB0(sizeof(GPNewProfileResponseArg));
        if (arg == 0) {
            func_02193734((int *)connection, (int)g_021A5214);
            return 1;
        }
        arg->profile = pid;
        arg->result = 0;
        __result__ = func_02189DFC(connection, callback, arg, operation, 0);
        if (__result__ != 0)
            return __result__;
    }
    func_0218E240(connection, (GPIOperation *)operation);
    return 0;
}






GPIProfile *func_0218FCD8(void **connection, int id)
{
    GPIConnection *profileList = (GPIConnection *)*connection;
    GPIProfile *pProfile;

    if (id <= 0)
        return 0;
    if (func_0218FD9C(connection, id, &pProfile))
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
        func_0218474C(profileList->profileList.profileTable, &profile);
        profileList->profileList.num++;
    }
    if (func_0218FD9C(connection, id, &pProfile))
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
int func_0218FDD8(void **connection, GPIOperation *operation, char *input)
{
    GPIConnection *iconnection = (GPIConnection *)*connection;
    GPICallback callback;
    GPDeleteProfileResponseArg *arg;
    int __result__;

    if (func_0219329C((int *)connection, input, 1))
        return 4;
    if (func_020949F4((const u8 *)input, (const u8 *)g_021A5224, 5) != 0) {
        func_02193710((int *)connection, 1, (int)g_021A51D8);
        func_02189D78((int *)connection, 3, 1);
        return 3;
    }
    callback = operation->callback;
    if (operation->callback.callback != 0) {
        arg = (GPDeleteProfileResponseArg *)func_0217EAB0(sizeof(GPDeleteProfileResponseArg));
        if (arg == 0) {
            func_02193734((int *)connection, (int)g_021A5214);
            return 1;
        }
        arg->profile = iconnection->profileid;
        arg->result = 0;
        __result__ = func_02189DFC(connection, callback, arg, operation, 0);
        if (__result__ != 0)
            return __result__;
    }
    func_0218E240(connection, (GPIOperation *)operation);
    return 0;
}







void gpiRemoveProfileByID(void ** connection, int profileid)
{
	GPIConnection * iconnection = (GPIConnection *)*connection;
	GPIProfile * profile;

	if (gpiGetProfile(connection, profileid, &profile))
		TableRemove(iconnection->profileList.profileTable, profile);
}







/*
 * Tail call on the word at +0x5c8 of the block the object points at.
 */
void func_0218FF24(const int *p, void *profile)
{
    func_021847BC(*(const int *)(*p + 0x5c8));
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
void func_0218FFE0(int a, int *p)
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
	if (TableMapSafe2(iconnection->profileList.profileTable, gpiProfileMapCallback, &mapData) == 0)
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



GPIProfile * gpiFindBlockedProfile(void ** connection, int blockIndex)
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
int func_02190140(char *p)
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
int func_02190188(void **connection, char *input)
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

    if (func_0219329C((int *)connection, input, 1))
        return 4;

    if (!func_02193378(input, g_021A522C, &index, buffer, sizeof(buffer))) {
        func_02193710((int *)connection, 1, (int)g_021A51D8);
        func_02189D78((int *)connection, 3, 1);
        return 3;
    }
    num = func_020964E0(buffer);

    str = func_02094B20(input, g_021A5234);
    if (!str) {
        func_02193710((int *)connection, 1, (int)g_021A51D8);
        func_02189D78((int *)connection, 3, 1);
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
            if (!func_02193378(input, g_021A523C, &index, buffer, sizeof(buffer))) {
                func_02193710((int *)connection, 1, (int)g_021A51D8);
                func_02189D78((int *)connection, 3, 1);
                return 3;
            }
        }

        profileid = func_020964E0(buffer);
        profile = func_0218FCD8(connection, profileid);
        if (!profile) {
            func_02193734((int *)connection, (int)g_021A5214);
            return 1;
        }
        profile->blocked = 1;
        profile->blockIndex = iconnection->profileList.numBlocked++;
        func_02189300(connection, profileid, 1);
    }

    return 0;
}
