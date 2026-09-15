/*
 * unit:     no
 * address:  0x020213F8
 * packet:   pkt_02020D5C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 * function: func_020213F8
 *
 * symbols:
 *   g_0209E904     0x0209E904  data
 *
 * Parked: byte correct, capped at MATCH by the evidence rather than by the C.
 * The table address has no `literal` witness the tool can see, and the reason
 * is a disassembly gap rather than a real absence: every pool word that holds
 * it sits inside one of the unlabelled leaf functions of this run
 * (0x02021350, 0x0202136C, 0x0202138C, 0x020213AC, 0x020213C0, 0x020213E0,
 * 0x020213F8, 0x0202142C), and disasm.py only labels a function whose
 * prologue saves lr, so those regions are not disassembled as code plus pool
 * at all and their `.word`s never enter the literal index
 * (docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md).  Seeding
 * those eight addresses into layout/function_starts.txt is what unblocks
 * this file; no new evidence has to be invented, and none of the C is in
 * doubt, the byte range is identical with the wildcard filled in.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/func_020213F8.c  *       --func func_020213F8 --addr 0x020213F8 --cc 1.1p1 --thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern const u16 g_0209E904[][2];

u16 func_020213F8(u16 v, u32 side)
{
    u32 i;

    for (i = 0; i < 0x19; i++) {
        if (v == g_0209E904[i][side]) {
            return g_0209E904[i][side ^ 1];
        }
    }
    return 0;
}
