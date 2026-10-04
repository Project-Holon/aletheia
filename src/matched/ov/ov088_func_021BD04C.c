/*
 * function: func_021BD04C
 * address:  0x021BD04C
 * packet:   pkt_ov088_021BD04C
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
 *   func_0201D83C  0x0201D83C  thumb
 *   func_02045C04  0x02045C04  arm
 *   func_020461D4  0x020461D4  arm
 */

extern int func_02028604(int a0);
struct Rec;
struct S02031140;
struct U16Vec;
extern void func_02031140(struct S02031140 *p);
extern void func_02045808(struct U16Vec *vec);
extern void func_0201D83C(void *);
extern void func_02045C04(struct Rec *rec);
extern void func_020461D4(unsigned char);

void func_021BD04C(unsigned char *p)
{
    func_02028604((int)(*(void **)(p + 0x24)));
    func_02031140(*(void **)(p + 0x18));
    func_02045808(*(void **)(p + 0x10));
    func_0201D83C(*(void **)(p + 0x04));
    func_02045C04(*(void **)(p + 0x08));
    func_020461D4(p[0x0C]);
}
