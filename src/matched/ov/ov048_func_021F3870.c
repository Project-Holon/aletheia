/*
 * function: FIELD_GIMMICK_GATE_ApplyBoardScroll
 * address: 0x021F3870
 * packet: pkt_ov048_021F3870
 * region: ov048
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GIMMICK_OBJ_ELBOARD_SetScroll 0x021F47BC thumb ov048
 */
struct M;
extern void GIMMICK_OBJ_ELBOARD_SetScroll(struct M *p, int v);
void FIELD_GIMMICK_GATE_ApplyBoardScroll(int *p) { GIMMICK_OBJ_ELBOARD_SetScroll((void *)p[5], p[6] << 12); }
