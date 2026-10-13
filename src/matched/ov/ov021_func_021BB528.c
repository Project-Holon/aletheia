/*
 * function: FLDEFF_GYOE_SetMMdl
 * address:  0x021BB528
 * packet:   pkt_ov021_021BB528
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELD_EFFECT_GetResource  0x021ABEA0  thumb  ov021
 *   FLDMMDL_GetCheckInfo  0x0216E1A4  thumb  ov010
 *   FIELD_EFFECT_GetFieldMap  0x021ABE14  thumb  ov021
 *   FLDEFF_GYOE_PlaySe  0x021BB778  thumb  ov021
 *   FIELD_EFFECT_AddObject  0x021ABFA8  thumb  ov021
 *   sGyoeTaskHeader     0x021D9A7C  data  a4
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;

extern int FIELD_EFFECT_GetResource(u32 a, u32 b);
typedef unsigned char  u8;
extern int FLDMMDL_GetCheckInfo(int a0, int a1);
extern u32 FIELD_EFFECT_GetFieldMap(u8 *p);
extern void FLDEFF_GYOE_PlaySe(int n);
extern void FIELD_EFFECT_AddObject(u32, void *, int, int, void *, int);
extern int sGyoeTaskHeader;

void FLDEFF_GYOE_SetMMdl(u32 a, u32 b, u32 c, u32 d)
{
    u32 s[7];

    s[0] = c;
    s[1] = d;
    s[2] = FIELD_EFFECT_GetResource(a, 4);
    s[3] = b;
    FLDMMDL_GetCheckInfo(b, (int)(&s[4]));
    s[6] = FIELD_EFFECT_GetFieldMap((u8 *)a);
    if (d == 1)
        FLDEFF_GYOE_PlaySe(c);
    FIELD_EFFECT_AddObject(a, &sGyoeTaskHeader, 0, 0, s, 0);
}
