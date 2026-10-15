/*
 * function: BOX2_SEQ_SetSlotIconPal
 * address:  0x021EC428
 * packet:   pkt_021DC9A0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   CLACT_TransferCharacterPart  0x0204AA94  arm  arm9
 *   CLACT_GetActorCharacterIndex  0x0204B7F0  arm  arm9
 *   CLACT_SetActorPaletteOffset  0x0204B6F4  arm  arm9
 *
 * Stop the slot, re-key it and restart it.  Two facts pin this one:
 *   the second call's FIRST argument is the first call's RESULT (r0 is
 *   never overwritten), and the result must be a named local -- the
 *   nested spelling moves a and b to r6/r7 (r6=a) instead of the image's
 *   r7=a / r6=b, a 1-byte miss at +0x18.
 */

typedef unsigned short u16;
typedef unsigned int   u32;
typedef unsigned char  u8;
struct Obj;
extern u16 CLACT_GetActorCharacterIndex(u8 *p);
extern void CLACT_TransferCharacterPart(int a, void *b, u32 c, int d, int e);
extern void CLACT_SetActorPaletteOffset(struct Obj *o, u32 v, u32 flag);
extern u16 CLACT_GetActorCharacterIndex(u8 *p);
extern void CLACT_TransferCharacterPart(int a, void *b, u32 c, int d, int e);
extern void CLACT_SetActorPaletteOffset(struct Obj *o, u32 v, u32 flag);
void BOX2_SEQ_SetSlotIconPal(char *p, int a, int i, int b)
{
    int v = CLACT_GetActorCharacterIndex((u8 *)(*(int *)(p + 0x9E74 + i * 4)));
    CLACT_TransferCharacterPart(v, (void *)a, 0x200, 0, 0);
    CLACT_SetActorPaletteOffset((struct Obj *)(*(int *)(p + 0x9E74 + i * 4)), (unsigned char)b, 1);
}

