/*
 * function: func_0218530C
 * address:  0x0218530C
 * packet:   pkt_ov023_0218530C
 * region:   ov023
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021850A0  0x021850A0  thumb  ov023
 *   func_02039338  0x02039338  arm
 *   func_02185F50  0x02185F50  thumb  ov023
 *   func_021860D0  0x021860D0  thumb  ov023
 *   func_02185EA0  0x02185EA0  thumb  ov023
 *   func_02185DE8  0x02185DE8  thumb  ov023
 */

typedef unsigned int u32;

extern void func_021850A0(char *p);
typedef unsigned short u16;
extern u16 func_02039338(void);
extern int func_02185F50(char *p);
extern void func_021860D0(char *p);
extern void func_02185EA0(char *p);
struct e6;
struct o4;
extern void func_02185DE8(char *p, struct e6 *e, struct o4 *o, int flag);

int func_0218530C(char *p, int x)
{
    func_021850A0(p);
    if (func_02039338() == 0) {
        if (func_02185F50(p) == 1) {
        } else {
            func_021860D0(p);
        }
    } else {
        func_021860D0(p);
    }
    func_02185EA0(p);
    func_02185DE8((char *)(*(u32 *)(p + 0x118)), (struct e6 *)(p + 0x4212), (struct o4 *)(p + 0x4230), 1);
    return x;
}
