/*
 * file:     palanm.c
 * unit:     yes
 * function: func_020213C0, func_020213E0, func_020213F8, func_0202142C, func_02021438, func_02021444, func_02021464, func_02021518, func_02021540, func_02021548, func_0202155C, func_020215A0, func_020215BC, func_020215EC, func_02021640, func_02021660, func_020216B4, func_020216D4
 * address:  0x020213C0
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
 *   sub_0209E968_Map  0x0209E968  data
 *   sub_0209E904_Tbl  0x0209E904  data
 *   g_02146788  0x02146788  data
 *   OS_GetTick  0x020870D0  arm
 *   _ll_udiv    0x0209C00C  arm
 *   func_02030734      0x02030734  arm
 *   MI_CpuFill8        0x02082BCC  arm
 *   func_02021518_File 0x020A73BC  data
 *   func_020307B0  0x020307B0  arm
 *   func_0202155C_File 0x020A73BC  data
 *   MIi_CpuCopy16  0x02082A60  arm
 *   func_02049F34  0x02049F34  arm
 *   func_02049F78  0x02049F78  arm
 *   0  0x05000000  main BG
 *   1  0x05000400  sub BG
 *   2  0x05000200  main OBJ
 *   3  0x05000600  sub OBJ
 */
struct PalAnmSlot_020215EC;
typedef unsigned short u16;

typedef unsigned int u32;

typedef unsigned char  u8;

typedef unsigned long long u64;

struct PalAnmState {
    u32 unk_00;
    u64 unk_04;
    u64 unk_0c;
    u64 tick;
};

struct PalAnmSlot_02021464 {
    void *unk_00;
    void *unk_04;
    u32   size;
    u32   unk_0c;
    u32   unk_10;
};

struct PalAnmSlot_020215A0 {
    void *unk_00;
    void *unk_04;
    u32   size;
    u32   unk_0c;
    u32   unk_10;
};

struct PalAnmSlot_020215BC {
    u16 *unk_00;
    u16 *unk_04;
    u32  size;
    u32  unk_0c;
    u32  unk_10;
};

struct PalAnmSlot_020215EC {
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

extern u64 OS_GetTick(void);
extern u32 func_02012FBC(u8 *p, u32 x);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void MI_CpuFill8(void *dest, u32 data, u32 size);
extern u32 func_020307B0(void *p);
extern void MIi_CpuCopy16(const void *src, void *dest, u32 size);
extern void *func_02049F34(u32 a0, u32 a1, u32 a2, u32 a3);
extern void *func_02049F78(void *a0, u32 a1, u32 a2, u32 a3);
int func_020213C0(u32 a);
u32 func_020213E0(u16 v);
u16 func_020213F8(int a, int b);
unsigned short func_0202142C(int a0);
void func_02021438(void);
void func_02021444(void);
void func_02021464(u8 *p);
void *func_02021518(u32 heap);
u32 func_02021540(void *a0);
void func_02021548(struct PalAnmSlot_02021464 *slots, u32 idx, void *a, void *b, u32 size);
void func_0202155C(struct PalAnmSlot_02021464 *slots, u32 idx, u32 size, u32 heap);
void func_020215A0(struct PalAnmSlot_020215A0 *slots, u32 idx);
void func_020215BC(struct PalAnmSlot_020215BC *slots, const void *src, u32 idx, u32 off, u16 size);
void func_020215EC(struct PalAnmSlot_020215EC *slots, u32 arcId, u32 fileId, u32 tag, u32 idx, u32 count, u16 off, u16 srcOff);
void func_02021640(struct PalAnmSlot_020215EC *slots, u32 arcId, u32 fileId, u32 tag, u32 idx, u32 count, u16 off);
void func_02021660(struct PalAnmSlot_020215EC *slots, void *arc, u32 fileId, u32 tag, u32 idx, u32 count, u16 off, u16 srcOff);
void func_020216B4(struct PalAnmSlot_020215EC *slots, void *arc, u32 fileId, u32 tag, u32 idx, u32 count, u16 off);
void func_020216D4(struct PalAnmSlot_020215EC *slots, u32 bank, u32 off, u32 size);
extern u16 sub_0209E968_Map[];
extern u16 sub_0209E904_Tbl[][2];
extern struct PalAnmState g_02146788;
extern const char func_02021518_File[];
extern const char func_0202155C_File[];





int func_020213C0(u32 a)
{
    u32 i;

    for (i = 0; i < 0x40; i++)
        if (sub_0209E968_Map[i] == a)
            return 1;
    return 0;
}





/*
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020213E0.c  *       --func func_020213E0 --addr 0x020213E0 --cc 1.1p1 --thumb
 */
u32 func_020213E0(u16 v)
{
    if ((u16)(v + 0xFE14) > 8) {
        return 1;
    }
    return 0;
}





u16 func_020213F8(int a, int b)
{
    u32 i;

    for (i = 0; i < 0x19; i++)
        if (sub_0209E904_Tbl[i][b] == a)
            return sub_0209E904_Tbl[i][b ^ 1];
    return 0;
}





unsigned short func_0202142C(int a0)
{
    return func_020213F8(a0, 0);
}




/*
 * Clears the one word at 0x02146788.  Four bytes of code and its pool word.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02021438.c \
 *       --func func_02021438 --addr 0x02021438 --cc 1.1p1 --thumb
 */
void func_02021438(void)
{
    g_02146788.unk_00 = 0;
}



/*
 * Reset the palette-animation module state block and stamp it with the
 * current tick.  The same global's first word is the one func_02021438
 * clears, so the block is a struct starting at 0x02146788, not five
 * unrelated globals.
 *
 * The tick is a `u64` field at +0x14: OS_GetTick returns the pair in r0:r1
 * and both halves are stored with plain word stores at +0x14 and +0x18,
 * which is a 4-aligned `long long`
 * (docs/idioms/long-long-aligns-to-four.md), not two `u32`s assigned from a
 * split helper.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02021444.c \
 *       --func func_02021444 --addr 0x02021444 --cc 1.1p1 --thumb
 */
void func_02021444(void)
{
    g_02146788.unk_00 = 1;
    g_02146788.unk_04 = 0;
    g_02146788.unk_0c = 0;
    g_02146788.tick = OS_GetTick();
}






/*
 * Palette-animation tick pump.  g_02146788 is the same state block
 * func_02021444 resets; unk_04, unk_0c and tick are 4-aligned u64 fields
 * (docs/idioms/long-long-aligns-to-four.md).  The divisor 0x01FF6210 is the
 * OS tick-to-unit scale applied after a <<6, through _ll_udiv
 * (docs/idioms/runtime-helper-reloc.md).
 *
 * The last four bytes were the arm order: the equal case is written first
 * so the `bne` reaches the OS_GetTick arm
 * (docs/idioms/the-fall-through-arm-is-the-source-order.md).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02021464.c \
 *       --func func_02021464 --addr 0x02021464 --cc 1.1p1 --thumb
 */
void func_02021464(u8 *p)
{
    u64 t;
    u64 v;

    if (g_02146788.unk_00 == 0) {
        return;
    }
    t = OS_GetTick();
    if (t < g_02146788.unk_04) {
        t = t + g_02146788.unk_04;
    } else {
        g_02146788.unk_04 = t;
    }
    v = ((t - g_02146788.tick) << 6) / 0x01FF6210;
    if (g_02146788.unk_0c >= v) {
        return;
    }
    func_02012FBC(p, (u32)(v - g_02146788.unk_0c));
    if (g_02146788.unk_04 == t) {
        g_02146788.unk_0c = v;
    } else {
        t = OS_GetTick();
        g_02146788.tick = t;
        g_02146788.unk_0c = (t << 6) / 0x01FF6210;
        g_02146788.unk_04 = t;
    }
}






/*
 * Allocate and zero the 0x120-byte palette-animation context.  0x120 is out
 * of Thumb immediate range, so the compiler materialises the tag 88 first
 * and derives the size from it with `adds r4, #0xc8`, the
 * docs/idioms/consecutive-line-numbers-are-one-pool-word-and-adds.md shape
 * applied to two unrelated constants that happen to be close.
 *
 * The heap id is truncated to 16 bits before the call (`lsls #16 / lsrs
 * #16`), so the value reaching the allocator is narrower than the parameter
 * this function receives.  A plain `u16` parameter forwarded unchanged does
 * not produce the pair, since mwcc assumes an incoming narrow parameter is
 * already truncated; the equally byte-exact reading is a `u16` heap-id
 * slot on the allocator prototype itself, which every other call site in
 * src/matched/ spells `u32`.
 *
 * EXACT*: the extent runs to 48 bytes because the next function at
 * 0x02021548 saves no lr and carries no label.
 *
 * 0x020A73BC is this translation unit's allocation-site pointer, the
 * palanm.c anchor in layout/file_anchors.txt.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02021518.c \
 *       --func func_02021518 --addr 0x02021518 --cc 1.1p1 --thumb
 */
void *func_02021518(u32 heap)
{
    void *p = func_02030734((u16)heap, 0x120, 0, func_02021518_File, 88);
    MI_CpuFill8(p, 0, 0x120);
    return p;
}






/*
 * Unlabelled Thumb leaf: a bare tail call to func_020307B0 with no arguments
 * (`ldr r3,[pc,#0]; bx r3`; the pool word names 0x020307B0).  Disasm.py gave
 * it no func_ label because it has no prologue.
 */
u32 func_02021540(void *a0)
{
    return func_020307B0(a0);
}






/*
 * Fill one 0x14-byte slot of the palette-animation buffer array: the two
 * buffer pointers and their common size.  No relocations.
 *
 * The fifth argument arrives on the stack; with two registers pushed and no
 * frame it reads back at [sp, #8].
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02021548.c \
 *       --func func_02021548 --addr 0x02021548 --cc 1.1p1 --thumb
 */
void func_02021548(struct PalAnmSlot_02021464 *slots, u32 idx, void *a, void *b,
                   u32 size)
{
    slots[idx].unk_00 = a;
    slots[idx].unk_04 = b;
    slots[idx].size = size;
}






/*
 * Allocate the double buffer for one palette-animation slot: two blocks of
 * the same size out of the same heap, tags 142 and 143, then hand both plus
 * the size to the slot setter.
 *
 * The size is the allocator's second argument and the setter's fifth, and
 * it is never reloaded, which is what pins it as a parameter rather than a
 * field of the slot.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0202155C.c \
 *       --func func_0202155C --addr 0x0202155C --cc 1.1p1 --thumb
 */
void func_0202155C(struct PalAnmSlot_02021464 *slots, u32 idx, u32 size, u32 heap)
{
    void *a = func_02030734(heap, size, 0, func_0202155C_File, 142);
    void *b = func_02030734(heap, size, 0, func_0202155C_File, 143);
    func_02021548((struct PalAnmSlot_02021464 *)slots, idx, a, b, size);
}





/*
 * Release the double buffer of one palette-animation slot, the inverse of
 * func_0202155C.  The two slot pointers are read back from the array rather
 * than passed in, which is what makes the 0x14 stride multiply live.
 *
 * EXACT*: the extent runs long because the next function at 0x020215BC has
 * no label.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020215A0.c \
 *       --func func_020215A0 --addr 0x020215A0 --cc 1.1p1 --thumb
 */
void func_020215A0(struct PalAnmSlot_020215A0 *slots, u32 idx)
{
    func_020307B0(slots[idx].unk_00);
    func_020307B0(slots[idx].unk_04);
}





/*
 * Copy the same source halfwords into both buffers of one palette-animation
 * slot at the same halfword offset.  The offset is scaled once (`lsls r4,
 * r3, #1`) and reused for both destinations, which is the `u16 *` pointer
 * arithmetic rather than a byte offset the caller already doubled.
 *
 * The fifth argument is a `u16` on the stack, read with `ldrh` at [sp,#0x18]
 * behind six pushed registers, and widened into the copier's `u32` length.
 *
 * EXACT*: the next function at 0x020215EC follows immediately with no label gap in the walk.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020215BC.c \
 *       --func func_020215BC --addr 0x020215BC --cc 1.1p1 --thumb
 */
void func_020215BC(struct PalAnmSlot_020215BC *slots, const void *src, u32 idx,
                   u32 off, u16 size)
{
    MIi_CpuCopy16(src, slots[idx].unk_00 + off, size);
    MIi_CpuCopy16(src, slots[idx].unk_04 + off, size);
}




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
void func_020215EC(struct PalAnmSlot_020215EC *slots, u32 arcId, u32 fileId, u32 tag,
                   u32 idx, u32 count, u16 off, u16 srcOff)
{
    struct PltRes *res;
    void *block;

    block = func_02049F34(arcId, fileId, (u32)(&res), (u16)((tag & 0x7fff) | 0x8000));
    if (count == 0) {
        count = res->count;
    }
    func_020215BC((struct PalAnmSlot_020215BC *)slots, res->data + srcOff, idx, off, (u16)count);
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
void func_02021640(struct PalAnmSlot_020215EC *slots, u32 arcId, u32 fileId, u32 tag,
                   u32 idx, u32 count, u16 off)
{
    func_020215EC((struct PalAnmSlot_020215EC *)slots, arcId, fileId, tag, idx, count, off, 0);
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
void func_02021660(struct PalAnmSlot_020215EC *slots, void *arc, u32 fileId, u32 tag,
                   u32 idx, u32 count, u16 off, u16 srcOff)
{
    struct PltRes *res;
    void *block;

    block = func_02049F78(arc, fileId, (u32)(&res), (u16)((tag & 0x7fff) | 0x8000));
    if (count == 0) {
        count = res->count;
    }
    func_020215BC((struct PalAnmSlot_020215BC *)slots, res->data + srcOff, idx, off, (u16)count);
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
void func_020216B4(struct PalAnmSlot_020215EC *slots, void *arc, u32 fileId, u32 tag,
                   u32 idx, u32 count, u16 off)
{
    func_02021660((struct PalAnmSlot_020215EC *)slots, arc, fileId, tag, idx, count, off, 0);
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
void func_020216D4(struct PalAnmSlot_020215EC *slots, u32 bank, u32 off, u32 size)
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

    func_020215BC((struct PalAnmSlot_020215BC *)slots, base + off, bank, off, (u16)size);
}
