/*
 * file:     unit_02059858_p02.c
 * unit:     yes
 * function: func_0205987C, func_020598C4, func_020598EC, func_0205994C, func_02059980, func_020599BC, func_02059A10, func_02059A44, func_02059A5C
 * address:  0x0205987C
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   MATHi_CRC32InitTableRev          0x02081ac0 arm
 *   MATH_CalcCRC32                   0x02081bb8 arm
 *   DWCi_Acc_GetFlag_DataType        0x0205911c arm
 *   DWCi_Acc_GetFriendKey            0x020590ac arm
 *   DWC_Acc_FriendKeyToGsProfileId   0x020593b8 arm
 *   DWCi_Acc_GetGsProfileId          0x020590c0 arm
 *   DWC_Acc_CreateFriendKey          0x020592d0 arm
 *   MI_CpuFill8                      0x02082bcc arm
 *   DWCi_Acc_SetFriendKey            0x020590f8 arm
 *   DWCi_Acc_SetFlag_DataType        0x020591f0 arm
 *   DWCi_Acc_IsAuthentic             0x020596c8 arm
 *   DWCi_Acc_SetGsProfileId          0x02059100 arm
 *   DWCi_Acc_GetUserId               0x02059084 arm
 *   DWCi_Acc_GetPlayerId             0x020590a4 arm
 */
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

struct DWCstAccUserData_020598EC {
    unsigned char pad[0x24];
    unsigned long gamecode;
};

struct DWCstAccUserData_0205994C {
    unsigned char pad[0x1c];
    int gs_profile_id;
    unsigned long reserved;
    unsigned long gamecode;
};

typedef struct { unsigned char pad[36]; unsigned long gamecode; } DWCstAccUserData;

extern void MATHi_CRC32InitTableRev(struct MATHCRC32Table *table, unsigned long poly);
extern unsigned long MATH_CalcCRC32(struct MATHCRC32Table *table, void *data, unsigned long dataLength);
extern unsigned long DWCi_Acc_GetFlag_DataType(void *userdata);
extern unsigned long long DWCi_Acc_GetFriendKey(void *data);
extern int DWC_Acc_FriendKeyToGsProfileId(unsigned long long friendkey, unsigned long gamecode);
extern int DWCi_Acc_GetGsProfileId(void *data);
extern unsigned long long DWC_Acc_CreateFriendKey(int gs_profile_id, unsigned long gamecode, int method);
unsigned long long func_020598C4(void *frienddata);
extern void MI_CpuFill8(void *dstp, unsigned char data, unsigned long size);
extern void DWCi_Acc_SetFriendKey(void *data, unsigned long long friendkey);
extern void DWCi_Acc_SetFlag_DataType(void *userdata, int type);
extern int DWCi_Acc_IsAuthentic(struct DWCstAccUserData *userdata);
extern void DWCi_Acc_SetGsProfileId(void *data, int gs_profile_id);
extern void DWCi_Acc_LoginIdToUserName(void *loginid, unsigned long gamecode, char *username);
extern unsigned long long DWCi_Acc_GetUserId(void *userdata);
extern unsigned long DWCi_Acc_GetPlayerId(void *userdata);
void func_02059A10(void *frienddata, int gs_profile_id);
void DWC_LoginIdToUserName(DWCstAccUserData *userdata, void *frienddata, char *username);
int func_02059A5C(void *frienddata1, void *frienddata2);
void func_02059980(void *token, unsigned long long friend_key);



/*
 * sdk:      DWCi_Acc_ClearDirty (libdwcaccount.TWL.HYB.a(dwc_account.o))
 */
void func_0205987C(struct DWCstAccUserData *userdata)
{
    struct MATHCRC32Table table;

    userdata->flag &= ~1;
    MATHi_CRC32InitTableRev(&table, 0xedb88320);
    userdata->crc32 = MATH_CalcCRC32(&table, userdata, 0x3c);
}



/*
 * sdk:      DWC_GetFriendKey (libdwcaccount.TWL.HYB.a(dwc_account.o))
 */
unsigned long long func_020598C4(void *frienddata)
{
    if (DWCi_Acc_GetFlag_DataType(frienddata) != 2) {
        return 0;
    }
    return DWCi_Acc_GetFriendKey(frienddata);
}



/*
 * sdk:      DWC_GetGsProfileId (libdwcaccount.TWL.HYB.a(dwc_account.o))
 */
int func_020598EC(struct DWCstAccUserData_020598EC *userdata, void *frienddata)
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
unsigned long long func_0205994C(struct DWCstAccUserData_0205994C *userdata)
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
void func_02059980(void *token, unsigned long long friend_key)
{
    MI_CpuFill8(token, 0, 12);
    DWCi_Acc_SetFriendKey(token, friend_key);
    DWCi_Acc_SetFlag_DataType(token, 2);
}



/*
 * sdk:      DWC_CreateExchangeToken (libdwcaccount.TWL.HYB.a(dwc_account.o))
 */
void func_020599BC(struct DWCstAccUserData *userdata, void *token)
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
void func_02059A10(void *frienddata, int gs_profile_id)
{
    MI_CpuFill8(frienddata, 0, 12);
    DWCi_Acc_SetGsProfileId(frienddata, gs_profile_id);
    DWCi_Acc_SetFlag_DataType(frienddata, 3);
}


void DWC_LoginIdToUserName(DWCstAccUserData *userdata, void *frienddata, char *username)
{
    DWCi_Acc_LoginIdToUserName(frienddata, userdata->gamecode, username);
}


/*
 * sdk:      DWC_IsEqualFriendData (libdwcaccount.TWL.HYB.a(dwc_account.o))
 */
int func_02059A5C(void *frienddata1, void *frienddata2)
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
