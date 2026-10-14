/*
 * function: ZUKAN_DETAIL_FORM_UpdateScrollInput
 * address:  0x021C6BB4
 * packet:   pkt_ov208_021C6BB4
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   ZUKAN_DETAIL_FORM_HandleScrollKey  0x021C6D10  thumb
 *   ZUKAN_DETAIL_FORM_HandleScrollTouch  0x021C6C00  thumb
 */

typedef unsigned char u8;
typedef unsigned int  u32;

extern int  ZUKAN_DETAIL_FORM_HandleScrollKey(void *a0, u8 *p, int key);
extern u32  ZUKAN_DETAIL_FORM_HandleScrollTouch(void *a0, u8 *p, int key);

#define W(o) (*(u32 *)(p + (o)))

void ZUKAN_DETAIL_FORM_UpdateScrollInput(void *a0, u8 *p, int key)
{
    if ((W(0x6b8) == 4 && W(0x6b4) != 0 && W(0x694) == 5) || W(0x6d4) != 0) {
        if (ZUKAN_DETAIL_FORM_HandleScrollKey(a0, p, key) == 0)
            ZUKAN_DETAIL_FORM_HandleScrollTouch(a0, p, key);
    }
}
