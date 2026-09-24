/*
 * function: func_02201F18
 * address:  0x02201F18
 * packet:   pkt_02201F18
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021F9088  0x021F9088  thumb  ov135
 *
 * Maps the state word at +0x38 to one of fifteen codes (cases written in
 * descending order, which is the order MWCC lays the bodies out in) and
 * forwards to func_021F9088 with p, the +0xb6c word, the code, 1 and 0x0f0f.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;

extern u32 func_021F9088(u8 *p, u32 a, u32 b, u32 c, u32 d);

u32 func_02201F18(u8 *p)
{
    u32 v;

    switch (*(u32 *)(p + 0x38) + 15) {
    case 14:
        v = 0x9d;
        break;
    case 13:
        v = 0xa9;
        break;
    case 12:
        v = 0xa2;
        break;
    case 11:
        v = 0xa4;
        break;
    case 10:
        v = 0xa3;
        break;
    case 9:
        v = 0x1b;
        break;
    case 8:
        v = 0x1c;
        break;
    case 7:
        v = 0x1d;
        break;
    case 6:
        v = 0x1e;
        break;
    case 5:
        v = 0x1f;
        break;
    case 4:
        v = 0x20;
        break;
    case 3:
        v = 0xa0;
        break;
    case 2:
        v = 0xa5;
        break;
    case 1:
        v = 0xaa;
        break;
    case 0:
        v = 0xa1;
        break;
    default:
        v = 0x9f;
        break;
    }
    return func_021F9088(p, *(u32 *)(p + 0xb6c), v, 1, 0x0f0f);
}
