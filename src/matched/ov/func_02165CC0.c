/*
 * function: func_02165CC0
 * address:  0x02165CC0
 * packet:   pkt_02165CC0
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02087D1C  0x02087D1C  arm
 *
 * Promoted from MATCH by the recursive-unblocker lane: 0x02087D1C now has an
 * EXACT arm9 shard entry (pkt_02087D1C), so the call resolves via `matched`.
 * Verified EXACT* (listing 144 vs compiled 24 is the multi-function extent;
 * the function's own bytes are exact).
 *
 * 2026-10-02: func_02087D1C returns a pointer, but it stays declared
 * `extern int func_02087D1C();` here.  A declaration-only fix (a pointer
 * return and a char * receiving local) does not keep the bytes: the
 * compiler moves the shift chain that builds t5.  A variant that folds the
 * shift chain into one expression,
 * `t5 = (unsigned)(*(int *)((char *)a1 + 0xc) << 0x10) >> 0x1c;`, with
 * `char *p = func_02087D1C();`, does match (EXACT, the same verdict as
 * this file against the current listings).  It changes code and not just
 * types, so it is kept outside the tree pending a decision:
 * docs/notes/func_02165CC0_variantF.c.txt.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern char *func_02087D1C(void);

void func_02165CC0(int a0, int a1)
{
    int t4;
    int t5;

t4 = a0 + 0;
a0 = *(int *)((char *)a1 + 0xc);
a0 = a0 << 0x10;
t5 = (unsigned)a0 >> 0x1c;
    a0 = (int)func_02087D1C();
loc_02165CCE:
a1 = t5 << 0x1c;
a1 = (unsigned)a1 >> 0x1b;
a0 = *(u16 *)((char *)a0 + a1);
*(u16 *)((char *)t4) = a0;
    return;}
