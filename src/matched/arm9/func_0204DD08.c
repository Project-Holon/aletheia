/*
 * function: CLACT_TransferPaletteData
 * address:  0x0204DD08
 * packet:   pkt_0204DD08
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Reconfigure one 0x18-byte entry of the holder's table: trim the surface
 * (the +0x08 byte count / +0x0c data word pair, a palette-shaped record) by
 * `head` 32-byte blocks from the front and to `tail` blocks, clamp it to the
 * layer limit, re-upload for one or both engines, then store the surviving
 * byte count into the entry's bits 0..30.  Sole caller: CLACT_RegisterPaletteEx.
 *
 * The C body is docs/notes/CLACT_TransferPaletteData.c.txt's (476 against 480 there),
 * closed in wave 10 by two levers:
 *  - THE MATERIALISED `lsl r0, r3, #5`.  The head block's offset is a named
 *    64-BIT local, `unsigned long long ofs = head * 32;`, used by the add and
 *    the sub, while the compare keeps the plain `head * 32` (which is why the
 *    image re-folds `cmp r1, r3, lsl #5` beside the live r0).  A 32-bit local
 *    of any type (u32, int, long, pointer, enum) is copy-propagated and folded
 *    into both consumers (476 bytes); a u16/s16 local materialises the value
 *    but narrows it (`lsl #21` + `lsr #16` shifter operands, 5 out).  Only
 *    the u64 local keeps the plain shift as a register temporary: its low
 *    word is what the u32 add and sub consume.  tools/permuter.py found the
 *    materialising temp (`temp(tmp1=head * 32)`, as u16); the width was a
 *    hand sweep.
 *  - THE TAIL MASK ORDER.  The entry's bit-31 half is read into its own
 *    local before the OR (`u32 hi = ent->unk_14 & 0x80000000;`), which is what
 *    loads +0x14 before surf->unk_08 (permuter `temp(tmp2=...)`).
 *
 * symbols:
 *   CLACT_IsVramTypeCompatible  0x0204D9B4  arm
 *   GX_SetBankForOBJExtPltt  0x020801F8  arm
 *   GX_SetBankForSubOBJExtPltt  0x0208083C  arm
 *   GX_GetBankForOBJExtPltt  0x02080C34  arm
 *   GX_GetBankForSubOBJExtPltt  0x02080C74  arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Ent    { u8 pad_00[0x14]; u32 unk_14; };          /* 0x18 */
struct Surf   { u8 pad_00[8]; u32 unk_08; u32 unk_0c; };
struct Holder { u8 pad_00[0xc]; struct Ent *ents; };

typedef signed int     s32;
struct NitroFileHeader;
extern s32 func_02062AD4(struct NitroFileHeader *file, void **out);
extern s32 func_02062A98(struct NitroFileHeader *file, void **out);
extern void func_020637D4(u32 *p);
extern u32 CLACT_IsVramTypeCompatible(u32 a, u32 b);
extern void func_02063E54(struct Surf *s, u32 size, int mode,
                         struct Ent *ent);
extern u16 GX_GetBankForOBJExtPltt(void);
extern u16 GX_GetBankForSubOBJExtPltt(void);
extern void func_0208068C(void);
extern void GX_SetBankForOBJExtPltt(int objExtPltt);
extern void GX_SetBankForSubOBJExtPltt(int sub_objExtPltt);

void CLACT_TransferPaletteData(struct Holder *h, int idx, void *src, void *sel,
                  u32 size, u16 head, u16 tail)
{
    struct Surf *surf;
    void *tmp;
    u32 off;
    u8 *ents;
    int max;
    int limit;
    int flag;
    u32 saved;

    off  = idx * sizeof(struct Ent);
    ents = (u8 *)h->ents;
    if (size >= 0x200) {
        size  = (u16)(size - 0x200);
        flag  = 1;
        max   = 0x100;
        limit = 0x2000;
    } else {
        flag  = 0;
        max   = 0x10;
        limit = 0x200;
    }

    func_02062AD4(src, &tmp);
    if (!func_02062A98(src, (void **)(&surf))) {
        return;
    }
    func_020637D4((u32 *)(ents + off));

    if (head != 0) {
        unsigned long long ofs = head * 32;
        if (surf->unk_08 > head * 32) {
            surf->unk_0c += ofs;
            surf->unk_08 -= ofs;
        }
    }
    if (tail != 0) {
        if (head + tail <= max) {
            if (surf->unk_08 > tail * 32) {
                surf->unk_08 = tail * 32;
            }
        }
    }
    if (size != 0) {
        if (surf->unk_08 + size > limit) {
            surf->unk_08 = limit - size;
        }
    }

    if (CLACT_IsVramTypeCompatible((u32)sel, 0)) {
        saved = GX_GetBankForOBJExtPltt();
        if (flag) func_0208068C();
        func_02063E54(surf, size, 1, (struct Ent *)(ents + off));
        if (flag) GX_SetBankForOBJExtPltt(saved);
    }
    if (CLACT_IsVramTypeCompatible((u32)sel, 1)) {
        saved = GX_GetBankForSubOBJExtPltt();
        if (flag) func_0208068C();
        func_02063E54(surf, size, 2, (struct Ent *)(ents + off));
        if (flag) GX_SetBankForSubOBJExtPltt(saved);
    }

    ((struct Ent *)((u8 *)h->ents + off))->unk_14 &= ~0x80000000;
    {
        u32 hi = ((struct Ent *)((u8 *)h->ents + off))->unk_14 & 0x80000000;
        ((struct Ent *)((u8 *)h->ents + off))->unk_14 = hi | (surf->unk_08 & ~0x80000000);
    }
}
