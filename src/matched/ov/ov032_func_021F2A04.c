/*
 * function: func_021F2A04
 * address:  0x021F2A04
 * packet:   pkt_ov032_021F2A04
 * region:   ov032
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021F2A04 0x021F2A04 thumb
 *   func_02045808 0x02045808 arm
 *   func_02045C04 0x02045C04 arm
 *   func_0201ED04 0x0201ED04 thumb
 *   func_0201C6EC 0x0201C6EC thumb
 *   func_0201C4C0 0x0201C4C0 thumb
 *   func_0201DD68 0x0201DD68 thumb
 *   func_020215A0 0x020215A0 thumb
 *   func_02021540 0x02021540 thumb
 *   func_02030EAC 0x02030EAC arm
 *   func_02031140 0x02031140 arm
 */

extern void func_02045808(int);
extern void func_02045C04(int);
extern void func_0201ED04(int);
extern void func_0201C6EC(int);
extern void func_0201C4C0(int);
extern void func_0201DD68(void);
extern void func_020215A0(int, int);
extern void func_02021540(int);
extern void func_02030EAC(int);
extern void func_02031140(int);

void func_021F2A04(char *p)
{
    func_02045808(*(int *)(p + 0x120));
    func_02045808(*(int *)(p + 0x11c));
    func_02045808(*(int *)(p + 0x118));
    func_02045C04(*(int *)(p + 0x114));
    func_0201ED04(*(int *)(p + 0x110));
    func_0201C6EC(*(int *)(p + 0xb4));
    func_0201C4C0(*(int *)(p + 0xb4));
    func_0201DD68();
    func_020215A0(*(int *)(p + 0xac), 3);
    func_020215A0(*(int *)(p + 0xac), 1);
    func_02021540(*(int *)(p + 0xac));
    *(int *)(p + 0xac) = 0;
    func_02030EAC(*(int *)(p + 0xa4));
    func_02031140(*(int *)(p + 0xa0));
}
