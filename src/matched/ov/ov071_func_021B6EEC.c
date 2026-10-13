/*
 * function: MONOLITH_TOOL_FreeLabel
 * address: 0x021B6EEC
 * packet: pkt_ov071_021B6EEC
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
void MONOLITH_TOOL_FreeLabel(void **p) { BMP_OAM_Delete(p[1]); BMP_Delete(p[0]); p[1] = 0; p[0] = 0; }
