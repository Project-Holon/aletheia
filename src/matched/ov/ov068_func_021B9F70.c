/*
 * function: func_021B9F70
 * address:  0x021B9F70
 * packet:   pkt_ov068_021B9F70
 * region:   ov068
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0204B3B4  0x0204B3B4  arm
 *   func_0204ADA4  0x0204ADA4  arm
 *   func_0204A8D4  0x0204A8D4  arm
 *   func_0204AFD8  0x0204AFD8  arm
 *   func_0204B1CC  0x0204B1CC  arm
 *   func_0204A5AC  0x0204A5AC  arm
 *   func_02082BCC  0x02082BCC  arm
 */

typedef unsigned int u32;

extern void func_0204B3B4(u32 a);
extern void func_0204ADA4(u32 a);
extern void func_0204A8D4(u32 a);
extern void func_0204AFD8(u32 a);
extern void func_0204B1CC(u32 a);
extern void func_0204A5AC(void);
extern void func_02082BCC(void *p, u32 a, u32 b);

void func_021B9F70(u32 *p)
{
    int i;

    for (i = 0; i < 14; i++) {
        if (p[i + 6] != 0) {
            func_0204B3B4(p[i + 6]);
        }
    }
    func_0204ADA4(p[1]);
    func_0204A8D4(p[2]);
    func_0204AFD8(p[3]);
    func_0204A8D4(p[4]);
    func_0204AFD8(p[5]);
    func_0204B1CC(p[0]);
    func_0204A5AC();
    func_02082BCC(p, 0, 0x54);
}
