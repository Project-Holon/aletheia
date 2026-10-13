/*
 * function: BTL_SERVER_CMD_ReadVariableArgs
 * address:  0x021CD6AC
 * packet:   pkt_ov093_021CD6AC
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_SERVER_CMD_ReadU16  0x021CCB18  thumb  ov093
 *   BTL_SERVER_CMD_ReadU32  0x021CCBE8  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern u16 BTL_SERVER_CMD_ReadU16(void *r);
extern s32 BTL_SERVER_CMD_ReadU32(void *r);

void BTL_SERVER_CMD_ReadVariableArgs(void *r, u8 cmd, s32 *out)
{
    int i;

    i = 1;
    out[0] = BTL_SERVER_CMD_ReadU16(r);
    if (cmd == 0x5c) {
        out[1] = BTL_SERVER_CMD_ReadU16(r);
        i++;
    }
    for (; i < 16; i++) {
        out[i] = BTL_SERVER_CMD_ReadU32(r);
        if (out[i] == 0xFFFF0000) {
            break;
        }
    }
}
