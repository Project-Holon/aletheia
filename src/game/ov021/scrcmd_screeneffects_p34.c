/*
 * file:     scrcmd_screeneffects_p34.c
 * unit:     yes
 * function: func_021B18E4, func_021B1950, func_021B19B0, func_021B19E0, func_021B1A20
 * address:  0x021B18E4
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
 *   func_0216DE94  0x0216DE94  thumb  ov010
 *   func_0216E084  0x0216E084  thumb  ov010
 *   func_02159AE8  0x02159AE8  thumb  ov010
 *   func_0216D5B0  0x0216D5B0  thumb  ov010
 *   func_0216D63C  0x0216D63C  thumb  ov010
 *   func_0216DB80  0x0216DB80  thumb  ov010
 */
struct SaveBlock;
struct BigObj;
struct Rec44;
typedef unsigned short u16;

typedef unsigned char  u8;

typedef unsigned int   u32;

typedef signed short s16;

void *func_0215A5EC(void *p);
void *func_0215A5E4(void *a0);
u32 func_02012844(const struct BigObj *p);
u16 func_02162744(u8 *p);
void *func_020127A4(struct SaveBlock *p);
unsigned short func_02012AC8(const struct Rec44 *p);
unsigned int func_02159B10(void *a0, void *a1);
u32 func_0201296C(const struct BigObj *p);
u32 func_02162740(u8 *p);
int func_0216CEE4(int a, int b, int c, int d, void *e, int f);
void func_0216DAF8(void *a0);
void *func_0216DE94(void *map, u32 id);
void func_0216E084(int a, int b, int c, int d, int e);
extern u16 *func_02159AE8(void *a0, void *a1);
extern u16 func_0216D5B0(u8 *p);
int func_0216D63C(char *a0, int a1);
extern void func_0216DB80(unsigned int *p, unsigned int v);
int func_021B18E4(int a, int b);
int func_021B1950(int a, int b);
int func_021B19B0(u32 a, u32 b);
int func_021B19E0(int a, int b);
int func_021B1A20(u32 a, u32 b);


int func_021B18E4(int a, int b)
{
    void *r4;
    int r5;
    int r6;
    int s8;
    int sc;
    int s10;
    int r0;

    s8 = (int)func_0215A5EC((void *)b);
    r4 = func_0215A5E4((void *)b);
    sc = func_02012844(r4);
    r5 = func_02162744((u8 *)sc);
    s10 = func_02012AC8((const struct Rec44 *)func_020127A4(r4));
    r6 = func_02159B10((void *)a, (void *)b);
    if (r5 != 0) {
        r4 = (void *)func_0201296C(r4);
        r0 = func_0216CEE4(s8, func_02162740((u8 *)sc), s10, r5, r4, r6);
        if (r0 != 0) {
            func_0216DAF8((void *)r0);
        }
    }
    return 0;
}


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


int func_021B19B0(u32 a, u32 b)
{
    u32 x = func_02159B10((void *)a, (void *)b);
    u16 *p = func_02159AE8((void *)a, (void *)b);
    u32 o = (u32)func_0216DE94(func_0215A5EC((void *)b), x);

    if (o != 0) {
        *p = func_0216D5B0((u8 *)o);
    }
    return 0;
}


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


int func_021B1A20(u32 a, u32 b)
{
    u32 x = func_02159B10((void *)a, (void *)b);
    u32 o = (u32)func_0216DE94(func_0215A5EC((void *)b), x);

    if (o != 0) {
        func_0216DB80((unsigned int *)o, 1);
    }
    return 0;
}
