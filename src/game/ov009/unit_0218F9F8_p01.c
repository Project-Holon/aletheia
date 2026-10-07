/*
 * file:     unit_0218F9F8_p01.c
 * unit:     yes
 * function: func_0218F9F8, func_0218FA0C, func_0218FA1C, func_0218FB14, func_0218FB68
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
 */
struct GPIOperation;
typedef struct GPIBuddyStatus
{
	char pad[8];
	void * field8;
	void * fieldC;
} GPIBuddyStatus;

typedef struct GPIBuddyStatusInfo
{
	char pad[8];
	void * field8;
	void * fieldC;
	void * field10;
	void * field14;
	char pad2[0x38 - 0x18];
	void * field38;
} GPIBuddyStatusInfo;

struct GPIProfile
{
	char pad[8];
	GPIBuddyStatus * buddyStatus;
	GPIBuddyStatusInfo * buddyStatusInfo;
	int pad10;
	void * field14;
	int pad18;
	void * field1C;
};

typedef struct GPIConnection
{
	char pad[0x5C8];
	void * profiles;
	int field5CC;
	int field5D0;
	int field5D4;
} GPIConnection;

typedef struct GPICallback {
    void (*callback)(void **, void *, void *);
    void *param;
} GPICallback;

typedef struct GPIOperation_s {
    int type;
    void *data;
    int blocking;
    GPICallback callback;
} GPIOperation;

typedef struct {
    int result;
    int profile;
} GPNewProfileResponseArg;

typedef unsigned char  u8;

typedef unsigned int   u32;

extern unsigned long long func_0209C0A4(int v);
extern void gsifree(void * ptr);
extern void ArrayFree(void * array);
extern void gpiFreeInfoCache(struct GPIProfile * profile);
extern void * TableNew(int elemSize, int nBuckets, int (*hashFn)(void *, int), int (*compFn)(void *, void *), void (*freeFn)(void *));
extern int gpiProfilesTableHash(void * arg, int numBuckets);
extern int func_0219329C(int *connection, const char *input, int fatal);
extern int func_020949F4(const u8 *s1, const u8 *s2, unsigned int n);
extern void func_02193710(int *connection, int result, int errorString);
extern int func_02189D78(int *connection, int a1, int a2);
extern int func_02193418(const char *command, const char *key, char *value, int valueLen);
extern int func_020964E0(u32 a0);
extern void *func_0217EAB0(unsigned long size);
extern void func_02193734(int *p, int b);
extern int func_02189DFC(void **connection, GPICallback callback, void *arg, GPIOperation *operation, int type);
extern void func_0218E240(void **connection, struct GPIOperation *operation);
int func_0218F9F8(int *p);
int gpiProfilesTableCompare(void *a, void *b);
void gpiProfilesTableFree(void * arg);
int gpiInitProfiles(void ** connection);
int func_0218FB68(void **connection, GPIOperation *operation, char *input);
extern char g_021A51D0[];
extern char g_021A51D8[];
extern char g_021A5208[];
extern char g_021A5214[];


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
	struct GPIProfile * profile = (struct GPIProfile *)arg;

	if (profile->buddyStatus != 0)
	{
		gsifree(profile->buddyStatus->field8);
		profile->buddyStatus->field8 = 0;
		gsifree(profile->buddyStatus->fieldC);
		profile->buddyStatus->fieldC = 0;
		gsifree(profile->buddyStatus);
		profile->buddyStatus = 0;
	}
	if (profile->buddyStatusInfo != 0)
	{
		gsifree(profile->buddyStatusInfo->field8);
		profile->buddyStatusInfo->field8 = 0;
		gsifree(profile->buddyStatusInfo->fieldC);
		profile->buddyStatusInfo->fieldC = 0;
		gsifree(profile->buddyStatusInfo->field10);
		profile->buddyStatusInfo->field10 = 0;
		gsifree(profile->buddyStatusInfo->field14);
		profile->buddyStatusInfo->field14 = 0;
		if (profile->buddyStatusInfo->field38 != 0)
		{
			ArrayFree(profile->buddyStatusInfo->field38);
			profile->buddyStatusInfo->field38 = 0;
		}
		gsifree(profile->buddyStatusInfo);
		profile->buddyStatusInfo = 0;
	}
	gpiFreeInfoCache(profile);
	gsifree(profile->field14);
	profile->field14 = 0;
	gsifree(profile->field1C);
	profile->field1C = 0;
}


int gpiInitProfiles(void ** connection)
{
	GPIConnection * iconnection = (GPIConnection *)*connection;
	int result = 0;

	iconnection->field5D0 = 0;
	iconnection->field5D4 = 0;
	iconnection->field5CC = 0;
	iconnection->profiles = TableNew(0x30, 0x20, gpiProfilesTableHash, gpiProfilesTableCompare, gpiProfilesTableFree);
	if (iconnection->profiles != 0)
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
    pid = func_020964E0((u32)buffer);
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
    func_0218E240(connection, (struct GPIOperation *)operation);
    return 0;
}
