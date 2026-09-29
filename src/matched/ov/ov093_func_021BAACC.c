/*
 * function: func_021BAACC
 * address:  0x021BAACC
 * packet:   pkt_ov093_021BAACC
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021B9AEC  0x021B9AEC  thumb  ov093
 *   func_021EEA58  0x021EEA58  thumb  ov093
 *   func_021BB840  0x021BB840  thumb  ov093
 *   func_021BB848  0x021BB848  thumb  ov093
 */

typedef unsigned char u8;
typedef unsigned short u16;

char *func_021B9AEC(char *p, int i);
int func_021EEA58(int, int, int, int);
void func_021BB840(char *, int, int, int);
void func_021BB848(char *, char *, u8);

void func_021BAACC(char *p, int a, int b, int c, u8 d)
{
    char *x;
    int y;
    char *q;
    int off;

    x = func_021B9AEC(*(char **)(p + 0x10), c);
    y = func_021EEA58(b, c, 1, *(u16 *)(p + 0xcc0));
    q = p + 0x14;
    off = c * 12;
    func_021BB840(q + off, c, y, 0);
    func_021BB848(q + off, x, d);
}
