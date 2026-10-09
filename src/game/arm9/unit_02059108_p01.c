/*
 * file:     unit_02059108_p01.c
 * unit:     yes
 * function: func_02059108, func_0205911C, func_0205912C, func_0205915C, func_02059194, DWCi_IsBuddyMsgAlreadySent
 * address:  0x02059108
 * region:   arm9
 * compiler: 1.2
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
 */
typedef struct {
    unsigned int raw;
} DWCstAccFlag;

typedef unsigned char u8;

typedef int BOOL;

extern BOOL CTRDG_IsExisting(void);
extern BOOL CTRDGi_IsBitIDAtInit(u8 bitID);
extern unsigned long DWCi_Acc_GetFlag_DataType(void *frienddata);
unsigned long DWCi_Acc_GetFlags(DWCstAccFlag *userdata);
asm unsigned long func_0205911C(void *userdata);
BOOL func_0205912C(u8 bitID);
int DWCi_IsBuddyFriendData(void *frienddata);
int DWCi_IsReverseBuddyFriendData(void *frienddata);
int DWCi_IsBuddyMsgAlreadySent(void *frienddata);




unsigned long DWCi_Acc_GetFlags(DWCstAccFlag *userdata)
{
    return (userdata->raw >> 11) & 0x1fffff;
}




asm unsigned long func_0205911C(void *userdata)
{
    stmdb	sp!, {r3, lr}
    bl	DWCi_Acc_GetFlags
    and	r0, r0, #3
    ldmia	sp!, {r3, pc}
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
