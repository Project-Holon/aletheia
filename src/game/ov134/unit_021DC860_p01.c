/*
 * file:     unit_021DC860_p01.c
 * unit:     yes
 * function: func_021DC860, func_021DC86C, func_021DC888
 * address:  0x021DC860
 * region:   ov134
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_020399A8 0x020399A8 arm
 *   func_0203D1A4 0x0203D1A4 arm
 *   func_0203159C 0x0203159C arm
 *   func_02082BCC 0x02082BCC arm
 *   func_02031324 0x02031324 arm
 *   func_0203A574 0x0203A574 arm
 *   func_021DCB48 0x021DCB48 thumb ov134
 *   func_021DCC48 0x021DCC48 thumb ov134
 *   tbl_021DCC9C 0x021DCC9C data a4
 *   g_02FFFC3C 0x02FFFC3C data a4
 */
#include "../../matched/include/Obj05411.h"

struct Entry;
struct Link;
struct Obj0203159C;
typedef struct {
    char pad0[0xF0];
    int tbl[1];
} Tbl;

typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct { u32 w[11]; } Args;

extern struct Entry *func_020399A8(void);
extern u32 func_0203D1A4(struct Link *p);
extern void *func_0203159C(struct Obj0203159C *obj, u32 size, u32 heap);
extern void func_02082BCC(void *, int, u32);
extern void *func_02031324(int a0);
extern void func_0203A574(u32 a, u32 b, u32 c, u32 d);
extern void func_021DCB48(const Args *, void *, void *);
extern void func_021DCC48(u8 *p, void *unused, u8 *out);
int func_021DC860(int i, Tbl *p);
void func_021DC86C(u32 value,u32 a,u32 b,u32 c,void *expected);
int func_021DC888(void *ctx, int unused, const Args *args);
extern const u32 tbl_021DCC9C[];
extern u32 g_02FFFC3C;


int func_021DC860(int i, Tbl *p)
{
    return p->tbl[i];
}

/*
 * extent: trailing 2-byte alignment padding; early return keeps the final unused compare.
 */
void func_021DC86C(u32 value,u32 a,u32 b,u32 c,void *expected) { if(expected==func_020399A8()) { if(value!=func_0203D1A4((struct Link *)func_020399A8())) return; } }

int func_021DC888(void *ctx, int unused, const Args *args)
{
    u8 *p;
    p = func_0203159C(ctx, 0x100, 4);
    func_02082BCC(p, 0, 0x100);
    *(Args *)(p + 0xd0) = *args;
    ((struct Obj05411 *)p)->fFC = 4;
    ((struct Obj05411 *)p)->fCC = func_02031324(((struct Obj05411 *)p)->fFC);
    func_0203A574(0x2f00, (u32)tbl_021DCC9C, 1, (u32)p);
    func_021DCB48(args, p, p + 4);
    func_021DCC48((u8 *)args, p, p + 0x9c);
    p[0xc4] = 0;
    ((struct Obj05411 *)p)->fC8 = g_02FFFC3C;
    ((struct Obj05411 *)p)->f0 = 0;
    return 1;
}
