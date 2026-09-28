/*
 * function: ov208_func_021C6AFC
 * address:  0x021C6AFC
 * packet:   pkt_ov208_021C6AFC
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   ov208_func_021C6E30  0x021C6E30  thumb
 *   ov208_func_021C6D6C  0x021C6D6C  thumb
 *   func_0204B404        0x0204B404  arm
 *   func_0204B3DC        0x0204B3DC  arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;

typedef struct {
    s16 x;
    s16 y;
} Ov208Pos;

extern u16  ov208_func_021C6E30(void *unused, u8 *p, int unused2, u16 skip, u16 stop);
extern void ov208_func_021C6D6C(int n, int i, u8 *lo, u8 *mid, u8 *hi);
extern void func_0204B404(u32 obj, Ov208Pos *pos, u16 flag);
extern void func_0204B3DC(u32 obj, int on);

void ov208_func_021C6AFC(void *a0, u8 *p, int a2)
{
    int on = 0;
    u16 n;
    u8 mid;
    Ov208Pos pos;

    switch (*(u32 *)(p + 0x6b8)) {
    case 0:
        break;
    case 4:
        if (*(u16 *)(p + 0x548) >= 3)
            on = 1;
        break;
    }
    if (on) {
        n = ov208_func_021C6E30(a0, p, a2, *(u16 *)(p + 0x54e), *(u16 *)(p + 0x550));
        ov208_func_021C6D6C((u16)(*(u16 *)(p + 0x548) - 1), n, 0, &mid, 0);
        pos.x = mid;
        pos.y = 0x30;
        func_0204B404(*(u32 *)(p + 0x5e8), &pos, 0);
        func_0204B3DC(*(u32 *)(p + 0x5e4), 1);
        func_0204B3DC(*(u32 *)(p + 0x5e8), 1);
        *(u32 *)(p + 0x698) = 0;
        *(u32 *)(p + 0x6d4) = 0;
        *(u32 *)(p + 0x69c) = 0;
    } else {
        func_0204B3DC(*(u32 *)(p + 0x5e4), 0);
        func_0204B3DC(*(u32 *)(p + 0x5e8), 0);
    }
}
