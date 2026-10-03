/*
 * unit:     no
 * function: func_0203C0B4
 * address:  0x0203C0B4
 * packet:   pkt_0203B5D4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 */

typedef unsigned char  u8;
extern void *func_0203D788(void);
extern void func_020394DC(u8 v);
void func_0203C0B4(void)
{
    int *r = func_0203D788();
    void (*fn)(int);
    func_020394DC(1);
    fn = *(void (**)(int))(*(int *)((char *)r + 0x340) + 0xc);
    fn(0);
}
