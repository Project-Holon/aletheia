/*
 * file:     btl_server_p90.c
 * unit:     yes
 * function: func_021C8234, func_021C824C, func_021C8288, func_021C8290
 * address:  0x021C8234
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
 *   func_021C6F0C   0x021C6F0C  thumb  ov093
 *   func_021B9934   0x021B9934  thumb  ov093
 *   func_021D59B4 0x021D59B4 thumb ov093
 *   func_021D62C4 0x021D62C4 thumb ov093
 *   func_021EF948 0x021EF948 thumb ov093
 *   func_021C2AB0   0x021C2AB0  thumb ov093
 *   func_021BFA00 0x021BFA00 thumb ov093
 */
#include "../../matched/include/Obj00003.h"
#include "../../matched/include/Obj21115.h"

struct Unk021D62A8;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

typedef struct { u32 f0; u8 pad[60]; } E64;

extern u8 *func_021B9934(char *p, int i);
extern int func_021C6F0C(u8 *p, u8 *a, int k);
extern int func_021D59B4(u8 *p, int k);
extern int func_021D62C4(struct Unk021D62A8 *p, int i);
extern int func_021EF948(int);
extern int func_021C2AB0(u8 *p);
extern int func_021BFA00(u8 *, u8 *, u8 *, void *);
int func_021C8234(u8 *p, int i);
int func_021C824C(u8 *p, int v);
int func_021C8288(u8 *p);
int func_021C8290(u8 *p, int a, int b, void *item);


/*
 * Wrapper family member; the body is the hand-checked shape of the family's first instance with only the member's constants substituted, per the family uniformity assertion in o36/report.md.
 */
int func_021C8234(u8 *p, int i) { return func_021C6F0C(p, func_021B9934(*(char * *)&((struct Obj00003 *)p)->f8, i), 1); }

/*
 * extent: two bytes alignment padding follow.
 */
int func_021C824C(u8 *p, int v) { void *m; m=func_021B9934(*(char * *)&((struct Obj21115 *)p)->f8,v); if(func_021D59B4(m,17)==103) return 0; if(func_021D62C4(m,19)) return 0; if(func_021EF948(7)==0) return 1; return 0; }


/*
 * tail-call thunk to func_021C2AB0
 */
int func_021C8288(u8 *p)
{
    return func_021C2AB0(p);
}

int func_021C8290(u8 *p, int a, int b, void *item) { u8 *x; x=func_021B9934(*(char * *)&((struct Obj00003 *)p)->f8,a); return func_021BFA00(p,x,func_021B9934(*(char * *)&((struct Obj00003 *)p)->f8,b),item); }
