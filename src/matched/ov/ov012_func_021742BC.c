/*
 * function: func_021742BC
 * address:  0x021742BC
 * packet:   pkt_ov012_021742BC
 * region:   ov012
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Stage machine on *state (8 states). Pooled small words 0x77/0xC3 are
 * linker overlay ids (ov119/ov195) handed to func_020120B4 with a table in
 * that overlay's window, as in ov001 func_021542C0.
 *
 * symbols:
 *   func_021BE8D4  0x021BE8D4  thumb  ov021
 *   func_021BE92C  0x021BE92C  thumb  ov021
 *   func_020144DC  0x020144DC  thumb
 *   func_020120B4  0x020120B4  thumb
 *   func_020120F0  0x020120F0  thumb
 *   func_0200FB24  0x0200FB24  thumb
 *   func_020145CC  0x020145CC  thumb
 *   ov119_id       0x00000077  data   a1
 *   ov195_id       0x000000C3  data   a1
 *   d_021E7608     0x021E7608  data   ov119  a4
 *   d_02208C40     0x02208C40  data   ov195  a4
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct Req {
    u32 f0;
    u32 f4;
    u16 f8;
    u8  fA;
    u8  fB;
    u32 fC;
    u32 f10;
} Req;

typedef struct Ctx {
    u32 f0;
    u32 f4;
    u32 f8;
    u32 fC;
    u32 f10;
    u32 f14;
    u32 f18;
    u32 f1C;
    Req *f20;
} Ctx;

extern void *func_021BE8D4(u32 a0, u32 a1, int a2, int a3);
extern void *func_021BE92C(u32 a0, u32 a1, int a2, int a3, int a4, int a5, int a6);
extern void *func_020144DC(u32 a0, u32 a1);
extern void  func_020120B4(u32 a0, void *a1, void *a2, void *a3);
extern int   func_020120F0(u32 a0);
extern u32 func_0200FB24(void);
extern void *func_020145CC(u32 a0);

extern char ov119_id[];
extern char ov195_id[];
extern u8 d_021E7608[];
extern u8 d_02208C40[];

int func_021742BC(u32 a0, u32 a1, u32 a2, Ctx *ctx, u32 a4, void **out, u8 *state)
{
    Req *r;

    switch (*state) {
    case 0:
        *out = func_021BE8D4(a0, a2, 0, 0);
        (*state)++;
        break;
    case 1:
        *out = func_020144DC(a0, a2);
        (*state)++;
        break;
    case 2:
        func_020120B4(a0, ov119_id, d_021E7608, ctx);
        (*state)++;
        break;
    case 3:
        if (func_020120F0(a0) != 0)
            break;
        if (ctx->f8 == 1)
            *state = 4;
        else
            *state = 6;
        break;
    case 4:
        r = ctx->f20;
        r->f0 = ctx->f14;
        r->f4 = ctx->f1C;
        r->f8 = ctx->fC;
        r->fA = 0;
        r->fB = ctx->f10;
        r->fC = 1;
        r->f10 = 0;
        ctx->f20 = r;
        func_020120B4(a0, ov195_id, d_02208C40, r);
        (*state)++;
        break;
    case 5:
        if (func_020120F0(a0) != 0)
            break;
        if (func_0200FB24() != 0) {
            *state = 6;
        } else {
            ctx->f8 = 1;
            *state = 2;
        }
        break;
    case 6:
        *out = func_020145CC(a0);
        *state = 7;
        break;
    case 7:
        *out = func_021BE92C(a0, a2, 0, 0, 1, 0, 0);
        *state = 8;
        break;
    default:
        return 1;
    }
    return 0;
}
