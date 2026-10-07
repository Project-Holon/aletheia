/*
 * file:     pms_input_view_p11.c
 * unit:     yes
 * function: func_021BB1C0, func_021BB1CC, func_021BB1E4, func_021BB1F4, func_021BB1F8, func_021BB214
 * address:  0x021BB1C0
 * region:   ov110
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021B9A3C 0x021B9A3C thumb ov110
 *   func_02045994 0x02045994 arm
 *   d_021C37A8 0x021C37A8 data a2
 */
#include "../../matched/include/Obj22355.h"
#include "../../matched/include/Obj22356.h"

struct Strbuf;
typedef unsigned char u8;

typedef unsigned short u16;

typedef short s16;

typedef signed char s8;

typedef unsigned int u32;

typedef int s32;

extern int func_021B9A3C(u8 *,u16,int);
extern void func_02045994(struct Strbuf *o, const u16 *src, u32 len);
u8 func_021BB1C0(u8 *p);
int func_021BB1CC(u8 *p, u8 i, int c);
u16 func_021BB1E4(u32 p,u32 i);
int func_021BB1F4(void);
void func_021BB1F8(u32 i, void *dst);
u16 func_021BB214(u32 i);
extern const u8 d_021C37A8[];


u8 func_021BB1C0(u8 *p) { return ((struct Obj22355 *)p)->fAF1; }

int func_021BB1CC(u8 *p, u8 i, int c) { return func_021B9A3C(*(u8 * *)&((struct Obj22356 *)p)->f4,*(u16 *)(p+i*2+0x8bc),c); }

u16 func_021BB1E4(u32 p,u32 i) { return *(u16 *)(p+i*2+0x8bc); }


int func_021BB1F4(void) { return 0x1b; }

void func_021BB1F8(u32 i, void *dst)
{
    func_02045994(dst, (const u16 *)(d_021C37A8 + i * 10), 2);
}

u16 func_021BB214(u32 i) { return *(const u16 *)(d_021C37A8+i*10); }
