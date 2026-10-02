/*
 * function: func_02186B60
 * address: 0x02186B60
 * packet: pkt_ov020_02186B60
 * region: ov020
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02161ECC 0x02161ECC thumb ov010
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef struct { u8 lo:4; u8 hi:4; u8 b1; u8 b2; u8 pad; u16 ids[8]; } T;
extern int func_02161ECC(T *p);
char *func_02186B60(char *p)
{
    int i;
    for (i = 0; i < 10; i++) {
        if (func_02161ECC((T *)(p + i * 24)) == 0)
            return p + i * 24;
    }
    return p;
}
