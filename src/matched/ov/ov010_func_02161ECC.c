/*
 * function: func_02161ECC
 * address: 0x02161ECC
 * packet: pkt_ov010_02161ECC
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_02161E84 0x02161E84 thumb ov010
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef struct { u8 lo:4; u8 hi:4; u8 b1; u8 b2; u8 pad; u16 ids[8]; } T;
extern int func_02161E84(T *);
int func_02161ECC(T *p)
{
    if (p->lo == 0) return 0;
    if (func_02161E84(p) != 0) return 1;
    return 0;
}
