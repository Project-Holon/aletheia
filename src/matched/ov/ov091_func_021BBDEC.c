/*
 * function: func_021BBDEC
 * address:  0x021BBDEC
 * packet:   pkt_ov091_021BBDEC
 * region:   ov091
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_02045EC0  0x02045EC0  arm
 *   func_02027FEC  0x02027FEC  thumb
 *   func_02045808  0x02045808  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;

typedef struct {
    int a;
    short b;
    int flag;
} S;

extern int func_02045EC0(int, int);
extern int func_02027FEC(int, void *, int, int, u8, u16);
extern void func_02045808(int);

int func_021BBDEC(int p, int unused, int id, int r3, u8 a4, int a5)
{
    S s;
    int r;
    s.a = func_02045EC0(*(int *)(p + 0x134), id);
    s.b = 0x39e3;
    if (a5 == 0) {
        s.flag = 0;
    } else {
        s.flag = 1;
    }
    r = func_02027FEC(*(int *)(p + 0x254), &s, r3, a4, 10, *(u16 *)p);
    func_02045808(s.a);
    return r;
}
