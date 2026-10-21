#!/usr/bin/env python3
"""protocheck.py: one prototype per function.

Every non-static function defined in src/game has a signature (return type and
parameter types).  Other files declare it again with an extern prototype, in a .c
file or a header.  This tool lists every declaration whose signature differs from
the definition's.

Types are compared after typedef resolution (typedefs are read from every src/game
file): scalars by width and signedness (u32, unsigned int and unsigned long are
one type; BOOL, fx32 and s32 are one type), pointers by pointee, aggregates by tag,
function pointers as one kind.  const and volatile are ignored.

A declaration resolves to a definition by name: first in its own region, then in
arm9, then anywhere if exactly one signature exists.  A name that has several
distinct definitions in that scope is skipped.  Calls that reach the function
through a `symbols:` row under another name are caught by tools/aliascheck.py,
which lists such second names; this tool does not follow them.

Mismatch kinds
  count     different number of parameters
  unproto   `f()` declared, the definition takes parameters
  ret       return type differs (void against a value, or two value types)
  ptrint    one side a pointer, the other an integer
  sign      same width, different signedness
  width     different integer width
  pointee   both pointers, different pointee
  other     anything else

    python tools/protocheck.py              summary and every mismatch (exit 1 if any)
    python tools/protocheck.py --tsv        tab separated rows: file line name kind declared defined
    python tools/protocheck.py --summary    counts only
    python tools/protocheck.py --ds          read the DS branch of #ifdef __MWERKS__ guards (default: the host branch)

Guards: a declaration under `#ifdef __MWERKS__` is the original DS prototype; the default run
reads the host branch (#else / #ifndef) and skips the DS one.  Other conditionals keep every branch.
"""
import argparse
import bisect
import os
import re
import sys

HERE = os.path.dirname(os.path.abspath(__file__))
ROOT = os.path.dirname(HERE)
GAME = os.path.join(ROOT, "src", "game")
sys.path.insert(0, HERE)
import protonames as pn  # noqa: E402
import placeholdernames as ph  # noqa: E402

# (declaring file, name): a declaration that stays different, with the reason.
EXCEPTIONS = [
    # ov094 btlv_effect.c: the original file-local prototype takes the move as a word; the definition takes u16.
    ("src/game/ov094/btlv_effect.c", "WAZA_TOOL_GetDamageType"),
    # arm9 callers that keep the original prototype. Each group says why (lane L2ARM9, 2026-10-21).
    # Width rows: the original caller passes the value at the wider width (heap id or coordinate as a word); a
    # prototype with the narrow width would add a mask at the call and change the bytes. Host: same result.
    ("src/game/arm9/arc_util.c", "BG_SYS_PushTile"),
    ("src/game/arm9/arc_util.c", "BG_SYS_MarkTileDirty"),
    ("src/game/arm9/clact.c", "VMAN_Create"),
    ("src/game/arm9/infowin.c", "BG_SYS_SetTileEntry"),
    ("src/game/arm9/mcss.c", "ARC_TOOL_LoadMember"),
    ("src/game/arm9/mcss.c", "ARC_TOOL_CreateHandle"),
    ("src/game/arm9/mcss.c", "ARC_TOOL_LoadHandleMember"),
    ("src/game/arm9/mcss.c", "ARC_UTIL_LoadCellBankFromArchive"),
    ("src/game/arm9/mcss.c", "ARC_UTIL_LoadMultiCellBankFromArchive"),
    ("src/game/arm9/mcss.c", "ARC_UTIL_LoadAnimBankFromArchive"),
    ("src/game/arm9/mcss.c", "ARC_UTIL_LoadMultiAnimBankFromArchive"),
    ("src/game/arm9/pms_draw.c", "CLACT_RegisterCharacter"),
    ("src/game/arm9/pms_draw.c", "CLACT_RegisterPaletteEx"),
    ("src/game/arm9/printsys.c", "BMP_Create"),
    ("src/game/arm9/time_icon.c", "BMP_WIN_Create"),
    ("src/game/arm9/wm_icon.c", "ARC_UTIL_UploadPaletteFromHandleWhole"),
    ("src/game/arm9/wm_icon.c", "ARC_UTIL_UploadScreenFromHandle"),
    ("src/game/arm9/bmp_menulist.c", "PRINTSYS_PrintQueColor"),
    ("src/game/arm9/bmp_menulist.c", "PRINTSYS_PrintColor"),
    # Void read: INFOWIN_LoadCharacters returns the value in r0 after BG_SYS_LoadPltt (a void function).
    ("src/game/arm9/infowin.c", "BG_SYS_LoadPltt"),
    # clact.c talks to the NNS G2D renderer and OAM manager through its own Surface, OamManager and transfer
    # task views, whose layouts differ from the SDK structs of nns_g2d_renderer.c and nns_g2d_oam_manager.c.
    # Retyping them is a whole-file job on clact.c (the bank pointers are already the SDK types).
    ("src/game/arm9/clact.c", "NNSi_G2dGetCellAnimFrameIdx"),
    ("src/game/arm9/clact.c", "NNSi_G2dReserveOamManagerSpan"),
    ("src/game/arm9/clact.c", "NNS_G2dInitRenderSurface"),
    ("src/game/arm9/clact.c", "NNSi_G2dEntryOamManagerOam"),
    ("src/game/arm9/clact.c", "NNS_G2dEntryOamManagerAffine"),
    ("src/game/arm9/clact.c", "NNS_G2dInitCellTransferStateManager"),
    # g3d_system.c: the nns_g3d_res.c, nns_g3d_tex.c and nns_g3d_mdl.c definitions take int and u8 * stand-ins, and
    # overlay callers (ov010, ov021, ov094, ov132, ov194) read the results through their own views.
    ("src/game/arm9/g3d_system.c", "NNS_G3dAnmObjInit"),
    ("src/game/arm9/g3d_system.c", "NNS_G3dAllocAnmObj"),
    ("src/game/arm9/g3d_system.c", "NNS_G3dGetMdlSet"),
    ("src/game/arm9/g3d_system.c", "NNS_G3dGetTex"),
    # gf_standard.c keeps its RtcDate and RtcTime views (28 files use struct RtcDate) and a callback of its own type.
    ("src/game/arm9/gf_standard.c", "RTC_GetDateTimeAsync"),
    # mcss.c: the enumeration callback and the colour blend take untyped pointers in the original caller.
    ("src/game/arm9/mcss.c", "NNSi_G2dMCEnumAnimBank"),
    ("src/game/arm9/mcss.c", "PALANM_BlendColors"),
    # particle.c reads the SPL manager head through a three-word view; the definition returns the full head struct.
    ("src/game/arm9/particle.c", "SPL_EMITTER_AllocNodeFromHeap"),
    # ov009 GameSpy callers declare int rand(void) and divide the result as signed; the ARM9 rand
    # returns an unsigned value (gpiconnect.c divides it as unsigned, umull). Both forms are in the
    # original bytes, so the callers keep their own declaration.
    ("src/game/ov009/gt2auth.c", "rand"),
    ("src/game/ov009/qr2.c", "rand"),
    ("src/game/ov009/sb_serverlist.c", "rand"),
    # L5MENUS (2026-10-21): overlay callers (ov067-ov231) that keep the original prototype. protocheck --fix and the
    # struct/width retype were tried per declaration: the definition's type changes the DS bytes (width, sign, argument
    # count, return of a void callee) or needs a record-layout change in the defining overlay (pointee, stand-in return).
    # Width, sign and count rows: host same (the caller truncates or ignores on both ABIs). Per file below.
    ("src/game/ov067/frame_list.c", "BG_SYS_DrawTileEx"),  # width
    ("src/game/ov067/touchbar.c", "CLACT_RegisterPaletteEx"),  # width
    ("src/game/ov067/touchbar.c", "CLACT_RegisterCharacter"),  # width
    ("src/game/ov067/touchbar.c", "ARC_UTIL_UploadPaletteFromHandleWhole"),  # sign,width
    ("src/game/ov067/touchbar.c", "ARC_UTIL_RegisterObjCharFromHandle"),  # width
    ("src/game/ov067/touchbar.c", "BG_SYS_DrawTileEx"),  # width
    ("src/game/ov067/touchbar.c", "BG_SYS_PushTile"),  # width
    ("src/game/ov067/touchbar.c", "STRBUF_Create"),  # width
    ("src/game/ov067/yesno_menu.c", "PRINTSYS_PrintQueColor"),  # pointee,ptrint,width
    ("src/game/ov067/yesno_menu.c", "CLACT_AddActorSurfacePos"),  # width
    ("src/game/ov068/option_menu.c", "GFL_HEAP_Free"),  # ret
    ("src/game/ov068/option_menu.c", "PRINTSYS_PrintColor"),  # width
    ("src/game/ov068/option_menu.c", "CLACT_RegisterPalette"),  # sign,width
    ("src/game/ov068/option_menu.c", "CLACT_RegisterCharacter"),  # sign,width
    ("src/game/ov068/option_menu.c", "CLACT_CreateActor"),  # ptrint,width
    ("src/game/ov070/itemmenu.c", "FILE_UTIL_GetItemParam"),  # width
    ("src/game/ov070/itemmenu.c", "ARC_UTIL_UploadBgPaletteAddFromHandle"),  # ret
    ("src/game/ov070/itemmenu.c", "FILE_UTIL_Get"),  # sign,width
    ("src/game/ov070/itemmenu.c", "WAZA_TOOL_GetParam"),  # width
    ("src/game/ov070/itemmenu.c", "BUTTON_MAN_Create"),  # ret,unproto
    ("src/game/ov070/itemmenu.c", "GFL_USE_AddMainTask"),  # ret,unproto
    ("src/game/ov072/townmap.c", "CLACT_RegisterCharacter"),  # width
    ("src/game/ov072/townmap.c", "TOUCHBAR_Create"),  # width
    ("src/game/ov072/townmap_grh.c", "CLACT_DrawSystem"),  # count
    ("src/game/ov076/enceff_model_scene.c", "GAME_EVENT_Create"),  # other
    ("src/game/ov076/enceff_model_types.h", "ENCEFF_GetWork"),  # ret
    ("src/game/ov077/enceff_cell_grid.c", "GAME_EVENT_Create"),  # other
    ("src/game/ov077/enceff_grid_types.h", "ENCEFF_GetWork"),  # ret
    ("src/game/ov079/enceff_block_flip.c", "ENCEFF_StartScreenTexEffectFlash"),  # other
    ("src/game/ov083/gpower_event.c", "SCRIPT_WORK_SetParams"),  # width
    ("src/game/ov083/gpower_event.c", "GPOWER_GetPowerCost"),  # ret
    ("src/game/ov083/gpower_event.c", "GAME_BEACON_SEARCH_SetHalfwordValue"),  # width
    ("src/game/ov088/save_control_intr.c", "SAVE_CONTROL_SetOutsideSaveLoaded"),  # pointee,width
    ("src/game/ov088/save_control_intr.c", "SAVE_CONTROL_SetOutsideSaveBroken"),  # pointee,width
    ("src/game/ov088/startmenu.c", "BG_SYS_SetPlaneVisible"),  # width
    ("src/game/ov088/startmenu.c", "BG_SYS_Create"),  # width
    ("src/game/ov088/startmenu.c", "G3D_SYSTEM_Init"),  # sign,width
    ("src/game/ov088/startmenu.c", "TCBL_Create"),  # sign,width
    ("src/game/ov088/startmenu.c", "GFL_USE_AddMainTask"),  # other,sign
    ("src/game/ov088/startmenu.c", "ARC_UTIL_UploadBgCharFromArchive"),  # width
    ("src/game/ov088/startmenu.c", "ARC_UTIL_UploadBgPaletteFromArchive"),  # width
    ("src/game/ov088/startmenu.c", "ARC_UTIL_UploadPaletteFromArchiveWhole"),  # width
    ("src/game/ov088/startmenu.c", "G3D_UTIL_Create"),  # width
    ("src/game/ov088/startmenu.c", "G3D_UTIL_GetObject"),  # width
    ("src/game/ov088/startmenu.c", "G3D_CAMERA_Create"),  # sign,width
    ("src/game/ov088/startmenu.c", "G3D_LIGHT_CreateSlots"),  # width
    ("src/game/ov088/startmenu.c", "CLACT_RegisterCharacter"),  # sign,width
    ("src/game/ov088/startmenu.c", "CLACT_RegisterPalette"),  # sign,width
    ("src/game/ov088/startmenu.c", "CLACT_CreateActor"),  # sign,width
    ("src/game/ov088/startmenu.c", "PLAYER_LOCATION_GetLocationA"),  # pointee,ret
    ("src/game/ov088/startmenu.c", "BG_SYS_DrawTileEx"),  # width
    ("src/game/ov088/startmenu.c", "BG_SYS_FillTileMap"),  # width
    ("src/game/ov088/startmenu.c", "BG_SYS_FreeSlot"),  # width
    ("src/game/ov091/plist_battle.c", "BMP_WIN_Create"),  # ret,sign,width
    ("src/game/ov091/plist_menu.c", "APP_TASKMENU_WIN_Create"),  # width
    ("src/game/ov091/plist_plate.c", "BMP_WIN_Create"),  # sign,width
    ("src/game/ov091/plist_plate.c", "BGWINFRM_GetScaleRank"),  # ret
    ("src/game/ov091/pokelist.c", "G3D_SYSTEM_Init"),  # ptrint,sign,width
    ("src/game/ov091/pokelist.c", "PRINTSYS_PrintColor"),  # width
    ("src/game/ov092/event_battle_return.c", "SHINKA_CHECK_CheckEvolution"),  # ret
    ("src/game/ov168/mictest.c", "BMP_WIN_Init"),  # width
    ("src/game/ov168/mictest.c", "BG_SYS_InitRun"),  # width
    ("src/game/ov203/demo3d.c", "DEMO3D_GRAPHIC_Create"),  # width
    ("src/game/ov203/demo3d_cmdsys.c", "DEMO3D_DATA_GetCommandList"),  # ret,sign
    ("src/game/ov203/demo3d_exp_c_cruiser.c", "UI_SCENE_CreateActor"),  # width
    ("src/game/ov203/demo3d_graphic.c", "G3D_LIGHT_SetDirection"),  # width
    ("src/game/ov203/demo3d_graphic.c", "CLACT_ExitSystem"),  # count
    ("src/game/ov203/demo3d_graphic.c", "G3D_SYSTEM_Exit"),  # count
    ("src/game/ov204/intro_cmd.c", "MYSTATUS_SetSex"),  # pointee
    ("src/game/ov204/intro_g3d.c", "G3D_UTIL_Create"),  # width
    ("src/game/ov204/intro_g3d.c", "G3D_CAMERA_Create"),  # width
    ("src/game/ov204/intro_graphic.c", "G3D_SYSTEM_Init"),  # sign
    ("src/game/ov206/zukan_info.c", "BMP_WIN_Create"),  # width
    ("src/game/ov206/zukan_info.c", "BMP_Blit"),  # width
    ("src/game/ov206/zukan_info.c", "CLACT_AddActorSurfacePos"),  # width
    ("src/game/ov207/zukan_toroku_graphic.c", "GFL_USE_AddMainTask"),  # ptrint
    ("src/game/ov207/zukan_toroku_graphic.c", "BG_SYS_Create"),  # width
    ("src/game/ov208/zknd_tbar.c", "BG_SYS_PushTile"),  # width
    ("src/game/ov208/zukan_detail_area.c", "BG_SYS_InitBgLayer"),  # width
    ("src/game/ov208/zukan_detail_graphic.c", "CLACT_DrawSystem"),  # count
    ("src/game/ov208/zukan_detail_graphic.c", "G3D_SYSTEM_Init"),  # width
    ("src/game/ov208/zukan_detail_info.c", "CLACT_CreateActor"),  # pointee,ptrint
    ("src/game/ov208/zukan_detail_info.c", "ZUKAN_INFO_Create"),  # ptrint
    ("src/game/ov208/zukan_detail_info.c", "ZUKAN_SAVE_GetViewGenderAndForm"),  # width
    ("src/game/ov208/zukan_detail_info.c", "ZUKAN_SAVE_IsCaught"),  # width
    ("src/game/ov208/zukan_detail_voice.c", "ZUKAN_SAVE_GetViewGenderAndForm"),  # width
    ("src/game/ov209/zukan_list.c", "ZUKAN_SAVE_SetLastViewedSpecies"),  # width
    ("src/game/ov209/zukan_list.c", "ZUKAN_CreateActor"),  # ret
    ("src/game/ov210/zknsearch_main.c", "ZUKAN_SEARCH_ENGINE_Create"),  # ret
    ("src/game/ov210/zknsearch_sys.c", "TCB_DeleteTask"),  # ret
    ("src/game/ov211/zukan_search_screen.c", "SAVE_CONTROL_LoadExtraSave"),  # width
    ("src/game/ov212/zukan.c", "CLACT_CreateActor"),  # pointee
    ("src/game/ov213/comm_btl_demo_graphic.c", "BG_SYS_Create"),  # width
    ("src/game/ov213/comm_btl_demo_graphic.c", "G3D_SYSTEM_Init"),  # width
    ("src/game/ov213/comm_btl_demo_graphic.c", "G3D_CAMERA_Create"),  # width
    ("src/game/ov213/comm_btl_demo_graphic.c", "G3D_SYSTEM_Exit"),  # count
    ("src/game/ov213/comm_btl_demo_main.c", "UI_SCENE_Create"),  # width
    ("src/game/ov213/comm_btl_demo_main.c", "BMP_WIN_Create"),  # ret,width
    ("src/game/ov213/comm_btl_demo_main.c", "UI_SCENE_LoadActorGfx"),  # width
    ("src/game/ov213/comm_btl_demo_main.c", "UI_SCENE_CreateActor"),  # width
    ("src/game/ov213/comm_btl_demo_main.c", "G3D_UTIL_Create"),  # width
    ("src/game/ov214/btl_rec_sel.c", "PRINTSYS_PrintQueColor"),  # width
    ("src/game/ov214/btl_rec_sel.c", "BG_SYS_FreeLayerBuf"),  # width
    ("src/game/ov214/btl_rec_sel.c", "PALANM_RequestFade"),  # width
    ("src/game/ov214/btl_rec_sel_graphic.c", "BG_SYS_Create"),  # width
    ("src/game/ov214/btl_rec_sel_graphic.c", "G3D_SYSTEM_Init"),  # width
    ("src/game/ov214/btl_rec_sel_graphic.c", "G3D_CAMERA_Create"),  # width
    ("src/game/ov214/btl_rec_sel_graphic.c", "G3D_SYSTEM_Exit"),  # count
    ("src/game/ov215/egg_demo_graphic.c", "G3D_SYSTEM_Init"),  # width
    ("src/game/ov215/egg_demo_graphic.c", "G3D_SYSTEM_Exit"),  # count
    ("src/game/ov216/beacon_detail_gra.c", "TOUCHBAR_Create"),  # width
    ("src/game/ov216/beacon_detail_gra.c", "BMP_WIN_Create"),  # ret,width
    ("src/game/ov216/beacon_detail_gra.c", "BG_SYS_Create"),  # width
    ("src/game/ov216/beacon_detail_gra.c", "PMS_DRAW_IsActive"),  # pointee
    ("src/game/ov216/beacon_detail_gra.c", "TOWNMAP_GRH_GetTownInfoValue"),  # width
    ("src/game/ov216/beacon_detail_gra.c", "PRINTSYS_PrintQueColor"),  # width
    ("src/game/ov217/bg_font.c", "PRINTSYS_PrintColor"),  # width
    ("src/game/ov217/research_common.c", "CLACT_ReleaseCellAnim"),  # ret,unproto
    ("src/game/ov217/research_common.c", "CLACT_ExitSystem"),  # count,ret
    ("src/game/ov217/research_graph.c", "BG_SYS_PushTile"),  # ret,sign
    ("src/game/ov217/research_graph.c", "GFL_USE_PlaySeDefaultVolume"),  # ret
    ("src/game/ov217/research_graph.c", "BG_SYS_ClearSlot"),  # ret,unproto
    ("src/game/ov217/research_graph.c", "CLACT_ReleaseCellAnim"),  # ret,unproto
    ("src/game/ov217/research_graph.c", "PALETTE_ANIME_IsRunning"),  # ret,unproto
    ("src/game/ov217/research_graph.c", "PRINTSYS_PrintColor"),  # width
    ("src/game/ov217/research_graph.c", "BG_SYS_FreeLayerBuf"),  # ret,unproto
    ("src/game/ov217/research_list.c", "BG_SYS_FillTileMap"),  # width
    ("src/game/ov217/research_list.c", "PALETTE_ANIME_IsRunning"),  # ret,unproto
    ("src/game/ov217/research_list.c", "PRINTSYS_PrintColor"),  # width
    ("src/game/ov217/research_top.c", "BG_SYS_Delete"),  # ret
    ("src/game/ov217/research_top.c", "BG_SYS_FillTileMap"),  # width
    ("src/game/ov217/research_top.c", "CLACT_SetActorAnimFrame"),  # ret,unproto
    ("src/game/ov217/research_top.c", "BG_SYS_ClearSlot"),  # ret,unproto
    ("src/game/ov217/research_top.c", "CLACT_ReleaseCellAnim"),  # ret,unproto
    ("src/game/ov218/un_select.c", "TOUCHBAR_Create"),  # width
    ("src/game/ov218/un_select.c", "CLACT_GetActorSurfacePos"),  # width
    ("src/game/ov218/un_select_graphic.c", "BG_SYS_Create"),  # width
    ("src/game/ov218/un_select_graphic.c", "BG_SYS_FreeLayerBuf"),  # width
    ("src/game/ov218/un_select_graphic.c", "G3D_SYSTEM_Init"),  # width
    ("src/game/ov218/un_select_graphic.c", "G3D_CAMERA_Create"),  # width
    ("src/game/ov219/beacon_detail.c", "MSGDATA_CreateFromArchive"),  # width
    ("src/game/ov219/beacon_detail.c", "WIFI_HISTORY_InitLanguageRegion"),  # width
    ("src/game/ov219/beacon_detail.c", "G3D_SYSTEM_Init"),  # width
    ("src/game/ov219/beacon_detail.c", "BMP_WIN_Exit"),  # count,ret
    ("src/game/ov219/beacon_detail.c", "G3D_SYSTEM_Exit"),  # count,ret
    ("src/game/ov219/beacon_detail.c", "BG_SYS_Delete"),  # count
    ("src/game/ov219/beacon_detail.c", "PRINTSYS_PrintQue"),  # pointee,ptrint,width
    ("src/game/ov219/beacon_detail.c", "STRBUF_Create"),  # ret
    ("src/game/ov219/beacon_detail.c", "MSGDATA_ReadString"),  # pointee
    ("src/game/ov220/th_award_graphic.c", "BG_SYS_Create"),  # width
    ("src/game/ov221/chihou_zukan_award_graphic.c", "BG_SYS_Create"),  # width
    ("src/game/ov221/chihou_zukan_award_graphic.c", "BG_SYS_FreeLayerBuf"),  # width
    ("src/game/ov221/chihou_zukan_award_graphic.c", "G3D_SYSTEM_Init"),  # width
    ("src/game/ov221/chihou_zukan_award_graphic.c", "G3D_CAMERA_Create"),  # width
    ("src/game/ov221/chihou_zukan_award_graphic.c", "G3D_SYSTEM_Exit"),  # count,ret
    ("src/game/ov222/zenkoku_zukan_award_graphic.c", "BG_SYS_Create"),  # width
    ("src/game/ov222/zenkoku_zukan_award_graphic.c", "G3D_SYSTEM_Init"),  # width
    ("src/game/ov222/zenkoku_zukan_award_graphic.c", "G3D_CAMERA_Create"),  # width
    ("src/game/ov222/zenkoku_zukan_award_graphic.c", "G3D_SYSTEM_Exit"),  # count
    ("src/game/ov223/psel.c", "ICA_ANIME_SetFrame"),  # ptrint,ret
    ("src/game/ov223/psel.c", "G3D_UTIL_RemoveUnit"),  # pointee
    ("src/game/ov223/psel.c", "BG_SYS_ClearLayerEx"),  # ret,width
    ("src/game/ov223/psel.c", "APP_TASKMENU_RES_Delete"),  # pointee,ret
    ("src/game/ov223/psel_graphic.c", "PSEL_NopBgDelete"),  # count
    ("src/game/ov223/psel_graphic.c", "PSEL_ClearBgLayer2"),  # count
    ("src/game/ov223/psel_graphic.c", "TOUCHPANEL_HitTrg"),  # pointee
    ("src/game/ov223/psel_graphic.c", "BG_SYS_Create"),  # width
    ("src/game/ov223/psel_graphic.c", "G3D_SYSTEM_Init"),  # sign,width
    ("src/game/ov223/psel_graphic.c", "G3D_CAMERA_Create"),  # pointee,ret,sign,width
    ("src/game/ov223/psel_graphic.c", "G3D_SYSTEM_Exit"),  # count
    ("src/game/ov224/subway_map_graphic.c", "BG_SYS_Create"),  # width
    ("src/game/ov224/subway_map_graphic.c", "G3D_SYSTEM_Init"),  # width
    ("src/game/ov224/subway_map_graphic.c", "G3D_CAMERA_Create"),  # width
    ("src/game/ov224/subway_map_graphic.c", "G3D_SYSTEM_Exit"),  # count
    ("src/game/ov225/manual_graphic.c", "BG_SYS_Create"),  # width
    ("src/game/ov225/manual_list.c", "NNS_GfdRegisterNewVramTransferTask"),  # ptrint
    ("src/game/ov225/manual_touchbar.c", "TOUCHBAR_Create"),  # pointee,ret,width
    ("src/game/ov230/sealed_checks_card_image.c", "CARDi_ReadRom"),  # other
]

KW = {"asm", "const", "volatile", "register", "extern", "static", "inline", "__inline", "auto"}
SCALARS = {"char", "short", "int", "long", "signed", "unsigned", "float", "double", "void"}
NOT_TYPE_WORDS = {"return", "else", "do", "case", "goto", "sizeof", "typedef", "if", "while", "for", "switch"}


DS_BUILD = [False]   # True: __MWERKS__ is defined (the DS branch of a guard counts)
_MW = re.compile(r"^\s*#\s*(ifdef|ifndef|if|elif|else|endif)\b\s*(.*)$")


def _mw_cond(kind, rest):
    """True/False when the directive tests only __MWERKS__, else None (unknown)."""
    rest = rest.strip()
    if kind == "ifdef":
        return True if rest == "__MWERKS__" else None
    if kind == "ifndef":
        return False if rest == "__MWERKS__" else None
    if kind in ("if", "elif"):
        if re.fullmatch(r"defined\s*\(\s*__MWERKS__\s*\)|defined\s+__MWERKS__", rest):
            return True
        if re.fullmatch(r"!\s*defined\s*\(\s*__MWERKS__\s*\)|!\s*defined\s+__MWERKS__", rest):
            return False
    return None


def strip_pp(code):
    """Preprocessor lines (with continuations) blanked, newlines kept.  A branch that
    #ifdef __MWERKS__ / #ifndef __MWERKS__ / #else selects away is blanked too: the host
    build (__MWERKS__ undefined) by default, the DS build with DS_BUILD[0] set.  Other
    conditionals keep every branch."""
    out = []
    cont = False
    stack = []   # [parent_active, known, cond_value_of_current_branch]
    active = True
    mw = DS_BUILD[0]
    for line in code.split("\n"):
        if cont:
            cont = line.rstrip().endswith("\\")
            out.append(" " * len(line))
            continue
        m = _MW.match(line) if line.lstrip().startswith("#") else None
        if m:
            kind, rest = m.group(1), m.group(2)
            if kind in ("ifdef", "ifndef", "if"):
                c = _mw_cond(kind, rest)
                stack.append([active, c is not None, c])
                if c is not None:
                    active = active and (c == mw)
            elif kind == "elif" and stack:
                c = _mw_cond(kind, rest)
                st = stack[-1]
                if st[1] or c is not None:
                    st[1] = True
                    st[2] = c if c is not None else (not st[2])
                    active = st[0] and (st[2] == mw)
            elif kind == "else" and stack:
                st = stack[-1]
                if st[1]:
                    active = st[0] and ((not st[2]) == mw)
            elif kind == "endif" and stack:
                active = stack.pop()[0]
        if cont or line.lstrip().startswith("#"):
            cont = line.rstrip().endswith("\\")
            out.append(" " * len(line))
        else:
            out.append(line if active else " " * len(line))
    return "\n".join(out)


def clean(path):
    raw = open(path, encoding="latin1", newline="").read().replace("\r\n", "\n")
    return strip_pp(ph.strip_comments(raw))


# ---------------------------------------------------------------- typedefs

class Types:
    def __init__(self, files):
        self.alias = {}      # name -> list of resolutions (text) found
        self.anon = set()    # "struct Name" tags that are only a typedef name (no tag in the source)
        for f in files:
            code = clean(f)
            self._scan(code)

    def _scan(self, code):
        for m in re.finditer(r"\btypedef\b", code):
            i = m.end()
            # find the end of the statement at depth 0
            depth = 0
            j = i
            while j < len(code):
                c = code[j]
                if c == "{":
                    depth += 1
                elif c == "}":
                    depth -= 1
                elif c == ";" and depth == 0:
                    break
                j += 1
            body = code[i:j]
            if depth != 0:
                continue
            fn = re.search(r"\(\s*\*+\s*(\w+)\s*\)\s*\(", body)
            if fn and not re.match(r"\s*(?:struct|union|enum)\s*\w*\s*\{", body):

                self.alias.setdefault(fn.group(1), set()).add("@fnptr")
                continue
            sm = re.match(r"\s*(struct|union|enum)\s*(\w*)\s*\{", body)
            if sm:
                kind, tag = sm.group(1), sm.group(2)
                # the declarator list follows the closing brace
                k = body.rfind("}")
                tail = body[k + 1:]
                for d in tail.split(","):
                    stars = d.count("*")
                    nm = re.search(r"(\w+)\s*(\[[^\]]*\])?\s*$", d)
                    if not nm:
                        continue
                    if kind == "enum":
                        res = "int"
                    else:
                        res = "%s %s" % (kind, tag or nm.group(1))
                        if not tag:
                            self.anon.add(res)
                    self.alias.setdefault(nm.group(1), set()).add(res + " *" * stars)
                continue
            # plain alias: typedef <type tokens> name[, name2];
            parts = body.split(",")
            first = parts[0]
            toks = re.findall(r"[A-Za-z_]\w*|\*", first)
            if len(toks) < 2:
                continue
            nm = toks[-1]
            base = toks[:-1]
            self.alias.setdefault(nm, set()).add(" ".join(base))
            for extra in parts[1:]:
                et = re.findall(r"[A-Za-z_]\w*|\*", extra)
                if et:
                    stars = " ".join(t for t in et[:-1] if t == "*")
                    self.alias.setdefault(et[-1], set()).add(" ".join(
                        [t for t in base if t != "*"]) + (" " + stars if stars else ""))

    def is_type_name(self, w):
        return w in self.alias

    def canon(self, toks, depth=0):
        """Canonical type string from a token list (no declarator name)."""
        stars = sum(1 for t in toks if t == "*")
        words = [t for t in toks if t != "*" and t not in KW]
        if not words:
            return "?"
        if words[0] in ("struct", "union") and len(words) >= 2:
            base = "%s %s" % (words[0], words[1])
        elif words[0] == "enum":
            base = "s32"
        elif all(w in SCALARS for w in words):
            base = self.scalar(words)
        elif len(words) == 1:
            w = words[0]
            res = self.alias.get(w)
            if res is None:
                base = w
            elif depth > 8:
                base = w
            else:
                outs = {self.canon(re.findall(r"[A-Za-z_]\w*|\*", r), depth + 1) if r != "@fnptr" else "@fnptr"
                        for r in res}
                if len(outs) == 1:
                    base = outs.pop()
                else:
                    base = w          # ambiguous: compare by name
        else:
            base = " ".join(words)
        if base == "@fnptr":
            return "@fnptr" + "*" * max(0, stars - 1) if stars == 0 else "@fnptr" + "*" * stars
        # a base that already holds pointers (alias to a pointer type)
        return base + "*" * stars

    @staticmethod
    def scalar(words):
        w = list(words)
        uns = "unsigned" in w
        w = [x for x in w if x not in ("signed", "unsigned")]
        if "void" in w:
            return "void"
        if "float" in w:
            return "float"
        if "double" in w:
            return "double"
        if w.count("long") >= 2:
            return "u64" if uns else "s64"
        if "char" in w:
            if uns:
                return "u8"
            return "s8" if "signed" in words else "char"
        if "short" in w:
            return "u16" if uns else "s16"
        return "u32" if uns else "s32"


def int_kind(t):
    """(width, signed) of an integer canonical type, or None."""
    return {"u8": (8, 0), "s8": (8, 1), "char": (8, 1), "u16": (16, 0), "s16": (16, 1), "u32": (32, 0),
            "s32": (32, 1), "u64": (64, 0), "s64": (64, 1)}.get(t)


def classify(a, b):
    """Kind of difference between two canonical types, or None if equal."""
    if a == b:
        return None
    if a.endswith("*") and b.endswith("*"):
        if a.startswith("@fnptr") or b.startswith("@fnptr"):
            return "pointee"
        return "pointee"
    if a.endswith("*") or b.endswith("*") or a.startswith("@fnptr") or b.startswith("@fnptr"):
        other = b if (a.endswith("*") or a.startswith("@fnptr")) else a
        if int_kind(other):
            return "ptrint"
        return "other"
    ka, kb = int_kind(a), int_kind(b)
    if ka and kb:
        return "sign" if ka[0] == kb[0] else "width"
    return "other"


# ---------------------------------------------------------------- parsing

DECL = re.compile(r"\b([A-Za-z_]\w*)\s*\(((?:[^;{}()]|\([^;{}()]*\)|\((?:[^;{}()]|\([^;{}()]*\))*\))*)\)\s*(?=[{;])", re.S)


def parse_params(types, text):
    text = text.strip()
    if text == "":
        return None                       # unprototyped
    if text == "void":
        return []
    out = []
    for p in pn.split_params(text):
        p = p.strip()
        if p == "...":
            out.append("...")
            continue
        if "(" in p:
            out.append("@fnptr")
            continue
        p = re.sub(r"(\w*)\s*(?:\[[^\]]*\]\s*)+", lambda m: " * " + m.group(1) + " ", p)
        toks = re.findall(r"[A-Za-z_]\w*|\*", p)
        toks = [t for t in toks if t not in KW]
        if len(toks) >= 2 and re.match(r"[A-Za-z_]", toks[-1]) and toks[-1] not in SCALARS \
                and toks[-2] not in ("struct", "union", "enum"):
            prev = toks[-2]
            if prev == "*" or prev in SCALARS or types.is_type_name(prev):
                toks = toks[:-1]
        out.append(types.canon(toks))
    return out


def scan(path, types):
    """Declarations: (name, ret, params|None, line, is_def, is_static)."""
    code = clean(path)
    starts = [0]
    for i, ch in enumerate(code):
        if ch == "\n":
            starts.append(i + 1)
    # brace depth per character position via cumulative scan
    depth = 0
    depths = []
    bpos = []
    for i, ch in enumerate(code):
        if ch == "{":
            depth += 1
        elif ch == "}":
            depth = max(0, depth - 1)
        depths.append(depth)
    res = []
    for m in DECL.finditer(code):
        name = m.group(1)
        if name in NOT_TYPE_WORDS or name in SCALARS or name in KW:
            continue
        d = depths[m.start()]
        # preceding statement text
        k = max(code.rfind(";", 0, m.start()), code.rfind("}", 0, m.start()), code.rfind("{", 0, m.start()))
        pre = code[k + 1:m.start()]
        pre_toks = re.findall(r"[A-Za-z_]\w*|\*|[^\sA-Za-z_0-9*]", pre)
        if not pre_toks:
            continue
        if any(not (re.match(r"[A-Za-z_]", t) or t == "*") for t in pre_toks):
            continue
        if any(t in NOT_TYPE_WORDS for t in pre_toks):
            continue
        if "typedef" in pre_toks:
            continue
        after = code[m.end():].lstrip()[:1]
        is_def = after == "{"
        if d > 0:
            if is_def or "extern" not in pre_toks:
                if is_def:
                    continue
                # block-scope declaration without extern: a type then the name
                if len(pre_toks) < 1 or not (types.is_type_name(pre_toks[0]) or pre_toks[0] in SCALARS
                                             or pre_toks[0] in ("struct", "union", "enum", "const", "volatile")):
                    continue
                if pre_toks[-1] == "*" or True:
                    pass
        elif is_def and d != 0:
            continue
        if d == 0 and is_def is False and after != ";":
            continue
        static = "static" in pre_toks
        rtoks = [t for t in pre_toks if t not in KW]
        ret = types.canon(rtoks)
        params = parse_params(types, m.group(2))
        line = bisect.bisect_right(starts, m.start())
        extra = {"pre_toks": pre_toks, "pre_start": k + 1, "name_start": m.start(),
                 "par_start": m.start(2), "par_end": m.end(2), "depth": d, "ptext": m.group(2)}
        res.append((name, ret, params, line, is_def, static, extra))
    return res, code, depths


def sig_text(ret, params):
    if params is None:
        return "%s (?)" % ret
    return "%s (%s)" % (ret, ", ".join(params))


def region_of(path):
    return os.path.relpath(path, GAME).replace(os.sep, "/").split("/")[0]


def compare(ret_d, par_d, ret_x, par_x):
    """Kind list for a declaration x against definition d."""
    kinds = []
    if par_x is None:
        if par_d:
            kinds.append("unproto")
    elif len(par_x) != len(par_d):
        kinds.append("count")
    else:
        for a, b in zip(par_x, par_d):
            k = classify(a, b)
            if k:
                kinds.append(k)
    k = classify(ret_x, ret_d)
    if k:
        kinds.append("ret")
    return kinds


# ---------------------------------------------------------------- fixing

SCALAR_TEXT = {"char", "u8", "s8", "u16", "s16", "u32", "s32", "u64", "s64", "float", "double", "void"}


KEYWORD_FORM = {"u8": "unsigned char", "s8": "signed char", "u16": "unsigned short", "s16": "short",
                "u32": "unsigned int", "s32": "int", "u64": "unsigned long long", "s64": "long long"}


def visible_typedefs(path, seen=None):
    """Names of the u8..s64 typedefs visible in a file: its own text and its quoted includes."""
    seen = seen if seen is not None else set()
    if path in seen or not os.path.isfile(path):
        return set()
    seen.add(path)
    raw = open(path, encoding="latin1").read()
    out = set(re.findall(r"\btypedef\b[^;{}]*?\b(u8|s8|u16|s16|u32|s32|u64|s64)\s*;", raw))
    for inc in re.findall(r'^\s*#\s*include\s+"([^"]+)"', raw, re.M):
        out |= visible_typedefs(os.path.normpath(os.path.join(os.path.dirname(path), inc)), seen)
    return out


def canon_text(types, c, code="", vis=None):
    """Source text of a canonical type, or None if it cannot be written in this file."""
    base = c.rstrip("*")
    n = len(c) - len(base)
    if base == "bool":
        # bool is a per-file typedef (typedef _Bool bool;), so only a file that declares it can spell it
        if not re.search(r"\btypedef\s+_Bool\s+bool\s*;", code or ""):
            return None
    elif base in SCALAR_TEXT:
        if vis is not None and base in KEYWORD_FORM and base not in vis:
            base = KEYWORD_FORM[base]
    elif base.startswith(("struct ", "union ")) and base not in types.anon:
        if n == 0:
            return None          # by value: the caller needs the complete type, a forward declaration is not enough
    elif base in types.anon:
        nm = base.split()[1]
        if not re.search(r"\b%s\b" % re.escape(nm), code):
            return None
        base = nm
    else:
        return None
    return base + (" " + "*" * n if n else "")


def join_name(t, name):
    if not name:
        return t
    return t + ("" if t.endswith("*") else " ") + name


def def_names(ptext):
    if not ptext.strip() or ptext.strip() == "void":
        return []
    out = []
    for p in pn.split_params(ptext):
        r = pn.param_name(p)
        out.append(r[0] if r else None)
    return out


def build_edits(types, code, depths, items, vis=None):
    """One edit per declaration of one file; items come from `detail`.

    edit = dict(name, local=[(start, end, text)], tags=[(tag, pos)], pos, ret, params, ptexts, rtext)
    """
    semis = [i for i, ch in enumerate(code) if ch == ";" and depths[i] == 0]
    edits = []
    skipped = []
    for (f, name, ret, params, line, d, kinds, ex) in items:
        dret, dparams, dex = d[2], d[3] or [], d[5]
        tags = []
        rtext = canon_text(types, dret, code, vis)
        dtexts = pn.split_params(ex["ptext"]) if ex["ptext"].strip() not in ("", "void") else []
        names = def_names(dex["ptext"])
        if len(names) != len(dparams):
            names = [None] * len(dparams)
        ptexts = []
        full = []
        bad = rtext is None
        for i, c in enumerate(dparams):
            if c == "...":
                ptexts.append("...")
                full.append("...")
            elif c.startswith("@fnptr"):
                if params is not None and len(params) == len(dparams) and params[i] == c and i < len(dtexts):
                    ptexts.append("@keep")
                    full.append(dtexts[i].strip())
                else:
                    bad = True
                    break
            else:
                t = canon_text(types, c, code, vis)
                if t is None:
                    bad = True
                    break
                ptexts.append(t)
                full.append(join_name(t, names[i]))
        if bad:
            skipped.append((name, "unwritable type"))
            continue
        local = []
        if any(k != "ret" for k in kinds):
            new = ", ".join(full) if dparams else "void"
            local.append((ex["par_start"], ex["par_end"], new))
        if "ret" in kinds:
            pre = code[ex["pre_start"]:ex["name_start"]]
            ws = pre[:len(pre) - len(pre.lstrip())]
            newpre = ws + ("extern " if "extern" in ex["pre_toks"] else "") + join_name(rtext, "")
            newpre += "" if newpre.endswith("*") else " "
            local.append((ex["pre_start"], ex["name_start"], newpre))
        for t in [rtext] + [x for x in ptexts if x not in ("...", "@keep")]:
            b = t.rstrip("* ")
            if b.startswith(("struct ", "union ")):
                tags.append((b, ex["name_start"]))
        edits.append(dict(name=name, local=local, tags=tags, pos=ex["name_start"], ret=dret,
                          params=dparams, ptexts=ptexts, rtext=rtext, vis=vis))
    return edits, skipped, semis


def apply_edits(code, edits_sel, semis, types):
    """Text edits for the selected declaration edits (offsets refer to the cleaned code, same as the LF text)."""
    out = []
    inserted = set()
    for e in sorted(edits_sel, key=lambda x: x["pos"]):
        for s, en, t in e["local"]:
            out.append((s, en, t))
        for tag, npos in e["tags"]:
            i = bisect.bisect_left(semis, npos) - 1
            ins = semis[i] + 1 if i >= 0 else 0
            kind, tg = tag.split()
            if tag in inserted or re.search(r"\b%s\s+%s\b" % (kind, tg), code[:ins]):
                continue
            inserted.add(tag)
            out.append((ins, ins, "\n%s;" % tag))
    seen = set()
    final = []
    for s, e, t in out:
        if (s, e, t) in seen:
            continue
        seen.add((s, e, t))
        final.append((s, e, t))
    return final


def splice(raw, final):
    res = raw
    for s, e, t in sorted(final, key=lambda x: (x[0], x[1]), reverse=True):
        res = res[:s] + t + res[e:]
    return res


def compile_errors(rel, lenient=False):
    """(ok, errors) of one file compiled as gameverify does, in process.  errors: [(line, text)]
    from every language mode; the continuation line of a message is joined to its first line."""
    import gameverify as gv
    import match
    path = os.path.join(ROOT, rel)
    raw = open(path, encoding="latin1").read()
    h, st = gv.settings_of(raw)
    flags = st["flags"].split() if st["flags"] else ["-O4,p"]
    langs = [st["lang"] or None]       # the mode the file's header names, as gameverify judges it
    ok = True
    errs = []
    for lang in langs:
        try:
            r, _tl = match.run_tu(path, int(h["address"], 16), st["compiler"], flags, st["isa"] == "thumb",
                                  lang, region=(h.get("region") or "").strip() or None)
        except (Exception, SystemExit) as e:
            return False, [(0, "ERROR %r" % (e,))]
        if not r.status.startswith(("EXACT", "MATCH") if lenient else ("EXACT",)):
            ok = False
        last = None
        for l in (r.log or "").splitlines():
            m = re.search(r"\.c:(\d+):\s*(.*)", l)
            if m:
                ln, tx = int(m.group(1)), m.group(2).strip()
                if tx.startswith("warning"):
                    continue
                if last is not None and last[0] == ln and not tx.startswith(("illegal", "function", "undefined",
                                                                              "identifier", "expression")):
                    last[1] += " " + tx
                else:
                    last = [ln, tx]
                    errs.append(last)
    seen = []
    for ln, tx in errs:
        if (ln, tx) not in seen:
            seen.append((ln, tx))
    return ok, seen


def verify_file(rel, allow_match=0):
    import subprocess
    r = subprocess.run([sys.executable, os.path.join(HERE, "gameverify.py"), "--file", rel],
                       cwd=ROOT, capture_output=True, text=True)
    out = r.stdout + r.stderr
    last = [l for l in out.splitlines() if l.startswith("files:")]
    if not last:
        return False
    m = re.search(r"MATCH \(relocations wildcarded\): (\d+)", last[-1])
    return "not exact: 0," in last[-1] and m is not None and int(m.group(1)) <= allow_match


def baseline_match(rel):
    """1 if the file is MATCH (relocations wildcarded) before any edit, else 0."""
    import subprocess
    r = subprocess.run([sys.executable, os.path.join(HERE, "gameverify.py"), "--file", rel],
                       cwd=ROOT, capture_output=True, text=True)
    last = [l for l in (r.stdout + r.stderr).splitlines() if l.startswith("files:")]
    m = re.search(r"MATCH \(relocations wildcarded\): (\d+)", last[-1]) if last else None
    return int(m.group(1)) if m else 0


# ---- cast repair: an argument or result whose pointer/integer type differs from the new prototype

CONV = re.compile(r"illegal implicit conversion from '([^']*)' to '([^']*)'")


def err_type_canon(types, text):
    """Canonical type of a type spelled in an mwcc message, or None."""
    t = text.strip()
    if "(" in t and t.endswith(")") and not t.startswith(("struct", "union")):
        return "@fnptr"          # a function or function pointer type: one kind, as in canon()
    if "(" in t or t == "void":
        return None
    t = re.sub(r"\[[^\]]*\]", " *", t)
    toks = re.findall(r"[A-Za-z_]\w*|\*", t)
    toks = [x for x in toks if x not in KW]
    if not toks:
        return None
    return types.canon(toks)


def call_spans(text, name, lo, hi):
    """(name_start, open_paren, close_paren) of calls to `name` whose text overlaps [lo, hi)."""
    out = []
    for m in re.finditer(r"\b%s\s*\(" % re.escape(name), text):
        if m.end() < lo - 4000 or m.start() > hi:
            continue
        i = m.end()
        depth = 1
        while i < len(text) and depth:
            c = text[i]
            if c == "(":
                depth += 1
            elif c == ")":
                depth -= 1
            elif c in ";{}" and depth == 1:
                break
            i += 1
        if depth:
            continue
        close = i - 1
        if close >= lo and m.start() < hi:
            out.append((m.start(), m.end() - 1, close))
    return out


def split_args(text, op, cl):
    """[(start, end)] of each top-level argument between the parens at op and cl."""
    args = []
    depth = 0
    start = op + 1
    for i in range(op + 1, cl):
        c = text[i]
        if c in "([{":
            depth += 1
        elif c in ")]}":
            depth -= 1
        elif c == "," and depth == 0:
            args.append((start, i))
            start = i + 1
    if text[start:cl].strip():
        args.append((start, cl))
    return args


CASTPFX = re.compile(r"^(\s*)\(\s*((?:(?:struct|union|unsigned|signed|const|volatile|void|char|short|int|long|float|double|u8|u16|u32|u64|s8|s16|s32|s64|BOOL|[A-Z]\w*)\s*)+(?:\*\s*)*)\)\s*(?=[\w(&*~!-])")


def derive_casts(types, cur, errs, edits_by_name, tried):
    """Cast edits (start, end, text) on `cur`, one set per round, from conversion errors."""
    starts = [0]
    for i, ch in enumerate(cur):
        if ch == "\n":
            starts.append(i + 1)
    out = []
    unresolved = []
    for ln, tx in errs:
        m = CONV.search(tx)
        if not m or ln <= 0 or ln > len(starts):
            unresolved.append((ln, tx))
            continue
        a_t, b_t = m.group(1), m.group(2)
        a_c, b_c = err_type_canon(types, a_t), err_type_canon(types, b_t)
        if a_c is None or b_c is None:
            unresolved.append((ln, tx))
            continue
        lo = starts[ln - 1]
        hi = starts[ln] if ln < len(starts) else len(cur)
        done = False
        for name, e in edits_by_name.items():
            for (ns, op, cl) in call_spans(cur, name, lo, hi):
                args = split_args(cur, op, cl)
                cands = []
                for j, pc in enumerate(e["params"]):
                    if j < len(args) and pc == b_c:
                        cands.append(("arg", j))
                # the call's own result converted to the type B (only after the arguments)
                if e["ret"] == a_c and e["ret"] != "void":
                    cands.append(("ret", None))
                for kind, j in cands:
                    key = (ns if kind == "ret" else args[j][0], kind, b_c)
                    # offsets move, so the key is by the call's name and ordinal on the line
                    key = (name, ln, kind, j, b_c, cur[ns:cl + 1])
                    if key in tried:
                        continue
                    tried.add(key)
                    ctext = canon_text(types, b_c, "", e.get("vis"))
                    if ctext is None:
                        continue
                    if kind == "ret":
                        out.append((ns, ns, "(%s)" % ctext))
                    else:
                        s, en = args[j]
                        body = cur[s:en]
                        cm = CASTPFX.match(body)
                        if cm:
                            intcast = cm.group(2).strip() in ("u32", "s32", "int", "unsigned int", "unsigned", "BOOL")
                            # a pointer that was cast to an integer for an integer parameter: the
                            # parameter is a pointer now, so the cast goes away
                            ptrcast = cm.group(2).strip().endswith("*")
                            # an integer that was cast to a pointer for a pointer parameter that is an integer now
                            out.append((s + len(cm.group(1)), s + cm.end(),
                                        "" if ((intcast and b_c.endswith("*")) or (ptrcast and not b_c.endswith("*") and int_kind(b_c))) else "(%s)" % ctext))
                        else:
                            lead = len(body) - len(body.lstrip())
                            trail = len(body.rstrip())
                            inner = body[lead:trail]
                            if re.match(r"^[\w.\[\]>-]+$", inner):
                                out.append((s + lead, s + lead, "(%s)" % ctext))
                            else:
                                out.append((s + lead, s + lead, "(%s)(" % ctext))
                                out.append((s + trail, s + trail, ")"))
                    done = True
                    break
                if done:
                    break
            if done:
                break
        if not done:
            unresolved.append((ln, tx))
    return out, unresolved


def implicated(cur, errs, names):
    """Names of edits whose callee is spelled on the statement of an error line."""
    lines = cur.split("\n")
    hit = set()
    for ln, tx in errs:
        if not (0 < ln <= len(lines)):
            continue
        seg = " ".join(lines[max(0, ln - 3):ln + 1])
        for n in names:
            if re.search(r"\b%s\b" % re.escape(n), seg) or n in tx:
                hit.add(n)
    return hit


import threading
import time
_tl = threading.local()
PRECAST = [None]   # optional hook: (rel, text, names) -> text with casts added before the repair rounds
LIMIT = [900]
BACKUP = [None]


def pipeline(rel, path, text, crlf, code, semis, types, sel, msgs, lenient=False, max_rounds=14):
    """Apply the selected declaration edits, repair conversions with casts until the file compiles.
    Returns (ok, dropped names).  The file on disk holds the last attempt."""
    cur = splice(text, apply_edits(code, sel, semis, types))
    if PRECAST[0]:
        cur = PRECAST[0](rel, cur, [e["name"] for e in sel])
    by_name = {e["name"]: e for e in sel}
    tried = set()
    dropped = set()
    pend = None
    def_tags = {t for e in sel for t, _p in e.get("tags", [])}
    pend_cur_guard = None
    bad_renames = set()
    max_rounds += 8
    for rnd in range(max_rounds):
        if time.time() > getattr(_tl, "deadline", 1e18):
            raise TimeoutError("time limit")
        open(path, "w", encoding="latin1", newline="").write(cur.replace("\n", "\r\n") if crlf else cur)
        ok, errs = compile_errors(rel, lenient)
        if ok:
            return True, dropped
        if not errs:
            return False, dropped        # bytes differ without a diagnostic
        if pend is not None:
            if len(errs) > pend[2]:
                cur = pend[0]            # the rename made it worse: take it back, cast instead
                bad_renames |= pend[1]
            pend = None
            if cur == pend_cur_guard:
                pass
        ren = []
        for ln_, tx_ in errs:
            m_ = CONV.search(tx_)
            if m_:
                a_c, b_c = err_type_canon(types, m_.group(1)), err_type_canon(types, m_.group(2))
                if (a_c and b_c and a_c != b_c and a_c.startswith(("struct ", "union ")) and b_c.startswith(("struct ", "union "))
                        and a_c.count("*") == b_c.count("*") and a_c.split()[0] == b_c.split()[0]):
                    pair = (a_c.rstrip("*"), b_c.rstrip("*"))
                    if pair[0] in def_tags and pair[1] not in def_tags:
                        pair = (pair[1], pair[0])        # the caller adopts the definition's tag
                    if pair not in bad_renames and pair not in ren and pair[1] not in types.anon:
                        ren.append(pair)
        ren = [(a_, b_) for a_, b_ in ren if not re.search(r"\b%s\s*\{" % re.escape(b_), cur)]
        if ren:
            snap = cur
            for a_, b_ in ren:
                kind_a, tag_a = a_.split()
                kind_b, tag_b = b_.split()
                cur = re.sub(r"\b%s\s+%s\b" % (kind_a, re.escape(tag_a)), "%s %s" % (kind_b, tag_b), cur)
            pend = (snap, set(ren), len(errs))
            continue
        casts, unresolved = derive_casts(types, cur, errs, by_name, tried)
        if not casts:
            lines_ = cur.split(chr(10))
            for ln_, tx_ in (unresolved or errs)[:4]:
                msgs.append(("UNRES", str(ln_), tx_[:150] + " >> " + (lines_[ln_ - 1].strip()[:120] if 0 < ln_ <= len(lines_) else "")))
            hit = implicated(cur, unresolved or errs, list(by_name))
            return False, hit
        cur = splice(cur, casts)
    return False, set(by_name)


def fix_one(args):
    try:
        return fix_one_inner(args)
    except Exception as e:
        return args[0], 0, len(args[1]), [("ERROR", repr(e)[:150], "")]


def fix_one_inner(args):
    rel, items, types, mode, log = args
    path = os.path.join(ROOT, rel)
    orig = open(path, encoding="latin1", newline="").read()
    _tl.deadline = time.time() + LIMIT[0]
    if BACKUP[0] and mode is not True:
        bp = os.path.join(BACKUP[0], rel)
        os.makedirs(os.path.dirname(bp), exist_ok=True)
        open(bp, "w", encoding="latin1", newline="").write(orig)
    crlf = "\r\n" in orig
    text = orig.replace("\r\n", "\n")
    code = clean(path)
    depths = []
    depth = 0
    for ch in code:
        if ch == "{":
            depth += 1
        elif ch == "}":
            depth = max(0, depth - 1)
        depths.append(depth)
    edits, skipped, semis = build_edits(types, code, depths, items, visible_typedefs(path))
    msgs = [("SKIP", n, why) for n, why in skipped]
    if not edits:
        return rel, 0, len(items), msgs
    if mode is True:
        for e in edits:
            msgs.append(("DRY", e["name"], repr(e["local"])))
        return rel, 0, len(items), msgs
    try:
        bm = baseline_match(rel) if mode != "diag" else 1
        sel = list(edits)
        if mode == "diag":
            cur = splice(text, apply_edits(code, sel, semis, types))
            open(path, "w", encoding="latin1", newline="").write(cur.replace("\n", "\r\n") if crlf else cur)
            ok, errs = compile_errors(rel)
            lines = cur.split("\n")
            for ln, msg in errs[:30]:
                msgs.append(("ERR", str(ln), msg[:200] + "   >> " + (lines[ln - 1].strip()[:140] if 0 < ln <= len(lines) else "")))
            open(path, "w", encoding="latin1", newline="").write(orig)
            return rel, 0, len(items), msgs
        # drop implicated edits, retry; bisect when the failure has no diagnostic
        good = None
        rounds = 0
        while sel and rounds < 8:
            rounds += 1
            ok, hit = pipeline(rel, path, text, crlf, code, semis, types, sel, msgs, bm)
            if ok:
                good = sel
                break
            if hit:
                for e in sel:
                    if e["name"] in hit:
                        msgs.append(("REJECT", e["name"], "conversion not repairable"))
                sel = [e for e in sel if e["name"] not in hit]
            else:
                break
        if good is None and sel:
            # no diagnostic: bisect over the declaration edits
            def solve(part):
                if not part:
                    return []
                ok, _h = pipeline(rel, path, text, crlf, code, semis, types, part, msgs, bm)
                if ok:
                    return part
                if len(part) == 1:
                    msgs.append(("REJECT", part[0]["name"], "not exact"))
                    return []
                mid = len(part) // 2
                return solve(part[:mid]) + solve(part[mid:])
            good = solve(sel)
            if good:
                ok, _h = pipeline(rel, path, text, crlf, code, semis, types, good, msgs, bm)
                if not ok:
                    good = None
        if good:
            if not verify_file(rel, bm):
                good = None
        if not good:
            open(path, "w", encoding="latin1", newline="").write(orig)
            return rel, 0, len(items), msgs
    except BaseException:
        open(path, "w", encoding="latin1", newline="").write(orig)
        raise
    for k in good:
        msgs.append(("KEEP", k["name"], ""))
    return rel, len(good), len(items) - len(good), msgs


def run_fix(a, types, detail):
    import concurrent.futures as cf
    allowed = None
    if a.files:
        allowed = {l.strip() for l in open(a.files) if l.strip()}
    byfile = {}
    for item in detail:
        rel = os.path.relpath(item[0], ROOT).replace(os.sep, "/")
        if not rel.endswith(".c"):
            continue
        if allowed is not None and rel not in allowed:
            continue
        byfile.setdefault(rel, []).append(item)
    jobs = [(rel, its, types, "diag" if a.diag else a.dry, a.log) for rel, its in sorted(byfile.items())]
    kept_total = left_total = 0
    logf = open(a.log, "a") if a.log else None
    with cf.ThreadPoolExecutor(a.jobs) as ex:
        for rel, kept, left, msgs in ex.map(fix_one, jobs):
            kept_total += kept
            left_total += left
            line = "%s kept=%d left=%d" % (rel, kept, left)
            print(line, flush=True)
            if logf:
                logf.write(line + "\n")
                for m in msgs:
                    logf.write("  %s %s %s\n" % m)
                logf.flush()
    print("files: %d, declarations kept: %d, not changed: %d" % (len(jobs), kept_total, left_total))
    return 0


# ---------------------------------------------------------------- audit: pointers passed through integer parameters

INTCAST = re.compile(r"^(\s*)\(\s*(?:u32|s32|int|unsigned int|unsigned|BOOL)\s*\)\s*")
IDENTCALL = re.compile(r"\b([A-Za-z_]\w*)\s*\(")


def audit_one(args):
    """Pointers that reach an integer (32 bit) parameter of a prototype through an explicit cast.

    The casts of the arguments listed here are removed in a scratch compile; a conversion error
    'from <pointer> to <integer>' shows the argument is a pointer.  The file is restored."""
    rel, intdefs, types = args
    path = os.path.join(ROOT, rel)
    orig = open(path, encoding="latin1", newline="").read()
    text = orig.replace("\r\n", "\n")
    crlf = "\r\n" in orig
    code = clean(path)
    edits = []        # (start, end, callee, j, line)
    starts = [0]
    for i, ch in enumerate(text):
        if ch == "\n":
            starts.append(i + 1)
    for m in IDENTCALL.finditer(code):
        name = m.group(1)
        params = intdefs.get(name)
        if not params:
            continue
        pre = code[max(0, m.start() - 12):m.start()].rstrip()
        if not pre or not (pre[-1] in "(,=;{}!&|+-?:<>/%^~" or re.search(r"\b(?:return|else|case)$", pre)):
            continue          # a declaration or definition, not a call
        op = m.end() - 1
        depth = 1
        i = m.end()
        while i < len(code) and depth:
            c = code[i]
            if c == "(":
                depth += 1
            elif c == ")":
                depth -= 1
            elif c in ";{}" and depth == 1:
                break
            i += 1
        if depth:
            continue
        cl = i - 1
        argl = split_args(code, op, cl)
        for j, pc in enumerate(params):
            if pc in ("u32", "s32") and j < len(argl):
                s0, e0 = argl[j]
                cm = INTCAST.match(code[s0:e0])
                if cm:
                    ln = bisect.bisect_right(starts, s0 + cm.start(0))
                    edits.append((s0 + len(cm.group(1)), s0 + cm.end(), name, j, ln))
    if not edits:
        return rel, [], 0
    try:
        new = splice(text, [(s, e, "") for s, e, _n, _j, _l in edits])
        open(path, "w", encoding="latin1", newline="").write(new.replace("\n", "\r\n") if crlf else new)
        ok, errs = compile_errors(rel, True)
    finally:
        open(path, "w", encoding="latin1", newline="").write(orig)
    # line numbers shift when nothing is removed across lines: removals never add or drop newlines
    per_line = {}
    for s, e, n, j, ln in edits:
        per_line.setdefault(ln, []).append((n, j))
    found = []
    for ln, tx in errs:
        m = CONV.search(tx)
        if not m or ln not in per_line or len(per_line[ln]) != 1:
            continue
        a_c = err_type_canon(types, m.group(1))
        b_c = err_type_canon(types, m.group(2))
        if a_c and a_c.endswith("*") and b_c in ("u32", "s32"):
            n, j = per_line[ln][0]
            found.append((n, j, a_c, ln))
    return rel, found, len(edits)


def run_audit(a, types, defs):
    import concurrent.futures as cf
    intdefs = {}
    for name, lst in defs.items():
        sigs = {tuple(d[3] or ()) for d in lst}
        if len(sigs) == 1:
            ps = list(sigs)[0]
            if any(p in ("u32", "s32") for p in ps):
                intdefs[name] = list(ps)
    allowed = {l.strip() for l in open(a.files)} if a.files else None
    jobs = []
    for f in sorted(ph.files_under([GAME])):
        rel = os.path.relpath(f, ROOT).replace(os.sep, "/")
        if rel.endswith(".c") and (allowed is None or rel in allowed):
            jobs.append((rel, intdefs, types))
    out = open(a.log, "w") if a.log else sys.stdout
    with cf.ThreadPoolExecutor(a.jobs) as ex:
        for rel, found, n in ex.map(audit_one, jobs):
            for nm, j, pt, ln in found:
                out.write("%s\t%d\t%s\t%d\t%s\n" % (rel, ln, nm, j, pt))
            out.flush()
    return 0


# ---------------------------------------------------------------- pointer parameters declared as integers

# optional lane-claim helper (multi-lane runs only): path in ALETHEIA_CLAIMS
CLAIMS = os.environ.get("ALETHEIA_CLAIMS", "")


def claim(rel):
    import subprocess
    if not CLAIMS:
        return True
    r = subprocess.run([sys.executable, CLAIMS, "claim", "PROTO1", rel], capture_output=True, text=True)
    return "claimed" in r.stdout


def run_ptrparams(a, types, defs):
    """Change the parameters that the audit shows to be pointers (audit TSV in --files) from u32/s32 to
    the pointer type in the definition and its prototypes; keep a change only when the definition's file stays exact."""
    groups = {}
    for l in open(a.files):
        f = l.rstrip("\n").split("\t")
        if len(f) < 5:
            continue
        groups.setdefault((f[2], int(f[3])), []).append(f[4])
    done = []
    callers = set()
    for (name, j), pts in sorted(groups.items()):
        cands = defs.get(name, [])
        if len(cands) != 1:
            print("SKIP %s %d: %d definitions" % (name, j, len(cands)))
            continue
        reg, dfile, dret, dparams = cands[0]
        if len(dparams or []) <= j or dparams[j] not in ("u32", "s32"):
            continue
        ptype = pts[0] if len(set(pts)) == 1 else "void*"
        rel = os.path.relpath(dfile, ROOT).replace(os.sep, "/")
        if not claim(rel):
            print("REFUSED %s (definition file of %s)" % (rel, name))
            continue
        recs, code, depths = scan(dfile, types)
        raw = open(dfile, encoding="latin1", newline="").read()
        crlf = "\r\n" in raw
        text = raw.replace("\r\n", "\n")
        vis = visible_typedefs(dfile)
        ptext_new = canon_text(types, ptype, code, vis)
        if ptext_new is None:
            print("SKIP %s %d: type %s not writable" % (name, j, ptype))
            continue
        local = []
        pos = None
        for (n2, ret, params, line, is_def, static, ex) in recs:
            if n2 != name or static or "asm" in ex["pre_toks"]:
                continue
            pl = pn.split_params(ex["ptext"])
            if len(pl) <= j:
                continue
            pnm = pn.param_name(pl[j])
            pl[j] = join_name(ptext_new, " ".join(pnm[0:1]) if pnm else "")
            local.append((ex["par_start"], ex["par_end"], ",".join(pl) if False else ", ".join(x.strip() for x in pl)))
            pos = pos if pos is not None else ex["name_start"]
        if not local:
            continue
        semis = [i for i, ch in enumerate(code) if ch == ";" and depths[i] == 0]
        tags = []
        b = ptext_new.rstrip("* ")
        if b.startswith(("struct ", "union ")):
            tags.append((b, pos))
        edit = dict(name=name, local=local, tags=tags, pos=pos)
        new = splice(text, apply_edits(code, [edit], semis, types))
        bm = baseline_match(rel)
        open(dfile, "w", encoding="latin1", newline="").write(new.replace("\n", "\r\n") if crlf else new)
        if verify_file(rel, bm):
            print("DONE %s param %d -> %s" % (name, j, ptext_new))
            done.append((name, j, ptext_new))
        else:
            open(dfile, "w", encoding="latin1", newline="").write(raw)
            print("FAILED %s param %d -> %s (definition file not exact)" % (name, j, ptext_new))
    print("definitions changed: %d" % len(done))
    return 0


def run_repair(a, types, defs):
    """Casts until the listed files compile exact again (a file left in a half edited state)."""
    for rel in [l.strip() for l in open(a.files) if l.strip()]:
        path = os.path.join(ROOT, rel)
        orig = open(path, encoding="latin1", newline="").read()
        crlf = chr(13) in orig
        cur = orig.replace(chr(13) + chr(10), chr(10))
        vis = visible_typedefs(path)
        recs, _c, _d = scan(path, types)
        by_name = {}
        for (name, ret, params, line, is_def, static, ex) in recs:
            cands = defs.get(name, [])
            if len(cands) == 1 and not is_def:
                d = cands[0]
                by_name[name] = dict(name=name, ret=d[2], params=d[3] or [], vis=vis)
        bm = baseline_match(rel)
        tried = set()
        ok = False
        for rnd in range(14):
            ok, errs = compile_errors(rel, bm == 1)
            if ok or not errs:
                break
            casts, unres = derive_casts(types, cur, errs, by_name, tried)
            if not casts:
                print("%s: unresolved %s" % (rel, errs[:3]))
                break
            cur = splice(cur, casts)
            open(path, "w", encoding="latin1", newline="").write(cur.replace(chr(10), chr(13) + chr(10)) if crlf else cur)
        print("%s: %s" % (rel, "exact" if ok else "NOT exact"))
    return 0


def defs_by_name(defs):
    return {n: [(d[0], d[1], d[2], d[3]) for d in lst] for n, lst in defs.items()}


def main():
    ap = argparse.ArgumentParser(description=__doc__.splitlines()[0])
    ap.add_argument("--tsv", action="store_true")
    ap.add_argument("--summary", action="store_true")
    ap.add_argument("--ds", action="store_true", help="read the DS branch of __MWERKS__ guards (default: the host branch)")
    ap.add_argument("--fix", action="store_true", help="rewrite mismatching declarations, keep what verifies")
    ap.add_argument("--files", help="with --fix: file with one repo-relative path per line (only these are edited)")
    ap.add_argument("--jobs", type=int, default=4)
    ap.add_argument("--limit", type=int, default=900, help="with --fix: seconds per file before it is given up and restored")
    ap.add_argument("--backup", help="with --fix: directory that receives each file's text before the first edit")
    ap.add_argument("--dry", action="store_true", help="with --fix: print the edits, write nothing")
    ap.add_argument("--diag", action="store_true", help="with --fix: apply all edits, print the compile errors, restore")
    ap.add_argument("--log", help="with --fix: append one line per kept/rejected declaration")
    ap.add_argument("--ptrparams", action="store_true", help="--files is an audit TSV: fix definitions whose integer parameter is a pointer")
    ap.add_argument("--repair", action="store_true", help="--files: casts until the files compile exact again")
    ap.add_argument("--audit", action="store_true", help="list pointers passed through integer parameters by a cast")
    a = ap.parse_args()
    LIMIT[0] = a.limit
    DS_BUILD[0] = a.ds
    BACKUP[0] = a.backup
    files = sorted(ph.files_under([GAME]))
    types = Types(files)
    asm_defs = set()
    defs = {}      # name -> list of (region, file, ret, params, line)
    decls = []     # (file, name, ret, params, line)
    for f in files:
        recs, _code, _depths = scan(f, types)
        for name, ret, params, line, is_def, static, extra in recs:
            if static:
                continue
            if is_def:
                if "asm" in extra["pre_toks"]:
                    asm_defs.add(name)
                    continue
                defs.setdefault(name, []).append((region_of(f), f, ret, params, line, extra))
            else:
                decls.append((f, name, ret, params, line, extra))
    rows = []
    detail = []
    skipped = 0
    for f, name, ret, params, line, dextra in decls:
        reg = region_of(f)
        cands = [d for d in defs.get(name, []) if d[0] == reg]
        if not cands:
            cands = [d for d in defs.get(name, []) if d[0] == "arm9"]
        if not cands:
            cands = defs.get(name, [])
        if not cands:
            continue
        sigs = {(d[2], tuple(d[3] or ())) for d in cands}
        if len(sigs) != 1:
            skipped += 1
            continue
        d = cands[0]
        if d[1] == f:
            continue
        if (os.path.relpath(f, ROOT).replace(os.sep, "/"), name) in EXCEPTIONS and not os.environ.get("NOEXC"):
            continue
        kinds = compare(d[2], d[3] or [], ret, params)
        if kinds:
            detail.append((f, name, ret, params, line, d, kinds, dextra))
            rows.append((os.path.relpath(f, ROOT).replace(os.sep, "/"), line, name, ",".join(sorted(set(kinds))),
                         sig_text(ret, params), sig_text(d[2], d[3]),
                         os.path.relpath(d[1], ROOT).replace(os.sep, "/")))
    if a.repair:
        return run_repair(a, types, defs_by_name(defs))
    if a.ptrparams:
        return run_ptrparams(a, types, defs_by_name(defs))
    if a.audit:
        return run_audit(a, types, defs_by_name(defs))
    if a.fix:
        return run_fix(a, types, detail)
    if a.tsv:
        for r in rows:
            print("\t".join(str(x) for x in r))
        return 1 if rows else 0
    counts = {}
    for r in rows:
        for k in r[3].split(","):
            counts[k] = counts.get(k, 0) + 1
    if not a.summary:
        for r in rows:
            print("%s:%d  %s  [%s]\n    declared %s\n    defined  %s  (%s)" % r)
    print("declarations checked: %d, definitions: %d, ambiguous names skipped: %d" % (len(decls), len(defs), skipped))
    print("mismatches: %d  %s" % (len(rows), " ".join("%s=%d" % kv for kv in sorted(counts.items()))))
    return 1 if rows else 0


if __name__ == "__main__":
    sys.exit(main())
