/*
 * function: func_02046440
 * address:  0x02046440
 * packet:   pkt_02046440
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   g_02146A5C         0x02146A5C  data
 *   g_020A7EA8         0x020A7EA8  data
 *   d_020A1308         0x020A1308  data
 *   d_020A1E38         0x020A1E38  data
 *   d_020A1300         0x020A1300  data
 *   d_020A1328         0x020A1328  data
 *   func_02030734      0x02030734  arm
 *   func_0206DF14      0x0206DF14  arm
 *   G3X_InitMtxStack   0x0207DB1C  arm
 *   func_0206A700      0x0206A700  arm
 *   func_02030BBC      0x02030BBC  arm
 *   func_0206DB40      0x0206DB40  arm
 *   func_020307C8      0x020307C8  arm
 *   func_0206210C      0x0206210C  arm
 *   func_02062114      0x02062114  arm
 *   func_020613D8      0x020613D8  arm
 *   func_0206246C      0x0206246C  arm
 *   func_02062474      0x02062474  arm
 *   func_02046858      0x02046858  arm
 *   func_02046A94      0x02046A94  arm
 *   func_02046B40      0x02046B40  arm
 *   func_02046BE0      0x02046BE0  arm
 *   func_02046C24      0x02046C24  arm
 *   G3X_SetFog         0x0207DC44  arm
 *   G3X_SetClearColor  0x0207DD24  arm
 *
 * The g3d_system.c constructor (line 92 allocation): allocates the 0xA0
 * context into g_02146A5C, brings up the geometry engine, optionally
 * sizes the command FIFO buffer (clamped to 0x1800), sets up texture and
 * palette VRAM managers (or the fixed-bank mode when the mode argument is
 * non-zero; note the palette arm's else-branch clears +0x14, not +0x10,
 * as the image does), pushes the default projection, four viewport
 * rectangles and the three view blocks, and finally either calls the
 * caller's setup hook or applies the SDK defaults (G3X_SetShading(0),
 * AntiAlias/AlphaTest/AlphaBlend/EdgeMarking off, G3X_SetFog off,
 * G3X_SetClearColor(0, 0, 0x7fff, 63, FALSE), G3_ViewPort(0, 0, 255, 191)).
 *
 * Written from scratch in wave 11.  Two declarations close it: the three
 * stack buffers are declared s32, s36, r (the later declaration takes the
 * lower address: sp+0x30, +0x0C, +0x04), and the heap parameter is s16
 * (tools/permuter.py, type:p(heap:u16->s16)); as u16 the compiler re-reads
 * it from its stack home instead of holding it in r8 across the first
 * allocation, and the whole body shifts by one instruction.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef int            BOOL;

#define reg_G3X_DISP3DCNT   (*(volatile u16 *)0x04000060)
#define reg_G3_SWAP_BUFFERS (*(volatile u32 *)0x04000540)
#define reg_G3_VIEWPORT     (*(volatile u32 *)0x04000580)

struct G3dCtx {
    u8    pad_00[0x10];
    void *f10;
    void *f14;
    u16   heap_id;
    u8    pad_1a[0x8c - 0x1a];
    u32   f8c;
    u32   f90;
    u8    pad_94[4];
    u32   f98;
    u32   f9c;
};

struct Setup32 { u32 w[8]; };
struct Setup36 { u32 w[9]; };
struct Rect16  { u16 h[4]; };

extern struct G3dCtx *g_02146A5C;
extern char g_020A7EA8[];
extern const struct Setup32 d_020A1308;
extern const u8 d_020A1E38[];
extern const struct Rect16 d_020A1300;
extern const struct Setup36 d_020A1328;

extern void *func_02030734(u16 heap, u32 size, u32 clear, const char *file, u32 line);
extern void  func_0206DF14(void);
extern void  G3X_InitMtxStack(void);
extern void  func_0206A700(void);
extern u32  *func_02030BBC(u32 size);
extern void  func_0206DB40(u32 *p);
extern void  func_020307C8(void *p, u16 heap, u32 n);
extern int func_0206210C(int v);
extern void  func_02062114(u32 a, u32 b, void *c, u32 d, u32 e);
extern void  func_020613D8(u32 mode, u32 flag);
extern int func_0206246C(int v);
extern void  func_02062474(u32 a, void *b, u32 c, u32 d);
extern void  func_02046858(const struct Setup32 *p);
extern void  func_02046A94(u32 index, const struct Rect16 *r);
extern void  func_02046B40(struct Setup36 *p);
extern void  func_02046BE0(u32 a, u32 b);
extern void  func_02046C24(u32 mode);
extern void  G3X_SetFog(BOOL enable, int mode, int slope, int offset);
extern void  G3X_SetClearColor(u16 rgb, int alpha, int depth, int polygonID, BOOL fog);

void func_02046440(u32 texMode, u32 texSize, u32 plttMode, u32 plttSize,
                   u16 fifoSize, s16 heap, void (*setup)(void))
{
    struct Setup32 s32;
    struct Setup36 s36;
    struct Rect16 r;
    u32 size;

    g_02146A5C = func_02030734(heap, 0xa0, 0, g_020A7EA8, 0x5c);
    g_02146A5C->heap_id = heap;
    g_02146A5C->f8c = texMode;
    g_02146A5C->f90 = plttMode;

    func_0206DF14();
    G3X_InitMtxStack();
    func_0206A700();

    if (fifoSize != 0)
        func_0206DB40(func_02030BBC(fifoSize > 0x1800 ? 0x1800 : fifoSize));

    reg_G3_SWAP_BUFFERS = 2;
    func_020307C8(g_02146A5C, g_02146A5C->heap_id, 4);

    if (texMode == 0) {
        size = func_0206210C(texSize << 7);
        g_02146A5C->f14 = func_02030734(g_02146A5C->heap_id, size, 0, g_020A7EA8, 0x7e);
        func_02062114(texSize << 17, 0, g_02146A5C->f14, size, 1);
    } else {
        func_020613D8((u16)texSize, 1);
        g_02146A5C->f14 = 0;
    }

    if (plttMode == 0) {
        size = func_0206246C(plttSize << 9);
        g_02146A5C->f10 = func_02030734(g_02146A5C->heap_id, size, 0, g_020A7EA8, 0x8d);
        func_02062474(plttSize << 14, g_02146A5C->f10, size, 1);
    } else {
        func_020613D8((u16)(plttSize << 14), 1);
        g_02146A5C->f14 = 0;
    }

    s32 = d_020A1308;
    s32.w[1] = *(s16 *)(d_020A1E38 + 0x8c);
    s32.w[2] = *(s16 *)(d_020A1E38 + 0x8e);
    func_02046858(&s32);

    r = d_020A1300;
    func_02046A94(0, &r);
    func_02046A94(1, &r);
    func_02046A94(2, &r);
    func_02046A94(3, &r);

    s36 = d_020A1328;
    func_02046B40(&s36);
    func_02046BE0(0, 1);
    func_02046C24(0);

    if (setup != 0) {
        setup();
    } else {
        reg_G3X_DISP3DCNT = (u16)((reg_G3X_DISP3DCNT & ~(0x0002 | 0x3000)) | (0 << 1));
        reg_G3X_DISP3DCNT &= ~(0x0010 | 0x3000);
        reg_G3X_DISP3DCNT &= ~(0x0004 | 0x3000);
        reg_G3X_DISP3DCNT &= ~(0x0008 | 0x3000);
        reg_G3X_DISP3DCNT &= ~(0x0020 | 0x3000);
        G3X_SetFog(0, 0, 0, 0);
        G3X_SetClearColor(0, 0, 0x7fff, 63, 0);
        reg_G3_VIEWPORT = 0xBFFF0000;
    }

    g_02146A5C->f98 = 0;
    g_02146A5C->f9c = 0;
}
