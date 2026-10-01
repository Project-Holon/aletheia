/*
 * function: func_021B8A14
 * address: 0x021B8A14
 * packet: pkt_ov172_021B8A14
 * region: ov172
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020399A8 0x020399A8 arm
 *   func_0203D3F8 0x0203D3F8 arm
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern u32 func_020399A8(void);
extern u32 func_0203D3F8(u32, u32, u32, u32, u32, u32, u32, u32);
u32 func_021B8A14(int unused, char *q)
{
    u32 entry, result;
    u8 available, write, read;
    entry = func_020399A8();
    write = *(u8 *)(q + 0x1ac);
    read = *(u8 *)(q + 0x1ad);
    if (read > write) available = 64 - read;
    else available = write - read;
    if (available > 8) available = 8;
    if (available != 0) {
        result = func_0203D3F8(entry, 255, 0x2002, available * 8, (u32)(q + 0x1ae + read * 8), 1, 1, 0);
        if (result != 0) {
            *(u8 *)(q + 0x1ad) += available;
            if (*(u8 *)(q + 0x1ad) >= 64) *(u8 *)(q + 0x1ad) -= 64;
        }
        return result;
    }
    return 1;
}
