/*
 * function: func_021BB4B4
 * address:  0x021BB4B4
 * packet:   pkt_ov088_021BB4B4
 * region:   ov088
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020071EC  0x020071EC  thumb
 *   func_0200C308  0x0200C308  thumb
 */

typedef unsigned char u8;

extern int func_020071EC(void *);
extern u8 func_0200C308(void *, unsigned);

void func_021BB4B4(char *p)
{
    unsigned i = 0;
    if (func_020071EC(*(void **)p) == 1) {
        p[0x120] = 0;
        i++;
    }
    (p + i)[0x120] = 1;
    (p + i)[0x121] = 2;
    i += 2;
    if (func_0200C308(*(void **)(p + 8), 1)) {
        (p + i)[0x120] = 3;
        i++;
    }
    if (func_0200C308(*(void **)(p + 8), 2)) {
        (p + i)[0x120] = 4;
        i++;
    }
    (p + i)[0x120] = 5;
    (p + i)[0x121] = 6;
    i += 2;
    if (func_0200C308(*(void **)(p + 8), 3)) {
        (p + i)[0x120] = 7;
        i++;
    }
    while (i < 8) {
        (p + i)[0x120] = 8;
        i++;
    }
}
