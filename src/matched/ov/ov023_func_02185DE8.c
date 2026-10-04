/*
 * function: func_02185DE8
 * address:  0x02185DE8
 * packet:   pkt_ov023_02185DE8
 * region:   ov023
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   d_02186C34     0x02186C34  data  ov023  a4
 *   func_02185C38  0x02185C38  thumb  ov023
 *   func_02185DA8  0x02185DA8  thumb  ov023
 *   func_02045334  0x02045334  arm
 *   func_02045374  0x02045374  arm
 *   func_02045730  0x02045730  arm
 *   func_020409B4  0x020409B4  arm
 */

struct e6 {
    unsigned char b[4];
    unsigned char c : 3;
    unsigned char n : 3;
    unsigned char d : 2;
    unsigned char pad;
};

struct o4 {
    unsigned char x;
    unsigned char y;
    unsigned short n;
};

extern char d_02186C34[];
extern void func_02185C38(int a0, int a1, int x1, int y1, int *px, int *py, int c, int d);
extern void func_02185DA8(struct e6 *e, struct o4 *o);
struct Descriptor;
extern void func_02045334(struct Descriptor *p);
extern void func_02045374(char *p);
extern unsigned char func_02045730(char *p);
extern void func_020409B4(unsigned int index);

void func_02185DE8(char *p, struct e6 *e, struct o4 *o, int flag)
{
    int hit;
    int i;
    int x;
    int y;

    hit = 0;
    for (i = 0; i < 5; i++) {
        if (e[i].n == 2) {
            x = e[i].b[0] - 9;
            y = e[i].b[2] - 0x11;
            func_02185C38((int)p, (int)(d_02186C34 + e[i].d * 0xc0 + e[i].c * 0x18),
                          e[i].b[1] - 9, e[i].b[3] - 0x11, &x, &y, 1, o[i].n);
            hit = 1;
        }
    }
    if (hit && flag) {
        func_02045334((struct Descriptor *)p);
        func_02045374(p);
        func_020409B4(func_02045730(p));
    }
    func_02185DA8(e, o);
    for (i = 0; i < 5; i++)
        e[i].n = 0;
}
