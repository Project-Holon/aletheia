/*
 * function: func_022026A0
 * address:  0x022026A0
 * packet:   pkt_022026A0
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0220262C  0x0220262C  thumb  ov135

 * Create the 0x48 sub-object, register the handle and hand it to the callback.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
struct Mon;
extern void *func_0201747C(struct Mon *p, u32 heap);
extern void func_0220262C(u32 h, u32 k);
extern void func_020307B0(void *p);

void func_022026A0(u8 *p, u32 k)
{
    u32 h = (u32)func_0201747C((struct Mon *)p, 0x48);

    func_0220262C(h, k);
    func_020307B0((void *)h);
}
