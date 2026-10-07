/*
 * file:     dwc_rap_p17.c
 * unit:     yes
 * function: func_02156888, func_02156A3C, func_02156A58
 * address:  0x02156888
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   d_021A8264     0x021A8264  data  ov009  a4
 *   func_02156C84  0x02156C84  thumb  ov009
 *   func_02156C60  0x02156C60  thumb  ov009
 *   func_0203D650  0x0203D650  arm
 *   func_0216B354  0x0216B354  arm  ov009
 *   func_0216B408  0x0216B408  arm  ov009
 *   func_02156B18  0x02156B18  thumb  ov009
 *   func_02156B3C  0x02156B3C  thumb  ov009
 *   func_02155678  0x02155678  thumb  ov009
 *   func_0203C9AC  0x0203C9AC  arm
 *   func_02156C00  0x02156C00  thumb  ov009
 *   func_02155374  0x02155374  thumb  ov009
 *   func_02177138  0x02177138  arm  ov009
 *   func_02177160  0x02177160  arm  ov009
 *   func_0216B634  0x0216B634  arm  ov009
 *   func_02177188  0x02177188  arm  ov009
 *   func_02155D80  0x02155D80  thumb  ov009
 *   func_02155DCC  0x02155DCC  thumb  ov009
 *   func_02155E9C  0x02155E9C  thumb  ov009
 *   func_02155BDC  0x02155BDC  thumb  ov009
 *   g_021A8264  0x021A8264  data  ov009  a4
 *   func_02155D2C  0x02155D2C  thumb  ov009
 *   func_0216B7E0  0x0216B7E0  arm  ov009
 *   func_0216B908  0x0216B908  arm  ov009
 */
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct {
    char pad[0x750];
    int f750;           /* 0x750 */
    int state;          /* 0x754 */
    char pad1[0x75c - 0x758];
    int f75c;           /* 0x75c */
    int f760;           /* 0x760 */
    int n;              /* 0x764 */
    char pad2[0x770 - 0x768];
    int aid;            /* 0x770 */
    char pad3[0x778 - 0x774];
    int f778;           /* 0x778 */
    char pad4[0x780 - 0x77c];
    short s780;         /* 0x780 */
    char pad5[0x78c - 0x782];
    int retry;          /* 0x78c */
    char pad6[0x798 - 0x790];
    int f798;           /* 0x798 */
    char pad7[0x7a1 - 0x79c];
    u8 b7a1;            /* 0x7a1 */
} G_02156888;

typedef struct {
    char pad[0x770];
    int aid;            /* 0x770 */
} G_02156A3C;

unsigned char func_02156C84(void);
void func_02156C60(void);
u32 func_0203D650(void);
int func_0216B354(int topology, unsigned char maxEntry, void *matchedCallback, void *matchedParam, void *newClientCallback, void *newClientParam, void *attemptCallback, void *connectionUserData, void *attemptParam);
int func_0216B408(int, int, void *, u32, void *, u32, void *, int *, u32);
void func_02156B18(int a, int b, int c, int d, int e);
void func_02156B3C(int a);
u8 func_02155678(void);
void func_0203C9AC(int a, u32 b, u32 c, u32 d);
void func_02156C00(u32 a);
void func_02155374(int);
int func_02177138(int a, int b);
int func_02177160(int a, int b);
int func_0216B634(int a, int b);
int func_02177188(int a, int b);
void func_02155D80(int a, u32 i);
void func_02155DCC(u32 a, u8 *p, int c);
void func_02155E9C(int a, int b, int c, u32 d);
void func_02155BDC(unsigned int n);
extern void func_02155D2C(int);
extern void func_0216B7E0(u8);
extern int func_0216B908(void);
int func_02156888(int a, int b, int c);
int func_02156A3C(void);
void func_02156A58(int a, int b, int c, int d, int e);
extern G_02156888 *d_021A8264;
extern u8 *g_021A8264;


int func_02156888(int a, int b, int c)
{
    int n = b;
    int r;
    int i;

    if (func_02156C84() != 0)
        return -4;
    if (d_021A8264->state != 6) {
        d_021A8264->retry++;
        if (d_021A8264->retry > 0x78)
            return -3;
        return -1;
    }
    func_02156C60();
    d_021A8264->f798 = 0;
    d_021A8264->b7a1 = 1;
    d_021A8264->aid = a;
    d_021A8264->n = b;
    d_021A8264->s780 = -1;
    if (c != 0)
        n = 2;
    d_021A8264->f778 = 1;
    if (a < 0) {
        r = func_0216B354(2, n, func_02156A58, (void *)func_0203D650(), func_02156B3C,
                          (void *)func_0203D650(), func_02155678, &d_021A8264->f750,
                          (void *)func_0203D650());
        d_021A8264->f75c = 1;
    } else {
        r = func_0216B408(2, a, func_02156B18, 0, func_02156B3C,
                          func_0203D650(), func_02155678, &d_021A8264->f750,
                          func_0203D650());
        d_021A8264->f75c = 2;
    }
    if (r == 0) {
        d_021A8264->retry++;
        if (d_021A8264->retry > 0x78)
            func_0203C9AC(0, 0, 0, 0x3f1);
        return -2;
    }
    d_021A8264->retry = 0;
    for (i = 0; i < b; i++)
        func_02156C00(i);
    func_02155374(7);
    func_02177138((int)func_02155D80, 0);
    func_02177160((int)func_02155DCC, 0);
    func_0216B634((int)func_02155E9C, 0);
    func_02177188((int)func_02155BDC, 0);
    d_021A8264->f760 = 0;
    return 0;
}


int func_02156A3C(void)
{
    if (d_021A8264 != 0)
        return d_021A8264->aid;
    return -1;
}


void func_02156A58(int a, int b, int c, int d, int e)
{
    int flag = 0;
    *(u32 *)(g_021A8264 + 0x778) = 0;
    if (a == 0) {
        if (b == 0) {
            if (g_021A8264[0x7a4] != 0 && e == -1) {
                flag = 1;
            }
            if (*(u32 *)(g_021A8264 + 0x2a4) != 0) {
                if (((int (*)(int, u32))*(u32 *)(g_021A8264 + 0x2a4))(e, func_0203D650()) == 0) {
                    flag = 1;
                }
            }
            if (g_021A8264[0x7a0] != 0 || flag != 0) {
                if (e != -1) {
                    func_0216B7E0(e);
                }
            }
            *(int *)(g_021A8264 + 0x770) = e;
            *(u32 *)(g_021A8264 + 0x798) = func_0216B908();
            if (*(u32 *)(g_021A8264 + 0x798) == 1) {
                func_02155374(8);
                return;
            }
            func_02155D2C(e);
            return;
        }
        if (c == 0) {
            *(u16 *)(g_021A8264 + 0x780) = e;
            *(int *)(g_021A8264 + 0x774) = flag - 1;
        }
    }
}
