/*
 * function: func_0200C058
 * address:  0x0200C058
 * packet:   pkt_0200BFA4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0200C10C    0x0200C10C  thumb
 *   func_02045B38    0x02045B38  arm
 *   func_02045EC0    0x02045EC0  arm
 *   func_02045A38    0x02045A38  arm
 *   func_02045808    0x02045808  arm
 *   func_02045C04    0x02045C04  arm
 *   memset           0x02082BCC  arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

typedef struct {
    u8  pad00[0x14];
    u32 f14;
    u8  pad18[0x20 - 0x18];
    u8  f20[0x12];
    u8  f32[0x12];
    u8  f44;
    u8  f45;
    u8  f46;
    u8  f47;
    u8  f48;
    u8  f49;
} Obj;

struct MsgBank;
struct Rec;
struct U16Vec;
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void  func_02045A38(void *a, void *dst, u32 n);
extern void func_02045808(struct U16Vec *vec);
extern void func_02045C04(struct Rec *rec);
extern void  func_0200C10C(Obj *p);
extern void *memset(void *dst, int c, u32 n);

void func_0200C058(Obj *p)
{
    void *a;
    void *b;
    void *c;

    memset(p, 0, 0xec);
    func_0200C10C(p);
    p->f14 &= 0xf0000000;
    a = func_02045B38(0, 3, 0x2f, 0x8007);
    b = func_02045EC0(a, 0x151);
    func_02045A38(b, p->f20, 9);
    func_02045808(b);
    c = func_02045EC0(a, 0x159);
    func_02045A38(c, p->f32, 9);
    func_02045808(c);
    func_02045C04(a);
    p->f44 = 0;
    p->f46 = 0;
    p->f47 = 0xff;
    p->f48 = 0xff;
    p->f49 = 0xff;
}
