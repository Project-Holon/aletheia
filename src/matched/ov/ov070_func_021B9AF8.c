/*
 * function: func_021B9AF8
 * address:  0x021B9AF8
 * packet:   pkt_ov070_021B9AF8
 * region:   ov070
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020452E8  0x020452E8  arm
 *   func_0204B3B4  0x0204B3B4  arm
 *   func_0204A8D4  0x0204A8D4  arm
 *   func_0204ADA4  0x0204ADA4  arm
 *   func_0204AFD8  0x0204AFD8  arm
 *   func_020437AC  0x020437AC  arm
 *   func_0204B1CC  0x0204B1CC  arm
 *   func_0204A5AC  0x0204A5AC  arm
 */

extern void func_020452E8(int);
extern void func_0204B3B4(int);
typedef unsigned int   u32;
extern void func_0204A8D4(u32 i);
extern void func_0204ADA4(u32 i);
extern void func_0204AFD8(u32 i);
extern void func_020437AC(int);
extern void func_0204B1CC(int);
extern void func_0204A5AC(void);

void func_021B9AF8(char *p)
{
    int i;
    func_020452E8(*(int *)(p + 0x73C));
    func_020452E8(*(int *)(p + 0x74C));
    func_020452E8(*(int *)(p + 0x744));
    func_020452E8(*(int *)(p + 0x734));
    func_020452E8(*(int *)(p + 0x754));
    func_020452E8(*(int *)(p + 0x76C));
    func_020452E8(*(int *)(p + 0x774));
    func_0204B3B4(*(int *)(p + 0x6A8));
    if (*(int *)(p + 0x6A0) != 0) {
        func_0204B3B4(*(int *)(p + 0x6A0));
        func_0204A8D4(*(int *)(p + 0x54C));
        func_0204ADA4(*(int *)(p + 0x548));
    }
    func_0204AFD8(*(int *)(p + 0x550));
    for (i = 0; i < 8; i++) {
        func_020437AC(*(int *)(p + i * 4 + 0x614));
    }
    func_0204B1CC(*(int *)(p + 0x69C));
    func_0204A5AC();
}
