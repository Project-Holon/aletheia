/*
 * file:     dwc_account.c
 * unit:     yes
 * function: DWCi_Acc_SetMaskBits, DWCi_Acc_GetUserId, DWCi_Acc_GetPlayerId, DWCi_Acc_GetFriendKey, DWCi_Acc_GetGsProfileId, DWCi_Acc_SetUserId, DWCi_Acc_SetPlayerId, DWCi_Acc_SetFriendKey, DWCi_Acc_SetGsProfileId, DWCi_Acc_GetFlags, DWCi_Acc_GetFlag_DataType, DWC_IsBuddyFriendData, DWCi_IsBuddyFriendData, DWCi_IsReverseBuddyFriendData, DWCi_IsBuddyMsgAlreadySent, DWCi_Acc_GetFlagDataTypeThunk, DWCi_Acc_SetFlags, DWCi_Acc_SetFlag_DataType, DWCi_SetBuddyFriendData, DWCi_SetReverseBuddyFlag, DWCi_SetExpIsBuddyFriendFlag, DWCi_SetSentBuddyReqFlag, DWC_Acc_CreateFriendKey, DWC_CheckFriendKey, DWC_Acc_CheckFriendKey, DWC_Acc_FriendKeyToGsProfileId, DWCi_Acc_U64ToString32, DWCi_Acc_LoginIdToUserName, DWCi_Acc_CreateUserData, DWCi_Acc_CreateTempLoginId, DWCi_Acc_CheckConsoleUserId, DWCi_Acc_IsValidLoginId, DWCi_Acc_IsAuthentic, DWC_IsValidFriendData, DWCi_Acc_IsValidFriendDataThunk, DWC_CreateUserData, DWC_CheckUserData, DWC_CheckValidConsole, DWC_CheckHasProfile, DWCi_Acc_SetLoginIdToUserData, DWC_CheckDirtyFlag, DWCi_Acc_IsDirty, DWC_ClearDirtyFlag, DWCi_Acc_ClearDirty, DWC_GetFriendKey, DWC_GetGsProfileId, DWC_CreateFriendKey, DWC_CreateFriendKeyToken, DWC_CreateExchangeToken, DWC_SetGsProfileId, DWC_LoginIdToUserName, DWC_IsEqualFriendData
 * address:  0x02059058
 * region:   arm9
 * compiler: dsi/1.2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * TwlDWC libdwcaccount dwc_account.o.
 * The two 32-bit halves arrive as separate arguments (high first), not as one u64.
 * Tail call to DWCi_Acc_IsDirty (ldr ip, =target; bx ip; pool word).
 *
 * symbols:
 *   DWCi_Acc_GetFlags    0x02059108  arm
 *   DWCi_IsBuddyFriendData  0x0205915C  arm
 *   DWCi_IsReverseBuddyFriendData  0x02059194  arm
 *   DWCi_Acc_GetFlag_DataType        0x0205911c arm
 *   MATHi_CRC8InitTable              0x02081940 arm
 *   MATH_CalcCRC8                    0x02081b3c arm
 *   MATH_MD5Init                     0x02081120 arm
 *   MATH_MD5Update                   0x02081164 arm
 *   MATH_MD5GetHash                  0x0208122c arm
 *   DWC_Acc_CreateFriendKey          0x020592d0 arm
 *   DWC_Acc_CheckFriendKey           0x02059374 arm
 *   g_020A7FF4                       0x020A7FF4 data
 *   DWCi_Acc_U64ToString32           0x02059408 arm
 *   OS_SNPrintf                      0x02084f80 arm
 *   g_020A8018                       0x020A8018 data
 *   MI_CpuFill8                      0x02082bcc arm
 *   DWCi_Acc_CreateTempLoginId       0x02059588 arm
 *   MATHi_CRC32InitTableRev          0x02081ac0 arm
 *   MATH_CalcCRC32                   0x02081bb8 arm
 *   OS_GetLowEntropyData             0x02088168 arm
 *   DWC_Auth_GetId                   0x02058fb4 arm
 *   DWC_IsValidFriendData  0x020596D8  arm
 *   DWCi_Acc_IsValidLoginId          0x020596b0 arm
 *   DWC_Acc_FriendKeyToGsProfileId   0x020593b8 arm
 *   DWCi_GetGamecode  0x0205A10C  arm
 */
#include "dwc_account.h"

typedef struct {
    unsigned int raw;
} DWCstAccFlag;

#include "../types.h"

#include "../sdk_math.h"

#include "../sdk_dwc.h"

extern unsigned long DWCi_Acc_GetFlag_DataType(void *frienddata);
#include "crc.h"
#include "dgt_md5.h"
extern unsigned long long DWC_Acc_CreateFriendKey(int gs_profile_id, unsigned long gamecode, int method);
extern int DWC_Acc_CheckFriendKey(unsigned long long friendkey, unsigned long gamecode, int method);
extern void DWCi_Acc_U64ToString32(unsigned long long num, int bitnum, char *result);
#include "os_printf.h"
#include "mi_memory.h"
extern void DWCi_Acc_CreateTempLoginId(struct DWCstAccLoginId *loginid);
#include "util_wifiidtool.h"
#include "os_entropy.h"
extern int DWC_IsValidFriendData(void *p);
#include "dwc_init.h"
void DWCi_Acc_CreateUserData(struct DWCstAccUserData *userdata, unsigned long gamecode);
extern int DWCi_Acc_IsValidLoginId(void *loginid);
extern int DWC_Acc_FriendKeyToGsProfileId(unsigned long long friendkey, unsigned long gamecode);
void DWCi_Acc_LoginIdToUserName(struct DWCstAccLoginId *loginid, unsigned long gamecode, char *username);
int DWCi_Acc_SetMaskBits(unsigned long *ptr, unsigned long data, unsigned long shift, unsigned long mask);
unsigned long long DWCi_Acc_GetUserId(struct DWCstAccLoginId *loginId);
unsigned long DWCi_Acc_GetPlayerId(struct DWCstAccLoginId *loginId);
unsigned long long DWCi_Acc_GetFriendKey(struct DWCstAccFriendKeyData *data);
int DWCi_Acc_GetGsProfileId(struct DWCstAccGsProfileIdData *data);
void DWCi_Acc_SetUserId(struct DWCstAccLoginId *loginId, unsigned long long userId);
void DWCi_Acc_SetPlayerId(struct DWCstAccLoginId *loginId, int playerId);
void DWCi_Acc_SetFriendKey(struct DWCstAccFriendKeyData *data, unsigned long long friendKey);
void DWCi_Acc_SetGsProfileId(struct DWCstAccGsProfileIdData *data, int gsProfileId);
unsigned long DWCi_Acc_GetFlags(DWCstAccFlag *userdata);
BOOL DWC_IsBuddyFriendData(void *frienddata);
int DWCi_IsBuddyFriendData(void *frienddata);
int DWCi_IsReverseBuddyFriendData(void *frienddata);
int DWCi_IsBuddyMsgAlreadySent(void *frienddata);
unsigned long DWCi_Acc_GetFlagDataTypeThunk(void *userdata);
void DWCi_Acc_SetFlags(void *userdata, unsigned long flags);
void DWCi_Acc_SetFlag_DataType(void *userdata, int type);
void DWCi_SetBuddyFriendData(DWCstAccFriendData *frienddata);
void DWCi_SetReverseBuddyFlag(void *frienddata, int setflag);
void DWCi_SetExpIsBuddyFriendFlag(void *frienddata, int setflag);
void DWCi_SetSentBuddyReqFlag(void *frienddata, int setflag);
int DWC_CheckFriendKey(struct DWCstAccUserData *userdata, unsigned long long friendKey);
int DWCi_Acc_CheckConsoleUserId(struct DWCstAccLoginId *loginid);
int DWCi_Acc_IsAuthentic(void *userdata);
int DWC_IsValidFriendData(void *frienddata);
int DWCi_Acc_IsValidFriendDataThunk(void *frienddata);
void DWC_CreateUserData(void *userdata);
int DWC_CheckUserData(struct DWCstAccUserData *userdata);
int DWC_CheckValidConsole(struct DWCstAccUserData *userdata);
int DWC_CheckHasProfile(struct DWCstAccUserData *userdata);
void DWCi_Acc_SetLoginIdToUserData(struct DWCstAccUserData *userdata, struct DWCstAccLoginId *loginid, int gs_profile_id);
int DWC_CheckDirtyFlag(void *userdata);
int DWCi_Acc_IsDirty(void *userdata);
void DWC_ClearDirtyFlag(struct DWCstAccUserData *userdata);
void DWCi_Acc_ClearDirty(struct DWCstAccUserData *userdata);
unsigned long long DWC_GetFriendKey(void *frienddata);
int DWC_GetGsProfileId(struct DWCstAccUserData *userdata, void *frienddata);
unsigned long long DWC_CreateFriendKey(struct DWCstAccUserData *userdata);
void DWC_CreateFriendKeyToken(void *token, unsigned long long friend_key);
void DWC_CreateExchangeToken(struct DWCstAccUserData *userdata, void *token);
void DWC_SetGsProfileId(void *frienddata, int gs_profile_id);
void DWC_LoginIdToUserName(struct DWCstAccUserData *userdata, void *frienddata, char *username);
int DWC_IsEqualFriendData(void *frienddata1, void *frienddata2);
extern const char g_020A7FF4[];
extern const char g_020A8018[];

int DWCi_Acc_SetMaskBits(unsigned long *ptr, unsigned long data, unsigned long shift, unsigned long mask)
{
    if (data & ~mask)
        return 0;
    *ptr = (*ptr & ~(mask << shift)) | (data << shift);
    return 1;
}

unsigned long long DWCi_Acc_GetUserId(struct DWCstAccLoginId *loginId)
{
    return ((unsigned long long)(loginId->id_data & 0x7ff) << 32) | loginId->userid_lo32;
}

unsigned long DWCi_Acc_GetPlayerId(struct DWCstAccLoginId *loginId)
{
    return loginId->playerid;
}

unsigned long long DWCi_Acc_GetFriendKey(struct DWCstAccFriendKeyData *data)
{
    return ((unsigned long long)data->keyHigh << 32) | data->keyLow;
}

int DWCi_Acc_GetGsProfileId(struct DWCstAccGsProfileIdData *data)
{
    return data->gsProfileId;
}

void DWCi_Acc_SetUserId(struct DWCstAccLoginId *loginId, unsigned long long userId)
{
    DWCi_Acc_SetMaskBits(&loginId->id_data, (unsigned long)(userId >> 32), 0, 0x7ff);
    loginId->userid_lo32 = (unsigned long)userId;
}

void DWCi_Acc_SetPlayerId(struct DWCstAccLoginId *loginId, int playerId)
{
    loginId->playerid = playerId;
}

void DWCi_Acc_SetFriendKey(struct DWCstAccFriendKeyData *data, unsigned long long friendKey)
{
    data->keyLow = (unsigned long)friendKey;
    data->keyHigh = (unsigned long)(friendKey >> 32);
}

void DWCi_Acc_SetGsProfileId(struct DWCstAccGsProfileIdData *data, int gsProfileId)
{
    data->gsProfileId = gsProfileId;
}

unsigned long DWCi_Acc_GetFlags(DWCstAccFlag *userdata)
{
    return (userdata->raw >> 11) & 0x1fffff;
}

unsigned long DWCi_Acc_GetFlag_DataType(void *userdata)
{
    return DWCi_Acc_GetFlags(userdata) & 3;
}

/*
 * sdk:      DWC_IsBuddyFriendData (libdwcaccount.TWL.HYB.a dwc_account.o)
 */
BOOL DWC_IsBuddyFriendData(void *frienddata)
{
    return (DWCi_IsBuddyFriendData(frienddata) && DWCi_IsReverseBuddyFriendData(frienddata)) ? 1 : 0;
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

unsigned long DWCi_Acc_GetFlagDataTypeThunk(void *userdata)
{
    return DWCi_Acc_GetFlag_DataType(userdata);
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
void DWCi_SetBuddyFriendData(DWCstAccFriendData *frienddata)
{
    unsigned long flags;

    if (DWCi_Acc_GetFlag_DataType(frienddata) == 3) {
        flags = DWCi_Acc_GetFlags((DWCstAccFlag *)frienddata) | 4;
        DWCi_Acc_SetFlags(frienddata, flags);
    }
}

/*
 * sdk:      DWCi_SetReverseBuddyFlag (libdwcaccount.TWL.HYB.a(dwc_account.o))
 */
void DWCi_SetReverseBuddyFlag(void *frienddata, int setflag)
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
void DWCi_SetExpIsBuddyFriendFlag(void *frienddata, int setflag)
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
void DWCi_SetSentBuddyReqFlag(void *frienddata, int setflag)
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
unsigned long long DWC_Acc_CreateFriendKey(int gs_profile_id, unsigned long gamecode, int method)
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

int DWC_CheckFriendKey(struct DWCstAccUserData *userdata, unsigned long long friendKey)
{
    return DWC_Acc_CheckFriendKey(friendKey, userdata->gamecode, 1);
}

/*
 * sdk:      DWC_Acc_CheckFriendKey (libdwcaccount.TWL.HYB.a(dwc_account.o))
 */
int DWC_Acc_CheckFriendKey(unsigned long long friendkey, unsigned long gamecode, int method)
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
int DWC_Acc_FriendKeyToGsProfileId(unsigned long long friendkey, unsigned long gamecode)
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
void DWCi_Acc_U64ToString32(unsigned long long num, int bitnum, char *result)
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
void DWCi_Acc_LoginIdToUserName(struct DWCstAccLoginId *loginid, unsigned long gamecode, char *username)
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
void DWCi_Acc_CreateUserData(struct DWCstAccUserData *userdata, unsigned long gamecode)
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

void DWCi_Acc_CreateTempLoginId(struct DWCstAccLoginId *loginid)
{
    DWCAuthWiFiId authid;
    unsigned long buffer[8];
    MATHRandContext32 context;
    unsigned long i;

    OS_GetLowEntropyData((u32 *)buffer);
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
int DWCi_Acc_CheckConsoleUserId(struct DWCstAccLoginId *loginid)
{
    DWCAuthWiFiId authid;

    DWC_Auth_GetId(&authid);
    if (authid.flg) {
        return DWCi_Acc_GetUserId(loginid) == authid.uId;
    }
    return DWCi_Acc_GetUserId(loginid) == authid.notAttestedId;
}

/*
 * The ARM9 listing labels this address DWCi_Acc_IsValidLoginId; it calls DWCi_Acc_GetFlag_DataType, so it is a dwc_account.o static (the SDK table's DWC_GHTTPCleanupRootCAList attribution here does not match the linked bytes).
 */
int DWCi_Acc_IsValidLoginId(void *loginid)
{
    return DWCi_Acc_GetFlag_DataType(loginid) == 1;
}

int DWCi_Acc_IsAuthentic(void *userdata)
{
    return DWCi_Acc_IsValidLoginId((char *)userdata + 16);
}

int DWC_IsValidFriendData(void *frienddata)
{
    unsigned long type = DWCi_Acc_GetFlag_DataType(frienddata);
    return type != 0;
}

int DWCi_Acc_IsValidFriendDataThunk(void *frienddata)
{
    return DWC_IsValidFriendData(frienddata);
}

void DWC_CreateUserData(void *userdata)
{
    DWCi_Acc_CreateUserData(userdata, (long unsigned int)DWCi_GetGamecode());
}

/*
 * sdk:      DWC_CheckUserData (libdwcaccount.TWL.HYB.a(dwc_account.o))
 */
int DWC_CheckUserData(struct DWCstAccUserData *userdata)
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
int DWC_CheckValidConsole(struct DWCstAccUserData *userdata)
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
int DWC_CheckHasProfile(struct DWCstAccUserData *userdata)
{
    return DWCi_Acc_IsValidLoginId((char *)userdata + 0x10) && ((int *)userdata)[7] > 0;
}

/*
 * sdk:      DWCi_Acc_SetLoginIdToUserData (libdwcaccount.TWL.HYB.a(dwc_account.o))
 */
void DWCi_Acc_SetLoginIdToUserData(struct DWCstAccUserData *userdata, struct DWCstAccLoginId *loginid, int gs_profile_id)
{
    struct MATHCRC32Table table;

    userdata->authentic = *loginid;
    userdata->gs_profile_id = gs_profile_id;
    MATHi_CRC32InitTableRev(&table, 0xedb88320);
    userdata->crc32 = MATH_CalcCRC32(&table, userdata, 0x3c);
    userdata->flag |= 1;
}

int DWC_CheckDirtyFlag(void *userdata)
{
    return DWCi_Acc_IsDirty(userdata);
}

int DWCi_Acc_IsDirty(void *userdata)
{
    return (*(unsigned long *)((char *)userdata + 32) & 1) == 1;
}

void DWC_ClearDirtyFlag(struct DWCstAccUserData *userdata)
{
    DWCi_Acc_ClearDirty(userdata);
}

/*
 * sdk:      DWCi_Acc_ClearDirty (libdwcaccount.TWL.HYB.a(dwc_account.o))
 */
void DWCi_Acc_ClearDirty(struct DWCstAccUserData *userdata)
{
    struct MATHCRC32Table table;

    userdata->flag &= ~1;
    MATHi_CRC32InitTableRev(&table, 0xedb88320);
    userdata->crc32 = MATH_CalcCRC32(&table, userdata, 0x3c);
}

/*
 * sdk:      DWC_GetFriendKey (libdwcaccount.TWL.HYB.a(dwc_account.o))
 */
unsigned long long DWC_GetFriendKey(void *frienddata)
{
    if (DWCi_Acc_GetFlag_DataType(frienddata) != 2) {
        return 0;
    }
    return DWCi_Acc_GetFriendKey(frienddata);
}

/*
 * sdk:      DWC_GetGsProfileId (libdwcaccount.TWL.HYB.a(dwc_account.o))
 */
int DWC_GetGsProfileId(struct DWCstAccUserData *userdata, void *frienddata)
{
    unsigned long long friend_key;
    unsigned long type;

    type = DWCi_Acc_GetFlag_DataType(frienddata);
    switch (type) {
    case 2:
        friend_key = DWCi_Acc_GetFriendKey(frienddata);
        return DWC_Acc_FriendKeyToGsProfileId(friend_key, userdata->gamecode);
    case 3:
        return DWCi_Acc_GetGsProfileId(frienddata);
    case 1:
        return -1;
    }
    return 0;
}

/*
 * sdk:      DWC_CreateFriendKey (libdwcaccount.TWL.HYB.a(dwc_account.o))
 */
unsigned long long DWC_CreateFriendKey(struct DWCstAccUserData *userdata)
{
    unsigned long long ret = 0;

    if (userdata->gs_profile_id != 0) {
        ret = DWC_Acc_CreateFriendKey(userdata->gs_profile_id, userdata->gamecode, 1);
    }
    return ret;
}

/*
 * sdk:      DWC_CreateFriendKeyToken (libdwcaccount.TWL.HYB.a(dwc_account.o))
 */
void DWC_CreateFriendKeyToken(void *token, unsigned long long friend_key)
{
    MI_CpuFill8(token, 0, 12);
    DWCi_Acc_SetFriendKey(token, friend_key);
    DWCi_Acc_SetFlag_DataType(token, 2);
}

/*
 * sdk:      DWC_CreateExchangeToken (libdwcaccount.TWL.HYB.a(dwc_account.o))
 */
void DWC_CreateExchangeToken(struct DWCstAccUserData *userdata, void *token)
{
    MI_CpuFill8(token, 0, 12);
    if (!DWCi_Acc_IsAuthentic(userdata)) {
        *(struct DWCstAccLoginId *)token = userdata->pseudo;
        return;
    }
    DWCi_Acc_SetGsProfileId(token, userdata->gs_profile_id);
    DWCi_Acc_SetFlag_DataType(token, 3);
}

/*
 * sdk:      DWC_SetGsProfileId (libdwcaccount.TWL.HYB.a(dwc_account.o))
 */
void DWC_SetGsProfileId(void *frienddata, int gs_profile_id)
{
    MI_CpuFill8(frienddata, 0, 12);
    DWCi_Acc_SetGsProfileId(frienddata, gs_profile_id);
    DWCi_Acc_SetFlag_DataType(frienddata, 3);
}

void DWC_LoginIdToUserName(struct DWCstAccUserData *userdata, void *frienddata, char *username)
{
    DWCi_Acc_LoginIdToUserName(frienddata, userdata->gamecode, username);
}

/*
 * sdk:      DWC_IsEqualFriendData (libdwcaccount.TWL.HYB.a(dwc_account.o))
 */
int DWC_IsEqualFriendData(void *frienddata1, void *frienddata2)
{
    unsigned long type1;
    unsigned long type2;

    type1 = DWCi_Acc_GetFlag_DataType(frienddata1);
    type2 = DWCi_Acc_GetFlag_DataType(frienddata2);
    if (type1 != type2) {
        return 0;
    }
    if (type1 == 3) {
        return DWCi_Acc_GetGsProfileId(frienddata1) == DWCi_Acc_GetGsProfileId(frienddata2);
    } else if (type1 == 1) {
        if (DWCi_Acc_GetUserId(frienddata1) == DWCi_Acc_GetUserId(frienddata2)
            && DWCi_Acc_GetPlayerId(frienddata1) == DWCi_Acc_GetPlayerId(frienddata2)) {
            return 1;
        }
        return 0;
    } else if (type1 == 2) {
        return DWCi_Acc_GetFriendKey(frienddata1) == DWCi_Acc_GetFriendKey(frienddata2);
    }
    return 0;
}
