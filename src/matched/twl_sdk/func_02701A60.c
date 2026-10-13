/*
 * function: CameraSendPxiData
 * address:  0x02701A60
 * packet:   twl_sys
 * region:   twl
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_02088610  0x02088610  arm twl a2
 */

typedef unsigned int u32;
typedef signed int s32;
typedef unsigned short u16;
typedef unsigned char u8;
typedef void (*CamPxiCallback)(u32 result, u32 arg);
extern int func_02088610(u32, u32, u32);

void CameraSendPxiData(const u8 *ptr) {
    u32 word = (ptr[0] << 16) | (ptr[1] << 8) | ptr[2];
    do {
    } while (func_02088610(0x15, word, 0) < 0);
}
