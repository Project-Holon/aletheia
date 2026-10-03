/*
 * function: func_021DB9FC
 * address:  0x021DB9FC
 * packet:   pkt_021DB9FC
 * region:   ov131
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
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
extern void func_0204B3DC(struct Obj *p, u32 v);

void func_021DB9FC(void *a, void *b, u8 *p)
{
    func_0204B3DC(*(void **)(p + 8), 0);
    func_0204B3DC(*(void **)(p + 0xc), 0);
}
