/*
 * function: func_0217D410
 * address: 0x0217D410
 * packet: pkt_ov176_0217D410
 * region: ov176
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021E8A78 0x021E8A78 thumb ov177
 *   func_0217DE60 0x0217DE60 thumb ov176
 *   func_0201ED04 0x0201ED04 thumb
 *   func_02045C04 0x02045C04 arm
 *   func_020307B0 0x020307B0 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Rec;
struct WordSet;
extern void func_021E8A78(void *p);
extern void func_0217DE60(int *);
extern void func_0201ED04(struct WordSet *p);
extern void func_02045C04(struct Rec *rec);
extern void func_020307B0(void *);
void func_0217D410(int *p) {func_021E8A78((void *)p[4]);func_0217DE60(p);func_0201ED04((struct WordSet *)p[1]);func_02045C04((struct Rec *)p[0]);func_020307B0(p);}
