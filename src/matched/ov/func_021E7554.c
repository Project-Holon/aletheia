/*
 * function: func_021E7554
 * address:  0x021E7554
 * packet:   pkt_021B75A8
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021E7554   0x021E7554  thumb ov093
 *   func_021D775C   0x021D775C  thumb ov093
 *   func_021C7CF4   0x021C7CF4  thumb ov093
 *   func_021D5B40   0x021D5B40  thumb ov093
 *   func_021C88A4   0x021C88A4  thumb ov093
 *   func_021C8838   0x021C8838  thumb ov093
 *   func_021C8860   0x021C8860  thumb ov093
 *   func_021C88C8   0x021C88C8  thumb ov093
 *   func_020213C0   0x020213C0  thumb
 *
 * Gate on func_021D775C(3) and on func_021D775C(0x46) being zero, then the
 * (u8) of func_021D775C(4) keys func_021C7CF4 and the (u16) of
 * func_021D5B40 is the value func_020213C0 must accept.  Both truncations
 * are materialised in the image, so both callees are declared int.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

int func_021D775C(int a);
void *func_021C7CF4(int a, int b);
int func_021D5B40(void *p);
int func_020213C0(u16 a);
void *func_021C88A4(int a, int k, int b);
void func_021C8838(void *p, int a, int b);
struct S;
void func_021C8860(struct S *p, unsigned int a);
void func_021C88C8(int a, void *p);

void func_021E7554(void *a, int b, int c)
{
    u8 k;
    u16 v;
    u8 *p;

    if (c != func_021D775C(3))
        return;
    if (func_021D775C(0x46) != 0)
        return;
    k = (u8)func_021D775C(4);
    v = (u16)func_021D5B40(func_021C7CF4(b, k));
    if (func_020213C0(v) == 0)
        return;
    p = func_021C88A4(b, 0x20, c);
    *(u8 *)(p + 6) = k;
    *(u16 *)(p + 4) = 0;
    func_021C8838(p + 0xc, 2, 0x454);
    func_021C8860((struct S *)(p + 0xc), k);
    func_021C8860((struct S *)(p + 0xc), v);
    func_021C88C8(b, p);
}
