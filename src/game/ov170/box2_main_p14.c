/*
 * file:     box2_main_p14.c
 * unit:     yes
 * function: func_021DF378, func_021DF38C
 * address:  0x021DF378
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_020307B0  0x020307B0  arm  arm9
 *   func_02012EBC 0x02012EBC thumb
 *   func_0200C0F0 0x0200C0F0 thumb
 *   func_02030734 0x02030734 arm
 *   func_020457B0 0x020457B0 arm
 *   func_0200785C 0x0200785C thumb
 *   func_0216BFD4 0x0216BFD4 thumb ov010
 *   func_02031348 0x02031348 arm
 *   d_021F1400 0x021F1400 data a1
 *   d_021F5580 0x021F5580 data a4 ov194
 *   ov194_id 0x000000C2 data a1
 */
#include "../../matched/include/Obj12156.h"
#include "../../matched/include/Obj18460.h"
#include "../../matched/include/Obj10650.h"

struct Big;
struct U16Vec;
typedef unsigned int   u32;

typedef struct { void *task; void *text; } Request;

typedef unsigned short u16;

extern u32 func_020307B0(void *p);
extern void *func_02012EBC(struct Big *p);
extern void *func_0200C0F0(void *sys);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void func_0200785C(void *save, unsigned box, void *dest);
extern int *func_0216BFD4(unsigned short a0, int a1, short a2, short a3, int s0, int s1, int s2);
extern void func_02031348(void *p, int a, const void *b, void *c);
int func_021DF378(char *p);
int func_021DF38C(char *p);
extern const char d_021F1400[];
extern const unsigned d_021F5580[];
extern const char ov194_id[];


/*
 * Mirror a word into a halfword field, forward, return 0.
 */
int func_021DF378(char *p)
{
    char *q = *(char * *)&((struct Obj12156 *)p)->fC;

    ((struct Obj12156 *)p)->f10 = ((struct Obj18460 *)q)->f38;
    func_020307B0(q);
    return 0;
}

/*
 * data: callback descriptor belongs to ov194 loaded by func_02031348.
 */
int func_021DF38C(char *p)
{
    int value;
    Request *r;
    value = (int)func_0200C0F0(func_02012EBC((*(void ***)p)[0]));
    r = func_02030734(0x4B, 8, 1, d_021F1400, 0xF1F);
    r->text = func_020457B0(20, 0x4B);
    func_0200785C((*(void ***)p)[1], ((struct Obj10650 *)p)->f14, r->text);
    r->task = func_0216BFD4(0x4B, 2, 0, 0, 8, (int)r->text, value);
    func_02031348(((struct Obj10650 *)p)->f4, (int)ov194_id, d_021F5580, r->task);
    *(Request * *)&((struct Obj10650 *)p)->fC = r;
    return 0;
}
