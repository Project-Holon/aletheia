/*
 * function: CLACT_InitDefaultRenderer
 * address:  0x0204BA38
 * packet:   pkt_0204B954
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   g_ClactTables     0x020A7F3C  data
 *   CLACT_InitRenderer  0x0204BD94  arm
 *
 * Copy two signed halfword pairs from the caller's array into clact.c's
 * static two-record scratch block and hand the block to CLACT_InitRenderer.
 *
 * The two pool words 0x020A7F3C and 0x020A7F54 are one symbol, not two: the
 * stores reach the record array as +0x18/+0x1a/+0x28/+0x2a off the base, so
 * the scratch block is the tail of the same static object whose first 0x18
 * bytes are the six function pointers CLACT_UpdateCellAnim..CLACT_ResetVramAnim that
 * 0x0204D4DC also loads
 * (docs/idioms/pool-base-for-a-far-field-is-the-symbol-offset-masked-by-the-load-reach.md).
 * Reading them as two objects splits the symbol and loses the relocation.
 *
 * `ldrsh` with an immediate offset is what names the source elements s16
 * (docs/idioms/ldrsh-register-offset-is-signedness.md covers the register
 * form of the same tell).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/CLACT_InitDefaultRenderer.c \
 *       --func CLACT_InitDefaultRenderer --addr 0x0204BA38 --cc 1.1p1 --arm
 */

typedef signed short  s16;
typedef unsigned char u8;
typedef unsigned int  u32;

struct Rec {
    s16 x;            /* 0x00 */
    s16 y;            /* 0x02 */
    u8  pad_04[0x0c];
};

struct Clact {
    void      (*vt[6])(void);   /* 0x00 */
    struct Rec  rec[2];         /* 0x18 */
};

extern struct Clact g_ClactTables;

struct Obj;
extern void CLACT_InitRenderer(struct Obj *obj, u8 *src, int count, u32 heap);

void CLACT_InitDefaultRenderer(void *a, const s16 *src, u32 mode)
{
    g_ClactTables.rec[0].x = src[0];
    g_ClactTables.rec[0].y = src[1];
    g_ClactTables.rec[1].x = src[2];
    g_ClactTables.rec[1].y = src[3];

    CLACT_InitRenderer(a, (u8 *)g_ClactTables.rec, 2, mode);
}
