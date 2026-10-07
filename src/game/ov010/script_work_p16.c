/*
 * file:     script_work_p16.c
 * unit:     yes
 * function: func_021590D4, func_021590F4
 * address:  0x021590D4
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02158FD0 0x02158FD0 thumb ov010
 *   func_02082A60 0x02082A60 arm
 *   func_020307B0 0x020307B0 arm
 */
#include "../../matched/include/Obj17639.h"

typedef unsigned int   u32;

typedef unsigned char  u8;

typedef unsigned short u16;

typedef signed short   s16;

extern int func_02158FD0(int a0, u32 a1, int a2);
extern void func_02082A60(const void *, void *, unsigned int);
extern u32 func_020307B0(void *p);
void func_021590D4(void *a, void *b, int a2);
void func_021590F4(void *p, u32 v);

void func_021590D4(void *a, void *b, int a2)
{
    void *p = (void *)func_02158FD0((int)a, 0x8020, a2);
    func_02082A60(b, p, 0x7e);
    func_020307B0(b);
}


/*
 * generated: lane O24 (ov010 leaf/wrapper sweep)
 *
 * Shifted-index word-field setter, same shape as its getter partner.
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_021590F4.c \
 *       --func func_021590F4 --addr 0x021590F4 --region ov010 --cc dsi/1.1p1 --thumb
 */
void func_021590F4(void *p, u32 v) { ((struct Obj17639 *)p)->f13C = v; }
