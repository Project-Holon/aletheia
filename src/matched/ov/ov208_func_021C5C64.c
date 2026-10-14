/*
 * function: ZUKAN_DETAIL_FORM_RebuildSideModels
 * address:  0x021C5C64
 * packet:   pkt_ov208_021C5C64
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   ZUKAN_DETAIL_FORM_DestroyModelItem  0x021C51A0  thumb
 *   ZUKAN_DETAIL_FORM_InitAnimState  0x021C51C8  thumb
 *   ZUKAN_DETAIL_FORM_PlaceModelItem  0x021C569C  thumb
 *   func_021C4EAC  0x021C4EAC  thumb
 *   ZUKAN_DETAIL_FORM_UpdateCursorMarkers  0x021C6A10  thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void ZUKAN_DETAIL_FORM_DestroyModelItem(char *p, int a);
extern void ZUKAN_DETAIL_FORM_InitAnimState(u32 turn, int side, u8 *p);
extern void ZUKAN_DETAIL_FORM_PlaceModelItem(void *a0, u8 *p, int key, int a, int b, int pose, u16 idx);
extern void func_021C4EAC(void *a0, u8 *p, int key);
extern void ZUKAN_DETAIL_FORM_UpdateCursorMarkers(void *a0, u8 *p, int key);

#define W(o) (*(u32 *)(p + (o)))
#define H(o) (*(u16 *)(p + (o)))

void ZUKAN_DETAIL_FORM_RebuildSideModels(void *a0, u8 *p, int key)
{
    int a;
    int b;

    ZUKAN_DETAIL_FORM_DestroyModelItem((char *)(p + 0x94), W(8));
    ZUKAN_DETAIL_FORM_DestroyModelItem((char *)(p + 0xd8), W(8));
    a = W(0x124) != 0 ? 2 : 4;
    b = W(0x124) != 0 ? 4 : 3;
    ZUKAN_DETAIL_FORM_PlaceModelItem(a0, p, key, a, b, 2, H(0x550));
    if (a != 4)
        ZUKAN_DETAIL_FORM_InitAnimState(W(0x98), 2, p);
    if (b != 4)
        ZUKAN_DETAIL_FORM_InitAnimState(W(0xdc), 3, p);
    func_021C4EAC(a0, p, key);
    ZUKAN_DETAIL_FORM_UpdateCursorMarkers(a0, p, key);
}
