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
#include "../include/Obj06560.h"
typedef unsigned char u8;
typedef unsigned int u32;
struct Entry;
extern struct Entry *func_020399A8(void);
extern u32 func_0203D3F8(u32, u32, u32, u32, u32, u32, u32, u32);
u32 func_021B8A14(int unused, char *q)
{
    u32 entry, result;
    u8 available, write, read;
    entry = (u32)func_020399A8();
    write = ((struct Obj06560 *)q)->f1AC;
    read = ((struct Obj06560 *)q)->f1AD;
    if (read > write) available = 64 - read;
    else available = write - read;
    if (available > 8) available = 8;
    if (available != 0) {
        result = func_0203D3F8(entry, 255, 0x2002, available * 8, (u32)(q + 0x1ae + read * 8), 1, 1, 0);
        if (result != 0) {
            ((struct Obj06560 *)q)->f1AD += available;
            if (((struct Obj06560 *)q)->f1AD >= 64) ((struct Obj06560 *)q)->f1AD -= 64;
        }
        return result;
    }
    return 1;
}
