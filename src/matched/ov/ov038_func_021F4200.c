/*
 * function: func_021F4200
 * address:  0x021F4200
 * packet:   pkt_ov038_021F4200
 * region:   ov038
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * note:     the case-0 byte must be held in a u8 (or u16) local: an int local
 *           swaps the 0x0201210C result and the 0x021897BC pointer between r4
 *           and r5.  func_020124E4/func_0201210C are argless as in the twin
 *           ov045_func_021F39B8.  func_021BE700/func_021BE674 take their
 *           fourth argument as u16 (the caller truncates it before the bl).
 *           func_021BE674's third parameter must be `int` here, as for
 *           func_021BE700: its own file's `unsigned int j` brings the r4/r5
 *           swap back even with the u8 local.
 *
 * symbols:
 *   func_020124E4 0x020124E4 thumb
 *   func_0201210C 0x0201210C thumb
 *   func_02188D2C 0x02188D2C thumb ov021
 *   func_021897BC 0x021897BC thumb
 *   func_02188C80 0x02188C80 thumb
 *   func_020120F4 0x020120F4 thumb
 *   func_02012EC4 0x02012EC4 thumb
 *   func_0200B3A4 0x0200B3A4 thumb
 *   func_0200B3A8 0x0200B3A8 thumb
 *   func_021BE700 0x021BE700 thumb ov021
 *   func_021BE674 0x021BE674 thumb ov021
 *   func_021BE6B0 0x021BE6B0 thumb ov021
 *   func_021BE6BC 0x021BE6BC thumb ov021
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void *func_020124E4(void *p);
extern void *func_0201210C(void *p);
extern int func_02188D2C(int *p);
extern int *func_021897BC(char *p, int idx);
extern u32 func_02188C80(u8 *p);
extern unsigned int func_020120F4(unsigned int);
extern unsigned int func_02012EC4(unsigned int);
extern int *func_0200B3A4(unsigned int, unsigned int);
extern unsigned short *func_0200B3A8(unsigned int, unsigned int);
extern void func_021BE700(void *p, int i, int j, u16 k, int flag);
extern void *func_021BE674(char *base, int i, int j, u16 k);
extern int func_021BE6B0(void *s, int b);
extern int func_021BE6BC(int *p);

int func_021F4200(int a0, int *a1)
{
    void *sys;
    int h;
    u8 *s;
    int *p;
    unsigned int t;
    unsigned short *q;
    int i;
    u8 c;

    sys = func_0201210C(func_020124E4((void *)a0));
    h = func_02188D2C(sys);
    s = (u8 *)func_021897BC(sys, 1);
    t = func_02012EC4(func_020120F4(func_02188C80(sys)));
    p = func_0200B3A4(t, 6);
    q = func_0200B3A8(t, 6);
    switch (*a1) {
    case 0:
        c = *s;
        for (i = 0; i < 2; i++) {
            func_021BE700((void *)h, 0, c, i, 1);
            func_021BE6B0(func_021BE674((char *)h, 0, c, i), 0);
        }
        *a1 = *a1 + 1;
        break;
    case 1:
        if (func_021BE6BC(func_021BE674((char *)h, 0, *s, 0))) {
            p[*s] = 1;
            q[*s] = 1;
            return 1;
        }
        break;
    }
    return 0;
}
