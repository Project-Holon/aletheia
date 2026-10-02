/*
 * function: func_021ED494
 * address:  0x021ED494
 * packet:   pkt_ov093_021ED494
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
 *   func_021F8118  0x021F8118  thumb  ov094
 *   func_021F80FC  0x021F80FC  thumb  ov094
 */
typedef unsigned char u8;
extern void *func_021B98AC(char *const *, u8);
extern int func_021D59B4(void *, int);
extern u8 func_021B8E70(u8 *, u8);
extern void func_021F8118(u8, int);
extern void func_021F80FC(u8, int);
void func_021ED494(u8 *p, u8 k, int x)
{
    int d = func_021D59B4(func_021B98AC(*(char *const **)(p + 0x138), k), 0xd);
    u8 r = func_021B8E70(*(u8 **)(p + 0x134), k);
    if (x != 0)
        func_021F8118(r, d);
    else
        func_021F80FC(r, d);
}
