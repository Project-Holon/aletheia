/*
 * file:     eventdata_system_p29.c
 * unit:     yes
 * function: func_02163BAC, func_02163C04
 * address:  0x02163BAC
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0216D67C  0x0216D67C  thumb
 *   func_0216DD1C  0x0216DD1C  thumb
 *   func_02163AF0  0x02163AF0  thumb
 *   func_0216D83C  0x0216D83C  thumb
 *   func_0216D86C  0x0216D86C  thumb
 *   func_0216D804  0x0216D804  thumb
 *   func_0216D81C  0x0216D81C  thumb
 *   func_02163A08  0x02163A08  thumb
 */
struct Ctx;
struct Rec;
typedef unsigned int   u32;

typedef short s16;

extern void *func_0216D67C(void *a0);
extern int func_0216DD1C(struct Ctx *c, struct Rec **out, u32 *iter);
extern int func_02163AF0(int a, int b, int c, int d, int e, int f);
extern int func_0216D83C(void *p);
extern int func_0216D86C(void *p);
extern int func_0216D804(void *p);
extern int func_0216D81C(void *p);
extern void func_02163A08(int a, int b, int c, s16 *r);
int func_02163BAC(int a, int b, int c, int d);
int func_02163C04(int a, int x, int y, int flag);


int func_02163BAC(int a, int b, int c, int d)
{
    int v;
    int cur;
    int it;

    v = 0;
    it = (int)func_0216D67C((void *)a);
    while (func_0216DD1C((struct Ctx *)it, (struct Rec **)(&cur), (u32 *)(&v)) == 1) {
        if (a != cur) {
            if (func_02163AF0(a, cur, b, c, d, 1) == 1)
                return 1;
        }
    }
    return 0;
}


int func_02163C04(int a, int x, int y, int flag)
{
    s16 r[4];
    int t;

    t = func_0216D83C((void *)a);
    func_02163A08(a, t, func_0216D86C((void *)a), r);
    if (r[0] <= x && r[2] >= x && r[1] <= y && r[3] >= y)
        return 1;
    if (flag == 1) {
        t = func_0216D804((void *)a);
        func_02163A08(a, t, func_0216D81C((void *)a), r);
        if (r[0] <= x && r[2] >= x && r[1] <= y && r[3] >= y)
            return 1;
    }
    return 0;
}
