/*
 * file:     unit_021B7560_p01.c
 * unit:     yes
 * function: func_021B78D0, func_021B78E4
 * address:  0x021B78D0
 * region:   ov102
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02030EAC 0x02030EAC arm
 *   func_021B7BC0 0x021B7BC0 thumb ov102
 *   func_021B7C04  0x021B7C04  thumb  ov102
 */
#include "../../matched/include/Obj22141.h"

struct Node;
typedef unsigned char u8;

typedef unsigned short u16;

typedef short s16;

typedef signed char s8;

typedef unsigned int u32;

typedef int s32;

extern void func_02030EAC(struct Node *);
extern void func_021B7BC0(void *);
extern void func_021B7C04(void *);
void func_021B78D0(void *p);
void func_021B78E4(void *p);

void func_021B78D0(void *p) { func_02030EAC(*(struct Node * *)&((struct Obj22141 *)p)->f90); func_021B7BC0(p); }

/*
 * evidence: func_021B7C04 is ov102's own code ("ldr r3, =0x0204A600; bx r3"
 * after the pop at 0x021B7C00), inside ov102's window, so only ov102 can be
 * resident there when this pool word is used.  Its start is seeded in
 * layout/function_starts.txt from this pointer word, the only reference;
 * it attests as sole-ref/code from ov102's own listing.  The old hint ov021
 * named a different overlay's function mapped over the same address.
 */
void func_021B78E4(void *p) { func_021B7C04(p); }
