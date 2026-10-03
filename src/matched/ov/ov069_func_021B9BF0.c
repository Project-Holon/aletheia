/*
 * function: func_021B9BF0
 * address:  0x021B9BF0
 * packet:   pkt_ov069_021B9BF0
 * region:   ov069
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0204A8D4  0x0204A8D4  arm
 *   func_0204ADA4  0x0204ADA4  arm
 *   func_0204AFD8  0x0204AFD8  arm
 *   func_0204B1CC  0x0204B1CC  arm
 *   func_0204A5AC  0x0204A5AC  arm
 */

typedef unsigned int   u32;
extern void func_0204A8D4(u32 i);
extern void func_0204ADA4(u32 i);
extern void func_0204AFD8(u32 i);
extern void func_0204B1CC(int);
extern void func_0204A5AC(void);

void func_021B9BF0(char *p)
{
    func_0204A8D4(*(int *)(p + 0x144));
    func_0204ADA4(*(int *)(p + 0x140));
    func_0204AFD8(*(int *)(p + 0x148));
    func_0204A8D4(*(int *)(p + 0x138));
    func_0204ADA4(*(int *)(p + 0x134));
    func_0204AFD8(*(int *)(p + 0x13C));
    func_0204B1CC(*(int *)(p + 0x120));
    func_0204B1CC(*(int *)(p + 0x11C));
    func_0204A5AC();
}
