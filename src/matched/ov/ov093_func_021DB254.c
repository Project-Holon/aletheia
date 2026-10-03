/*
 * function: func_021DB254
 * address: 0x021DB254
 * packet: pkt_ov093_021DB254
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_021C8288 0x021C8288 thumb ov093
 *   func_021DB374 0x021DB374 thumb ov093
 */
typedef unsigned char  u8;
extern int func_021C8288(u8 *p);
extern void func_021DB374(void *,int,unsigned int);

void func_021DB254(int a, void *b, int c, int *d)
{
    func_021DB374(b, c, func_021C8288(b));
    *d = 1;
}
