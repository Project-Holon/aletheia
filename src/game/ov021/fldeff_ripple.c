/*
 * file:     fldeff_ripple.c
 * unit:     yes
 * function: func_021C3670, func_021C36B0, func_021C36EC, func_021C37F8, func_021C385C, func_021C3898, func_021C38DC, func_021C38F4, func_021C3A00, func_021C3A44, func_021C3A70, func_021C3A7C, func_021C3A90, func_021C3AAC, func_021C3ADC, func_021C3B0C, func_021C3B2C, func_021C3BB0, func_021C3BCC, func_021C3BD4, func_021C3C04, func_021C3C30, func_021C3C5C, func_021C3C78, func_021C3C88, func_021C3D1C, func_021C3DA8, func_021C3DE4, func_021C3E38, func_021C3E64, func_021C3F60, func_021C3FC0, func_021C4018, func_021C4024, func_021C4030, func_021C4078, func_021C4084, func_021C40F8, func_021C4160, func_021C4238, func_021C42BC, func_021C42F4, func_021C4340, func_021C447C, func_021C4504, func_021C452C, func_021C457C, func_021C459C, func_021C4608, func_021C4628, func_021C4678, func_021C46A4, func_021C46F8, func_021C474C, func_021C4788, func_021C47B4, func_021C47E8, func_021C47FC, func_021C483C, func_021C484C
 * address:  0x021C3670
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
 *   func_02017E1C  0x02017E1C  thumb
 *   d_021DA8D8     0x021DA8D8  data  ov021  a4
 *   func_0200BCA8  0x0200BCA8  thumb
 *   func_0200BCEC  0x0200BCEC  thumb
 *   func_02019C90  0x02019C90  thumb
 *   func_0200BCB8  0x0200BCB8  thumb
 *   func_021C34C4  0x021C34C4  thumb  ov021
 *   func_02188C80  0x02188C80  thumb  ov021
 *   func_020120F4  0x020120F4  thumb
 *   func_02012944  0x02012944  thumb
 *   func_0200BC2C  0x0200BC2C  thumb
 *   func_02012F98  0x02012F98  thumb
 *   func_02007C34  0x02007C34  thumb
 *   func_02082BCC  0x02082BCC  arm
 *   d_021DA960     0x021DA960  data  ov021  a4
 *   func_02005728  0x02005728  thumb  ov021
 *   func_0201ADE4  0x0201ADE4  thumb
 *   func_0201AE1C  0x0201AE1C  thumb
 *   func_0201AE14  0x0201AE14  thumb
 *   d_021DA930     0x021DA930  data  ov021  a4
 *   d_021DA918     0x021DA918  data  ov021  a4
 *   func_02008530  0x02008530  thumb
 *   func_02017ED8  0x02017ED8  thumb
 *   func_0201ADD0  0x0201ADD0  thumb
 *   func_02048F60  0x02048F60  arm
 *   func_020307B0  0x020307B0  arm
 *   d_021DA908     0x021DA908  data  ov021  a4
 *   d_021DA8F8     0x021DA8F8  data  ov021  a4
 *   func_020212B0  0x020212B0  thumb
 *   d_021DA8E8     0x021DA8E8  data  ov021  a4
 *   func_02017588  0x02017588  thumb
 *   func_02017E40  0x02017E40  thumb
 *   func_02018A00  0x02018A00  thumb
 *   func_02008510  0x02008510  thumb
 *   func_02045808  0x02045808  arm
 *   func_02045EC0  0x02045EC0  arm
 *   func_0202F190  0x0202F190  thumb
 *   func_02018198  0x02018198  thumb
 *   func_020185C4  0x020185C4  thumb
 *   func_0201B9F0  0x0201B9F0  thumb
 *   g_020A7370     0x020A7370  data
 *   d_021DA948     0x021DA948  data  ov021  a4
 *   func_02021288  0x02021288  thumb
 *   func_0202130C  0x0202130C  thumb
 *   func_021C1094  0x021C1094  thumb  ov021
 *   func_021C10A0  0x021C10A0  thumb  ov021
 *   func_0215A64C  0x0215A64C  thumb  ov010
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_0201210C  0x0201210C  thumb
 *   func_02188CB4  0x02188CB4  thumb  ov021
 *   func_021A3074  0x021A3074  thumb  ov021
 *   func_0216D5F8  0x0216D5F8  thumb  ov010
 *   func_02188C98  0x02188C98  thumb  ov021
 *   func_0215A5CC  0x0215A5CC  thumb  ov010
 *   func_021A3364  0x021A3364  thumb  ov021
 *   func_021AB0D4  0x021AB0D4  thumb  ov021
 *   func_021C1024  0x021C1024  thumb  ov021
 *   func_0215A644  0x0215A644  thumb  ov010
 *   func_020113D0  0x020113D0  thumb
 *   func_021C12C4  0x021C12C4  thumb  ov021
 *   func_021C12D0  0x021C12D0  thumb  ov021
 *   func_021A3050  0x021A3050  thumb  ov021
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_021C1228  0x021C1228  thumb  ov021
 *   func_02188CD0  0x02188CD0  thumb  ov021
 *   func_021C9550  0x021C9550  thumb  ov021
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_021D2418  0x021D2418  thumb  ov021
 *   func_021D2440  0x021D2440  thumb  ov021
 *   func_0215897C  0x0215897C  thumb  ov010
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   func_02034AC4  0x02034AC4  arm
 *   abs_id_3f      0x0000003F  data
 *   func_021A305C  0x021A305C  thumb  ov021
 *   func_021F36C0  0x021F36C0  thumb  ov037
 *   ov063_id       0x0000003F  data
 *   func_021F3758  0x021F3758  thumb  ov063
 *   func_021F376C  0x021F376C  thumb  ov063
 *   func_021ABE14  0x021ABE14  thumb  ov021
 *   func_02188C90  0x02188C90  thumb  ov021
 *   d_021DE468     0x021DE468  data  ov021
 *   func_021ABE24  0x021ABE24  thumb  ov021
 *   func_02046E24  0x02046E24  arm
 *   func_021AC1F0  0x021AC1F0  thumb  ov021
 *   func_020500F0  0x020500F0  arm
 *   func_02050278  0x02050278  arm
 *   func_02164280  0x02164280  thumb  ov010
 *   func_021ABEA0  0x021ABEA0  thumb  ov021
 *   func_021ABFA8  0x021ABFA8  thumb  ov021
 *   d_021DA9F0     0x021DA9F0  data  a4
 */
#include "../../matched/include/Obj03142.h"
#include "../../matched/include/Obj18302.h"
#include "../../matched/include/Obj00358.h"
#include "../../matched/include/Obj18303.h"
#include "../../matched/include/Obj09211.h"
#include "../../matched/include/Obj20193.h"
#include "../../matched/include/Obj20194.h"
#include "../../matched/include/Obj02093.h"
#include "../../matched/include/Obj12131.h"

struct Ctx;
struct Sub02007AC8Entry;
struct Personal;
struct Sub0200852CObj;
struct Mon;
struct MsgBank;
struct U16Vec;
struct Obj00020;
struct Desc;
struct Obj;
struct P_021C474C;
struct BbActRec;
struct BbActSys;
struct X;
typedef unsigned int u32;

typedef struct { u32 v[4]; } T4;

typedef unsigned short u16;

typedef unsigned char u8;

typedef struct {
    u32 f0;
    u32 f4;
    void *box;
    u16 steps;
} S_021C3670;

typedef signed short   s16;

typedef signed char    s8;

typedef struct {
    u32 species;
    u32 form;
    u32 level;
    u32 f0C;
    u32 f10;
    u32 f14;
    u32 iv[6];
    u32 f30;
    u32 f34;
    u32 f38;
    u32 mv[4];
    u32 f4C;
    u32 f50;
    u32 f54;
    u32 a[6];
    u32 b[6];
    u32 n;
} S_021C38F4;

typedef struct { u32 a, b, c; } E;

typedef struct { E e[12]; } T_021C3A7C;

typedef struct { u32 v[6]; } T6;

typedef struct { u32 v[6]; } T_021C3F60;

typedef struct { u16 x, y; } P_021C3670;

typedef struct { u32 v[4]; } T;

typedef unsigned long long u64;

typedef signed int     s32;

typedef struct {
    void *owner;
    u32 obj;
    u32 f8;
} R;

typedef signed int     s32_021C47E8;

typedef struct S { u32 w0; u8 b4, b5, b6, b7; u32 w8; } S;

typedef struct P_021C474C { u32 f0; u32 f4; u16 f8; } P_021C474C;

typedef int            s32_021C484C;

typedef struct Vec3 { s32_021C484C x, y, z; } Vec3;

typedef struct Arg { u32 a; Vec3 v; } Arg;

extern u32 func_02017E1C(void *, u32, u32);
extern int func_0200BCA8(void *e, int i);
extern void func_0200BCEC(void *e, int i, int j);
extern u32 func_02019C90(u16 a, u16 b, u32 k);
extern int func_0200BCB8(void *e);
extern u32 func_02005728(u32 v);
extern u8 func_021C34C4(void **p);
extern void *func_02188C80(void *p);
extern void *func_020120F4(const struct Ctx *p);
extern u8 *func_02012944(void *p);
extern u32 func_0200BC2C(u32, int);
extern u32 func_02007C34(u32, u32);
extern struct Sub02007AC8Entry *func_02012F98(void *p);
extern u32 func_02082BCC(u32, u32, u32, u32);
extern void *func_0201ADE4(u32 a, int b, u32 heap);
extern u32 func_0201AE1C(const struct Personal *p, u32 field);
extern void func_0201AE14(void *p);
u32 func_02008530(const struct Sub0200852CObj *obj);
extern u32 func_02017ED8(u32 a, u32 b);
extern void func_0201ADD0(unsigned int species, int form, void *dest);
extern void *func_02048F60(u32 archive, u32 member, u32 heap);
extern u32 func_020307B0(void *p);
extern u16 func_020212B0(u16 id);
extern void func_02017588(struct Mon *p, u16 species, u16 level, unsigned long long id, u32 pow, unsigned long long rnd);
extern void func_02017E40(void *mon, u32 id, u32 v);
extern void func_02018A00(void *mon, u32 species, u32 form);
extern void *func_02008510(void *a, int tag);
extern void func_02045808(struct U16Vec *vec);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void func_0202F190(void *a0, u32 a1, u32 a2, u32 a3, u16 a4);
extern void func_02018198(void *mon);
extern void func_020185C4(void *mon);
extern void func_0201B9F0(void *mon);
extern u32 func_02021288(u32 a);
extern u32 func_0202130C(u32 a);
extern void func_02048F74(void *dst, u32 archive_id, u32 member, u32 mode, u32 *size_out);
extern void *func_0215A64C(void *a);
extern int func_021C1094(void *x);
extern int func_021C10A0(u32 a);
extern void *func_0215A5DC(void *a0);
extern void *func_0201210C(const struct Ctx *p);
extern void *func_02188CB4(struct Obj00020 *p);
extern void *func_021A3074(unsigned char *p);
extern u16 func_0216D5F8(void *p);
extern u32 func_02188C98(u8 *p);
extern u16 func_0215A5CC(void *a0);
extern void func_021A3364(u32 *a, int b, int *out);
extern int func_021AB0D4(void *a, void *b);
extern u32 func_021C1024(void *a, u32 b, u32 c, u32 d);
extern void func_0215A644(void *p, u32 v);
extern void func_020113D0(char *p, int val);
extern int func_021C12C4(void *x);
extern void func_021C12D0(void *x);
extern u16 func_021A3050(u8 *p);
extern u32 func_02159B10(void *a, void *b);
extern u32 func_021C1228(void *a, u32 b, u32 c, u32 d);
extern u32 func_02188CD0(u8 *p);
extern void func_021C9550(u32 a, u32 b);
extern void *func_0215A5F4(void *p);
extern void *func_021D2418(void *a, u32 b);
extern void *func_021D2440(void *a, u32 b, u32 c);
extern void func_0215897C(void *a, void *b);
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern void *func_020124E8(struct Obj *p);
extern int func_02034AC4(int a);
extern void func_021A305C(char *p, u32 b);
extern void *func_021F36C0(void *a, u32 b, u32 c, u32 d);
extern void func_02034A5C(s32 handle);
extern int func_021F376C(int *p);
extern void func_021F3758(u8 *p);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u32 func_021ABE14(u8 *p);
extern u32 func_02188C90(u8 *p);
extern u32 func_021ABE24(u8 *p);
extern void *func_02046E24(u32 a0, u32 a1);
extern void func_021AC1F0(struct X *x, void *b);
extern u16 func_020500F0(struct BbActSys *o, const struct BbActRec *recs, u32 n);
extern void func_02050278(struct BbActSys *o, u32 first, u32 count);
extern void func_02164280(int x, int y, int *p);
extern int func_021ABEA0(u32 a, u32 b);
extern void func_021ABFA8(u32 a, u8 *b, u32 c, u32 d, Arg *e, u32 f);
int func_021C3670(void *a, u32 b);
void func_021C36B0(void *e);
int func_021C36EC(u32 a, u32 b);
int func_021C37F8(u32 a, u32 b);
int func_021C385C(S_021C3670 *p);
void func_021C3898(u32 *p, u32 c);
int func_021C38DC(u32 a, u32 b);
void func_021C38F4(u16 heap, void *b, void *c, u32 m0, u32 m1, void *mon);
void func_021C3A00(u32 *p);
void func_021C3A44(void **p);
void func_021C3A70(u32 *p);
int func_021C3A7C();
void func_021C3A90(void *a, u32 *out);
void func_021C3AAC(void *a, u32 *out);
void func_021C3ADC(void *a, u32 *out);
void func_021C3B0C(void *a, u32 *out);
void func_021C3B2C(u32 *p, u32 *q);
int func_021C3BB0(u32 a);
int func_021C3BCC(u32 a, u32 b);
void func_021C3BD4(void *a, u32 *out);
void func_021C3C04(void *a, u32 *out);
void func_021C3C30(void *a, u32 *out);
int func_021C3C5C(u32 a);
void func_021C3C78(void *a, u32 *out);
void func_021C3C88(u32 *p, u32 *q);
void func_021C3D1C(u32 *p, u32 *q, u32 d);
void func_021C3DA8(void **p, u32 *out);
void func_021C3DE4(u32 *a, u32 *p, u32 heap);
void func_021C3E38(u32 *p, u32 heap);
void func_021C3E64(u32 *p, S_021C38F4 *q);
void func_021C3F60(int a, u32 *p);
void func_021C3FC0(u32 *a, u32 *b);
void func_021C4018(int a, char *p);
void func_021C4024(int a, char *p);
void func_021C4030(u32 *p, u32 *q);
u32 func_021C4078(void);
void func_021C4084(u32 *p);
void func_021C40F8(u32 *p, u32 *q, u32 heap);
void func_021C4160(u32 *p, u32 *q);
void func_021C4238(u32 *a, u32 *b, u32 *c);
void func_021C42BC(void **p, u32 *q);
void func_021C42F4(u32 *p, u32 v);
void func_021C4340(void *mon, const S_021C38F4 *q, void *my, u32 y, u16 heap);
int func_021C447C(u32 a, u32 b, u32 c, u32 d);
u16 func_021C4504(u16 sp);
u8 func_021C452C(u32 a, u32 b, u32 c, u32 d);
int func_021C457C(void *a, void *b);
u32 func_021C459C(u32 a, u32 b);
int func_021C4608(void *a, void *b);
u32 func_021C4628(u32 a, void *b);
int func_021C4678(void *a, void *b);
int func_021C46A4(void *a, void *b);
u32 func_021C46F8(u32 a, u32 b, u32 c);
void *func_021C474C(void *a, u32 b, u32 c);
int func_021C4788(void *t);
R *func_021C47B4(u8 *owner, u32 heap);
void func_021C47E8(u32 a, u8 *p);
void func_021C47FC(P_021C474C *p);
void func_021C483C(u8 *p);
void func_021C484C(u32 a, int b, int c, s32_021C484C d);
extern const T4 d_021DA8D8;
extern T_021C3A7C d_021DA960;
extern const T6 d_021DA930;
extern T_021C3F60 d_021DA918;
extern T d_021DA908;
extern const T4 d_021DA8F8;
extern T d_021DA8E8;
extern void *g_020A7370;
extern const T6 d_021DA948;
extern unsigned char abs_id_3f[];
extern char ov063_id[];
extern char d_021DE468[];
extern u8 d_021DA9F0[];






/*
 * Addresses are Black-image addresses.
 */
int func_021C3670(void *a, u32 b)
{
    T4 t = d_021DA8D8;
    int i;

    for (i = 0; i < 4; i++) {
        if (b == func_02017E1C(a, t.v[i], 0))
            return 1;
    }
    return 0;
}






/*
 * Compacts the two day-care slots so occupied ones come first.
 */
void func_021C36B0(void *e)
{
    int i, j;

    for (i = 0; i < 2; i++) {
        if (func_0200BCA8(e, i) == 1)
            continue;
        for (j = i + 1; j < 2; j++) {
            if (func_0200BCA8(e, j) == 1)
                func_0200BCEC(e, j, j - 1);
        }
    }
}






/*
 * Breeding compatibility of two party Pokemon (egg groups 0x18/0x19,
 * Ditto 0x84, gender 0x6E). EXACT* only for the 2-byte pad before
 * func_021C37F8. The last test is spelled as the negated conjunction
 * returning 0, so the fall-through is the call.
 */
int func_021C36EC(u32 a, u32 b)
{
    u32 sp[2];
    u32 fm[2];
    u32 gd[2];
    u32 g1[2];
    u32 g2[2];
    u32 m[2];
    int i;

    m[0] = a;
    m[1] = b;
    for (i = 0; i < 2; i++) {
        sp[i] = func_02017E1C((void *)m[i], 5, 0);
        func_02017E1C((void *)m[i], 7, 0);
        fm[i] = func_02017E1C((void *)m[i], 0x6f, 0);
        gd[i] = func_02017E1C((void *)m[i], 0x6e, 0);
        g1[i] = func_02019C90(sp[i], fm[i], 0x18);
        g2[i] = func_02019C90(sp[i], fm[i], 0x19);
    }
    if (g1[0] == 0xf || g1[1] == 0xf || g2[0] == 0xf || g2[1] == 0xf)
        return 0;
    if (sp[0] == 0x84 && sp[1] == 0x84)
        return 0;
    if (sp[0] == 0x84 || sp[1] == 0x84)
        return func_021C37F8(a, b);
    if (gd[0] == gd[1])
        return 0;
    if (gd[0] == 2 || gd[1] == 2)
        return 0;
    if (g1[0] != g1[1] && g1[0] != g2[1] && g2[0] != g1[1] && g2[0] != g2[1])
        return 0;
    return func_021C37F8(a, b);
}






int func_021C37F8(u32 a, u32 b)
{
    u32 x[2];
    u32 y[2];
    u32 m[2];
    int i;

    m[0] = a;
    m[1] = b;
    for (i = 0; i < 2; i++) {
        x[i] = func_02017E1C((void *)m[i], 5, 0);
        y[i] = func_02017E1C((void *)m[i], 7, 0);
    }
    if (x[0] != x[1]) {
        if (y[0] == y[1])
            return 0x14;
        return 0x32;
    }
    if (y[0] == y[1])
        return 0x32;
    return 0x46;
}






/*
 * Step counter: every 16 steps rolls for an egg against compatibility (EXACT*: pad).
 */
int func_021C385C(S_021C3670 *p)
{
    u16 old = p->steps;

    p->steps = old + 0x10;
    if (old > 0xFF) {
        p->steps = 0;
        if (func_0200BCB8(p->box) >= 2) {
            u32 r = func_02005728(0x640);
            if (r < func_021C34C4((void **)p))
                return 1;
        }
    }
    return 0;
}






void func_021C3898(u32 *p, u32 c)
{
    u32 a = (u32)func_02012944(func_020120F4(func_02188C80((void *)p[1])));
    u32 b = func_0200BC2C(p[2], 0);
    u32 d = func_0200BC2C(p[2], 1);

    func_021C38F4(((struct Obj03142 *)p)->f0, (void *)a, (void *)0xEA62, b, d, (void *)c);
}






/*
 * Blocking site: the bl to func_02012F98 at +000C of this function.
 *
 * no listing carries a func_ label at this address -- disasm.py classified the bytes as data in every overlay whose window holds it -- and the only branches to it are these ov021 call sites, so the `label` class has no traced entry point to read and a region hint cannot invent one.  Filing a source for the TARGET (rule 10) would attest every caller that needs it, with no change here.
 *
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_021C38DC(u32 a, u32 b)
{
return func_02007C34((u32)func_02012F98((void *)func_020120F4((const struct Ctx *)func_02188C80((void *)a))), b);
}






/*
 * Day-care offspring builder: runs every step of the 0x8C-byte work
 * record over the parent pair m and hands the result to func_021C4340.
 * Callee prototypes without a matched file are written from the call
 * site's argument registers.
 */
void func_021C38F4(u16 heap, void *b, void *c, u32 m0, u32 m1, void *mon)
{
    S_021C38F4 s;
    u32 m[2];

    m[0] = m0;
    m[1] = m1;
    func_021C3A00(m);
    func_021C3A44((void **)m);
    func_021C3A7C(&s);
    func_021C3A90(m, (u32 *)(&s));
    func_021C3AAC(m, (u32 *)(&s));
    func_021C3ADC(m, (u32 *)(&s));
    func_021C3B0C(m, (u32 *)(&s));
    func_021C3B2C(m, (u32 *)(&s));
    func_021C3BCC((u32)m, (u32)(&s));
    func_021C3BD4(m, (u32 *)(&s));
    func_021C3C04(m, (u32 *)(&s));
    func_021C3C30(m, (u32 *)(&s));
    func_021C3C78(m, (u32 *)(&s));
    func_021C3C88(m, (u32 *)(&s));
    func_021C3D1C(m, (u32 *)(&s), heap);
    func_021C3DA8((void **)m, (u32 *)(&s));
    func_021C3DE4(m, (u32 *)&s, heap);
    func_021C3E38((u32 *)(&s), heap);
    func_021C3E64(m, &s);
    func_021C3F60((int)m, (u32 *)(&s));
    func_021C3FC0(m, (u32 *)(&s));
    func_021C4018((int)b, (char *)(&s));
    func_021C4024((int)m, (char *)(&s));
    func_021C4030(m, (u32 *)(&s));
    func_021C4084((u32 *)(&s));
    func_021C40F8(m, (u32 *)(&s), heap);
    func_021C4160(m, (u32 *)(&s));
    func_021C4238(m, (u32 *)(&s), (u32 *)heap);
    func_021C42BC((void **)m, (u32 *)(&s));
    func_021C4340(mon, &s, b, (u32)c, heap);
}






void func_021C3A00(u32 *p)
{
    u32 a = func_02017E1C((void *)p[0], 0x6e, 0);

    func_02017E1C((void *)p[1], 0x6e, 0);
    if (a == 1)
        func_021C3A70(p);
    func_02017E1C((void *)p[0], 0x6e, 0);
    if (func_02017E1C((void *)p[1], 0x6e, 0) == 0)
        func_021C3A70(p);
}






/*
 * Applies the special-case hook for species 0x84 holding item 2 (EXACT*: pad).
 */
void func_021C3A44(void **p)
{
    u32 sp = func_02017E1C(p[0], 5, 0);
    u32 item = func_02017E1C(p[1], 0x6E, 0);

    if (sp == 0x84 && item == 2)
        func_021C3A70((u32 *)p);
}






void func_021C3A70(u32 *p)
{
    u32 t = p[0];

    p[0] = p[1];
    p[1] = t;
}








/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_021C3A7C(u32 a, u32 b, u32 c, u32 d)
{
func_02082BCC(a, 0, 140, d);
((struct Obj18302 *)((u8 *)(a)))->f8 = 1;
return 1;
}








/*
 * Stores the base form of the parent species.
 */
void func_021C3A90(void *a, u32 *out)
{
    *out = func_021C4504(func_02017E1C((void *)func_021C3BB0((u32)a), 5, 0));
}








/*
 * Nidoran family: offspring species is a coin flip of 0x1D / 0x20.
 */
void func_021C3AAC(void *a, u32 *out)
{
    u32 sp = func_02017E1C((void *)func_021C3BB0((u32)a), 5, 0);

    if (sp == 0x1D || sp - 0x20 <= 2) {
        if (func_02005728(2) == 0)
            *out = 0x1D;
        else
            *out = 0x20;
    }
}








/*
 * Volbeat / Illumise: offspring species is a coin flip of the two.
 */
void func_021C3ADC(void *a, u32 *out)
{
    u32 sp = func_02017E1C((void *)func_021C3BB0((u32)a), 5, 0);

    if (sp == 0x139 || sp == 0x13A) {
        if (func_02005728(2) == 0)
            *out = 0x139;
        else
            *out = 0x13A;
    }
}








/*
 * Manaphy parents produce Phione.
 */
void func_021C3B0C(void *a, u32 *out)
{
    if (func_02017E1C((void *)func_021C3BB0((u32)a), 5, 0) == 0x1EA)
        *out = 0x1E9;
}








void func_021C3B2C(u32 *p, u32 *q)
{
    T_021C3A7C t = d_021DA960;
    int i;
    u32 r5, r3;
    u32 x = func_021C3BB0((u32)p);

    i = 0;
    func_02017E1C((void *)x, 5, 0);
    func_02017E1C((void *)x, 6, 0);
    r5 = func_02017E1C((void *)p[0], 6, 0);
    r3 = func_02017E1C((void *)p[1], 6, 0);
    for (; i < 12; i++) {
        if (*q == t.e[i].a && r5 != t.e[i].b && r3 != t.e[i].b) {
            *q = t.e[i].c;
            return;
        }
    }
}








int func_021C3BB0(u32 a)
{
if (func_02017E1C(((struct Obj00358 *)((u8 *)(a)))->f4, 5, 0) == 132) {
    return *(u32 *)&((struct Obj00358 *)((u8 *)(a)))->f0;
}
return *(u32 *)&((struct Obj00358 *)((u8 *)(a)))->f4;
}








int func_021C3BCC(u32 a, u32 b)
{
((struct Obj18303 *)((u8 *)(b)))->f4 = 0;
return 0;
}








/*
 * Copies the parent's form for species 0x1A6..0x1A7.
 */
void func_021C3BD4(void *a, u32 *out)
{
    void *mon = (void *)func_021C3C5C((u32)a);
    u32 sp = func_02017E1C(mon, 5, 0);

    if (sp - 0x1A6 <= 1)
        out[1] = func_02017E1C(mon, 0x6F, 0);
}








/*
 * Copies the parent's form for species 0x19C..0x19D.
 */
void func_021C3C04(void *a, u32 *out)
{
    void *mon = (void *)func_021C3C5C((u32)a);
    u32 sp = func_02017E1C(mon, 5, 0);

    if (sp - 0x19C <= 1)
        out[1] = func_02017E1C(mon, 0x6F, 0);
}








/*
 * Copies the parent's form for species 0x226.
 */
void func_021C3C30(void *a, u32 *out)
{
    void *mon = (void *)func_021C3C5C((u32)a);
    u32 sp = func_02017E1C(mon, 5, 0);

    if (sp == 0x226)
        out[1] = func_02017E1C(mon, 0x6F, 0);
}








int func_021C3C5C(u32 a)
{
if (func_02017E1C(((struct Obj09211 *)((u8 *)(a)))->f4, 5, 0) == 132) {
    return ((struct Obj09211 *)((u8 *)(a)))->f0;
}
return *(u32 *)&((struct Obj09211 *)((u8 *)(a)))->f4;
}








/*
 * Rolls the offspring nature (EXACT*: pad).
 */
void func_021C3C78(void *a, u32 *out)
{
    out[3] = func_02005728(0x19);
}








void func_021C3C88(u32 *p, u32 *q)
{
    int x, y;
    u32 s0, s1;

    x = 0;
    if (func_02017E1C((void *)p[0], 6, 0) == 0xe5)
        x = 1;
    y = 0;
    if (func_02017E1C((void *)p[1], 6, 0) == 0xe5)
        y = 1;
    s0 = func_02017E1C((void *)p[0], 0x70, 0);
    s1 = func_02017E1C((void *)p[1], 0x70, 0);
    if (x || y) {
        if (func_02005728(2) == 0)
            return;
    }
    if (x && y) {
        if (func_02005728(2) == 0) {
            q[3] = s0;
            q[0x14] = 1;
        } else {
            q[3] = s1;
            q[0x15] = 1;
        }
    } else if (x) {
        q[3] = s0;
        q[0x14] = 1;
    } else if (y) {
        q[3] = s1;
        q[0x15] = 1;
    }
}








void func_021C3D1C(u32 *p, u32 *q, u32 d)
{
    u32 a = func_02017E1C((void *)p[1], 5, 0);
    u32 b = func_02017E1C((void *)p[1], 0x6f, 0);
    u32 c = func_02017E1C((void *)p[1], 0xa, 0);
    u32 k = (u32)func_021C452C((u16)a, (u16)b, (u16)c, d);
    u32 r = func_02005728(100);

    switch (k) {
    default:
    case 0:
        if (r < 0x50)
            q[0x13] = 0;
        else
            q[0x13] = 1;
        return;
    case 1:
        if (r < 0x14)
            q[0x13] = 0;
        else
            q[0x13] = 1;
        return;
    case 2:
        if (r < 0x14)
            q[0x13] = 0;
        else if (r < 0x28)
            q[0x13] = 1;
        else
            q[0x13] = 2;
        return;
    }
}








/*
 * Sets the +0x4C flag by coin flip when a parent is species 0x84 (EXACT*: pad).
 */
void func_021C3DA8(void **p, u32 *out)
{
    u32 a = func_02017E1C(p[0], 5, 0);
    u32 b = func_02017E1C(p[1], 5, 0);

    if (a == 0x84 || b == 0x84) {
        if (func_02005728(2) == 0)
            out[19] = 0;
        else
            out[19] = 1;
    }
}








void func_021C3DE4(u32 *a, u32 *p, u32 heap)
{
    u32 s[3];
    u32 x = (u32)func_0201ADE4((u16)p[0], (u16)p[1], heap);

    s[0] = func_0201AE1C((const struct Personal *)x, 0x1a);
    s[1] = func_0201AE1C((const struct Personal *)x, 0x1b);
    s[2] = func_0201AE1C((const struct Personal *)x, 0x1c);
    func_0201AE14((void *)x);
    if (p[0x13] < 2) {
        p[4] = s[p[0x13]];
        if (p[4] == 0)
            p[4] = s[0];
    }
}








/*
 * Reads personal-data field 0x15 for the species/form pair (EXACT*: pad).
 */
void func_021C3E38(u32 *p, u32 heap)
{
    void *h = func_0201ADE4((u16)p[0], (u16)p[1], heap);
    u32 v = func_0201AE1C(h, 0x15);

    func_0201AE14(h);
    p[5] = v;
}








/*
 * The flag array at q+0x58 must be a struct member (q->a[ia]); spelled
 * q[0x16 + ia] the compiler folds 0x16 into the index and spills it.
 */
void func_021C3E64(u32 *p, S_021C38F4 *q)
{
    T6 t;
    int fa;
    int fb;
    int ia;
    int ib;
    u32 a;
    u32 b;
    int i;

    fa = 0;
    fb = 0;
    a = func_02017E1C((void *)p[0], 6, 0);
    b = func_02017E1C((void *)p[1], 6, 0);
    t = d_021DA930;
    for (i = 0; i < 6; i++) {
        if (a == t.v[i]) {
            fa = 1;
            ia = i;
            break;
        }
    }
    for (i = 0; i < 6; i++) {
        if (b == t.v[i]) {
            fb = 1;
            ib = i;
            break;
        }
    }
    if (fa && fb) {
        if (func_02005728(2) == 0) {
            q->a[ia] = 1;
            q->n++;
        } else {
            q->b[ib] = 1;
            q->n++;
        }
    } else if (fa) {
        q->a[ia] = 1;
        q->n++;
    } else if (fb) {
        q->b[ib] = 1;
        q->n++;
    }
}







void func_021C3F60(int a, u32 *p)
{
    while (p[0x22] < 3) {
        u32 r = func_02005728(6);

        if (func_02005728(2) == 0) {
            if (p[0x16 + r] == 0 && p[0x1c + r] == 0) {
                p[0x16 + r] = 1;
                p[0x22]++;
            }
        } else {
            if (p[0x16 + r] == 0 && p[0x1c + r] == 0) {
                p[0x1c + r] = 1;
                p[0x22]++;
            }
        }
    }
}







void func_021C3FC0(u32 *a, u32 *b)
{
    T_021C3F60 t = d_021DA918;
    u32 *pt = t.v;
    int i;

    for (i = 0; i < 6; i++) {
        u32 *e = b + i;

        if (e[0x16] != 0)
            e[6] = func_02017E1C((void *)a[0], pt[i], 0);
        if (e[0x1c] != 0)
            e[6] = func_02017E1C((void *)a[1], pt[i], 0);
    }
}







void func_021C4018(int a, char *p)
{
    ((struct Obj20193 *)p)->f30 = func_02008530((const struct Sub0200852CObj *)a);
}






void func_021C4024(int a, char *p)
{
    ((struct Obj20194 *)p)->f34 = func_021C4078();
}






void func_021C4030(u32 *p, u32 *q)
{
    int i = 0;
    u32 a = func_02017E1C((void *)p[0], 0xc, 0);

    if (a == func_02017E1C((void *)p[1], 0xc, 0))
        return;
    if (func_02017ED8(q[0xc], q[0xd]) != 0)
        return;
    do {
        q[0xd] = func_021C4078();
        if (func_02017ED8(q[0xc], q[0xd]) != 0)
            return;
        i++;
    } while (i < 5);
}







/*
 * Tail call with minus one.
 *
 * Addresses are Black-image addresses.
 */
u32 func_021C4078(void)
{
    return func_02005728(-1);
}







void func_021C4084(u32 *p)
{
    P_021C3670 buf[26];
    P_021C3670 d, c, b, a;
    int i;
    int end;
    u32 dy, lim, cx;

    func_0201ADD0((u16)p[0], (u16)p[1], buf);
    i = 0;
    goto test;
body:
    d = a;
    c = a;
    dy = d.y;
    lim = p[2];
    cx = c.x;
    if (lim < dy)
        return;
    func_021C42F4(p, cx);
    i++;
test:
    a = buf[i];
    b = a;
    end = 0;
    if (b.x == 0xffff && b.y == 0xffff)
        end = 1;
    if (!end)
        goto body;
}







/*
 * r2 is never touched before the func_02048F60 call: the function takes a
 * third parameter and forwards it as the heap argument. With two
 * parameters the table copy takes r3/r2 instead of r4/r3 (7 bytes).
 * Addresses are Black-image addresses.
 */
void func_021C40F8(u32 *p, u32 *q, u32 heap)
{
    T t = d_021DA908;
    u32 *pt = t.v;
    u16 *buf = func_02048F60(0x7b, q[0], heap);
    int n = buf[0];
    int i;

    for (i = 0; i < 4; i++) {
        u32 v = func_02017E1C((void *)p[0], pt[i], 0);
        int j;

        for (j = 1; j <= n; j++) {
            if (v == buf[j]) {
                func_021C42F4(q, v);
                break;
            }
        }
    }
    func_020307B0(buf);
}







/*
 * Twin of func_021C4084 (same goto-rotated learnset walk). The call
 * result must be a named local (v == mv gives cmp r0, r5), and end = 0
 * goes after the entry copies, as in the twin.
 */
void func_021C4160(u32 *p, u32 *q)
{
    P_021C3670 buf[26];
    T4 t = d_021DA8F8;
    P_021C3670 d, b, a;
    int i;
    int fa;
    int fb;
    int end;
    int k;
    u32 mv;
    u32 v;

    func_0201ADD0((u16)q[0], (u16)q[1], buf);
    i = 0;
    goto test;
body:
    d = a;
    mv = d.x;
    fa = 0;
    fb = 0;
    for (k = 0; k < 4; k++) {
        v = func_02017E1C((void *)p[0], t.v[k], 0);
        if (v == mv) {
            fa = 1;
            break;
        }
    }
    for (k = 0; k < 4; k++) {
        v = func_02017E1C((void *)p[1], t.v[k], 0);
        if (v == mv) {
            fb = 1;
            break;
        }
    }
    if (fa && fb)
        func_021C42F4(q, mv);
    i++;
test:
    a = buf[i];
    b = a;
    end = 0;
    if (b.x == 0xffff && b.y == 0xffff)
        end = 1;
    if (!end)
        goto body;
}







void func_021C4238(u32 *a, u32 *b, u32 *c)
{
    T t = d_021DA8E8;
    int i;

    for (i = 0; i < 4; i++) {
        u32 v = func_02017E1C((void *)a[0], t.v[i], 0);
        int k;

        for (k = 0x148; k <= 0x272; k++) {
            if (v == func_020212B0(k)) {
                if (func_021C447C((u32)c, (u16)b[0], (u16)b[1], (u16)k)) {
                    func_021C42F4(b, v);
                    break;
                }
            }
        }
    }
}







/*
 * Pikachu offspring learns move 0x158 when a parent holds item 0xEC.
 */
void func_021C42BC(void **p, u32 *q)
{
    if (q[0] == 0xAC) {
        if (func_02017E1C(p[0], 6, 0) == 0xEC || func_02017E1C(p[1], 6, 0) == 0xEC)
            func_021C42F4(q, 0x158);
    }
}







void func_021C42F4(u32 *p, u32 v)
{
    int i;
    u32 n;

    if (v == 0)
        return;
    n = ((struct Obj02093 *)p)->f38;
    for (i = 0; i < n; i++) {
        if (v == *(u32 *)((char *)p + i * 4 + 0x3c))
            return;
    }
    if (n < 4) {
        *(u32 *)((char *)p + n * 4 + 0x3c) = v;
        ((struct Obj02093 *)p)->f38 = ((struct Obj02093 *)p)->f38 + 1;
        return;
    }
    for (i = 0; i < 3; i++)
        *(u32 *)((char *)p + i * 4 + 0x3c) = *(u32 *)((char *)p + i * 4 + 0x40);
    *(u32 *)((char *)p + i * 4 + 0x3c) = v;
}







/*
 * Builds the day-care egg/offspring Pokemon from the 0x8C-byte work
 * record q (the struct func_021C38F4 fills on its stack). The bl to the
 * Thumb tail-call stub func_02018198 is witnessed by
 * src/matched/arm9/func_02018198.c.
 *
 * Load-bearing: const S_021C38F4 *q (the species/level loads rise above the zero
 * stack-argument stores), and heap u16 at both callees (func_02008510,
 * func_0202F190) so it is re-read from its stack slot per call.
 */
void func_021C4340(void *mon, const S_021C38F4 *q, void *my, u32 y, u16 heap)
{
    T6 t = d_021DA948;
    int i;
    u32 s;

    func_02017588(mon, q->species, q->level, q->f30, -1, q->f34);
    func_02017E40(mon, 0x6f, q->form);
    func_02017E40(mon, 0x70, q->f0C);
    func_02017E40(mon, 9, q->f14);
    if (q->f4C == 2)
        func_02018A00(mon, q->species, q->form);
    else
        func_02017E40(mon, 0xb2, q->f10);
    for (i = 0; i < 6; i++) {
        if (q->a[i] != 0 || q->b[i] != 0)
            func_02017E40(mon, t.v[i], q->iv[i]);
    }
    func_02017E40(mon, 0x36, q->mv[0]);
    func_02017E40(mon, 0x37, q->mv[1]);
    func_02017E40(mon, 0x38, q->mv[2]);
    func_02017E40(mon, 0x39, q->mv[3]);
    s = (u32)func_02008510(my, heap);
    func_02017E40(mon, 0x8d, s);
    func_02045808((struct U16Vec *)s);
    s = (u32)func_02045EC0(g_020A7370, 0x28a);
    func_02017E40(mon, 0x73, s);
    func_02045808((struct U16Vec *)s);
    func_0202F190(mon, 5, (u32)my, y, heap);
    func_02017E40(mon, 0x4c, 1);
    func_02018198(mon);
    func_020185C4(mon);
    func_0201B9F0(mon);
}







int func_021C447C(u32 a, u32 b, u32 c, u32 d)
{
    u32 y, x, v;

    if (b >= 0x289)
        return 0;
    if (func_02021288(d) == 0)
        return 0;
    x = (u32)func_0201ADE4(b, c, a);
    y = func_0202130C(d);
    if (y < 0x20) {
        v = func_0201AE1C((const struct Personal *)x, 0x27);
    } else if (y < 0x40) {
        v = func_0201AE1C((const struct Personal *)x, 0x28);
        y -= 0x20;
    } else if (y < 0x60) {
        v = func_0201AE1C((const struct Personal *)x, 0x29);
        y -= 0x40;
    } else {
        v = func_0201AE1C((const struct Personal *)x, 0x2a);
        y -= 0x60;
    }
    func_0201AE14((void *)x);
    return v & (1 << y);
}







/*
 * Maps a species to its base form via the evolution table (species below
 * 0x289).
 */
u16 func_021C4504(u16 sp)
{
    u16 v;

    if (sp >= 0x289)
        return sp;
    func_02048F74(&v, 0x14, sp, 0, (u32 *)2);
    return v;
}






u8 func_021C452C(u32 a, u32 b, u32 c, u32 d)
{
    u32 s[3];
    u32 x = (u32)func_0201ADE4(a, b, d);
    u32 i;

    s[0] = func_0201AE1C((const struct Personal *)x, 0x1a);
    s[1] = func_0201AE1C((const struct Personal *)x, 0x1b);
    s[2] = func_0201AE1C((const struct Personal *)x, 0x1c);
    func_0201AE14((void *)x);
    for (i = 0; i < 3; i++) {
        if (c == s[i])
            break;
    }
    if (i >= 3)
        i = 0;
    return i;
}






/*
 * Formerly MATCH on unwitnessed callees; their matched entries now witness them.
 */
int func_021C457C(void *a, void *b)
{
    void *x = func_0215A64C(b);

    if (func_021C1094(x) == 1) {
        func_021C10A0((u32)x);
        return 1;
    }
    return 0;
}






u32 func_021C459C(u32 a, u32 b)
{
    u32 buf[3];
    u32 z, w, t;
    void *x;
    void *y;

    x = func_0201210C(func_0215A5DC((void *)b));
    y = func_02188CB4((void *)x);
    z = func_0216D5F8(func_021A3074(y));
    x = (void *)func_02188C98(x);
    w = func_0215A5CC((void *)b);
    func_021A3364(y, z, (int *)buf);
    t = func_021AB0D4(x, buf);
    t = func_021C1024(y, z, t, w);
    func_0215A644((void *)b, t);
    func_020113D0((char *)a, (int)func_021C457C);
    return 1;
}






int func_021C4608(void *a, void *b)
{
    void *x = func_0215A64C(b);

    if (func_021C12C4(x) == 1) {
        func_021C12D0(x);
        return 1;
    }
    return 0;
}






u32 func_021C4628(u32 a, void *b)
{
    u32 w, y, t;
    void *x;

    w = func_0215A5CC(b);
    x = func_02188CB4(func_0201210C(func_0215A5DC((void *)b)));
    y = func_021A3050(x);
    t = func_02159B10((void *)a, (void *)b);
    t = func_021C1228(x, y, t, w);
    func_0215A644((void *)b, t);
    func_020113D0((char *)a, (int)func_021C4608);
    return 1;
}






/*
 * Refreshes the field object from the day-care state (EXACT*: pad).
 */
int func_021C4678(void *a, void *b)
{
    void *g = func_0201210C(func_0215A5DC(b));
    void *h = func_021A3074(func_02188CB4((void *)g));

    func_021C9550((u32)h, func_02188CD0(g));
    return 0;
}






/*
 * The shared func_0215897C call is written out in every arm and
 * cross-jumped by the compiler; a result local merged after the if chain
 * spills z instead of b.
 */
int func_021C46A4(void *a, void *b)
{
    u32 t;
    void *y;
    void *x;
    void *z;

    x = func_0215A5DC(b);
    y = func_0201210C(x);
    z = func_0215A5F4(b);
    t = func_02159B10(a, b);
    if (t == 0)
        func_0215897C(z, func_021D2418(x, (u32)y));
    else if (t == 1)
        func_0215897C(z, func_021D2440(x, (u32)y, 0));
    else
        func_0215897C(z, func_021D2440(x, (u32)y, 1));
    return 1;
}




u32 func_021C46F8(u32 a, u32 b, u32 c)
{
    u32 t = (u32)func_020122C0((void *)a, 0, func_021C4788, 4);
    u32 *w = func_020124E8((struct Obj *)t);
    void *x;
    void *y;

    func_02034AC4((int)abs_id_3f);
    x = func_02188CB4((void *)b);
    y = func_021A3074((void *)x);
    func_021A305C(x, c);
    *w = (u32)func_021F36C0((void *)a, b, (u32)y, 1);
    return t;
}




/*
 * Loads ov063 and spawns the task that drives its effect.
 */
void *func_021C474C(void *a, u32 b, u32 c)
{
    void *t = func_020122C0(a, 0, func_021C4788, 4);
    void **w = func_020124E8(t);

    func_02034AC4((u32)ov063_id);
    *w = func_021F36C0(a, b, c, 0);
    return t;
}





/*
 * Task callback: when the ov063 effect reports done, frees it and unloads
 * ov063.
 * Callee witnesses filed in wave A1 (witness lane).
 */
int func_021C4788(void *t)
{
    void **w = func_020124E8(t);

    if (func_021F376C(*w) != 0) {
        func_021F3758(*w);
        func_02034A5C((u32)ov063_id);
        return 1;
    }
    return 0;
}





/*
 * Allocates the 0xC-byte field-object record and initialises it.
 */
R *func_021C47B4(u8 *owner, u32 heap)
{
    R *r = func_02030734(heap, 0xC, 1, d_021DE468, 0x56);

    r->owner = owner;
    r->obj = func_02188C90((u8 *)func_021ABE14(owner));
    func_021C47FC((struct P_021C474C *)r);
    return r;
}




/*
 * Pattern-generated from the ov021 family.
 *
 * Addresses are Black-image addresses.
 */
void func_021C47E8(u32 a, u8 *p)
{
    func_021C483C(p);
    func_020307B0(p);
}




void func_021C47FC(P_021C474C *p)
{
    S s;
    u32 x = func_021ABE24((u8 *)p->f0);

    s.b4 = 2;
    s.b5 = 0x13;
    s.b6 = 0x10;
    s.b7 = 0x10;
    s.w8 = 1;
    s.w0 = (u32)func_02046E24(x, 0x2e);
    func_021AC1F0((struct X *)p->f0, (void *)s.w0);
    p->f8 = func_020500F0((struct BbActSys *)p->f4, (const struct BbActRec *)(&s), 1);
}




void func_021C483C(u8 *p)
{
    func_02050278((struct BbActSys *)(((struct Obj12131 *)p)->f4), ((struct Obj12131 *)p)->f8, 1);
}




void func_021C484C(u32 a, int b, int c, s32_021C484C d)
{
    Vec3 v;
    Arg s;

    func_02164280(b, c, (int *)(&v));
    v.y = d - 0x8000;
    v.z -= 0x5000;
    s.a = func_021ABEA0(a, 7);
    s.v = v;
    func_021ABFA8(a, d_021DA9F0, 0, 0, &s, 0);
}
