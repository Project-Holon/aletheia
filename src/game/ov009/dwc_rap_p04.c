/*
 * file:     dwc_rap_p04.c
 * unit:     yes
 * function: func_02155338, func_0215536C, func_02155374, func_02155388, func_0215539C, func_021554A0
 * address:  0x02155338
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02156874 0x02156874 thumb ov009
 *   func_02156B70 0x02156B70 thumb ov009
 *   func_02156B8C 0x02156B8C thumb ov009
 *   func_02156D70 0x02156D70 thumb ov009
 *   func_02156CD0 0x02156CD0 thumb ov009
 *   g_021A1B80  0x021A1B80  data
 *   g_021A8264  0x021A8264  data
 *   d_021A8264     0x021A8264  data  ov009  a4
 *   d_021A1C5C     0x021A1C5C  data  ov009  a1
 *   d_021A1C60     0x021A1C60  data  ov009  a1
 *   func_0203D798  0x0203D798  arm
 *   func_0203D7C8  0x0203D7C8  arm
 *   func_02034714  0x02034714  arm
 *   func_020597C8  0x020597C8  arm
 *   func_02059760  0x02059760  arm
 *   func_02156C60 0x02156C60 thumb ov009
 *   func_0203D7FC 0x0203D7FC arm
 *   func_02059F18 0x02059F18 arm
 */
#include "../../matched/include/G__anon_Work.h"

struct DWCstAccUserData;
typedef signed short s16;

typedef unsigned int u32;

typedef unsigned char  u8;

typedef unsigned short u16;

typedef struct {
    char pad0[0x56];
    u16 heap;
    char pad58[0x60 - 0x58];
    u8 b60;
} Ctx;

typedef struct {
    char pad0[0x100];
    int w100;
    char pad104[0x108 - 0x104];
    int w108;
    char pad10C[0x17C - 0x10C];
    int arr[32];
    char pad1FC[0x32C - 0x1FC];
    u8 bytes[32];
    char pad34C[0x764 - 0x34C];
    int w764;
    char pad768[0x770 - 0x768];
    int w770;
    int w774;
    char pad778[0x77C - 0x778];
    int w77C;
    char pad780[0x782 - 0x780];
    u16 h782;
    char pad784[0x790 - 0x784];
    int w790;
    u16 h794;
    u16 h796;
    char pad798[0x79E - 0x798];
    u8 b79E;
    char pad79F[0x7A1 - 0x79F];
    u8 b7A1;
    char pad7A2[0x7AC - 0x7A2];
} G;

extern unsigned char func_02156874(int);
extern s16 func_02156B70(void);
extern int func_02156B8C(void);
extern void func_02156D70(u32);
extern int func_02156CD0(void);
void *func_0203D798(void);
void *func_0203D7C8(u32 heap, u32 size, const char *file, u16 line);
void func_02034714(const char *expr, u32 line, const char *file);
int func_020597C8(struct DWCstAccUserData *userdata);
int func_02059760(struct DWCstAccUserData *userdata);
extern void func_02156C60(void *);
extern void func_0203D7FC(void *);
extern void func_02059F18(void);
int func_02155338(int n);
s16 func_0215534C(void);
int func_02155354(void);
void func_0215535C(u32 v);
int func_02155364(void);
void *func_0215536C(void);
void func_02155374(int v);
int func_02155388(void);
int func_0215539C(int a0, int a1);
void func_021554A0(void);
extern char g_021A1B80[];
extern struct _anon_Work *g_021A8264;
extern G *d_021A8264;
extern char d_021A1C5C[];
extern char d_021A1C60[];

/*
 * Follower func_0215535C resolves through the verified existing 02156CF4
 * unit after its function inventory was corrected to include 02156D70.
 */
int func_02155338(int n)
{
    if (func_02156874(n) == 6) return 1;
    return 0;
}

s16 func_0215534C(void)
{
    return func_02156B70();
}

int func_02155354(void)
{
    return func_02156B8C();
}

void func_0215535C(u32 v)
{
    func_02156D70(v);
}

int func_02155364(void)
{
    return func_02156CD0();
}


/*
 * Address of the module state object.
 */
void *func_0215536C(void)
{
    return g_021A1B80;
}


/*
 * Stores a word at +0x754 of the block the pointer holds.
 */
void func_02155374(int v)
{
    *(int *)(((char *)g_021A8264) + 0x754) = v;
}


/*
 * True when the block pointer is set.
 */
int func_02155388(void)
{
    return ((char *)g_021A8264) != 0;
}


/*
 * Allocates the 0x7AC-byte ov009 work block into d_021A8264 (asserting it
 * was empty) and initialises it.  func_0203D7C8's last two arguments look
 * like a file/line pair (d_021A1C60, 302).
 */
int func_0215539C(int a0, int a1)
{
    Ctx *ctx;
    int i;

    ctx = func_0203D798();
    if (d_021A8264 != 0)
        func_02034714(d_021A1C5C, 0, d_021A1C5C);
    d_021A8264 = func_0203D7C8(ctx->heap, sizeof(G), d_021A1C60, 302);
    for (i = 0; i < 32; i++)
        d_021A8264->arr[i] = -1;
    func_02155374(0);
    d_021A8264->w77C = 0;
    d_021A8264->w770 = -1;
    d_021A8264->w764 = ctx->b60;
    d_021A8264->w774 = -1;
    d_021A8264->h782 = 0;
    d_021A8264->b79E = 0;
    d_021A8264->h794 = 1;
    d_021A8264->w790 = 1;
    d_021A8264->h796 = 1;
    d_021A8264->w108 = a0;
    d_021A8264->w100 = a1;
    d_021A8264->b7A1 = 1;
    for (i = 0; i < 32; i++)
        d_021A8264->bytes[i] = 0;
    if (func_020597C8((struct DWCstAccUserData *)d_021A8264->w108) == 0)
        return 1;
    if (func_02059760((struct DWCstAccUserData *)d_021A8264->w108) == 0)
        return 2;
    return 0;
}

/*
 * func_02156C60 receives the preceding call's live r0 result; its older
 * source declares no arguments. This caller preserves that register payload.
 */
void func_021554A0(void)
{
    if (d_021A8264) {
        func_02156C60(func_0203D798());
        func_0203D7FC(d_021A8264);
        d_021A8264 = 0;
    }
    func_02059F18();
}
