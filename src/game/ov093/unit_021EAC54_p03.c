/*
 * file:     unit_021EAC54_p03.c
 * unit:     yes
 * function: func_021EADF4, func_021EAE04
 * address:  0x021EADF4
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
 *   func_021EE390 0x021EE390 thumb ov093
 *   func_021EE228   0x021EE228  thumb  ov093
 */
#include "../../matched/include/Obj21576.h"

struct O;
typedef unsigned char u8;

typedef unsigned int u32;

typedef unsigned short u16;

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

typedef struct { u32 f0; u8 pad[60]; } E64;

extern int func_021EE390(struct O *);
int func_021EADF4(u8 *p);
void func_021EAE04(u32 *p);

int func_021EADF4(u8 *p)
{
    return func_021EE390(*(struct O * *)&((struct Obj21576 *)p)->f17C);
}


/*
 * Indexed-dispatch thunk (o18's 23-member shape): the member's whole stream is movs/lsls/ldr/ldr/bx with r0 as the load base; only the scratch register, the index constant and the tail target differ. Tail call T(p[i]) with the index materialised as a scaled immediate.
 */
void func_021EAE04(u32 *p) { func_021EE228(p[0x5f]); }
