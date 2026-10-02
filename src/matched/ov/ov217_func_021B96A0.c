/*
 * function: func_021B96A0
 * address:  0x021B96A0
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0201058C  0x0201058C  thumb
 *   func_020120F4  0x020120F4  thumb
 *   func_020121CC  0x020121CC  thumb
 *   func_0201283C  0x0201283C  thumb
 *
 * Flushes the +4 handle through three sub-calls, then raises event 1 with
 * the record's leading halfword when the fourth sub-call reports busy.
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

extern u32 func_0201058C(void *key);
extern void *func_020120F4(void *p);
extern u32 func_020121CC();
extern u32 func_0201283C(const void *p);
extern u32 func_0203D34C();
void func_021B96A0(u32 a0)
{
    func_0201058C((void *)func_0201283C(func_020120F4(*(void **)(((u8*)a0) + 4))));
    if (func_020121CC(*(u32*)(((u8*)a0) + 4)) != 0) {
    func_0203D34C(1, *(u16*)(((u8*)a0)));
    }
}
