/*
 * function: func_021D2F44
 * address:  0x021D2F44
 * packet:   pkt_ov021_021D2F44
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 *
 * Blocked: func_021F37B8 is a Thumb call into the 0x021F window, where 32
 * overlays overlap and none is attested as the one loaded beside ov021.
 *
 * symbols:
 *   func_0215897C  0x0215897C  thumb  ov010
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_021F37B8  0x021F37B8  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u32 func_0215A5F4(u32 a);
extern u32 func_0215A5DC(u32 a);
extern void *func_021F37B8(u32 a);
extern void func_0215897C(u32, void *);

int func_021D2F44(u32 a, u32 b)
{
    u32 x = func_0215A5F4(b);
    void *t = func_021F37B8(func_0215A5DC(b));

    if (t == 0) {
        return 1;
    }
    func_0215897C(x, t);
    return 1;
}
