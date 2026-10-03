/*
 * function: func_021DB7B8
 * address:  0x021DB7B8
 * packet:   pkt_021DB7B8
 * region:   ov131
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0204B3B4  0x0204B3B4  arm
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

struct Obj;
extern void func_0204B3B4(struct Obj *p);

void func_021DB7B8(void *a, void *b, u8 *p)
{
    func_0204B3B4(*(void **)(p + 8));
    func_0204B3B4(*(void **)(p + 0xc));
    *(u8 *)p = 0xff;
}
