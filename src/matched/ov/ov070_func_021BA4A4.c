/*
 * function: ITEMMENU_UploadSlotGraphics
 * address:  0x021BA4A4
 * packet:   pkt_ov070_021BA4A4
 * region:   ov070
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   CLACT_GetCharacterVramAddress  0x0204ABBC  arm
 *   BMP_GetPixels  0x020437D4  arm
 *   BMP_GetByteSize  0x020437EC  arm
 *   func_020862F0  0x020862F0  arm
 *   func_0207E780  0x0207E780  arm
 *   ITEMMENU_IsBrowseMode  0x021B811C  thumb  ov070
 *   CLACT_SetActorAnimSeq  0x0204B878  arm
 *   CLACT_SetActorDrawEnable  0x0204B3DC  arm
 */
#include "../include/Obj09880.h"

typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;

extern int CLACT_GetCharacterVramAddress(u32 idx, u32 flag);
struct Bmp;
extern void *BMP_GetPixels(const struct Bmp *bmp);
extern u32 BMP_GetByteSize(const struct Bmp *bmp);
extern void func_020862F0(void *, u32);
extern void func_0207E780(void *, void *, u32);
extern int ITEMMENU_IsBrowseMode(u8 *p);
struct Obj;
extern void CLACT_SetActorAnimSeq(struct Obj *p, u16 value);
struct Obj;
extern void CLACT_SetActorDrawEnable(struct Obj *p, unsigned int v);

void ITEMMENU_UploadSlotGraphics(char *p)
{
    int i;
    u8 *src;
    u8 *dst;

    for (i = 0; i < 8; i++) {
        src = (u8 *)CLACT_GetCharacterVramAddress(*(u32 *)(p + i * 4 + 0x5F4), 0);
        dst = BMP_GetPixels(*(void **)(p + i * 4 + 0x614));
        func_020862F0(dst, BMP_GetByteSize(*(void **)(p + i * 4 + 0x614)));
        func_0207E780(dst + 0x100, src + 0x80, 0x80);
        func_0207E780(dst + 0x280, src + 0x100, 0x80);
        func_0207E780(dst, src + 0x300, 0x100);
        func_0207E780(dst + 0x180, src + 0x400, 0x100);
        if (*(u32 *)(p + i * 4 + 0x654) != 0) {
            if (((struct Obj09880 *)p)->f80C == 4) {
                if (ITEMMENU_IsBrowseMode((u8 *)p) == 1 && *(u32 *)(p + i * 4 + 0x654) != 3) {
                    CLACT_SetActorAnimSeq((struct Obj *)(*(int *)(p + i * 4 + 0x674)), *(u32 *)(p + i * 4 + 0x654) - 1);
                    CLACT_SetActorDrawEnable((struct Obj *)*(int *)(p + i * 4 + 0x674), 1);
                } else {
                    CLACT_SetActorDrawEnable((struct Obj *)*(int *)(p + i * 4 + 0x674), 0);
                }
            } else if (((struct Obj09880 *)p)->f80C == 0 && *(u32 *)(p + i * 4 + 0x654) >= 4) {
                CLACT_SetActorAnimSeq((struct Obj *)(*(int *)(p + i * 4 + 0x674)), *(u32 *)(p + i * 4 + 0x654) - 1);
                CLACT_SetActorDrawEnable((struct Obj *)*(int *)(p + i * 4 + 0x674), 1);
            } else if (((struct Obj09880 *)p)->f80C == 2 && *(u32 *)(p + i * 4 + 0x654) >= 7) {
                CLACT_SetActorAnimSeq((struct Obj *)(*(int *)(p + i * 4 + 0x674)), *(u32 *)(p + i * 4 + 0x654) - 1);
                CLACT_SetActorDrawEnable((struct Obj *)*(int *)(p + i * 4 + 0x674), 1);
            } else {
                CLACT_SetActorDrawEnable((struct Obj *)*(int *)(p + i * 4 + 0x674), 0);
            }
            CLACT_SetActorDrawEnable((struct Obj *)*(int *)(p + i * 4 + 0x634), 1);
        } else {
            CLACT_SetActorDrawEnable((struct Obj *)*(int *)(p + i * 4 + 0x674), 0);
            CLACT_SetActorDrawEnable((struct Obj *)*(int *)(p + i * 4 + 0x634), 0);
        }
    }
}
