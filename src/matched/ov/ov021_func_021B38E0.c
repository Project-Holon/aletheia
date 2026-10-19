/*
 * function: SCRCMD_PROC_FLD_BuildItemListByBadges
 * address:  0x021B38E0
 * packet:   pkt_ov021_021B38E0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Spill slots: the image puts the idx*4 offset at sp+4, q at sp+8, n at sp+0xc.
 * A single-def offset local is folded into a compiler temporary, and temps
 * take slots above every spilled local; the second (redundant) assignment in
 * the flag arm keeps off a real local, and declaration order (n, q, ..., off;
 * last declared lowest) gives the image layout.
 *
 * symbols:
 *   SCRCMD_PROC_FLD_BuildItemListByBadges 0x021B38E0 thumb
 *   func_02045B38 0x02045B38 arm
 *   FILE_UTIL_IsMachineItem 0x02021288 thumb
 *   BMP_MENUWORK_Create 0x0201F81C thumb
 *   SCRCMD_PROC_FLD_SetItemSlot 0x021B385C thumb ov021
 *   FILE_UTIL_GetItemParam 0x02020FE4 thumb
 *   GPOWER_ApplyShopPrice 0x0201102C thumb
 *   SCRCMD_PROC_FLD_LoadItemRows 0x021B3834 thumb ov021
 *   BMP_MENUWORK_AddMsgItem 0x0201F878 thumb
 *   MSGDATA_Delete 0x02045C04 arm
 *   d_021D946C 0x021D946C data
 *   d_021D95DE 0x021D95DE data
 *   d_021DE1A8 0x021DE1A8 data
 */
#include "../include/Obj00037.h"
#include "../include/Obj12843.h"

typedef unsigned char u8;
typedef unsigned short u16;

typedef unsigned int   u32;
struct MsgBank;
struct Rec;
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern u32 FILE_UTIL_IsMachineItem(u32 id);
extern void *BMP_MENUWORK_Create(int, int);
extern void SCRCMD_PROC_FLD_SetItemSlot(char *p, int idx, int mode, int val, int arg);
extern u32 FILE_UTIL_GetItemParam(void *a, u32 sel, u32 id);
extern u32 GPOWER_ApplyShopPrice(u32 v);
struct Slot;
extern u32 SCRCMD_PROC_FLD_LoadItemRows(u8 *p, int n);
extern void BMP_MENUWORK_AddMsgItem(struct Slot *table, u32 a, u32 b, u32 tag, u32 heap);
extern u32 MSGDATA_Delete(struct Rec *rec);

extern u8 d_021D946C[];
extern u8 d_021D95DE[];
extern u16 *d_021DE1A8[];

void SCRCMD_PROC_FLD_BuildItemListByBadges(char *p, int a, int b, int c)
{
    int n;
    void *q = func_02045B38(0, 2, 54, ((struct Obj00037 *)p)->f4);
    int idx;
    int k;
    int v;
    char *e;
    int off;

    if (a == 0xff) {
        idx = d_021D946C[c];
    } else {
        idx = b + 6;
    }
    off = idx * 4;
    if (FILE_UTIL_IsMachineItem(**(u16 **)((char *)d_021DE1A8 + off))) {
        ((struct Obj00037 *)p)->f162 = 1;
        off = idx * 4;
    }
    n = d_021D95DE[idx];
    ((struct Obj00037 *)p)->f180 = BMP_MENUWORK_Create(n + 1, ((struct Obj00037 *)p)->f4);
    for (k = 0; k < n; k++) {
        v = (*(u16 **)((char *)d_021DE1A8 + off))[k];
        SCRCMD_PROC_FLD_SetItemSlot(p, k, ((struct Obj00037 *)p)->f162, v, (int)q);
        e = p + k * 8;
        ((struct Obj12843 *)e)->f20 = v;
        ((struct Obj12843 *)e)->f24 = GPOWER_ApplyShopPrice(FILE_UTIL_GetItemParam((void *)v, 0, ((struct Obj00037 *)p)->f4));
    }
    ((struct Obj00037 *)p)->f160 = k;
    SCRCMD_PROC_FLD_LoadItemRows((u8 *)(p + 32), ((struct Obj00037 *)p)->f160);
    BMP_MENUWORK_AddMsgItem((struct Slot *)(*(char * *)&((struct Obj00037 *)p)->f180 + k * 8), (u32)(((struct Obj00037 *)p)->f188), 11, -2, ((struct Obj00037 *)p)->f4);
    MSGDATA_Delete(q);
}
