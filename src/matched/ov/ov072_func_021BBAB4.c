/*
 * function: func_021BBAB4
 * address:  0x021BBAB4
 * packet:   pkt_ov072_021BBAB4
 * region:   ov072
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0204B3B4  0x0204B3B4  arm
 *   func_0204AFD8  0x0204AFD8  arm
 *   func_0204A8D4  0x0204A8D4  arm
 *   func_0204ADA4  0x0204ADA4  arm
 *   func_0204B1CC  0x0204B1CC  arm
 *   func_0204A5AC  0x0204A5AC  arm
 *   func_02082BCC  0x02082BCC  arm
 */
typedef unsigned int u32;

extern void func_0204B3B4(u32 a);
extern void func_0204AFD8(u32 a);
extern void func_0204A8D4(u32 a);
extern void func_0204ADA4(u32 a);
extern void func_0204B1CC(u32 a);
extern void func_0204A5AC(void);
extern void func_02082BCC(void *p, int v, int n);

void func_021BBAB4(u32 *p)
{
    int i;

    for (i = 0; i < 4; i++) {
        if (p[i + 1] != 0) {
            func_0204B3B4(p[i + 1]);
        }
    }
    func_0204AFD8(p[7]);
    func_0204A8D4(p[6]);
    func_0204ADA4(p[8]);
    if (p[0] != 0) {
        func_0204B1CC(p[0]);
    }
    func_0204A5AC();
    func_02082BCC(p, 0, 0x24);
}
