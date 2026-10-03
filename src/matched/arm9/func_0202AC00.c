/*
 * function: func_0202AC00
 * address:  0x0202AC00
 * packet:   pkt_0202AC00
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */

typedef unsigned char u8;
typedef unsigned int  u32;

extern u32 func_0202ACC8(void *obj);
extern void func_0202AEB8(void *obj, u32 value);
extern void func_0202AEBC(u8 *p);
extern u32  func_0202ACBC(u8 *p);
extern void func_0202ADB4(u8 *p, u32 v);
extern int  func_0202AD8C(u8 *p);
extern void func_0202ABFC(void *obj, u32 value);

void func_0202AC00(u8 *p)
{
    if (func_0202ACC8(p) != 0)
        return;

    *(u32 *)(p + 4) = 1;
    func_0202AEB8(p, 0);
    func_0202AEBC(p);
    func_0202ADB4(p, func_0202ACBC(p));

    if (func_0202AD8C(p) == 1)
        func_0202ABFC(p, 1);
    else
        func_0202ABFC(p, 0);
}
