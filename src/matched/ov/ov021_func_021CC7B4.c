/*
 * function: func_021CC7B4
 * address:  0x021CC7B4
 * packet:   pkt_ov021_021CC7B4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021CC8B0  0x021CC8B0  thumb  ov021
 *   func_02034714  0x02034714  arm
 *   func_021CCDF8  0x021CCDF8  thumb  ov021
 *   func_021CCCC4  0x021CCCC4  thumb  ov021
 *   func_021CCB98  0x021CCB98  thumb  ov021
 *   func_021CC9A4  0x021CC9A4  thumb  ov021
 *   func_021CCEE4  0x021CCEE4  thumb  ov021
 *   func_0201D83C  0x0201D83C  thumb
 *   func_0204B1CC  0x0204B1CC  arm
 *   func_020307B0  0x020307B0  arm
 *   d_021DE5BC  0x021DE5BC  data  a1
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct Obj {
    u8 pad0[0x18];
    u32 f18;
    u8 pad1C[0xb8 - 0x1c];
    u32 fB8;
    u8 padBC[0xc1 - 0xbc];
    u8 fC1;
} Obj;

extern u32 func_021CC8B0(Obj *p, u32 *out);
extern void func_02034714(const char *expr, u32 line, const char *file);
extern void func_021CCDF8(u8 *p);
extern int func_021CCCC4(u32 a);
extern void func_021CCB98(u8 *p);
extern void func_021CC9A4(u8 *p);
extern int func_021CCEE4(u32 a);
struct Bank;
extern u32 func_0201D83C(void *ptr);
extern u32 func_0204B1CC(struct Bank *bank);
extern u32 func_020307B0(void *p);
extern const char d_021DE5BC[];

u32 func_021CC7B4(Obj *p, u32 *out)
{
    u32 r;

    r = func_021CC8B0(p, out);
    if (p->fC1 != 1)
        func_02034714(d_021DE5BC, 0, d_021DE5BC);
    func_021CCDF8((u8 *)p);
    func_021CCCC4((u32)p);
    func_021CCB98((u8 *)p);
    func_021CC9A4((u8 *)p);
    func_021CCEE4((u32)p);
    func_0201D83C((void *)p->fB8);
    func_0204B1CC((struct Bank *)p->f18);
    func_020307B0(p);
    return r;
}
