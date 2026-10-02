/*
 * function: func_021F3A88
 * address:  0x021F3A88
 * packet:   pkt_ov038_021F3A88
 * region:   ov038
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0201210C 0x0201210C thumb
 *   func_021897BC 0x021897BC thumb
 *   func_02188CB4 0x02188CB4 thumb
 *   func_02188C80 0x02188C80 thumb
 *   func_020120F4 0x020120F4 thumb
 *   func_02012EC4 0x02012EC4 thumb
 *   func_0200B3A4 0x0200B3A4 thumb
 *   func_021A3050 0x021A3050 thumb ov021
 *   func_021F3A08 0x021F3A08 thumb ov038
 *   func_020122C0 0x020122C0 thumb
 *   func_021F3B3C 0x021F3B3C thumb ov038
 *   func_021F407C 0x021F407C thumb ov038
 *   func_021F3F40 0x021F3F40 thumb ov038
 */

extern void *func_0201210C(void *p);
extern unsigned char *func_021897BC(void *, int);
extern void *func_02188CB4(unsigned char *p);
extern int func_02188C80(void *);
extern int func_020120F4(int);
extern int func_02012EC4(int);
extern int *func_0200B3A4(int, int);
extern int func_021A3050(int);
extern int func_021F3A08(int *, int, int, int *, int *);
extern int func_020122C0(int, int, void *, int);
extern void func_021F3B3C(void);
extern void func_021F407C(void);
extern void func_021F3F40(void);

int func_021F3A88(int a0, int a1, int a2)
{
    int o1;
    int o2;
    int r6; /* int-typed on purpose: pointer local changes codegen */
    int r7;
    unsigned char *r4;

    r6 = (int)func_0201210C((void *)a0);
    r4 = func_021897BC((void *)r6, 1);
    r6 = (int)func_02188CB4((void *)r6);
    r7 = (int)func_0200B3A4(func_02012EC4(func_020120F4(func_02188C80(func_0201210C((void *)a0)))), 6);
    r6 = func_021A3050(r6);
    if (r6 != 0 && r6 != 1)
        return 0;
    r7 = func_021F3A08((int *)r7, a1, a2, &o1, &o2);
    if (r7 < 7) {
        if (o2 != 0) {
            if (o1 == 1)
                func_020122C0(a0, 0, func_021F3B3C, 0);
            else
                func_020122C0(a0, 0, func_021F407C, 0);
        } else {
            func_020122C0(a0, 0, func_021F3F40, 0);
        }
    } else {
        return 0;
    }
    r4[5] = 0;
    r4[7] = 0;
    r4[6] = r6;
    r4[3] = r7;
    *(int *)(r4 + 0x14) = 0;
    *(int *)(r4 + 0x18) = 0;
    *(int *)(r4 + 0x1c) = 0;
}
