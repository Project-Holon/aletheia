/*
 * function: func_0202C070
 * address:  0x0202C070
 * packet:   pkt_0202C070
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH*
 * note:     re-verified 2026-09-20: MATCH*; see verify output
 *
 * Blocked: the THM_CALL at +0012 to func_0202C148 has no manifest entry.
 * 0x0202C148 (76 bytes, pkt_0202C148, still open) is byte-correct except an
 * eight-instruction schedule permutation in its prologue: 15 C spellings were
 * measured and every one emits the same permuted block, so it is a DIFF and
 * cannot be filed - see docs/notes/pkt_0202C148.c.txt.  The other two sites
 * (func_0202C124, func_0202C118) resolve as `matched`.  Every concrete byte
 * reproduces.
 *
 * Creates a node through func_0202C124, prepares it with func_0202C118 and
 * binds the argument with func_0202C148.
 *
 * symbols:
 *   func_0202C124  0x0202C124  thumb
 *   func_0202C118  0x0202C118  thumb
 *   func_0202C148  0x0202C148  thumb
 */

typedef unsigned char u8;
typedef unsigned int  u32;

extern u8  *func_0202C124(void);
extern void func_0202C118(void);
extern void func_0202C148(u8 *p, u8 *arg);

u8 *func_0202C070(u8 *p)
{
    u8 *r = func_0202C124();

    func_0202C118();
    func_0202C148(r, p);
    return r;
}
