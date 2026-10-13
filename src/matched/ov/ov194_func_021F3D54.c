/*
 * function: func_021F3D54
 * address:  0x021F3D54
 * packet:   pkt_021F3D54
 * region:   ov194
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   STRBUF_Delete  0x02045808  arm  arm9
 * Addresses are Black-image addresses.
 */
#include "../include/Obj14504.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
struct Descriptor;
struct U16Vec;
extern u32 func_020452E8(struct Descriptor *d);
extern void STRBUF_Delete(struct U16Vec *vec);
extern void func_02082BCC(u8 *, u32, u32);

void func_021F3D54(u8 *p)
{
    func_020452E8((struct Descriptor *)(((struct Obj14504 *)p)->f14));
    STRBUF_Delete((struct U16Vec *)(((struct Obj14504 *)p)->f1C));
    func_02082BCC(p, 0, 0x24);
}

