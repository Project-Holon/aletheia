/*
 * file:     script_command_p07.c
 * unit:     yes
 * function: func_021FBD78, func_021FBDCC, func_021FBE00, func_021FBE38
 * address:  0x021FBD78
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
 *   func_021F9DAC 0x021F9DAC thumb ov132
 *   func_021F6B18 0x021F6B18 thumb ov112
 *   func_021F9DB8 0x021F9DB8 thumb ov132
 *   func_021F9DB0 0x021F9DB0 thumb ov132
 *   func_021F6B80 0x021F6B80 thumb ov112
 *   func_021F6BC0 0x021F6BC0 thumb ov112
 */
#include "../../matched/include/Obj03290.h"
#include "../../matched/include/Obj10555.h"
#include "../../matched/include/Obj14112.h"
#include "../../matched/include/Obj10556.h"
#include "../../matched/include/Obj14113.h"
#include "../../matched/include/Obj14114.h"
#include "../../matched/include/Obj14115.h"

struct Cursor;
struct Object;
struct Entry;
typedef unsigned char u8;

typedef unsigned int   u32;

extern u32 func_0201134C(struct Cursor *p);
extern void *func_021F9DAC(void *p);
extern struct Entry *func_021F6B18(struct Object *,unsigned short);
extern void func_021F9DB8(void *p, void *v, u32 i);
extern unsigned int *func_021F9DB0(void *,unsigned char);
extern void func_021F6B80(unsigned int *,unsigned int *);
extern void func_021F6BC0(char *,unsigned int *,unsigned int);
int func_021FBD78(int unused, char *p);
int func_021FBDCC(int unused,char *p);
int func_021FBE00(int unused,char *p);
int func_021FBE38(int unused,char *p);

/*
 * note: inferred extent ends with two zero padding bytes before the next labelled function.
 */
int func_021FBD78(int unused, char *p)
{
    int a, b, c, d;
    a = func_0201134C(((struct Obj03290 *)p)->f4);
    b = func_0201134C(((struct Obj03290 *)p)->f4);
    c = func_0201134C(((struct Obj03290 *)p)->f4);
    d = func_0201134C(((struct Obj03290 *)p)->f4);
    ((struct Obj03290 *)p)->f18 = 0;
    if (a == 1) ((struct Obj03290 *)p)->f18 += 1;
    if (b == 1) ((struct Obj03290 *)p)->f18 += 2;
    if (c == 1) ((struct Obj03290 *)p)->f18 += 4;
    if (d == 1) ((struct Obj03290 *)p)->f18 += 8;
    return 0;
}

/*
 * prototype: 021F6B18's own source reads r0 only; this caller additionally
 * supplies r1 as a narrowed halfword, retained as an unused second input.
 */
int func_021FBDCC(int unused,char *p) { char *obj; unsigned int a,b; struct Entry *entry;obj=*(char * *)&((struct Obj10555 *)p)->f0;a=func_0201134C(*(struct Cursor * *)&((struct Obj10555 *)p)->f4);b=func_0201134C(*(struct Cursor * *)&((struct Obj10555 *)p)->f4);entry=func_021F6B18(func_021F9DAC(((struct Obj14112 *)obj)->f34),b);func_021F9DB8(((struct Obj14112 *)obj)->f34,entry,(unsigned char)a);return 0; }

/*
 * extent: Two bytes of zero alignment padding follow the 54-byte body.
 */
int func_021FBE00(int unused,char *p) { char *obj; unsigned int n; void *ctx; obj=*(char * *)&((struct Obj14113 *)p)->f0;n=func_0201134C(*(struct Cursor * *)&((struct Obj14113 *)p)->f4);ctx=func_021F9DAC(((struct Obj10556 *)obj)->f34);func_021F6B80(ctx,func_021F9DB0(((struct Obj10556 *)obj)->f34,n));func_021F9DB8(((struct Obj10556 *)obj)->f34,0,(unsigned char)n);return 0; }

int func_021FBE38(int unused,char *p) { char *obj; unsigned int n; void *ctx; obj=*(char * *)&((struct Obj14114 *)p)->f0;n=func_0201134C(*(struct Cursor * *)&((struct Obj14114 *)p)->f4);ctx=func_021F9DAC(((struct Obj14115 *)obj)->f34);func_021F6BC0(ctx,func_021F9DB0(((struct Obj14115 *)obj)->f34,n),1);return 0; }
