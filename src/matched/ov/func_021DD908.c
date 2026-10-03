/*
 * function: func_021DD908
 * address:  0x021DD908
 * packet:   pkt_021B75A8
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021DD908   0x021DD908  thumb ov093
 *   func_021D775C   0x021D775C  thumb ov093
 *   func_021C7CF4   0x021C7CF4  thumb ov093
 *   func_021D5BDC   0x021D5BDC  thumb ov093
 *   func_021C88A4   0x021C88A4  thumb ov093
 *   func_021C88C8   0x021C88C8  thumb ov093
 *   func_021C8838   0x021C8838  thumb ov093
 *   func_021C8860   0x021C8860  thumb ov093
 *   func_021D70A8   0x021D70A8  thumb ov093
 *
 * Shape F1 gate on func_021D775C(2), reject if func_021D5BDC(r,9) says so,
 * publish record #0x17 (carrying c and the constant 9), then build record #4
 * as two strings and publish it too.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

int func_021D775C(int a);
void *func_021C7CF4(int a, int b);
struct QQ;
struct UtilWork;
int func_021D5BDC(struct UtilWork *p, u32 n);
void *func_021C88A4(int a, int k, int b);
void func_021C88C8(int a, void *p);
void func_021C8838(void *p, int a, int b);
void func_021C8860(void *p, int a);
extern u16 func_021D70A8(struct QQ *p);

void func_021DD908(void *a, int b, int c)
{
    void *p, *q;

    if (c != func_021D775C(2))
        return;
    if (func_021D5BDC(func_021C7CF4(b, c), 9) != 0)
        return;
    p = func_021C88A4(b, 0x17, c);
    *(u8 *)((u8 *)p + 8) = c;
    *(u32 *)((u8 *)p + 4) = 9;
    func_021C88C8(b, p);
    q = func_021C88A4(b, 4, c);
    func_021C8838((u8 *)q + 4, 2, 0x3e9);
    func_021C8860((u8 *)q + 4, c);
    func_021C8860((u8 *)q + 4, func_021D70A8(a));
    func_021C88C8(b, q);
}
