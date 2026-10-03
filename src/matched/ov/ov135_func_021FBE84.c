/*
 * function: func_021FBE84
 * address:  0x021FBE84
 * packet:   pkt_021FBE84
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02045EC0  0x02045EC0  arm
 *   func_021FAC50  0x021FAC50  thumb
 *   func_02045808  0x02045808  arm
 */

typedef signed char s8;
typedef signed short s16;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct MsgBank;
struct U16Vec;
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void func_021FAC50(void *mgr, void *win, void *str, u32 x, u16 color, void *g);
extern void func_02045808(struct U16Vec *vec);

void func_021FBE84(void *mgr, void *bank, void *win, u32 index, u32 x, u16 color, void *g)
{
    void *str = func_02045EC0(bank, index);

    func_021FAC50(mgr, win, str, x, color, g);
    func_02045808(str);
}
