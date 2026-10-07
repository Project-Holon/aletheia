/*
 * function: func_0215F280
 * address:  0x0215F280
 * packet:   pkt_0215F280
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Frame teardown on the handle the overlay index returned, then the
 * overlay's own mode setter.
 *
 * symbols:
 *   func_0215A5DC   0x0215A5DC  thumb  ov010
 *   func_0201213C   0x0201213C  thumb
 *   func_020121CC   0x020121CC  thumb
 *   func_02159168   0x02159168  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void *func_0215A5DC(void *a0);
struct Ctx;
struct IcaAnime;
extern void func_0201213C(struct Ctx *p, u32 v);
extern u32 func_020121CC(struct IcaAnime *p);
extern void func_02159168(int);

int func_0215F280(void *a0, void *a1)
{
    void *p = func_0215A5DC(a1);

    func_0201213C(p, 0);
    func_020121CC(p);
    func_02159168(0xB);

    return 1;
}

