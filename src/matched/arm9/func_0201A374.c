/*
 * function: func_0201A374
 * address:  0x0201A374
 * packet:   pkt_0201A374
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0201EFA4   0x0201EFA4  thumb
 *   func_020457B0   0x020457B0  arm
 *   func_02045CAC   0x02045CAC  arm
 *   func_0201F250   0x0201F250  thumb
 *
 * Load one 0x40-byte sprite record whose mode word is chosen from the pair of
 * bytes at a0+2/+3: (1,6) selects 6, equal bytes select 7, a byte above 1
 * with 6 following selects 8 and anything else 9.  Both palette fields are
 * stamped through func_0201EFA4, the record is allocated against a4, its
 * slots are filled from *a2 through func_02045CAC and the pair is bound by
 * func_0201F250.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0201A374.c \
 *       --func func_0201A374 --addr 0x0201A374 --cc 1.1p1 --thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void  func_0201EFA4(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5);
struct U16Vec;
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void  func_02045CAC(u32 a0, u32 a1, u32 a2);
extern void  func_0201F250(u32 a0, void *a1, u32 a2);

void *func_0201A374(u8 *a0, u32 a1, u32 *a2, u32 a3, u16 a4)
{
    u32 mode;
    void *p;

    if (a0[2] == 1 && a0[3] == 6) {
        mode = 6;
    } else if (a0[2] == a0[3]) {
        mode = 7;
    } else if (a0[2] > 1 && a0[3] == 6) {
        mode = 8;
    } else {
        mode = 9;
    }
    func_0201EFA4(a1, 0, a0[2], 1, 0, 1);
    func_0201EFA4(a1, 1, a0[3], 1, 0, 1);
    p = func_020457B0(0x40, a4);
    func_02045CAC(*a2, mode, a3);
    func_0201F250(a1, p, a3);
    return p;
}
