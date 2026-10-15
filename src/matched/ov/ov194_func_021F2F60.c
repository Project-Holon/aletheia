/*
 * function: NAMEIN_GRAPHIC_GridValue
 * address: 0x021F2F60
 * packet: pkt_ov194_021F2F60
 * region: ov194
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   NAMEIN_GRAPHIC_ComputeGridValue 0x021F2F68 thumb ov194
 */
extern int NAMEIN_GRAPHIC_ComputeGridValue(const int *,int *);
int NAMEIN_GRAPHIC_GridValue(const int *p,int *out) {return NAMEIN_GRAPHIC_ComputeGridValue(p,out);}
