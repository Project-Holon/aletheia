/*
 * function: func_021DAC90
 * address:  0x021DAC90
 * packet:   pkt_021B75A8
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021DAC90   0x021DAC90  thumb ov093
 *   func_021D775C   0x021D775C  thumb ov093
 *   func_021C7CF4   0x021C7CF4  thumb ov093
 *   func_021D76BC   0x021D76BC  thumb ov093
 *   func_021C88A4   0x021C88A4  thumb ov093
 *   func_021C88B4   0x021C88B4  thumb ov093
 *   func_021C8838   0x021C8838  thumb ov093
 *   func_021C8860   0x021C8860  thumb ov093
 *   func_021C88C8   0x021C88C8  thumb ov093
 *   func_0201C314   0x0201C314  thumb
 *
 * Gate on func_021D775C(4) then a re-test on func_021D775C(3); the
 * func_021C7CF4(b, c) call's value is dropped, only the (u16) of
 * func_021D775C(0x12) is kept.  Five more rejections, then the 2-event,
 * record, 3-event tail.  The trailing event's constant 3 is live across the
 * whole body, which is why the image keeps it in r7.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

int func_021D775C(int a);
void *func_021C7CF4(int *p, int i);
int func_021D76BC(int key, u32 val);
u32 func_0201C314(void *p);
void *func_021C88A4(char *p, int a, int b);
void func_021C88B4(void *a, int k, int b);
void func_021C8838(void *p, int a, int b);
struct S;
void func_021C8860(struct S *p, unsigned int a);
void func_021C88C8(void *a, void *b);

void func_021DAC90(void *a, int b, int c)
{
    void *q;
    u16 v;

    if (c != func_021D775C(4))
        return;
    if (c == func_021D775C(3))
        return;
    func_021C7CF4((int *)b, c);
    v = (u16)func_021D775C(0x12);
    if (func_0201C314((void *)v) == 0)
        return;
    if (v == 0xa5)
        return;
    if (func_021D775C(0x38) > 3)
        return;
    if (func_021D76BC(0x40, 1) == 0)
        return;
    func_021C88B4((void *)b, 2, c);
    q = func_021C88A4((char *)b, 4, c);
    func_021C8838((u8 *)q + 4, 2, 0xd2);
    func_021C8860((struct S *)((u8 *)q + 4), c);
    func_021C88C8((void *)b, q);
    func_021C88B4((void *)b, 3, c);
}
