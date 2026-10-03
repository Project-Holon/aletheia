/*
 * function: func_02028B50
 * address:  0x02028B50
 * packet:   pkt_02028B50
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Both halfword cells the caller clears sit in ONE struct, four bytes apart
 * (0xac and 0xb0), and the same index reaches both.  Spelled as two
 * independent `u16 *` locals the compiler recomputes the second address from
 * `idx + 1` and the frame loses two bytes; as two adjacent u16[2] fields of
 * one struct both accesses share the scaled index register and the function
 * is EXACT.
 *
 * symbols:
 *   func_02006148  0x02006148  thumb
 *   func_020061F8  0x020061F8  thumb
 *   func_021D21C0  0x021D21C0  thumb ov021
 *   func_021D21E0  0x021D21E0  thumb ov021
 */
typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
extern int func_02006148(u32 a0);
extern void func_020061F8(int i);
extern int func_021D21C0(u32 id);
extern int func_021D21E0(u32 id);
struct S { u8 pad[0xac]; u16 lo[2]; u16 hi[2]; };
void func_02028B50(u8 *p, int a0)
{
    u32 idx;
    struct S *s = (struct S *)p;
    idx = func_02006148(a0);
    if (func_021D21C0(a0) == 0) {
        func_020061F8(idx);
        return;
    }
    if (func_021D21E0(a0) != 0) {
        if (a0 == s->lo[idx - 1]) {
            s->lo[idx - 1] = 0xffff;
            s->hi[idx - 1] = 0xffff;
        }
    }
    func_020061F8(idx);
}
