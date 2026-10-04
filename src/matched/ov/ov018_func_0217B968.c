/*
 * function: func_0217B968
 * address:  0x0217B968
 * packet:   pkt_ov018_0217B968
 * region:   ov018
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_0202648C  0x0202648C  thumb
 *   func_02026460  0x02026460  thumb
 *   func_0200FB24  0x0200FB24  thumb
 *   func_02035390  0x02035390  arm
 *   func_020353B0  0x020353B0  arm
 *   func_02012204  0x02012204  thumb
 *   func_020120D8  0x020120D8  thumb
 *   func_020120F4  0x020120F4  thumb
 *   func_020127A4  0x020127A4  thumb
 *   func_02012AC8  0x02012AC8  thumb
 *   func_02013D5C  0x02013D5C  thumb
 *   func_021A3038  0x021A3038  thumb  ov021
 *   func_02026454  0x02026454  thumb
 *   func_0217B930  0x0217B930  thumb  ov018
 *   func_0217BA54  0x0217BA54  thumb  ov018
 *   func_020392B8  0x020392B8  arm
 *   func_02026474  0x02026474  thumb
 *   func_02026400  0x02026400  thumb
 *   func_0202640C  0x0202640C  thumb
 *   func_0217BA48  0x0217BA48  thumb  ov018
 */

typedef unsigned char u8;

typedef struct { int x, y, z; } Vec;

typedef unsigned int   u32;
struct Comm;
struct Ctx;
struct Rec44;
extern u32 func_0202648C(void *obj);
extern u32 func_02026460(void *obj);
extern u32 func_0200FB24(void);
extern int func_02035390(void);
extern int func_020353B0(void);
extern u32 func_02012204(const struct Ctx *p);
extern int func_020120D8(char *p);
extern int func_020120F4(void *);
extern int func_020127A4(int);
extern unsigned short func_02012AC8(const struct Rec44 *p);
extern u32 func_02013D5C(u32 id);
struct VecFx32;
extern void func_021A3038(unsigned char *, struct VecFx32 *);
extern u32 func_02026454(void *obj);
extern int func_0217B930(Vec *);
extern void func_0217BA54(void *);
extern int func_020392B8(void);
extern u8 *func_02026474(void *);
extern void func_02026400(struct Comm *p);
extern void func_0202640C(void *, void (*)(int, int), void *);
extern void func_0217BA48(int, int);

void func_0217B968(int a0, void *a1, void *a2, void *a3)
{
    Vec v;

    if (func_0202648C(a2) != 0)
        return;
    if (func_02026460(a2) == 1)
        return;
    if (func_0200FB24() != 0)
        return;
    if (func_02035390() == 1 && func_020353B0() == 1)
        return;
    if (func_02012204(a1) == 1)
        return;
    if (func_020120D8(a1) == 1)
        return;
    if (func_02013D5C(func_02012AC8((const struct Rec44 *)func_020127A4(func_020120F4(a1)))) == 0)
        return;
    func_021A3038(a3, (struct VecFx32 *)&v);
    switch (func_02026454(a2)) {
    case 0:
        if (func_0217B930(&v) == 1)
            func_0217BA54(a1);
        break;
    case 2:
        if (func_0217B930(&v) != 0)
            return;
        if (func_020392B8() > 1)
            return;
        if (func_02026474(a2)[0x8FD] == 4)
            return;
        func_02026400(a2);
        break;
    case 1:
        if (func_0217B930(&v) == 1)
            func_0202640C(a2, func_0217BA48, a1);
        break;
    }
}
