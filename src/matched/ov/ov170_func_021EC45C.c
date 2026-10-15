/*
 * function: BOX2_SEQ_LoadIconResource
 * address:  0x021EC45C
 * packet:   pkt_ov170_021EC45C
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BOX2_SEQ_LoadGraphicResource 0x021EC338 thumb
 *   POKE_TOOL_GetIconPalette 0x0201BBE8 thumb
 *   BOX2_SEQ_SetSlotIconPal 0x021EC428 thumb
 *   func_020307B0 0x020307B0 arm
 *
 * Loads an icon resource for a, uploads it and frees the file.
 */
#include "../include/Obj24003.h"

extern void *BOX2_SEQ_LoadGraphicResource(char *p, void *b, void *c);
extern int POKE_TOOL_GetIconPalette(void *a);
extern void BOX2_SEQ_SetSlotIconPal(char *w, int a, int i, int b);
typedef unsigned int   u32;
extern u32 func_020307B0(void *p);

#define WORK(p) (*(char **)((p) + 0x2C))

void BOX2_SEQ_LoadIconResource(unsigned char *p, void *a, int i)
{
    void *d;
    void *res = BOX2_SEQ_LoadGraphicResource(WORK(p), a, &d);
    BOX2_SEQ_SetSlotIconPal(WORK(p), ((struct Obj24003 *)d)->f14, i, POKE_TOOL_GetIconPalette(a));
    func_020307B0(res);
}
