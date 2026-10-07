/*
 * file:     guru2_main_p20.c
 * unit:     yes
 * function: func_021E11B4, func_021E11E4, func_021E11F4
 * address:  0x021E11B4
 * region:   ov137
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02082BCC 0x02082BCC arm
 *   func_02030DA8 0x02030DA8 arm
 *   func_021E11A0 0x021E11A0 thumb ov137
 *   func_02030EAC  0x02030EAC  arm
 */
#include "../../matched/include/Obj14246.h"
#include "../../matched/include/Obj23794.h"
#include "../../matched/include/Obj14247.h"

struct Node;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed int     s32;

typedef signed char s8;

typedef signed short s16;

extern void func_02082BCC(void *, int, unsigned);
extern void *func_02030DA8(void *, void (*)(void *, u8 *), void *, int);
extern void func_021E11A0(void *, u8 *);
extern void func_02030EAC(struct Node *n);
void func_021E11B4(char *p);
void func_021E11E4(u8 *p);
void func_021E11F4(char *p);

void func_021E11B4(char *p)
{
    func_02082BCC(p + 0xc74, 0, 20);
    ((struct Obj14246 *)p)->fD88 = func_02030DA8(((struct Obj14246 *)p)->fD98, func_021E11A0, p, 255);
}


/*
 * Addresses are Black-image addresses.
 */
void func_021E11E4(u8 *p)
{
    func_02030EAC(((struct Obj23794 *)p)->fD88);
}


void func_021E11F4(char *p)
{
    char *q = p + 0xC74;

    ((struct Obj14247 *)q)->f8 = 1;
    ((struct Obj14247 *)q)->f0 = 1;
}
