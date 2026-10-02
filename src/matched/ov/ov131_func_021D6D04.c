/*
 * function: func_021D6D04
 * address:  0x021D6D04
 * packet:   pkt_021D6D04
 * region:   ov131
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021D797C  0x021D797C  thumb
 *   func_0204B3DC  0x0204B3DC  arm
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

extern void func_021D797C(u8 *p, void **q);
extern void func_0204B3DC(void *, int);

void func_021D6D04(void *a, u8 *p)
{
    func_021D797C(a, (void **)p);
    func_0204B3DC(*(void **)(p + 0x20), 0);
}
