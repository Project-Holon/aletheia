/*
 * function: func_021C65E4
 * address:  0x021C65E4
 * packet:   pkt_ov136_021C65E4
 * region:   ov136
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0204A5AC  0x0204A5AC  arm
 *   func_0204ADA4  0x0204ADA4  arm
 *   func_0204AFD8  0x0204AFD8  arm
 *   func_0204B1CC  0x0204B1CC  arm
 */

typedef unsigned char u8;
extern void func_0204AFD8(void *);
extern void func_0204ADA4(void *);
struct Bank;
extern void func_0204B1CC(struct Bank *bank);
extern void func_0204A5AC(void);
void func_021C65E4(u8 *p)
{
    func_0204AFD8(*(void **)(p + 0x230));
    func_0204ADA4(*(void **)(p + 0x250));
    func_0204B1CC(*(void **)(p + 0x1EC));
    func_0204A5AC();
}
