/*
 * function: func_021E2E60
 * address: 0x021E2E60
 * packet: pkt_ov183_021E2E60
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   d_021E3910 0x021E3910 data a4
 */
typedef struct Pair {int a,b;} Pair;
typedef struct Table {int head[4];Pair pair;} Table;
extern const Table d_021E3910;
void func_021E2E60(Pair *p)
{
    *p=d_021E3910.pair;
}
