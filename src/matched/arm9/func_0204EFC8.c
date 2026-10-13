/*
 * function: BILLBOARD_AddImageFromArchive
 * address:  0x0204EFC8
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
 *   G3D_SYSTEM_CreateResourceArc   0x02046DB8  arm
 *
 * The second wrapper, one call longer than BILLBOARD_AddImage: the handle it seats
 * the slot with is G3D_SYSTEM_CreateResourceArc(a1, a2) rather than a1 directly, and the
 * trailing parameters are one word and two bytes rather than two bytes
 * (`ldr` at sp+0x20, `ldrb` at sp+0x24 and sp+0x28).
 *
 * The frame and the scan out-parameter are the same as BILLBOARD_AddImage's, and
 * the slot base is again re-read for each call.
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
extern void *G3D_SYSTEM_CreateResourceArc(u32 a0, u32 a1);

u32 BILLBOARD_AddImageFromArchive(struct Desc *desc, u32 a1, u32 a2, u32 a3, u32 a4, u8 a5, u8 a6)
{
    u32 idx;

    if (BILLBOARD_FindFreeImage((struct Struct_0204EE0C *)desc, (int *)(&idx)) == 1) {
        BILLBOARD_BindImageResource((struct Struct_0204EE64 *)(&desc->slots[idx]), (u32)G3D_SYSTEM_CreateResourceArc(a1, a2));
        BILLBOARD_SetImageFormat((struct Cell *)(&desc->slots[idx]), a3, a4, a5, a6);
    }
    return idx;
}
