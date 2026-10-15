/*
 * function: SHINKA_DEMO_SetMenuText
 * address:  0x022055BC
 * packet:   pkt_022055BC
 * region:   ov195
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   SHINKA_DEMO_BuildString 0x02205620 thumb ov195
 *   STRBUF_Delete 0x02045808 arm
 */
#include "../include/Obj03903.h"

typedef unsigned short u16;
typedef unsigned int u32;

extern u32 SHINKA_DEMO_BuildString(u32, u32, u32, u32, u32, u32, u32);
struct U16Vec;
extern void STRBUF_Delete(struct U16Vec *vec);

void SHINKA_DEMO_SetMenuText(char *a, u32 a1, u32 a2, u32 k0, u32 v0, u32 k1, u32 v1,
                   u32 b1, u32 b2, u32 m0, u32 w0, u32 m1, u32 w1)
{
    if (((struct Obj03903 *)a)->f94 != 0)
        STRBUF_Delete((struct U16Vec *)(((struct Obj03903 *)a)->f94));
    if (((struct Obj03903 *)a)->f98 != 0)
        STRBUF_Delete((struct U16Vec *)(((struct Obj03903 *)a)->f98));
    ((struct Obj03903 *)a)->f94 = SHINKA_DEMO_BuildString(((struct Obj03903 *)a)->f2, a1, a2, k0, v0, k1, v1);
    ((struct Obj03903 *)a)->f98 = SHINKA_DEMO_BuildString(((struct Obj03903 *)a)->f2, b1, b2, m0, w0, m1, w1);
}
