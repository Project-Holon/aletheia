/*
 * function: func_021DD3DC
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
 *   func_021DD314  0x021DD314  thumb  ov170
 *   func_021EDAB0  0x021EDAB0  thumb  ov170
 *   POKE_TOOL_GetBoxParam  0x020185F4  thumb  arm9
 *
 * Rebuild the row then forward it and the two tag shorts; the
 *   three callers share p[0x14] as the id.
 */
#include "../include/Obj00000.h"
#include "../include/Obj09221.h"


typedef unsigned int u32;

extern void *func_0201AB28(void *p, u32 idx);
extern void *POKE_TOOL_GetBoxParam(void *p);
struct Sub020075B0Entry;
extern int func_020075B0(void *save, u32 box, u32 slot, const struct Sub020075B0Entry *src);
extern void func_021DD314(char **p, int a, unsigned b);
extern void func_021EDAB0(char *, int);
void func_021DD3DC(char *p, unsigned char *a)
{
    int x = (int)POKE_TOOL_GetBoxParam(func_0201AB28(*(void **)(*(int *)&((struct Obj00000 *)p)->f0 + 8),
                                        ((struct Obj09221 *)a)->f4 - 0x1e));
    func_020075B0((void *)(*(int *)(*(int *)&((struct Obj00000 *)p)->f0 + 4)), ((struct Obj00000 *)p)->f14,
                  ((struct Obj09221 *)a)->f2, (const struct Sub020075B0Entry *)x);
    func_021DD314((char **)p, ((struct Obj00000 *)p)->f14, ((struct Obj09221 *)a)->f4);
    func_021EDAB0(p, ((struct Obj00000 *)p)->f14);
}
