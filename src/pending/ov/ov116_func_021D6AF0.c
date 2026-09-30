/*
 * function: func_021D6AF0
 * address: 0x021D6AF0
 * packet: pkt_ov116_021D6AF0
 * region: ov116
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: MATCH
 * blocker: ARM9 0x0200DD28 has no outside code witness. Blocker C attempted
 * in scratch blocker-DD28.c; best run DD28-r3.log is DIFF (102 bytes vs 100).
 * The existing ARM9 unit_0200DD10.c also records this function's near miss.
 * blocker: 0x0200DD28 best attempted C below is DIFF, not verified EXACT:
 *   typedef unsigned char B_u8;
 *   typedef unsigned short B_u16;
 *   typedef unsigned int B_u32;
 *   void func_0200DD28(B_u8 *p,B_u32 a,B_u32 b,B_u32 *date) {
 *       B_u16 slot; B_u8 mask=1; B_u8 bit;
 *       if(b != 0 && b <= 200 && a != 0 && a <= 10) {
 *           slot=(b-1)+(a-1)*200; bit=slot%8; mask=mask<<bit;
 *           (p+4)[(B_u8)(slot/8)] |= mask;
 *           *(B_u32 *)p=(date[0]<<24)|((date[1]<<24)>>8)
 *                       |((date[2]<<24)>>16)|date[3];
 *       }
 *   }
 * symbols:
 *   func_02167ED8 0x02167ED8 arm ov009
 *   func_0200DD28 0x0200DD28 thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int func_02167ED8(void *, void *);
extern void func_0200DE6C(void *, const void *, u8, u8);
extern void func_0200DD28(void *, u8, u8, void *);
void func_021D6AF0(u8 *p, void *q) {
    u32 time[3];
    u32 date[4];
    func_02167ED8(date, time);
    func_0200DE6C(q, p + 14, *(u16 *)(p + 8), *(u16 *)(p + 10));
    func_0200DD28(q, *(u16 *)(p + 8), *(u16 *)(p + 10), date);
}
