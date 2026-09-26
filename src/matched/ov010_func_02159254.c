/*
 * function: func_02159254
 * address:  0x02159254
 * packet:   pkt_02159254
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Recursive MATCH unblocker: tail-call thunk at the pool word 0x0215A691
 * (func_0215A690). Matched so the ABS32 site in func_02159260 attests as
 * `matched`.
 *
 * symbols:
 *   func_0215A690  0x0215A690  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_0215A690(char *);

void func_02159254(char *a0, char *a1)
{
    func_0215A690(a1);
    (void)a0;
}
