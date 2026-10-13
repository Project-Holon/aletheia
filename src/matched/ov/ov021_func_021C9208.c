/*
 * function: FLDEFF_D06DENKI_FollowDraw
 * address:  0x021C9208
 * packet:   pkt_ov021_021C9208
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0207ADC4  0x0207ADC4  arm
 *   FIELD_EFFECT_GetObjectPos  0x021AC1B8  thumb  ov021
 *   G3D_SYSTEM_DrawObjectCulling  0x02047AC8  arm
 *   sD06DenkiFollowDrawStatus     0x021DAC08  data  a4
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;

typedef struct T { int w[15]; } T;
typedef struct V3 { int v[3]; } V3;

extern T sD06DenkiFollowDrawStatus;

extern void func_0207ADC4(int *m);
extern void FIELD_EFFECT_GetObjectPos(u32 a, T *t);
struct Arg;
extern int G3D_SYSTEM_DrawObjectCulling(void *a0, struct Arg *a1);

void FLDEFF_D06DENKI_FollowDraw(u32 a, u32 *b)
{
    T t = sD06DenkiFollowDrawStatus;

    func_0207ADC4(&t.w[6]);
    FIELD_EFFECT_GetObjectPos(a, &t);
    G3D_SYSTEM_DrawObjectCulling((void *)b[6], (struct Arg *)(&t));
    *(V3 *)&t = *(V3 *)(b + 10);
    G3D_SYSTEM_DrawObjectCulling((void *)b[13], (struct Arg *)(&t));
}
