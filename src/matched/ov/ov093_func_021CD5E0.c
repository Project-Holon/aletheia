/*
 * function: BTL_SERVER_CMD_ReadNext
 * address:  0x021CD5E0
 * packet:   pkt_ov093_021CD5E0
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_SERVER_CMD_ReadU16  0x021CCB18  thumb  ov093
 *   BTL_SERVER_CMD_ReadU8  0x021CCAD4  thumb  ov093
 *   BTL_SERVER_CMD_ReadFixedArgs  0x021CD0F0  thumb  ov093
 *   BTL_SERVER_CMD_ReadVariableArgs  0x021CD6AC  thumb  ov093
 *   gBtlServerCmdLayouts  0x021EFF14  data
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

typedef struct {
    u32 wpos;
    u32 rpos;
} Buf;

extern const u8 gBtlServerCmdLayouts[];
extern u16 BTL_SERVER_CMD_ReadU16(void *r);
extern u8 BTL_SERVER_CMD_ReadU8(u8 *p);
extern void BTL_SERVER_CMD_ReadFixedArgs(void *r, int cmd, s32 *a);
extern void BTL_SERVER_CMD_ReadVariableArgs(void *r, u8 cmd, s32 *a);

int BTL_SERVER_CMD_ReadNext(Buf *r, s32 *a)
{
    int c;
    u8 k;

    c = BTL_SERVER_CMD_ReadU16(r);
    while (c == 0x5f) {
        r->rpos += BTL_SERVER_CMD_ReadU8((u8 *)r);
        if (r->rpos >= r->wpos) {
            return 0x5e;
        }
        c = BTL_SERVER_CMD_ReadU16(r);
    }
    k = gBtlServerCmdLayouts[c];
    if (k != 0 && k != 0x10) {
        BTL_SERVER_CMD_ReadFixedArgs(r, k, a);
    } else {
        BTL_SERVER_CMD_ReadVariableArgs(r, c, a);
    }
    return c;
}
