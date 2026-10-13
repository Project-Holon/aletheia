/*
 * function: FIELD_GIMMICK_ROTATING_ROOM_Exit
 * address: 0x021F3A04
 * packet: pkt_ov046_021F3A04
 * region: ov046
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   FIELDMAP_GetExpObj 0x02188D2C thumb ov021
 *   FIELDMAP_GetCommonWork 0x021897BC thumb ov021
 *   FIELDMAP_FreeCommonWork 0x021897A0 thumb ov021
 *   FLD_EXP_OBJ_RemoveUnit 0x021BE418 thumb ov021
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int FIELDMAP_GetExpObj(int *p);
extern int *FIELDMAP_GetCommonWork(char *,int);
extern void FIELDMAP_FreeCommonWork(u8 *,int);
extern void FLD_EXP_OBJ_RemoveUnit(u8 *,u16);
void FIELD_GIMMICK_ROTATING_ROOM_Exit(u32 a) { u32 p; p=FIELDMAP_GetExpObj((int *)a); FIELDMAP_GetCommonWork((char *)a,1); FIELDMAP_FreeCommonWork((u8 *)a,1); FLD_EXP_OBJ_RemoveUnit((u8 *)p,0); }
