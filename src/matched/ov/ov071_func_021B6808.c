/*
 * function: func_021B6808
 * address: 0x021B6808
 * packet: pkt_ov071_021B6808
 * region: ov071
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02045C04 0x02045C04 arm
 *   func_0201ED04 0x0201ED04 thumb
 *   func_0201C6EC 0x0201C6EC thumb
 *   func_0201C4C0 0x0201C4C0 thumb
 *   func_0201D83C 0x0201D83C thumb
 *   func_02031140 0x02031140 arm
 */
struct Rec;
struct WordSet;
struct PrintSys;
struct S02031140;
extern unsigned int func_02045C04(struct Rec *rec);
extern unsigned int func_0201ED04(struct WordSet *p);
extern void func_0201C6EC(struct PrintSys *);
extern void func_0201C4C0(struct PrintSys *);
typedef unsigned int   u32;
extern u32 func_0201D83C(void *ptr);
extern void func_02031140(struct S02031140 *);
void func_021B6808(void **p)
{
    func_02045C04(p[7]);
    func_02045C04(p[8]);
    func_02045C04(p[9]);
    func_02045C04(p[10]);
    func_0201ED04(p[4]);
    func_0201C6EC(p[2]);
    func_0201C4C0(p[2]);
    func_0201D83C(p[3]);
    func_02031140(p[6]);
}
