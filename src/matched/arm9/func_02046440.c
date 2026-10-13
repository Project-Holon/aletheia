/*
 * function: G3D_SYSTEM_Init
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
 *   _G3dSystem         0x02146A5C  data
 *   G3D_SYSTEM_FileName         0x020A7EA8  data
 *   _DefaultProjection         0x020A1308  data
 *   d_020A1E38         0x020A1E38  data
 *   _DefaultLight         0x020A1300  data
 *   _DefaultLookAt         0x020A1328  data
 *   func_02030734      0x02030734  arm
 *   NNS_G3dInit      0x0206DF14  arm
 *   G3X_InitMtxStack   0x0207DB1C  arm
 *   func_0206A700      0x0206A700  arm
 *   func_02030BBC      0x02030BBC  arm
 *   NNS_G3dGeSetBuffer      0x0206DB40  arm
 *   func_020307C8      0x020307C8  arm
 *   func_0206210C      0x0206210C  arm
 *   func_02062114      0x02062114  arm
 *   func_020613D8      0x020613D8  arm
 *   func_0206246C      0x0206246C  arm
 *   func_02062474      0x02062474  arm
 *   G3D_SYSTEM_SetProjection      0x02046858  arm
 *   G3D_SYSTEM_SetLight      0x02046A94  arm
 *   G3D_SYSTEM_SetLookAt      0x02046B40  arm
 *   G3D_SYSTEM_SetSwapBuffersMode      0x02046BE0  arm
 *   G3D_SYSTEM_SetGlbFlushMode      0x02046C24  arm
 *   G3X_SetFog         0x0207DC44  arm
 *   G3X_SetClearColor  0x0207DD24  arm
 *
 * The g3d_system.c constructor (line 92 allocation): allocates the 0xA0
 * context into _G3dSystem, brings up the geometry engine, optionally
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

extern struct G3dCtx *_G3dSystem;
extern char G3D_SYSTEM_FileName[];
extern const struct Setup32 _DefaultProjection;
extern const u8 d_020A1E38[];
extern const struct Rect16 _DefaultLight;
extern const struct Setup36 _DefaultLookAt;

extern void *func_02030734(u32 heap, u32 size, int clear, const char *file, u16 line);
extern void  NNS_G3dInit(void);
extern void  G3X_InitMtxStack(void);
extern void  func_0206A700(void);
extern void *func_02030BBC(u32 a0);
extern void  NNS_G3dGeSetBuffer(u32 *p);
extern void  func_020307C8(void *p, u16 heap, u32 n);
extern int func_0206210C(int v);
extern void func_02062114(u32 a, u32 b, u32 c, u32 d, u32 e);
extern void  func_020613D8(u32 mode, u32 flag);
extern int func_0206246C(int v);
extern void func_02062474(u32 a, u32 b, u32 c, u32 d);
extern void G3D_SYSTEM_SetProjection(const u32 *src);
extern void G3D_SYSTEM_SetLight(u32 idx, const u16 *src);
extern void G3D_SYSTEM_SetLookAt(u8 *a0);
extern void  G3D_SYSTEM_SetSwapBuffersMode(u32 a, u32 b);
extern void  G3D_SYSTEM_SetGlbFlushMode(u32 mode);
extern void  G3X_SetFog(BOOL enable, int mode, int slope, int offset);
extern void  G3X_SetClearColor(u16 rgb, int alpha, int depth, int polygonID, BOOL fog);

void G3D_SYSTEM_Init(u32 texMode, u32 texSize, u32 plttMode, u32 plttSize,
                   u16 fifoSize, s16 heap, void (*setup)(void))
{
    struct Setup32 s32;
    struct Setup36 s36;
    struct Rect16 r;
    u32 size;

    _G3dSystem = func_02030734((u16)heap, 0xa0, 0, G3D_SYSTEM_FileName, 0x5c);
    _G3dSystem->heap_id = heap;
    _G3dSystem->f8c = texMode;
    _G3dSystem->f90 = plttMode;

    NNS_G3dInit();
    G3X_InitMtxStack();
    func_0206A700();

    if (fifoSize != 0)
        NNS_G3dGeSetBuffer(func_02030BBC(fifoSize > 0x1800 ? 0x1800 : fifoSize));

    reg_G3_SWAP_BUFFERS = 2;
    func_020307C8(_G3dSystem, _G3dSystem->heap_id, 4);

    if (texMode == 0) {
        size = func_0206210C(texSize << 7);
        _G3dSystem->f14 = func_02030734(_G3dSystem->heap_id, size, 0, G3D_SYSTEM_FileName, 0x7e);
        func_02062114(texSize << 17, 0, (u32)_G3dSystem->f14, size, 1);
    } else {
        func_020613D8((u16)texSize, 1);
        _G3dSystem->f14 = 0;
    }

    if (plttMode == 0) {
        size = func_0206246C(plttSize << 9);
        _G3dSystem->f10 = func_02030734(_G3dSystem->heap_id, size, 0, G3D_SYSTEM_FileName, 0x8d);
        func_02062474(plttSize << 14, (u32)_G3dSystem->f10, size, 1);
    } else {
        func_020613D8((u16)(plttSize << 14), 1);
        _G3dSystem->f14 = 0;
    }

    s32 = _DefaultProjection;
    s32.w[1] = *(s16 *)(d_020A1E38 + 0x8c);
    s32.w[2] = *(s16 *)(d_020A1E38 + 0x8e);
    G3D_SYSTEM_SetProjection((const u32 *)(&s32));

    r = _DefaultLight;
    G3D_SYSTEM_SetLight(0, (const u16 *)(&r));
    G3D_SYSTEM_SetLight(1, (const u16 *)(&r));
    G3D_SYSTEM_SetLight(2, (const u16 *)(&r));
    G3D_SYSTEM_SetLight(3, (const u16 *)(&r));

    s36 = _DefaultLookAt;
    G3D_SYSTEM_SetLookAt((u8 *)(&s36));
    G3D_SYSTEM_SetSwapBuffersMode(0, 1);
    G3D_SYSTEM_SetGlbFlushMode(0);

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

    _G3dSystem->f98 = 0;
    _G3dSystem->f9c = 0;
}
