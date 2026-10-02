/*
 * function: func_021DB4C4
 * address: 0x021DB4C4
 * packet: pkt_ov093_021DB4C4
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_021DA8A8 0x021DA8A8 thumb ov093
 *   func_021DA96C 0x021DA96C thumb ov093
 */
extern int func_021DA8A8(int,int,int);
extern void func_021DA96C(void *,int,unsigned int,int);

void func_021DB4C4(int a, void *b, int c)
{
    if (func_021DA8A8((int)b, c, 12) != 0) func_021DA96C(b, c, 3, 1);
}
