/*
 * function: func_021C00C8
 * address:  0x021C00C8
 * packet:   pkt_ov021_021C00C8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02188D38  0x02188D38  thumb  ov021
 *   func_021C0140  0x021C0140  thumb  ov021
 *   func_021C017C  0x021C017C  thumb  ov021
 *   func_021C01F8  0x021C01F8  thumb  ov021
 *   func_02012374  0x02012374  thumb
 *   func_021C6E48  0x021C6E48  thumb  ov021
 *   func_020061E4  0x020061E4  thumb
 *   func_021C01E4  0x021C01E4  thumb  ov021
 *
 * Same family as func_021BF76C: func_021C6E48 takes func_02188D38's result,
 * which keeps r0 live across the switch and puts the dispatch index in r1.
 */

typedef unsigned int   u32;
typedef unsigned char  u8;
extern u32 func_02188D38(u8 *p);
extern void func_021C0140(u32 *p);
extern void func_021C017C(u8 *p);
extern int func_021C01F8(u32 *p);
struct Evt;
extern void func_02012374(struct Evt *evt, struct Evt **out);
extern int func_021C6E48(void *p);
extern void func_020061E4(unsigned int a);
extern int func_021C01E4(void **a);

int func_021C00C8(void *task, int *state, void **q)
{
    void *d;
    int t;

    d = (void *)func_02188D38(q[1]);

    switch (*state) {
    case 0:
        func_021C0140((u32 *)q);
        func_021C017C((u8 *)q);
        (*state)++;
        break;
    case 1:
        t = (int)q[29];
        q[29] = (void *)(t + 1);
        if (t > 35) {
            func_02012374(task, (struct Evt **)func_021C01F8((u32 *)q));
            (*state)++;
            break;
        }
    case 2:
        if (func_021C6E48(d) != 0) {
            func_020061E4(0x559);
            (*state)++;
        }
        break;
    case 3:
        func_021C01E4(q);
        return 1;
    }
    return 0;
}
