/*
 * function: B_PLIST_DRAW_PrintPpPair
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
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   PRINTSYS_PrintQueColor 0x0201C724 thumb
 *   STRBUF_Delete 0x02045808 arm
 *   STRBUF_Create 0x020457B0 arm
 *   WORDSET_SetSlotNumber 0x0201EFA4 thumb
 *   WORDSET_CopyTaggedText 0x0201F250 thumb
 *   func_0201D304 0x0201D304 thumb
 *   BMP_WIN_GetWidth 0x02045738 arm
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
struct Descriptor;
struct MsgBank;
struct StrObj;
struct U16Vec;
struct WordSet;
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern u32 func_0201D304(struct StrObj *s, u32 a, u32 b);
extern u8 BMP_WIN_GetWidth(struct Descriptor *p);
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
extern void PRINTSYS_PrintQueColor(void *owner, u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern void STRBUF_Delete(struct U16Vec *vec);
extern struct U16Vec *STRBUF_Create(u32 capacity, u32 heapId);
extern void WORDSET_SetSlotNumber(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern void WORDSET_CopyTaggedText(struct WordSet *ws, void *dst, void *src);

void B_PLIST_DRAW_PrintPpPair(u8 *p, int slot, int a2, int a3)
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
    x = ((BMP_WIN_GetWidth(handle) << 3) - w1) >> 1;
    ctx1 = P->f1EAC;
    PRINTSYS_PrintQueColor((void *)ctx1, (u32)BMP_WIN_GetBmp(*(void **)(tab + slot)), (s16)x, (s16)0, (u32)text, P->hdr->font, (u32)0x3DC0);
    fl = p + 0x1F74;
    fl[slot] = 1;
    STRBUF_Delete(text);
    text2 = func_02045EC0(P->f1EA0, 0x36);
    h2 = STRBUF_Create(6, P->hdr->f10);
    WORDSET_SetSlotNumber(P->f1EA4, 0, a2, 3, 0, 1);
    WORDSET_CopyTaggedText(P->f1EA4, h2, text2);
    w2 = func_0201D304(h2, P->hdr->font, 0);
    ctx2 = P->f1EAC;
    PRINTSYS_PrintQueColor((void *)ctx2, (u32)BMP_WIN_GetBmp(*(void **)(tab + slot)), (s16)(x - w2), (s16)0, (u32)h2, P->hdr->font, (u32)0x3DC0);
    fl[slot] = 1;
    STRBUF_Delete(text2);
    STRBUF_Delete(h2);
    text3 = func_02045EC0(P->f1EA0, 0x37);
    h3 = STRBUF_Create(6, P->hdr->f10);
    WORDSET_SetSlotNumber(P->f1EA4, 0, a3, 3, 0, 1);
    WORDSET_CopyTaggedText(P->f1EA4, h3, text3);
    ctx3 = P->f1EAC;
    PRINTSYS_PrintQueColor((void *)ctx3, (u32)BMP_WIN_GetBmp(*(void **)(tab + slot)), (s16)(x + w1), (s16)0, (u32)h3, P->hdr->font, (u32)0x3DC0);
    fl[slot] = 1;
    STRBUF_Delete(text3);
    STRBUF_Delete(h3);
}
