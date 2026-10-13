/*
 * function: BTL_MSG_BuildPlainEntry
 * address:  0x021EF664
 * packet:   pkt_ov093_021EF664
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   gBtlMsgState  0x021F6398  data  a4
 *   MSGDATA_ReadString  0x02045CAC  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    u32 f0;
    u32 f4;
    u32 f8;
    u32 fc;
    u32 t[8];
} D;

extern D gBtlMsgState;
struct MsgBank;
extern void MSGDATA_ReadString(struct MsgBank *bank, u32 index, void *dest);

void BTL_MSG_BuildPlainEntry(int a, u16 b, int c)
{
    u16 k;

    if (b != 0) {
        k = (b - 1) * 3;
        if (c == 0)
            k = k + 1;
        else
            k = k + 2;
        MSGDATA_ReadString((struct MsgBank *)gBtlMsgState.t[7], k, (void *)a);
    }
}
