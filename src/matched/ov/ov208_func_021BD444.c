/*
 * function: ZKND_TBAR_LoadButtonResources
 * address:  0x021BD444
 * packet:   pkt_ov208_021BD444
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   MI_CpuFill8        0x02082BCC  arm
 *   APP_ICON_GetArchiveId        0x020275E4  thumb
 *   func_020490F4        0x020490F4  arm
 *   APP_ICON_GetStatusAnimFileId        0x02027624  thumb
 *   func_02049B68        0x02049B68  arm
 *   APP_ICON_GetStatusFrameFileId        0x02027628  thumb
 *   func_02049740        0x02049740  arm
 *   APP_ICON_GetStatusDataFileId        0x0202762C  thumb
 *   ZKND_TBAR_LoadCellArchive  0x021BD574  thumb
 *   APP_ICON_GetMoveKindPaletteFileId        0x02027614  thumb
 *   CLACT_RegisterPaletteEx        0x0204AC18  arm
 *   APP_ICON_GetMoveKindAnimFileId        0x02027618  thumb
 *   CLACT_RegisterCharacter        0x0204A6C8  arm
 *   APP_ICON_GetStatusCellFileId        0x0202761C  thumb
 *   APP_ICON_GetStatusPaletteFileId        0x02027620  thumb
 *   CLACT_RegisterCellAnim        0x0204AF28  arm
 *   ARC_TOOL_DeleteHandle        0x02049238  arm
 *
 * The heap word reaches 0x021BD574 untruncated, so this file declares that
 * callee's last parameter u32 (the callee itself reads it with ldrh).
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Ov208Bg {
    u32 f0;
    u32 f4;
    u32 f8;
    u32 fc;
    u32 f10;
};

extern void MI_CpuFill8(void *p, u32 v, u32 n);
extern u32  APP_ICON_GetArchiveId(void);
extern void *func_020490F4(unsigned int id, unsigned int heap);
extern u32  APP_ICON_GetStatusAnimFileId(void);
extern void func_02049B68(void *a, u32 b, u32 c, u32 d, u32 e, u32 f);
extern u32  APP_ICON_GetStatusFrameFileId(void);
extern u32  func_02049740(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 flags);
extern u32  APP_ICON_GetStatusDataFileId(void);
extern void ZKND_TBAR_LoadCellArchive(void *a0, u32 a1, u32 channel, u32 add, u8 a4, u8 a5, u8 a6,
                                u8 a7, u8 x, u8 y, u8 w, u8 h, u8 pal, u32 a13, u32 heap);
extern u32  APP_ICON_GetMoveKindPaletteFileId(void);
extern u32  CLACT_RegisterPaletteEx(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g);
extern u32  APP_ICON_GetMoveKindAnimFileId(void);
extern u32  CLACT_RegisterCharacter(void *a, u32 b, u32 c, u32 a3, u32 flags);
extern u32  APP_ICON_GetStatusCellFileId(u32 a);
extern u32  APP_ICON_GetStatusPaletteFileId(u32 a);
typedef signed int     s32;
extern s32 CLACT_RegisterCellAnim(void *owner, u32 first, u32 second, u32 mode);
extern void ARC_TOOL_DeleteHandle(void *h);

void ZKND_TBAR_LoadButtonResources(struct Ov208Bg *p, u32 channel, u32 objChannel, u32 palOfs,
                         u32 kind, u8 pal, u8 objPal, u32 skip, u32 heap)
{
    void *h;

    MI_CpuFill8(p, 0, sizeof(*p));
    p->fc = channel;
    h = func_020490F4(APP_ICON_GetArchiveId(), heap);
    if (skip == 0) {
        func_02049B68(h, APP_ICON_GetStatusAnimFileId(), palOfs, pal << 5, 0x20, heap);
        p->f10 = func_02049740(h, APP_ICON_GetStatusFrameFileId(), p->fc, 0x800, 0, heap);
        ZKND_TBAR_LoadCellArchive(h, APP_ICON_GetStatusDataFileId(), p->fc, (u16)p->f10, 0, 0x15, 0x20, 0x18,
                            0, 0x15, 0x20, 3, pal, 0, heap);
    }
    p->f0 = CLACT_RegisterPaletteEx(h, APP_ICON_GetMoveKindPaletteFileId(), objChannel, (u16)(objPal << 5), 0, 3, heap);
    p->f4 = CLACT_RegisterCharacter(h, APP_ICON_GetMoveKindAnimFileId(), 0, objChannel, heap);
    p->f8 = CLACT_RegisterCellAnim(h, APP_ICON_GetStatusCellFileId(kind), APP_ICON_GetStatusPaletteFileId(kind), heap);
    ARC_TOOL_DeleteHandle(h);
}
