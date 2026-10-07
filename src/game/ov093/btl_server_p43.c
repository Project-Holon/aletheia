/*
 * file:     btl_server_p43.c
 * unit:     yes
 * function: func_021C0780, func_021C07AC
 * address:  0x021C0780
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
 *   func_021D5440  0x021D5440  thumb  ov093
 *   func_021CD4B0  0x021CD4B0  thumb  ov093
 *   func_021D69A0  0x021D69A0  thumb  ov093
 *   func_021C07D4 0x021C07D4 thumb ov093
 *   func_021C0898 0x021C0898 thumb ov093
 */
#include "../../matched/include/Obj00003.h"

typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

extern u8 func_021D5440(u8 *p);
extern void func_021CD4B0(void *w, volatile u32 id, ...);
extern void func_021D69A0(u8 *base, int idx, u8 val);
extern int func_021C07D4(u8 *, u8 *, u32, u32, int);
extern int func_021C0898(u8 *, u8 *, u32, u32);
void func_021C0780(u8 *p, u8 *a, int i, u8 v);
int func_021C07AC(u8 *p, u8 *a, u32 c, u32 d, int e);


void func_021C0780(u8 *p, u8 *a, int i, u8 v)
{
    func_021CD4B0(((struct Obj00003 *)p)->fC, 0x25, func_021D5440(a), (u8)i, v);
    func_021D69A0(a, i, v);
}

/*
 * extent: Two alignment bytes at 0x021C07D2 precede matched func_021C07D4.
 * lever: Wide forwarded arguments avoid truncations absent before the first call.
 */
int func_021C07AC(u8 *p, u8 *a, u32 c, u32 d, int e)
{
    u8 result = func_021C07D4(p, a, d, c, e);
    return func_021C0898(p, a, d, result);
}
