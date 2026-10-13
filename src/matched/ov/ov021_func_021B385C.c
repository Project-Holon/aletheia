/*
 * function: SCRCMD_PROC_FLD_SetItemSlot
 * address:  0x021B385C
 * packet:   pkt_ov021_021B385C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   SCRCMD_PROC_FLD_SetItemSlot 0x021B385C thumb
 *   func_0201EFA4 0x0201EFA4 thumb
 *   func_020212B0 0x020212B0 thumb
 *   func_0201EF34 0x0201EF34 thumb
 *   func_0201F250 0x0201F250 thumb
 *   BMP_MENUWORK_AddStrItem 0x0201F898 thumb
 *   BMP_MENUWORK_AddMsgItem 0x0201F878 thumb
 */
#include "../include/Obj00037.h"

typedef unsigned short u16;

typedef unsigned int   u32;
struct WordSet;
extern void func_0201EFA4(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern u16 func_020212B0(u16 id);
extern void func_0201EF34(struct WordSet *p, u32 i, u32 v);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
struct Slot;
extern void BMP_MENUWORK_AddStrItem(struct Slot *table, u32 a, u32 b, u32 tag);
extern void BMP_MENUWORK_AddMsgItem(struct Slot *table, u32 a, u32 b, u32 tag, u32 heap);

void SCRCMD_PROC_FLD_SetItemSlot(char *p, int idx, int mode, int val, int arg)
{
    if (mode == 1) {
        func_0201EFA4(((struct Obj00037 *)p)->f190, 0, val - 327, 2, 2, 1);
        func_0201EF34(((struct Obj00037 *)p)->f190, 1, func_020212B0(val));
        func_0201F250(((struct Obj00037 *)p)->f190, ((struct Obj00037 *)p)->f198, ((struct Obj00037 *)p)->f19C);
        BMP_MENUWORK_AddStrItem((struct Slot *)(*(char * *)&((struct Obj00037 *)p)->f180 + idx * 8), (u32)(((struct Obj00037 *)p)->f198), idx, ((struct Obj00037 *)p)->f4);
    } else {
        BMP_MENUWORK_AddMsgItem((struct Slot *)(*(char * *)&((struct Obj00037 *)p)->f180 + idx * 8), arg, val, idx, ((struct Obj00037 *)p)->f4);
    }
}
