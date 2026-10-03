/*
 * function: func_021C5E30
 * address:  0x021C5E30
 * packet:   pkt_ov136_021C5E30
 * region:   ov136
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021C5E30 0x021C5E30 thumb
 *   func_0202DC08 0x0202DC08 thumb
 *   func_0201C4C0 0x0201C4C0 thumb
 *   func_0204B1CC 0x0204B1CC arm
 */
typedef unsigned char u8;
struct Bank;
struct Obj;
struct PrintSys;
extern void func_0202DC08(struct Obj *p);
extern void func_0201C4C0(struct PrintSys *p);
extern void func_0204B1CC(struct Bank *bank);
void func_021C5E30(u8 *p)
{
    func_0202DC08(*(void **)(*(u8 **)(p + 8) + 0x35C));
    func_0201C4C0(*(void **)(*(u8 **)(p + 8) + 0x36C));
    func_0204B1CC(*(void **)(*(u8 **)(p + 8) + 0x368));
}
