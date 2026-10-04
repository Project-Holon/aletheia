/*
 * function: func_021E58A0
 * address: 0x021E58A0
 * packet: pkt_ov119_021E58A0
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020490F4 0x020490F4 arm
 *   func_0204A6C8 0x0204A6C8 arm
 *   func_0204AC18 0x0204AC18 arm
 *   func_0204AF28 0x0204AF28 arm
 *   func_02049238 0x02049238 arm
 *   func_0204B294 0x0204B294 arm
 *   func_0204B92C 0x0204B92C arm
 *   func_0204B3DC 0x0204B3DC arm
 */
typedef unsigned short u16;
typedef unsigned char u8;
typedef struct { u16 x, y, z; u8 a, b; } Sprite;
extern void *func_020490F4(unsigned int id, u16 heap);
typedef signed int     s32;
typedef unsigned int   u32;
extern s32 func_0204A6C8(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern s32 func_0204AC18(void *a, u32 b, u32 c, u32 d, u16 e, u16 f, u16 g);
extern s32 func_0204AF28(void *owner, u32 first, u32 second, u32 mode);
extern void func_02049238(void *);
struct Obj;
extern struct Obj *func_0204B294(void *, unsigned int, unsigned int, unsigned int, const void *, u16, u16);
extern void func_0204B92C(struct Obj *p, u32 v);
extern void func_0204B3DC(struct Obj *p, unsigned int v);
void func_021E58A0(int p)
{
    void *a;
    Sprite s;
    a = func_020490F4(0x66, *(u16 *)(p + 0x5f4));
    *(int *)(p + 0x894) = func_0204A6C8(a, 0x18, 0, 1, *(u16 *)(p + 0x5f4));
    *(int *)(p + 0x880) = func_0204AC18(a, 0x12, 1, 0xc0, 0, 6, *(u16 *)(p + 0x5f4));
    *(int *)(p + 0x8b0) = func_0204AF28(a, 0x17, 0x16, *(u16 *)(p + 0x5f4));
    func_02049238(a);
    s.x = 0x80; s.y = 0xb4; s.z = 2; s.a = 0xe; s.b = 0;
    *(int *)(p + 0xf04) = (int)func_0204B294((void *)*(int *)(p + 0x9c4), *(int *)(p + 0x894), *(int *)(p + 0x880), *(int *)(p + 0x8b0), &s, 1, *(u16 *)(p + 0x5f4));
    func_0204B92C((struct Obj *)*(int *)(p + 0xf04), 0);
    func_0204B3DC((struct Obj *)*(int *)(p + 0xf04), 1);
}
