/*
 * file:     btlv_core_p05.c
 * unit:     yes
 * function: func_021E8D04, func_021E8D0C, func_021E8D24, func_021E8D48, func_021E8DA8
 * address:  0x021E8D04
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021E8CFC  0x021E8CFC  thumb  ov093
 */
typedef unsigned char u8;

extern unsigned char func_021E8CFC(int x);
int func_021E8D04(int x);
void func_021E8D0C(int x, unsigned char *a, unsigned char *b);
int func_021E8D24(int x, int k);
int func_021E8D48(int a, int b);
int func_021E8DA8(int x);

int func_021E8D04(int x)
{
    return (unsigned char)x;
}


void func_021E8D0C(int x, unsigned char *a, unsigned char *b)
{
    *a = func_021E8CFC(x);
    *b = func_021E8D04(x);
}


int func_021E8D24(int x, int k)
{
    if (k == func_021E8CFC(x)) {
        return 1;
    }
    if (k == func_021E8D04(x)) {
        return 1;
    }
    return 0;
}


int func_021E8D48(int a, int b)
{
    if (func_021E8CFC(a) == func_021E8CFC(b)) return 1;
    if (func_021E8CFC(a) == func_021E8D04(b)) return 1;
    if (func_021E8D04(a) == func_021E8CFC(b)) return 1;
    if (func_021E8D04(a) == func_021E8D04(b)) return 1;
    return 0;
}


int func_021E8DA8(int x)
{
    if (func_021E8CFC(x) == func_021E8D04(x)) {
        return 1;
    }
    return 0;
}
