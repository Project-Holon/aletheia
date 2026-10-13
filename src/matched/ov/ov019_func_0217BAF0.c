/*
 * function: UNION_ONESELF_SetFieldBusy
 * address: 0x0217BAF0
 * packet: pkt_ov019_0217BAF0
 * region: ov019
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   FIELDMAP_CTRL_GRID_SetBusy 0x021A2E44 thumb ov021
 */
extern void FIELDMAP_CTRL_GRID_SetBusy(int, unsigned int);
void UNION_ONESELF_SetFieldBusy(char *p, int x, unsigned int v)
{
    p[0x3563] = v;
    FIELDMAP_CTRL_GRID_SetBusy(x, v);
}
