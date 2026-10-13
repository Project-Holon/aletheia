/*
 * function: FIELD_GIMMICK_GATE_StartBoardAnime
 * address: 0x021F39BC
 * packet: pkt_ov048_021F39BC
 * region: ov048
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   FIELDMAP_GetExpObj 0x02188D2C thumb ov021
 *   FLD_EXP_OBJ_SetAnimeEnabled 0x021BE700 thumb ov021
 *   gGateBoardAnimeTable 0x021F50D2 data a2
 */
typedef unsigned short u16;
extern int FIELDMAP_GetExpObj(int *p);
extern void FLD_EXP_OBJ_SetAnimeEnabled(void *p, int i, int j, int k, int flag);
extern const u16 gGateBoardAnimeTable[];
void FIELD_GIMMICK_GATE_StartBoardAnime(int *p) { FLD_EXP_OBJ_SetAnimeEnabled((void *)FIELDMAP_GetExpObj((int *)p[1]),1,0,gGateBoardAnimeTable[((int *)p[7])[0x1d]],1); }
