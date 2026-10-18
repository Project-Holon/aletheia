/*
 * function: SCRIPT_COMMAND_CmdCompareScores
 * address:  0x021FBA6C
 * packet:   pkt_ov132_021FBA14
 * region:   ov132
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * notes:    unlabelled Thumb function after SCRIPT_COMMAND_TaskRotate (its listing extent
 *           ran past it); seeded in layout/function_starts.txt.
 *
 * symbols:
 *   func_02030734 0x02030734 arm
 *   PARTICLE_InitManager 0x02050B80 arm
 *   d_021FDCB0 0x021FDCB0 data a4
 *   PARTICLE_ExitManager 0x02050ED4 arm
 *   func_020307B0 0x020307B0 arm
 *   PARTICLE_UpdateAllSystems 0x02051574 arm
 *   PARTICLE_DrawAllSystems 0x02051534 arm
 *   PARTICLE_CreateSystemDefault 0x02050C04 arm
 *   PARTICLE_LoadArchiveMember 0x0205121C arm
 *   func_020056BC 0x020056BC thumb
 *   PARTICLE_SetupSystem 0x02051230 arm
 *   PARTICLE_KillAllEffects 0x02051620 arm
 *   PARTICLE_DeleteSystem 0x02050DB8 arm
 *   PARTICLE_StartEffect 0x020515B4 arm
 *   PARTICLE_KillEffect  0x02051630  arm
 *   BUTTON_MAN_SetEmitterPos  0x02051838  arm
 *   d_021FDCC4 0x021FDCC4 data a4
 *   STA_ACTING_GetCameraPos 0x021F9DFC thumb ov132
 *   func_02005728 0x02005728 thumb
 *   MUSICAL_PROGRAM_GetCategoryBonus 0x0215725C thumb ov010
 *   STA_ACTING_GetCameraTarget 0x021F9E04 thumb ov132
 *   STA_ACTING_GetActorSystem 0x021F9DA0 thumb ov132
 *   STA_ACTING_GetActor 0x021F9DA4 thumb ov132
 *   STA_ACTING_GetCharSystem 0x021F9DD4 thumb ov132
 *   STA_ACTING_GetCharSlot 0x021F9DDC thumb ov132
 *   STA_ACT_LIGHT_CopyActorPos 0x021F8044 thumb ov112
 *   STA_ACT_LIGHT_GetElemPos 0x021F6F04 thumb ov112
 *   _fflt 0x0209BDBC arm
 *   _ffltu 0x0209BE04 arm
 *   _fdiv 0x0209CE10 arm
 *   _fsub 0x0209CB8C arm
 *   _ffix 0x0209C494 arm
 *   BG_SYS_SetTileEntry 0x02041300 arm
 *   func_02041B6C 0x02041B6C arm
 *   d_021FDC16 0x021FDC16 data a2
 *   BG_SYS_FillScrollArea 0x02040618 arm
 *   d_021FDCD8 0x021FDCD8 data a4
 *   CLACT_DeleteActor 0x0204B3B4 arm
 *   CLACT_ReleasePalette 0x0204ADA4 arm
 *   CLACT_ReleaseCharacter 0x0204A8D4 arm
 *   CLACT_ReleaseCellAnim 0x0204AFD8 arm
 *   CLACT_DeleteUnit 0x0204B1CC arm
 *   d_021FDC20 0x021FDC20 data a1
 *   TOUCHPANEL_HitTrg 0x02035C08 arm
 *   G2x_SetBlendBrightness_ 0x0207D658 arm
 *   STA_ACTING_RequestAction 0x021F9730 thumb ov132
 *   STA_ACTING_GetCurrentAction 0x021F9768 thumb ov132
 *   CLACT_RestartActorAnim 0x0204B9A0 arm
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   CLACT_AddActorSurfacePos 0x0204B404 arm
 *   UI_SetInputMode 0x020355D8 arm
 *   CLACT_GetActorDrawEnable 0x0204B3F4 arm
 *   CLACT_IsActorAnimActive 0x0204B98C arm
 *   STA_ACTING_GetActorCount 0x021F9E0C thumb ov132
 *   CLACT_CreateUnit 0x0204B100 arm
 *   CLACT_SetUnitDefaultRenderer 0x0204B270 arm
 *   func_020490F4 0x020490F4 arm
 *   CLACT_RegisterPaletteEx 0x0204AC18 arm
 *   CLACT_RegisterCharacter 0x0204A6C8 arm
 *   CLACT_RegisterCellAnim 0x0204AF28 arm
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   CLACT_RegisterPalette 0x0204ABF0 arm
 *   MUSICAL_MCSS_GetElemPtr 0x021F4F54 thumb ov112
 *   MUSICAL_MCSS_NoOp6 0x021F4F70 thumb ov112
 *   CLACT_CreateActor 0x0204B294 arm
 *   CLACT_SetActorAutoAnim 0x0204B92C arm
 *   ARC_UTIL_LoadMember 0x0204A1BC arm
 *   NNS_G3dGetTex 0x0206E964 arm
 *   CLACT_GetCharacterVramAddress 0x0204ABBC arm
 *   DWCi_ScreenDC_FlushRange 0x020862F0 arm
 *   func_0207E5D0 0x0207E5D0 arm
 *   func_0207E804 0x0207E804 arm
 *   func_02030CB0 0x02030CB0 arm
 *   func_02030CBC 0x02030CBC arm
 *   NNS_FndInitList 0x02060468 arm
 *   d_021FDCEC 0x021FDCEC data ov132 a4
 *   func_02011290 0x02011290 thumb
 *   VM_Delete 0x02011264 thumb
 *   NNS_FndGetNextListObject 0x02060614 arm
 *   TCB_Noop 0x02030DA4 arm
 *   TCB_Main 0x02030D28 arm
 *   VM_Create 0x0201121C thumb
 *   VM_Init 0x0201126C thumb
 *   VM_Start 0x0201127C thumb
 *   d_021FDC2C 0x021FDC2C data ov132 a4
 *   VM_Control 0x02011298 thumb
 *   func_02030DA8 0x02030DA8 arm
 *   NNS_FndAppendListObject 0x020604AC arm
 *   func_02030EAC 0x02030EAC arm
 *   NNS_FndRemoveListObject 0x020605B4 arm
 *   _fadd 0x0209C95C arm
 *   VEC_MultAdd 0x0207CEE4 arm
 *   VEC_Add 0x0207C9D0 arm
 *   VM_GetU32 0x0201134C thumb
 *   d_021FDD00 0x021FDD00 data ov132 a4
 *   STA_ACTING_PlayRankSe 0x021F96D0 thumb ov132
 *   STA_ACTING_SetCameraPos 0x021F9E00 thumb ov132
 *   STA_ACTING_SetCameraTarget 0x021F9E08 thumb ov132
 *   STA_ACTING_ShowAnim  0x021F9D80  thumb
 *   STA_ACTING_ScheduleActions  0x021F9AD8  thumb
 *   STA_ACTING_HideAnim  0x021F9D90  thumb
 *   STA_ACT_LIGHT_SetSlotVisible 0x021F80D4 thumb ov112
 *   STA_ACT_LIGHT_SetActorFlagB 0x021F812C thumb ov112
 *   STA_ACT_LIGHT_SetActorPos 0x021F8054 thumb ov112
 *   VEC_Subtract 0x0207CA00 arm
 *   STA_ACT_LIGHT_ResetRenderAnim 0x021F80B0 thumb ov112
 *   STA_ACT_LIGHT_StartRenderAnim 0x021F80A0 thumb ov112
 *   STA_ACT_LIGHT_SetRenderAnim 0x021F80C8 thumb ov112
 *   STA_ACT_LIGHT_SetActorVisible 0x021F8140 thumb ov112
 *   STA_ACT_LIGHT_SetElemValue 0x021F8154 thumb ov112
 *   STA_ACTING_PositionAnim 0x021F9D18 thumb ov132
 *   STA_ACTING_SetSelection 0x021F95CC thumb ov132
 *   STA_ACTING_LoadRankAnim 0x021F9140 thumb ov132
 *   STA_ACTING_LoadAnimMember 0x021F91A8 thumb ov132
 *   STA_ACT_LIGHT_SetActorOffset 0x021F8084 thumb ov112
 *   _u32_div_f 0x0209C2B0 arm
 *   _ll_mul 0x0209C054 arm
 *   FX_SinCosTable_ 0x020A1B38 data a2
 *   func_0209C0A4  0x0209C0A4  arm
 *   STA_ACTING_GetRecordScore 0x021F9E20 thumb ov132
 *   STA_ACTING_GetBonus 0x021F9E34 thumb ov132
 *   STA_ACTING_SetField10 0x021F9E3C thumb ov132
 *   _s32_to_float 0x0209BDBC arm
 *   func_0209C494 0x0209C494 arm
 *   func_0209CB8C 0x0209CB8C arm
 *   func_0209CE10 0x0209CE10 arm
 *   STA_ACTING_GetActObj 0x021F9DAC thumb ov132
 *   STA_ACT_OBJ_AddEntry 0x021F6B18 thumb ov112
 *   STA_ACTING_SetSlot 0x021F9DB8 thumb ov132
 *   STA_ACTING_GetSlot 0x021F9DB0 thumb ov132
 *   STA_ACT_OBJ_FreeEntry 0x021F6B80 thumb ov112
 *   STA_ACT_LIGHT_SetElemVisible 0x021F6BC0 thumb ov112
 *   STA_ACT_OBJ_SetEntryTarget 0x021F6B9C thumb ov112
 *   STA_ACT_OBJ_GetEntryTarget 0x021F6BB0 thumb ov112
 *   STA_ACTING_GetAnimHandle 0x021F9DC0 thumb ov132
 *   STA_ACTING_SetAnimSlot 0x021F9DCC thumb ov132
 *   STA_ACTING_GetAnimSlot 0x021F9DC4 thumb ov132
 *   STA_ACT_LIGHT_CreateActor 0x021F6E78 thumb ov112
 *   STA_ACT_LIGHT_SetElemA 0x021F6F14 thumb ov112
 *   STA_ACT_LIGHT_SetElemB 0x021F6F1C thumb ov112
 *   STA_ACTING_SetCharSlot 0x021F9DE8 thumb ov132
 *   STA_ACTING_MarkDirty 0x021F95E8 thumb ov132
 *   STA_ACT_LIGHT_DeleteActor 0x021F6EE4 thumb ov112
 *   STA_ACT_LIGHT_CopyElemA 0x021F6EF4 thumb ov112
 *   STA_ACTING_GetBoard 0x021F9DF4 thumb ov132
 *   STA_ACTING_PrintText 0x021F93D8 thumb ov132
 *   STA_ACTING_ClearText  0x021F94B0  thumb
 *   GF_FONT_SetTextColor 0x0201DD78 thumb
 *   STA_ACTING_InstallBgm  0x021F9664  thumb
 *   STA_ACTING_StartSeq  0x021F9680  thumb
 *   STA_ACTING_StopSeq  0x021F9690  thumb
 *   STA_ACTING_ReplaceWaveData 0x021F969C thumb ov132
 *   STA_ACTING_PlayBgm  0x021F96B0  thumb
 *   STA_ACTING_StopBgm  0x021F96C4  thumb
 *   d_021FDE5C 0x021FDE5C data a4
 *   GAME_COMM_RequestExitNoCallback 0x02026400 thumb
 *   GFL_NET_StartSession 0x0203CBAC arm
 *   OS_GetMacAddress 0x02087C6C arm
 *   d_021FDE4C 0x021FDE4C data a4
 *   d_021FDDEC 0x021FDDEC data a4
 *   GFL_NET_GetNegotiationNum 0x0203D1B4 arm
 *   GFL_NET_Exit 0x0203CEAC arm
 *   GFL_NET_COMMAND_DeleteCommandTable 0x0203A5E4 arm
 *   GFL_NET_SetLoginOption 0x0203D7BC arm
 *   func_0200FB24 0x0200FB24 thumb
 *   GFL_NET_IsParentAid 0x0203D378 arm
 *   GFL_NET_HANDLE_GetCurrentHandle 0x020399A8 arm
 *   GFL_NET_SendToHandle 0x0203D3A8 arm
 *   ICA_ANIME_SetField30 0x02012124 thumb
 *   GFL_NET_IsSessionNull 0x0203CDBC arm
 *   GFL_NET_COMMAND_AddCommandTable 0x0203A574 arm
 *   d_021FDC38 0x021FDC38 data a4
 *   GAME_DATA_GetSaveBlock2A 0x02012F44 thumb
 *   POKE_TOOL_GetPartyParamSize 0x020173EC thumb
 *   POKE_TOOL_GetBoxParamSize 0x020173E8 thumb
 *   MYSTATUS_GetSize 0x02008468 thumb
 *   MI_CpuFill8 0x02082BCC arm
 *   MUSICAL_SAVE_GetFanPoints 0x0200A81C thumb
 *   GF_STANDARD_Rand 0x0203F0A8 arm
 *   _ull_mul 0x0209C054 arm
 *   STA_NET_SendRandomOrder 0x021FD84C thumb ov132
 *   STA_NET_NotifyHostKind4 0x021FD6C8 thumb ov132
 *   STA_NET_SendSlot1Command 0x021FD704 thumb ov132
 *   STA_NET_NotifyHostKind5 0x021FD6DC thumb ov132
 *   STA_NET_NotifyHostKind6 0x021FD6F0 thumb ov132
 *   STA_NET_SendSlot2Command 0x021FD76C thumb ov132
 *   STA_NET_SendSlot3Command 0x021FD7D4 thumb ov132
 *   STA_NET_IsTransferDone 0x021FD6A4 thumb ov132
 *   STA_NET_UpdateTransferState 0x021FD550 thumb ov132
 *   GFL_NET_HANDLE_SetTimingSyncRange  0x02039C68  arm
 *   GFL_NET_HANDLE_IsTimingSyncRange 0x02039CB4 arm
 *   GFL_NET_SendData 0x0203D3F8 arm
 *   GFL_NET_HANDLE_GetNetHandle 0x0203996C arm
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   MI_CpuCopy8 0x02082D44 arm
 *   func_020084BC 0x020084BC thumb
 *   STA_ACT_EFFECT_SetSceneField14  0x021F9E40  thumb  ov132
 *   STA_ACT_SCRIPT_AddTask  0x021FADA0  thumb  ov132
 *   SCRIPT_COMMAND_TaskCameraTarget  0x021FB190  thumb  ov132
 *   SCRIPT_COMMAND_TaskActorMove  0x021FB528  thumb  ov132
 *   SCRIPT_COMMAND_TaskShake  0x021FB8CC  thumb  ov132
 *   MYSTATUS_Copy  0x02008494  thumb  arm9
 *   GAME_COMM_Start  0x020263D8  thumb  arm9
 *   ICA_ANIME_GetField1C  0x020120F4  thumb  arm9
 *   STA_ACT_LIGHT_SetActorAngle  0x021F8068  thumb  ov112
 *   STA_ACT_EFFECT_GetSceneOwner  0x021F9E44  thumb
 *   STA_ACT_EFFECT_Noop  0x021F9E4C  thumb
 *   STA_ACT_EFFECT_Create  0x021F9E50  thumb
 *   STA_ACT_EFFECT_Delete  0x021F9E94  thumb
 *   STA_ACT_EFFECT_Update  0x021F9ECC  thumb
 *   STA_ACT_EFFECT_Draw  0x021F9ED4  thumb
 *   STA_ACT_EFFECT_StartSystem  0x021F9EDC  thumb
 *   STA_ACT_EFFECT_KillSystem  0x021F9F58  thumb
 *   STA_ACT_EFFECT_StartEffect  0x021F9F74  thumb
 *   STA_ACT_EFFECT_KillEffect  0x021F9FB4  thumb
 *   STA_ACT_EFFECT_SetEmitterPos  0x021F9FD0  thumb
 *   STA_ACT_AUDIENCE_Create  0x021F9FEC  thumb
 *   STA_ACT_AUDIENCE_Delete  0x021FA04C  thumb
 *   STA_ACT_AUDIENCE_Update  0x021FA064  thumb
 *   STA_ACT_AUDIENCE_Noop  0x021FA0D0  thumb
 *   STA_ACT_AUDIENCE_Noop2  0x021FA0D4  thumb
 *   STA_ACT_AUDIENCE_SetupRecords  0x021FA0D8  thumb
 *   STA_ACT_AUDIENCE_Noop3  0x021FA278  thumb
 *   STA_ACT_AUDIENCE_UpdateRecords  0x021FA27C  thumb
 *   STA_ACT_AUDIENCE_UpdateRecord  0x021FA2A0  thumb
 *   STA_ACT_AUDIENCE_DrawRecord  0x021FA3A8  thumb
 *   STA_ACT_AUDIENCE_ApplyChoices  0x021FA4AC  thumb
 *   STA_ACT_AUDIENCE_RandomizeRecords  0x021FA528  thumb
 *   STA_ACT_AUDIENCE_SetSlotValue  0x021FA558  thumb
 *   STA_ACT_AUDIENCE_SetHighlight  0x021FA56C  thumb
 *   STA_ACT_AUDIENCE_SetBgScroll  0x021FA57C  thumb
 *   STA_ACT_BUTTON_Create  0x021FA5B0  thumb
 *   STA_ACT_BUTTON_Delete  0x021FA64C  thumb
 *   STA_ACT_BUTTON_Update  0x021FA6CC  thumb
 *   STA_ACT_BUTTON_CreateActors  0x021FA7E0  thumb
 *   STA_ACT_BUTTON_LoadCharacter  0x021FA99C  thumb
 *   STA_ACT_BUTTON_SetVisible  0x021FAAB8  thumb
 *   STA_ACT_SCRIPT_Create  0x021FAAF4  thumb
 *   STA_ACT_SCRIPT_Delete  0x021FAB58  thumb
 *   STA_ACT_SCRIPT_Update  0x021FABD8  thumb
 *   STA_ACT_SCRIPT_AddScript  0x021FAC74  thumb
 *   STA_ACT_SCRIPT_AddScriptFromTable  0x021FAD0C  thumb
 *   STA_ACT_SCRIPT_RunScript  0x021FAD2C  thumb
 *   STA_ACT_SCRIPT_CountScripts  0x021FAD7C  thumb
 *   STA_ACT_SCRIPT_RemoveTask  0x021FADF8  thumb
 *   STA_ACT_SCRIPT_StepTaskInt  0x021FAE1C  thumb
 *   STA_ACT_SCRIPT_StepTaskVec  0x021FAE4C  thumb
 *   STA_ACT_SCRIPT_StepTaskActor  0x021FAEA8  thumb
 *   STA_ACT_SCRIPT_TickSlot  0x021FAEE8  thumb
 *   STA_ACT_SCRIPT_SetWaitFlag  0x021FAF10  thumb
 *   STA_ACT_SCRIPT_SkipArg  0x021FAF1C  thumb
 *   STA_ACT_SCRIPT_SetWaitFromArg  0x021FAF28  thumb
 *   STA_ACT_SCRIPT_SetRemainingWait  0x021FAF38  thumb
 *   STA_ACT_SCRIPT_SetPendingFlag  0x021FAF54  thumb
 *   SCRIPT_COMMAND_CmdCameraTo224  0x021FAF70  thumb
 *   SCRIPT_COMMAND_CmdCameraTo0  0x021FAFDC  thumb
 *   SCRIPT_COMMAND_CmdSetCameraPos  0x021FB050  thumb
 *   SCRIPT_COMMAND_TaskCameraPos  0x021FB0DC  thumb
 *   SCRIPT_COMMAND_CmdSetCameraTarget  0x021FB104  thumb
 *   SCRIPT_COMMAND_CmdSkipArg  0x021FB1C0  thumb
 *   SCRIPT_COMMAND_CmdShowAnim  0x021FB1CC  thumb
 *   SCRIPT_COMMAND_CmdHideAnim  0x021FB1E4  thumb
 *   SCRIPT_COMMAND_GetActorMask  0x021FB1F4  thumb
 *   SCRIPT_COMMAND_CmdSetActorFrame  0x021FB208  thumb
 *   SCRIPT_COMMAND_CmdSetActorVisible  0x021FB258  thumb
 *   SCRIPT_COMMAND_CmdSetActorPos  0x021FB2B0  thumb
 *   SCRIPT_COMMAND_CmdAddActorPos  0x021FB3E0  thumb
 *   SCRIPT_COMMAND_CmdActorAnimRestart  0x021FB55C  thumb
 *   SCRIPT_COMMAND_CmdActorAnimPause  0x021FB5A4  thumb
 *   SCRIPT_COMMAND_CmdSetActorFlag  0x021FB5EC  thumb
 *   SCRIPT_COMMAND_CmdSetActorScale  0x021FB640  thumb
 *   SCRIPT_COMMAND_CmdSetActorLight  0x021FB698  thumb
 *   SCRIPT_COMMAND_CmdPositionAnim  0x021FB6F0  thumb
 *   SCRIPT_COMMAND_CmdSetSelection  0x021FB738  thumb
 *   SCRIPT_COMMAND_CmdClearSelection  0x021FB774  thumb
 *   SCRIPT_COMMAND_CmdLoadRankAnim  0x021FB7A4  thumb
 *   SCRIPT_COMMAND_CmdLoadAnimMember  0x021FB7D8  thumb
 *   SCRIPT_COMMAND_CmdStartShake  0x021FB808  thumb
 *   SCRIPT_COMMAND_CmdRotateActor  0x021FB948  thumb
 *   SCRIPT_COMMAND_TaskRotate  0x021FBA14  thumb
 *   SCRIPT_COMMAND_CmdSetFlags  0x021FBD78  thumb
 *   SCRIPT_COMMAND_CmdAddEntry  0x021FBDCC  thumb
 *   SCRIPT_COMMAND_CmdFreeEntry  0x021FBE00  thumb
 *   SCRIPT_COMMAND_CmdShowEntry  0x021FBE38  thumb
 *   SCRIPT_COMMAND_CmdHideEntry  0x021FBE64  thumb
 *   SCRIPT_COMMAND_CmdSetEntryTarget  0x021FBE90  thumb
 *   SCRIPT_COMMAND_TaskEntryTarget  0x021FBF74  thumb
 *   SCRIPT_COMMAND_CmdSetAnimSlot  0x021FBFA8  thumb
 *   SCRIPT_COMMAND_CmdFreeAnimSlot  0x021FBFDC  thumb
 *   SCRIPT_COMMAND_CmdStartEffect  0x021FC014  thumb
 *   SCRIPT_COMMAND_CmdKillEffect  0x021FC080  thumb
 *   SCRIPT_COMMAND_CmdMoveEffect  0x021FC0AC  thumb
 *   SCRIPT_COMMAND_TaskMoveEffect  0x021FC178  thumb
 *   SCRIPT_COMMAND_CmdSetChar  0x021FC1D4  thumb
 *   SCRIPT_COMMAND_CmdFreeChar  0x021FC22C  thumb
 *   SCRIPT_COMMAND_CmdSetCharPos  0x021FC268  thumb
 *   SCRIPT_COMMAND_TaskCharMove  0x021FC34C  thumb
 *   SCRIPT_COMMAND_CmdCharFollowActor  0x021FC380  thumb
 *   SCRIPT_COMMAND_TaskCharFollow  0x021FC490  thumb
 *   SCRIPT_COMMAND_CmdSetCharColor  0x021FC4CC  thumb
 *   SCRIPT_COMMAND_CmdPrintText  0x021FC53C  thumb
 *   SCRIPT_COMMAND_CmdClearText  0x021FC560  thumb
 *   SCRIPT_COMMAND_CmdSetTextColor  0x021FC570  thumb
 *   SCRIPT_COMMAND_CmdInstallBgm  0x021FC5A0  thumb
 *   SCRIPT_COMMAND_CmdStartSeq  0x021FC5BC  thumb
 *   SCRIPT_COMMAND_CmdStopSeq  0x021FC5D8  thumb
 *   SCRIPT_COMMAND_CmdReplaceWave  0x021FC5E8  thumb
 *   SCRIPT_COMMAND_CmdPlayBgm  0x021FC61C  thumb
 *   SCRIPT_COMMAND_CmdStopBgm  0x021FC634  thumb
 *   MUS_COMM_FUNC_Create  0x021FC644  thumb
 *   MUS_COMM_FUNC_Delete  0x021FC684  thumb
 *   MUS_COMM_FUNC_StartSession  0x021FC694  thumb
 *   MUS_COMM_FUNC_UpdateNetState  0x021FC6EC  thumb
 *   MUS_COMM_FUNC_WaitSessionNull  0x021FC7DC  thumb
 *   MUS_COMM_FUNC_Task  0x021FC7F8  thumb
 *   MUS_COMM_FUNC_SetHostFlag  0x021FC804  thumb
 *   MUS_COMM_FUNC_InitCommandTable  0x021FC81C  thumb
 *   MUS_COMM_FUNC_InitWork  0x021FC848  thumb
 *   MUS_COMM_FUNC_DeleteBuffers  0x021FCA38  thumb
 *   MUS_COMM_FUNC_SetReady  0x021FCAA0  thumb
 *   MUS_COMM_FUNC_Update  0x021FCAA8  thumb
 *   MUS_COMM_FUNC_SetTimingSync  0x021FCDEC  thumb
 *   MUS_COMM_FUNC_CheckTimingSync  0x021FCE00  thumb
 *   MUS_COMM_FUNC_GetSlotValueA  0x021FCE28  thumb
 *   MUS_COMM_FUNC_GetSlotValueB  0x021FCE44  thumb
 *   MUS_COMM_FUNC_GetRecordPtr  0x021FCE60  thumb
 *   MUS_COMM_FUNC_GetRecordSize  0x021FCE64  thumb
 *   MUS_COMM_FUNC_Equals  0x021FCE68  thumb
 *   MUS_COMM_FUNC_SendCommand  0x021FCE74  thumb
 *   MUS_COMM_FUNC_SendCommandWait  0x021FCEA8  thumb
 *   MUS_COMM_FUNC_HandlePacket  0x021FCEDC  thumb
 *   MUS_COMM_FUNC_SendMyStatus  0x021FD14C  thumb
 *   MUS_COMM_FUNC_SetEntryFlag  0x021FD208  thumb
 *   MUS_COMM_FUNC_ClearEntryFlag  0x021FD218  thumb
 *   MUS_COMM_FUNC_SendBoxData  0x021FD22C  thumb
 *   MUS_COMM_FUNC_ReceiveBoxData  0x021FD2B8  thumb
 *   MUS_COMM_FUNC_ResetBoxFlags  0x021FD328  thumb
 *   MUS_COMM_FUNC_SendStatusBlock  0x021FD350  thumb
 *   MUS_COMM_FUNC_SetRecordData  0x021FD3D8  thumb
 *   MUS_COMM_FUNC_ClearRecordData  0x021FD3F0  thumb
 *   MUS_COMM_FUNC_SendRecordBlock  0x021FD400  thumb
 *   MUS_COMM_FUNC_ReceiveRecordBlock  0x021FD470  thumb
 *   GAME_DATA_GetMyStatus  0x02012944  thumb  arm9
 */

#include "../../game/ov132/ov132_types.h"

#define ABS(x) ((x) < 0 ? -(x) : (x))
#define W(q,k) (*(u32 *)((q)+(k)))
#define P(q,k) (*(u8 **)((q)+(k)))
struct Bank;
struct Obj_021F9E40;
struct Actor;
struct Vec2;
struct Ctx;
struct ScriptVm;
struct DList;
struct ScriptVmParams;
struct Node;
struct Cursor;
struct Object;
struct Entry;
struct Comm;
struct Req;
struct Big;
struct Link;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct { int x, y, z; } Vec;

typedef struct { int a; Vec v; } Part;

typedef struct { char pad[0x4808]; Part part[4]; } Obj_021F9E40;

typedef signed int     s32;

typedef short s16_021F9E40;

typedef signed char s8;

typedef signed short s16_021FA558;

typedef signed short s16_021FA56C;

typedef short s16_021FA6CC;

typedef enum { FLAG_ZERO, FLAG_ONE } Flag;

typedef struct {u8 bytes[12];} Key;

typedef struct {s16_021FA6CC x,y;} Pos;

typedef short s16_021FA7E0;

typedef struct {s16_021FA7E0 x,y,index;u8 a,b;} Params;

typedef enum { COORD_ZERO } Coord;

typedef struct TaskData { void *context; int tick, duration, count; void *slot; int amplitude; void *owner; void *task; } TaskData;

typedef signed short s16;

typedef struct Vec3 { u32 x, y, z; } Vec3;

typedef struct Tag { u32 v; } Tag;

typedef struct Obj_021FBA6C { u16 f0; u8 pad2[0x32]; char *f34; } Obj_021FBA6C;

typedef struct Msg { Obj_021FBA6C *f0; void *f4; u8 pad8[0xC]; u16 f14; } Msg;

typedef struct R38 {
    u32 f00; char *f04; Vec3 f08; Vec3 f14; Vec3 f20; u16 f2C; u16 f2E; Obj_021FBA6C *f30; void *f34;
} R38;

typedef struct R20 { char *f00; u32 f04; u32 f08; u32 f0C; void *f10; u32 f14; Obj_021FBA6C *f18; void *f1C; } R20;

typedef struct R18 { char *f00; u32 f04; u32 f08; u16 f0C; u16 f0E; Obj_021FBA6C *f10; void *f14; } R18;

typedef unsigned long long u64;

struct Pl {
    u32 a;
    u32 b;
    u32 c;
    u8 d;
    u8 pad[3];
    u32 x;
    u32 e;
    u8 rest[0x18];
};

struct G {
    u8 pad[0x64];
    struct Pl pl[4];
};

struct Request {u8 kind;u32 value;};

typedef struct 
{
  u8 tag;
  u32 data;
} Packet;

typedef struct {u16 heap;u8 pad[0x12a];u32 value;void *first,*second;char *buffer;u8 tail[0x70];} Owner_021F9E40;

typedef struct { u32 w[12]; } E;

typedef struct { u8 pad[0x60]; E e[4]; } T;

struct Record { int f0; int flag; char pad8[0x14]; char *data; char pad20[0x10]; };

struct Context { char pad0[0x60]; struct Record rec[4]; };

/* The callback owner is the 0x1ac-byte allocation in 021FC644. */
typedef struct {u8 pad[0x128];char *buffer;u8 tail[0x80];} Owner_021FD22C;

extern void *func_02030734(unsigned, unsigned, int, const char *, u16);
extern void PARTICLE_InitManager(unsigned);
extern void PARTICLE_ExitManager(void);
extern u32 func_020307B0(void *p);
extern int PARTICLE_UpdateAllSystems(void);
extern int PARTICLE_DrawAllSystems(void);
extern int PARTICLE_CreateSystemDefault(int a, int b, int c, int d);
extern int PARTICLE_LoadArchiveMember(u32 a, u32 b, u32 c);
extern unsigned func_020056BC(void);
extern void PARTICLE_SetupSystem(void *, void *, unsigned, unsigned);
extern void PARTICLE_KillAllEffects(u32);
extern void PARTICLE_DeleteSystem(u8 *p);
extern int PARTICLE_StartEffect(void *p, int b, int c);
extern void PARTICLE_KillEffect(void **p, void *q);
extern void BUTTON_MAN_SetEmitterPos(void *, int);
extern u16 STA_ACTING_GetCameraPos(void *p);
extern unsigned func_02005728(unsigned);
extern u8 MUSICAL_PROGRAM_GetCategoryBonus(u8 *, int);
extern u16 STA_ACTING_GetCameraTarget(u8 *p);
extern void *STA_ACTING_GetActorSystem(char *p);
extern void *STA_ACTING_GetActor(char *p, u32 i);
extern void *STA_ACTING_GetCharSystem(void *);
extern void *STA_ACTING_GetCharSlot(void *,u8);
extern void STA_ACT_LIGHT_CopyActorPos(void *unused, u32 *p, u32 *q);
extern void STA_ACT_LIGHT_GetElemPos(void *,char *,Vec *);
extern void BG_SYS_SetTileEntry(u32,u16,u8,u8,u8,u8,u8);
extern void func_02041B6C(u32);
extern void BG_SYS_FillScrollArea(unsigned, unsigned, unsigned);
extern void CLACT_DeleteActor(struct Obj_021F9E40 *p);
extern void CLACT_ReleasePalette(u32 i);
extern void CLACT_ReleaseCharacter(u32 i);
extern void CLACT_ReleaseCellAnim(u32 i);
extern u32 CLACT_DeleteUnit(struct Bank *bank);
extern int TOUCHPANEL_HitTrg(const void *);
extern void G2x_SetBlendBrightness_(unsigned long,int,int);
extern void STA_ACTING_RequestAction(char *p, int value);
extern void CLACT_RestartActorAnim(struct Actor *a);
extern void CLACT_SetActorDrawEnable(struct Obj_021F9E40 *,unsigned int);
extern void CLACT_AddActorSurfacePos(struct Obj_021F9E40 *p, const struct Vec2 *delta, u32 which);
extern void UI_SetInputMode(u8);
extern int STA_ACTING_GetCurrentAction(char *p);
extern u32 CLACT_GetActorDrawEnable(struct Obj_021F9E40 *p);
extern u32 CLACT_IsActorAnimActive(struct Actor *a);
extern u32 STA_ACTING_GetActorCount(u8 *p);
extern u8 *MUSICAL_MCSS_GetElemPtr(u8 *,int);
extern int MUSICAL_MCSS_NoOp6(int *);
extern struct Bank *CLACT_CreateUnit(int count, u8 flag, u32 heapId);
extern void *func_020490F4(u32 id, u32 heap);
extern void CLACT_SetUnitDefaultRenderer(struct Bank *bank);
extern void ARC_TOOL_DeleteHandle(void *);
extern void CLACT_SetActorAutoAnim(struct Obj_021F9E40 *,u32);
extern int CLACT_RegisterPaletteEx(void *,u32,u32,u32,u16,u16,u16),CLACT_RegisterCharacter(void *,u32,u32,u32,u16),CLACT_RegisterCellAnim(void *,u32,u32,u32),CLACT_RegisterPalette(void *,u32,u32,u32,u16);
extern struct Obj_021F9E40 *CLACT_CreateActor(void *,unsigned int,unsigned int,unsigned int,const void *,u16,u16);
extern int ARC_UTIL_LoadMember(int,int,int,int);
extern unsigned char *NNS_G3dGetTex(unsigned char *p);
extern int CLACT_GetCharacterVramAddress(u32 idx, u32 flag);
extern void DWCi_ScreenDC_FlushRange(void *,u32);
extern void func_0207E5D0(const void *,u32,u32);
extern void func_0207E804(const void *,void *,u32);
extern u32 func_02030CB0(u32);
extern struct Ctx *func_02030CBC(u32 capacity, struct Ctx *c);
extern void NNS_FndInitList(int p0, int p1);
extern struct ScriptVm *func_02011290(struct ScriptVm *vm);
extern void VM_Delete(void *);
extern void *NNS_FndGetNextListObject(struct DList *list, void *elem);
extern void TCB_Noop(void *);
extern void TCB_Main(struct Ctx *c);
extern struct ScriptVm *VM_Create(u32 heapId, const struct ScriptVmParams *params);
extern void VM_Init(struct ScriptVm *vm, void *user);
extern void VM_Start(struct ScriptVm *vm, u8 *pc);
extern int VM_Control(struct ScriptVm *vm);
extern struct Node *func_02030DA8(struct Ctx *c, u32 a, u32 b, u32 key);
extern void NNS_FndAppendListObject(void *, void *);
extern void func_02030EAC(struct Node *n);
extern void NNS_FndRemoveListObject(volatile struct DList *list, void *elem);
extern void VEC_MultAdd(int, void *, void *, void *);
extern void VEC_Add(const Vec *, const Vec *, Vec *);
extern u32 VM_GetU32(struct Cursor *p);
extern void STA_ACTING_PlayRankSe(char *p);
extern void STA_ACTING_SetCameraPos(void *, u16);
extern void STA_ACTING_SetCameraTarget(u8 *p, u16 v);
extern void STA_ACTING_ShowAnim(char *p);
extern void STA_ACTING_ScheduleActions(char *p, int mode, u8 slot);
extern void STA_ACTING_HideAnim(char *p);
extern void STA_ACT_LIGHT_SetSlotVisible(char *, char *, int);
extern int STA_ACT_LIGHT_SetActorFlagB(int unused, int *p, int flag);
extern void STA_ACT_LIGHT_SetActorPos(void *unused, u32 *p, const u32 *q);
extern void VEC_Subtract(void *,void *,void *);
extern void STA_ACT_LIGHT_ResetRenderAnim(char *, char *);
extern void STA_ACT_LIGHT_StartRenderAnim(int a, u8 *p);
extern void STA_ACT_LIGHT_SetRenderAnim(int, void *, u8);
extern void STA_ACT_LIGHT_SetActorVisible(int a, u8 *p, int b);
extern int STA_ACT_LIGHT_SetElemValue(int a0, int *a1, int a2);
extern void STA_ACTING_PositionAnim(char *p, unsigned i);
extern void STA_ACTING_SetSelection(char *,unsigned char,int);
extern void STA_ACTING_LoadRankAnim(unsigned char *,unsigned char,unsigned char);
extern void STA_ACTING_LoadAnimMember(char *p, u8 n, u8 mask);
extern void STA_ACT_LIGHT_SetActorOffset(void *unused, u32 *p, const u32 *q);
extern int func_0209C0A4();
extern void STA_ACT_LIGHT_SetActorAngle(int self, char *p, u16 v);
extern u16 STA_ACTING_GetRecordScore(char *p, u32 i);
extern u16 STA_ACTING_GetBonus(char *p, u32 i);
extern void STA_ACTING_SetField10(char *p, u32 v);
extern int _s32_to_float(int a);
extern u32 func_0209C494(u32 a);
extern u32 func_0209CB8C(u32 a, u32 b);
extern u32 func_0209CE10(u32 a, u32 b);
extern void *STA_ACTING_GetActObj(void *p);
extern struct Entry *STA_ACT_OBJ_AddEntry(struct Object *,unsigned short);
extern void STA_ACTING_SetSlot(void *p, void *v, u32 i);
extern unsigned int *STA_ACTING_GetSlot(void *,unsigned char);
extern void STA_ACT_OBJ_FreeEntry(unsigned int *,unsigned int *);
extern void STA_ACT_LIGHT_SetElemVisible(char *,unsigned int *,unsigned int);
extern void STA_ACT_OBJ_SetEntryTarget(void *,u32 *,u32 *);
extern void STA_ACT_OBJ_GetEntryTarget(void *,u32 *,u32 *);
extern void *STA_ACTING_GetAnimHandle(void *p);
extern void STA_ACTING_SetAnimSlot(void *p, void *v, u32 i);
extern void *STA_ACTING_GetAnimSlot(void *,u8);
extern u8 *STA_ACT_LIGHT_CreateActor(u8 *p, int v);
extern void STA_ACT_LIGHT_SetElemA(void *a, char *p, u16 b, u8 c);
extern void STA_ACT_LIGHT_SetElemB(void *a, char *p, u32 b, u32 c);
extern void STA_ACTING_SetCharSlot(void *,void *,u8);
extern void STA_ACTING_MarkDirty(char *p);
extern void STA_ACT_LIGHT_DeleteActor(void *,u8 *);
extern void STA_ACT_LIGHT_CopyElemA(void *unused, u32 *p, const u32 *q);
extern void *STA_ACTING_GetBoard(void *p);
extern void STA_ACTING_PrintText(u8 *,u16,u32);
extern void STA_ACTING_ClearText(u8 *p);
extern void GF_FONT_SetTextColor(u32 r, u32 g, u32 b);
extern void STA_ACTING_InstallBgm(char *p, int a);
extern void STA_ACTING_StartSeq(char *p, int a);
extern void STA_ACTING_StopSeq(char *p);
extern int STA_ACTING_ReplaceWaveData(char *p, u32 a, u32 b, u32 d);
extern void STA_ACTING_PlayBgm(char *p, int a);
extern void STA_ACTING_StopBgm(char *p);
extern void *ICA_ANIME_GetField1C(const struct Ctx *p);
extern void GAME_COMM_Start(struct Comm *p, u32 a1, u32 a2);
extern void GAME_COMM_RequestExitNoCallback(struct Comm *);
extern u8 *GAME_DATA_GetMyStatus(void *p);
extern void GFL_NET_StartSession(struct Req *req, u32 a2, u32 a3);
extern void MYSTATUS_Copy(void *, void *);
extern void OS_GetMacAddress(void *);
extern int GFL_NET_GetNegotiationNum(void);
extern int GFL_NET_Exit(int);
extern void GFL_NET_COMMAND_DeleteCommandTable(u32);
extern void GFL_NET_SetLoginOption(u8 a0);
extern u32 func_0200FB24(void);
extern u32 GFL_NET_IsParentAid(void);
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
extern int GFL_NET_SendToHandle(struct Entry *a, u32 b, u32 c, u32 d);
extern void ICA_ANIME_SetField30(struct Ctx *p, u32 v);
extern int GFL_NET_IsSessionNull(void);
extern void GFL_NET_COMMAND_AddCommandTable(u32,u32,u32,u32);
extern void *GAME_DATA_GetSaveBlock2A(void *);
extern u32 POKE_TOOL_GetPartyParamSize(void);
extern u32 POKE_TOOL_GetBoxParamSize(void);
extern int MYSTATUS_GetSize(void);
extern void MI_CpuFill8(void *,u8,u32);
extern u16 MUSICAL_SAVE_GetFanPoints(struct Big *p);
extern u32 GF_STANDARD_Rand(void);
extern int STA_NET_SendRandomOrder(u8 *p);
extern int STA_NET_NotifyHostKind4(u8 *p);
extern int STA_NET_SendSlot1Command(u8 *p);
extern int STA_NET_NotifyHostKind5(char *);
extern int STA_NET_NotifyHostKind6(char *);
extern int STA_NET_SendSlot2Command(u8 *p);
extern int STA_NET_SendSlot3Command(u8 *p);
extern int STA_NET_IsTransferDone(char *);
extern void STA_NET_UpdateTransferState(char *);
extern void GFL_NET_HANDLE_SetTimingSyncRange(struct Link *, unsigned int, unsigned int);
extern unsigned int GFL_NET_HANDLE_IsTimingSyncRange(struct Link *p, unsigned int lo, unsigned int hi);
extern u32 GFL_NET_SendData(u32,u32,u32,u32,u32,u32,u32,u32);
extern struct Entry *GFL_NET_HANDLE_GetNetHandle(int);
extern void GFL_USE_PlaySeDefaultVolume(u32);
extern void MI_CpuCopy8(void *,void *,u32);
extern int func_020084BC(const u16 *values);
void STA_ACT_EFFECT_SetSceneField14(u8 *p,u32 v);
u32 STA_ACT_EFFECT_GetSceneOwner(u8 *p);
void STA_ACT_EFFECT_Noop(u8 *a0);
char *STA_ACT_EFFECT_Create(unsigned heap);
void STA_ACT_EFFECT_Delete(u8 *p);
int STA_ACT_EFFECT_Update(u8 *a0);
int STA_ACT_EFFECT_Draw(u8 *a0);
char *STA_ACT_EFFECT_StartSystem(char *p, u32 a);
void STA_ACT_EFFECT_KillSystem(u8 *unused,u8 *p);
void STA_ACT_EFFECT_StartEffect(char *p, unsigned i, Vec *v);
void STA_ACT_EFFECT_KillEffect(char *p, int i);
void STA_ACT_EFFECT_SetEmitterPos(char *p, int i, int a);
char *STA_ACT_AUDIENCE_Create(unsigned heap, void *a, unsigned b);
void STA_ACT_AUDIENCE_Delete(u8 *p);
void STA_ACT_AUDIENCE_Update(char *p);
void STA_ACT_AUDIENCE_Noop(char *a0);
void STA_ACT_AUDIENCE_Noop2(void *p);
void STA_ACT_AUDIENCE_SetupRecords(char *p, char *q);
void STA_ACT_AUDIENCE_Noop3(void *a0);
void STA_ACT_AUDIENCE_UpdateRecords(char *p);
void STA_ACT_AUDIENCE_UpdateRecord(char *p,u8 *rec);
void STA_ACT_AUDIENCE_DrawRecord(char *p,u8 *rec,unsigned type);
void STA_ACT_AUDIENCE_ApplyChoices(char *p);
void STA_ACT_AUDIENCE_RandomizeRecords(char *p);
void STA_ACT_AUDIENCE_SetSlotValue(char *p, int i, int v);
void STA_ACT_AUDIENCE_SetHighlight(char *p, u8 v);
void STA_ACT_AUDIENCE_SetBgScroll(void *unused, int x);
char *STA_ACT_BUTTON_Create(unsigned heap, void *a, char *b);
void STA_ACT_BUTTON_Delete(char *p);
void STA_ACT_BUTTON_Update(char *p);
void STA_ACT_BUTTON_CreateActors(char *p);
void STA_ACT_BUTTON_LoadCharacter(u8 *p,u16 slot,int resource,u32 type);
void STA_ACT_BUTTON_SetVisible(char *p, unsigned flag);
void *STA_ACT_SCRIPT_Create(u32 heap, void *owner);
void STA_ACT_SCRIPT_Delete(char *p);
void STA_ACT_SCRIPT_Update(char *p);
void *STA_ACT_SCRIPT_AddScript(char *p, void *arg, int flag);
char *STA_ACT_SCRIPT_AddScriptFromTable(char *p, char *base, unsigned index, unsigned char flag);
int STA_ACT_SCRIPT_RunScript(void *unused, char *p);
u8 STA_ACT_SCRIPT_CountScripts(char *p);
void *STA_ACT_SCRIPT_AddTask(char *p, u32 fn, u32 arg, u32 key);
void STA_ACT_SCRIPT_RemoveTask(char *p, char *q);
int STA_ACT_SCRIPT_StepTaskInt(char *p, int *out);
int STA_ACT_SCRIPT_StepTaskVec(char *p, int *out);
int STA_ACT_SCRIPT_StepTaskActor(char *p, void *out);
int STA_ACT_SCRIPT_TickSlot(char *p);
int STA_ACT_SCRIPT_SetWaitFlag(void *unused, char *p);
int STA_ACT_SCRIPT_SkipArg(void *a, char *p);
int STA_ACT_SCRIPT_SetWaitFromArg(void *a, u8 *p);
int STA_ACT_SCRIPT_SetRemainingWait(void *a, u8 *p);
int STA_ACT_SCRIPT_SetPendingFlag(int a, char *b);
int SCRIPT_COMMAND_CmdCameraTo224(void *unused, char *ctx);
int SCRIPT_COMMAND_CmdCameraTo0(void *unused, char *ctx);
int SCRIPT_COMMAND_CmdSetCameraPos(void *unused, char *ctx);
void SCRIPT_COMMAND_TaskCameraPos(void *unused, char *p);
int SCRIPT_COMMAND_CmdSetCameraTarget(void *unused, char *ctx);
void SCRIPT_COMMAND_TaskCameraTarget(void *unused, char *p);
int SCRIPT_COMMAND_CmdSkipArg(void *unused,char *p);
int SCRIPT_COMMAND_CmdShowAnim(int a, char **pp);
int SCRIPT_COMMAND_CmdHideAnim(void *a, void **pp);
int SCRIPT_COMMAND_GetActorMask(char *p, int i);
int SCRIPT_COMMAND_CmdSetActorFrame(int unused, char *p);
int SCRIPT_COMMAND_CmdSetActorVisible(int unused, char *p);
int SCRIPT_COMMAND_CmdSetActorPos(int unused,char *p);
int SCRIPT_COMMAND_CmdAddActorPos(int unused,char *p);
void SCRIPT_COMMAND_TaskActorMove(int unused,char *p);
int SCRIPT_COMMAND_CmdActorAnimRestart(int unused, char *p);
int SCRIPT_COMMAND_CmdActorAnimPause(int unused, char *p);
int SCRIPT_COMMAND_CmdSetActorFlag(int unused, char *p);
int SCRIPT_COMMAND_CmdSetActorScale(int unused, char *p);
int SCRIPT_COMMAND_CmdSetActorLight(int unused, char *p);
int SCRIPT_COMMAND_CmdPositionAnim(int unused, char *p);
int SCRIPT_COMMAND_CmdSetSelection(int unused,char *p);
int SCRIPT_COMMAND_CmdClearSelection(int unused,char *p);
int SCRIPT_COMMAND_CmdLoadRankAnim(int unused,char *p);
int SCRIPT_COMMAND_CmdLoadAnimMember(int unused,char *p);
int SCRIPT_COMMAND_CmdStartShake(int unused, char *p);
void SCRIPT_COMMAND_TaskShake(int unused, char *p);
int SCRIPT_COMMAND_CmdRotateActor(int unused,char *p);
void SCRIPT_COMMAND_TaskRotate(int a0, int *a1);
int SCRIPT_COMMAND_CmdCompareScores(int unused, Msg *m);
int SCRIPT_COMMAND_CmdSetFlags(int unused, char *p);
int SCRIPT_COMMAND_CmdAddEntry(int unused,char *p);
int SCRIPT_COMMAND_CmdFreeEntry(int unused,char *p);
int SCRIPT_COMMAND_CmdShowEntry(int unused,char *p);
int SCRIPT_COMMAND_CmdHideEntry(int unused,char *p);
int SCRIPT_COMMAND_CmdSetEntryTarget(int unused,char *p);
void SCRIPT_COMMAND_TaskEntryTarget(int unused,char *p);
int SCRIPT_COMMAND_CmdSetAnimSlot(int unused,char *p);
int SCRIPT_COMMAND_CmdFreeAnimSlot(int unused,char *p);
int SCRIPT_COMMAND_CmdStartEffect(int unused, char *p);
int SCRIPT_COMMAND_CmdKillEffect(int unused,char *p);
int SCRIPT_COMMAND_CmdMoveEffect(int unused,char *p);
void SCRIPT_COMMAND_TaskMoveEffect(int a, char *p);
int SCRIPT_COMMAND_CmdSetChar(int a,char **p);
int SCRIPT_COMMAND_CmdFreeChar(int unused,char *p);
int SCRIPT_COMMAND_CmdSetCharPos(int unused,char *p);
void SCRIPT_COMMAND_TaskCharMove(int unused,char *p);
int SCRIPT_COMMAND_CmdCharFollowActor(int unused,char *p);
void SCRIPT_COMMAND_TaskCharFollow(int unused,char *p);
int SCRIPT_COMMAND_CmdSetCharColor(int a,char **p);
int SCRIPT_COMMAND_CmdPrintText(int unused,char *p);
int SCRIPT_COMMAND_CmdClearText(void *a, void **pp);
int SCRIPT_COMMAND_CmdSetTextColor(int unused,char *p);
int SCRIPT_COMMAND_CmdInstallBgm(int a, char **pp);
int SCRIPT_COMMAND_CmdStartSeq(int a, char **pp);
int SCRIPT_COMMAND_CmdStopSeq(int a, char **pp);
int SCRIPT_COMMAND_CmdReplaceWave(int unused,char *p);
int SCRIPT_COMMAND_CmdPlayBgm(int a, char **pp);
int SCRIPT_COMMAND_CmdStopBgm(int a, char **pp);
void MUS_COMM_FUNC_Create(int a, void *b, void *c, int d);
void MUS_COMM_FUNC_Delete(char *p);
void *MUS_COMM_FUNC_StartSession(int a,char *p);
int MUS_COMM_FUNC_UpdateNetState(int *state,u8 *p);
int MUS_COMM_FUNC_WaitSessionNull(int unused,int unused1,void *p);
void MUS_COMM_FUNC_Task(int unused,int unused1,char *p);
void MUS_COMM_FUNC_SetHostFlag(char *p);
void MUS_COMM_FUNC_InitCommandTable(char *p);
void MUS_COMM_FUNC_InitWork(u8 *p,void *a,void *b,int unused,void *d,u16 heap);
void MUS_COMM_FUNC_DeleteBuffers(char *p);
void MUS_COMM_FUNC_SetReady(char *p);
void MUS_COMM_FUNC_Update(char *p);
void MUS_COMM_FUNC_SetTimingSync(int a, int b);
int MUS_COMM_FUNC_CheckTimingSync(char *p,int id);
int MUS_COMM_FUNC_GetSlotValueA(char *p,u32 index);
int MUS_COMM_FUNC_GetSlotValueB(char *p,u32 index);
char *MUS_COMM_FUNC_GetRecordPtr(char *p);
u32 MUS_COMM_FUNC_GetRecordSize(void);
int MUS_COMM_FUNC_Equals(int a,int b);
void MUS_COMM_FUNC_SendCommand(int unused,int kind,u32 value,u32 id);
u32 MUS_COMM_FUNC_SendCommandWait(int unused,int kind,u32 value,u32 id);
void MUS_COMM_FUNC_HandlePacket(unsigned long slot, int unused, const Packet *q, char *p);
u32 MUS_COMM_FUNC_SendMyStatus(Owner_021F9E40 *p);
void MUS_COMM_FUNC_SetEntryFlag(int i, int b, int c, T *p);
u32 MUS_COMM_FUNC_ClearEntryFlag(int i, T *p);
int MUS_COMM_FUNC_SendBoxData(char *p);
void MUS_COMM_FUNC_ReceiveBoxData(int a,int b,int c,char *p);
void *MUS_COMM_FUNC_ResetBoxFlags(int a,char *p);
int MUS_COMM_FUNC_SendStatusBlock(char *p, char *src);
void MUS_COMM_FUNC_SetRecordData(long i,int b,int c,struct Context *p);
void *MUS_COMM_FUNC_ClearRecordData(long i,struct Context *p);
int MUS_COMM_FUNC_SendRecordBlock(const char *p);
void MUS_COMM_FUNC_ReceiveRecordBlock(int a,int b,int c,const Owner_021FD22C *p);
extern const char d_021FDCB0[];
extern const char d_021FDCC4[];
extern u16 d_021FDC16[];
extern const char d_021FDCD8[];
extern const Key d_021FDC20;
extern char d_021FDCEC[];
extern char d_021FDC2C[];
extern const char d_021FDD00[];
extern const s16_021FA558 FX_SinCosTable_[];
extern const char d_021FDE5C[];
extern char d_021FDE4C[];
extern char d_021FDDEC[];
extern char d_021FDC38[];

int SCRIPT_COMMAND_CmdCompareScores(int unused, Msg *m)
{
    Obj_021FBA6C *o = m->f0;
    u32 vec[4];
    Vec3 v;
    Tag tag;
    u32 x = VM_GetU32(m->f4);
    u32 y = VM_GetU32(m->f4);
    void *h = STA_ACTING_GetActorSystem(o->f34);
    u32 idx;
    u32 total;
    u32 base;
    u32 maxabs = 0;
    s8 dir[4] = { 0, 0, 0, 0 };
    u16 max = 0;
    u8 i, j, k;

    for (i = 0; i < 4; i++) {
        u16 v = STA_ACTING_GetBonus(o->f34, i) + STA_ACTING_GetRecordScore(o->f34, i);
        if (max < v)
            max = v;
    }
    for (i = 0; i < 4; i++) {
        u16 v = STA_ACTING_GetBonus(o->f34, i) + STA_ACTING_GetRecordScore(o->f34, i);
        if (max == v)
            idx = i;
    }
    for (i = 0; i < 4; i++) {
        STA_ACT_LIGHT_CopyActorPos(h, STA_ACTING_GetActor(o->f34, i), &v.x);
        vec[i] = v.x;
        if (i == idx)
            base = v.x;
    }
    for (i = 0; i < 4; i++)
        vec[i] = vec[i] - base;
    for (i = 0; i < 4; i++) {
        if (i == idx)
            continue;
        for (j = 0; j < 4; j++) {
            if (i == j)
                continue;
            if ((int)vec[i] > 0 && (int)vec[j] >= 0 && (int)vec[i] > (int)vec[j])
                dir[i]++;
            else if ((int)vec[i] < 0 && (int)vec[j] <= 0 && (int)vec[i] < (int)vec[j])
                dir[i]--;
        }
        if ((int)maxabs < ABS(dir[i]))
            maxabs = (u8)ABS(dir[i]);
    }
    total = 0;
    for (k = 0; k < 4; k++) {
        R38 *a;
        tag.v = 0x54B;
        tag.v -= 0x1B;
        a = func_02030734(o->f0, 0x38, 0, d_021FDD00, tag.v);
        a->f30 = o;
        a->f00 = (u32)STA_ACTING_GetActor(o->f34, k);
        a->f04 = o->f34;
        a->f2E = 0;
        STA_ACT_LIGHT_CopyActorPos(h, (void *)a->f00, (u32 *)&a->f08);
        a->f14.x = base + (dir[k] << 18);
        a->f14.y = a->f08.y;
        a->f14.z = a->f08.z;
        a->f2C = func_0209C0A4(ABS(dir[k]) * x, maxabs);
        a->f20.x = func_0209C0A4(a->f14.x - a->f08.x, a->f2C);
        a->f20.y = func_0209C0A4(a->f14.y - a->f08.y, a->f2C);
        a->f20.z = func_0209C0A4(a->f14.z - a->f08.z, a->f2C);
        a->f34 = STA_ACT_SCRIPT_AddTask((char *)o, (u32)SCRIPT_COMMAND_TaskActorMove, (u32)a, 10);
        if (a->f2C != 0) {
            R20 *b = func_02030734(o->f0, 0x20, 0, d_021FDD00, 0x54B);
            u16 t = a->f2C;
            int rem = (u8)(t % 15) ? 1 : 0;
            b->f18 = o;
            b->f10 = STA_ACTING_GetActor(o->f34, k);
            b->f14 = 0x8000;
            b->f00 = o->f34;
            b->f04 = 0;
            b->f08 = 15;
            b->f0C = (u8)(t / 15 + rem);
            b->f1C = STA_ACT_SCRIPT_AddTask((char *)o, (u32)SCRIPT_COMMAND_TaskShake, (u32)b, 10);
        }
        total += a->f14.x;
    }
    {
        R18 *c = func_02030734(o->f0, 0x18, 0, d_021FDD00, 0x563);
        u32 f;
        c->f10 = o;
        c->f00 = o->f34;
        c->f0E = 0;
        c->f04 = STA_ACTING_GetCameraTarget((u8 *)o->f34);
        f = _s32_to_float((int)total / 4);
        f = func_0209CE10(f, 0x45800000);
        f = func_0209CB8C(f, 0x43000000);
        c->f08 = func_0209C494(f);
        c->f0C = x;
        c->f14 = STA_ACT_SCRIPT_AddTask((char *)o, (u32)SCRIPT_COMMAND_TaskCameraTarget, (u32)c, 10);
        STA_ACT_EFFECT_SetSceneField14((u8 *)o->f34, 1);
        STA_ACTING_SetField10(o->f34, 1);
        if (y == 1) {
            m->f14 = x;
            return 1;
        }
        return 0;
    }
}
