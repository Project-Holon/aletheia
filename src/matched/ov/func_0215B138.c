/*
 * function: func_0215B138
 * address:  0x0215B138
 * packet:   pkt_0215B138
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * The third argument of the arm9 pair call is the slot the overlay index
 * returned, with a literal one alongside.
 *
 * symbols:
 *   func_02159B10   0x02159B10  thumb  ov010
 *   func_0215A5E4   0x0215A5E4  thumb  ov010
 *   func_02012F08   0x02012F08  thumb
 *   func_0200C2F0   0x0200C2F0  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void *func_02159B10(void *, void *);
extern void *func_0215A5E4(void *a0);
extern int func_02012F08(void *);
extern void func_0200C2F0(int, void *, int);

int func_0215B138(void *a0, void *a1)
{
    void *v = func_02159B10(a0, a1);

    func_0200C2F0(func_02012F08(func_0215A5E4(a1)), v, 1);

    return 0;
}

