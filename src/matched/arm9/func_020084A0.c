/*
 * unit:     no
 * function: func_020084A0
 * address:  0x020084A0
 * packet:   pkt_0200846C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 */

typedef unsigned char u8;
typedef unsigned int u32;

struct Sub0200852CObj {
    u32 unk00;
    u32 unk04;
    u32 unk08;
    u32 unk0C;
    u32 unk10;
    u32 unk14;
    u8 unk18;
    u8 unk19;
    u8 unk1A;
    u8 unk1B;
    u8 unk1C;
    u8 unk1D;
};

extern void func_02082BCC(void *dst, u8 value, u32 size);
extern void func_02008560(struct Sub0200852CObj *obj, u8 value);

void func_020084A0(struct Sub0200852CObj *obj)
{
    func_02082BCC(obj, 0, 0x20);
    obj->unk1A = 2;
    func_02008560(obj, 0x15);
}
