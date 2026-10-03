/*
 * function: func_021E10BC
 * address: 0x021E10BC
 * packet: pkt_ov183_021E10BC
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0202570C 0x0202570C thumb
 *   func_02025588 0x02025588 thumb
 */
struct Grid;
extern void func_0202570C(struct Grid *);
extern void func_02025588(void *);
void func_021E10BC(char *p){ func_0202570C(*(struct Grid **)(p+0x304)); func_0202570C(*(struct Grid **)(p+0x308)); func_02025588(*(void **)(p+0x300)); }
