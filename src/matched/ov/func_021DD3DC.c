/*
 * function: BOX2_MAIN_GetBoxMon
 * address:  0x021DD3DC
 * packet:   pkt_021DC9A0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BOX2_MAIN_ClearSlot  0x021DD314  thumb  ov170
 *   BOX2_UI_DrawSlot  0x021EDAB0  thumb  ov170
 *   POKE_TOOL_GetBoxParam  0x020185F4  thumb  arm9
 *   POKEPARTY_GetMember  0x0201AB28  thumb  arm9
 *
 * Rebuild the row then forward it and the two tag shorts; the
 *   three callers share p[0x14] as the id.
 */
#include "../include/Obj00000.h"
#include "../include/Obj09221.h"


typedef unsigned int u32;

extern void *POKEPARTY_GetMember(void *p, u32 idx);
extern void *POKE_TOOL_GetBoxParam(void *p);
struct Sub020075B0Entry;
extern int func_020075B0(void *save, u32 box, u32 slot, const struct Sub020075B0Entry *src);
extern void BOX2_MAIN_ClearSlot(char **p, int a, unsigned b);
extern void BOX2_UI_DrawSlot(char *, int);
void BOX2_MAIN_GetBoxMon(char *p, unsigned char *a)
{
    int x = (int)POKE_TOOL_GetBoxParam(POKEPARTY_GetMember(*(void **)(*(int *)&((struct Obj00000 *)p)->f0 + 8),
                                        ((struct Obj09221 *)a)->f4 - 0x1e));
    func_020075B0((void *)(*(int *)(*(int *)&((struct Obj00000 *)p)->f0 + 4)), ((struct Obj00000 *)p)->f14,
                  ((struct Obj09221 *)a)->f2, (const struct Sub020075B0Entry *)x);
    BOX2_MAIN_ClearSlot((char **)p, ((struct Obj00000 *)p)->f14, ((struct Obj09221 *)a)->f4);
    BOX2_UI_DrawSlot(p, ((struct Obj00000 *)p)->f14);
}
