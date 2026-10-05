/*
 * function: func_0220D494
 * address: 0x0220D494
 * packet: pkt_ov198_0220D494
 * region: ov198
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * symbols:
 *   func_02045EC0 0x02045EC0 arm
 *   func_02045770 0x02045770 arm
 *   func_0201C724 0x0201C724 thumb
 *   func_02045808 0x02045808 arm
 *   func_020457B0 0x020457B0 arm
 *   func_0201EFA4 0x0201EFA4 thumb
 *   func_0201F250 0x0201F250 thumb
 *   func_0201D304 0x0201D304 thumb
 *   func_02045738 0x02045738 arm
 *
 * Near miss: the body is byte-for-byte right in shape; the residue is pure
 * register allocation / frame packing. The original keeps `handle` in r7
 * (used only for the 45738 call, then r7 is recycled by the shifted coordinate)
 * with `base` in [sp+0x1c] and `off` in r6, and packs the frame as
 * push {r3,r4,r5,r6,r7,lr} / sub sp,#0x40.  Naming base/off or inlining the
 * array, splitting f/y per block, and hoisting handle all leave the allocator
 * choosing a different split (5-reg push + #0x44) and one extra instruction.
 * Needs a different spelling of the three draw blocks; not an evidence problem.
 *
 * Re-verified (DIFF fixer): still 391 concrete bytes; all 15 relocations
 * resolve, so it is a frame-packing/allocation residue, not evidence.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
struct Ov198Hdr { char pad[0xC]; u32 font; u16 f10; };
struct Ov198P { struct Ov198Hdr *hdr; char pad[0x1E9C]; void *f1EA0; void *f1EA4; void *pad8; u32 f1EAC; };
#define P ((struct Ov198P *)p)
extern void *func_02045EC0(void *bank, u32 index);
extern u32 func_0201D304(void *, u32, u32);
extern u32 func_02045738(void *);
extern void *func_02045770(void *p);
extern void func_0201C724(u32, u32, s16, s16, void *, u32, u32);
extern void func_02045808(void *);
extern void *func_020457B0(u32, u32);
extern void func_0201EFA4(void *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern void func_0201F250(void *ws, void *dst, void *src);

void func_0220D494(u8 *p, int slot, int a2, int a3)
{
    u8 *tab;
    void *handle;
    void *text;
    u32 w1;
    u32 x;
    u32 ctx1;
    u8 *fl;
    void *text2;
    void *h2;
    u32 w2;
    u32 ctx2;
    void *text3;
    void *h3;
    u32 ctx3;

    slot = slot * 8;
    tab = p + 0x1F70;
    handle = *(void **)(tab + slot);
    text = func_02045EC0(P->f1EA0, 0x38);
    w1 = func_0201D304(text, P->hdr->font, 0);
    x = ((func_02045738(handle) << 3) - w1) >> 1;
    ctx1 = P->f1EAC;
    func_0201C724(ctx1, (u32)func_02045770(*(void **)(tab + slot)), x, 0, text, P->hdr->font, 0x3DC0);
    fl = p + 0x1F74;
    fl[slot] = 1;
    func_02045808(text);
    text2 = func_02045EC0(P->f1EA0, 0x36);
    h2 = func_020457B0(6, P->hdr->f10);
    func_0201EFA4(P->f1EA4, 0, a2, 3, 0, 1);
    func_0201F250(P->f1EA4, h2, text2);
    w2 = func_0201D304(h2, P->hdr->font, 0);
    ctx2 = P->f1EAC;
    func_0201C724(ctx2, (u32)func_02045770(*(void **)(tab + slot)), x - w2, 0, h2, P->hdr->font, 0x3DC0);
    fl[slot] = 1;
    func_02045808(text2);
    func_02045808(h2);
    text3 = func_02045EC0(P->f1EA0, 0x37);
    h3 = func_020457B0(6, P->hdr->f10);
    func_0201EFA4(P->f1EA4, 0, a3, 3, 0, 1);
    func_0201F250(P->f1EA4, h3, text3);
    ctx3 = P->f1EAC;
    func_0201C724(ctx3, (u32)func_02045770(*(void **)(tab + slot)), x + w1, 0, h3, P->hdr->font, 0x3DC0);
    fl[slot] = 1;
    func_02045808(text3);
    func_02045808(h3);
}
