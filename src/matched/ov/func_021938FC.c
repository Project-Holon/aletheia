/*
 * function: FIELD_WFBC_WriteSaveData
 * address:  0x021938FC
 * packet:   pkt_021938FC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail-call thunk: forwards to FIELD_WFBC_CopyPeopleToSaveData with no argument change.
 *
 * symbols:
 *   FIELD_WFBC_CopyPeopleToSaveData  0x02193E54  thumb
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void FIELD_WFBC_CopyPeopleToSaveData(unsigned char *p, unsigned char *q);

void FIELD_WFBC_WriteSaveData(void *v, unsigned char *a1)
{
    FIELD_WFBC_CopyPeopleToSaveData(v, a1);
}
