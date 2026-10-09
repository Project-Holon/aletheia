/*
 * file:     dwc_rap_p02.c
 * unit:     yes
 * function: func_02155244, func_02155264, func_02155280
 * address:  0x02155244
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02156690  0x02156690  thumb  ov009
 *   func_02156730  0x02156730  thumb  ov009
 *   func_02155B14 0x02155B14 thumb ov009
 *   func_02155648  0x02155648  thumb  ov009
 */
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed short   s16;

typedef signed char    s8;

extern int func_02155B14(int, int);
extern void func_02155648(int a, int b);
int func_02155244(int x);
int func_02155264(int a, int b, int c, void (*cb)(int));
int func_02155280(int a);



int func_02155244(int x)
{
    int func_02156690(int);
    int func_02156730(void);
    int t;
    if (x == 0) t = 1;
    else t = 0;
    if (func_02156690(t)) {
        func_02156730();
        return 1;
    }
    return 0;
}


int func_02155264(int a, int b, int c, void (*cb)(int))
{
    if (func_02155B14(a, b)) {
        if (cb) cb(1);
        return 1;
    }
    return 0;
}


/*
 * Calls func_02155648 on the argument twice and returns 1.
 */
int func_02155280(int a)
{
    func_02155648(a, a);

    return 1;
}
