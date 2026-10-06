/*
 * function: func_021C1D30
 * address:  0x021C1D30
 * packet:   pkt_ov208_021C1D30
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0201C6EC  0x0201C6EC  thumb
 *   func_02045770  0x02045770  arm
 *   func_02043B5C  0x02043B5C  arm
 *   func_021BBB3C  0x021BBB3C  thumb  ov072
 *   func_02013E4C  0x02013E4C  thumb
 *   func_02045EC0  0x02045EC0  arm
 *   func_0201C724  0x0201C724  thumb
 *   func_02045808  0x02045808  arm
 *   func_021C0740  0x021C0740  thumb  ov208
 *   func_0204B878  0x0204B878  arm
 *   func_0204B404  0x0204B404  arm
 *   func_0204B3DC  0x0204B3DC  arm
 *   func_02045334  0x02045334  arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef short          s16;

typedef struct {
    u16 x;
    u16 y;
} Pt;

struct MsgBank;
struct Obj;
struct PrintSys;
extern void func_0201C6EC(struct PrintSys *p);
struct Descriptor;
extern void *func_02045770(struct Descriptor *p);
struct CharBuf;
struct U16Vec;
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern unsigned short func_021BBB3C(char *p, int a, int b);
extern u32 func_02013E4C(u32 id);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void func_0201C724(void *owner, u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern void func_02045808(struct U16Vec *vec);
extern void func_021C0740(u16 *heap, u8 *p, int key, u8 i);
extern void func_0204B878(struct Obj *p, u16 value);
struct Vec2;
extern void func_0204B404(struct Obj *p, const struct Vec2 *delta, u32 which);
struct Obj;
extern void func_0204B3DC(struct Obj *obj, unsigned int on);
extern void func_02045334(struct Descriptor *p);

#define W(o) (*(u32 *)(p + (o)))

void func_021C1D30(u16 *heap, u8 *p, int key)
{
    void *str;
    Pt pt;

    W(0x28) = 0;
    func_0201C6EC((struct PrintSys *)W(0x38));
    func_02043B5C(func_02045770((struct Descriptor *)W(0x18)), 0);
    if (p[0x79] != 0xff) {
        str = func_02045EC0((struct MsgBank *)W(0x10), func_02013E4C(func_021BBB3C((char *)W(0x3c8), p[0x79], 0)));
        func_0201C724((void *)W(0x38), (u32)func_02045770((struct Descriptor *)W(0x18)), 0, 1, (u32)str, W(4), 0x3c40);
        func_02045808(str);
        W(0x28) = 1;
        func_021C0740(heap, p, key, 1);
        pt.x = func_021BBB3C((char *)W(0x3c8), p[0x79], 2);
        pt.y = func_021BBB3C((char *)W(0x3c8), p[0x79], 3);
        func_0204B878((struct Obj *)W(0xd0), 5);
        func_0204B404((struct Obj *)W(0xd0), (const struct Vec2 *)(&pt), 0);
        func_0204B3DC((struct Obj *)W(0xd0), 1);
    } else {
        func_02045334((struct Descriptor *)W(0x18));
        func_0204B3DC((struct Obj *)W(0xd0), 0);
    }
}
