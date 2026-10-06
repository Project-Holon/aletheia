/*
 * function: func_0217D6C8
 * address:  0x0217D6C8
 * packet:   pkt_ov018_0217D6C8
 * region:   ov018
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02045808  0x02045808  arm
 *   func_02045C04  0x02045C04  arm
 *   func_0201C6EC  0x0201C6EC  thumb
 *   func_0201C4C0  0x0201C4C0  thumb
 *   func_0201ED04  0x0201ED04  thumb
 *   func_0201D83C  0x0201D83C  thumb
 *   func_02031140  0x02031140  arm
 *   func_02025588  0x02025588  thumb
 *   func_0204B084  0x0204B084  arm
 *   func_0204B1CC  0x0204B1CC  arm
 */

struct Bank;
struct PrintSys;
struct Rec;
struct S02031140;
struct U16Vec;
struct WordSet;
extern void func_02045808(struct U16Vec *vec);
extern unsigned int func_02045C04(struct Rec *rec);
extern void func_0201C6EC(struct PrintSys *p);
extern void func_0201C4C0(struct PrintSys *p);
extern unsigned int func_0201ED04(struct WordSet *p);
typedef unsigned int   u32;
extern u32 func_0201D83C(void *ptr);
extern void func_02031140(struct S02031140 *p);
extern void func_02025588(void *p);
extern void func_0204B084(int);
extern u32 func_0204B1CC(struct Bank *bank);

void func_0217D6C8(int *p)
{
    func_02045808((struct U16Vec *)p[0x38 / 4]);
    func_02045808((struct U16Vec *)p[0x3c / 4]);
    func_02045808((struct U16Vec *)p[0x40 / 4]);
    func_02045C04((struct Rec *)p[0x2c / 4]);
    func_02045C04((struct Rec *)p[0x30 / 4]);
    func_0201C6EC((struct PrintSys *)p[0x28 / 4]);
    func_0201C4C0((struct PrintSys *)p[0x28 / 4]);
    func_0201ED04((struct WordSet *)p[0x24 / 4]);
    func_0201D83C((void *)p[0x1c / 4]);
    func_02031140((struct S02031140 *)p[0x20 / 4]);
    func_02025588((void *)p[0xb0 / 4]);
    func_0204B084(p[0x58 / 4]);
    func_0204B1CC((struct Bank *)p[0x54 / 4]);
}
