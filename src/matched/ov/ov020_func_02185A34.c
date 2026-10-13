/*
 * function: EVENT_MAPCHANGE_SetMapEffectMask
 * address: 0x02185A34
 * packet: pkt_ov020_02185A34
 * region: ov020
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GAME_DATA_GetMoveModelSys 0x02012B38 thumb
 *   ZONEDATA_GetFieldSkillMapEffect 0x02013F6C thumb
 *   FIELD_STATUS_IsFlashActive 0x02014468 thumb
 *   FIELD_STATUS_SetMapEffectMask 0x0201446C thumb
 * interface: 0201446C's full-word input matches the absent call-site truncation.
 */
typedef unsigned char  u8;
struct BigObj;
struct Sub02014444Obj;
extern void *GAME_DATA_GetMoveModelSys(const struct BigObj *p);
extern unsigned int ZONEDATA_GetFieldSkillMapEffect(unsigned int id);
extern u8 FIELD_STATUS_IsFlashActive(struct Sub02014444Obj *o);
extern void FIELD_STATUS_SetMapEffectMask(void *p, unsigned int value);
void EVENT_MAPCHANGE_SetMapEffectMask(void *p, unsigned int id)
{
    void *object;
    unsigned int flags;
    object = GAME_DATA_GetMoveModelSys(p);
    flags = ZONEDATA_GetFieldSkillMapEffect(id);
    if ((flags & 1) && FIELD_STATUS_IsFlashActive(object)) {
        flags &= ~1;
        flags |= 2;
    }
    FIELD_STATUS_SetMapEffectMask(object, flags);
}
