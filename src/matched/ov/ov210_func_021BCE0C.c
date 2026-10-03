/*
 * function: func_021BCE0C
 * address: 0x021BCE0C
 * packet: pkt_ov210_021BCE0C
 * region: ov210
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0202CD64 0x0202CD64 thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed char s8;
typedef signed short s16;
typedef unsigned int u32;
struct WinMgr;
extern void func_0202CD64(struct WinMgr *mgr, u32 idx, s8 dx, s8 dy, u8 frames);
void func_021BCE0C(char *p, int delta)
{
    int magnitude;
    int direction;
    *(u16 *)(p + 0x2c8) = 48;
    *(s16 *)(p + 0x2ca) = delta;
    magnitude = delta < 0 ? -delta : delta;
    direction = delta / (delta < 0 ? -delta : delta);
    func_0202CD64(*(struct WinMgr **)(p + 0x20), 0, 0, direction, 48 / magnitude);
}
