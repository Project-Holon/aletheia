/*
 * function: FLDEFF_IAIGIRI_Draw
 * address:  0x021C9690
 * packet:   pkt_ov021_021C9690
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   sIaigiriDrawStatus  0x021DAC94  data  ov021  a4
 *   func_02030734  0x02030734  arm
 *   func_020307B0  0x020307B0  arm
 *   G3D_SYSTEM_DrawObjectCulling  0x02047AC8  arm
 *   MTX_Identity33_  0x0207ADC4  arm
 *   FIELD_EFFECT_GetObjectPos  0x021AC1B8  thumb  ov021
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u32 func_020307B0(void *p);
typedef struct { u32 a[6]; u32 b[9]; } T;
typedef struct { u32 f0; u32 f4; } E;
extern T sIaigiriDrawStatus;
extern void MTX_Identity33_(void *p);
extern void FIELD_EFFECT_GetObjectPos(u32 a, T *t);
struct Arg;
extern int G3D_SYSTEM_DrawObjectCulling(void *a0, struct Arg *a1);
void FLDEFF_IAIGIRI_Draw(u32 a, E *e)
{
    T t = sIaigiriDrawStatus;
    MTX_Identity33_(t.b);
    FIELD_EFFECT_GetObjectPos(a, &t);
    G3D_SYSTEM_DrawObjectCulling((void *)e->f4, (struct Arg *)(&t));
}
