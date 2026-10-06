/*
 * function: func_021BF76C
 * address:  0x021BF76C
 * packet:   pkt_ov021_021BF76C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02188C58  0x02188C58  thumb  ov021
 *   func_02188D38  0x02188D38  thumb  ov021
 *   func_0218F0A8  0x0218F0A8  thumb  ov021
 *   func_0218F0E8  0x0218F0E8  thumb  ov021
 *   func_021BF874  0x021BF874  thumb  ov021
 *   func_021BF7F8  0x021BF7F8  thumb  ov021
 *   func_021BF898  0x021BF898  thumb  ov021
 *   func_02012374  0x02012374  thumb
 *   func_021C6E48  0x021C6E48  thumb  ov021
 *   func_021BF860  0x021BF860  thumb  ov021
 *
 * func_021C6E48 takes func_02188D38's result (no argument setup before its
 * bl in case 4); that value, live across the switch, is what puts the
 * dispatch index in r1.
 */

extern void *func_02188C58(void *o);
extern void *func_02188D38(void *o);
typedef unsigned int   u32;
typedef unsigned char  u8;
struct Evt;
extern void func_0218F0A8(u8 *a);
extern u32 func_0218F0E8(u8 *a);
extern void func_021BF874(void **q);
extern void func_021BF7F8(void **q);
extern void *func_021BF898(int *q);
extern void func_02012374(struct Evt *evt, struct Evt **out);
extern int func_021C6E48(void *p);
extern void func_021BF860(void **q);

int func_021BF76C(void *task, int *state, void **q)
{
    void *obj;
    void *h;
    void *d;

    obj = q[1];
    h = func_02188C58(obj);
    d = func_02188D38(obj);

    switch (*state) {
    case 0:
        func_0218F0A8(h);
        (*state)++;
        break;
    case 1:
        if (func_0218F0E8(h) == 0)
            (*state)++;
        break;
    case 2:
        if (q[23] == 0) {
            func_021BF874(q);
            func_021BF7F8(q);
        }
        (*state)++;
        break;
    case 3:
        func_02012374(task, func_021BF898((int *)q));
        (*state)++;
        break;
    case 4:
        if (func_021C6E48(d) != 0)
            (*state)++;
        break;
    case 5:
        func_021BF860(q);
        return 1;
    }
    return 0;
}
