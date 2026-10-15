/*
 * function: CTVT_CALL_WorkMain
 * address:  0x021BD43C
 * packet:   pkt_ov172_021BD43C
 * region:   ov172
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * 2026-10-02: byte-correct. Blocker: CTVT_COMM_IsSessionEnded (a 64-byte thumb getter-style
 * function, show prints it as ARM) has no label/start in ov172's layout (only ov105
 * has the label), so its 2 bl sites stay unresolved. Layout gap = figure move,
 * not edited; referencing sites +0056 and +0078 here.
 *
 * symbols:
 *   CTVT_COMM_Main  0x021B7E34  thumb  ov172
 *   CTVT_TALK_Main  0x021B9044  thumb  ov172
 *   CTVT_CALL_Update  0x021BBF2C  thumb  ov172
 *   CTVT_DRAW_Main  0x021BA9EC  thumb  ov172
 *   CTVT_COMM_IsSessionEnded  0x021B80CC  thumb
 *   _fflt          0x0209BDBC  arm
 *   _fdiv          0x0209CE10  arm
 *   _ffixu         0x0209C4C8  arm
 *   CTVT_CALL_UpdateMemberWindows  0x021BDD6C  thumb  ov172
 *   DRAW_SYSTEM_Nop  0x021B6C48  thumb  ov172
 *   CTVT_CAMVIEW_Update  0x021B712C  thumb  ov172
 *   CTVT_CAMVIEW_IsShutterIdle  0x021B7590  thumb  ov172
 *   CTVT_CALL_SwitchScreen  0x021BDCB8  thumb  ov172
 *   func_02061CA4  0x02061CA4  arm
 *   FX_SinCosTable_     0x020A1B38  data
 *   NNS_GfdRegisterNewVramTransferTask  0x02061CA4  arm  arm9
 *   PRINTSYS_QUE_Main  0x0201C4E4  thumb  arm9
 *   WIPE_SYS_EndCheck  0x020221A4  thumb  arm9
 *   TCBL_Main  0x020310C4  arm  arm9
 *   CLACT_DrawSystem  0x0204A600  arm  arm9
 *   BG_SYS_FillScrollArea  0x02040618  arm  arm9
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed int     s32;

struct PrintSys;
struct Tcbl;
extern void CTVT_COMM_Main(void *p, char *q);
struct S;
extern u32 CTVT_TALK_Main(void *p, struct S *s);
extern int CTVT_CALL_Update(void *a0, char *p);
extern int CTVT_DRAW_Main(void *a0, char *p);
extern u32 CTVT_COMM_IsSessionEnded(int unused, char *p);
extern void CTVT_CALL_UpdateMemberWindows(u8 *p);
extern void DRAW_SYSTEM_Nop(u32 a);
extern void CTVT_CAMVIEW_Update(int unused, char *q);
extern int CTVT_CAMVIEW_IsShutterIdle(int x, char *p);
extern void CTVT_CALL_SwitchScreen(u8 *p);
extern u32  WIPE_SYS_EndCheck(void);
extern void CLACT_DrawSystem(void);
extern u32 PRINTSYS_QUE_Main(struct PrintSys *ps);
extern void TCBL_Main(struct Tcbl *p);
extern u32  func_02005728(u32 v);
extern void BG_SYS_FillScrollArea(u32 layer, u32 a, u32 b);
extern s32 NNS_GfdRegisterNewVramTransferTask(void *p, u32 a, u32 b, s32 size);
extern s16 FX_SinCosTable_[];

#define F(o) (*(u32 *)(ctx + (o)))
#define H(o) (*(u16 *)(ctx + (o)))

int CTVT_CALL_WorkMain(char *ctx)
{
    u32 idx;
    s32 v;
    u8 pal;

    CTVT_COMM_Main(ctx, (char *)F(0x1e4));
    switch (F(8)) {
    case 1:
        F(0xc) = CTVT_TALK_Main(ctx, (struct S *)F(0x1e8));
        break;
    case 2:
        F(0xc) = CTVT_CALL_Update(ctx, (char *)F(0x1f0));
        break;
    case 3:
        F(0xc) = CTVT_DRAW_Main(ctx, (char *)F(0x1ec));
        break;
    case 4:
        if (CTVT_COMM_IsSessionEnded((int)ctx, (char *)F(0x1e4)) == 1 && CTVT_CAMVIEW_IsShutterIdle((int)ctx, (char *)F(0x1e0)) == 1) {
            return 1;
        }
        return 0;
    case 5:
        if (CTVT_COMM_IsSessionEnded((int)ctx, (char *)F(0x1e4)) == 1 && CTVT_CAMVIEW_IsShutterIdle((int)ctx, (char *)F(0x1e0)) == 1
            && WIPE_SYS_EndCheck() == 1) {
            return 1;
        }
        break;
    }
    if (F(0x14) == 1 && WIPE_SYS_EndCheck() == 1) {
        F(0xc) = 5;
    }
    if (F(8) != F(0xc)) {
        CTVT_CALL_SwitchScreen((u8 *)ctx);
    }
    CTVT_CAMVIEW_Update((int)ctx, (char *)F(0x1e0));
    DRAW_SYSTEM_Nop(F(0x1f4));
    CLACT_DrawSystem();
    PRINTSYS_QUE_Main((struct PrintSys *)F(0x1d0));
    CTVT_CALL_UpdateMemberWindows((u8 *)ctx);
    H(0x38) += 0x200;
    idx = H(0x38) >> 4;
    v = (FX_SinCosTable_[idx * 2] + 0x1000) / 2 * 10;
    pal = (u8)(u32)((float)v / 4096.0f);
    if (pal >= 10) {
        pal = 9;
    }
    if (pal != H(0x3a)) {
        H(0x3a) = pal;
        NNS_GfdRegisterNewVramTransferTask((void *)0x1f, 0x40, (u32)(ctx + 0x3c + pal * 32), 0x20);
    }
    TCBL_Main((struct Tcbl *)F(0x1d8));
    BG_SYS_FillScrollArea(1, 0, func_02005728(0x100));
    BG_SYS_FillScrollArea(1, 3, func_02005728(0x100));
    return 0;
}
