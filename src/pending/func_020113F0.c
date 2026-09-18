/*
 * function: func_020113F0
 * address:  0x020113F0
 * packet:   pkt_020113F0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 *
 * symbols:
 *   g_0209DF24  0x0209DF24  data
 *
 * A flat two-dimensional table lookup: row stride 24 (0x18), byte
 * entries.  func_020113D8.c's header refers to "src/matched/
 * sub_02011410.c" for the near-miss details on this function; no such
 * file exists in the tree (a stale cross-reference), so this file is
 * written fresh from the disassembly at asm/arm9/src/004_02010BB8.s:1339.
 *
 * This was the register-swap near miss the cross-reference promised:
 * `g_0209DF24[row * 24 + col]` (or with the addends swapped) puts the
 * combined `table + row*24` pointer and `col` into the ldrb the wrong
 * way round (r1/r0 versus the original's r0/r1). Naming the combined
 * pointer as a local (`p = g_0209DF24 + row * 24; return p[col];`)
 * reproduces the original's register choice exactly and closes the near
 * miss to MATCH; only g_0209DF24 itself has no witness outside this
 * function's own range (it is a flat data table, no code anywhere in
 * the image branches to it or reads it as a `matched`/`label` site), so
 * this stays MATCH rather than EXACT.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/func_020113F0.c \
 *       --func func_020113F0 --addr 0x020113F0 --cc 1.1p1 --thumb
 * blocker:  unresolved relocation(s): 0209DF24 (data, from header)*/

typedef unsigned char u8;
typedef unsigned int  u32;

extern const u8 g_0209DF24[];

u8 func_020113F0(u32 row, u32 col)
{
    const u8 *p = g_0209DF24 + row * 24;
    return p[col];
}
