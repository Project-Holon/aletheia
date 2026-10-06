/*
 * function: func_0202AC60
 * address:  0x0202AC60
 * packet:   pkt_0202AC60
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0202ABFC 0x0202ABFC  thumb
 *   func_0202AC4C 0x0202AC4C  thumb
 *   func_0202ACC8 0x0202ACC8  thumb
 *   func_0202AD8C 0x0202AD8C  thumb
 *   func_0202ADA0 0x0202ADA0  thumb
 *   func_0202ADB4 0x0202ADB4  thumb
 *   func_0202AE60 0x0202AE60  thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u32 func_0202ACC8(void *obj);
extern int func_0202AD8C(int a0);
extern int func_0202ADA0(int a0, int a1);
extern int func_0202AC4C(int a0);
extern int func_0202ADB4(int a0, int a1);
extern void func_0202AE60(void *obj, u32 value);
extern void func_0202ABFC(void *obj, u32 value);

void func_0202AC60(u8 *p, u32 a1)
{
    if (func_0202ACC8(p) == 0) {
        return;
    }
    if (func_0202AD8C((int)p) == 1) {
        if (func_0202ADA0((int)p, a1) == 1) {
            func_0202AC4C((int)p);
            return;
        }
    }
    func_0202ADB4((int)p, a1);
    if (func_0202AD8C((int)p) == 1) {
        func_0202AE60(p, 0);
        func_0202ABFC(p, 1);
        return;
    }
    func_0202ABFC(p, 2);
}
