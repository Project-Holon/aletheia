/*
 * function: CROWD_FindBlockingMmdl
 * address:  0x021F42AC
 * packet:   pkt_ov055_021F42AC
 * region:   ov055
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * d and e are u16, as are CROWD_IsMmdlInFront's last two parameters (its own
 * file): with u32 the stack parameter's load (ldr r6, [sp, #0x20]) sinks to
 * the first call instead of leading the prologue.
 *
 * symbols:
 *   FLDMMDL_SysSearchUseMmdl  0x0216DD1C  thumb  ov010
 *   FLDMMDL_CheckStatusBit  0x0216D55C  thumb  ov010
 *   FLDMMDL_CheckStatusBitVanish  0x0216DAB4  thumb  ov010
 *   CROWD_IsMmdlInFront  0x021F4318  thumb  ov055
 */
#include "../include/Obj00204.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Ctx;
struct Rec;
extern int FLDMMDL_SysSearchUseMmdl(struct Ctx *c, struct Rec **out, u32 *iter);
extern int FLDMMDL_CheckStatusBit(int a, int b);
extern int FLDMMDL_CheckStatusBitVanish(void *a);
extern int CROWD_IsMmdlInFront(const u8 *a, void *b, u16 c, u16 d);

int CROWD_FindBlockingMmdl(u8 *a, void *b, u32 *c, u16 d, u16 e)
{
    u32 iter = 0;
    u32 cur;

    while (FLDMMDL_SysSearchUseMmdl(b, (struct Rec **)(&cur), &iter) == 1) {
        if (*(u32 *)&((struct Obj00204 *)a)->fC != cur && FLDMMDL_CheckStatusBit(cur, 0x80) == 0 &&
            FLDMMDL_CheckStatusBitVanish((void *)cur) == 0 && CROWD_IsMmdlInFront(a, (void *)cur, d, e) != 0) {
            *c = cur;
            return 1;
        }
    }
    return 0;
}
