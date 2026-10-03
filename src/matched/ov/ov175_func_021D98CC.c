/*
 * function: func_021D98CC
 * address: 0x021D98CC
 * packet: pkt_ov175_021D98CC
 * region: ov175
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021E8338 0x021E8338 thumb ov177
 */
typedef struct Work Work;
extern int func_021E8338(Work *);
int func_021D98CC(char *p)
{
    return func_021E8338(*(Work **)(p+0x24));
}
