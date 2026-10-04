/*
 * unit:     no
 * function: func_02021660
 * address:  0x02021660
 * packet:   pkt_02021444
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02049F78  0x02049F78  arm
 *   func_020215BC  0x020215BC  thumb
 *   func_020307B0  0x020307B0  arm
 *
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

extern void *func_02049F78(void *a0, u32 a1, u32 a2, u32 a3);
extern void func_020215BC(struct PalAnmSlot *slots, const void *src, u32 idx,
                          u32 off, u16 size);
extern void func_020307B0(void *p);

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
