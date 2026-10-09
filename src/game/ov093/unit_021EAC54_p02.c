/*
 * file:     unit_021EAC54_p02.c
 * unit:     yes
 * function: func_021EADA4, func_021EADB4, func_021EADC4, func_021EADD4, func_021EADE4, func_021EADF4, func_021EAE04, func_021EAE14, func_021EAE24, func_021EAE34, func_021EAE44, func_021EAE54, func_021EAE64, func_021EAE74
 * address:  0x021EADA4
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
 *   func_021EE264 0x021EE264 thumb ov093
 *   func_021EE2A0 0x021EE2A0 thumb ov093
 *   func_021EE2F8 0x021EE2F8 thumb ov093
 *   func_021EE318 0x021EE318 thumb ov093
 *   func_021EE370 0x021EE370 thumb ov093
 *   func_021EE390 0x021EE390 thumb ov093
 *   func_021EE228   0x021EE228  thumb  ov093
 *   func_021EE25C   0x021EE25C  thumb  ov093
 *   func_021EE23C 0x021EE23C thumb ov093
 *   func_0689B670   0x0689B670  thumb  ov095
 *   func_0689B69C   0x0689B69C  thumb  ov095
 *   func_0689B790   0x0689B790  thumb  ov095
 *   func_021EAE98  0x021EAE98  thumb  ov093
 */
#include "../../matched/include/Obj21571.h"
#include "../../matched/include/Obj21572.h"
#include "../../matched/include/Obj21573.h"
#include "../../matched/include/Obj21574.h"
#include "../../matched/include/Obj21575.h"
#include "../../matched/include/Obj21576.h"
#include "../../matched/include/Obj21577.h"
#include "../../matched/include/Obj21578.h"
#include "../../matched/include/Obj07847.h"

struct T;
struct O;
struct Q;
typedef unsigned char u8;

typedef unsigned int u32;

typedef unsigned short u16;

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

typedef struct { u32 f0; u8 pad[60]; } E64;

extern void func_021EE264(char *, int, struct T *);
extern int func_021EE2A0(struct O *);
extern void func_021EE2F8(struct O *);
extern int func_021EE318(struct O *);
extern void func_021EE370(struct O *);
extern int func_021EE390(struct O *);
extern void func_021EE23C(struct Q *q);
extern int func_021EE25C(void *);
extern void func_021EAE98(void *a, void *b);
void func_021EADA4(u8 *p, int a, struct T *b);
int func_021EADB4(u8 *p);
void func_021EADC4(u8 *p);
int func_021EADD4(u8 *p);
void func_021EADE4(u8 *p);
int func_021EADF4(u8 *p);
void func_021EAE04(u32 *p);
int func_021EAE14(void **p);
void func_021EAE24(u8 *p);
int func_021EAE34(u8 *p);
void func_021EAE44(E64 *p);
void func_021EAE54(E64 *p);
void func_021EAE64(E64 *p);
void func_021EAE74(char *p, u32 a, u32 b);




void func_021EADA4(u8 *p, int a, struct T *b)
{
    func_021EE264(*(char * *)&((struct Obj21571 *)p)->f17C, a, b);
}





int func_021EADB4(u8 *p)
{
    return func_021EE2A0(*(struct O * *)&((struct Obj21572 *)p)->f17C);
}





void func_021EADC4(u8 *p)
{
    func_021EE2F8(*(struct O * *)&((struct Obj21573 *)p)->f17C);
}





int func_021EADD4(u8 *p)
{
    return func_021EE318(*(struct O * *)&((struct Obj21574 *)p)->f17C);
}





void func_021EADE4(u8 *p)
{
    func_021EE370(*(struct O * *)&((struct Obj21575 *)p)->f17C);
}




int func_021EADF4(u8 *p)
{
    return func_021EE390(*(struct O * *)&((struct Obj21576 *)p)->f17C);
}





/*
 * Indexed-dispatch thunk (o18's 23-member shape): the member's whole stream is movs/lsls/ldr/ldr/bx with r0 as the load base; only the scratch register, the index constant and the tail target differ. Tail call T(p[i]) with the index materialised as a scaled immediate.
 */
void func_021EAE04(u32 *p) { func_021EE228(p[0x5f]); }



/*
 * Indexed-dispatch thunk (o18's 23-member shape): the whole stream is movs/lsls/ldr/ldr/bx with r0 as the load base, and one argument means the index temp is r1.  Tail call T(p[0x5f]).  The pool word names a mid-stream entry point that no listing labels, so the site caps at MATCH until the TARGET is filed; func_021EE25C is an EXACT entry in this shard, which the `matched` class accepts as the witness (brief rule 10), and the call site then attests with no change of its own.
 */
int func_021EAE14(void **p) { return func_021EE25C(p[0x5f]); }


void func_021EAE24(u8 *p)
{
    func_021EE23C(((struct Obj21577 *)p)->f17C);
}


int func_021EAE34(u8 *p)
{
    return func_021EE25C(((struct Obj21578 *)p)->f17C);
}




/*
 * Resolved: func_0689B670 was matched (ov095), so the +0x0C ABS32 now
 * attests through the `matched` class and the thunk is byte-exact.
 *
 * Indexed-dispatch thunk, o18's 23-member shape: void func_021EAE44(E64 *p) { func_0689B670(p[0x6].f0); }
 */
void func_021EAE44(E64 *p) { func_0689B670(p[0x6].f0); }




void func_021EAE54(E64 *p) { func_0689B69C(p[0x6].f0); }




/*
 * Resolved: func_0689B790 was matched (ov095), so the +0x0C ABS32 now
 * attests through the `matched` class and the thunk is byte-exact.
 *
 * Indexed-dispatch thunk, o18's 23-member shape: void func_021EAE64(E64 *p) { func_0689B790(p[0x6].f0); }
 */
void func_021EAE64(E64 *p) { func_0689B790(p[0x6].f0); }




void func_021EAE74(char *p, u32 a, u32 b)
{
    ((struct Obj07847 *)p)->f160 = a;
    ((struct Obj07847 *)p)->f164 = b;
    ((struct Obj07847 *)p)->f16C = 0;
    func_021EAE98(((struct Obj07847 *)p)->f180, p + 0x160);
}
