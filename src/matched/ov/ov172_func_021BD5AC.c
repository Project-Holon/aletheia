/*
 * function: func_021BD5AC
 * address:  0x021BD5AC
 * packet:   pkt_ov172_021BD5AC
 * region:   ov172
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021B71B8  0x021B71B8  thumb  ov172
 *   func_021B6C4C  0x021B6C4C  thumb  ov172
 *   func_021B9574  0x021B9574  thumb  ov172
 */

typedef unsigned int u32;

extern void func_021B71B8(char *ctx, u32 a);
extern void func_0204A648(void);
extern void func_021B6C4C(char *p);
extern void func_021B9574(int unused, char *p);

void func_021BD5AC(int unused, char *ctx)
{
    func_021B71B8(ctx, *(u32 *)(ctx + 0x1e0));
    func_0204A648();
    func_021B6C4C((char *)(*(u32 *)(ctx + 0x1f4)));
    func_021B9574((int)ctx, (char *)(*(u32 *)(ctx + 0x1e8)));
}
