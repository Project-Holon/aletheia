/*
 * function: func_021B6474
 * address: 0x021B6474
 * packet: pkt_ov180_021B6474
 * region: ov180
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02045808 0x02045808 arm
 *   func_0201ED04 0x0201ED04 thumb
 *   func_0201D83C 0x0201D83C thumb
 *   func_02045C04 0x02045C04 arm
 */
typedef unsigned int u32;
typedef unsigned short u16;
struct WordSet; struct Rec;
struct U16Vec;
extern void func_02045808(struct U16Vec *vec);
extern void func_0201ED04(struct WordSet *);
extern void func_0201D83C(void *);
extern void func_02045C04(struct Rec *);
void func_021B6474(char *p) {func_02045808(*(void **)(p+0x9040));func_0201ED04(*(struct WordSet **)(p+0x903C));func_0201D83C(*(void **)(p+0x9034));func_0201D83C(*(void **)(p+0x9030));func_02045C04(*(struct Rec **)(p+0x9038));}
