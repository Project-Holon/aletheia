/*
 * file:     btl_server_p02.c
 * unit:     yes
 * function: func_021B9940, func_021B994C, func_021B997C, func_021B99B8, func_021B99C0, func_021B99E0, func_021B99F0
 * address:  0x021B9940
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
 *   func_021B8ED8 0x021B8ED8 thumb ov093
 *   func_021B8DE4 0x021B8DE4 thumb ov093
 *   func_021B9114 0x021B9114 thumb ov093
 *   func_02007B50 0x02007B50 thumb
 *   func_02007C70 0x02007C70 thumb
 *   func_021B6994  0x021B6994  thumb  ov093
 *   func_021B8588 0x021B8588 thumb ov093
 *   data_021EFD70  0x021EFD70  data  ov093
 */
#include "../../matched/include/Obj13279.h"

struct PerapVoice;
struct S;
typedef unsigned char u8;

typedef unsigned int u32;

typedef unsigned short u16;

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

struct Unk021EFD70 { u8 b[10]; };

extern u8 func_021B8ED8(u8 *p, u8 k);
extern u8 func_021B8DE4(char *p, int i);
extern u8 func_021B9114(u8 **);
extern void *func_02007B50(void **p);
extern u32 func_02007C70(struct PerapVoice *p);
int func_021B6994(struct S **pp, u32 b);
extern u32 func_021B8588(void **p);
u8 *func_021B9940(char *p, u8 i);
int func_021B994C(u8 *p, u32 i, void **out);
int func_021B997C(u8 *p, unsigned int i);
int func_021B99B8(void *pp, unsigned int b);
int func_021B99C0(struct S **p, u32 b);
struct Unk021EFD70 *func_021B99E0(int i);
u32 func_021B99F0(u32 x);
extern struct Unk021EFD70 data_021EFD70[];


u8 *func_021B9940(char *p, u8 i)
{
    return *(u8 **)(p + i * 4 + 0x84);
}

/*
 * evidence: original narrows second argument before 021B8ED8 call.
 */
int func_021B994C(u8 *p, u32 i, void **out)
{
    void *v;
    u32 n = func_021B8DE4((char *)p, func_021B8ED8(p, i));
    v = *(void **)(p + n * 4 + 0x3e0);
    if (v != 0) {
        *out = v;
        return 1;
    }
    return 0;
}

int func_021B997C(u8 *p, unsigned int i)
{
    if (func_021B9114((u8 **)p) == 0) {
        unsigned int q = (unsigned int)p + 0x3e0;
        if (*(void **)(q + i * 4) != 0 && func_02007B50(*(void **)(q + i * 4)) != 0)
            return func_02007C70(*(void **)(q + i * 4));
        return 0;
    }
    return *(u8 *)((unsigned int)*(u8 * *)&((struct Obj13279 *)p)->f0 + i + 0x44);
}


int func_021B99B8(void *pp, unsigned int b)
{
    return func_021B6994(pp, b);
}

/*
 * evidence: entry r1 is forwarded unchanged to the two-argument 021B6994.
 */
int func_021B99C0(struct S **p, u32 b)
{
    int result = func_021B6994(p, b);
    if (func_021B8588((void **)p) == 3) result = (u8)(result + 2);
    return result;
}


struct Unk021EFD70 *func_021B99E0(int i)
{
    return &data_021EFD70[i];
}


u32 func_021B99F0(u32 x) { return (x == 2 || x == 3) ? 1 : 0; }
