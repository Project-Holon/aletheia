/*
 * function: func_021E8A00
 * address:  0x021E8A00
 * packet:   pkt_ov177_021E8A00
 * region:   ov177
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02045770  0x02045770  arm
 *   func_0201C6C4  0x0201C6C4  thumb
 *   func_02045334  0x02045334  arm
 *   func_020200CC  0x020200CC  thumb
 */

typedef struct {
    char          pad0[4];
    int           f4;
    int           f8;
    unsigned char fc;
    char          pad1[3];
    int           f10;
    int           f14;
    int           f18;
} S;

extern int  func_02045770(int);
extern int  func_0201C6C4(int, int);
extern void func_02045334(int);
extern int  func_020200CC(int);

int func_021E8A00(S *p)
{
    int r4 = p->f4;
    int r;

    if (p->fc != 0) {
        if (func_0201C6C4(r4, func_02045770(p->f8)) == 0) {
            func_02045334(p->f8);
            p->fc = 0;
        }
    }
    r = func_020200CC(p->f10);
    if (r == -2) {
        r = p->f18;
    }
    return r;
}
