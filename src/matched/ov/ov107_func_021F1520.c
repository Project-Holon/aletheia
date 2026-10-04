/*
 * function: func_021F1520
 * address: 0x021F1520
 * packet: pkt_ov107_021F1520
 * region: ov107
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02194798 0x02194798 thumb ov021
 *   func_02027858 0x02027858 thumb
 *   func_0201FEF4 0x0201FEF4 thumb
 *   func_0202F038 0x0202F038 thumb
 *   func_02028604 0x02028604 thumb
 *   func_02027FD8 0x02027FD8 thumb
 *   func_0201C4C0 0x0201C4C0 thumb
 *   func_0201CE48 0x0201CE48 thumb
 *   func_02045808 0x02045808 arm
 *   func_021F18EC 0x021F18EC thumb ov107
 *   func_02045C04 0x02045C04 arm
 *   func_020452E8 0x020452E8 arm
 *   func_0201D83C 0x0201D83C thumb
 *   func_02031140 0x02031140 arm
 *   func_020307B0 0x020307B0 arm
 *   func_02034A5C 0x02034A5C arm
 *   ov021_id 0x00000015 data
 */
extern void func_02194798(void *);
extern void func_02027858(void *);
extern void func_0201FEF4(void *);
extern void func_0202F038(void *);
extern int func_02028604(int a0);
extern void func_02027FD8(void *);
extern void func_0201C4C0(void *);
extern void func_0201CE48(void *);
extern void func_02045808(void *);
extern void func_021F18EC(void *);
extern void func_02045C04(void *);
extern void func_020452E8(void *);
extern void func_0201D83C(void *);
extern void func_02031140(void *);
extern void func_020307B0(void *);
extern void func_02034A5C(int);
extern char ov021_id[];
#define P(k) (*(void **)(p+(k)))
void func_021F1520(char *p)
{
    if(P(0x54))func_02194798(P(0x54));
    if(P(0x3C))func_02027858(P(0x3C));
    if(P(0x50))func_0201FEF4(P(0x50));
    if(P(0x5C)){func_0202F038(P(0x5C));P(0x5C)=0;}
    func_02028604((int)P(0x44));func_02027FD8(P(0x40));func_0201C4C0(P(0x30));
    if(P(0x18))func_0201CE48(P(0x18));
    if(P(0x20))func_02045808(P(0x20));
    if(P(0x24))func_021F18EC(p);
    func_02045C04(P(0x1C));
    if(P(0x10))func_020452E8(P(0x10));
    func_0201D83C(P(0x14));func_02031140(P(0x0C));func_020307B0(p);func_02034A5C((int)ov021_id);
}
