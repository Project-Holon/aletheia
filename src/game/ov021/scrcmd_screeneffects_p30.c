/*
 * file:     scrcmd_screeneffects_p30.c
 * unit:     yes
 * function: func_021B162C, func_021B1668, func_021B1698, func_021B16DC
 * address:  0x021B162C
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
 *   func_0201F250  0x0201F250  thumb
 *   func_02045CAC  0x02045CAC  arm
 *   func_02158F74  0x02158F74  thumb  ov010
 *   func_02158F78  0x02158F78  thumb  ov010
 *   func_02158F7C  0x02158F7C  thumb  ov010
 *   func_0215A60C  0x0215A60C  thumb  ov010
 *   func_0215A5EC  0x0215A5EC  thumb  ov010
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_0216DE54  0x0216DE54  thumb  ov010
 *   func_0216DE94  0x0216DE94  thumb  ov010
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_0201134C  0x0201134C  thumb
 *   func_02197D3C  0x02197D3C  thumb  ov021
 *   func_0215A6DC  0x0215A6DC  thumb  ov010
 *   func_0215A6FC  0x0215A6FC  thumb  ov010
 */
struct MsgBank;
struct WordSet;
struct Cursor;
typedef unsigned int u32;

typedef unsigned char  u8;

typedef unsigned short u16;

typedef signed short   s16;

typedef signed char    s8;

extern u32 func_0215A60C(u8 *p);
extern u32 func_02158F78(u8 *p);
extern void *func_02158F74(void *p);
extern u32 func_02158F7C(u8 *p);
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void *func_0215A5EC(void *p);
extern void *func_0216DE54(void *map, u32 kind);
extern void *func_0215A5F4(void *p);
extern void *func_0216DE94(void *map, u32 id);
unsigned int func_02159B10(void *a0, void *a1);
unsigned int func_0201134C(struct Cursor *p);
int func_02197D3C(int a, int b);
void func_0215A6DC(int *p, int v);
extern u32 func_0215A6FC(u32, u32, u32, u32);
u32 func_021B162C(u32 a, u32 b, u32 c);
u32 func_021B1668(u32 a, u32 b);
int func_021B1698(int *a, int *b);
int func_021B16DC(u32 a, u32 b, u32 c, u32 d);


u32 func_021B162C(u32 a, u32 b, u32 c)
{
    u32 x, r, s, n;

    x = func_0215A60C((u8 *)a);
    r = func_02158F78((u8 *)b);
    s = (u32)func_02158F74((void *)b);
    n = func_02158F7C((u8 *)b);
    func_02045CAC((struct MsgBank *)x, c, (void *)n);
    func_0201F250((struct WordSet *)s, (void *)r, (void *)n);
    return r;
}


u32 func_021B1668(u32 a, u32 b)
{
    u32 t;
    u32 r;

    t = (u32)func_0215A5EC((void *)a);
    if (b == 0xf2) {
        r = (u32)func_0216DE54((void *)t, 0x30);
    } else if (b == 0xf1) {
        func_0215A5F4((void *)a);
    } else {
        r = (u32)func_0216DE94((void *)t, b);
    }
    return r;
}


int func_021B1698(int *a, int *b)
{
    int r7;
    int r6;
    int r0;

    func_0215A5F4((void *)b);
    r7 = func_02159B10(a, (void *)b);
    r6 = func_0201134C((struct Cursor *)a);
    r0 = func_021B1668((u32)b, r7);
    if (r0 == 0) {
        return 0;
    }
    func_0215A6DC(b, func_02197D3C(r0, a[5] + r6));
    return 0;
}


/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_021B16DC(u32 a, u32 b, u32 c, u32 d)
{
if (func_0215A6FC(b, b, c, d) == 0) {
    return 1;
}
return 0;
}
