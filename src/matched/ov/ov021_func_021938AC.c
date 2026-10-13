/*
 * function: FIELD_WFBC_Create
 * address:  0x021938AC
 * packet:   pkt_ov021_021938AC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02030734  0x02030734  arm  arm9
 *   FIELD_WFBC_Clear  0x02193CBC  thumb  ov021
 *   sFieldWfbcFileName     0x021DDA60  data   ov021  a1
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef short          s16;

extern char sFieldWfbcFileName[];

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void FIELD_WFBC_Clear(unsigned char *p);

void *FIELD_WFBC_Create(u32 heap)
{
    void *o = func_02030734(heap, 0x144, 1, sFieldWfbcFileName, 0x12A);
    FIELD_WFBC_Clear(o);
    return o;
}
