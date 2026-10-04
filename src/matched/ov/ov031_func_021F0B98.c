/*
 * function: func_021F0B98
 * address:  0x021F0B98
 * packet:   pkt_ov031_021F0B98
 * region:   ov031
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021F0B98  0x021F0B98  thumb
 *   func_02035CB8  0x02035CB8  arm
 *   func_0204B454  0x0204B454  arm
 *   func_02035C60  0x02035C60  arm
 *   func_0204B404  0x0204B404  arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;

extern u32 func_02035CB8(u32 *outA, u32 *outB);
struct Actor;
struct PtS;
extern void func_0204B454(struct Actor *, struct PtS *, unsigned int);
extern int func_02035C60(void);
extern void func_0204B404(int, void *, int);

int func_021F0B98(char *o)
{
    s16 buf[2];
    u32 x;
    u32 y;
    int r;

    if (func_02035CB8(&x, &y) == 0)
        return 0;
    r = 1;
    func_0204B454((struct Actor *)*(int *)(o + 0x2C), (struct PtS *)buf, 1);
    if (*(u8 *)(o + 0x31) == 0) {
        if (func_02035C60() == 0)
            return 0;
        if ((u32)(buf[0] - 0xB) <= x && (u32)(buf[0] + 0xB) >= x &&
            (u32)(buf[1] - 0xB) <= y && (u32)(buf[1] + 0xB) >= y)
            return r;
    } else {
        if (y < 0x1C)
            y = 0x1C;
        else if (y > 0x9C)
            y = 0x9C;
        buf[1] = y;
        func_0204B404(*(int *)(o + 0x2C), buf, 1);
        return 1;
    }
    return 0;
}
