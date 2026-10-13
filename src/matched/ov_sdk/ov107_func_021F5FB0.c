/*
 * function: func_021F5FB0
 * address:  0x021F5FB0
 * packet:   pkt_ov107_021F5FB0
 * region:   ov107
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      MB_DisconnectChild (libmb.TWL.HYB.a(mb_wm_base.o))
 *
 * symbols:
 *   WM_Disconnect  0x0208F938  arm
 *   MI_CpuFill8  0x02082BCC  arm
 *   func_021F6850  0x021F6850  arm  ov107
 *   func_021F46C8  0x021F46C8  arm  ov107
 *   g_021F6F90     0x021F6F90  data
 *
 * mb_wm_base.o's statics sit in one block; the vendor reaches mbc (block
 * +0x10, 0x021F6FA0) through one pool word anchored at WM_DMA_NO
 * (0x021F6F90), so the block is a struct overlay named by offset.
 */

#include "../include/G_WmBase.h"

typedef unsigned char  u8;
typedef signed char    s8;
typedef unsigned short u16;
typedef unsigned long  u32;

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
#define FILEINFO(id)     (((MBiFileSlot *)((u8 *)((MBiParam *)g_021F6F90.ext) + (id) * sizeof(MBiFileInfo)))->fi)

extern int WM_Disconnect(void (*callback)(void *), u16 aid);
extern void MI_CpuFill8(void *dstp, u8 data, u32 size);
extern void func_021F6850(u16 child_aid);
extern void func_021F46C8(void *arg);
extern struct WmBase g_021F6F90;

void func_021F5FB0(u16 aid)
{

    WM_Disconnect(func_021F46C8, aid);
    if (aid == 0 || aid >= 16)
        return;
    ((MBiParam *)g_021F6F90.ext)->childversion[aid - 1] = 0;
    MI_CpuFill8(&((MBiParam *)g_021F6F90.ext)->childggid[aid - 1], 0, sizeof(u32));
    MI_CpuFill8(((MBiParam *)g_021F6F90.ext)->childInfo[aid - 1], 0, 0x16);
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
