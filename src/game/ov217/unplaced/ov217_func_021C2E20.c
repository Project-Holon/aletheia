/*
 * function: func_021C2E20
 * address:  0x021C2E20
 * packet:   pkt_021C2E20
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Releases the object at field 0xc through an SDK destructor and clears
 * field 4.  The callee is ENV_SetResourceSet (ARM), one of several SDK
 * copies of that symbol; pinned by address below.
 *
 * symbols:
 *   ENV_SetResourceSet  0x020307B0  arm
 *
 * Addresses are Black-image addresses.
 */
#include "../../../matched/include/Obj14769.h"

typedef unsigned int u32;

extern void ENV_SetResourceSet(u32 p);

void func_021C2E20(char *p)
{
    ENV_SetResourceSet(((struct Obj14769 *)p)->fC);
    ((struct Obj14769 *)p)->f4 = 0;
}
