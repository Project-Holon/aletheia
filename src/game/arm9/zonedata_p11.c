/*
 * file:     zonedata_p11.c
 * unit:     yes
 * function: func_0201433C, func_02014368
 * address:  0x0201433C
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 */
typedef unsigned short u16;

extern unsigned char *func_02014388(char *a0, unsigned int a1);
void func_0201433C(char *a0, int a1);
void func_02014368(char *a0, int a1, int a2);


void func_0201433C(char *a0, int a1)
{
    unsigned char *p = func_02014388(a0, a1);

    if (p != 0)
        *p &= 0xff ^ (1 << (a1 % 8));
}


void func_02014368(char *a0, int a1, int a2)
{
    int i;

    for (i = a1; i <= a2; i++)
        func_0201433C(a0, (u16)i);
}
