/*
 * function: func_021BACD8
 * address:  0x021BACD8
 * packet:   pkt_ov088_021BACD8
 * region:   ov088
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02028604  0x02028604  thumb
 *   func_02031140  0x02031140  arm
 *   func_02045808  0x02045808  arm
 *   func_0201C4C0  0x0201C4C0  thumb
 *   func_0201ED04  0x0201ED04  thumb
 *   func_0201D83C  0x0201D83C  thumb
 *   func_02045C04  0x02045C04  arm
 */

extern int func_02028604(int a0);
struct PrintSys;
struct Rec;
struct S02031140;
struct U16Vec;
struct WordSet;
extern void func_02031140(struct S02031140 *p);
extern void func_02045808(struct U16Vec *vec);
extern void func_0201C4C0(struct PrintSys *p);
extern void func_0201ED04(struct WordSet *p);
extern void func_0201D83C(void *ptr);
extern void func_02045C04(struct Rec *rec);

void func_021BACD8(int *p)
{
    func_02028604(p[0x74 / 4]);
    func_02031140((struct S02031140 *)p[0x70 / 4]);
    func_02045808((struct U16Vec *)p[0x64 / 4]);
    func_0201C4C0((struct PrintSys *)p[0x68 / 4]);
    func_0201ED04((struct WordSet *)p[0x60 / 4]);
    func_0201D83C((void *)p[0x58 / 4]);
    func_02045C04((struct Rec *)p[0x5c / 4]);
}
