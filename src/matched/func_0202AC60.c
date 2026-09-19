/*
 * function: func_0202AC60
 * address:  0x0202AC60
 * packet:   pkt_0202AC60
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
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

extern int  func_0202ACC8(u8 *p, u32 a1);
extern int  func_0202AD8C(u8 *p);
extern int  func_0202ADA0(u8 *p, u32 a1);
extern void func_0202AC4C(u8 *p);
extern void func_0202ADB4(u8 *p, u32 a1);
extern void func_0202AE60(u8 *p, int a1);
extern void func_0202ABFC(u8 *p, int a1);

void func_0202AC60(u8 *p, u32 a1)
{
    if (func_0202ACC8(p, a1) == 0) {
        return;
    }
    if (func_0202AD8C(p) == 1) {
        if (func_0202ADA0(p, a1) == 1) {
            func_0202AC4C(p);
            return;
        }
    }
    func_0202ADB4(p, a1);
    if (func_0202AD8C(p) == 1) {
        func_0202AE60(p, 0);
        func_0202ABFC(p, 1);
        return;
    }
    func_0202ABFC(p, 2);
}
