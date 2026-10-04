/*
 * function: func_021CFDBC
 * address:  0x021CFDBC
 * packet:   pkt_ov021_021CFDBC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02012EBC  0x02012EBC  thumb
 *   func_02009470  0x02009470  thumb
 *   func_02012F38  0x02012F38  thumb
 *   func_0200973C  0x0200973C  thumb
 *   func_0201F048  0x0201F048  thumb
 *   func_02025B64  0x02025B64  thumb
 *   func_02008570  0x02008570  thumb
 *   func_0201F094  0x0201F094  thumb
 *   func_02012944  0x02012944  thumb
 *   func_0201F02C  0x0201F02C  thumb
 *   func_02009634  0x02009634  thumb
 *   func_0201EE60  0x0201EE60  thumb
 *   func_02009628  0x02009628  thumb
 *   func_0201F198  0x0201F198  thumb
 *   func_0201EFA4  0x0201EFA4  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct Big;
struct Sub0200852CObj;
struct Sub02009470Ent;
struct Sub02009470Obj;
struct WordSet;
extern void *func_02012EBC(struct Big *p);
extern struct Sub02009470Obj *func_02009470(void *sys);
extern int func_02012F38(int base);
extern struct Sub02009470Ent *func_0200973C(struct Sub02009470Obj *obj, int i);
struct WordSet;
extern void func_0201F048(struct WordSet *p, u32 i, u32 n);
extern u8 func_02025B64(u32 v);
extern u8 func_02008570(const struct Sub0200852CObj *obj);
extern void func_0201F094(struct WordSet *p, u32 i, u32 a, u32 n);
extern u8 *func_02012944(void *p);
extern void func_0201F02C(struct WordSet *p, u32 i, void *a);
extern u32 func_02009634(const struct Sub02009470Obj *obj, u32 i, u32 field);
extern void func_0201EE60(struct WordSet *p, u32 i, u16 v);
extern u8 func_02009628(const struct Sub02009470Obj *obj);
extern void func_0201F198(struct WordSet *p, u32 i, u32 v);
extern void func_0201EFA4(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);

void func_021CFDBC(void *ws, u32 h, u32 x)
{
    u32 g, e, v;
    u8 k;

    g = (u32)func_02009470(func_02012EBC((struct Big *)h));
    k = *((u8 *)func_02012F38(h));
    e = (u32)func_0200973C((struct Sub02009470Obj *)g, x);
    func_0201F048(ws, 0, k);
    if (func_02025B64(k)) {
        func_0201F094(ws, 1, k, func_02008570((const struct Sub0200852CObj *)e));
    }
    func_0201F02C(ws, 3, func_02012944((void *)h));
    func_0201EE60(ws, 5, func_02009634((const struct Sub02009470Obj *)g, x, 0));
    func_0201F198(ws, 6, func_02009628((const struct Sub02009470Obj *)g));
    func_0201F02C(ws, 7, (void *)e);
    v = func_02009634((const struct Sub02009470Obj *)g, x, 3);
    if (v == 0) {
        v = 1;
    }
    func_0201EFA4(ws, 8, v, 3, 0, 1);
    func_0201EE60(ws, 9, func_02009634((const struct Sub02009470Obj *)g, x, 1));
    k = func_02009634((const struct Sub02009470Obj *)g, x, 2);
    func_0201F198(ws, 10, k);
}
