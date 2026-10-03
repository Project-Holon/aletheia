/*
 * function: func_021DE114
 * address: 0x021DE114
 * packet: pkt_ov171_021DE114
 * region: ov171
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   d_021DEB88 0x021DEB88 data a4
 *   func_021DC924 0x021DC924 thumb ov171
 *   func_0204A48C 0x0204A48C arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
struct Cfg {u8 pad_00[8];u8 unk_08,unk_09,unk_0a,unk_0b;u32 unk_0c;u16 unk_10,unk_12,unk_14,unk_16,unk_18,unk_1a;};
extern const struct Cfg d_021DEB88;
extern u32 func_021DC924(void);
extern void func_0204A48C(const struct Cfg *,u32,u32);
void func_021DE114(u8 *p)
{
    struct Cfg cfg=d_021DEB88;
    func_0204A48C(&cfg,func_021DC924(),140);
}
