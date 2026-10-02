/*
 * function: func_021BCF68
 * address: 0x021BCF68
 * packet: pkt_ov217_021BCF68
 * region: ov217
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * symbols:
 *   func_0204B100 0x0204B100 arm
 *   d_021C305C 0x021C305C data a1
 *   d_021C3060 0x021C3060 data a2
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct S { char pad0[8]; u16 h8; char pad[0x10a]; int arr[3]; };
extern const u8 d_021C305C[];
extern const u16 d_021C3060[];
extern int func_0204B100(int a, u8 b, u32 c);

void func_021BCF68(struct S *p)
{
    int i;
    for (i = 0; i < 3; i++) {
        p->arr[i] = func_0204B100(d_021C3060[i], d_021C305C[i], p->h8);
    }
}
