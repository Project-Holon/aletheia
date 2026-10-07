/*
 * file:     unit_021B7560_p02.c
 * unit:     yes
 * function: func_021B78EC, func_021B7918, func_021B793C, func_021B7948, func_021B7954
 * address:  0x021B78EC
 * region:   ov103
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
 *   func_021B8C40 0x021B8C40 thumb ov103
 *   func_021B7D08 0x021B7D08 thumb ov103
 *   func_021B7AE8 0x021B7AE8 thumb ov103
 *   func_021B7C08 0x021B7C08 thumb ov103
 *   func_021B7C4C 0x021B7C4C thumb ov103
 *   func_021B7D30 0x021B7D30 thumb ov103
 *   func_021B8C4C 0x021B8C4C thumb ov103
 *   func_021B7D44 0x021B7D44 thumb ov103
 *   func_021B7C5C  0x021B7C5C  thumb  ov103
 *   func_021B7C64  0x021B7C64  thumb  ov103
 */
#include "../../matched/include/Obj22177.h"

struct Node;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef short s16;

typedef signed char s8;

typedef int s32;

extern void func_02030EAC(struct Node *n);
extern void func_021B8C40(void *);
extern void func_021B7D08(u8 *p);
extern void func_021B7AE8(u32 *);
extern void func_021B7C08(u8 *);
extern void func_021B7C4C(void *);
extern void func_021B7D30(u8 *p);
extern void func_021B8C4C(u8 **);
extern void func_021B7D44(void *);
extern u32 func_021B7C5C(u8 *p, u32 i);
extern u32 func_021B7C64(u32 *p);
void func_021B78EC(u8 *p);
void func_021B7918(u8 *p);
int func_021B793C(u8 *p, int i);
u32 func_021B7948(u8 *p);
u8 *func_021B7954(u8 *p);

void func_021B78EC(u8 *p) { func_02030EAC(((struct Obj22177 *)p)->f170); func_021B8C40(p+352); func_021B7D08(p+4); func_021B7AE8((u32 *)p); func_021B7C08(p+204); }

void func_021B7918(u8 *p) { func_021B7C4C(p+204); func_021B7D30(p+4); func_021B8C4C((u8 **)(p+352)); func_021B7D44(p+4); }

/*
 * evidence: func_021B7C5C is ov103's own code ("lsls r1, #2; adds r0, r1;
 * ldr r0, [r0, #0x10]; bx lr" after pool_021B7C58), inside ov103's window, so
 * only ov103 can be resident there when this pool word is used.  Its start is
 * seeded in layout/function_starts.txt from this pointer word, the only
 * reference; it attests as sole-ref/code from ov103's own listing.  The old
 * hint ov016 named a different overlay's function mapped over the address.
 */
int func_021B793C(u8 *p, int i) { return func_021B7C5C(p + 0xcc, i); }

u32 func_021B7948(u8 *p) { return func_021B7C64((u32 *)(p + 0xcc)); }


u8 *func_021B7954(u8 *p) { return p + 0x160; }
