/*
 * file:     weather_task_p62.c
 * unit:     yes
 * function: func_021A55DC, func_021A55FC, func_021A5610
 * address:  0x021A55DC
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
 *   func_021AB404  0x021AB404  thumb  ov021
 *   func_021AB410  0x021AB410  thumb  ov021
 *   func_021A5788  0x021A5788  thumb  ov021
 *   func_021AB0F0  0x021AB0F0  thumb  ov021
 */
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed short   s16;

typedef signed char    s8;

int func_021AB404(int a);
int func_021AB410(int a);
void func_021A5788(u32 *p, int k, int *out);
u16 func_021AB0F0(u32 attr);
int func_021A55DC(int a);
int func_021A55FC(int a);
int func_021A5610(u32 *p);


int func_021A55DC(int a)
{
    if (func_021AB404(a) == 1 || func_021AB410(a) == 1)
        return 1;
    return 0;
}


/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_021A55FC(int a)
{
if (func_021AB404(a) == 1) {
    return 1;
}
return 0;
}


int func_021A5610(u32 *p)
{
    int x;

    func_021A5788(p, 9, &x);
    if (func_021A55FC(func_021AB0F0(x)) == 1)
        return 1;
    return 0;
}
