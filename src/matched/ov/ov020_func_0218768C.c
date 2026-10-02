/*
 * function: func_0218768C
 * address: 0x0218768C
 * packet: pkt_ov020_0218768C
 * region: ov020
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * lever: capture the base in a local before filling the stack pair, preserving the original r3 load.
 * symbols:
 *   func_021876B0 0x021876B0 thumb ov020
 */
typedef struct { int index; char *base; } Pair;
extern void func_021876B0(Pair *p, int tick);
void func_0218768C(char *p)
{
    Pair pair;
    char *base;
    (*(int *)(p + 0x18))++;
    base = *(char **)(p + 0x14);
    if (base != (char *)-1) {
        pair.index = *(int *)(p + 0xc);
        pair.base = base;
        func_021876B0(&pair, *(int *)(p + 0x18));
    }
}
