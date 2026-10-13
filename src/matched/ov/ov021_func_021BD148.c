/*
 * function: PLACE_NAME_LETTER_Create
 * address:  0x021BD148
 * packet:   pkt_ov021_021BD148
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   PLACE_NAME_LETTER_AllocWork  0x021BD214  thumb  ov021
 *   PLACE_NAME_LETTER_InitWork  0x021BD234  thumb  ov021
 *   PLACE_NAME_LETTER_SetHeapId  0x021BD2BC  thumb  ov021
 *   PLACE_NAME_LETTER_CreateBmp  0x021BD250  thumb  ov021
 *   PLACE_NAME_LETTER_CreateBmpOam  0x021BD278  thumb  ov021
 *   PLACE_NAME_LETTER_SetVisibleRaw  0x021BD5F8  thumb  ov021
 */

extern void *PLACE_NAME_LETTER_AllocWork(int a);
extern void PLACE_NAME_LETTER_InitWork(void *p);
typedef unsigned char  u8;
extern void PLACE_NAME_LETTER_SetHeapId(u8 *p, int v);
extern void PLACE_NAME_LETTER_CreateBmp(void *p);
extern void PLACE_NAME_LETTER_CreateBmpOam(void *p, int a, int b, int c);
extern void PLACE_NAME_LETTER_SetVisibleRaw(void *p, unsigned int a);

void *PLACE_NAME_LETTER_Create(int a0, int a1, int a2, int a3)
{
    void *p = PLACE_NAME_LETTER_AllocWork(a0);
    PLACE_NAME_LETTER_InitWork(p);
    PLACE_NAME_LETTER_SetHeapId(p, a0);
    PLACE_NAME_LETTER_CreateBmp(p);
    PLACE_NAME_LETTER_CreateBmpOam(p, a1, a2, a3);
    PLACE_NAME_LETTER_SetVisibleRaw(p, 0);
    return p;
}
