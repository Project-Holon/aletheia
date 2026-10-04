/*
 * function: func_021F9218
 * address:  0x021F9218
 * packet:   pkt_021F9218
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02045EC0  0x02045EC0  arm
 *   func_02045808  0x02045808  arm
 *   func_021F91A0  0x021F91A0  thumb
 *   tbl_022031EC   0x022031EC  data
 */

typedef signed char s8;
typedef signed short s16;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern const u32 tbl_022031EC[];

struct MsgBank;
struct U16Vec;
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void func_02045808(struct U16Vec *vec);
extern int func_021F91A0(u8 *p, u32 b, u32 c, u32 d, u32 e, u16 f, u32 g);

void func_021F9218(void *win, void *bank, int idx, void *g)
{
    void *str;

    str = func_02045EC0(bank, tbl_022031EC[idx]);
    func_021F91A0(win, (u32)str, 0, 0, 0, 0x440, (u32)g);
    func_02045808(str);
}
