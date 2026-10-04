/*
 * function: func_021BF208
 * address: 0x021BF208
 * packet: pkt_ov110_021BF208
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021BEDD0 0x021BEDD0 thumb ov110
 *   func_021BF338 0x021BF338 thumb ov110
 *   func_021BF360 0x021BF360 thumb ov110
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u32 func_021BEDD0(u8 *);
extern u32 func_021BF338(u8 *);
extern u32 func_021BF360(u8 *);
u32 func_021BF208(u8 *p, u32 keys)
{
    u32 r;
    if (keys & 0x80) {
        if (*(u16 *)(p + 0xC) != 0)
            return 4;
        if (p[7] < 5) {
            p[7]++;
            r = func_021BEDD0(p);
            if (r < (u32)*(u16 *)(p + 4) - 2)
                return 1;
            if (r == (u32)*(u16 *)(p + 4) - 2) {
                if (r & 1) {
                    p[6] = 0;
                    return 1;
                }
                p[7]--;
                return 4;
            }
            p[7]--;
            return 4;
        }
        if (*(u16 *)p < *(u16 *)(p + 2)) {
            *(u32 *)(p + 8) = 1;
            *(u16 *)p = *(u16 *)p + 1;
            r = func_021BEDD0(p);
            if (r < (u32)*(u16 *)(p + 4) - 2)
                return 2;
            p[6] = 0;
            return 3;
        }
        return 4;
    }
    if (keys & 0x40) {
        if (*(u16 *)(p + 0xC) != 0) {
            *(u16 *)(p + 0xC) = 0;
            return 1;
        }
        if (p[7] != 0) {
            p[7]--;
            return 1;
        }
        if (*(u16 *)p != 0) {
            *(int *)(p + 8) = -1;
            *(u16 *)p = *(u16 *)p - 1;
            return 2;
        }
        return 4;
    }
    if (keys & 0x20) {
        if (p[6] == 1) {
            p[6] ^= 1;
            r = func_021BEDD0(p);
            if (r < (u32)*(u16 *)(p + 4) - 2)
                return 1;
            p[6] ^= 1;
        }
        return 4;
    }
    if (keys & 0x10) {
        if (p[6] == 0) {
            p[6] ^= 1;
            r = func_021BEDD0(p);
            if (r < (u32)*(u16 *)(p + 4) - 2)
                return 1;
            p[6] ^= 1;
        }
        return 4;
    }
    if (keys & 0x200)
        return func_021BF338(p);
    if (keys & 0x100)
        return func_021BF360(p);
    return 0;
}
