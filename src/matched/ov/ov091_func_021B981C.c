/*
 * function: func_021B981C
 * address: 0x021B981C
 * packet: pkt_ov091_021B981C
 * region: ov091
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021BB1A0 0x021BB1A0 thumb ov091
 *   func_021BB0C4 0x021BB0C4 thumb ov091
 *   func_021BB200 0x021BB200 thumb ov091
 *   func_021B999C 0x021B999C thumb ov091
 *   func_0201AB8C 0x0201AB8C thumb
 *   func_0201AB28 0x0201AB28 thumb
 *   func_020061E4 0x020061E4 thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;
extern void func_021BB1A0(int, u8 *, int);
extern void func_021BB0C4(u8 *, u8 *, int);
extern void func_021BB200(u8 *, u8 *, int, int);
extern void func_021B999C(u8 *);
extern void func_0201AB8C(int, int, int, u16);
extern int func_0201AB28(int, int);
extern void func_020061E4(unsigned int);
#define W(o) (*(int *)(p + (o)))
#define ROW(i) (*(u8 **)(p + (i) * 4 + 0x160))
void func_021B981C(u8 *p)
{
    switch (p[0xe]) {
    case 3:
        func_021BB1A0((int)p, ROW(W(0x2c)), p[0x104]);
        func_021BB1A0((int)p, ROW(W(0x30)), p[0x104]);
        p[0x104]++;
        func_021BB0C4(p, ROW(W(0x2c)), p[0x104]);
        func_021BB0C4(p, ROW(W(0x30)), p[0x104]);
        if (p[0x104] >= 16) {
            func_0201AB8C(*(int *)W(0x280), W(0x2c), W(0x30), *(u16 *)p);
            func_021BB200(p, ROW(W(0x2c)), func_0201AB28(*(int *)W(0x280), W(0x2c)), p[0x104]);
            func_021BB200(p, ROW(W(0x30)), func_0201AB28(*(int *)W(0x280), W(0x30)), p[0x104]);
            p[0xe] = 4;
            func_020061E4(0x642);
        }
        break;
    case 4:
        func_021BB1A0((int)p, ROW(W(0x2c)), p[0x104]);
        func_021BB1A0((int)p, ROW(W(0x30)), p[0x104]);
        p[0x104]--;
        func_021BB0C4(p, ROW(W(0x2c)), p[0x104]);
        func_021BB0C4(p, ROW(W(0x30)), p[0x104]);
        if (p[0x104] == 0)
            func_021B999C(p);
        break;
    }
}
