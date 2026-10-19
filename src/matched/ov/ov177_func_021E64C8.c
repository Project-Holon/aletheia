/*
 * function: WIFIBATTLEMATCH_VIEW_StepMainWindow
 * address: 0x021E64C8
 * packet: pkt_ov177_021E64C8
 * region: ov177
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 *
 * symbols:
 *   CLACT_GetActorSurfacePos  0x0204B454  arm  arm9
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb  arm9
 *   CLACT_AddActorSurfacePos  0x0204B404  arm  arm9
 *   BG_SYS_ChangeScroll  0x02041EE4  arm  arm9
 */
typedef struct { short x, y; } Pt;
typedef struct {
    char pad0[0x16c];
    void *objs[22];      /* 0x16c */
    char pad1c4[0x200 - 0x1c4];
    unsigned count;      /* 0x200 */
    short baseX[22];     /* 0x204 */
    unsigned char bg;    /* 0x230 */
    char pad231[3];
    unsigned layer;      /* 0x234 */
} Work;
struct Actor;
struct PtS;
typedef unsigned short u16;
extern void CLACT_GetActorSurfacePos(struct Actor *actor, struct PtS *out, u16 space);
extern void CLACT_AddActorSurfacePos(void *, const Pt *, unsigned short);
extern void GFL_USE_PlaySeDefaultVolume(unsigned);
extern unsigned func_0209C2B0(unsigned, unsigned);
typedef unsigned int   u32;
extern u32 func_020407E8(u32 layer);
extern void BG_SYS_ChangeScroll(u32 index, u32 a, u32 b);
int WIFIBATTLEMATCH_VIEW_StepMainWindow(Work *w)
{
    int ret;
    int level;
    int i;
    Pt cur, pos;
    if (func_020407E8(w->bg) == 0)
        return 1;
    ret = 0;
    if (w->count == 0) {
        for (i = 0; i < 22; i++) {
            if (w->objs[i] != 0) {
                CLACT_GetActorSurfacePos(w->objs[i], (struct PtS *)&cur, (unsigned short)w->layer);
                w->baseX[i] = cur.x;
            }
        }
        GFL_USE_PlaySeDefaultVolume(0x63b);
    }
    level = func_0209C2B0(w->count << 8, 20) - 0x100;
    for (i = 0; i < 22; i++) {
        if (w->objs[i] != 0) {
            CLACT_GetActorSurfacePos(w->objs[i], (struct PtS *)&pos, (unsigned short)w->layer);
            pos.x = w->baseX[i] - func_0209C2B0(w->count << 8, 20);
            CLACT_AddActorSurfacePos(w->objs[i], &pos, w->layer);
        }
    }
    if (w->count++ >= 20) {
        level = 0;
        w->count = 0;
        ret = 1;
    }
    BG_SYS_ChangeScroll((unsigned char)(w->bg + 1), (int)0, (int)level);
    BG_SYS_ChangeScroll((unsigned char)w->bg, (int)0, (int)level);
    return ret;
}
