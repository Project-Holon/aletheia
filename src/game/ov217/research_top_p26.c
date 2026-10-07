/*
 * file:     research_top_p26.c
 * unit:     yes
 * function: func_021BEAF8, func_021BEB40
 * address:  0x021BEAF8
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021BF810 0x021BF810 thumb ov217
 *   func_021BF5D0 0x021BF5D0 thumb ov217
 *   func_021BEBE4 0x021BEBE4 thumb ov217
 *   func_021BEBC0 0x021BEBC0 thumb ov217
 *   func_021BF594  0x021BF594  thumb  ov217
 *   func_021BF5BC  0x021BF5BC  thumb  ov217
 */
#include "../../matched/include/Obj00021.h"
#include "../../matched/include/Obj25912.h"

typedef unsigned char u8;

typedef unsigned int u32;

typedef unsigned short u16;

typedef signed char    s8;

typedef signed short   s16;

typedef signed int     s32;

extern u32 func_021BF810(void *p);
extern u32 func_021BF5D0(u8 *, u32);
extern u32 func_021BEBE4(u32);
extern u32 func_021BEBC0(u32);
extern void func_02025A54(u8 *g, u32 a);
extern u32 func_021BF594();
extern void func_021BF5BC(u8 *a0, u32 a1);
void func_021BEAF8(u8 *p);
u32 func_021BEB40(u32 a0);

void func_021BEAF8(u8 *p)
{
    if (((struct Obj00021 *)p)->f3C8 == 1 || ((struct Obj00021 *)p)->f3D0 == 1 || func_021BF810(p) == 0) {
        if (func_021BF5D0(p, 5) == 0) func_021BEBE4((u32)p);
    } else {
        if (func_021BF5D0(p, 5) == 1) func_021BEBC0((u32)p);
    }
}

/*
 * Reconstructed from the listing (.inst decoded).
 *
 * Addresses are Black-image addresses.
 */
u32 func_021BEB40(u32 a0)
{
    func_02025A54((u8 *)(((struct Obj25912 *)(((u8*)a0)))->f3AC), 0);
    func_021BF5BC((u8 *)a0, 5);
    func_021BF5BC((u8 *)a0, 6);
    return func_021BF594(a0, 2);
}
