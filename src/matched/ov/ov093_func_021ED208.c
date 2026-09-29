/*
 * function: func_021ED208
 * address:  0x021ED208
 * packet:   pkt_ov093_021ED208
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021B98AC  0x021B98AC  thumb  ov093
 *   func_021D59B4  0x021D59B4  thumb  ov093
 *   func_021B8E70  0x021B8E70  thumb  ov093
 *   func_021F80FC  0x021F80FC  thumb  ov094
 *   func_021F7C2C  0x021F7C2C  thumb  ov094
 *   func_021F8118  0x021F8118  thumb  ov094
 */

typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;

extern int func_021B98AC(char *const *q, u8 b);
extern int func_021D59B4(void *p, int k);
extern u8 func_021B8E70(u8 *p, u32 k);
extern void func_021F80FC(u32 a, int b);
extern void func_021F7C2C(u32 a, u32 b);
extern void func_021F8118(u32 a, int b);

void func_021ED208(char *p, u8 k, u16 a, int flag)
{
    int t;
    u32 v;

    t = func_021D59B4((void *)func_021B98AC(*(char *const **)(p + 0x138), k), 0xd);
    v = func_021B8E70(*(u8 **)(p + 0x134), k);
    if (flag == 0) {
        func_021F80FC(v, t);
        func_021F7C2C(v, a);
    } else {
        func_021F8118(v, t);
    }
}
