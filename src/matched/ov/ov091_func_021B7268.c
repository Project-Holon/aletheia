/*
 * function: func_021B7268
 * address: 0x021B7268
 * packet: pkt_ov091_021B7268
 * region: ov091
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0201C6EC 0x0201C6EC thumb
 *   func_0201C4C0 0x0201C4C0 thumb
 *   func_02045C04 0x02045C04 arm
 *   func_0201D83C 0x0201D83C thumb
 */
struct PrintSys;
struct Rec;
extern void func_0201C6EC(struct PrintSys *p);
extern void func_0201C4C0(struct PrintSys *p);
extern void func_02045C04(struct Rec *rec);
extern void func_0201D83C(void *);
void func_021B7268(unsigned p) { func_0201C6EC((struct PrintSys *)(*(unsigned *)(p+320))); func_0201C4C0((struct PrintSys *)(*(unsigned *)(p+320))); func_02045C04((struct Rec *)(*(int *)(p+308))); func_0201D83C(*(void **)(p+316)); func_0201D83C(*(void **)(p+312)); }
