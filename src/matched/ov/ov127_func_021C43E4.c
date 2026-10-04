/*
 * function: func_021C43E4
 * address: 0x021C43E4
 * packet: pkt_ov127_021C43E4
 * region: ov127
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0204A6C8 0x0204A6C8 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int     s32;
extern s32 func_0204A6C8(void *a, u32 b, u32 c, u32 a3, u16 flags);
typedef struct { u32 mode, handle, owner, a, b; } Entry;
typedef struct { u8 pad[16]; Entry entries[18]; u8 gap[380]; u32 owner; u32 gap2; u32 source; } Context;
void func_021C43E4(u8 *p, int i, u32 a, u32 b, u32 c)
{
    Context *ctx;
    ctx = (Context *)p;
    ctx->entries[i].handle = func_0204A6C8((void *)ctx->source, i + 1, 0, a, c);
    ctx->entries[i].owner = ctx->owner;
    ctx->entries[i].a = a;
    ctx->entries[i].b = b;
    ctx->entries[i].mode = 1;
}
