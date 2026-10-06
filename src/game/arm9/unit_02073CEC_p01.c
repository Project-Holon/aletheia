/*
 * file:     unit_02073CEC_p01.c
 * unit:     yes
 * function: func_02073CEC, func_02073D5C, func_02073D7C
 * address:  0x02073CEC
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   g_0214E9B4       0x0214E9B4  data
 *   g_0214E9FC       0x0214E9FC  data
 *   func_02075C08  0x02075C08  arm
 *   func_02075C20  0x02075C20  arm
 *   func_02073DFC  0x02073DFC  arm
 *   func_02075BD4  0x02075BD4  arm
 *   func_02089638  0x02089638  arm
 */
struct LerpObj;
struct Obj;
typedef unsigned char  u8;

typedef unsigned int   u32;

typedef signed int     s32;

typedef struct St {
    u32 f00;
    u32 f04;
    u8  pad08[0x18];
    u32 f20;
    u32 f24;
    u32 f28;
    s32 f2c;
    u8  pad30[0x0c];
    u8  f3c[0x10];
    u32 f4c;
    s32 f50;
} St;

struct A {
    u8  p00[0x2c];
    int b0 : 1;
    int b1 : 1;
    int hi : 30;
    u8  p30[0x10];
    u32 f40;
    u32 f44;
    u32 f48;
    u32 f4c;
    u32 f50;
};

extern void func_02073BF0(struct A *, u32);
extern u32 func_02087988(void);
extern void func_0208799C(u32);
extern void func_020894B4(u32, u32, u32, u32);
extern void func_02075C08(struct LerpObj *obj);
extern int func_02075C20(struct LerpObj *obj);
extern void func_02073DFC(void);
extern s32 func_02075BD4(struct Obj *o);
extern void func_02089638(u32 a, s32 b, s32 c);
void func_02073D5C(void);
void func_02073D7C(void);
extern u32 g_0214E9B4;
extern St g_0214E9FC;

void func_02073CEC(struct A *a) {
    u32 r;
    if (!a->b1) return;
    while (a->f40 != 0) {
        r = func_02087988();
        func_02073BF0(a, 1);
        func_0208799C(r);
    }
    func_020894B4(a->f4c, 0, 1u << a->f48, 0);
}


void func_02073D5C(void);



/*
 * Clears the two words of the sequence/index pair to zero.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02073D5C.c \
 *       --func func_02073D5C --addr 0x02073D5C --cc 1.1p1 --arm
 */
void func_02073D5C(void)
{
    g_0214E9B4 = 0;
    g_0214E9FC.f00 = 0;
}


/*
 * Blocked at MATCH: every concrete byte of the 128 is identical and 5 of the
 * 6 relocations resolve.  The one that does not is the PC24 at +0x44 to
 * func_02073DFC, this function's own immediate follower at 0x02073DFC: that
 * `bl` is the only branch to the address anywhere in the image, so neither
 * `label` nor `matched` can attest it while 0x02073DFC is unfiled.
 * func_02073DFC was worked this pass and reached 228 of its 232 bytes with
 * the whole structure right; see docs/notes/func_02073DFC.c.txt.  Filing it
 * EXACT promotes this file with no C change, and this file in turn is one of
 * the two remaining blockers on src/pending/func_02072758.c.
 */
void func_02073D7C(void)
{
    St *s;
    s32 v;

    s = &g_0214E9FC;
    if (s->f00 == 0) {
        return;
    }
    if (s->f04 != 0) {
        return;
    }

    func_02075C08((struct LerpObj *)s->f3c);

    if (s->f4c != 0 && func_02075C20((struct LerpObj *)s->f3c) != 0) {
        func_02073DFC();
        return;
    }

    v = func_02075BD4((struct Obj *)s->f3c) >> 8;
    if (v == s->f50) {
        return;
    }
    func_02089638(s->f24, v, 0);
    s->f50 = v;
}
