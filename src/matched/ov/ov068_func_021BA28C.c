/*
 * function: func_021BA28C
 * address:  0x021BA28C
 * packet:   pkt_ov068_021BA28C
 * region:   ov068
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02045770  0x02045770  arm
 *   func_02043B5C  0x02043B5C  arm
 *   func_02045CAC  0x02045CAC  arm
 *   func_0201CE48  0x0201CE48  thumb
 *   func_0201C6FC  0x0201C6FC  thumb
 *   func_0201CCE4  0x0201CCE4  thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Descriptor;
extern void *func_02045770(struct Descriptor *p);
struct CharBuf;
struct MsgBank;
struct PrintSys;
struct Rec3;
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern void func_0201CE48(struct Rec3 *p);
extern void func_0201C6FC(struct PrintSys *p, u32 a, u32 b, u32 c, void *s, u32 e);
extern u32  func_0201CCE4(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6,
                          u32 a7, u16 a8, u16 a9);

void func_021BA28C(u8 *p, u32 a1, u32 a2, u32 a3, u32 a4)
{
    u32 t;

    func_02043B5C((struct CharBuf *)((u32)func_02045770((struct Descriptor *)*(u32 *)(p + 0x10))), (u8)*(u16 *)(p + 0x18));
    func_02045CAC((struct MsgBank *)a1, a2, (void *)(*(u32 *)(p + 0x14)));
    if (*(u32 *)(p + 8) != 0) {
        func_0201CE48((struct Rec3 *)(*(u32 *)(p + 8)));
        *(u32 *)(p + 8) = 0;
    }
    if (a4 == 0) {
        t = *(u32 *)(p + 0x24);
        func_0201C6FC((struct PrintSys *)t, (u32)func_02045770((struct Descriptor *)*(u32 *)(p + 0x1c)), 0, 0,
                      (void *)(*(u32 *)(p + 0x14)), *(u32 *)(p + 4));
        p[0x20] = 1;
        *(u32 *)(p + 0x28) = 2;
        return;
    }
    *(u32 *)(p + 8) = func_0201CCE4(*(u32 *)(p + 0x10), 0, 0, *(u32 *)(p + 0x14),
                                    *(u32 *)(p + 4), a3, *(u32 *)(p + 0xc), 0,
                                    *(u16 *)(p + 0x1a), *(u16 *)(p + 0x18));
    *(u32 *)(p + 0x28) = 1;
}
