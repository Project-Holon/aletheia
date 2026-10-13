/*
 * function: UNION_MSG_PrintTalkMsg
 * address:  0x0217F188
 * packet:   pkt_ov019_0217F188
 * region:   ov019
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02034714  0x02034714  arm
 *   MSGDATA_ReadString  0x02045CAC  arm
 *   func_0201F250  0x0201F250  thumb
 *   FIELD_MSGBG_PlainWinPrintStream  0x021916A8  thumb  ov021
 *   d_021807F8     0x021807F8  data   ov019 a4
 * Addresses are Black-image addresses.
 */
#include "../include/Obj00484.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void func_02034714(const char *a, u32 b, const char *c);
struct MsgBank;
struct R;
struct WordSet;
extern void MSGDATA_ReadString(struct MsgBank *bank, u32 index, void *dest);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void FIELD_MSGBG_PlainWinPrintStream(struct R *r, u32 b, u16 c, u32 d);
extern u32 d_021807F8[];

void UNION_MSG_PrintTalkMsg(char *p, u32 arg)
{
    if (*(u32 *)&((struct Obj00484 *)p)->f280C == 0) {
        func_02034714((const char *)d_021807F8, 0, (const char *)d_021807F8);
    }
    MSGDATA_ReadString((struct MsgBank *)(*(u32 *)&((struct Obj00484 *)p)->f2808), arg, (void *)(((struct Obj00484 *)p)->f2820));
    func_0201F250((struct WordSet *)(*(u32 *)&((struct Obj00484 *)p)->f2804), (void *)(((struct Obj00484 *)p)->f2824), (void *)(((struct Obj00484 *)p)->f2820));
    FIELD_MSGBG_PlainWinPrintStream((struct R *)(*(u32 *)(p + 0x280c)), 0, 0, ((struct Obj00484 *)p)->f2824);
    ((struct Obj00484 *)p)->f2828 = 1;
}
