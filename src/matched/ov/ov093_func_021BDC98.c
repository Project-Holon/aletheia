/*
 * function: func_021BDC98
 * address:  0x021BDC98
 * packet:   pkt_ov093_021BDC98
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021BDC78  0x021BDC78  thumb  ov093
 *   func_021BDD00  0x021BDD00  thumb  ov093
 *   func_021D5440  0x021D5440  thumb  ov093
 *   func_021B8D8C  0x021B8D8C  thumb  ov093
 *   func_021B8E28  0x021B8E28  thumb  ov093
 *   func_021BD9D4  0x021BD9D4  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern void func_021BDC78(u8 *p, u8 *a);
extern int func_021BDD00(u8 *p, u8 *a, int c);
extern u8 func_021D5440(u8 *p);
extern int func_021B8D8C(void *p, void *a, u32 b);
extern void func_021B8E28(u8 *p, u32 n, u8 *out, u8 *cnt_out);
extern void func_021BD9D4(u8 *p, u32 a, u32 b, u32 c, u8 d);

void func_021BDC98(u8 *p, u8 *a, u32 v)
{
    u8 buf[2];
    int r;
    u8 *q;
    func_021BDC78(p, a);
    if (func_021BDD00(p, a, 0)) {
        r = func_021B8D8C(*(void **)(p + 4), *(void **)(p + 8), func_021D5440(a));
        func_021B8E28(*(u8 **)(p + 4), r, &buf[1], &buf[0]);
        q = p + 0x7D9;
        if (q[buf[1]] < 0xFF) q[buf[1]]++;
        func_021BD9D4(p, buf[1], buf[0], v, 1);
    }
}
