/*
 * function: INTRUDE_FIELD_GetMmdlParamPair
 * address: 0x0217C274
 * packet: pkt_ov018_0217C274
 * region: ov018
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   FLDMMDL_GetParam 0x0216D63C thumb ov010
 */
extern int FLDMMDL_GetParam(char *, int);
void INTRUDE_FIELD_GetMmdlParamPair(unsigned int *out, char *p)
{
    int lo;
    lo = FLDMMDL_GetParam(p, 1);
    *out = lo | (FLDMMDL_GetParam(p, 2) << 16);
}
