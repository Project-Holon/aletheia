/*
 * function: sub_02043094
 * address:  0x02043094
 * packet:   pkt_02042B24
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   g_02146A44     0x02146A44  data
 *   func_0203422C  0x0203422C  arm
 *
 * Release one block back to whichever of the two arenas the slot index
 * names.  Slots 0..3 belong to the arena at +0x168 of the singleton hanging
 * off 0x02146A44, slots 4..7 to the one at +0x16c, and any other index is a
 * no-op.  The byte offset is biased by the per-slot base at +0x190 and the
 * byte length rounded up, both converted to 32-byte units before
 * func_0203422C sees them.  The index is not rebased for the second arena:
 * both arms read unk_190[idx] with the raw index.
 *
 * Codegen note: the round-up flag has to be spelled as the ternary
 * `(size & 0x1f) ? 1 : 0`, not as the relational `(size & 0x1f) != 0`.
 * Both are `tst`/`movne`/`moveq`, but the relational form is folded into
 * the argument expression and the scheduler then hoists the global load
 * above it, spilling the flag into lr; the ternary is materialised as its
 * own value first, which keeps ip free and reproduces the original order.
 */

typedef unsigned char u8;
typedef unsigned int  u32;

struct Ctx {
    u8  pad_00[0x168];
    void *unk_168;
    void *unk_16c;
    u8  pad_170[0x20];
    u32 unk_190[8];
};

extern struct Ctx *g_02146A44;

typedef signed int     s32;
struct AreaMan;
extern void func_0203422C(struct AreaMan *p, u32 start, s32 len);

void sub_02043094(u32 idx, u32 offset, u32 size)
{
    switch (idx) {
    case 0:
    case 1:
    case 2:
    case 3:
        {
            u32 count = ((size & 0x1f) ? 1 : 0) + (size >> 5);
            func_0203422C(g_02146A44->unk_168,
                          (offset + g_02146A44->unk_190[idx]) >> 5, count);
        }
        break;
    case 4:
    case 5:
    case 6:
    case 7:
        {
            u32 count = ((size & 0x1f) ? 1 : 0) + (size >> 5);
            func_0203422C(g_02146A44->unk_16c,
                          (offset + g_02146A44->unk_190[idx]) >> 5, count);
        }
        break;
    }
}
