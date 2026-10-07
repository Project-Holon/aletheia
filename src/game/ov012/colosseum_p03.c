/*
 * file:     colosseum_p03.c
 * unit:     yes
 * function: func_02174DC8, func_02174DF0
 * address:  0x02174DC8
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
 *   func_02082D44 0x02082D44 arm
 *   func_020399A8 0x020399A8 arm
 *   func_0203D3A8 0x0203D3A8 arm
 */
#include "../../matched/include/Obj19289.h"
#include "../../matched/include/Obj19291.h"

struct Entry;
typedef unsigned char u8;

typedef unsigned int u32;

typedef unsigned short u16;

extern void func_02082D44(void *,void *,u32);
extern struct Entry *func_020399A8(void);
extern int func_0203D3A8(struct Entry *a, u32 b, u32 c, u32 d);
void func_02174DC8(int unused, u32 n, void *src, u8 *ctx);
int func_02174DF0(u32 v);
void func_02174E08(int index,int unused1,int unused2,u8 *ctx);

void func_02174DC8(int unused, u32 n, void *src, u8 *ctx)
{
    u8 *p = *(u8 * *)&((struct Obj19289 *)ctx)->f355C;
    if (p) {
        func_02082D44(src,p+0x15c,n);
        p[0x160] = 1;
    }
}

/*
 * Caller consumes 020399A8's live r0 despite its filed void return.
 */
int func_02174DF0(u32 v) { return func_0203D3A8(func_020399A8(),0x1507,4,v); }

void func_02174E08(int index,int unused1,int unused2,u8 *ctx)
{
    u8 *p = *(u8 * *)&((struct Obj19291 *)ctx)->f355C;
    if (p) (p+index)[0xd4] = 1;
}
