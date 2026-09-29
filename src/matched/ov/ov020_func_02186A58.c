/*
 * function: func_02186A58
 * address:  0x02186A58
 * packet:   pkt_ov020_02186A58
 * region:   ov020
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02161ECC  0x02161ECC  thumb  ov010
 */

typedef unsigned char u8;

extern int func_02161ECC(char *);

int func_02186A58(char *p, int id)
{
    int i;
    char *b;
    char *a;

    i = 0;
    a = p + 8;
    for (; i < 10; i++) {
        if (func_02161ECC(a + i * 0x18) != 0 && (u8)p[i * 0x18 + 9] == id)
            return 1;
    }
    i = 0;
    b = p + 0xF8;
    for (; i < 10; i++) {
        if (func_02161ECC(b + i * 0x18) != 0 && (u8)p[i * 0x18 + 0xF9] == id)
            return 1;
    }
    return 0;
}
