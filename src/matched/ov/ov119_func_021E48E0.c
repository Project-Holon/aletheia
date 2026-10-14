/*
 * function: POKETRADE_2D_DeleteOfferIcons
 * address: 0x021E48E0
 * packet: pkt_ov119_021E48E0
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   POKETRADE_2D_DeleteCursorActor 0x021E7058 thumb ov119
 *   POKETRADE_SAVE_DeleteOfferStatusIcons 0x021E1CA8 thumb ov119
 *   CLACT_DeleteActor 0x0204B3B4 arm
 *   CLACT_ReleasePalette 0x0204ADA4 arm
 *   CLACT_ReleaseCharacter 0x0204A8D4 arm
 *   CLACT_ReleaseCellAnim 0x0204AFD8 arm
 */
extern void POKETRADE_2D_DeleteCursorActor(void *);
typedef unsigned int   u32;
extern void POKETRADE_SAVE_DeleteOfferStatusIcons(char *p);
struct Obj;
extern void CLACT_DeleteActor(struct Obj *p);
extern void CLACT_ReleasePalette(u32 i);
extern void CLACT_ReleaseCharacter(u32 i);
extern void CLACT_ReleaseCellAnim(u32 i);
void POKETRADE_2D_DeleteOfferIcons(char *p)
{
    int i;
    POKETRADE_2D_DeleteCursorActor(p);
    POKETRADE_SAVE_DeleteOfferStatusIcons(p);
    for (i = 0; i < 10; i++) {
        if (*(int *)(p + i * 4 + 0xefc)) {
            CLACT_DeleteActor((struct Obj *)(*(int *)(p + i * 4 + 0xefc)));
            *(int *)(p + i * 4 + 0xefc) = 0;
        }
    }
    for (i = 0; i < 6; i++) {
        if (*(int *)(p + i * 4 + 0x87c)) {
            CLACT_ReleasePalette(*(int *)(p + i * 4 + 0x87c));
            *(int *)(p + i * 4 + 0x87c) = 0;
        }
    }
    for (; i < 12; i++) {
        if (*(int *)(p + i * 4 + 0x87c)) {
            CLACT_ReleaseCharacter(*(int *)(p + i * 4 + 0x87c));
            *(int *)(p + i * 4 + 0x87c) = 0;
        }
    }
    for (; i < 18; i++) {
        if (*(int *)(p + i * 4 + 0x87c)) {
            CLACT_ReleaseCellAnim(*(int *)(p + i * 4 + 0x87c));
            *(int *)(p + i * 4 + 0x87c) = 0;
        }
    }
}
