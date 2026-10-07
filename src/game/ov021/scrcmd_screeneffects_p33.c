/*
 * file:     scrcmd_screeneffects_p33.c
 * unit:     yes
 * function: func_021B181C, func_021B18B8
 * address:  0x021B181C
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
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_02158F58  0x02158F58  thumb  ov010
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_02188C9C  0x02188C9C  thumb  ov021
 *   func_0215A5EC  0x0215A5EC  thumb  ov010
 *   func_0215A5E4  0x0215A5E4  thumb  ov010
 *   func_0201296C  0x0201296C  thumb
 *   func_0216E3D0  0x0216E3D0  thumb  ov010
 *   func_0216CE6C  0x0216CE6C  thumb  ov010
 *   func_0216DAF8  0x0216DAF8  thumb  ov010
 *   func_0216CF2C  0x0216CF2C  thumb  ov010
 *   func_0216DE94  0x0216DE94  thumb  ov010
 */
struct BigObj;
typedef signed short s16;

typedef unsigned short u16;

typedef unsigned char  u8;

typedef unsigned int   u32;

void *func_0215A5F4(void *p);
int func_02158F58(int a0);
unsigned int func_02159B10(void *a0, void *a1);
u16 func_02188C9C(u8 *p);
void *func_0215A5EC(void *p);
void *func_0215A5E4(void *a0);
u32 func_0201296C(const struct BigObj *p);
int func_0216E3D0(int a, int b);
int func_0216CE6C(int a, s16 b, s16 c, int d, int e, int f, int g, int h);
void func_0216DAF8(void *a0);
extern void *func_0216DE94(void *map, u32 id);
extern void func_0216CF2C(u32);
int func_021B181C(int a, int b);
int func_021B18B8(u32 a, u32 b);


int func_021B181C(int a, int b)
{
    int r6;
    int v0;
    int v1;
    int v2;
    int v3;
    int v4;
    int r7;
    int r5;
    int r0;

    r6 = (int)func_02158F58((int)func_0215A5F4((void *)b));
    v0 = func_02159B10((void *)a, (void *)b);
    v1 = func_02159B10((void *)a, (void *)b);
    v2 = func_02159B10((void *)a, (void *)b);
    v3 = func_02159B10((void *)a, (void *)b);
    v4 = func_02159B10((void *)a, (void *)b);
    r7 = func_02159B10((void *)a, (void *)b);
    r5 = func_02188C9C((u8 *)(((int *)r6)[1]));
    r6 = (int)func_0215A5EC((void *)b);
    r0 = func_0216E3D0(func_0201296C(func_0215A5E4((void *)b)), v4);
    r0 = func_0216CE6C(r6, v0, v1, v2, v3, r0, r7, r5);
    if (r0 != 0) {
        func_0216DAF8((void *)r0);
    }
    return 0;
}


int func_021B18B8(u32 a, u32 b)
{
    u32 t = (u32)func_0215A5EC((void *)b);
    u32 o = (u32)func_0216DE94((void *)t, func_02159B10((void *)a, (void *)b));

    if (o != 0) {
        func_0216CF2C(o);
    }
    return 0;
}
