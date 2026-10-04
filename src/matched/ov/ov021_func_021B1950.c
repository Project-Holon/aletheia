/*
 * function: func_021B1950
 * address:  0x021B1950
 * packet:   pkt_ov021_021B1950
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_0215A5EC  0x0215A5EC  thumb  ov010
 *   func_0216DE94  0x0216DE94  thumb  ov010
 *   func_0216E084  0x0216E084  thumb  ov010
 */

typedef signed short s16;

unsigned int func_02159B10(void *a0, void *a1);
typedef unsigned int   u32;
void *func_0215A5EC(void *p);
void *func_0216DE94(void *map, u32 id);
void func_0216E084(int a, int b, int c, int d, int e);

int func_021B1950(int a, int b)
{
    int r0;
    int r2;
    s16 r1;
    s16 r7;
    s16 r6;
    int r4;

    r2 = func_02159B10((void *)a, (void *)b);
    r1 = func_02159B10((void *)a, (void *)b);
    r7 = func_02159B10((void *)a, (void *)b);
    r6 = func_02159B10((void *)a, (void *)b);
    r4 = func_02159B10((void *)a, (void *)b);
    r0 = (int)func_0216DE94(func_0215A5EC((void *)b), r2);
    if (r0) {
        func_0216E084(r0, r1, r7, r6, r4);
    }
    return 0;
}
