/*
 * file:     research_graph.c
 * unit:     yes
 * function: RESEARCH_GRAPH_Create, RESEARCH_GRAPH_Destroy, RESEARCH_GRAPH_Update, RESEARCH_GRAPH_GetVisible, RESEARCH_GRAPH_GetActive, RESEARCH_GRAPH_Init, RESEARCH_GRAPH_UpdateIntro, RESEARCH_GRAPH_HandleInput, RESEARCH_GRAPH_HandleInputAlt, RESEARCH_GRAPH_EnterDrawSlow, RESEARCH_GRAPH_StepAnimation, RESEARCH_GRAPH_EnterFadeIn, RESEARCH_GRAPH_EnterFadeOut, RESEARCH_GRAPH_EnterDrawMedium, RESEARCH_GRAPH_EnterDrawMediumAlt, RESEARCH_GRAPH_ExitFade, RESEARCH_GRAPH_AdvanceWhileActive, RESEARCH_GRAPH_Cleanup, RESEARCH_GRAPH_SetStateChanged, RESEARCH_GRAPH_SetEntryHandled, RESEARCH_GRAPH_SetActive, RESEARCH_GRAPH_GetCount, RESEARCH_GRAPH_GetTransitionKind, RESEARCH_GRAPH_IncTimer, RESEARCH_GRAPH_PushCommand, RESEARCH_GRAPH_ProcessCommand, RESEARCH_GRAPH_StartSubState, RESEARCH_GRAPH_GetSubState, RESEARCH_GRAPH_IncSubState, RESEARCH_GRAPH_SelectPrev, RESEARCH_GRAPH_SelectNext, RESEARCH_GRAPH_SelectDirect, RESEARCH_GRAPH_ApplySelection, RESEARCH_GRAPH_MoveGroupBackward, RESEARCH_GRAPH_MoveGroupForward, RESEARCH_GRAPH_MoveEntryForward, RESEARCH_GRAPH_MoveEntryBackward, RESEARCH_GRAPH_MoveToFirstEntry, RESEARCH_GRAPH_MoveToSelectedEntry, RESEARCH_GRAPH_ToggleEntry, RESEARCH_GRAPH_FadeIn, RESEARCH_GRAPH_FadeOut, RESEARCH_GRAPH_CycleIndex, RESEARCH_GRAPH_SetIndex, RESEARCH_GRAPH_DrawIndexCursor, RESEARCH_GRAPH_DrawIndexCursorDim, RESEARCH_GRAPH_CycleGroup, RESEARCH_GRAPH_SetEntryFromSlice, RESEARCH_GRAPH_StepEntry, RESEARCH_GRAPH_ClearEntryIndex, RESEARCH_GRAPH_SyncArrow, RESEARCH_GRAPH_SetHighlightSelected, RESEARCH_GRAPH_SetHighlightA, RESEARCH_GRAPH_SetHighlightB, RESEARCH_GRAPH_SetHighlightC, RESEARCH_GRAPH_SetNormalA, RESEARCH_GRAPH_SetNormalB, RESEARCH_GRAPH_StartPaletteAnime, RESEARCH_GRAPH_SwapCenterPairs, RESEARCH_GRAPH_QuantizePosition, RESEARCH_GRAPH_SetCenterDepth, RESEARCH_GRAPH_SetSlicesFromGraphA, RESEARCH_GRAPH_SetSlicesFromGraphB, RESEARCH_GRAPH_UpdateCircles, RESEARCH_GRAPH_DrawCircles, RESEARCH_GRAPH_DrawSliceColor, RESEARCH_GRAPH_LayoutArrow, RESEARCH_GRAPH_UpdatePercentages, RESEARCH_GRAPH_HideAllPercentages, RESEARCH_GRAPH_ShowPercent, RESEARCH_GRAPH_ShowPercentages, RESEARCH_GRAPH_LayoutTouchRects, RESEARCH_GRAPH_LoadBackground, RESEARCH_GRAPH_PrintTitle, RESEARCH_GRAPH_PrintGroupLabel, RESEARCH_GRAPH_PrintKindLabel, RESEARCH_GRAPH_PrintSliceLabel, RESEARCH_GRAPH_PrintTimeLabel, RESEARCH_GRAPH_PrintTeamLabel, RESEARCH_GRAPH_SetTeamLabelVisible, RESEARCH_GRAPH_SetDetailLabelVisible, RESEARCH_GRAPH_LayoutActors, RESEARCH_GRAPH_SetTriangleActorVisible, RESEARCH_GRAPH_LayoutMarkerActor, RESEARCH_GRAPH_EnableOams, RESEARCH_GRAPH_EnableOamsA, RESEARCH_GRAPH_DisableOams, RESEARCH_GRAPH_SetOamEnabled, RESEARCH_GRAPH_StartSlotPaletteAnime, RESEARCH_GRAPH_StopSlotPaletteAnime, RESEARCH_GRAPH_IsSlotPaletteAnimeRunning, RESEARCH_GRAPH_UpdateSlotPalettes, RESEARCH_GRAPH_UpdatePaletteAnime, RESEARCH_GRAPH_RequestFadeIn, RESEARCH_GRAPH_RequestFadeOut, RESEARCH_GRAPH_IsFadeDone, RESEARCH_GRAPH_TransferPalettes, RESEARCH_GRAPH_CheckQuestionnaireUpdated, RESEARCH_GRAPH_ClearUpdatedFlag, RESEARCH_GRAPH_TickTimer, RESEARCH_GRAPH_ResetTimer, RESEARCH_GRAPH_GetContext, RESEARCH_GRAPH_GetAppResource, RESEARCH_GRAPH_SetHeapId, RESEARCH_GRAPH_GetOwner, RESEARCH_GRAPH_SetOwner, RESEARCH_GRAPH_GetInputFlag, RESEARCH_GRAPH_SetGraphKind, RESEARCH_GRAPH_GetLeftCircle, RESEARCH_GRAPH_GetRightCircle, RESEARCH_GRAPH_AreCirclesIdle, RESEARCH_GRAPH_GetGroupKey, RESEARCH_GRAPH_GetGroupCount, RESEARCH_GRAPH_GetEntryKey, RESEARCH_GRAPH_GetGroupValue, RESEARCH_GRAPH_GetGroupTotalA, RESEARCH_GRAPH_GetGroupTotalB, RESEARCH_GRAPH_GetEntryValue, RESEARCH_GRAPH_GetEntryValueA, RESEARCH_GRAPH_GetEntryValueB, RESEARCH_GRAPH_GetFirstSaveGroup, RESEARCH_GRAPH_GetEntryIdBySave, RESEARCH_GRAPH_GetPlayTimeGroupId, RESEARCH_GRAPH_GetSaveBits, RESEARCH_GRAPH_GetClactUnit, RESEARCH_GRAPH_GetSharedHandle, RESEARCH_GRAPH_GetMarkerActor, RESEARCH_GRAPH_Alloc, RESEARCH_GRAPH_InitFields, RESEARCH_GRAPH_Free, RESEARCH_GRAPH_ClearCommandQueue, RESEARCH_GRAPH_CreateCommandQueue, RESEARCH_GRAPH_DestroyCommandQueue, RESEARCH_GRAPH_ClearFont, RESEARCH_GRAPH_CreateFont, RESEARCH_GRAPH_DeleteFont, RESEARCH_GRAPH_ClearMessages, RESEARCH_GRAPH_CreateMessages, RESEARCH_GRAPH_DeleteMessages, RESEARCH_GRAPH_ClearWordSet, RESEARCH_GRAPH_CreateWordSet, RESEARCH_GRAPH_DeleteWordSet, RESEARCH_GRAPH_ClearCircles, RESEARCH_GRAPH_CreateCircles, RESEARCH_GRAPH_DestroyCircles, RESEARCH_GRAPH_ClearGraphTable, RESEARCH_GRAPH_BuildGraphTable, RESEARCH_GRAPH_InitTouchRects, RESEARCH_GRAPH_ClearArrow, RESEARCH_GRAPH_CreateArrow, RESEARCH_GRAPH_DestroyArrow, RESEARCH_GRAPH_ClearPercentages, RESEARCH_GRAPH_CreatePercentages, RESEARCH_GRAPH_DestroyPercentages, RESEARCH_GRAPH_InitScreen, RESEARCH_GRAPH_InitOverlayBackgrounds, RESEARCH_GRAPH_ExitOverlayBackgrounds, RESEARCH_GRAPH_LoadBackground6, RESEARCH_GRAPH_DummyBg7, RESEARCH_GRAPH_UpdateBackground7, RESEARCH_GRAPH_ShowBackground7, RESEARCH_GRAPH_LoadBackground2, RESEARCH_GRAPH_DummyBg3, RESEARCH_GRAPH_UpdateBackground3, RESEARCH_GRAPH_ShowBackground3, RESEARCH_GRAPH_ClearLabels, RESEARCH_GRAPH_CreateLabels, RESEARCH_GRAPH_DestroyLabels, RESEARCH_GRAPH_RegisterEntryResources, RESEARCH_GRAPH_ReleaseEntryResources, RESEARCH_GRAPH_RegisterCursorResources, RESEARCH_GRAPH_ReleaseCursorResources, RESEARCH_GRAPH_ClearUnits, RESEARCH_GRAPH_CreateUnits, RESEARCH_GRAPH_DeleteUnits, RESEARCH_GRAPH_ClearActors, RESEARCH_GRAPH_CreateActors, RESEARCH_GRAPH_DeleteActors, RESEARCH_GRAPH_ClearBmps, RESEARCH_GRAPH_CreateBmps, RESEARCH_GRAPH_DrawBmps, RESEARCH_GRAPH_DrawBadge, RESEARCH_GRAPH_DeleteBmps, RESEARCH_GRAPH_CreateOamSys, RESEARCH_GRAPH_DeleteOamSys, RESEARCH_GRAPH_CreateOamObjects, RESEARCH_GRAPH_DeleteOamObjects, RESEARCH_GRAPH_ClearPalAnm, RESEARCH_GRAPH_CreatePalAnm, RESEARCH_GRAPH_DeletePalAnm, RESEARCH_GRAPH_ClearPaletteAnime, RESEARCH_GRAPH_CreatePaletteAnime, RESEARCH_GRAPH_DestroyPaletteAnime, RESEARCH_GRAPH_BindPaletteAnime, RESEARCH_GRAPH_RestorePaletteAnime, RESEARCH_GRAPH_RestartNetwork, RESEARCH_GRAPH_RegisterVBlank, RESEARCH_GRAPH_UnregisterVBlank, RESEARCH_GRAPH_ClampByte, RESEARCH_GRAPH_OpenComm, RESEARCH_GRAPH_GetCommKindOrStart, RESEARCH_GRAPH_ClearNotifyFlag
 * address:  0x021BD5F4
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from research_top.c, unit_021BFFC8.c, queue.c, palette_anime.c, PALETTE_ANIME_ReleaseOriginal.c by tools/splitfile.py.
 *
 * symbols:
 *   GAMESYSTEM_TryStartAutoComm  0x020121CC  thumb
 *   BG_SYS_SetGraphicsMode  0x0203FC28  arm
 *   BG_SYS_InitBgLayer  0x0203FCA0  arm
 *   ARC_TOOL_CreateHandle 0x020490F4 arm
 *   ARC_TOOL_LoadHandleMember 0x02049250 arm
 *   GFL_HEAP_Free 0x020307B0 arm
 *   NNS_G2dGetUnpackedScreenData 0x02062B30 arm
 *   BG_SYS_DrawTile 0x02041090 arm
 *   BG_SYS_PushTile 0x020409B4 arm
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
 *   G2x_SetBlendAlpha_ 0x0207D63C arm
 *   BMP_WIN_Init 0x02045088 arm
 *   BG_SYS_SetTileUnit  0x02040DA8  arm
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
 *   SYMBOL_SAVE_GetBitBlock 0x0200E394 thumb
 *   MISC_SAVEDATA_GetStatusByte 0x0200E44C thumb
 *   BMP_OAM_SetPalette  0x02025A54  thumb
 *   BG_SYS_FillTileMap 0x020413B0 arm
 *   CLACT_AddActorSurfacePos 0x0204B404 arm
 *   CLACT_SetActorAutoAnim 0x0204B92C arm
 *   BgTextLabel_SetVisible  0x021C0FF8  thumb  ov217
 *   _s32_div_f  0x0209C0A4  arm
 *   PALANM_GetFadeRequestBits  0x02021ED8  thumb
 *   PALETTE_ANIME_IsRunning  0x021C2A10  thumb  ov217
 *   BMP_OAM_SetEnabled  0x02025774  thumb
 *   MSGDATA_CreateFromArchive 0x02045B38 arm
 *   CLACT_CreateUnit 0x0204B100 arm
 *   BMP_Create 0x02043678 arm
 *   BMP_CreateFromArchive 0x0204384C arm
 *   BMP_Blit 0x020439A0 arm
 *   MSGDATA_AllocString 0x02045EC0 arm
 *   BMP_Delete 0x020437AC arm
 *   PRINTSYS_PrintColor 0x0201C7D0 thumb
 *   BMP_OAM_CreateSys  0x02025538  thumb
 *   BMP_OAM_DeleteSys  0x02025588  thumb
 *   BMP_OAM_Create  0x020255A0  thumb
 *   BMP_OAM_UploadChars  0x020257D0  thumb
 *   BMP_OAM_Delete  0x0202570C  thumb
 *   PALANM_Delete  0x02021540  thumb
 *   GFL_USE_AddMainTask  0x020056A0  thumb
 *   ARROW_Update  0x021C20C4  thumb  ov217
 *   RESEARCH_GRAPH_InitOverlayBackgrounds  0x021BFFC8  thumb  ov217
 *   RESEARCH_GRAPH_LoadBackground6  0x021C00AC  thumb  ov217
 *   RESEARCH_GRAPH_UpdateBackground7  0x021C00FC  thumb  ov217
 *   RESEARCH_GRAPH_LoadBackground2  0x021C0124  thumb  ov217
 *   RESEARCH_GRAPH_UpdateBackground3  0x021C0174  thumb  ov217
 *   RESEARCH_GRAPH_CreateLabels  0x021C01B8  thumb  ov217
 *   RESEARCH_GRAPH_RegisterEntryResources  0x021C0250  thumb  ov217
 *   RESEARCH_GRAPH_RegisterCursorResources  0x021C02C8  thumb  ov217
 *   RESEARCH_GRAPH_CreateUnits  0x021C03A0  thumb  ov217
 *   RESEARCH_GRAPH_CreateActors  0x021C0408  thumb  ov217
 *   RESEARCH_GRAPH_CreateBmps  0x021C04CC  thumb  ov217
 *   RESEARCH_GRAPH_DrawBmps  0x021C04FC  thumb  ov217
 *   RESEARCH_GRAPH_DrawBadge  0x021C05B0  thumb  ov217
 *   RESEARCH_GRAPH_CreateOamSys  0x021C06C8  thumb  ov217
 *   RESEARCH_GRAPH_CreateOamObjects  0x021C06F0  thumb  ov217
 *   RESEARCH_GRAPH_CreatePalAnm  0x021C07BC  thumb  ov217
 *   RESEARCH_GRAPH_CreatePaletteAnime  0x021C083C  thumb  ov217
 *   RESEARCH_GRAPH_BindPaletteAnime  0x021C0878  thumb  ov217
 *   RESEARCH_GRAPH_RegisterVBlank  0x021C08D4  thumb  ov217
 *   RESEARCH_GRAPH_RestartNetwork  0x021C08C4  thumb  ov217
 *   RESEARCH_GRAPH_OpenComm 0x021C0918 thumb ov217
 *   RESEARCH_GRAPH_GetCommKindOrStart 0x021C093C thumb ov217
 *   GFL_USE_IsAnySeBusy  0x02006238  thumb
 *   CircleGraph_SetEnabled  0x021C1184  thumb  ov217
 *   CircleGraph_QueueDrawSlow  0x021C1154  thumb  ov217
 *   CircleGraph_QueueDrawMedium 0x021C1178 thumb ov217
 *   RESEARCH_GRAPH_ExitOverlayBackgrounds  0x021C0084  thumb  ov217
 *   RESEARCH_GRAPH_DummyBg7  0x021C00F8  thumb  ov217
 *   RESEARCH_GRAPH_ShowBackground7  0x021C0114  thumb  ov217
 *   RESEARCH_GRAPH_DummyBg3  0x021C0170  thumb  ov217
 *   RESEARCH_GRAPH_ShowBackground3  0x021C018C  thumb  ov217
 *   RESEARCH_GRAPH_DestroyLabels  0x021C0230  thumb  ov217
 *   RESEARCH_GRAPH_ReleaseEntryResources  0x021C02A8  thumb  ov217
 *   RESEARCH_GRAPH_ReleaseCursorResources  0x021C0358  thumb  ov217
 *   RESEARCH_GRAPH_DeleteUnits  0x021C03D0  thumb  ov217
 *   RESEARCH_GRAPH_DeleteActors  0x021C0494  thumb  ov217
 *   RESEARCH_GRAPH_DeleteBmps  0x021C06AC  thumb  ov217
 *   RESEARCH_GRAPH_DeleteOamSys  0x021C06E0  thumb  ov217
 *   RESEARCH_GRAPH_DeleteOamObjects  0x021C0794  thumb  ov217
 *   RESEARCH_GRAPH_DeletePalAnm  0x021C0800  thumb  ov217
 *   RESEARCH_GRAPH_DestroyPaletteAnime  0x021C085C  thumb  ov217
 *   RESEARCH_GRAPH_RestorePaletteAnime  0x021C08A8  thumb  ov217
 *   RESEARCH_GRAPH_UnregisterVBlank  0x021C08F0  thumb  ov217
 *   RESEARCH_GRAPH_ClearNotifyFlag  0x021C0968  thumb  ov217
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
 *   RESEARCH_GRAPH_ClampByte 0x021C0900 thumb ov217
 *   d_021C3628     0x021C3628  data   ov217  a4
 *   d_021C36B8 0x021C36B8 data a1
 *   d_021C369A 0x021C369A data a1
 *   BgTextLabel_PrintText 0x021C0F78 thumb ov217
 *   STRBUF_Create 0x020457B0 arm
 *   STRBUF_Delete 0x02045808 arm
 *   WORDSET_SetSlotNumber 0x0201EFA4 thumb
 *   WORDSET_SetSlotTag 0x0201EE0C thumb
 *   WORDSET_CopyTaggedText 0x0201F250 thumb
 *   d_021C3850 0x021C3850 data a2
 *   CLACT_SetActorAnimLoopCount 0x0204B9C4 arm
 *   d_021C3A34 0x021C3A34 data a4
 *   PALANM_RequestFade 0x0202173C thumb
 *   RESEARCH_COMMON_GetContext  0x021C09B0  thumb  ov217
 *   CircleGraph_IsAnimating  0x021C11F4  thumb  ov217
 *   d_021C363C 0x021C363C data ov217 a1
 *   d_021C3646 0x021C3646 data ov217 a1
 *   d_021C3632 0x021C3632 data ov217 a1
 *   SYMBOL_SAVE_GetQuestionnaireBits 0x0200E3A0 thumb
 *   SYMBOL_SAVE_GetQuestionnaireAnswer 0x0200E3A4 thumb
 *   GRAPHTABLE_GetEntryId 0x021C2644 thumb ov217
 *   GAME_DATA_GetPlayTime 0x02012FCC thumb
 *   PLAYTIME_GetHours 0x0200864C thumb
 *   MISC_SAVEDATA_GetHalfword  0x0200E458  thumb
 *   GFL_USE_GetMainTaskList 0x020056BC thumb
 *   RESEARCH_GRAPH_ClearLabels 0x021C019C thumb ov217
 *   RESEARCH_GRAPH_ClearUnits 0x021C0384 thumb ov217
 *   RESEARCH_GRAPH_ClearActors 0x021C03EC thumb ov217
 *   RESEARCH_GRAPH_ClearBmps 0x021C04B0 thumb ov217
 *   RESEARCH_GRAPH_ClearPalAnm 0x021C07B0 thumb ov217
 *   RESEARCH_GRAPH_ClearPaletteAnime 0x021C0820 thumb ov217
 *   d_021C3650 0x021C3650 data a4
 *   WORDSET_DeleteStrbufED04  0x0201ED04  thumb
 *   CircleGraph_Create 0x021C10C8 thumb ov217
 *   CircleGraph_Destroy 0x021C10D8 thumb ov217
 *   MI_CpuFill8  0x02082BCC  arm
 *   MISC_SAVEDATA_GetTallyWord 0x0200E47C thumb
 *   MISC_SAVEDATA_GetTallyValue 0x0200E4B0 thumb
 *   MISC_SAVEDATA_GetScoreValue 0x0200E4F8 thumb
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
 *   G3X_Init 0x0207D988 arm
 *   G3X_InitMtxStack 0x0207DB1C arm
 *   G3X_SetEdgeColorTable 0x0207DCF8 arm
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
 *   BG_SYS_SetLowBit 0x0204044C arm
 *   BG_SYS_SetPlaneVisible 0x02040588 arm
 *   d_021C366C 0x021C366C data a4
 *   d_021C36D8 0x021C36D8 data ov217
 *   d_021C36F8 0x021C36F8 data ov217
 *   d_021C3718 0x021C3718 data ov217
 *   d_021C3738 0x021C3738 data ov217
 *   d_021C3B7C 0x021C3B7C data ov217
 *   d_021C3620  0x021C3620  data  a2
 *   d_021C3618  0x021C3618  data  a1
 *   d_021C37FC 0x021C37FC data a4
 *   RESEARCH_GRAPH_GetSharedHandle 0x021BF9FC thumb ov217
 *   RESEARCH_GRAPH_GetClactUnit 0x021BF9F0 thumb ov217
 *   d_021C37A4  0x021C37A4  data  a4
 *   d_021C3C54  0x021C3C54  data  a4
 *   d_021C37D0  0x021C37D0  data  a4
 *   d_021C377C 0x021C377C data a4
 *   d_021C3A28  0x021C3A28  data  a4
 *   RESEARCH_GRAPH_TransferPalettes  0x021BF6BC  thumb  ov217
 *   TCB_DeleteTask  0x02030EAC  arm
 *   ICA_ANIME_GetField24  0x02012138  thumb
 *   GAME_COMM_RequestExitNoCallback  0x02026400  thumb
 *   GAME_COMM_GetKind  0x02026454  thumb
 *   GAME_COMM_SetNotifyFlag  0x02026498  thumb
 *   RESEARCH_GRAPH_GetContext  0x021BF734  thumb  ov217
 *   GFL_HEAP_Alloc  0x02030734  arm
 *   WORDSET_CreateDefault  0x0201EC64  thumb  arm9
 *   BG_SYS_Init  0x02040C14  arm  arm9
 *   BG_SYS_ClearSlot  0x020414EC  arm  arm9
 *   BG_SYS_Update  0x020419E4  arm  arm9
 *   BG_SYS_FreeLayerBuf  0x020403F4  arm  arm9
 */
#include "../../matched/include/G_Bg.h"
#include "research_shared_types.h"

struct MessageView;

struct WordSet;

struct PlayTime;

struct ResearchObjB {
    union { void * owner; u32 ownerU; };
    u16 heapId;
    u8 pad6[0x2];
    u32 font;
    void * msgBankA;
    u8 pad10[0x4];
    void * msgBankB;
    void * wordSet;
    u32 commandQueue;
    u32 state;
    u32 subState;
    u32 stateTimer;
    u32 count;
    u32 elapsedTimer;
    union { u32 cursorIndex; int cursorIndexSigned; };
    u8 titleGroup;
    u8 pad39[0x27F];
    u8 groupIndex;
    u8 entryIndex;
    u8 pad2BA[0x2];
    void * leftCircleA;
    void * leftCircleB;
    void * rightCircleA;
    void * rightCircleB;
    u32 graphKind;
    void * arrow;
    void * percentages[10];
    u8 percentageCount;
    u8 percentageVisible;
    u8 pad2FE[0x4A];
    int titleLabel;
    u32 groupLabel;
    u32 kindLabel;
    u32 sliceLabel;
    u32 timeLabel;
    u32 teamLabel;
    u32 emptyLabel;
    u32 detailLabel;
    u32 clactUnits[7];
    u32 units[4];
    void * markerActorA;
    void * markerActorB;
    u32 triangleActor;
    void * markerActor;
    u32 oamSys;
    void * oamObjectA;
    void * oamObjectB;
    void * bmps[2];
    void * palAnm;
    union { void * fadeParam; u32 fadeParamU; };
    u32 vblankNode;
    void * drawSystem;
    u32 entryShown;
    int touchSelected;
    u32 detailMode;
    u32 timerExpired;
    u32 updatedFlag;
    u32 stateChanged;
    u32 visible;
    u32 active;
};

struct GraphSliceInput { u8 id,pad[3]; u32 value; u8 x,y,z,quantX,quantY,quantZ,pad2[2]; };

struct GraphEntryView { u16 id; u8 x,y,z,pad; u16 valueA; u32 valueB; };

struct CursorLayoutRow { u8 x,y,w,h; int offsets[8]; };

typedef struct PaletteAnimeStart { u32 mode; u16 color; u8 pad[14]; } PaletteAnimeStart;

typedef struct MessageView { u32 owner; u16 heapId; u16 pad; u32 font; u32 messages[3]; } MessageView;

struct CursorRect { u8 x, y, w, h; };

struct ArrowCreateArgs { u32 charId; u32 paletteId; u32 cellId; u16 space; u16 animSeq[4]; };

struct PercentageCreateArgs { u32 charIndex; u32 paletteIndex; u32 cellAnimIndex; u16 priority; u16 digitAnimSeq; u16 signAnimSeq; };

extern u32 GAMESYSTEM_TryStartAutoComm(struct IcaAnime *p);

extern void GFL_NET_RestartWithDefaultTimeout(u32 a, u32 b);

extern void *ARC_TOOL_CreateHandle(unsigned int id, u32 heap);

extern void *ARC_TOOL_LoadHandleMember(struct ArcFile *, u32, u32);

extern u32 GFL_HEAP_Free(void *p);

extern int NNS_G2dGetUnpackedScreenData(void *, void **);

extern void BG_SYS_DrawTile(u32, u32, u32, u32, u8, u8);

extern int BG_SYS_PushTile(int);

extern void ARC_TOOL_DeleteHandle(void *);

extern void BG_SYS_FillTileMap(int index, int x0, int y0, int w, int h, int pal);

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

extern void *GFL_HEAP_Alloc(u32 heapId, u32 size, int clear, const char *site, u16 tag);

extern struct GfFont *GF_FONT_Create(int a0, int a1, int a2, int a3, u32 heapId);

extern u32 GF_FONT_Delete(void *ptr);

extern struct MsgBank *MSGDATA_CreateFromArchive(u32 resident, u32 arcId, u32 fileId, u32 heapId);

extern u32 MSGDATA_Delete(struct Rec *rec);

extern int RingQueue_Create(int a0, int a1);

extern void RingQueue_Destroy(void *p);

extern void BMP_WIN_Init(u16);

extern void BMP_WIN_Exit(void);

extern void BG_SYS_Init(u32 layer, u32 value, u32 count, u32 index);

extern u32 BG_SYS_ClearSlot();

extern void BG_SYS_SetTileUnit(u32, u32, u32);

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

extern void *SYMBOL_SAVE_GetBitBlock(void *a0);

extern int MISC_SAVEDATA_GetStatusByte(int p0, int p1);

extern void BMP_OAM_SetPalette(u8 *g, u32 a);

extern void CLACT_AddActorSurfacePos(struct Obj *p,const struct Vec2 *delta,u32 which);

extern void BgTextLabel_SetVisible(u8 *p, int visible);

extern int _s32_div_f(int a, int b);

extern int PALANM_RequestFade(PalAnmObj *, u16, u16, s16, u8, u8, u16, void *);

extern u32 PALANM_GetFadeRequestBits(const char *ptr);

extern u32 PALETTE_ANIME_IsRunning();

extern u32 PALANM_TransferPalettes(struct S02021D50 *p);

extern u32 BG_SYS_Update();

extern void BMP_OAM_SetEnabled(u8 *g, u32 a);

extern u32 GFL_USE_GetMainTaskList(void);

extern struct Bmp *BMP_Create(u32 width, u32 height, u32 depth, u16 heap);

extern struct Bmp *BMP_CreateFromArchive(u32,u32,u32,u32);

extern void BMP_Blit(struct Bmp *,struct Bmp *,u32,u32,int,int,u32,u32,u32);

extern void *MSGDATA_AllocString(struct MsgBank *,u32);

extern void PRINTSYS_PrintColor(void *,s16,s16,void *,void *,u16);

extern void BMP_OAM_DeleteSys(void *p);

extern void BMP_OAM_UploadChars(struct Obj *);

extern void BMP_OAM_Delete(struct Grid *g);

extern void *PALANM_Create(u32);

extern void PALANM_AllocSlotBuffers(struct PalAnmSlot *, u32, u32, u32);

extern void PALANM_CopyHwPaletteToSlot(struct PalAnmSlot *, u32, u32, u32);

extern u32 PALANM_Delete(void *a0);

extern void PALANM_FreeSlotBuffers(struct PalAnmSlot *slots, u32 idx);

extern int GFL_USE_AddMainTask(void (*)(void), void *, int);

extern void TCB_DeleteTask(struct Node *n);

extern void ARROW_Update(void *h);

void RESEARCH_GRAPH_InitOverlayBackgrounds(char *p);

void RESEARCH_GRAPH_LoadBackground6(char *p);

u32 RESEARCH_GRAPH_UpdateBackground7();

void RESEARCH_GRAPH_LoadBackground2(char *p);

u32 RESEARCH_GRAPH_UpdateBackground3();

void RESEARCH_GRAPH_CreateLabels(char *p);

void RESEARCH_GRAPH_RegisterEntryResources(char *p);

void RESEARCH_GRAPH_RegisterCursorResources(char *p);

void RESEARCH_GRAPH_CreateUnits(u8 *p);

void RESEARCH_GRAPH_CreateActors(u8 *p);

void RESEARCH_GRAPH_CreateBmps(u8 *p);

void RESEARCH_GRAPH_DrawBmps(u8 *p);

void RESEARCH_GRAPH_DrawBadge(u8 *p);

void RESEARCH_GRAPH_CreateOamSys(u8 *p);

void RESEARCH_GRAPH_CreateOamObjects(u8 *p);

void RESEARCH_GRAPH_CreatePalAnm(u8 *p);

void RESEARCH_GRAPH_CreatePaletteAnime(u8 *p);

void RESEARCH_GRAPH_BindPaletteAnime(u8 *p);

void RESEARCH_GRAPH_RegisterVBlank(char *p);

void RESEARCH_GRAPH_RestartNetwork(u32 a0);

void RESEARCH_GRAPH_OpenComm(u8 *a0);

int RESEARCH_GRAPH_GetCommKindOrStart(u8 *a0);

extern int GFL_USE_IsAnySeBusy(void);

extern void CircleGraph_SetEnabled(u8 *h, u32 v);

extern void CircleGraph_QueueDrawSlow(u8 *h);

extern void CircleGraph_QueueDrawMedium(u8 *h);

u32 RESEARCH_GRAPH_ExitOverlayBackgrounds();

void RESEARCH_GRAPH_DummyBg7();

void RESEARCH_GRAPH_ShowBackground7();

void RESEARCH_GRAPH_DummyBg3();

void RESEARCH_GRAPH_ShowBackground3();

void RESEARCH_GRAPH_DestroyLabels(int *p);

u32 RESEARCH_GRAPH_ReleaseEntryResources(u32 a0);

u32 RESEARCH_GRAPH_ReleaseCursorResources(u32 a0);

void RESEARCH_GRAPH_DeleteUnits(int *p);

void RESEARCH_GRAPH_DeleteActors(int *p);

void RESEARCH_GRAPH_DeleteBmps(int *p);

void RESEARCH_GRAPH_DeleteOamSys(u8 *a0);

void RESEARCH_GRAPH_DeleteOamObjects(int *p);

u32 RESEARCH_GRAPH_DeletePalAnm(u32 a0);

void RESEARCH_GRAPH_DestroyPaletteAnime(int *p);

void RESEARCH_GRAPH_RestorePaletteAnime(int *p);

void RESEARCH_GRAPH_UnregisterVBlank(u8 *a0);

void RESEARCH_GRAPH_ClearNotifyFlag(unsigned char *a0);

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

u32 RESEARCH_GRAPH_ClampByte(s32 v);

extern void BgTextLabel_PrintText(u8 *p, struct U16Vec *text);

extern struct U16Vec *STRBUF_Create(u32 capacity, u32 heapId);

extern void STRBUF_Delete(struct U16Vec *vec);

extern void WORDSET_SetSlotNumber(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);

extern void WORDSET_SetSlotTag(struct WordSet *p, u32 i, const void *src, u32 n, u32 f, u32 c);

extern void WORDSET_CopyTaggedText(struct WordSet *ws, void *dst, void *src);

extern void CLACT_SetActorAnimLoopCount(struct Actor *,unsigned);

extern u32 RESEARCH_COMMON_GetContext(u32 *p);

extern int CircleGraph_IsAnimating(u8 *p);

extern void *SYMBOL_SAVE_GetQuestionnaireBits(void *a);

extern u32 SYMBOL_SAVE_GetQuestionnaireAnswer(const u8 *, int);

extern u32 GRAPHTABLE_GetEntryId(void *, u32, u8);

extern int GAME_DATA_GetPlayTime(int);

extern u16 PLAYTIME_GetHours(const struct PlayTime *p);

extern u16 MISC_SAVEDATA_GetHalfword(const u16 *, int);

void RESEARCH_GRAPH_ClearLabels(void *p);

void RESEARCH_GRAPH_ClearUnits(void *p);

void RESEARCH_GRAPH_ClearActors(void *p);

void RESEARCH_GRAPH_ClearBmps(void *p);

void RESEARCH_GRAPH_ClearPalAnm(void *p);

void RESEARCH_GRAPH_ClearPaletteAnime(void *p);

extern struct WordSet *WORDSET_CreateDefault(u32 heap);

extern u32 WORDSET_DeleteStrbufED04(struct WordSet *p);

extern u32 CircleGraph_Create(u32 a0);

extern u32 CircleGraph_Destroy(void *a0);

extern void MI_CpuFill8(u32, u32, u32);

extern u32 MISC_SAVEDATA_GetTallyWord(u8 *p, int i);

extern u32 MISC_SAVEDATA_GetTallyValue(u8 *a0, u32 a1, u32 a2);

extern int MISC_SAVEDATA_GetScoreValue(int a0, int a1, int a2);

extern u32 ARROW_Create(u32, u32);

extern u32 ARROW_Destroy(void *a0);

extern u32 PERCENTAGE_Create(u32, u32, u32);

extern u32 PERCENTAGE_Destroy(void *a0);

extern void G3X_Init(void);

extern void G3X_InitMtxStack(void);

extern void G3X_SetEdgeColorTable(const void *);

void *RESEARCH_GRAPH_Create(void *p);

u32 RESEARCH_GRAPH_Destroy(void *a0);

void RESEARCH_GRAPH_Update(unsigned char *p);

u32 RESEARCH_GRAPH_GetVisible(void *p);

u32 RESEARCH_GRAPH_GetActive(void *p);

void RESEARCH_GRAPH_Init(unsigned char *p);

void RESEARCH_GRAPH_UpdateIntro(u32 a0);

void RESEARCH_GRAPH_HandleInput(u8 *p);

void RESEARCH_GRAPH_HandleInputAlt(u8 *p);

void RESEARCH_GRAPH_EnterDrawSlow(u8 *p);

void RESEARCH_GRAPH_StepAnimation(u8 *p);

void RESEARCH_GRAPH_EnterFadeIn(u32 a0);

void RESEARCH_GRAPH_EnterFadeOut(u32 a0);

void RESEARCH_GRAPH_EnterDrawMedium(char *p);

void RESEARCH_GRAPH_EnterDrawMediumAlt(char *p);

void RESEARCH_GRAPH_ExitFade(u32 a0);

void RESEARCH_GRAPH_AdvanceWhileActive(u32 a0);

void RESEARCH_GRAPH_Cleanup(u8 *a0);

void RESEARCH_GRAPH_SetStateChanged(void *p);

void RESEARCH_GRAPH_SetEntryHandled(u8 *a0, u32 a1);

void RESEARCH_GRAPH_SetActive(void *p, u32 v);

u32 RESEARCH_GRAPH_GetCount(void *p);

u32 RESEARCH_GRAPH_GetTransitionKind(u8 *a0);

void RESEARCH_GRAPH_IncTimer(void *p);

void RESEARCH_GRAPH_PushCommand(u8 *a0, u32 a1);

void RESEARCH_GRAPH_ProcessCommand(u32 a0);

void RESEARCH_GRAPH_StartSubState(void *p, u32 v);

u32 RESEARCH_GRAPH_GetSubState(void *p);

void RESEARCH_GRAPH_IncSubState(void *p);

void RESEARCH_GRAPH_SelectPrev(u8 *p);

void RESEARCH_GRAPH_SelectNext(u8 *p);

u32 RESEARCH_GRAPH_SelectDirect(u32 a0, u32 a1);

void RESEARCH_GRAPH_ApplySelection(u8 *a0, u32 a1);

void RESEARCH_GRAPH_MoveGroupBackward(char *p);

void RESEARCH_GRAPH_MoveGroupForward(char *p);

u32 RESEARCH_GRAPH_MoveEntryForward(u32 a0);

u32 RESEARCH_GRAPH_MoveEntryBackward(u32 a0);

void RESEARCH_GRAPH_MoveToFirstEntry(char *p);

void RESEARCH_GRAPH_MoveToSelectedEntry(char *p);

void RESEARCH_GRAPH_ToggleEntry(char *p);

void RESEARCH_GRAPH_FadeIn(void);

void RESEARCH_GRAPH_FadeOut(void);

void RESEARCH_GRAPH_CycleIndex(char *p, int a);

void RESEARCH_GRAPH_SetIndex(void *p, u32 v);

int RESEARCH_GRAPH_DrawIndexCursor(char *p);

void RESEARCH_GRAPH_DrawIndexCursorDim(u8 *p);

void RESEARCH_GRAPH_CycleGroup(char *p, int a);

void RESEARCH_GRAPH_SetEntryFromSlice(char *p);

void RESEARCH_GRAPH_StepEntry(u8 *p, int step);

void RESEARCH_GRAPH_ClearEntryIndex(u8 *a0);

void RESEARCH_GRAPH_SyncArrow(u8 *p);

void RESEARCH_GRAPH_SetHighlightSelected(u32 a0);

void RESEARCH_GRAPH_SetHighlightA(u32 a0);

void RESEARCH_GRAPH_SetHighlightB(u32 a0);

void RESEARCH_GRAPH_SetHighlightC(u32 a0);

void RESEARCH_GRAPH_SetNormalA(u32 a0);

void RESEARCH_GRAPH_SetNormalB(u32 a0);

void RESEARCH_GRAPH_StartPaletteAnime(u32 *p);

void RESEARCH_GRAPH_SwapCenterPairs(void *p);

void RESEARCH_GRAPH_QuantizePosition(u32 a0);

void RESEARCH_GRAPH_SetCenterDepth(void *p);

void RESEARCH_GRAPH_SetSlicesFromGraphA(u8 *p,int mode);

void RESEARCH_GRAPH_SetSlicesFromGraphB(u8 *p, u32 mode);

void RESEARCH_GRAPH_UpdateCircles(char *p);

void RESEARCH_GRAPH_DrawCircles(char *p);

void RESEARCH_GRAPH_DrawSliceColor(char *p);

void RESEARCH_GRAPH_LayoutArrow(char *p);

void RESEARCH_GRAPH_UpdatePercentages(char *p);

void RESEARCH_GRAPH_HideAllPercentages(char *p);

void RESEARCH_GRAPH_ShowPercent(u8 *a0, u32 a1);

void RESEARCH_GRAPH_ShowPercentages(char *p);

void RESEARCH_GRAPH_LayoutTouchRects(u8 *p);

void RESEARCH_GRAPH_LoadBackground(char *p);

void RESEARCH_GRAPH_PrintTitle(char *p);

void RESEARCH_GRAPH_PrintGroupLabel(char *p);

void RESEARCH_GRAPH_PrintKindLabel(char *p);

void RESEARCH_GRAPH_PrintSliceLabel(char *p);

void RESEARCH_GRAPH_PrintTimeLabel(char *p);

void RESEARCH_GRAPH_PrintTeamLabel(char *p);

void RESEARCH_GRAPH_SetTeamLabelVisible(char *p);

void RESEARCH_GRAPH_SetDetailLabelVisible(char *p);

void RESEARCH_GRAPH_LayoutActors(char *p);

void RESEARCH_GRAPH_SetTriangleActorVisible(char *p);

void RESEARCH_GRAPH_LayoutMarkerActor(char *p);

void RESEARCH_GRAPH_EnableOams(void *a0);

void RESEARCH_GRAPH_EnableOamsA(void *a0);

void RESEARCH_GRAPH_DisableOams(void *a0);

void RESEARCH_GRAPH_SetOamEnabled(u8 *p, u32 i, u32 j);

void RESEARCH_GRAPH_StartSlotPaletteAnime(char *p, int i);

void RESEARCH_GRAPH_StopSlotPaletteAnime(u8 *a0, u32 a1);

u32 RESEARCH_GRAPH_IsSlotPaletteAnimeRunning(u8 *a0, u32 a1);

void RESEARCH_GRAPH_UpdateSlotPalettes(int *p);

void RESEARCH_GRAPH_UpdatePaletteAnime(u8 *a0);

void RESEARCH_GRAPH_RequestFadeIn(char *p);

void RESEARCH_GRAPH_RequestFadeOut(char *p);

u32 RESEARCH_GRAPH_IsFadeDone(u8 *a0);

u32 RESEARCH_GRAPH_TransferPalettes(u32 a0, u32 a1);

void RESEARCH_GRAPH_CheckQuestionnaireUpdated(char *p);

void RESEARCH_GRAPH_ClearUpdatedFlag(void *p);

void RESEARCH_GRAPH_TickTimer(void *p);

void RESEARCH_GRAPH_ResetTimer(void *p);

u32 RESEARCH_GRAPH_GetContext(u8 *a0);

u32 RESEARCH_GRAPH_GetAppResource(u8 *a0);

void RESEARCH_GRAPH_SetHeapId(void *p, u32 v);

u32 RESEARCH_GRAPH_GetOwner(void *p);

void RESEARCH_GRAPH_SetOwner(void *p, u32 v);

u32 RESEARCH_GRAPH_GetInputFlag(void *p);

void RESEARCH_GRAPH_SetGraphKind(void *p, u32 v);

u8 *RESEARCH_GRAPH_GetLeftCircle(void *p);

u8 *RESEARCH_GRAPH_GetRightCircle(void *p);

u32 RESEARCH_GRAPH_AreCirclesIdle(u32 a0);

u32 RESEARCH_GRAPH_GetGroupKey(void *p);

u32 RESEARCH_GRAPH_GetGroupCount(void *p);

u32 RESEARCH_GRAPH_GetEntryKey(void *p);

u32 RESEARCH_GRAPH_GetGroupValue(void *p);

u32 RESEARCH_GRAPH_GetGroupTotalA(void *p);

u32 RESEARCH_GRAPH_GetGroupTotalB(void *p);

u32 RESEARCH_GRAPH_GetEntryValue(char *p);

u32 RESEARCH_GRAPH_GetEntryValueA(void *p);

u32 RESEARCH_GRAPH_GetEntryValueB(void *p);

u8 RESEARCH_GRAPH_GetFirstSaveGroup(u8 *p);

u32 RESEARCH_GRAPH_GetEntryIdBySave(u8 *p);

u32 RESEARCH_GRAPH_GetPlayTimeGroupId(u8 *p);

u16 RESEARCH_GRAPH_GetSaveBits(u32 a0);

u32 RESEARCH_GRAPH_GetClactUnit(void *p, u32 i);

u32 RESEARCH_GRAPH_GetSharedHandle(void *p, u32 i);

u32 RESEARCH_GRAPH_GetMarkerActor(void *p, u32 i);

u32 RESEARCH_GRAPH_Alloc(u32 a0);

void RESEARCH_GRAPH_InitFields(char *p);

u32 RESEARCH_GRAPH_Free(void *a0);

void RESEARCH_GRAPH_ClearCommandQueue(void *p);

void RESEARCH_GRAPH_CreateCommandQueue(u32 a0);

void RESEARCH_GRAPH_DestroyCommandQueue(u8 *a0);

void RESEARCH_GRAPH_ClearFont(void *p);

void RESEARCH_GRAPH_CreateFont(u32 a0);

void RESEARCH_GRAPH_DeleteFont(u8 *a0);

void RESEARCH_GRAPH_ClearMessages(void *p);

void RESEARCH_GRAPH_CreateMessages(MessageView *p);

void RESEARCH_GRAPH_DeleteMessages(int *p);

void RESEARCH_GRAPH_ClearWordSet(void *p);

void RESEARCH_GRAPH_CreateWordSet(u32 a0);

void RESEARCH_GRAPH_DeleteWordSet(u8 *a0);

void RESEARCH_GRAPH_ClearCircles(void *p);

void RESEARCH_GRAPH_CreateCircles(char *p);

void RESEARCH_GRAPH_DestroyCircles(char *p);

void RESEARCH_GRAPH_ClearGraphTable(u8 *a0);

void RESEARCH_GRAPH_BuildGraphTable(char *p);

void RESEARCH_GRAPH_InitTouchRects(u8 *p);

void RESEARCH_GRAPH_ClearArrow(void *p);

void RESEARCH_GRAPH_CreateArrow(char *p);

void RESEARCH_GRAPH_DestroyArrow(u8 *a0);

void RESEARCH_GRAPH_ClearPercentages(void *p);

void RESEARCH_GRAPH_CreatePercentages(char *p);

void RESEARCH_GRAPH_DestroyPercentages(int *p);

void RESEARCH_GRAPH_InitScreen(void);

extern struct CursorLayoutRow d_021C3AC8[];

extern unsigned char d_021C3628[];

extern u8 d_021C36B8[];

extern u8 d_021C369A[];

extern const u16 d_021C3850[];

extern PaletteAnimeStart d_021C3A34[];

extern const u8 d_021C363C[];

extern const u8 d_021C3646[];

extern const u8 d_021C3632[];

extern u32 d_021C3650[];

extern u8 d_021C367C[];

extern u8 d_021C3D44[][17];

extern struct Bg d_021C386C;

extern u8 d_021C3900[];

extern u8 d_021C3994[];

extern const struct CursorRect d_021C3758[];

extern const u16 d_021C365C[];

void *RESEARCH_GRAPH_Create(void *p)
{
    void *r;
    void *a;
    a = (void *)RESEARCH_COMMON_GetHeapId(p);
    r = (void *)RESEARCH_GRAPH_Alloc((u32)a);
    RESEARCH_GRAPH_InitFields(r);
    RESEARCH_GRAPH_SetHeapId(r, (u32)a);
    RESEARCH_GRAPH_SetOwner(r, (u32)p);
    return r;
}

u32 RESEARCH_GRAPH_Destroy(void *a0)
{
    RESEARCH_GRAPH_DestroyCommandQueue((u8 *)a0);
    return RESEARCH_GRAPH_Free(a0);
}

void RESEARCH_GRAPH_Update(unsigned char *p)
{
    switch (((struct ResearchObjB *)p)->state) {
    case 0: RESEARCH_GRAPH_Init(p); break;
    case 1: RESEARCH_GRAPH_UpdateIntro((u32)p); break;
    case 2: RESEARCH_GRAPH_HandleInput(p); break;
    case 3: RESEARCH_GRAPH_HandleInputAlt(p); break;
    case 4: RESEARCH_GRAPH_EnterDrawSlow(p); break;
    case 5: RESEARCH_GRAPH_StepAnimation(p); break;
    case 6: RESEARCH_GRAPH_EnterFadeIn((u32)p); break;
    case 7: RESEARCH_GRAPH_EnterFadeOut((u32)p); break;
    case 8: RESEARCH_GRAPH_EnterDrawMedium((char *)p); break;
    case 9: RESEARCH_GRAPH_EnterDrawMediumAlt((char *)p); break;
    case 10: RESEARCH_GRAPH_ExitFade((u32)p); break;
    case 11: RESEARCH_GRAPH_AdvanceWhileActive((u32)p); break;
    case 12: RESEARCH_GRAPH_Cleanup((u8 *)p); break;
    case 13: return;
    }
    RESEARCH_GRAPH_CheckQuestionnaireUpdated((char *)p);
    RESEARCH_GRAPH_TickTimer(p);
    if (((struct ResearchObjB *)p)->drawSystem != 0) {
        CLACT_DrawSystem(((struct ResearchObjB *)p)->drawSystem);
        RESEARCH_GRAPH_UpdateCircles((char *)p);
        ARROW_Update(((struct ResearchObjB *)p)->arrow);
        RESEARCH_GRAPH_UpdatePaletteAnime(p);
        RESEARCH_GRAPH_UpdateSlotPalettes((int *)p);
        RESEARCH_GRAPH_DrawCircles((char *)p);
        RESEARCH_GRAPH_DrawSliceColor((char *)p);
        *(volatile unsigned int *)0x04000540 = 0;
    }
    RESEARCH_GRAPH_IncTimer(p);
    RESEARCH_GRAPH_ProcessCommand((u32)p);
}

u32 RESEARCH_GRAPH_GetVisible(void *p)
{
    return ((struct ResearchObjB *)p)->visible;
}

/*
 * Field getter, u32 at +0x3e4.
 *
 * Addresses are Black-image addresses.
 */
u32 RESEARCH_GRAPH_GetActive(void *p)
{
    return ((struct ResearchObjB *)p)->active;
}

void RESEARCH_GRAPH_Init(unsigned char *p)
{
    int r;
    RESEARCH_GRAPH_CreateCommandQueue((u32)p);
    RESEARCH_GRAPH_CreateFont((u32)p);
    RESEARCH_GRAPH_CreateMessages((struct MessageView *)p);
    RESEARCH_GRAPH_CreateWordSet((u32)p);
    RESEARCH_GRAPH_InitTouchRects(p);
    RESEARCH_GRAPH_LayoutTouchRects(p);
    RESEARCH_GRAPH_InitScreen();
    RESEARCH_GRAPH_InitOverlayBackgrounds((char *)p);
    RESEARCH_GRAPH_LoadBackground6((char *)p);
    RESEARCH_GRAPH_UpdateBackground7(p);
    RESEARCH_GRAPH_LoadBackground2((char *)p);
    RESEARCH_GRAPH_UpdateBackground3(p);
    RESEARCH_GRAPH_CreateLabels((char *)p);
    RESEARCH_GRAPH_RegisterEntryResources((char *)p);
    RESEARCH_GRAPH_RegisterCursorResources((char *)p);
    RESEARCH_GRAPH_CreateUnits(p);
    RESEARCH_GRAPH_CreateActors(p);
    RESEARCH_GRAPH_CreateBmps(p);
    RESEARCH_GRAPH_DrawBmps(p);
    RESEARCH_GRAPH_DrawBadge(p);
    RESEARCH_GRAPH_CreateOamSys(p);
    RESEARCH_GRAPH_CreateOamObjects(p);
    RESEARCH_GRAPH_BuildGraphTable((char *)p);
    RESEARCH_GRAPH_CreateCircles((char *)p);
    RESEARCH_GRAPH_CreateArrow((char *)p);
    RESEARCH_GRAPH_CreatePercentages((char *)p);
    RESEARCH_GRAPH_CreatePalAnm(p);
    RESEARCH_GRAPH_CreatePaletteAnime(p);
    RESEARCH_GRAPH_BindPaletteAnime(p);
    RESEARCH_GRAPH_RegisterVBlank((char *)p);
    RESEARCH_GRAPH_RestartNetwork((u32)p);
    RESEARCH_GRAPH_PrintTitle((char *)p);
    RESEARCH_GRAPH_PrintGroupLabel((char *)p);
    RESEARCH_GRAPH_PrintKindLabel((char *)p);
    RESEARCH_GRAPH_PrintSliceLabel((char *)p);
    RESEARCH_GRAPH_PrintTimeLabel((char *)p);
    RESEARCH_GRAPH_PrintTeamLabel((char *)p);
    RESEARCH_GRAPH_SetTeamLabelVisible((char *)p);
    RESEARCH_GRAPH_SetDetailLabelVisible((char *)p);
    RESEARCH_GRAPH_LayoutActors((char *)p);
    RESEARCH_GRAPH_LoadBackground((char *)p);
    RESEARCH_GRAPH_SetTriangleActorVisible((char *)p);
    RESEARCH_GRAPH_EnableOams(p);
    RESEARCH_GRAPH_StartSlotPaletteAnime((char *)p, 0);
    RESEARCH_GRAPH_StartSlotPaletteAnime((char *)p, 7);
    RESEARCH_GRAPH_SyncArrow(p);
    *(int *)&((struct ResearchObjB *)p)->drawSystem = 1;
    RESEARCH_GRAPH_FadeIn();
    r = RESEARCH_GRAPH_GetTransitionKind(p);
    RESEARCH_GRAPH_PushCommand(p, 1);
    RESEARCH_GRAPH_PushCommand(p, r);
    if (r == 3)
        RESEARCH_GRAPH_DrawIndexCursor((char *)p);
    RESEARCH_GRAPH_SetStateChanged(p);
}

#pragma thumb on

void RESEARCH_GRAPH_UpdateIntro(u32 a0)
{
    switch (RESEARCH_GRAPH_GetSubState((void *)a0)) {
    case 0:
        RESEARCH_GRAPH_OpenComm((u8 *)a0);
        RESEARCH_GRAPH_IncSubState((void *)a0);
        break;
    case 1:
        if (RESEARCH_GRAPH_GetCommKindOrStart((u8 *)a0) != 0) {
            RESEARCH_GRAPH_SetStateChanged((void *)a0);
        }
        break;
    }
}

void RESEARCH_GRAPH_HandleInput(u8 *p)
{
    u32 keys;
    int hit;
    int sub;

    KEY_GetCont();
    keys = KEY_GetTrg();
    hit = TOUCHPANEL_HitTrg(p + 0x2FE);
    sub = TOUCHPANEL_HitTrg(RESEARCH_COMMON_GetTouchRects(((struct ResearchObjB *)p)->owner));
    if (*(int *)&((struct ResearchObjB *)p)->entryShown != 0 && ((struct ResearchObjB *)p)->updatedFlag != 0 && *(int *)&((struct ResearchObjB *)p)->timerExpired != 0) {
        RESEARCH_GRAPH_SetStateChanged(p);
        RESEARCH_GRAPH_PushCommand(p, 8);
        RESEARCH_GRAPH_PushCommand(p, 6);
        RESEARCH_GRAPH_PushCommand(p, 7);
        RESEARCH_GRAPH_PushCommand(p, 5);
        RESEARCH_GRAPH_PushCommand(p, 2);
        return;
    }
    if (RESEARCH_GRAPH_GetInputFlag(p) != 0 || sub == 0) {
        RESEARCH_GRAPH_SetEntryHandled(p, 1);
        RESEARCH_GRAPH_StartPaletteAnime((u32 *)p);
        GFL_USE_PlaySeDefaultVolume(0x551);
        RESEARCH_GRAPH_SetStateChanged(p);
        RESEARCH_GRAPH_PushCommand(p, 11);
        RESEARCH_GRAPH_PushCommand(p, 10);
        RESEARCH_GRAPH_PushCommand(p, 12);
        return;
    }
    if ((keys & 0x40) || (keys & 0x80) || (keys & 0x20) || (keys & 0x10) || (keys & 1)) {
        RESEARCH_GRAPH_DrawIndexCursor((char *)p);
        RESEARCH_GRAPH_SyncArrow(p);
        RESEARCH_GRAPH_SetStateChanged(p);
        RESEARCH_GRAPH_PushCommand(p, 3);
        return;
    }
    if (hit == 6 && *(int *)&((struct ResearchObjB *)p)->entryShown == 0 && RESEARCH_GRAPH_GetGroupValue(p) != 0) {
        ((struct ResearchObjB *)p)->touchSelected = 1;
        RESEARCH_GRAPH_SetHighlightSelected((u32)p);
        RESEARCH_GRAPH_SetStateChanged(p);
        RESEARCH_GRAPH_PushCommand(p, 4);
        RESEARCH_GRAPH_PushCommand(p, 6);
        RESEARCH_GRAPH_PushCommand(p, 7);
        RESEARCH_GRAPH_PushCommand(p, 5);
        RESEARCH_GRAPH_PushCommand(p, 2);
    } else if (hit == 7) {
        if (*(int *)&((struct ResearchObjB *)p)->entryShown == 0 && RESEARCH_GRAPH_GetGroupValue(p) != 0) {
            ((struct ResearchObjB *)p)->touchSelected = 1;
            RESEARCH_GRAPH_SetHighlightSelected((u32)p);
            RESEARCH_GRAPH_SetStateChanged(p);
            RESEARCH_GRAPH_PushCommand(p, 4);
            RESEARCH_GRAPH_PushCommand(p, 6);
            RESEARCH_GRAPH_PushCommand(p, 7);
            RESEARCH_GRAPH_PushCommand(p, 5);
            RESEARCH_GRAPH_PushCommand(p, 2);
        } else {
            GFL_USE_PlaySeDefaultVolume(0x557);
        }
    } else if (hit == 2) {
        if (*(int *)&((struct ResearchObjB *)p)->entryShown == 0 && RESEARCH_GRAPH_GetGroupValue(p) != 0) {
            ((struct ResearchObjB *)p)->touchSelected = 1;
            RESEARCH_GRAPH_SetHighlightSelected((u32)p);
            RESEARCH_GRAPH_SetStateChanged(p);
            RESEARCH_GRAPH_PushCommand(p, 4);
            RESEARCH_GRAPH_PushCommand(p, 6);
            RESEARCH_GRAPH_PushCommand(p, 7);
            RESEARCH_GRAPH_PushCommand(p, 5);
            RESEARCH_GRAPH_PushCommand(p, 2);
        } else {
            RESEARCH_GRAPH_SelectDirect((u32)p, 0);
        }
    } else if (*(int *)&((struct ResearchObjB *)p)->entryShown != 0 && RESEARCH_GRAPH_GetGroupValue(p) != 0 && hit == 3) {
        RESEARCH_GRAPH_SelectDirect((u32)p, 1);
        RESEARCH_GRAPH_DrawIndexCursor((char *)p);
        RESEARCH_GRAPH_SyncArrow(p);
        RESEARCH_GRAPH_SetStateChanged(p);
        RESEARCH_GRAPH_PushCommand(p, 3);
    } else if (*(int *)&((struct ResearchObjB *)p)->entryShown != 0 && RESEARCH_GRAPH_GetGroupValue(p) != 0 && hit == 4) {
        RESEARCH_GRAPH_SelectDirect((u32)p, 2);
        RESEARCH_GRAPH_DrawIndexCursor((char *)p);
        RESEARCH_GRAPH_SyncArrow(p);
        RESEARCH_GRAPH_SetStateChanged(p);
        RESEARCH_GRAPH_PushCommand(p, 3);
    } else if (hit == 5) {
        RESEARCH_GRAPH_SelectDirect((u32)p, 3);
        RESEARCH_GRAPH_DrawIndexCursor((char *)p);
        RESEARCH_GRAPH_SyncArrow(p);
        RESEARCH_GRAPH_SetStateChanged(p);
        RESEARCH_GRAPH_PushCommand(p, 3);
    } else if (hit == 0) {
        RESEARCH_GRAPH_DrawIndexCursor((char *)p);
        RESEARCH_GRAPH_SyncArrow(p);
        RESEARCH_GRAPH_SetStateChanged(p);
        RESEARCH_GRAPH_PushCommand(p, 3);
        switch (*(int *)&((struct ResearchObjB *)p)->cursorIndex) {
        case 0: RESEARCH_GRAPH_MoveGroupForward((char *)p); break;
        case 1: RESEARCH_GRAPH_MoveEntryBackward((u32)p); break;
        case 3: RESEARCH_GRAPH_ToggleEntry((char *)p); break;
        }
    } else if (hit == 1) {
        RESEARCH_GRAPH_DrawIndexCursor((char *)p);
        RESEARCH_GRAPH_SyncArrow(p);
        RESEARCH_GRAPH_SetStateChanged(p);
        RESEARCH_GRAPH_PushCommand(p, 3);
        switch (*(int *)&((struct ResearchObjB *)p)->cursorIndex) {
        case 0: RESEARCH_GRAPH_MoveGroupBackward((char *)p); break;
        case 1: RESEARCH_GRAPH_MoveEntryForward((u32)p); break;
        case 3: RESEARCH_GRAPH_ToggleEntry((char *)p); break;
        }
    } else if (keys & 2) {
        RESEARCH_GRAPH_SetEntryHandled(p, 0);
        RESEARCH_GRAPH_StartPaletteAnime((u32 *)p);
        GFL_USE_PlaySeDefaultVolume(0x551);
        RESEARCH_GRAPH_SetStateChanged(p);
        RESEARCH_GRAPH_PushCommand(p, 11);
        RESEARCH_GRAPH_PushCommand(p, 10);
        RESEARCH_GRAPH_PushCommand(p, 12);
    }
}

void RESEARCH_GRAPH_HandleInputAlt(u8 *p)
{
    u32 keys;
    int hit;
    int sub;

    KEY_GetCont();
    keys = KEY_GetTrg();
    hit = TOUCHPANEL_HitTrg(p + 0x2FE);
    sub = TOUCHPANEL_HitTrg(RESEARCH_COMMON_GetTouchRects(((struct ResearchObjB *)p)->owner));
    if (*(int *)&((struct ResearchObjB *)p)->entryShown != 0 && ((struct ResearchObjB *)p)->updatedFlag != 0 && *(int *)&((struct ResearchObjB *)p)->timerExpired != 0) {
        RESEARCH_GRAPH_SetStateChanged(p);
        RESEARCH_GRAPH_PushCommand(p, 9);
        RESEARCH_GRAPH_PushCommand(p, 6);
        RESEARCH_GRAPH_PushCommand(p, 7);
        RESEARCH_GRAPH_PushCommand(p, 5);
        RESEARCH_GRAPH_PushCommand(p, 3);
        return;
    }
    if (RESEARCH_GRAPH_GetInputFlag(p) != 0 || sub == 0) {
        RESEARCH_GRAPH_SetEntryHandled(p, 1);
        RESEARCH_GRAPH_StartPaletteAnime((u32 *)p);
        GFL_USE_PlaySeDefaultVolume(0x551);
        RESEARCH_GRAPH_SetStateChanged(p);
        RESEARCH_GRAPH_PushCommand(p, 11);
        RESEARCH_GRAPH_PushCommand(p, 10);
        RESEARCH_GRAPH_PushCommand(p, 12);
        return;
    }
    if (keys & 0x40) {
        RESEARCH_GRAPH_SelectPrev(p);
    } else if (keys & 0x80) {
        RESEARCH_GRAPH_SelectNext(p);
    } else if (hit == 6 && *(int *)&((struct ResearchObjB *)p)->entryShown == 0 && RESEARCH_GRAPH_GetGroupValue(p) != 0) {
        ((struct ResearchObjB *)p)->touchSelected = 1;
        RESEARCH_GRAPH_SetHighlightSelected((u32)p);
        RESEARCH_GRAPH_SetStateChanged(p);
        RESEARCH_GRAPH_PushCommand(p, 4);
        RESEARCH_GRAPH_PushCommand(p, 6);
        RESEARCH_GRAPH_PushCommand(p, 7);
        RESEARCH_GRAPH_PushCommand(p, 5);
        RESEARCH_GRAPH_PushCommand(p, 2);
    } else if (hit == 7) {
        if (*(int *)&((struct ResearchObjB *)p)->entryShown == 0 && RESEARCH_GRAPH_GetGroupValue(p) != 0) {
            ((struct ResearchObjB *)p)->touchSelected = 1;
            RESEARCH_GRAPH_SetHighlightSelected((u32)p);
            RESEARCH_GRAPH_SetStateChanged(p);
            RESEARCH_GRAPH_PushCommand(p, 4);
            RESEARCH_GRAPH_PushCommand(p, 6);
            RESEARCH_GRAPH_PushCommand(p, 7);
            RESEARCH_GRAPH_PushCommand(p, 5);
            RESEARCH_GRAPH_PushCommand(p, 2);
        } else {
            GFL_USE_PlaySeDefaultVolume(0x557);
        }
    } else if (hit == 2) {
        if (*(int *)&((struct ResearchObjB *)p)->entryShown == 0 && RESEARCH_GRAPH_GetGroupValue(p) != 0) {
            ((struct ResearchObjB *)p)->touchSelected = 1;
            RESEARCH_GRAPH_SetHighlightSelected((u32)p);
            RESEARCH_GRAPH_SetStateChanged(p);
            RESEARCH_GRAPH_PushCommand(p, 4);
            RESEARCH_GRAPH_PushCommand(p, 6);
            RESEARCH_GRAPH_PushCommand(p, 7);
            RESEARCH_GRAPH_PushCommand(p, 5);
            RESEARCH_GRAPH_PushCommand(p, 2);
        } else {
            RESEARCH_GRAPH_SelectDirect((u32)p, 0);
        }
    } else if (*(int *)&((struct ResearchObjB *)p)->entryShown != 0 && RESEARCH_GRAPH_GetGroupValue(p) != 0 && hit == 3) {
        RESEARCH_GRAPH_SelectDirect((u32)p, 1);
    } else if (*(int *)&((struct ResearchObjB *)p)->entryShown != 0 && RESEARCH_GRAPH_GetGroupValue(p) != 0 && hit == 4) {
        RESEARCH_GRAPH_SelectDirect((u32)p, 2);
    } else if (hit == 5) {
        RESEARCH_GRAPH_SelectDirect((u32)p, 3);
    } else if ((keys & 0x20) || hit == 0) {
        switch (*(int *)&((struct ResearchObjB *)p)->cursorIndex) {
        case 0: RESEARCH_GRAPH_MoveGroupForward((char *)p); break;
        case 1: RESEARCH_GRAPH_MoveEntryBackward((u32)p); break;
        case 3: RESEARCH_GRAPH_ToggleEntry((char *)p); break;
        }
    } else if ((keys & 0x10) || hit == 1) {
        switch (*(int *)&((struct ResearchObjB *)p)->cursorIndex) {
        case 0: RESEARCH_GRAPH_MoveGroupBackward((char *)p); break;
        case 1: RESEARCH_GRAPH_MoveEntryForward((u32)p); break;
        case 3: RESEARCH_GRAPH_ToggleEntry((char *)p); break;
        }
    } else if ((keys & 1) && *(int *)&((struct ResearchObjB *)p)->entryShown == 0 && RESEARCH_GRAPH_GetGroupValue(p) != 0
               && (*(int *)&((struct ResearchObjB *)p)->cursorIndex == 0 || *(int *)&((struct ResearchObjB *)p)->cursorIndex == 4)) {
        ((struct ResearchObjB *)p)->touchSelected = 0;
        RESEARCH_GRAPH_SetHighlightSelected((u32)p);
        RESEARCH_GRAPH_SetStateChanged(p);
        RESEARCH_GRAPH_PushCommand(p, 4);
        RESEARCH_GRAPH_PushCommand(p, 6);
        RESEARCH_GRAPH_PushCommand(p, 7);
        RESEARCH_GRAPH_PushCommand(p, 5);
        RESEARCH_GRAPH_PushCommand(p, 3);
    } else if (keys & 2) {
        RESEARCH_GRAPH_SetEntryHandled(p, 0);
        RESEARCH_GRAPH_StartPaletteAnime((u32 *)p);
        GFL_USE_PlaySeDefaultVolume(0x551);
        RESEARCH_GRAPH_SetStateChanged(p);
        RESEARCH_GRAPH_PushCommand(p, 11);
        RESEARCH_GRAPH_PushCommand(p, 10);
        RESEARCH_GRAPH_PushCommand(p, 12);
    }
}

void RESEARCH_GRAPH_EnterDrawSlow(u8 *p)
{
    switch (RESEARCH_GRAPH_GetSubState(p)) {
    case 0:
        RESEARCH_GRAPH_BuildGraphTable((char *)p);
        RESEARCH_GRAPH_ClearUpdatedFlag(p);
        RESEARCH_GRAPH_EnableOamsA(p);
        RESEARCH_GRAPH_SetSlicesFromGraphA(p, 0);
        RESEARCH_GRAPH_SetSlicesFromGraphA(p, 1);
        CircleGraph_SetEnabled(RESEARCH_GRAPH_GetLeftCircle(p), 1);
        CircleGraph_QueueDrawSlow(RESEARCH_GRAPH_GetLeftCircle(p));
        RESEARCH_GRAPH_IncSubState(p);
        break;
    case 1:
        if (GFL_USE_IsAnySeBusy() == 0) {
            if (((struct ResearchObjB *)p)->stateTimer >= 0x78)
                RESEARCH_GRAPH_IncSubState(p);
            else
                GFL_USE_PlaySeDefaultVolume(0x76B);
        }
        break;
    case 2:
        *(int *)&((struct ResearchObjB *)p)->entryShown = 1;
        RESEARCH_GRAPH_SetIndex(p, 1);
        RESEARCH_GRAPH_LayoutActors((char *)p);
        RESEARCH_GRAPH_LayoutTouchRects(p);
        RESEARCH_GRAPH_MoveToSelectedEntry((char *)p);
        RESEARCH_GRAPH_DisableOams(p);
        RESEARCH_GRAPH_LoadBackground((char *)p);
        RESEARCH_GRAPH_PrintSliceLabel((char *)p);
        RESEARCH_GRAPH_PrintTimeLabel((char *)p);
        RESEARCH_GRAPH_SetDetailLabelVisible((char *)p);
        RESEARCH_GRAPH_PrintTeamLabel((char *)p);
        RESEARCH_GRAPH_LayoutArrow((char *)p);
        RESEARCH_GRAPH_SetTriangleActorVisible((char *)p);
        if (((struct ResearchObjB *)p)->touchSelected == 0)
            RESEARCH_GRAPH_DrawIndexCursor((char *)p);
        GFL_USE_PlaySeDefaultVolume(0x76C);
        RESEARCH_GRAPH_SetStateChanged(p);
        break;
    }
}

void RESEARCH_GRAPH_StepAnimation(u8 *p)
{
    switch (RESEARCH_GRAPH_GetSubState(p)) {
    case 0:
        RESEARCH_GRAPH_UpdatePercentages((char *)p);
        RESEARCH_GRAPH_IncSubState(p);
        break;
    case 1:
        if (((struct ResearchObjB *)p)->stateTimer % 10u == 0) {
            u8 index = p[765];
            p[765] = index + 1;
            RESEARCH_GRAPH_ShowPercent(p, index);
        }
        if (p[764] <= p[765]) RESEARCH_GRAPH_SetStateChanged(p);
        break;
    }
}

/*
 * Same two-case entry as RESEARCH_GRAPH_EnterFadeOut; mode 0 arms the +5 handle and
 * RESEARCH_GRAPH_RequestFadeIn().
 *
 * Addresses are Black-image addresses.
 */
void RESEARCH_GRAPH_EnterFadeIn(u32 a0)
{
    switch (RESEARCH_GRAPH_GetSubState((void *)a0)) {
    case 0:
    RESEARCH_GRAPH_StopSlotPaletteAnime((u8 *)a0, 5);
    RESEARCH_GRAPH_RequestFadeIn((char *)a0);
    RESEARCH_GRAPH_IncSubState((void *)a0);
    break;
    case 1:
    if (RESEARCH_GRAPH_IsFadeDone((u8 *)a0) != 0) {
    RESEARCH_GRAPH_SetStateChanged((void *)a0);
    }
    break;
    }
}

void RESEARCH_GRAPH_EnterFadeOut(u32 a0)
{
    switch (RESEARCH_GRAPH_GetSubState((void *)a0)) {
    case 0:
    RESEARCH_GRAPH_RequestFadeOut((char *)a0);
    RESEARCH_GRAPH_IncSubState((void *)a0);
    break;
    case 1:
    if (RESEARCH_GRAPH_IsFadeDone((u8 *)a0) != 0) {
    RESEARCH_GRAPH_SyncArrow((u8 *)a0);
    RESEARCH_GRAPH_SetStateChanged((void *)a0);
    }
    break;
    }
}

void RESEARCH_GRAPH_EnterDrawMedium(char *p)
{
    switch (RESEARCH_GRAPH_GetSubState(p)) {
    case 0:
        ((struct ResearchObjB *)p)->detailMode = 1;
        RESEARCH_GRAPH_ClearUpdatedFlag(p);
        RESEARCH_GRAPH_ResetTimer(p);
        RESEARCH_GRAPH_BuildGraphTable(p);
        RESEARCH_GRAPH_LoadBackground(p);
        RESEARCH_GRAPH_PrintSliceLabel(p);
        RESEARCH_GRAPH_SetDetailLabelVisible(p);
        RESEARCH_GRAPH_SetTeamLabelVisible(p);
        RESEARCH_GRAPH_LayoutArrow(p);
        RESEARCH_GRAPH_LayoutActors(p);
        RESEARCH_GRAPH_HideAllPercentages(p);
        RESEARCH_GRAPH_SetSlicesFromGraphB((u8 *)p, 0);
        RESEARCH_GRAPH_SetSlicesFromGraphB((u8 *)p, 1);
        RESEARCH_GRAPH_SetCenterDepth(p);
        CircleGraph_SetEnabled(RESEARCH_GRAPH_GetRightCircle(p), 1);
        CircleGraph_QueueDrawMedium(RESEARCH_GRAPH_GetRightCircle(p));
        RESEARCH_GRAPH_IncSubState(p);
        break;
    case 1:
        if (GFL_USE_IsAnySeBusy() == 0) {
            if (((struct ResearchObjB *)p)->stateTimer >= 0x3c) {
                RESEARCH_GRAPH_IncSubState(p);
                return;
            }
            GFL_USE_PlaySeDefaultVolume(0x76b);
        }
        break;
    case 2:
        ((struct ResearchObjB *)p)->detailMode = 0;
        RESEARCH_GRAPH_SwapCenterPairs(p);
        CircleGraph_SetEnabled(RESEARCH_GRAPH_GetRightCircle(p), 0);
        RESEARCH_GRAPH_LoadBackground(p);
        RESEARCH_GRAPH_SetDetailLabelVisible(p);
        RESEARCH_GRAPH_PrintSliceLabel(p);
        RESEARCH_GRAPH_PrintTimeLabel(p);
        RESEARCH_GRAPH_PrintTeamLabel(p);
        RESEARCH_GRAPH_LayoutArrow(p);
        RESEARCH_GRAPH_LayoutActors(p);
        RESEARCH_GRAPH_LayoutMarkerActor(p);
        RESEARCH_GRAPH_SetTriangleActorVisible(p);
        GFL_USE_PlaySeDefaultVolume(0x76c);
        RESEARCH_GRAPH_SetStateChanged(p);
        break;
    }
}

void RESEARCH_GRAPH_EnterDrawMediumAlt(char *p)
{
    switch (RESEARCH_GRAPH_GetSubState(p)) {
    case 0:
        ((struct ResearchObjB *)p)->detailMode = 1;
        RESEARCH_GRAPH_ClearUpdatedFlag(p);
        RESEARCH_GRAPH_ResetTimer(p);
        RESEARCH_GRAPH_BuildGraphTable(p);
        RESEARCH_GRAPH_DrawIndexCursorDim((u8 *)p);
        RESEARCH_GRAPH_LoadBackground(p);
        RESEARCH_GRAPH_PrintSliceLabel(p);
        RESEARCH_GRAPH_SetDetailLabelVisible(p);
        RESEARCH_GRAPH_SetTeamLabelVisible(p);
        RESEARCH_GRAPH_LayoutArrow(p);
        RESEARCH_GRAPH_LayoutActors(p);
        RESEARCH_GRAPH_HideAllPercentages(p);
        RESEARCH_GRAPH_SetSlicesFromGraphB((u8 *)p, 0);
        RESEARCH_GRAPH_SetSlicesFromGraphB((u8 *)p, 1);
        RESEARCH_GRAPH_SetCenterDepth(p);
        CircleGraph_SetEnabled(RESEARCH_GRAPH_GetRightCircle(p), 1);
        CircleGraph_QueueDrawMedium(RESEARCH_GRAPH_GetRightCircle(p));
        RESEARCH_GRAPH_IncSubState(p);
        break;
    case 1:
        if (GFL_USE_IsAnySeBusy() == 0) {
            if (((struct ResearchObjB *)p)->stateTimer >= 0x3c) {
                RESEARCH_GRAPH_IncSubState(p);
                return;
            }
            GFL_USE_PlaySeDefaultVolume(0x76b);
        }
        break;
    case 2:
        ((struct ResearchObjB *)p)->detailMode = 0;
        RESEARCH_GRAPH_SwapCenterPairs(p);
        CircleGraph_SetEnabled(RESEARCH_GRAPH_GetRightCircle(p), 0);
        RESEARCH_GRAPH_LoadBackground(p);
        RESEARCH_GRAPH_DrawIndexCursor(p);
        RESEARCH_GRAPH_SetDetailLabelVisible(p);
        RESEARCH_GRAPH_PrintSliceLabel(p);
        RESEARCH_GRAPH_PrintTimeLabel(p);
        RESEARCH_GRAPH_PrintTeamLabel(p);
        RESEARCH_GRAPH_LayoutArrow(p);
        RESEARCH_GRAPH_LayoutActors(p);
        RESEARCH_GRAPH_LayoutMarkerActor(p);
        RESEARCH_GRAPH_SetTriangleActorVisible(p);
        GFL_USE_PlaySeDefaultVolume(0x76c);
        RESEARCH_GRAPH_SetStateChanged(p);
        break;
    }
}

/*
 * Same two-case entry with RESEARCH_GRAPH_FadeOut() and the ARM9 query FADE_IsActive().
 *
 * Addresses are Black-image addresses.
 */
void RESEARCH_GRAPH_ExitFade(u32 a0)
{
    switch (RESEARCH_GRAPH_GetSubState((void *)a0)) {
    case 0:
    RESEARCH_GRAPH_FadeOut();
    RESEARCH_GRAPH_IncSubState((void *)a0);
    break;
    case 1:
    if (FADE_IsActive() == 0) {
    RESEARCH_GRAPH_SetStateChanged((void *)a0);
    }
    break;
    }
}

/*
 * Calls RESEARCH_GRAPH_SetStateChanged() while RESEARCH_GRAPH_GetCount() is below the record's +0x28
 * count.
 *
 * Addresses are Black-image addresses.
 */
void RESEARCH_GRAPH_AdvanceWhileActive(u32 a0)
{
    if (RESEARCH_GRAPH_GetCount((void *)a0) < ((struct ResearchObjB *)a0)->stateTimer) {
    RESEARCH_GRAPH_SetStateChanged((void *)a0);
    }
}

void RESEARCH_GRAPH_Cleanup(u8 *a0)
{
    RESEARCH_GRAPH_RestorePaletteAnime((int *)a0);
    RESEARCH_GRAPH_DestroyPaletteAnime((int *)a0);
    RESEARCH_COMMON_StopPaletteAnime(*(u32 *)&((struct ResearchObjB *)a0)->owner);
    RESEARCH_COMMON_RestorePaletteAnime(*(u32 *)&((struct ResearchObjB *)a0)->owner);
    RESEARCH_GRAPH_UnregisterVBlank((u8 *)a0);
    RESEARCH_GRAPH_DestroyPercentages((int *)a0);
    RESEARCH_GRAPH_DestroyArrow(a0);
    RESEARCH_GRAPH_DestroyCircles((char *)a0);
    RESEARCH_GRAPH_DeletePalAnm((u32)a0);
    RESEARCH_GRAPH_DeleteBmps((int *)a0);
    RESEARCH_GRAPH_DeleteOamObjects((int *)a0);
    RESEARCH_GRAPH_DeleteOamSys((u8 *)a0);
    RESEARCH_GRAPH_DeleteActors((int *)a0);
    RESEARCH_GRAPH_DeleteUnits((int *)a0);
    RESEARCH_GRAPH_ReleaseEntryResources((u32)a0);
    RESEARCH_GRAPH_ReleaseCursorResources((u32)a0);
    RESEARCH_GRAPH_DestroyLabels((int *)a0);
    RESEARCH_GRAPH_ShowBackground3(a0);
    RESEARCH_GRAPH_DummyBg3(a0);
    RESEARCH_GRAPH_ShowBackground7(a0);
    RESEARCH_GRAPH_DummyBg7(a0);
    RESEARCH_GRAPH_ExitOverlayBackgrounds(a0);
    RESEARCH_GRAPH_DeleteWordSet((u8 *)a0);
    RESEARCH_GRAPH_DeleteMessages((int *)a0);
    RESEARCH_GRAPH_DeleteFont((u8 *)a0);
    RESEARCH_GRAPH_SetActive((void *)a0, 0);
    RESEARCH_GRAPH_PushCommand((u8 *)a0, 13);
    RESEARCH_GRAPH_SetStateChanged((void *)a0);
    RESEARCH_GRAPH_ClearNotifyFlag((unsigned char *)a0);
    *(u32 *)&((struct ResearchObjB *)a0)->drawSystem = 0;
    ((struct ResearchObjB *)a0)->visible = 1;
}

void RESEARCH_GRAPH_SetStateChanged(void *p)
{
    ((struct ResearchObjB *)p)->stateChanged = 1;
}

/*
 * Tail-call veneer: forwards arg(s) (u32)(*(u32*)(a0)) to RESEARCH_COMMON_SetEntryHandled.
 *
 * Addresses are Black-image addresses.
 */
void RESEARCH_GRAPH_SetEntryHandled(u8 *a0, u32 a1)
{
    RESEARCH_COMMON_SetEntryHandled(*(u8 * *)&((struct ResearchObjB *)a0)->owner, a1);
}

void RESEARCH_GRAPH_SetActive(void *p, u32 v)
{
    ((struct ResearchObjB *)p)->active = v;
}

u32 RESEARCH_GRAPH_GetCount(void *p)
{
    return ((struct ResearchObjB *)p)->count;
}

/*
 * Classifies the record: 3 when the first query is busy and the second is
 * not, else 2.
 *
 * Addresses are Black-image addresses.
 */
u32 RESEARCH_GRAPH_GetTransitionKind(u8 *a0)
{
    u32 v = ((struct ResearchObjB *)a0)->ownerU;
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
void RESEARCH_GRAPH_IncTimer(void *p)
{
    u32 *c = (u32 *)((char *)p + 0x28);
    *c += 1;
}

/*
 * Tail-call veneer: forwards arg(s) (u32)(*(u32*)(a0 + 28)) to RingQueue_Push.
 *
 * Addresses are Black-image addresses.
 */
void RESEARCH_GRAPH_PushCommand(u8 *a0, u32 a1)
{
    RingQueue_Push((u32)(((struct ResearchObjB *)a0)->commandQueue), a1);
}

void RESEARCH_GRAPH_ProcessCommand(u32 a0)
{
    if (((struct ResearchObjB *)a0)->stateChanged != 0) {
    if (RingQueue_IsEmpty(((struct ResearchObjB *)a0)->commandQueue) == 0) {
    RESEARCH_GRAPH_StartSubState((void *)a0, RingQueue_Pop((struct Ring *)(((struct ResearchObjB *)a0)->commandQueue)));
    }
    }
}

/*
 * Set +0x20, clear +0x24, +0x28 and +0x3dc.
 *
 * Addresses are Black-image addresses.
 */
void RESEARCH_GRAPH_StartSubState(void *p, u32 v)
{
    ((struct ResearchObjB *)p)->state = v;
    ((struct ResearchObjB *)p)->subState = 0;
    ((struct ResearchObjB *)p)->stateTimer = 0;
    ((struct ResearchObjB *)p)->stateChanged = 0;
}

u32 RESEARCH_GRAPH_GetSubState(void *p)
{
    return ((struct ResearchObjB *)p)->subState;
}

/*
 * Increment the u32 at +0x24.
 *
 * Addresses are Black-image addresses.
 */
void RESEARCH_GRAPH_IncSubState(void *p)
{
    u32 *c = (u32 *)((char *)p + 0x24);
    *c += 1;
}

void RESEARCH_GRAPH_SelectPrev(u8 *p)
{
    int repeat=1;
    RESEARCH_GRAPH_DrawIndexCursorDim(p);
    RESEARCH_GRAPH_CycleIndex((char *)p,-1);
    do {
        u32 index=((struct ResearchObjB *)p)->cursorIndex;
        if (index-1<=1) {
            if (((struct ResearchObjB *)p)->entryShown==0 || RESEARCH_GRAPH_GetGroupValue(p)==0) {
                RESEARCH_GRAPH_CycleIndex((char *)p,-1);
            } else repeat=0;
        } else if (index==4) {
            if (((struct ResearchObjB *)p)->entryShown==1 || RESEARCH_GRAPH_GetGroupValue(p)==0) {
                RESEARCH_GRAPH_CycleIndex((char *)p,-1);
            } else repeat=0;
        } else repeat=0;
    } while(repeat);
    RESEARCH_GRAPH_DrawIndexCursor((char *)p);
    RESEARCH_GRAPH_LayoutActors((char *)p);
    RESEARCH_GRAPH_LayoutMarkerActor((char *)p);
    RESEARCH_GRAPH_StartSlotPaletteAnime((char *)p,1);
    if (((struct ResearchObjB *)p)->cursorIndex==4) RESEARCH_GRAPH_SetHighlightC((u32)p);
    GFL_USE_PlaySeDefaultVolume(1352);
    RESEARCH_GRAPH_LayoutTouchRects(p);
}

void RESEARCH_GRAPH_SelectNext(u8 *p)
{
    int repeat=1;
    RESEARCH_GRAPH_DrawIndexCursorDim(p);
    RESEARCH_GRAPH_CycleIndex((char *)p,1);
    do {
        u32 index=((struct ResearchObjB *)p)->cursorIndex;
        if (index-1<=1) {
            if (((struct ResearchObjB *)p)->entryShown==0 || RESEARCH_GRAPH_GetGroupValue(p)==0) {
                RESEARCH_GRAPH_CycleIndex((char *)p,1);
            } else repeat=0;
        } else if (index==4) {
            if (((struct ResearchObjB *)p)->entryShown==1 || RESEARCH_GRAPH_GetGroupValue(p)==0) {
                RESEARCH_GRAPH_CycleIndex((char *)p,1);
            } else repeat=0;
        } else repeat=0;
    } while(repeat);
    RESEARCH_GRAPH_DrawIndexCursor((char *)p);
    RESEARCH_GRAPH_LayoutActors((char *)p);
    RESEARCH_GRAPH_LayoutMarkerActor((char *)p);
    RESEARCH_GRAPH_StartSlotPaletteAnime((char *)p,1);
    if (((struct ResearchObjB *)p)->cursorIndex==4) RESEARCH_GRAPH_SetHighlightC((u32)p);
    GFL_USE_PlaySeDefaultVolume(1352);
    RESEARCH_GRAPH_LayoutTouchRects(p);
}

u32 RESEARCH_GRAPH_SelectDirect(u32 a0, u32 a1)
{
    RESEARCH_GRAPH_ApplySelection((u8 *)a0, a1);
    RESEARCH_GRAPH_StartSlotPaletteAnime((char *)a0, 1);
    return GFL_USE_PlaySeDefaultVolume(1352);
}

void RESEARCH_GRAPH_ApplySelection(u8 *a0, u32 a1)
{
    if ((u32)(a1 - 1) <= 1) {
    if (((struct ResearchObjB *)a0)->entryShown == 0) {
    return;
    }
    if (RESEARCH_GRAPH_GetGroupValue(a0) == 0) {
    return;
    }
    }
    RESEARCH_GRAPH_DrawIndexCursorDim(a0);
    RESEARCH_GRAPH_SetIndex(a0, a1);
    RESEARCH_GRAPH_DrawIndexCursor((char *)a0);
    RESEARCH_GRAPH_LayoutActors((char *)a0);
    RESEARCH_GRAPH_LayoutMarkerActor((char *)a0);
    RESEARCH_GRAPH_LayoutTouchRects(a0);
}

/*
 * Per-frame step for the record's +0x3C8 sub-state; the tail is the
 * fixed-order call list that re-arms the sub-system (delta +1).
 *
 * Addresses are Black-image addresses.
 */
void RESEARCH_GRAPH_MoveGroupBackward(char *p)
{
    if (((struct ResearchObjB *)p)->entryShown != 0) {
        if (RESEARCH_GRAPH_GetGroupValue(p) != 0) {
            CircleGraph_QueueErase(RESEARCH_GRAPH_GetLeftCircle(p));
        }
    }
    RESEARCH_GRAPH_BuildGraphTable(p);
    RESEARCH_GRAPH_ClearUpdatedFlag(p);
    RESEARCH_GRAPH_CycleGroup(p, 1);
    ((struct ResearchObjB *)p)->entryShown = 0;
    RESEARCH_GRAPH_LoadBackground(p);
    RESEARCH_GRAPH_DrawIndexCursor(p);
    RESEARCH_GRAPH_PrintGroupLabel(p);
    RESEARCH_GRAPH_PrintKindLabel(p);
    RESEARCH_GRAPH_MoveToFirstEntry((char *)p);
    RESEARCH_GRAPH_PrintTimeLabel(p);
    RESEARCH_GRAPH_PrintTeamLabel(p);
    RESEARCH_GRAPH_SetTeamLabelVisible(p);
    RESEARCH_GRAPH_HideAllPercentages(p);
    RESEARCH_GRAPH_SetTriangleActorVisible(p);
    RESEARCH_GRAPH_SyncArrow((u8 *)p);
    GFL_USE_PlaySeDefaultVolume(1352);
}

/*
 * Identical frame step to RESEARCH_GRAPH_MoveGroupBackward with the sub-state delta -1.
 *
 * Addresses are Black-image addresses.
 */
void RESEARCH_GRAPH_MoveGroupForward(char *p)
{
    if (((struct ResearchObjB *)p)->entryShown != 0) {
        if (RESEARCH_GRAPH_GetGroupValue(p) != 0) {
            CircleGraph_QueueErase(RESEARCH_GRAPH_GetLeftCircle(p));
        }
    }
    RESEARCH_GRAPH_BuildGraphTable(p);
    RESEARCH_GRAPH_ClearUpdatedFlag(p);
    RESEARCH_GRAPH_CycleGroup(p, -1);
    ((struct ResearchObjB *)p)->entryShown = 0;
    RESEARCH_GRAPH_LoadBackground(p);
    RESEARCH_GRAPH_DrawIndexCursor(p);
    RESEARCH_GRAPH_PrintGroupLabel(p);
    RESEARCH_GRAPH_PrintKindLabel(p);
    RESEARCH_GRAPH_MoveToFirstEntry((char *)p);
    RESEARCH_GRAPH_PrintTimeLabel(p);
    RESEARCH_GRAPH_PrintTeamLabel(p);
    RESEARCH_GRAPH_SetTeamLabelVisible(p);
    RESEARCH_GRAPH_HideAllPercentages(p);
    RESEARCH_GRAPH_SetTriangleActorVisible(p);
    RESEARCH_GRAPH_SyncArrow((u8 *)p);
    GFL_USE_PlaySeDefaultVolume(1352);
}

u32 RESEARCH_GRAPH_MoveEntryForward(u32 a0)
{
    RESEARCH_GRAPH_StepEntry((u8 *)a0, 1);
    RESEARCH_GRAPH_PrintSliceLabel((char *)a0);
    RESEARCH_GRAPH_LayoutArrow((char *)a0);
    return GFL_USE_PlaySeDefaultVolume(1352);
}

u32 RESEARCH_GRAPH_MoveEntryBackward(u32 a0)
{
    RESEARCH_GRAPH_StepEntry((u8 *)a0, -1);
    RESEARCH_GRAPH_PrintSliceLabel((char *)a0);
    RESEARCH_GRAPH_LayoutArrow((char *)a0);
    return GFL_USE_PlaySeDefaultVolume(1352);
}

void RESEARCH_GRAPH_MoveToFirstEntry(char *p)
{
    RESEARCH_GRAPH_ClearEntryIndex((u8 *)p);
    RESEARCH_GRAPH_PrintSliceLabel(p);
    RESEARCH_GRAPH_LayoutArrow(p);
}

void RESEARCH_GRAPH_MoveToSelectedEntry(char *p)
{
    RESEARCH_GRAPH_SetEntryFromSlice(p);
    RESEARCH_GRAPH_PrintSliceLabel(p);
    RESEARCH_GRAPH_LayoutArrow(p);
}

void RESEARCH_GRAPH_ToggleEntry(char *p)
{
    int flag = 0;
    u32 k;
    if (RESEARCH_GRAPH_AreCirclesIdle((u32)p) == 0) {
        return;
    }
    if (((struct ResearchObjB *)p)->entryShown != 0 && RESEARCH_GRAPH_GetGroupValue(p) != 0) {
        CircleGraph_QueueErase(RESEARCH_GRAPH_GetLeftCircle(p));
        flag = 1;
    }
    switch (((struct ResearchObjB *)p)->graphKind) {
    case 0:
        k = 1;
        break;
    case 1:
        k = 0;
        break;
    }
    RESEARCH_GRAPH_SetGraphKind(p, k);
    RESEARCH_GRAPH_LoadBackground(p);
    RESEARCH_GRAPH_DrawIndexCursor(p);
    RESEARCH_GRAPH_PrintSliceLabel(p);
    RESEARCH_GRAPH_PrintTimeLabel(p);
    RESEARCH_GRAPH_PrintTeamLabel(p);
    RESEARCH_GRAPH_SetTeamLabelVisible(p);
    RESEARCH_GRAPH_SetDetailLabelVisible(p);
    RESEARCH_GRAPH_SetTriangleActorVisible(p);
    RESEARCH_GRAPH_SyncArrow((u8 *)p);
    RESEARCH_GRAPH_LayoutArrow(p);
    RESEARCH_GRAPH_HideAllPercentages(p);
    if (((struct ResearchObjB *)p)->entryShown != 0 && RESEARCH_GRAPH_GetGroupValue(p) != 0) {
        RESEARCH_GRAPH_UpdatePercentages(p);
        RESEARCH_GRAPH_ShowPercentages(p);
    }
    if (((struct ResearchObjB *)p)->entryShown != 0 && RESEARCH_GRAPH_GetGroupValue(p) != 0) {
        if (flag != 0) {
            CircleGraph_HoldUpdate(RESEARCH_GRAPH_GetLeftCircle(p), 0x14);
        }
        CircleGraph_QueueDrawFast(RESEARCH_GRAPH_GetLeftCircle(p));
        CircleGraph_SetEnabled(RESEARCH_GRAPH_GetLeftCircle(p), 1);
    }
    GFL_USE_PlaySeDefaultVolume(0x548);
}

void RESEARCH_GRAPH_FadeIn(void)
{
    FADE_Start(3, 0x10, 0, 0);
}

void RESEARCH_GRAPH_FadeOut(void)
{
    FADE_Start(3, 0, 16, 0);
}

void RESEARCH_GRAPH_CycleIndex(char *p, int a)
{
    ((struct ResearchObjB *)p)->cursorIndexSigned = (((struct ResearchObjB *)p)->cursorIndexSigned + a + 5) % 5;
}

/*
 * Field setter, u32 at +0x34.
 *
 * Addresses are Black-image addresses.
 */
void RESEARCH_GRAPH_SetIndex(void *p, u32 v)
{
    ((struct ResearchObjB *)p)->cursorIndex = v;
}

int RESEARCH_GRAPH_DrawIndexCursor(char *p)
{
    switch (((struct ResearchObjB *)p)->cursorIndexSigned) {
    case 0:
    case 2:
    case 3:
        BG_SYS_FillTileMap(2, d_021C3AC8[*(int *)(p + 0x34)].x,
                      d_021C3AC8[*(int *)(p + 0x34)].y,
                      d_021C3AC8[*(int *)(p + 0x34)].w,
                      d_021C3AC8[*(int *)(p + 0x34)].h, 0xa);
        break;
    case 1:
        BG_SYS_FillTileMap(2, 0xd, 4, 0x13, 4, 0xa);
        BG_SYS_FillTileMap(2, 0x10, 8, 0x10, 3, 0xa);
        break;
    case 4:
        RESEARCH_GRAPH_SetHighlightA((u32)p);
        break;
    }
    return BG_SYS_PushTile(2);
}

void RESEARCH_GRAPH_DrawIndexCursorDim(u8 *p)
{
    switch (((struct ResearchObjB *)p)->cursorIndex) {
    case 0:
    case 2:
    case 3:
        BG_SYS_FillTileMap(2, d_021C3AC8[*(u32 *)(p + 52)].x,
            d_021C3AC8[*(u32 *)(p + 52)].y,
            d_021C3AC8[*(u32 *)(p + 52)].w,
            d_021C3AC8[*(u32 *)(p + 52)].h, 6);
        break;
    case 1:
        BG_SYS_FillTileMap(2,13,4,19,4,6);
        BG_SYS_FillTileMap(2,16,8,16,3,6);
        break;
    case 4:
        RESEARCH_GRAPH_SetHighlightB((u32)p);
        break;
    }
    BG_SYS_PushTile(2);
}

void RESEARCH_GRAPH_CycleGroup(char *p, int a)
{
    ((struct ResearchObjB *)p)->groupIndex = (u8)((((struct ResearchObjB *)p)->groupIndex + a + 3) % 3);
}

void RESEARCH_GRAPH_SetEntryFromSlice(char *p)
{
    u8 *o = RESEARCH_GRAPH_GetLeftCircle(p);

    u32 k = RESEARCH_GRAPH_GetGroupKey(p);
    int v = CircleGraph_GetSliceKey(o, 0);
    ((struct ResearchObjB *)p)->entryIndex = GRAPHTABLE_FindEntry((const u8 *)(p + 0x38), (u8)k, (u8)v);
}

/*
 * Prototypes: original loads r0/r1 and reads return at 021C11C8/11D0;
 * narrow argument truncations are explicit in the caller.
 */
void RESEARCH_GRAPH_StepEntry(u8 *p, int step)
{
    u8 *object;
    int kind;
    int count;
    int index;
    object = RESEARCH_GRAPH_GetLeftCircle(p);
    kind = RESEARCH_GRAPH_GetGroupKey(p);
    count = RESEARCH_GRAPH_GetGroupCount(p);
    index = RESEARCH_GRAPH_GetEntryKey(p);
    index = CircleGraph_FindSliceIndex(object, index);

    index = (count + (index + step)) % count;
    index = CircleGraph_GetSliceKey(object, index);
    p[697] = GRAPHTABLE_FindEntry(p + 56, kind, index);
}

void RESEARCH_GRAPH_ClearEntryIndex(u8 *a0)
{
    ((struct ResearchObjB *)a0)->entryIndex = 0;
}

void RESEARCH_GRAPH_SyncArrow(u8 *p)
{
    if (((struct ResearchObjB *)p)->entryShown == 1 || ((struct ResearchObjB *)p)->detailMode == 1 || RESEARCH_GRAPH_GetGroupValue(p) == 0) {
        if (RESEARCH_GRAPH_IsSlotPaletteAnimeRunning(p, 5) == 0) RESEARCH_GRAPH_SetNormalB((u32)p);
    } else {
        if (RESEARCH_GRAPH_IsSlotPaletteAnimeRunning(p, 5) == 1) RESEARCH_GRAPH_SetNormalA((u32)p);
    }
}

void RESEARCH_GRAPH_SetHighlightSelected(u32 a0)
{
    BMP_OAM_SetPalette((u8 *)(((struct ResearchObjB *)a0)->oamObjectB), 0);
    RESEARCH_GRAPH_StopSlotPaletteAnime((u8 *)a0, 5);
    RESEARCH_GRAPH_StopSlotPaletteAnime((u8 *)a0, 6);
    RESEARCH_GRAPH_StartSlotPaletteAnime((char *)a0, 2);
}

void RESEARCH_GRAPH_SetHighlightA(u32 a0)
{
    BMP_OAM_SetPalette((u8 *)(((struct ResearchObjB *)a0)->oamObjectB), 0);
    RESEARCH_GRAPH_StartSlotPaletteAnime((char *)a0, 3);
}

void RESEARCH_GRAPH_SetHighlightB(u32 a0)
{
    BMP_OAM_SetPalette((u8 *)(((struct ResearchObjB *)a0)->oamObjectB), 1);
    RESEARCH_GRAPH_StopSlotPaletteAnime((u8 *)a0, 3);
}

void RESEARCH_GRAPH_SetHighlightC(u32 a0)
{
    BMP_OAM_SetPalette((u8 *)(((struct ResearchObjB *)a0)->oamObjectB), 0);
    RESEARCH_GRAPH_StartSlotPaletteAnime((char *)a0, 4);
}

void RESEARCH_GRAPH_SetNormalA(u32 a0)
{
    BMP_OAM_SetPalette((u8 *)(((struct ResearchObjB *)a0)->oamObjectB), 1);
    RESEARCH_GRAPH_StopSlotPaletteAnime((u8 *)a0, 5);
    RESEARCH_GRAPH_StartSlotPaletteAnime((char *)a0, 6);
}

void RESEARCH_GRAPH_SetNormalB(u32 a0)
{
    BMP_OAM_SetPalette((u8 *)(((struct ResearchObjB *)a0)->oamObjectB), 1);
    RESEARCH_GRAPH_StartSlotPaletteAnime((char *)a0, 5);
}

void RESEARCH_GRAPH_StartPaletteAnime(u32 *p)
{
    RESEARCH_COMMON_StartPaletteAnime((u8 *)(*p), 0);
}

/*
 * Swap the u32 pairs at +0x2bc and +0x2c4.
 *
 * Addresses are Black-image addresses.
 */
void RESEARCH_GRAPH_SwapCenterPairs(void *p)
{
    int i;
    for (i = 0; i < 2; i++) {
        u32 t = *(u32 *)((char *)p + i * 4 + 0x2bc);
        *(u32 *)((char *)p + i * 4 + 0x2bc) = *(u32 *)((char *)p + i * 4 + 0x2c4);
        *(u32 *)((char *)p + i * 4 + 0x2c4) = t;
    }
}

void RESEARCH_GRAPH_QuantizePosition(u32 a0)
{
    u32 v1 = _s32_div_f(((struct GraphSliceInput *)a0)->y + 62, 3);
    u32 v2 = _s32_div_f(((struct GraphSliceInput *)a0)->z + 62, 3);
    ((struct GraphSliceInput *)a0)->quantX = _s32_div_f(((struct GraphSliceInput *)a0)->x + 62, 3);
    ((struct GraphSliceInput *)a0)->quantY = v1;
    ((struct GraphSliceInput *)a0)->quantZ = v2;
}

void RESEARCH_GRAPH_SetCenterDepth(void *p)
{
    CircleGraph_SetCenterDepth(RESEARCH_GRAPH_GetLeftCircle(p), 0xFFFFE000);
    CircleGraph_SetCenterDepth(RESEARCH_GRAPH_GetRightCircle(p), 0);
}

void RESEARCH_GRAPH_SetSlicesFromGraphA(u8 *p,int mode)
{
    struct GraphSliceInput items[17];
    struct GraphEntryView *base;
    u32 object;
    int count;
    int i;
    object=*(u32 *)(p+700+mode*4);
    count=RESEARCH_GRAPH_GetGroupCount(p);
    base=(struct GraphEntryView *)(p+60+p[696]*212);
    for(i=0;i<count;i++) {
        struct GraphEntryView *q=(struct GraphEntryView *)((u8 *)base+8+i*12);
        struct GraphSliceInput *t=&items[i];
        t->id=q->id; t->x=q->x; t->y=q->y; t->z=q->z;
        RESEARCH_GRAPH_QuantizePosition((u32)t);
        switch(mode) { case 0: t->value=q->valueA; break; case 1: t->value=q->valueB; break; }
    }
    CircleGraph_SetSlices((u8 *)object,(u8 *)items,count);
}

void RESEARCH_GRAPH_SetSlicesFromGraphB(u8 *p, u32 mode)
{
    struct GraphSliceInput items[17];
    struct GraphEntryView *base;
    u32 object;
    int count;
    int i;
    object=*(u32 *)(p+708+mode*4);
    count=RESEARCH_GRAPH_GetGroupCount(p);
    base=(struct GraphEntryView *)(p+60+p[696]*212);
    for(i=0;i<count;i++) {
        struct GraphEntryView *q=(struct GraphEntryView *)((u8 *)base+8+i*12);
        struct GraphSliceInput *t=&items[i];
        t->id=q->id; t->x=q->x; t->y=q->y; t->z=q->z;
        RESEARCH_GRAPH_QuantizePosition((u32)t);
        switch(mode) { case 0: t->value=q->valueA; break; case 1: t->value=q->valueB; break; }
    }
    CircleGraph_SetSlices((u8 *)object,(u8 *)items,count);
}

void RESEARCH_GRAPH_UpdateCircles(char *p)
{
    int i;
    for (i = 0; i < 2; i++) {
        CircleGraph_Update(*(u8 **)(p + i * 4 + 0x2bc));
        CircleGraph_Update(*(u8 **)(p + i * 4 + 0x2c4));
    }
}

void RESEARCH_GRAPH_DrawCircles(char *p)
{
    int i;
    for (i = 0; i < 2; i++) {
        CircleGraph_Draw(*(u8 **)(p + i * 4 + 0x2bc));
        CircleGraph_Draw(*(u8 **)(p + i * 4 + 0x2c4));
    }
}

void RESEARCH_GRAPH_DrawSliceColor(char *p)
{
    unsigned r,g,b;
    void *color;
    if (((struct ResearchObjB *)p)->entryShown==0 || ((struct ResearchObjB *)p)->detailMode==1 || RESEARCH_GRAPH_GetGroupValue(p)==0) return;
    color=p+56;
    r=GRAPHTABLE_GetEntryRed(color,((struct ResearchObjB *)p)->groupIndex,((struct ResearchObjB *)p)->entryIndex);
    g=GRAPHTABLE_GetEntryGreen(color,((struct ResearchObjB *)p)->groupIndex,((struct ResearchObjB *)p)->entryIndex);
    b=GRAPHTABLE_GetEntryBlue(color,((struct ResearchObjB *)p)->groupIndex,((struct ResearchObjB *)p)->entryIndex);
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
void RESEARCH_GRAPH_LayoutArrow(char *p)
{
    u8 *object;
    unsigned index;
    s32 x,y;
    ARROW_Reset(*(unsigned *)&((struct ResearchObjB *)p)->arrow);
    if (((struct ResearchObjB *)p)->detailMode==1) return;
    if (((struct ResearchObjB *)p)->entryShown==0) return;
    if (RESEARCH_GRAPH_GetGroupValue(p)==0) return;
    object=RESEARCH_GRAPH_GetLeftCircle(p);
    index=RESEARCH_GRAPH_GetEntryKey(p);
    if (CircleGraph_GetPercentByKey(object,index)==0) return;
    if (((struct ResearchObjB *)p)->entryShown!=0) {
        object=RESEARCH_GRAPH_GetLeftCircle(p);
        index=RESEARCH_GRAPH_GetEntryKey(p);
        CircleGraph_GetLabelPositionByKey(object,index,&x,&y);

        ARROW_Layout(*(unsigned *)&((struct ResearchObjB *)p)->arrow,104,34,x,y);
        ARROW_Start(*(unsigned *)&((struct ResearchObjB *)p)->arrow);
    }
}

/*
 * lever: unsigned output counter i; initialize before decrementing the signed reverse counter.
 * C11E8 forwards original r0/r1 to C1AB4's two-input record lookup.
 * C271C forwards original r1/r2 to C288C's two-field setter.
 */
void RESEARCH_GRAPH_UpdatePercentages(char *p)
{
    int n,id;
    unsigned i;
    u8 *object;
    s32 x,y;
    unsigned slot;
    n=RESEARCH_GRAPH_GetGroupCount(p);
    object=RESEARCH_GRAPH_GetLeftCircle(p);
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
    ((struct ResearchObjB *)p)->percentageCount=i;
}

void RESEARCH_GRAPH_HideAllPercentages(char *p)
{
    int i;
    u8 z = 0;
    for (i = 0; i < 10; i++) {
        PERCENTAGE_SetVisible(*(u32 *)(p + i * 4 + 0x2d4), z);
    }
    ((struct ResearchObjB *)p)->percentageVisible = z;
}

/*
 * Tail-call veneer: forwards arg(s) (u32)(*(u32*)(a0 + (a1)*4 + 724)), 1 to PERCENTAGE_SetVisible.
 *
 * Addresses are Black-image addresses.
 */
void RESEARCH_GRAPH_ShowPercent(u8 *a0, u32 a1)
{
    PERCENTAGE_SetVisible((u32)(*(u32*)(a0 + (a1)*4 + 724)), 1);
}

void RESEARCH_GRAPH_ShowPercentages(char *p)
{
    int i;
    int n;
    n = ((struct ResearchObjB *)p)->percentageCount;
    for (i = 0; i < n; i++) {
        RESEARCH_GRAPH_ShowPercent((u8 *)p, (u8)i);
    }
}

/*
 * lever: pool 021BF088 is 021C3AC8; dropping contested ov217 data hint resolves sole-ref evidence.
 */
void RESEARCH_GRAPH_LayoutTouchRects(u8 *p)
{
    const struct CursorLayoutRow *row;
    u8 *q;
    row=(const struct CursorLayoutRow *)&d_021C3AC8[((struct ResearchObjB *)p)->cursorIndex];
    q=p+0x2fe;
    q[2]=RESEARCH_GRAPH_ClampByte(row->offsets[0]+row->offsets[4]-16);
    p[0x2fe]=RESEARCH_GRAPH_ClampByte(row->offsets[1]+row->offsets[5]-16);
    q[3]=RESEARCH_GRAPH_ClampByte(q[2]+32);
    q[1]=RESEARCH_GRAPH_ClampByte(p[0x2fe]+32);
    row=(const struct CursorLayoutRow *)&d_021C3AC8[((struct ResearchObjB *)p)->cursorIndex];
    q=p+0x302;
    q[2]=RESEARCH_GRAPH_ClampByte(row->offsets[0]+row->offsets[6]-16);
    p[0x302]=RESEARCH_GRAPH_ClampByte(row->offsets[1]+row->offsets[7]-16);
    q[3]=RESEARCH_GRAPH_ClampByte(q[2]+32);
    q[1]=RESEARCH_GRAPH_ClampByte(p[0x302]+32);
}

void RESEARCH_GRAPH_LoadBackground(char *p)
{
    struct ArcFile *arc;
    void *file,*out;
    unsigned id;
    arc=ARC_TOOL_CreateHandle(192,((struct ResearchObjB *)p)->heapId);
    if (((struct ResearchObjB *)p)->detailMode!=0) id=8;
    else if (RESEARCH_GRAPH_GetGroupValue(p)==0) id=6;
    else {
        id=6;
        if (((struct ResearchObjB *)p)->entryShown!=0) id=7;
    }
    file=ARC_TOOL_LoadHandleMember(arc,id,((struct ResearchObjB *)p)->heapId);
    NNS_G2dGetUnpackedScreenData(file,&out);
    BG_SYS_DrawTile(2,(unsigned)out+12,0,0,32,32);
    BG_SYS_PushTile(2);
    GFL_HEAP_Free(file);
    ARC_TOOL_DeleteHandle(arc);
}

/*
 * Tail call through a pool word: bx r3 spends r3 on the target, so only the
 * two argument registers are live (see docs/idioms/a-tail-call-cannot-pass-a-fourth-argument.md).
 *
 * Addresses are Black-image addresses.
 */
void RESEARCH_GRAPH_PrintTitle(char *p)
{
    BgTextLabel_PrintMessage(((struct ResearchObjB *)p)->titleLabel, d_021C3628[((struct ResearchObjB *)p)->titleGroup]);
}

void RESEARCH_GRAPH_PrintGroupLabel(char *p)
{
    u32 i = RESEARCH_GRAPH_GetGroupKey(p);
    BgTextLabel_PrintMessage(((struct ResearchObjB *)p)->groupLabel, d_021C36B8[i]);
}

void RESEARCH_GRAPH_PrintKindLabel(char *p)
{
    u32 o = ((struct ResearchObjB *)p)->kindLabel;
    u32 i = RESEARCH_GRAPH_GetGroupKey(p);
    BgTextLabel_PrintMessage(o, d_021C369A[i]);
}

void RESEARCH_GRAPH_PrintSliceLabel(char *p)
{
    u32 t = ((struct ResearchObjB *)p)->sliceLabel;
    u8 *o = RESEARCH_GRAPH_GetLeftCircle(p);
    u32 k;
    u32 a, b, c;
    void *x, *y, *z;
    if (((struct ResearchObjB *)p)->entryShown == 0 || ((struct ResearchObjB *)p)->detailMode == 1) {
        BgTextLabel_SetVisible((u8 *)t, 0);
        return;
    }
    if (RESEARCH_GRAPH_GetGroupValue(p) == 0) {
        BgTextLabel_SetVisible((u8 *)t, 0);
        return;
    }
    k = RESEARCH_GRAPH_GetEntryKey(p);
    a = CircleGraph_FindSliceIndex(o, (u8)k);

    b = RESEARCH_GRAPH_GetEntryValue(p);
    c = CircleGraph_GetPercentByKey(o, (u8)k);
    x = MSGDATA_AllocString(((struct ResearchObjB *)p)->msgBankA, 0xd);
    y = MSGDATA_AllocString(((struct ResearchObjB *)p)->msgBankB, k);
    z = STRBUF_Create(0x80, ((struct ResearchObjB *)p)->heapId);
    WORDSET_SetSlotNumber(((struct ResearchObjB *)p)->wordSet, 0, a + 1, 2, 1, 1);
    WORDSET_SetSlotTag(((struct ResearchObjB *)p)->wordSet, 1, y, 0, 1, 2);
    WORDSET_SetSlotNumber(((struct ResearchObjB *)p)->wordSet, 2, b, 5, 1, 1);
    WORDSET_SetSlotNumber(((struct ResearchObjB *)p)->wordSet, 3, c, 3, 1, 1);
    WORDSET_CopyTaggedText(((struct ResearchObjB *)p)->wordSet, z, x);
    BgTextLabel_PrintText((u8 *)t, z);
    BgTextLabel_SetVisible((u8 *)t, 1);
    STRBUF_Delete(x);
    STRBUF_Delete(z);
    STRBUF_Delete(y);
}

/*
 * EE0C: original stores sixth argument 2 at sp+4; preserve visibly supplied trailing input.
 */
void RESEARCH_GRAPH_PrintTimeLabel(char *p)
{
    unsigned index;
    struct U16Vec *a,*b,*buf;
    if (((struct ResearchObjB *)p)->entryShown==0 || RESEARCH_GRAPH_GetGroupValue(p)==0) {
        BgTextLabel_SetVisible((u8 *)(((struct ResearchObjB *)p)->timeLabel),0);
        return;
    }
    index=RESEARCH_GRAPH_GetEntryIdBySave((unsigned char *)p);
    a=MSGDATA_AllocString(*(struct MsgBank * *)&((struct ResearchObjB *)p)->msgBankA,14);
    b=MSGDATA_AllocString(*(struct MsgBank * *)&((struct ResearchObjB *)p)->msgBankB,index);
    buf=STRBUF_Create(128,((struct ResearchObjB *)p)->heapId);
    WORDSET_SetSlotTag(*(struct WordSet * *)&((struct ResearchObjB *)p)->wordSet,0,b,0,1,2);
    WORDSET_CopyTaggedText(*(struct WordSet * *)&((struct ResearchObjB *)p)->wordSet,buf,a);
    BgTextLabel_SetVisible((u8 *)(((struct ResearchObjB *)p)->timeLabel),1);
    BgTextLabel_PrintText((u8 *)(((struct ResearchObjB *)p)->timeLabel),buf);
    STRBUF_Delete(a);
    STRBUF_Delete(buf);
    STRBUF_Delete(b);
}

void RESEARCH_GRAPH_PrintTeamLabel(char *p)
{
    u32 k;
    u32 x;
    void *a, *b;
    void *c;
    if (((struct ResearchObjB *)p)->entryShown != 0) {
        switch (((struct ResearchObjB *)p)->graphKind) {
        case 0:
            k = 0xf;
            break;
        case 1:
            k = 0x11;
            break;
        }
    } else {
        switch (((struct ResearchObjB *)p)->graphKind) {
        case 0:
            k = 0x10;
            break;
        case 1:
            k = 0x12;
            break;
        }
    }
    x = RESEARCH_GRAPH_GetGroupValue(p);
    c = ((struct ResearchObjB *)p)->wordSet;
    a = MSGDATA_AllocString(((struct ResearchObjB *)p)->msgBankA, k);
    b = STRBUF_Create(0x80, ((struct ResearchObjB *)p)->heapId);
    WORDSET_SetSlotNumber(c, 0, x, 6, 1, 1);
    WORDSET_CopyTaggedText(c, b, a);
    BgTextLabel_PrintText((u8 *)(((struct ResearchObjB *)p)->teamLabel), b);
    STRBUF_Delete(a);
    STRBUF_Delete(b);
}

void RESEARCH_GRAPH_SetTeamLabelVisible(char *p)
{
    if (RESEARCH_GRAPH_GetGroupValue(p) == 0) {
        BgTextLabel_SetVisible((u8 *)(((struct ResearchObjB *)p)->emptyLabel), 1);
    } else {
        BgTextLabel_SetVisible((u8 *)(((struct ResearchObjB *)p)->emptyLabel), 0);
    }
}

void RESEARCH_GRAPH_SetDetailLabelVisible(char *p)
{
    if (((struct ResearchObjB *)p)->detailMode != 0) {
        BgTextLabel_SetVisible((u8 *)(((struct ResearchObjB *)p)->detailLabel), 1);
    } else {
        BgTextLabel_SetVisible((u8 *)(((struct ResearchObjB *)p)->detailLabel), 0);
    }
}

void RESEARCH_GRAPH_LayoutActors(char *p)
{
    const struct CursorLayoutRow *row;
    struct Obj *a,*b;
    struct Vec2 pos;
    row=(const struct CursorLayoutRow *)&d_021C3AC8[((struct ResearchObjB *)p)->cursorIndex];
    a=(struct Obj *)RESEARCH_GRAPH_GetMarkerActor(p,0);
    b=(struct Obj *)RESEARCH_GRAPH_GetMarkerActor(p,1);
    if (((struct ResearchObjB *)p)->detailMode==1 || ((struct ResearchObjB *)p)->cursorIndex==2 || ((struct ResearchObjB *)p)->cursorIndex==4) {
        CLACT_SetActorDrawEnable(a,0);
        CLACT_SetActorDrawEnable(b,0);
        return;
    }
    pos.x=row->offsets[0]+row->offsets[4];
    pos.y=row->offsets[1]+row->offsets[5];
    CLACT_AddActorSurfacePos(a,&pos,0);
    pos.x=row->offsets[0]+row->offsets[6];
    pos.y=row->offsets[1]+row->offsets[7];
    CLACT_AddActorSurfacePos(b,&pos,0);
    CLACT_SetActorDrawEnable(a,1);
    CLACT_SetActorDrawEnable(b,1);
    CLACT_SetActorAutoAnim(a,1);
    CLACT_SetActorAutoAnim(b,1);
}

void RESEARCH_GRAPH_SetTriangleActorVisible(char *p)
{
    if (((struct ResearchObjB *)p)->entryShown == 0 || RESEARCH_GRAPH_GetGroupValue(p) == 0) {
        CLACT_SetActorDrawEnable((struct Obj *)((struct ResearchObjB *)p)->triangleActor, 0);
    } else {
        CLACT_SetActorDrawEnable((struct Obj *)((struct ResearchObjB *)p)->triangleActor, 1);
    }
}

void RESEARCH_GRAPH_LayoutMarkerActor(char *p)
{
    struct Obj *obj;
    unsigned index;
    s32 x,y;
    struct Vec2 pos;
    const u16 *table;
    obj=*(struct Obj * *)&((struct ResearchObjB *)p)->markerActor;
    table=d_021C3850;
    if (((struct ResearchObjB *)p)->entryShown==0) { CLACT_SetActorDrawEnable(obj,0); return; }
    if (((struct ResearchObjB *)p)->cursorIndex!=2) { CLACT_SetActorDrawEnable(obj,0); return; }
    index=RESEARCH_GRAPH_GetEntryIdBySave((u8 *)p);
    if (CircleGraph_GetPercentByKey(RESEARCH_GRAPH_GetLeftCircle(p),index)==0) { CLACT_SetActorDrawEnable(obj,0); return; }
    if (index==0) { CLACT_SetActorDrawEnable(obj,0); return; }
    CircleGraph_GetLabelPositionByKey(RESEARCH_GRAPH_GetLeftCircle(p),index,&x,&y);

    pos.x=x;
    pos.y=y;
    CLACT_AddActorSurfacePos(obj,&pos,table[12]);
    CLACT_SetActorDrawEnable(obj,1);
    CLACT_SetActorAutoAnim(obj,1);
    CLACT_SetActorAnimLoopCount((struct Actor *)obj,2);
}

void RESEARCH_GRAPH_EnableOams(void *a0)
{
    RESEARCH_GRAPH_SetOamEnabled((u8 *)a0, 1, 1);
}

/*
 * Tail-call veneer: forwards arg(s) a0, 0, 1 to RESEARCH_GRAPH_SetOamEnabled.
 *
 * Addresses are Black-image addresses.
 */
void RESEARCH_GRAPH_EnableOamsA(void *a0)
{
    RESEARCH_GRAPH_SetOamEnabled((u8 *)a0, 0, 1);
}

/*
 * Tail-call veneer: forwards arg(s) a0, 0, 0 to RESEARCH_GRAPH_SetOamEnabled.
 *
 * Addresses are Black-image addresses.
 */
void RESEARCH_GRAPH_DisableOams(void *a0)
{
    RESEARCH_GRAPH_SetOamEnabled((u8 *)a0, 0, 0);
}

void RESEARCH_GRAPH_SetOamEnabled(u8 *p, u32 i, u32 j)
{
    BMP_OAM_SetEnabled((u8 *)(*(u32 *)(p + i * 4 + 0x3a8)), j);
}

void RESEARCH_GRAPH_StartSlotPaletteAnime(char *p, int i)
{
    PALETTE_ANIME_Start((u8 *)(*(u32 *)(p + i * 4 + 0x324)), d_021C3A34[i].mode, d_021C3A34[i].color);
}

/*
 * Tail-call veneer: forwards arg(s) (u32)(*(u32*)(a0 + (a1)*4 + 804)), (u32)(a0 + (a1)*4) to PALETTE_ANIME_Stop.
 *
 * Addresses are Black-image addresses.
 */
void RESEARCH_GRAPH_StopSlotPaletteAnime(u8 *a0, u32 a1)
{
    PALETTE_ANIME_Stop((u32)(*(u32*)(a0 + (a1)*4 + 804)));
}

/*
 * Tail-call veneer: forwards arg(s) (u32)(*(u32*)(a0 + (a1)*4 + 804)), (u32)(a0 + (a1)*4) to PALETTE_ANIME_IsRunning.
 *
 * Addresses are Black-image addresses.
 */
u32 RESEARCH_GRAPH_IsSlotPaletteAnimeRunning(u8 *a0, u32 a1)
{
    return PALETTE_ANIME_IsRunning((u32)(*(u32*)(a0 + (a1)*4 + 804)), (u32)(a0 + (a1)*4));
}

void RESEARCH_GRAPH_UpdateSlotPalettes(int *p)
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
void RESEARCH_GRAPH_UpdatePaletteAnime(u8 *a0)
{
    RESEARCH_COMMON_UpdatePaletteAnime((u32)(((struct ResearchObjB *)a0)->ownerU));
}

void RESEARCH_GRAPH_RequestFadeIn(char *p)
{
    PALANM_RequestFade(*(struct PalAnmObj * *)&((struct ResearchObjB *)p)->palAnm,1,0xffff,3,0,7,0xffff,((struct ResearchObjB *)p)->fadeParam);
    PALANM_RequestFade(*(struct PalAnmObj * *)&((struct ResearchObjB *)p)->palAnm,4,0xffff,3,0,7,0xffff,((struct ResearchObjB *)p)->fadeParam);
}

void RESEARCH_GRAPH_RequestFadeOut(char *p)
{
    PALANM_RequestFade(*(struct PalAnmObj * *)&((struct ResearchObjB *)p)->palAnm,1,0xffff,3,7,0,0xffff,((struct ResearchObjB *)p)->fadeParam);
    PALANM_RequestFade(*(struct PalAnmObj * *)&((struct ResearchObjB *)p)->palAnm,4,0xffff,3,7,0,0xffff,((struct ResearchObjB *)p)->fadeParam);
}

/*
 * Note: the record's +0x3B8 handle is idle.
 *            witness outside 021BF6A4..021BF6BC.  Bytes are exact and 24/24
 *            match the listing extent; file the TARGET first (OV-BRIEF rule
 *            10) and this promotes to EXACT with no source change.
 *
 * Addresses are Black-image addresses.
 */
u32 RESEARCH_GRAPH_IsFadeDone(u8 *a0)
{
    if (PALANM_GetFadeRequestBits((const char *)(((struct ResearchObjB *)a0)->palAnm)) == 0) {
    return 1;
    }
    return 0;
}

u32 RESEARCH_GRAPH_TransferPalettes(u32 a0, u32 a1)
{
    BG_SYS_Update();
    CLACT_VBlankSystem();
    return PALANM_TransferPalettes((struct S02021D50 *)((struct ResearchObjB *)a1)->palAnm);
}

void RESEARCH_GRAPH_CheckQuestionnaireUpdated(char *p)
{
    if (GAME_BEACON_PopQuestionnaireUpdated() == 1) {
        u16 a = RESEARCH_GRAPH_GetGroupTotalA(p);
        if (a != (u16)(u32)RESEARCH_GRAPH_GetSaveBits((u32)p)) {
            ((struct ResearchObjB *)p)->updatedFlag = 1;
        }
    }
}

/*
 * Clear the u32 at +0x3d8.
 *
 * Addresses are Black-image addresses.
 */
void RESEARCH_GRAPH_ClearUpdatedFlag(void *p)
{
    ((struct ResearchObjB *)p)->updatedFlag = 0;
}

void RESEARCH_GRAPH_TickTimer(void *p)
{
    if (((struct ResearchObjB *)p)->elapsedTimer < 0xf0) {
        ((struct ResearchObjB *)p)->elapsedTimer += 1;
    } else {
        ((struct ResearchObjB *)p)->timerExpired = 1;
    }
}

void RESEARCH_GRAPH_ResetTimer(void *p)
{
    ((struct ResearchObjB *)p)->elapsedTimer = 0;
    ((struct ResearchObjB *)p)->timerExpired = 0;
}

u32 RESEARCH_GRAPH_GetContext(u8 *a0)
{
    return RESEARCH_COMMON_GetContext((u32 *)(((struct ResearchObjB *)a0)->owner));
}

/*
 * Tail-call veneer: forwards arg(s) (u32)(*(u32*)(a0)) to RESEARCH_COMMON_GetAppResource.
 *
 * Addresses are Black-image addresses.
 */
u32 RESEARCH_GRAPH_GetAppResource(u8 *a0)
{
    return RESEARCH_COMMON_GetAppResource((void *)(((struct ResearchObjB *)a0)->ownerU));
}

void RESEARCH_GRAPH_SetHeapId(void *p, u32 v)
{
    ((struct ResearchObjB *)p)->heapId = v;
}

/*
 * Field getter, u32 at +0.
 *
 * Addresses are Black-image addresses.
 */
u32 RESEARCH_GRAPH_GetOwner(void *p)
{
    return ((struct ResearchObjB *)p)->ownerU;
}

void RESEARCH_GRAPH_SetOwner(void *p, u32 v)
{
    ((struct ResearchObjB *)p)->ownerU = v;
}

u32 RESEARCH_GRAPH_GetInputFlag(void *p)
{
    return RESEARCH_COMMON_GetInputFlag((void *)RESEARCH_GRAPH_GetOwner(p));
}

/*
 * Field setter, u32 at +0x2cc.
 *
 * Addresses are Black-image addresses.
 */
void RESEARCH_GRAPH_SetGraphKind(void *p, u32 v)
{
    ((struct ResearchObjB *)p)->graphKind = v;
}

u8 *RESEARCH_GRAPH_GetLeftCircle(void *p)
{
    u32 i = ((struct ResearchObjB *)p)->graphKind;
    return *(u8 **)((char *)p + i * 4 + 0x2bc);

}

u8 *RESEARCH_GRAPH_GetRightCircle(void *p)
{
    u32 i = ((struct ResearchObjB *)p)->graphKind;
    return *(u8 **)((char *)p + i * 4 + 0x2c4);

}

u32 RESEARCH_GRAPH_AreCirclesIdle(u32 a0)
{
    if (CircleGraph_IsAnimating(*(u8 * *)&((struct ResearchObjB *)a0)->leftCircleA) != 0 || CircleGraph_IsAnimating(*(u8 * *)&((struct ResearchObjB *)a0)->leftCircleB) != 0 || CircleGraph_IsAnimating(*(u8 * *)&((struct ResearchObjB *)a0)->rightCircleA) != 0 || CircleGraph_IsAnimating(*(u8 * *)&((struct ResearchObjB *)a0)->rightCircleB) != 0) {
    return 0;
    }
    return 1;
}

u32 RESEARCH_GRAPH_GetGroupKey(void *p)
{
    u32 i = ((struct ResearchObjB *)p)->groupIndex;
    return *(u8 *)((char *)p + i * 0xd4 + 0x3c);
}

u32 RESEARCH_GRAPH_GetGroupCount(void *p)
{
    u32 i = ((struct ResearchObjB *)p)->groupIndex;
    return *(u8 *)((char *)p + i * 0xd4 + 0x3d);
}

/*
 * Element field: u16 at +0x44 of a 12-byte sub-record of record 0xd4.
 *
 * Addresses are Black-image addresses.
 */
u32 RESEARCH_GRAPH_GetEntryKey(void *p)
{
    u32 i = ((u8 *)p)[0x2b8];
    u32 j = ((u8 *)p)[0x2b9];
    return *(u16 *)((char *)p + 0x44 + i * 0xd4 + j * 0xc);
}

u32 RESEARCH_GRAPH_GetGroupValue(void *p)
{
    u32 r = 0;
    switch (((struct ResearchObjB *)p)->graphKind) {
    case 0:
        r = RESEARCH_GRAPH_GetGroupTotalA(p);
        break;
    case 1:
        r = RESEARCH_GRAPH_GetGroupTotalB(p);
        break;
    }
    return r;
}

/*
 * Element field: u16 at +0x3e of record 0xd4 bytes, selected by the u8 at +0x2b8.
 *
 * Addresses are Black-image addresses.
 */
u32 RESEARCH_GRAPH_GetGroupTotalA(void *p)
{
    u32 i = ((struct ResearchObjB *)p)->groupIndex;
    return *(u16 *)((char *)p + i * 0xd4 + 0x3e);
}

u32 RESEARCH_GRAPH_GetGroupTotalB(void *p)
{
    u32 i = ((struct ResearchObjB *)p)->groupIndex;
    return *(u32 *)((char *)p + i * 0xd4 + 0x40);
}

u32 RESEARCH_GRAPH_GetEntryValue(char *p)
{
    switch (((struct ResearchObjB *)p)->graphKind) {
    case 0:
        return RESEARCH_GRAPH_GetEntryValueA(p);
    case 1:
        return RESEARCH_GRAPH_GetEntryValueB(p);
    }
    return 0;
}

/*
 * Element field: u16 at +0x4a of a 12-byte sub-record of record 0xd4.
 *
 * Addresses are Black-image addresses.
 */
u32 RESEARCH_GRAPH_GetEntryValueA(void *p)
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
u32 RESEARCH_GRAPH_GetEntryValueB(void *p)
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
u8 RESEARCH_GRAPH_GetFirstSaveGroup(u8 *p)
{
    u8 bytes[3];
    u8 a,b,c,j;
    void *base;
    int i;
    base=SYMBOL_SAVE_GetBitBlock(GAME_DATA_GetSaveControl((struct Big *)RESEARCH_GRAPH_GetAppResource(p)));
    for (i=0;i<3;i++) bytes[i]=MISC_SAVEDATA_GetStatusByte((int)base,i);
    b=bytes[1];
    c=bytes[2];
    a=bytes[0];
    for (j=0;j<10;j++) {
        if (a==d_021C363C[j] && b==d_021C3646[j] && c==d_021C3632[j]) return j;
    }
    return 0;
}

u32 RESEARCH_GRAPH_GetEntryIdBySave(u8 *p)
{
    void *bits;
    u32 index;
    u16 n;
    bits = SYMBOL_SAVE_GetQuestionnaireBits(SYMBOL_SAVE_GetBitBlock(GAME_DATA_GetSaveControl((struct Big *)RESEARCH_GRAPH_GetAppResource(p))));
    index = RESEARCH_GRAPH_GetGroupKey(p);
    if (index == 29) return RESEARCH_GRAPH_GetPlayTimeGroupId(p);
    n = SYMBOL_SAVE_GetQuestionnaireAnswer((const u8 *)bits, index);
    if (n == 0) return 0;
    n--;
    return (u8)GRAPHTABLE_GetEntryId(p + 0x38, p[0x2b8], n);
}

/*
 * extent: trailing 00 00 at 021BF9CA is two-byte alignment padding.
 * prototype: 02012FCC legacy trailing arguments omitted: full 12-byte body only reads r0, then returns its field at 0x6ac; no forwarding.
 * prototype: full 02012FCC body only reads r0, does not forward r1-r3; legacy trailing inputs omitted.
 */
u32 RESEARCH_GRAPH_GetPlayTimeGroupId(u8 *p)
{
    u32 v = PLAYTIME_GetHours((const struct PlayTime *)GAME_DATA_GetPlayTime(RESEARCH_GRAPH_GetAppResource(p)));
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
 *   +001C THM_CALL MISC_SAVEDATA_GetHalfword       -> unresolved: 0200E458 (arm, from name) has no witness outside 021BF9CC..021BF9EE
 * Promote automatically when the target is matched.
 *
 * Addresses are Black-image addresses.
 */
u16 RESEARCH_GRAPH_GetSaveBits(u32 a0)
{
    return MISC_SAVEDATA_GetHalfword((const u16 *)SYMBOL_SAVE_GetBitBlock(GAME_DATA_GetSaveControl((struct Big *)RESEARCH_GRAPH_GetAppResource((u8 *)a0))), RESEARCH_GRAPH_GetGroupKey((void *)a0));
}

u32 RESEARCH_GRAPH_GetClactUnit(void *p, u32 i)
{
    return *(u32 *)((char *)p + i * 4 + 0x368);
}

u32 RESEARCH_GRAPH_GetSharedHandle(void *p, u32 i)
{
    return *(u32 *)((char *)p + i * 4 + 0x384);
}

u32 RESEARCH_GRAPH_GetMarkerActor(void *p, u32 i)
{
    return *(u32 *)((char *)p + i * 4 + 0x394);
}

u32 RESEARCH_GRAPH_Alloc(u32 a0)
{
    return (u32)GFL_HEAP_Alloc(a0, 1000, 0, (const char *)0x21C400C, 4096);
}

void RESEARCH_GRAPH_InitFields(char *p)
{
    int i;
    ((struct ResearchObjB *)p)->state = 0;
    ((struct ResearchObjB *)p)->subState = 0;
    ((struct ResearchObjB *)p)->stateChanged = 0;
    ((struct ResearchObjB *)p)->count = 0xf;
    ((struct ResearchObjB *)p)->stateTimer = 0;
    ((struct ResearchObjB *)p)->elapsedTimer = 0;
    ((struct ResearchObjB *)p)->cursorIndex = 0;
    ((struct ResearchObjB *)p)->drawSystem = 0;
    ((struct ResearchObjB *)p)->entryShown = 0;
    ((struct ResearchObjB *)p)->touchSelected = 0;
    ((struct ResearchObjB *)p)->detailMode = 0;
    ((struct ResearchObjB *)p)->timerExpired = 0;
    ((struct ResearchObjB *)p)->updatedFlag = 0;
    ((struct ResearchObjB *)p)->groupIndex = 0;
    ((struct ResearchObjB *)p)->entryIndex = 0;
    ((struct ResearchObjB *)p)->graphKind = 0;
    ((struct ResearchObjB *)p)->fadeParamU = GFL_USE_GetMainTaskList();
    ((struct ResearchObjB *)p)->percentageCount = 0;
    ((struct ResearchObjB *)p)->percentageVisible = 0;
    ((struct ResearchObjB *)p)->active = 0;
    ((struct ResearchObjB *)p)->visible = 0;
    for (i = 0; i < 7; i++) {
        *(u32 *)(p + i * 4 + 0x368) = 0;
    }
    RESEARCH_GRAPH_ClearGraphTable((u8 *)p);
    RESEARCH_GRAPH_ClearCommandQueue(p);
    RESEARCH_GRAPH_ClearCircles(p);
    RESEARCH_GRAPH_ClearArrow(p);
    RESEARCH_GRAPH_ClearPercentages(p);
    RESEARCH_GRAPH_ClearMessages(p);
    RESEARCH_GRAPH_ClearWordSet(p);
    RESEARCH_GRAPH_ClearFont(p);
    RESEARCH_GRAPH_ClearLabels(p);
    RESEARCH_GRAPH_ClearUnits(p);
    RESEARCH_GRAPH_ClearActors(p);
    RESEARCH_GRAPH_ClearBmps(p);
    RESEARCH_GRAPH_ClearPalAnm(p);
    RESEARCH_GRAPH_ClearPaletteAnime(p);
}

u32 RESEARCH_GRAPH_Free(void *a0)
{
    return GFL_HEAP_Free(a0);
}

/*
 * Clear the u32 at +0x1c.
 *
 * Addresses are Black-image addresses.
 */
void RESEARCH_GRAPH_ClearCommandQueue(void *p)
{
    ((struct ResearchObjB *)p)->commandQueue = 0;
}

void RESEARCH_GRAPH_CreateCommandQueue(u32 a0)
{
    ((struct ResearchObjB *)a0)->commandQueue = RingQueue_Create(10, ((struct ResearchObjB *)a0)->heapId);
}

void RESEARCH_GRAPH_DestroyCommandQueue(u8 *a0)
{
    RingQueue_Destroy((void *)((u32)(((struct ResearchObjB *)a0)->commandQueue)));
}

/*
 * Clear the u32 at +8.
 *
 * Addresses are Black-image addresses.
 */
void RESEARCH_GRAPH_ClearFont(void *p)
{
    ((struct ResearchObjB *)p)->font = 0;
}

void RESEARCH_GRAPH_CreateFont(u32 a0)
{
    u8 s[4];
    ((struct ResearchObjB *)a0)->font = (u32)GF_FONT_Create(23, 0, 0, 0, (u32)(((struct ResearchObjB *)a0)->heapId));
}

/*
 * Tail-call veneer: forwards arg(s) (u32)(*(u32*)(a0 + 8)) to GF_FONT_Delete.
 *
 * Addresses are Black-image addresses.
 */
void RESEARCH_GRAPH_DeleteFont(u8 *a0)
{
    GF_FONT_Delete((void *)((u32)(((struct ResearchObjB *)a0)->font)));
}

/*
 * Clear three u32 slots at +0xc.
 *
 * Addresses are Black-image addresses.
 */
void RESEARCH_GRAPH_ClearMessages(void *p)
{
    int i;
    for (i = 0; i < 3; i++)
        *(u32 *)((char *)p + i * 4 + 0xc) = 0;
}

void RESEARCH_GRAPH_CreateMessages(MessageView *p)
{
    int i;
    for (i = 0; i < 3; i++) {
        p->messages[i] = (u32)MSGDATA_CreateFromArchive(0, 2, (u16)d_021C3650[i], (u16)p->heapId);
    }
}

void RESEARCH_GRAPH_DeleteMessages(int *p)
{
    int i;
    for (i = 0; i < 3; i++)
        MSGDATA_Delete((struct Rec *)p[i + 3]);
}

void RESEARCH_GRAPH_ClearWordSet(void *p)
{
    ((struct ResearchObjB *)p)->wordSet = 0;
}

void RESEARCH_GRAPH_CreateWordSet(u32 a0)
{
    ((struct ResearchObjB *)a0)->wordSet = (void *)WORDSET_CreateDefault(((struct ResearchObjB *)a0)->heapId);
}

void RESEARCH_GRAPH_DeleteWordSet(u8 *a0)
{
    WORDSET_DeleteStrbufED04((struct WordSet *)((u32)(((struct ResearchObjB *)a0)->wordSet)));
}

/*
 * Clear two pairs of u32 slots at +0x2bc and +0x2c4.
 *
 * Addresses are Black-image addresses.
 */
void RESEARCH_GRAPH_ClearCircles(void *p)
{
    int i;
    for (i = 0; i < 2; i++) {
        *(u32 *)((char *)p + i * 4 + 0x2bc) = 0;
        *(u32 *)((char *)p + i * 4 + 0x2c4) = 0;
    }
}

void RESEARCH_GRAPH_CreateCircles(char *p)
{
    int i;
    for (i = 0; i < 2; i++) {
        *(u32 *)(p + i * 4 + 0x2bc) = CircleGraph_Create(((struct ResearchObjB *)p)->heapId);
        *(u32 *)(p + i * 4 + 0x2c4) = CircleGraph_Create(((struct ResearchObjB *)p)->heapId);
    }
}

void RESEARCH_GRAPH_DestroyCircles(char *p)
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
void RESEARCH_GRAPH_ClearGraphTable(u8 *a0)
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
 * src/matched/arm9/MISC_SAVEDATA_GetTallyWord.c (EXACT, 10 bytes); this goes EXACT once
 * that file has a shard (integrator).
 * Note 2026-10-04 (wD1 lane06): Not retried (203 bytes, stack slot order only). No new finding.
 */
void RESEARCH_GRAPH_BuildGraphTable(char *p)
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
    h = SYMBOL_SAVE_GetBitBlock(GAME_DATA_GetSaveControl((struct Big *)RESEARCH_GRAPH_GetAppResource((u8 *)p)));
    first = RESEARCH_GRAPH_GetFirstSaveGroup((u8 *)p);
    i = 0;
    grp[0] = MISC_SAVEDATA_GetStatusByte((int)h, 0);
    grp[1] = MISC_SAVEDATA_GetStatusByte((int)h, 1);
    grp[2] = MISC_SAVEDATA_GetStatusByte((int)h, 2);
    cnt[0] = d_021C367C[grp[0]];
    cnt[1] = d_021C367C[grp[1]];
    cnt[2] = d_021C367C[grp[2]];
    va[0] = MISC_SAVEDATA_GetHalfword(h, grp[0]);
    va[1] = MISC_SAVEDATA_GetHalfword(h, grp[1]);
    va[2] = MISC_SAVEDATA_GetHalfword(h, grp[2]);
    vb[0] = MISC_SAVEDATA_GetTallyWord(h, grp[0]);
    vb[1] = MISC_SAVEDATA_GetTallyWord(h, grp[1]);
    vb[2] = MISC_SAVEDATA_GetTallyWord(h, grp[2]);
    for (i = 0; i < 3; i++) {
        u8 g = grp[i];
        n = cnt[i];
        for (j = 0; j < n; j++) {
            sh[i][j] = d_021C3D44[g][j];
            A[i][j] = MISC_SAVEDATA_GetTallyValue(h, g, j + 1);
            B[i][j] = MISC_SAVEDATA_GetScoreValue((int)h, g, j + 1);
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

void RESEARCH_GRAPH_InitTouchRects(u8 *p)
{
    int i;
    for (i = 0; i < 9; i++) {
        p[i * 4 + 0x300] = d_021C3758[i].x;
        p[i * 4 + 0x301] = d_021C3758[i].y;
        p[i * 4 + 0x2fe] = d_021C3758[i].w;
        p[i * 4 + 0x2ff] = d_021C3758[i].h;
    }
}

/*
 * Clear the u32 at +0x2d0.
 *
 * Addresses are Black-image addresses.
 */
void RESEARCH_GRAPH_ClearArrow(void *p)
{
    ((struct ResearchObjB *)p)->arrow = 0;
}

void RESEARCH_GRAPH_CreateArrow(char *p)
{
    struct ArrowCreateArgs args;
    args.charId = RESEARCH_GRAPH_GetClactUnit(p, 0);
    args.paletteId = RESEARCH_GRAPH_GetClactUnit(p, 1);
    args.cellId = RESEARCH_GRAPH_GetClactUnit(p, 2);
    args.space = 0;
    args.animSeq[0] = 0;
    args.animSeq[1] = 1;
    args.animSeq[2] = 2;
    args.animSeq[3] = 3;
    ((struct ResearchObjB *)p)->arrow = (void *)ARROW_Create(((struct ResearchObjB *)p)->heapId, (u32)&args);
}

/*
 * Tail-call veneer: forwards arg(s) (u32)(*(u32*)(a0 + 720)), 720 to ARROW_Destroy.
 *
 * Addresses are Black-image addresses.
 */
void RESEARCH_GRAPH_DestroyArrow(u8 *a0)
{
    ARROW_Destroy((void *)(((struct ResearchObjB *)a0)->arrow));
}

/*
 * Clear ten u32 slots at +0x2d4.
 *
 * Addresses are Black-image addresses.
 */
void RESEARCH_GRAPH_ClearPercentages(void *p)
{
    int i;
    for (i = 0; i < 10; i++)
        *(u32 *)((char *)p + i * 4 + 0x2d4) = 0;
}

/*
 * lever: p + i * 4 + 0x2d4 keeps the indexed base before the call; p + 0x2d4 + i * 4 differed by 23 bytes.
 */
void RESEARCH_GRAPH_CreatePercentages(char *p)
{
    struct PercentageCreateArgs args;
    int i;
    args.charIndex = RESEARCH_GRAPH_GetClactUnit(p, 0);
    args.paletteIndex = RESEARCH_GRAPH_GetClactUnit(p, 1);
    args.cellAnimIndex = RESEARCH_GRAPH_GetClactUnit(p, 2);
    args.priority = 0;
    args.digitAnimSeq = 12;
    args.signAnimSeq = 13;
    for (i = 0; i < 10; i++) {
        *(u32 *)(p + i * 4 + 0x2d4) = PERCENTAGE_Create(((struct ResearchObjB *)p)->heapId, (u32)&args, RESEARCH_GRAPH_GetSharedHandle(p, 3));
        PERCENTAGE_SetVisible(*(u32 *)(p + i * 4 + 0x2d4), 0);
    }
}

void RESEARCH_GRAPH_DestroyPercentages(int *p)
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
void RESEARCH_GRAPH_InitScreen(void)
{
    G3X_Init();
    G3X_InitMtxStack();
    *(volatile u32 *)0x04000440 = 0;
    *(volatile u32 *)0x04000454 = 0;
    *(volatile u32 *)0x04000440 = 2;
    *(volatile u32 *)0x04000454 = 0;
    *(volatile u16 *)0x04000060 = (*(volatile u16 *)0x04000060 & ~0x3000) | 0x10;
    *(volatile u16 *)0x04000060 = (*(volatile u16 *)0x04000060 & ~0x3000) | 0x20;
    G3X_SetEdgeColorTable(d_021C365C);
}

struct DispConfig { u32 graphicsMode, bgMode, vramMode, layerMode; };

struct BgTemplate { u32 dispcnt, bgMode, bufSize, layerMode; unsigned char screenSize, colorMode, screenBase, charBase; u32 vramOffset; unsigned char bgControl, priority, reservedA, reservedB; u32 mosaic; };

struct Config { u8 bgLayer, winX, winY, winWidth, winHeight, textX, textY, palette, red, green, blue; u32 centered; };

struct GraphLabelEntry { u8 bgLayer, winX, winY, winWidth, winHeight, textX, textY, palette, red, green, blue; u32 messageIndex, messageMode, centered; };

struct ActorEntry { s16 x,y,z; u8 a,b; u32 sharedHandle, unitA, unitB, unitC; u16 space, pad; };

struct EntryUnit { int x,y,z,bank,index,px,py; u8 r,g,b,pad2; u32 arc,member,enabled; };

extern void BG_SYS_SetGraphicsMode(struct DispConfig *);

extern void BG_SYS_SetLowBit(u32);

extern void BG_SYS_InitBgLayer(u32, const struct BgTemplate *, u32);

extern void BG_SYS_SetPlaneVisible(unsigned char which, unsigned char enable);

extern void G2x_SetBlendAlpha_(u32 *, u32, u32, int, int);

extern u32 BG_SYS_FreeLayerBuf();

extern void CLACT_ReleasePalette(u32 i);

extern struct Obj *CLACT_CreateActor(void *owner, unsigned int i, unsigned int j, unsigned int k, const void *position, unsigned short space, unsigned short heap);

extern void BMP_Delete(struct Bmp *);

extern struct DispConfig d_021C366C;

extern const struct BgTemplate d_021C36D8,d_021C36F8,d_021C3718,d_021C3738;

extern const struct GraphLabelEntry d_021C3B7C[];

extern const u16 d_021C3620[];

extern const u8 d_021C3618[];

extern const struct ActorEntry d_021C37FC[];

extern const struct EntryUnit d_021C37A4[];

/*
 * data: pool 021C0068 contains 6c 36 1c 02; contested ov217 hint removed per canonical rule, data a4 resolves sole-ref.
 */
void RESEARCH_GRAPH_InitOverlayBackgrounds(char *p)
{
    BG_SYS_SetGraphicsMode(&d_021C366C);
    BG_SYS_SetLowBit(2);
    BG_SYS_InitBgLayer(6, &d_021C36D8, 0);
    BG_SYS_InitBgLayer(7, &d_021C3738, 0);
    BG_SYS_InitBgLayer(2, &d_021C36F8, 0);
    BG_SYS_InitBgLayer(3, &d_021C3718, 0);
    BG_SYS_SetPlaneVisible(4, 1);
    BG_SYS_SetPlaneVisible(5, 1);
    BG_SYS_SetPlaneVisible(6, 1);
    BG_SYS_SetPlaneVisible(7, 1);
    BG_SYS_SetPlaneVisible(0, 1);
    BG_SYS_SetPlaneVisible(1, 1);
    BG_SYS_SetPlaneVisible(2, 1);
    BG_SYS_SetPlaneVisible(3, 1);
    G2x_SetBlendAlpha_((u32 *)0x04001050, 2, 1, 7, 15);
    G2x_SetBlendAlpha_((u32 *)0x04000050, 4, 2, 16, 5);
    BMP_WIN_Init(((struct ResearchObjB *)p)->heapId);
}

/*
 * Reconstructed from the listing (.inst decoded).
 *
 * Addresses are Black-image addresses.
 */
u32 RESEARCH_GRAPH_ExitOverlayBackgrounds()
{
    BMP_WIN_Exit();
    BG_SYS_FreeLayerBuf(0);
    BG_SYS_FreeLayerBuf(3);
    BG_SYS_FreeLayerBuf(2);
    BG_SYS_FreeLayerBuf(7);
    return BG_SYS_FreeLayerBuf(6);
}

void RESEARCH_GRAPH_LoadBackground6(char *p)
{
    void *out;
    void *h;
    void *blob;
    h = ARC_TOOL_CreateHandle(192, ((struct ResearchObjB *)p)->heapId);
    blob = ARC_TOOL_LoadHandleMember((struct ArcFile *)h, 13, ((struct ResearchObjB *)p)->heapId);
    NNS_G2dGetUnpackedScreenData(blob, &out);
    BG_SYS_DrawTile(6, (u32)((char *)out + 12), 0, 0, 32, 24);
    BG_SYS_PushTile(6);
    GFL_HEAP_Free((void *)((u32)blob));
    ARC_TOOL_DeleteHandle(h);
}

/*
 * Empty stub.
 *
 * Addresses are Black-image addresses.
 */
void RESEARCH_GRAPH_DummyBg7()
{
}

u32 RESEARCH_GRAPH_UpdateBackground7()
{
    BG_SYS_Init(7, 0, 1, 0);
    return BG_SYS_ClearSlot(7);
}

/*
 * Tail-call veneer: forwards arg(s) 7, 1, 0 to BG_SYS_SetTileUnit.
 *
 * Addresses are Black-image addresses.
 */
void RESEARCH_GRAPH_ShowBackground7()
{
    BG_SYS_SetTileUnit(7, 1, 0);
}

/*
 * extent: trailing 00 00 at 021C016E is two-byte alignment padding.
 */
void RESEARCH_GRAPH_LoadBackground2(char *p)
{
    void *out;
    void *h;
    void *blob;
    h = ARC_TOOL_CreateHandle(192, ((struct ResearchObjB *)p)->heapId);
    blob = ARC_TOOL_LoadHandleMember((struct ArcFile *)h, 7, ((struct ResearchObjB *)p)->heapId);
    NNS_G2dGetUnpackedScreenData(blob, &out);
    BG_SYS_DrawTile(2, (u32)((char *)out + 12), 0, 0, 32, 32);
    BG_SYS_PushTile(2);
    GFL_HEAP_Free((void *)((u32)blob));
    ARC_TOOL_DeleteHandle(h);
}

void RESEARCH_GRAPH_DummyBg3()
{
}

u32 RESEARCH_GRAPH_UpdateBackground3()
{
    BG_SYS_Init(3, 0, 1, 0);
    return BG_SYS_ClearSlot(3);
}

/*
 * Tail-call veneer: forwards arg(s) 3, 1, 0 to BG_SYS_SetTileUnit.
 *
 * Addresses are Black-image addresses.
 */
void RESEARCH_GRAPH_ShowBackground3(u32 a0, u32 a1, u32 a2)
{
    BG_SYS_SetTileUnit(3, 1, 0);
}

/*
 * Clear nine u32 slots at +0x344.
 *
 * Addresses are Black-image addresses.
 */
void RESEARCH_GRAPH_ClearLabels(void *p)
{
    int i;
    for (i = 0; i < 9; i++)
        *(u32 *)((char *)p + i * 4 + 0x344) = 0;
}

/*
 * lever: direct indexed assignment computes and spills the destination before allocation; a handle temporary first gave 116 bytes and 47 differing bytes.
 * prototype: keep caller's visible second argument to 021C0F5C despite its legacy one-argument source (021C021C loads r1 before call).
 */
void RESEARCH_GRAPH_CreateLabels(char *p)
{
    struct Config args;
    int i;
    for (i = 0; i < 9; i++) {
        u32 handle;
        args.bgLayer = d_021C3B7C[i].bgLayer;
        args.winX = d_021C3B7C[i].winX;
        args.winY = d_021C3B7C[i].winY;
        args.winWidth = d_021C3B7C[i].winWidth;
        args.winHeight = d_021C3B7C[i].winHeight;
        args.textX = d_021C3B7C[i].textX;
        args.textY = d_021C3B7C[i].textY;
        args.palette = d_021C3B7C[i].palette;
        args.red = d_021C3B7C[i].red;
        args.green = d_021C3B7C[i].green;
        args.blue = d_021C3B7C[i].blue;
        args.centered = d_021C3B7C[i].centered;
        *(u32 *)(p + i * 4 + 0x344) = (u32)BgTextLabel_Create(&args, ((struct ResearchObjB *)p)->font, *(u32 *)(p + d_021C3B7C[i].messageIndex * 4 + 12), ((struct ResearchObjB *)p)->heapId);
        handle = *(u32 *)(p + i * 4 + 0x344);
        BgTextLabel_PrintMessage(handle, d_021C3B7C[i].messageMode);
    }
}

/*
 * Addresses are Black-image addresses.
 */
void RESEARCH_GRAPH_DestroyLabels(int *p)
{
    int i;
    for (i = 0; i < 9; i++) {
        BgTextLabel_Destroy((u8 *)p[i + 0xD1]);
        p[i + 0xD1] = 0;
    }
}

void RESEARCH_GRAPH_RegisterEntryResources(char *p)
{
    u16 heap = ((struct ResearchObjB *)p)->heapId;
    void *h = ARC_TOOL_CreateHandle(192, heap);
    int a = CLACT_RegisterCharacter((void *)((u32)h), 15, 0, 1, heap);
    int b = CLACT_RegisterPalette((void *)h, 16, 1, 0, heap);
    int c = CLACT_RegisterCellAnim((void *)((u32)h), 14, 17, heap);
    ((struct ResearchObjB *)p)->clactUnits[4] = a;
    ((struct ResearchObjB *)p)->clactUnits[5] = b;
    ((struct ResearchObjB *)p)->clactUnits[6] = c;
    ARC_TOOL_DeleteHandle(h);
}

u32 RESEARCH_GRAPH_ReleaseEntryResources(u32 a0)
{
    CLACT_ReleaseCharacter(((struct ResearchObjB *)(((u8*)a0)))->clactUnits[4]);
    CLACT_ReleasePalette(((struct ResearchObjB *)(((u8*)a0)))->clactUnits[5]);
    return CLACT_ReleaseCellAnim(((struct ResearchObjB *)(((u8*)a0)))->clactUnits[6]);
}

void RESEARCH_GRAPH_RegisterCursorResources(char *p)
{
    u16 heap = ((struct ResearchObjB *)p)->heapId;
    void *h = ARC_TOOL_CreateHandle(192, heap);
    int a = CLACT_RegisterCharacter((void *)((u32)h), 15, 0, 0, heap);
    int b = CLACT_RegisterPaletteEx((void *)((u32)h), 16, 0, 192, 0, 3, heap);
    int c = CLACT_RegisterCellAnim((void *)((u32)h), 14, 17, heap);
    int d;
    ARC_TOOL_DeleteHandle(h);
    h = ARC_TOOL_CreateHandle(83, heap);
    d = CLACT_RegisterPaletteEx((void *)((u32)h), 31, 0, 128, 0, 2, heap);
    ARC_TOOL_DeleteHandle(h);
    ((struct ResearchObjB *)p)->clactUnits[0] = a;
    ((struct ResearchObjB *)p)->clactUnits[1] = b;
    ((struct ResearchObjB *)p)->clactUnits[3] = d;
    ((struct ResearchObjB *)p)->clactUnits[2] = c;
}

u32 RESEARCH_GRAPH_ReleaseCursorResources(u32 a0)
{
    CLACT_ReleaseCharacter(((struct ResearchObjB *)(((u8*)a0)))->clactUnits[0]);
    CLACT_ReleasePalette(((struct ResearchObjB *)(((u8*)a0)))->clactUnits[1]);
    CLACT_ReleasePalette(((struct ResearchObjB *)(((u8*)a0)))->clactUnits[3]);
    return CLACT_ReleaseCellAnim(((struct ResearchObjB *)(((u8*)a0)))->clactUnits[2]);
}

void RESEARCH_GRAPH_ClearUnits(void *p)
{
    int i;
    for (i = 0; i < 4; i++)
        *(u32 *)((char *)p + i * 4 + 0x384) = 0;
}

void RESEARCH_GRAPH_CreateUnits(u8 *p)
{
    int i;
    for (i = 0; i < 4; i++)
        *(int *)(p + i * 4 + 0x384) = (int)CLACT_CreateUnit(d_021C3620[i], d_021C3618[i], ((struct ResearchObjB *)p)->heapId);
}

void RESEARCH_GRAPH_DeleteUnits(int *p)
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
void RESEARCH_GRAPH_ClearActors(void *p)
{
    int i;
    for (i = 0; i < 4; i++)
        *(u32 *)((char *)p + i * 4 + 0x394) = 0;
}

/*
 * prototype: 0204B294 result observed in r0 despite legacy matched void return.
 */
void RESEARCH_GRAPH_CreateActors(u8 *p)
{
    struct Arg arg;
    const struct ActorEntry *q;
    u8 *dest;
    int i;
    u32 a,b,c,d;
    for(i=0;i<4;i++) {
        q=&d_021C37FC[i];
        arg.x=q->x; arg.y=q->y; arg.z=q->z; arg.a=q->a; arg.b=q->b;
        a=RESEARCH_GRAPH_GetSharedHandle(p,q->sharedHandle);
        b=RESEARCH_GRAPH_GetClactUnit(p,q->unitA);
        c=RESEARCH_GRAPH_GetClactUnit(p,q->unitB);
        d=RESEARCH_GRAPH_GetClactUnit(p,q->unitC);
        dest=p+i*4;
        *(u32 *)&((struct ResearchObjB *)dest)->markerActorA=(u32)CLACT_CreateActor((void *)a,b,c,d,&arg,q->space,((struct ResearchObjB *)p)->heapId);
        CLACT_SetActorDrawEnable(*(struct Obj * *)&((struct ResearchObjB *)dest)->markerActorA,0);
    }
}

void RESEARCH_GRAPH_DeleteActors(int *p)
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
void RESEARCH_GRAPH_ClearBmps(void *p)
{
    int i;
    for (i = 0; i < 2; i++)
        *(u32 *)((char *)p + i * 4 + 0x3b0) = 0;
}

void RESEARCH_GRAPH_CreateBmps(u8 *p)
{
    int i;
    for (i = 0; i < 2; i++)
        *(int *)(p + i * 4 + 0x3B0) = (int)BMP_Create(d_021C37A4[i].x, d_021C37A4[i].y, d_021C37A4[i].z, ((struct ResearchObjB *)p)->heapId);
}

void RESEARCH_GRAPH_DrawBmps(u8 *p)
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
            bmp=BMP_CreateFromArchive(q->arc,q->member,0,((struct ResearchObjB *)p)->heapId);
            dest=p+i*4;
            BMP_Blit(bmp,*(struct Bmp * *)&((struct ResearchObjB *)dest)->bmps[0],0,0,0,0,q->x<<3,q->y<<3,q->b);
            color=((q->r&31)<<10)|((q->g&31)<<5)|(q->b&31);
            text=MSGDATA_AllocString(*(struct MsgBank **)(p+12+q->bank*4),q->index);
            PRINTSYS_PrintColor(((struct ResearchObjB *)dest)->bmps[0],q->px,q->py,text,(void *)((struct ResearchObjB *)p)->font,color);
            GFL_HEAP_Free(text);
            BMP_Delete((struct Bmp *)bmp);
        }
    }
}

#define E ((const struct EntryUnit *)gb)

struct Comm;

struct RowQueue {
    int cells[20];
};

struct Tab {
    struct RowQueue rows[3];
};

struct OamObjectParam { void *bmp; s16 x,y; u32 animResId, palette; u8 drawPriority, bgPriority; u16 space; u32 engine; };

struct OamObjectRow { s16 x,y; u32 clactUnitIndex, palette; u8 drawPriority, bgPriority; u16 space; u32 engine; };

struct PaletteAnimeBind {
    u32 palette;
    u32 original;
    u8 colorCount;
    u8 pad[11];
};

extern int BMP_OAM_CreateSys(u16 heap, int a);

extern struct Grid *BMP_OAM_Create(struct Sys *,const struct OamObjectParam *);

extern u32 ICA_ANIME_GetField24(const struct Ctx *);

extern void GAME_COMM_RequestExitNoCallback(struct Comm *p);

extern u32 GAME_COMM_GetKind(void *obj);

extern void GAME_COMM_SetNotifyFlag(void *obj, u32 flag);

extern const struct Tab d_021C3C54;

extern const struct EntryUnit d_021C37D0;

extern const struct OamObjectRow d_021C377C[];

extern const struct PaletteAnimeBind d_021C3A28[];

void RESEARCH_GRAPH_DrawBadge(u8 *p)
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
            BMP_Blit(bmp, *(struct Bmp **)(p + 0x3B4), (tab.rows[i].cells[j] % 3) * 8, (tab.rows[i].cells[j] / 3) * 8, j * 8, y, 8, 8, 0);
        }
    }
    BMP_Delete((struct Bmp *)bmp);
    color = ((E->r & 31) << 10) | ((E->g & 31) << 5) | (E->b & 31);
    text = MSGDATA_AllocString(*(struct MsgBank **)(p + 12 + E->bank * 4), E->index);
    PRINTSYS_PrintColor(*(void **)(p + 0x3B4), E->px, E->py, text, *(void **)(p + 8), color);
    GFL_HEAP_Free(text);
}

void RESEARCH_GRAPH_DeleteBmps(int *p)
{
    int i;
    for (i = 0; i < 2; i++)
        BMP_Delete((struct Bmp *)p[i + 0xEC]);
}

void RESEARCH_GRAPH_CreateOamSys(u8 *p)
{
    ((struct ResearchObjB *)p)->oamSys = BMP_OAM_CreateSys(((struct ResearchObjB *)p)->heapId, ((struct ResearchObjB *)p)->units[2]);
}

void RESEARCH_GRAPH_DeleteOamSys(u8 *a0)
{
    BMP_OAM_DeleteSys((void *)((u32)(((struct ResearchObjB *)a0)->oamSys)));
}

/*
 * note 2026-10-05 (wave D9r lane 131): removed the 4 dead first assignments
 * (`sysOff=0x3B0;` before `sysOff=0x3A4;`; `outOff=0x3B0;` before
 * `outOff=0x3A8;` and 2 more). Game code has no line table, so these were
 * stand-ins. The plain single assignment gives EXACT in --lang c99 and
 * --lang c: the output bytes do not change. Older text in this header that
 * asks for the double assignment is superseded.
 */
void RESEARCH_GRAPH_CreateOamObjects(u8 *p)
{
    int sysOff,outOff,callOff,uploadOff;
    struct OamObjectParam param;
    int i;
    const struct OamObjectRow *q;
    u8 *dest;
    sysOff=0x3A4;
    outOff=0x3A8;
    callOff=0x3A8;
    uploadOff=0x3A8;
    for(i=0;i<2;i++) {
        dest=p+i*4;
        param.bmp=((struct ResearchObjB *)dest)->bmps[0];
        q=&d_021C377C[i];
        param.x=q->x; param.y=q->y;
        param.animResId=RESEARCH_GRAPH_GetClactUnit(p,q->clactUnitIndex);
        param.palette=q->palette;
        param.drawPriority=q->drawPriority; param.bgPriority=q->bgPriority;
        param.space=q->space; param.engine=q->engine;
        *(struct Grid **)(dest+outOff)=BMP_OAM_Create(*(struct Sys **)(p+sysOff),&param);
        BMP_OAM_SetEnabled(*(u8 **)(dest+callOff),0);
        BMP_OAM_UploadChars(*(struct Obj **)(dest+uploadOff));
    }
}

/*
 * Addresses are Black-image addresses.
 */
void RESEARCH_GRAPH_DeleteOamObjects(int *p)
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
void RESEARCH_GRAPH_ClearPalAnm(void *p)
{
    ((struct ResearchObjB *)p)->palAnm = 0;
}

void RESEARCH_GRAPH_CreatePalAnm(u8 *p)
{
    ((struct ResearchObjB *)p)->palAnm = PALANM_Create(((struct ResearchObjB *)p)->heapId);
    PALANM_AllocSlotBuffers(((struct ResearchObjB *)p)->palAnm, 0, 512, ((struct ResearchObjB *)p)->heapId);
    PALANM_AllocSlotBuffers(((struct ResearchObjB *)p)->palAnm, 2, 512, ((struct ResearchObjB *)p)->heapId);
    PALANM_CopyHwPaletteToSlot(((struct ResearchObjB *)p)->palAnm, 0, 0, 512);
    PALANM_CopyHwPaletteToSlot(((struct ResearchObjB *)p)->palAnm, 2, 0, 512);
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
u32 RESEARCH_GRAPH_DeletePalAnm(u32 a0)
{
    PALANM_FreeSlotBuffers((struct PalAnmSlot *)(((struct ResearchObjB *)(((u8*)a0)))->palAnm), 0);
    PALANM_FreeSlotBuffers((struct PalAnmSlot *)(((struct ResearchObjB *)(((u8*)a0)))->palAnm), 2);
    return PALANM_Delete((void *)(((struct ResearchObjB *)(((u8*)a0)))->palAnm));
}

void RESEARCH_GRAPH_ClearPaletteAnime(void *p)
{
    int i;
    for (i = 0; i < 8; i++)
        *(u32 *)((char *)p + i * 4 + 0x324) = 0;
}

void RESEARCH_GRAPH_CreatePaletteAnime(u8 *p)
{
    int i;
    for (i = 0; i < 8; i++)
        *(int *)(p + i * 4 + 0x324) = PALETTE_ANIME_Create(((struct ResearchObjB *)p)->heapId);
}

void RESEARCH_GRAPH_DestroyPaletteAnime(int *p)
{
    int i;
    for (i = 0; i < 8; i++)
        PALETTE_ANIME_Destroy((void *)p[i + 0xC9]);
}

void RESEARCH_GRAPH_BindPaletteAnime(u8 *p)
{
    int i;
    for (i = 0; i < 8; i++)
        PALETTE_ANIME_Bind((void *)(*(int *)(p + i * 4 + 0x324)), d_021C3A28[i].palette, d_021C3A28[i].original, d_021C3A28[i].colorCount);
}

void RESEARCH_GRAPH_RestorePaletteAnime(int *p)
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
void RESEARCH_GRAPH_RestartNetwork(u32 a0)
{
    GFL_NET_RestartWithDefaultTimeout(1, ((struct ResearchObjB *)(((u8*)a0 + 0)))->heapId);
}

void RESEARCH_GRAPH_RegisterVBlank(char *p)
{
    ((struct ResearchObjB *)p)->vblankNode = GFL_USE_AddMainTask((void (*)(void))RESEARCH_GRAPH_TransferPalettes, p, 0);
}

/*
 * Tail-call veneer: forwards arg(s) (u32)(*(u32*)(a0 + 960)), 960 to TCB_DeleteTask.
 *
 * Addresses are Black-image addresses.
 */
void RESEARCH_GRAPH_UnregisterVBlank(u8 *a0)
{
    TCB_DeleteTask((struct Node *)((u32)(((struct ResearchObjB *)a0)->vblankNode)));
}

u32 RESEARCH_GRAPH_ClampByte(s32 v)
{
    if (v < 0)
        return 0;
    if (v > 0xff)
        return 0xff;
    return (u8)v;
}

/*
 * Opens the +0x10 record (ICA_ANIME_GetField24 on the result of RESEARCH_GRAPH_GetContext),
 * tags it with 1, and releases it when GAME_COMM_GetKind reports state 2.
 * Closed by the generator's duplicate guard statement (O89).
 *
 * Addresses are Black-image addresses.
 */
void RESEARCH_GRAPH_OpenComm(u8 *a0)
{
    u32 v1 = ICA_ANIME_GetField24((const struct Ctx *)RESEARCH_GRAPH_GetContext(a0));
    GAME_COMM_SetNotifyFlag((void *)v1, 1);
    if (GAME_COMM_GetKind((void *)v1) == 2) {
    GAME_COMM_RequestExitNoCallback((struct Comm *)v1);
    }
}

int RESEARCH_GRAPH_GetCommKindOrStart(u8 *a0)
{
    u32 r;
    r = RESEARCH_GRAPH_GetContext(a0);
    switch (GAME_COMM_GetKind((void *)ICA_ANIME_GetField24((const struct Ctx *)r))) {
    case 0:
        GAMESYSTEM_TryStartAutoComm((struct IcaAnime *)r);
        return 1;
    default:
        return 1;
    case 2:
        return 0;
    }
}

void RESEARCH_GRAPH_ClearNotifyFlag(unsigned char *a0)
{
    GAME_COMM_SetNotifyFlag((void *)ICA_ANIME_GetField24((const struct Ctx *)RESEARCH_GRAPH_GetContext(a0)), 0);
}
