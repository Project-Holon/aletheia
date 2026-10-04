/*
 * function: func_021C4380
 * address: 0x021C4380
 * packet: pkt_ov127_021C4380
 * region: ov127
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0204A6C8 0x0204A6C8 arm
 *   func_0204AC18 0x0204AC18 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int     s32;
extern s32 func_0204A6C8(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern s32 func_0204AC18(void *a, u32 b, u32 c, u32 d, u16 e, u16 f, u16 g);
typedef struct { u32 mode, handle, owner, a, b; } Entry;
typedef struct { u8 pad[16]; Entry entries[18]; u8 gap[384]; u32 source; } Context;
void func_021C4380(Context *ctx, int i, u32 a, u32 b, u32 c)
{
    int n;
    n = (i - 16) * 2;
    ctx->entries[i].handle = func_0204A6C8((void *)ctx->source, n + 5, 0, a, c);
    ctx->entries[i].owner = func_0204AC18((void *)ctx->source, n + 4, a, 256, 0, 2, c);
    ctx->entries[i].a = a;
    ctx->entries[i].b = b;
    ctx->entries[i].mode = 0;
}
