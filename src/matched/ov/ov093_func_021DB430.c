/*
 * unit: yes
 * function: func_021DB430, func_021DB454
 * address: 0x021DB430
 * packet: pkt_ov093_021DB430
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021DA8A8 0x021DA8A8 thumb ov093
 *   func_021DA96C 0x021DA96C thumb ov093
 *   d_021F0A70 0x021F0A70 data a4
 */
extern int func_021DA8A8(int,int,int);
extern void func_021DA96C(void *,int,unsigned int,int);
extern const unsigned int d_021F0A70[];

void func_021DB430(int a, void *b, int c)
{
    if (func_021DA8A8((int)b, c, 10) != 0) func_021DA96C(b, c, 3, 1);
}

const unsigned int *func_021DB454(int *p)
{
    *p = 3;
    return d_021F0A70;
}
