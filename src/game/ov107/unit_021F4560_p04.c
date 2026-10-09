/*
 * file:     unit_021F4560_p04.c
 * unit:     yes
 * function: MBi_CommEnd, func_021F5F74, func_021F5FB0, func_021F6148, func_021F6158, func_021F61A4, func_021F628C, func_021F62A0, func_021F62B4, MBi_IsStarted, MBi_CheckWmErrcode
 * address:  0x021F5EE4
 * region:   ov107
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   OS_DisableInterrupts             0x02087988 arm
 *   MBi_EndCommon                    0x021f4684 arm
 *   MBi_IsTaskAvailable              0x021f6610 arm
 *   MBi_EndTaskThread                0x021f67bc arm
 *   MBi_CallReset                    0x021f5ea0 arm
 *   OS_RestoreInterrupts             0x0208799c arm
 *   d_021F6F90                       0x021F6F90 data
 *   MBi_OnReset                      0x021f5ed8 arm
 *   OS_Terminate                     0x02088234 arm
 *   func_0208F938  0x0208F938  arm
 *   func_02082BCC  0x02082BCC  arm
 *   func_021F6850  0x021F6850  arm  ov107
 *   func_021F46C8  0x021F46C8  arm  ov107
 *   mbiScanParam   0x021F6FC0  data
 *   WM_SetMPDataToPortEx             0x0208fcb4 arm
 *   func_021F6158 0x021F6158 arm ov107
 *   func_021F4EFC 0x021F4EFC arm ov107
 */
#include "mb_wm.h"

typedef struct MBiFileSlot {
    u8 pad0[0x1788];
    MBiParentFileInfo fi;
} MBiFileSlot;

extern u32 OS_DisableInterrupts(void);
extern void MBi_EndCommon(void *arg);
extern int MBi_IsTaskAvailable(void);
extern void MBi_EndTaskThread(void (*callback)(struct MBiTaskInfo *));
extern int MBi_CallReset(void);
extern u32 OS_RestoreInterrupts(u32 state);
extern void MBi_OnReset(void);
extern void OS_Terminate(void);
extern int func_0208F938(void (*callback)(void *), u16 aid);
extern void func_02082BCC(void *dstp, u8 data, u32 size);
extern void func_021F6850(u16 child_aid);
extern void func_021F46C8(void *arg);
extern int WM_SetMPDataToPortEx(void (*callback)(void *), void *arg, u16 *sendData, u16 sendDataSize, u16 destBitmap, u16 port, u16 prio);
extern int func_021F6158(void *callback, unsigned short *sendData, unsigned short sendDataSize, unsigned short arg3, unsigned short pollbmp);
extern void func_021F4EFC(void *arg);
int MBi_CommEnd(void);
void MB_EndToIdle(void);
void func_021F5FB0(u16 aid);
void MBi_SetMaxScanTime(u16 time);
int func_021F61A4(unsigned short *buf, int len, int pollbmp);
u32 MBi_GetGgid(void);
u16 MB_GetTgid(void);
unsigned char MBi_GetAttribute(void);
int MBi_IsStarted(void);
void MBi_CheckWmErrcode(u16 apiid, int errcode);


/*
 * The object adds fid * 0x5d4 to mbc before the member offset (0x1788 +
 * field); `mbc->fileinfo[fid].field` folds the constant first and indexes
 * last (48 bytes differ).  Stepping mbc by whole file slots reproduces it.
 */
#define FILEINFO(id)     (((MBiFileSlot *)((u8 *)((MBCommPWork *)mbWm.ext) + (id) * sizeof(MBiParentFileInfo)))->fi)






int MBi_CommEnd(void)
{
    int ret = 1;
    u32 enabled;

    enabled = OS_DisableInterrupts();
    if (*(u8 *)(*(char **)(d_021F6F90 + 0xC) + 0x50D) == 0) {
        MBi_EndCommon(0);
    } else if (*(u16 *)(*(char **)(d_021F6F90 + 0xC) + 0x526) == 0) {
        *(u32 *)(*(char **)(d_021F6F90 + 0xC) + 0x5E4) = 0;
        *(u16 *)(*(char **)(d_021F6F90 + 0xC) + 0x526) = 1;
        if (MBi_IsTaskAvailable()) {
            MBi_EndTaskThread((void (*)(struct MBiTaskInfo *))MBi_OnReset);
            ret = 0;
        } else {
            ret = MBi_CallReset();
        }
    }
    OS_RestoreInterrupts(enabled);
    return ret;
}







void MB_EndToIdle(void)
{
    u32 enabled = OS_DisableInterrupts();

    if (*(u32 *)(*(char **)(d_021F6F90 + 0x10) + 0x1320) == 0)
        OS_Terminate();
    MBi_CommEnd();
    OS_RestoreInterrupts(enabled);
}







void func_021F5FB0(u16 aid)
{

    func_0208F938(func_021F46C8, aid);
    if (aid == 0 || aid >= 16)
        return;
    ((MBCommPWork *)mbWm.ext)->childversion[aid - 1] = 0;
    func_02082BCC(&((MBCommPWork *)mbWm.ext)->childggid[aid - 1], 0, sizeof(u32));
    func_02082BCC(&((MBCommPWork *)mbWm.ext)->childUser[aid - 1], 0, 0x16);
    func_021F6850(aid);
    ((MBCommPWork *)mbWm.ext)->req2child[aid - 1] = 0;
    if (((MBCommPWork *)mbWm.ext)->fileid_of_child[aid - 1] != -1) {
        u8 fid = (u8)((MBCommPWork *)mbWm.ext)->fileid_of_child[aid - 1];
        u16 child = aid;

        FILEINFO(fid).gameinfo_child_bmp &= (u16)~(1 << child);
        FILEINFO(fid).gameinfo_changed_bmp |= (u16)(1 << child);
        ((MBCommPWork *)mbWm.ext)->fileid_of_child[child - 1] = -1;
        FILEINFO(fid).pollbmp &= (u16)~(1 << child);
    }
    if (((MBCommPWork *)mbWm.ext)->child_entry_bmp & (1 << aid)) {
        ((MBCommPWork *)mbWm.ext)->child_num--;
        ((MBCommPWork *)mbWm.ext)->child_entry_bmp &= (u16)~(1 << aid);
    }
    ((MBCommPWork *)mbWm.ext)->p_comm_state[aid - 1] = 0;
}







void MBi_SetMaxScanTime(u16 time)
{
    mbiScanParam.maxChannelTime = time;
}






static int MBi_SetMPData(void (*callback)(void *), u16 *sendData, u16 sendDataSize, u16 unused, u16 pollbmp)
{
    int errcode;

    errcode = WM_SetMPDataToPortEx(callback, 0, sendData, sendDataSize, pollbmp, 1, 3);
    MBi_CheckWmErrcode(0xF, errcode);
    return errcode;
}






/*
 * sdk:      MBi_SendMP (libmb.TWL.HYB.a(mb_wm_base.o))
 */
int func_021F61A4(unsigned short *buf, int len, int pollbmp)
{
    unsigned short size = len;
    unsigned short pollbitmap = pollbmp;
    int errcode;

    if (*(unsigned short *)((u8 *)mbWm.work + 0x528) == 0 || *(unsigned short *)((u8 *)mbWm.work + 0x526) == 1) {
        return 1;
    }
    switch (*(unsigned short *)((u8 *)mbWm.work + 0x524)) {
    case 1:
        errcode = func_021F6158(*(void **)((u8 *)mbWm.work + 0x508), buf, size, *(unsigned short *)((u8 *)mbWm.work + 0x52C) == 0 ? 0x3E8 : 0, pollbitmap);
        if (errcode == 2) {
            ((u8 *)mbWm.work)[0x50C] = 1;
        }
        return errcode == 2 ? 0 : errcode;
    case 2:
        errcode = func_021F6158(func_021F4EFC, buf, size, 0, pollbitmap);
        if (errcode == 2) {
            ((u8 *)mbWm.work)[0x50C] = 1;
        }
        return errcode == 2 ? 0 : errcode;
    }
    return 1;
}






u32 MBi_GetGgid(void)
{
    return *(u32 *)(*(char **)(d_021F6F90 + 0xC) + 8);
}





u16 MB_GetTgid(void)
{
    return *(u16 *)(*(char **)(d_021F6F90 + 0xC) + 0xC);
}





unsigned char MBi_GetAttribute(void)
{
    char *base = *(char **)(d_021F6F90 + 0xC);

    return (*(u16 *)(base + 0xE) ? 1 : 0) | (*(u16 *)(base + 0x12) ? 2 : 0) |
           (*(u16 *)(base + 0x14) ? 4 : 0) | (*(u16 *)(base + 0x16) ? 8 : 0);
}



int MBi_IsStarted(void)
{
    return *(u8 *)(*(char **)(d_021F6F90 + 0xC) + 0x50D) == 1;
}


void MBi_CheckWmErrcode(u16 apiid, int errcode)
{
    struct
    {
        u16 apiid;
        u16 errcode;
    } arg;
    void (*callback)(int, void *);

    if (errcode == 2 || errcode == 0)
        return;

    arg.apiid = apiid;
    arg.errcode = (u16)errcode;
    callback = *(void (**)(int, void *))(*(char **)(d_021F6F90 + 0xC) + 0x51C);
    callback(0xFF, &arg);
}
