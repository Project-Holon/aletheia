/*
 * file:     g3d_system_p01.c
 * unit:     yes
 * function: func_02046440, func_02046788, func_020467EC, func_02046858, func_02046A94, func_02046AFC, func_02046B40, func_02046BE0, func_02046BFC, func_02046C10, func_02046C24
 * address:  0x02046440
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
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
 *   G3X_SetFog         0x0207DC44  arm
 *   G3X_SetClearColor  0x0207DD24  arm
 *   func_020307B0   0x020307B0  arm
 *   func_0206DB24   0x0206DB24  arm
 *   func_0206DB60   0x0206DB60  arm
 *   func_02030BC8   0x02030BC8  arm
 *   g_02148B54     0x02148B54  data
 *   g_02148B4C     0x02148B4C  data
 *   func_0207C408  0x0207C408  arm
 *   func_0207C1D0  0x0207C1D0  arm
 *   func_0207C554  0x0207C554  arm
 *   func_0206AA3C 0x0206AA3C  arm
 *   func_0206AA78 0x0206AA78  arm
 *   func_0207BCA0    0x0207BCA0  arm
 *   g_02148B98       0x02148B98  data
 *   g_02148D8C       0x02148D8C  data
 *   g_02148D98       0x02148D98  data
 *   g_02148DA4       0x02148DA4  data
 *   func_02046C88   0x02046C88  arm
 *   func_0206A884   0x0206A884  arm
 *   func_0206A8FC   0x0206A8FC  arm
 */
#include "../../matched/include/Obj01315.h"
#include "../../matched/include/Obj06969.h"

typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed short   s16_0;

typedef int            BOOL;

struct G3dCtx_0 {
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

struct Ctx_0 {
    u8    pad_00[0x10];
    void *unk_10;
    void *unk_14;
};

struct G3dCtx_1 {
    u8  pad_00[0x1c];
    u32 mode;
    u32 f20;
    u32 f24;
    u32 f28;
    u32 f2c;
    u32 f30;
    u32 f34;
    u32 f38;
};

typedef short          s16_1;

struct Tri {
    u32 a;
    u32 b;
    u32 c;
};

typedef struct {
    u32 w[3];
} Blk;

struct Ctx_1 {
    u8  pad_00[0x80];
    u32 unk_80;
    u32 unk_84;
};

struct Ctx {
    u8  pad_00[0x88];
    void *unk_88;
};

extern void *func_02030734(u32 heap, u32 size, int clear, const char *file, u16 line);
extern void  func_0206DF14(void);
extern void  G3X_InitMtxStack(void);
extern void  func_0206A700(void);
extern void *func_02030BBC(u32 a0);
extern void  func_0206DB40(u32 *p);
extern void  func_020307C8(void *p, u16 heap, u32 n);
extern int func_0206210C(int v);
extern void func_02062114(u32 a, u32 b, u32 c, u32 d, u32 e);
extern void  func_020613D8(u32 mode, u32 flag);
extern int func_0206246C(int v);
extern void func_02062474(u32 a, u32 b, u32 c, u32 d);
extern void  G3X_SetFog(BOOL enable, int mode, int slope, int offset);
extern void  G3X_SetClearColor(u16 rgb, int alpha, int depth, int polygonID, BOOL fog);
extern u32 func_020307B0(void *p);
extern u32   func_0206DB24(void);
extern void *func_0206DB60(void);
extern int   func_02030BC8(u32 idx);
extern void func_0207C408(u32 a0, u32 a1, u32 a2, u32 a3, u32 s0, u32 s1, void *s2);
extern void func_0207C1D0(u32 a0, u32 a1, u32 a2, u32 a3, u32 s0, u32 s1, u32 s2, void *s3);
extern void func_0207C554(u32 a0, u32 a1, u32 a2, u32 a3, u32 s0, u32 s1, u32 s2, void *s3);
extern void func_0206AA3C(int idx, int a, int b, int c);
extern void func_0206AA78(int idx, u32 v);
extern void func_0207BCA0(void *a0, void *a1, void *a2, void *a3);
extern void func_02046C88(void);
extern void func_0206A884(void);
extern void func_0206A8FC(void);
void func_02046440(u32 texMode, u32 texSize, u32 plttMode, u32 plttSize, u16 fifoSize, s16_0 heap, void (*setup)(void));
void func_02046788(void);
void func_020467EC(int p0);
void func_02046858(const u32 *src);
void func_02046A94(u32 idx, const u16 *src);
void func_02046AFC(u8 *dst);
void func_02046B40(u8 *a0);
void func_02046BE0(u32 a, u32 b);
int func_02046BFC(void);
int func_02046C10(void);
void func_02046C24(u32 mode);
extern void *g_02146A5C;
extern char g_020A7EA8[];
extern const struct Setup32 d_020A1308;
extern const u8 d_020A1E38[];
extern const struct Rect16 d_020A1300;
extern const struct Setup36 d_020A1328;
extern u8  g_02148B54[];
extern u32 g_02148B4C[];
extern Blk g_02148D8C;
extern Blk g_02148D98;
extern Blk g_02148DA4;
extern Blk g_02148B98;








#define reg_G3X_DISP3DCNT   (*(volatile u16 *)0x04000060)







#define reg_G3_SWAP_BUFFERS (*(volatile u32 *)0x04000540)







#define reg_G3_VIEWPORT     (*(volatile u32 *)0x04000580)








/*
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
void func_02046440(u32 texMode, u32 texSize, u32 plttMode, u32 plttSize,
                   u16 fifoSize, s16_0 heap, void (*setup)(void))
{
    struct Setup32 s32;
    struct Setup36 s36;
    struct Rect16 r;
    u32 size;

    g_02146A5C = func_02030734((u16)heap, 0xa0, 0, g_020A7EA8, 0x5c);
    ((struct G3dCtx_0 *)g_02146A5C)->heap_id = heap;
    ((struct G3dCtx_0 *)g_02146A5C)->f8c = texMode;
    ((struct G3dCtx_0 *)g_02146A5C)->f90 = plttMode;

    func_0206DF14();
    G3X_InitMtxStack();
    func_0206A700();

    if (fifoSize != 0)
        func_0206DB40(func_02030BBC(fifoSize > 0x1800 ? 0x1800 : fifoSize));

    reg_G3_SWAP_BUFFERS = 2;
    func_020307C8(((struct G3dCtx_0 *)g_02146A5C), ((struct G3dCtx_0 *)g_02146A5C)->heap_id, 4);

    if (texMode == 0) {
        size = func_0206210C(texSize << 7);
        ((struct G3dCtx_0 *)g_02146A5C)->f14 = func_02030734(((struct G3dCtx_0 *)g_02146A5C)->heap_id, size, 0, g_020A7EA8, 0x7e);
        func_02062114(texSize << 17, 0, (u32)((struct G3dCtx_0 *)g_02146A5C)->f14, size, 1);
    } else {
        func_020613D8((u16)texSize, 1);
        ((struct G3dCtx_0 *)g_02146A5C)->f14 = 0;
    }

    if (plttMode == 0) {
        size = func_0206246C(plttSize << 9);
        ((struct G3dCtx_0 *)g_02146A5C)->f10 = func_02030734(((struct G3dCtx_0 *)g_02146A5C)->heap_id, size, 0, g_020A7EA8, 0x8d);
        func_02062474(plttSize << 14, (u32)((struct G3dCtx_0 *)g_02146A5C)->f10, size, 1);
    } else {
        func_020613D8((u16)(plttSize << 14), 1);
        ((struct G3dCtx_0 *)g_02146A5C)->f14 = 0;
    }

    s32 = d_020A1308;
    s32.w[1] = *(s16_0 *)(d_020A1E38 + 0x8c);
    s32.w[2] = *(s16_0 *)(d_020A1E38 + 0x8e);
    func_02046858((const u32 *)(&s32));

    r = d_020A1300;
    func_02046A94(0, (const u16 *)(&r));
    func_02046A94(1, (const u16 *)(&r));
    func_02046A94(2, (const u16 *)(&r));
    func_02046A94(3, (const u16 *)(&r));

    s36 = d_020A1328;
    func_02046B40((u8 *)(&s36));
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

    ((struct G3dCtx_0 *)g_02146A5C)->f98 = 0;
    ((struct G3dCtx_0 *)g_02146A5C)->f9c = 0;
}







/*
 * Shut the module down: free the two owned pointers at +0x10 and +0x14 if
 * they are set, run the paired stop only when func_0206DB24 answers exactly
 * one, and finally free the context itself and null its slot.
 *
 * The context pointer is re-read from its slot for every use, so the two
 * guards each carry their own `ldr`; only the last statement caches the
 * slot's address in r4, because it needs it again for the store of zero.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02046788.c \
 *       --func func_02046788 --addr 0x02046788 --cc 1.1p1 --arm
 *
 * Parked: byte correct, capped at MATCH by the evidence rather than by the C.
 *
 * Every concrete byte is right; the site(s) above stay wildcarded because 0206DB24
 * has exactly one witness image wide and it is the branch inside this very range.
 * Blocking evidence class: label/matched, no outside witness.  It unsticks when the
 * callee is itself EXACT (the `matched` class) or a second caller turns up.
 *
 * Parked: byte correct, capped at MATCH by the evidence rather than by the C.
 * Blocking evidence class: label/matched, no outside witness.  0x0206DB24 is
 * called from this site and nowhere else the harness can see, so its PC24
 * stays wildcarded; matching 0x0206DB24 elsewhere (or a second caller)
 * closes it.
 */
void func_02046788(void)
{
    if (((struct Ctx_0 *)g_02146A5C)->unk_10 != 0)
        func_020307B0(((struct Ctx_0 *)g_02146A5C)->unk_10);
    if (((struct Ctx_0 *)g_02146A5C)->unk_14 != 0)
        func_020307B0(((struct Ctx_0 *)g_02146A5C)->unk_14);

    if (func_0206DB24() == 1) {
        func_02030BC8((u32)func_0206DB60());
    }

    func_020307B0(((struct Ctx_0 *)g_02146A5C));
    g_02146A5C = 0;
}









void func_020467EC(int p0){ *(int *)&((struct Obj01315 *)p0)->f0 = (int)*(int *)((*(int *)(0x2146A5C) + 28)); *(int *)&((struct Obj01315 *)p0)->f4 = (int)*(int *)((*(int *)(0x2146A5C) + 32)); *(int *)&((struct Obj01315 *)p0)->f8 = (int)*(int *)((*(int *)(0x2146A5C) + 36)); *(int *)&((struct Obj01315 *)p0)->fC = (int)*(int *)((*(int *)(0x2146A5C) + 40)); *(int *)&((struct Obj01315 *)p0)->f10 = (int)*(int *)((*(int *)(0x2146A5C) + 44)); *(int *)&((struct Obj01315 *)p0)->f14 = (int)*(int *)((*(int *)(0x2146A5C) + 48)); *(int *)&((struct Obj01315 *)p0)->f18 = (int)*(int *)((*(int *)(0x2146A5C) + 52)); *(int *)&((struct Obj01315 *)p0)->f1C = (int)*(int *)((*(int *)(0x2146A5C) + 56)); }







/*
 * Store an eight-word projection setup into the context (+0x1C mode,
 * +0x20..+0x38 parameters), then program it through one of three setup
 * calls selected by the mode; a zero +0x38 is replaced by 0x1000.  Every
 * arm clears bits 0x50 of g_02148B4C[0x3F] and returns on its own.
 *
 * Closed in wave 11.  What the older notes were missing:
 *   - the register-block pointer is taken into a named local (`hw`)
 *     BEFORE the dispatch; it is what lives in r4 across each call, which
 *     is why the image pushes r4 and can use it as the second prologue
 *     temporary (without it the push is {r3, lr} and the pipelined stores
 *     alternate ip/r3);
 *   - +0x38 selects between two calls per mode (0x1000 when zero, the
 *     field itself otherwise), not an OR with 0x1000;
 *   - mode 0 passes seven arguments (no +0x2C), modes 1 and 2 eight.
 */
void func_02046858(const u32 *src)
{
    u32 *hw;

    ((struct G3dCtx_1 *)g_02146A5C)->mode = src[0];
    ((struct G3dCtx_1 *)g_02146A5C)->f20 = src[1];
    ((struct G3dCtx_1 *)g_02146A5C)->f24 = src[2];
    ((struct G3dCtx_1 *)g_02146A5C)->f28 = src[3];
    ((struct G3dCtx_1 *)g_02146A5C)->f2c = src[4];
    ((struct G3dCtx_1 *)g_02146A5C)->f30 = src[5];
    ((struct G3dCtx_1 *)g_02146A5C)->f34 = src[6];
    ((struct G3dCtx_1 *)g_02146A5C)->f38 = src[7];
    hw = g_02148B4C;

    switch (((struct G3dCtx_1 *)g_02146A5C)->mode) {
    case 0:
        if (((struct G3dCtx_1 *)g_02146A5C)->f38 == 0) {
            func_0207C408(((struct G3dCtx_1 *)g_02146A5C)->f20, ((struct G3dCtx_1 *)g_02146A5C)->f24, ((struct G3dCtx_1 *)g_02146A5C)->f28, ((struct G3dCtx_1 *)g_02146A5C)->f30,
                ((struct G3dCtx_1 *)g_02146A5C)->f34, 0x1000, g_02148B54);
            hw[0x3F] &= ~0x50u;
            return;
        }
        func_0207C408(((struct G3dCtx_1 *)g_02146A5C)->f20, ((struct G3dCtx_1 *)g_02146A5C)->f24, ((struct G3dCtx_1 *)g_02146A5C)->f28, ((struct G3dCtx_1 *)g_02146A5C)->f30,
            ((struct G3dCtx_1 *)g_02146A5C)->f34, ((struct G3dCtx_1 *)g_02146A5C)->f38, g_02148B54);
        hw[0x3F] &= ~0x50u;
        return;
    case 1:
        if (((struct G3dCtx_1 *)g_02146A5C)->f38 == 0) {
            func_0207C1D0(((struct G3dCtx_1 *)g_02146A5C)->f20, ((struct G3dCtx_1 *)g_02146A5C)->f24, ((struct G3dCtx_1 *)g_02146A5C)->f28, ((struct G3dCtx_1 *)g_02146A5C)->f2c,
                ((struct G3dCtx_1 *)g_02146A5C)->f30, ((struct G3dCtx_1 *)g_02146A5C)->f34, 0x1000, g_02148B54);
            hw[0x3F] &= ~0x50u;
            return;
        }
        func_0207C1D0(((struct G3dCtx_1 *)g_02146A5C)->f20, ((struct G3dCtx_1 *)g_02146A5C)->f24, ((struct G3dCtx_1 *)g_02146A5C)->f28, ((struct G3dCtx_1 *)g_02146A5C)->f2c,
            ((struct G3dCtx_1 *)g_02146A5C)->f30, ((struct G3dCtx_1 *)g_02146A5C)->f34, ((struct G3dCtx_1 *)g_02146A5C)->f38, g_02148B54);
        hw[0x3F] &= ~0x50u;
        return;
    case 2:
        if (((struct G3dCtx_1 *)g_02146A5C)->f38 == 0) {
            func_0207C554(((struct G3dCtx_1 *)g_02146A5C)->f20, ((struct G3dCtx_1 *)g_02146A5C)->f24, ((struct G3dCtx_1 *)g_02146A5C)->f28, ((struct G3dCtx_1 *)g_02146A5C)->f2c,
                ((struct G3dCtx_1 *)g_02146A5C)->f30, ((struct G3dCtx_1 *)g_02146A5C)->f34, 0x1000, g_02148B54);
            hw[0x3F] &= ~0x50u;
            return;
        }
        func_0207C554(((struct G3dCtx_1 *)g_02146A5C)->f20, ((struct G3dCtx_1 *)g_02146A5C)->f24, ((struct G3dCtx_1 *)g_02146A5C)->f28, ((struct G3dCtx_1 *)g_02146A5C)->f2c,
            ((struct G3dCtx_1 *)g_02146A5C)->f30, ((struct G3dCtx_1 *)g_02146A5C)->f34, ((struct G3dCtx_1 *)g_02146A5C)->f38, g_02148B54);
        hw[0x3F] &= ~0x50u;
        return;
    }
}






/*
 * A four-halfword record written into an eight-byte slot of the global
 * context at index `idx` (the slot base is ctx + idx*8 and the record starts
 * at +0x3c of it), then the same fields read back signed for the first
 * notification call and unsigned for the second.  The context pointer is
 * re-read from its slot once per statement group because each call may
 * replace it, which is why the field accesses are not CSE'd into one load.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02046A94.c \
 *       --func func_02046A94 --addr 0x02046A94 --cc 1.1p1 --arm
 */
void func_02046A94(u32 idx, const u16 *src)
{
    u8 *p = ((u8 *)g_02146A5C) + idx * 8;

    ((struct Obj06969 *)p)->f3C = src[0];
    ((struct Obj06969 *)p)->f3E = src[1];
    ((struct Obj06969 *)p)->f40 = src[2];
    ((struct Obj06969 *)p)->f42 = src[3];

    func_0206AA3C(idx, *(s16_1 *)(((u8 *)g_02146A5C) + idx * 8 + 0x3c),
                  *(s16_1 *)(((u8 *)g_02146A5C) + idx * 8 + 0x3e),
                  *(s16_1 *)(((u8 *)g_02146A5C) + idx * 8 + 0x40));
    func_0206AA78(idx, *(u16 *)(((u8 *)g_02146A5C) + idx * 8 + 0x42));
}




/*
 * Copy three twelve-byte groups out of the context: +0x5c to the caller's
 * +0, +0x68 to +0xc and +0x74 to +0x18.  Each group is one nested struct
 * assignment, which this compiler emits as a paired ldm/stm of three words
 * (docs/idioms/aggregate-assignment-is-ldm-stm.md) - three separate field
 * copies would be nine loads and nine stores.
 *
 * The context is read once: the three assignments are not separated by any
 * call, so the pointer stays live in ip, and the calling argument is kept in
 * lr while the first two destinations are built into r0/r3.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02046AFC.c \
 *       --func func_02046AFC --addr 0x02046AFC --cc 1.1p1 --arm
 */
void func_02046AFC(u8 *dst)
{
    *(struct Tri *)(dst + 0x00) = *(struct Tri *)(((u8 *)g_02146A5C) + 0x5c);
    *(struct Tri *)(dst + 0x0c) = *(struct Tri *)(((u8 *)g_02146A5C) + 0x68);
    *(struct Tri *)(dst + 0x18) = *(struct Tri *)(((u8 *)g_02146A5C) + 0x74);
}




void func_02046B40(u8 *a0)
{
    u8 *o = (u8 *)((u32 *)g_02146A5C);

    *(Blk *)(o + 0x5C) = *(Blk *)a0;
    *(Blk *)(o + 0x68) = *(Blk *)(a0 + 0xC);
    *(Blk *)(o + 0x74) = *(Blk *)(a0 + 0x18);
    g_02148D8C = *(Blk *)(o + 0x5C);
    g_02148D98 = *(Blk *)(o + 0x68);
    g_02148DA4 = *(Blk *)(o + 0x74);
    func_0207BCA0(o + 0x5C, o + 0x68, o + 0x74, &g_02148B98);
    g_02148B4C[0x3F] &= ~0xE8u;
}


/*
 * Store the pair of words at +0x80 and +0x84 of the context at 0x02146A5C.
 * The context pointer is re-read from its own slot between the two stores,
 * because the first store cannot be proven not to alias it; the second load
 * therefore goes to r0, the register the outgoing value no longer needs.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02046BE0.c \
 *       --func func_02046BE0 --addr 0x02046BE0 --cc 1.1p1 --arm
 */
void func_02046BE0(u32 a, u32 b)
{
    ((struct Ctx_1 *)g_02146A5C)->unk_80 = a;
    ((struct Ctx_1 *)g_02146A5C)->unk_84 = b;
}



int func_02046BFC(void){ return *(int *)((*(int *)(0x2146A5C) + 140)); }

int func_02046C10(void){ return *(int *)((*(int *)(0x2146A5C) + 144)); }



/*
 * Parked: byte correct, capped at MATCH by the evidence rather than by the C.
 *
 * Install one of three handlers into the context's +0x88 word.  Modes 1 and
 * 2 have their own constant; mode 0 and everything else share the third
 * block, which is why the comparison chain starts at zero and the shared
 * body sits immediately after the last compare.
 *
 * The three values are code addresses: 0x0206A884 and 0x0206A8FC are
 * ordinary functions and 0x02046C88 is the eight-byte ARM tail stub
 * `ldr ip, [pc, #0]; bx ip; .word 0x0206A854` (attested as `veneer`), so the
 * mode-0 handler goes through one extra hop.
 *
 * Two of the four sites stay wildcarded: 0x0206A884 and 0x0206A8FC each have
 * exactly one witness image wide and it is the pool word inside this range.
 * Blocking evidence class: label/matched, no outside witness.  Either address
 * being matched elsewhere (`matched` class) closes it.
 *
 * The `*` is the unlabelled follower at 0x02046C88 - the tail stub itself is
 * inside this listing's extent because nothing in it saves lr.
 */
void func_02046C24(u32 mode)
{
    switch (mode) {
    case 0:
    default:
        ((struct Ctx *)g_02146A5C)->unk_88 = func_02046C88;
        break;
    case 1:
        ((struct Ctx *)g_02146A5C)->unk_88 = func_0206A884;
        break;
    case 2:
        ((struct Ctx *)g_02146A5C)->unk_88 = func_0206A8FC;
        break;
    }
}
