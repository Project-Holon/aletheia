/*
 * function: func_0217DBE0,func_0217DC20
 * unit: yes
 * address: 0x0217DBE0
 * packet: pkt_ov176_0217DBE0
 * region: ov176
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021E8AA8 0x021E8AA8 thumb ov177
 *   func_0217DFD0 0x0217DFD0 thumb ov176
 *   func_0217DFE4 0x0217DFE4 thumb ov176
 *   func_021E8AA0 0x021E8AA0 thumb ov177
 *   func_0217DC20 0x0217DC20 thumb ov176
 */
extern void func_0217DFD0(int *, int, int);
extern int func_0217DFE4(int *);
extern void func_021E8AA0(int *p, int v);
extern void func_0217DC20(int);
extern void func_021E8AA8(int);
void func_0217DBE0(int a, int *state, int *p)
{
    switch (*state) {
    case 0:
        func_0217DFD0(p, 0x6F, 1);
        *state = 1;
        break;
    case 1:
        if (func_0217DFE4(p))
            *state = 2;
        break;
    case 2:
        func_021E8AA0((int *)a, (int)func_0217DC20);
        break;
    }
}
void func_0217DC20(int a) { func_021E8AA8(a); }
