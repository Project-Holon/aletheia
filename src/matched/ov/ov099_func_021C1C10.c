/*
 * function: func_021C1C10
 * address:  0x021C1C10
 * packet:   pkt_ov099_021BF2C4
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020362DC  0x020362DC  arm
 *   func_0203630C  0x0203630C  arm
 *   func_021B63D0  0x021B63D0  thumb  ov067
 *   func_021B6448  0x021B6448  thumb  ov067
 */
typedef unsigned char u8;

typedef struct {
    char pad[0x8ef];
    u8 f8ef;                /* 0x8ef */
    char pad8f0[0xbc];
    void *f9ac;             /* 0x9ac */
} Work;

extern void func_021B63D0(void *p);
extern int func_021B6448(void *p);
extern int func_0203630C(void);
extern int func_020362DC(void);

int func_021C1C10(Work *w)
{
    if (w->f8ef == 3)
        return 0;
    if (w->f9ac != 0) {
        func_021B63D0(w->f9ac);
        if (func_021B6448(w->f9ac) == 1)
            return 1;
    }
    if ((func_0203630C() & 0xf0) || (func_020362DC() & 0x403))
        return 1;
    return 0;
}
