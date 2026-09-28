/*
 * Part of a translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/000_02004000.s.
 *
 * unit:     yes
 * address:  0x02005C4C
 * packet:   pkt_02005924
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: sub_02005C4C, sub_02005C64, sub_02005C8C
 *
 * symbols:
 *   sub_02005C4C_State  0x020AA260  data
 *   sub_02005C64_Obj    0x020AA354  data
 *   sub_020058D0        0x020058D0  thumb
 *   func_0208574C       0x0208574C  arm
 *
 * Three predicates.  sub_02005C8C carries no label, because it saves
 * nothing: it reads the DS interrupt enable register at 0x04000210 and
 * reports one bit of it.  0x04000210 reaches the literal pool as a plain
 * constant with no relocation, while the mask 0x80000 does not reach the
 * pool at all: `movs r0, #2` and `lsls r0, r0, #0x12` is two halfwords
 * against the four bytes a pool word plus its `ldr` would cost, so any
 * constant that is a small value shifted left is built rather than loaded.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Sub02005C4CState {
    u32 unk00;
    u32 unk04;
    u32 unk08;
    u32 unk0C;
    u32 unk10;
    u32 unk14;
    u32 unk18;
    u32 unk1C;
    u32 unk20;
    u32 unk24;
    u32 unk28;
};

extern struct Sub02005C4CState sub_02005C4C_State;
extern u8 sub_02005C64_Obj[];

extern u16 sub_020058D0(void);
extern int func_0208574C(u8 *obj);

u32 sub_02005C4C(void)
{
    if (sub_02005C4C_State.unk1C == 0) {
        return sub_020058D0();
    }
    return sub_02005C4C_State.unk28;
}

int sub_02005C64(void)
{
    if (sub_02005C4C_State.unk14 == 0) {
        return 0;
    }
    if (func_0208574C(sub_02005C64_Obj) != 0) {
        return 0;
    }
    return 1;
}

int sub_02005C8C(void)
{
    if (*(volatile u32 *)0x04000210 & 0x80000) {
        return 1;
    }
    return 0;
}
