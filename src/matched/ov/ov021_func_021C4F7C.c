/*
 * function: func_021C4F7C
 * address:  0x021C4F7C
 * packet:   pkt_ov021_021C4F7C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * The heap id is a u16 stack parameter, and the callees it feeds take a u16
 * heap too (docs/idioms/narrow-stack-parameters-and-callee-prototype-free-
 * the-narrow-home-store.md): only then does the u16 a3's home store
 * `str r3, [sp, #0x18]` lead the prologue. With u32 heap it sank below
 * `ldr r7, [sp, #0x40]; str r0, [sp, #0x10]` (6 bytes). pos.y = 0x60 is
 * written once before the loop, and the element address is spelled
 * p + i * 4 + 0x58 (r6 = p + i*4 shared with the table index).
 *
 * symbols:
 *   func_02030734  0x02030734  arm
 *   func_02082BCC  0x02082BCC  arm
 *   func_0203FCA0  0x0203FCA0  arm
 *   func_020414AC  0x020414AC  arm
 *   func_02040C14  0x02040C14  arm
 *   func_0204B100  0x0204B100  arm
 *   func_020490F4  0x020490F4  arm
 *   func_02049B68  0x02049B68  arm
 *   func_0204ABF0  0x0204ABF0  arm
 *   func_0204A6C8  0x0204A6C8  arm
 *   func_0204AF28  0x0204AF28  arm
 *   func_02049658  0x02049658  arm
 *   func_020498F4  0x020498F4  arm
 *   func_020413B0  0x020413B0  arm
 *   func_02049238  0x02049238  arm
 *   func_0204B294  0x0204B294  arm
 *   func_0204B3DC  0x0204B3DC  arm
 *   func_0204B92C  0x0204B92C  arm
 *   func_02045B38  0x02045B38  arm
 *   func_0201D7EC  0x0201D7EC  thumb
 *   func_0201C450  0x0201C450  thumb
 *   func_02012EBC  0x02012EBC  thumb
 *   func_0200C40C  0x0200C40C  thumb
 *   func_021C53A0  0x021C53A0  thumb  ov021
 *   func_02041B6C  0x02041B6C  arm
 *   func_0207D63C  0x0207D63C  arm
 *   func_02040618  0x02040618  arm
 *   func_02040588  0x02040588  arm
 *   d_021DE498     0x021DE498  data  ov021  a1
 *   d_021DAA60     0x021DAA60  data  a4
 *   d_021DAA54     0x021DAA54  data  a4
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct { u16 x; u16 y; u16 z; u8 a; u8 b; } Pos;

extern char d_021DE498[];
extern const u32 d_021DAA60[];
extern const u32 d_021DAA54[];

typedef signed int     s32;
struct Big;
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void func_02082BCC(void *p, int v, int n);
extern void func_0203FCA0(int, const void *, int);
extern void func_020414AC(int);
extern void func_02040C14(u32 layer, u32 value, u32 count, u32 index);
extern u32 func_0204B100(u32 a, u32 b, u16 heap);
extern void *func_020490F4(unsigned int id, u16 heap);
extern void func_02049B68(void *a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern u32 func_0204ABF0(void *arc, u32 id, u32 a, u32 b, u16 heap);
extern s32 func_0204A6C8(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern s32 func_0204AF28(void *owner, u32 first, u32 second, u32 mode);
extern void func_02049658(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_020498F4(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_020413B0(u32 index, u8 x0, u8 y0, u8 w, u8 h, u8 pal);
extern void func_02049238(void *);
struct Obj;
extern struct Obj *func_0204B294(void *, unsigned int, unsigned int, unsigned int, const void *, u16, u16);
extern void func_0204B3DC(struct Obj *p, unsigned int v);
struct Obj;
extern void func_0204B92C(struct Obj *obj, unsigned int v);
extern u32 func_02045B38(u32, u32, u32, u32);
extern u32 func_0201D7EC(u32 a, u32 b, u32 c, u32 d, u16 heap);
extern u32 func_0201C450(u32 size, u16 heap);
extern void *func_02012EBC(struct Big *p);
extern u32 func_0200C40C(void *p);
extern void func_021C53A0(char *a, const u16 *b, u32 c, u32 d, u32 e, u32 f, void *g, u16 h);
extern void func_02041B6C(u32 bit);
extern void func_0207D63C(int, int, int, int, int);
extern void func_02040618(u32 layer, u32 a, u32 b);
extern void func_02040588(u32 which, u32 enable);

char *func_021C4F7C(void *a0, int mode, const u16 *a2, u16 a3, u16 heap)
{
    Pos pos;
    int x;
    char *p;
    void *arc;
    int i;

    i = 0;
    p = func_02030734(heap, 0x88, 0, d_021DE498, 0xFC);
    func_02082BCC(p, 0, 0x88);
    *(u32 *)(p + 0x74) = 0;
    *(u32 *)(p + 0x78) = 25;
    *(const u16 **)(p + 0x7C) = a2;
    func_0203FCA0(1, d_021DAA60, 0);
    func_020414AC(1);
    func_02040C14(1, 0, 1, 0);
    *(u32 *)(p + 0x4C) = func_0204B100(8, 0, heap);
    x = 0x80;
    arc = func_020490F4(0x80, heap);
    func_02049B68(arc, 0, 0, x + 0xE0, 0x40, heap);
    *(u16 *)(p + 0x50) = func_0204ABF0(arc, 4, 0, 0x40, heap);
    *(u16 *)(p + 0x52) = func_0204A6C8(arc, 3, 0, 0, heap);
    *(u16 *)(p + 0x54) = func_0204AF28(arc, 2, 1, heap);
    x += 0xC0;
    func_02049B68(arc, 6, 0, x, 0x20, heap);
    func_02049658(arc, 5, 1, 0, 0, 0, heap);
    func_020498F4(arc, 7, 1, 0, 0, 0, heap);
    func_020413B0(1, 0, 11, 32, 1, 10);
    func_02049238(arc);
    func_02082BCC(&pos, 0, 8);
    pos.y = 0x60;
    for (i = 0; i < 3; i++) {
        pos.z = i;
        pos.x = d_021DAA54[i];
        *(u32 *)(p + i * 4 + 0x58) = (u32)func_0204B294((void *)*(u32 *)(p + 0x4C), *(u16 *)(p + 0x52),
            *(u16 *)(p + 0x50), *(u16 *)(p + 0x54), &pos, 0, heap);
        func_0204B3DC((struct Obj *)*(u32 *)(p + i * 4 + 0x58), 0);
        func_0204B92C((struct Obj *)*(u32 *)(p + i * 4 + 0x58), 1);
    }
    *(u32 *)(p + 0x64) = func_02045B38(0, 2, 0xAD, heap);
    *(u32 *)(p + 0x68) = func_0201D7EC(0x17, 0, 0, 0, a3);
    *(u32 *)(p + 0x6C) = func_0201C450(0x1000, heap);
    func_021C53A0(p, *(const u16 **)(p + 0x7C), *(u32 *)(p + 0x64), *(u32 *)(p + 0x68),
        *(u32 *)(p + 0x6C), func_0200C40C(func_02012EBC(a0)), p + 0x58, a3);
    func_02041B6C(1);
    func_0207D63C(0x04000050, 2, 1, 12, 4);
    switch (mode) {
    case 0:
        func_02040618(1, 3, -0xC0);
        func_02040588(1, 0);
        *(u16 *)(p + 0x70) = 0;
        break;
    case 1:
        func_02040618(1, 3, 0);
        func_02040588(1, 1);
        *(u16 *)(p + 0x70) = 3;
        break;
    }
    return p;
}
