/*
 * function: CLACT_SetOamOffsets
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
 *   g_ClactSystem     0x02146A74  data
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
 *   python tools/match.py one --src src/matched/CLACT_SetOamOffsets.c \
 *       --func CLACT_SetOamOffsets --addr 0x0204BA7C --cc 1.1p1 --arm
 */

#include "../include/G_Mgr.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern struct Mgr *g_ClactSystem;

extern int func_02063800(char *p, int i);

void CLACT_SetOamOffsets(u32 set, u16 bias, u32 v)
{
    g_ClactSystem->unk_f0 = (u32)func_02063800((char *)set, (u32)1) >> 5;
    g_ClactSystem->unk_f2 = (u32)func_02063800((char *)set, (u32)2) >> 5;

    g_ClactSystem->unk_f0 += bias;
    g_ClactSystem->unk_f2 += bias;

    g_ClactSystem->unk_f4 = v;
}
