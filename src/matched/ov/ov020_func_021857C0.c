/*
 * function: func_021857C0
 * address:  0x021857C0
 * packet:   pkt_ov020_021857C0
 * region:   ov020
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020120F4  0x020120F4  thumb
 *   func_020127A4  0x020127A4  thumb
 *   func_02012844  0x02012844  thumb
 *   func_02012B38  0x02012B38  thumb
 *   func_02014454  0x02014454  thumb
 *   func_02012870  0x02012870  thumb
 *   func_0201289C  0x0201289C  thumb
 *   func_02012AC4  0x02012AC4  thumb
 *   func_02012ACC  0x02012ACC  thumb
 *   func_020141DC  0x020141DC  thumb
 *   func_02012A90  0x02012A90  thumb
 *   func_02012AA4  0x02012AA4  thumb
 *   func_02012ABC  0x02012ABC  thumb
 *   func_02012134  0x02012134  thumb
 *   func_0202B544  0x0202B544  thumb
 *   func_02012854  0x02012854  thumb
 *   func_02012900  0x02012900  thumb
 *   func_0202C83C  0x0202C83C  thumb
 *   func_0201405C  0x0201405C  thumb
 *   func_02012964  0x02012964  thumb
 *   func_02185788  0x02185788  thumb  ov020
 *   func_02185758  0x02185758  thumb  ov020
 *   func_02185B9C  0x02185B9C  thumb  ov020
 *   func_021858E4  0x021858E4  thumb  ov020
 *   func_02185A34  0x02185A34  thumb  ov020
 *   func_021859FC  0x021859FC  thumb  ov020
 *   func_02159FE0  0x02159FE0  thumb  ov010
 *   func_02168EEC  0x02168EEC  thumb  ov010
 *   func_021643E8  0x021643E8  thumb  ov010
 *   func_0215A014  0x0215A014  thumb  ov010
 *   func_02158AE0  0x02158AE0  thumb  ov010
 *   func_0216E29C  0x0216E29C  thumb  ov010
 *   func_0216CCCC  0x0216CCCC  thumb  ov010
 */

typedef unsigned short u16;
typedef short          s16;

typedef struct Obj {
    int f0;
    s16 h4, h6, h8, ha;
    int fc, f10, f14, f18;
} Obj;

struct BigObj;
struct Ctx;
struct H4;
struct Rec020141DC;
struct Rec1C;
struct Rec44;
struct SaveBlock;
struct Vec12;
void *func_020120F4(const struct Ctx *p);
void *func_020127A4(struct SaveBlock *p);
int func_02012844(void *p);
void *func_02012B38(const struct BigObj *p);
typedef unsigned int   u32;
typedef unsigned char  u8;
struct BigObj;
struct Rec44;
struct Sub02014444Obj;
void func_02014454(struct Sub02014444Obj *o, u8 v);
struct Rec1C *func_02012870(const struct BigObj *p);
void func_0201289C(struct BigObj *p, const struct Rec1C *src);
void func_02012AC4(struct Rec44 *p, u16 v);
void func_02012ACC(void *p, int v);
int func_020141DC(const struct Rec020141DC *p);
void func_02012A90(struct Rec44 *p, const struct Vec12 *src);
void func_02012AA4(struct Rec44 *p, const struct H4 *src);
void func_02012ABC(struct Rec44 *p, u8 v);
void *func_02012134(void *p);
void func_0202B544(u32 a, u16 b);
void func_02012854(struct BigObj *p, const struct Rec1C *src);
void func_02012900(const struct BigObj *p, u16 v);
int func_0202C83C(int a0, int a1);
int func_0201405C(u16 v);
u32 func_02012964(const struct BigObj *p);
void func_02185788(int a, int b, Obj *o);
int func_02185758(int v);
void func_02185B9C(int a0, int id);
void func_021858E4(int a, const short *p);
void func_02185A34(void *p, unsigned int id);
void func_021859FC(void *p, const short *s);
int func_02159FE0(int v);
void func_02168EEC(int a);
void func_021643E8(void *p, u16 v);
void func_0215A014(void *p, int v);
void func_02158AE0(void *a0, void *a1);
void func_0216E29C(struct Obj *o, int v);
void func_0216CCCC(struct Obj *o);

void func_021857C0(void *a, int b)
{
    void *r5;
    void *r4;
    int t;
    Obj s;
    u16 v;
    int n;
    void *q;

    r5 = func_020120F4(a);
    r4 = func_020127A4(r5);
    t = (int)func_02012844(r5);
    func_02014454(func_02012B38(r5), 1);
    func_02185788(t, b, &s);
    if (s.f0 == 3)
        func_0201289C(r5, func_02012870(r5));
    func_02012AC4(r4, s.h4);
    func_02012ACC(r4, func_02185758(s.h8));
    if (func_020141DC((const struct Rec020141DC *)(&s)) == 0) {
        func_02012A90(r4, (const struct Vec12 *)(&s.f10));
        func_02012ABC(r4, 0);
    } else {
        func_02012AA4(r4, (const struct H4 *)(&s.f10));
        func_02012ABC(r4, 1);
    }
    func_0202B544((u32)func_02012134(a), s.h4);
    func_02012854(r5, (const struct Rec1C *)(&s));
    v = func_02159FE0(s.h4);
    if (v != 0)
        func_02012900(r5, v);
    func_02185B9C((int)r5, s.h4);
    func_02168EEC((int)r5);
    func_021643E8(r5, s.h4);
    func_0215A014(r5, s.h4);
    func_02158AE0(a, (void *)4);
    func_021858E4((int)r5, (const short int *)b);
    func_02185A34(r5, (u16)s.h4);
    func_021859FC(r5, (const short int *)(&s));
    func_0202C83C((int)a, s.h4);
    n = (int)func_0201405C((u16)s.h4);
    q = (void *)func_02012964(r5);
    if (n < 16)
        func_0216E29C(q, n);
    else
        func_0216CCCC(q);
}
