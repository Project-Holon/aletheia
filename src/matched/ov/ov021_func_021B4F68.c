/*
 * function: func_021B4F68
 * address:  0x021B4F68
 * packet:   pkt_ov021_021B4F68
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_0215897C  0x0215897C  thumb  ov010
 *   func_0201210C  0x0201210C  thumb
 *   func_020120F4  0x020120F4  thumb
 *   func_020146F8  0x020146F8  thumb
 *   abs_id_DB      0x000000DB  data
 *   d_02185F0C     0x02185F0C  data  ov219  a4
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u8 abs_id_DB[];
extern u8 d_02185F0C[];
extern void *func_0215A5F4(void *p);
extern void *func_0215A5DC(void *a0);
extern void func_0215897C(void *a, void *b);
struct Ctx;
extern void *func_0201210C(const struct Ctx *p);
extern u32 func_020120F4(void *a);
extern void *func_020146F8(void *a, void *b, const void *c, const void *d, u32 e);

int func_021B4F68(u32 a, u32 b)
{
    void *r5;
    void *r4;
    void *r6;

    r5 = func_0215A5DC((void *)b);
    r4 = func_0215A5F4((void *)b);
    r6 = func_0201210C((void *)r5);
    func_0215897C(r4, func_020146F8(r5, r6, abs_id_DB, d_02185F0C, func_020120F4(r5)));
    return 1;
}
