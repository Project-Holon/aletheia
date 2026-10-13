/*
 * function: FIELD_MSGBG_CreateMsgStreamColor
 * address:  0x02190C94
 * packet:   pkt_ov021_02190C94
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02030734  0x02030734  arm
 *   d_021DDA50     0x021DDA50  data   ov021  a1
 *   PRINTSYS_PrintStreamCallBack  0x0201CD10  thumb
 *   FIELD_MSGBG_MsgStreamCallback  0x02190D08  thumb  ov021
 *   FIELD_MSGBG_KeyWaitReset  0x02193200  thumb  ov021
 * Addresses are Black-image addresses.
 */
#include "../include/Obj07432.h"
#include "../include/Obj07433.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef short          s16;

extern char d_021DDA50[];

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
typedef signed int     s32;
struct Rec;
extern struct Rec *PRINTSYS_PrintStreamCallBack(u32 a0, s16 a1, s16 a2, u32 a3, u32 a4, s32 a5, u32 a6, u32 a7, u32 a8, u16 a9, u32 a10);
extern int FIELD_MSGBG_MsgStreamCallback(int x);
extern int FIELD_MSGBG_KeyWaitReset(u32 a);

u32 *FIELD_MSGBG_CreateMsgStreamColor(u32 *a, u32 b, u32 c, u32 d, u16 e0, u32 f, u16 g)
{
    u32 *r;

    r = (u32 *)func_02030734(((struct Obj07432 *)a)->f0, 0xc, 1, d_021DDA50, 0x85e);
    r[2] = (u32)a;
    ((struct Obj07433 *)r)->f2 = f;
    r[1] = (u32)PRINTSYS_PrintStreamCallBack(c, d, e0, b, a[2], f, a[0x59], 0, ((struct Obj07432 *)a)->f0, g,
                         (u32)((void *)FIELD_MSGBG_MsgStreamCallback));
    FIELD_MSGBG_KeyWaitReset(r[2] + 0x160);
    return r;
}
