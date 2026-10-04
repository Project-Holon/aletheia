/*
 * function: func_021B19E0
 * address:  0x021B19E0
 * packet:   pkt_ov021_021B19E0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_02159AE8  0x02159AE8  thumb  ov010
 *   func_0215A5EC  0x0215A5EC  thumb  ov010
 *   func_0216DE94  0x0216DE94  thumb  ov010
 *   func_0216D63C  0x0216D63C  thumb  ov010
 */

typedef unsigned short u16;

unsigned int func_02159B10(void *a, void *b);
u16 *func_02159AE8(void *a0, void *a1);
typedef unsigned int   u32;
void *func_0215A5EC(void *p);
void *func_0216DE94(void *map, u32 id);
int func_0216D63C(char *a0, int a1);

int func_021B19E0(int a, int b)
{
    int r7;
    unsigned int r4;
    u16 *r6;
    int r0;

    r7 = func_02159B10((void *)a, (void *)b);
    r4 = func_02159B10((void *)a, (void *)b);
    r6 = func_02159AE8((void *)a, (void *)b);
    r0 = (int)func_0216DE94(func_0215A5EC((void *)b), r7);
    if (r4 <= 2 && r0 != 0) {
        *r6 = func_0216D63C((char *)r0, r4);
    }
    return 0;
}
