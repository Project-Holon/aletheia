/*
 * file:     btl_server_p66.c
 * unit:     yes
 * function: func_021C4E38, func_021C4EA4, func_021C4F64
 * address:  0x021C4E38
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021D74F8  0x021D74F8  thumb  ov093
 *   func_021D5440  0x021D5440  thumb  ov093
 *   func_021D75EC  0x021D75EC  thumb  ov093
 *   func_021D7630  0x021D7630  thumb  ov093
 *   func_021D75A8  0x021D75A8  thumb  ov093
 *   func_021D70F0  0x021D70F0  thumb  ov093
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021D7540  0x021D7540  thumb  ov093
 *   func_021C8838  0x021C8838  thumb  ov093
 *   func_021C8860  0x021C8860  thumb  ov093
 *   func_021C8810  0x021C8810  thumb  ov093
 *   func_021C20BC  0x021C20BC  thumb  ov093
 *   func_021C99A0  0x021C99A0  thumb  ov093
 *   func_021C8010  0x021C8010  thumb  ov093
 *   func_021C70E4  0x021C70E4  thumb  ov093
 *   func_021D59B4  0x021D59B4  thumb  ov093
 *   func_021C20D0  0x021C20D0  thumb  ov093
 *   func_021D5B68 0x021D5B68 thumb ov093
 *   func_021C5078 0x021C5078 thumb ov093
 *   func_021BA1A8 0x021BA1A8 thumb ov093
 *   func_021B8DDC 0x021B8DDC thumb ov093
 *   func_021CD64C 0x021CD64C thumb ov093
 *   func_021CD4B0 0x021CD4B0 thumb ov093
 *   func_021C5108 0x021C5108 thumb ov093
 *   func_021D646C 0x021D646C thumb ov093
 *   func_021B8FF4 0x021B8FF4 thumb ov093
 *   func_021C5098 0x021C5098 thumb ov093
 *   func_021B92B0 0x021B92B0 thumb ov093
 *   func_021C5088 0x021C5088 thumb ov093
 *   func_021B902C 0x021B902C thumb ov093
 *   func_021BA1B4 0x021BA1B4 thumb ov093
 */
struct S;
struct Msg;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

extern void func_021D74F8(int line);
extern u8 func_021D5440(u8 *p);
extern void func_021D75EC(int key, u32 val);
extern void func_021D7630(int key, u32 val);
extern void func_021D75A8(int key, u32 val);
extern void func_021D70F0(void *a, int id);
extern int func_021D775C(int key);
extern void func_021D7540(int line);
extern void func_021C8838(void *p, int a, int b);
extern void func_021C8860(struct S *p, u32 val);
extern void func_021C8810(u8 *p);
extern int func_021C20BC(u8 *p, u8 *a, int r);
extern int func_021C99A0(void *w, const struct Msg *m);
extern int func_021C8010(u8 *p, u32 x);
extern void func_021C70E4(u8 *p, int a, int b, int c, int e, u32 f);
extern int func_021D59B4(u8 *p, int k);
extern int func_021C20D0(u8 *p, u8 *a, int c, u8 *l);
extern int func_021D5B68(void *);
extern void func_021C5078(u8 *, u8);
extern int func_021BA1A8(char **p, int m);
extern u8 func_021B8DDC(u32);
extern void func_021CD64C(void *, u8, ...);
extern void func_021CD4B0(void *w, volatile u32 id, ...);
extern void func_021C5108(u8 *, u8 *, int);
extern void func_021D646C(u8 *);
extern u8 func_021B8FF4(u8 *);
extern u32 func_021C5098(u8 *);
extern void func_021B92B0(char *p, void *m, int k);
extern void func_021C5088(u8 *, u8);
extern int func_021B902C(int, int);
extern void func_021BA1B4(char **p, int i);
int func_021C4E38(u8 *p, u8 *a, u32 b, u32 c);
void func_021C4EA4(u8 *p, u8 *a, int k, int n);
int func_021C4F64(u8 *p, u8 *a);


int func_021C4E38(u8 *p, u8 *a, u32 b, u32 c)
{
    u8 f;
    int r;
    int s;
    func_021D74F8(9960);
    func_021D75EC(2, func_021D5440(a));
    func_021D75EC(0x39, b);
    r = 0;
    func_021D7630(0x41, 0);
    func_021D75A8(0x32, c);
    func_021D70F0(p, 0x7f);
    s = func_021D775C(0x32);
    f = func_021D775C(0x41);
    func_021D7540(9969);
    if (f == 0) {
        r = s;
    }
    return r;
}



void func_021C4EA4(u8 *p, u8 *a, int k, int n)
{
    u8 x = func_021D5440(a);
    switch (k) {
    case 4:
        func_021C8838(p + 0x1AE4, 2, 396);
        func_021C8860((struct S *)(p + 0x1AE4), x);
        break;
    case 3:
        func_021C8838(p + 0x1AE4, 2, 399);
        func_021C8860((struct S *)(p + 0x1AE4), x);
        break;
    default:
        func_021C8810(p + 0x1AE4);
        break;
    }
    if (n > 0 && func_021C20BC(p, a, n) != 0) {
        func_021C99A0(p, (const struct Msg *)(p + 0x1AE4));
        func_021C8810(p + 0x1AE4);
        func_021C70E4(p, 0x290, func_021C8010(p, x), 6, 0, 0);
        if ((int)func_021D59B4(a, 0xd) <= n) {
            func_021C70E4(p, 0x255, 6, 6, 0, 0);
        }
        func_021C20D0(p, a, n, 0);
    }
}


/*
 * note: 2026-10-05 recoup: `ok = 0;` written after the call to func_021C5108 (it is
 * only read by the later compare), not before it; this puts the zero store in r2 as in the
 * original. EXACT in c99 and c. Callees: func_021D59B4 and func_021BA1A8 return int,
 * func_021B8DDC (unlabelled in ov093 matched set) returns u8, func_021C5108 and
 * func_021B92B0 are void with three arguments.
 */
int func_021C4F64(u8 *p, u8 *a)
{
    u8 k = func_021D5440(a);
    u8 *flags = p + 0x7a9;
    int ok;
    int side;
    int health;
    if (!flags[k] && func_021D5B68(a)) {
    flags[k] = 1;
    func_021C5078(p + 0x3e0, k);
    if (!(func_021BA1A8(*(void **)(p + 4), 0x200) && func_021B8DDC(k) != 0) && p[0x789] != k)
        func_021CD64C(*(void **)(p + 12), 0x5b, 0, k, 0xffff0000);
    func_021CD4B0(*(void **)(p + 12), 0x39, k);
    func_021C5108(p, a, 0);
    ok = 0;
    func_021D646C(a);
    side = func_021B8DDC(k);
    if (side == func_021B8FF4(*(u8 **)(p + 4))) {
        health = func_021D59B4(a, 15);
        if (health + 30 <= (int)func_021C5098(p)) ok = 1;
        func_021B92B0((char *)(*(u8 **)(p + 4)), a, ok);
    }
    func_021C5088(p + 0x1ab8, k);
    side = func_021B8DDC(k);
    {
        int current = func_021B8FF4(*(u8 **)(p + 4));
        if (side == current) {
            func_021BA1B4((char **)(*(u8 **)(p + 4)), 0x4c);
        } else if (!func_021B902C(side, current)) {
            func_021BA1B4((char **)(*(u8 **)(p + 4)), 0x19);
            func_021BA1B4((char **)(*(u8 **)(p + 4)), 0x52);
        }
    }
    return 1;
    }
    return 0;
}
