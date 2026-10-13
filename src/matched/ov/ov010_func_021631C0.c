/*
 * function: FLDMMDL_MOVE_InitAttrInfo
 * address:  0x021631C0
 * packet:   pkt_ov010_021631C0
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02082C60  0x02082C60  arm
 *   FLDMMDL_GetOldAttr  0x0216D7E4  thumb  ov010
 *   FLDMMDL_GetNowAttr  0x0216D7DC  thumb  ov010
 *   MAP_ATTR_GetTerrainId  0x021AB0F0  thumb  ov021
 *   MAP_ATTR_GetFlags  0x021AB0F8  thumb  ov021
 *   FLDMMDL_GetObjCodeParam  0x0216E3C4  thumb  ov010
 *   FLDMMDL_GetMmdlSys  0x0216D67C  thumb  ov010
 *   FLDMMDL_SysGetFieldMap  0x0216D534  thumb  ov010
 *   FIELDMAP_GetEffect  0x02188CD0  thumb  ov021
 *   FIELD_EFFECT_GetModelBaseOffset  0x021ABE28  thumb  ov021
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    int a;
    int b;
    u16 c;
    u16 d;
    u16 e;
    u16 f;
    void *g;
    int h;
    u8 i;
} S;

extern void func_02082C60();
extern u32 FLDMMDL_GetOldAttr(void *p);
extern u32 FLDMMDL_GetNowAttr(void *p);
extern u16 MAP_ATTR_GetTerrainId(u32 attr);
extern u16 MAP_ATTR_GetFlags(u32 attr);
extern void *FLDMMDL_GetObjCodeParam(void *p);
extern void *FLDMMDL_GetMmdlSys(void *a0);
extern u32 FLDMMDL_SysGetFieldMap(void *p);
extern u32 FIELDMAP_GetEffect(u8 *p);
extern u8 FIELD_EFFECT_GetModelBaseOffset(u8 *p);

void FLDMMDL_MOVE_InitAttrInfo(int a, S *s)
{
    int b;
    u32 h;

    func_02082C60(s, 0, 0x1c);
    s->a = FLDMMDL_GetOldAttr((void *)a);
    b = FLDMMDL_GetNowAttr((void *)a);
    s->b = b;
    if (b != -1) {
        s->d = MAP_ATTR_GetTerrainId(b);
        s->f = MAP_ATTR_GetFlags(s->b);
    }
    if (s->a != -1) {
        s->c = MAP_ATTR_GetTerrainId(s->a);
        s->e = MAP_ATTR_GetFlags(s->a);
    }
    s->g = FLDMMDL_GetObjCodeParam((void *)a);
    h = FIELDMAP_GetEffect((u8 *)FLDMMDL_SysGetFieldMap((void *)FLDMMDL_GetMmdlSys((void *)a)));
    s->h = h;
    s->i = FIELD_EFFECT_GetModelBaseOffset((u8 *)h);
}
