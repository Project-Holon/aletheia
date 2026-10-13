/*
 * A whole translation unit, matched as one byte range.
 *
 * unit:     yes
 * function: TOUCHPANEL_GetPointContSys, TOUCHPANEL_GetPointCont, TOUCHPANEL_GetPointTrgSys, TOUCHPANEL_GetPointTrg,
 *           TOUCHPANEL_HitPoint
 * address:  0x02035C70
 * packet:   pkt_02035C60
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_02035224  0x02035224  arm
 *   TOUCHPANEL_GetWork  0x02035750  arm
 *   TOUCHPANEL_ReadPointX  0x02035760  arm
 *   TOUCHPANEL_ReadPointY  0x02035780  arm
 *   TOUCHPANEL_ReadCont  0x020357A0  arm
 *   TOUCHPANEL_ReadTrg  0x020357C0  arm
 *   TOUCHPANEL_SearchHitTable  0x02035ADC  arm
 *
 * The singleton-facing half of the 0x02035000 block: every entry point here
 * is the "no context argument" spelling of a worker that lives a little
 * earlier in the file, with func_02035224() supplying the context.
 *
 * TOUCHPANEL_GetPointContSys and TOUCHPANEL_GetPointTrgSys are the two two-output readers; they differ
 * only in which predicate gates them (0x020357A0 versus 0x020357C0).  Each
 * is called from exactly one place, its own wrapper in this same file, so
 * the two pairs have to live in one unit for those sites to close as
 * `local` (same shape as src/matched/unit_020362BC.c).
 *
 * TOUCHPANEL_HitPoint has no label of its own in the listing: it is an unlabelled
 * follower of TOUCHPANEL_GetPointTrg (its prologue saves nothing).  It is the u16
 * narrowing shim in front of TOUCHPANEL_SearchHitTable, and it is the pool-word-and-bx
 * tail call idiom, one section per function.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02035C70.c \
 *       --addr 0x02035C70 --arm
 */

typedef unsigned short u16;
typedef unsigned int   u32;

struct Ctx;

struct R;
struct UiCtx;
extern struct UiCtx *func_02035224(void);
extern int TOUCHPANEL_GetWork(void);
struct Kind;
extern u16 TOUCHPANEL_ReadPointX(struct Kind *p);
extern u16 TOUCHPANEL_ReadPointY(struct Kind *p);
extern int TOUCHPANEL_ReadCont(struct Kind *p);
extern u16 TOUCHPANEL_ReadTrg(struct Kind *p);
extern int TOUCHPANEL_SearchHitTable(struct R *p, u32 x, u32 y);

u32 TOUCHPANEL_GetPointContSys(struct Ctx *ctx, u32 *outA, u32 *outB);
u32 TOUCHPANEL_GetPointTrgSys(struct Ctx *ctx, u32 *outA, u32 *outB);

u32 TOUCHPANEL_GetPointContSys(struct Ctx *ctx, u32 *outA, u32 *outB)
{
    TOUCHPANEL_GetWork();
    if (TOUCHPANEL_ReadCont((struct Kind *)ctx) == 0) {
        return 0;
    }
    *outA = TOUCHPANEL_ReadPointX((struct Kind *)ctx);
    *outB = TOUCHPANEL_ReadPointY((struct Kind *)ctx);
    return 1;
}

u32 TOUCHPANEL_GetPointCont(u32 *outA, u32 *outB)
{
    return TOUCHPANEL_GetPointContSys((struct Ctx *)func_02035224(), outA, outB);
}

u32 TOUCHPANEL_GetPointTrgSys(struct Ctx *ctx, u32 *outA, u32 *outB)
{
    TOUCHPANEL_GetWork();
    if (TOUCHPANEL_ReadTrg((struct Kind *)ctx) == 0) {
        return 0;
    }
    *outA = TOUCHPANEL_ReadPointX((struct Kind *)ctx);
    *outB = TOUCHPANEL_ReadPointY((struct Kind *)ctx);
    return 1;
}

u32 TOUCHPANEL_GetPointTrg(u32 *outA, u32 *outB)
{
    return TOUCHPANEL_GetPointTrgSys((struct Ctx *)func_02035224(), outA, outB);
}

u32 TOUCHPANEL_HitPoint(struct Ctx *ctx, u32 a, u32 b)
{
    return (u32)TOUCHPANEL_SearchHitTable((struct R *)ctx, (u16)a, (u16)b);
}
