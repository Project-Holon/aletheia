/*
 * function: func_021D98D8
 * address: 0x021D98D8
 * packet: pkt_ov175_021D98D8
 * region: ov175
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021E8420 0x021E8420 thumb ov177
 */
typedef struct Work Work;
extern int func_021E8420(Work *);
int func_021D98D8(char *p)
{
    return func_021E8420(*(Work **)(p+0x24));
}
