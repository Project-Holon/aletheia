/*
 * function: func_0215D864
 * address:  0x0215D864
 * packet:   pkt_0215D864
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * blocked:   wild=4
 *
 * The slot index is truncated to a byte before the arm9 pair call.
 *
 * symbols:
 *   func_02159B10   0x02159B10  thumb  ov010
 *   func_0215A5E4   0x0215A5E4  thumb  ov010
 *   func_02012F44   0x02012F44  thumb
 *   func_0200A6BC   0x0200A6BC  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern unsigned int func_02159B10(void *a0, void *a1);
extern void *func_0215A5E4(void *a0);
extern int func_02012F44(void *);
struct Big;
extern void func_0200A6BC(struct Big *p, u32 index);

int func_0215D864(void *a0, void *a1)
{
    int v = func_02159B10(a0, a1);

    func_0200A6BC((struct Big *)func_02012F44(func_0215A5E4(a1)), (u8)v);

    return 0;
}

