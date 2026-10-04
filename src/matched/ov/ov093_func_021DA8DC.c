/*
 * function: func_021DA8DC
 * address:  0x021DA8DC
 * packet:   pkt_ov093_021DA8DC
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021C7CF4   0x021C7CF4  thumb ov093
 *   func_021D5B48   0x021D5B48  thumb ov093
 *   func_021C88A4   0x021C88A4  thumb ov093
 *   func_021D7B74   0x021D7B74  thumb ov093
 *   func_021C8838   0x021C8838  thumb ov093
 *   func_021C8860   0x021C8860  thumb ov093
 *   func_021C88C8   0x021C88C8  thumb ov093
 *   func_021D76BC   0x021D76BC  thumb ov093
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

extern void *func_021C7CF4(int a, int b);
extern int func_021D5B48(u8 *p);
extern void *func_021C88A4(int a, int k, int b);
extern int func_021D7B74(u8 *p, u32 k);
extern void func_021C8838(void *p, int a, int b);
struct S;
extern void func_021C8860(struct S *p, u32 a);
extern void func_021C88C8(int a, void *p);
extern int func_021D76BC(int key, u32 val);

void func_021DA8DC(int a, int b, int c)
{
    void *m;
    u8 *p;
    u8 *q;

    m = func_021C7CF4(a, b);
    if (func_021D5B48(m) == 0) {
        p = func_021C88A4(a, 5, b);
        p[6] = b;
        *(u16 *)(p + 4) = func_021D7B74(m, c);
        *(u32 *)p |= 2 << 22;
        func_021C8838(p + 8, 2, 0x183);
        func_021C8860((struct S *)(p + 8), b);
        func_021C88C8(a, p);
    } else {
        q = func_021C88A4(a, 4, b);
        func_021C8838(q + 4, 2, 0xd2);
        func_021C8860((struct S *)(q + 4), b);
        *(u32 *)q |= 2 << 22;
        func_021C88C8(a, q);
    }
    func_021D76BC(0x51, 1);
}
