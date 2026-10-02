/*
 * function: func_0216AF1C
 * address:  0x0216AF1C
 * packet:   pkt_0216AF1C
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Overlay index on the first argument, then the pair call is staged with
 * the fourth argument.
 *
 * symbols:
 *   func_0215A5E4   0x0215A5E4  thumb  ov010
 *   func_0217C274   0x0217C274  thumb
 *   func_0217C2A0   0x0217C2A0  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void *func_0215A5E4(void *a0);
extern void func_0217C274(void *, void *);
extern void func_0217C2A0(int, void *, void *);

void func_0216AF1C(void *a0, void *a1, void *a2, void *a3)
{
    void *v = func_0215A5E4(a0);

    func_0217C274(a3, a1);
    func_0217C2A0(4, v, a3);
}

