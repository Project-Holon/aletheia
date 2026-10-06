/*
 * function: func_021B7D14
 * address: 0x021B7D14
 * packet: pkt_ov106_021B7D14
 * region: ov106
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * closed 2026-10-05 (recoup integrator): func_02049658 returns u32 (its matched definition tail-returns sub_0204968C); with the void declaration the later register zeros were copied from the pooled zero; with the real return type the
 *   bytes are EXACT in c99 and c.
 * 2026-10-05 (lane S9, pengy share): twin shape is ov104 func_021B7994 (no exact twin
 * found). Loop, call order and all arguments are right. 508 B vs 492 B, residue:
 * the original pools the stack-argument zero in r4 (movs r4,#0 right after the
 * p[0] store, str r4 for every stack zero) and keeps k=7 in r5 (movs r5,#7 beside
 * the arg setup of the first 02049658(...,3,7,...) call, used for lsls r4,r5,#6
 * = 0x1c0), with the later 7 arguments as literal movs. Mine rematerialises each
 * zero and CSEs the later 7s from k. Tried: bg local for the table read (fixed the
 * loop), i=0 reuse, named int z, no k at all, six per-function pragmas
 * (lifetimes, propagation, common_subs, dead_assignments, scheduling, peephole):
 * none pools the zero. d_021B94A8 also has no witness (ov106 token did not help).
 * Idioms checked: a-named-zero-argument-pins-the-callers-truncation (z folded, no
 * change), a-repeated-small-constant-takes-a-callee-saved-register (wall note),
 * a-hoisted-loop-invariant-zero-takes-the-freshly-dead-register (n/a),
 * a-constant-loaded-at-entry-into-a-callee-saved-register (n/a).
 *
 * symbols:
 *   func_02082BCC 0x02082BCC arm
 *   func_0203F8F4 0x0203F8F4 arm
 *   func_02045088 0x02045088 arm
 *   func_0203FC28 0x0203FC28 arm
 *   func_0203FCA0 0x0203FCA0 arm
 *   func_020414AC 0x020414AC arm
 *   func_02040588 0x02040588 arm
 *   func_020490F4 0x020490F4 arm
 *   func_02049B68 0x02049B68 arm
 *   func_02049658 0x02049658 arm
 *   func_020498F4 0x020498F4 arm
 *   func_02040C14 0x02040C14 arm
 *   func_02049740 0x02049740 arm
 *   func_02049B40 0x02049B40 arm
 *   func_02049238 0x02049238 arm
 *   func_02045B38 0x02045B38 arm
 *   func_0201D7EC 0x0201D7EC thumb
 *   func_020450F0 0x020450F0 arm
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_02045EC0 0x02045EC0 arm
 *   func_02012944 0x02012944 thumb
 *   func_021B91A8 0x021B91A8 thumb
 *   func_02045808 0x02045808 arm
 *   func_0201D83C 0x0201D83C thumb
 *   func_02045C04 0x02045C04 arm
 *   func_02045334 0x02045334 arm
 *   func_02045374 0x02045374 arm
 *   func_020409B4 0x020409B4 arm
 *   d_021B94A8 0x021B94A8 data
 *   d_021B9524 0x021B9524 data a4
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct DispConfig;
struct BgTemplate { u8 bytes[32]; };
typedef struct { u32 bg; struct BgTemplate t; u32 type; } BgEntry;
struct Descriptor;
struct MsgBank;
struct GfFont;
struct StrObj;
extern struct DispConfig d_021B94A8;
extern BgEntry d_021B9524[];
extern void func_02082BCC(void *, int, u32);
extern void func_0203F8F4(u32);
extern void func_02045088(u32);
extern void func_0203FC28(struct DispConfig *);
struct Cfg;
struct CharBuf;
struct Rec;
struct U16Vec;
extern void func_0203FCA0(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void func_020414AC(u8);
extern void func_02040588(unsigned char which, unsigned char enable);
extern void *func_020490F4(unsigned int id, u32 heap);
extern void func_02049B68(void *a, u32 b, u32 c, u32 d, u32 e, u32 f);
extern unsigned int func_02049658(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g);
extern void func_020498F4(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g);
extern void func_02040C14(u32, u32, u32, u32);
extern u32 func_02049740(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 flags);
extern void func_02049B40(u32, u32, u32, u32, u32, u32);
extern void func_02049238(void *);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern struct GfFont *func_0201D7EC(int a0, int a1, int a2, int a3, u32 heapId);
extern u32 func_020450F0(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern void *func_02045770(struct Descriptor *);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void *func_02045EC0(struct MsgBank *, u32);
extern u8 *func_02012944(void *p);
extern void func_021B91A8(struct Descriptor *, struct StrObj *, void *, u32);
extern void func_02045808(struct U16Vec *vec);
extern u32 func_0201D83C(void *ptr);
extern u32 func_02045C04(struct Rec *rec);
extern void func_02045334(struct Descriptor *);
extern void func_02045374(struct Cfg *cfg);
extern void func_020409B4(u32);
void func_021B7D14(u32 *p, void *arg, u32 heap) {
 int i; int k; u32 bg; struct MsgBank *msg; struct GfFont *font; struct StrObj *str;
 func_02082BCC(p, 0, 0x10);
 func_0203F8F4(heap);
 func_02045088(heap);
 func_0203FC28(&d_021B94A8);
 for (i = 0; i < 8; i++) {
  bg = d_021B9524[i].bg;
  func_0203FCA0((u8)bg, &d_021B9524[i].t, (u8)d_021B9524[i].type);
  func_020414AC(bg);
  func_02040588(bg, 1);
 }
 p[0] = (u32)func_020490F4(0x4d, heap);
 func_02049B68((void *)p[0], 0, 0, 0, 0, heap);
 func_02049658((void *)p[0], 1, 3, 0, 0, 0, heap);
 func_02049658((void *)p[0], 3, 0, 0, 0, 0, heap);
 func_020498F4((void *)p[0], 4, 3, 0, 0, 0, heap);
 func_020498F4((void *)p[0], 6, 0, 0, 0, 0, heap);
 func_02049B68((void *)p[0], 0, 4, 0, 0, heap);
 k = 7;
 func_02049658((void *)p[0], 3, 7, 0, 0, 0, heap);
 func_020498F4((void *)p[0], 7, 7, 0, 0, 0, heap);
 func_02040C14(1, 0, 1, 0);
 func_02040C14(5, 0, 1, 0);
 p[1] = func_02049740((void *)p[0], 2, 1, 0, 0, heap);
 p[2] = func_02049740((void *)p[0], 2, 5, 0, 0, heap);
 func_02049B40(0x17, 5, 0, k << 6, 0x20, heap);
 func_02049B40(0x17, 5, 4, k << 6, 0x20, heap);
 func_02049238((void *)p[0]);
 msg = func_02045B38(0, 2, 0x32, heap);
 font = func_0201D7EC(0x17, 0, 0, 0, heap);
 p[3] = func_020450F0(0, 3, 1, 0x1a, (u32)2, (u32)0xe, (u32)1);
 func_02043B5C(func_02045770((struct Descriptor *)p[3]), 0xf);
 str = (struct StrObj *)func_02045EC0(msg, 0);
 func_021B91A8((struct Descriptor *)p[3], str, func_02012944(arg), (u32)font);
 func_02045808((struct U16Vec *)str);
 func_0201D83C(font);
 func_02045C04((struct Rec *)msg);
 func_02045334((struct Descriptor *)p[3]);
 func_02045374((struct Cfg *)p[3]);
 func_020409B4(0);
}
