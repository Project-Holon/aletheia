/*
 * file:     unit_021F4560_p04.c
 * unit:     yes
 * function: func_021F5F74, func_021F5FB0, func_021F6148
 * address:  0x021F5F74
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
 *   OS_Terminate                     0x02088234 arm
 *   MBi_CommEnd                      0x021f5ee4 arm
 *   OS_RestoreInterrupts             0x0208799c arm
 *   d_021F6F90                       0x021F6F90 data
 *   func_0208F938  0x0208F938  arm
 *   func_02082BCC  0x02082BCC  arm
 *   func_021F6850  0x021F6850  arm  ov107
 *   func_021F46C8  0x021F46C8  arm  ov107
 *   g_021F6F90     0x021F6F90  data
 *   mbiScanParam   0x021F6FC0  data
 */
#include "../../matched/include/G_WmBase.h"

#define FILEINFO(id)     (((MBiFileSlot *)((u8 *)((MBiParam *)g_021F6F90.ext) + (id) * sizeof(MBiFileInfo)))->fi)
typedef unsigned long u32;

typedef unsigned char  u8;

typedef signed char    s8;

typedef unsigned short u16;

typedef struct MBiFileInfo {
    u8 pad0[0x5c4];
    u16 gameinfo_child_bmp;
    u16 active_child_bmp;
    u16 update_child_bmp;
    u8 pad5ca[0x5d4 - 0x5ca];
} MBiFileInfo;

typedef struct MBiParam {
    u8 pad0[0x1340];
    u8 childInfo[15][0x16];
    u16 childversion[15];
    u32 childggid[15];
    u32 p_comm_state_cb;
    u32 p_comm_state[15];
    u8 pad1524[2];
    s8 req_fid[15];
    u8 req_num;
    u16 req_bmp;
    u8 pad1538[0x1754 - 0x1538];
    u16 child_seq[15];
    u8 pad1772[0x1788 - 0x1772];
    MBiFileInfo fileinfo[16];
} MBiParam;

/*
 * The object adds fid * 0x5d4 to mbc before the member offset (0x1788 +
 * field); `mbc->fileinfo[fid].field` folds the constant first and indexes
 * last (48 bytes differ).  Stepping mbc by whole file slots reproduces it.
 */
typedef struct MBiFileSlot {
    u8 pad0[0x1788];
    MBiFileInfo fi;
} MBiFileSlot;

extern u32 OS_DisableInterrupts(void);
extern void OS_Terminate(void);
extern int MBi_CommEnd(void);
extern u32 OS_RestoreInterrupts(u32 state);
extern int func_0208F938(void (*callback)(void *), u16 aid);
extern void func_02082BCC(void *dstp, u8 data, u32 size);
extern void func_021F6850(u16 child_aid);
extern void func_021F46C8(void *arg);
void MB_EndToIdle(void);
void func_021F5FB0(u16 aid);
void MBi_SetMaxScanTime(u16 time);
extern struct WmBase d_021F6F90;
extern struct WmBase g_021F6F90;
extern char mbiScanParam[];


void MB_EndToIdle(void)
{
    u32 enabled = OS_DisableInterrupts();

    if (*(u32 *)(*(char **)(((char *)&d_021F6F90) + 0x10) + 0x1320) == 0)
        OS_Terminate();
    MBi_CommEnd();
    OS_RestoreInterrupts(enabled);
}


void func_021F5FB0(u16 aid)
{

    func_0208F938(func_021F46C8, aid);
    if (aid == 0 || aid >= 16)
        return;
    ((MBiParam *)g_021F6F90.ext)->childversion[aid - 1] = 0;
    func_02082BCC(&((MBiParam *)g_021F6F90.ext)->childggid[aid - 1], 0, sizeof(u32));
    func_02082BCC(((MBiParam *)g_021F6F90.ext)->childInfo[aid - 1], 0, 0x16);
    func_021F6850(aid);
    ((MBiParam *)g_021F6F90.ext)->child_seq[aid - 1] = 0;
    if (((MBiParam *)g_021F6F90.ext)->req_fid[aid - 1] != -1) {
        u8 fid = (u8)((MBiParam *)g_021F6F90.ext)->req_fid[aid - 1];
        u16 child = aid;

        FILEINFO(fid).active_child_bmp &= (u16)~(1 << child);
        FILEINFO(fid).update_child_bmp |= (u16)(1 << child);
        ((MBiParam *)g_021F6F90.ext)->req_fid[child - 1] = -1;
        FILEINFO(fid).gameinfo_child_bmp &= (u16)~(1 << child);
    }
    if (((MBiParam *)g_021F6F90.ext)->req_bmp & (1 << aid)) {
        ((MBiParam *)g_021F6F90.ext)->req_num--;
        ((MBiParam *)g_021F6F90.ext)->req_bmp &= (u16)~(1 << aid);
    }
    ((MBiParam *)g_021F6F90.ext)->p_comm_state[aid - 1] = 0;
}


void MBi_SetMaxScanTime(u16 time)
{
    *(u16 *)(mbiScanParam + 8) = time;
}
