/*
 * function: func_021DCC88
 * address: 0x021DCC88
 * packet: pkt_ov171_021DCC88
 * region: ov171
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02045808 0x02045808 arm
 *   func_0201C4C0 0x0201C4C0 thumb
 *   func_0201ED04 0x0201ED04 thumb
 *   func_0201D83C 0x0201D83C thumb
 *   func_02045C04 0x02045C04 arm
 */
extern void func_02045808(void *);
extern void func_0201C4C0(void *);
extern void func_0201ED04(void *);
extern void func_0201D83C(void *);
extern void func_02045C04(void *);
#define PTR(p,n) (*(void **)((p)+(n)))
void func_021DCC88(char *p)
{
    func_02045808(PTR(p,0xb68));
    func_0201C4C0(PTR(p,0xb6c));
    func_0201ED04(PTR(p,0xb64));
    func_0201D83C(PTR(p,0xb5c));
    func_0201D83C(PTR(p,0xb58));
    func_02045C04(PTR(p,0xb60));
}
