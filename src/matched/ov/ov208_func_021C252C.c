/*
 * function: ov208_func_021C252C
 * address:  0x021C252C
 * packet:   pkt_ov208_021C252C
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0204B688  0x0204B688  arm
 *   ov208_func_021BC518  0x021BC518  thumb  ov208
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef int            s32;

struct Actor;
extern void func_0204B688(struct Actor *actor, u32 value);
extern void ov208_func_021BC518(u32 blend);

void ov208_func_021C252C(u16 *heap, u8 *p, int key)
{
    u8 i;

    for (i = 0; i < 2; i++) {
        if (((u32 *)(p + 0x5c))[i] != 0)
            func_0204B688((struct Actor *)(((u32 *)(p + 0x5c))[i]), 1);
    }
    ov208_func_021BC518(*(u32 *)(p + 0x41c));
}
