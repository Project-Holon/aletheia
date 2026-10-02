/*
 * function: func_021738BC
 * address: 0x021738BC
 * packet: pkt_ov011_021738BC
 * region: ov011
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02167658 0x02167658 thumb ov010
 * The index loaded from c remains live in r1 into 02167658.
 */
typedef unsigned char u8;
typedef unsigned int u32;
typedef struct { void *sys; void *obj; } Work;
extern void func_02167658(Work *, int);
void func_021738BC(int a, int b, int *c, u8 *d)
{
    int i;
    u32 bit;
    u8 mask;
    i = *c;
    bit = 1u << i;
    mask = d[0x8fb];
    if (mask & bit) {
        d[0x8fb] = mask ^ (u8)bit;
        func_02167658(*(Work **)(d + 8), i);
    }
}
