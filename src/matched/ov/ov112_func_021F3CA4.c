/*
 * function: MUSICAL_SHOT_SYS_Init3D
 * address:  0x021F3CA4
 * packet:   pkt_ov112_021F3CA4
 * region:   ov112
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * 2026-10-05 (user decision): the u32 return in the ARC_UTIL_UploadPaletteFromHandle declaration (void definition) is accepted as a real mismatched declaration.
 * note (2026-10-05, wave D9r lane 70): closed from 422 differing bytes. The residue (3 and 1 held
 *   in r7/r4 in the head, late r3 zeros copied from r6) came from the return type of
 *   ARC_UTIL_UploadPaletteFromHandle: declared u32 instead of void, the head constant webs and the fresh late zeros
 *   come out as in the original. func_02049658 is u32 as in the matched ov123 021D9D3C and
 *   ov210 021BC5DC callers (its helper 0x0204968C returns r4). Caveat for review: the matched
 *   arm9 definition of ARC_UTIL_UploadPaletteFromHandle is void, and its helper 0x02049C28 sets no return value on
 *   its last path, so u32 is the game header's declaration, not a computed result. Constants
 *   are plain literals (0xC000, 0x10000, 0x1000). The four contested data hints (d_021F81AC,
 *   d_021F81C4, d_021F8274, d_021F8214) resolve without the overlay token.
 * symbols:
 *   G3D_SYSTEM_Init  0x02046440  arm
 *   BG_SYS_SetLowBit  0x0204044C  arm
 *   G3D_SYSTEM_SetSwapBuffersMode  0x02046BE0  arm
 *   G3D_CAMERA_Create  0x02048A24  arm
 *   G3D_CAMERA_Reset  0x02048AD0  arm
 *   func_0207DCF8  0x0207DCF8  arm
 *   BILLBOARD_Create  0x0204EBD4  arm
 *   BILLBOARD_SetField10  0x0204ED70  arm
 *   MUSICAL_SHOT_SYS_LoadBg  0x021F3EAC  thumb  ov112
 *   func_02040618  0x02040618  arm
 *   func_020490F4  0x020490F4  arm
 *   ARC_UTIL_UploadPaletteFromHandle  0x02049BDC  arm
 *   func_02049658  0x02049658  arm
 *   func_020498F4  0x020498F4  arm
 *   func_020409B4  0x020409B4  arm
 *   ARC_TOOL_DeleteHandle  0x02049238  arm
 *   func_0207D63C  0x0207D63C  arm
 *   d_021F81AC  0x021F81AC  data  a4
 *   d_021F81B8  0x021F81B8  data  ov112  a4
 *   d_021F81A0  0x021F81A0  data  ov112  a4
 *   d_021F81C4  0x021F81C4  data  a4
 *   d_021F8274  0x021F8274  data  a4
 *   d_021F8258  0x021F8258  data  ov112  a4
 *   d_021F8214  0x021F8214  data  a4
 *   d_021F81D4  0x021F81D4  data  ov112  a4
 *   d_021F81F4  0x021F81F4  data  ov112  a4
  * note 2026-10-05 (integrator): parked in pending although it verifies EXACT. It closes only with
 * ARC_UTIL_UploadPaletteFromHandle declared u32; its matched arm9 definition is void and every matched caller declares
 * it void. Waiting for the user to accept or reject that declaration.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct { u32 w[7]; } T28;
typedef struct { u32 w[3]; } T12;

extern void G3D_SYSTEM_Init(int, int, int, int, int, int, int);
extern void BG_SYS_SetLowBit(u32 mode);
extern void G3D_SYSTEM_SetSwapBuffersMode(u32 a, u32 b);
extern void *G3D_CAMERA_Create(int, int, int, int, int, int, int, int, const void *, const void *, const void *, int);
struct Blk3;
struct Light;
extern void G3D_CAMERA_Reset(struct Light *l);
extern void func_0207DCF8(const void *a);
extern void *BILLBOARD_Create(u8 *src, void *heap);
extern void BILLBOARD_SetField10(u8 *dst, struct Blk3 *src);
extern void MUSICAL_SHOT_SYS_LoadBg(const void *a, u32 b, u32 c);
extern void func_02040618(u32, u32, u32);
extern void *func_020490F4(u32 id, u32 heap);
extern u32 ARC_UTIL_UploadPaletteFromHandle(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u16 a6);
extern u32 func_02049658(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_020498F4(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_020409B4(u32 index);
extern void ARC_TOOL_DeleteHandle(void *h);
extern void func_0207D63C(u32, u32, u32, u32, u32);

extern const char d_021F81AC[];
extern const char d_021F81B8[];
extern const char d_021F81A0[];
extern const char d_021F81C4[];
extern const T28 d_021F8274;
extern const T12 d_021F8258;
extern const char d_021F8214[];
extern const char d_021F81D4[];
extern const char d_021F81F4[];

static inline void G2_SetWndOBJInsidePlane(int wnd, int effect)
{
    u32 tmp;
    tmp = (*(volatile u16 *)0x0400004A & ~0x3F00u) | ((u32)wnd << 8);
    if (effect) tmp |= 0x2000;
    *(volatile u16 *)0x0400004A = (u16)tmp;
}
static inline void G2_SetWndOutsidePlane(int wnd, int effect)
{
    u32 tmp;
    tmp = (*(volatile u16 *)0x0400004A & ~63u) | (u32)wnd;
    if (effect) tmp |= 32;
    *(volatile u16 *)0x0400004A = (u16)tmp;
}

void MUSICAL_SHOT_SYS_Init3D(char *p)
{
    void *h;
    void *cam;
    T28 a;
    T12 b;
    T12 *pb;

    G3D_SYSTEM_Init(0, 2, 0, 4, 0, *(u16 *)p, 0);
    BG_SYS_SetLowBit(3);
    G3D_SYSTEM_SetSwapBuffersMode(0, 1);
    cam = G3D_CAMERA_Create(2, 0xC000, 0, 0, 0x10000, 0x1000, 0x3E8000, 0,
                        d_021F81AC, d_021F81B8, d_021F81A0, *(u16 *)p);
    *(void **)(p + 0x18) = cam;
    G3D_CAMERA_Reset(cam);
    func_0207DCF8(d_021F81C4);
    *(volatile u16 *)0x04000060 = *(volatile u16 *)0x04000060 & 0xCFDF;
    *(volatile u16 *)0x04000060 = (*(volatile u16 *)0x04000060 & ~0x3000) | 0x10;
    *(volatile u16 *)0x04000060 = (*(volatile u16 *)0x04000060 & ~0x3000) | 8;
    G3D_SYSTEM_SetSwapBuffersMode(0, 0);
    a = d_021F8274;
    b = d_021F8258;
    pb = &b;
    h = BILLBOARD_Create((u8 *)(&a), (void *)(*(u16 *)p));
    *(void **)(p + 0x1C) = h;
    BILLBOARD_SetField10(h, (struct Blk3 *)pb);
    MUSICAL_SHOT_SYS_LoadBg(d_021F8214, 1, 0);
    MUSICAL_SHOT_SYS_LoadBg(d_021F81D4, 2, 0);
    MUSICAL_SHOT_SYS_LoadBg(d_021F81F4, 3, 0);
    func_02040618(2, 3, 0xE0);
    h = func_020490F4(0x2F, *(u16 *)p);
    ARC_UTIL_UploadPaletteFromHandle(h, 3, 0, 0, 0, 0x20, *(u16 *)p);
    func_02049658(h, 9, 2, 0, 0, 0, *(u16 *)p);
    func_020498F4(h, 0xF, 2, 0, 0, 0, *(u16 *)p);
    ARC_UTIL_UploadPaletteFromHandle(h, 2, 0, 0x20, 0x20, 0x20, *(u16 *)p);
    func_02049658(h, 8, 3, 0, 0, 0, *(u16 *)p);
    func_020498F4(h, 0xE, 3, 0, 0, 0, *(u16 *)p);
    func_020409B4(2);
    func_020409B4(3);
    ARC_TOOL_DeleteHandle(h);
    func_0207D63C(0x04000050, 8, 1, 0, 0xA);
    *(volatile u32 *)0x04000000 = (*(volatile u32 *)0x04000000 & 0xFFFF1FFF) | 0x8000;
    G2_SetWndOBJInsidePlane(0x17, 1);
    G2_SetWndOutsidePlane(0x1F, 1);
}
