/*
 * function: MYSTERY_UTIL_DeleteWindow
 * address:  0x021D9A40
 * packet:   pkt_021D9A40
 * region:   ov121
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BMP_WIN_Delete  0x020452E8  arm
 *   STRBUF_Delete  0x02045808  arm
 *   func_020307B0  0x020307B0  arm
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj13950.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

struct Descriptor;
struct U16Vec;
extern u32 BMP_WIN_Delete(struct Descriptor *d);
extern void STRBUF_Delete(struct U16Vec *vec);
extern u32 func_020307B0(void *p);

void MYSTERY_UTIL_DeleteWindow(u8 *p)
{
    BMP_WIN_Delete(((struct Obj13950 *)p)->fC);
    STRBUF_Delete(((struct Obj13950 *)p)->f10);
    func_020307B0(p);
}
