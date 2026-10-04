/*
 * function: func_021DA780
 * address:  0x021DA780
 * packet:   pkt_ov093_021DA780
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021D775C   0x021D775C  thumb ov093
 *   func_021C88B4   0x021C88B4  thumb ov093
 *   func_021C88A4   0x021C88A4  thumb ov093
 *   func_021C8838   0x021C8838  thumb ov093
 *   func_021C8860   0x021C8860  thumb ov093
 *   func_021C88C8   0x021C88C8  thumb ov093
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

extern int func_021D775C(int a);
extern void func_021C88B4(void *a, int k, int b);
extern void *func_021C88A4(int a, int k, int b);
extern void func_021C8838(void *p, int a, int b);
struct S;
extern void func_021C8860(struct S *p, u32 a);
extern void func_021C88C8(void *a, void *b);

void func_021DA780(int a, int b, int c, int *d)
{
    u8 *p;

    if (c != func_021D775C(2))
        return;
    if (*d == 0)
        return;
    func_021C88B4((void *)b, 2, c);
    p = func_021C88A4(b, 4, c);
    func_021C8838(p + 4, 2, 0x202);
    func_021C8860((struct S *)(p + 4), c);
    func_021C88C8((void *)b, p);
    func_021C88B4((void *)b, 3, c);
    *d = 0;
}
