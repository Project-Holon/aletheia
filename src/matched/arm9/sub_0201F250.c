/*
 * function: WORDSET_CopyTaggedText
 * address:  0x0201F250
 * packet:   pkt_0201F250
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * wordset.c's message expander, 204 bytes.  It walks the source message a
 * halfword at a time and rewrites it into the destination buffer: an ordinary
 * character is copied straight through, a 0xF000 tag that is not a word
 * reference is copied verbatim halfword by halfword, and a word reference is
 * replaced by the stored word itself.
 *
 * The tag primitives it calls are the seven of src/matched/unit_0201D5C4.c:
 * PRINTSYS_GetTagChar is the 0xF000 marker, PRINTSYS_IsWordSlotTag says whether the tag is a
 * word reference, PRINTSYS_GetTagParam reads parameter 0 (the word index),
 * PRINTSYS_AppendTag writes a new tag, and PRINTSYS_SkipTag steps the cursor past a
 * tag.  The word table hangs off the object at +8 and its entries are 0xC
 * bytes: a flag at +4 and the word's own message at +8.  When the flag is set
 * the expansion is bracketed by two freshly built 0xBD tags, kinds 6 and 4,
 * whose single parameter is the word index and the constant 0x54.
 *
 * Three details cost time:
 *
 *   - **The entry pointer is a named local for the first tag write and the
 *     written-out expression for the second.**  `&tbl[i]` must be bound to a
 *     local, because the two `strh`s into the parameter buffer sit between the
 *     flag test and the first write, and the buffer has its address taken, so
 *     re-reading `ws->unk08` after them costs a reload the original does not
 *     have.  Binding it for the *second* write as well is four bytes too long
 *     the other way: the local would then be live across PRINTSYS_AppendTag and the
 *     index has to be spilled.  The original recomputes the address from the
 *     two callee-saved registers it already holds, which is what writing the
 *     expression out gives.
 *   - **The character copies are `*p++`, not `p[0]` then `p++`.**  With the
 *     increment spelled separately the compiler sinks it past the call and
 *     then folds the loop-bottom re-read into the copy's own load; the
 *     function is four bytes short and the bottom of the loop is wrong.
 *   - **`q` is declared before `p`.**  The two cursors are the only locals
 *     live across the inner loop, and declaring `p` first swaps r4 and r5
 *     throughout (docs/idioms/declaration-order-decides-which-register-a-local-gets.md).
 *
 * EXACT*: the two bytes after the epilogue are the unit's alignment padding
 * and 0x0201F31C, the next function, already carries a label.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0201F250.c \
 *       --func WORDSET_CopyTaggedText --addr 0x0201F250 --cc 1.1p1 --thumb
 *
 * symbols:
 *   STRBUF_Clear  0x0204581C  arm
 *   STRBUF_GetChars  0x02045A90  arm
 *   STRBUF_AppendChar  0x02045AFC  arm
 *   STRBUF_GetEosChar  0x02045A98  arm
 *   PRINTSYS_IsWordSlotTag  0x0201D5CC  thumb
 *   PRINTSYS_GetTagChar  0x0201D5C4  thumb
 *   PRINTSYS_AppendTag  0x0201D60C  thumb
 *   PRINTSYS_GetTagParam  0x0201D670  thumb
 *   PRINTSYS_SkipTag  0x0201D688  thumb
 *   WORDSET_AppendUnpackedString  0x0201F4A0  thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Entry {
    u32   unk00;
    u8    unk04;
    u8    pad05[3];
    void *unk08;
};

struct WordSet {
    u32 pad00[2];
    struct Entry *unk08;
};

struct U16Vec;
extern u16 *STRBUF_GetChars(struct U16Vec *vec);
extern void STRBUF_Clear(struct U16Vec *vec);
extern u16  STRBUF_GetEosChar(void);
extern void STRBUF_AppendChar(struct U16Vec *vec, u16 value);

extern u32   PRINTSYS_GetTagChar(void);
extern u32   PRINTSYS_IsWordSlotTag(const u16 *p);
extern void  PRINTSYS_AppendTag(void *s, u32 b, u32 c, u16 n, const u16 *arr);
extern u32   PRINTSYS_GetTagParam(const u16 *p, u32 i);
extern u16  *PRINTSYS_SkipTag(u16 *p);
extern void  WORDSET_AppendUnpackedString(void *dst, void *src);

void WORDSET_CopyTaggedText(struct WordSet *ws, void *dst, void *src)
{
    u16 buf[2];
    u32 term;
    u32 marker;
    u16 *q;
    u16 *p;
    u32 i;
    struct Entry *e;

    p = STRBUF_GetChars(src);
    STRBUF_Clear(dst);
    term = STRBUF_GetEosChar();
    marker = PRINTSYS_GetTagChar();
    while (p[0] != term) {
        if (p[0] == marker) {
            if (PRINTSYS_IsWordSlotTag(p) != 0) {
                i = PRINTSYS_GetTagParam(p, 0);
                e = &ws->unk08[i];
                if (e->unk04 != 0) {
                    buf[1] = (u16)i;
                    buf[0] = 0x54;
                    PRINTSYS_AppendTag(e->unk08, 0xBD, 6, 1, &buf[1]);
                    PRINTSYS_AppendTag(ws->unk08[i].unk08, 0xBD, 4, 1, &buf[0]);
                }
                WORDSET_AppendUnpackedString(dst, ws->unk08[i].unk08);
                p = PRINTSYS_SkipTag(p);
            } else {
                q = p;
                p = PRINTSYS_SkipTag(p);
                while (q < p) {
                    STRBUF_AppendChar(dst, *q++);
                }
            }
        } else {
            STRBUF_AppendChar(dst, *p++);
        }
    }
}
