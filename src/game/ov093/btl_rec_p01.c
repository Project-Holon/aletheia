/*
 * file:     btl_rec_p01.c
 * unit:     yes
 * function: func_021EE104, func_021EE200, func_021EE21C, func_021EE224, func_021EE228, func_021EE23C, func_021EE264
 * address:  0x021EE104
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
 *   func_02082BCC 0x02082BCC arm
 *   func_021B9AF8 0x021B9AF8 thumb ov093
 *   func_021B9B94 0x021B9B94 thumb ov093
 *   func_021B9C00 0x021B9C00 thumb ov093
 *   func_021D5B68 0x021D5B68 thumb ov093
 *   func_021D62A8 0x021D62A8 thumb ov093
 *   func_021D5B7C 0x021D5B7C thumb ov093
 *   func_021EF694  0x021EF694  thumb  ov093
 *   func_021ECEB8  0x021ECEB8  thumb  ov093
 *   func_021ECF68   0x021ECF68  thumb  ov093
 *   func_0204E720  0x0204E720  arm
 *   func_02043B5C  0x02043B5C  arm
 *   func_02045334  0x02045334  arm
 *   func_021EB318  0x021EB318  thumb  ov093
 *   func_021EE3E8  0x021EE3E8  thumb  ov093
 */
#include "../../matched/include/Obj00027.h"
#include "../../matched/include/Obj06295.h"

struct Q1;
struct S2;
struct Unk021D62A8;
struct T;
struct CharBuf;
struct Descriptor;
struct C;
typedef unsigned char u8;

typedef signed char s8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed short s16;

typedef signed int s32;

struct Q {
    int f00;
    int f04;
};

struct T {
    u16 v[7];
};

struct O {
    u8 pad00[0xe0];
    int (*fe0)(void *, void *);
    int (*fe4)(void *, void *);
    void *fe8;
    int fec;
};

extern void func_02082BCC(void *, u8, u32);
extern char *func_021B9AF8(char *p, int i);
extern u8 func_021B9B94(struct Q1 *p);
extern u8 *func_021B9C00(struct S2 *p, u32 i);
extern int func_021D5B68(void *);
extern int func_021D62A8(struct Unk021D62A8 *p);
extern int func_021D5B7C(void *);
extern void func_021EF694(u32 a, u32 b);
extern void func_021ECEB8(u8 *, u32, u16, u32);
extern int func_021ECF68(struct T *p);
extern void func_0204E720(u32 a, s32 b, s32 c, s32 d);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_02045334(struct Descriptor *d);
extern u32 func_021EB318(void);
extern int func_021EE3E8(int *st, struct C *c);
void func_021EE104(u8 *p, u32 *out, u32 a, u32 b, u32 flag);
void func_021EE200(u8 *p);
int func_021EE21C(u8 *p);
void func_021EE224(char *p);
void func_021EE228(void);
void func_021EE23C(struct Q *q);
int func_021EE25C(void);
void func_021EE264(char *o, int a, struct T *src);

/*
 * tail: 021EE1FE..021EE200 is zero alignment padding.
 */
void func_021EE104(u8 *p, u32 *out, u32 a, u32 b, u32 flag)
{
    void *groups[2] = {0, 0};
    int counts[2] = {0, 0};
    int i;
    int side;
    s8 slot;
    void *entry;
    func_02082BCC(out, 0, 28);
    groups[0] = func_021B9AF8(((struct Obj00027 *)p)->f138, a);
    counts[0] = func_021B9B94(groups[0]);
    if (b < 4) {
        groups[1] = func_021B9AF8(((struct Obj00027 *)p)->f138, b);
        counts[1] = func_021B9B94(groups[1]);
        if (counts[0] > 3) counts[0] = 3;
        if (counts[1] > 3) counts[1] = 3;
    }
    out[0] = flag;
    for (i = 0; i < 6; i++) {
        if (i < counts[0] + counts[1]) {
            if (i < counts[0]) { side = 0; slot = i; }
            else { side = 1; slot = i - counts[0]; }
            entry = func_021B9C00(groups[side], (u8)slot);
            if (func_021D5B68(entry)) out[side * 3 + slot + 1] = 2;
            else if (func_021D62A8(entry)) out[side * 3 + slot + 1] = 3;
            else if (!func_021D5B7C(entry)) out[side * 3 + slot + 1] = 0;
            else out[side * 3 + slot + 1] = 1;
        }
    }
}


void func_021EE200(u8 *p)
{
    func_021EF694(((struct Obj00027 *)p)->f34, 0xf);
    func_021ECEB8(p, ((struct Obj00027 *)p)->f34, 0, 0);
}


/*
 * Untraced mid-stream entry point: a plain tail thunk, `ldr r3,=T; bx r3`, whose pool word names func_021ECF68.
 */
int func_021EE21C(u8 *p) { return func_021ECF68((struct T *)p); }

void func_021EE224(char *p)
{
}


void func_021EE228(void)
{
    int x = 0x10;
    func_0204E720(1, 0, x, x - 0x13);
}


void func_021EE23C(struct Q *q)
{
    func_02043B5C((struct CharBuf *)q->f04, 12);
    func_02045334((struct Descriptor *)q->f00);
    func_0204E720(1, 16, 0, -3);
}


int func_021EE25C(void)
{
    return func_021EB318();
}


void func_021EE264(char *o, int a, struct T *src)
{
    ((struct Obj06295 *)o)->f16C = a;
    *(struct T *)(o + 0x170) = *src;
    ((struct O *)o)->fe0 = 0;
    ((struct O *)o)->fe4 = (int (*)(void *, void *))func_021EE3E8;
    ((struct O *)o)->fe8 = o;
    ((struct O *)o)->fec = 0;
}
