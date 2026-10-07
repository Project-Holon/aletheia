/*
 * file:     palette_anime_p16.c
 * unit:     yes
 * function: func_021C295C, func_021C299C, func_021C29B4, func_021C29C8, func_021C29D8, func_021C29E8, func_021C29F0, func_021C29F8, func_021C2A00, func_021C2A08
 * address:  0x021C295C
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0204B294 0x0204B294 arm
 *   func_0204B3B4  0x0204B3B4  arm
 *   func_021C2DA0  0x021C2DA0  thumb  ov217
 *   func_021C2DCC  0x021C2DCC  thumb  ov217
 *   func_021C2DC4  0x021C2DC4  thumb  ov217
 *   func_021C2E20  0x021C2E20  thumb  ov217
 *   func_021C2DE0  0x021C2DE0  thumb  ov217
 *   func_021C2A30  0x021C2A30  thumb  ov217
 *   func_021C2A18  0x021C2A18  thumb  ov217
 *   func_021C2A28  0x021C2A28  thumb  ov217
 *   func_021C2D88  0x021C2D88  thumb  ov217
 */
#include "../../matched/include/Obj08446.h"
#include "../../matched/include/Obj14767.h"

struct Obj;
struct arg_021C295C {
    unsigned short a;
    unsigned short b;
    unsigned short c;
    unsigned char d;
    unsigned char e;
};

typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed int     s32;

typedef struct {
    u32 w[5];
} Blk20;

typedef signed char    s8;

typedef signed short   s16;

typedef struct {
    u32 w[8];
} Rec;

extern struct Obj *func_0204B294(void *, unsigned int, unsigned int, unsigned int, const void *, unsigned short, unsigned short);
extern void func_0204B3B4(struct Obj *p);
extern u32 func_021C2DA0(u32 a0);
extern void func_021C2DCC(char *p);
extern u32 func_021C2DC4(void *a0);
extern void func_021C2E20(char *p);
extern void func_021C2DE0(char *p, unsigned short *dst, unsigned short *src, int count);
extern void func_021C2A30(Rec *);
extern void func_021C2A18(u8 *p, u32 b, u16 c);
extern void func_021C2A28(void *p);
extern int func_021C2D88(char *p);
void func_021C295C(unsigned char *p);
void func_021C299C(int *p);
void func_021C29B4(void *p, const void *src);
u32 func_021C29C8(u32 a0);
u32 func_021C29D8(void *a0);
void func_021C29E8(void *p, u32 b, u32 c, u32 d);
void func_021C29F0(Rec *p);
void func_021C29F8(u8 *p, u32 b, u16 c);
void func_021C2A00(u32 a0);
int func_021C2A08(char *p);


void func_021C295C(unsigned char *p)
{
    struct arg_021C295C s;
    int *q = (int *)(p + 0x20);
    int i;

    s.a = 0;
    s.b = 0;
    s.c = 0;
    s.d = 0;
    s.e = 0;
    for (i = 0; i < 4; i++) {
        *(int *)(p + 0x10 + i * 4) =
            (int)func_0204B294((void *)((struct Obj14767 *)p)->fC, q[0], q[1], q[2], &s,
                          ((struct Obj08446 *)q)->fC,
                          ((struct Obj14767 *)p)->f0);
    }
}


/*
 * Addresses are Black-image addresses.
 */
void func_021C299C(int *p)
{
    int i;
    for (i = 0; i < 4; i++)
        func_0204B3B4((struct Obj *)p[i + 4]);
}


/*
 * Copy a 20-byte block into the record at +0x20.
 *
 * Addresses are Black-image addresses.
 */
void func_021C29B4(void *p, const void *src)
{
    *(Blk20 *)((char *)p + 0x20) = *(const Blk20 *)src;
}

/*
 * Reconstructed from the listing (.inst decoded).
 *
 * Addresses are Black-image addresses.
 */
u32 func_021C29C8(u32 a0)
{
    u32 v1 = func_021C2DA0(a0);
    func_021C2DCC((char *)v1);
    return v1;
}

u32 func_021C29D8(void *a0)
{
    func_021C2E20((char *)a0);
    return func_021C2DC4(a0);
}


void func_021C29E8(void *p, u32 b, u32 c, u32 d)
{
    func_021C2DE0(p, (short unsigned int *)b, (short unsigned int *)c, d);
}


/*
 * Tail-call veneer: passes its argument through to func_021C2A30.
 *
 * Addresses are Black-image addresses.
 */
void func_021C29F0(Rec *p)
{
    func_021C2A30(p);
}


/*
 * Unlabelled 4-byte tail-call veneer in a .word run; pool 0x021C29FC names
 * func_021C2A18. Middle of the func_021BA31C blocker chain.
 *
 * Addresses are Black-image addresses.
 */
void func_021C29F8(u8 *p, u32 b, u16 c)
{
    func_021C2A18(p, b, c);
}

/*
 * Tail-call veneer to func_021C2A28.
 *
 * Addresses are Black-image addresses.
 */
void func_021C2A00(u32 a0)
{
    func_021C2A28((void *)a0);
}


/*
 * Tail-call veneer: branch to func_021C2D88.
 *
 * Addresses are Black-image addresses.
 */
int func_021C2A08(char *p)
{
    return func_021C2D88(p);
}
