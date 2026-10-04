/*
 * function: func_02205070
 * address:  0x02205070
 * packet:   pkt_02205070
 * region:   ov195
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   d_02208C4C 0x02208C4C data a4
 *   func_020490F4 0x020490F4 arm
 *   func_0204AC18 0x0204AC18 arm
 *   func_0204A6C8 0x0204A6C8 arm
 *   func_0204AF28 0x0204AF28 arm
 *   func_02049238 0x02049238 arm
 *   func_02205A28 0x02205A28 thumb ov195
 *   func_0204B294 0x0204B294 arm
 *   func_0204B92C 0x0204B92C arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u8 d_02208C4C[];
extern void *func_020490F4(unsigned int id, u16 heap);
typedef signed int     s32;
extern s32 func_0204AC18(void *a, u32 b, u32 c, u32 d, u16 e, u16 f, u16 g);
extern s32 func_0204A6C8(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern s32 func_0204AF28(void *owner, u32 first, u32 second, u32 mode);
extern void func_02049238(void *);
extern u32 func_02205A28(u32);
struct Obj;
extern struct Obj *func_0204B294(void *, u32, u32, u32, const void *, u16, u16);
struct Obj;
extern void func_0204B92C(struct Obj *, u32);

void func_02205070(int a, char *b)
{
    void *h;
    u8 i;
    int z;

    h = func_020490F4(0xb6, *(u16 *)(b + 2));
    i = 0;
    *(u32 *)(b + 0x40) = func_0204AC18(h, 3, 0, 0, i, 1, *(u16 *)(b + 2));
    *(u32 *)(b + 0x3c) = func_0204A6C8(h, 2, 0, 0, *(u16 *)(b + 2));
    *(u32 *)(b + 0x44) = func_0204AF28(h, 1, 0, *(u16 *)(b + 2));
    func_02049238(h);
    for (z = i; i < 6; i++) {
        char *e = b + i * 4;
        *(u32 *)(e + 0x48) = (u32)func_0204B294((void *)func_02205A28(*(u32 *)(b + 4)), *(u32 *)(b + 0x3c), *(u32 *)(b + 0x40),
                                           *(u32 *)(b + 0x44), d_02208C4C + i * 8, z, *(u16 *)(b + 2));
        func_0204B92C((struct Obj *)*(u32 *)(e + 0x48), z);
    }
    *(u32 *)(b + 0x60) = 1;
}
