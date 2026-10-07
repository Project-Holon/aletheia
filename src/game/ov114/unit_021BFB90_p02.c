/*
 * file:     unit_021BFB90_p02.c
 * unit:     yes
 * function: func_021BFF7C, func_021C0004
 * address:  0x021BFF7C
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   ghiAppendDataToBuffer  0x021BFCEC arm ov114
 *   g_021CE58C             0x021CE58C data
 *   g_021CE590             0x021CE590 data
 *   func_021BFB90 0x021BFB90  arm
 */
typedef struct {
    char pad0[4];
    char *data;
    int size;
    int length;
    int pos;
    char pad1[12];
    int fixed;
    char pad2[4];
} GHIBuffer;

typedef struct Base {
    unsigned char pad0[0x40];
    int f40;
    unsigned char pad1[0x124 - 0x44];
    int f124;
} Base;

typedef struct Ctx {
    Base *f0;
    char *f4;
    int f8;
    int fC;
    int f10;
    int f14;
    int f18;
    int f1C;
    int f20;
} Ctx;

extern int ghiAppendDataToBuffer(GHIBuffer *buffer, char *data, int dataLen);
extern int func_021BFB90(void *, int);
int func_021BFF7C(GHIBuffer *buffer, char *name, char *value);
int func_021C0004(Ctx *ctx, int ch);
extern char g_021CE58C[];
extern char g_021CE590[];


int func_021BFF7C(GHIBuffer *buffer, char *name, char *value)
{
    if (ghiAppendDataToBuffer(buffer, name, 0) == 0)
        return 0;
    if (ghiAppendDataToBuffer(buffer, g_021CE58C, 2) == 0)
        return 0;
    if (ghiAppendDataToBuffer(buffer, value, 0) == 0)
        return 0;
    if (ghiAppendDataToBuffer(buffer, g_021CE590, 2) == 0)
        return 0;
    return 1;
}


int func_021C0004(Ctx *ctx, int ch)
{
    if (ctx == 0)
        return 0;
    if (ctx->f20 != 0)
        return 0;
    if (ctx->fC + 1 >= ctx->f8) {
        if (ctx->f18 != 0) {
            ctx->f0->f124 = 1;
            ctx->f0->f40 = 2;
            return 0;
        }
        if (func_021BFB90(ctx, ctx->f14) != 0)
            goto append;
        ctx->f0->f124 = 1;
        ctx->f0->f40 = 1;
        return 0;
    }
append:
    ctx->f4[ctx->fC] = ch;
    ctx->fC++;
    ctx->f4[ctx->fC] = 0;
    return 1;
}
