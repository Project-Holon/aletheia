/*
 * function: FLDEFF_D06DENKI_SparkDraw
 * address:  0x021C8FF0
 * packet:   pkt_ov021_021C8FF0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   G3D_SYSTEM_SetObjectAnimeFrame  0x0204784C  arm
 *   G3D_SYSTEM_IncObjectAnimeFrame  0x020478B8  arm
 *   G3D_SYSTEM_GetObjectAnimeFrame  0x02047828  arm
 *   func_0207ADC4  0x0207ADC4  arm
 *   FIELD_EFFECT_GetObjectPos  0x021AC1B8  thumb  ov021
 *   G3D_SYSTEM_DrawObjectCulling  0x02047AC8  arm
 *   sD06DenkiSparkDrawStatus     0x021DABCC  data  a4
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;

typedef struct T { int w[15]; } T;

extern T sD06DenkiSparkDrawStatus;

typedef signed int     s32;
struct AnmCtl;
typedef unsigned short u16;
extern u32 G3D_SYSTEM_SetObjectAnimeFrame(struct AnmCtl *c, u16 idx, s32 *frame);
struct Arg;
extern int G3D_SYSTEM_IncObjectAnimeFrame(void *a, int idx, int amount);
extern u32 G3D_SYSTEM_GetObjectAnimeFrame(struct AnmCtl *c, u32 idx, s32 *frame);
extern void func_0207ADC4(int *m);
extern void FIELD_EFFECT_GetObjectPos(u32 a, T *t);
extern int G3D_SYSTEM_DrawObjectCulling(void *a0, struct Arg *a1);

void FLDEFF_D06DENKI_SparkDraw(u32 a, u32 *b)
{
    T t;
    u32 h;

    if (b[2] == 0) {
        t = sD06DenkiSparkDrawStatus;
        h = *(u32 *)(b[0] + 0x30);
        G3D_SYSTEM_SetObjectAnimeFrame((struct AnmCtl *)h, 0, (s32 *)(b + 1));
        if (G3D_SYSTEM_IncObjectAnimeFrame((void *)h, 0, 0x1000) == 0) {
            b[2] = 1;
        }
        if (G3D_SYSTEM_GetObjectAnimeFrame((struct AnmCtl *)h, 0, (s32 *)(b + 1)) == 0) {
            b[2] = 1;
        }
        func_0207ADC4(&t.w[6]);
        FIELD_EFFECT_GetObjectPos(a, &t);
        G3D_SYSTEM_DrawObjectCulling((void *)h, (struct Arg *)(&t));
    }
}
