/*
 * function: func_021DCE80
 * address: 0x021DCE80
 * packet: pkt_ov170_021DCE80
 * region: ov170
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * trailing: two bytes alignment padding at 0x021DCEBE.
 * symbols:
 *   func_02045808 0x02045808 arm
 *   func_0201C4C0 0x0201C4C0 thumb
 *   func_0201ED04 0x0201ED04 thumb
 *   func_0201D83C 0x0201D83C thumb
 *   func_02045C04 0x02045C04 arm
 */
struct PrintSys;
struct Rec;
struct U16Vec;
struct WordSet;
extern void func_02045808(struct U16Vec *vec);
extern void func_0201C4C0(struct PrintSys *p);
extern void func_0201ED04(struct WordSet *p);
extern void func_0201D83C(void *);
extern void func_02045C04(struct Rec *rec);
#define WORK(p) (*(char **)((p)+0x2c))
#define PTR(p,n) (*(void **)(WORK(p)+(n)))
void func_021DCE80(char *p)
{
    func_02045808(PTR(p,0x88));
    func_0201C4C0(PTR(p,0x8c));
    func_0201ED04(PTR(p,0x84));
    func_0201D83C(PTR(p,0x7c));
    func_0201D83C(PTR(p,0x78));
    func_02045C04(PTR(p,0x80));
}
