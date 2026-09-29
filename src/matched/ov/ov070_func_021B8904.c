/*
 * function: func_021B8904
 * address:  0x021B8904
 * packet:   pkt_ov070_021B8904
 * region:   ov070
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0202208C  0x0202208C  thumb
 *   func_021BA41C  0x021BA41C  thumb  ov070
 *   func_021BA4A4  0x021BA4A4  thumb  ov070
 *   func_021B9ED8  0x021B9ED8  thumb  ov070
 *   func_021BB73C  0x021BB73C  thumb  ov070
 *   func_020310C4  0x020310C4  arm
 */

extern void func_0202208C();
extern void func_021BA41C();
extern void func_021BA4A4();
extern void func_021B9ED8();
extern void func_021BB73C();
extern void func_020310C4();

int func_021B8904(int a, int b, int c, int p)
{
    void (*fn)(int) = *(void (**)(int))((char *)p + 0x4F8);
    if (fn == 0) {
        func_0202208C(0, 0, 0, 0, 6, 1, *(unsigned short *)((char *)p + 0x544));
        return 1;
    }
    *(int *)((char *)p + 0x818) = *(int *)((char *)p + 0x814);
    fn(p);
    if (*(unsigned short *)((char *)p + 0x83E) != 0) {
        func_021BA41C(p);
        *(unsigned short *)((char *)p + 0x83E) = 0;
    }
    if (*(unsigned short *)((char *)p + 0x83C) != 0) {
        func_021BA4A4(p);
        *(unsigned short *)((char *)p + 0x83C) = 0;
    }
    func_021B9ED8(p);
    func_021BB73C(p);
    func_020310C4(*(int *)((char *)p + 0x730));
    return 0;
}
