/*
 * file:     palanm_p03.c
 * unit:     yes
 * function: func_020215EC, func_02021640, func_02021660, func_020216B4, func_020216D4
 * address:  0x020215EC
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02049F34  0x02049F34  arm
 *   func_020215BC  0x020215BC  thumb
 *   func_020307B0  0x020307B0  arm
 *   func_020215EC  0x020215EC  thumb
 *   func_02049F78  0x02049F78  arm
 *   func_02021660  0x02021660  thumb
 *   0  0x05000000  main BG
 *   1  0x05000400  sub BG
 *   2  0x05000200  main OBJ
 *   3  0x05000600  sub OBJ
 */
struct PalAnmSlot;
typedef unsigned short u16;

typedef unsigned int   u32;

struct PalAnmSlot {
    u16 *unk_00;
    u16 *unk_04;
    u32  size;
    u32  unk_0c;
    u32  unk_10;
};

struct PltRes {
    u32  unk_00;
    u32  unk_04;
    u32  count;
    u16 *data;
};

extern void *func_02049F34(u32 a0, u32 a1, u32 a2, u32 a3);
extern void func_020215BC(struct PalAnmSlot *slots, const void *src, u32 idx,
                          u32 off, u16 size);
extern u32 func_020307B0(void *p);
extern void func_020215EC(struct PalAnmSlot *slots, u32 arcId, u32 fileId,
                          u32 tag, u32 idx, u32 count, u16 off, u16 srcOff);
extern void *func_02049F78(void *a0, u32 a1, u32 a2, u32 a3);
extern void func_02021660(struct PalAnmSlot *slots, void *arc, u32 fileId,
                          u32 tag, u32 idx, u32 count, u16 off, u16 srcOff);


/*
 * Load a palette resource, copy a run of it into both buffers of one
 * palette-animation slot, then release the loaded block.  func_02021660 is
 * the same function against the sibling loader at 0x02049F78.
 *
 * The loader's fourth argument is `(u16)((arg & 0x7fff) | 0x8000)`: the
 * constant is materialised once as 0x7fff for the mask and re-derived as
 * 0x8000 with `adds r3, r4, #1` for the flag, so the two constants are one
 * pool word.
 *
 * The count argument doubles as "use the resource's own count": zero falls
 * through to the loaded header's +0x08, and only the merged value is
 * truncated to 16 bits, which is what puts the `lsls/lsrs` pair after the
 * join rather than in each arm.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020215EC.c \
 *       --func func_020215EC --addr 0x020215EC --cc 1.1p1 --thumb
 */
void func_020215EC(struct PalAnmSlot *slots, u32 arcId, u32 fileId, u32 tag,
                   u32 idx, u32 count, u16 off, u16 srcOff)
{
    struct PltRes *res;
    void *block;

    block = func_02049F34(arcId, fileId, (u32)(&res), (u16)((tag & 0x7fff) | 0x8000));
    if (count == 0) {
        count = res->count;
    }
    func_020215BC(slots, res->data + srcOff, idx, off, (u16)count);
    func_020307B0(block);
}


/*
 * Forward to func_020215EC with a source offset of zero, i.e. copy from the
 * start of the loaded palette.  The four register arguments are never
 * touched, only the three stack arguments are re-pushed and the eighth is
 * appended; the seventh is re-read with `ldrh`, which is what pins it as a
 * `u16` in both prototypes.
 *
 * EXACT*: the extent runs long because the next function has no label.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02021640.c \
 *       --func func_02021640 --addr 0x02021640 --cc 1.1p1 --thumb
 */
void func_02021640(struct PalAnmSlot *slots, u32 arcId, u32 fileId, u32 tag,
                   u32 idx, u32 count, u16 off)
{
    func_020215EC(slots, arcId, fileId, tag, idx, count, off, 0);
}


/*
 * Load a palette resource, copy a run of it into both buffers of one
 * palette-animation slot, then release the loaded block.  func_020215EC is
 * the same function against the sibling loader at 0x02049F34.
 *
 * The loader's fourth argument is `(u16)((arg & 0x7fff) | 0x8000)`: the
 * constant is materialised once as 0x7fff for the mask and re-derived as
 * 0x8000 with `adds r3, r4, #1` for the flag, so the two constants are one
 * pool word.
 *
 * The count argument doubles as "use the resource's own count": zero falls
 * through to the loaded header's +0x08, and only the merged value is
 * truncated to 16 bits, which is what puts the `lsls/lsrs` pair after the
 * join rather than in each arm.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02021660.c \
 *       --func func_02021660 --addr 0x02021660 --cc 1.1p1 --thumb
 */
void func_02021660(struct PalAnmSlot *slots, void *arc, u32 fileId, u32 tag,
                   u32 idx, u32 count, u16 off, u16 srcOff)
{
    struct PltRes *res;
    void *block;

    block = func_02049F78(arc, fileId, (u32)(&res), (u16)((tag & 0x7fff) | 0x8000));
    if (count == 0) {
        count = res->count;
    }
    func_020215BC(slots, res->data + srcOff, idx, off, (u16)count);
    func_020307B0(block);
}


/*
 * Forward to func_02021660 with a source offset of zero, i.e. copy from the
 * start of the loaded palette.  The four register arguments are never
 * touched, only the three stack arguments are re-pushed and the eighth is
 * appended; the seventh is re-read with `ldrh`, which is what pins it as a
 * `u16` in both prototypes.
 *
 * EXACT*: the extent runs long because the next function has no label.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020216B4.c \
 *       --func func_020216B4 --addr 0x020216B4 --cc 1.1p1 --thumb
 */
void func_020216B4(struct PalAnmSlot *slots, void *arc, u32 fileId, u32 tag,
                   u32 idx, u32 count, u16 off)
{
    func_02021660(slots, arc, fileId, tag, idx, count, off, 0);
}


/*
 * Snapshot one palette bank into the animation slot that shadows it.  The
 * bank selector indexes both the hardware palette base and the slot array,
 * so 0..3 are the four DS palette RAM windows in the order
 * main BG / sub BG / main OBJ / sub OBJ:
 *
 *   0  0x05000000  main BG
 *   1  0x05000400  sub BG
 *   2  0x05000200  main OBJ
 *   3  0x05000600  sub OBJ
 *
 * Only 0x05000000 is built with `movs #5 / lsls #24`; the other three need a
 * pool word each, which is why the dense halfword table has one arm that is
 * two instructions and three that are one.
 *
 * The offset is added as `u16 *` arithmetic to the bank base and passed
 * again, unscaled, as the callee's own halfword offset.
 *
 * EXACT*: the extent runs to 106 bytes because the switch pools and the next function at 0x0202173E are pulled in.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020216D4.c \
 *       --func func_020216D4 --addr 0x020216D4 --cc 1.1p1 --thumb
 */
void func_020216D4(struct PalAnmSlot *slots, u32 bank, u32 off, u32 size)
{
    u16 *base;

    switch (bank) {
    case 0:
        base = (u16 *)0x05000000;
        break;
    case 1:
        base = (u16 *)0x05000400;
        break;
    case 2:
        base = (u16 *)0x05000200;
        break;
    case 3:
        base = (u16 *)0x05000600;
        break;
    default:
        return;
    }

    func_020215BC(slots, base + off, bank, off, (u16)size);
}
