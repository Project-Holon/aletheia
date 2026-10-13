/*
 * function: UNION_MSG_SelectYesNo
 * address:  0x0217F268
 * packet:   pkt_ov019_0217F268
 * region:   ov019
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02034714  0x02034714  arm
 *   FIELD_MSGBG_YesNoMenuMain  0x02190C78  thumb  ov021
 *   d_021807F8     0x021807F8  data   ov019 a4
 * Addresses are Black-image addresses.
 */
#include "../include/Obj00033.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void func_02034714(const char *a, u32 b, const char *c);
struct Handle;
extern int FIELD_MSGBG_YesNoMenuMain(struct Handle *h);
extern u32 d_021807F8[];

int UNION_MSG_SelectYesNo(char *p, u32 *out)
{
    int r;

    if (*(u32 *)&((struct Obj00033 *)p)->f2814 == 0) {
        func_02034714((const char *)d_021807F8, 0, (const char *)d_021807F8);
    }
    r = FIELD_MSGBG_YesNoMenuMain((struct Handle *)(*(u32 *)(p + 0x2814)));
    if (r == 2) {
        return 0;
    }
    *out = (r == 0) ? 1 : 0;
    return 1;
}
