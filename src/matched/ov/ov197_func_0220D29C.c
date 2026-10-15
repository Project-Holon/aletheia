/*
 * function: B_BAG_MAIN_StateStartMessage
 * address:  0x0220D29C
 * packet:   pkt_0220D29C
 * region:   ov197
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BMP_MENUWORK_DrawWindowBorder 0x0201F7A8 thumb
 */
#include "../include/Obj25087.h"

typedef unsigned int   u32;
extern void BMP_MENUWORK_DrawWindowBorder(void *desc, u32 kind);

int B_BAG_MAIN_StateStartMessage(char *a)
{
    BMP_MENUWORK_DrawWindowBorder((void *)(((struct Obj25087 *)a)->f24), 0);
    return 6;
}