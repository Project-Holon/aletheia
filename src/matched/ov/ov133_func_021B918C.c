/*
 * function: DUP_FITTING_DrawFrames
 * address: 0x021B918C
 * packet: pkt_ov133_021B918C
 * region: ov133
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   _fflt 0x0209BDBC arm
 *   _fmul 0x0209C77C arm
 *   _fadd 0x0209C95C arm
 *   _fsub 0x0209CB8C arm
 *   _ffix 0x0209C494 arm
 *   _ffixu 0x0209C4C8 arm
 *   _fgr 0x0209BBB0 arm
 *   _ll_mul 0x0209C054 arm
 *   FX_Sqrt 0x0207C7B4 arm
 *   FX_Atan2Idx 0x0207CFB8 arm
 *   DUP_FITTING_SetModelTransform 0x021B765C thumb ov133
 *   DUP_FITTING_ITEM_ListGetHead 0x021BA184 thumb ov133
 *   DUP_FITTING_ITEM_ElemGetPos 0x021BA228 thumb ov133
 *   DUP_FITTING_ITEM_ElemGetRenderElem 0x021BA218 thumb ov133
 *   DUP_FITTING_ITEM_ElemGetNext 0x021BA208 thumb ov133
 *   MUSICAL_MCSS_SetElemScale 0x021F4EA4 thumb ov112
 *   MUSICAL_MCSS_SetElemPos 0x021F4E8C thumb ov112
 *   BG_SYS_ChangeScrollImmediate 0x02040618 arm
 *   CLACT_AddActorSurfacePos 0x0204B404 arm
 *   FX_SinCosTable_ 0x020A1B38 data
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef int fx32;
typedef struct { short s; short c; } SC;
typedef struct { short x; short y; } Pt;
extern const SC FX_SinCosTable_[];
extern void DUP_FITTING_SetModelTransform(u8 *p, u32 a, u32 b, u32 c, u32 d);
struct Obj;
struct Vec2;
extern void *DUP_FITTING_ITEM_ListGetHead(char *p);
extern u8 *DUP_FITTING_ITEM_ElemGetPos(u8 *p);
extern u32 DUP_FITTING_ITEM_ElemGetRenderElem(u8 *p);
extern u32 DUP_FITTING_ITEM_ElemGetNext(u8 *p);
extern void MUSICAL_MCSS_SetElemScale(u32 unused, u32 p, u32 q);
extern void MUSICAL_MCSS_SetElemPos(u8 *, int, int *);
extern void BG_SYS_ChangeScrollImmediate(u32 layer, u32 a, u32 b);
extern void CLACT_AddActorSurfacePos(struct Obj *p, const struct Vec2 *delta, u32 which);
extern int FX_Sqrt(int);
extern int FX_Atan2Idx(int, int);

#define FXI(d) ((fx32)(((d) > 0) ? ((d) * 4096 + .5f) : ((d) * 4096 - .5f)))
#define FXF(x) ((fx32)(((x) > 0) ? ((x) * 4096.0f + .5f) : ((x) * 4096.0f - .5f)))

void DUP_FITTING_DrawFrames(u8 *p)
{
    u8 *e;
    Pt r;
    DUP_FITTING_SetModelTransform(p, *(u16 *)(p + 0x182C), 0, (u16)(*(int *)(p + 0x10) + 0x48), (u32)(48.0f + (float)*(int *)(p + 0x10) * 0.6666667f));
    e = DUP_FITTING_ITEM_ListGetHead((char *)(*(u8 **)(p + 0x1820)));
    while (e) {
        int *pos = (int *)DUP_FITTING_ITEM_ElemGetPos(e);
        int id = DUP_FITTING_ITEM_ElemGetRenderElem(e);
        int y;
        int x;
        int d;
        int dist, ang, k;
        const SC *sc;
        int v[3];
        x = (short)(pos[0] - 0x80);
        y = (short)(pos[1] - 0x50);
        d = x * x + y * y;
        dist = FX_Sqrt(FXI(d));
        ang = FX_Atan2Idx(FXI(y), FXI(x));
        MUSICAL_MCSS_SetElemScale((u32)(*(u8 **)(p + 0x1884)), id, (u32)v);
        k = dist + FXI(*(int *)(p + 0x10));
        sc = &FX_SinCosTable_[ang >> 4];
        v[0] = (fx32)(((long long)sc->c * k + 0x800) >> 12) + 0x80000;
        k = dist + FXF((float)*(int *)(p + 0x10) * 0.6666667f);
        v[1] = (fx32)(((long long)sc->s * k + 0x800) >> 12) + 0x50000;
        MUSICAL_MCSS_SetElemPos(*(u8 **)(p + 0x1884), id, v);
        e = (u8 *)DUP_FITTING_ITEM_ElemGetNext(e);
    }
    BG_SYS_ChangeScrollImmediate(2, 3, -*(int *)(p + 0x10));
    r.x = 0x20;
    {
        int t = 0xC0 - *(int *)(p + 0x10);
        if (t >= 0x40) t = 0x40;
        r.y = t + 0xA0;
    }
    CLACT_AddActorSurfacePos((struct Obj *)(*(u8 **)(p + 0x184C)), (const struct Vec2 *)(&r), 0);
    r.x = 0xE0;
    {
        int t = 0xC0 - *(int *)(p + 0x10);
        if (t >= 0x40) t = 0x40;
        r.y = t + 0xA0;
    }
    CLACT_AddActorSurfacePos((struct Obj *)(*(u8 **)(p + 0x1850)), (const struct Vec2 *)(&r), 0);
}
