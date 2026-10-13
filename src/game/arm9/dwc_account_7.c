/*
 * file:     dwc_account_7.c
 * unit:     yes
 * function: func_02059108, func_0205911C, func_0205912C, func_0205915C, func_02059194, DWCi_IsBuddyMsgAlreadySent, func_020591CC, DWCi_Acc_SetFlags, func_020591F0, func_02059214, func_02059240, func_02059270, func_020592A0, func_020592D0, func_02059354, func_02059374, func_020593B8, func_02059408, func_02059474, func_02059508, func_02059588, func_02059644, func_020596B0, func_020596C8, DWC_IsValidFriendData, func_020596F0, DWC_CreateUserData, func_02059718, func_02059760, func_020597C8, func_020597F0
 * address:  0x02059108
 * region:   arm9
 * compiler: dsi/1.2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02059108    0x02059108  arm
 *   CTRDG_IsExisting  0x0205915C  arm
 *   CTRDGi_IsBitIDAtInit  0x02059194  arm
 *   DWCi_Acc_GetFlag_DataType        0x0205911c arm
 *   MATHi_CRC8InitTable              0x02081940 arm
 *   MATH_CalcCRC8                    0x02081b3c arm
 *   MATH_MD5Init                     0x02081120 arm
 *   MATH_MD5Update                   0x02081164 arm
 *   MATH_MD5GetHash                  0x0208122c arm
 *   DWC_Acc_CreateFriendKey          0x020592d0 arm
 *   DWC_Acc_CheckFriendKey           0x02059374 arm
 *   g_020A7FF4                       0x020A7FF4 data
 *   DWCi_Acc_GetUserId               0x02059084 arm
 *   DWCi_Acc_U64ToString32           0x02059408 arm
 *   DWCi_Acc_GetPlayerId             0x020590a4 arm
 *   OS_SNPrintf                      0x02084f80 arm
 *   g_020A8018                       0x020A8018 data
 *   MI_CpuFill8                      0x02082bcc arm
 *   DWCi_Acc_CreateTempLoginId       0x02059588 arm
 *   MATHi_CRC32InitTableRev          0x02081ac0 arm
 *   MATH_CalcCRC32                   0x02081bb8 arm
 *   OS_GetLowEntropyData             0x02088168 arm
 *   DWC_Auth_GetId                   0x02058fb4 arm
 *   DWCi_Acc_SetUserId               0x020590c8 arm
 *   DWCi_Acc_SetPlayerId             0x020590f0 arm
 *   func_020596D8  0x020596D8  arm
 *   DWCi_Acc_IsValidLoginId          0x020596b0 arm
 */
struct DWCstAccLoginId;
struct DWCstAccUserData;
typedef struct {
    unsigned int raw;
} DWCstAccFlag;

typedef unsigned char u8;

typedef int BOOL;

typedef union DWCstAccFriendData DWCstAccFriendData;

struct MATHMD5Context {
    unsigned char data[88];
};

struct MATHCRC8Table {
    unsigned char table[256];
};

struct MATHCRC32Table {
    unsigned long table[256];
};

struct DWCstAccLoginId {
    unsigned long data[3];
};

struct DWCstAccUserData {
    unsigned long size;
    struct DWCstAccLoginId pseudo;
    struct DWCstAccLoginId authentic;
    int gs_profile_id;
    unsigned long flag;
    unsigned long gamecode;
    unsigned long reserved[5];
    unsigned long crc32;
};

typedef struct DWCAuthWiFiId {
    unsigned long long uId;
    unsigned long long notAttestedId;
    unsigned long flg;
} DWCAuthWiFiId;

typedef struct MATHRandContext32 {
    unsigned long long x;
    unsigned long long mul;
    unsigned long long add;
} MATHRandContext32;

extern BOOL CTRDG_IsExisting(void);
extern BOOL CTRDGi_IsBitIDAtInit(u8 bitID);
extern unsigned long DWCi_Acc_GetFlag_DataType(void *frienddata);
extern int DWCi_Acc_SetMaskBits(unsigned long *ptr, unsigned long data, unsigned long shift, unsigned long mask);
extern void MATHi_CRC8InitTable(struct MATHCRC8Table *table, unsigned char poly);
extern unsigned char MATH_CalcCRC8(struct MATHCRC8Table *table, void *data, unsigned long dataLength);
extern void MATH_MD5Init(struct MATHMD5Context *context);
extern void MATH_MD5Update(struct MATHMD5Context *context, void *input, unsigned long length);
extern void MATH_MD5GetHash(struct MATHMD5Context *context, void *digest);
extern unsigned long long DWC_Acc_CreateFriendKey(int gs_profile_id, unsigned long gamecode, int method);
extern int DWC_Acc_CheckFriendKey(unsigned long long friendkey, unsigned long gamecode, int method);
extern unsigned long long DWCi_Acc_GetUserId(struct DWCstAccLoginId *userdata);
extern void DWCi_Acc_U64ToString32(unsigned long long num, int bitnum, char *result);
extern unsigned long DWCi_Acc_GetPlayerId(struct DWCstAccLoginId *userdata);
extern int OS_SNPrintf(char *dst, unsigned long len, const char *fmt, ...);
extern void MATHi_CRC32InitTableRev(struct MATHCRC32Table *table, unsigned long poly);
extern unsigned long MATH_CalcCRC32(struct MATHCRC32Table *table, void *data, unsigned long dataLength);
extern void MI_CpuFill8(void *dstp, unsigned char data, unsigned long size);
extern void DWCi_Acc_CreateTempLoginId(struct DWCstAccLoginId *loginid);
extern void DWC_Auth_GetId(DWCAuthWiFiId *id);
extern void OS_GetLowEntropyData(unsigned long *buffer);
extern void DWCi_Acc_SetUserId(struct DWCstAccLoginId *userdata, unsigned long long userid);
extern void DWCi_Acc_SetPlayerId(struct DWCstAccLoginId *userdata, unsigned long playerid);
extern int func_020596D8(void *p);
extern void *func_0205A10C(void);
extern void DWCi_Acc_CreateUserData(void *userdata, unsigned long gamecode);
extern int DWCi_Acc_IsValidLoginId(void *loginid);
unsigned long DWCi_Acc_GetFlags(DWCstAccFlag *userdata);
unsigned long func_0205911C(void *userdata);
BOOL func_0205912C(u8 bitID);
int DWCi_IsBuddyFriendData(void *frienddata);
int DWCi_IsReverseBuddyFriendData(void *frienddata);
int DWCi_IsBuddyMsgAlreadySent(void *frienddata);
unsigned long func_020591CC(void *userdata);
void DWCi_Acc_SetFlags(void *userdata, unsigned long flags);
void DWCi_Acc_SetFlag_DataType(void *userdata, int type);
void func_02059214(DWCstAccFriendData *frienddata);
void func_02059240(void *frienddata, int setflag);
void func_02059270(void *frienddata, int setflag);
void func_020592A0(void *frienddata, int setflag);
unsigned long long func_020592D0(int gs_profile_id, unsigned long gamecode, int method);
asm int DWC_CheckFriendKey(void *data, unsigned long long friendKey);
int func_02059374(unsigned long long friendkey, unsigned long gamecode, int method);
int func_020593B8(unsigned long long friendkey, unsigned long gamecode);
void func_02059408(unsigned long long num, int bitnum, char *result);
void func_02059474(struct DWCstAccLoginId *loginid, unsigned long gamecode, char *username);
void func_02059508(struct DWCstAccUserData *userdata, unsigned long gamecode);
void func_02059588(struct DWCstAccLoginId *loginid);
int func_02059644(struct DWCstAccLoginId *loginid);
int func_020596B0(void *loginid);
int DWCi_Acc_IsAuthentic(void *userdata);
int DWC_IsValidFriendData(void *frienddata);
int func_020596F0(void *p);
void DWC_CreateUserData(void *userdata);
int func_02059718(struct DWCstAccUserData *userdata);
int func_02059760(struct DWCstAccUserData *userdata);
int func_020597C8(struct DWCstAccUserData *userdata);
void func_020597F0(struct DWCstAccUserData *userdata, struct DWCstAccLoginId *loginid, int gs_profile_id);
extern const char g_020A7FF4[];
extern const char g_020A8018[];






unsigned long DWCi_Acc_GetFlags(DWCstAccFlag *userdata)
{
    return (userdata->raw >> 11) & 0x1fffff;
}






unsigned long func_0205911C(void *userdata)
{
    return DWCi_Acc_GetFlags(userdata) & 3;
}






/*
 * sdk:      CTRDG_IsBitID (libctrdg.TWL.HYB.a ctrdg.o)
 */
BOOL func_0205912C(u8 bitID)
{
    return (CTRDG_IsExisting() && CTRDGi_IsBitIDAtInit(bitID)) ? 1 : 0;
}






int DWCi_IsBuddyFriendData(void *frienddata)
{
    if (DWCi_Acc_GetFlag_DataType(frienddata) == 3)
        return (DWCi_Acc_GetFlags(frienddata) & 4) == 4;
    return 0;
}






int DWCi_IsReverseBuddyFriendData(void *frienddata)
{
    unsigned long type = DWCi_Acc_GetFlags(frienddata);
    return (type & 8) == 8;
}




int DWCi_IsBuddyMsgAlreadySent(void *frienddata)
{
    unsigned long type = DWCi_Acc_GetFlags(frienddata);
    return (type & 32) == 32;
}



unsigned long func_020591CC(void *userdata)
{
    return func_0205911C(userdata);
}








void DWCi_Acc_SetFlags(void *userdata, unsigned long flags)
{
    DWCi_Acc_SetMaskBits(userdata, flags, 11, 0x1fffff);
}









void DWCi_Acc_SetFlag_DataType(void *userdata, int type)
{
    unsigned long flags = DWCi_Acc_GetFlags(userdata);
    DWCi_Acc_SetFlags(userdata, (flags & ~3) | type);
}









/*
 * sdk:      DWCi_SetBuddyFriendData (dwc_account.o)
 */
void func_02059214(DWCstAccFriendData *frienddata)
{
    unsigned long flags;

    if (func_0205911C(frienddata) == 3) {
        flags = DWCi_Acc_GetFlags((DWCstAccFlag *)frienddata) | 4;
        DWCi_Acc_SetFlags(frienddata, flags);
    }
}









/*
 * sdk:      DWCi_SetReverseBuddyFlag (libdwcaccount.TWL.HYB.a(dwc_account.o))
 */
void func_02059240(void *frienddata, int setflag)
{
    unsigned long tempflags;

    if (setflag) {
        tempflags = DWCi_Acc_GetFlags(frienddata) | 8;
    } else {
        tempflags = DWCi_Acc_GetFlags(frienddata) & ~8;
    }
    DWCi_Acc_SetFlags(frienddata, tempflags);
}









/*
 * sdk:      DWCi_SetExpIsBuddyFriendFlag (libdwcaccount.TWL.HYB.a(dwc_account.o))
 */
void func_02059270(void *frienddata, int setflag)
{
    unsigned long tempflags;

    if (setflag) {
        tempflags = DWCi_Acc_GetFlags(frienddata) | 0x10;
    } else {
        tempflags = DWCi_Acc_GetFlags(frienddata) & ~0x10;
    }
    DWCi_Acc_SetFlags(frienddata, tempflags);
}









/*
 * sdk:      DWCi_SetSentBuddyReqFlag (libdwcaccount.TWL.HYB.a(dwc_account.o))
 */
void func_020592A0(void *frienddata, int setflag)
{
    unsigned long tempflags;

    if (setflag) {
        tempflags = DWCi_Acc_GetFlags(frienddata) | 0x20;
    } else {
        tempflags = DWCi_Acc_GetFlags(frienddata) & ~0x20;
    }
    DWCi_Acc_SetFlags(frienddata, tempflags);
}









/*
 * sdk:      DWC_Acc_CreateFriendKey (libdwcaccount.TWL.HYB.a(dwc_account.o))
 */
unsigned long long func_020592D0(int gs_profile_id, unsigned long gamecode, int method)
{
    unsigned long code[2];
    int hash;
    struct MATHCRC8Table table;
    struct MATHMD5Context context;
    unsigned char digest[16];

    code[0] = (unsigned long)gs_profile_id;
    code[1] = gamecode;
    if (method == 0) {
        MATHi_CRC8InitTable(&table, 7);
        hash = MATH_CalcCRC8(&table, code, sizeof(code));
    } else {
        MATH_MD5Init(&context);
        MATH_MD5Update(&context, code, sizeof(code));
        MATH_MD5GetHash(&context, digest);
        hash = digest[0] >> 1;
    }
    return ((unsigned long long)(hash & 0x7f) << 32) | (unsigned long)gs_profile_id;
}









asm int DWC_CheckFriendKey(void *data, unsigned long long friendKey)
{
    mov	r3, r0
    mov	r0, r1
    mov	r1, r2
    ldr	r2, [r3, #0x24]
    ldr ip, =func_02059374
    mov	r3, #1
    bx	ip
}








/*
 * sdk:      DWC_Acc_CheckFriendKey (libdwcaccount.TWL.HYB.a(dwc_account.o))
 */
int func_02059374(unsigned long long friendkey, unsigned long gamecode, int method)
{
    int pid = (int)(friendkey & 0xffffffff);

    if (pid <= 0) {
        return 0;
    }
    if (friendkey == DWC_Acc_CreateFriendKey(pid, gamecode, method)) {
        return 1;
    }
    return 0;
}








/*
 * sdk:      DWC_Acc_FriendKeyToGsProfileId (libdwcaccount.TWL.HYB.a(dwc_account.o))
 */
int func_020593B8(unsigned long long friendkey, unsigned long gamecode)
{
    int i;

    for (i = 0; i < 2; i++) {
        if (DWC_Acc_CheckFriendKey(friendkey, gamecode, i)) {
            return (int)(friendkey & 0xffffffff);
        }
    }
    return 0;
}








/*
 * sdk:      DWCi_Acc_U64ToString32 (libdwcaccount.TWL.HYB.a(dwc_account.o))
 */
void func_02059408(unsigned long long num, int bitnum, char *result)
{
    int i;
    int loopnum;
    const char *sStringTable;

    sStringTable = g_020A7FF4;
    loopnum = (bitnum + 4) / 5;
    for (i = 0; i < loopnum; i++) {
        *(result + loopnum - 1 - i) = sStringTable[num & 0x1f];
        num >>= 5;
    }
    result[loopnum] = 0;
}







/*
 * sdk:      DWCi_Acc_LoginIdToUserName (libdwcaccount.TWL.HYB.a(dwc_account.o))
 */
void func_02059474(struct DWCstAccLoginId *loginid, unsigned long gamecode, char *username)
{
    char userid[21];
    char playerid[21];

    DWCi_Acc_U64ToString32(DWCi_Acc_GetUserId(loginid), 43, userid);
    DWCi_Acc_U64ToString32(DWCi_Acc_GetPlayerId(loginid), 32, playerid);
    OS_SNPrintf(username, 21, g_020A8018, userid,
                (unsigned char)(gamecode >> 24), (unsigned char)(gamecode >> 16),
                (unsigned char)(gamecode >> 8), (unsigned char)gamecode, playerid);
}






/*
 * sdk:      DWCi_Acc_CreateUserData (libdwcaccount.TWL.HYB.a(dwc_account.o))
 */
void func_02059508(struct DWCstAccUserData *userdata, unsigned long gamecode)
{
    struct MATHCRC32Table table;

    MI_CpuFill8(userdata, 0, sizeof(struct DWCstAccUserData));
    userdata->size = sizeof(struct DWCstAccUserData);
    userdata->gs_profile_id = 0;
    userdata->gamecode = gamecode;
    DWCi_Acc_CreateTempLoginId(&userdata->pseudo);
    DWCi_Acc_SetFlag_DataType(&userdata->authentic, 0);
    MATHi_CRC32InitTableRev(&table, 0xedb88320);
    userdata->crc32 = MATH_CalcCRC32(&table, userdata, 0x3c);
    userdata->flag |= 1;
}





static inline void MATH_InitRand32(MATHRandContext32 *context, unsigned long long seed)
{
    context->x = seed;
    context->mul = 0x5d588b656c078965ULL;
    context->add = 0x269ec3ULL;
}





static inline unsigned long MATH_Rand32(MATHRandContext32 *context, unsigned long max)
{
    context->x = context->mul * context->x + context->add;
    if (max == 0) {
        return (unsigned long)(context->x >> 32);
    }
    return (unsigned long)(((context->x >> 32) * max) >> 32);
}





void func_02059588(struct DWCstAccLoginId *loginid)
{
    DWCAuthWiFiId authid;
    unsigned long buffer[8];
    MATHRandContext32 context;
    unsigned long i;

    OS_GetLowEntropyData(buffer);
    for (i = 1; i < 8; i++) {
        buffer[i] ^= buffer[i - 1];
    }
    MATH_InitRand32(&context, buffer[7]);
    DWC_Auth_GetId(&authid);
    if (authid.flg) {
        DWCi_Acc_SetUserId(loginid, authid.uId);
    } else {
        DWCi_Acc_SetUserId(loginid, authid.notAttestedId);
    }
    DWCi_Acc_SetPlayerId(loginid, MATH_Rand32(&context, 0));
    DWCi_Acc_SetFlag_DataType(loginid, 1);
}






/*
 * sdk:      DWCi_Acc_CheckConsoleUserId (libdwcaccount.TWL.HYB.a(dwc_account.o))
 */
int func_02059644(struct DWCstAccLoginId *loginid)
{
    DWCAuthWiFiId authid;

    DWC_Auth_GetId(&authid);
    if (authid.flg) {
        return DWCi_Acc_GetUserId(loginid) == authid.uId;
    }
    return DWCi_Acc_GetUserId(loginid) == authid.notAttestedId;
}






/*
 * The ARM9 listing labels this address func_020596B0; it calls DWCi_Acc_GetFlag_DataType, so it is a dwc_account.o static (the SDK table's DWC_GHTTPCleanupRootCAList attribution here does not match the linked bytes).
 */
int func_020596B0(void *loginid)
{
    return DWCi_Acc_GetFlag_DataType(loginid) == 1;
}






int DWCi_Acc_IsAuthentic(void *userdata)
{
    return func_020596B0((char *)userdata + 16);
}





int DWC_IsValidFriendData(void *frienddata)
{
    unsigned long type = DWCi_Acc_GetFlag_DataType(frienddata);
    return type != 0;
}



int func_020596F0(void *p)
{
    return func_020596D8(p);
}



void DWC_CreateUserData(void *userdata)
{
    DWCi_Acc_CreateUserData(userdata, (long unsigned int)func_0205A10C());
}




/*
 * sdk:      DWC_CheckUserData (libdwcaccount.TWL.HYB.a(dwc_account.o))
 */
int func_02059718(struct DWCstAccUserData *userdata)
{
    struct MATHCRC32Table table;
    unsigned long crc32;

    MATHi_CRC32InitTableRev(&table, 0xedb88320);
    crc32 = MATH_CalcCRC32(&table, userdata, 0x3c);
    return crc32 == userdata->crc32;
}



/*
 * sdk:      DWC_CheckValidConsole (libdwcaccount.TWL.HYB.a(dwc_account.o))
 */
int func_02059760(struct DWCstAccUserData *userdata)
{
    DWCAuthWiFiId authid;

    if (DWCi_Acc_GetFlag_DataType(&userdata->authentic) == 0) {
        return 1;
    }
    DWC_Auth_GetId(&authid);
    if (!authid.flg) {
        return 0;
    }
    if (DWCi_Acc_GetUserId(&userdata->authentic) == authid.uId) {
        return 1;
    }
    return 0;
}



/*
 * sdk:      DWC_CheckHasProfile (libdwcaccount.TWL.HYB.a(dwc_account.o))
 */
int func_020597C8(struct DWCstAccUserData *userdata)
{
    return DWCi_Acc_IsValidLoginId((char *)userdata + 0x10) && ((int *)userdata)[7] > 0;
}



/*
 * sdk:      DWCi_Acc_SetLoginIdToUserData (libdwcaccount.TWL.HYB.a(dwc_account.o))
 */
void func_020597F0(struct DWCstAccUserData *userdata, struct DWCstAccLoginId *loginid, int gs_profile_id)
{
    struct MATHCRC32Table table;

    userdata->authentic = *loginid;
    userdata->gs_profile_id = gs_profile_id;
    MATHi_CRC32InitTableRev(&table, 0xedb88320);
    userdata->crc32 = MATH_CalcCRC32(&table, userdata, 0x3c);
    userdata->flag |= 1;
}
