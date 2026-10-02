/*
 * function: func_0217BB3C
 * address: 0x0217BB3C
 * packet: pkt_ov019_0217BB3C
 * region: ov019
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02173524 0x02173524 thumb ov012
 *   func_021734A8 0x021734A8 thumb ov012
 *   func_0217F074 0x0217F074 thumb ov019
 *   func_0217BAF0 0x0217BAF0 thumb ov019
 */
typedef unsigned char u8;
typedef unsigned int u32;
typedef struct { struct { void *f0; } *head; } Work;
extern void func_02173524(Work *w, u8 *p);
extern void func_021734A8(u8 *self, u32 id, u32 v);
extern void func_0217F074(void *ctx);
extern void func_0217BAF0(void *ctx, int a, int v);
int func_0217BB3C(u8 *ctx, u8 *obj, int a)
{
    func_02173524((Work *)ctx, obj + 0x14);
    func_021734A8(ctx, 4, 0);
    func_0217F074(ctx);
    func_0217BAF0(ctx, a, 0);
    ctx[0x282E] = 0;
    return 1;
}
