/*
 * file:     unit_0204F2FC.c
 * unit:     yes
 * function: BILLBOARD_SetImageTexAddr, func_0204F32C, BILLBOARD_CalcImageFrameRange, BILLBOARD_AddElem, BILLBOARD_FreeElem, func_0204F5E4, func_0204F604, func_0204F638, func_0204F654, func_0204F66C, func_0204F684, func_0204F6B4, BILLBOARD_GetElemVisible
 * address:  0x0204F2FC
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   _s32_div_f  0x0209C0A4  arm
 */
#include "billboard_types.h"

void BILLBOARD_SetImageTexAddr(struct BbBoard *board, int imageIndex, u32 texKey);
void func_0204F32C(struct BbBoard *board, int imageIndex, u32 *outPlttKey);
void BILLBOARD_CalcImageFrameRange(struct BbBoard *board, u32 imageIndex, int frame, int *outOffset, int *outFrameSize, u8 useFrameIndex);
void BILLBOARD_FreeElem(struct BbBoard *board, u32 elemIndex);
void func_0204F5E4(struct BbBoard *board, u32 elemIndex, u16 *outImageIndex);
void func_0204F604(struct BbBoard *board, u32 elemIndex, u16 *imageIndex);
void func_0204F654(struct BbBoard *board, int elemIndex, u16 *outCell);
void func_0204F66C(struct BbBoard *board, int elemIndex, u16 *cell);
void func_0204F6B4(struct BbBoard *board, int elemIndex, u8 *alpha);
void func_0204F6DC(struct BbBoard *board, int elemIndex, u8 *polyId);
u32 BILLBOARD_GetElemVisible(struct BbBoard *board, int elemIndex);

void BILLBOARD_SetImageTexAddr(struct BbBoard *board, int imageIndex, u32 texKey)
{
    u32 off = imageIndex * sizeof(struct BbImage);
    ((struct BbImage *)((u8 *)board->images + off))->texKey = texKey;
    ((struct BbImage *)((u8 *)board->images + off))->vramAddr = (((struct BbImage *)((u8 *)board->images + off))->texKey << 16) >> 13;
}

void func_0204F32C(struct BbBoard *board, int imageIndex, u32 *outPlttKey)
{
    *outPlttKey = ((struct BbImage *)(imageIndex * sizeof(struct BbImage) + (int)board->images))->plttKey;
}


void BILLBOARD_CalcImageFrameRange(struct BbBoard *board, u32 imageIndex, int frame, int *outOffset, int *outFrameSize, u8 useFrameIndex)
{
    struct BbImage *image = (struct BbImage *)((u8 *)board->images + imageIndex * sizeof(struct BbImage));
    int frameRow;

    switch (image->texFmt) {
    case 3:
        *outFrameSize = image->cellHeight * ((image->cellWidth << 5) / 8) / 8;
        break;
    case 1:
    case 4:
    case 6:
        *outFrameSize = image->cellHeight * ((image->cellWidth << 6) / 8) / 8;
        break;
    case 2:
        *outFrameSize = image->cellHeight * ((image->cellWidth << 4) / 8) / 8;
        break;
    }
    if (useFrameIndex == 0) {
        *outOffset = frame * *outFrameSize;
        return;
    }
    frameRow = frame / image->texWidth;
    *outOffset = *outFrameSize * frameRow + image->cellWidth * (frame % image->texWidth);
}


/*
 * billboard.c: allocate a free 0x1c-byte element (image index field 0x3FFF
 * = free) and initialise it. Every earlier residue came from spelling the
 * two packed halfwords as hand masks; the source is plain bitfield
 * assignment (14/2 at +0x00, 5/4/1/1/1/4 at +0x18), in the image's store
 * order.
 */
s32 BILLBOARD_AddElem(struct BbBoard *board, u32 imageIndex, u16 scaleX, u16 scaleY, VecFx32 *pos, u8 alpha, u32 light, u32 facingMode)
{
    s32 i;

    for (i = 0; i < board->elemCount; i++) {
        if (board->elems[i].imageIndex == BB_ELEM_FREE) {
            board->elems[i].imageIndex = (u16)imageIndex;
            board->elems[i].facingMode = (u16)facingMode;
            board->elems[i].scaleX = scaleX;
            board->elems[i].scaleY = scaleY;
            board->elems[i].rotZ = 0;
            board->elems[i].pos = *pos;
            board->elems[i].alpha = alpha;
            board->elems[i].polyId = 0;
            board->elems[i].visible = 0;
            board->elems[i].light = (u16)light;
            board->elems[i].flipS = 0;
            board->elems[i].flipT = 0;
            board->elems[i].cell = 0;
            return i;
        }
    }
    return 0;
}


/*
 * If the low 14 bits of the u16 at the element are not already all ones,
 * set them and leave the top two bits alone. The 14-bit width only survives
 * to a plain lsl/lsr pair as a bitfield
 * (docs/idioms/shift-pair-with-no-matching-type-is-a-bitfield.md).
 */
void BILLBOARD_FreeElem(struct BbBoard *board, u32 elemIndex)
{
    struct BbElem *elem = (struct BbElem *)((u8 *)board->elems + elemIndex * sizeof(struct BbElem));

    if (elem->imageIndex != BB_ELEM_FREE) {
        elem->imageIndex = BB_ELEM_FREE;
    }
}


/*
 * Fourteen-bit field getter on the 0x1c-byte elements: the shift pair is an
 * equal `lsl #0x12` / `lsr #0x12`, and the stride is spelled as byte
 * arithmetic so it comes out as `mul` rather than `mla`.
 */
void func_0204F5E4(struct BbBoard *board, u32 elemIndex, u16 *outImageIndex)
{
    *outImageIndex = ((struct BbElem *)((u8 *)board->elems + elemIndex * sizeof(struct BbElem)))->imageIndex;
}


/*
 * Same element and field as BILLBOARD_FreeElem, but the low 14 bits are copied in
 * from the caller's u16. The compiler reuses the inverted mask it already
 * needed as `lsr #18` rather than materialising 0x3fff twice.
 */
void func_0204F604(struct BbBoard *board, u32 elemIndex, u16 *imageIndex)
{
    u16 *packed = (u16 *)((u8 *)board->elems + elemIndex * sizeof(struct BbElem));

    *packed = (u16)((*packed & ~0x3fff) | (*imageIndex & 0x3fff));
}


/*
 * Twelve-byte aggregate copy out of the caller's vector into the position
 * of one element: one `ldm`/`stm` of three registers.
 */
void func_0204F638(struct BbBoard *board, int elemIndex, VecFx32 *pos)
{
    struct BbElem *elem = &board->elems[elemIndex];

    elem->pos = *pos;
}


void func_0204F654(struct BbBoard *board, int elemIndex, u16 *outCell)
{
    *outCell = board->elems[elemIndex].cell;
}


void func_0204F66C(struct BbBoard *board, int elemIndex, u16 *cell)
{
    ((struct BbElem *)(elemIndex * sizeof(struct BbElem) + (int)board->elems))->cell = *cell;
}


void func_0204F684(struct BbBoard *board, int elemIndex, const s16 *scaleX, const s16 *scaleY)
{
    board->elems[elemIndex].scaleX = *scaleX;
    board->elems[elemIndex].scaleY = *scaleY;
}


/*
 * The three accessors that follow func_0204F684, 0x0204F6B4..0x0204F720, on
 * the bitfields of the packed halfword at +0x18 of one element: five bits
 * at bit 0 (alpha), four bits at bit 5 (polygon id offset), and the single
 * bit at bit 9 (visible).
 *
 * All three are unlabelled in the generated listing, because none of them
 * saves a register in a prologue and `disasm.py` only auto-labels a function
 * whose prologue saves `lr`
 * (docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md).
 *
 * Each one is a read-modify-write of the whole halfword, which is what a
 * bitfield assignment costs.
 */
void func_0204F6B4(struct BbBoard *board, int elemIndex, u8 *alpha)
{
    struct BbElem *elem = &board->elems[elemIndex];

    elem->alpha = *alpha;
}


void func_0204F6DC(struct BbBoard *board, int elemIndex, u8 *polyId)
{
    struct BbElem *elem = &board->elems[elemIndex];

    elem->polyId = *polyId;
}


u32 BILLBOARD_GetElemVisible(struct BbBoard *board, int elemIndex)
{
    struct BbElem *elem = &board->elems[elemIndex];

    return elem->visible;
}
