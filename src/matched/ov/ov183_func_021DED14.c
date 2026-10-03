/*
 * function: func_021DED14
 * address: 0x021DED14
 * packet: pkt_ov183_021DED14
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021FE784 0x021FE784 thumb ov186
 *   func_021FE7B0 0x021FE7B0 thumb ov186
 *   func_021FD73C 0x021FD73C thumb ov186
 *   func_021DEDB4 0x021DEDB4 thumb ov183
 */
extern void func_021FE784(void *, int, int, int);
extern int func_021FE7B0(int *);
extern void func_021FD73C(int *, int);
extern void func_021DEDB4(int *task, int *state, char *p);
void func_021DED14(int *a, int *state, char *p)
{
    switch (*state) {
    case 0:
        func_021FE784(*(void **)(*(char **)(p + 0x108) + 8), 2, 3, 0);
        *state = 1;
        break;
    case 1:
        if (func_021FE7B0(*(int **)(*(char **)(p + 0x108) + 8)) != 0) *state = 2;
        break;
    case 2:
        func_021FD73C(a, (int)func_021DEDB4);
        break;
    }
}
