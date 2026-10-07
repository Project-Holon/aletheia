/*
 * file:     unit_021B7518_p05.c
 * unit:     yes
 * function: func_021B85DC, func_021B85EC, func_021B8630, func_021B8640, func_021B8670, func_021B86A0, func_021B86B8, func_021B86C0, func_021B86C8
 * address:  0x021B85DC
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
 *   func_02013080 0x02013080 thumb
 *   ov231_id       0x000000E7  data
 *   func_02034AC4  0x02034AC4  arm
 *   func_02034A5C  0x02034A5C  arm
 *   func_021809D8  0x021809D8  thumb  ov231
 *   func_021BA1A8  0x021BA1A8  thumb  ov093
 */
#include "../../matched/include/Obj20952.h"
#include "../../matched/include/Obj12104.h"
#include "../../matched/include/Obj18127.h"

typedef unsigned int   u32;

typedef unsigned char u8;

typedef unsigned short u16;

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

extern signed char func_02013080(u32 idx);
extern int func_02034AC4(int id);
extern void func_02034A5C(int id);
extern int func_021809D8(void);
extern int func_021BA1A8(char **p, int m);
int func_021B85DC(unsigned char *p);
int func_021B85EC(u32 **p);
/* 021B8630 first round: `if (*q > 1) return 0;` came back bls. The image * takes the guard, so the guarded read is the fall-through arm. */ u32 func_021B8630(u32 **p);
unsigned int func_021B8640(unsigned int **p);
unsigned int func_021B8670(unsigned int **p);
int func_021B86A0(unsigned int **p, unsigned int i);
void *func_021B86B8(void ***p);
/* 021B86C0 ldr r0,[r0]; adds r0,#0x20; ldrb r0,[r0] */ u8 func_021B86C0(u8 **p);
int func_021B86C8(unsigned char **p);
extern u8 ov231_id[];

int func_021B85DC(unsigned char *p) { return func_02013080(((struct Obj20952 *)p)->f43C); }


int func_021B85EC(u32 **p)
{
    int r;
    if (**p <= 1) {
        func_02034AC4((int)ov231_id);
        r = func_021809D8();
        func_02034A5C((int)ov231_id);
        if (r == 0) {
            return 0;
        }
        if (func_021BA1A8((char **)p, 0x200) == 0) {
            return 1;
        }
    }
    return 0;
}


/* 021B8630  first round: `if (*q > 1) return 0;` came back bls.  The image
 * takes the guard, so the guarded read is the fall-through arm. */
/*
 * Leaf with no calls and no pool; 8 instructions, 16 bytes: ldr r1, [r0]; ldr r0, [r1]; cmp r0, #1; bhi loc_021B863C; ldr r0, [r1, #0x70]; bx lr; movs r0, #0; bx lr.
 */
u32 func_021B8630(u32 **p)
{
    u32 *q = *p;
    if (*q <= 1)
        return ((struct Obj12104 *)q)->f70;
    return 0;
}

unsigned int func_021B8640(unsigned int **p) { switch ((*p)[1]) { case 0:return 1; case 1:return 3; case 2:return 5; case 3:return 5; default:return 5; } }

unsigned int func_021B8670(unsigned int **p) { switch ((*p)[1]) { case 0:return 1; case 1:return 2; case 2:return 3; case 3:return 1; default:return 1; } }

int func_021B86A0(unsigned int **p, unsigned int i) { if (i < func_021B8670(p)*2) return 1; return 0; }

void *func_021B86B8(void ***p)
{
    return **p;
}


/* 021B86C0  ldr r0,[r0]; adds r0,#0x20; ldrb r0,[r0] */
/*
 * Leaf with no calls and no pool; 4 instructions, 8 bytes: ldr r0, [r0]; adds r0, #0x20; ldrb r0, [r0]; bx lr.
 */
u8 func_021B86C0(u8 **p) { return ((struct Obj18127 *)(*p))->f20; }

/*
 * extent: final two zero bytes are alignment padding before the next labelled function.
 */
int func_021B86C8(unsigned char **p) { if ((*p)[0x22]) return 1; return 0; }
