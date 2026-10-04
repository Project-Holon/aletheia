/*
 * function: func_021BC8E4
 * address: 0x021BC8E4
 * packet: pkt_ov217_021BC8E4
 * region: ov217
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * symbols:
 *   func_02045B38 0x02045B38 arm
 *   d_021C3078 0x021C3078 data a4
 */
typedef unsigned short u16;
struct S { char pad0[8]; u16 h8; char pad[6]; int arr[2]; };
extern const unsigned int d_021C3078[];
typedef unsigned int   u32;
struct MsgBank;
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);

void func_021BC8E4(struct S *p)
{
    int i;
    for (i = 0; i < 2; i++) {
        p->arr[i] = (int)func_02045B38(0, 2, (u16)d_021C3078[i], p->h8);
    }
}
