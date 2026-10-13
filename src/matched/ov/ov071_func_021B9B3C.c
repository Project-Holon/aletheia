/*
 * function: MONOLITH_TOOL_DeleteRowGrids
 * address: 0x021B9B3C
 * packet: pkt_ov071_021B9B3C
 * region: ov071
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BMP_OAM_Delete 0x0202570C thumb
 *   BMP_Delete 0x020437AC arm
 */

struct Grid;
struct Obj020437AC;
extern void BMP_OAM_Delete(struct Grid *g);
extern void BMP_Delete(struct Obj020437AC *p);
void MONOLITH_TOOL_DeleteRowGrids(char *p) { int i; for (i = 0; i < 7; i++) { BMP_OAM_Delete(*(void **)(p + i * 4 + 0x2a0)); BMP_Delete(*(void **)(p + i * 4 + 0x2bc)); } }
