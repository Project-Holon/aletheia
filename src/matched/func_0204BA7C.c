/*
 * function: func_0204BA7C
 * address:  0x0204BA7C
 * packet:   pkt_0204B954
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   g_02146A74     0x02146A74  data
 *   func_02063800  0x02063800  arm
 *
 * Record the two VRAM base offsets of a cell-actor resource set in the
 * singleton: func_02063800 returns a byte address per bank selector, the
 * halfword fields at +0xf0 and +0xf2 hold it in 32-byte units, and the
 * caller's bias is then folded into both.
 *
 * The bias is folded with `+=`, not by adding it into the expression above:
 * the compound form re-reads the halfword it just stored
 * (docs/idioms/compound-assignment-rereads-the-field-plain-assignment-reuses-the-cached-load.md),
 * which is what produces the four extra `ldr r1, [r6]` / `ldrh` / `strh`
 * groups instead of one `add` before each store.
 *
 * Only the address of the global is worth keeping in r6: the pointer itself
 * is re-read before every store because each call and each store may alias
 * it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0204BA7C.c \
 *       --func func_0204BA7C --addr 0x0204BA7C --cc 1.1p1 --arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Sys {
    u8  pad_000[0xf0];
    u16 unk_0f0;   /* 0xf0 */
    u16 unk_0f2;   /* 0xf2 */
    u32 unk_0f4;   /* 0xf4 */
};

extern struct Sys *g_02146A74;

extern u32 func_02063800(u32 set, u32 which);

void func_0204BA7C(u32 set, u16 bias, u32 v)
{
    g_02146A74->unk_0f0 = func_02063800(set, 1) >> 5;
    g_02146A74->unk_0f2 = func_02063800(set, 2) >> 5;

    g_02146A74->unk_0f0 += bias;
    g_02146A74->unk_0f2 += bias;

    g_02146A74->unk_0f4 = v;
}
