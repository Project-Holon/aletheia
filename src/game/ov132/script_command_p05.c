/*
 * file:     script_command_p05.c
 * unit:     yes
 * function: func_021FB5EC, func_021FB640, func_021FB698, func_021FB6F0, func_021FB738, func_021FB774, func_021FB7A4, func_021FB7D8
 * address:  0x021FB5EC
 * region:   ov132
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0201134C 0x0201134C thumb
 *   func_021FB1F4 0x021FB1F4 thumb ov132
 *   func_021F9DA0 0x021F9DA0 thumb ov132
 *   func_021F9DA4 0x021F9DA4 thumb ov132
 *   func_021F80C8 0x021F80C8 thumb ov112
 *   func_021F8140 0x021F8140 thumb ov112
 *   func_021F8154 0x021F8154 thumb ov112
 *   func_021F9D18 0x021F9D18 thumb ov132
 *   func_021F95CC 0x021F95CC thumb ov132
 *   func_021F9140 0x021F9140 thumb ov132
 *   func_021F9AD8 0x021F9AD8 thumb ov132
 *   func_021F91A8 0x021F91A8 thumb ov132
 */
#include "../../matched/include/Obj10550.h"
#include "../../matched/include/Obj14107.h"
#include "../../matched/include/Obj10551.h"
#include "../../matched/include/Obj14108.h"
#include "../../matched/include/Obj10552.h"
#include "../../matched/include/Obj14109.h"
#include "../../matched/include/Obj14110.h"
#include "../../matched/include/Obj23255.h"
#include "../../matched/include/Obj08164.h"
#include "../../matched/include/Obj23256.h"
#include "../../matched/include/Obj10553.h"
#include "../../matched/include/Obj14111.h"
#include "../../matched/include/Obj10554.h"
#include "../../matched/include/Obj23257.h"

struct Cursor;
typedef unsigned char u8;

typedef unsigned int u32;

extern u32 func_0201134C(struct Cursor *p);
extern int func_021FB1F4(char *, int);
extern void *func_021F9DA0(char *);
extern void *func_021F9DA4(char *, u32);
extern void func_021F80C8(int, void *, u8);
extern void func_021F8140(int a, u8 *p, int b);
extern int func_021F8154(int a0, int *a1, int a2);
extern void func_021F9D18(char *p, unsigned i);
extern void func_021F95CC(char *,unsigned char,int);
extern void func_021F9140(unsigned char *,unsigned char,unsigned char);
extern void func_021F9AD8(char *,int,unsigned char);
extern void func_021F91A8(char *p, u8 n, u8 mask);
int func_021FB5EC(int unused, char *p);
int func_021FB640(int unused, char *p);
int func_021FB698(int unused, char *p);
int func_021FB6F0(int unused, char *p);
int func_021FB738(int unused,char *p);
int func_021FB774(int unused,char *p);
int func_021FB7A4(int unused,char *p);
int func_021FB7D8(int unused,char *p);

/*
 * note: func_021F80C8 is called with a u8 third parameter (its matched unit declares unsigned int; the narrowing is loop-invariant and hoisted).
 * note: older draft in docs/notes/pkt_ov132_021FB5EC.c.txt (DIFF6) is superseded.
 */
int func_021FB5EC(int unused, char *p)
{
    char *obj;
    int mask;
    int value;
    char *ctx;
    u8 i;
    obj = *(char **)p;
    mask = func_021FB1F4(p, func_0201134C(*(void **)(p + 4)));
    value = func_0201134C(*(void **)(p + 4));
    ctx = func_021F9DA0(*(char **)(obj + 0x34));
    for (i = 0; i < 4; i++) {
        if ((1 << i) & mask) {
            func_021F80C8((int)ctx, func_021F9DA4(*(char **)(obj + 0x34), i), value);
        }
    }
    return 0;
}

/*
 * note: inferred extent ends with two zero padding bytes before the next labelled function.
 */
int func_021FB640(int unused, char *p)
{
    char *obj;
    int mask;
    int value;
    char *ctx;
    u8 i;
    obj = *(char * *)&((struct Obj10550 *)p)->f0;
    mask = func_021FB1F4(p, func_0201134C(((struct Obj10550 *)p)->f4));
    value = func_0201134C(((struct Obj10550 *)p)->f4);
    ctx = func_021F9DA0(((struct Obj14107 *)obj)->f34);
    for (i = 0; i < 4; i++) {
        if ((1 << i) & mask) {
            func_021F8140((int)ctx, func_021F9DA4(((struct Obj14107 *)obj)->f34, i), value != 0);
        }
    }
    return 0;
}

int func_021FB698(int unused, char *p)
{
    char *obj;
    int mask;
    int value;
    char *ctx;
    u8 i;
    obj = *(char * *)&((struct Obj10551 *)p)->f0;
    mask = func_021FB1F4(p, func_0201134C(((struct Obj10551 *)p)->f4));
    value = func_0201134C(((struct Obj10551 *)p)->f4);
    ctx = func_021F9DA0(((struct Obj14108 *)obj)->f34);
    for (i = 0; i < 4; i++) {
        if ((1 << i) & mask) {
            func_021F8154((int)ctx, func_021F9DA4(((struct Obj14108 *)obj)->f34, i), value != 0);
        }
    }
    return 0;
}

int func_021FB6F0(int unused, char *p)
{
    char *obj;
    int mask;
    char *ctx;
    u8 i;
    obj = *(char * *)&((struct Obj14109 *)p)->f0;
    mask = func_021FB1F4(p, func_0201134C(((struct Obj14109 *)p)->f4));
    ctx = func_021F9DA0(((struct Obj10552 *)obj)->f34);
    for (i = 0; i < 4; i++) {
        if ((1 << i) & mask) {
            func_021F9DA4(((struct Obj10552 *)obj)->f34, i);
            func_021F9D18(((struct Obj10552 *)obj)->f34, i);
        }
    }
    return 0;
}

/*
 * extent: Two bytes of zero alignment padding follow the 58-byte body.
 */
int func_021FB738(int unused,char *p) { char *obj; int mask; unsigned char i; obj=*(char * *)&((struct Obj14110 *)p)->f0; mask=func_021FB1F4(p,func_0201134C(*(struct Cursor * *)&((struct Obj14110 *)p)->f4)); for(i=0;i<4;i++)if((1<<i)&mask)func_021F95CC(*(char * *)&((struct Obj23255 *)obj)->f34,i,1); return 0; }

int func_021FB774(int unused,char *p) { char *obj; obj=*(char * *)&((struct Obj23256 *)p)->f0; func_021F95CC(*(char * *)&((struct Obj08164 *)obj)->f34,0,0);func_021F95CC(*(char * *)&((struct Obj08164 *)obj)->f34,1,0);func_021F95CC(*(char * *)&((struct Obj08164 *)obj)->f34,2,0);func_021F95CC(*(char * *)&((struct Obj08164 *)obj)->f34,3,0);return 0; }

/*
 * prototype: Original caller narrows both 021F9140 arguments to bytes,
 * overriding its own source's wider parameters; 021F9AD8 index is byte too.
 */
int func_021FB7A4(int unused,char *p) { char *obj; unsigned int index,n; obj=*(char * *)&((struct Obj10553 *)p)->f0;index=func_0201134C(*(struct Cursor * *)&((struct Obj10553 *)p)->f4);n=func_0201134C(*(struct Cursor * *)&((struct Obj10553 *)p)->f4);func_021F9140(*(unsigned char * *)&((struct Obj14111 *)obj)->f34,n,index);func_021F9AD8(*(char * *)&((struct Obj14111 *)obj)->f34,1,index);return 0; }

int func_021FB7D8(int unused,char *p) { char *obj; int mask; unsigned int n; obj=*(char * *)&((struct Obj10554 *)p)->f0;mask=func_021FB1F4(p,func_0201134C(*(struct Cursor * *)&((struct Obj10554 *)p)->f4));n=func_0201134C(*(struct Cursor * *)&((struct Obj10554 *)p)->f4);func_021F91A8((char *)(*(unsigned char * *)&((struct Obj23257 *)obj)->f34),n,mask);return 0; }
