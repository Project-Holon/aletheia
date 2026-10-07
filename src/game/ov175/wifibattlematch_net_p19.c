/*
 * file:     wifibattlematch_net_p19.c
 * unit:     yes
 * function: func_021DAFB8, func_021DB160, func_021DB218, func_021DB228, func_021DB238, func_021DB248, func_021DB258, func_021DB294, func_021DB2D4, func_021DB300, func_021DB328, func_021DB350
 * address:  0x021DAFB8
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021DF420 0x021DF420 arm ov175
 *   func_021DF3E8 0x021DF3E8 arm ov175
 *   func_02034714 0x02034714 arm
 *   d_021E2EF8 0x021E2EF8 data a4
 *   DWC_ScReportAddByteValue  0x021DF3E8  arm
 *   func_020399A8 0x020399A8 arm
 *   func_0203D1A4 0x0203D1A4 arm
 *   func_02082D44 0x02082D44 arm
 *   func_02012950 0x02012950 thumb
 *   func_02008468 0x02008468 thumb
 *   g_021E2EF8  0x021E2EF8  data
 */
#include "../../matched/include/Obj14338.h"
#include "../../matched/include/Obj14339.h"
#include "../../matched/include/Obj24337.h"
#include "../../matched/include/Obj24338.h"
#include "../../matched/include/Obj24339.h"

struct Entry;
struct Link;
struct Rec44;
struct Sub24;
typedef unsigned int u32_021DAFB8;

typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned long u32_021DB218;

typedef signed char s8;

typedef unsigned long u32_021DB228;

typedef unsigned long u32_021DB238;

typedef unsigned long u32_021DB248;

typedef unsigned int u32_021DB258;

typedef unsigned int   u32_021DB294;

typedef unsigned long u32_021DB2D4;

typedef unsigned long u32_021DB300;

typedef unsigned long u32_021DB328;

typedef unsigned long u32_021DB350;

extern int func_021DF420(int,int,int);
extern int func_021DF3E8(int,int,int);
extern void func_02034714(const char *expr, u32_021DAFB8 line, const char *file);
extern int DWC_ScReportAddByteValue(u32_021DB218 report, u16 keyId, s8 value);
extern struct Entry *func_020399A8(void);
extern u32_021DB258 func_0203D1A4(struct Link *p);
extern void func_02082D44(const void *,void *,int);
extern struct Rec44 *func_02012950(struct Sub24 *p, u32_021DB294 i);
extern int func_02008468(void);
void func_021DAFB8(int *ctx,const u32_021DAFB8 *record,int invert);
void func_021DB160(int *ctx, int *input, int invert);
int func_021DB218(u32_021DB218 *ctx);
int func_021DB228(u32_021DB228 *ctx);
int func_021DB238(u32_021DB238 *ctx);
int func_021DB248(u32_021DB248 *ctx);
void func_021DB258(int index,int unused,const void *src,u8 *p,int owner);
void func_021DB294(int index, int unused, void *dest, char *ctx, int owner);
int func_021DB2D4(int a, char *b);
void func_021DB300(u32_021DB300 a, u32_021DB300 b, u32_021DB300 c, char *d, u32_021DB300 e);
void func_021DB328(u32_021DB328 a, u32_021DB328 b, u32_021DB328 c, char *d, u32_021DB328 e);
void func_021DB350(u32_021DB350 a, u32_021DB350 b, u32_021DB350 c, char *d, u32_021DB350 e);
extern const char d_021E2EF8[];
extern u32_021DB2D4 g_021E2EF8[];

void func_021DAFB8(int *ctx,const u32_021DAFB8 *record,int invert) {
    int first,second,flip=0,skip=0,present;
    present=record[2]!=0 || record[3]!=0;
    switch(record[1]) {
    case 0: case 3: first=0; second=1; flip=1; break;
    case 1: case 4: first=1; second=0; flip=1; break;
    case 2: first=0; second=0; skip=1; break;
    case 5: case 6: default: first=0; second=0; break;
    }
    if(!invert && flip) { first^=1; second^=1; }
    switch(record[0]) {
    case 0:
        if(!skip && func_021DF420(ctx[1],15,1)) return;
        if(func_021DF3E8(ctx[1],5,first)) return;
        if(func_021DF3E8(ctx[1],6,second)) return;
        break;
    case 1:
        if(!skip && func_021DF420(ctx[1],16,1)) return;
        if(func_021DF3E8(ctx[1],8,first)) return;
        if(func_021DF3E8(ctx[1],7,second)) return;
        break;
    case 2:
        if(!skip && func_021DF420(ctx[1],18,1)) return;
        if(func_021DF3E8(ctx[1],11,first)) return;
        if(func_021DF3E8(ctx[1],12,second)) return;
        break;
    case 3:
        if(!skip && func_021DF420(ctx[1],17,1)) return;
        if(func_021DF3E8(ctx[1],9,first)) return;
        if(func_021DF3E8(ctx[1],10,second)) return;
        break;
    case 4:
        if(!skip && func_021DF420(ctx[1],19,1)) return;
        if(func_021DF3E8(ctx[1],13,first)) return;
        if(func_021DF3E8(ctx[1],14,second)) return;
        break;
    default: func_02034714(d_021E2EF8,0,d_021E2EF8); break;
    }
    if(func_021DF3E8(ctx[1],20,present!=0)) return;
    func_021DF3E8(ctx[1],27,-1);
}

/*
 * tail: 021DB216..021DB218 is two zero alignment bytes.
 */
void func_021DB160(int *ctx, int *input, int invert)
{
    int flip = 0, skip = 0;
    int first, second;
    int present = 1;
    if (input[2] == 0 && input[3] == 0) present = 0;
    switch (input[1]) {
    case 0: case 3: first = 0; second = 1; flip = 1; break;
    case 1: case 4: first = 1; second = 0; flip = 1; break;
    case 2: first = 0; second = 0; skip = 1; break;
    case 5: case 6: default: first = 0; second = 0; break;
    }
    if (!invert && flip) { first ^= 1; second ^= 1; }
    if (!skip && func_021DF420(ctx[1], 0x15, 1)) return;
    if (func_021DF3E8(ctx[1], 0x16, first)) return;
    if (func_021DF3E8(ctx[1], 0x17, second)) return;
    if (func_021DF3E8(ctx[1], 0x18, present != 0)) return;
    func_021DF3E8(ctx[1], 0x1c, -1);
}


/*
 * Report callback: adds byte key 0x1a with value 1 to the report at +0x4.
 */
int func_021DB218(u32_021DB218 *ctx)
{
    return DWC_ScReportAddByteValue(ctx[1], 0x1a, 1);
}


/*
 * Report callback: adds byte key 0x19 with value 1 to the report at +0x4.
 */
int func_021DB228(u32_021DB228 *ctx)
{
    return DWC_ScReportAddByteValue(ctx[1], 0x19, 1);
}


/*
 * Report callback: adds byte key 0x1b with value -1 to the report at +0x4.
 */
int func_021DB238(u32_021DB238 *ctx)
{
    return DWC_ScReportAddByteValue(ctx[1], 0x1b, -1);
}


int func_021DB248(u32_021DB248 *ctx)
{
    return DWC_ScReportAddByteValue(ctx[1], 0x1c, -1);
}

void func_021DB258(int index,int unused,const void *src,u8 *p,int owner) { if(owner==(int)func_020399A8() && index!=func_0203D1A4((struct Link *)((int)func_020399A8()))) { func_02082D44(src,*(u8 * *)&((struct Obj14338 *)p)->f1464+0x6c,0x68); ((struct Obj14338 *)p)->f138=1; } }

void func_021DB294(int index, int unused, void *dest, char *ctx, int owner)
{
    void *record;
    record = func_02012950(((struct Obj14339 *)ctx)->f8, index);
    func_02082D44(dest, record, func_02008468());
    if (owner == (int)func_020399A8()) {
        if (index != func_0203D1A4((struct Link *)((int)func_020399A8())))
            ((struct Obj14339 *)ctx)->f13C = 1;
    }
}

/*
 * Compare the caller's first word with the current 0x0203D1A4 handle of the 0x020399A8 block; a match releases the 0x021E2EF8 pair through 0x02034714, a mismatch yields the +0x218 sub-block.
 */
int func_021DB2D4(int a, char *b)
{
    if (func_0203D1A4((struct Link *)((int)func_020399A8())) == a) {
        func_02034714((const char *)((int)g_021E2EF8), 0, (const char *)((int)g_021E2EF8));
        return 0;
    }
    return (int)(b + 0x218);
}


/*
 * Guarded flag set: only when the caller's fifth argument (on the stack)
 * matches the tick from 0x020399A8 and the first argument does NOT match
 * 0x0203D1A4 does it store 1 in the +0x140 word of the fourth argument.
 */
void func_021DB300(u32_021DB300 a, u32_021DB300 b, u32_021DB300 c, char *d, u32_021DB300 e)
{
    if (e != (u32_021DB300)func_020399A8())
        return;
    if (a == func_0203D1A4((struct Link *)((u32_021DB300)func_020399A8())))
        return;
    ((struct Obj24337 *)d)->f140 = 1;
}


/*
 * Guarded flag set: only when the caller's fifth argument (on the stack)
 * matches the tick from 0x020399A8 and the first argument does NOT match
 * 0x0203D1A4 does it store 1 in the +0x144 word of the fourth argument.
 */
void func_021DB328(u32_021DB328 a, u32_021DB328 b, u32_021DB328 c, char *d, u32_021DB328 e)
{
    if (e != (u32_021DB328)func_020399A8())
        return;
    if (a == func_0203D1A4((struct Link *)((u32_021DB328)func_020399A8())))
        return;
    ((struct Obj24338 *)d)->f144 = 1;
}


/*
 * Guarded flag set: only when the caller's fifth argument (on the stack)
 * matches the entry address from 0x020399A8 and the first argument does NOT match
 * 0x0203D1A4 does it store 1 in the +0x148 word of the fourth argument.
 */
void func_021DB350(u32_021DB350 a, u32_021DB350 b, u32_021DB350 c, char *d, u32_021DB350 e)
{
    if (e != (u32_021DB350)func_020399A8())
        return;
    if (a == func_0203D1A4((struct Link *)((u32_021DB350)func_020399A8())))
        return;
    ((struct Obj24339 *)d)->f148 = 1;
}
