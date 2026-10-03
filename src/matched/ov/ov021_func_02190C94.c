/*
 * function: func_02190C94
 * address:  0x02190C94
 * packet:   pkt_ov021_02190C94
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02030734  0x02030734  arm
 *   d_021DDA50     0x021DDA50  data   ov021  a1
 *   func_0201CD10  0x0201CD10  thumb
 *   func_02190D08  0x02190D08  thumb  ov021
 *   func_02193200  0x02193200  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef short          s16;

extern char d_021DDA50[];

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u32 func_0201CD10(u32 a, s16 b, s16 c, u32 d, u32 e, u32 f, u32 g, u32 h,
                         u32 i, u32 j, void *k);
extern int func_02190D08(int x);
extern void func_02193200(u32 a);

u32 *func_02190C94(u32 *a, u32 b, u32 c, u32 d, s16 e0, u32 f, u16 g)
{
    u32 *r;

    r = (u32 *)func_02030734(*(u16 *)a, 0xc, 1, d_021DDA50, 0x85e);
    r[2] = (u32)a;
    *(u16 *)((u8 *)r + 2) = f;
    r[1] = func_0201CD10(c, d, e0, b, a[2], f, a[0x59], 0, *(u16 *)a, g,
                         (void *)func_02190D08);
    func_02193200(r[2] + 0x160);
    return r;
}
