/*
 * function: UNION_COMM_BuildBeacon
 * address:  0x0217325C
 * packet:   pkt_ov012_0217325C
 * region:   ov012
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Fills the 0x64-byte record that UNION_COMM_StoreBeacon files into its table
 * (same bitfield at byte 7 bit 4, MAC at +0x64 of a table entry).
 *
 * symbols:
 *   MI_CpuFill8  0x02082BCC  arm
 *   GFL_NET_IsParentAid  0x0203D378  arm
 *   OS_GetMacAddress  0x02087C6C  arm
 *   MI_CpuCopy8    0x02082D44  arm
 *   GFL_NET_GetNegotiationNum  0x0203D1B4  arm
 *   func_020084F8  0x020084F8  thumb
 *   func_02008554  0x02008554  thumb
 *   func_02008550  0x02008550  thumb
 *   func_02008530  0x02008530  thumb
 *   func_0200856C  0x0200856C  thumb
 *   func_02008570  0x02008570  thumb
 *   ICA_ANIME_GetField1C  0x020120F4  thumb
 *   GAME_DATA_GetField1A0  0x0201283C  thumb
 *   WIFILIST_MakeExchangeToken  0x02009CB0  thumb
 *   UNION_APP_IsClosed  0x021840C8  thumb  ov022
 */
#include "../include/Obj02671.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct Blob28 {
    u8 b[0x28];
} Blob28;

typedef struct Rec {
    u8  mac[6];
    u8  b6lo : 3;
    u8  b6bit : 1;
    u8  b6hi : 4;
    u8  b7lo : 3;
    u8  b7bit : 1;
    u8  used : 1;
    u8  b7hi : 3;
    u8  f8;
    u8  f9;
    u8  fA;
    u8  fB;
    u8  fC[0x10];
    u16 f1C;
    u16 f1E;
    u16 f20;
    u16 f22;
    u16 f24;
    u8  f26;
    u8  f27;
    Blob28 f28;
    u8  f50[0xc];
    u32 f5C;
    u32 f60;
} Rec;

typedef struct Local {
    u8  f0;
    u8  f1;
    u8  f2;
    u8  f3;
    u16 f4;
    u16 f6;
    u16 f8;
    u16 fA;
    u16 fC;
    u8  fE;
    u8  fF;
    u8  pad10[8];
    u8 *f18;
    u8  pad1C[4];
    u8 *f20;
    u8  pad24[0xc];
    Blob28 f30;
} Local;

typedef struct Save {
    void *f0;
    u8    pad4[8];
    u32   fC;
} Save;

extern void MI_CpuFill8(void *dst, int val, int size);
struct Sub0200852CObj;
extern u32 GFL_NET_IsParentAid(void);
extern void OS_GetMacAddress(void *p);
extern void MI_CpuCopy8(const void *src, void *dst, int n);
extern int  GFL_NET_GetNegotiationNum(void);
struct BigObj;
struct Ctx;
extern u32 func_020084F8(void *dst, u32 value, u32 size);
extern u8 func_02008554(const struct Sub0200852CObj *obj);
extern u8 func_02008550(const struct Sub0200852CObj *obj);
extern u32 func_02008530(const struct Sub0200852CObj *obj);
extern u8 func_0200856C(const struct Sub0200852CObj *obj);
extern u8 func_02008570(const struct Sub0200852CObj *obj);
extern void *ICA_ANIME_GetField1C(const struct Ctx *p);
extern u32 GAME_DATA_GetField1A0(const struct BigObj *p);
extern int WIFILIST_MakeExchangeToken(int a0, int a1);
extern int UNION_APP_IsClosed(u8 *p);

void UNION_COMM_BuildBeacon(u8 *self, Rec *out)
{
    Local *l = (Local *)(self + 0x2830);

    MI_CpuFill8(out, 0, 0x64);
    if (l->f20 != 0) {
        if (GFL_NET_IsParentAid() == 1)
            OS_GetMacAddress(out);
        else
            MI_CpuCopy8(l->f20 + 0x64, out, 6);
    } else if (l->f18 != 0) {
        MI_CpuCopy8(l->f18 + 0x64, out, 6);
    }
    out->b6lo = GFL_NET_GetNegotiationNum();
    out->f8 = 0x15;
    out->f9 = 2;
    out->fA = l->f1;
    out->b7hi = l->f2;
    out->fB = l->f0;
    func_020084F8((*(Save * *)&((struct Obj02671 *)self)->f0)->f0, (u32)out->fC, 8);
    out->b6hi = func_02008554((*(Save * *)&((struct Obj02671 *)self)->f0)->f0);
    out->b7bit = (u32)func_02008550((*(Save * *)&((struct Obj02671 *)self)->f0)->f0);
    out->f5C = func_02008530((*(Save * *)&((struct Obj02671 *)self)->f0)->f0);
    out->b7lo = l->fF;
    out->f1C = l->f4;
    out->f1E = l->f6;
    out->f20 = l->f8;
    out->f22 = l->fA;
    out->f24 = l->fC;
    out->f26 = func_0200856C((*(Save * *)&((struct Obj02671 *)self)->f0)->f0);
    out->f27 = func_02008570((*(Save * *)&((struct Obj02671 *)self)->f0)->f0);
    out->f28 = l->f30;
    WIFILIST_MakeExchangeToken(GAME_DATA_GetField1A0(ICA_ANIME_GetField1C((const struct Ctx *)((*(Save * *)&((struct Obj02671 *)self)->f0)->fC))), (int)out->f50);
    if (((struct Obj02671 *)self)->f3528 != 0)
        out->b6bit = UNION_APP_IsClosed(((struct Obj02671 *)self)->f3528);
    else
        out->b6bit = 0;
    out->used = 1;
    self[0x2829] = 1;
}
