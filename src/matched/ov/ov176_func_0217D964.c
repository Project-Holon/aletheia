/*
 * function: func_0217D964
 * address: 0x0217D964
 * packet: pkt_ov176_0217D964
 * region: ov176
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0217DC28 0x0217DC28 thumb ov176
 *   func_0217DEA4 0x0217DEA4 thumb ov176
 *   func_0217DE8C 0x0217DE8C thumb ov176
 *   func_020362DC 0x020362DC arm
 *   func_0217E000 0x0217E000 thumb ov176
 *   func_0217DFF0 0x0217DFF0 thumb ov176
 *   func_0217DFD0 0x0217DFD0 thumb ov176
 *   func_0217DFE4 0x0217DFE4 thumb ov176
 *   func_0217DEDC 0x0217DEDC thumb ov176
 *   func_0217DFBC 0x0217DFBC thumb ov176
 *   func_0217DFA8 0x0217DFA8 thumb ov176
 *   func_0217DE98 0x0217DE98 thumb ov176
 *   func_021E8AA0 0x021E8AA0 thumb ov177
 *   func_0217DC20 0x0217DC20 thumb ov176
 */
extern void func_0217DC28(int *);
extern void func_0217DEA4(int *, int);
extern int func_0217DE8C(int *);
extern int func_020362DC(void);
extern void func_0217E000(int *);
extern int func_0217DFF0(int, int);
extern void func_0217DFD0(int *, int, int);
extern int func_0217DFE4(int *);
extern void func_0217DEDC(char *, int);
extern int func_0217DFBC(int *);
extern void func_0217DFA8(int *);
extern int func_0217DE98(int *);
extern void func_021E8AA0(int *, int);
extern void func_0217DC20(void);
void func_0217D964(int *a, int *state, int *p)
{
    int result;
    switch (*state) {
    case 0: func_0217DC28(p); func_0217DEA4(p, 1); *state = 1; break;
    case 1: if (func_0217DE8C(p)) *state = 2; break;
    case 2: if (func_020362DC() & 3) *state = 3; break;
    case 3: func_0217E000(p); func_0217DFF0((int)p, 1); func_0217DFD0(p, 0x6D, 1); *state = 4; break;
    case 4: if (func_0217DFE4(p)) *state = 5; break;
    case 5: func_0217DEDC((char *)p, 1); *state = 6; break;
    case 6:
        result = func_0217DFBC(p);
        if (result != -1) {
            func_0217DFA8(p);
            if (result == 0) *state = 7;
        }
        break;
    case 7: if (func_0217DE98(p)) *state = 8; break;
    case 8: func_021E8AA0(a, (int)func_0217DC20); break;
    }
}
