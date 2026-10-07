/*
 * file:     br_btn_p11.c
 * unit:     yes
 * function: func_021FB594, func_021FB5A0, func_021FB5B8, func_021FB5C4, func_021FB5E4
 * address:  0x021FB594
 * region:   ov186
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0204B838 0x0204B838 arm
 *   func_0204B84C  0x0204B84C  arm
 *   func_02025A0C  0x02025A0C  thumb
 *   func_0204B864 0x0204B864 arm
 *   func_0204B6F4 0x0204B6F4 arm
 *   func_02025A54 0x02025A54 thumb
 *   func_02030734 0x02030734 arm
 *   func_02082BCC 0x02082BCC arm
 *   func_021FB644 0x021FB644 thumb ov186
 *   d_022007F0 0x022007F0 data a4
 *   d_02200D28 0x02200D28 data a1
 */
#include "../../matched/include/Obj24826.h"
#include "../../matched/include/Obj24827.h"
#include "../../matched/include/Obj14459.h"

struct Obj;
typedef unsigned int   u32;

typedef unsigned char  u8;

typedef unsigned short u16;

/* Callee's complete leaf reads only r0; legacy r1-r3 are unused, unforwarded. */
extern int func_0204B838(int);
extern void func_0204B84C(int, unsigned int);
extern void func_02025A0C(u8 *g, u32 a);
extern unsigned func_0204B864(unsigned char *);
extern void func_0204B6F4(struct Obj *o, u32 v, u32 flag);
extern void func_02025A54(u8 *g, u32 a);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void func_02082BCC(void *, int, int);
extern void func_021FB644(char *ctx);
int func_021FB594(char *p);
void func_021FB5A0(int *p, int b);
unsigned func_021FB5B8(char *p);
void func_021FB5C4(char *p,int n);
void *func_021FB5E4(int *ctx, int heap);
extern const unsigned short d_022007F0[][6];
extern char d_02200D28[];

int func_021FB594(char *p) { return func_0204B838(((struct Obj24826 *)p)->f0); }


void func_021FB5A0(int *p, int b)
{
    func_0204B84C(p[0], b);
    func_02025A0C((u8 *)p[1], b);
}

unsigned func_021FB5B8(char *p) { return func_0204B864(*(unsigned char * *)&((struct Obj24827 *)p)->f0); }

void func_021FB5C4(char *p,int n) { func_0204B6F4(((struct Obj14459 *)p)->f0,(unsigned char)n,0);func_02025A54(*(unsigned char * *)&((struct Obj14459 *)p)->f4,(unsigned char)(n+1)); }

void *func_021FB5E4(int *ctx, int heap)
{
    int total = 0;
    int i;
    int *result;
    for (i = 0; i < 12; i++) total += d_022007F0[i][0];
    result = func_02030734(heap, total * 24 + 4, 0, d_02200D28, 0x429);
    func_02082BCC(result, 0, total * 24 + 4);
    *result = *ctx;
    func_021FB644((char *)result);
    return result;
}
