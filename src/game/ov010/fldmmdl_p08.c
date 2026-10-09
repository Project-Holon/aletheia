/*
 * file:     fldmmdl_p08.c
 * unit:     yes
 * function: func_0216E0E8, func_0216E114, func_0216E160, func_0216E174, func_0216E180, func_0216E190, func_0216E1A4, func_0216E1C4, func_0216E204, func_0216E280, func_0216E290, func_0216E29C, func_0216E2AC, func_0216E2E0, func_0216E2E8, func_0216E39C, func_0216E3C4, func_0216E3C8, func_0216E3CC, func_0216E3D0, func_0216E3D8, func_0216E400, func_0216E40C, func_0216E418, func_0216E42C, func_0216E434
 * address:  0x0216E0E8
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
 *   func_0216D67C  0x0216D67C  thumb  ov010
 *   func_0216D71C  0x0216D71C  thumb  ov010
 *   func_0216D59C  0x0216D59C  thumb  ov010
 *   func_0216D230  0x0216D230  thumb  ov010
 *   func_0216D268  0x0216D268  thumb  ov010
 *   func_0216D948  0x0216D948  thumb  ov010
 *   func_0216D57C  0x0216D57C  thumb  ov010
 *   func_02164010  0x02164010  thumb  ov010
 *   func_0216D674  0x0216D674  thumb  ov010
 *   func_0216DAA0  0x0216DAA0  thumb  ov010
 *   func_0216D744  0x0216D744  thumb  ov010
 *   func_0216DA88  0x0216DA88  thumb  ov010
 *   func_0216D570  0x0216D570  thumb  ov010
 *   func_02082BCC  0x02082BCC  arm
 *   func_0216D568 0x0216D568 thumb ov010
 *   func_0216D588  0x0216D588  thumb  ov010
 *   func_0216D598  0x0216D598  thumb  ov010
 *   func_0216D590  0x0216D590  thumb  ov010
 *   func_0216D55C  0x0216D55C  thumb  ov010
 *   func_0216D76C  0x0216D76C  thumb  ov010
 *   func_0216D594  0x0216D594  thumb  ov010
 *   func_0216DA94  0x0216DA94  thumb  ov010
 *   func_020490F4  0x020490F4  arm
 *   func_02049238  0x02049238  arm
 *   func_02048F4C  0x02048F4C  arm
 *   func_0216DD1C 0x0216DD1C thumb ov010
 *   func_0200F128 0x0200F128 thumb
 *   func_0204944C 0x0204944C arm
 *   func_0216D550  0x0216D550  thumb  ov010
 *   func_0216D548  0x0216D548  thumb  ov010
 *   func_020143CC 0x020143CC thumb
 *   d_021D5E04  0x021D5E04  data  ov093  a4
 *   d_021D770C  0x021D770C  data  ov021  a4
 *   func_020142E8  0x020142E8  thumb
 */
#include "../../matched/include/Obj17853.h"
#include "../../matched/include/Obj17854.h"
#include "../../matched/include/Obj09167.h"
#include "../../matched/include/Obj09168.h"
#include "../../matched/include/Obj00113.h"
#include "../../matched/include/Obj05908.h"
#include "../../matched/include/Obj17855.h"
#include "../../matched/include/Obj19134.h"
#include "../../matched/include/Obj12404.h"
#include "../../matched/include/Obj12405.h"
#include "../../matched/include/Obj19137.h"

struct Ctx;
struct Rec;
struct ArcFile;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed char s8;

typedef struct Obj {
    char pad[0x44];
    void *f44;
} Obj;

typedef struct {
    u16 w[14];
} Rec;

typedef struct Record { u16 fields[14]; } Record;

typedef signed short   s16;

extern void *func_0216D67C(void *a0);
extern int func_0216D71C(void *);
extern int func_0216D59C();
extern int func_0216D230(int a0);
extern int func_0216D268(int a0, int a1);
extern int func_0216D948(int a0);
extern u32 func_0216D57C(void *p, u32 v);
extern int func_02164010(int a);
extern int func_0216D674(void *, u16);
extern int func_0216DAA0(void *a0);
extern int func_0216D744();
extern int func_0216DA88();
extern char *func_0216D570(char *p, u32 v);
extern int func_02082BCC(void *, int, int);
extern void *func_0216D568(void *p, u32 v);
extern u16 func_0216D588(void *p);
extern u16 func_0216D598(void *p);
extern u16 func_0216D590(void *p);
extern int func_0216D55C(int a0, int a1);
extern int func_0216D76C(void *);
extern void func_0216D594(void *p, u32 v);
extern void func_0216DA94(void *a);
extern void *func_020490F4(u32, u32);
extern void func_02049238(void *p);
void func_02048F4C(void *dst, u32 archive_id, u32 member);
extern int func_0216DD1C(struct Ctx *, struct Rec **, u32 *);
extern u32 func_0200F128(u32 id);
extern void func_0204944C(struct ArcFile *arc, u32 member, u32 offset, u32 size, void *dst);
extern u32 *func_0216D550(u32 *p, u32 v);
extern unsigned int *func_0216D548(unsigned int *, unsigned int);
extern unsigned int func_020143CC(unsigned int, unsigned int);
extern unsigned int func_020142E8(void *bitmap, int id);
int func_0216E0E8(int a0, int a1);
int func_0216E114(int a0);
int func_0216E160(int a0);
void func_0216E174(void *a0);
int func_0216E180(void *a0);
void func_0216E190(void *a);
int func_0216E1A4(int a0, int a1);
int func_0216E1C4(int a0, int a1);
void func_0216E204(char *a, u32 v);
void *func_0216E280(int a0, int a1);
int func_0216E290(char *p);
void func_0216E29C(Obj *o, int v);
void func_0216E2AC(void *p, u32 i, Rec *out);
u16 func_0216E2E0(void *p);
void func_0216E2E8(const char *ctx, u32 id, Record *out);
void func_0216E39C(const char *ctx, u32 id, u8 *w);
void *func_0216E3C4(void *p);
void *func_0216E3C8(void *p);
u8 *func_0216E3CC(u8 *p);
int func_0216E3D0(int a, int b);
unsigned int func_0216E3D8(unsigned int a, unsigned int id);
u32 func_0216E400(int i);
u32 func_0216E40C(int i);
int func_0216E418(void *a);
unsigned int func_0216E42C(void *bitmap, int id);
u32 func_0216E434(u32 a);
extern u32 d_021D5E04[];
extern u32 d_021D770C[];







int func_0216E0E8(int a0, int a1)
{
    int t4;
    int t5;
    int t6;

t5 = a0 + 0;
t4 = a1 + 0;
    a0 = (int)func_0216D67C((void *)a0);
loc_0216E0F2:
t6 = a0 + 0;
a0 = t5 + 0;
    a0 = func_0216D71C((void *)a0);
loc_0216E0FA:
a0 = t5 + 0;
a1 = t4 + 0;
    a0 = func_0216D59C(a0, a1);
loc_0216E102:
a0 = t5 + 0;
    a0 = func_0216D230(a0);
loc_0216E108:
a0 = t6 + 0;
a1 = t5 + 0;
    a0 = func_0216D268(a0, a1);
loc_0216E110:
    return a0;}








/*
 * blocked:  listing 76 compiled 74
 */
int func_0216E114(int a0)
{
    int a1;
    int t4;

t4 = a0 + 0;
    a0 = (int)func_0216D67C((void *)a0);
loc_0216E11C:
    a0 = func_0216D948(a0);
loc_0216E120:
    if (a0 == 0) goto loc_0216E15C;
loc_0216E124:
a1 = 1;
a0 = t4 + 0;
a1 = a1 << 0xc;
    a0 = func_0216D57C((void *)a0, a1);
loc_0216E12E:
    if (a0 == 0) goto loc_0216E138;
loc_0216E132:
a0 = t4 + 0;
    a0 = func_02164010(a0);
loc_0216E138:
a0 = t4 + 0;
a1 = 0;
    a0 = func_0216D674((void *)a0, a1);
loc_0216E140:
a0 = t4 + 0;
    a0 = func_0216DAA0((void *)a0);
loc_0216E146:
    if (a0 != 0) goto loc_0216E15C;
loc_0216E14A:
a0 = t4 + 0;
    a0 = func_0216E160(a0);
loc_0216E150:
a0 = t4 + 0;
    a0 = func_0216D744(a0);
loc_0216E156:
a0 = t4 + 0;
    a0 = func_0216DA88(a0);
loc_0216E15C:
    return a0;}








int func_0216E160(int a0)
{
    int t4;
    void *p;

t4 = a0 + 0;
    p = func_0216E3C4((void *)a0);
loc_0216E168:
a0 = ((struct Obj17854 *)p)->f3;
    a0 = func_0216E40C(a0);
loc_0216E16E:
t4 = t4 + 0x90;
((struct Obj17853 *)((char *)t4))->f0 = a0;
    return a0;}







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
 *   python tools/match.py one --src src/matched/func_0216E174.c \
 *       --func func_0216E174 --addr 0x0216E174 --region ov010 --cc dsi/1.1p1 --thumb
 */
void func_0216E174(void *a0)
{

    func_0216D570(a0, 442368);
}







/*
 * generated: lane O24 (ov010 leaf/wrapper sweep)
 *
 * Tail call through a pool word and `bx r3`: a two-instruction
 * thunk into func_02082BCC, the shape of the arm9 copy.
 * (docs/idioms/tail-call-is-a-pool-word-and-bx.md)
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0216E180.c \
 *       --func func_0216E180 --addr 0x0216E180 --region ov010 --cc dsi/1.1p1 --thumb
 */
int func_0216E180(void *a0){

    func_02082BCC(a0, 0, 256);
}






void func_0216E190(void *a) { func_0216D568(a, 0x20); func_0216E174(a); }







int func_0216E1A4(int a0, int a1)
{
    int t4;
    int t5;

t5 = a0 + 0;
t4 = a1 + 0;
    a0 = func_0216D588((void *)a0);
loc_0216E1AE:
((struct Obj09167 *)((char *)t4))->f0 = a0;
a0 = t5 + 0;
    a0 = func_0216D598((void *)a0);
loc_0216E1B6:
((struct Obj09167 *)t4)->f2 = a0;
a0 = t5 + 0;
    a0 = func_0216D590((void *)a0);
loc_0216E1BE:
((struct Obj09167 *)t4)->f4 = a0;
    return a0;}







int func_0216E1C4(int a0, int a1)
{
    int t4;
    int t5;
    int t6;

t4 = a1 + 0;
a1 = 1;
t5 = a0 + 0;
t6 = 1;
    a0 = func_0216D55C(a0, a1);
loc_0216E1D2:
    if (a0 == 0) goto loc_0216E1FE;
loc_0216E1D6:
a0 = t5 + 0;
    a0 = func_0216D588((void *)a0);
loc_0216E1DC:
a1 = ((struct Obj09168 *)((char *)t4))->f0;
    if (a1 != a0) goto loc_0216E1FE;
loc_0216E1E2:
a0 = t5 + 0;
    a0 = func_0216D598((void *)a0);
loc_0216E1E8:
a1 = ((struct Obj09168 *)t4)->f2;
    if (a1 != a0) goto loc_0216E1FE;
loc_0216E1EE:
a0 = t5 + 0;
    a0 = func_0216D590((void *)a0);
loc_0216E1F4:
a1 = ((struct Obj09168 *)t4)->f4;
    if (a1 != a0) goto loc_0216E1FE;
loc_0216E1FA:
a0 = t6 + 0;
    return a0;
loc_0216E1FE:
a0 = 0;
    return a0;}






void func_0216E204(char *a, u32 v)
{
    void *ctx;
    char *p;

    ctx = func_0216D67C(a);
    if (func_0216D948((int)ctx) == 1 && func_0216DAA0(a) == 1)
        func_0216D76C(a);
    func_0216D594(a, v);
    func_0216E39C((const char *)ctx, v, (u8 *)a);
    p = a + 0xe4;
    ((struct Obj00113 *)a)->f7C = ((struct Obj05908 *)p)->fB;
    ((struct Obj00113 *)a)->f7D = ((struct Obj05908 *)p)->fC;
    *(s8 *)&((struct Obj00113 *)a)->f7E = ((struct Obj05908 *)p)->fD;
    *(s8 *)&((struct Obj00113 *)a)->f7F = ((struct Obj05908 *)p)->fE;
    *(s8 *)&((struct Obj00113 *)a)->f80 = ((struct Obj05908 *)p)->fF;
    func_0216DA94(a);
    func_0216E190(a);
    func_0216E114((int)a);
}






/*
 * blocked:  listing 16 compiled 14
 */
void *func_0216E280(int a0, int a1)
{
    int t4;
    void *p;

t4 = a0 + 0;
    p = func_020490F4(0x30, a1);
loc_0216E28A:
((struct Obj17855 *)t4)->f14 = p;
    return p;}






/*
 * Forwards the pointer at +0x14 to the arm9 routine at 0x02049238.
 */
int func_0216E290(char *p){
    func_02049238(((struct Obj19134 *)p)->f14);
}






/*
 * Unlabelled leaf (saves no lr, so disasm.py prints it as .word data):
 * a tail call through a pool word, the sole blocker of ov020 func_021857C0.
 */
void func_0216E29C(Obj *o, int v)
{
    func_02048F4C(o->f44, 0x3a, v);
}





/*
 * Unlabelled leaf, blocker of ov021 func_0219C680: copies record i (28 bytes) from the table at +0x44.
 * Overlay choice, ov009 and ov010 share this window; ov009 holds ARM code here,
 * ov010 holds this Thumb routine, and the ov021 callers already name ov010
 * (ov010 is the overlay resident with ov021).
 *
 * Addresses are Black-image addresses.
 */
void func_0216E2AC(void *p, u32 i, Rec *out)
{
    u16 *t = *(u16 * *)&((struct Obj12404 *)p)->f44;

    if (i < t[0]) {
        u16 k = (t[0] + 1) / 2 * 2;
        Rec *r = (Rec *)(t + (k + 2));

        *out = r[i];
    }
}





/*
 * Unlabelled leaf, blocker of ov021 func_0219C680: count halfword of the table at +0x44.
 * Overlay choice, ov009 and ov010 share this window; ov009 holds ARM code here,
 * ov010 holds this Thumb routine, and the ov021 callers already name ov010
 * (ov010 is the overlay resident with ov021).
 *
 * Addresses are Black-image addresses.
 */
u16 func_0216E2E0(void *p)
{
    return **(u16 * *)&((struct Obj12404 *)p)->f44;
}



/*
 * Direct halfword-aligned 28-byte Record assignments restore ctx=r5/id=r4/out=r6.
 * A named u16 offset and const context parameter restore the last stack store.
 * func_0216DD1C 0x0216DD1C thumb ov010
 * func_0216D598 0x0216D598 thumb ov010
 * func_0200F128 0x0200F128 thumb
 * func_0204944C 0x0204944C arm
 */
void func_0216E2E8(const char *ctx, u32 id, Record *out)
{
    u16 offset;
    int i;
    u32 j;
    u16 n;
    u16 *tbl;
    u32 iter;
    void *rec;

    tbl = *(u16 * *)&((struct Obj12405 *)ctx)->f44;
    n = tbl[0];

    if (n < 0x1a) {
        u16 k = ((n + 1) / 2) * 2;
        char *recs = (char *)tbl + (k + 2) * 2;
        for (i = 0; i < n; i++) {
            if (id == tbl[i + 1]) {
                u16 *src = (u16 *)(recs + i * 0x1c);
                *out = *(Record *)src;
                return;
            }
        }
    }
    iter = 0;
    if (func_0216DD1C((void *)ctx, (struct Rec **)(&rec), &iter)) {
        do {
            if (id == func_0216D598(rec)) {
                u16 *src = (u16 *)((char *)rec + 0xe4);
                *out = *(Record *)src;
                return;
            }
        } while (func_0216DD1C((void *)ctx, (struct Rec **)(&rec), &iter));
    }
    offset = func_0200F128(id) * 0x1c + 4;
    func_0204944C(((struct Obj12405 *)ctx)->f14, 0, offset, 0x1c, out);
}




void func_0216E39C(const char *ctx, u32 id, u8 *w)
{
    func_0216D550((u32 *)w, 1);
    func_0216E2E8(ctx, id, (Record *)(w + 0xe4));
    func_0216D548((u32 *)w, 1);
}




/*
 * generated: lane O24 (ov010 leaf/wrapper sweep)
 *
 * Returns the address of an interior member (field address), pool-free leaf.
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0216E3C4.c \
 *       --func func_0216E3C4 --addr 0x0216E3C4 --region ov010 --cc dsi/1.1p1 --thumb
 */
void *func_0216E3C4(void *p) { return (char *)p + 228; }



/*
 * Unlabelled leaf: adds r0, #0x10; bx lr.
 */
void *func_0216E3C8(void *p)
{
    return (char *)p + 0x10;
}




/*
 * Unlabelled leaf: returns its argument plus 0x10.
 *
 * Addresses are Black-image addresses.
 */
u8 *func_0216E3CC(u8 *p)
{
    return p + 0x10;
}




/*
 * Unlabelled thumb tail-call stub (ldr r3,[pc,#0]; bx r3; .word 0x0216E3D9);
 * the sole blocker of ov021 func_021B181C.
 */
int func_0216E3D0(int a, int b)
{
    return func_0216E3D8(a, b);
}



unsigned int func_0216E3D8(unsigned int a, unsigned int id) { if (id>=162 && id<=177) { if(a==0) id=10; else id=*(u16 *)func_020143CC(a,(u16)(id+0x3f7e)); } return id; }




/*
 * note: the parked file gave no overlay hint; un-hinted, sole-ref/data saw
 * data at 0x021D5E04 in several overlapping overlays and refused.  ov093 is
 * the one overlay where it is a data object start, so the hint fixes the
 * choice and the site resolves as sole-ref/data.
 */
u32 func_0216E400(int i)
{
    return d_021D5E04[i];
}




/*
 * note: the parked file gave no overlay hint; un-hinted, sole-ref saw data at
 * 0x021D770C in several overlapping overlays and refused.  ov021 is the
 * pointer-table home of the word (the ov021 datum is 0x021D86C0), so the hint
 * fixes the choice and the site resolves as sole-ref/self.
 */
u32 func_0216E40C(int i)
{
    return d_021D770C[i];
}



int func_0216E418(void *a) { if (((struct Obj19137 *)a)->fA==65535) return 1; return 0; }




/*
 * Tail call thunk: forwards its arguments unchanged to 0x020142E8.
 */
unsigned int func_0216E42C(void *bitmap, int id)
{
    return func_020142E8(bitmap, id);
}



/*
 * Classify an id: 1 for the eight 'special' values, the id itself otherwise.
 *
 * Addresses are Black-image addresses.
 */
u32 func_0216E434(u32 a)
{
switch (a) {
case 4:
case 5:
case 6:
case 7:
case 8:
case 11:
case 12:
case 13:
return 1;
}
return a;
}
