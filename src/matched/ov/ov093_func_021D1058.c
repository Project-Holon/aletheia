/*
 * function: func_021D1058
 * address:  0x021D1058
 * packet:   pkt_ov093_021D1058
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021B9AB0  0x021B9AB0  thumb  ov093
 *   func_021B9C00  0x021B9C00  thumb  ov093
 *   func_021D5B68  0x021D5B68  thumb  ov093
 *   func_021D83FC  0x021D83FC  thumb  ov093
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_021B9AB0(int k);
extern u8 *func_021B9C00(void *p, u32 i);
extern int func_021D5B68(void *p);
extern void func_021D83FC(void *p, int k);

int func_021D1058(u8 *s, void *q)
{
    int k;

    k = 2;
    if (func_021D5B68(func_021B9C00(*(void **)(s + 0x118), (u8)func_021B9AB0(2))) == 0) {
        func_021D83FC(q, k);
        return 4;
    }
    k = 3;
    if (func_021D5B68(func_021B9C00(*(void **)(s + 0x118), (u8)func_021B9AB0(3))) == 0) {
        func_021D83FC(q, k);
        return 4;
    }
    return 0;
}
