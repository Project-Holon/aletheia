/*
 * function: func_021585E0
 * address: 0x021585E0
 * packet: pkt_ov010_021585E0
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02158344 0x02158344 thumb ov010
 *   func_02158630 0x02158630 thumb ov010
 * Callee 02158344 consumes incoming r0; the flag extract reads bit 2.
 */
typedef unsigned char u8;
typedef struct { u8 low:2; u8 flag:1; u8 high:5; } Flag;
extern u8 *func_02158344(void *);
extern int func_02158630(int);
int func_021585E0(int p)
{
    u8 *q = func_02158344((void *)p);
    if (q == 0)
        return 0;
    if (((Flag *)(q + 0x93F))->flag == 0) {
        if (func_02158630(p) == 3)
            return 2;
        return 1;
    }
    return 3;
}
