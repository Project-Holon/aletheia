/*
 * function: func_021D87E0
 * address: 0x021D87E0
 * packet: pkt_ov131_021D87E0
 * region: ov131
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02030734 0x02030734 arm
 *   func_02045B38 0x02045B38 arm
 *   d_021DC834 0x021DC834 data a1
 */
typedef unsigned short u16;
typedef unsigned int u32;
struct MsgBank;
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern const char d_021DC834[];
struct S { u32 a; u32 pad[19]; void *f50; u32 pad2[3]; unsigned char b60; };
void *func_021D87E0(u16 *a) {
 struct S *p = func_02030734(*a, 0x3b8, 0, d_021DC834, 0xaf);
 p->a = 0;
 p->b60 = 0;
 p->f50 = func_02045B38(0, 2, 0xaa, *a);
 return p;
}
