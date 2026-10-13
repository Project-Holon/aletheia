/*
 * function: UNION_MSG_SetupTalkWindow
 * address:  0x0217F098
 * packet:   pkt_ov019_0217F098
 * region:   ov019
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02034714  0x02034714  arm
 *   FIELDMAP_GetMsgBg  0x02188C54  thumb  ov021
 *   FIELD_MSGBG_CreateMsgData  0x021904B0  thumb  ov021
 *   STRBUF_Create  0x020457B0  arm
 *   UNION_MSG_CreateWordSet  0x0217F020  thumb  ov019
 *   FIELD_MSGBG_CreatePlainWin  0x02191558  thumb  ov021
 *   FIELD_MSGBG_ClearPlainWin  0x021915EC  thumb  ov021
 *   d_021807F8     0x021807F8  data  a4
 */
#include "../include/Obj00484.h"

typedef unsigned char  u8;
extern void func_02034714(const char *expr, unsigned int line, const char *file);
extern unsigned int FIELDMAP_GetMsgBg(u8 *p);
typedef unsigned int   u32;
extern int FIELD_MSGBG_CreateMsgData(u32 a, u32 b);
typedef unsigned short u16;
struct Fx;
struct R;
struct U16Vec;
extern struct U16Vec *STRBUF_Create(u32 capacity, u32 heapId);
extern void UNION_MSG_CreateWordSet(unsigned char *p);
extern struct R *FIELD_MSGBG_CreatePlainWin(struct Fx *a, u32 b, u32 c, u16 d, u16 e, u16 f, u16 g);
struct R;
extern void FIELD_MSGBG_ClearPlainWin(struct R *r);
extern int d_021807F8[];

void UNION_MSG_SetupTalkWindow(unsigned char *base, u8 *x)
{
    int r6;
    if (((struct Obj00484 *)base)->f280C == 0) {
        if (*(int *)&((struct Obj00484 *)base)->f2808 != 0)
            func_02034714((const char *)d_021807F8, 0, (const char *)d_021807F8);
        r6 = FIELDMAP_GetMsgBg(x);
        *(int *)(base + 0x2808) = FIELD_MSGBG_CreateMsgData(r6, 200);
        *(int *)&((struct Obj00484 *)base)->f2820 = (int)STRBUF_Create(0x100, 0x41);
        *(int *)&((struct Obj00484 *)base)->f2824 = (int)STRBUF_Create(0x100, 0x41);
        UNION_MSG_CreateWordSet(base);
        ((struct Obj00484 *)base)->f280C = (int)FIELD_MSGBG_CreatePlainWin((struct Fx *)r6, *(int *)(base + 0x2808), 0, 1, 0x13, 0x1e, 4);
    } else {
        FIELD_MSGBG_ClearPlainWin((struct R *)(((struct Obj00484 *)base)->f280C));
    }
}
