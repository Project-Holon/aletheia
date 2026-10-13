/*
 * function: BILLBOARD_AddImage
 * address:  0x0204EF58
 * packet:   pkt_0204EE0C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   BILLBOARD_FindFreeImage   0x0204EE0C  arm
 *   BILLBOARD_BindImageResource   0x0204EE64  arm
 *   BILLBOARD_SetImageFormat   0x0204EEC8  arm
 *
 * The first of the two "insert and publish" wrappers over the 0x28-byte slot
 * table: scan for a free slot with BILLBOARD_FindFreeImage, seat it with BILLBOARD_BindImageResource
 * and hand it to BILLBOARD_SetImageFormat.
 *
 * The scan index is an out-parameter on the caller's own frame (`add r1,
 * sp, #4`), which is where the 8-byte frame comes from, and the same word is
 * the return value whether or not the scan succeeded, so the local is
 * deliberately left uninitialised: BILLBOARD_FindFreeImage writes it on both paths.
 *
 * The two trailing parameters are `u8`: a byte-typed parameter that arrives on
 * the stack is read with `ldrb` where a 32-bit one would be `ldr`, and that is
 * the only thing that distinguishes this prototype from BILLBOARD_AddImageFromArchive's
 * (a word, a byte, a byte).
 *
 * `&desc->slots[idx]` is spelled as an index, not as byte arithmetic: the
 * element stride has to be a declared sizeof, because that is what emits the
 * `mov r6, #0x28` / `mla` pair the image has (an `idx * 0x28` on a byte
 * pointer comes out as `mul` plus `add`).
 *
 * The slot base is re-read for the second call, because the first one may
 * have changed it.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Slot {
    u8  pad_00[4];
    u32 unk_04;
    u32 unk_08;
    u32 unk_0c;
    u32 unk_10;
    u32 unk_14;
    u8  pad_18[8];
    u32 unk_20;
    u32 unk_24;
};

struct Desc {
    u8           pad_00[4];
    struct Slot *slots;
    u32          unk_08;
    int          count;
};

struct Struct_0204EE0C;
struct Struct_0204EE64;
extern int BILLBOARD_FindFreeImage(struct Struct_0204EE0C *p, int *out_index);
extern void BILLBOARD_BindImageResource(struct Struct_0204EE64 *p, u32 heapId);
typedef signed int     s32;
struct Cell;
extern void BILLBOARD_SetImageFormat(struct Cell *dst, u32 idx, s32 fmt, u32 b, u8 c);

u32 BILLBOARD_AddImage(struct Desc *desc, u32 a1, u32 a2, u32 a3, u8 a4, u8 a5)
{
    u32 idx;

    if (BILLBOARD_FindFreeImage((struct Struct_0204EE0C *)desc, (int *)(&idx)) == 1) {
        BILLBOARD_BindImageResource((struct Struct_0204EE64 *)(&desc->slots[idx]), a1);
        BILLBOARD_SetImageFormat((struct Cell *)(&desc->slots[idx]), a2, a3, a4, a5);
    }
    return idx;
}
