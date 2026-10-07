/*
 * file:     unit_021B7560_p03.c
 * unit:     yes
 * function: func_021B7940, func_021B795C, func_021B7968, func_021B7974
 * address:  0x021B7940
 * region:   ov104
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
 *   func_021B7AD4 0x021B7AD4 thumb ov104
 *   func_021B7CA4 0x021B7CA4 thumb ov104
 *   func_021B7D0C  0x021B7D0C  thumb  ov104
 *   func_021B7D1C  0x021B7D1C  thumb  ov104
 *   func_021B7D24  0x021B7D24  thumb  ov104
 */
#include "../../matched/include/Obj22216.h"

struct Node;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef short s16;

typedef signed char s8;

typedef int s32;

extern void func_02030EAC(struct Node *);
extern void func_021B7AD4(u32 *);
extern void func_021B7CA4(void **);
extern void func_021B7D0C(int x);
extern int func_021B7D1C(u8 *p, int i);
extern u32 func_021B7D24(u32 *p);
void func_021B7940(u8 *p);
void func_021B795C(u8 *p);
int func_021B7968(u8 *p, int i);
u32 func_021B7974(u8 *p);

/*
 * extent: two zero alignment bytes follow compiled code.
 */
void func_021B7940(u8 *p) { func_02030EAC(*(struct Node * *)&((struct Obj22216 *)p)->fB8); func_021B7AD4((u32 *)p); func_021B7CA4((void **)(p+4)); }

void func_021B795C(u8 *p) { func_021B7D0C((int)(p + 4)); }

int func_021B7968(u8 *p, int i) { return func_021B7D1C(p + 4, i); }

/*
 * Unblocked by matching func_021B7D24 in ov104 (pkt_ov104_021B7D24).
 */
u32 func_021B7974(u8 *p) { return func_021B7D24((u32 *)(p + 4)); }
