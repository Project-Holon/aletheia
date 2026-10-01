/*
 * function: func_021DF0DC
 * address: 0x021DF0DC
 * packet: pkt_ov183_021DF0DC
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021FD12C 0x021FD12C thumb ov186
 *   func_021FD170 0x021FD170 thumb ov186
 *   func_021FD860 0x021FD860 thumb ov186
 *   func_021FE784 0x021FE784 thumb ov186
 *   func_021FE7B0 0x021FE7B0 thumb ov186
 *   func_021FD73C 0x021FD73C thumb ov186
 *   func_021DEE7C 0x021DEE7C thumb ov183
 */
typedef unsigned short u16;
extern int func_021FD12C(int, int, unsigned int);
extern void func_021FD170(int, int, int);
extern void func_021FD860(int, int, int *);
extern void func_021FE784(int *, int, int, int);
extern int func_021FE7B0(int *);
extern void func_021FD73C(int *, int);
extern void func_021DEE7C(void);
void func_021DF0DC(int *p, int *state, char *q)
{
    int args[2];
    switch (*state) {
    case 0:
        if (*(int *)(q + 0x24) == 0) {
            *(int *)(q + 0x24) = func_021FD12C(*(int *)(*(char **)(q + 0x108) + 0x10), *(int *)(q + 0x14), *(u16 *)(q + 0x18));
        }
        if (**(int **)(q + 0x108) == 3) {
            func_021FD170(*(int *)(q + 0x24), *(int *)(*(char **)(q + 0x108) + 0x10), 0x14B);
        } else {
            func_021FD170(*(int *)(q + 0x24), *(int *)(*(char **)(q + 0x108) + 0x10), 0x13E);
        }
        args[0] = 0x80;
        args[1] = 0x60;
        func_021FD860(*(int *)(q + 0x1C), 4, args);
        *state = 1;
        break;
    case 1:
        func_021FE784(*(int **)(*(char **)(q + 0x108) + 8), 2, 3, 0);
        *state = 2;
        break;
    case 2:
        if (func_021FE7B0(*(int **)(*(char **)(q + 0x108) + 8)) != 0) *state = 3;
        break;
    case 3:
        func_021FD73C(p, (int)func_021DEE7C);
        break;
    }
}
