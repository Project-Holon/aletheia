/*
 * file:     fieldmap_p12.c
 * unit:     yes
 * function: func_02189810, func_02189998, func_021899C4, func_021899F0
 * address:  0x02189810
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0219047C    0x0219047C  thumb  ov021
 *   func_0218CC64    0x0218CC64  thumb  ov021
 *   func_021C7FB4    0x021C7FB4  thumb  ov021
 *   _ll_mul          0x0209C054  arm
 *   MIi_CpuCopyFast  0x02082B0C  arm
 *   func_0206A854    0x0206A854  arm
 *   func_0206DB80    0x0206DB80  arm
 *   func_021ABE0C    0x021ABE0C  thumb  ov021
 *   func_021C64E0    0x021C64E0  thumb  ov021
 *   func_02050790    0x02050790  arm
 *   func_0217F928    0x0217F928  thumb  ov019
 *   func_021BB954    0x021BB954  thumb  ov021
 *   func_021A1B38    0x021A1B38  thumb  ov021
 *   func_021BE4F8    0x021BE4F8  thumb  ov021
 *   func_021C1AEC    0x021C1AEC  thumb  ov021
 *   func_021C1C4C    0x021C1C4C  thumb  ov021
 *   g_02148B54       0x02148B54  data
 *   g_02148BCC       0x02148BCC  data
 *   func_0207DD24  0x0207DD24  arm
 *   func_021CF520  0x021CF520  thumb  ov021
 */
#include "../../matched/include/Obj00704.h"
#include "../../matched/include/G_Glb.h"
#include "../../matched/include/Obj19499.h"
#include "../../matched/include/Obj19500.h"
#include "../../matched/include/Obj19501.h"

#define FX_MUL(a, b) ((fx32)(((fx64)(a) * (b) + 0x800) >> 12))
struct tagLISTCB;
typedef unsigned char  u8;

typedef unsigned int   u32;

typedef int fx32;

typedef long long fx64;

typedef struct { fx32 m[4][4]; } MtxFx44;

typedef struct {
    u8 pad[0x7C];
    u32 flag;
} Glb;

typedef unsigned short u16;

extern void func_0219047C(u8 *p);
extern void func_0218CC64(char *p, int a, int m);
extern void func_021C7FB4(u32 a);
extern void MIi_CpuCopyFast(const void *src, void *dst, u32 size);
extern void func_0206A854(void);
extern void func_0206DB80(void);
extern void func_021ABE0C(u32 a);
extern void func_021C64E0(u32 a);
extern void func_02050790(struct tagLISTCB *list, int b, int c);
extern void func_0217F928(char *p);
extern void func_021BB954(u8 *p);
extern void func_021A1B38(u32 *p);
extern void func_021BE4F8(char *p);
extern void func_021C1AEC(void);
extern void func_021C1C4C(char *p);
void func_0207DD24(u16 rgb, int alpha, int depth, int polygonID, int fog);
void func_021CF520(int h);
void func_02189810(u8 *p);
void func_02189998(unsigned char *p);
void func_021899C4(unsigned char *p);
u32 func_021899F0(u8 *p);
extern MtxFx44 g_02148B54;
extern struct Glb g_02148BCC;


/*
 * Addresses are Black-image addresses.
 */
void func_02189810(u8 *p)
{
    MtxFx44 saved;
    MtxFx44 m;

    if (((struct Obj00704 *)p)->f28 != 0)
        func_0219047C((u8 *)(((struct Obj00704 *)p)->f28));
    func_0218CC64((char *)(((struct Obj00704 *)p)->f48), ((struct Obj00704 *)p)->fA4, 1);
    func_021C7FB4(((struct Obj00704 *)p)->fA0);
    saved = g_02148B54;

    m = saved;
    m.m[3][2] += FX_MUL(m.m[2][2], ((struct Obj00704 *)p)->f104);
    MIi_CpuCopyFast(&m, &g_02148B54, 0x40);
    g_02148BCC.flag &= ~0x50;
    func_0206A854();
    func_0206DB80();
    func_021ABE0C(((struct Obj00704 *)p)->f94);
    func_021C64E0(((struct Obj00704 *)p)->f130);
    func_02050790((struct tagLISTCB *)(((struct Obj00704 *)p)->fB0), ((struct Obj00704 *)p)->fA4, ((struct Obj00704 *)p)->fA8);
    func_02050790((struct tagLISTCB *)(((struct Obj00704 *)p)->fB8), ((struct Obj00704 *)p)->fA4, ((struct Obj00704 *)p)->fA8);
    if (((struct Obj00704 *)p)->f98 != 0)
        func_0217F928((char *)(((struct Obj00704 *)p)->f98));

    m = saved;
    m.m[3][2] += FX_MUL(m.m[2][2], ((struct Obj00704 *)p)->f104 / 2);
    MIi_CpuCopyFast(&m, &g_02148B54, 0x40);
    g_02148BCC.flag &= ~0x50;
    func_0206A854();
    func_0206DB80();
    func_02050790((struct tagLISTCB *)(((struct Obj00704 *)p)->fB4), ((struct Obj00704 *)p)->fA4, ((struct Obj00704 *)p)->fA8);

    MIi_CpuCopyFast(&saved, &g_02148B54, 0x40);
    g_02148BCC.flag &= ~0x50;
    func_0206A854();

    func_021BB954((u8 *)(((struct Obj00704 *)p)->fBC));
    func_021A1B38((u32 *)(((struct Obj00704 *)p)->f20));
    func_021BE4F8((char *)(((struct Obj00704 *)p)->f34));
    func_021C1AEC();
    func_021C1C4C((char *)(((struct Obj00704 *)p)->f124));
}


void func_02189998(unsigned char *p)
{
    func_0207DD24(0, 0, 0x7FFF, 0, 0);
    func_021C1AEC();
    func_021C1C4C((char *)(((struct Obj19499 *)p)->f124));
}


void func_021899C4(unsigned char *p)
{
    func_0207DD24(0x4210, 0x1F, 0x7FFF, 0, 0);
    func_021CF520(((struct Obj19500 *)p)->f13C);
}


/*
 * Unlabelled leaf getter: the word at +0x12C (func_021899F8 is its setter).
 * Addresses are Black-image addresses.
 */
u32 func_021899F0(u8 *p)
{
    return ((struct Obj19501 *)p)->f12C;
}
