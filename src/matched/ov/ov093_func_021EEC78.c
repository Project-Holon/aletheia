/*
 * function: BTL_MSG_Init
 * address:  0x021EEC78
 * packet:   pkt_ov093_021EEC78
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_MAIN_CheckSetupStatusFlag  0x021BA1A8  thumb  ov093
 *   func_0201EC64  0x0201EC64  thumb
 *   STRBUF_Create  0x020457B0  arm
 *   func_02045B38  0x02045B38  arm
 *   gBtlMsgState     0x021F6398  data  ov093  a4
 *   gBtlMsgFlags     0x021F63D8  data  ov093  a4
 *   sBtlMsgBankFileIds     0x021F3990  data  ov093  a2
 */

#include "../include/G_ov093_021F6398.h"
#include "../include/G_H.h"

typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;

typedef struct {
    u8 pad[0x10];
    u16 f10;
    u8 pad2[6];
    u16 f18;
    u16 f1a;
} H;

extern struct G_ov093_021F6398 gBtlMsgState;
extern struct H gBtlMsgFlags;
extern const u16 sBtlMsgBankFileIds[];
struct MsgBank;
struct U16Vec;
struct WordSet;
extern int BTL_MAIN_CheckSetupStatusFlag(char **p, int m);
extern struct WordSet *func_0201EC64(u32 heap);
extern struct U16Vec *STRBUF_Create(u32 capacity, u32 heapId);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);

void BTL_MSG_Init(u32 a, u32 b, u32 c, u32 d)
{
    int i;

    gBtlMsgState.f00 = a;
    gBtlMsgState.f04 = c;
    gBtlMsgFlags.f10 = d;
    gBtlMsgState.f54 = b;
    gBtlMsgFlags.f18 = BTL_MAIN_CheckSetupStatusFlag((char **)a, 0x200);
    gBtlMsgFlags.f1a = 0;
    gBtlMsgState.f08 = (u32)func_0201EC64(d);
    gBtlMsgState.f0c = (u32)STRBUF_Create(0x200 >> 1, d);
    for (i = 0; i < 8; i++) {
        gBtlMsgState.t[i] = (u32)func_02045B38(0, 2, sBtlMsgBankFileIds[i], d);
    }
}
