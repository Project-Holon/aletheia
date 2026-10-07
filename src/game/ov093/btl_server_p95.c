/*
 * file:     btl_server_p95.c
 * unit:     yes
 * function: func_021C846C, func_021C8494
 * address:  0x021C846C
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
 *   func_021B9934 0x021B9934 thumb ov093
 *   func_021BFEAC 0x021BFEAC thumb ov093
 *   func_021BFF60   0x021BFF60  thumb  ov093
 */
#include "../../matched/include/Obj00003.h"

typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

typedef struct { u32 f0; u8 pad[60]; } E64;

extern u8 *func_021B9934(char *p, int i);
extern int func_021BFEAC(u8 *, u8 *, u8 *, int *);
extern void func_021BFF60(u8 *p, u8 *a, int z);
int func_021C846C(u8 *p, int a, int b, int *out);
void func_021C8494(u8 *p, int i);

/*
 * extent: Two bytes of alignment padding follow the 38-byte function.
 */
int func_021C846C(u8 *p, int a, int b, int *out)
{
    u8 *x = func_021B9934(*(char * *)&((struct Obj00003 *)p)->f8, a);
    u8 *y = func_021B9934(*(char * *)&((struct Obj00003 *)p)->f8, b);
    return func_021BFEAC(p, x, y, out);
}


/*
 * Wrapper family member; the body is the hand-checked shape of the family's first instance with only the member's constants substituted, per the family uniformity assertion in o36/report.md.
 */
void func_021C8494(u8 *p, int i) { func_021BFF60(p, func_021B9934(*(char * *)&((struct Obj00003 *)p)->f8, i), 1); }
