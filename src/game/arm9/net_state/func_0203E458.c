/*
 * unit:     no
 * function: func_0203E458
 * address:  0x0203E458
 * packet:   pkt_0203DA7C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * symbols:
 *   g_021469F0      0x021469F0  data
 */

typedef struct G_021469F0 {
    unsigned char pad[0x7c];
    void *(*fn)(void *);
} G_021469F0;
extern G_021469F0 *g_021469F0;
void *func_0203E458(void *arg)
{
    void *r;
    if (g_021469F0 == 0)
        return 0;
    r = g_021469F0->fn(arg);
    return (char *)r + 0x24;
}
