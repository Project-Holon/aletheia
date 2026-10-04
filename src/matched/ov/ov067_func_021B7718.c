/*
 * function: func_021B7718
 * address:  0x021B7718
 * packet:   pkt_ov067_021B7718
 * region:   ov067
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * The handed 596-byte extent also holds the unlabelled follower
 * 0x021B7754 (filed separately).
 *
 * symbols:
 *   func_02061CA4  0x02061CA4  arm
 */

typedef unsigned int u32;

typedef signed int     s32;
extern s32 func_02061CA4(void *p, u32 a, u32 b, s32 size);

void func_021B7718(int which, int idx, void *data)
{
    int type;

    switch (which) {
    case 0:
        type = 0xf;
        break;
    case 1:
        type = 0xe;
        break;
    case 4:
        type = 0x1f;
        break;
    case 5:
        type = 0x1e;
        break;
    case 2:
    case 3:
        return;
    default:
        return;
    }
    func_02061CA4((void *)type, idx << 5, (u32)data, 0x20);
}
