/*
 * file:     unit_02064C10.c
 * function: func_02064C10
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
 *   python tools/match.py one --src src/matched/func_02064C10.c \
 *       --func func_02064C10 --addr 0x02064C10 --arm --cc 1.1p1
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct MCNodeBankHeader {
    u16 reserved;
    u16 count;
};

struct MCCellBankHeader {
    u16 count;
};

struct MCAnimBank {
    void *pHeader;      /* +0x00 */
    void *pResource;    /* +0x04 */
    u32   kind;         /* +0x08 */
    void *pRecords;     /* +0x0C */
};

struct CellAnim;
extern void func_02064384(struct CellAnim *anim, u32 frames);

void func_02064C10(struct MCAnimBank *bank)
{
    u16 i;

    if (bank->kind == 1) {
        void *records = bank->pRecords;

        for (i = 0; i < ((struct MCNodeBankHeader *)bank->pHeader)->count; i++) {
            func_02064384((struct CellAnim *)((u8 *)records + i * 0x5c), 0);
        }
    } else {
        void *records = bank->pRecords;

        for (i = 0; i < ((struct MCCellBankHeader *)bank->pHeader)->count; i++) {
            func_02064384(*(void **)((u8 *)records + i * 0x28), 0);
        }
    }
}
