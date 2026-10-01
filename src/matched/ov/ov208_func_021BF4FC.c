/*
 * function: func_021BF4FC
 * address: 0x021BF4FC
 * packet: pkt_ov208_021BF4FC
 * region: ov208
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * Species local and CC40/CED4 species arguments are u32: this caller has no u16 truncation before either call.
 * symbols:
 *   func_021BC3A4 0x021BC3A4 thumb ov208
 *   func_0200CA1C 0x0200CA1C thumb
 *   func_021BC3C0 0x021BC3C0 thumb ov208
 *   func_0200CC40 0x0200CC40 thumb
 *   func_0200D288 0x0200D288 thumb
 *   func_0200CED4 0x0200CED4 thumb
 *   func_0200D3C0 0x0200D3C0 thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Blk37;
extern int func_021BC3A4(int);
extern void *func_0200CA1C(int);
extern u16 func_021BC3C0(int);
extern void func_0200CC40(u8 *, u32, u32 *, u32 *, u32 *, u16);
extern u32 func_0200D288(struct Blk37 *, u32);
extern u32 func_0200CED4(struct Blk37 *, u32);
extern u32 func_0200D3C0(struct Blk37 *, u32, u32);
void func_021BF4FC(const u16 *heap, u8 *p, int key, u16 *out1, u16 *out2, u16 *out3, u16 *out4, u32 *out5, u32 *out6, u32 *out7)
{
    u32 values[6];
    u32 a, b, c, special, value;
    struct Blk37 *ctx;
    u32 id;
    u8 i;
    ctx = func_0200CA1C(func_021BC3A4(key));
    id = func_021BC3C0(key);
    special = 0;
    func_0200CC40((u8 *)ctx, id, &b, &c, &a, *heap);
    if (id == 327) special = func_0200D288(ctx, special);
    value = func_0200CED4(ctx, id);
    for (i = 0; i < 6; i++) values[i] = func_0200D3C0(ctx, id, p[i * 20 + 0x28]);
    *out1 = id;
    *out2 = a;
    *out3 = b;
    *out4 = c;
    *out5 = special;
    *out6 = value;
    for (i = 0; i < 6; i++) out7[i] = values[i];
}
