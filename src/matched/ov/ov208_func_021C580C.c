/*
 * function: ZUKAN_DETAIL_FORM_RebuildModels
 * address:  0x021C580C
 * packet:   pkt_ov208_021C580C
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   ZUKAN_DETAIL_FORM_DestroyModelItem  0x021C51A0  thumb
 *   ZUKAN_DETAIL_FORM_InitAnimState  0x021C51C8  thumb
 *   ZUKAN_DETAIL_FORM_RefreshFormEntries  0x021C5664  thumb
 *   ZUKAN_DETAIL_FORM_PlaceModelItem  0x021C569C  thumb
 *   ZUKAN_DETAIL_FORM_SwapIconActor  0x021C5CF0  thumb
 *   ZUKAN_DETAIL_FORM_DrawSpeciesLabels  0x021C4BB4  thumb
 *   ZUKAN_DETAIL_FORM_UpdateBgScrollForState  0x021C4F30  thumb
 *   ZUKAN_DETAIL_FORM_DrawFormLabelMain  0x021C4E54  thumb
 *   ZUKAN_DETAIL_FORM_DrawFormLabelSub  0x021C4EAC  thumb
 *   ZUKAN_DETAIL_FORM_UpdateCursorMarkers  0x021C6A10  thumb
 *   ZUKAN_DETAIL_FORM_UpdateScrollMarkers  0x021C6AFC  thumb
 *   ZUKAN_DETAIL_FORM_UpdateArrowVisibility  0x021C68D4  thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Ov208Mdl {
    u32 obj;
    u32 f4;
    u8  pos[0x3c];
};

extern void ZUKAN_DETAIL_FORM_DestroyModelItem(char *p, int a);
extern void ZUKAN_DETAIL_FORM_InitAnimState(u32 obj, int side, u8 *p);
extern void ZUKAN_DETAIL_FORM_RefreshFormEntries(u16 *heap, u8 *p, int key);
extern void ZUKAN_DETAIL_FORM_PlaceModelItem(u16 *heap, u8 *p, int key, int a, int b, int pose, u16 idx);
extern void ZUKAN_DETAIL_FORM_SwapIconActor(u16 *heap, u8 *p, int key);
extern void ZUKAN_DETAIL_FORM_DrawSpeciesLabels(u16 *heap, u8 *p, int key);
extern void ZUKAN_DETAIL_FORM_UpdateBgScrollForState(u16 *heap, u8 *p, int key);
extern void ZUKAN_DETAIL_FORM_DrawFormLabelMain(u16 *heap, u8 *p, int key);
extern void ZUKAN_DETAIL_FORM_DrawFormLabelSub(u16 *heap, u8 *p, int key);
extern void ZUKAN_DETAIL_FORM_UpdateCursorMarkers(u16 *heap, u8 *p, int key);
extern void ZUKAN_DETAIL_FORM_UpdateScrollMarkers(u16 *heap, u8 *p, int key);
extern void ZUKAN_DETAIL_FORM_UpdateArrowVisibility(u16 *heap, u8 *p, int key);

#define W(o) (*(u32 *)(p + (o)))
#define H(o) (*(u16 *)(p + (o)))
#define MDL(i) ((struct Ov208Mdl *)(p + 0xc) + (i))

void ZUKAN_DETAIL_FORM_RebuildModels(u16 *heap, u8 *p, int key)
{
    u8 i;
    int a;
    int b;
    int pose;

    for (i = 0; i < 4; i++)
        ZUKAN_DETAIL_FORM_DestroyModelItem((char *)MDL(i), W(8));
    ZUKAN_DETAIL_FORM_RefreshFormEntries(heap, p, key);
    pose = 0;
    if (W(0x6b8) == 4 && H(0x548) >= 2)
        pose = 1;
    a = W(0x124) != 0 ? 0 : 4;
    b = W(0x124) != 0 ? 4 : 1;
    ZUKAN_DETAIL_FORM_PlaceModelItem(heap, p, key, a, b, pose, H(0x54e));
    if (a != 4)
        ZUKAN_DETAIL_FORM_InitAnimState(MDL(0)->f4, 0, p);
    if (b != 4)
        ZUKAN_DETAIL_FORM_InitAnimState(MDL(1)->f4, 1, p);
    if (W(0x6b8) == 4 && H(0x548) >= 2) {
        a = W(0x124) != 0 ? 2 : 4;
        b = W(0x124) != 0 ? 4 : 3;
        ZUKAN_DETAIL_FORM_PlaceModelItem(heap, p, key, a, b, 2, H(0x550));
        if (a != 4)
            ZUKAN_DETAIL_FORM_InitAnimState(MDL(2)->f4, 2, p);
        if (b != 4)
            ZUKAN_DETAIL_FORM_InitAnimState(MDL(3)->f4, 3, p);
    }
    ZUKAN_DETAIL_FORM_SwapIconActor(heap, p, key);
    ZUKAN_DETAIL_FORM_DrawSpeciesLabels(heap, p, key);
    ZUKAN_DETAIL_FORM_UpdateBgScrollForState(heap, p, key);
    ZUKAN_DETAIL_FORM_DrawFormLabelMain(heap, p, key);
    ZUKAN_DETAIL_FORM_DrawFormLabelSub(heap, p, key);
    ZUKAN_DETAIL_FORM_UpdateCursorMarkers(heap, p, key);
    ZUKAN_DETAIL_FORM_UpdateScrollMarkers(heap, p, key);
    ZUKAN_DETAIL_FORM_UpdateArrowVisibility(heap, p, key);
}
