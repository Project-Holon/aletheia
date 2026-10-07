/*
 * file:     field_effect_p24.c
 * unit:     yes
 * function: func_021AAFFC, func_021AB018
 * address:  0x021AAFFC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021AC154  0x021AC154  thumb
 *   func_02005728  0x02005728  thumb
 *   _u32_div_f     0x0209C2B0  arm
 *   d_021D8E8A     0x021D8E8A  data  a2
 */
typedef struct {
    char pad[0x5b4];
    int f5b4;
} D;

extern void func_021AC154(int a);
extern unsigned long func_02005728(unsigned long v);
void func_021AAFFC(D *d);
unsigned short func_021AB018(void);
extern unsigned short d_021D8E8A[];


void func_021AAFFC(D *d)
{
    if (d->f5b4 != 0) {
        func_021AC154(d->f5b4);
        d->f5b4 = 0;
    }
}


unsigned short func_021AB018(void)
{
    unsigned short r = func_02005728(1000);

    if (r < 100)
        return d_021D8E8A[(unsigned short)(func_02005728(1000) / 100)];
    if (r < 950)
        return (unsigned short)((unsigned short)(func_02005728(1700) / 100) + 548);
    return 229;
}
