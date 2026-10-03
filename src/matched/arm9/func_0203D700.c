/*
 * function: func_0203D700
 * address:  0x0203D700
 * packet:   pkt_0203D578
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Calls the net context's +0x30 callback with its +0x34c argument.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203D700.c \
 *       --func func_0203D700 --addr 0x0203D700 --arm --cc 1.1p1
 */

typedef unsigned char u8;
typedef unsigned int  u32;

extern void *func_0203D788(void);

void func_0203D700(void)
{
    u8 *p = func_0203D788();

    if (*(u32 *)(p + 0x30) != 0) {
        ((void (*)(u32)) * (u32 *)(p + 0x30))(*(u32 *)(p + 0x34c));
    }
}
