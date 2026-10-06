/*
 * file:     net_state_p14.c
 * unit:     yes
 * function: func_02037680, func_02037700, func_0203778C
 * address:  0x02037680
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
 *   str_020A7A24   0x020A7A24  data
 *   str_020A7A34   0x020A7A34  data
 *   g_021469D0     0x021469D0  data
 *   func_02034714  0x02034714  arm
 *   func_0203640C  0x0203640C  arm
 *   func_02037234  0x02037234  arm
 *   func_0203D798  0x0203D798  arm
 *   func_0203D788  0x0203D788  arm
 *   func_02037288  0x02037288  arm
 *   g_020387A0     0x020387A0  data
 */
#include "../../matched/include/Obj15915.h"

struct Rec;
typedef unsigned char u8;

typedef unsigned int  u32;

struct Net {
    u8 pad00[0x10];
    u8 *f10;
    u8 pad14[0x4c - 0x14];
    u8 f4C[0x11c - 0x4c];
    u8 f11C[0x1b4 - 0x11c];
    u32 f1B4[8];
    u8 pad1D4[0x1d7 - 0x1d4];
    u8 f1D7[8];
    u8 pad1DF[0x1e0 - 0x1df];
    u32 f1E0;
};

typedef unsigned short u16;

struct Ctx {
    u8   pad00[0x64];
    u8   f64;          /* 0x64 */
    u8   pad65[0x6c - 0x65];
    u16  f6c;          /* 0x6c */
    u8   pad6e[0x340 - 0x6e];
    u32 *f340;         /* 0x340 */
    u32  pad344[2];    /* 0x344, 0x348 */
    u32  f34c;         /* 0x34c */
};

struct Oth {
    u8  pad0[0x56];
    u16 f56;           /* 0x56 */
};

extern void func_02034714(const char *expr, u32 line, const char *file);
extern void func_0203640C(struct Rec *p, u32 a, int b);
extern void func_02037234(u8 *p);
extern void *func_0203D798(void);
extern void *func_0203D788(void);
extern int func_02037288(u32 a0, u32 heap, u32 c);
void func_02037680(int i);
int func_02037700(u32 a0, u32 a1);
u32 func_0203778C(u32 p);
extern const u8 str_020A7A24[];
extern const u8 str_020A7A34[];
extern struct Net *g_021469D0;
extern u8   g_020387A0[];


/*
 * Reset one net_system slot (docs/families/net_system.h).  The 8-byte
 * "colouring" residue of docs/notes/pkt_02037288_wave25.c.txt was a wrong
 * reading of the callee's argument list: func_0203640C here takes THREE
 * arguments, (header, buffer, length), and r2 at the call is the slot
 * stride f1E0 passed on purpose as the buffer length, not a leftover of
 * the mla.  The slot header is initialised to { f10 + i * f1E0, f1E0 }.
 */
void func_02037680(int i)
{
    if (i >= 8) {
        func_02034714((const char *)str_020A7A24, 0x155, (const char *)str_020A7A34);
    }
    g_021469D0->f1B4[i] = 0;
    func_0203640C((struct Rec *)(g_021469D0->f4C + i * 16), (u32)(g_021469D0->f10 + i * g_021469D0->f1E0), g_021469D0->f1E0);
    g_021469D0->f1D7[i] = 0;
    func_02037234(g_021469D0->f11C + i * 16);
}


/*
 * Filed on lane 1 as the single-caller callee of src/pending/func_0203C864.c.
 * The 0x340 field is a table of function pointers reached through two
 * indirect calls; the third reaches a slot at +0x68 past two unread words at
 * +0x44 and +0x48, which is why the struct keeps them as padding.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02037700.c \
 *       --func func_02037700 --addr 0x02037700 --cc 1.1p1 --arm
 */
int func_02037700(u32 a0, u32 a1)
{
    struct Oth *o = (struct Oth *)func_0203D798();
    struct Ctx *c = func_0203D788();
    u32 flag = 0;

    if (c->f64 != 0 && c->f6c != 0)
        flag = 1;
    func_02037288(a0, a1, flag);
    ((void (*)(u16, struct Ctx *, u32, u32))c->f340[1])(o->f56, c, 0, c->f34c);
    ((void (*)(u32))c->f340[2])(0);
    ((void (*)(u8 *))c->f340[0x68 / 4])(g_020387A0);
    return 1;
}


/*
 * 32-byte hook dispatcher: func_0203D788 returns the current context, whose
 * word at +0x340 names a vtable whose slot +0x90 is called with the incoming
 * argument.  The call is a real `blx r1` and not a tail call because r4 has to
 * be restored afterwards, which is what makes it `return f(p)` and not a
 * `bx`.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203778C.c \
 *       --func func_0203778C --addr 0x0203778C --cc 1.1p1 --arm
 */
u32 func_0203778C(u32 p)
{
    char *c = func_0203D788();
    u32 (*f)(u32) = *(u32 (**)(u32))(*(char * *)&((struct Obj15915 *)c)->f340 + 0x90);

    return f(p);
}
