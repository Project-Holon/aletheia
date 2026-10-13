/*
 * function: func_021BA9EC
 * address:  0x021BA9EC
 * packet:   pkt_ov172_021BA9EC
 * region:   ov172
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * 2026-10-02 (lane C1-04): byte-correct; one relocation wildcarded.
 * Blocker: func_021BE02C has no witness in ov172 (unlabelled leaf: 021BE02C
 * is `ldr r0, [r0, #0x10]; bx lr`, 021BE030 is the paired setter
 * `str r1, [r0, #0x10]; bx lr`; both missing from the layout, a figure
 * move). The only other file for that address is ov203's unrelated function.
 * The +0x96 wrap-around reload is a volatile read in the else arm.
 *
 * Scene state machine, one switch on the state word at +0, then the
 * per-frame tail (window release checks, key handling, colour fade).
 *
 * symbols:
 *   func_021BE00C  0x021BE00C  thumb  ov172
 *   func_021BE02C  0x021BE02C  thumb  ov172
 *   func_021BDFDC  0x021BDFDC  thumb  ov172
 *   func_021BDFE4  0x021BDFE4  thumb  ov172
 *   func_021BE0B0  0x021BE0B0  thumb  ov172
 *   func_021BE0B4  0x021BE0B4  thumb  ov172
 *   func_021BE0A4  0x021BE0A4  thumb  ov172
 *   func_021BE08C  0x021BE08C  thumb  ov172
 *   func_021BE044  0x021BE044  thumb  ov172
 *   func_021B7590  0x021B7590  thumb  ov172
 *   func_021B7578  0x021B7578  thumb  ov172
 *   func_021B7B80  0x021B7B80  thumb  ov172
 *   func_021B7B3C  0x021B7B3C  thumb  ov172
 *   func_021B8084  0x021B8084  thumb  ov172
 *   func_021B8740  0x021B8740  thumb  ov172
 *   func_021B8B34  0x021B8B34  thumb  ov172
 *   func_021B8B48  0x021B8B48  thumb  ov172
 *   func_021B77B4  0x021B77B4  thumb  ov172
 *   func_021BB938  0x021BB938  thumb  ov172
 *   func_021BB8F4  0x021BB8F4  thumb  ov172
 *   func_021BAE58  0x021BAE58  thumb  ov172
 *   func_021BAEE0  0x021BAEE0  thumb  ov172
 *   func_021BB4D0  0x021BB4D0  thumb  ov172
 *   func_021BB288  0x021BB288  thumb  ov172
 *   FX_SinCosTable_     0x020A1B38  data a2
 *   WIPE_SYS_Start  0x0202208C  thumb  arm9
 *   WIPE_SYS_EndCheck  0x020221A4  thumb  arm9
 *   TOUCHPANEL_GetTrg  0x02035C60  arm  arm9
 *   BMP_WIN_TransferChars  0x02045334  arm  arm9
 *   BMP_WIN_MakeScreen  0x02045374  arm  arm9
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb  arm9
 *   PRINTSYS_QUE_IsExistTarget  0x0201C6C4  thumb  arm9
 *   KEY_GetTrg  0x020362DC  arm  arm9
 *   BMP_WIN_GetBmp  0x02045770  arm  arm9
 *   CLACT_SetActorDrawEnable  0x0204B3DC  arm  arm9
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj00140.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed int     s32;

extern u16 func_021BE00C(u16 *p);
extern u32  func_021BE02C(void *c);
extern u32  func_021BDFDC(void *c);
extern u32  func_021BDFE4(void *c);
extern void func_021BE0B0(void *c, u32 v);
extern u32  func_021BE0B4(void *c);
extern u32 func_021BE0A4(void *p);
extern void func_021BE08C(void *c);
extern u32  func_021BE044(void *c);
struct Cfg;
struct PrintSys;
extern int func_021B7590(int x, char *p);
extern void func_021B7578(int x, char *p);
extern void func_021B7B80(int x, char *p);
extern void func_021B7B3C(int x, int y, int z);
extern void func_021B8084(void *a, char *q);
extern u32 func_021B8740(int a, int b, u8 c, u32 d);
extern void func_021B8B34(void *c, u32 v, u32 k);
extern int  func_021B8B48(void *c, u32 v, u32 k);
extern u32 func_021B77B4(int unused, void *p);
extern void func_021BB938(void *p, u8 *q, int id);
extern int func_021BB8F4(void *a0, int *out);
extern void func_021BAE58(void *p, u8 *q);
extern void func_021BAEE0(void *ctx, u8 *p);
extern void func_021BB4D0(void *unused, u8 *q);
extern void func_021BB288(void *ctx, u8 *p);
extern void WIPE_SYS_Start(void *p1, u32 p2, u32 p3, u32 p4, u32 p5, u32 p6, u32 p7);
extern u32  WIPE_SYS_EndCheck(void);
extern int TOUCHPANEL_GetTrg(void);
extern u32  KEY_GetTrg(void);
extern u32 PRINTSYS_QUE_IsExistTarget(struct PrintSys *p, void *v);
struct Descriptor;
extern void *BMP_WIN_GetBmp(struct Descriptor *w);
extern void func_0201F73C(void *a0, int a1, int a2, int a3);
extern void BMP_WIN_TransferChars(struct Descriptor *);
extern void BMP_WIN_MakeScreen(struct Cfg *cfg);
extern void func_02041B6C(u32 a);
extern void func_020409B4(u32 a);
extern void GFL_USE_PlaySeDefaultVolume(u32 id);
extern s32 func_02061CA4(void *p, u32 a, u32 b, s32 size);
struct Obj;
extern void CLACT_SetActorDrawEnable(struct Obj *a, unsigned int b);

extern s16 FX_SinCosTable_[];

int func_021BA9EC(void *a0, char *p)
{
    u32 v;
    u32 flag;
    u32 z;
    u8 i;
    u32 t;
    u32 s;
    u32 k;

    v = func_021BE00C(a0);
    z = 0;
    ((struct Obj00140 *)p)->f8 = z;
    switch (((struct Obj00140 *)p)->f0) {
    case 0:
        if (func_021BE02C(a0) == 1) {
            WIPE_SYS_Start((void *)z, 1, 1, z, 6, 1, v);
        } else {
            WIPE_SYS_Start((void *)4, 1, 1, z, 6, 1, v);
        }
        ((struct Obj00140 *)p)->f0 = 1;
        break;
    case 1:
        if (WIPE_SYS_EndCheck() == 1) {
            ((struct Obj00140 *)p)->f18 = 1;
            ((struct Obj00140 *)p)->f0 = 4;
        }
        break;
    case 2:
        t = func_021BDFDC(a0);
        if (((struct Obj00140 *)p)->f20 != 0) {
            if (func_021B7590((int)a0, (char *)t) != 1) {
                break;
            }
        }
        WIPE_SYS_Start(0, 0, 0, 0, 6, 1, v);
        ((struct Obj00140 *)p)->f0 = 3;
        ((struct Obj00140 *)p)->f18 = 0;
        break;
    case 3:
        if (WIPE_SYS_EndCheck() == 1) {
            if (((struct Obj00140 *)p)->f1C == 0) {
                return 1;
            }
            return 4;
        }
        break;
    case 4:
        if (func_021BB8F4(a0, (int *)p) == 0) {
            func_021BAE58(a0, (u8 *)p);
        }
        break;
    case 5:
        if (func_021BB8F4(a0, (int *)p) == 0) {
            func_021BAEE0(a0, (u8 *)p);
        }
        break;
    case 6:
        func_021B8084(a0, (char *)func_021BDFE4(a0));
        func_021BB938(a0, (u8 *)p, 0x24);
        flag = 1;
        func_021BE0B0(a0, 1);
        ((struct Obj00140 *)p)->f0 = 7;
        func_021B7B80((int)a0, (char *)func_021BDFDC(a0));
        ((struct Obj00140 *)p)->f20 = flag;
        break;
    case 7:
        if (TOUCHPANEL_GetTrg() == 1 || (KEY_GetTrg() & 3) != 0) {
            ((struct Obj00140 *)p)->f1C = flag = 1;
            ((struct Obj00140 *)p)->f0 = 2;
            func_021BE0B0(a0, 1);
            func_021B7578((int)a0, (char *)func_021BDFDC(a0));
            ((struct Obj00140 *)p)->f20 = flag;
        }
        break;
    case 8:
        if (func_021B8740((int)a0, func_021BDFE4(a0), 10, z) == 1) {
            ((struct Obj00140 *)p)->f0 = 9;
        }
        break;
    case 9:
        func_021B8084(a0, (char *)func_021BDFE4(a0));
        func_021BB938(a0, (u8 *)p, 0x25);
        flag = 1;
        func_021BE0B0(a0, 1);
        ((struct Obj00140 *)p)->f0 = 10;
        ((struct Obj00140 *)p)->f54 = z;
        func_021B7B80((int)a0, (char *)func_021BDFDC(a0));
        ((struct Obj00140 *)p)->f20 = flag;
        break;
    case 10:
        ((struct Obj00140 *)p)->f54 = ((struct Obj00140 *)p)->f54 + 1;
        if (TOUCHPANEL_GetTrg() == 1 || (KEY_GetTrg() & 3) != 0
            || ((struct Obj00140 *)p)->f54 >= 300) {
            ((struct Obj00140 *)p)->f0 = 11;
        }
        break;
    case 11:
        func_021B8B34(a0, func_021BDFE4(a0), 0x2f);
        ((struct Obj00140 *)p)->f0 = 12;
        break;
    case 12:
        if (func_021B8B48(a0, func_021BDFE4(a0), 0x2f) == 1) {
            ((struct Obj00140 *)p)->f1C = flag = 1;
            ((struct Obj00140 *)p)->f0 = 2;
            func_021BE0B0(a0, 1);
            func_021B7578((int)a0, (char *)func_021BDFDC(a0));
            ((struct Obj00140 *)p)->f20 = flag;
        }
        break;
    case 13:
        func_021B8084(a0, (char *)func_021BDFE4(a0));
        func_021BB938(a0, (u8 *)p, 0x26);
        flag = 1;
        func_021BE0B0(a0, 1);
        ((struct Obj00140 *)p)->f0 = 14;
        func_021B7B80((int)a0, (char *)func_021BDFDC(a0));
        ((struct Obj00140 *)p)->f20 = flag;
        break;
    case 14:
        if (TOUCHPANEL_GetTrg() == 1 || (KEY_GetTrg() & 3) != 0) {
            ((struct Obj00140 *)p)->f1C = flag = 1;
            ((struct Obj00140 *)p)->f0 = 2;
            func_021BE0B0(a0, 1);
            func_021B7578((int)a0, (char *)func_021BDFDC(a0));
            ((struct Obj00140 *)p)->f20 = flag;
        }
        break;
    }
    func_021BB4D0(a0, (u8 *)p);
    if (((struct Obj00140 *)p)->f18 == 1) {
        func_021BB288(a0, (u8 *)p);
    }
    if (((struct Obj00140 *)p)->f38 == 1) {
        t = func_021BE044(a0);
        if (PRINTSYS_QUE_IsExistTarget((struct PrintSys *)t, (void *)((u32)BMP_WIN_GetBmp((struct Descriptor *)((struct Obj00140 *)p)->f48))) == 0) {
            func_0201F73C((void *)(((struct Obj00140 *)p)->f48), 2, 0x140, 9);
            BMP_WIN_TransferChars((struct Descriptor *)((struct Obj00140 *)p)->f48);
            BMP_WIN_MakeScreen((struct Cfg *)(((struct Obj00140 *)p)->f48));
            func_02041B6C(4);
            i = 0;
            ((struct Obj00140 *)p)->f38 = 0;
            if (((struct Obj00140 *)p)->f3C == 1) {
                k = 1;
                for (i = 0; i < 5; i++) {
                    CLACT_SetActorDrawEnable((struct Obj *)*(u32 *)(p + i * 4 + 0x70), k);
                }
            } else {
                k = i;
                for (i = 0; i < 5; i++) {
                    CLACT_SetActorDrawEnable((struct Obj *)*(u32 *)(p + i * 4 + 0x70), k);
                }
            }
        }
    }
    if (((struct Obj00140 *)p)->f40 == 1) {
        t = func_021BE044(a0);
        if (PRINTSYS_QUE_IsExistTarget((struct PrintSys *)t, (void *)((u32)BMP_WIN_GetBmp((struct Descriptor *)((struct Obj00140 *)p)->f4C))) == 0) {
            BMP_WIN_TransferChars((struct Descriptor *)((struct Obj00140 *)p)->f4C);
            BMP_WIN_MakeScreen((struct Cfg *)(((struct Obj00140 *)p)->f4C));
            func_020409B4(4);
            ((struct Obj00140 *)p)->f40 = 0;
        }
    }
    if (((struct Obj00140 *)p)->f44 == 1 && ((struct Obj00140 *)p)->f50 != 0) {
        t = func_021BE044(a0);
        if (PRINTSYS_QUE_IsExistTarget((struct PrintSys *)t, (void *)((u32)BMP_WIN_GetBmp((struct Descriptor *)((struct Obj00140 *)p)->f50))) == 0) {
            BMP_WIN_TransferChars((struct Descriptor *)((struct Obj00140 *)p)->f50);
            BMP_WIN_MakeScreen((struct Cfg *)(((struct Obj00140 *)p)->f50));
            func_020409B4(0);
            ((struct Obj00140 *)p)->f44 = 0;
        }
    }
    if (*(s32 *)&((struct Obj00140 *)p)->f0 <= 5 && func_021BE0B4(a0) == 0) {
        v = func_021BDFDC(a0);
        if (KEY_GetTrg() & 0x40) {
            func_021B7B3C((int)a0, v, 0);
        }
        if (KEY_GetTrg() & 0x10) {
            func_021B7B3C((int)a0, v, 5);
        }
        if (KEY_GetTrg() & 0x80) {
            func_021B7B3C((int)a0, v, 1);
        }
        if (KEY_GetTrg() & 0x20) {
            func_021B7B3C((int)a0, v, 3);
        }
    }
    if (func_021BE0A4(a0) == 0 && (KEY_GetTrg() & 0x200)) {
        if (func_021B77B4((int)a0, (void *)func_021BDFDC(a0)) == 0) {
            func_021BE08C(a0);
            GFL_USE_PlaySeDefaultVolume(0x66C);
        }
    }
    t = *(volatile u16 *)&((struct Obj00140 *)p)->f96;
    ((struct Obj00140 *)p)->f96 = ((s32)(t + 0x400) >= 0x10000) ? t - 0xFC00 : *(volatile u16 *)&((struct Obj00140 *)p)->f96 + 0x400;
    s = FX_SinCosTable_[(((struct Obj00140 *)p)->f96 >> 4) * 2 + 1];
    s = (s16)((s32)(s + 0x1000) / 2);
    s = (u8)(((s32)s * -9 >> 12) + 0x1c);
    ((struct Obj00140 *)p)->f94 = s | (s << 5) | (s << 10);
    func_02061CA4((void *)0xe, 0xde, (u32)(p + 0x94), 2);
    return 3;
}
