/*
 * function: NNSi_G2dMCAnimUpdateBank
 * address:  0x02064C10
 * packet:   pkt_020648E0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_02064384   0x02064384  arm
 *
 * The single-step twin of func_02064934: walks every node of the multi-cell
 * bank and advances its cell animation by one frame.  Same two layouts
 * (kind 1 is the 0x5C-stride node array with its count at header +2, anything
 * else the 0x28-stride cell array with its count at header +0 and each
 * record's pointer in its word 0).
 *
 * The second argument func_02064384 receives is the constant 0, materialised
 * into r4 once outside the loop and never refreshed: the register that holds it
 * is rematerialised off the counter's own zero.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/NNSi_G2dMCAnimUpdateBank.c \
 *       --func NNSi_G2dMCAnimUpdateBank --addr 0x02064C10 --arm --cc 1.1p1
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct NodeHdr02064C10 {
    u16 pad_00;
    u16 count;
};

struct CellHdr02064C10 {
    u16 count;
};

struct Obj02064C10 {
    void *hdr;      /* +0x00 */
    u32   unk_04;
    u32   kind;     /* +0x08 */
    void *base;     /* +0x0C */
};

struct CellAnim;
extern void func_02064384(struct CellAnim *anim, u32 i);

void NNSi_G2dMCAnimUpdateBank(struct Obj02064C10 *x)
{
    u16 i;

    if (x->kind == 1) {
        void *base = x->base;

        for (i = 0; i < ((struct NodeHdr02064C10 *)x->hdr)->count; i++) {
            func_02064384((struct CellAnim *)((u8 *)base + i * 0x5c), 0);
        }
    } else {
        void *base = x->base;

        for (i = 0; i < ((struct CellHdr02064C10 *)x->hdr)->count; i++) {
            func_02064384(*(void **)((u8 *)base + i * 0x28), 0);
        }
    }
}
