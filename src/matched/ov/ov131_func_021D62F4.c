/*
 * function: func_021D62F4
 * address: 0x021D62F4
 * packet: pkt_ov131_021D62F4
 * region: ov131
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021DBF2C 0x021DBF2C thumb ov131
 *   func_02017E88 0x02017E88 thumb
 */
extern unsigned int func_021DBF2C(unsigned int, unsigned int);
typedef unsigned int   u32;
extern u32 func_02017E88(void *p, u32 id, u32 v);
int func_021D62F4(char *p, void *q)
{
    unsigned char i;
    for (i = 0; i < 0x50; i++) {
        if (func_02017E88(q, func_021DBF2C(i, 0), 0) == 1) {
            return 1;
        }
    }
    return 0;
}
