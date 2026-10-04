/*
 * function: func_021B18E4
 * address:  0x021B18E4
 * packet:   pkt_ov021_021B18E4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0215A5EC  0x0215A5EC  thumb  ov010
 *   func_0215A5E4  0x0215A5E4  thumb  ov010
 *   func_02012844  0x02012844  thumb
 *   func_02162744  0x02162744  thumb  ov010
 *   func_020127A4  0x020127A4  thumb
 *   func_02012AC8  0x02012AC8  thumb
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_0201296C  0x0201296C  thumb
 *   func_02162740  0x02162740  thumb  ov010
 *   func_0216CEE4  0x0216CEE4  thumb  ov010
 *   func_0216DAF8  0x0216DAF8  thumb  ov010
 */

int func_0215A5EC(int b);
void *func_0215A5E4(void *a0);
typedef unsigned int   u32;
struct BigObj;
u32 func_02012844(const struct BigObj *p);
int func_02162744(int a);
int func_020127A4(void *a);
struct Rec44;
unsigned short func_02012AC8(const struct Rec44 *p);
unsigned int func_02159B10(void *a0, void *a1);
void *func_0201296C(void *a);
int func_02162740(int a);
int func_0216CEE4(int a, int b, int c, int d, void *e, int f);
void func_0216DAF8(int a);

int func_021B18E4(int a, int b)
{
    void *r4;
    int r5;
    int r6;
    int s8;
    int sc;
    int s10;
    int r0;

    s8 = func_0215A5EC(b);
    r4 = func_0215A5E4((void *)b);
    sc = func_02012844(r4);
    r5 = func_02162744(sc);
    s10 = func_02012AC8((const struct Rec44 *)func_020127A4(r4));
    r6 = func_02159B10((void *)a, (void *)b);
    if (r5 != 0) {
        r4 = func_0201296C(r4);
        r0 = func_0216CEE4(s8, func_02162740(sc), s10, r5, r4, r6);
        if (r0 != 0) {
            func_0216DAF8(r0);
        }
    }
    return 0;
}
