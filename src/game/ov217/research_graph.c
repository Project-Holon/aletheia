/*
 * file:     research_graph.c
 * unit:     yes
 * function: func_021BD5F4, func_021BD61C, func_021BD62C, func_021BD708, func_021BD710, func_021BD718, func_021BD868, func_021BD89C, func_021BDC18, func_021BDF58, func_021BE040, func_021BE094, func_021BE0D0, func_021BE108, func_021BE21C, func_021BE33C, func_021BE36C, func_021BE384, func_021BE448, func_021BE454, func_021BE460, func_021BE468, func_021BE46C, func_021BE490, func_021BE498, func_021BE4A4, func_021BE4CC, func_021BE4DC, func_021BE4E0, func_021BE4E8, func_021BE580, func_021BE614, func_021BE630, func_021BE678, func_021BE704, func_021BE790, func_021BE7B4, func_021BE7D8, func_021BE7F0, func_021BE808, func_021BE8FC, func_021BE90C, func_021BE91C, func_021BE930, func_021BE934, func_021BE9B8, func_021BEA3C, func_021BEA54, func_021BEA8C, func_021BEAEC, func_021BEAF8, func_021BEB40, func_021BEB6C, func_021BEB88, func_021BEBA4, func_021BEBC0, func_021BEBE4, func_021BEC00, func_021BEC0C, func_021BEC34, func_021BEC64, func_021BEC84, func_021BED10, func_021BED9C, func_021BEDC4, func_021BEDEC, func_021BEEA4, func_021BEF30, func_021BEF98, func_021BEFC0, func_021BEFD4, func_021BEFF8, func_021BF08C, func_021BF100, func_021BF11C, func_021BF13C, func_021BF15C, func_021BF264, func_021BF2FC, func_021BF38C, func_021BF3B4, func_021BF3D8, func_021BF47C, func_021BF4AC, func_021BF55C, func_021BF568, func_021BF574, func_021BF580, func_021BF594, func_021BF5BC, func_021BF5D0, func_021BF5E4, func_021BF600, func_021BF60C, func_021BF658, func_021BF6A4, func_021BF6BC, func_021BF6D4, func_021BF704, func_021BF710, func_021BF728, func_021BF734, func_021BF740, func_021BF74C, func_021BF750, func_021BF754, func_021BF758, func_021BF764, func_021BF76C, func_021BF77C, func_021BF78C, func_021BF7CC, func_021BF7E0, func_021BF7F4, func_021BF810, func_021BF834, func_021BF844, func_021BF854, func_021BF878, func_021BF894, func_021BF8B0, func_021BF910, func_021BF968, func_021BF9CC, func_021BF9F0, func_021BF9FC, func_021BFA08, func_021BFA14, func_021BFA30, func_021BFB04, func_021BFB0C, func_021BFB14, func_021BFB24, func_021BFB30, func_021BFB38, func_021BFB54, func_021BFB60, func_021BFB74, func_021BFBA0, func_021BFBB8, func_021BFBC0, func_021BFBD0, func_021BFBDC, func_021BFBFC, func_021BFC28, func_021BFC50, func_021BFC60, func_021BFE40, func_021BFE80, func_021BFE8C, func_021BFED4, func_021BFEE4, func_021BFF00, func_021BFF5C, func_021BFF78, func_021BFFC8, func_021C0084, func_021C00AC, func_021C00F8, func_021C00FC, func_021C0114, func_021C0124, func_021C0170, func_021C0174, func_021C018C, func_021C019C, func_021C01B8, func_021C0230, func_021C0250, func_021C02A8, func_021C02C8, func_021C0358, func_021C0384, func_021C03A0, func_021C03D0, func_021C03EC, func_021C0408, func_021C0494, func_021C04B0, func_021C04CC, func_021C04FC, func_021C05B0, func_021C06AC, func_021C06C8, func_021C06E0, func_021C06F0, func_021C0794, func_021C07B0, func_021C07BC, func_021C0800, func_021C0820, func_021C083C, func_021C085C, func_021C0878, func_021C08A8, func_021C08C4, func_021C08D4, func_021C08F0, func_021C0900, func_021C0918, func_021C093C, func_021C0968
 * address:  0x021BD5F4
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from research_top.c, unit_021BFFC8.c, queue.c, palette_anime.c, ov217_func_021C2E20.c by tools/splitfile.py.
 *
 * symbols:
 *   GAMESYSTEM_TryStartAutoComm  0x020121CC  thumb
 *   func_0203FC28  0x0203FC28  arm
 *   func_0203FCA0  0x0203FCA0  arm
 *   func_020490F4 0x020490F4 arm
 *   ARC_TOOL_LoadHandleMember 0x02049250 arm
 *   func_020307B0 0x020307B0 arm
 *   func_02062B30 0x02062B30 arm
 *   func_02041090 0x02041090 arm
 *   func_020409B4 0x020409B4 arm
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   RESEARCH_COMMON_GetHeapId  0x021C09AC  thumb  ov217
 *   RESEARCH_COMMON_UpdatePaletteAnime 0x021C09D0 thumb ov217
 *   CLACT_DrawSystem 0x0204A600 arm
 *   KEY_GetTrg 0x020362DC arm
 *   TOUCHPANEL_HitTrg 0x02035C08 arm
 *   RESEARCH_COMMON_GetTouchRects 0x021C09B8 thumb ov217
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   RESEARCH_COMMON_StopPaletteAnime  0x021C09E0  thumb  ov217
 *   RESEARCH_COMMON_RestorePaletteAnime  0x021C09EC  thumb  ov217
 *   RingQueue_Push  0x021C0E4C  thumb  ov217
 *   RingQueue_Pop  0x021C0E54  thumb  ov217
 *   RingQueue_IsEmpty  0x021C0E64  thumb  ov217
 *   RESEARCH_COMMON_GetPreviousScreen  0x021C09C8  thumb  ov217
 *   RESEARCH_COMMON_GetEntryHandled  0x021C09CC  thumb  ov217
 *   RESEARCH_COMMON_SetEntryHandled  0x021C09C4  thumb  ov217
 *   GAME_BEACON_PopQuestionnaireUpdated  0x020270E0  thumb
 *   RESEARCH_COMMON_StartPaletteAnime  0x021C09D8  thumb  ov217
 *   PALETTE_ANIME_Start  0x021C29F8  thumb  ov217
 *   PALETTE_ANIME_Stop  0x021C2A00  thumb  ov217
 *   PALETTE_ANIME_Update  0x021C29F0  thumb  ov217
 *   RESEARCH_COMMON_GetAppResource 0x021C09B4 thumb ov217
 *   RESEARCH_COMMON_GetInputFlag  0x021C09F8  thumb  ov217
 *   GF_FONT_Delete  0x0201D83C  thumb
 *   MSGDATA_Delete  0x02045C04  arm
 *   RingQueue_Create  0x021C0E08  thumb  ov217
 *   RingQueue_Destroy  0x021C0E3C  thumb  ov217
 *   func_0207D63C 0x0207D63C arm
 *   BMP_WIN_Init 0x02045088 arm
 *   func_02040DA8  0x02040DA8  arm
 *   BgTextLabel_Create 0x021C0EF4 thumb ov217
 *   BgTextLabel_PrintMessage 0x021C0F5C thumb ov217
 *   BgTextLabel_Destroy  0x021C0F48  thumb  ov217
 *   CLACT_RegisterCharacter 0x0204A6C8 arm
 *   CLACT_RegisterPalette 0x0204ABF0 arm
 *   CLACT_RegisterCellAnim 0x0204AF28 arm
 *   CLACT_RegisterPaletteEx 0x0204AC18 arm
 *   CLACT_DeleteUnit  0x0204B1CC  arm
 *   CLACT_CreateActor 0x0204B294 arm
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   CLACT_DeleteActor  0x0204B3B4  arm
 *   PALETTE_ANIME_Create  0x021C29C8  thumb  ov217
 *   PALETTE_ANIME_Destroy  0x021C29D8  thumb  ov217
 *   PALETTE_ANIME_Bind  0x021C29E8  thumb  ov217
 *   PALETTE_ANIME_Restore  0x021C2A08  thumb  ov217
 *   CLACT_VBlankSystem  0x0204A648  arm
 *   KEY_GetCont 0x0203630C arm
 *   GAME_DATA_GetSaveControl 0x02012EBC thumb
 *   func_0200E394 0x0200E394 thumb
 *   func_0200E44C 0x0200E44C thumb
 *   BMP_OAM_SetPalette  0x02025A54  thumb
 *   func_020413B0 0x020413B0 arm
 *   CLACT_AddActorSurfacePos 0x0204B404 arm
 *   CLACT_SetActorAutoAnim 0x0204B92C arm
 *   BgTextLabel_SetVisible  0x021C0FF8  thumb  ov217
 *   func_0209C0A4  0x0209C0A4  arm
 *   PALANM_GetFadeRequestBits  0x02021ED8  thumb
 *   PALETTE_ANIME_IsRunning  0x021C2A10  thumb  ov217
 *   BMP_OAM_SetEnabled  0x02025774  thumb
 *   func_02045B38 0x02045B38 arm
 *   CLACT_CreateUnit 0x0204B100 arm
 *   BMP_Create 0x02043678 arm
 *   BMP_CreateFromArchive 0x0204384C arm
 *   BMP_Blit 0x020439A0 arm
 *   func_02045EC0 0x02045EC0 arm
 *   BMP_Delete 0x020437AC arm
 *   PRINTSYS_PrintColor 0x0201C7D0 thumb
 *   BMP_OAM_CreateSys  0x02025538  thumb
 *   BMP_OAM_DeleteSys  0x02025588  thumb
 *   BMP_OAM_Create  0x020255A0  thumb
 *   BMP_OAM_UploadChars  0x020257D0  thumb
 *   BMP_OAM_Delete  0x0202570C  thumb
 *   PALANM_Delete  0x02021540  thumb
 *   func_020056A0  0x020056A0  thumb
 *   ARROW_Update  0x021C20C4  thumb  ov217
 *   func_021BFFC8  0x021BFFC8  thumb  ov217
 *   func_021C00AC  0x021C00AC  thumb  ov217
 *   func_021C00FC  0x021C00FC  thumb  ov217
 *   func_021C0124  0x021C0124  thumb  ov217
 *   func_021C0174  0x021C0174  thumb  ov217
 *   func_021C01B8  0x021C01B8  thumb  ov217
 *   func_021C0250  0x021C0250  thumb  ov217
 *   func_021C02C8  0x021C02C8  thumb  ov217
 *   func_021C03A0  0x021C03A0  thumb  ov217
 *   func_021C0408  0x021C0408  thumb  ov217
 *   func_021C04CC  0x021C04CC  thumb  ov217
 *   func_021C04FC  0x021C04FC  thumb  ov217
 *   func_021C05B0  0x021C05B0  thumb  ov217
 *   func_021C06C8  0x021C06C8  thumb  ov217
 *   func_021C06F0  0x021C06F0  thumb  ov217
 *   func_021C07BC  0x021C07BC  thumb  ov217
 *   func_021C083C  0x021C083C  thumb  ov217
 *   func_021C0878  0x021C0878  thumb  ov217
 *   func_021C08D4  0x021C08D4  thumb  ov217
 *   func_021C08C4  0x021C08C4  thumb  ov217
 *   func_021C0918 0x021C0918 thumb ov217
 *   func_021C093C 0x021C093C thumb ov217
 *   GFL_USE_IsAnySeBusy  0x02006238  thumb
 *   CircleGraph_SetEnabled  0x021C1184  thumb  ov217
 *   CircleGraph_QueueDrawSlow  0x021C1154  thumb  ov217
 *   CircleGraph_QueueDrawMedium 0x021C1178 thumb ov217
 *   func_021C0084  0x021C0084  thumb  ov217
 *   func_021C00F8  0x021C00F8  thumb  ov217
 *   func_021C0114  0x021C0114  thumb  ov217
 *   func_021C0170  0x021C0170  thumb  ov217
 *   func_021C018C  0x021C018C  thumb  ov217
 *   func_021C0230  0x021C0230  thumb  ov217
 *   func_021C02A8  0x021C02A8  thumb  ov217
 *   func_021C0358  0x021C0358  thumb  ov217
 *   func_021C03D0  0x021C03D0  thumb  ov217
 *   func_021C0494  0x021C0494  thumb  ov217
 *   func_021C06AC  0x021C06AC  thumb  ov217
 *   func_021C06E0  0x021C06E0  thumb  ov217
 *   func_021C0794  0x021C0794  thumb  ov217
 *   func_021C0800  0x021C0800  thumb  ov217
 *   func_021C085C  0x021C085C  thumb  ov217
 *   func_021C08A8  0x021C08A8  thumb  ov217
 *   func_021C08F0  0x021C08F0  thumb  ov217
 *   func_021C0968  0x021C0968  thumb  ov217
 *   CircleGraph_QueueErase  0x021C116C  thumb  ov217
 *   CircleGraph_HoldUpdate 0x021C118C thumb ov217
 *   CircleGraph_QueueDrawFast 0x021C1160 thumb ov217
 *   FADE_Start  0x0204E720  arm
 *   d_021C3AC8     0x021C3AC8  data  a1
 *   CircleGraph_GetSliceKey 0x021C11D0 thumb ov217
 *   GRAPHTABLE_FindEntry 0x021C26AC thumb ov217
 *   CircleGraph_FindSliceIndex 0x021C11C8 thumb ov217
 *   CircleGraph_SetCenterDepth 0x021C11A4 thumb ov217
 *   CircleGraph_SetSlices 0x021C10E8 thumb ov217
 *   CircleGraph_Update 0x021C1124 thumb ov217
 *   CircleGraph_Draw 0x021C112C thumb ov217
 *   GRAPHTABLE_GetEntryRed 0x021C2654 thumb ov217
 *   GRAPHTABLE_GetEntryGreen 0x021C2664 thumb ov217
 *   GRAPHTABLE_GetEntryBlue 0x021C2674 thumb ov217
 *   ARROW_Reset 0x021C20D8 thumb ov217
 *   CircleGraph_GetPercentByKey 0x021C11DC thumb ov217
 *   CircleGraph_GetLabelPositionByKey 0x021C11FC thumb ov217
 *   ARROW_Layout 0x021C20B4 thumb ov217
 *   ARROW_Start 0x021C20CC thumb ov217
 *   CircleGraph_GetPercentByIndex 0x021C11E8 thumb ov217
 *   CircleGraph_GetLabelPositionByIndex 0x021C1224 thumb ov217
 *   PERCENTAGE_SetValue 0x021C272C thumb ov217
 *   PERCENTAGE_SetPosition 0x021C271C thumb ov217
 *   PERCENTAGE_SetVisible 0x021C2740 thumb ov217
 *   func_021C0900 0x021C0900 thumb ov217
 *   d_021C3628     0x021C3628  data   ov217  a4
 *   d_021C36B8 0x021C36B8 data a1
 *   d_021C369A 0x021C369A data a1
 *   BgTextLabel_PrintText 0x021C0F78 thumb ov217
 *   STRBUF_Create 0x020457B0 arm
 *   STRBUF_Delete 0x02045808 arm
 *   func_0201EFA4 0x0201EFA4 thumb
 *   func_0201EE0C 0x0201EE0C thumb
 *   func_0201F250 0x0201F250 thumb
 *   d_021C3850 0x021C3850 data a2
 *   CLACT_SetActorAnimLoopCount 0x0204B9C4 arm
 *   d_021C3A34 0x021C3A34 data a4
 *   PALANM_RequestFade 0x0202173C thumb
 *   RESEARCH_COMMON_GetContext  0x021C09B0  thumb  ov217
 *   CircleGraph_IsAnimating  0x021C11F4  thumb  ov217
 *   d_021C363C 0x021C363C data ov217 a1
 *   d_021C3646 0x021C3646 data ov217 a1
 *   d_021C3632 0x021C3632 data ov217 a1
 *   func_0200E3A0 0x0200E3A0 thumb
 *   func_0200E3A4 0x0200E3A4 thumb
 *   GRAPHTABLE_GetEntryId 0x021C2644 thumb ov217
 *   GAME_DATA_GetPlayTime 0x02012FCC thumb
 *   func_0200864C 0x0200864C thumb
 *   func_0200E458  0x0200E458  thumb
 *   func_020056BC 0x020056BC thumb
 *   func_021C019C 0x021C019C thumb ov217
 *   func_021C0384 0x021C0384 thumb ov217
 *   func_021C03EC 0x021C03EC thumb ov217
 *   func_021C04B0 0x021C04B0 thumb ov217
 *   func_021C07B0 0x021C07B0 thumb ov217
 *   func_021C0820 0x021C0820 thumb ov217
 *   d_021C3650 0x021C3650 data a4
 *   func_0201ED04  0x0201ED04  thumb
 *   CircleGraph_Create 0x021C10C8 thumb ov217
 *   CircleGraph_Destroy 0x021C10D8 thumb ov217
 *   MI_CpuFill8  0x02082BCC  arm
 *   func_0200E47C 0x0200E47C thumb
 *   func_0200E4B0 0x0200E4B0 thumb
 *   func_0200E4F8 0x0200E4F8 thumb
 *   d_021C367C 0x021C367C data a1
 *   d_021C3D44 0x021C3D44 data a1
 *   d_021C386C 0x021C386C data a1
 *   d_021C3900 0x021C3900 data a1
 *   d_021C3994 0x021C3994 data a1
 *   d_021C3758 0x021C3758 data a1
 *   ARROW_Create 0x021C2070 thumb ov217
 *   ARROW_Destroy  0x021C209C  thumb  ov217
 *   PERCENTAGE_Create 0x021C26E8 thumb ov217
 *   PERCENTAGE_Destroy  0x021C270C  thumb  ov217
 *   func_0207D988 0x0207D988 arm
 *   func_0207DB1C 0x0207DB1C arm
 *   func_0207DCF8 0x0207DCF8 arm
 *   d_021C365C 0x021C365C data a4
 *   PALANM_TransferPalettes  0x02021D50  thumb  arm9
 *   GF_FONT_Create  0x0201D7EC  thumb  arm9
 *   PALANM_Create  0x02021518  thumb  arm9
 *   PALANM_AllocSlotBuffers  0x0202155C  thumb  arm9
 *   PALANM_FreeSlotBuffers  0x020215A0  thumb  arm9
 *   PALANM_CopyHwPaletteToSlot  0x020216D4  thumb  arm9
 *   GFL_NET_RestartWithDefaultTimeout  0x0203D34C  arm  arm9
 *   BMP_WIN_Exit  0x020450C8  arm  arm9
 *   CLACT_ReleaseCharacter  0x0204A8D4  arm  arm9
 *   CLACT_ReleasePalette  0x0204ADA4  arm  arm9
 *   CLACT_ReleaseCellAnim  0x0204AFD8  arm  arm9
 *   FADE_IsActive  0x0204E804  arm  arm9
 *   func_0204044C 0x0204044C arm
 *   sub_02040588 0x02040588 arm
 *   d_021C366C 0x021C366C data a4
 *   d_021C36D8 0x021C36D8 data ov217
 *   d_021C36F8 0x021C36F8 data ov217
 *   d_021C3718 0x021C3718 data ov217
 *   d_021C3738 0x021C3738 data ov217
 *   d_021C3B7C 0x021C3B7C data ov217
 *   d_021C3620  0x021C3620  data  a2
 *   d_021C3618  0x021C3618  data  a1
 *   d_021C37FC 0x021C37FC data a4
 *   func_021BF9FC 0x021BF9FC thumb ov217
 *   func_021BF9F0 0x021BF9F0 thumb ov217
 *   d_021C37A4  0x021C37A4  data  a4
 *   d_021C3C54  0x021C3C54  data  a4
 *   d_021C37D0  0x021C37D0  data  a4
 *   d_021C377C 0x021C377C data a4
 *   d_021C3A28  0x021C3A28  data  a4
 *   func_021BF6BC  0x021BF6BC  thumb  ov217
 *   func_02030EAC  0x02030EAC  arm
 *   func_02012138  0x02012138  thumb
 *   GAME_COMM_RequestExitNoCallback  0x02026400  thumb
 *   GAME_COMM_GetKind  0x02026454  thumb
 *   GAME_COMM_SetNotifyFlag  0x02026498  thumb
 *   func_021BF734  0x021BF734  thumb  ov217
 *   func_02030734  0x02030734  arm
 */
#include "../../matched/include/G_E.h"
#include "../../matched/include/Obj25933.h"
#include "../../matched/include/Obj25949.h"
#include "../../matched/include/G_Bg.h"
#include "../../matched/include/Obj25959.h"
#include "../../matched/include/Obj14748.h"
#include "../../matched/include/Obj14749.h"
#include "../../matched/include/Obj14750.h"
#include "../../matched/include/Obj08438.h"
#include "../../matched/include/Obj10960.h"
#include "../../matched/include/Obj06713.h"
#include "../../matched/include/Obj08439.h"
#include "../../matched/include/Obj25960.h"
#include "../../matched/include/Obj14752.h"
#include "../../matched/include/Obj25962.h"
#include "../../matched/include/Obj25964.h"
#include "../../matched/include/Obj14753.h"
#include "../../matched/include/Obj14754.h"
#include "../../matched/include/Obj10961.h"
#include "../../matched/include/Obj25966.h"
#include "../../matched/include/Obj25967.h"
#include "../../matched/include/Obj25969.h"
#include "../../matched/include/Obj03953.h"
#include "../../matched/include/Obj10962.h"
#include "../../matched/include/Obj25970.h"
#include "../../matched/include/Obj25973.h"
#include "../../matched/include/Obj25974.h"
#include "../../matched/include/Obj25975.h"
#include "research_top_shared_types.h"
#include "research_list_shared_types.h"
#include "research_graph_shared_types.h"

struct W;

struct WordSet;

struct PlayTime;

struct ResearchObjB {
    union { void * f0; u32 f0u; };
    u16 f4;
    u8 pad6[0x2];
    u32 f8;
    void * fC;
    u8 pad10[0x4];
    void * f14;
    void * f18;
    u32 f1C;
    u32 f20;
    u32 f24;
    u32 f28;
    u32 f2C;
    u32 f30;
    union { u32 f34; int f34s; };
    u8 f38;
    u8 pad39[0x27F];
    u8 f2B8;
    u8 f2B9;
    u8 pad2BA[0x2];
    void * f2BC;
    void * f2C0;
    void * f2C4;
    void * f2C8;
    u32 f2CC;
    void * f2D0;
    u8 pad2D4[0x28];
    u8 f2FC;
    u8 f2FD;
    u8 pad2FE[0x4A];
    int f348;
    u32 f34C;
    u32 f350;
    u32 f354;
    u32 f358;
    u32 f35C;
    u32 f360;
    u32 f364;
    u8 pad368[0x34];
    u32 f39C;
    void * f3A0;
    u8 pad3A4[0x8];
    u32 f3AC;
    u8 pad3B0[0x8];
    void * f3B8;
    union { void * f3BC; u32 f3BCu; };
    u8 pad3C0[0x4];
    void * f3C4;
    u32 f3C8;
    int f3CC;
    u32 f3D0;
    u32 f3D4;
    u32 f3D8;
    u32 f3DC;
    u32 f3E0;
    u32 f3E4;
};

struct Item { u8 id,pad[3]; u32 value; u8 x,y,z,a,b,c,pad2[2]; };

struct Input { u16 id; u8 x,y,z,pad; u16 a; u32 b; };

struct Row { u8 x,y,w,h; int fields[8]; };

typedef struct S { u32 a; u16 b; u8 pad[14]; } S;

typedef struct W { u32 w0; u16 h; u16 pad; u32 w8; u32 obj[3]; } W;

struct Entry { u8 a, b, c, d; };

struct Params_021BFE8C { u32 handles[3]; u16 a, b, c, d, e; };

struct Params_021BFF00 { u32 handles[3]; u16 a, b, c; };

extern u32 GAMESYSTEM_TryStartAutoComm(struct IcaAnime *p);

extern void GFL_NET_RestartWithDefaultTimeout(u32 a, u32 b);

extern void *func_020490F4(unsigned int id, u32 heap);

extern void *ARC_TOOL_LoadHandleMember(struct ArcFile *, u32, u32);

extern u32 func_020307B0(void *p);

extern int func_02062B30(void *, void **);

extern void func_02041090(u32, u32, u32, u32, u8, u8);

extern int func_020409B4(int);

extern void ARC_TOOL_DeleteHandle(void *);

extern void func_020413B0(int index, int x0, int y0, int w, int h, int pal);

extern u32 RESEARCH_COMMON_GetHeapId(void *);

extern void RESEARCH_COMMON_UpdatePaletteAnime(unsigned);

extern void CLACT_DrawSystem();

extern u32 KEY_GetTrg(void);

extern int TOUCHPANEL_HitTrg(const void *);

extern void * RESEARCH_COMMON_GetTouchRects(void *);

extern u32 GFL_USE_PlaySeDefaultVolume(u32 a);

extern int FADE_IsActive(void);

extern void RESEARCH_COMMON_StopPaletteAnime(u32 a0);

extern void RESEARCH_COMMON_RestorePaletteAnime(u32 a0);

extern void RingQueue_Push(u32, u32);

extern u32 RingQueue_Pop(struct Ring *r);

extern u32 RingQueue_IsEmpty();

extern u32 RESEARCH_COMMON_GetPreviousScreen(void *p);

extern u32 RESEARCH_COMMON_GetEntryHandled(void *p);

extern void RESEARCH_COMMON_SetEntryHandled(u8 *p, u32 v);

extern u8 GAME_BEACON_PopQuestionnaireUpdated(void);

extern void RESEARCH_COMMON_StartPaletteAnime(u8 *p, u32 i);

extern void CLACT_SetActorDrawEnable(struct Obj *, unsigned int);

extern void CLACT_SetActorAutoAnim(struct Obj *p, unsigned int v);

extern void FADE_Start(u32 a, s32 b, s32 c, s32 d);

extern void PALETTE_ANIME_Start(u8 *p, u32 b, u16 c);

extern void PALETTE_ANIME_Stop(u32 a0);

extern void PALETTE_ANIME_Update(int);

extern unsigned RESEARCH_COMMON_GetAppResource(void *);

extern u32 RESEARCH_COMMON_GetInputFlag(void *p);

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);

extern struct GfFont *GF_FONT_Create(int a0, int a1, int a2, int a3, u32 heapId);

extern u32 GF_FONT_Delete(void *ptr);

extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);

extern u32 MSGDATA_Delete(struct Rec *rec);

extern int RingQueue_Create(int a0, int a1);

extern void RingQueue_Destroy(void *p);

extern void BMP_WIN_Init(u16);

extern void BMP_WIN_Exit(void);

extern void func_02040C14(u32 layer, u32 value, u32 count, u32 index);

extern u32 func_020414EC();

extern void func_02040DA8(u32, u32, u32);

extern struct Record *BgTextLabel_Create(const struct Config *config, u32 a, u32 b, u32 heap);

u32 BgTextLabel_PrintMessage(u32 a0, u32 a1);

extern void BgTextLabel_Destroy(u8 *p);

extern s32 CLACT_RegisterCharacter(void *a, u32 b, u32 c, u32 a3, u16 flags);

extern s32 CLACT_RegisterPalette(void *a, u32 b, u32 c, u32 d, u16 g);

extern s32 CLACT_RegisterCellAnim(void *owner, u32 first, u32 second, u32 mode);

extern void CLACT_ReleaseCharacter(u32 i);

extern u32 CLACT_ReleaseCellAnim();

extern s32 CLACT_RegisterPaletteEx(void *a, u32 b, u32 c, u32 d, u16 e, u16 f, u16 g);

extern struct Bank *CLACT_CreateUnit(int count, u8 flag, u32 heapId);

extern u32 CLACT_DeleteUnit(struct Bank *bank);

extern void CLACT_DeleteActor(struct Obj *p);

extern u32 PALETTE_ANIME_Create(u32 a0);

extern u32 PALETTE_ANIME_Destroy(void *a0);

extern void PALETTE_ANIME_Bind(void *p, u32 b, u32 c, u32 d);

extern int PALETTE_ANIME_Restore(char *p);

extern void CLACT_VBlankSystem(void);

extern u32 KEY_GetCont(void);

extern void *GAME_DATA_GetSaveControl(struct Big *);

extern void *func_0200E394(void *a0);

extern int func_0200E44C(int p0, int p1);

extern void BMP_OAM_SetPalette(u8 *g, u32 a);

extern void CLACT_AddActorSurfacePos(struct Obj *p,const struct Vec2 *delta,u32 which);

extern void BgTextLabel_SetVisible(u8 *p, int visible);

extern u32 func_0209C0A4(u32, u32);

extern int PALANM_RequestFade(PalAnmObj *, u16, u16, s16, u8, u8, u16, void *);

extern u32 PALANM_GetFadeRequestBits(const char *ptr);

extern u32 PALETTE_ANIME_IsRunning();

extern u32 PALANM_TransferPalettes(struct S02021D50 *p);

extern u32 func_020419E4();

extern void BMP_OAM_SetEnabled(u8 *g, u32 a);

extern u32 func_020056BC(void);

extern struct Bmp *BMP_Create(u32 width, u32 height, u32 depth, u16 heap);

extern struct Bmp *BMP_CreateFromArchive(u32,u32,u32,u32);

extern void BMP_Blit(struct Bmp *,struct Bmp *,u32,u32,int,int,u32,u32,u32);

extern void *func_02045EC0(struct MsgBank *,u32);

extern void PRINTSYS_PrintColor(void *,s16,s16,void *,void *,u16);

extern void BMP_OAM_DeleteSys(void *p);

extern void BMP_OAM_UploadChars(struct Obj *);

extern void BMP_OAM_Delete(struct Grid *g);

extern void *PALANM_Create(u32);

extern void PALANM_AllocSlotBuffers(struct PalAnmSlot *, u32, u32, u32);

extern void PALANM_CopyHwPaletteToSlot(struct PalAnmSlot *, u32, u32, u32);

extern u32 PALANM_Delete(void *a0);

extern void PALANM_FreeSlotBuffers(struct PalAnmSlot *slots, u32 idx);

extern int func_020056A0(void (*)(void), void *, int);

extern void func_02030EAC(struct Node *n);

extern void ARROW_Update(void *h);

void func_021BFFC8(char *p);

void func_021C00AC(char *p);

u32 func_021C00FC();

void func_021C0124(char *p);

u32 func_021C0174();

void func_021C01B8(char *p);

void func_021C0250(char *p);

void func_021C02C8(char *p);

void func_021C03A0(u8 *p);

void func_021C0408(u8 *p);

void func_021C04CC(u8 *p);

void func_021C04FC(u8 *p);

void func_021C05B0(u8 *p);

void func_021C06C8(u8 *p);

void func_021C06F0(u8 *p);

void func_021C07BC(u8 *p);

void func_021C083C(u8 *p);

void func_021C0878(u8 *p);

void func_021C08D4(char *p);

void func_021C08C4(u32 a0);

void func_021C0918(u8 *a0);

int func_021C093C(u8 *a0);

extern int GFL_USE_IsAnySeBusy(void);

extern void CircleGraph_SetEnabled(u8 *h, u32 v);

extern void CircleGraph_QueueDrawSlow(u8 *h);

extern void CircleGraph_QueueDrawMedium(u8 *h);

u32 func_021C0084();

void func_021C00F8();

void func_021C0114();

void func_021C0170();

void func_021C018C();

void func_021C0230(int *p);

u32 func_021C02A8(u32 a0);

u32 func_021C0358(u32 a0);

void func_021C03D0(int *p);

void func_021C0494(int *p);

void func_021C06AC(int *p);

void func_021C06E0(u8 *a0);

void func_021C0794(int *p);

u32 func_021C0800(u32 a0);

void func_021C085C(int *p);

void func_021C08A8(int *p);

void func_021C08F0(u8 *a0);

void func_021C0968(unsigned char *a0);

extern void CircleGraph_QueueErase(u8 *h);

extern void CircleGraph_HoldUpdate(u8 *h, u32 v);

extern void CircleGraph_QueueDrawFast(u8 *h);

extern u8 CircleGraph_GetSliceKey(u8 *p, u8 n);

extern u32 GRAPHTABLE_FindEntry(const u8 *p, u8 unused, u8 key);

extern u8 CircleGraph_FindSliceIndex(u8 *p, u8 key);

extern void CircleGraph_SetCenterDepth(u8 *p, int a1);

extern void CircleGraph_SetSlices(u8 *p, u8 *tab, int n);

extern void CircleGraph_Update(u8 *p);

extern void CircleGraph_Draw(u8 *p);

extern unsigned GRAPHTABLE_GetEntryRed(void *,unsigned,unsigned);

extern unsigned GRAPHTABLE_GetEntryGreen(void *,unsigned,unsigned);

extern unsigned GRAPHTABLE_GetEntryBlue(void *,unsigned,unsigned);

extern unsigned ARROW_Reset(unsigned);

extern u8 CircleGraph_GetPercentByKey(u8 *p, u8 key);

extern void CircleGraph_GetLabelPositionByKey(u8 *h, u8 key, s32 *px, s32 *py);

extern void ARROW_Layout(int a0, int a1, int a2, int a3, int a4);

extern void ARROW_Start(unsigned);

extern u8 CircleGraph_GetPercentByIndex(u8 *p, u8 n);

extern void CircleGraph_GetLabelPositionByIndex(u8 *h, u8 n, s32 *px, s32 *py);

extern unsigned PERCENTAGE_SetValue(unsigned,unsigned);

extern unsigned PERCENTAGE_SetPosition(unsigned,unsigned,unsigned);

extern void PERCENTAGE_SetVisible(u32 a, u32 b);

u32 func_021C0900(s32 v);

extern void BgTextLabel_PrintText(u8 *p, struct U16Vec *text);

extern struct U16Vec *STRBUF_Create(u32 capacity, u32 heapId);

extern void STRBUF_Delete(struct U16Vec *vec);

extern void func_0201EFA4(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);

extern void func_0201EE0C(struct WordSet *p, u32 i, const void *src, u32 n, u32 f, u32 c);

extern void func_0201F250(struct WordSet *ws, void *dst, void *src);

extern void CLACT_SetActorAnimLoopCount(struct Actor *,unsigned);

extern u32 RESEARCH_COMMON_GetContext(u32 *p);

extern int CircleGraph_IsAnimating(u8 *p);

extern void *func_0200E3A0(void *a);

extern u32 func_0200E3A4(const u8 *, int);

extern u32 GRAPHTABLE_GetEntryId(void *, u32, u8);

extern int GAME_DATA_GetPlayTime(int);

extern u16 func_0200864C(const struct PlayTime *p);

extern u16 func_0200E458(const u16 *, int);

void func_021C019C(void *p);

void func_021C0384(void *p);

void func_021C03EC(void *p);

void func_021C04B0(void *p);

void func_021C07B0(void *p);

void func_021C0820(void *p);

extern struct WordSet *func_0201EC64(u32 heap);

extern u32 func_0201ED04(struct WordSet *p);

extern u32 CircleGraph_Create(u32 a0);

extern u32 CircleGraph_Destroy(void *a0);

extern void MI_CpuFill8(u32, u32, u32);

extern u32 func_0200E47C(u8 *p, int i);

extern u32 func_0200E4B0(u8 *a0, u32 a1, u32 a2);

extern int func_0200E4F8(int a0, int a1, int a2);

extern u32 ARROW_Create(u32, u32);

extern u32 ARROW_Destroy(void *a0);

extern u32 PERCENTAGE_Create(u32, u32, u32);

extern u32 PERCENTAGE_Destroy(void *a0);

extern void func_0207D988(void);

extern void func_0207DB1C(void);

extern void func_0207DCF8(const void *);

void *func_021BD5F4(void *p);

u32 func_021BD61C(void *a0);

void func_021BD62C(unsigned char *p);

u32 func_021BD708(void *p);

u32 func_021BD710(void *p);

void func_021BD718(unsigned char *p);

void func_021BD868(u32 a0);

void func_021BD89C(u8 *p);

void func_021BDC18(u8 *p);

void func_021BDF58(u8 *p);

void func_021BE040(u8 *p);

void func_021BE094(u32 a0);

void func_021BE0D0(u32 a0);

void func_021BE108(char *p);

void func_021BE21C(char *p);

void func_021BE33C(u32 a0);

void func_021BE36C(u32 a0);

void func_021BE384(u8 *a0);

void func_021BE448(void *p);

void func_021BE454(u8 *a0, u32 a1);

void func_021BE460(void *p, u32 v);

u32 func_021BE468(void *p);

u32 func_021BE46C(u8 *a0);

void func_021BE490(void *p);

void func_021BE498(u8 *a0, u32 a1);

void func_021BE4A4(u32 a0);

void func_021BE4CC(void *p, u32 v);

u32 func_021BE4DC(void *p);

void func_021BE4E0(void *p);

void func_021BE4E8(u8 *p);

void func_021BE580(u8 *p);

u32 func_021BE614(u32 a0, u32 a1);

void func_021BE630(u8 *a0, u32 a1);

void func_021BE678(char *p);

void func_021BE704(char *p);

u32 func_021BE790(u32 a0);

u32 func_021BE7B4(u32 a0);

void func_021BE7D8(char *p);

void func_021BE7F0(char *p);

void func_021BE808(char *p);

void func_021BE8FC(void);

void func_021BE90C(void);

void func_021BE91C(char *p, int a);

void func_021BE930(void *p, u32 v);

int func_021BE934(char *p);

void func_021BE9B8(u8 *p);

void func_021BEA3C(char *p, int a);

void func_021BEA54(char *p);

void func_021BEA8C(u8 *p, int step);

void func_021BEAEC(u8 *a0);

void func_021BEAF8(u8 *p);

void func_021BEB40(u32 a0);

void func_021BEB6C(u32 a0);

void func_021BEB88(u32 a0);

void func_021BEBA4(u32 a0);

void func_021BEBC0(u32 a0);

void func_021BEBE4(u32 a0);

void func_021BEC00(u32 *p);

void func_021BEC0C(void *p);

void func_021BEC34(u32 a0);

void func_021BEC64(void *p);

void func_021BEC84(u8 *p,int mode);

void func_021BED10(u8 *p, u32 mode);

void func_021BED9C(char *p);

void func_021BEDC4(char *p);

void func_021BEDEC(char *p);

void func_021BEEA4(char *p);

void func_021BEF30(char *p);

void func_021BEF98(char *p);

void func_021BEFC0(u8 *a0, u32 a1);

void func_021BEFD4(char *p);

void func_021BEFF8(u8 *p);

void func_021BF08C(char *p);

void func_021BF100(char *p);

void func_021BF11C(char *p);

void func_021BF13C(char *p);

void func_021BF15C(char *p);

void func_021BF264(char *p);

void func_021BF2FC(char *p);

void func_021BF38C(char *p);

void func_021BF3B4(char *p);

void func_021BF3D8(char *p);

void func_021BF47C(char *p);

void func_021BF4AC(char *p);

void func_021BF55C(void *a0);

void func_021BF568(void *a0);

void func_021BF574(void *a0);

void func_021BF580(u8 *p, u32 i, u32 j);

void func_021BF594(char *p, int i);

void func_021BF5BC(u8 *a0, u32 a1);

u32 func_021BF5D0(u8 *a0, u32 a1);

void func_021BF5E4(int *p);

void func_021BF600(u8 *a0);

void func_021BF60C(char *p);

void func_021BF658(char *p);

u32 func_021BF6A4(u8 *a0);

u32 func_021BF6BC(u32 a0, u32 a1);

void func_021BF6D4(char *p);

void func_021BF704(void *p);

void func_021BF710(void *p);

void func_021BF728(void *p);

u32 func_021BF734(u8 *a0);

u32 func_021BF740(u8 *a0);

void func_021BF74C(void *p, u32 v);

u32 func_021BF750(void *p);

void func_021BF754(void *p, u32 v);

u32 func_021BF758(void *p);

void func_021BF764(void *p, u32 v);

u8 *func_021BF76C(void *p);

u8 *func_021BF77C(void *p);

u32 func_021BF78C(u32 a0);

u32 func_021BF7CC(void *p);

u32 func_021BF7E0(void *p);

u32 func_021BF7F4(void *p);

u32 func_021BF810(void *p);

u32 func_021BF834(void *p);

u32 func_021BF844(void *p);

u32 func_021BF854(char *p);

u32 func_021BF878(void *p);

u32 func_021BF894(void *p);

u8 func_021BF8B0(u8 *p);

u32 func_021BF910(u8 *p);

u32 func_021BF968(u8 *p);

u16 func_021BF9CC(u32 a0);

u32 func_021BF9F0(void *p, u32 i);

u32 func_021BF9FC(void *p, u32 i);

u32 func_021BFA08(void *p, u32 i);

u32 func_021BFA14(u32 a0);

void func_021BFA30(char *p);

u32 func_021BFB04(void *a0);

void func_021BFB0C(void *p);

void func_021BFB14(u32 a0);

void func_021BFB24(u8 *a0);

void func_021BFB30(void *p);

void func_021BFB38(u32 a0);

void func_021BFB54(u8 *a0);

void func_021BFB60(void *p);

void func_021BFB74(W *p);

void func_021BFBA0(int *p);

void func_021BFBB8(void *p);

void func_021BFBC0(u32 a0);

void func_021BFBD0(u8 *a0);

void func_021BFBDC(void *p);

void func_021BFBFC(char *p);

void func_021BFC28(char *p);

void func_021BFC50(u8 *a0);

void func_021BFC60(char *p);

void func_021BFE40(u8 *p);

void func_021BFE80(void *p);

void func_021BFE8C(char *p);

void func_021BFED4(u8 *a0);

void func_021BFEE4(void *p);

void func_021BFF00(char *p);

void func_021BFF5C(int *p);

void func_021BFF78(void);

extern struct E d_021C3AC8[];

extern unsigned char d_021C3628[];

extern u8 d_021C36B8[];

extern u8 d_021C369A[];

extern const u16 d_021C3850[];

extern S d_021C3A34[];

extern const u8 d_021C363C[];

extern const u8 d_021C3646[];

extern const u8 d_021C3632[];

extern u32 d_021C3650[];

extern u8 d_021C367C[];

extern u8 d_021C3D44[][17];

extern struct Bg d_021C386C;

extern u8 d_021C3900[];

extern u8 d_021C3994[];

extern const struct Entry d_021C3758[];

extern const u16 d_021C365C[];

void *func_021BD5F4(void *p)
{
    void *r;
    void *a;
    a = (void *)RESEARCH_COMMON_GetHeapId(p);
    r = (void *)func_021BFA14((u32)a);
    func_021BFA30(r);
    func_021BF74C(r, (u32)a);
    func_021BF754(r, (u32)p);
    return r;
}

u32 func_021BD61C(void *a0)
{
    func_021BFB24((u8 *)a0);
    return func_021BFB04(a0);
}

void func_021BD62C(unsigned char *p)
{
    switch (((struct ResearchObjB *)p)->f20) {
    case 0: func_021BD718(p); break;
    case 1: func_021BD868((u32)p); break;
    case 2: func_021BD89C(p); break;
    case 3: func_021BDC18(p); break;
    case 4: func_021BDF58(p); break;
    case 5: func_021BE040(p); break;
    case 6: func_021BE094((u32)p); break;
    case 7: func_021BE0D0((u32)p); break;
    case 8: func_021BE108((char *)p); break;
    case 9: func_021BE21C((char *)p); break;
    case 10: func_021BE33C((u32)p); break;
    case 11: func_021BE36C((u32)p); break;
    case 12: func_021BE384((u8 *)p); break;
    case 13: return;
    }
    func_021BF6D4((char *)p);
    func_021BF710(p);
    if (((struct ResearchObjB *)p)->f3C4 != 0) {
        CLACT_DrawSystem(((struct ResearchObjB *)p)->f3C4);
        func_021BED9C((char *)p);
        ARROW_Update(((struct ResearchObjB *)p)->f2D0);
        func_021BF600(p);
        func_021BF5E4((int *)p);
        func_021BEDC4((char *)p);
        func_021BEDEC((char *)p);
        *(volatile unsigned int *)0x04000540 = 0;
    }
    func_021BE490(p);
    func_021BE4A4((u32)p);
}

u32 func_021BD708(void *p)
{
    return ((struct ResearchObjB *)p)->f3E0;
}

/*
 * Field getter, u32 at +0x3e4.
 *
 * Addresses are Black-image addresses.
 */
u32 func_021BD710(void *p)
{
    return ((struct ResearchObjB *)p)->f3E4;
}

void func_021BD718(unsigned char *p)
{
    int r;
    func_021BFB14((u32)p);
    func_021BFB38((u32)p);
    func_021BFB74((struct W *)p);
    func_021BFBC0((u32)p);
    func_021BFE40(p);
    func_021BEFF8(p);
    func_021BFF78();
    func_021BFFC8((char *)p);
    func_021C00AC((char *)p);
    func_021C00FC(p);
    func_021C0124((char *)p);
    func_021C0174(p);
    func_021C01B8((char *)p);
    func_021C0250((char *)p);
    func_021C02C8((char *)p);
    func_021C03A0(p);
    func_021C0408(p);
    func_021C04CC(p);
    func_021C04FC(p);
    func_021C05B0(p);
    func_021C06C8(p);
    func_021C06F0(p);
    func_021BFC60((char *)p);
    func_021BFBFC((char *)p);
    func_021BFE8C((char *)p);
    func_021BFF00((char *)p);
    func_021C07BC(p);
    func_021C083C(p);
    func_021C0878(p);
    func_021C08D4((char *)p);
    func_021C08C4((u32)p);
    func_021BF100((char *)p);
    func_021BF11C((char *)p);
    func_021BF13C((char *)p);
    func_021BF15C((char *)p);
    func_021BF264((char *)p);
    func_021BF2FC((char *)p);
    func_021BF38C((char *)p);
    func_021BF3B4((char *)p);
    func_021BF3D8((char *)p);
    func_021BF08C((char *)p);
    func_021BF47C((char *)p);
    func_021BF55C(p);
    func_021BF594((char *)p, 0);
    func_021BF594((char *)p, 7);
    func_021BEAF8(p);
    *(int *)&((struct ResearchObjB *)p)->f3C4 = 1;
    func_021BE8FC();
    r = func_021BE46C(p);
    func_021BE498(p, 1);
    func_021BE498(p, r);
    if (r == 3)
        func_021BE934((char *)p);
    func_021BE448(p);
}

#pragma thumb on

void func_021BD868(u32 a0)
{
    switch (func_021BE4DC((void *)a0)) {
    case 0:
        func_021C0918((u8 *)a0);
        func_021BE4E0((void *)a0);
        break;
    case 1:
        if (func_021C093C((u8 *)a0) != 0) {
            func_021BE448((void *)a0);
        }
        break;
    }
}

void func_021BD89C(u8 *p)
{
    u32 keys;
    int hit;
    int sub;

    KEY_GetCont();
    keys = KEY_GetTrg();
    hit = TOUCHPANEL_HitTrg(p + 0x2FE);
    sub = TOUCHPANEL_HitTrg(RESEARCH_COMMON_GetTouchRects(((struct ResearchObjB *)p)->f0));
    if (*(int *)&((struct ResearchObjB *)p)->f3C8 != 0 && ((struct ResearchObjB *)p)->f3D8 != 0 && *(int *)&((struct ResearchObjB *)p)->f3D4 != 0) {
        func_021BE448(p);
        func_021BE498(p, 8);
        func_021BE498(p, 6);
        func_021BE498(p, 7);
        func_021BE498(p, 5);
        func_021BE498(p, 2);
        return;
    }
    if (func_021BF758(p) != 0 || sub == 0) {
        func_021BE454(p, 1);
        func_021BEC00((u32 *)p);
        GFL_USE_PlaySeDefaultVolume(0x551);
        func_021BE448(p);
        func_021BE498(p, 11);
        func_021BE498(p, 10);
        func_021BE498(p, 12);
        return;
    }
    if ((keys & 0x40) || (keys & 0x80) || (keys & 0x20) || (keys & 0x10) || (keys & 1)) {
        func_021BE934((char *)p);
        func_021BEAF8(p);
        func_021BE448(p);
        func_021BE498(p, 3);
        return;
    }
    if (hit == 6 && *(int *)&((struct ResearchObjB *)p)->f3C8 == 0 && func_021BF810(p) != 0) {
        ((struct ResearchObjB *)p)->f3CC = 1;
        func_021BEB40((u32)p);
        func_021BE448(p);
        func_021BE498(p, 4);
        func_021BE498(p, 6);
        func_021BE498(p, 7);
        func_021BE498(p, 5);
        func_021BE498(p, 2);
    } else if (hit == 7) {
        if (*(int *)&((struct ResearchObjB *)p)->f3C8 == 0 && func_021BF810(p) != 0) {
            ((struct ResearchObjB *)p)->f3CC = 1;
            func_021BEB40((u32)p);
            func_021BE448(p);
            func_021BE498(p, 4);
            func_021BE498(p, 6);
            func_021BE498(p, 7);
            func_021BE498(p, 5);
            func_021BE498(p, 2);
        } else {
            GFL_USE_PlaySeDefaultVolume(0x557);
        }
    } else if (hit == 2) {
        if (*(int *)&((struct ResearchObjB *)p)->f3C8 == 0 && func_021BF810(p) != 0) {
            ((struct ResearchObjB *)p)->f3CC = 1;
            func_021BEB40((u32)p);
            func_021BE448(p);
            func_021BE498(p, 4);
            func_021BE498(p, 6);
            func_021BE498(p, 7);
            func_021BE498(p, 5);
            func_021BE498(p, 2);
        } else {
            func_021BE614((u32)p, 0);
        }
    } else if (*(int *)&((struct ResearchObjB *)p)->f3C8 != 0 && func_021BF810(p) != 0 && hit == 3) {
        func_021BE614((u32)p, 1);
        func_021BE934((char *)p);
        func_021BEAF8(p);
        func_021BE448(p);
        func_021BE498(p, 3);
    } else if (*(int *)&((struct ResearchObjB *)p)->f3C8 != 0 && func_021BF810(p) != 0 && hit == 4) {
        func_021BE614((u32)p, 2);
        func_021BE934((char *)p);
        func_021BEAF8(p);
        func_021BE448(p);
        func_021BE498(p, 3);
    } else if (hit == 5) {
        func_021BE614((u32)p, 3);
        func_021BE934((char *)p);
        func_021BEAF8(p);
        func_021BE448(p);
        func_021BE498(p, 3);
    } else if (hit == 0) {
        func_021BE934((char *)p);
        func_021BEAF8(p);
        func_021BE448(p);
        func_021BE498(p, 3);
        switch (*(int *)&((struct ResearchObjB *)p)->f34) {
        case 0: func_021BE704((char *)p); break;
        case 1: func_021BE7B4((u32)p); break;
        case 3: func_021BE808((char *)p); break;
        }
    } else if (hit == 1) {
        func_021BE934((char *)p);
        func_021BEAF8(p);
        func_021BE448(p);
        func_021BE498(p, 3);
        switch (*(int *)&((struct ResearchObjB *)p)->f34) {
        case 0: func_021BE678((char *)p); break;
        case 1: func_021BE790((u32)p); break;
        case 3: func_021BE808((char *)p); break;
        }
    } else if (keys & 2) {
        func_021BE454(p, 0);
        func_021BEC00((u32 *)p);
        GFL_USE_PlaySeDefaultVolume(0x551);
        func_021BE448(p);
        func_021BE498(p, 11);
        func_021BE498(p, 10);
        func_021BE498(p, 12);
    }
}

void func_021BDC18(u8 *p)
{
    u32 keys;
    int hit;
    int sub;

    KEY_GetCont();
    keys = KEY_GetTrg();
    hit = TOUCHPANEL_HitTrg(p + 0x2FE);
    sub = TOUCHPANEL_HitTrg(RESEARCH_COMMON_GetTouchRects(((struct ResearchObjB *)p)->f0));
    if (*(int *)&((struct ResearchObjB *)p)->f3C8 != 0 && ((struct ResearchObjB *)p)->f3D8 != 0 && *(int *)&((struct ResearchObjB *)p)->f3D4 != 0) {
        func_021BE448(p);
        func_021BE498(p, 9);
        func_021BE498(p, 6);
        func_021BE498(p, 7);
        func_021BE498(p, 5);
        func_021BE498(p, 3);
        return;
    }
    if (func_021BF758(p) != 0 || sub == 0) {
        func_021BE454(p, 1);
        func_021BEC00((u32 *)p);
        GFL_USE_PlaySeDefaultVolume(0x551);
        func_021BE448(p);
        func_021BE498(p, 11);
        func_021BE498(p, 10);
        func_021BE498(p, 12);
        return;
    }
    if (keys & 0x40) {
        func_021BE4E8(p);
    } else if (keys & 0x80) {
        func_021BE580(p);
    } else if (hit == 6 && *(int *)&((struct ResearchObjB *)p)->f3C8 == 0 && func_021BF810(p) != 0) {
        ((struct ResearchObjB *)p)->f3CC = 1;
        func_021BEB40((u32)p);
        func_021BE448(p);
        func_021BE498(p, 4);
        func_021BE498(p, 6);
        func_021BE498(p, 7);
        func_021BE498(p, 5);
        func_021BE498(p, 2);
    } else if (hit == 7) {
        if (*(int *)&((struct ResearchObjB *)p)->f3C8 == 0 && func_021BF810(p) != 0) {
            ((struct ResearchObjB *)p)->f3CC = 1;
            func_021BEB40((u32)p);
            func_021BE448(p);
            func_021BE498(p, 4);
            func_021BE498(p, 6);
            func_021BE498(p, 7);
            func_021BE498(p, 5);
            func_021BE498(p, 2);
        } else {
            GFL_USE_PlaySeDefaultVolume(0x557);
        }
    } else if (hit == 2) {
        if (*(int *)&((struct ResearchObjB *)p)->f3C8 == 0 && func_021BF810(p) != 0) {
            ((struct ResearchObjB *)p)->f3CC = 1;
            func_021BEB40((u32)p);
            func_021BE448(p);
            func_021BE498(p, 4);
            func_021BE498(p, 6);
            func_021BE498(p, 7);
            func_021BE498(p, 5);
            func_021BE498(p, 2);
        } else {
            func_021BE614((u32)p, 0);
        }
    } else if (*(int *)&((struct ResearchObjB *)p)->f3C8 != 0 && func_021BF810(p) != 0 && hit == 3) {
        func_021BE614((u32)p, 1);
    } else if (*(int *)&((struct ResearchObjB *)p)->f3C8 != 0 && func_021BF810(p) != 0 && hit == 4) {
        func_021BE614((u32)p, 2);
    } else if (hit == 5) {
        func_021BE614((u32)p, 3);
    } else if ((keys & 0x20) || hit == 0) {
        switch (*(int *)&((struct ResearchObjB *)p)->f34) {
        case 0: func_021BE704((char *)p); break;
        case 1: func_021BE7B4((u32)p); break;
        case 3: func_021BE808((char *)p); break;
        }
    } else if ((keys & 0x10) || hit == 1) {
        switch (*(int *)&((struct ResearchObjB *)p)->f34) {
        case 0: func_021BE678((char *)p); break;
        case 1: func_021BE790((u32)p); break;
        case 3: func_021BE808((char *)p); break;
        }
    } else if ((keys & 1) && *(int *)&((struct ResearchObjB *)p)->f3C8 == 0 && func_021BF810(p) != 0
               && (*(int *)&((struct ResearchObjB *)p)->f34 == 0 || *(int *)&((struct ResearchObjB *)p)->f34 == 4)) {
        ((struct ResearchObjB *)p)->f3CC = 0;
        func_021BEB40((u32)p);
        func_021BE448(p);
        func_021BE498(p, 4);
        func_021BE498(p, 6);
        func_021BE498(p, 7);
        func_021BE498(p, 5);
        func_021BE498(p, 3);
    } else if (keys & 2) {
        func_021BE454(p, 0);
        func_021BEC00((u32 *)p);
        GFL_USE_PlaySeDefaultVolume(0x551);
        func_021BE448(p);
        func_021BE498(p, 11);
        func_021BE498(p, 10);
        func_021BE498(p, 12);
    }
}

void func_021BDF58(u8 *p)
{
    switch (func_021BE4DC(p)) {
    case 0:
        func_021BFC60((char *)p);
        func_021BF704(p);
        func_021BF568(p);
        func_021BEC84(p, 0);
        func_021BEC84(p, 1);
        CircleGraph_SetEnabled(func_021BF76C(p), 1);
        CircleGraph_QueueDrawSlow(func_021BF76C(p));
        func_021BE4E0(p);
        break;
    case 1:
        if (GFL_USE_IsAnySeBusy() == 0) {
            if (((struct ResearchObjB *)p)->f28 >= 0x78)
                func_021BE4E0(p);
            else
                GFL_USE_PlaySeDefaultVolume(0x76B);
        }
        break;
    case 2:
        *(int *)&((struct ResearchObjB *)p)->f3C8 = 1;
        func_021BE930(p, 1);
        func_021BF3D8((char *)p);
        func_021BEFF8(p);
        func_021BE7F0((char *)p);
        func_021BF574(p);
        func_021BF08C((char *)p);
        func_021BF15C((char *)p);
        func_021BF264((char *)p);
        func_021BF3B4((char *)p);
        func_021BF2FC((char *)p);
        func_021BEEA4((char *)p);
        func_021BF47C((char *)p);
        if (((struct ResearchObjB *)p)->f3CC == 0)
            func_021BE934((char *)p);
        GFL_USE_PlaySeDefaultVolume(0x76C);
        func_021BE448(p);
        break;
    }
}

void func_021BE040(u8 *p)
{
    switch (func_021BE4DC(p)) {
    case 0:
        func_021BEF30((char *)p);
        func_021BE4E0(p);
        break;
    case 1:
        if (((struct ResearchObjB *)p)->f28 % 10u == 0) {
            u8 index = p[765];
            p[765] = index + 1;
            func_021BEFC0(p, index);
        }
        if (p[764] <= p[765]) func_021BE448(p);
        break;
    }
}

/*
 * Same two-case entry as func_021BE0D0; mode 0 arms the +5 handle and
 * func_021BF60C().
 *
 * Addresses are Black-image addresses.
 */
void func_021BE094(u32 a0)
{
    switch (func_021BE4DC((void *)a0)) {
    case 0:
    func_021BF5BC((u8 *)a0, 5);
    func_021BF60C((char *)a0);
    func_021BE4E0((void *)a0);
    break;
    case 1:
    if (func_021BF6A4((u8 *)a0) != 0) {
    func_021BE448((void *)a0);
    }
    break;
    }
}

void func_021BE0D0(u32 a0)
{
    switch (func_021BE4DC((void *)a0)) {
    case 0:
    func_021BF658((char *)a0);
    func_021BE4E0((void *)a0);
    break;
    case 1:
    if (func_021BF6A4((u8 *)a0) != 0) {
    func_021BEAF8((u8 *)a0);
    func_021BE448((void *)a0);
    }
    break;
    }
}

void func_021BE108(char *p)
{
    switch (func_021BE4DC(p)) {
    case 0:
        ((struct ResearchObjB *)p)->f3D0 = 1;
        func_021BF704(p);
        func_021BF728(p);
        func_021BFC60(p);
        func_021BF08C(p);
        func_021BF15C(p);
        func_021BF3B4(p);
        func_021BF38C(p);
        func_021BEEA4(p);
        func_021BF3D8(p);
        func_021BEF98(p);
        func_021BED10((u8 *)p, 0);
        func_021BED10((u8 *)p, 1);
        func_021BEC64(p);
        CircleGraph_SetEnabled(func_021BF77C(p), 1);
        CircleGraph_QueueDrawMedium(func_021BF77C(p));
        func_021BE4E0(p);
        break;
    case 1:
        if (GFL_USE_IsAnySeBusy() == 0) {
            if (((struct ResearchObjB *)p)->f28 >= 0x3c) {
                func_021BE4E0(p);
                return;
            }
            GFL_USE_PlaySeDefaultVolume(0x76b);
        }
        break;
    case 2:
        ((struct ResearchObjB *)p)->f3D0 = 0;
        func_021BEC0C(p);
        CircleGraph_SetEnabled(func_021BF77C(p), 0);
        func_021BF08C(p);
        func_021BF3B4(p);
        func_021BF15C(p);
        func_021BF264(p);
        func_021BF2FC(p);
        func_021BEEA4(p);
        func_021BF3D8(p);
        func_021BF4AC(p);
        func_021BF47C(p);
        GFL_USE_PlaySeDefaultVolume(0x76c);
        func_021BE448(p);
        break;
    }
}

void func_021BE21C(char *p)
{
    switch (func_021BE4DC(p)) {
    case 0:
        ((struct ResearchObjB *)p)->f3D0 = 1;
        func_021BF704(p);
        func_021BF728(p);
        func_021BFC60(p);
        func_021BE9B8((u8 *)p);
        func_021BF08C(p);
        func_021BF15C(p);
        func_021BF3B4(p);
        func_021BF38C(p);
        func_021BEEA4(p);
        func_021BF3D8(p);
        func_021BEF98(p);
        func_021BED10((u8 *)p, 0);
        func_021BED10((u8 *)p, 1);
        func_021BEC64(p);
        CircleGraph_SetEnabled(func_021BF77C(p), 1);
        CircleGraph_QueueDrawMedium(func_021BF77C(p));
        func_021BE4E0(p);
        break;
    case 1:
        if (GFL_USE_IsAnySeBusy() == 0) {
            if (((struct ResearchObjB *)p)->f28 >= 0x3c) {
                func_021BE4E0(p);
                return;
            }
            GFL_USE_PlaySeDefaultVolume(0x76b);
        }
        break;
    case 2:
        ((struct ResearchObjB *)p)->f3D0 = 0;
        func_021BEC0C(p);
        CircleGraph_SetEnabled(func_021BF77C(p), 0);
        func_021BF08C(p);
        func_021BE934(p);
        func_021BF3B4(p);
        func_021BF15C(p);
        func_021BF264(p);
        func_021BF2FC(p);
        func_021BEEA4(p);
        func_021BF3D8(p);
        func_021BF4AC(p);
        func_021BF47C(p);
        GFL_USE_PlaySeDefaultVolume(0x76c);
        func_021BE448(p);
        break;
    }
}

/*
 * Same two-case entry with func_021BE90C() and the ARM9 query FADE_IsActive().
 *
 * Addresses are Black-image addresses.
 */
void func_021BE33C(u32 a0)
{
    switch (func_021BE4DC((void *)a0)) {
    case 0:
    func_021BE90C();
    func_021BE4E0((void *)a0);
    break;
    case 1:
    if (FADE_IsActive() == 0) {
    func_021BE448((void *)a0);
    }
    break;
    }
}

/*
 * Calls func_021BE448() while func_021BE468() is below the record's +0x28
 * count.
 *
 * Addresses are Black-image addresses.
 */
void func_021BE36C(u32 a0)
{
    if (func_021BE468((void *)a0) < ((struct ResearchObjB *)a0)->f28) {
    func_021BE448((void *)a0);
    }
}

void func_021BE384(u8 *a0)
{
    func_021C08A8((int *)a0);
    func_021C085C((int *)a0);
    RESEARCH_COMMON_StopPaletteAnime(*(u32 *)&((struct ResearchObjB *)a0)->f0);
    RESEARCH_COMMON_RestorePaletteAnime(*(u32 *)&((struct ResearchObjB *)a0)->f0);
    func_021C08F0((u8 *)a0);
    func_021BFF5C((int *)a0);
    func_021BFED4(a0);
    func_021BFC28((char *)a0);
    func_021C0800((u32)a0);
    func_021C06AC((int *)a0);
    func_021C0794((int *)a0);
    func_021C06E0((u8 *)a0);
    func_021C0494((int *)a0);
    func_021C03D0((int *)a0);
    func_021C02A8((u32)a0);
    func_021C0358((u32)a0);
    func_021C0230((int *)a0);
    func_021C018C(a0);
    func_021C0170(a0);
    func_021C0114(a0);
    func_021C00F8(a0);
    func_021C0084(a0);
    func_021BFBD0((u8 *)a0);
    func_021BFBA0((int *)a0);
    func_021BFB54((u8 *)a0);
    func_021BE460((void *)a0, 0);
    func_021BE498((u8 *)a0, 13);
    func_021BE448((void *)a0);
    func_021C0968((unsigned char *)a0);
    *(u32 *)&((struct ResearchObjB *)a0)->f3C4 = 0;
    ((struct ResearchObjB *)a0)->f3E0 = 1;
}

void func_021BE448(void *p)
{
    ((struct ResearchObjB *)p)->f3DC = 1;
}

/*
 * Tail-call veneer: forwards arg(s) (u32)(*(u32*)(a0)) to RESEARCH_COMMON_SetEntryHandled.
 *
 * Addresses are Black-image addresses.
 */
void func_021BE454(u8 *a0, u32 a1)
{
    RESEARCH_COMMON_SetEntryHandled(*(u8 * *)&((struct ResearchObjB *)a0)->f0, a1);
}

void func_021BE460(void *p, u32 v)
{
    ((struct ResearchObjB *)p)->f3E4 = v;
}

u32 func_021BE468(void *p)
{
    return ((struct ResearchObjB *)p)->f2C;
}

/*
 * Classifies the record: 3 when the first query is busy and the second is
 * not, else 2.
 *
 * Addresses are Black-image addresses.
 */
u32 func_021BE46C(u8 *a0)
{
    u32 v = ((struct ResearchObjB *)a0)->f0u;
    u32 a = RESEARCH_COMMON_GetPreviousScreen((void *)v);
    u32 b = RESEARCH_COMMON_GetEntryHandled((void *)v);
    if (a != 0 && b == 0) {
    return 3;
    }
    return 2;
}

/*
 * Increment the u32 at +0x28.
 *
 * Addresses are Black-image addresses.
 */
void func_021BE490(void *p)
{
    u32 *c = (u32 *)((char *)p + 0x28);
    *c += 1;
}

/*
 * Tail-call veneer: forwards arg(s) (u32)(*(u32*)(a0 + 28)) to RingQueue_Push.
 *
 * Addresses are Black-image addresses.
 */
void func_021BE498(u8 *a0, u32 a1)
{
    RingQueue_Push((u32)(((struct ResearchObjB *)a0)->f1C), a1);
}

void func_021BE4A4(u32 a0)
{
    if (((struct ResearchObjB *)a0)->f3DC != 0) {
    if (RingQueue_IsEmpty(((struct ResearchObjB *)a0)->f1C) == 0) {
    func_021BE4CC((void *)a0, RingQueue_Pop((struct Ring *)(((struct ResearchObjB *)a0)->f1C)));
    }
    }
}

/*
 * Set +0x20, clear +0x24, +0x28 and +0x3dc.
 *
 * Addresses are Black-image addresses.
 */
void func_021BE4CC(void *p, u32 v)
{
    ((struct ResearchObjB *)p)->f20 = v;
    ((struct ResearchObjB *)p)->f24 = 0;
    ((struct ResearchObjB *)p)->f28 = 0;
    ((struct ResearchObjB *)p)->f3DC = 0;
}

u32 func_021BE4DC(void *p)
{
    return ((struct ResearchObjB *)p)->f24;
}

/*
 * Increment the u32 at +0x24.
 *
 * Addresses are Black-image addresses.
 */
void func_021BE4E0(void *p)
{
    u32 *c = (u32 *)((char *)p + 0x24);
    *c += 1;
}

void func_021BE4E8(u8 *p)
{
    int repeat=1;
    func_021BE9B8(p);
    func_021BE91C((char *)p,-1);
    do {
        u32 index=((struct ResearchObjB *)p)->f34;
        if (index-1<=1) {
            if (((struct ResearchObjB *)p)->f3C8==0 || func_021BF810(p)==0) {
                func_021BE91C((char *)p,-1);
            } else repeat=0;
        } else if (index==4) {
            if (((struct ResearchObjB *)p)->f3C8==1 || func_021BF810(p)==0) {
                func_021BE91C((char *)p,-1);
            } else repeat=0;
        } else repeat=0;
    } while(repeat);
    func_021BE934((char *)p);
    func_021BF3D8((char *)p);
    func_021BF4AC((char *)p);
    func_021BF594((char *)p,1);
    if (((struct ResearchObjB *)p)->f34==4) func_021BEBA4((u32)p);
    GFL_USE_PlaySeDefaultVolume(1352);
    func_021BEFF8(p);
}

void func_021BE580(u8 *p)
{
    int repeat=1;
    func_021BE9B8(p);
    func_021BE91C((char *)p,1);
    do {
        u32 index=((struct ResearchObjB *)p)->f34;
        if (index-1<=1) {
            if (((struct ResearchObjB *)p)->f3C8==0 || func_021BF810(p)==0) {
                func_021BE91C((char *)p,1);
            } else repeat=0;
        } else if (index==4) {
            if (((struct ResearchObjB *)p)->f3C8==1 || func_021BF810(p)==0) {
                func_021BE91C((char *)p,1);
            } else repeat=0;
        } else repeat=0;
    } while(repeat);
    func_021BE934((char *)p);
    func_021BF3D8((char *)p);
    func_021BF4AC((char *)p);
    func_021BF594((char *)p,1);
    if (((struct ResearchObjB *)p)->f34==4) func_021BEBA4((u32)p);
    GFL_USE_PlaySeDefaultVolume(1352);
    func_021BEFF8(p);
}

u32 func_021BE614(u32 a0, u32 a1)
{
    func_021BE630((u8 *)a0, a1);
    func_021BF594((char *)a0, 1);
    return GFL_USE_PlaySeDefaultVolume(1352);
}

void func_021BE630(u8 *a0, u32 a1)
{
    if ((u32)(a1 - 1) <= 1) {
    if (((struct ResearchObjB *)a0)->f3C8 == 0) {
    return;
    }
    if (func_021BF810(a0) == 0) {
    return;
    }
    }
    func_021BE9B8(a0);
    func_021BE930(a0, a1);
    func_021BE934((char *)a0);
    func_021BF3D8((char *)a0);
    func_021BF4AC((char *)a0);
    func_021BEFF8(a0);
}

/*
 * Per-frame step for the record's +0x3C8 sub-state; the tail is the
 * fixed-order call list that re-arms the sub-system (delta +1).
 *
 * Addresses are Black-image addresses.
 */
void func_021BE678(char *p)
{
    if (((struct ResearchObjB *)p)->f3C8 != 0) {
        if (func_021BF810(p) != 0) {
            CircleGraph_QueueErase(func_021BF76C(p));
        }
    }
    func_021BFC60(p);
    func_021BF704(p);
    func_021BEA3C(p, 1);
    ((struct ResearchObjB *)p)->f3C8 = 0;
    func_021BF08C(p);
    func_021BE934(p);
    func_021BF11C(p);
    func_021BF13C(p);
    func_021BE7D8((char *)p);
    func_021BF264(p);
    func_021BF2FC(p);
    func_021BF38C(p);
    func_021BEF98(p);
    func_021BF47C(p);
    func_021BEAF8((u8 *)p);
    GFL_USE_PlaySeDefaultVolume(1352);
}

/*
 * Identical frame step to func_021BE678 with the sub-state delta -1.
 *
 * Addresses are Black-image addresses.
 */
void func_021BE704(char *p)
{
    if (((struct ResearchObjB *)p)->f3C8 != 0) {
        if (func_021BF810(p) != 0) {
            CircleGraph_QueueErase(func_021BF76C(p));
        }
    }
    func_021BFC60(p);
    func_021BF704(p);
    func_021BEA3C(p, -1);
    ((struct ResearchObjB *)p)->f3C8 = 0;
    func_021BF08C(p);
    func_021BE934(p);
    func_021BF11C(p);
    func_021BF13C(p);
    func_021BE7D8((char *)p);
    func_021BF264(p);
    func_021BF2FC(p);
    func_021BF38C(p);
    func_021BEF98(p);
    func_021BF47C(p);
    func_021BEAF8((u8 *)p);
    GFL_USE_PlaySeDefaultVolume(1352);
}

u32 func_021BE790(u32 a0)
{
    func_021BEA8C((u8 *)a0, 1);
    func_021BF15C((char *)a0);
    func_021BEEA4((char *)a0);
    return GFL_USE_PlaySeDefaultVolume(1352);
}

u32 func_021BE7B4(u32 a0)
{
    func_021BEA8C((u8 *)a0, -1);
    func_021BF15C((char *)a0);
    func_021BEEA4((char *)a0);
    return GFL_USE_PlaySeDefaultVolume(1352);
}

void func_021BE7D8(char *p)
{
    func_021BEAEC((u8 *)p);
    func_021BF15C(p);
    func_021BEEA4(p);
}

void func_021BE7F0(char *p)
{
    func_021BEA54(p);
    func_021BF15C(p);
    func_021BEEA4(p);
}

void func_021BE808(char *p)
{
    int flag = 0;
    u32 k;
    if (func_021BF78C((u32)p) == 0) {
        return;
    }
    if (((struct ResearchObjB *)p)->f3C8 != 0 && func_021BF810(p) != 0) {
        CircleGraph_QueueErase(func_021BF76C(p));
        flag = 1;
    }
    switch (((struct ResearchObjB *)p)->f2CC) {
    case 0:
        k = 1;
        break;
    case 1:
        k = 0;
        break;
    }
    func_021BF764(p, k);
    func_021BF08C(p);
    func_021BE934(p);
    func_021BF15C(p);
    func_021BF264(p);
    func_021BF2FC(p);
    func_021BF38C(p);
    func_021BF3B4(p);
    func_021BF47C(p);
    func_021BEAF8((u8 *)p);
    func_021BEEA4(p);
    func_021BEF98(p);
    if (((struct ResearchObjB *)p)->f3C8 != 0 && func_021BF810(p) != 0) {
        func_021BEF30(p);
        func_021BEFD4(p);
    }
    if (((struct ResearchObjB *)p)->f3C8 != 0 && func_021BF810(p) != 0) {
        if (flag != 0) {
            CircleGraph_HoldUpdate(func_021BF76C(p), 0x14);
        }
        CircleGraph_QueueDrawFast(func_021BF76C(p));
        CircleGraph_SetEnabled(func_021BF76C(p), 1);
    }
    GFL_USE_PlaySeDefaultVolume(0x548);
}

void func_021BE8FC(void)
{
    FADE_Start(3, 0x10, 0, 0);
}

void func_021BE90C(void)
{
    FADE_Start(3, 0, 16, 0);
}

void func_021BE91C(char *p, int a)
{
    ((struct ResearchObjB *)p)->f34s = (((struct ResearchObjB *)p)->f34s + a + 5) % 5;
}

/*
 * Field setter, u32 at +0x34.
 *
 * Addresses are Black-image addresses.
 */
void func_021BE930(void *p, u32 v)
{
    ((struct ResearchObjB *)p)->f34 = v;
}

int func_021BE934(char *p)
{
    switch (((struct ResearchObjB *)p)->f34s) {
    case 0:
    case 2:
    case 3:
        func_020413B0(2, d_021C3AC8[*(int *)(p + 0x34)].a,
                      d_021C3AC8[*(int *)(p + 0x34)].b,
                      d_021C3AC8[*(int *)(p + 0x34)].c,
                      d_021C3AC8[*(int *)(p + 0x34)].d, 0xa);
        break;
    case 1:
        func_020413B0(2, 0xd, 4, 0x13, 4, 0xa);
        func_020413B0(2, 0x10, 8, 0x10, 3, 0xa);
        break;
    case 4:
        func_021BEB6C((u32)p);
        break;
    }
    return func_020409B4(2);
}

void func_021BE9B8(u8 *p)
{
    switch (((struct ResearchObjB *)p)->f34) {
    case 0:
    case 2:
    case 3:
        func_020413B0(2, d_021C3AC8[*(u32 *)(p + 52)].a,
            d_021C3AC8[*(u32 *)(p + 52)].b,
            d_021C3AC8[*(u32 *)(p + 52)].c,
            d_021C3AC8[*(u32 *)(p + 52)].d, 6);
        break;
    case 1:
        func_020413B0(2,13,4,19,4,6);
        func_020413B0(2,16,8,16,3,6);
        break;
    case 4:
        func_021BEB88((u32)p);
        break;
    }
    func_020409B4(2);
}

void func_021BEA3C(char *p, int a)
{
    ((struct ResearchObjB *)p)->f2B8 = (u8)((((struct ResearchObjB *)p)->f2B8 + a + 3) % 3);
}

void func_021BEA54(char *p)
{
    u8 *o = func_021BF76C(p);

    u32 k = func_021BF7CC(p);
    int v = CircleGraph_GetSliceKey(o, 0);
    ((struct ResearchObjB *)p)->f2B9 = GRAPHTABLE_FindEntry((const u8 *)(p + 0x38), (u8)k, (u8)v);
}

/*
 * Prototypes: original loads r0/r1 and reads return at 021C11C8/11D0;
 * narrow argument truncations are explicit in the caller.
 */
void func_021BEA8C(u8 *p, int step)
{
    u8 *object;
    int kind;
    int count;
    int index;
    object = func_021BF76C(p);
    kind = func_021BF7CC(p);
    count = func_021BF7E0(p);
    index = func_021BF7F4(p);
    index = CircleGraph_FindSliceIndex(object, index);

    index = (count + (index + step)) % count;
    index = CircleGraph_GetSliceKey(object, index);
    p[697] = GRAPHTABLE_FindEntry(p + 56, kind, index);
}

void func_021BEAEC(u8 *a0)
{
    ((struct ResearchObjB *)a0)->f2B9 = 0;
}

void func_021BEAF8(u8 *p)
{
    if (((struct ResearchObjB *)p)->f3C8 == 1 || ((struct ResearchObjB *)p)->f3D0 == 1 || func_021BF810(p) == 0) {
        if (func_021BF5D0(p, 5) == 0) func_021BEBE4((u32)p);
    } else {
        if (func_021BF5D0(p, 5) == 1) func_021BEBC0((u32)p);
    }
}

void func_021BEB40(u32 a0)
{
    BMP_OAM_SetPalette((u8 *)(((struct ResearchObjB *)a0)->f3AC), 0);
    func_021BF5BC((u8 *)a0, 5);
    func_021BF5BC((u8 *)a0, 6);
    func_021BF594((char *)a0, 2);
}

void func_021BEB6C(u32 a0)
{
    BMP_OAM_SetPalette((u8 *)(((struct ResearchObjB *)a0)->f3AC), 0);
    func_021BF594((char *)a0, 3);
}

void func_021BEB88(u32 a0)
{
    BMP_OAM_SetPalette((u8 *)(((struct ResearchObjB *)a0)->f3AC), 1);
    func_021BF5BC((u8 *)a0, 3);
}

void func_021BEBA4(u32 a0)
{
    BMP_OAM_SetPalette((u8 *)(((struct ResearchObjB *)a0)->f3AC), 0);
    func_021BF594((char *)a0, 4);
}

void func_021BEBC0(u32 a0)
{
    BMP_OAM_SetPalette((u8 *)(((struct ResearchObjB *)a0)->f3AC), 1);
    func_021BF5BC((u8 *)a0, 5);
    func_021BF594((char *)a0, 6);
}

void func_021BEBE4(u32 a0)
{
    BMP_OAM_SetPalette((u8 *)(((struct ResearchObjB *)a0)->f3AC), 1);
    func_021BF594((char *)a0, 5);
}

void func_021BEC00(u32 *p)
{
    RESEARCH_COMMON_StartPaletteAnime((u8 *)(*p), 0);
}

/*
 * Swap the u32 pairs at +0x2bc and +0x2c4.
 *
 * Addresses are Black-image addresses.
 */
void func_021BEC0C(void *p)
{
    int i;
    for (i = 0; i < 2; i++) {
        u32 t = *(u32 *)((char *)p + i * 4 + 0x2bc);
        *(u32 *)((char *)p + i * 4 + 0x2bc) = *(u32 *)((char *)p + i * 4 + 0x2c4);
        *(u32 *)((char *)p + i * 4 + 0x2c4) = t;
    }
}

void func_021BEC34(u32 a0)
{
    u32 v1 = func_0209C0A4(((struct Item *)a0)->y + 62, 3);
    u32 v2 = func_0209C0A4(((struct Item *)a0)->z + 62, 3);
    ((struct Item *)a0)->a = func_0209C0A4(((struct Item *)a0)->x + 62, 3);
    ((struct Item *)a0)->b = v1;
    ((struct Item *)a0)->c = v2;
}

void func_021BEC64(void *p)
{
    CircleGraph_SetCenterDepth(func_021BF76C(p), 0xFFFFE000);
    CircleGraph_SetCenterDepth(func_021BF77C(p), 0);
}

void func_021BEC84(u8 *p,int mode)
{
    struct Item items[17];
    struct Input *base;
    u32 object;
    int count;
    int i;
    object=*(u32 *)(p+700+mode*4);
    count=func_021BF7E0(p);
    base=(struct Input *)(p+60+p[696]*212);
    for(i=0;i<count;i++) {
        struct Input *q=(struct Input *)((u8 *)base+8+i*12);
        struct Item *t=&items[i];
        t->id=q->id; t->x=q->x; t->y=q->y; t->z=q->z;
        func_021BEC34((u32)t);
        switch(mode) { case 0: t->value=q->a; break; case 1: t->value=q->b; break; }
    }
    CircleGraph_SetSlices((u8 *)object,(u8 *)items,count);
}

void func_021BED10(u8 *p, u32 mode)
{
    struct Item items[17];
    struct Input *base;
    u32 object;
    int count;
    int i;
    object=*(u32 *)(p+708+mode*4);
    count=func_021BF7E0(p);
    base=(struct Input *)(p+60+p[696]*212);
    for(i=0;i<count;i++) {
        struct Input *q=(struct Input *)((u8 *)base+8+i*12);
        struct Item *t=&items[i];
        t->id=q->id; t->x=q->x; t->y=q->y; t->z=q->z;
        func_021BEC34((u32)t);
        switch(mode) { case 0: t->value=q->a; break; case 1: t->value=q->b; break; }
    }
    CircleGraph_SetSlices((u8 *)object,(u8 *)items,count);
}

void func_021BED9C(char *p)
{
    int i;
    for (i = 0; i < 2; i++) {
        CircleGraph_Update(*(u8 **)(p + i * 4 + 0x2bc));
        CircleGraph_Update(*(u8 **)(p + i * 4 + 0x2c4));
    }
}

void func_021BEDC4(char *p)
{
    int i;
    for (i = 0; i < 2; i++) {
        CircleGraph_Draw(*(u8 **)(p + i * 4 + 0x2bc));
        CircleGraph_Draw(*(u8 **)(p + i * 4 + 0x2c4));
    }
}

void func_021BEDEC(char *p)
{
    unsigned r,g,b;
    void *color;
    if (((struct ResearchObjB *)p)->f3C8==0 || ((struct ResearchObjB *)p)->f3D0==1 || func_021BF810(p)==0) return;
    color=p+56;
    r=GRAPHTABLE_GetEntryRed(color,((struct ResearchObjB *)p)->f2B8,((struct ResearchObjB *)p)->f2B9);
    g=GRAPHTABLE_GetEntryGreen(color,((struct ResearchObjB *)p)->f2B8,((struct ResearchObjB *)p)->f2B9);
    b=GRAPHTABLE_GetEntryBlue(color,((struct ResearchObjB *)p)->f2B8,((struct ResearchObjB *)p)->f2B9);
    *(volatile unsigned *)0x040004a4=0x001f00c0;
    *(volatile unsigned *)0x04000500=1;
    *(volatile unsigned *)0x04000480=(u16)(r | (g<<5) | (b<<10));
    *(volatile unsigned *)0x0400048c=0x096cfc68;
    *(volatile unsigned *)0x0400048c=0;
    *(volatile unsigned *)0x0400048c=0x0a7afc68;
    *(volatile unsigned *)0x0400048c=0;
    *(volatile unsigned *)0x0400048c=0x0a7afda1;
    *(volatile unsigned *)0x0400048c=0;
    *(volatile unsigned *)0x0400048c=0x096cfda1;
    *(volatile unsigned *)0x0400048c=0;
    *(volatile unsigned *)0x04000504=0;
}

/*
 * C11DC forwards r0/r1 through C1AC0; caller's narrowed index remains in its prototype.
 * C20CC overwrites incoming r1 with 1 before forwarding to C218C; legacy unused trailing parameter omitted.
 */
void func_021BEEA4(char *p)
{
    u8 *object;
    unsigned index;
    s32 x,y;
    ARROW_Reset(*(unsigned *)&((struct ResearchObjB *)p)->f2D0);
    if (((struct ResearchObjB *)p)->f3D0==1) return;
    if (((struct ResearchObjB *)p)->f3C8==0) return;
    if (func_021BF810(p)==0) return;
    object=func_021BF76C(p);
    index=func_021BF7F4(p);
    if (CircleGraph_GetPercentByKey(object,index)==0) return;
    if (((struct ResearchObjB *)p)->f3C8!=0) {
        object=func_021BF76C(p);
        index=func_021BF7F4(p);
        CircleGraph_GetLabelPositionByKey(object,index,&x,&y);

        ARROW_Layout(*(unsigned *)&((struct ResearchObjB *)p)->f2D0,104,34,x,y);
        ARROW_Start(*(unsigned *)&((struct ResearchObjB *)p)->f2D0);
    }
}

/*
 * lever: unsigned output counter i; initialize before decrementing the signed reverse counter.
 * C11E8 forwards original r0/r1 to C1AB4's two-input record lookup.
 * C271C forwards original r1/r2 to C288C's two-field setter.
 */
void func_021BEF30(char *p)
{
    int n,id;
    unsigned i;
    u8 *object;
    s32 x,y;
    unsigned slot;
    n=func_021BF7E0(p);
    object=func_021BF76C(p);
    i=0;
    n--;
    for (;n>=0;n--) {
        id=CircleGraph_GetPercentByIndex(object,n);
        CircleGraph_GetLabelPositionByIndex(object,n,&x,&y);

        if (id>=10) {
            slot=*(unsigned *)(p+i*4+0x2d4);
            PERCENTAGE_SetValue(slot,id);
            PERCENTAGE_SetPosition(slot,x,y);
            i++;
        }
    }
    ((struct ResearchObjB *)p)->f2FC=i;
}

void func_021BEF98(char *p)
{
    int i;
    u8 z = 0;
    for (i = 0; i < 10; i++) {
        PERCENTAGE_SetVisible(*(u32 *)(p + i * 4 + 0x2d4), z);
    }
    ((struct ResearchObjB *)p)->f2FD = z;
}

/*
 * Tail-call veneer: forwards arg(s) (u32)(*(u32*)(a0 + (a1)*4 + 724)), 1 to PERCENTAGE_SetVisible.
 *
 * Addresses are Black-image addresses.
 */
void func_021BEFC0(u8 *a0, u32 a1)
{
    PERCENTAGE_SetVisible((u32)(*(u32*)(a0 + (a1)*4 + 724)), 1);
}

void func_021BEFD4(char *p)
{
    int i;
    int n;
    n = ((struct ResearchObjB *)p)->f2FC;
    for (i = 0; i < n; i++) {
        func_021BEFC0((u8 *)p, (u8)i);
    }
}

/*
 * lever: pool 021BF088 is 021C3AC8; dropping contested ov217 data hint resolves sole-ref evidence.
 */
void func_021BEFF8(u8 *p)
{
    const struct Row *row;
    u8 *q;
    row=(const struct Row *)&d_021C3AC8[((struct ResearchObjB *)p)->f34];
    q=p+0x2fe;
    q[2]=func_021C0900(row->fields[0]+row->fields[4]-16);
    p[0x2fe]=func_021C0900(row->fields[1]+row->fields[5]-16);
    q[3]=func_021C0900(q[2]+32);
    q[1]=func_021C0900(p[0x2fe]+32);
    row=(const struct Row *)&d_021C3AC8[((struct ResearchObjB *)p)->f34];
    q=p+0x302;
    q[2]=func_021C0900(row->fields[0]+row->fields[6]-16);
    p[0x302]=func_021C0900(row->fields[1]+row->fields[7]-16);
    q[3]=func_021C0900(q[2]+32);
    q[1]=func_021C0900(p[0x302]+32);
}

void func_021BF08C(char *p)
{
    struct ArcFile *arc;
    void *file,*out;
    unsigned id;
    arc=func_020490F4(192,((struct ResearchObjB *)p)->f4);
    if (((struct ResearchObjB *)p)->f3D0!=0) id=8;
    else if (func_021BF810(p)==0) id=6;
    else {
        id=6;
        if (((struct ResearchObjB *)p)->f3C8!=0) id=7;
    }
    file=ARC_TOOL_LoadHandleMember(arc,id,((struct ResearchObjB *)p)->f4);
    func_02062B30(file,&out);
    func_02041090(2,(unsigned)out+12,0,0,32,32);
    func_020409B4(2);
    func_020307B0(file);
    ARC_TOOL_DeleteHandle(arc);
}

/*
 * Tail call through a pool word: bx r3 spends r3 on the target, so only the
 * two argument registers are live (see docs/idioms/a-tail-call-cannot-pass-a-fourth-argument.md).
 *
 * Addresses are Black-image addresses.
 */
void func_021BF100(char *p)
{
    BgTextLabel_PrintMessage(((struct ResearchObjB *)p)->f348, d_021C3628[((struct ResearchObjB *)p)->f38]);
}

void func_021BF11C(char *p)
{
    u32 i = func_021BF7CC(p);
    BgTextLabel_PrintMessage(((struct ResearchObjB *)p)->f34C, d_021C36B8[i]);
}

void func_021BF13C(char *p)
{
    u32 o = ((struct ResearchObjB *)p)->f350;
    u32 i = func_021BF7CC(p);
    BgTextLabel_PrintMessage(o, d_021C369A[i]);
}

void func_021BF15C(char *p)
{
    u32 t = ((struct ResearchObjB *)p)->f354;
    u8 *o = func_021BF76C(p);
    u32 k;
    u32 a, b, c;
    void *x, *y, *z;
    if (((struct ResearchObjB *)p)->f3C8 == 0 || ((struct ResearchObjB *)p)->f3D0 == 1) {
        BgTextLabel_SetVisible((u8 *)t, 0);
        return;
    }
    if (func_021BF810(p) == 0) {
        BgTextLabel_SetVisible((u8 *)t, 0);
        return;
    }
    k = func_021BF7F4(p);
    a = CircleGraph_FindSliceIndex(o, (u8)k);

    b = func_021BF854(p);
    c = CircleGraph_GetPercentByKey(o, (u8)k);
    x = func_02045EC0(((struct ResearchObjB *)p)->fC, 0xd);
    y = func_02045EC0(((struct ResearchObjB *)p)->f14, k);
    z = STRBUF_Create(0x80, ((struct ResearchObjB *)p)->f4);
    func_0201EFA4(((struct ResearchObjB *)p)->f18, 0, a + 1, 2, 1, 1);
    func_0201EE0C(((struct ResearchObjB *)p)->f18, 1, y, 0, 1, 2);
    func_0201EFA4(((struct ResearchObjB *)p)->f18, 2, b, 5, 1, 1);
    func_0201EFA4(((struct ResearchObjB *)p)->f18, 3, c, 3, 1, 1);
    func_0201F250(((struct ResearchObjB *)p)->f18, z, x);
    BgTextLabel_PrintText((u8 *)t, z);
    BgTextLabel_SetVisible((u8 *)t, 1);
    STRBUF_Delete(x);
    STRBUF_Delete(z);
    STRBUF_Delete(y);
}

/*
 * EE0C: original stores sixth argument 2 at sp+4; preserve visibly supplied trailing input.
 */
void func_021BF264(char *p)
{
    unsigned index;
    struct U16Vec *a,*b,*buf;
    if (((struct ResearchObjB *)p)->f3C8==0 || func_021BF810(p)==0) {
        BgTextLabel_SetVisible((u8 *)(((struct ResearchObjB *)p)->f358),0);
        return;
    }
    index=func_021BF910((unsigned char *)p);
    a=func_02045EC0(*(struct MsgBank * *)&((struct ResearchObjB *)p)->fC,14);
    b=func_02045EC0(*(struct MsgBank * *)&((struct ResearchObjB *)p)->f14,index);
    buf=STRBUF_Create(128,((struct ResearchObjB *)p)->f4);
    func_0201EE0C(*(struct WordSet * *)&((struct ResearchObjB *)p)->f18,0,b,0,1,2);
    func_0201F250(*(struct WordSet * *)&((struct ResearchObjB *)p)->f18,buf,a);
    BgTextLabel_SetVisible((u8 *)(((struct ResearchObjB *)p)->f358),1);
    BgTextLabel_PrintText((u8 *)(((struct ResearchObjB *)p)->f358),buf);
    STRBUF_Delete(a);
    STRBUF_Delete(buf);
    STRBUF_Delete(b);
}

void func_021BF2FC(char *p)
{
    u32 k;
    u32 x;
    void *a, *b;
    void *c;
    if (((struct ResearchObjB *)p)->f3C8 != 0) {
        switch (((struct ResearchObjB *)p)->f2CC) {
        case 0:
            k = 0xf;
            break;
        case 1:
            k = 0x11;
            break;
        }
    } else {
        switch (((struct ResearchObjB *)p)->f2CC) {
        case 0:
            k = 0x10;
            break;
        case 1:
            k = 0x12;
            break;
        }
    }
    x = func_021BF810(p);
    c = ((struct ResearchObjB *)p)->f18;
    a = func_02045EC0(((struct ResearchObjB *)p)->fC, k);
    b = STRBUF_Create(0x80, ((struct ResearchObjB *)p)->f4);
    func_0201EFA4(c, 0, x, 6, 1, 1);
    func_0201F250(c, b, a);
    BgTextLabel_PrintText((u8 *)(((struct ResearchObjB *)p)->f35C), b);
    STRBUF_Delete(a);
    STRBUF_Delete(b);
}

void func_021BF38C(char *p)
{
    if (func_021BF810(p) == 0) {
        BgTextLabel_SetVisible((u8 *)(((struct ResearchObjB *)p)->f360), 1);
    } else {
        BgTextLabel_SetVisible((u8 *)(((struct ResearchObjB *)p)->f360), 0);
    }
}

void func_021BF3B4(char *p)
{
    if (((struct ResearchObjB *)p)->f3D0 != 0) {
        BgTextLabel_SetVisible((u8 *)(((struct ResearchObjB *)p)->f364), 1);
    } else {
        BgTextLabel_SetVisible((u8 *)(((struct ResearchObjB *)p)->f364), 0);
    }
}

void func_021BF3D8(char *p)
{
    const struct Row *row;
    struct Obj *a,*b;
    struct Vec2 pos;
    row=(const struct Row *)&d_021C3AC8[((struct ResearchObjB *)p)->f34];
    a=(struct Obj *)func_021BFA08(p,0);
    b=(struct Obj *)func_021BFA08(p,1);
    if (((struct ResearchObjB *)p)->f3D0==1 || ((struct ResearchObjB *)p)->f34==2 || ((struct ResearchObjB *)p)->f34==4) {
        CLACT_SetActorDrawEnable(a,0);
        CLACT_SetActorDrawEnable(b,0);
        return;
    }
    pos.x=row->fields[0]+row->fields[4];
    pos.y=row->fields[1]+row->fields[5];
    CLACT_AddActorSurfacePos(a,&pos,0);
    pos.x=row->fields[0]+row->fields[6];
    pos.y=row->fields[1]+row->fields[7];
    CLACT_AddActorSurfacePos(b,&pos,0);
    CLACT_SetActorDrawEnable(a,1);
    CLACT_SetActorDrawEnable(b,1);
    CLACT_SetActorAutoAnim(a,1);
    CLACT_SetActorAutoAnim(b,1);
}

void func_021BF47C(char *p)
{
    if (((struct ResearchObjB *)p)->f3C8 == 0 || func_021BF810(p) == 0) {
        CLACT_SetActorDrawEnable((struct Obj *)((struct ResearchObjB *)p)->f39C, 0);
    } else {
        CLACT_SetActorDrawEnable((struct Obj *)((struct ResearchObjB *)p)->f39C, 1);
    }
}

void func_021BF4AC(char *p)
{
    struct Obj *obj;
    unsigned index;
    s32 x,y;
    struct Vec2 pos;
    const u16 *table;
    obj=*(struct Obj * *)&((struct ResearchObjB *)p)->f3A0;
    table=d_021C3850;
    if (((struct ResearchObjB *)p)->f3C8==0) { CLACT_SetActorDrawEnable(obj,0); return; }
    if (((struct ResearchObjB *)p)->f34!=2) { CLACT_SetActorDrawEnable(obj,0); return; }
    index=func_021BF910((u8 *)p);
    if (CircleGraph_GetPercentByKey(func_021BF76C(p),index)==0) { CLACT_SetActorDrawEnable(obj,0); return; }
    if (index==0) { CLACT_SetActorDrawEnable(obj,0); return; }
    CircleGraph_GetLabelPositionByKey(func_021BF76C(p),index,&x,&y);

    pos.x=x;
    pos.y=y;
    CLACT_AddActorSurfacePos(obj,&pos,table[12]);
    CLACT_SetActorDrawEnable(obj,1);
    CLACT_SetActorAutoAnim(obj,1);
    CLACT_SetActorAnimLoopCount((struct Actor *)obj,2);
}

void func_021BF55C(void *a0)
{
    func_021BF580((u8 *)a0, 1, 1);
}

/*
 * Tail-call veneer: forwards arg(s) a0, 0, 1 to func_021BF580.
 *
 * Addresses are Black-image addresses.
 */
void func_021BF568(void *a0)
{
    func_021BF580((u8 *)a0, 0, 1);
}

/*
 * Tail-call veneer: forwards arg(s) a0, 0, 0 to func_021BF580.
 *
 * Addresses are Black-image addresses.
 */
void func_021BF574(void *a0)
{
    func_021BF580((u8 *)a0, 0, 0);
}

void func_021BF580(u8 *p, u32 i, u32 j)
{
    BMP_OAM_SetEnabled((u8 *)(*(u32 *)(p + i * 4 + 0x3a8)), j);
}

void func_021BF594(char *p, int i)
{
    PALETTE_ANIME_Start((u8 *)(*(u32 *)(p + i * 4 + 0x324)), d_021C3A34[i].a, d_021C3A34[i].b);
}

/*
 * Tail-call veneer: forwards arg(s) (u32)(*(u32*)(a0 + (a1)*4 + 804)), (u32)(a0 + (a1)*4) to PALETTE_ANIME_Stop.
 *
 * Addresses are Black-image addresses.
 */
void func_021BF5BC(u8 *a0, u32 a1)
{
    PALETTE_ANIME_Stop((u32)(*(u32*)(a0 + (a1)*4 + 804)));
}

/*
 * Tail-call veneer: forwards arg(s) (u32)(*(u32*)(a0 + (a1)*4 + 804)), (u32)(a0 + (a1)*4) to PALETTE_ANIME_IsRunning.
 *
 * Addresses are Black-image addresses.
 */
u32 func_021BF5D0(u8 *a0, u32 a1)
{
    return PALETTE_ANIME_IsRunning((u32)(*(u32*)(a0 + (a1)*4 + 804)), (u32)(a0 + (a1)*4));
}

void func_021BF5E4(int *p)
{
    int i;
    for (i = 0; i < 8; i++)
        PALETTE_ANIME_Update(p[i + 0xC9]);
}

/*
 * Tail-call veneer: forwards arg(s) (u32)(*(u32*)(a0)) to RESEARCH_COMMON_UpdatePaletteAnime.
 *
 * Addresses are Black-image addresses.
 */
void func_021BF600(u8 *a0)
{
    RESEARCH_COMMON_UpdatePaletteAnime((u32)(((struct ResearchObjB *)a0)->f0u));
}

void func_021BF60C(char *p)
{
    PALANM_RequestFade(*(struct PalAnmObj * *)&((struct ResearchObjB *)p)->f3B8,1,0xffff,3,0,7,0xffff,((struct ResearchObjB *)p)->f3BC);
    PALANM_RequestFade(*(struct PalAnmObj * *)&((struct ResearchObjB *)p)->f3B8,4,0xffff,3,0,7,0xffff,((struct ResearchObjB *)p)->f3BC);
}

void func_021BF658(char *p)
{
    PALANM_RequestFade(*(struct PalAnmObj * *)&((struct ResearchObjB *)p)->f3B8,1,0xffff,3,7,0,0xffff,((struct ResearchObjB *)p)->f3BC);
    PALANM_RequestFade(*(struct PalAnmObj * *)&((struct ResearchObjB *)p)->f3B8,4,0xffff,3,7,0,0xffff,((struct ResearchObjB *)p)->f3BC);
}

/*
 * Note: the record's +0x3B8 handle is idle.
 *            witness outside 021BF6A4..021BF6BC.  Bytes are exact and 24/24
 *            match the listing extent; file the TARGET first (OV-BRIEF rule
 *            10) and this promotes to EXACT with no source change.
 *
 * Addresses are Black-image addresses.
 */
u32 func_021BF6A4(u8 *a0)
{
    if (PALANM_GetFadeRequestBits((const char *)(((struct ResearchObjB *)a0)->f3B8)) == 0) {
    return 1;
    }
    return 0;
}

u32 func_021BF6BC(u32 a0, u32 a1)
{
    func_020419E4();
    CLACT_VBlankSystem();
    return PALANM_TransferPalettes((struct S02021D50 *)((struct ResearchObjB *)a1)->f3B8);
}

void func_021BF6D4(char *p)
{
    if (GAME_BEACON_PopQuestionnaireUpdated() == 1) {
        u16 a = func_021BF834(p);
        if (a != (u16)(u32)func_021BF9CC((u32)p)) {
            ((struct ResearchObjB *)p)->f3D8 = 1;
        }
    }
}

/*
 * Clear the u32 at +0x3d8.
 *
 * Addresses are Black-image addresses.
 */
void func_021BF704(void *p)
{
    ((struct ResearchObjB *)p)->f3D8 = 0;
}

void func_021BF710(void *p)
{
    if (((struct ResearchObjB *)p)->f30 < 0xf0) {
        ((struct ResearchObjB *)p)->f30 += 1;
    } else {
        ((struct ResearchObjB *)p)->f3D4 = 1;
    }
}

void func_021BF728(void *p)
{
    ((struct ResearchObjB *)p)->f30 = 0;
    ((struct ResearchObjB *)p)->f3D4 = 0;
}

u32 func_021BF734(u8 *a0)
{
    return RESEARCH_COMMON_GetContext((u32 *)(((struct Obj25933 *)a0)->f0));
}

/*
 * Tail-call veneer: forwards arg(s) (u32)(*(u32*)(a0)) to RESEARCH_COMMON_GetAppResource.
 *
 * Addresses are Black-image addresses.
 */
u32 func_021BF740(u8 *a0)
{
    return RESEARCH_COMMON_GetAppResource((void *)(((struct ResearchObjB *)a0)->f0u));
}

void func_021BF74C(void *p, u32 v)
{
    ((struct ResearchObjB *)p)->f4 = v;
}

/*
 * Field getter, u32 at +0.
 *
 * Addresses are Black-image addresses.
 */
u32 func_021BF750(void *p)
{
    return ((struct ResearchObjB *)p)->f0u;
}

void func_021BF754(void *p, u32 v)
{
    ((struct ResearchObjB *)p)->f0u = v;
}

u32 func_021BF758(void *p)
{
    return RESEARCH_COMMON_GetInputFlag((void *)func_021BF750(p));
}

/*
 * Field setter, u32 at +0x2cc.
 *
 * Addresses are Black-image addresses.
 */
void func_021BF764(void *p, u32 v)
{
    ((struct ResearchObjB *)p)->f2CC = v;
}

u8 *func_021BF76C(void *p)
{
    u32 i = ((struct ResearchObjB *)p)->f2CC;
    return *(u8 **)((char *)p + i * 4 + 0x2bc);

}

u8 *func_021BF77C(void *p)
{
    u32 i = ((struct ResearchObjB *)p)->f2CC;
    return *(u8 **)((char *)p + i * 4 + 0x2c4);

}

u32 func_021BF78C(u32 a0)
{
    if (CircleGraph_IsAnimating(*(u8 * *)&((struct ResearchObjB *)a0)->f2BC) != 0 || CircleGraph_IsAnimating(*(u8 * *)&((struct ResearchObjB *)a0)->f2C0) != 0 || CircleGraph_IsAnimating(*(u8 * *)&((struct ResearchObjB *)a0)->f2C4) != 0 || CircleGraph_IsAnimating(*(u8 * *)&((struct ResearchObjB *)a0)->f2C8) != 0) {
    return 0;
    }
    return 1;
}

u32 func_021BF7CC(void *p)
{
    u32 i = ((struct ResearchObjB *)p)->f2B8;
    return *(u8 *)((char *)p + i * 0xd4 + 0x3c);
}

u32 func_021BF7E0(void *p)
{
    u32 i = ((struct ResearchObjB *)p)->f2B8;
    return *(u8 *)((char *)p + i * 0xd4 + 0x3d);
}

/*
 * Element field: u16 at +0x44 of a 12-byte sub-record of record 0xd4.
 *
 * Addresses are Black-image addresses.
 */
u32 func_021BF7F4(void *p)
{
    u32 i = ((u8 *)p)[0x2b8];
    u32 j = ((u8 *)p)[0x2b9];
    return *(u16 *)((char *)p + 0x44 + i * 0xd4 + j * 0xc);
}

u32 func_021BF810(void *p)
{
    u32 r = 0;
    switch (((struct ResearchObjB *)p)->f2CC) {
    case 0:
        r = func_021BF834(p);
        break;
    case 1:
        r = func_021BF844(p);
        break;
    }
    return r;
}

/*
 * Element field: u16 at +0x3e of record 0xd4 bytes, selected by the u8 at +0x2b8.
 *
 * Addresses are Black-image addresses.
 */
u32 func_021BF834(void *p)
{
    u32 i = ((struct ResearchObjB *)p)->f2B8;
    return *(u16 *)((char *)p + i * 0xd4 + 0x3e);
}

u32 func_021BF844(void *p)
{
    u32 i = ((struct ResearchObjB *)p)->f2B8;
    return *(u32 *)((char *)p + i * 0xd4 + 0x40);
}

u32 func_021BF854(char *p)
{
    switch (((struct ResearchObjB *)p)->f2CC) {
    case 0:
        return func_021BF878(p);
    case 1:
        return func_021BF894(p);
    }
    return 0;
}

/*
 * Element field: u16 at +0x4a of a 12-byte sub-record of record 0xd4.
 *
 * Addresses are Black-image addresses.
 */
u32 func_021BF878(void *p)
{
    u32 i = ((u8 *)p)[0x2b8];
    u32 j = ((u8 *)p)[0x2b9];
    return *(u16 *)((char *)p + 0x4a + i * 0xd4 + j * 0xc);
}

/*
 * Element field: u32 at +0x4c of a 12-byte sub-record of record 0xd4.
 *
 * Addresses are Black-image addresses.
 */
u32 func_021BF894(void *p)
{
    u32 i = ((u8 *)p)[0x2b8];
    u32 j = ((u8 *)p)[0x2b9];
    return *(u32 *)((char *)p + 0x4c + i * 0xd4 + j * 0xc);
}

/*
 * lever: pointer-typed lookup base keeps the original r4/r5 allocation; E44C full body reads only r0/r1 and forwards neither legacy trailing input.
 * F740 tail-forwards to C09B4's pointer getter; E394 tail-forwards to 071CC's returned save block.
 * E44C's full body reads only r0/r1 and has no forwarding calls; legacy two trailing inputs omitted.
 */
u8 func_021BF8B0(u8 *p)
{
    u8 bytes[3];
    u8 a,b,c,j;
    void *base;
    int i;
    base=func_0200E394(GAME_DATA_GetSaveControl((struct Big *)func_021BF740(p)));
    for (i=0;i<3;i++) bytes[i]=func_0200E44C((int)base,i);
    b=bytes[1];
    c=bytes[2];
    a=bytes[0];
    for (j=0;j<10;j++) {
        if (a==d_021C363C[j] && b==d_021C3646[j] && c==d_021C3632[j]) return j;
    }
    return 0;
}

u32 func_021BF910(u8 *p)
{
    void *bits;
    u32 index;
    u16 n;
    bits = func_0200E3A0(func_0200E394(GAME_DATA_GetSaveControl((struct Big *)func_021BF740(p))));
    index = func_021BF7CC(p);
    if (index == 29) return func_021BF968(p);
    n = func_0200E3A4((const u8 *)bits, index);
    if (n == 0) return 0;
    n--;
    return (u8)GRAPHTABLE_GetEntryId(p + 0x38, p[0x2b8], n);
}

/*
 * extent: trailing 00 00 at 021BF9CA is two-byte alignment padding.
 * prototype: 02012FCC legacy trailing arguments omitted: full 12-byte body only reads r0, then returns its field at 0x6ac; no forwarding.
 * prototype: full 02012FCC body only reads r0, does not forward r1-r3; legacy trailing inputs omitted.
 */
u32 func_021BF968(u8 *p)
{
    u32 v = func_0200864C((const struct PlayTime *)GAME_DATA_GetPlayTime(func_021BF740(p)));
    if (v < 10) return 135;
    if (v < 20) return 136;
    if (v < 30) return 137;
    if (v < 40) return 138;
    if (v < 50) return 139;
    if (v < 60) return 140;
    if (v < 70) return 141;
    if (v < 80) return 142;
    if (v < 90) return 143;
    if (v < 100) return 144;
    return 145;
}

/*
 * Reconstructed from the listing.
 *
 * BLOCKED at MATCH: the relocation site(s) below have no independent witness.
 *   +001C THM_CALL func_0200E458       -> unresolved: 0200E458 (arm, from name) has no witness outside 021BF9CC..021BF9EE
 * Promote automatically when the target is matched.
 *
 * Addresses are Black-image addresses.
 */
u16 func_021BF9CC(u32 a0)
{
    return func_0200E458((const u16 *)func_0200E394(GAME_DATA_GetSaveControl((struct Big *)func_021BF740((u8 *)a0))), func_021BF7CC((void *)a0));
}

u32 func_021BF9F0(void *p, u32 i)
{
    return *(u32 *)((char *)p + i * 4 + 0x368);
}

u32 func_021BF9FC(void *p, u32 i)
{
    return *(u32 *)((char *)p + i * 4 + 0x384);
}

u32 func_021BFA08(void *p, u32 i)
{
    return *(u32 *)((char *)p + i * 4 + 0x394);
}

u32 func_021BFA14(u32 a0)
{
    return (u32)func_02030734(a0, 1000, 0, (const char *)0x21C400C, 4096);
}

void func_021BFA30(char *p)
{
    int i;
    ((struct ResearchObjB *)p)->f20 = 0;
    ((struct ResearchObjB *)p)->f24 = 0;
    ((struct ResearchObjB *)p)->f3DC = 0;
    ((struct ResearchObjB *)p)->f2C = 0xf;
    ((struct ResearchObjB *)p)->f28 = 0;
    ((struct ResearchObjB *)p)->f30 = 0;
    ((struct ResearchObjB *)p)->f34 = 0;
    ((struct ResearchObjB *)p)->f3C4 = 0;
    ((struct ResearchObjB *)p)->f3C8 = 0;
    ((struct ResearchObjB *)p)->f3CC = 0;
    ((struct ResearchObjB *)p)->f3D0 = 0;
    ((struct ResearchObjB *)p)->f3D4 = 0;
    ((struct ResearchObjB *)p)->f3D8 = 0;
    ((struct ResearchObjB *)p)->f2B8 = 0;
    ((struct ResearchObjB *)p)->f2B9 = 0;
    ((struct ResearchObjB *)p)->f2CC = 0;
    ((struct ResearchObjB *)p)->f3BCu = func_020056BC();
    ((struct ResearchObjB *)p)->f2FC = 0;
    ((struct ResearchObjB *)p)->f2FD = 0;
    ((struct ResearchObjB *)p)->f3E4 = 0;
    ((struct ResearchObjB *)p)->f3E0 = 0;
    for (i = 0; i < 7; i++) {
        *(u32 *)(p + i * 4 + 0x368) = 0;
    }
    func_021BFC50((u8 *)p);
    func_021BFB0C(p);
    func_021BFBDC(p);
    func_021BFE80(p);
    func_021BFEE4(p);
    func_021BFB60(p);
    func_021BFBB8(p);
    func_021BFB30(p);
    func_021C019C(p);
    func_021C0384(p);
    func_021C03EC(p);
    func_021C04B0(p);
    func_021C07B0(p);
    func_021C0820(p);
}

u32 func_021BFB04(void *a0)
{
    return func_020307B0(a0);
}

/*
 * Clear the u32 at +0x1c.
 *
 * Addresses are Black-image addresses.
 */
void func_021BFB0C(void *p)
{
    ((struct ResearchObjB *)p)->f1C = 0;
}

void func_021BFB14(u32 a0)
{
    ((struct ResearchObjB *)a0)->f1C = RingQueue_Create(10, ((struct ResearchObjB *)a0)->f4);
}

void func_021BFB24(u8 *a0)
{
    RingQueue_Destroy((void *)((u32)(((struct Obj25949 *)a0)->f1C)));
}

/*
 * Clear the u32 at +8.
 *
 * Addresses are Black-image addresses.
 */
void func_021BFB30(void *p)
{
    ((struct ResearchObjB *)p)->f8 = 0;
}

void func_021BFB38(u32 a0)
{
    u8 s[4];
    ((struct ResearchObjB *)a0)->f8 = (u32)GF_FONT_Create(23, 0, 0, 0, (u32)(((struct ResearchObjB *)a0)->f4));
}

/*
 * Tail-call veneer: forwards arg(s) (u32)(*(u32*)(a0 + 8)) to GF_FONT_Delete.
 *
 * Addresses are Black-image addresses.
 */
void func_021BFB54(u8 *a0)
{
    GF_FONT_Delete((void *)((u32)(((struct ResearchObjB *)a0)->f8)));
}

/*
 * Clear three u32 slots at +0xc.
 *
 * Addresses are Black-image addresses.
 */
void func_021BFB60(void *p)
{
    int i;
    for (i = 0; i < 3; i++)
        *(u32 *)((char *)p + i * 4 + 0xc) = 0;
}

void func_021BFB74(W *p)
{
    int i;
    for (i = 0; i < 3; i++) {
        p->obj[i] = (u32)func_02045B38(0, 2, (u16)d_021C3650[i], (u16)p->h);
    }
}

void func_021BFBA0(int *p)
{
    int i;
    for (i = 0; i < 3; i++)
        MSGDATA_Delete((struct Rec *)p[i + 3]);
}

void func_021BFBB8(void *p)
{
    ((struct ResearchObjB *)p)->f18 = 0;
}

void func_021BFBC0(u32 a0)
{
    ((struct ResearchObjB *)a0)->f18 = (void *)func_0201EC64(((struct ResearchObjB *)a0)->f4);
}

void func_021BFBD0(u8 *a0)
{
    func_0201ED04((struct WordSet *)((u32)(((struct ResearchObjB *)a0)->f18)));
}

/*
 * Clear two pairs of u32 slots at +0x2bc and +0x2c4.
 *
 * Addresses are Black-image addresses.
 */
void func_021BFBDC(void *p)
{
    int i;
    for (i = 0; i < 2; i++) {
        *(u32 *)((char *)p + i * 4 + 0x2bc) = 0;
        *(u32 *)((char *)p + i * 4 + 0x2c4) = 0;
    }
}

void func_021BFBFC(char *p)
{
    int i;
    for (i = 0; i < 2; i++) {
        *(u32 *)(p + i * 4 + 0x2bc) = CircleGraph_Create(((struct ResearchObjB *)p)->f4);
        *(u32 *)(p + i * 4 + 0x2c4) = CircleGraph_Create(((struct ResearchObjB *)p)->f4);
    }
}

void func_021BFC28(char *p)
{
    int i;
    for (i = 0; i < 2; i++) {
        CircleGraph_Destroy((void *)(*(u32 *)(p + i * 4 + 0x2bc)));
        CircleGraph_Destroy((void *)(*(u32 *)(p + i * 4 + 0x2c4)));
    }
}

/*
 * Tail-call veneer: forwards arg(s) (u32)(a0 + 56), 0, 640 to MI_CpuFill8.
 *
 * Addresses are Black-image addresses.
 */
void func_021BFC50(u8 *a0)
{
    MI_CpuFill8((u32)(a0 + 56), 0, 640);
}

/*
 * blocker (2026-10-02, lane04 wC1): 203 bytes differ, relocations all resolve.
 * Locals now laid out like the original (sh, A, B, va, vb, buf declaration
 * order gives the right stack slots). Left: the original keeps the first
 * loop counter in memory (sp+0x20) and addresses buf+3 as reg+reg, has one
 * more spill word (frame sub sp 0x4c vs 0x48), first byte in sp+0x1c, and
 * spills grp[1] to sp+8. Opus lane to finish.
 *
 * Addresses are Black-image addresses.
 *
 * Note 2026-10-04 (wD2 lane04): n, i, first now sit in the original slots (declare `int n` before
 * `i`, then `first`; 195 bytes differ). Left: the u8 c1 spill (original sp+8, the last slot, below the four
 * loop pointer temps at 0x18..0xc; here 0x18), k lives in memory (sp+4), and buf+3 is formed as
 * `add r1,sp,#0x28; adds r1,#3` then reg+reg (here folded to [r0,#3]); a two-array struct
 * {u8 a[3]; u8 b[3]} did not change that.
 * Note 2026-10-05 (wD4 lane12): MATCH, all 480 bytes. Keys: buf is two
 * separate u8 arrays grp[3] (declared first, lands at sp+0x2B) and cnt[3]
 * (sp+0x28), which gives the `add sp,#0x28; adds #3` reg+reg form; no c0/c1/c2
 * locals (grp[x] re-read, the compiler CSE temp takes the sp+8 slot below the
 * loop temps); no `a` local for va[k]; `s = sh[k][j]` before `r = q + j*12`.
 * Only blocker: arm9 callee 0x0200E47C had no label. Filed it as
 * src/matched/arm9/func_0200E47C.c (EXACT, 10 bytes); this goes EXACT once
 * that file has a shard (integrator).
 * Note 2026-10-04 (wD1 lane06): Not retried (203 bytes, stack slot order only). No new finding.
 */
void func_021BFC60(char *p)
{
    u16 sh[3][17];
    u32 A[3][17];
    u32 B[3][17];
    u32 va[3];
    u32 vb[3];
    u8 grp[3];
    u8 cnt[3];
    int n;
    int i, j, k;
    void *h;
    u8 first;
    h = func_0200E394(GAME_DATA_GetSaveControl((struct Big *)func_021BF740((u8 *)p)));
    first = func_021BF8B0((u8 *)p);
    i = 0;
    grp[0] = func_0200E44C((int)h, 0);
    grp[1] = func_0200E44C((int)h, 1);
    grp[2] = func_0200E44C((int)h, 2);
    cnt[0] = d_021C367C[grp[0]];
    cnt[1] = d_021C367C[grp[1]];
    cnt[2] = d_021C367C[grp[2]];
    va[0] = func_0200E458(h, grp[0]);
    va[1] = func_0200E458(h, grp[1]);
    va[2] = func_0200E458(h, grp[2]);
    vb[0] = func_0200E47C(h, grp[0]);
    vb[1] = func_0200E47C(h, grp[1]);
    vb[2] = func_0200E47C(h, grp[2]);
    for (i = 0; i < 3; i++) {
        u8 g = grp[i];
        n = cnt[i];
        for (j = 0; j < n; j++) {
            sh[i][j] = d_021C3D44[g][j];
            A[i][j] = func_0200E4B0(h, g, j + 1);
            B[i][j] = func_0200E4F8((int)h, g, j + 1);
        }
    }
    *(u8 *)(p + 0x38) = first;
    for (k = 0; k < 3; k++) {
        char *q = p + k * 0xd4;
        *(u8 *)(q + 0x3c) = grp[k];
        *(u8 *)(q + 0x3d) = cnt[k];
        *(u16 *)(q + 0x3e) = va[k];
        *(u32 *)(q + 0x40) = va[k] + vb[k];
        if (*(u32 *)(q + 0x40) > 999999) {
            *(u32 *)(q + 0x40) = 999999;
        }
        for (j = 0; j < 17; j++) {
            u16 s = sh[k][j];
            char *r = q + j * 12;
            u32 x;
            *(u16 *)(r + 0x44) = s;
            *(u8 *)(r + 0x46) = ((u8 *)&d_021C386C)[s];
            *(u8 *)(r + 0x47) = d_021C3900[s];
            *(u8 *)(r + 0x48) = d_021C3994[s];
            x = A[k][j];
            *(u16 *)(r + 0x4a) = x;
            *(u32 *)(r + 0x4c) = x + B[k][j];
        }
    }
}

void func_021BFE40(u8 *p)
{
    int i;
    for (i = 0; i < 9; i++) {
        p[i * 4 + 0x300] = d_021C3758[i].a;
        p[i * 4 + 0x301] = d_021C3758[i].b;
        p[i * 4 + 0x2fe] = d_021C3758[i].c;
        p[i * 4 + 0x2ff] = d_021C3758[i].d;
    }
}

/*
 * Clear the u32 at +0x2d0.
 *
 * Addresses are Black-image addresses.
 */
void func_021BFE80(void *p)
{
    ((struct ResearchObjB *)p)->f2D0 = 0;
}

void func_021BFE8C(char *p)
{
    struct Params_021BFE8C args;
    args.handles[0] = func_021BF9F0(p, 0);
    args.handles[1] = func_021BF9F0(p, 1);
    args.handles[2] = func_021BF9F0(p, 2);
    args.a = 0;
    args.b = 0;
    args.c = 1;
    args.d = 2;
    args.e = 3;
    ((struct ResearchObjB *)p)->f2D0 = (void *)ARROW_Create(((struct ResearchObjB *)p)->f4, (u32)&args);
}

/*
 * Tail-call veneer: forwards arg(s) (u32)(*(u32*)(a0 + 720)), 720 to ARROW_Destroy.
 *
 * Addresses are Black-image addresses.
 */
void func_021BFED4(u8 *a0)
{
    ARROW_Destroy((void *)(((struct ResearchObjB *)a0)->f2D0));
}

/*
 * Clear ten u32 slots at +0x2d4.
 *
 * Addresses are Black-image addresses.
 */
void func_021BFEE4(void *p)
{
    int i;
    for (i = 0; i < 10; i++)
        *(u32 *)((char *)p + i * 4 + 0x2d4) = 0;
}

/*
 * lever: p + i * 4 + 0x2d4 keeps the indexed base before the call; p + 0x2d4 + i * 4 differed by 23 bytes.
 */
void func_021BFF00(char *p)
{
    struct Params_021BFF00 args;
    int i;
    args.handles[0] = func_021BF9F0(p, 0);
    args.handles[1] = func_021BF9F0(p, 1);
    args.handles[2] = func_021BF9F0(p, 2);
    args.a = 0;
    args.b = 12;
    args.c = 13;
    for (i = 0; i < 10; i++) {
        *(u32 *)(p + i * 4 + 0x2d4) = PERCENTAGE_Create(((struct ResearchObjB *)p)->f4, (u32)&args, func_021BF9FC(p, 3));
        PERCENTAGE_SetVisible(*(u32 *)(p + i * 4 + 0x2d4), 0);
    }
}

void func_021BFF5C(int *p)
{
    int i;
    for (i = 0; i < 10; i++)
        PERCENTAGE_Destroy((void *)p[i + 0xB5]);
}

/*
 * prototype: 0207DCF8 full body fixes r1/r2 and forwards only entry r0 to 02082A60; full target overwrites entry r3 and reads no stack arguments.
 * data: pool 021BFFC4 contains 5c 36 1c 02; contested ov217 hint removed per canonical rule, data a4 resolves sole-ref.
 * volatile: hardware stores 021BFF88/8C/90/94; 04000060 re-read at 021BFF96 and 021BFFA4.
 */
void func_021BFF78(void)
{
    func_0207D988();
    func_0207DB1C();
    *(volatile u32 *)0x04000440 = 0;
    *(volatile u32 *)0x04000454 = 0;
    *(volatile u32 *)0x04000440 = 2;
    *(volatile u32 *)0x04000454 = 0;
    *(volatile u16 *)0x04000060 = (*(volatile u16 *)0x04000060 & ~0x3000) | 0x10;
    *(volatile u16 *)0x04000060 = (*(volatile u16 *)0x04000060 & ~0x3000) | 0x20;
    func_0207DCF8(d_021C365C);
}

struct DispConfig { u32 a,b,c,d; };

struct BgTemplate { u32 a,b,c,d; unsigned char e,f,g,h; u32 i; unsigned char j,k,l,m; u32 n; };

struct Config { u8 a,b,c,d,e,f,g,h,i,j,k; u32 extra; };

struct Entry_021BFFC8 { u8 a,b,c,d,e,f,g,h,i,j,k; u32 index, mode, extra; };

struct Entry_021C03D0 { s16 x,y,z; u8 a,b; u32 c,d,e,f; u16 g,pad; };

struct EntryUnit { int x,y,z,bank,index,px,py; u8 r,g,b,pad2; u32 arc,member,enabled; };

extern void func_0203FC28(struct DispConfig *);

extern void func_0204044C(u32);

extern void func_0203FCA0(u32, const struct BgTemplate *, u32);

extern void sub_02040588(unsigned char which, unsigned char enable);

extern void func_0207D63C(u32 *, u32, u32, int, int);

extern u32 func_020403F4();

extern void CLACT_ReleasePalette(u32 i);

extern struct Obj *CLACT_CreateActor(void *owner, unsigned int i, unsigned int j, unsigned int k, const void *position, unsigned short space, unsigned short heap);

extern void BMP_Delete(struct Obj020437AC *);

extern struct DispConfig d_021C366C;

extern const struct BgTemplate d_021C36D8,d_021C36F8,d_021C3718,d_021C3738;

extern const struct Entry_021BFFC8 d_021C3B7C[];

extern const u16 d_021C3620[];

extern const u8 d_021C3618[];

extern const struct Entry_021C03D0 d_021C37FC[];

extern const struct EntryUnit d_021C37A4[];

/*
 * data: pool 021C0068 contains 6c 36 1c 02; contested ov217 hint removed per canonical rule, data a4 resolves sole-ref.
 */
void func_021BFFC8(char *p)
{
    func_0203FC28(&d_021C366C);
    func_0204044C(2);
    func_0203FCA0(6, &d_021C36D8, 0);
    func_0203FCA0(7, &d_021C3738, 0);
    func_0203FCA0(2, &d_021C36F8, 0);
    func_0203FCA0(3, &d_021C3718, 0);
    sub_02040588(4, 1);
    sub_02040588(5, 1);
    sub_02040588(6, 1);
    sub_02040588(7, 1);
    sub_02040588(0, 1);
    sub_02040588(1, 1);
    sub_02040588(2, 1);
    sub_02040588(3, 1);
    func_0207D63C((u32 *)0x04001050, 2, 1, 7, 15);
    func_0207D63C((u32 *)0x04000050, 4, 2, 16, 5);
    BMP_WIN_Init(((struct Obj25959 *)p)->f4);
}

/*
 * Reconstructed from the listing (.inst decoded).
 *
 * Addresses are Black-image addresses.
 */
u32 func_021C0084()
{
    BMP_WIN_Exit();
    func_020403F4(0);
    func_020403F4(3);
    func_020403F4(2);
    func_020403F4(7);
    return func_020403F4(6);
}

void func_021C00AC(char *p)
{
    void *out;
    void *h;
    void *blob;
    h = func_020490F4(192, ((struct Obj14748 *)p)->f4);
    blob = ARC_TOOL_LoadHandleMember((struct ArcFile *)h, 13, ((struct Obj14748 *)p)->f4);
    func_02062B30(blob, &out);
    func_02041090(6, (u32)((char *)out + 12), 0, 0, 32, 24);
    func_020409B4(6);
    func_020307B0((void *)((u32)blob));
    ARC_TOOL_DeleteHandle(h);
}

/*
 * Empty stub.
 *
 * Addresses are Black-image addresses.
 */
void func_021C00F8()
{
}

u32 func_021C00FC()
{
    func_02040C14(7, 0, 1, 0);
    return func_020414EC(7);
}

/*
 * Tail-call veneer: forwards arg(s) 7, 1, 0 to func_02040DA8.
 *
 * Addresses are Black-image addresses.
 */
void func_021C0114()
{
    func_02040DA8(7, 1, 0);
}

/*
 * extent: trailing 00 00 at 021C016E is two-byte alignment padding.
 */
void func_021C0124(char *p)
{
    void *out;
    void *h;
    void *blob;
    h = func_020490F4(192, ((struct Obj14749 *)p)->f4);
    blob = ARC_TOOL_LoadHandleMember((struct ArcFile *)h, 7, ((struct Obj14749 *)p)->f4);
    func_02062B30(blob, &out);
    func_02041090(2, (u32)((char *)out + 12), 0, 0, 32, 32);
    func_020409B4(2);
    func_020307B0((void *)((u32)blob));
    ARC_TOOL_DeleteHandle(h);
}

void func_021C0170()
{
}

u32 func_021C0174()
{
    func_02040C14(3, 0, 1, 0);
    return func_020414EC(3);
}

/*
 * Tail-call veneer: forwards arg(s) 3, 1, 0 to func_02040DA8.
 *
 * Addresses are Black-image addresses.
 */
void func_021C018C(u32 a0, u32 a1, u32 a2)
{
    func_02040DA8(3, 1, 0);
}

/*
 * Clear nine u32 slots at +0x344.
 *
 * Addresses are Black-image addresses.
 */
void func_021C019C(void *p)
{
    int i;
    for (i = 0; i < 9; i++)
        *(u32 *)((char *)p + i * 4 + 0x344) = 0;
}

/*
 * lever: direct indexed assignment computes and spills the destination before allocation; a handle temporary first gave 116 bytes and 47 differing bytes.
 * prototype: keep caller's visible second argument to 021C0F5C despite its legacy one-argument source (021C021C loads r1 before call).
 */
void func_021C01B8(char *p)
{
    struct Config args;
    int i;
    for (i = 0; i < 9; i++) {
        u32 handle;
        args.a = d_021C3B7C[i].a;
        args.b = d_021C3B7C[i].b;
        args.c = d_021C3B7C[i].c;
        args.d = d_021C3B7C[i].d;
        args.e = d_021C3B7C[i].e;
        args.f = d_021C3B7C[i].f;
        args.g = d_021C3B7C[i].g;
        args.h = d_021C3B7C[i].h;
        args.i = d_021C3B7C[i].i;
        args.j = d_021C3B7C[i].j;
        args.k = d_021C3B7C[i].k;
        args.extra = d_021C3B7C[i].extra;
        *(u32 *)(p + i * 4 + 0x344) = (u32)BgTextLabel_Create(&args, ((struct Obj14750 *)p)->f8, *(u32 *)(p + d_021C3B7C[i].index * 4 + 12), ((struct Obj14750 *)p)->f4);
        handle = *(u32 *)(p + i * 4 + 0x344);
        BgTextLabel_PrintMessage(handle, d_021C3B7C[i].mode);
    }
}

/*
 * Addresses are Black-image addresses.
 */
void func_021C0230(int *p)
{
    int i;
    for (i = 0; i < 9; i++) {
        BgTextLabel_Destroy((u8 *)p[i + 0xD1]);
        p[i + 0xD1] = 0;
    }
}

void func_021C0250(char *p)
{
    u16 heap = ((struct Obj08438 *)p)->f4;
    void *h = func_020490F4(192, heap);
    int a = CLACT_RegisterCharacter((void *)((u32)h), 15, 0, 1, heap);
    int b = CLACT_RegisterPalette((void *)h, 16, 1, 0, heap);
    int c = CLACT_RegisterCellAnim((void *)((u32)h), 14, 17, heap);
    ((struct Obj08438 *)p)->f378 = a;
    ((struct Obj08438 *)p)->f37C = b;
    ((struct Obj08438 *)p)->f380 = c;
    ARC_TOOL_DeleteHandle(h);
}

u32 func_021C02A8(u32 a0)
{
    CLACT_ReleaseCharacter(((struct Obj10960 *)(((u8*)a0)))->f378);
    CLACT_ReleasePalette(((struct Obj10960 *)(((u8*)a0)))->f37C);
    return CLACT_ReleaseCellAnim(((struct Obj10960 *)(((u8*)a0)))->f380);
}

void func_021C02C8(char *p)
{
    u16 heap = ((struct Obj06713 *)p)->f4;
    void *h = func_020490F4(192, heap);
    int a = CLACT_RegisterCharacter((void *)((u32)h), 15, 0, 0, heap);
    int b = CLACT_RegisterPaletteEx((void *)((u32)h), 16, 0, 192, 0, 3, heap);
    int c = CLACT_RegisterCellAnim((void *)((u32)h), 14, 17, heap);
    int d;
    ARC_TOOL_DeleteHandle(h);
    h = func_020490F4(83, heap);
    d = CLACT_RegisterPaletteEx((void *)((u32)h), 31, 0, 128, 0, 2, heap);
    ARC_TOOL_DeleteHandle(h);
    ((struct Obj06713 *)p)->f368 = a;
    ((struct Obj06713 *)p)->f36C = b;
    ((struct Obj06713 *)p)->f374 = d;
    ((struct Obj06713 *)p)->f370 = c;
}

u32 func_021C0358(u32 a0)
{
    CLACT_ReleaseCharacter(((struct Obj08439 *)(((u8*)a0)))->f368);
    CLACT_ReleasePalette(((struct Obj08439 *)(((u8*)a0)))->f36C);
    CLACT_ReleasePalette(((struct Obj08439 *)(((u8*)a0)))->f374);
    return CLACT_ReleaseCellAnim(((struct Obj08439 *)(((u8*)a0)))->f370);
}

void func_021C0384(void *p)
{
    int i;
    for (i = 0; i < 4; i++)
        *(u32 *)((char *)p + i * 4 + 0x384) = 0;
}

void func_021C03A0(u8 *p)
{
    int i;
    for (i = 0; i < 4; i++)
        *(int *)(p + i * 4 + 0x384) = (int)CLACT_CreateUnit(d_021C3620[i], d_021C3618[i], ((struct Obj25960 *)p)->f4);
}

void func_021C03D0(int *p)
{
    int i;
    for (i = 0; i < 4; i++)
        CLACT_DeleteUnit((struct Bank *)p[i + 0xE1]);
}

/*
 * Clear four u32 slots at +0x394.
 *
 * Addresses are Black-image addresses.
 */
void func_021C03EC(void *p)
{
    int i;
    for (i = 0; i < 4; i++)
        *(u32 *)((char *)p + i * 4 + 0x394) = 0;
}

/*
 * prototype: 0204B294 result observed in r0 despite legacy matched void return.
 */
void func_021C0408(u8 *p)
{
    struct Arg arg;
    const struct Entry_021C03D0 *q;
    u8 *dest;
    int i;
    u32 a,b,c,d;
    for(i=0;i<4;i++) {
        q=&d_021C37FC[i];
        arg.x=q->x; arg.y=q->y; arg.z=q->z; arg.a=q->a; arg.b=q->b;
        a=func_021BF9FC(p,q->c);
        b=func_021BF9F0(p,q->d);
        c=func_021BF9F0(p,q->e);
        d=func_021BF9F0(p,q->f);
        dest=p+i*4;
        *(u32 *)&((struct Obj14752 *)dest)->f394=(u32)CLACT_CreateActor((void *)a,b,c,d,&arg,q->g,((struct Obj25962 *)p)->f4);
        CLACT_SetActorDrawEnable(*(struct Obj * *)&((struct Obj14752 *)dest)->f394,0);
    }
}

void func_021C0494(int *p)
{
    int i;
    for (i = 0; i < 4; i++)
        CLACT_DeleteActor((struct Obj *)p[i + 0xE5]);
}

/*
 * Clear two u32 slots at +0x3b0.
 *
 * Addresses are Black-image addresses.
 */
void func_021C04B0(void *p)
{
    int i;
    for (i = 0; i < 2; i++)
        *(u32 *)((char *)p + i * 4 + 0x3b0) = 0;
}

void func_021C04CC(u8 *p)
{
    int i;
    for (i = 0; i < 2; i++)
        *(int *)(p + i * 4 + 0x3B0) = (int)BMP_Create(d_021C37A4[i].x, d_021C37A4[i].y, d_021C37A4[i].z, ((struct Obj25964 *)p)->f4);
}

void func_021C04FC(u8 *p)
{
    const struct EntryUnit *q;
    struct Bmp *bmp;
    void *text;
    u16 color;
    u8 *dest;
    int i;
    for(i=0;i<2;i++) {
        q=&d_021C37A4[i];
        if(q->enabled) {
            bmp=BMP_CreateFromArchive(q->arc,q->member,0,((struct Obj14753 *)p)->f4);
            dest=p+i*4;
            BMP_Blit(bmp,*(struct Bmp * *)&((struct Obj14754 *)dest)->f3B0,0,0,0,0,q->x<<3,q->y<<3,q->b);
            color=((q->r&31)<<10)|((q->g&31)<<5)|(q->b&31);
            text=func_02045EC0(*(struct MsgBank **)(p+12+q->bank*4),q->index);
            PRINTSYS_PrintColor(((struct Obj14754 *)dest)->f3B0,q->px,q->py,text,((struct Obj14753 *)p)->f8,color);
            func_020307B0(text);
            BMP_Delete((struct Obj020437AC *)bmp);
        }
    }
}

#define E ((const struct Entry_021C05B0 *)gb)

struct Comm;

struct Entry_021C05B0 {
    int x, y, pad, bank, index, px, py;
    u8 r, g, b, pad2;
    u32 arc, member, enabled;
};

struct RowQueue {
    int w[20];
};

struct Tab {
    struct RowQueue r[3];
};

struct ParamQueue { void *bmp; s16 x,y; u32 f8,fc; u8 f10,f11; u16 f12; u32 f14; };

struct Entry_021C06F0 { s16 x,y; u32 f8,fc; u8 f10,f11; u16 f12; u32 f14; };

struct Ent {
    u32 a;
    u32 b;
    u8 c;
    u8 pad[11];
};

extern int BMP_OAM_CreateSys(u16 heap, int a);

extern struct Grid *BMP_OAM_Create(struct Sys *,const struct ParamQueue *);

extern u32 func_02012138(const struct Ctx *);

extern void GAME_COMM_RequestExitNoCallback(struct Comm *p);

extern u32 GAME_COMM_GetKind(void *obj);

extern void GAME_COMM_SetNotifyFlag(void *obj, u32 flag);

extern const struct Tab d_021C3C54;

extern const struct Entry_021C05B0 d_021C37D0;

extern const struct Entry_021C06F0 d_021C377C[];

extern const struct Ent d_021C3A28[];

void func_021C05B0(u8 *p)
{
    struct Tab tab = d_021C3C54;
    int i;
    int j;
    struct Bmp *bmp;
    void *text;
    u16 color;
    u32 gb = (u32)&d_021C37D0;
    bmp = BMP_CreateFromArchive(E->arc, E->member, 0, *(u16 *)(p + 4));
    for (i = 0; i < 3; i++) {
        int y = i * 8;
        for (j = 0; j < 20; j++) {
            BMP_Blit(bmp, *(struct Bmp **)(p + 0x3B4), (tab.r[i].w[j] % 3) * 8, (tab.r[i].w[j] / 3) * 8, j * 8, y, 8, 8, 0);
        }
    }
    BMP_Delete((struct Obj020437AC *)bmp);
    color = ((E->r & 31) << 10) | ((E->g & 31) << 5) | (E->b & 31);
    text = func_02045EC0(*(struct MsgBank **)(p + 12 + E->bank * 4), E->index);
    PRINTSYS_PrintColor(*(void **)(p + 0x3B4), E->px, E->py, text, *(void **)(p + 8), color);
    func_020307B0(text);
}

void func_021C06AC(int *p)
{
    int i;
    for (i = 0; i < 2; i++)
        BMP_Delete((struct Obj020437AC *)p[i + 0xEC]);
}

void func_021C06C8(u8 *p)
{
    ((struct Obj10961 *)p)->f3A4 = BMP_OAM_CreateSys(((struct Obj10961 *)p)->f4, ((struct Obj10961 *)p)->f38C);
}

void func_021C06E0(u8 *a0)
{
    BMP_OAM_DeleteSys((void *)((u32)(((struct Obj25966 *)a0)->f3A4)));
}

/*
 * note 2026-10-05 (wave D9r lane 131): removed the 4 dead first assignments
 * (`sysOff=0x3B0;` before `sysOff=0x3A4;`; `outOff=0x3B0;` before
 * `outOff=0x3A8;` and 2 more). Game code has no line table, so these were
 * stand-ins. The plain single assignment gives EXACT in --lang c99 and
 * --lang c: the output bytes do not change. Older text in this header that
 * asks for the double assignment is superseded.
 */
void func_021C06F0(u8 *p)
{
    int sysOff,outOff,callOff,uploadOff;
    struct ParamQueue param;
    int i;
    const struct Entry_021C06F0 *q;
    u8 *dest;
    sysOff=0x3A4;
    outOff=0x3A8;
    callOff=0x3A8;
    uploadOff=0x3A8;
    for(i=0;i<2;i++) {
        dest=p+i*4;
        param.bmp=((struct Obj25967 *)dest)->f3B0;
        q=&d_021C377C[i];
        param.x=q->x; param.y=q->y;
        param.f8=func_021BF9F0(p,q->f8);
        param.fc=q->fc;
        param.f10=q->f10; param.f11=q->f11;
        param.f12=q->f12; param.f14=q->f14;
        *(struct Grid **)(dest+outOff)=BMP_OAM_Create(*(struct Sys **)(p+sysOff),&param);
        BMP_OAM_SetEnabled(*(u8 **)(dest+callOff),0);
        BMP_OAM_UploadChars(*(struct Obj **)(dest+uploadOff));
    }
}

/*
 * Addresses are Black-image addresses.
 */
void func_021C0794(int *p)
{
    int i;
    for (i = 0; i < 2; i++)
        BMP_OAM_Delete((struct Grid *)p[i + 0xEA]);
}

/*
 * Clear the u32 at +0x3b8.
 *
 * Addresses are Black-image addresses.
 */
void func_021C07B0(void *p)
{
    ((struct Obj25969 *)p)->f3B8 = 0;
}

void func_021C07BC(u8 *p)
{
    ((struct Obj03953 *)p)->f3B8 = PALANM_Create(((struct Obj03953 *)p)->f4);
    PALANM_AllocSlotBuffers(((struct Obj03953 *)p)->f3B8, 0, 512, ((struct Obj03953 *)p)->f4);
    PALANM_AllocSlotBuffers(((struct Obj03953 *)p)->f3B8, 2, 512, ((struct Obj03953 *)p)->f4);
    PALANM_CopyHwPaletteToSlot(((struct Obj03953 *)p)->f3B8, 0, 0, 512);
    PALANM_CopyHwPaletteToSlot(((struct Obj03953 *)p)->f3B8, 2, 0, 512);
}

/*
 * Reconstructed from the listing (.inst decoded).
 *
 * BLOCKED at MATCH: the relocation site(s) below have no independent witness.
 *   +001A THM_CALL PALANM_Delete       -> unresolved: 02021540 (arm, from name) has no witness outside 021C0800..021C0820
 * Promote automatically when the target is matched.
 *
 * Addresses are Black-image addresses.
 */
u32 func_021C0800(u32 a0)
{
    PALANM_FreeSlotBuffers((struct PalAnmSlot *)(((struct Obj10962 *)(((u8*)a0)))->f3B8), 0);
    PALANM_FreeSlotBuffers((struct PalAnmSlot *)(((struct Obj10962 *)(((u8*)a0)))->f3B8), 2);
    return PALANM_Delete((void *)(((struct Obj10962 *)(((u8*)a0)))->f3B8));
}

void func_021C0820(void *p)
{
    int i;
    for (i = 0; i < 8; i++)
        *(u32 *)((char *)p + i * 4 + 0x324) = 0;
}

void func_021C083C(u8 *p)
{
    int i;
    for (i = 0; i < 8; i++)
        *(int *)(p + i * 4 + 0x324) = PALETTE_ANIME_Create(((struct Obj25970 *)p)->f4);
}

void func_021C085C(int *p)
{
    int i;
    for (i = 0; i < 8; i++)
        PALETTE_ANIME_Destroy((void *)p[i + 0xC9]);
}

void func_021C0878(u8 *p)
{
    int i;
    for (i = 0; i < 8; i++)
        PALETTE_ANIME_Bind((void *)(*(int *)(p + i * 4 + 0x324)), d_021C3A28[i].a, d_021C3A28[i].b, d_021C3A28[i].c);
}

void func_021C08A8(int *p)
{
    int i;
    for (i = 0; i < 8; i++)
        PALETTE_ANIME_Restore((char *)p[i + 0xC9]);
}

/*
 * Reconstructed from the listing.
 *
 * Addresses are Black-image addresses.
 */
void func_021C08C4(u32 a0)
{
    GFL_NET_RestartWithDefaultTimeout(1, ((struct Obj25973 *)(((u8*)a0 + 0)))->f4);
}

void func_021C08D4(char *p)
{
    ((struct Obj25974 *)p)->f3C0 = func_020056A0((void (*)(void))func_021BF6BC, p, 0);
}

/*
 * Tail-call veneer: forwards arg(s) (u32)(*(u32*)(a0 + 960)), 960 to func_02030EAC.
 *
 * Addresses are Black-image addresses.
 */
void func_021C08F0(u8 *a0)
{
    func_02030EAC((struct Node *)((u32)(((struct Obj25975 *)a0)->f3C0)));
}

u32 func_021C0900(s32 v)
{
    if (v < 0)
        return 0;
    if (v > 0xff)
        return 0xff;
    return (u8)v;
}

/*
 * Opens the +0x10 record (func_02012138 on the result of func_021BF734),
 * tags it with 1, and releases it when GAME_COMM_GetKind reports state 2.
 * Closed by the generator's duplicate guard statement (O89).
 *
 * Addresses are Black-image addresses.
 */
void func_021C0918(u8 *a0)
{
    u32 v1 = func_02012138((const struct Ctx *)func_021BF734(a0));
    GAME_COMM_SetNotifyFlag((void *)v1, 1);
    if (GAME_COMM_GetKind((void *)v1) == 2) {
    GAME_COMM_RequestExitNoCallback((struct Comm *)v1);
    }
}

int func_021C093C(u8 *a0)
{
    u32 r;
    r = func_021BF734(a0);
    switch (GAME_COMM_GetKind((void *)func_02012138((const struct Ctx *)r))) {
    case 0:
        GAMESYSTEM_TryStartAutoComm((struct IcaAnime *)r);
        return 1;
    default:
        return 1;
    case 2:
        return 0;
    }
}

void func_021C0968(unsigned char *a0)
{
    GAME_COMM_SetNotifyFlag((void *)func_02012138((const struct Ctx *)func_021BF734(a0)), 0);
}
