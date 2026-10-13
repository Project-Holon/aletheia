/*
 * function: BTL_SERVER_CMD_WriteCommand
 * address:  0x021CCC0C
 * packet:   pkt_021CCC0C
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_SERVER_CMD_WriteCommand   0x021CCC0C  thumb
 *   BTL_SERVER_CMD_WriteU8   0x021CCAA8  thumb ov093
 *   BTL_SERVER_CMD_WriteU16   0x021CCAE0  thumb ov093
 *   BTL_SERVER_CMD_WriteU24   0x021CCB34  thumb ov093
 *   BTL_SERVER_CMD_WriteU32   0x021CCB98  thumb ov093
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;

extern void BTL_SERVER_CMD_WriteU8(void *w, u8 v);
extern void BTL_SERVER_CMD_WriteU16(void *w, u16 v);
extern void BTL_SERVER_CMD_WriteU24(void *w, u32 v);
extern void BTL_SERVER_CMD_WriteU32(void *w, s32 v);

void BTL_SERVER_CMD_WriteCommand(void *w, u32 id, int cmd, s32 *a)
{
    int i;

    BTL_SERVER_CMD_WriteU16(w, id);
    switch (cmd) {
    case 1:
        BTL_SERVER_CMD_WriteU8(w, a[0]);
        break;
    case 17:
        BTL_SERVER_CMD_WriteU16(w, a[0]);
        break;
    case 2:
        BTL_SERVER_CMD_WriteU8(w, a[0]);
        BTL_SERVER_CMD_WriteU8(w, a[1]);
        break;
    case 18:
        BTL_SERVER_CMD_WriteU8(w, a[0]);
        BTL_SERVER_CMD_WriteU16(w, a[1]);
        break;
    case 34:
        BTL_SERVER_CMD_WriteU8(w, a[0]);
        BTL_SERVER_CMD_WriteU32(w, a[1]);
        break;
    case 50:
        BTL_SERVER_CMD_WriteU8(w, ((a[0] & 0xF) << 4) | (a[1] & 0xF));
        break;
    case 66:
        BTL_SERVER_CMD_WriteU8(w, ((a[0] & 0x1F) << 3) | (a[1] & 7));
        break;
    case 3:
        BTL_SERVER_CMD_WriteU8(w, ((a[0] & 0x1F) << 3) | (a[1] & 7));
        BTL_SERVER_CMD_WriteU8(w, a[2]);
        break;
    case 19:
        BTL_SERVER_CMD_WriteU8(w, ((a[0] & 0x1F) << 3) | (a[1] & 7));
        BTL_SERVER_CMD_WriteU16(w, a[2]);
        break;
    case 35:
        BTL_SERVER_CMD_WriteU16(w, (a[2] & 0x1F) | (((a[1] & 0x1F) << 5) | ((a[0] & 0x1F) << 10)));
        break;
    case 51:
        BTL_SERVER_CMD_WriteU24(w, (a[2] & 0x3FFF) | (((a[1] & 0x1F) << 14) | ((a[0] & 0x1F) << 19)));
        break;
    case 67:
        BTL_SERVER_CMD_WriteU8(w, a[0]);
        BTL_SERVER_CMD_WriteU8(w, a[1]);
        BTL_SERVER_CMD_WriteU16(w, a[2]);
        break;
    case 83:
        BTL_SERVER_CMD_WriteU8(w, a[0]);
        BTL_SERVER_CMD_WriteU8(w, a[1]);
        BTL_SERVER_CMD_WriteU32(w, a[2]);
        break;
    case 20:
        BTL_SERVER_CMD_WriteU8(w, ((a[0] & 0x1F) << 3) | (a[1] & 7));
        BTL_SERVER_CMD_WriteU8(w, ((a[2] & 0x1F) << 3) | (a[3] & 7));
        break;
    case 4:
        BTL_SERVER_CMD_WriteU8(w, ((a[0] & 0x1F) << 3) | (a[1] & 7));
        BTL_SERVER_CMD_WriteU8(w, a[2]);
        BTL_SERVER_CMD_WriteU16(w, a[3]);
        break;
    case 36:
        BTL_SERVER_CMD_WriteU24(w, (a[2] & 0x3FFF) | (((a[1] & 0x1F) << 14) | ((a[0] & 0x1F) << 19)));
        BTL_SERVER_CMD_WriteU8(w, a[3]);
        break;
    case 52:
        BTL_SERVER_CMD_WriteU24(w, (a[2] & 0x3FFF) | (((a[1] & 0x1F) << 14) | ((a[0] & 0x1F) << 19)));
        BTL_SERVER_CMD_WriteU16(w, a[3]);
        break;
    case 68:
        BTL_SERVER_CMD_WriteU16(w, (a[2] & 0x3F) | (((a[1] & 0x1F) << 6) | ((a[0] & 0x1F) << 11)));
        BTL_SERVER_CMD_WriteU16(w, a[3]);
        break;
    case 84:
        BTL_SERVER_CMD_WriteU8(w, a[0]);
        BTL_SERVER_CMD_WriteU8(w, a[1]);
        BTL_SERVER_CMD_WriteU16(w, a[2]);
        BTL_SERVER_CMD_WriteU16(w, a[3]);
        break;
    case 5:
        BTL_SERVER_CMD_WriteU16(w, (a[2] & 0x1F) | (((a[1] & 0x1F) << 5) | ((a[0] & 0x1F) << 10)));
        BTL_SERVER_CMD_WriteU16(w, a[3]);
        BTL_SERVER_CMD_WriteU16(w, a[4]);
        break;
    case 21: {
        u8 hi = ((a[0] & 0x1F) << 3) | (a[1] & 7);
        u8 lo = ((a[2] & 0x7F) << 1) | (a[3] & 1);
        BTL_SERVER_CMD_WriteU16(w, hi);
        BTL_SERVER_CMD_WriteU16(w, lo);
        BTL_SERVER_CMD_WriteU16(w, a[4]);
        break;
    }
    case 37:
        BTL_SERVER_CMD_WriteU8(w, ((a[0] & 7) << 5) | ((a[1] & 7) << 2) | ((a[2] & 1) << 1) | (a[3] & 1));
        BTL_SERVER_CMD_WriteU16(w, a[4]);
        break;
    case 6: {
        u16 v0 = (a[2] & 0x1F) | (((a[1] & 0x1F) << 5) | ((a[0] & 0x1F) << 10));
        u16 v1 = (a[5] & 0x1F) | (((a[4] & 0x1F) << 5) | ((a[3] & 0x1F) << 10));
        BTL_SERVER_CMD_WriteU16(w, v0);
        BTL_SERVER_CMD_WriteU16(w, v1);
        break;
    }
    case 22:
        BTL_SERVER_CMD_WriteU8(w, ((a[0] & 7) << 5) | ((a[1] & 3) << 3) | ((a[2] & 1) << 2) | ((a[3] & 1) << 1) | (a[4] & 1));
        BTL_SERVER_CMD_WriteU16(w, a[5]);
        break;
    case 38:
        BTL_SERVER_CMD_WriteU24(w, ((a[0] & 0x1F) << 15) | ((a[1] & 0x1F) << 10) | ((a[2] & 0x1F) << 5) | (a[3] & 0x1F));
        BTL_SERVER_CMD_WriteU16(w, a[4]);
        BTL_SERVER_CMD_WriteU16(w, a[5]);
        break;
    case 7:
        for (i = 0; i < 7; i++)
            BTL_SERVER_CMD_WriteU8(w, a[i]);
        break;
    case 8:
        for (i = 0; i < 8; i++)
            BTL_SERVER_CMD_WriteU8(w, a[i]);
        break;
    }
}
