/*
 * function: func_021BC868
 * address: 0x021BC868
 * packet: pkt_ov209_021BC868
 * region: ov209
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02045808 0x02045808 arm
 *   func_0201C4C0 0x0201C4C0 thumb
 *   func_0201ED04 0x0201ED04 thumb
 *   func_0201D83C 0x0201D83C thumb
 *   func_02045C04 0x02045C04 arm
 */
struct U16Vec;struct PrintSys;struct WordSet;struct Rec;extern void func_02045808(struct U16Vec *);extern void func_0201C4C0(struct PrintSys *);extern void func_0201ED04(struct WordSet *);extern void func_0201D83C(void *);extern void func_02045C04(struct Rec *);
void func_021BC868(char *p){func_02045808(*(struct U16Vec **)(p+68));func_0201C4C0(*(struct PrintSys **)(p+72));func_0201ED04(*(struct WordSet **)(p+64));func_0201D83C(*(void **)(p+56));func_02045C04(*(struct Rec **)(p+60));}
