/*
 * file:     fldmmdl_p13.c
 * unit:     yes
 * function: func_0216D2AC, func_0216D2F8, func_0216D38C, func_0216D3A8, func_0216D3B4
 * address:  0x0216D2AC
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0216DD1C  0x0216DD1C  thumb  ov010
 *   func_0216D948  0x0216D948  thumb  ov010
 *   func_0216DFAC  0x0216DFAC  thumb  ov010
 *   func_0216D780  0x0216D780  thumb  ov010
 *   func_0216D568  0x0216D568  thumb  ov010
 *   func_0216D244  0x0216D244  thumb  ov010
 *   func_0216D55C  0x0216D55C  thumb  ov010
 *   func_0216D268  0x0216D268  thumb  ov010
 *   func_0216D57C  0x0216D57C  thumb  ov010
 *   func_0216D730  0x0216D730  thumb  ov010
 *   func_0216D570  0x0216D570  thumb  ov010
 *   func_0216DAA0  0x0216DAA0  thumb  ov010
 *   func_0216E114  0x0216E114  thumb  ov010
 *   func_0216D794  0x0216D794  thumb  ov010
 *   func_0216E174  0x0216E174  thumb  ov010
 *   func_0216D28C  0x0216D28C  thumb  ov010
 *   func_0216DA30  0x0216DA30  thumb  ov010
 *   func_0216D67C  0x0216D67C  thumb  ov010
 *   func_02197C78  0x02197C78  thumb
 */
struct Ctx;
struct Rec;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

extern int func_0216DD1C(struct Ctx *c, struct Rec **out, u32 *iter);
extern int func_0216D948(int a0);
extern int func_0216DFAC(int a0);
extern void func_0216D780(void *a0);
extern void *func_0216D568(void *p, u32 v);
extern void func_0216D244(u32 x, u8 *o);
extern int func_0216D55C(int a0, int a1);
extern int func_0216D268(int a0, int a1);
extern u32 func_0216D57C(void *p, u32 v);
extern void func_0216D730(void *a0);
extern char *func_0216D570(char *p, u32 v);
extern int func_0216DAA0(void *a0);
extern int func_0216E114(int a0);
extern void func_0216D794(void *a0);
extern void func_0216E174(void *a0);
extern int func_0216D28C();
extern int func_0216DA30();
extern void *func_0216D67C(void *a0);
extern int func_02197C78();
void func_0216D2AC(u32 x);
void func_0216D2F8(u32 x);
void func_0216D38C(int a0);
void func_0216D3A8(u32 a, u32 b);
int func_0216D3B4(int a0);


void func_0216D2AC(u32 x)
{
    int n;
    u8 *o;
    u32 k = 5;

    n = 0;
    if (func_0216D948(x)) {
        while (func_0216DD1C((struct Ctx *)x, (struct Rec **)(&o), (u32 *)(&n)) == 1) {
            func_0216DFAC((int)o);
            func_0216D780(o);
            func_0216D568(o, k);
        }
    }
}


void func_0216D2F8(u32 x)
{
    int n;
    u8 *o;
    u32 a = 1;
    u32 b = 4;
    u32 c = 2;

    n = 0;
    if (func_0216DD1C((struct Ctx *)x, (struct Rec **)(&o), (u32 *)(&n)) == 1) {
        do {
            func_0216D244(x, o);
            if (func_0216D55C((int)o, c) == 0)
                func_0216D268(x, (int)o);
            if (func_0216D57C(o, a)) {
                func_0216D730(o);
                func_0216D570((char *)o, a);
            }
            if (func_0216DAA0(o) == 0)
                func_0216E114((int)o);
            if (func_0216D57C(o, b)) {
                func_0216D794(o);
                func_0216D570((char *)o, b);
            }
            func_0216E174(o);
        } while (func_0216DD1C((struct Ctx *)x, (struct Rec **)(&o), (u32 *)(&n)) == 1);
    }
}


/*
 * blocked:  listing 28 compiled 26
 */
void func_0216D38C(int a0)
{
    int t4;

t4 = a0 + 0;
    a0 = func_0216D28C(a0);
loc_0216D394:
a0 = t4 + 0;
    a0 = func_0216DA30(a0);
loc_0216D39A:
    if (a0 != 1) goto loc_0216D3A4;
loc_0216D39E:
a0 = t4 + 0;
    a0 = func_0216D3B4(a0);
loc_0216D3A4:
    return;}


/*
 * Unlabelled leaf (in a .word run): callback thunk that forwards its
 * second argument to func_0216D38C. Filed as the witness that
 * func_0216DF64's pointer to it needs.
 */
void func_0216D3A8(u32 a, u32 b)
{
    func_0216D38C(b);
}


int func_0216D3B4(int a0)
{
    int t4;

t4 = a0 + 0;
    a0 = (int)func_0216D67C((void *)a0);
loc_0216D3BC:
    a0 = func_0216D948(a0);
loc_0216D3C0:
    if (a0 != 1) goto loc_0216D3CA;
loc_0216D3C4:
a0 = t4 + 0;
    a0 = func_02197C78(a0);
loc_0216D3CA:
    return a0;}
