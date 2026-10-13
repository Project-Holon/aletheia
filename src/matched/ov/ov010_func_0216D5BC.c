/*
 * function: FLDMMDL_IsAliasEventId
 * address:  0x0216D5BC
 * packet:   pkt_ov010_0216D5BC
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FLDMMDL_GetEventId  0x0216D5B8  thumb  ov010
 */
typedef unsigned short u16;
typedef unsigned int u32;
extern u32 FLDMMDL_GetEventId(void *p);
int FLDMMDL_IsAliasEventId(void *p)
{
    return FLDMMDL_GetEventId(p) == 0xFFFF;
}
