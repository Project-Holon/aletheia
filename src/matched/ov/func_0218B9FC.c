/*
 * function: FIELD_BUILDMODEL_UnregisterObject
 * address:  0x0218B9FC
 * packet:   pkt_0218B924
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail-call thunk: forwards to FIELD_BUILDMODEL_RemoveEntriesByObject with no argument change.
 *
 * symbols:
 *   FIELD_BUILDMODEL_RemoveEntriesByObject  0x0218C4EC  thumb
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void FIELD_BUILDMODEL_RemoveEntriesByObject(unsigned char *p, void *key);

void FIELD_BUILDMODEL_UnregisterObject(int a, int obj)
{
    FIELD_BUILDMODEL_RemoveEntriesByObject((unsigned char *)a, (void *)obj);
}
