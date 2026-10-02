/*
 * function: func_021D3B74
 * address: 0x021D3B74
 * packet: pkt_ov093_021D3B74
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021EF9F4 0x021EF9F4 thumb ov093
 */
typedef unsigned char u8;
typedef unsigned int u32;
typedef struct { u32 v; } Slot;
extern int func_021EF9F4(void *, u32, Slot, int);
int func_021D3B74(u32 *a, int *b, u32 *c)
{
    Slot s;
    s.v = c[1];
    func_021EF9F4((void *)a[13], c[0], s, 0);
    return 1;
}
