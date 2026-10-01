/*
 * function: func_021BAEE0
 * address: 0x021BAEE0
 * packet: pkt_ov223_021BAEE0
 * region: ov223
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * Trailing AF2E halfword is zero alignment padding.
 * symbols:
 *   func_0201CE48 0x0201CE48 thumb
 *   func_02045808 0x02045808 arm
 *   func_020452E8 0x020452E8 arm
 *   func_02031140 0x02031140 arm
 *   func_02045C04 0x02045C04 arm
 */
typedef unsigned char u8;
struct Rec3;
struct U16Vec;
struct Descriptor;
struct S02031140;
struct Rec;
extern void func_0201CE48(struct Rec3 *);
extern void func_02045808(struct U16Vec *);
extern void func_020452E8(struct Descriptor *);
extern void func_02031140(struct S02031140 *);
extern void func_02045C04(struct Rec *);
void func_021BAEE0(char *p)
{
    u8 i;
    if (*(struct Rec3 **)(p + 0x250))
        func_0201CE48(*(struct Rec3 **)(p + 0x250));
    if (*(struct U16Vec **)(p + 0x258))
        func_02045808(*(struct U16Vec **)(p + 0x258));
    for (i = 0; i < 3; i++)
        func_020452E8(*(struct Descriptor **)(p + 0x238 + i * 4));
    func_02031140(*(struct S02031140 **)(p + 0x254));
    func_02045C04(*(struct Rec **)(p + 0x234));
}
