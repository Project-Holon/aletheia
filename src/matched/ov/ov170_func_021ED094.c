/*
 * function: BOX2_SEQ_SetSlotCharacter
 * address:  0x021ED094
 * packet:   pkt_ov170_021ED094
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FILE_UTIL_GetItemCount 0x02020F08 thumb
 *   FILE_UTIL_Get 0x02020E60 thumb
 *   ARC_UTIL_LoadScreenDataFromArchive 0x02049E34 arm
 *   CLACT_GetActorCharacterIndex 0x0204B7F0 arm
 *   CLACT_TransferCharacter 0x0204A9D0 arm
 *   func_020307B0 0x020307B0 arm
 *   ARC_UTIL_LoadPaletteBlockFromArchive 0x02049F34 arm
 *   CLACT_GetActorPaletteIndex 0x0204B7F8 arm
 *   CLACT_TransferPalette 0x0204ADEC arm
 */
#include "../include/Obj14276.h"


extern unsigned FILE_UTIL_GetItemCount(void);
extern unsigned FILE_UTIL_Get(unsigned item, unsigned which);
typedef unsigned short u16;
typedef unsigned int   u32;
typedef unsigned char  u8;
struct Sub0204A9D0;
extern void *ARC_UTIL_LoadScreenDataFromArchive(u32 a0, u32 a1, u32 a2, u32 a3, u16 a4);
extern u16 CLACT_GetActorCharacterIndex(u8 *p);
extern void CLACT_TransferCharacter(int a, struct Sub0204A9D0 *b);
extern u32 func_020307B0(void *p);
extern void *ARC_UTIL_LoadPaletteBlockFromArchive(u32 a0, u32 a1, u32 a2, u32 a3);
extern u16 CLACT_GetActorPaletteIndex(u8 *p);
extern void CLACT_TransferPalette(void *dst, void *src, unsigned flag);

void BOX2_SEQ_SetSlotCharacter(char *w, unsigned item)
{
    void *a;
    void *b;
    void *q;
    q = ARC_UTIL_LoadScreenDataFromArchive(FILE_UTIL_GetItemCount(), FILE_UTIL_Get(item, 1), 0, (u32)(&a), 0x4C);
    CLACT_TransferCharacter(CLACT_GetActorCharacterIndex(((struct Obj14276 *)w)->f9E9C), a);
    func_020307B0(q);
    q = ARC_UTIL_LoadPaletteBlockFromArchive(FILE_UTIL_GetItemCount(), FILE_UTIL_Get(item, 2), (u32)(&b), 0x4C);
    CLACT_TransferPalette((void *)CLACT_GetActorPaletteIndex(((struct Obj14276 *)w)->f9E9C), b, 1);
    func_020307B0(q);
}
