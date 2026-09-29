/*
 * function: func_0216C8CC
 * address:  0x0216C8CC
 * packet:   pkt_ov010_0216C8CC
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 *
 * blockers: d_021F03C4 and d_021EFDAC data pointers outside ov010 window; no witness
 * (tried ov006/008/011/187/199/ov010 hints)
 *
 * symbols:
 *   func_02031330  0x02031330  arm
 *   func_02034AC4  0x02034AC4  arm
 *   func_0203A574  0x0203A574  arm
 *   func_020399A8  0x020399A8  arm
 *   func_0203D594  0x0203D594  arm
 *   func_0200FB24  0x0200FB24  thumb
 *   func_0203D5A0  0x0203D5A0  arm
 *   func_02031348  0x02031348  arm
 *   func_0203A5E4  0x0203A5E4  arm
 *   func_02034A5C  0x02034A5C  arm
 *   id_0000005D    0x0000005D  data  a1
 *   d_021F03C4     0x021F03C4  data  a4
 *   d_021EFDAC     0x021EFDAC  data  a4
 */

extern int func_02031330(int);
extern void func_02034AC4(char *);
extern void func_0203A574(int, char *, int, int);
extern int func_020399A8(void);
extern void func_0203D594(int, int);
extern int func_0200FB24(void);
extern int func_0203D5A0(int, int);
extern void func_02031348(int, int, char *, int);
extern void func_0203A5E4(int);
extern void func_02034A5C(char *);
extern char id_0000005D[];
extern char d_021F03C4[];
extern char d_021EFDAC[];

int func_0216C8CC(int a, int *st, int *o, int *x)
{
    int r = func_02031330(x[0]);
    switch (*st) {
    case 0:
        func_02034AC4(id_0000005D);
        func_0203A574(0x100, d_021F03C4, 9, 0);
        func_0203D594(func_020399A8(), 0xc8);
        *st = 1;
        break;
    case 1:
        if (func_0200FB24() != 0) {
            *st = 4;
            break;
        }
        if (func_0203D5A0(func_020399A8(), 0xc8) == 0)
            break;
        *st = 2;
        break;
    case 2:
        func_02031348(x[0], ~0, d_021EFDAC, o[1]);
        *st = 3;
        break;
    case 3:
        if (r == 1)
            break;
        *st = 4;
        break;
    case 4:
        func_0203A5E4(0x100);
        func_02034A5C(id_0000005D);
        *st = 5;
        break;
    case 5:
        return 1;
    }
    return 0;
}
