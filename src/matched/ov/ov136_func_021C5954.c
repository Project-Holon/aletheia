/*
 * function: func_021C5954
 * address:  0x021C5954
 * packet:   pkt_ov136_021C5954
 * region:   ov136
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021C5954 0x021C5954 thumb
 *   func_02045808 0x02045808 arm
 *   func_0201ED04 0x0201ED04 thumb
 *   func_02045C04 0x02045C04 arm
 */
typedef unsigned char u8;
struct Rec;
struct U16Vec;
struct WordSet;
extern void func_02045808(struct U16Vec *vec);
extern void func_0201ED04(struct WordSet *p);
extern void func_02045C04(struct Rec *rec);
void func_021C5954(u8 *p)
{
    func_02045808(*(void **)(p + 0x1D8));
    func_0201ED04(*(void **)(p + 0x1D4));
    func_02045C04(*(void **)(p + 0x1D0));
}
