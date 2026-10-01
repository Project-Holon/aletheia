/*
 * function: func_021B7CF0
 * address: 0x021B7CF0
 * packet: pkt_ov180_021B7CF0
 * region: ov180
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021B7C78 0x021B7C78 thumb ov180
 *   func_021B7750 0x021B7750 thumb ov180
 *   func_021B75A4 0x021B75A4 thumb ov180
 *   func_021B746C 0x021B746C thumb ov180
 *   func_021B7814 0x021B7814 thumb ov180
 *   d_021B81BC 0x021B81BC data a4
 *   d_021B81D4 0x021B81D4 data a4
 *   d_021B81A4 0x021B81A4 data a4
 */
typedef struct { unsigned short a, b; unsigned c; int d, e, f; unsigned short g, h; } S24;
extern S24 d_021B81BC, d_021B81D4, d_021B81A4;
extern void func_021B7C78(char *);
extern void func_021B7750(char *);
extern int func_021B75A4(char *, S24 *);
extern void func_021B746C(int *, int, int);
extern void func_021B7814(char *);
void func_021B7CF0(char *p)
{
    func_021B7C78(p);
    func_021B7750(p);
    *(int *)(p + 0x9050) = func_021B75A4(p, &d_021B81BC);
    *(int *)(p + 0x9054) = func_021B75A4(p, &d_021B81D4);
    *(int *)(p + 0x9058) = func_021B75A4(p, &d_021B81A4);
    func_021B746C((int *)p, 4, 0);
    func_021B7814(p);
}
