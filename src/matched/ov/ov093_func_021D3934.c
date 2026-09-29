/*
 * function: func_021D3934
 * address:  0x021D3934
 * packet:   pkt_ov093_021D3934
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021B9AEC  0x021B9AEC  thumb  ov093
 *   func_021B9C10  0x021B9C10  thumb  ov093
 *   func_021B9BF0  0x021B9BF0  thumb  ov093
 *   func_021D63EC  0x021D63EC  thumb  ov093
 *   func_021D6580  0x021D6580  thumb  ov093
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern char *func_021B9AEC(char *p, u8 i);
extern void func_021B9C10(char *p, u8 a, u8 b);
extern void *func_021B9BF0(void *p, int i);
extern void func_021D63EC(void *p, u16 v);
extern void func_021D6580(void *p);

int func_021D3934(char *a, int b, u32 *s)
{
    u8 x;
    u8 y;
    char *l;
    void *e;

    x = *(u32 *)(a + 0x13c);
    y = *(u32 *)(a + 0x140);
    l = func_021B9AEC(*(char **)(a + 4), *(u32 *)(a + 0x138));
    if (x != y)
        func_021B9C10(l, x, y);
    e = func_021B9BF0(l, x);
    func_021D63EC(e, s[3]);
    func_021D6580(e);
    return 1;
}
