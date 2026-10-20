/*
 * file:     app_power.c
 * unit:     yes
 * function: APP_POWER_ClearCallback, APP_POWER_SetCallback, APP_POWER_HaltWithMessage, APP_POWER_ShowShutdownScreen, APP_POWER_LoadShutdownScreen, APP_POWER_DrawShutdownScreen, APP_POWER_IsSupported, OVERLAY_LAUNCH_Driver, APP_POWER_IsReady
 * address:  0x0202F768
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from time_icon.c by tools/splitfile.py.
 *
 * symbols:
 *   STRBUF_Delete  0x02045808  arm
 *   GFL_HEAP_Free  0x020307B0  arm
 *   BMP_Delete   0x020437AC  arm
 *   SAVE_CONTROL_Delete  0x02007084  thumb
 *   GFL_NET_GetRunState  0x0203CD98  arm
 *   GFL_NET_ClearExitFlag  0x0203CF04  arm
 *   GFL_NET_Exit  0x0203CEAC  arm
 *   GFL_NET_IRC_WIRELESS_Exit  0x0203D0D0  arm
 *   GFL_NET_Main  0x0203CF5C  arm
 *   GFL_NET_IsSessionNull  0x0203CDBC  arm
 *   UI_ClearSoftResetInhibitGlobal  0x020351A0  arm
 *   GFL_USE_PollPowerExit  0x020053EC  thumb
 *   GXx_SetMasterBrightness_    0x0207D534  arm
 *   GX_HBlankIntr    0x0207D3AC  arm
 *   GX_VBlankIntr    0x0207D3E4  arm
 *   GX_ResetBankForBG    0x020808F4  arm
 *   GX_ResetBankForSubBG    0x020809A0  arm
 *   GX_SetBankForBG    0x0207FDCC  arm
 *   GX_SetGraphicsMode    0x0207D4B0  arm
 *   G2_GetBG1CharPtr    0x0207E24C  arm
 *   MIi_CpuClear32    0x02082A7C  arm
 *   ARC_UTIL_LoadMember    0x0204A1BC  arm
 *   NNS_G2dGetUnpackedCharacterDataEx    0x02062A4C  arm
 *   DC_FlushRange    0x020862F0  arm
 *   MIi_CpuCopy16    0x02082A60  arm
 *   NNS_G2dGetUnpackedScreenData    0x02062B30  arm
 *   G2_GetBG1ScrPtr    0x0207DFB4  arm
 *   NNS_G2dGetUnpackedPaletteCompressInfo    0x02062AD4  arm
 *   NNS_G2dGetUnpackedPaletteData    0x02062A98  arm
 *   MIi_CpuClear16    0x02082A48  arm
 *   BMP_CreateFromVram    0x02043754  arm
 *   GF_FONT_Create    0x0201D7EC  thumb
 *   MSGDATA_CreateFromArchive    0x02045B38  arm
 *   MSGDATA_AllocString    0x02045EC0  arm
 *   PRINTSYS_PrintColor    0x0201C7D0  thumb
 *   MSGDATA_Delete    0x02045C04  arm
 *   GF_FONT_Delete    0x0201D83C  thumb
 *   ov088_id       0x00000058  data  a1
 *   ov179_id       0x000000B3  data  a1
 *   d_021BD8E8     0x021BD8E8  data ov088
 *   d_021B68D8     0x021B68D8  data  ov179
 *   d_021BD574     0x021BD574  data ov088
 *   sOverlayLaunchWork     0x02146948  data
 *   sOverlayLaunchWorkArg 0x02146948  data
 *   PROCSYS_PushGlobal  0x020312CC  arm
 */
#include "comm_player_support_shared_types.h"
#include "../types.h"
#include "time_icon_shared_types.h"
#include "save_event_shared_types.h"

#define REG32(a) (*(volatile u32 *)(a))

#define REG16(a) (*(volatile u16 *)(a))

#define REG_BG1CNT_A        0x0400000A

#define REG_BG1HOFS_A       0x04000014

#define REG_BLDCNT_A        0x04000050

#define REG_MASTER_BRIGHT_A 0x0400006C

#define REG_MASTER_BRIGHT_B 0x0400106C

struct MsgBank;

struct GfFont;

struct ArchiveRecord;

/* State block of the overlay launcher driven by OVERLAY_LAUNCH_Driver. */
struct OverlayLaunchWork {
    u16 stage;      /* 0x00 */
    u8 enabled;     /* 0x02 */
    u8 aborted;     /* 0x03, set by the launched overlay */
    u32 mode;       /* 0x04 */
};

#include "gfl_heap_wrap.h"

#include "strbuf.h"

typedef short s16_p07;
#include "bmp.h"

#include "save_control.h"

#include "net.h"






#include "ui.h"

#include "gfl_use.h"

#include "gx.h"



#include "gx_vramcnt.h"




#include "gx_bgcnt.h"

#include "mi_memory.h"

#include "arc_util.h"
struct NitroFileHeader;

#include "nns_g2d_anim_bank.h"

#include "os_cache.h"


#include "nns_g2d_load.h"






#include "gf_font.h"

#include "msgdata.h"


#include "printsys.h"



#include "procsys.h"

void APP_POWER_ClearCallback(void);

void APP_POWER_SetCallback(u32 on);

void APP_POWER_HaltWithMessage(u32 mode);

void APP_POWER_ShowShutdownScreen(u32 messageId);

void APP_POWER_LoadShutdownScreen(void);

void APP_POWER_DrawShutdownScreen(u32 messageId);

int APP_POWER_IsSupported(void);

int OVERLAY_LAUNCH_Driver(void *unused, u32 *state);

int APP_POWER_IsReady(void);

extern u8 ov088_id[];

extern u8 ov179_id[];

extern u8 d_021BD8E8[];

extern u8 d_021B68D8[];

extern u8 d_021BD574[];

extern struct OverlayLaunchWork sOverlayLaunchWork;

extern u8 sOverlayLaunchWorkArg[];

/* Hardware registers (main engine, A) used by the shutdown display reset. */
#define REG_DISPCNT_A       0x04000000

/*
 * An unlabelled tail-call leaf (it saves nothing, so disasm.py prints it as
 * .word data): APP_POWER_HaltWithMessage(0).  With APP_POWER_SetCallback it is the callback pair
 * GFL_USE_InitSystem (gfl_use.c boot) hands to BACKUP_SYSTEM_Init(7, ...).  Filed apart
 * from APP_POWER_SetCallback on purpose: the only pool words naming 0x0202F789 that
 * are outside a two-function range are each other's, so as one unit neither
 * site has a witness
 * (docs/idioms/split-a-unit-so-two-call-sites-attest-each-other.md).
 */
void APP_POWER_ClearCallback(void)
{
    APP_POWER_HaltWithMessage(0);
}

/*
 * The second unlabelled tail-call leaf of the callback pair GFL_USE_InitSystem
 * hands to BACKUP_SYSTEM_Init: a flag mapped to mode 2 (clear) or 1 (set) for
 * APP_POWER_HaltWithMessage.  Filed apart from APP_POWER_ClearCallback so each pool word
 * witnesses the other.
 */
void APP_POWER_SetCallback(u32 on)
{
    u32 mode;

    if (on == 0) {
        mode = 2;
    } else {
        mode = 1;
    }
    APP_POWER_HaltWithMessage(mode);
}

/*
 * The power callback reached from APP_POWER_ClearCallback as APP_POWER_HaltWithMessage(0) (and
 * registered through the pool word 0x0202F789 at 0x0202F784).  It never
 * returns: after the shutdown work it spins on GFL_USE_PollPowerExit.
 */
void APP_POWER_HaltWithMessage(u32 mode)
{
    SAVE_CONTROL_Delete();
    APP_POWER_ShowShutdownScreen(mode);
    if (GFL_NET_GetRunState()) {
        GFL_NET_ClearExitFlag();
        GFL_NET_Exit(0);
        GFL_NET_IRC_WIRELESS_Exit();
        do {
            GFL_NET_Main();
        } while (!GFL_NET_IsSessionNull());
    }
    UI_ClearSoftResetInhibitGlobal(2);
    for (;;)
        GFL_USE_PollPowerExit();
}

/*
 * The two calls to this packet's own followers (0x0202F870 at +0x7A and
 * 0x0202F940 at +0x80) are the only sites that need the `matched` class:
 * their compared range was their only `label` witness until those two files
 * existed.  Everything else is `label`.
 *
 * A display reset for the shutdown screen: two GXx_SetMasterBrightness_ writes of
 * 0xFFFFFFF0 to the master brightness registers of both engines, the engine
 * setup calls, then three read-modify-write pairs on the hardware registers
 * (DISPCNT: clear bits 8-12, set bit 9, then clear 0xE000; BG1CNT: clear all
 * but 0x43, set 4, then clear bit 6; BG1HOFS and BLDCNT zeroed), the two
 * packet-local sub-inits, and the brightness registers set again.
 *
 * Note the compiler derives BG1CNT and BG1HOFS from the pooled
 * master-brightness address with `subs r0, #0x62` / `#0x58`, and reuses the
 * value 4 in r6 as `lsls r0, r6, #0x18` for the DISPCNT base; both fall out
 * of writing the plain literals, so no symbol for the registers is needed.
 */
void APP_POWER_ShowShutdownScreen(u32 messageId)
{
    GXx_SetMasterBrightness_((volatile u16 *)REG_MASTER_BRIGHT_A, 0xFFFFFFF0);
    GXx_SetMasterBrightness_((volatile u16 *)REG_MASTER_BRIGHT_B, 0xFFFFFFF0);
    GX_HBlankIntr(0);
    GX_VBlankIntr(0);
    GX_ResetBankForBG();
    GX_ResetBankForSubBG();
    GX_SetBankForBG(4);
    GX_SetGraphicsMode(1, 0, 0);
    REG32(REG_DISPCNT_A) = (REG32(REG_DISPCNT_A) & 0xFFFFE0FF) | 0x200;
    REG32(REG_DISPCNT_A) = REG32(REG_DISPCNT_A) & 0xFFFF1FFF;
    REG16(REG_BG1CNT_A) = (REG16(REG_BG1CNT_A) & 0x43) | 4;
    REG16(REG_BG1CNT_A) = REG16(REG_BG1CNT_A) & 0xFFBF;
    REG32(REG_BG1HOFS_A) = 0;
    REG16(REG_BLDCNT_A) = 0;
    APP_POWER_LoadShutdownScreen();
    APP_POWER_DrawShutdownScreen(messageId);
    GXx_SetMasterBrightness_((volatile u16 *)REG_MASTER_BRIGHT_A, 0);
    GXx_SetMasterBrightness_((volatile u16 *)REG_MASTER_BRIGHT_B, 0x10);
}

/*
 * Three copies of one block: register a handle with ARC_UTIL_LoadMember(0x16, i, 0, 7),
 * probe it (NNS_G2dGetUnpackedCharacterDataEx / 02062B30 / 02062A98 with a stack out-pointer), and
 * on success clear 0x20 bytes of the record's buffer through DC_FlushRange and
 * fill it back through MIi_CpuCopy16 with the current frame-tick from the
 * getter (G2_GetBG1CharPtr / G2_GetBG1ScrPtr).  The handle is released with
 * GFL_HEAP_Free after each block.
 *
 * The idiom that makes this EXACT: the word each block reads twice (size of
 * the character data, size of the screen data) is written as an ASSIGNMENT
 * INSIDE the third argument of the second call --
 * `MIi_CpuCopy16(chars[5], getter(), charSize = chars[4])`.  mwcc evaluates
 * the arguments of a call right-to-left, so the assignment's load lands
 * before the getter call, and the value it produces is live across that
 * call, which is what puts it in r5 and forces the original's
 * `push {r3, r4, r5, lr}` frame.  Spelling the same value as a statement
 * before the call puts the load one statement early; spelling it inline in
 * both calls leaves the load where it is scheduled and loses r5 (6 bytes
 * short).  See docs/idioms/
 * an-assignment-inside-a-call-argument-pins-the-load-in-a-callee-saved-register.md
 *
 * Archive 0x16 members 1, 2 and 0 are the character data, screen data and
 * palette of the shutdown screen.
 */
void APP_POWER_LoadShutdownScreen(void)
{
    u32 *chars;
    u32 *screen;
    u32 *palette;
    u32 *paletteHeader;
    void *res;
    u32 charSize;
    u32 screenSize;

    MIi_CpuClear32(0, (void *)G2_GetBG1CharPtr(), 0x4000);
    res = ARC_UTIL_LoadMember(0x16, 1, 0, 7);
    if (NNS_G2dGetUnpackedCharacterDataEx((struct NitroFileHeader *)res, (void **)(&chars)) != 0) {
        DC_FlushRange((void *)(chars[5]), chars[4]);
        MIi_CpuCopy16((const void *)(chars[5]), (void *)G2_GetBG1CharPtr(), charSize = chars[4]);
    }
    GFL_HEAP_Free(res);
    res = ARC_UTIL_LoadMember(0x16, 2, 0, 7);
    if (NNS_G2dGetUnpackedScreenData(res, (void **)(&screen)) != 0) {
        DC_FlushRange((void *)((u32)screen + 0xc), screen[2]);
        MIi_CpuCopy16((const void *)((u32)screen + 0xc), (void *)G2_GetBG1ScrPtr(), screenSize = screen[2]);
    }
    GFL_HEAP_Free(res);
    res = ARC_UTIL_LoadMember(0x16, 0, 0, 7);
    NNS_G2dGetUnpackedPaletteCompressInfo((struct NitroFileHeader *)res, (void **)(&paletteHeader));
    if (NNS_G2dGetUnpackedPaletteData((struct NitroFileHeader *)res, (void **)(&palette)) != 0) {
        DC_FlushRange((void *)(palette[3]), 0x20);
        MIi_CpuCopy16((const void *)(palette[3]), (void *)0x05000000, 0x20);
    }
    GFL_HEAP_Free(res);
}

/*
 * EXACT* -- the inferred extent (184 bytes) runs 4 bytes past this
 * function's own 180, over the unlabelled 4-byte leaf at 0x0202F9F4
 * (`movs r0, #1; bx lr`, i.e. `return 1;`), which saves no lr and so gets no
 * label from disasm.py -- docs/idioms/
 * unlabelled-leaf-functions-hide-in-word-runs.md.  That leaf is worth seeding
 * into layout/function_starts.txt by the integrator; it is not ours to edit.
 * The follower is also not covered by the manifest entry below, and no `tu`
 * range may span it.
 *
 * Fills the tilemap of the shutdown screen with consecutive tile numbers,
 * then draws message `messageId` of message bank 2 into a 30x16 tile bitmap.
 */
void APP_POWER_DrawShutdownScreen(u32 messageId)
{
    u16 *tilemap;
    s32 column;
    s32 row;
    u16 tile;
    struct Bmp *bmp;
    struct GfFont *font;
    struct MsgBank *msgBank;
    struct Strbuf *message;

    tilemap = (u16 *)G2_GetBG1ScrPtr();
    tile = 0x20;
    for (row = 4; row < 0x14; row++) {
        for (column = 1; column < 0x1f; column++) {
            tilemap[(row << 5) + column] = tile;
            tile = tile + 1;
        }
    }
    MIi_CpuClear16(0x7777, (void *)((u32)G2_GetBG1CharPtr() + 0x400), 0x3C00);
    bmp = BMP_CreateFromVram((void *)((u32)G2_GetBG1CharPtr() + 0x400), 0x1e, 0x10, 0x20, 7);
    font = GF_FONT_Create(0x17, 0, 0, 0, 7);
    msgBank = MSGDATA_CreateFromArchive(0, 2, 2, 7);
    message = MSGDATA_AllocString(msgBank, messageId);
    PRINTSYS_PrintColor(bmp, 0, 0, message, font, 0x1167);
    STRBUF_Delete(message);
    MSGDATA_Delete(msgBank);
    GF_FONT_Delete(font);
    BMP_Delete(bmp);
}

int APP_POWER_IsSupported(void)
{
    return 1;
}

/*
 * wave 17 (overlay_id class): EXACT. The pooled overlay-id sites ov088_id
 * (88) and ov179_id (179) resolve as `overlay_id` (a layout overlay index,
 * loaded by a pc-relative load of this function, reaching the id register
 * of a known overlay loader), which was the last blocker.
 *
 * A five-state proc driver, the net_save.c shape of
 * src/pending/GFL_NET_SAVE_Main.c: state 0 starts overlay 0x58's proc on
 * &sOverlayLaunchWork.mode, states 1 to 3 (re)start overlay 0xB3's proc on
 * the work block, with state 2 bailing to 4 when `aborted` is set, and
 * state 4 starts overlay 0x58's second proc and resets to 0.
 *
 * Two pool words both name 0x02146948 (0x0202FA9C, the base of the field
 * stores, and 0x0202FAA8, the third call argument).  mwcc merges pool words
 * per symbol and CSEs the loaded address, so one symbol gives one word and
 * reuses r2 as the store base (184 -> 172 bytes, 98 out).  Two symbols at
 * the same address reproduce both words; sOverlayLaunchWorkArg is that
 * second name.  The state-2 test is written with the work in the `if` and
 * the bail-out after it (fall-through arm is the source order), so its
 * `*state = 4` block is the one state 3 branches back into.
 */
int OVERLAY_LAUNCH_Driver(void *unused, u32 *state)
{
    switch (*state) {
    case 0:
        PROCSYS_PushGlobal((u32)ov088_id, (const ProcData *)d_021BD8E8, (void *)&sOverlayLaunchWork.mode);
        *state = 1;
        break;
    case 1:
        sOverlayLaunchWork.mode = 1;
        sOverlayLaunchWork.stage = 0;
        sOverlayLaunchWork.enabled = 1;
        sOverlayLaunchWork.aborted = 0;
        PROCSYS_PushGlobal((u32)ov179_id, (const ProcData *)d_021B68D8, (void *)sOverlayLaunchWorkArg);
        *state = 2;
        break;
    case 2:
        if (sOverlayLaunchWork.aborted == 0) {
            sOverlayLaunchWork.stage = 1;
            sOverlayLaunchWork.aborted = 0;
            PROCSYS_PushGlobal((u32)ov179_id, (const ProcData *)d_021B68D8, (void *)sOverlayLaunchWorkArg);
            *state = 3;
            break;
        }
        *state = 4;
        break;
    case 3:
        sOverlayLaunchWork.stage = 2;
        sOverlayLaunchWork.aborted = 0;
        PROCSYS_PushGlobal((u32)ov179_id, (const ProcData *)d_021B68D8, (void *)sOverlayLaunchWorkArg);
        *state = 4;
        break;
    case 4:
        PROCSYS_PushGlobal((u32)ov088_id, (const ProcData *)d_021BD574, 0);
        *state = 0;
        break;
    }
    return 0;
}

int APP_POWER_IsReady(void)
{
    return 1;
}
