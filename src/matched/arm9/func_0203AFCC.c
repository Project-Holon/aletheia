/*
 * function: func_0203AFCC
 * address:  0x0203AFCC
 * packet:   pkt_0203AF40
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * blocker:  +0018 PC24 func_0203AD8C -- `label`: the only branch to 0x0203AD8C
 *           anywhere in the image is this call, so the site has no witness
 *           outside 0203AFCC..0203B018 and stays wildcarded.
 *           +0044 ABS32 func_0203AF40 -- the word is the previous function's
 *           address; its only two occurrences in the image are the pool words
 *           inside this very range (0x0203B010 here and 0x0203AFC0 in
 *           func_0203AF40), so `label` (no branch reaches it) and `literal`
 *           (self-witness) both refuse.  Filing func_0203AF40 as an EXACT
 *           manifest entry converts this site to `matched` and leaves
 *           func_0203AD8C as the only cap.
 *           Every concrete byte of the body and of the pool words reproduces
 *           (76 of 76; dsi/1.1p1).
 *
 * symbols:
 *   func_02034F84  0x02034F84  arm
 *   func_0203AD80  0x0203AD80  arm
 *   g_021469DC     0x021469DC  data
 */

typedef unsigned int u32;

extern void func_02034F84(u32 a);
extern void func_0203AD8C(u32 a0);
extern void func_0203AD80(void *ctx, void *ptr, u32 cond, u32 line);
struct Rec;
extern void func_0203AF40(struct Rec *p);
extern u32 *g_021469DC;

void func_0203AFCC(void *a, u32 b)
{
    func_02034F84(4);
    func_0203AD8C((u32)a);
    g_021469DC[0xb] = b;
    func_0203AD80(g_021469DC, (void *)func_0203AF40, 0, 0x13F);
}
