/*
 * function: func_0217AF9C
 * address:  0x0217AF9C
 * packet:   pkt_0217AF9C
 * region:   ov176
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021E8628  0x021E8628  thumb
 *   func_0201C4C0  0x0201C4C0  thumb
 *   func_02045C04  0x02045C04  arm
 *   func_0201D83C  0x0201D83C  thumb
 */
typedef unsigned int u32;

extern void func_021E8628(u32 a);
struct PrintSys;
struct Rec;
extern void func_0201C4C0(struct PrintSys *p);
extern void func_02045C04(struct Rec *rec);
extern void func_0201D83C(void *ptr);

void func_0217AF9C(char *p)
{
    func_021E8628(*(u32 *)(p + 8));
    func_0201C4C0((struct PrintSys *)(*(u32 *)(p + 0x14)));
    func_02045C04((struct Rec *)(*(u32 *)(p + 0x10)));
    func_0201D83C((void *)(*(u32 *)(p + 0xc)));
}
