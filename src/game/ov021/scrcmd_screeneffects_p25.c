/*
 * file:     scrcmd_screeneffects_p25.c
 * unit:     yes
 * function: func_021B0D14, func_021B0D74
 * address:  0x021B0D14
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
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_021B0BAC  0x021B0BAC  thumb
 *   func_020113D0  0x020113D0  thumb
 *   func_021B0CEC  0x021B0CEC  thumb
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_02158F90  0x02158F90  thumb  ov010
 *   func_0216D588  0x0216D588  thumb  ov010
 */
extern unsigned int func_02159B10(void *, void *);
extern int func_021B0BAC(int, int, int, int, int, int);
extern void func_020113D0(char *p, int val);
extern int func_021B0CEC(int, int);
extern void *func_0215A5F4(void *p);
extern void *func_02158F90(void *);
extern unsigned short func_0216D588(void *);
int func_021B0D14(int a, int b);
int func_021B0D74(int a, int b);


int func_021B0D14(int a, int b)
{
    int v0, v1, v2, v3, v4;
    v0 = func_02159B10((void *)a, (void *)b);
    v1 = func_02159B10((void *)a, (void *)b);
    v2 = func_02159B10((void *)a, (void *)b);
    v3 = func_02159B10((void *)a, (void *)b);
    v4 = func_02159B10((void *)a, (void *)b);
    if (func_021B0BAC(b, v2, v0, v1, v3, v4) == 1) {
        func_020113D0((char *)a, (int)func_021B0CEC);
        return 1;
    }
    return 0;
}


int func_021B0D74(int a, int b)
{
    void *o;
    int v0, v1, v2, v3;
    unsigned char f;
    o = func_02158F90(func_0215A5F4((void *)b));
    v0 = func_02159B10((void *)a, (void *)b);
    v1 = func_02159B10((void *)a, (void *)b);
    v2 = func_02159B10((void *)a, (void *)b);
    v3 = func_02159B10((void *)a, (void *)b);
    if (o == 0) {
        return 1;
    }
    f = func_0216D588(o);
    if (func_021B0BAC(b, f, v0, v1, v2, v3) == 1) {
        func_020113D0((char *)a, (int)func_021B0CEC);
        return 1;
    }
    return 0;
}
