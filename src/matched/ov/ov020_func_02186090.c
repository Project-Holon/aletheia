/*
 * function: FIELD_WFBC_DATA_LOCAL_GetPersonIndexFromMmdl
 * address:  0x02186090
 * packet:   pkt_ov020_02186090
 * region:   ov020
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * extent: two zero alignment bytes after the return.
 * symbols:
 *   FLDMMDL_GetObjId  0x0216D588  thumb
 */

typedef unsigned short u16;

u16 FLDMMDL_GetObjId(void *p);

int FIELD_WFBC_DATA_LOCAL_GetPersonIndexFromMmdl(void *p)
{
    return FLDMMDL_GetObjId(p) - 0x80;
}
