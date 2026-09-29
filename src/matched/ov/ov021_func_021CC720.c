/*
 * function: func_021CC720
 * address:  0x021CC720
 * packet:   pkt_ov021_021CC720
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02034714  0x02034714  arm
 *   func_02030734  0x02030734  arm
 *   func_0204B100  0x0204B100  arm
 *   func_0201D7EC  0x0201D7EC  thumb
 *   func_021CCEB8  0x021CCEB8  thumb  ov021
 *   func_021CC8DC  0x021CC8DC  thumb  ov021
 *   func_021CCA00  0x021CCA00  thumb  ov021
 *   func_021CCC50  0x021CCC50  thumb  ov021
 *   func_021CCCE4  0x021CCCE4  thumb  ov021
 *   d_021DE5BC  0x021DE5BC  data  a1
 *   d_021DE5C0  0x021DE5C0  data  ov021
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct Obj {
    u32 f0;
    u32 f4;
    u32 f8;
    u16 fC;
    u8 padE[2];
    u32 f10;
    u32 f14;
    u32 f18;
    u8 pad1C[0xb8 - 0x1c];
    u32 fB8;
    u8 padBC[0xc4 - 0xbc];
} Obj;

extern void func_02034714(const char *file, int line, const char *msg);
extern Obj *func_02030734(u16 heap, u32 size, u32 clear, const char *file, u32 line);
extern u32 func_0204B100(u32 a, u32 b, u32 heap);
extern u32 func_0201D7EC(u32 a, u32 b, u32 c, u32 d, u16 heap);
extern void func_021CCEB8(Obj *p);
extern void func_021CC8DC(Obj *p);
extern void func_021CCA00(Obj *p);
extern void func_021CCC50(Obj *p);
extern void func_021CCCE4(Obj *p);
extern const char d_021DE5BC[];
extern const char d_021DE5C0[];

Obj *func_021CC720(u32 a, u32 b, u32 c, u32 d, u32 e, u16 heap)
{
    Obj *p;

    if (b == 0 || c == 0)
        func_02034714(d_021DE5BC, 0, d_021DE5BC);
    p = func_02030734(heap, 0xc4, 1, d_021DE5C0, 0xd3);
    p->f0 = a;
    p->f4 = b;
    p->f8 = c;
    p->fC = heap;
    p->f10 = d;
    p->f14 = e;
    p->f18 = func_0204B100(0x20, 0xa, p->fC);
    p->fB8 = func_0201D7EC(0x17, 3, 0, 0, p->fC);
    func_021CCEB8(p);
    func_021CC8DC(p);
    func_021CCA00(p);
    func_021CCC50(p);
    func_021CCCE4(p);
    return p;
}
