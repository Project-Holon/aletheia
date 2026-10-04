/*
 * function: func_021B96D0
 * address:  0x021B96D0
 * packet:   pkt_ov099_021B96D0
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021C48E8  0x021C48E8  thumb  ov127
 *   func_021B9C9C  0x021B9C9C  thumb  ov099
 *   func_021B9C4C  0x021B9C4C  thumb  ov099
 *   func_021C5994  0x021C5994  thumb  ov127
 *   func_021C5A60  0x021C5A60  thumb  ov127
 *   func_021C571C  0x021C571C  thumb  ov127
 *   func_021B9CD0  0x021B9CD0  thumb  ov099
 *   func_021B9F84  0x021B9F84  thumb  ov099
 *   func_021B9BA8  0x021B9BA8  thumb  ov099
 *   func_021B97CC  0x021B97CC  thumb  ov099
 *   func_021B9FDC  0x021B9FDC  thumb  ov099
 *   func_021B9F48  0x021B9F48  thumb  ov099
 *   func_0203630C  0x0203630C  arm
 *   func_020362DC  0x020362DC  arm
 *   func_021B97F4  0x021B97F4  thumb  ov099
 *   func_021B9BC4  0x021B9BC4  thumb  ov099
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern void func_021C48E8(void *a);
extern void func_021B9C9C(char *p);
extern void func_021B9C4C(char *p);
extern void func_021C5994(void *p, void *q);
extern void func_021C5A60(char *p, void *q);
extern void func_021C571C(void *a);
extern void func_021B9CD0(char *p);
extern void func_021B9F84(char *p);
extern int func_021B9BA8(char *p);
extern void func_021B97CC(char *p);
extern int func_021B9FDC(char *p);
extern void func_021B9F48(char *p);
extern u32 func_0203630C(void);
extern u32 func_020362DC(void);
extern u8 func_021B97F4(char *p);
extern int func_021B9BC4(char *p);

int func_021B96D0(char *p)
{
    if (*(u32 *)0x02FFFC3C & 1) {
        func_021C48E8(*(void **)(p + 0x58C));
        func_021B9C9C(p);
        func_021B9C4C(p);
        func_021C5994(p + 0x594, **(void ***)(p + 0x570));
        func_021C5A60(*(char **)(p + 0x598), p + 0x594);
        func_021C571C(*(void **)(p + 0x590));
        func_021B9CD0(p);
        func_021B9F84(p);
    }
    if (func_021B9BA8(p) == 1) {
        func_021B97CC(p);
        if (func_021B9FDC(p) == 1) {
            func_021B9F48(p);
            if (func_0203630C() & 0x80)
                return 1;
        }
        if (func_020362DC() & 1) {
            if (func_021B97F4(p) != 0)
                return 2;
            if (func_021B9BC4(p) == 1)
                return 3;
        }
    }
    return 0;
}
