/*
 * function: func_0203D754
 * address:  0x0203D754
 * packet:   pkt_0203D578
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Calls the net context's +0x24 callback with the func_020399A8 result,
 * the argument and the context's +0x34c value.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203D754.c \
 *       --func func_0203D754 --addr 0x0203D754 --arm --cc 1.1p1
 */

typedef unsigned char u8;
typedef unsigned int  u32;

extern void *func_0203D788(void);
struct Entry;
extern struct Entry *func_020399A8(void);

void func_0203D754(u32 a)
{
    u8 *p = func_0203D788();

    if (*(u32 *)(p + 0x24) == 0) {
        return;
    }
    ((void (*)(u32, u32, u32)) * (u32 *)(p + 0x24))(
        (u32)func_020399A8(), a, *(u32 *)(p + 0x34c));
}
