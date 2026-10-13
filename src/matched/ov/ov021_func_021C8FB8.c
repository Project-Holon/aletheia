/*
 * function: FLDEFF_D06DENKI_SparkInit
 * address:  0x021C8FB8
 * packet:   pkt_ov021_021C8FB8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_020061E4  0x020061E4  thumb
 *   FIELD_EFFECT_GetObjectParam  0x021AC1AC  thumb  ov021
 *   FIELD_EFFECT_SetObjectPos  0x021AC1CC  thumb  ov021
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { u32 x, y, z; } V;
extern int FIELD_EFFECT_GetObjectParam(u32 a);
extern void FIELD_EFFECT_SetObjectPos(u32 a, u32 *p);
extern void func_020061E4(u32 id);
void FLDEFF_D06DENKI_SparkInit(u32 a, u32 *out)
{
    u32 *r = (u32 *)FIELD_EFFECT_GetObjectParam(a);
    *out = r[0];
    FIELD_EFFECT_SetObjectPos(a, &r[1]);
    func_020061E4(0x6a2);
}
