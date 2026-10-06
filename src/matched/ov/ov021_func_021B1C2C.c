/*
 * function: func_021B1C2C
 * address:  0x021B1C2C
 * packet:   pkt_ov021_021B1C2C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_02158F58  0x02158F58  thumb  ov010
 *   func_02159AE8  0x02159AE8  thumb  ov010
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_02188C7C  0x02188C7C  thumb  ov021
 *   func_0216DDDC  0x0216DDDC  thumb  ov010
 *   func_0216D588  0x0216D588  thumb  ov010
 */

typedef signed short s16;

void *func_0215A5F4(void *p);
typedef unsigned short u16;
int func_02158F58(int a0);
s16 *func_02159AE8(void *a0, void *a1);
unsigned int func_02159B10(void *a, void *b);
void *func_02188C7C(unsigned char *p);
typedef signed int     s32;
typedef unsigned int   u32;
typedef unsigned char  u8;
u8 *func_0216DDDC(u32 a, u32 b, u32 c, s32 x, s32 lim, u32 d);
u16 func_0216D588(void *p);

int func_021B1C2C(int a, int b)
{
    int r7;
    s16 *s8;
    s16 *r6;
    int sc;
    int s10;
    int r4;
    int r0;

    r7 = ((int *)func_02158F58((int)func_0215A5F4((void *)b)))[1];
    s8 = func_02159AE8((void *)a, (void *)b);
    r6 = func_02159AE8((void *)a, (void *)b);
    sc = func_02159B10((void *)a, (void *)b);
    s10 = func_02159B10((void *)a, (void *)b);
    r4 = func_02159B10((void *)a, (void *)b);
    r0 = (int)func_0216DDDC((u32)func_02188C7C((void *)r7), (s16)sc, (s16)r4, s10 << 16, 0x8000, (int)0);
    if (r0) {
        *r6 = 1;
        *s8 = func_0216D588((void *)r0);
    } else {
        *r6 = 0;
    }
    return 0;
}
