/*
 * file:     unit_02183B60_p03.c
 * unit:     yes
 * function: func_02184360, func_02184388, func_02184410, func_02184504, func_02184584, func_0218466C, func_02184730, func_021847CC, func_02184894, func_0218495C, func_02184A14, func_02184AB4, func_02184B54, func_02184BF8
 * address:  0x02184360
 * region:   ov020
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_020122C0 0x020122C0 thumb
 *   func_020124E8 0x020124E8 thumb
 *   func_021841C0 0x021841C0 thumb ov020
 *   func_0218403C  0x0218403C  thumb  ov020
 *   func_02188C7C  0x02188C7C  thumb  ov021
 *   func_0216D9A0  0x0216D9A0  thumb  ov010
 *   func_0218409C  0x0218409C  thumb  ov020
 *   func_021BD648  0x021BD648  thumb  ov021
 *   func_02012374  0x02012374  thumb
 *   func_02184120  0x02184120  thumb  ov020
 *   func_021BD9BC  0x021BD9BC  thumb  ov021
 *   func_02012138  0x02012138  thumb
 *   func_02158344  0x02158344  thumb  ov010
 *   func_0216D9E4  0x0216D9E4  thumb  ov010
 *   func_02013DD0  0x02013DD0  thumb
 *   func_0215841C  0x0215841C  thumb  ov010
 *   func_021746AC  0x021746AC  thumb  ov011
 *   func_02158428  0x02158428  thumb  ov010
 *   func_02012A30  0x02012A30  thumb
 *   func_02161824  0x02161824  thumb  ov010
 *   func_02029D44  0x02029D44  thumb
 *   func_02029D7C  0x02029D7C  thumb
 *   func_021BE89C  0x021BE89C  thumb  ov021
 *   func_021BE8B8  0x021BE8B8  thumb  ov021
 *   func_021BE8D4  0x021BE8D4  thumb  ov021
 *   func_021BE92C  0x021BE92C  thumb  ov021
 *   func_02188D20  0x02188D20  thumb  ov021
 *   func_021BC550  0x021BC550  thumb  ov021
 *   func_021BF58C  0x021BF58C  thumb  ov021
 *   func_021BFD34  0x021BFD34  thumb  ov021
 *   func_02185F48  0x02185F48  thumb  ov020
 *   func_021BF5B4  0x021BF5B4  thumb  ov021
 *   func_021BFD70  0x021BFD70  thumb  ov021
 *   func_021BF5E8  0x021BF5E8  thumb  ov021
 *   func_021BFDA0  0x021BFDA0  thumb  ov021
 *   func_020127A4  0x020127A4  thumb
 *   func_02012B2C  0x02012B2C  thumb
 *   func_021BF61C  0x021BF61C  thumb  ov021
 *   func_021BFDD0  0x021BFDD0  thumb  ov021
 *   func_02188D38  0x02188D38  thumb  ov021
 *   func_021C6E48  0x021C6E48  thumb  ov021
 *   func_021BFE00  0x021BFE00  thumb  ov021
 *   func_021BF644  0x021BF644  thumb  ov021
 *   func_02034A5C  0x02034A5C  arm
 *   func_02034AC4  0x02034AC4  arm
 *   func_02158780  0x02158780  thumb  ov010
 *   ov011_id       0x0000000B  data  a1
 *   ov012_id       0x0000000C  data  a1
 */
#include "../../matched/include/Obj00082.h"
#include "../../matched/include/Obj04972.h"
#include "../../matched/include/Obj04190.h"
#include "../../matched/include/Obj05964.h"
#include "../../matched/include/Obj04977.h"
#include "../../matched/include/Obj09424.h"
#include "../../matched/include/Obj04978.h"

struct Desc;
struct Obj;
struct Evt;
struct Ctx;
struct BigObj;
struct SaveBlock;
struct Rec44;
typedef unsigned char u8;

typedef unsigned int   u32;

typedef unsigned short u16;

typedef short s16;

typedef struct Obj {
    int f00;
    int f04;
    int f08;
    char pad0c[0x14 - 0x0c];
    s16 f14;
    char pad16[0x44 - 0x16];
    int f44;
    u16 f48;
    u16 f4a;
} Obj;

typedef struct { int f[39]; } S9C;

extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern void *func_020124E8(struct Obj *p);
extern int func_021841C0(int ctx, int *state, u8 **pp);
extern void func_0218403C(u8 *p);
extern void *func_02188C7C(u8 *p);
extern void func_0216D9A0(void *map);
extern void func_0218409C(u8 *p, int a);
extern int func_021BD648(u8 *p);
extern void func_02012374(struct Evt *evt, struct Evt **out);
extern void func_02184120(u8 *p, int a);
extern int func_021BD9BC(u32 *p);
extern unsigned int func_02012138(const struct Ctx *p);
extern int func_02158344(int a0);
extern unsigned int *func_0216D9E4(void *c);
extern int func_02013DD0(int a);
extern u8 func_0215841C(void *p);
extern int func_021746AC(char *a, int b);
extern u8 func_02158428(u8 *p);
extern unsigned int func_02012A30(const struct BigObj *p);
extern void *func_02161824(void *a, void *b);
extern void func_02029D44(u32 a, u32 b, u16 c, u8 d);
extern void func_02029D7C(int a, int b);
extern int func_021BE89C(int a, u32 b);
extern int func_021BE8B8(int a, int b);
extern int func_021BE8D4(void *a, int b, int sel, int d);
extern int func_021BE92C(void *a, int b, int sel, int d, int e, u8 f, u8 g);
extern u32 func_02188D20(u8 *p);
extern void func_021BC550(void *p, int v);
extern void *func_021BF58C(int a, void *p, int c);
extern int func_021BFD34(int ctx, int a, int b, u8 *p);
extern void func_02185F48(void *p);
extern void *func_021BF5B4(int a, int b, int c, int d, int e, int f);
extern void *func_021BFD70(int a0, void *p, int a2, int a3);
u32 func_021BF5E8(u32 a, u32 b, u32 c, u32 d, u32 e, u32 f);
void *func_021BFDA0(int a0, void *p, int a2, int a3);
extern void *func_020127A4(struct SaveBlock *p);
extern void func_02012B2C(struct Rec44 *p, u32 v);
extern void *func_021BF61C(int a, int b, int c);
extern void *func_021BFDD0(int a0, void *p, int a2, int a3);
extern u32 func_02188D38(u8 *p);
extern int func_021C6E48(int a);
extern void *func_021BFE00(int a0, void *p, int a2);
extern int func_021BF644(int a, int b, int c);
void func_02034A5C(int id);
int func_02034AC4(int id);
int func_02158780(void *p, u16 b, int c, int d, u16 e);
void *func_02184360(u8 *p, int value);
int func_02184388(int a, int *state, u8 *p);
int func_02184410(int a, int *state, u8 *p);
int func_02184504(int a, int *state, u8 *p);
int func_02184584(int ctx, int *state, u8 *p);
int func_0218466C(int ctx, int *state, u8 *p);
int func_02184730(int ctx, int *state, u8 *p);
int func_021847CC(int ctx, int *state, u8 *p);
int func_02184894(void *a, int *state, Obj *o);
int func_0218495C(int ctx, int *state, u8 *p);
int func_02184A14(int ctx, int *state, u8 *p);
int func_02184AB4(int ctx, int *state, u8 *p);
int func_02184B54(int ctx, int *state, u8 *p);
int func_02184BF8(void *ctx, int *st, int *p);
extern char ov011_id[];
extern char ov012_id[];

void *func_02184360(u8 *p, int value)
{
    void *task;
    void **w;
    task = func_020122C0(((struct Obj00082 *)p)->f0, 0, (void *)func_021841C0, 4);
    w = func_020124E8(task);
    *w = p;
    p[0x30] = value;
    return task;
}


int func_02184388(int a, int *state, u8 *p)
{
    void *w = ((struct Obj00082 *)p)->f8;

    switch (*state) {
    case 0:
        func_0218403C(p);
        func_0216D9A0(func_02188C7C((u8 *)w));
        func_0218409C(p, a);
        func_02012374((struct Evt *)a, (struct Evt **)func_021BD648(p + 0x4c));
        (*state)++;
        return 0x21;
    case 1:
        func_02012374((struct Evt *)a, func_02184360(p, 0));
        (*state)++;
        break;
    case 2:
        func_02184120(p, a);
        func_02012374((struct Evt *)a, (struct Evt **)func_021BD9BC((u32 *)(p + 0x4c)));
        (*state)++;
        break;
    case 3:
        return 1;
    }
    return 0;
}


/*
 * Byte-correct (MATCH*: 242 compiled against a 244-byte listing extent, the
 * two bytes are alignment padding).  The one wildcarded site is +0x4C,
 * `bl func_02013DD0`: an unlabelled arm9 leaf (Ilias's) with no witness
 * outside this range, the documented near miss after unit_02013D9C.c.  Its
 * bytes (ldr r1,=0x0209DFC0; ldr r3,=sub_02013B10+1; movs r2,#4; bx r3) are
 *     extern const unsigned short tbl_0209DFC0[];      (data)
 *     extern int sub_02013B10(int v, const unsigned short *t, int n);
 *     int func_02013DD0(int v) { return sub_02013B10(v, tbl_0209DFC0, 4); }
 * which now verifies EXACT on its own (2026-09-29, `match.py one --region
 * arm9 --thumb`: the table by sole-ref/data, sub_02013B10 by literal), so
 * the unit_02013D9C.c note that it has no witness is out of date.  Once
 * that leaf is filed in an arm9 shard, this file goes EXACT unchanged.
 */
int func_02184410(int a, int *state, u8 *p)
{
    int z;
    int y;
    u8 *w;

    z = *(int *)(p + 8);
    y = *(int *)(p + 4);
    w = (u8 *)func_02158344(func_02012138((const struct Ctx *)(*(int *)(p + 0))));

    switch (*state) {
    case 0:
        func_0216D9A0(func_02188C7C((u8 *)z));
        if (func_02013DD0(*(u16 *)(p + 0x14)) == 1) {
            *state = 5;
        } else {
            *state = 1;
        }
        break;
    case 1:
        func_0218409C(p, a);
        func_02012374((struct Evt *)a, (struct Evt **)func_021BD648(p + 0x4c));
        (*state)++;
        return 0x21;
    case 2:
        func_02012374((struct Evt *)a, func_02184360(p, 0));
        (*state)++;
        break;
    case 3:
        func_02184120(p, a);
        func_02012374((struct Evt *)a, (struct Evt **)func_021BD9BC((u32 *)(p + 0x4c)));
        (*state)++;
        break;
    case 4:
        return 1;
    case 5:
        if (w == 0) {
            *state = 7;
            break;
        }
        if (func_021746AC((char *)w, func_0215841C((void *)y)) == 1) {
            (*state)++;
        }
        break;
    case 6:
        if (w == 0) {
            *state = 7;
            break;
        }
        if (func_02158428(w) == 1) {
            *state = 1;
        }
        break;
    case 7:
        func_0216D9E4(func_02188C7C((u8 *)z));
        return 1;
    }
    return 0;
}


int func_02184504(int a, int *state, u8 *p)
{
    int r;
    int v;
    int x;
    int z;
    int y;

    x = ((struct Obj04972 *)p)->f0;
    z = ((struct Obj04972 *)p)->f8;
    y = ((struct Obj04972 *)p)->f4;
    v = func_02012A30((const struct BigObj *)y);

    switch (*state) {
    case 0:
        r = (int)func_02161824((void *)x, (void *)z);
        func_02012374((struct Evt *)a, (struct Evt **)r);
        (*state)++;
        break;
    case 1:
        func_02029D44(v, y, ((struct Obj04972 *)p)->f14, (u8)((struct Obj04972 *)p)->f4A);
        func_02029D7C(v, y);
        (*state)++;
        break;
    case 2:
        r = (int)func_02184360(p, ((struct Obj04972 *)p)->f30);
        func_02012374((struct Evt *)a, (struct Evt **)r);
        (*state)++;
        break;
    case 3:
        return 1;
    }
    return 0;
}


int func_02184584(int ctx, int *state, u8 *p)
{
    int x;
    int z;

    x = *(int *)&((struct Obj00082 *)p)->f0;
    z = *(int *)&((struct Obj00082 *)p)->f8;

    switch (*state) {
    case 0:
        func_0218403C(p);
        func_02012374((struct Evt *)ctx, func_02161824((void *)x, (void *)z));
        (*state)++;
        break;
    case 1:
        if (((struct Obj00082 *)p)->f40 != 0 && ((struct Obj00082 *)p)->f44 != 0) {
            func_02012374((struct Evt *)ctx, (struct Evt **)func_021BE8D4((void *)x, z, 0, 0));
        } else {
            func_02012374((struct Evt *)ctx, (struct Evt **)func_021BE8D4((void *)x, z, func_021BE89C(((struct Obj00082 *)p)->fC, ((struct Obj00082 *)p)->f14), 0));
        }
        (*state)++;
        break;
    case 2:
        func_02012374((struct Evt *)ctx, func_02184360(p, ((struct Obj00082 *)p)->f30));
        (*state)++;
        break;
    case 3:
        if (((struct Obj00082 *)p)->f40 != 0 && ((struct Obj00082 *)p)->f44 != 0) {
            func_02012374((struct Evt *)ctx, (struct Evt **)func_021BE92C((void *)x, z, 3, 0, 0, (u8)((struct Obj00082 *)p)->f48, (u8)((struct Obj00082 *)p)->f4A));
        } else {
            func_02012374((struct Evt *)ctx, (struct Evt **)func_021BE92C((void *)x, z, func_021BE8B8(((struct Obj00082 *)p)->fC, ((struct Obj00082 *)p)->f14), 0, 1, 0, 0));
        }
        (*state)++;
        break;
    case 4:
        return 1;
    }
    return 0;
}


int func_0218466C(int ctx, int *state, u8 *p)
{
    int v;
    int x;
    int z;
    int y;

    x = ((struct Obj04190 *)p)->f0;
    y = ((struct Obj04190 *)p)->f4;
    z = ((struct Obj04190 *)p)->f8;
    v = (int)func_02012A30((const struct BigObj *)y);

    switch (*state) {
    case 0:
        func_02012374((struct Evt *)ctx, func_02161824((void *)x, (void *)z));
        (*state)++;
        break;
    case 8:
        func_02012374((struct Evt *)ctx, (struct Evt **)func_021BE8D4((void *)x, z, 2, 0));
        (*state)++;
        break;
    case 9:
        func_02029D44(v, y, ((struct Obj04190 *)p)->f14, (u8)((struct Obj04190 *)p)->f4A);
        func_02029D7C(v, y);
        (*state)++;
        break;
    case 10:
        func_02012374((struct Evt *)ctx, func_02184360(p, ((struct Obj04190 *)p)->f30));
        (*state)++;
        break;
    case 11:
        func_02012374((struct Evt *)ctx, (struct Evt **)func_021BE92C((void *)x, z, 2, 0, 0, 0, 0));
        (*state)++;
        break;
    case 12:
        func_021BC550((void *)func_02188D20((u8 *)z), *(s16 *)&((struct Obj04190 *)p)->f14);
        return 1;
    default:
        (*state)++;
        break;
    }
    return 0;
}


int func_02184730(int ctx, int *state, u8 *p)
{
    int v;
    int x;
    int z;
    int y;

    x = ((struct Obj05964 *)p)->f0;
    y = ((struct Obj05964 *)p)->f4;
    z = ((struct Obj05964 *)p)->f8;
    v = func_02012A30((const struct BigObj *)y);

    switch (*state) {
    case 0:
        func_02012374((struct Evt *)ctx, func_02161824((void *)x, (void *)z));
        (*state)++;
        break;
    case 1:
        func_02012374((struct Evt *)ctx, (struct Evt **)func_021BFD34(ctx, x, z, p + 0x34));
        (*state)++;
        break;
    case 2:
        func_02029D44(v, y, ((struct Obj05964 *)p)->f14, (u8)((struct Obj05964 *)p)->f4A);
        func_02029D7C(v, y);
        (*state)++;
        break;
    case 3:
        func_02012374((struct Evt *)ctx, func_02184360(p, 0));
        (*state)++;
        break;
    case 4:
        func_02012374((struct Evt *)ctx, (struct Evt **)func_021BF58C(ctx, (void *)x, z));
        (*state)++;
        break;
    case 5:
        return 1;
    }
    return 0;
}


int func_021847CC(int ctx, int *state, u8 *p)
{
    int v;
    int x;
    int z;
    int y;

    x = *(int *)&((struct Obj00082 *)p)->f0;
    y = ((struct Obj00082 *)p)->f4;
    z = *(int *)&((struct Obj00082 *)p)->f8;
    v = func_02012A30((const struct BigObj *)y);

    switch (*state) {
    case 0:
        func_0218403C(p);
        func_02012374((struct Evt *)ctx, func_02161824((void *)x, (void *)z));
        (*state)++;
        break;
    case 1:
        func_02012374((struct Evt *)ctx, func_021BFD70(ctx, (void *)x, z, ((struct Obj00082 *)p)->f44));
        (*state)++;
        break;
    case 2:
        func_02185F48((void *)y);
        func_02029D44(v, y, ((struct Obj00082 *)p)->f14, (u8)((struct Obj00082 *)p)->f4A);
        func_02029D7C(v, y);
        (*state)++;
        break;
    case 3:
        func_02012374((struct Evt *)ctx, func_02184360(p, 2));
        (*state)++;
        break;
    case 4:
        func_02012374((struct Evt *)ctx, func_021BF5B4(ctx, x, z, ((struct Obj00082 *)p)->f44,
                                         ((struct Obj00082 *)p)->f48, ((struct Obj00082 *)p)->f4A));
        (*state)++;
        break;
    case 5:
        func_021BC550((void *)func_02188D20((u8 *)z), *(s16 *)&((struct Obj00082 *)p)->f14);
        return 1;
    }
    return 0;
}


int func_02184894(void *a, int *state, Obj *o)
{
    int f0 = o->f00;
    int f4 = o->f04;
    int f8 = o->f08;
    int h = func_02012A30((const void *)f4);

    switch (*state) {
    case 0:
        func_0218403C((u8 *)o);
        func_02012374(a, func_02161824((void *)f0, (void *)f8));
        (*state)++;
        break;
    case 1:
        func_02012374(a, func_021BFDA0((int)a, (void *)f0, f8, o->f44));
        (*state)++;
        break;
    case 2:
        func_02185F48((void *)f4);
        func_02029D44((int)h, (int)f4, (u16)o->f14, (u8)o->f4a);
        func_02029D7C(h, f4);
        (*state)++;
        break;
    case 3:
        func_02012374(a, func_02184360((u8 *)o, 2));
        (*state)++;
        break;
    case 4:
        func_02012374(a, (struct Evt **)func_021BF5E8((u32)a, f0, f8, o->f44, o->f48, o->f4a));
        (*state)++;
        break;
    case 5:
        func_021BC550((void *)func_02188D20((u8 *)f8), o->f14);
        return 1;
    }
    return 0;
}


int func_0218495C(int ctx, int *state, u8 *p)
{
    int v;
    int x;
    int z;
    int y;

    x = ((struct Obj04977 *)p)->f0;
    y = ((struct Obj04977 *)p)->f4;
    z = ((struct Obj04977 *)p)->f8;
    v = func_02012A30((const struct BigObj *)y);

    switch (*state) {
    case 0:
        func_02012374((struct Evt *)ctx, func_02161824((void *)x, (void *)z));
        (*state)++;
        break;
    case 1:
        func_02012374((struct Evt *)ctx, func_021BFDD0(ctx, (void *)x, z, 1));
        (*state)++;
        break;
    case 2:
        func_02012B2C((struct Rec44 *)((int)func_020127A4((struct SaveBlock *)y)), 0);
        func_02029D44(v, y, ((struct Obj04977 *)p)->f14, (u8)((struct Obj04977 *)p)->f4A);
        func_02029D7C(v, y);
        (*state)++;
        break;
    case 3:
        func_02012374((struct Evt *)ctx, func_02184360(p, 3));
        (*state)++;
        break;
    case 4:
        func_02012374((struct Evt *)ctx, func_021BF61C(ctx, x, z));
        (*state)++;
        break;
    case 5:
        func_021BC550((void *)func_02188D20((u8 *)z), *(s16 *)&((struct Obj04977 *)p)->f14);
        return 1;
    }
    return 0;
}


int func_02184A14(int ctx, int *state, u8 *p)
{
    int x = *(int *)&((struct Obj00082 *)p)->f0;
    int z = *(int *)&((struct Obj00082 *)p)->f8;
    int t = func_02188D38((u8 *)z);

    switch (*state) {
    case 0:
        func_02012374((struct Evt *)ctx, (struct Evt **)func_021BE8D4((void *)x, z, 1, 0));
        (*state)++;
        break;
    case 1:
        if (func_021C6E48(t)) {
            func_02012374((struct Evt *)ctx, func_02161824((void *)x, (void *)z));
            (*state)++;
        }
        break;
    case 2:
        func_02012374((struct Evt *)ctx, func_02184360(p, 0));
        (*state)++;
        break;
    case 3:
        func_02012374((struct Evt *)ctx, (struct Evt **)func_021BE92C((void *)x, z, 1, 0, 1, 0, 0));
        (*state)++;
        break;
    case 4:
        func_021BC550((void *)func_02188D20((u8 *)z), *(s16 *)&((struct Obj00082 *)p)->f14);
        return 1;
    }
    return 0;
}


int func_02184AB4(int ctx, int *state, u8 *p)
{
    int x = ((struct Obj09424 *)p)->f0;
    int z = ((struct Obj09424 *)p)->f8;
    int r;
    S9C *o;

    switch (*state) {
    case 0:
        func_02012374((struct Evt *)ctx, func_02161824((void *)x, (void *)z));
        (*state)++;
        break;
    case 1:
        func_02012374((struct Evt *)ctx, (struct Evt **)func_021BE8D4((void *)x, z, 0, 0));
        (*state)++;
        break;
    case 2:
        r = (int)func_020122C0((void *)x, 0, func_02184504, 0x9c);
        o = func_020124E8((struct Obj *)r);
        *o = *(S9C *)p;
        func_02012374((struct Evt *)ctx, (struct Evt **)r);
        (*state)++;
        break;
    case 3:
        func_02012374((struct Evt *)ctx, (struct Evt **)func_021BE92C((void *)x, z, 0, 0, 1, 0, 0));
        (*state)++;
        break;
    case 4:
        func_021BC550((void *)func_02188D20((u8 *)z), ((struct Obj09424 *)p)->f14);
        return 1;
    }
    return 0;
}


int func_02184B54(int ctx, int *state, u8 *p)
{
    int v;
    int x;
    int z;
    int y;

    x = ((struct Obj04978 *)p)->f0;
    y = ((struct Obj04978 *)p)->f4;
    z = ((struct Obj04978 *)p)->f8;
    v = func_02012A30((const struct BigObj *)y);

    switch (*state) {
    case 0:
        func_02012374((struct Evt *)ctx, func_02161824((void *)x, (void *)z));
        (*state)++;
        break;
    case 1:
        func_02012374((struct Evt *)ctx, func_021BFE00(ctx, (void *)x, z));
        (*state)++;
        break;
    case 2:
        func_02029D44(v, y, ((struct Obj04978 *)p)->f14, (u8)((struct Obj04978 *)p)->f4A);
        func_02029D7C(v, y);
        func_02012374((struct Evt *)ctx, func_02184360(p, 0));
        (*state)++;
        break;
    case 3:
        func_02012374((struct Evt *)ctx, (struct Evt **)func_021BF644(ctx, x, z));
        (*state)++;
        break;
    case 4:
        func_021BC550((void *)func_02188D20((u8 *)z), *(s16 *)&((struct Obj04978 *)p)->f14);
        return 1;
    }
    return 0;
}


int func_02184BF8(void *ctx, int *st, int *p)
{
    int a = p[0];
    int b = p[2];
    int r;

    switch (*st) {
    case 0:
        r = (int)func_021BFDD0((int)ctx, (void *)a, b, 0);
    join:
        func_02012374(ctx, (struct Evt **)r);
        (*st)++;
        break;
    case 1:
        r = (int)func_02184360((u8 *)p, 0);
        goto join;
    case 2:
        func_02034A5C((int)ov012_id);
        func_02034AC4((int)ov011_id);
        func_02158780(ctx, 0x83A, 0, 0, 0x15);
        (*st)++;
        break;
    case 3:
        return 1;
    }
    return 0;
}
