/*
 * function: func_02189800
 * address:  0x02189800
 * packet:   pkt_ov096_02189800
 * region:   ov096
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * symbols:
 *   func_0201134C  0x0201134C  thumb
 *   func_0218A160  0x0218A160  thumb  ov096
 *   func_0218A2FC  0x0218A2FC  thumb  ov096
 *   func_0218A308  0x0218A308  thumb  ov096
 *   func_0218A0F4  0x0218A0F4  thumb  ov096
 *   func_021B8DE4  0x021B8DE4  thumb  ov093
 *   func_021B9AF8  0x021B9AF8  thumb  ov093
 *   func_021B99B8  0x021B99B8  thumb  ov093
 *   func_021B9B94  0x021B9B94  thumb  ov093
 *   func_021D5B68  0x021D5B68  thumb  ov093
 *   func_021D5C44  0x021D5C44  thumb  ov093
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef signed char s8;
typedef unsigned int u32;
typedef int s32;

extern int func_0201134C(int);
extern u8 func_0218A160(u8 *p, int k);
extern u8 *func_0218A2FC(u8 *p, u8 i);
extern u8 *func_0218A308(void *, u32);
extern int func_0218A0F4(u8 *a, int op, int x, int y, int z);
extern unsigned char func_021B8DE4(char *p, int i);
extern char *func_021B9AF8(char *p, int i);
extern int func_021B99B8(void *pp, unsigned int b);
struct Q1;
extern u8 func_021B9B94(struct Q1 *p);
extern int func_021D5B68(void *);
extern int func_021D5C44(void *);

int func_02189800(int a, int b) {
    int r4;
    int x;
    u8 y;
    int r5;
    int t;
    r4 = func_0201134C(a);
    x = func_0201134C(a);
    y = func_0218A160((u8 *)b, r4);
    r5 = func_021B8DE4((char *)(*(int *)(b + 0xb0)), y);
    r4 = (int)func_021B9AF8(*(char **)(b + 0xb8), r5);
    r5 = func_021B99B8((void *)(*(int *)(b + 0xb0)), r5);
    for (; r5 < func_021B9B94((struct Q1 *)r4); r5++) {
        if (func_021D5B68(func_0218A308((void *)r4, (u8)r5)) == 0) {
            t = func_021D5C44(func_0218A2FC((u8 *)b, y));
            if (func_0218A0F4((u8 *)a, 0, t, 100, x) != 0) {
                break;
            }
        }
    }
    return *(int *)(b + 0xc4);
}
