/*
 * function: func_021F1080
 * address:  0x021F1080
 * packet:   pkt_ov032_021F1080
 * region:   ov032
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021F1080  0x021F1080  thumb
 *   func_02026D48  0x02026D48  thumb
 *   func_021F2144  0x021F2144  thumb  ov032
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u16 func_02026D48(u16 v);
extern void func_021F2144(char *p, char *q, int r, int s, int t);

void func_021F1080(char *p, char *q, int r, int t)
{
    u8 c;

    c = (func_02026D48(*(u16 *)(q + 6)) >= 0x2a30) ? 1 : 0;
    if (c == *(u8 *)(q + 5) && r == 0) {
        return;
    }
    *(u8 *)(q + 5) = c;
    if (c != 0) {
        func_021F2144(p, q, *(int *)(q + 0x24), 0xca0, t);
    } else {
        func_021F2144(p, q, *(int *)(q + 0x24), 0x3c60, t);
    }
}
