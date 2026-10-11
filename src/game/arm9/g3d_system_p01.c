/*
 * file:     g3d_system_p01.c
 * unit:     yes
 * function: func_02046440, func_02046788, func_020467EC, func_02046858, func_02046A94, func_02046AFC, func_02046B40, func_02046BE0, func_02046BFC, func_02046C10, func_02046C24, func_02046C88, func_02046C94, sub_02046C9C, func_02046CE0, func_02046DB8, func_02046E24, func_02046E90, func_02046EFC, func_02046F48, func_02046F50, func_02046FCC, func_02046FF8, func_020470A8, func_020470D0, func_02047180, func_02047204, DWCi_LSTlPopFront, func_02047260, func_020472F8, func_02047348, func_02047388, func_020473B8, func_020473D8, func_020473EC, func_02047400, func_02047504, func_0204754C, func_02047554, func_0204755C, func_02047564, func_0204762C, func_02047674, func_0204767C, func_02047738, func_02047788, func_02047790, func_0204779C, func_020477A4, func_020477D4, func_02047804, func_02047828, func_0204784C, func_02047888, func_020478B8, func_02047910, func_02047964
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
 *   func_0206A884   0x0206A884  arm
 *   func_0206A8FC   0x0206A8FC  arm
 *   func_0206A854  0x0206A854  arm
 *   func_0206E964      0x0206E964  arm
 *   sG3dSystemFile  0x020A7EA8  data
 *   func_02048F60  0x02048F60  arm
 *   func_02049250  0x02049250  arm
 *   func_02048F9C  0x02048F9C  arm
 *   func_020307E0  0x020307E0  arm
 *   func_02069FF8  0x02069FF8  arm
 *   func_0206A124  0x0206A124  arm
 *   func_020862F0  0x020862F0  arm
 *   func_0206A00C  0x0206A00C  arm
 *   func_0206A12C  0x0206A12C  arm
 *   DC_FlushRange  0x020862F0  arm
 *   func_02069FD0  0x02069FD0  arm
 *   func_02069FE4  0x02069FE4  arm
 *   g_020A8140     0x020A8140  data
 *   g_020A8148     0x020A8148  data
 *   func_0206A110  0x0206A110  arm
 *   g_szG3DSystem   0x020A7EA8  data
 *   func_0206E954   0x0206E954  arm
 *   func_0206E348   0x0206E348  arm
 *   func_0206A2CC   0x0206A2CC  arm
 *   func_0206A4AC   0x0206A4AC  arm
 *   func_02069D14   0x02069D14  arm
 *   func_0206E358   0x0206E358  arm
 *   func_0206E9A4  0x0206E9A4  arm
 *   func_0206E364  0x0206E364  arm
 *   func_02069C74  0x02069C74  arm
 *   func_0206E388   0x0206E388  arm
 *   str_020A7EA8   0x020A7EA8  data
 *   func_02069E88  0x02069E88  arm
 *   func_02069F7C   0x02069F7C  arm
 *   func_0207DA8C  0x0207DA8C  arm
 */
#include "../../matched/include/Obj01315.h"
#include "../../matched/include/Obj06969.h"
#include "../../matched/include/Obj04802.h"
#include "../../matched/include/Obj03459.h"
#include "../../matched/include/Obj16033.h"
#include "../../matched/include/Obj16034.h"
#include "../../matched/include/Obj04073.h"
#include "../../matched/include/Obj09057.h"
#include "../../matched/include/Obj11417.h"
#include "../../matched/include/Obj16035.h"
#include "../../matched/include/Obj16042.h"
#include "../../matched/include/Obj16046.h"
#include "../../matched/include/Obj06972.h"
#include "../../matched/include/Obj16059.h"
#include "../../matched/include/Obj16062.h"

#define reg_G3X_DISP3DCNT   (*(volatile u16 *)0x04000060)
#define reg_G3_SWAP_BUFFERS (*(volatile u32 *)0x04000540)
#define reg_G3_VIEWPORT     (*(volatile u32 *)0x04000580)
struct S02046CE0;
struct ArcFile;
struct Up;
struct Layer_020472F8;
struct Tagged;
struct Tex;
struct Obj02061330;
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

struct Rec {
    u16 tag;
    u16 unk_02;
    u32 unk_04;
    void *unk_08;
};

struct S02046CE0 {
    u16 unk00;
    u16 result;
    u32 *tag;
};

struct G3dSys_0 {
    u8  pad00[0x18];
    u16 h18;            /* +0x18 */
};

struct Tagged {
    u16   tag;
    u16   pad02;
    void *buf;
};

struct Tagged_02046F50 {
    u16 tag;
    u16 kind;
};

struct Tagged_02046FCC {
    u16   tag;
    u16   pad02;
    void *buf;
};

struct Record {
    u8  pad00[0x14];
    u32 size;
};

struct BufHdr {
    u32 unk00;
    u32 unk04;
    u32 size;
};

struct Layer_020472F8 {
    u8  pad_00[0x1c];
    u16 pad_1c;
    u16 unk_1e;
    u16 unk_20;
};

struct Layer_02047348 {
    u8    pad_00[4];
    void *unk_04;
};

struct Ctl {
    u8  pad_00[8];
    u32 unk_08;
    u8  pad_0c[4];
    u16 unk_10;
    u8  pad_12[6];
    u32 unk_18;
    u8  pad_1c[4];
    u16 unk_20;
    u8  pad_22[0xa];
    u32 unk_2c;
    u8  pad_30[2];
    u16 unk_32;
};

typedef int s32_0;

typedef signed short   s16;

struct G3dCtx {
    u8  pad_00[0x18];
    u16 heap_id;
};

struct G3dSub {
    u32 pad_00;
    u32 handle;
};

struct G3dOwner {
    u32            pad_00;
    struct G3dSub *f04;
    u32            pad_08;
    struct G3dSub *f0c;
};

struct G3dRec {
    u16 tag;
    u16 unk_02;
    u32 unk_04;
    const struct G3dOwner *unk_08;
};

struct Mod {
    u8  pad_00[0x18];
    u16 f18;
};

struct Desc {
    u16 tag;
    u8  pad_02[2];
    u32 key;
    u32 array;
    u16 count;
};

struct G3dSlot {
    u32   unk_00;
    void *unk_04;
};

struct G3dInner {
    u32   unk_00;
    void *unk_04;
};

struct G3dSys_1 {
    u32               unk_00;
    struct G3dInner  *unk_04;
    struct G3dSlot  **slots;
};

struct Sub {
    u32 pad_00;
    u32 unk_04;
};

struct Mid {
    u32 pad_00;
    u32 unk_04;
};

struct Owner {
    u32      pad_00;
    struct Mid *unk_04;
    struct Sub **unk_08;
};

typedef signed int     s32_1;

struct AnmRes {
    u32 f0;
    u16 numFrame;       /* +4 */
};

struct AnmObj {
    s32_1 frame;          /* +0, fx32 */
    u32 f4;
    struct AnmRes *res; /* +8 */
};

struct AnmSlot {
    u32 f0;
    struct AnmObj *obj; /* +4 */
};

struct AnmCtl {
    u32 f0;
    u32 f4;
    struct AnmSlot **slots; /* +8 */
};

struct Run {
    u32 cur;
    u32 pad_04;
    u8 *desc;
};

struct Obj {
    u32 pad_00;
    struct Run *run;
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
extern void func_0206A884(void);
extern void func_0206A8FC(void);
extern void func_0206A854(void);
extern unsigned char *func_0206E964(unsigned char *p);
extern void *func_02048F60(u32 archive_id, u32 member, u32 heap);
extern void *func_02049250(struct ArcFile *arc, u32 member, u32 heap);
extern void *func_02048F9C(const char *path, u32 a, u32 heap);
extern void func_020307E0(void *p, u32 size);
extern void func_02069FF8(char *p, int a, int b);
extern void func_0206A124(int *p, int v);
extern void func_020862F0(int a, int b);
extern void func_0206A00C(struct Up *u, u32 wrap);
extern void func_0206A12C(int a, int b);
extern void func_0206A0C4(struct Tex *t, u32 *a, u32 *b);
extern u32   func_0206A17C(u8 *p);
extern void  DC_FlushRange(void *addr, u32 size);
extern int func_02069FD0(int p);
extern int func_02069FE4(int p);
extern int func_0206A110(int p);
extern int func_0206E954(int p0);
extern void *func_0206E348(void *);
extern void func_0206A2CC(void *, void *);
extern void func_0206A4AC(void *, void *);
extern void func_02069D14(void *, void *);
extern void func_0206E358(struct Obj02061330 *ctx, int field);
extern u8 *func_0206E9A4(u8 *p, u32 idx);
extern u32  func_0206E364(struct G3dCtx *a0, int a1, u32 a2);
extern void func_02069C74(u32 a0, int a1, u32 a2, int a3);
extern void func_0206E388(struct Obj02061330 *ctx, int field);
extern void func_02069E88(void *a, void *b);
extern void func_02069F7C(u32 a, u32 b);
extern void func_0207DA8C(void);
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
void func_02046C88(void);
int func_02046C94(void);
void sub_02046C9C(struct Rec *rec, u32 mode, u32 value);
void func_02046CE0(struct S02046CE0 *out, u32 *tag);
void *func_02046DB8(u32 a0, u32 a1);
void *func_02046E24(u32 a0, u32 a1);
void *func_02046E90(u32 a0, u32 a1);
void func_02046EFC(struct Tagged *p);
void *func_02046F48(struct Tagged *p);
u32 func_02046F50(struct Tagged_02046F50 *p, u32 sel);
void func_02046FCC(struct Tagged_02046FCC *p);
int func_02046FF8(int *self);
u32 func_020470A8(void *p);
int func_020470D0(u32 *p);
int func_02047180(u32 *p);
u32 func_02047204(struct Tagged *p);
asm void DWCi_LSTlPopFront(void);
int func_02047260(u32 a0, u32 *a1, u32 *a2);
int func_020472F8(struct Layer_020472F8 *layer, u32 *out);
int func_02047348(struct Layer_02047348 *layer);
u32 func_02047388(struct Layer_02047348 *layer);
u32 func_020473B8(struct Layer_02047348 *layer);
int func_020473D8(int a0);
int func_020473EC(int a0);
void *func_02047400(void *a0, u32 n, void *a2);
void func_02047504(struct Rec *p);
int func_0204754C(int *p);
int func_02047554(int *p);
int func_0204755C(int *p);
struct G3dRec *func_02047564(struct G3dOwner *a0, const struct G3dOwner *a1, int a2);
void func_0204762C(struct Rec *p);
int func_02047674(int p);
void *func_0204767C(u32 a0, u32 *a1, int a2);
void func_02047738(struct Rec *p);
int func_02047788(int *p);
int func_02047790(int *p, int i);
int func_0204779C(int *p);
u32 func_020477A4(struct G3dSys_1 *sys, u32 idx);
int func_020477D4(struct Owner *owner, u32 index);
u32 func_02047804(struct AnmCtl *c, u16 idx);
u32 func_02047828(struct AnmCtl *c, u32 idx, s32_1 *frame);
u32 func_0204784C(struct AnmCtl *c, u16 idx, s32_1 *frame);
int func_02047888(int *a, int idx, int *out);
int func_020478B8(void *a, int idx, int amount);
int func_02047910(void *a, int idx, int amount);
void func_02047964(void);
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
extern u8 sG3dSystemFile;
extern char g_szG3DSystem[];
extern char        str_020A7EA8[];









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


void func_02046C88(void)
{
    func_0206A854();
}














int func_02046C94(void){ return 8; }















/*
 * Initialise a counted record: the mode picks the halfword written at +2
 * (2, 3 and 4 for modes 1, 2 and 3), then the caller's value goes into the
 * word at +4 and the constant 0x48BF into the halfword at +0.  Modes other
 * than one to three leave the +2 field alone entirely, which is why the
 * last arm stores inside its own arm and the first two meet at a shared
 * store: the comparison chain tests 1, 2 and 3 in that order and falls
 * through to the tail for everything else.
 *
 * The function saves no lr because it calls nothing, so disasm.py gives it
 * no label; 0x48BF is too wide for a `mov` and is the pool word at the end.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_02046C9C.c \
 *       --func sub_02046C9C --addr 0x02046C9C --cc 1.1p1 --arm
 */
void sub_02046C9C(struct Rec *rec, u32 mode, u32 value)
{
    switch (mode) {
    case 1:
        rec->unk_02 = 2;
        break;
    case 2:
        rec->unk_02 = 3;
        break;
    case 3:
        rec->unk_02 = 4;
        break;
    }

    rec->unk_04 = value;
    rec->tag = 0x48BF;
}















/*
 * Classify a 4-byte archive/container tag and record the result.
 *
 * `out` is a three-field record: a u16 at +00 (constant 0x48BF), a u16
 * result code at +02, and the tag pointer itself at +04.  The tag is one
 * of the little-endian ASCII magics; the five audio-ish containers
 * (BVA0/BMA0/BCA0/BTA0/BTP0) all report 4, BMD0 reports 1 or 2 depending
 * on func_0206E964, BTX0 reports 3, anything else 0.
 *
 * Shape notes:
 *  - The case bodies are laid out in *source* order, not value order.  The
 *    comparison tree is value-ordered either way, but writing BMD0 first,
 *    BTX0 second, then the five 4-reporting cases puts the BMD0 arm at
 *    +0x80 and the shared `result = 4` arm at +0xA8, which is what the
 *    original does; the natural ascending order puts the 4-arm right after
 *    the tree and moves all four branch targets.
 *  - The five 4-reporting cases share one store because the arms are
 *    identical; only the value in r0 differs.
 *  - BMD0's two stores are the if/else written out (`= 2` in one arm,
 *    `= 1` in the other), which mwcc predicates rather than folds into a
 *    select.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02046CE0.c \
 *       --func func_02046CE0 --addr 0x02046CE0 --cc 1.1p1 --arm
 */
void func_02046CE0(struct S02046CE0 *out, u32 *tag)
{
    switch (*tag) {
    case 0x30444D42:
        if (func_0206E964((unsigned char *)tag) == 0) {
            out->result = 2;
        } else {
            out->result = 1;
        }
        break;
    case 0x30585442:
        out->result = 3;
        break;
    case 0x30415642:
    case 0x30414D42:
    case 0x30414342:
    case 0x30415442:
    case 0x30505442:
        out->result = 4;
        break;
    default:
        out->result = 0;
        break;
    }
    out->tag = tag;
    out->unk00 = 0x48BF;
}















/*
 * g3d_system.c's eight-byte-node allocators.  Three siblings, identical but
 * for the loader they call and the source line: read the size from the
 * global's +0x18 halfword, allocate eight bytes with file name and line, run
 * the loader for (arg0, arg1, that same halfword) and hand its result to
 * func_02046CE0 together with the new node.  The global is re-read after the
 * allocator call - the callee may have replaced it - which is why the second
 * `ldr r1, [r4]` is there.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02046DB8.c \
 *       --func func_02046DB8 --addr 0x02046DB8 --cc 1.1p1 --arm
 */
void *func_02046DB8(u32 a0, u32 a1)
{
    u8 *node = func_02030734(((struct G3dSys_0 *)g_02146A5C)->h18, 8, 0,
                             (const char *)&sG3dSystemFile, 0x2b4);

    func_02046CE0((struct S02046CE0 *)node, func_02048F60(a0, a1, ((struct G3dSys_0 *)g_02146A5C)->h18));
    return node;
}















/*
 * g3d_system.c's eight-byte-node allocators.  Three siblings, identical but
 * for the loader they call and the source line: read the size from the
 * global's +0x18 halfword, allocate eight bytes with file name and line, run
 * the loader for (arg0, arg1, that same halfword) and hand its result to
 * func_02046CE0 together with the new node.  The global is re-read after the
 * allocator call - the callee may have replaced it - which is why the second
 * `ldr r1, [r4]` is there.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02046E24.c \
 *       --func func_02046E24 --addr 0x02046E24 --cc 1.1p1 --arm
 */
void *func_02046E24(u32 a0, u32 a1)
{
    u8 *node = func_02030734(((struct G3dSys_0 *)g_02146A5C)->h18, 8, 0,
                             (const char *)&sG3dSystemFile, 0x2c8);

    func_02046CE0((struct S02046CE0 *)node, func_02049250((struct ArcFile *)a0, a1, ((struct G3dSys_0 *)g_02146A5C)->h18));
    return node;
}















/*
 * g3d_system.c's eight-byte-node allocators.  Three siblings, identical but
 * for the loader they call and the source line: read the size from the
 * global's +0x18 halfword, allocate eight bytes with file name and line, run
 * the loader for (arg0, arg1, that same halfword) and hand its result to
 * func_02046CE0 together with the new node.  The global is re-read after the
 * allocator call - the callee may have replaced it - which is why the second
 * `ldr r1, [r4]` is there.
 *
 * Promoted by parks lane 2: the loader 0x02048F9C was filed first as an
 * EXACT entry (src/matched/func_02048F9C.c, shard pkt_02048F9C) and the call
 * at +0x48 now resolves through the `matched` class.  No change to the C.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02046E90.c \
 *       --func func_02046E90 --addr 0x02046E90 --cc 1.1p1 --arm
 */
void *func_02046E90(u32 a0, u32 a1)
{
    u8 *node = func_02030734(((struct G3dSys_0 *)g_02146A5C)->h18, 8, 0,
                             (const char *)&sG3dSystemFile, 0x2dc);

    func_02046CE0((struct S02046CE0 *)node, func_02048F9C((const char *)a0, a1, ((struct G3dSys_0 *)g_02146A5C)->h18));
    return node;
}















/*
 * The guarded destructor of the 0x48BF-tagged object, 0x02046EFC-0x02046F48
 * including its one pool word.  A NULL handle is a no-op, and so is a handle
 * whose tag halfword is not 0x48BF; otherwise the tag is stamped down to
 * 0x48BE ("freed"), the owned buffer at +4 is released and nulled, and the
 * object itself is released.
 *
 * The two tags are one pool word and a `sub r1, r1, #1`: 0x48BF is not an
 * ARM rotated immediate so it costs a pool word, and 0x48BE is then derived
 * from it rather than pooled a second time, the same accounting as
 * docs/idioms/consecutive-line-numbers-are-one-pool-word-and-adds.md.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02046EFC.c \
 *       --addr 0x02046EFC --cc 1.1p1 --arm
 */
void func_02046EFC(struct Tagged *p)
{
    if (p == 0) {
        return;
    }
    if (p->tag != 0x48BF) {
        return;
    }
    p->tag = 0x48BE;
    if (p->buf != 0) {
        func_020307B0(p->buf);
        p->buf = 0;
    }
    func_020307B0(p);
}















/*
 * The buffer accessor of the 0x48BF-tagged object whose destructor is
 * src/matched/unit_02046EFC.c: the pointer at +4, returned by value.  No
 * relocation, two instructions, no label of its own in the listing
 * (docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md).
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_02046F48.c \
 *       --func func_02046F48 --addr 0x02046F48 --cc 1.1p1 --arm
 */
void *func_02046F48(struct Tagged *p)
{
    return p->buf;
}














/*
 * A five-way predicate over the halfword at +2: the second argument picks
 * which set of values counts as a hit.  The dispatch is the ARM dense-switch
 * form, `addls pc, pc, r1, lsl #2` over four `b`s with the default reached by
 * the `b` that falls out of the bounds test, so the cases really are 0 to 3
 * with nothing missing (docs/idioms/dense-switch-is-a-pc-relative-halfword-table.md
 * is the Thumb form of the same tell).
 *
 * Case 1 is a range test written as one in the source, not a disjunction:
 * this front end does not fold `v == 1 || v == 2` into a range, it emits the
 * `cmp`/`cmpne` pair that cases 2 and 3 show.  The `lsl #16`/`lsr #16`
 * narrowing and the unsigned `cmp #1` are likewise spelled in the C.
 *
 * The bias is written `+ 0xFFFF`, not `- 1`.  Both mean the same thing after
 * the halfword narrowing, but `- 1` compiles to a single `sub r0, r0, #1`
 * and `+ 0xFFFF` to the pair `add r0, r0, #0xff` / `add r0, r0, #0xff00`,
 * because 0xFFFF is not an ARM rotated immediate and splits into two that
 * are.  Four bytes, and the only thing that separates the two readings.  See
 * docs/idioms/a-plus-0xffff-bias-is-two-adds-and-a-minus-one-is-one-sub.md.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_02046F50.c \
 *       --func func_02046F50 --addr 0x02046F50 --cc 1.1p1 --arm
 */
u32 func_02046F50(struct Tagged_02046F50 *p, u32 sel)
{
    u16 v = p->kind;

    switch (sel) {
    case 0:
        return v == 0;
    case 1:
        return (u16)(v + 0xFFFF) <= 1;
    case 2:
        return v == 1 || v == 3;
    case 3:
        return v == 4;
    }
    return 0;
}














/*
 * Shrink the 0x48BF-tagged object's buffer to exactly what it holds:
 * 0x0206E964 walks the buffer and returns the address of its last record,
 * that record's own length lives at +0x14, and the new size handed to the
 * heap trimmer at 0x020307E0 is the distance from the buffer's base to the
 * end of that record.
 *
 * The returned pointer is copied out of r0 into r2 before it is used, which
 * is the tell that it is a named local and not an inline call argument
 * (docs/idioms/an-inline-call-argument-is-scheduled-per-site-a-local-is-not.md).
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_02046FCC.c \
 *       --func func_02046FCC --addr 0x02046FCC --cc 1.1p1 --arm
 */
void func_02046FCC(struct Tagged_02046FCC *p)
{
    void          *buf = p->buf;
    struct Record *last = (struct Record *)func_0206E964(buf);

    func_020307E0(buf, (u32)((u8 *)last + last->size - (u8 *)buf));
}













/*
 * First guard exits through the shared epilogue at the end of the function
 * (a plain `return 0` there is if-converted and loses the branch).
 */
int func_02046FF8(int *self)
{
    int v8;
    int v4;
    int v0;
    int h;
    int p;

    h = self[1];
    p = (int)func_0206E964((unsigned char *)h);
    if (p == 0)
        goto fail;
    if (func_02047260(p, (u32 *)(&v8), (u32 *)(&v4)) == 0)
        return 0;
    if (func_020472F8((struct Layer_020472F8 *)p, (u32 *)(&v0)) == 0)
        return 0;
    func_02069FF8((char *)p, v8, v4);
    func_0206A124((int *)p, v0);
    func_020862F0(h, *(int *)&((struct Obj04802 *)h)->f8);
    func_0206A00C((struct Up *)p, 1);
    func_0206A12C(p, 1);
    return 1;
fail:
    return 0;
}













/*
 * "Build, then trim": run the builder at 0x02046FF8 over the tagged object
 * and, only if it reports success, shrink the buffer with 0x02046FCC.  The
 * zero return is predicated (`moveq`/`popeq`) rather than branched, which is
 * the whole body being two statements long.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_020470A8.c \
 *       --func func_020470A8 --addr 0x020470A8 --cc 1.1p1 --arm
 */
u32 func_020470A8(void *p)
{
    if (func_02046FF8(p) == 0) {
        return 0;
    }
    func_02046FCC(p);
    return 1;
}












/*
 * Byte-correct, MATCH-capped.  NOT in the manifest; see src/pending/README.md.
 *
 * 176 bytes, 0x020470D0..0x02047180, one function, every concrete byte
 * reproduced (0 differing bytes of 176) -- the diff is empty apart from the
 * two wildcarded call fields.
 *
 * Blocked on the `label` class at two addresses, both of which are in
 * ANOTHER PACKET (the pair lives in pkt_0206A12C and above, which this lane
 * does not own):
 *
 *   +0x40  bl func_0206A0C4   the reader, called (p, &x, &y)
 *   +0x8C  bl func_0206A17C   reached only through the callback below
 *
 * Neither address is matched, parked or labelled outside this range, so both
 * sites stay wildcarded.  Nothing in this C changes when they are filed.
 *
 * Two spellings in here are worth keeping:
 *
 *  - The two "is this bit set" locals are spelled as an int initialised to 0
 *    and set to 1 in the body, NOT as `f = (x & 1) != 0`.  The boolean form
 *    makes mwcc emit a movne/moveq pair per local and loses the original's
 *    `movs r5, #0 / movs r6, r5` up front; the explicit init keeps them.
 *  - The closing callback takes func_0206A17C's RETURN value as its
 *    argument: `(*(void (**)(u32))0x020A814C)(func_0206A17C(r))`.  Spelled as
 *    a bare `(...)()` call mwcc uses r0 for the loaded pointer and blx r0;
 *    the original loads into r1 and blx r1 precisely because r0 is already
 *    holding the argument.  Passing the call's result is what forces r1.
 *
 * The three callbacks are called through globals at 0x020A8144 and
 * 0x020A814C, written as numeric casts so the pool word stays a plain
 * literal rather than a relocation.
 */
int func_020470D0(u32 *p)
{
    u8  *r;
    int  f1;
    int  f2;
    u32  x;
    u32  y;

    r = func_0206E964((unsigned char *)p[1]);
    f1 = 0;
    f2 = 0;
    if (((struct Obj03459 *)r)->f10 & 1)
        f1 = 1;
    if (((struct Obj03459 *)r)->f20 & 1)
        f2 = 1;
    func_0206A0C4((struct Tex *)r, &x, &y);
    if (f1)
        (*(void (**)(u32))0x020A8144)(x);
    if (f2)
        (*(void (**)(u32))0x020A8144)(y);
    if ((((struct Obj03459 *)r)->f32 & 1) != 0 && ((struct Obj03459 *)r)->f30 != 0)
        (*(void (**)(u32))0x020A814C)(func_0206A17C(r));
    return 1;
}












int func_02047180(u32 *p)
{
    u32 h;
    u32 a;
    u32 b;
    u32 c;

    h = (u32)func_0206E964((unsigned char *)p[1]);
    if (h == 0)
        goto fail;
    if (func_02047260(h, &a, &b) == 0)
        return 0;
    if (func_020472F8((struct Layer_020472F8 *)h, &c) == 0)
        return 0;
    func_02069FF8((char *)h, a, b);
    func_0206A124((int *)h, c);
    return 1;
fail:
    return 0;
}












/*
 * Publish the built buffer: locate its last record with 0x0206E964, bail out
 * if there is none, flush the buffer's own byte length (the word at +8 of
 * the buffer header) out of the data cache, then hand the record to the two
 * upload routines and report success.
 *
 * The literal 1 is materialised once into r4 and serves as both upload
 * calls' second argument and the return value
 * (docs/idioms/a-small-constant-is-rematerialised-off-a-zero-register-unless-an-argument-shares-it.md,
 * read in the direction where the argument does share it).
 *
 * `movs r5, r0` doing the NULL test on the way into the callee-saved
 * register is what a named local assigned from the call and then tested
 * looks like.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_02047204.c \
 *       --func func_02047204 --addr 0x02047204 --cc 1.1p1 --arm
 */
u32 func_02047204(struct Tagged *p)
{
    struct BufHdr *buf = p->buf;
    void          *last = func_0206E964((unsigned char *)buf);

    if (last == 0) {
        return 0;
    }
    DC_FlushRange(buf, buf->size);
    func_0206A00C(last, 1);
    func_0206A12C((int)last, 1);
    return 1;
}











asm void DWCi_LSTlPopFront(void)
{
    ldr r0, [r0, #4]
    ldr ip, =func_0206E964
    bx ip
}











extern u32 (*g_020A8140)(void *p, u32 mode, u32 a2);











/*
 * The two probes are looked up independently; the same dispatcher is called
 * for each, once in mode 0 and once in mode 1, with the first probe's handle
 * (which is necessarily null in the second branch) in r0.  Either failure
 * report is a bare zero.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02047260.c \
 *       --func func_02047260 --addr 0x02047260 --cc 1.1p1 --arm
 */
int func_02047260(u32 a0, u32 *a1, u32 *a2)
{
    void *p = (void *)func_02069FD0(a0);
    void *q = (void *)func_02069FE4(a0);

    if (p != 0) {
        *a1 = g_020A8140(p, 0, 0);
        if (*a1 == 0)
            return 0;
    }
    if (q != 0) {
        *a2 = g_020A8140(p, 1, 0);
        if (*a2 == 0)
            return 0;
    }
    return 1;
}











extern u32 (*g_020A8148)(u32 handle, u32 flags, u32 zero);











/*
 * Open one layer: ask func_0206A110 for the layer's handle (a zero handle
 * is the failure path and answers 1), then call the current handler out of
 * the function pointer at 0x020A8148 with the handle, the layer's bit
 * 0x8000 of the halfword at +0x20 and a zero, and store what it returns
 * through the caller's out pointer.
 *
 * `h != 0` is spelled as two statements, not as a comparison: the zero is
 * already live in r4 (it was r2 for the indirect call), so the failure path
 * is a predicated `moveq r0, r4` plus `popeq`, and the success path is the
 * plain `mov r0, #1`.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020472F8.c \
 *       --func func_020472F8 --addr 0x020472F8 --cc 1.1p1 --arm
 */
int func_020472F8(struct Layer_020472F8 *layer, u32 *out)
{
    u32 h;

    h = func_0206A110((int)layer);
    if (h == 0)
        goto ret1;

    h = g_020A8148(h, layer->unk_20 & 0x8000, 0);
    *out = h;
    if (h == 0)
        return 0;
ret1:
    return 1;
}











/*
 * Three consecutive accessors on the object a layer record points at
 * through +4, 64 + 48 + 32 bytes with no padding between them.  The object
 * carries three "ready" bits, one per halfword at +0x10, +0x20 and +0x32,
 * and each bit guards the word at +8, +0x18 and +0x2c respectively.
 *
 * func_02047348 asks whether any of the three is set: the first two tests
 * are early `return 1`s, which is why they branch forward to a shared
 * one-exit and the third is written as the inverted guard (`if (!bit)
 * return 0;`) whose fall-through carries the `return 1`.
 *
 * func_02047388 and func_020473B8 return the guarded word itself, so their
 * arms are single instructions and the compiler if-converts them into
 * predicated `ldrne` / `moveq` on the entry compare; the third test in
 * func_02047388 is the one that stays a real branch pair.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02047348.c \
 *       --addr 0x02047348 --arm
 */
int func_02047348(struct Layer_02047348 *layer)
{
    struct Ctl *p = (struct Ctl *)func_0206E964(layer->unk_04);

    if ((p->unk_10 & 1) || (p->unk_20 & 1) || (p->unk_32 & 1))
        return 1;
    return 0;
}










u32 func_02047388(struct Layer_02047348 *layer)
{
    struct Ctl *p = (struct Ctl *)func_0206E964(layer->unk_04);

    if (p->unk_10 & 1)
        return p->unk_08;
    if (p->unk_20 & 1)
        return p->unk_18;
    return 0;
}










u32 func_020473B8(struct Layer_02047348 *layer)
{
    struct Ctl *p = (struct Ctl *)func_0206E964(layer->unk_04);

    if (p->unk_32 & 1)
        return p->unk_2c;
    return 0;
}











int func_020473D8(int a0){ int t0 = func_02047250(); return (t0 + ((struct Obj16033 *)((char *)(t0)))->f14); }










int func_020473EC(int a0){ int t0 = func_02047250(); return (t0 + ((struct Obj16034 *)((char *)(t0)))->f38); }










/*
 * Construct a 0x7A14-tagged record (the sibling of func_02047564's 0x59D1
 * one): look the owner's +4 handle up through func_0206E954, index its
 * table by `n` to a byte offset, turn that into a pointer, optionally take
 * a second handle from a2, allocate 0x10 bytes out of the context's heap
 * with `g3d_system.c:1544` as the __FILE__/__LINE__ pair, fill the tag and
 * the two owner slots, and register it.
 *
 * WHY THE GOTOS.  Two earlier waves (see docs/notes/pkt_02047400.c.txt)
 * landed three instructions (12 bytes) short with the structured
 * `if (p) { b = p + 8; if (b) { if (n < p[9]) { ... } } }` plus a ternary
 * for q, in five spellings.  The residue was a front-end if-conversion:
 * mwcc predicated the five-instruction `ofs` body (`ldrhlo`/`addlo`/
 * `mlalo`) and therefore hoisted `ofs = 0` before the guards as
 * `mov r2, r4`, and it predicated the q selection as `moveq r5, #0`.
 *
 * The image does neither.  It gives `ofs = 0` its own out-of-line block at
 * +0x50 with TWO predecessors (the `b == 0` and the `n >= p[9]` guards) and
 * an unconditional `b` over it from the body, and it sends the `p == 0`
 * test straight to an out-of-line `q = 0` at +0x64.  Writing those two
 * join blocks as explicit `goto` targets is what reproduces them: with the
 * body no longer the only path into its successor, the front end has no
 * single-block region left to predicate, so the five instructions come out
 * bare and the missing `b` and `bne` appear.  This is the general form of
 * docs/idioms/guards-separated-by-statements-share-an-exit-only-through-goto.md
 * applied to a join rather than to an exit.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02047400.c \
 *       --func func_02047400 --addr 0x02047400 --cc 1.1p1 --arm
 */
void *func_02047400(void *a0, u32 n, void *a2)
{
    u32 z;
    u8 *p;
    u8 *b;
    void *q;
    void *obj;
    u8 *ofs;
    u32 idx;
    u32 cnt;

    z = 0;
    p = (u8 *)func_0206E954((int)(((struct Obj09057 *)a0)->f4));
    if (p == 0) goto qzero;
    b = p + 8;
    if (b == 0) goto ozero;
    if (n >= p[9]) goto ozero;
    idx = ((struct Obj11417 *)p)->fE;
    cnt = *(u16 *)(b + idx);
    ofs = (u8 *)(cnt * n + (s32_0)(b + idx + 4));
    goto join;
ozero:
    ofs = 0;
join:
    if (ofs != 0) { q = (void *)(p + ((struct Obj16035 *)ofs)->f0); goto have; }
qzero:
    q = 0;
have:
    ;

    if (a2 != 0) z = (u32)func_0206E964(((struct Obj09057 *)a2)->f4);

    obj = func_02030734(*(u16 *)((u8 *)g_02146A5C + 0x18),
                        0x10, 0, g_szG3DSystem, 0x608);
    ((struct Obj04073 *)obj)->f0 = 0x7A14;
    ((struct Obj04073 *)obj)->f8 = a0;
    ((struct Obj04073 *)obj)->fC = a2;
    ((struct Obj04073 *)obj)->f4 = func_0206E348(g_02146A5C);
    if (z != 0) {
        func_0206A2CC(q, (void *)z);
        func_0206A4AC(q, (void *)z);
    }
    func_02069D14(((struct Obj04073 *)obj)->f4, q);
    return obj;
}










/*
 * Release one tagged record: nothing at all for a null pointer, and nothing
 * for a record whose halfword tag at +0 is not 0x7A14.  Otherwise hand the
 * pointer's +4 field to func_0206E358, drop the tag to one below its own
 * value and free the record.
 *
 * The tag is pooled once (0x7A14 is past a `mov` immediate) and reused for
 * the decrement, which is why the new value arrives as `sub r1, r4, #1`
 * rather than as a second literal; the `mov r0, r5` before the store is the
 * free call's argument being set up early.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02047504.c \
 *       --func func_02047504 --addr 0x02047504 --cc 1.1p1 --arm
 */
void func_02047504(struct Rec *p)
{
    if (p == 0)
        return;
    if (p->tag != 0x7A14)
        return;

    func_0206E358((struct Obj02061330 *)g_02146A5C, p->unk_04);
    p->tag = 0x7A14 - 1;
    func_020307B0(p);
}








int func_0204754C(int *p){ return p[2]; }








int func_02047554(int *p){ return p[3]; }








int func_0204755C(int *p){ return p[1]; }









/*
 * g3d_system.c.  Allocate a 12-byte record from the context heap (tag
 * 0x59D1, owner a1), fetch animation a2 from a1's resource
 * (func_0206E9A4), allocate the animation object against a0's model
 * (func_0206E364) and initialise it with a0's texture when a0 has one
 * (func_02047554 / func_0206E964, then func_02069C74).
 *
 * The lever (wave 16) is `const` on the read-only owner parameter a1 (and
 * the record field that keeps it): with a1 const the a1->f04 load may move
 * above the tag store, and the scheduler then issues the tag's pool load
 * first exactly as the image does.  Without const every spelling left the
 * four instructions after the allocation in the other order (11 bytes out,
 * docs/notes/pkt_02047564.c.txt).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02047564.c  *       --func func_02047564 --addr 0x02047564 --arm
 */
struct G3dRec *func_02047564(struct G3dOwner *a0, const struct G3dOwner *a1, int a2)
{
    struct G3dRec *r;
    int x;
    u32 y;
    int z = 0;

    r = func_02030734(((struct G3dCtx *)g_02146A5C)->heap_id, 0xC, 0, g_020A7EA8, 0x6D2);
    r->tag = 0x59D1;
    r->unk_08 = a1;
    x = (int)func_0206E9A4((u8 *)a1->f04, a2);
    y = a0->f04->handle;
    if (func_02047554((int *)a0) != 0)
        z = (int)func_0206E964((unsigned char *)a0->f0c->handle);
    r->unk_04 = func_0206E364(((struct G3dCtx *)g_02146A5C), x, y);
    func_02069C74(r->unk_04, x, y, z);
    return r;
}






/*
 * The sibling of func_02047504 for the other record tag: 0x59D1 instead of
 * 0x7A14 and func_0206E388 instead of func_0206E358.  Everything else,
 * including the register allocation and the reuse of the pooled tag for the
 * decrement, is identical.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0204762C.c \
 *       --func func_0204762C --addr 0x0204762C --cc 1.1p1 --arm
 */
void func_0204762C(struct Rec *p)
{
    if (p == 0)
        return;
    if (p->tag != 0x59D1)
        return;

    func_0206E388((struct Obj02061330 *)g_02146A5C, p->unk_04);
    p->tag = 0x59D1 - 1;
    func_020307B0(p);
}








/*
 * Unlabelled ARM leaf getter: return the word at +4.  disasm.py never
 * traced a func_ start here (the listing emits these bytes as data words),
 * so the caller func_021BE748 in ov021 had no witness for its bl; this
 * entry supplies the `matched` class.
 */
int func_02047674(int p)
{
    return ((struct Obj16042 *)p)->f4;
}







/*
 * Allocate a 0x10-byte descriptor from the module heap: a 0x2185 tag, the
 * caller's key, the count, and -- only when the count is non-zero -- a second
 * allocation of count*4 bytes holding a copy of the caller's array.  Both
 * allocations pass the same module name and differ only in their line
 * constant (0x75b and 0x765).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0204767C.c \
 *       --func func_0204767C --addr 0x0204767C --cc 1.1p1 --arm
 */
void *func_0204767C(u32 a0, u32 *a1, int a2)
{
    struct Desc *d;
    int i;

    d = (struct Desc *)func_02030734(((struct Mod *)g_02146A5C)->f18, 0x10, 0, str_020A7EA8,
                                     0x75b);
    d->tag = 0x2185;
    d->key = a0;
    d->count = (u16)a2;
    if (a2 == 0) {
        d->array = 0;
    } else {
        d->array = (u32)func_02030734(((struct Mod *)g_02146A5C)->f18, a2 * 4, 1, str_020A7EA8,
                                 0x765);
        if (a1 != 0 && (int)a2 > 0) {
            for (i = 0; i < a2; i++)
                ((u32 *)d->array)[i] = a1[i];
        }
    }
    return d;
}







/*
 * Retire one record: a null pointer and a mismatched tag 0x2185 are both
 * passed over by predicated returns, then the owned pointer at +8 is freed
 * and cleared (only if it was set) before the tag is left at 0x2184 and the
 * record itself is freed.  Both tags are past a `mov` immediate and so are
 * two pool words at the end of the function.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02047738.c \
 *       --func func_02047738 --addr 0x02047738 --cc 1.1p1 --arm
 */
void func_02047738(struct Rec *p)
{
    if (p == 0)
        return;
    if (p->tag != 0x2185)
        return;

    if (p->unk_08 != 0) {
        func_020307B0(p->unk_08);
        p->unk_08 = 0;
    }

    p->tag = 0x2184;
    func_020307B0(p);
}





int func_02047788(int *p){ return p[1]; }





int func_02047790(int *p, int i){ return ((int *)p[2])[i]; }






int func_0204779C(int *p){ return ((struct Obj16046 *)p)->fC; }






/*
 * Dispatch one slot of the G3D system's object table, reporting whether the
 * slot was occupied.  The empty case is the conditional early return
 * `moveq r0, #0 / popeq {r3, pc}`, so the two exits carry different constants
 * and neither arm is shared.
 *
 * The three `ldr ..., #4` loads interleave two independent chains, the
 * system's own +0x04 -> +0x04 pointer walk and the slot's +0x04 payload;
 * scheduling them together is what puts the slot's load in the middle.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020477A4.c \
 *       --func func_020477A4 --addr 0x020477A4 --cc 1.1p1 --arm
 */
u32 func_020477A4(struct G3dSys_1 *sys, u32 idx)
{
    struct G3dSlot *slot = sys->slots[idx];

    if (slot == 0) {
        return 0;
    }

    func_02069E88(sys->unk_04->unk_04, slot->unk_04);
    return 1;
}





/*
 * Parked: byte correct, capped at MATCH by the evidence rather than by the C.
 *
 * Hand the indexed sub-record's +4 word to func_02069F7C, along with the
 * owner's own +4 record's +4 word: the pointer chain is two `ldr`s deep on
 * the owner side and one on the sub-record side, and nothing is loaded until
 * the null test has passed, because the failure path is a predicated
 * `moveq`/`popeq` off the compare.
 *
 * Every concrete byte is right.  The single PC24 stays wildcarded: 0x02069F7C
 * is called from this site and nowhere else the harness can see, it is not in
 * the manifest, and a one-function range admits no cut (--suggest-split cannot
 * help).  Blocking evidence class: label/matched, no witness.  It unsticks the
 * moment 0x02069F7C is itself EXACT (`matched` class) or a second caller of it
 * turns up in an overlay.
 *
 * The `*` is the unlabelled follower at 0x02047804 (a leaf with no lr-saving
 * prologue) making disasm.py's extent for the original run to 0x02047970.
 */
int func_020477D4(struct Owner *owner, u32 index)
{
    struct Sub *sub = owner->unk_08[index];

    if (sub == 0)
        return 0;

    func_02069F7C(owner->unk_04->unk_04, sub->unk_04);
    return 1;
}





/*
 * Two siblings of func_0204784C over the same slot table at +8: a null slot
 * returns 0; otherwise the first clears the slot object's frame and the
 * second stores it to *frame, and both return 1.  Seeded from ov021
 * 0x0218C064 and 0x0218C486 (blx).
 *
 * Addresses are Black-image addresses.
 */
u32 func_02047804(struct AnmCtl *c, u16 idx)
{
    struct AnmSlot *s = c->slots[idx];

    if (s == 0) {
        return 0;
    }
    s->obj->frame = 0;
    return 1;
}




u32 func_02047828(struct AnmCtl *c, u32 idx, s32_1 *frame)
{
    struct AnmSlot *s = c->slots[idx];

    if (s == 0) {
        return 0;
    }
    *frame = s->obj->frame;
    return 1;
}





/*
 * ARM leaf, seeded 2026-09-27 from the ov195 call sites 0x02208B3E and
 * 0x02208B48 (func_02208AB0). Looks up slot idx of the table at +8; a
 * null slot returns 0. Otherwise it sets the slot object's frame to
 * *frame, clamped from above to numFrame << 12 (the u16 at +4 of the
 * object's resource), with a signed compare (strge/strlt), and returns 1.
 * Siblings at 0x02047804, 0x02047828, 0x020478B8 and 0x02047910 share the
 * slot lookup and are still unlabelled.
 *
 * Addresses are Black-image addresses.
 */
u32 func_0204784C(struct AnmCtl *c, u16 idx, s32_1 *frame)
{
    struct AnmSlot *s = c->slots[idx];
    struct AnmObj *a;

    if (s == 0) {
        return 0;
    }
    a = s->obj;
    if (*frame >= (s32_1)(a->res->numFrame << 12)) {
        a->frame = a->res->numFrame << 12;
    } else {
        a->frame = *frame;
    }
    return 1;
}





/*
 * Looks up entry idx of the table at a[2]; on a hit stores the u16 at
 * entry->f4->f8->f4 shifted to 20.12 fixed point and returns 1.  Filed as the
 * witness for ov021 func_021D0750.
 */
int func_02047888(int *a, int idx, int *out)
{
    int *p = ((int **)a[2])[idx];
    if (p == 0) {
        return 0;
    }
    *out = ((u16 *)((int *)p[1])[2])[2] << 12;
    return 1;
}




/*
 * Unlabelled ARM leaf: advance a clamped counter.  a is a table base whose
 * slot [idx] holds an object; the object's word at +4 points at a run state
 * (counter at +0, descriptor pointer at +8) whose descriptor's u16 at +4 is a
 * limit in units of 0x1000.  Adds amount to the counter; if it reaches the
 * limit it rewinds by one 0x1000 and returns 0, if it goes negative it pins to
 * zero and returns 0, otherwise returns 1.
 */
int func_020478B8(void *a, int idx, int amount)
{
    struct Obj **tbl = *(struct Obj ** *)&((struct Obj06972 *)a)->f8;
    struct Obj *e = tbl[idx];
    struct Run *r;
    int nv;
    u32 lim;

    if (e == 0) {
        return 0;
    }

    r = e->run;
    nv = (int)r->cur + amount;
    r->cur = (u32)nv;

    lim = (u32)((struct Obj16059 *)(r->desc))->f4 << 12;
    if (nv >= (int)lim) {
        r->cur = lim - 0x1000;
        return 0;
    }
    if (nv < 0) {
        r->cur = 0;
        return 0;
    }
    return 1;
}




/*
 * Unlabelled ARM leaf: the sibling of func_020478B8 with a different clamp
 * policy.  Advance the counter of the run state reached through a's table slot
 * [idx]; if it reaches the descriptor limit it pins the counter to zero and
 * returns 0, if it goes negative it pins it to the limit and returns 0,
 * otherwise returns 1.
 */
int func_02047910(void *a, int idx, int amount)
{
    struct Obj **tbl = *(struct Obj ** *)&((struct Obj06972 *)a)->f8;
    struct Obj *e = tbl[idx];
    struct Run *r;
    int nv;
    u32 lim;

    if (e == 0) {
        return 0;
    }

    r = e->run;
    nv = (int)r->cur + amount;
    r->cur = (u32)nv;

    lim = (u32)((struct Obj16062 *)(r->desc))->f4 << 12;
    if (nv >= (int)lim) {
        r->cur = 0;
        return 0;
    }
    if (nv < 0) {
        r->cur = lim;
        return 0;
    }
    return 1;
}


void func_02047964(void)
{
    func_0207DA8C();
}
