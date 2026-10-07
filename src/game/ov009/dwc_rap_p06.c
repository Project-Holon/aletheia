/*
 * file:     dwc_rap_p06.c
 * unit:     yes
 * function: func_0215568C, func_0215580C
 * address:  0x0215568C
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
 *   d_021A1C5C     0x021A1C5C  data  ov009  a1
 *   d_021A1C74     0x021A1C74  data  ov009  a1
 *   d_021A1974     0x021A1974  data  ov009  a1
 *   func_02034714  0x02034714  arm
 *   func_02156C60  0x02156C60  thumb  ov009
 *   func_0216CA04  0x0216CA04  arm
 *   func_02082BCC  0x02082BCC  arm
 *   func_02094530  0x02094530  arm
 *   func_0203F004  0x0203F004  arm
 *   func_02156C00  0x02156C00  thumb  ov009
 *   func_02155374  0x02155374  thumb  ov009
 *   func_0203D650  0x0203D650  arm
 *   func_0216B284  0x0216B284  arm
 *   func_02177138  0x02177138  arm
 *   func_02177160  0x02177160  arm
 *   func_0216B634  0x0216B634  arm
 *   func_02177188  0x02177188  arm
 *   func_02155674  0x02155674  thumb  ov009
 *   func_02155678  0x02155678  thumb  ov009
 *   func_02155D3C  0x02155D3C  thumb  ov009
 *   func_02155D7C  0x02155D7C  thumb  ov009
 *   func_02155D80  0x02155D80  thumb  ov009
 *   func_02155DCC  0x02155DCC  thumb  ov009
 *   func_02155E9C  0x02155E9C  thumb  ov009
 *   func_02155BDC  0x02155BDC  thumb  ov009
 */
typedef unsigned char  u8;

typedef struct {
    char pad0[0x2AC];
    char name[0x80];
    char pad32C[0x750 - 0x32C];
    int w750;
    int state;
    int w758;
    int w75C;
    int w760;
    int n;
    char pad768[0x7A1 - 0x768];
    u8 b7A1;
} G_0215568C;

typedef void (*Fn)(void);

typedef unsigned int   u32;

typedef struct {
    char pad0[0x754];
    int state;
    int w758;
    int w75C;
    int w760;
    int n;
    char pad768[0x7A1 - 0x768];
    u8 b7A1;
} G_0215580C;

void func_02034714(const char *expr, u32 line, const char *file);
void func_02156C60(void);
u8 func_0216CA04(u8 keyID, char *keyString, char *valueSrc);
void func_02082BCC(void *p, int v, int n);
u32 func_02094530(char *dst, u32 n, ...);
u32 func_0203F004(const u8 *s);
void func_02156C00(u32 a);
void func_02155374(int v);
u32 func_0203D650(void);
int func_0216B284(int topology, unsigned char maxEntry, char *addFilter, void *matchedCallback, void *matchedParam, void *newClientCallback, void *newClientParam, void *evalCallback, void *evalParam, void *attemptCallback, void *connectionUserData, void *attemptParam);
int func_02177138(int a, int b);
int func_02177160(int a, int b);
int func_0216B634(int a, int b);
int func_02177188(int a, int b);
void func_02155674(void);
u8 func_02155678(void);
void func_02155D3C(int a, int b, int c, int d, int e);
int func_02155D7C(void);
void func_02155D80(int a, u32 i);
void func_02155DCC(u32 a, u8 *p, int c);
void func_02155E9C(int a, int b, int c, u32 d);
void func_02155BDC(unsigned int n);
int func_0215568C(void *a0, int n, int a2);
int func_0215580C(int a0, int n, int a2, int a3);
extern G_0215568C *d_021A8264;
extern char d_021A1C5C[];
extern char d_021A1C74[];
extern char d_021A1974[];


/*
 * Sibling of func_0215580C: in state 6, formats a 0x80-byte name at +0x2AC,
 * resets n slots, enters state 7 and hands func_0216B284 (mode 2) and three
 * registrars the ov009 callbacks.
 *
 * The four callback leaves it passes were unlabelled; their own EXACT
 * shards (wave 2) witness them.
 */
int func_0215568C(void *a0, int n, int a2)
{
    int i;

    if (d_021A8264 == 0)
        func_02034714(d_021A1C5C, 0, d_021A1C5C);
    if (d_021A8264->state != 6)
        return 0;
    func_02156C60();
    if (func_0216CA04(0, d_021A1C74, a0) == 0)
        func_02034714(d_021A1C5C, 0, d_021A1C5C);
    func_02082BCC(d_021A8264->name, 0, 0x80);
    func_02094530(d_021A8264->name, (u32)d_021A1974, d_021A1C74, a0);
    if ((int)func_0203F004((const u8 *)d_021A8264->name) >= 0x80)
        func_02034714(d_021A1C5C, 0, d_021A1C5C);
    if (a2)
        func_0216CA04(1, d_021A8264->name, d_021A8264->name);
    for (i = 0; i < n; i++)
        func_02156C00(i);
    func_02155374(7);
    d_021A8264->n = n;
    if (func_0216B284(2, n, d_021A8264->name, (Fn)func_02155D3C,
                      (void *)func_0203D650(), func_02155674,
                      (void *)func_0203D650(), (Fn)func_02155D7C,
                      (void *)func_0203D650(), (Fn)func_02155678,
                      &d_021A8264->w750, (void *)func_0203D650()) == 0)
        return 0;
    d_021A8264->w75C = 0;
    func_02177138((int)((Fn)func_02155D80), 0);
    func_02177160((int)((Fn)func_02155DCC), 0);
    func_0216B634((int)((Fn)func_02155E9C), 0);
    func_02177188((int)((Fn)func_02155BDC), 0);
    d_021A8264->w760 = 0;
    d_021A8264->b7A1 = 1;
    return 1;
}


/*
 * In state 6 of the ov009 work block: resets n slots, enters state 7 and
 * hands func_0216B284 and three registrars the ov009 callbacks.
 *
 * The two callback leaves it passes were unlabelled; their own EXACT
 * shards (wave 2) witness them.
 */
int func_0215580C(int a0, int n, int a2, int a3)
{
    int i;

    if (d_021A8264 == 0)
        func_02034714(d_021A1C5C, 0, d_021A1C5C);
    if (d_021A8264->state != 6)
        return 0;
    func_02156C60();
    for (i = 0; i < n; i++)
        func_02156C00(i);
    func_02155374(7);
    d_021A8264->n = n;
    if (func_0216B284(1, n, (char *)a0, (Fn)func_02155D3C, 0, func_02155674, 0, (void *)a2, (void *)a3,
                      0, 0, 0) == 0)
        return 0;
    d_021A8264->w75C = 0;
    func_02177138((int)((Fn)func_02155D80), 0);
    func_02177160((int)((Fn)func_02155DCC), 0);
    func_0216B634((int)((Fn)func_02155E9C), 0);
    func_02177188((int)((Fn)func_02155BDC), 0);
    d_021A8264->w760 = 0;
    d_021A8264->b7A1 = 1;
    d_021A8264->w758 = 0x3EF;
    return 1;
}
