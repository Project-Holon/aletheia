/*
 * function: func_021E0BA4
 * address: 0x021E0BA4
 * packet: pkt_ov119_021E0BA4
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GFL_NET_HANDLE_GetCurrentHandle 0x020399A8 arm
 *   func_02039C68 0x02039C68 arm
 *   func_021D8E84 0x021D8E84 thumb ov119
 *   func_021E0BC4 0x021E0BC4 thumb ov119
 */
struct Entry;
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
struct Link;
extern void func_02039C68(struct Link *, unsigned, unsigned);
extern void func_021D8E84(void *, int);
extern void func_021E0BC4(void *);
void func_021E0BA4(void *p)
{
    func_02039C68((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(), 0x18, 8);
    func_021D8E84(p, (int)func_021E0BC4);
}
