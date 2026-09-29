/*
 * function: func_021C0780
 * address:  0x021C0780
 * packet:   pkt_ov021_021C0780
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020124E4  0x020124E4  thumb
 *   func_02012138  0x02012138  thumb
 *   func_0203CD98  0x0203CD98  arm
 *   func_0203CEAC  0x0203CEAC  arm
 *   func_0203CDBC  0x0203CDBC  arm
 *   func_0200FBA0  0x0200FBA0  thumb
 *   func_02012124  0x02012124  thumb
 *   func_020121CC  0x020121CC  thumb
 *   func_02026474  0x02026474  thumb
 *   func_02026454  0x02026454  thumb
 *   func_02164FC4  0x02164FC4  thumb  ov010
 */

typedef unsigned char  u8;
typedef unsigned int   u32;

extern u32 func_020124E4(void);
extern u32 func_02012138(u32 a);
extern int func_0203CD98(void);
extern void func_0203CEAC(int a);
extern int func_0203CDBC(void);
extern void func_0200FBA0(void);
extern void func_02012124(u32 a, u32 b);
extern int func_020121CC(u32 a);
extern u32 func_02026474(u32 a);
extern int func_02026454(u32 a);
extern void func_02164FC4(u32 a);

int func_021C0780(u32 a, int *st)
{
    u32 x;
    u32 y;
    u32 z;

    x = func_020124E4();
    y = func_02012138(x);
    switch (*st) {
    case 0:
        if (func_0203CD98()) {
            func_0203CEAC(0);
        }
        *st = *st + 1;
        break;
    case 1:
        if (func_0203CDBC() == 1) {
            func_0200FBA0();
            func_02012124(x, 0);
            *st = *st + 1;
        }
        break;
    case 2:
        if (func_020121CC(x) == 1) {
            *st = *st + 1;
            break;
        }
        return 1;
    case 3:
        z = func_02026474(y);
        if (z && func_02026454(y)) {
            func_02164FC4(z);
            return 1;
        }
        break;
    }
    return 0;
}
