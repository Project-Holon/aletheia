/*
 * function: func_021B9EC4
 * address:  0x021B9EC4
 * packet:   pkt_ov088_021B9EC4
 * region:   ov088
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020490F4  0x020490F4  arm
 *   func_0204A48C  0x0204A48C  arm
 *   func_0204B100  0x0204B100  arm
 *   func_0204B270  0x0204B270  arm
 *   func_0204A6C8  0x0204A6C8  arm
 *   func_0204ABF0  0x0204ABF0  arm
 *   func_0204AF28  0x0204AF28  arm
 *   func_0204B294  0x0204B294  arm
 *   func_0204B92C  0x0204B92C  arm
 *   func_02043598  0x02043598  arm
 *   func_02049238  0x02049238  arm
 *   d_020A1448     0x020A1448  data  a4
 *   d_021BD508     0x021BD508  data  ov088  a4
 */

typedef struct {
    unsigned short a;
    unsigned short b;
    unsigned short c;
    unsigned char d;
    unsigned char e;
} Local;

extern char d_020A1448[];
extern char d_021BD508[];

extern void *func_020490F4(unsigned int id, unsigned int heap);
extern void func_0204A48C(void *, void *, int);
extern int func_0204B100(int, int, int);
typedef signed int     s32;
typedef unsigned int   u32;
struct Bank;
extern void func_0204B270(struct Bank *bank);
extern int func_0204A6C8(void *, int, int, int, int);
extern int func_0204ABF0(void *, int, int, int, int);
extern s32 func_0204AF28(void *owner, u32 first, u32 second, u32 mode);
extern int func_0204B294(int, int, int, int, Local *, int, int);
struct Obj;
extern void func_0204B92C(struct Obj *p, u32 v);
extern void func_02043598(u32 mask, u32 enable);
extern void func_02049238(void *);

void func_021B9EC4(int *p, int heap)
{
    Local s;
    void *h;
    h = func_020490F4(0x1a, heap);
    func_0204A48C(d_020A1448, d_021BD508, heap);
    p[0] = func_0204B100(0x40, 0, heap);
    func_0204B270((void *)p[0]);
    p[12] = func_0204A6C8(h, 5, 1, 1, heap);
    p[11] = func_0204ABF0(h, 4, 1, 0, heap);
    p[13] = func_0204AF28(h, 6, 7, heap);
    s.a = 0x80;
    s.b = 0x60;
    s.c = 0;
    s.e = 0;
    s.d = 0;
    p[1] = func_0204B294(p[0], p[12], p[11], p[13], &s, 1, heap);
    func_0204B92C((struct Obj *)p[1], 1);
    func_02043598(0x10, 1);
    func_02049238(h);
}
