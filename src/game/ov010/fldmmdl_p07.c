/*
 * file:     fldmmdl_p07.c
 * unit:     yes
 * function: func_0216D9A0, func_0216D9E4, func_0216DA20, func_0216DA30, func_0216DA44, func_0216DA50, func_0216DA5C, func_0216DA70, func_0216DA7C, func_0216DA88, func_0216DA94, func_0216DAA0, func_0216DAB4, func_0216DAC8, func_0216DAE0, func_0216DAF8, func_0216DB04, func_0216DB10, func_0216DB24, func_0216DB4C, func_0216DB68, func_0216DB80, func_0216DB98, func_0216DBB4, func_0216DBCC, func_0216DBE8, func_0216DC00, func_0216DC18, func_0216DC34, func_0216DC4C, func_0216DC64, func_0216DC80, func_0216DC98, func_0216DCB4, func_0216DCCC, func_0216DCE8, func_0216DD04, func_0216DD1C, func_0216DD60, func_0216DDC0, func_0216DDDC, func_0216DE54, func_0216DE94, func_0216DEE0, func_0216DEEC, func_0216DF1C, func_0216DF64, func_0216DFAC, func_0216DFC4, func_0216E014, func_0216E084, func_0216E0AC
 * address:  0x0216D9A0
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
 *   func_0216D4DC  0x0216D4DC  thumb  ov010
 *   func_0216D4E4  0x0216D4E4  thumb  ov010
 *   func_0216D67C 0x0216D67C thumb ov010
 *   func_0216D4D4 0x0216D4D4 thumb ov010
 *   func_0216D55C  0x0216D55C  thumb  ov010
 *   func_0216D568  0x0216D568  thumb  ov010
 *   func_0216D570  0x0216D570  thumb  ov010
 *   func_0216D57C  0x0216D57C  thumb  ov010
 *   func_0216D548 0x0216D548 thumb ov010
 *   func_0216D550 0x0216D550 thumb ov010
 *   func_0216D948  0x0216D948  thumb  ov010
 *   func_0216D4F0  0x0216D4F0  thumb  ov010
 *   func_02082BCC  0x02082BCC  arm
 *   func_02163C04  0x02163C04  thumb  ov010
 *   func_0216D8AC  0x0216D8AC  thumb  ov010
 *   func_0209C054  0x0209C054  arm
 *   func_0216D5A0  0x0216D5A0  thumb  ov010
 *   func_0216D588  0x0216D588  thumb  ov010
 *   func_0216CF2C  0x0216CF2C  thumb  ov010
 *   func_02030DA8  0x02030DA8  arm
 *   func_0216D4F4  0x0216D4F4  thumb  ov010
 *   func_0216D514  0x0216D514  thumb  ov010
 *   func_0216D3A8  0x0216D3A8  thumb  ov010
 *   func_02030EAC  0x02030EAC  arm
 *   func_0216D598  0x0216D598  thumb  ov010
 *   func_0216D844  0x0216D844  thumb  ov010
 *   func_0216D85C  0x0216D85C  thumb  ov010
 *   func_0216D874  0x0216D874  thumb  ov010
 *   func_0216D89C  0x0216D89C  thumb  ov010
 *   func_02163F10  0x02163F10  thumb  ov010
 *   func_0216D5D8  0x0216D5D8  thumb  ov010
 *   func_0216D4B4  0x0216D4B4  thumb  ov010
 *   func_0216D71C  0x0216D71C  thumb  ov010
 *   func_0216CFC4  0x0216CFC4  thumb  ov010
 *   func_0216D02C  0x0216D02C  thumb  ov010
 *   func_0216D230  0x0216D230  thumb  ov010
 *   func_0216D268  0x0216D268  thumb  ov010
 *   func_0216D0E8  0x0216D0E8  thumb  ov010
 */
#include "../../matched/include/Obj17852.h"
#include "../../matched/include/Obj19133.h"
#include "../../matched/include/Obj00113.h"

struct Ctx;
struct Rec;
typedef unsigned int u32;

typedef unsigned char u8;

typedef unsigned short u16;

typedef signed short   s16_0216D9A0;

typedef signed char    s8;

typedef struct Rec {
    u8 data[0x100];
} Rec;

typedef struct Ctx {
    u8 pad[0x18];
    Rec *recs;
} Ctx;

typedef struct {
    int n;
    u8 *e[16];
} List;

typedef int s32;

typedef long long s64;

typedef short s16_0216DEE0;

extern void func_0216D4DC(void *map, u32 flag);
extern u32 *func_0216D4E4(u32 *p, u32 v);
extern void *func_0216D67C(void *p);
extern int func_0216D4D4(int a0, int a1);
extern int func_0216D55C(int a0, int a1);
extern void *func_0216D568(void *p, u32 v);
extern char *func_0216D570(char *p, u32 v);
extern u32 func_0216D57C(void *p, u32 v);
extern unsigned int *func_0216D548(unsigned int *, unsigned int);
extern u32 *func_0216D550(u32 *p, u32 v);
extern int func_0216D948(int a0);
extern u16 func_0216D4F0(void *p);
extern int func_02082BCC(void *, int, int);
extern int func_02163C04(int a, int x, int y, int flag);
extern u32 func_0216D8AC(void *p);
extern u16 func_0216D5A0(void *obj);
extern u16 func_0216D588(void *obj);
extern void func_0216CF2C(u8 *o);
extern u16 func_0216D4F4(void *p);
extern u32 func_0216D514(void *p);
extern void func_0216D3A8(u32 a, u32 b);
extern int func_02030DA8(int owner, int fn, int arg, int n);
extern int func_02030EAC();
extern u16 func_0216D598(void *p);
extern void func_0216D844(void *, short);
extern void func_0216D85C(void *p, int v);
extern void func_0216D874(int a0, int a1);
extern void func_0216D89C(void *p, const void *q);
extern int func_02163F10(int a0);
extern int func_0216D5D8(int a0, int a1);
extern void *func_0216D4B4(char *p);
extern int func_0216D71C(void *);
extern int func_0216CFC4(int a0, int a1);
extern void func_0216D02C(int a, u8 *p);
extern int func_0216D230(int a0);
extern int func_0216D268(int a0, int a1);
extern int func_0216D0E8();
void func_0216D9A0(void *map);
u32 *func_0216D9E4(void *c);
int func_0216DA20(void *p, unsigned int v);
int func_0216DA30(int a0, int a1);
void func_0216DA44(u32 a);
void func_0216DA50(u8 *p);
int func_0216DA5C(void *a0);
void func_0216DA70(void *a0);
void func_0216DA7C(u8 *p);
void func_0216DA88(void *a0, unsigned a1, unsigned a2, unsigned a3);
void func_0216DA94(void *a0);
int func_0216DAA0(void *a0);
int func_0216DAB4(void *a0);
void func_0216DAC8(unsigned int *p, unsigned int v);
void func_0216DAE0(unsigned int *p, unsigned int v);
void func_0216DAF8(void *a0);
char *func_0216DB04(void *a0);
int func_0216DB10(void *a0);
int func_0216DB24(int a0);
int func_0216DB4C(void *a0, int a1);
int func_0216DB68(void *a0);
void func_0216DB80(unsigned int *p, unsigned int v);
int func_0216DB98(void *a0, int a1);
int func_0216DBB4(void *a0);
int func_0216DBCC(void *a0, u32 a1, int a2);
int func_0216DBE8(void *a0);
int func_0216DC00(void *a0);
int func_0216DC18(void *a0, int a1);
int func_0216DC34(void *a0);
int func_0216DC4C(void *a0);
int func_0216DC64(void *a0, int a1);
int func_0216DC80(void *a0);
int func_0216DC98(void *a0, int a1);
int func_0216DCB4(void *a0);
int func_0216DCCC(void *a0, int a1);
int func_0216DCE8(void *a0, int a1);
int func_0216DD04(void *a0);
int func_0216DD1C(struct Ctx *, struct Rec **, u32 *);
int func_0216DD60(u32 x, u32 b, u32 c, u32 d, List *out);
void *func_0216DDC0(u32 a, u32 b, u32 c, u32 d);
u8 *func_0216DDDC(u32 a, u32 b, u32 c, s32 x, s32 lim, u32 d);
void *func_0216DE54(void *map, u32 kind);
void *func_0216DE94(void *map, u32 id);
void *func_0216DEE0(void *a0);
int func_0216DEEC(int a0);
void func_0216DF1C(u32 x);
void func_0216DF64(u8 *o, u32 b);
int func_0216DFAC(int a0);
int func_0216DFC4(void *a, u32 id);
void func_0216E014(void *a, int *p, int b);
void func_0216E084(void *a, unsigned int x, unsigned int y, unsigned int z, u16 k);
void func_0216E0AC(void *a0, void *a1);










void func_0216D9A0(void *map)
{
    u32 pos = 0;
    void *it;

    while (func_0216DD1C(map, (struct Rec **)(&it), &pos) == 1) {
        if (func_0216DC80(it) == 0)
            func_0216DAF8(it);
    }
    func_0216D4DC(map, 0x20);
}










/*
 * Releases every record func_0216DD1C yields, then func_0216D4E4(c, 0x20).
 */
u32 *func_0216D9E4(void *c)
{
    u32 iter;
    void *r;

    iter = 0;
    while (func_0216DD1C(c, (struct Rec **)(&r), &iter) == 1)
        func_0216DB04(r);
    return func_0216D4E4(c, 0x20);
}









int func_0216DA20(void *p, unsigned int v)
{
    return func_0216D4D4((int)func_0216D67C(p), v);
}










int func_0216DA30(int a0, int a1)
{
    int t4;

a1 = 1;
t4 = 1;
    a0 = func_0216D55C(a0, a1);
loc_0216DA3A:
    if (a0 != 0) goto loc_0216DA40;
loc_0216DA3E:
t4 = 0;
loc_0216DA40:
a0 = t4 + 0;
    return a0;}











/*
 * Tail call to func_0216D568 with a masked second argument.
 *
 * Addresses are Black-image addresses.
 */
void func_0216DA44(u32 a)
{
    func_0216D568((void *)a, 0x10);
}










/*
 * Thin wrapper: clear bit 4 of the word at +4 (tail call to func_0216D570).
 *
 * Addresses are Black-image addresses.
 */
void func_0216DA50(u8 *p)
{
func_0216D570((char *)p, 0x10);
}










/*
 * generated: lane O24 (ov010 leaf/wrapper sweep)
 *
 * Boolean-and-call leaf: a one-line predicate test over a
 * call whose result the compiler keeps in r0.
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0216DA5C.c \
 *       --func func_0216DA5C --addr 0x0216DA5C --region ov010 --cc dsi/1.1p1 --thumb
 */
int func_0216DA5C(void *a0)
{
    if (func_0216D57C(a0, 16))
        return 1;
    return 0;
}










/*
 * generated: lane O24 (ov010 leaf/wrapper sweep)
 *
 * Tail call through a pool word and `bx r3`: a two-instruction
 * thunk into func_0216D568, the shape of the arm9 copy.
 * (docs/idioms/tail-call-is-a-pool-word-and-bx.md)
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0216DA70.c \
 *       --func func_0216DA70 --addr 0x0216DA70 --region ov010 --cc dsi/1.1p1 --thumb
 */
void func_0216DA70(void *a0)
{

    func_0216D568(a0, 32);
}










/*
 * Thin wrapper: clear bit 6 of the word at +4 (tail call to func_0216D570).
 *
 * Addresses are Black-image addresses.
 */
void func_0216DA7C(u8 *p)
{
func_0216D570((char *)p, 0x40);
}










/*
 * generated: lane O24 (ov010 leaf/wrapper sweep)
 *
 * Tail call through a pool word and `bx r3`: a two-instruction
 * thunk into func_0216D568, the shape of the arm9 copy.
 * (docs/idioms/tail-call-is-a-pool-word-and-bx.md)
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0216DA88.c \
 *       --func func_0216DA88 --addr 0x0216DA88 --region ov010 --cc dsi/1.1p1 --thumb
 */
void func_0216DA88(void *a0, unsigned a1, unsigned a2, unsigned a3)
{

    func_0216D568(a0, 2);
}










/*
 * generated: lane O24 (ov010 leaf/wrapper sweep)
 *
 * Tail call through a pool word and `bx r3`: a two-instruction
 * thunk into func_0216D570, the shape of the arm9 copy.
 * (docs/idioms/tail-call-is-a-pool-word-and-bx.md)
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0216DA94.c \
 *       --func func_0216DA94 --addr 0x0216DA94 --region ov010 --cc dsi/1.1p1 --thumb
 */
void func_0216DA94(void *a0)
{

    func_0216D570(a0, 2);
}










/*
 * generated: lane O24 (ov010 leaf/wrapper sweep)
 *
 * Boolean-and-call leaf: a one-line predicate test over a
 * call whose result the compiler keeps in r0.
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0216DAA0.c \
 *       --func func_0216DAA0 --addr 0x0216DAA0 --region ov010 --cc dsi/1.1p1 --thumb
 */
int func_0216DAA0(void *a0)
{
    if (func_0216D57C(a0, 2))
        return 1;
    return 0;
}










/*
 * generated: lane O24 (ov010 leaf/wrapper sweep)
 *
 * Boolean-and-call leaf: a one-line predicate test over a
 * call whose result the compiler keeps in r0.
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0216DAB4.c \
 *       --func func_0216DAB4 --addr 0x0216DAB4 --region ov010 --cc dsi/1.1p1 --thumb
 */
int func_0216DAB4(void *a0)
{
    if (func_0216D55C((int)a0, 4))
        return 1;
    return 0;
}









void func_0216DAC8(unsigned int *p, unsigned int v)
{
    if (v == 1) func_0216D548(p, 4);
    else func_0216D550(p, 4);
}









void func_0216DAE0(unsigned int *p, unsigned int v)
{
    if (v == 1) func_0216D550(p, 128);
    else func_0216D548(p, 128);
}










/*
 * generated: lane O24 (ov010 leaf/wrapper sweep)
 *
 * Tail call through a pool word and `bx r3`: a two-instruction
 * thunk into func_0216D568, the shape of the arm9 copy.
 * (docs/idioms/tail-call-is-a-pool-word-and-bx.md)
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0216DAF8.c \
 *       --func func_0216DAF8 --addr 0x0216DAF8 --region ov010 --cc dsi/1.1p1 --thumb
 */
void func_0216DAF8(void *a0)
{

    func_0216D568(a0, 8);
}










/*
 * generated: lane O24 (ov010 leaf/wrapper sweep)
 *
 * Tail call through a pool word and `bx r3`: a two-instruction
 * thunk into func_0216D570, the shape of the arm9 copy.
 * (docs/idioms/tail-call-is-a-pool-word-and-bx.md)
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0216DB04.c \
 *       --func func_0216DB04 --addr 0x0216DB04 --region ov010 --cc dsi/1.1p1 --thumb
 */
char *func_0216DB04(void *a0)
{

    return func_0216D570(a0, 8);
}










/*
 * generated: lane O24 (ov010 leaf/wrapper sweep)
 *
 * Boolean-and-call leaf: a one-line predicate test over a
 * call whose result the compiler keeps in r0.
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0216DB10.c \
 *       --func func_0216DB10 --addr 0x0216DB10 --region ov010 --cc dsi/1.1p1 --thumb
 */
int func_0216DB10(void *a0)
{
    if (func_0216D57C(a0, 8))
        return 1;
    return 0;
}










int func_0216DB24(int a0)
{
    int t4;

t4 = a0 + 0;
    a0 = (int)func_0216D67C((void *)a0);
loc_0216DB2C:
    a0 = func_0216D948(a0);
loc_0216DB30:
    if (a0 != 0) goto loc_0216DB38;
loc_0216DB34:
a0 = 0;
    return a0;
loc_0216DB38:
a0 = t4 + 0;
    a0 = func_0216DAA0((void *)a0);
loc_0216DB3E:
    if (a0 == 0) goto loc_0216DB46;
loc_0216DB42:
a0 = 1;
    return a0;
loc_0216DB46:
a0 = 0;
    return a0;}










/*
 * The first argument picks which of the pair of field setters
 * takes the shifted mask and the value.
 */
int func_0216DB4C(void *a0, int a1)
{
    if (a1 == 1)
        return (int)func_0216D548(a0, 0x200);

    return (int)func_0216D550(a0, 0x200);
}










/*
 * generated: lane O24 (ov010 leaf/wrapper sweep)
 *
 * Boolean-and-call leaf: a one-line predicate test over a
 * call whose result the compiler keeps in r0.
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0216DB68.c \
 *       --func func_0216DB68 --addr 0x0216DB68 --region ov010 --cc dsi/1.1p1 --thumb
 */
int func_0216DB68(void *a0)
{
    if (func_0216D55C((int)a0, 512))
        return 1;
    return 0;
}









void func_0216DB80(unsigned int *p, unsigned int v)
{
    if (v == 1) func_0216D548(p, 32);
    else func_0216D550(p, 32);
}










int func_0216DB98(void *a0, int a1)
{
    int a2;
    if (a1 == 1)
        return (int)func_0216D548(a0, 0x800);

    return (int)func_0216D550(a0, 0x800);
}










/*
 * generated: lane O24 (ov010 leaf/wrapper sweep)
 *
 * Boolean-and-call leaf: a one-line predicate test over a
 * call whose result the compiler keeps in r0.
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0216DBB4.c \
 *       --func func_0216DBB4 --addr 0x0216DBB4 --region ov010 --cc dsi/1.1p1 --thumb
 */
int func_0216DBB4(void *a0)
{
    if (func_0216D55C((int)a0, 2048))
        return 1;
    return 0;
}










int func_0216DBCC(void *a0, u32 a1, int a2)
{
    if (a1 == 1)
        return (int)func_0216D568(a0, 0x40000);

    return (int)func_0216D570(a0, 0x40000);
}










/*
 * generated: lane O24 (ov010 leaf/wrapper sweep)
 *
 * Boolean-and-call leaf: a one-line predicate test over a
 * call whose result the compiler keeps in r0.
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0216DBE8.c \
 *       --func func_0216DBE8 --addr 0x0216DBE8 --region ov010 --cc dsi/1.1p1 --thumb
 */
int func_0216DBE8(void *a0)
{
    if (func_0216D57C(a0, 262144))
        return 1;
    return 0;
}









/*
 * generated: lane O24 (ov010 leaf/wrapper sweep)
 *
 * Boolean-and-call leaf: a one-line predicate test over a
 * call whose result the compiler keeps in r0.
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0216DC00.c \
 *       --func func_0216DC00 --addr 0x0216DC00 --region ov010 --cc dsi/1.1p1 --thumb
 */
int func_0216DC00(void *a0)
{
    if (func_0216D55C((int)a0, 4096))
        return 1;
    return 0;
}









int func_0216DC18(void *a0, int a1)
{
    int a2;
    if (a1 == 1)
        return (int)func_0216D568(a0, 0x20000);

    return (int)func_0216D570(a0, 0x20000);
}









/*
 * generated: lane O24 (ov010 leaf/wrapper sweep)
 *
 * Boolean-and-call leaf: a one-line predicate test over a
 * call whose result the compiler keeps in r0.
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0216DC34.c \
 *       --func func_0216DC34 --addr 0x0216DC34 --region ov010 --cc dsi/1.1p1 --thumb
 */
int func_0216DC34(void *a0)
{
    if (func_0216D57C(a0, 131072))
        return 1;
    return 0;
}









/*
 * generated: lane O24 (ov010 leaf/wrapper sweep)
 *
 * Boolean-and-call leaf: a one-line predicate test over a
 * call whose result the compiler keeps in r0.
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0216DC4C.c \
 *       --func func_0216DC4C --addr 0x0216DC4C --region ov010 --cc dsi/1.1p1 --thumb
 */
int func_0216DC4C(void *a0)
{
    if (func_0216D57C(a0, 512))
        return 1;
    return 0;
}









int func_0216DC64(void *a0, int a1)
{
    int a2;
    if (a1 == 1)
        return (int)func_0216D568(a0, 0x80000);

    return (int)func_0216D570(a0, 0x80000);
}









/*
 * generated: lane O24 (ov010 leaf/wrapper sweep)
 *
 * Boolean-and-call leaf: a one-line predicate test over a
 * call whose result the compiler keeps in r0.
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0216DC80.c \
 *       --func func_0216DC80 --addr 0x0216DC80 --region ov010 --cc dsi/1.1p1 --thumb
 */
int func_0216DC80(void *a0)
{
    if (func_0216D57C(a0, 524288))
        return 1;
    return 0;
}









int func_0216DC98(void *a0, int a1)
{
    int a2;
    if (a1 == 1)
        return (int)func_0216D548(a0, 0x400);

    return (int)func_0216D550(a0, 0x400);
}









/*
 * generated: lane O24 (ov010 leaf/wrapper sweep)
 *
 * Boolean-and-call leaf: a one-line predicate test over a
 * call whose result the compiler keeps in r0.
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0216DCB4.c \
 *       --func func_0216DCB4 --addr 0x0216DCB4 --region ov010 --cc dsi/1.1p1 --thumb
 */
int func_0216DCB4(void *a0)
{
    if (func_0216D55C((int)a0, 1024))
        return 1;
    return 0;
}








int func_0216DCCC(void *a0, int a1)
{
    int a2;
    if (a1 == 1)
        return (int)func_0216D568(a0, 0x100000);

    return (int)func_0216D570(a0, 0x100000);
}








int func_0216DCE8(void *a0, int a1)
{
    int a2;
    if (a1 == 1)
        return (int)func_0216D568(a0, 0x200000);

    return (int)func_0216D570(a0, 0x200000);
}








/*
 * generated: lane O24 (ov010 leaf/wrapper sweep)
 *
 * Boolean-and-call leaf: a one-line predicate test over a
 * call whose result the compiler keeps in r0.
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0216DD04.c \
 *       --func func_0216DD04 --addr 0x0216DD04 --region ov010 --cc dsi/1.1p1 --thumb
 */
int func_0216DD04(void *a0)
{
    if (func_0216D57C(a0, 2097152))
        return 1;
    return 0;
}








/*
 * Iterator: advances *iter over the 0x100-byte records at +0x18 and
 * returns TRUE with *out set at the next record func_0216D55C accepts.
 */
int func_0216DD1C(struct Ctx *c, struct Rec **out, u32 *iter){
    u32 n;
    Rec *r;

    n = func_0216D4F0(c);
    if (*iter < n) {
        r = &c->recs[*iter];
        do {
            (*iter)++;
            if (func_0216D55C((int)r, 1)) {
                *out = r;
                return 1;
            }
            r++;
        } while (*iter < n);
    }
    return 0;
}






/*
 * Collects up to 16 matching objects into a 0x44-byte result block
 * (count word, then the pointers).
 */
int func_0216DD60(u32 x, u32 b, u32 c, u32 d, List *out)
{
    int n;
    u8 *o;

    n = 0;
    func_02082BCC(out, 0, 0x44);
    while (func_0216DD1C((struct Ctx *)x, (struct Rec **)(&o), (u32 *)(&n)) == 1) {
        if (func_02163C04((int)o, b, c, d) == 1) {
            int i = out->n++;
            out->e[i] = o;
            if (out->n >= 16)
                break;
        }
    }
    return out->n;
}




void *func_0216DDC0(u32 a, u32 b, u32 c, u32 d)
{
    List out;
    if (func_0216DD60(a, b, c, d, &out) != 0)
        return out.e[0];
    return 0;
}





u8 *func_0216DDDC(u32 a, u32 b, u32 c, s32 x, s32 lim, u32 d)
{
    List buf;
    u32 i;
    u32 n;

    n = func_0216DD60(a, b, c, d, &buf);
    if (n == 0)
        return 0;
    for (i = 0; i < n; i++) {
        s32 q = func_0216D8AC(buf.e[i]) - x;

        if (q < 0)
            q = (s32)(((s64)q * (s64)(s32)0xFFFFF000 + 0x800) >> 12);
        if (q < lim)
            return buf.e[i];
    }
    return 0;
}





/*
 * First object of the given kind in the map (func_0216DD1C walks it),
 * or NULL.
 */
void *func_0216DE54(void *map, u32 kind)
{
    u32 iter;
    void *obj;

    iter = 0;
    while (func_0216DD1C(map, (struct Rec **)(&obj), &iter) == 1) {
        if (func_0216D5A0(obj) == kind)
            return obj;
    }
    return 0;
}





/*
 * First free object (func_0216DBB4 zero) with the given id in the map,
 * or NULL (func_0216DE54 is the by-kind twin).
 */
void *func_0216DE94(void *map, u32 id)
{
    u32 iter;
    void *obj;

    iter = 0;
    while (func_0216DD1C(map, (struct Rec **)(&obj), &iter) == 1) {
        if (func_0216DBB4(obj) == 0 && func_0216D588(obj) == id)
            return obj;
    }
    return 0;
}




/*
 * generated: lane O24 (ov010 leaf/wrapper sweep)
 *
 * Tail call through a pool word and `bx r3`: a two-instruction
 * thunk into func_0216DE94, the shape of the arm9 copy.
 * (docs/idioms/tail-call-is-a-pool-word-and-bx.md)
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0216DEE0.c \
 *       --func func_0216DEE0 --addr 0x0216DEE0 --region ov010 --cc dsi/1.1p1 --thumb
 */
void *func_0216DEE0(void *a0)
{
    return func_0216DE94(a0, 255);
}




int func_0216DEEC(int a0)
{
    int a1;
    int t4;
    int t5;
    int t6;
    int t7;

t5 = a0 + 0;
t4 = 0;
    a0 = func_0216D4F0((void *)a0);
loc_0216DEF6:
t7 = 1;
t5 = ((struct Obj17852 *)t5)->f18;
t6 = a0 + 0;
t7 = t7 << 8;
loc_0216DEFE:
a0 = t5 + 0;
a1 = 1;
    a0 = func_0216D55C(a0, a1);
loc_0216DF06:
    if (a0 != 0) goto loc_0216DF0E;
loc_0216DF0A:
a0 = t5 + 0;
    return a0;
loc_0216DF0E:
t4 = t4 + 1;
t5 = t5 + t7;
    if (t4 < t6) goto loc_0216DEFE;
loc_0216DF16:
a0 = 0;
    return a0;}




void func_0216DF1C(u32 x)
{
    int n;
    u8 *o;
    u32 k = 0x20;

    n = 0;
    while (func_0216DD1C((struct Ctx *)x, (struct Rec **)(&o), (u32 *)(&n))) {
        if (func_0216D55C((int)o, k) == 0) {
            func_0216D588(o);
            func_0216CF2C(o);
        }
    }
}




void func_0216DF64(u8 *o, u32 b)
{
    int d = 0;
    int base = func_0216D4F4((void *)b);
    int t = func_0216D5A0(o);

    if (t == 0x30 || t == 0x32)
        d = 1;
    else if (func_0216D588(o) == 0xff)
        d--;
    ((struct Obj19133 *)o)->f84 = func_02030DA8(func_0216D514((void *)b), (int)func_0216D3A8, (int)o, base + d);
}




int func_0216DFAC(int a0)
{
    int t4;

t4 = a0 + 0;
a0 = a0 + 0x84;
a0 = *(int *)&((struct Obj00113 *)((char *)a0))->f0;
    if (a0 == 0) goto loc_0216DFC2;
loc_0216DFB8:
    a0 = func_02030EAC(a0);
loc_0216DFBC:
a0 = 0;
t4 = t4 + 0x84;
*(int *)&((struct Obj00113 *)((char *)t4))->f0 = a0;
loc_0216DFC2:
    return a0;}




int func_0216DFC4(void *a, u32 id)
{
    u32 iter = 0;
    void *out;
    void *ctx;

    ctx = func_0216D67C(a);
    while (func_0216DD1C(ctx, (struct Rec **)(&out), &iter) == 1) {
        if (out != a) {
            u32 v = func_0216D598(out);
            if (v != 0xFFFF && v == id)
                return 1;
        }
    }
    return 0;
}




void func_0216E014(void *a, int *p, int b)
{
    func_0216D844(a, (s16_0216DEE0)((p[0] >> 4) / 4096));
    func_0216D85C(a, (s16_0216DEE0)((p[1] >> 4) / 4096));
    func_0216D874((int)a, (s16_0216DEE0)((p[2] >> 4) / 4096));
    func_0216D89C(a, p);
    func_02163F10((int)a);
    func_0216D5D8((int)a, b);
    func_0216D4B4(a);
    func_0216D568(a, 0x20);
    func_0216D570(a, 0x50);
}



void func_0216E084(void *a, unsigned int x, unsigned int y, unsigned int z, u16 k) { int p[3]; p[0]=(x<<16)+0x8000; p[1]=y<<16; p[2]=(z<<16)+0x8000; func_0216E014(a,p,k); }


void func_0216E0AC(void *a0, void *a1)
{
    void *t4;
    void *t5;
    int t6;

t5 = a0;
t4 = a1;
    t6 = (int)func_0216D67C(a0);
loc_0216E0B6:
    func_0216D71C(t5);
loc_0216E0BE:
    func_0216CFC4((int)t5, (int)t4);
loc_0216E0C6:
    func_0216D02C((int)t5, t4);
loc_0216E0CE:
    func_0216D230((int)t5);
loc_0216E0D4:
    func_0216D268(t6, (int)t5);
loc_0216E0DC:
    func_0216D0E8(t5, t4, 0);
loc_0216E0E6:
    return;}
