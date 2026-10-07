/*
 * file:     unit_0219B508_p05.c
 * unit:     yes
 * function: func_0219BB3C, func_0219BB48
 * address:  0x0219BB3C
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
 *   func_0216D69C  0x0216D69C  thumb
 *   func_0216DA50  0x0216DA50  thumb  ov010
 *   func_0216DA7C  0x0216DA7C  thumb  ov010
 *   func_0219BCE4  0x0219BCE4  thumb  ov021
 *   func_0219BD30  0x0219BD30  thumb  ov021
 *   func_0216DA44  0x0216DA44  thumb  ov010
 */
struct Obj05999;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed short   s16;

typedef signed char    s8;

void *func_0216D69C(void);
extern void func_0216DA50(u8 *p);
extern void func_0216DA7C(u8 *p);
extern int func_0219BCE4(u32 a, u32 b);
extern int func_0219BD30(char *a, struct Obj05999 *b);
extern void func_0216DA44(u32);
void func_0219BB3C(void);
int func_0219BB48(char *a, u8 *s);


void func_0219BB3C(void)
{
    char *p = func_0216D69C();

    p[1] = 0;
}


int func_0219BB48(char *a, u8 *s)
{
    func_0216DA50((u8 *)a);
    func_0216DA7C((u8 *)a);
    if (func_0219BCE4((u32)a, (u32)s) == 1 && func_0219BD30(a, (struct Obj05999 *)s) == 1) {
        func_0216DA44((u32)a);
        s[0]++;
        return 1;
    }
    return 0;
}
