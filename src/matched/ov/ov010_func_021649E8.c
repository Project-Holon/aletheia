/*
 * function: func_021649E8
 * address:  0x021649E8
 * packet:   pkt_ov010_021649E8
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Two-step state machine on *st: step 0 starts a request, step 1 finishes.
 *
 * symbols:
 *   func_020124E4  0x020124E4  thumb
 *   func_02012374  0x02012374  thumb
 *   func_021F5550  0x021F5550  thumb  ov082
 *   func_02159168  0x02159168  thumb  ov010
 *   func_02034A5C  0x02034A5C  arm
 *   ov_id_52       0x00000052  data
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Evt;
struct Obj;
extern void *func_020124E4(struct Obj *p);
extern void func_02012374(struct Evt *evt, struct Evt **out);
extern void *func_021F5550(void *p);
extern void func_02159168(int n);
extern void func_02034A5C(int a);
extern u8 ov_id_52[];

int func_021649E8(void *a, int *st)
{
    int r = (int)func_020124E4(a);
    switch (*st) {
    case 0:
        func_02012374(a, func_021F5550((void *)r));
        (*st)++;
        break;
    case 1:
        func_02159168(7);
        func_02034A5C((int)ov_id_52);
        return 1;
    }
    return 0;
}
