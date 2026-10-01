/*
 * function: func_021DE940
 * address: 0x021DE940
 * packet: pkt_ov183_021DE940
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   d_021E3534 0x021E3534 data a4
 *   func_021FD860 0x021FD860 thumb ov186
 *   func_020061E4 0x020061E4 thumb
 */
typedef unsigned int u32;
typedef struct Rect { u32 x0, y0, x1, y1; } Rect;
extern const Rect d_021E3534[];
extern void func_021FD860(int, int, int *);
extern void func_020061E4(int);
int func_021DE940(char *p, int x, int y)
{
    int skip = *(int *)(p + 0x68);
    int i;
    for (i = 0; i < 4; i++) {
        if (i != skip && (u32)(x - d_021E3534[i].x0) <= d_021E3534[i].x1 - d_021E3534[i].x0 &&
            (u32)(y - d_021E3534[i].y0) <= d_021E3534[i].y1 - d_021E3534[i].y0) {
            int args[2];
            args[0] = x;
            args[1] = y;
            func_021FD860(*(int *)(p + 0x64), 1, args);
            func_020061E4(0x703);
            return i;
        }
    }
    return 0;
}
