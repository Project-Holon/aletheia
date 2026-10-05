/*
 * function: func_021C8BC4
 * address: 0x021C8BC4
 * packet: pkt_ov114_021C8BC4
 * region: ov114
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: arm
 * status: DIFF
 * recoup 2026-10-05 (wave P15 D6): residue 4 B (loop byte temps r1/r2 swapped: original
 *   b in r1, a in r2; ours b in r2, a in r1). Callees ov114 siblings return int
 *   (func_021CA470 int; func_021C9EE4 void, int server arg): declared as in matched
 *   ov114 021C87FC/021C8C68, no change in the residue. Tried: local order (b,a / a,b,
 *   function scope / block scope), assignment order, u8 vs int temps, const source,
 *   one shared temp, u8* instead of Pair, struct copy (adds mov), indexed form
 *   (strength reduced differently, 135 B off), stores a-then-b (loads reorder, 115 B off),
 *   each of the 6 per-function pragmas (opt_propagation off 117 B off, rest still 4 B).
 *   Idioms read: an-unsigned-counter-keeps-the-subs-bne-of-a-countdown-loop (kept
 *   unsigned countdown, loop shape matches), declaration-order-picks-the-register-
 *   initialisation-order-picks-the-load (no effect here), compute-a-stores-operands-
 *   before-the-store, a-byte-record-table-with-a-trailing-index-array-is-a-struct,
 *   post-increment-of-a-field-spends-a-copy. 26 compiles, over cap; stopped.
 *   Twin grep: func_021C9EE4/func_021CA470/func_021CA1B4 callers in ov114 only
 *   (87FC, 8C68, 8DA0 etc.), none copies 2-byte records in a loop.
 * symbols:
 *   d_021D3D28   0x021D3D28  data  a4
 *   d_021D3D2C   0x021D3D2C  data  a4
 *   d_021CF538   0x021CF538  data  a4
 *   d_021CF634   0x021CF634  data  a4
 *   d_021D3D40   0x021D3D40  data  a4
 *   func_021C9EE4 0x021C9EE4  arm
 *   func_021CA470 0x021CA470  arm
 *   func_021CA1B4 0x021CA1B4  arm
 */
typedef unsigned char u8;
extern unsigned int *d_021D3D28;
extern unsigned int d_021D3D2C[];
extern unsigned int d_021CF538[];
extern unsigned int d_021CF634[];
extern unsigned int d_021D3D40[];
extern void func_021C9EE4(int server, char *initdata);
extern int func_021CA470(void *, unsigned int, void *, unsigned int, unsigned int);
extern void func_021CA1B4(void);

typedef struct { u8 a, b; } Pair;
void func_021C8BC4(Pair *p, unsigned int x)
{
    unsigned int i;
    Pair *q = (Pair *)d_021D3D40;
    d_021D3D2C[0x72] = x;
    for (i = 4; i != 0; i--) {
        u8 b = p->b;
        u8 a = p->a;
        p++;
        q->b = b;
        q->a = a;
        q++;
    }
    func_021C9EE4((int)d_021D3D28, (char *)d_021CF538);
    if (func_021CA470(d_021CF634, d_021D3D2C[2], d_021D3D40, 8, 0) == 0) {
        d_021D3D2C[0] = 14;
        return;
    }
    d_021D3D2C[0] = 24;
    d_021D3D2C[1] = -13;
    func_021CA1B4();
}
