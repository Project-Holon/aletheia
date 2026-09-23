/*
 * function: func_0202F1B4
 * address:  0x0202F1B4
 * packet:   pkt_0202F1B4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * note:     time_icon.c seven-way mode switch around a func_02017DBC /
 *           func_02017DE4 bracket.  Closed in wave 16: the 129-byte residue
 *           of docs/notes/func_0202F1B4.c.txt was NOT an allocator tie but
 *           the source's gotos.  Every case is written out in full (no
 *           shared labels) and case 2's guard carries the call run in BOTH
 *           arms; 1.1p1's own cross-jumping then produces the image's
 *           `b` into case 0's func_0202F464/func_0202F47C tail, the kept
 *           `bne; b` pair in case 2, and the head that spills the selector
 *           and holds the fifth parameter in r7.  The call at +0x58 is
 *           attested by src/matched/func_0202F47C.c (same shard).
 *           0x7532 is a plain constant.
 * symbols:
 *   func_02017DBC  0x02017DBC  thumb
 *   func_02017DE4  0x02017DE4  thumb
 *   func_02018488  0x02018488  thumb
 *   func_0202F2F4  0x0202F2F4  thumb
 *   func_0202F30C  0x0202F30C  thumb
 *   func_0202F3AC  0x0202F3AC  thumb
 *   func_0202F41C  0x0202F41C  thumb
 *   func_0202F464  0x0202F464  thumb
 *   func_0202F47C  0x0202F47C  thumb
 */
typedef unsigned int u32;
extern u32  func_02017DBC(u32 a);
extern void func_02017DE4(u32 a, u32 h);
extern u32  func_02018488(u32 a, u32 c);
extern void func_0202F2F4(u32 a, u32 x);
extern void func_0202F30C(u32 a, u32 x, u32 y);
extern void func_0202F3AC(u32 a, u32 x);
extern void func_0202F41C(u32 a, u32 c, u32 e);
extern void func_0202F464(u32 a);
extern void func_0202F47C(u32 a);
void func_0202F1B4(u32 a, u32 b, u32 c, u32 d, u32 e)
{
    u32 h = func_02017DBC(a);

    switch (b) {
    case 0:
        func_0202F2F4(a, 0);
        func_0202F30C(a, d, 1);
        func_0202F41C(a, c, e);
        func_0202F464(a);
        func_0202F47C(a);
        break;
    case 1:
        func_0202F30C(a, 0x7532, 1);
        func_0202F464(a);
        func_0202F47C(a);
        break;
    case 2:
        if (func_02018488(a, c) == 1) {
            func_0202F30C(a, d, 1);
            func_0202F41C(a, c, e);
        } else {
            func_0202F3AC(a, 1);
            func_0202F30C(a, d, 1);
            func_0202F41C(a, c, e);
        }
        func_0202F47C(a);
        break;
    case 3:
    case 4:
        break;
    case 5:
        func_0202F30C(a, d, 0);
        func_0202F41C(a, c, e);
        func_0202F47C(a);
        break;
    case 6:
        func_0202F30C(a, d, 1);
        break;
    }
    func_02017DE4(a, h);
}
