/*
 * function: func_021EE544
 * address:  0x021EE544
 * packet:   pkt_ov170_021EE544
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * 2026-10-05 (wD7 lane17): closed by declaring the table d_021F0188 const (extern and local
 *   pointer). A const load does not alias the outgoing stack store, so the scheduler hoists g[0]
 *   above `str r1,[sp]`; the non-const E table loads stay below it.
 * symbols:
 *   func_021EEFA4  0x021EEFA4  thumb
 *   d_021F0188  0x021F0188  data
 *   d_021F0DCC  0x021F0DCC  data
 *   d_021F0370  0x021F0370  data
 */

typedef struct { unsigned char a, b, pad[10]; } E;
extern const unsigned char d_021F0188[];
extern E d_021F0DCC[];
extern E d_021F0370[];
extern void func_021EEFA4(char *p, unsigned char x, unsigned char y, unsigned char tx, unsigned char ty);
void func_021EE544(char *p, unsigned int i)
{
    E *e; const unsigned char *g = d_021F0188;
    if (i < 0x1e) { e = &d_021F0DCC[i]; } else { e = &d_021F0370[i - 0x1e]; }
    func_021EEFA4(*(char **)(p + 0x2c), e->a, e->b, g[0], g[1]);
}
