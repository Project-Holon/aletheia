/*
 * function: FIELD_WFBC_GetPeopleNum
 * address:  0x021938F4
 * packet:   pkt_021938F4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   FIELD_WFBC_CountPeople  0x02193D08  thumb  ov021
 *
 * Unblocked by matching the leaf at 0x02193D08 in ov021; the tail-call site
 * now resolves via `matched`.
 */

int FIELD_WFBC_CountPeople(unsigned char *p);

int FIELD_WFBC_GetPeopleNum(unsigned char *p)
{
    return FIELD_WFBC_CountPeople(p);
}
