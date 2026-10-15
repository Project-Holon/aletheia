/*
 * function: FIELD_RAIL_StepLocation
 * address:  0x021B7C90
 * packet:   pkt_ov021_021B7C90
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GF_STANDARD_CompareBytes  0x0203EFC8  arm
 *   FIELD_RAIL_WORK_IsLocationValid  0x021B7DE0  thumb
 *   FIELD_RAIL_WORK_SetLocation  0x021B7EE4  thumb
 *   FIELD_RAIL_WORK_GetPos  0x021B8028  thumb
 *   FIELD_RAIL_WORK_StartStep  0x021B80E0  thumb
 *   FIELD_RAIL_WORK_UpdateStep  0x021B810C  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned char u8;
typedef unsigned int u32;

struct Mgr { u8 pad00[0x1C]; u8 *f1C; };

extern void FIELD_RAIL_WORK_SetLocation(void *p, void *r);
extern void FIELD_RAIL_WORK_StartStep(void *p, int a, void *key);
struct Sub;
extern void FIELD_RAIL_WORK_UpdateStep(struct Sub *o);
extern void FIELD_RAIL_WORK_GetPos(void *p, void *q);
typedef signed int     s32;
extern s32 GF_STANDARD_CompareBytes(const u8 *a, const u8 *b, u32 n);
extern int FIELD_RAIL_WORK_IsLocationValid(void *p, void *r);

int FIELD_RAIL_StepLocation(struct Mgr *m, void *r, void *key, void *q)
{
    FIELD_RAIL_WORK_SetLocation(m->f1C, r);
    FIELD_RAIL_WORK_StartStep(m->f1C, 4, key);
    FIELD_RAIL_WORK_UpdateStep((struct Sub *)m->f1C);
    FIELD_RAIL_WORK_GetPos(m->f1C, q);
    if (GF_STANDARD_CompareBytes(r, m->f1C + 0x5C, 8) == 0)
        return 0;
    return FIELD_RAIL_WORK_IsLocationValid(m->f1C, m->f1C + 0x5C);
}
