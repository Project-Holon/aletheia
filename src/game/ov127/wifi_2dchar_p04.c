/*
 * file:     wifi_2dchar_p04.c
 * unit:     yes
 * function: func_021C4380, func_021C43E4
 * address:  0x021C4380
 * region:   ov127
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0204A6C8 0x0204A6C8 arm
 *   func_0204AC18 0x0204AC18 arm
 */
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed int     s32;

typedef struct { u32 mode, handle, owner, a, b; } Entry;

typedef struct { u8 pad[16]; Entry entries[18]; u8 gap[384]; u32 source; } Context_021C4380;

typedef struct { u8 pad[16]; Entry entries[18]; u8 gap[380]; u32 owner; u32 gap2; u32 source; } Context_021C43E4;

extern s32 func_0204A6C8(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern s32 func_0204AC18(void *a, u32 b, u32 c, u32 d, u16 e, u16 f, u16 g);
void func_021C4380(Context_021C4380 *ctx, int i, u32 a, u32 b, u32 c);
void func_021C43E4(u8 *p, int i, u32 a, u32 b, u32 c);

void func_021C4380(Context_021C4380 *ctx, int i, u32 a, u32 b, u32 c)
{
    int n;
    n = (i - 16) * 2;
    ctx->entries[i].handle = func_0204A6C8((void *)ctx->source, n + 5, 0, a, c);
    ctx->entries[i].owner = func_0204AC18((void *)ctx->source, n + 4, a, 256, 0, 2, c);
    ctx->entries[i].a = a;
    ctx->entries[i].b = b;
    ctx->entries[i].mode = 0;
}

void func_021C43E4(u8 *p, int i, u32 a, u32 b, u32 c)
{
    Context_021C43E4 *ctx;
    ctx = (Context_021C43E4 *)p;
    ctx->entries[i].handle = func_0204A6C8((void *)ctx->source, i + 1, 0, a, c);
    ctx->entries[i].owner = ctx->owner;
    ctx->entries[i].a = a;
    ctx->entries[i].b = b;
    ctx->entries[i].mode = 1;
}
