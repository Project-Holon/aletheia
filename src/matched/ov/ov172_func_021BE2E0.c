/*
 * function: func_021BE2E0
 * address:  0x021BE2E0
 * packet:   pkt_021B6100
 * region:   ov172
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail call to func_0204B3DC with the field at +0x1b0 and a zero.
 *
 * symbols:
 *   func_0204B3DC  0x0204B3DC  arm
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

struct Obj;
extern void func_0204B3DC(struct Obj *v, unsigned int zero);

void func_021BE2E0(void *p)
{
    func_0204B3DC((struct Obj *)*(u32 *)((char *)p + 0x1b0), 0);
}
