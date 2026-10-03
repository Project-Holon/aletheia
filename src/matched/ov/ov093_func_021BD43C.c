/*
 * function: func_021BD43C
 * address:  0x021BD43C
 * packet:   pkt_ov093_021BD43C
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021B9AEC  0x021B9AEC  thumb  ov093
 *   func_021B8BEC  0x021B8BEC  thumb  ov093
 *   func_021BD4D4  0x021BD4D4  thumb  ov093
 *   func_021B9C10  0x021B9C10  thumb  ov093
 *   func_021CD4B0  0x021CD4B0  thumb  ov093
 *   func_021B9BF0  0x021B9BF0  thumb  ov093
 *   func_021D5B68  0x021D5B68  thumb  ov093
 *   func_021D5FC0  0x021D5FC0  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern char *func_021B9AEC(char *p, int i);
extern u8 func_021B8BEC(u8 *p, u32 k, u8 n);
extern void func_021BD4D4(u8 *p, int a, int b);
extern void func_021B9C10(char *p, u8 a, u8 b);
extern void func_021CD4B0(void *w, volatile u32 id, ...);
extern u8 *func_021B9BF0(char *p, u8 i);
extern int func_021D5B68(void *p);
extern void func_021D5FC0(u8 *p, u32 n);

void func_021BD43C(u8 *p, int i, u8 a, u8 b, int c)
{
    char *s = func_021B9AEC(*(char **)(p + 8), i);
    int x = func_021B8BEC(*(u8 **)(p + 4), i, a);
    int y = func_021B8BEC(*(u8 **)(p + 4), i, b);
    u8 *q;
    u8 *r;
    func_021BD4D4(p + 0x1ab8, x, y);
    func_021B9C10(s, a, b);
    if (c == 0) {
        func_021CD4B0(*(void **)(p + 0xc), 0x44, i, x, y);
        q = func_021B9BF0(s, a);
        r = func_021B9BF0(s, b);
        if (!func_021D5B68(q)) func_021D5FC0(q, 0xc);
        if (!func_021D5B68(r)) func_021D5FC0(r, 0xc);
    }
}
