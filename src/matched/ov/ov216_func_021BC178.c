/*
 * function: func_021BC178
 * address: 0x021BC178
 * packet: pkt_ov216_021BC178
 * region: ov216
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02045808 0x02045808 arm
 *   func_02045C04 0x02045C04 arm
 *   func_0201ED04 0x0201ED04 thumb
 *   func_0201D83C 0x0201D83C thumb
 *   func_0201C6EC 0x0201C6EC thumb
 *   func_0201C4C0 0x0201C4C0 thumb
 *   func_0201DD68 0x0201DD68 thumb
 *   func_02031140 0x02031140 arm
 *   func_02049238 0x02049238 arm
 */
struct U16Vec; struct Rec; struct WordSet; struct PrintSys; struct S02031140;
extern void func_02045808(struct U16Vec *);
extern void func_02045C04(struct Rec *);
extern void func_0201ED04(struct WordSet *);
extern void func_0201D83C(void *);
extern void func_0201C6EC(struct PrintSys *);
extern void func_0201C4C0(struct PrintSys *);
extern void func_0201DD68(void);
extern void func_02031140(struct S02031140 *);
extern void func_02049238(void *);
void func_021BC178(char *p)
{
    func_02045808(*(struct U16Vec **)(p+0x144));
    func_02045808(*(struct U16Vec **)(p+0x140));
    func_02045808(*(struct U16Vec **)(p+0x13c));
    func_02045C04(*(struct Rec **)(p+0x134));
    func_02045C04(*(struct Rec **)(p+0x130));
    func_0201ED04(*(struct WordSet **)(p+0x138));
    func_0201D83C(*(void **)(p+0x128));
    func_0201C6EC(*(struct PrintSys **)(p+0x12c));
    func_0201C4C0(*(struct PrintSys **)(p+0x12c));
    func_0201DD68();
    func_02031140(*(struct S02031140 **)(p+0x18));
    func_02049238(*(void **)(p+0x54));
}
