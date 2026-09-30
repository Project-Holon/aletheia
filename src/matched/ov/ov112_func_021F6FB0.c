/*
 * function: func_021F6FB0
 * address: 0x021F6FB0
 * packet: pkt_ov112_021F6FB0
 * region: ov112
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: two-byte zero padding before 021F7048.
 * symbols:
 *   func_021F7048 0x021F7048 thumb ov112
 *   func_02046DB8 0x02046DB8 arm
 *   func_02046FF8 0x02046FF8 arm
 *   func_02047400 0x02047400 arm
 *   func_02047564 0x02047564 arm
 *   func_0204767C 0x0204767C arm
 *   func_020477A4 0x020477A4 arm
 */
typedef unsigned char u8;
typedef struct { int pad[7]; int single; int a[3]; int b; int c[3]; int d; } Cleanup;
extern void func_021F7048(Cleanup *);
extern int func_02046DB8(int, char *);
extern int func_02046FF8(int);
extern int func_02047400(int, int, int);
extern int func_02047564(int, int, int);
extern int func_0204767C(int, int *, int);
extern void func_020477A4(int, int);
void func_021F6FB0(Cleanup *p, char *q) {
    u8 i, j;
    if (p->single != 0) func_021F7048(p);
    p->single = func_02046DB8(0x2f, q + 0x1e);
    p->a[0] = func_02046DB8(0x2f, q + 0x24);
    p->a[1] = func_02046DB8(0x2f, q + 0x2e);
    p->a[2] = func_02046DB8(0x2f, q + 0x29);
    if (func_02046FF8(p->single) != 0) {
        p->b = func_02047400(p->single, 0, p->single);
        for (i = 0; i < 3; i++) p->c[i] = func_02047564(p->b, p->a[i], 0);
        p->d = func_0204767C(p->b, p->c, 3);
        for (j = 0; j < 3; j++) func_020477A4(p->d, j);
    }
}
