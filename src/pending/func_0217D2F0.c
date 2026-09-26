/*
 * function: func_0217D2F0
 * address:  0x0217D2F0
 * packet:   pkt_0217D2F0
 * region:   ov176
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 *
 * blocker:  byte-correct, but the calls to func_0200BAC8 and func_0201A918
 *           have no witness outside this range. Both are unlabelled Thumb
 *           leaf code in arm9 that disasm.py emitted as `.word` runs
 *           (0200BAC8 is inside a `0x21314B01` word block, 0201A918 inside a
 *           `0x47704800` word block), so they are neither `label` nor
 *           `sole-ref/code` (not a traced func_ start) and no SDK symbol
 *           exists. Nothing to cut: both call sites are inside this function.
 *
 * symbols:
 *   func_02012944  0x02012944  thumb
 *   func_02008468  0x02008468  thumb
 *   func_02082D44  0x02082D44  arm
 *   func_02087C6C  0x02087C6C  arm
 *   func_02012EBC  0x02012EBC  thumb
 *   func_0200E6E8  0x0200E6E8  thumb
 *   func_0200E6FC  0x0200E6FC  thumb
 *   func_0200BAC8  0x0200BAC8  thumb
 *   func_0200BAF4  0x0200BAF4  thumb
 *   func_0201A918  0x0201A918  thumb
 *   func_020307B0  0x020307B0  arm
 *   func_0200E918  0x0200E918  thumb
 *   func_0200B078  0x0200B078  thumb
 *   ov067_id       0x00000043  data
 */
typedef unsigned char u8;
typedef unsigned int u32;

extern u32 func_02012944(void *p);
extern u32 func_02008468(void);
extern void func_02082D44(u32 a, void *p, u32 b);
extern void func_02087C6C(void *p);
extern u32 func_02012EBC(void *p);
extern u32 func_0200E6E8(u32 a);
extern void func_0200E6FC(u32 a, int b, void *p);
extern u32 func_0200BAC8(u32 a);
extern u32 func_0200BAF4(u32 a, int b);
extern u32 func_0201A918(void);
extern void func_020307B0(void *p);
extern u32 func_0200E918(u32 a, int b);
extern u32 func_0200B078(u32 a, int b);

void func_0217D2F0(u8 *p, u8 *q)
{
    u8 *r = *(u8 **)(q + 0x1b8);
    u32 x;
    u32 a;

    *(u32 *)(p + 0x44) = 0x64;
    x = func_02012944(r);
    func_02082D44(x, p, func_02008468());
    func_02087C6C(p + 0x20);
    func_0200E6FC(func_0200E6E8(func_02012EBC(r)), 0, p + 0x38);
    a = func_0200BAF4(func_0200BAC8(func_02012EBC(r)), 0x8056);
    func_02082D44(a, p + 0xd4, func_0201A918());
    func_020307B0((void *)a);
    *(u32 *)(p + 0x28) = func_0200E918(*(u32 *)(q + 0x34), 1);
    *(u32 *)(p + 0x2c) = func_0200E918(*(u32 *)(q + 0x34), 2);
    *(u32 *)(p + 0x30) = func_0200E918(*(u32 *)(q + 0x34), 0);
    *(u32 *)(p + 0x40) = func_0200B078(*(u32 *)(q + 0x38), 2);
}




