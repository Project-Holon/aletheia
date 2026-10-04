/*
 * function: func_021DA96C
 * address:  0x021DA96C
 * packet:   pkt_ov093_021DA96C
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021C7CF4  0x021C7CF4  thumb  ov093
 *   func_021D5D14  0x021D5D14  thumb  ov093
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 *   func_021C8838  0x021C8838  thumb  ov093
 *   func_021C8860  0x021C8860  thumb  ov093
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef signed char    s8;
extern void *func_021C7CF4(int *p, int i);
extern int func_021D5D14(s8 *p, int i, int sign);
extern void *func_021C88A4(void *a, int k, int b);
extern void func_021C88C8(void *a, void *b);
extern void func_021C8838(void *p, int a, int b);
struct S;
extern void func_021C8860(struct S *p, u32 v);

void func_021DA96C(void *a, int id, u32 e, int d)
{
    u8 *r;

    if (func_021D5D14(func_021C7CF4(a, id), e, d) != 0) {
        r = (u8 *)func_021C88A4(a, 14, id);
        r[0xf] = 1;
        r[0x10] = id;
        r[0xe] = 1;
        *(u32 *)(r + 4) = e;
        r[0xc] = d;
        *(u32 *)r |= 0x800000;
        func_021C88C8(a, r);
    } else {
        r = (u8 *)func_021C88A4(a, 4, id);
        func_021C8838(r + 4, 2, 0xd2);
        func_021C8860((struct S *)(r + 4), id);
        *(u32 *)r |= 0x800000;
        func_021C88C8(a, r);
    }
}
