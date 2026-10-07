/*
 * function: func_021E1EB8
 * address:  0x021E1EB8
 * packet:   pkt_ov093_021E1EB8
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021D70A8  0x021D70A8  thumb  ov093
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021C8838  0x021C8838  thumb  ov093
 *   func_021C8860  0x021C8860  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 *   func_021D76BC  0x021D76BC  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern int func_021D775C(int key);
struct QQ;
extern u16 func_021D70A8(struct QQ *p);
extern void *func_021C88A4(char *p, int a, int b);
extern void func_021C8838(void *p, int a, int b);
struct S;
extern void func_021C8860(struct S *p, u32 val);
extern void func_021C88C8(void *a, void *b);
extern int func_021D76BC(int key, u32 val);

void func_021E1EB8(void *u, int a, int b, int *p)
{
    u8 *s;

    if (b == func_021D775C(2)) {
        if (func_021D775C(0x12) == func_021D70A8(u)) {
            s = func_021C88A4((char *)a, 4, b);
            func_021C8838(s + 4, 2, 0x298);
            func_021C8860((struct S *)(s + 4), b);
            func_021C88C8((void *)a, s);
            func_021D76BC(0x3e, 1);
            p[6] = 1;
            p[0] = 1;
        }
    }
}
