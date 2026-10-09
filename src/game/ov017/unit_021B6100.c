/*
 * file:     unit_021B6100.c
 * unit:     yes
 * function: func_021B6100, func_021B61F8, func_021B6298, func_021B6368
 * address:  0x021B6100
 * region:   ov017
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0202EB0C  0x0202EB0C  thumb
 *   func_020053EC  0x020053EC  thumb
 *   func_02034F5C  0x02034F5C  arm
 *   func_021B641C  0x021B641C  thumb  ov017
 *   func_0207D534  0x0207D534  arm
 *   func_020808F4  0x020808F4  arm
 *   func_020809A0  0x020809A0  arm
 *   func_0207FDCC  0x0207FDCC  arm
 *   func_0207D4B0  0x0207D4B0  arm
 *   func_0207E24C  0x0207E24C  arm
 *   func_02082A7C  0x02082A7C  arm
 *   func_0204A1BC  0x0204A1BC  arm
 *   func_02062A4C  0x02062A4C  arm
 *   func_020862F0  0x020862F0  arm
 *   func_02082A60  0x02082A60  arm
 *   func_020307B0  0x020307B0  arm
 *   func_02062B30  0x02062B30  arm
 *   func_0207DFB4  0x0207DFB4  arm
 *   func_02062AD4  0x02062AD4  arm
 *   func_02062A98  0x02062A98  arm
 *   func_02082A48  0x02082A48  arm
 *   func_02043754  0x02043754  arm
 *   func_0201D7EC  0x0201D7EC  thumb
 *   func_02045B38  0x02045B38  arm
 *   func_02045EC0  0x02045EC0  arm
 *   func_0201C7D0  0x0201C7D0  thumb
 *   func_02045808  0x02045808  arm
 *   func_02045C04  0x02045C04  arm
 *   func_0201D83C  0x0201D83C  thumb
 *   func_020437AC  0x020437AC  arm
 */
#define R32(a) (*(volatile u32 *)(a))
#define R16(a) (*(volatile u16 *)(a))
struct NitroFileHeader;
struct Bmp;
struct GfFont;
struct MsgBank;
struct Obj020437AC;
struct Rec;
struct U16Vec;
typedef unsigned short u16;

typedef unsigned int   u32;

typedef unsigned char u8;

typedef struct Chr {
    u8 pad00[0x10];
    u32 f10;
    void *f14;
} Chr;

typedef struct Scr {
    u8 pad00[0x8];
    u32 f08;
    u8 f0c[1];
} Scr;

typedef struct Pal {
    u8 pad00[0xc];
    void *f0c;
} Pal;

typedef signed int     s32;

typedef signed short   s16;

extern u32 func_0202EB0C(void);
extern void func_020053EC(void);
extern void func_02034F5C(void);
extern void func_021B641C(void);
extern void func_0207D534(volatile u16 *reg, int brightness);
extern int func_020808F4(void);
extern int func_020809A0(void);
extern void func_0207FDCC(int);
extern void func_0207D4B0(int, int, int);
extern void *func_0207E24C(void);
extern void func_02082A7C(u32 v, void *dst, u32 size);
extern int func_0204A1BC(int a0, int a1, int a2, int a3);
extern signed int func_02062A4C(struct NitroFileHeader *file, void **out);
extern void func_020862F0(void *p, u32 size);
extern void func_02082A60(void *src, void *dst, u32 size);
extern u32 func_020307B0(void *p);
extern int func_02062B30(void *file, void **out);
extern void *func_0207DFB4(void);
extern s32 func_02062AD4(struct NitroFileHeader *file, void **out);
extern s32 func_02062A98(struct NitroFileHeader *file, void **out);
extern void func_02082A48(int, u32, u32);
extern struct Bmp *func_02043754(void *pixels, u32 width, u32 height, u32 depth, u16 heap);
extern struct GfFont *func_0201D7EC(int a0, int a1, int a2, int a3, u32 heapId);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void func_0201C7D0(void *x, s16 y, s16 z, void *s, void *w, u16 v);
extern void func_02045808(struct U16Vec *vec);
extern u32 func_02045C04(struct Rec *rec);
extern u32 func_0201D83C(void *ptr);
extern void func_020437AC(struct Obj020437AC *p);
void func_021B6100(void);
void func_021B61F8(int a);
void func_021B6298(void);
void func_021B6368(int a);




static inline u16 ReadKeys(void)
{
    u16 k = (u16)(((*(volatile u16 *)0x04000130 | *(volatile u16 *)0x02FFFFA8) ^ 0x2FFF) & 0x2FFF);
    k = (u16)(k & ~((k & 0x40) << 1) & ~((k & 0x20) >> 1));
    return k;
}




void func_021B6100(void)
{
    func_021B61F8(func_0202EB0C() ? 0x2A : 0x10);
    while (ReadKeys() & 3) {
        func_020053EC();
        func_02034F5C();
    }
    while (!(ReadKeys() & 3)) {
        func_020053EC();
        func_02034F5C();
    }
    func_021B641C();
}




void func_021B61F8(int a)
{
    func_0207D534((volatile u16 *)0x0400006C, -16);
    func_0207D534((volatile u16 *)0x0400106C, -16);
    func_020808F4();
    func_020809A0();
    func_0207FDCC(4);
    func_0207D4B0(1, 0, 0);
    R32(0x04000000) = (R32(0x04000000) & 0xFFFFE0FF) | (1 << 9);
    R32(0x04000000) &= 0xFFFF1FFF;
    R16(0x0400000A) = (R16(0x0400000A) & 0x43) | 4;
    R16(0x0400000A) &= 0xFFBF;
    R32(0x04000014) = 0;
    R16(0x04000050) = 0;
    func_021B6298();
    func_021B6368(a);
    func_0207D534((volatile u16 *)0x0400006C, 0);
    func_0207D534((volatile u16 *)0x0400106C, 0x10);
}



static inline void Copy(void *src, void *dst, u32 size)
{
    func_02082A60(src, dst, size);
}



/*
 * Loads a background from archive 0x16: clears 0x4000 bytes of character
 * VRAM, then unpacks file 1 (characters), file 2 (screen) and file 0
 * (palette, 0x20 bytes to 0x05000000), flushing and copying each and
 * freeing the file buffer after each.
 *
 * The copy goes through an inline wrapper (or a dst local): a plain
 * call argument f(src, g(), p->size) loads the size after g(); the
 * original loads it before g() and keeps it in r5.
 */
void func_021B6298(void)
{
    Chr *chr;
    Scr *scr;
    Pal *pal;
    void *cmp;
    void *file;

    func_02082A7C(0, func_0207E24C(), 0x4000);

    file = (void *)func_0204A1BC(0x16, 1, 0, 1);
    if (func_02062A4C(file, (void **)(&chr))) {
        func_020862F0(chr->f14, chr->f10);
        Copy(chr->f14, func_0207E24C(), chr->f10);
    }
    func_020307B0(file);

    file = (void *)func_0204A1BC(0x16, 2, 0, 1);
    if (func_02062B30(file, (void **)(&scr))) {
        func_020862F0(scr->f0c, scr->f08);
        Copy(scr->f0c, func_0207DFB4(), scr->f08);
    }
    func_020307B0(file);

    file = (void *)func_0204A1BC(0x16, 0, 0, 1);
    func_02062AD4(file, &cmp);
    if (func_02062A98(file, (void **)(&pal))) {
        func_020862F0(pal->f0c, 0x20);
        Copy(pal->f0c, (void *)0x05000000, 0x20);
    }
    func_020307B0(file);
}


void func_021B6368(int a)
{
    u16 *base;
    int j, i;
    u16 v;
    int p, q, r, s;

    base = func_0207DFB4();
    v = 0x20;
    for (i = 4; i < 20; i++) {
        for (j = 1; j < 31; j++) {
            base[i * 32 + j] = v;
            v++;
        }
    }
    func_02082A48(0x7777, (u32)func_0207E24C() + 0x400, 0x3C00);
    p = (int)func_02043754((void *)((u32)func_0207E24C() + 0x400), 30, 16, 32, 1);
    q = (int)func_0201D7EC(0x17, 0, 0, 0, 1);
    r = (int)func_02045B38(0, 2, 0xe8, 1);
    s = (int)func_02045EC0((struct MsgBank *)r, a);
    func_0201C7D0((void *)p, 0, 0, (void *)s, (void *)q, 0x1167);
    func_02045808((struct U16Vec *)s);
    func_02045C04((struct Rec *)r);
    func_0201D83C((void *)q);
    func_020437AC((struct Obj020437AC *)p);
}
