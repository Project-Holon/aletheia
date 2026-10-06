/*
 * function: func_021640B0
 * address:  0x021640B0
 * packet:   pkt_ov010_021640B0
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0216DCB4  0x0216DCB4  thumb
 *   func_0216D804  0x0216D804  thumb
 *   func_0216D810  0x0216D810  thumb
 *   func_0216D81C  0x0216D81C  thumb
 *   func_02163E34  0x02163E34  thumb
 *   func_0216D83C  0x0216D83C  thumb
 *   func_0216D86C  0x0216D86C  thumb
 *   func_02164280  0x02164280  thumb
 *   func_0216D8AC  0x0216D8AC  thumb
 *   func_0216D7E0  0x0216D7E0  thumb
 *   func_0216D7D8  0x0216D7D8  thumb
 *   func_0216D570  0x0216D570  thumb
 *   func_0216D568  0x0216D568  thumb
 */

typedef short s16;

typedef unsigned int   u32;
extern int func_0216DCB4(void *a0);
extern int func_0216D804(void *p);
extern int func_0216D810(void *p);
extern int func_0216D81C(void *p);
extern int func_02163E34(int a, int *p, int *out);
extern int func_0216D83C(void *p);
extern int func_0216D86C(void *p);
extern void func_02164280(int x, int y, int *p);
extern u32 func_0216D8AC(void *p);
extern void func_0216D7E0(void *p, u32 v);
extern void func_0216D7D8(void *p, u32 v);
extern char *func_0216D570(char *p, u32 v);
extern void *func_0216D568(void *p, u32 v);

int func_021640B0(int a)
{
    int rect[3];
    int o1;
    int o2;
    int r1;
    int r2;

    r1 = 0;
    r2 = 0;
    o1 = -1;
    o2 = -1;
    if (func_0216DCB4((void *)a) == 0) {
        int x = func_0216D804((void *)a);
        int y = func_0216D810((void *)a);
        int z = func_0216D81C((void *)a);
        rect[0] = x << 16;
        rect[1] = y << 16;
        rect[2] = z << 16;
        r1 = func_02163E34(a, rect, &o1);
        func_02164280((s16)func_0216D83C((void *)a), (s16)func_0216D86C((void *)a), rect);
        rect[1] = func_0216D8AC((void *)a);
        r2 = func_02163E34(a, rect, &o2);
    }
    if (r1 == 1)
        func_0216D7E0((void *)a, o1);
    if (r2 == 1)
        func_0216D7D8((void *)a, o2);
    if (r2 == 1) {
        func_0216D570((char *)a, 0x800);
        return 1;
    }
    func_0216D568((void *)a, 0x800);
    return 0;
}
