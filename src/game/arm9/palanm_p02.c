/*
 * file:     palanm_p02.c
 * unit:     yes
 * function: func_02021464, func_02021518, func_02021540, func_02021548, func_0202155C, func_020215A0, func_020215BC
 * address:  0x02021464
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
 *   g_02146788  0x02146788  data
 *   OS_GetTick  0x020870D0  arm
 *   _ll_udiv    0x0209C00C  arm
 *   func_02030734      0x02030734  arm
 *   MI_CpuFill8        0x02082BCC  arm
 *   func_02021518_File 0x020A73BC  data
 *   func_020307B0  0x020307B0  arm
 *   func_0202155C_File 0x020A73BC  data
 *   MIi_CpuCopy16  0x02082A60  arm
 */
typedef unsigned char      u8;

typedef unsigned int       u32;

typedef unsigned long long u64;

struct PalAnmState {
    u32 unk_00;
    u64 unk_04;
    u64 unk_0c;
    u64 tick;
};

typedef unsigned short u16;

struct PalAnmSlot {
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

extern u64 OS_GetTick(void);
extern u32 func_02012FBC(u8 *p, u32 x);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void MI_CpuFill8(void *dest, u32 data, u32 size);
extern u32 func_020307B0(void *p);
extern void MIi_CpuCopy16(const void *src, void *dest, u32 size);
void func_02021464(u8 *p);
void *func_02021518(u32 heap);
u32 func_02021540(void *a0);
void func_02021548(struct PalAnmSlot *slots, u32 idx, void *a, void *b, u32 size);
void func_0202155C(struct PalAnmSlot *slots, u32 idx, u32 size, u32 heap);
void func_020215A0(struct PalAnmSlot_020215A0 *slots, u32 idx);
void func_020215BC(struct PalAnmSlot_020215BC *slots, const void *src, u32 idx, u32 off, u16 size);
extern struct PalAnmState g_02146788;
extern const char func_02021518_File[];
extern const char func_0202155C_File[];




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
void func_02021548(struct PalAnmSlot *slots, u32 idx, void *a, void *b,
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
void func_0202155C(struct PalAnmSlot *slots, u32 idx, u32 size, u32 heap)
{
    void *a = func_02030734(heap, size, 0, func_0202155C_File, 142);
    void *b = func_02030734(heap, size, 0, func_0202155C_File, 143);
    func_02021548(slots, idx, a, b, size);
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
