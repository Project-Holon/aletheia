/*
 * function: func_021DED64
 * address: 0x021DED64
 * packet: pkt_ov183_021DED64
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021FE784 0x021FE784 thumb ov186
 *   func_021FE7B0 0x021FE7B0 thumb ov186
 *   func_021FD73C 0x021FD73C thumb ov186
 *   func_021DECB0 0x021DECB0 thumb ov183
 */
extern void func_021FE784(int *, int, int, int);
extern int func_021FE7B0(int *);
extern void func_021FD73C(int *, int);
extern void func_021DECB0(void *a, int b, char *p);
void func_021DED64(int *p, int *state, char *q)
{
    switch (*state) {
    case 0:
        func_021FE784(*(int **)(*(char **)(q + 0x108) + 8), 2, 3, 1);
        *state = 1;
        break;
    case 1:
        if (func_021FE7B0(*(int **)(*(char **)(q + 0x108) + 8)) != 0) *state = 2;
        break;
    case 2:
        func_021FD73C(p, (int)func_021DECB0);
        break;
    }
}
