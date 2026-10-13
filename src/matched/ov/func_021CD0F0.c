/*
 * function: BTL_SERVER_CMD_ReadFixedArgs
 * address:  0x021CD0F0
 * packet:   pkt_021CD0F0
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_SERVER_CMD_ReadFixedArgs   0x021CD0F0  thumb
 *   BTL_SERVER_CMD_ReadU8   0x021CCAD4  thumb ov093
 *   BTL_SERVER_CMD_ReadU16   0x021CCB18  thumb ov093
 *   BTL_SERVER_CMD_ReadU24   0x021CCB78  thumb ov093
 *   BTL_SERVER_CMD_ReadU32   0x021CCBE8  thumb ov093
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;

extern u8 BTL_SERVER_CMD_ReadU8(u8 *p);
extern u16 BTL_SERVER_CMD_ReadU16(void *r);
extern u32 BTL_SERVER_CMD_ReadU24(void *r);
extern s32 BTL_SERVER_CMD_ReadU32(void *r);

void BTL_SERVER_CMD_ReadFixedArgs(void *r, int cmd, s32 *a)
{
    u8 b;
    u32 h;
    u32 x;
    int i;

    switch (cmd) {
    case 1:
        a[0] = BTL_SERVER_CMD_ReadU8(r);
        break;
    case 17:
        a[0] = BTL_SERVER_CMD_ReadU16(r);
        break;
    case 2:
        a[0] = BTL_SERVER_CMD_ReadU8(r);
        a[1] = BTL_SERVER_CMD_ReadU8(r);
        break;
    case 18:
        a[0] = BTL_SERVER_CMD_ReadU8(r);
        a[1] = BTL_SERVER_CMD_ReadU16(r);
        break;
    case 34:
        a[0] = BTL_SERVER_CMD_ReadU8(r);
        a[1] = BTL_SERVER_CMD_ReadU32(r);
        break;
    case 50:
        b = BTL_SERVER_CMD_ReadU8(r);
        a[0] = (b >> 4) & 0xF;
        a[1] = b & 0xF;
        break;
    case 66:
        b = BTL_SERVER_CMD_ReadU8(r);
        a[0] = (b >> 3) & 0x1F;
        a[1] = b & 7;
        break;
    case 3:
        b = BTL_SERVER_CMD_ReadU8(r);
        a[0] = (b >> 3) & 0x1F;
        a[1] = b & 7;
        a[2] = BTL_SERVER_CMD_ReadU8(r);
        break;
    case 19:
        b = BTL_SERVER_CMD_ReadU8(r);
        a[0] = (b >> 3) & 0x1F;
        a[1] = b & 7;
        a[2] = BTL_SERVER_CMD_ReadU16(r);
        break;
    case 35:
        h = BTL_SERVER_CMD_ReadU16(r);
        a[0] = (h >> 10) & 0x1F;
        a[1] = (h >> 5) & 0x1F;
        a[2] = h & 0x1F;
        break;
    case 51:
        x = BTL_SERVER_CMD_ReadU24(r);
        a[0] = (x >> 19) & 0x1F;
        a[1] = (x >> 14) & 0x1F;
        a[2] = x & 0x3FFF;
        break;
    case 67:
        a[0] = BTL_SERVER_CMD_ReadU8(r);
        a[1] = BTL_SERVER_CMD_ReadU8(r);
        a[2] = BTL_SERVER_CMD_ReadU16(r);
        break;
    case 83:
        a[0] = BTL_SERVER_CMD_ReadU8(r);
        a[1] = BTL_SERVER_CMD_ReadU8(r);
        a[2] = BTL_SERVER_CMD_ReadU32(r);
        break;
    case 20:
        b = BTL_SERVER_CMD_ReadU8(r);
        a[0] = (b >> 3) & 0x1F;
        a[1] = b & 7;
        b = BTL_SERVER_CMD_ReadU8(r);
        a[2] = (b >> 3) & 0x1F;
        a[3] = b & 7;
        break;
    case 4:
        b = BTL_SERVER_CMD_ReadU8(r);
        a[0] = (b >> 3) & 0x1F;
        a[1] = b & 7;
        a[2] = BTL_SERVER_CMD_ReadU8(r);
        a[3] = BTL_SERVER_CMD_ReadU16(r);
        break;
    case 36:
        x = BTL_SERVER_CMD_ReadU24(r);
        a[0] = (x >> 19) & 0x1F;
        a[1] = (x >> 14) & 0x1F;
        a[2] = x & 0x3FFF;
        a[3] = BTL_SERVER_CMD_ReadU8(r);
        break;
    case 52:
        x = BTL_SERVER_CMD_ReadU24(r);
        a[0] = (x >> 19) & 0x1F;
        a[1] = (x >> 14) & 0x1F;
        a[2] = x & 0x3FFF;
        a[3] = BTL_SERVER_CMD_ReadU16(r);
        break;
    case 68:
        h = BTL_SERVER_CMD_ReadU16(r);
        a[0] = (h >> 11) & 0x1F;
        a[1] = (h >> 6) & 0x1F;
        a[2] = h & 0x3F;
        a[3] = BTL_SERVER_CMD_ReadU16(r);
        break;
    case 84:
        a[0] = BTL_SERVER_CMD_ReadU8(r);
        a[1] = BTL_SERVER_CMD_ReadU8(r);
        a[2] = BTL_SERVER_CMD_ReadU16(r);
        a[3] = BTL_SERVER_CMD_ReadU16(r);
        break;
    case 5:
        h = BTL_SERVER_CMD_ReadU16(r);
        a[0] = (h >> 10) & 0x1F;
        a[1] = (h >> 5) & 0x1F;
        a[2] = h & 0x1F;
        a[3] = BTL_SERVER_CMD_ReadU16(r);
        a[4] = BTL_SERVER_CMD_ReadU16(r);
        break;
    case 21: {
        u32 hi = BTL_SERVER_CMD_ReadU16(r);
        u32 lo = BTL_SERVER_CMD_ReadU16(r);
        a[0] = ((u8)hi >> 3) & 0x1F;
        a[1] = (u8)hi & 7;
        a[2] = ((u8)lo >> 1) & 0x7F;
        a[3] = (u8)lo & 1;
        a[4] = BTL_SERVER_CMD_ReadU16(r);
        break;
    }
    case 37:
        x = BTL_SERVER_CMD_ReadU8(r);
        a[0] = (x >> 5) & 7;
        a[1] = (x >> 2) & 7;
        a[2] = (x >> 1) & 1;
        a[3] = x & 1;
        a[4] = BTL_SERVER_CMD_ReadU16(r);
        break;
    case 6: {
        u32 v0 = BTL_SERVER_CMD_ReadU16(r);
        u32 v1 = BTL_SERVER_CMD_ReadU16(r);
        a[0] = (v0 >> 10) & 0x1F;
        a[1] = (v0 >> 5) & 0x1F;
        a[2] = v0 & 0x1F;
        a[3] = (v1 >> 10) & 0x1F;
        a[4] = (v1 >> 5) & 0x1F;
        a[5] = v1 & 0x1F;
        break;
    }
    case 22:
        x = BTL_SERVER_CMD_ReadU8(r);
        a[0] = (x >> 5) & 7;
        a[1] = (x >> 3) & 3;
        a[2] = (x >> 2) & 1;
        a[3] = (x >> 1) & 1;
        a[4] = x & 1;
        a[5] = BTL_SERVER_CMD_ReadU16(r);
        break;
    case 38:
        x = BTL_SERVER_CMD_ReadU24(r);
        a[0] = (x >> 15) & 0x1F;
        a[1] = (x >> 10) & 0x1F;
        a[2] = (x >> 5) & 0x1F;
        a[3] = x & 0x1F;
        a[4] = BTL_SERVER_CMD_ReadU16(r);
        a[5] = BTL_SERVER_CMD_ReadU16(r);
        break;
    case 7:
        for (i = 0; i < 7; i++)
            a[i] = BTL_SERVER_CMD_ReadU8(r);
        break;
    case 8:
        for (i = 0; i < 8; i++)
            a[i] = BTL_SERVER_CMD_ReadU8(r);
        break;
    }
}
