/*
 * function: func_021DED6C
 * address:  0x021DED6C
 * packet:   pkt_021B75A8
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021DED6C   0x021DED6C  thumb ov093
 *   func_021D775C   0x021D775C  thumb ov093
 *   func_021DCFF8   0x021DCFF8  thumb ov093
 *   func_021D70A8   0x021D70A8  thumb ov093
 *   func_021C88A4   0x021C88A4  thumb ov093
 *   func_021C8838   0x021C8838  thumb ov093
 *   func_021C8860   0x021C8860  thumb ov093
 *   func_021C88C8   0x021C88C8  thumb ov093
 *   func_0209C2B0   0x0209C2B0  arm
 *
 * Three func_021D775C gates (3, 0x4d zero, 0x32 non-zero), then the 0x32
 * handle and func_021DCFF8(a, 2) go to the ARM helper at 0x0209C2B0, whose
 * zero result becomes 1.  Record #5 gets c and that halfword plus the same
 * two-string tail as func_021DD908.  The second argument lives on the stack
 * because all six saved registers are taken.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

int func_021D775C(int a);
int func_021DCFF8(void *a, int k);
int func_0209C2B0(int a, int b);
struct QQ;
extern u16 func_021D70A8(struct QQ *p);
void *func_021C88A4(int a, int k, int b);
void func_021C8838(void *p, int a, int b);
void func_021C8860(void *p, int a);
void func_021C88C8(int a, void *p);

void func_021DED6C(void *a, int b, int c)
{
    int r, v;
    u8 *p;

    if (c != func_021D775C(3))
        return;
    if (func_021D775C(0x4d) != 0)
        return;
    r = func_021D775C(0x32);
    if (r == 0)
        return;
    v = func_0209C2B0(r, func_021DCFF8(a, 2));
    if (v == 0)
        v = 1;
    p = func_021C88A4(b, 5, c);
    *(u8 *)(p + 6) = c;
    *(u16 *)(p + 4) = v;
    func_021C8838(p + 8, 2, 0x392);
    func_021C8860(p + 8, c);
    func_021C8860(p + 8, func_021D70A8(a));
    func_021C88C8(b, p);
}
