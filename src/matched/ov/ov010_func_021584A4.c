/*
 * function: func_021584A4
 * address:  0x021584A4
 * packet:   pkt_ov010_021584A4
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02158344  0x02158344  thumb
 *   func_02012B58  0x02012B58  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;

typedef struct { u16 f : 3; u16 g : 13; } Fh;

extern u8 *func_02158344(void);
extern int func_02012B58(int);

int func_021584A4(int unused, int a, int mode)
{
    u8 *q = func_02158344();
    int n;
    int cur;
    if (q == 0)
        return 1;
    cur = ((Fh *)(q + 0x86))->f;
    if (mode == 2) {
        n = cur - 1;
        if (n < 0)
            n = q[0x901];
    } else {
        n = cur + 1;
        if (n >= q[0x901] + 1)
            n = 0;
    }
    if (n == func_02012B58(a))
        return 1;
    return 0;
}
