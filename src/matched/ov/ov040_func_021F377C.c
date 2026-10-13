/*
 * function: FIELD_GIMMICK_FLAG_ANIME_Exit
 * address: 0x021F377C
 * packet: pkt_ov040_021F377C
 * region: ov040
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   FIELDMAP_GetExpObj 0x02188D2C thumb ov021
 *   FIELDMAP_FreeCommonWork 0x021897A0 thumb ov021
 *   FLD_EXP_OBJ_RemoveUnit 0x021BE418 thumb ov021
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int FIELDMAP_GetExpObj(int *p);
extern void FIELDMAP_FreeCommonWork(u8 *p, int i);
extern void FLD_EXP_OBJ_RemoveUnit(u8 *p, u16 i);
void FIELD_GIMMICK_FLAG_ANIME_Exit(u8 *p) { u8 *q; q = (u8 *)FIELDMAP_GetExpObj((int *)p); FIELDMAP_FreeCommonWork(p, 1); FLD_EXP_OBJ_RemoveUnit(q, 0); }
