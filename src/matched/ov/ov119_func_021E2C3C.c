/*
 * function: POKETRADE_SAVE_Setup3DDrawState
 * address: 0x021E2C3C
 * packet: pkt_ov119_021E2C3C
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * volatile: 0x04000060 reread at 021E2C9C, 021E2CAA, 021E2CB6, 021E2CC0, 021E2CC8; 0x04000580 hardware store at 021E2CEC.
 * symbols:
 *   MTX_Identity33_ 0x0207ADC4 arm
 *   ICA_ANIME_SetCameraPos 0x02011CF0 thumb
 *   ICA_ANIME_SetCameraTarget 0x02011D0C thumb
 *   G3D_CAMERA_Reset 0x02048AD0 arm
 *   G3X_SetFog 0x0207DC44 arm
 *   G3X_SetClearColor 0x0207DD24 arm
 *   G3D_SYSTEM_SetLight 0x02046A94 arm
 *   ICA_ANIME_GetTranslate 0x02011610 thumb
 *   BUTTON_MAN_SetEmitterPos 0x02051838 arm
 *   d_021E79C8 0x021E79C8 data a4
 */
typedef unsigned short u16;
typedef unsigned char u8;
typedef unsigned int u32;
typedef int fx32;
typedef struct { fx32 x, y, z; } VecFx32;
typedef struct { fx32 m[3][3]; } MtxFx33;
typedef struct { VecFx32 trans; VecFx32 scale; MtxFx33 rot; } Transform;
typedef struct {
    char pad0[0x90];
    u32 anim90;
    u32 anim94;
    u32 anim98;
    u32 anim9c;
    void *objA0;
    void *objA4;
    void *objA8;
    void *objAC;
} Sub;
typedef struct {
    char pad0[0xc];
    Sub *sub;
    char pad10[0x83c - 0x10];
    void *x83c;
} Work;
typedef enum { SHADING_TOON, SHADING_HIGHLIGHT } Shading;
extern void MTX_Identity33_(MtxFx33 *m);
extern void ICA_ANIME_SetCameraPos(void *a0, void *a1);
extern void ICA_ANIME_SetCameraTarget(void *a0, void *a1);
struct Light;
extern void G3D_CAMERA_Reset(struct Light *l);
extern void G3X_SetFog(int, int, int, int);
extern void G3X_SetClearColor(u16 rgb, int alpha, int depth, int polygonID, int fog);
extern void G3D_SYSTEM_SetLight(u32 idx, const u16 *src);
struct IcaAnime;
struct Rec12;
extern u32 ICA_ANIME_GetTranslate(struct IcaAnime *t, struct Rec12 *out);
extern void BUTTON_MAN_SetEmitterPos(void *obj, VecFx32 *v);
extern char d_021E79C8[];
static inline void shading(Shading s) { *(volatile u16 *)0x04000060 = (u16)((*(volatile u16 *)0x04000060 & ~0x3002) | (s << 1)); }
static inline void antialias(int b) { if(b) *(volatile u16 *)0x04000060 = (u16)((*(volatile u16 *)0x04000060 & ~0x3000) | 0x10); else *(volatile u16 *)0x04000060 &= (u16)~0x3010; }
static inline void alphatest(int b) { if(b) *(volatile u16 *)0x04000060 = (u16)((*(volatile u16 *)0x04000060 & ~0x3000) | 4); else *(volatile u16 *)0x04000060 &= (u16)~0x3004; }
static inline void blend(int b) { if(b) *(volatile u16 *)0x04000060 = (u16)((*(volatile u16 *)0x04000060 & ~0x3000) | 8); else *(volatile u16 *)0x04000060 &= (u16)~0x3008; }
static inline void edge(int b) { if(b) *(volatile u16 *)0x04000060 = (u16)((*(volatile u16 *)0x04000060 & ~0x3000) | 0x20); else *(volatile u16 *)0x04000060 &= (u16)~0x3020; }
void POKETRADE_SAVE_Setup3DDrawState(Work *w, Transform *t)
{
    unsigned i;
    VecFx32 v1;
    VecFx32 v2;
    t->trans.x = 0;
    t->trans.y = 0;
    t->trans.z = 0;
    t->scale.x = 0x1000;
    t->scale.y = 0x1000;
    t->scale.z = 0x1000;
    MTX_Identity33_(&t->rot);
    if (w->sub != 0) {
        if (w->sub->objA8 == 0) ICA_ANIME_SetCameraPos(w->x83c, (void *)w->sub->anim90);
        if (w->sub->objAC == 0) ICA_ANIME_SetCameraTarget(w->x83c, (void *)w->sub->anim94);
    }
    G3D_CAMERA_Reset(w->x83c);
    shading(SHADING_HIGHLIGHT); antialias(1); alphatest(0); blend(0); edge(0);
    G3X_SetFog(1, 0, 0, 0);
    G3X_SetClearColor(0, 0, 0x7fff, 0x3f, 0);
    *(volatile unsigned *)0x04000580 = 0xbfff0000;
    for (i = 0; i < 4; i++) G3D_SYSTEM_SetLight((u8)i, (const u16 *)(d_021E79C8 + i * 8));
    if (w->sub != 0) {
        if (w->sub->objA0 != 0) {
            ICA_ANIME_GetTranslate((struct IcaAnime *)w->sub->anim98, (struct Rec12 *)&v1);
            BUTTON_MAN_SetEmitterPos(w->sub->objA0, &v1);
        }
        if (w->sub->objA4 != 0) {
            ICA_ANIME_GetTranslate((struct IcaAnime *)w->sub->anim9c, (struct Rec12 *)&v2);
            BUTTON_MAN_SetEmitterPos(w->sub->objA4, &v2);
        }
    }
}
