/*
 * function: func_021CD0F0
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
 *   func_021CD0F0   0x021CD0F0  thumb
 *   func_021CCAD4   0x021CCAD4  thumb ov093
 *   func_021CCB18   0x021CCB18  thumb ov093
 *   func_021CCB78   0x021CCB78  thumb ov093
 *   func_021CCBE8   0x021CCBE8  thumb ov093
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;

extern u8 func_021CCAD4(u8 *p);
extern u16 func_021CCB18(void *r);
extern u32 func_021CCB78(void *r);
extern s32 func_021CCBE8(void *r);

void func_021CD0F0(void *r, int cmd, s32 *a)
{
    u8 b;
    u32 h;
    u32 x;
    int i;

    switch (cmd) {
    case 1:
        a[0] = func_021CCAD4(r);
        break;
    case 17:
        a[0] = func_021CCB18(r);
        break;
    case 2:
        a[0] = func_021CCAD4(r);
        a[1] = func_021CCAD4(r);
        break;
    case 18:
        a[0] = func_021CCAD4(r);
        a[1] = func_021CCB18(r);
        break;
    case 34:
        a[0] = func_021CCAD4(r);
        a[1] = func_021CCBE8(r);
        break;
    case 50:
        b = func_021CCAD4(r);
        a[0] = (b >> 4) & 0xF;
        a[1] = b & 0xF;
        break;
    case 66:
        b = func_021CCAD4(r);
        a[0] = (b >> 3) & 0x1F;
        a[1] = b & 7;
        break;
    case 3:
        b = func_021CCAD4(r);
        a[0] = (b >> 3) & 0x1F;
        a[1] = b & 7;
        a[2] = func_021CCAD4(r);
        break;
    case 19:
        b = func_021CCAD4(r);
        a[0] = (b >> 3) & 0x1F;
        a[1] = b & 7;
        a[2] = func_021CCB18(r);
        break;
    case 35:
        h = func_021CCB18(r);
        a[0] = (h >> 10) & 0x1F;
        a[1] = (h >> 5) & 0x1F;
        a[2] = h & 0x1F;
        break;
    case 51:
        x = func_021CCB78(r);
        a[0] = (x >> 19) & 0x1F;
        a[1] = (x >> 14) & 0x1F;
        a[2] = x & 0x3FFF;
        break;
    case 67:
        a[0] = func_021CCAD4(r);
        a[1] = func_021CCAD4(r);
        a[2] = func_021CCB18(r);
        break;
    case 83:
        a[0] = func_021CCAD4(r);
        a[1] = func_021CCAD4(r);
        a[2] = func_021CCBE8(r);
        break;
    case 20:
        b = func_021CCAD4(r);
        a[0] = (b >> 3) & 0x1F;
        a[1] = b & 7;
        b = func_021CCAD4(r);
        a[2] = (b >> 3) & 0x1F;
        a[3] = b & 7;
        break;
    case 4:
        b = func_021CCAD4(r);
        a[0] = (b >> 3) & 0x1F;
        a[1] = b & 7;
        a[2] = func_021CCAD4(r);
        a[3] = func_021CCB18(r);
        break;
    case 36:
        x = func_021CCB78(r);
        a[0] = (x >> 19) & 0x1F;
        a[1] = (x >> 14) & 0x1F;
        a[2] = x & 0x3FFF;
        a[3] = func_021CCAD4(r);
        break;
    case 52:
        x = func_021CCB78(r);
        a[0] = (x >> 19) & 0x1F;
        a[1] = (x >> 14) & 0x1F;
        a[2] = x & 0x3FFF;
        a[3] = func_021CCB18(r);
        break;
    case 68:
        h = func_021CCB18(r);
        a[0] = (h >> 11) & 0x1F;
        a[1] = (h >> 6) & 0x1F;
        a[2] = h & 0x3F;
        a[3] = func_021CCB18(r);
        break;
    case 84:
        a[0] = func_021CCAD4(r);
        a[1] = func_021CCAD4(r);
        a[2] = func_021CCB18(r);
        a[3] = func_021CCB18(r);
        break;
    case 5:
        h = func_021CCB18(r);
        a[0] = (h >> 10) & 0x1F;
        a[1] = (h >> 5) & 0x1F;
        a[2] = h & 0x1F;
        a[3] = func_021CCB18(r);
        a[4] = func_021CCB18(r);
        break;
    case 21: {
        u32 hi = func_021CCB18(r);
        u32 lo = func_021CCB18(r);
        a[0] = ((u8)hi >> 3) & 0x1F;
        a[1] = (u8)hi & 7;
        a[2] = ((u8)lo >> 1) & 0x7F;
        a[3] = (u8)lo & 1;
        a[4] = func_021CCB18(r);
        break;
    }
    case 37:
        x = func_021CCAD4(r);
        a[0] = (x >> 5) & 7;
        a[1] = (x >> 2) & 7;
        a[2] = (x >> 1) & 1;
        a[3] = x & 1;
        a[4] = func_021CCB18(r);
        break;
    case 6: {
        u32 v0 = func_021CCB18(r);
        u32 v1 = func_021CCB18(r);
        a[0] = (v0 >> 10) & 0x1F;
        a[1] = (v0 >> 5) & 0x1F;
        a[2] = v0 & 0x1F;
        a[3] = (v1 >> 10) & 0x1F;
        a[4] = (v1 >> 5) & 0x1F;
        a[5] = v1 & 0x1F;
        break;
    }
    case 22:
        x = func_021CCAD4(r);
        a[0] = (x >> 5) & 7;
        a[1] = (x >> 3) & 3;
        a[2] = (x >> 2) & 1;
        a[3] = (x >> 1) & 1;
        a[4] = x & 1;
        a[5] = func_021CCB18(r);
        break;
    case 38:
        x = func_021CCB78(r);
        a[0] = (x >> 15) & 0x1F;
        a[1] = (x >> 10) & 0x1F;
        a[2] = (x >> 5) & 0x1F;
        a[3] = x & 0x1F;
        a[4] = func_021CCB18(r);
        a[5] = func_021CCB18(r);
        break;
    case 7:
        for (i = 0; i < 7; i++)
            a[i] = func_021CCAD4(r);
        break;
    case 8:
        for (i = 0; i < 8; i++)
            a[i] = func_021CCAD4(r);
        break;
    }
}
