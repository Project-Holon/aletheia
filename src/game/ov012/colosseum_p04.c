/*
 * file:     colosseum_p04.c
 * unit:     yes
 * function: func_02174E64, func_02174E9C
 * address:  0x02174E64
 * region:   ov012
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
 *   func_0203D3F8 0x0203D3F8 arm
 */
#include "../../matched/include/Obj19292.h"
#include "../../matched/include/Obj19294.h"

struct Entry;
typedef unsigned char u8;

typedef unsigned int u32;

extern struct Entry *func_020399A8(void);
extern u32 func_0203D3F8(u32,u32,u32,u32,u32,u32,u32,u32);
u32 func_02174E64(void);
void func_02174E88(int unused0,int unused1,int unused2,u8 *ctx);
u32 func_02174E9C(int v);
void func_02174EC4(int unused0,int unused1,int unused2,u8 *ctx);

/*
 * Caller consumes 020399A8's live r0 despite its filed void return.
 */
u32 func_02174E64(void) { return func_0203D3F8((u32)func_020399A8(),0,0x1509,0,0,1,0,0); }

void func_02174E88(int unused0,int unused1,int unused2,u8 *ctx)
{
    u8 *p = *(u8 * *)&((struct Obj19292 *)ctx)->f355C;
    if (p) p[0xdf] = 0;
}

u32 func_02174E9C(int v) { return func_0203D3F8((u32)func_020399A8(),(u8)v,0x150a,0,0,1,0,0); }

void func_02174EC4(int unused0,int unused1,int unused2,u8 *ctx)
{
    u8 *p = *(u8 * *)&((struct Obj19294 *)ctx)->f355C;
    if (p) p[0xcb] = 1;
}
