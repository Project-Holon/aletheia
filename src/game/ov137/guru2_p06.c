/*
 * file:     guru2_p06.c
 * unit:     yes
 * function: func_021DD1A4, func_021DD1B4, func_021DD1D0
 * address:  0x021DD1A4
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
 *   func_021DD14C  0x021DD14C  thumb
 *   func_0204A648  0x0204A648  arm
 *   func_020419E4  0x020419E4  arm
 *   func_0201C4E4  0x0201C4E4  thumb
 *   func_020310C4  0x020310C4  arm
 *   func_020433E0 0x020433E0 arm
 *   d_021E1B40 0x021E1B40 data a4
 */
#include "../../matched/include/Obj10615.h"

struct PrintSys;
struct Tcbl;
struct DispVram;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed int     s32;

typedef signed short s16;

extern void func_021DD14C(void *unused, u8 *p);
extern void func_0204A648(void);
extern void func_020419E4(void);
extern u32 func_0201C4E4(struct PrintSys *ps);
extern void func_020310C4(struct Tcbl *p);
extern void func_020433E0(const struct DispVram *c);
void func_021DD1A4(void *a0, void *work);
void func_021DD1B4(u8 *p);
void func_021DD1D0(void);
extern const u32 d_021E1B40[];


/*
 * Addresses are Black-image addresses.
 */
void func_021DD1A4(void *a0, void *work)
{
    func_021DD14C(a0, work);
    func_0204A648();
    func_020419E4();
}


void func_021DD1B4(u8 *p)
{
    if (((struct Obj10615 *)p)->fEC)
        func_0201C4E4(((struct Obj10615 *)p)->fEC);
    func_020310C4(((struct Obj10615 *)p)->fF4);
}

void func_021DD1D0(void) {func_020433E0((const struct DispVram *)d_021E1B40);}
