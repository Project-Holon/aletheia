/*
 * function: func_021F4E30
 * address:  0x021F4E30
 * packet:   pkt_021F4E30
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
  *
  *
  *
  *
  *
 * symbols:
 *   func_021F5060  0x021F5060  thumb
 */

typedef signed char s8;
typedef signed short s16;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;

extern void func_02027974(void *m);
extern u32 func_020279E8(void *m);
extern u8 func_02027A04(void *m);
extern void func_021F5060(void);

u32 func_021F4E30(u8 *p)
{
    u32 r = (u32)-1;

    if (*(void **)(p + 0xE08) != 0) {
        func_02027974(*(void **)(p + 0xE08));
        if (func_020279E8(*(void **)(p + 0xE08)) != 0) {
            r = func_02027A04(*(void **)(p + 0xE08)) + 1;
            func_021F5060();
        }
    }
    return r;
}
