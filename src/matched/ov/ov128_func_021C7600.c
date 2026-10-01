/*
 * function: func_021C7600
 * address: 0x021C7600
 * packet: pkt_ov128_021C7600
 * region: ov128
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02035C60 0x02035C60 arm
 *   func_0203630C 0x0203630C arm
 *   func_020362DC 0x020362DC arm
 */
extern int func_0201CE30(void *);
extern void func_0201CE5C(void *, int);
extern void func_0201CE38(void *);
extern void func_0201CE48(void *);
extern int func_02035C60(void);
extern int func_0203630C(void);
extern int func_020362DC(void);
extern void func_020061E4(int);
int func_021C7600(void *p, int *q)
{
    switch (func_0201CE30(p)) {
    case 0:
        if (func_02035C60() == 1 || (func_0203630C() & 3)) func_0201CE5C(p, 0);
        *q = 0;
        break;
    case 1:
        if (*q == 0 && (func_02035C60() == 1 || (func_020362DC() & 3))) {
            func_020061E4(0x547);
            func_0201CE38(p);
            *q = 1;
        }
        break;
    case 2:
        func_0201CE48(p);
        *q = 0;
        return 0;
    }
    return 1;
}
