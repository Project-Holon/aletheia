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
 *   BG_SYS_FreeTiles  0x02040DA8  arm
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
 *   SYMBOL_SAVE_ReadBitField 0x0200E3A4 thumb
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
 *   WORDSET_Delete  0x0201ED04  thumb
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
 *   GFL_NET_RefreshWmIconAtTopRight  0x0203D34C  arm  arm9
 *   BMP_WIN_Exit  0x020450C8  arm  arm9
 *   CLACT_ReleaseCharacter  0x0204A8D4  arm  arm9
 *   CLACT_ReleasePalette  0x0204ADA4  arm  arm9
 *   CLACT_ReleaseCellAnim  0x0204AFD8  arm  arm9
 *   FADE_IsActive  0x0204E804  arm  arm9
 *   BG_SYS_EnableBg0WithPriority 0x0204044C arm
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
 *   GAMESYSTEM_GetGameComm  0x02012138  thumb
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
 *   _u32_div_f                   0x0209C2B0  arm
 */
struct ActorInitParam;
struct ClactActor;
struct ClactVec2;
struct PaletteFade;
struct Unit;
#include "../arm9/arc_tool.h"
#include "../sdk_ioreg.h"
#include "../arm9/palanm.h"
#include "../arm9/touchpanel.h"
#include "../arm9/bmp_oam.h"
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
struct GameSystem;

extern u32 GAMESYSTEM_TryStartAutoComm(struct GameSystem *gameSystem);

extern void GFL_NET_RefreshWmIconAtTopRight(u32 a, u32 b);



extern u32 GFL_HEAP_Free(void *p);

extern int NNS_G2dGetUnpackedScreenData(void *, void **);

extern void BG_SYS_DrawTile(u32, u32, u32, u32, u8, u8);

extern int BG_SYS_PushTile(int);

extern void ARC_TOOL_DeleteHandle(void *);

extern void BG_SYS_FillTileMap(unsigned char index, unsigned char x0, unsigned char y0, unsigned char w, unsigned char h, unsigned char pal);
struct ResearchCommon;

extern u32 RESEARCH_COMMON_GetHeapId(struct ResearchCommon *common);

extern void RESEARCH_COMMON_UpdatePaletteAnime(unsigned);

extern void CLACT_DrawSystem();

extern u32 KEY_GetTrg(void);


extern void * RESEARCH_COMMON_GetTouchRects(struct ResearchCommon *common);

extern u32 GFL_USE_PlaySeDefaultVolume(u32 a);

extern int FADE_IsActive(void);

extern void RESEARCH_COMMON_StopPaletteAnime(u32 common);

extern void RESEARCH_COMMON_RestorePaletteAnime(u32 common);
struct RingQueue;

extern void RingQueue_Push(struct RingQueue *queue, int value);

extern u32 RingQueue_Pop(struct RingQueue *queue);

extern int RingQueue_IsEmpty(struct RingQueue *queue);

extern u32 RESEARCH_COMMON_GetPreviousScreen(struct ResearchCommon *common);

extern u32 RESEARCH_COMMON_GetEntryHandled(struct ResearchCommon *common);

extern void RESEARCH_COMMON_SetEntryHandled(struct ResearchCommon *common, unsigned int value);

extern u8 GAME_BEACON_PopQuestionnaireUpdated(void);

extern void RESEARCH_COMMON_StartPaletteAnime(struct ResearchCommon *common, unsigned int index);
struct Actor;

extern void CLACT_SetActorDrawEnable(struct ClactActor *actor, unsigned int value);

extern void CLACT_SetActorAutoAnim(struct ClactActor *actor, unsigned int enable);

extern void FADE_Start(u32 a, s32 b, s32 c, s32 d);
struct PaletteAnime;

extern void PALETTE_ANIME_Start(struct PaletteAnime *anime, unsigned int mode, unsigned short color);

extern void PALETTE_ANIME_Stop(struct PaletteAnime *anime);

extern void PALETTE_ANIME_Update(struct PaletteAnime *anime);

extern unsigned RESEARCH_COMMON_GetAppResource(struct ResearchCommon *common);

extern u32 RESEARCH_COMMON_GetInputFlag(struct ResearchCommon *common);

extern void *GFL_HEAP_Alloc(u32 heapId, u32 size, int clear, const char *site, u16 tag);

extern struct GfFont *GF_FONT_Create(int archiveId, int fileId, int format, int isFixedWidth, u32 heapId);

extern u32 GF_FONT_Delete(struct GfFont *font);

extern struct MsgBank *MSGDATA_CreateFromArchive(u32 resident, u32 arcId, u16 fileId, u32 heapId);

extern u32 MSGDATA_Delete(struct MsgBank *bank);

extern int RingQueue_Create(int capacity, int heapId);

extern void RingQueue_Destroy(struct RingQueue *queue);

extern void BMP_WIN_Init(u32);

extern void BMP_WIN_Exit(void);

extern void BG_SYS_Init(u32 layer, u32 value, u32 count, u32 index);

extern u32 BG_SYS_ClearSlot();

extern void BG_SYS_FreeTiles(u32, u32, u32);
struct BgTextLabelConfig;
struct BgTextLabel;

extern struct BgTextLabel *BgTextLabel_Create(struct BgTextLabelConfig *config, unsigned int font, unsigned int msgBank, unsigned int heapId);

u32 BgTextLabel_PrintMessage(struct BgTextLabel *label, unsigned int msgIndex);

extern void BgTextLabel_Destroy(struct BgTextLabel *label);

extern s32 CLACT_RegisterCharacter(void *a, u32 b, u32 c, u32 vram_mode, u16 flags);

extern s32 CLACT_RegisterPalette(void *a, u32 b, u32 c, u32 d, u16 g);

extern s32 CLACT_RegisterCellAnim(void *owner, u32 first, u32 second, u32 mode);

extern void CLACT_ReleaseCharacter(u32 i);

extern u32 CLACT_ReleaseCellAnim();

extern s32 CLACT_RegisterPaletteEx(void *a, u32 b, u32 c, u32 d, u16 e, u16 f, u16 g);

extern struct Unit *CLACT_CreateUnit(int count, u8 flag, u32 heapId);

extern u32 CLACT_DeleteUnit(struct Unit *bank);

extern void CLACT_DeleteActor(struct ClactActor *actor);

extern u32 PALETTE_ANIME_Create(u32 heapId);

extern u32 PALETTE_ANIME_Destroy(struct PaletteAnime *anime);

extern void PALETTE_ANIME_Bind(struct PaletteAnime *anime, unsigned short *palette, unsigned short *original, int colorCount);

extern int PALETTE_ANIME_Restore(struct PaletteAnime *anime);

extern void CLACT_VBlankSystem(void);

extern u32 KEY_GetCont(void);
struct GameData;
struct SaveControl;

extern struct SaveControl *GAME_DATA_GetSaveControl(struct GameData *gd);

extern void *SYMBOL_SAVE_GetBitBlock(void *saveData);

extern int MISC_SAVEDATA_GetStatusByte(int tally, int index);
struct BmpOam;

extern void BMP_OAM_SetPalette(struct BmpOam *bmpOam, unsigned int palette);

extern void CLACT_AddActorSurfacePos(struct ClactActor *p,const struct ClactVec2 *delta,u32 which);

extern void BgTextLabel_SetVisible(struct BgTextLabel *label, int visible);




extern u32 PALETTE_ANIME_IsRunning();


extern void BG_SYS_Update();

extern void BMP_OAM_SetEnabled(struct BmpOam *bmpOam, unsigned int enabled);
struct TcbList;

extern struct TcbList *GFL_USE_GetMainTaskList(void);

extern struct Bmp *BMP_Create(u32 width, u32 height, u32 depth, u16 heap);

extern struct Bmp *BMP_CreateFromArchive(u32,u32,u32,u32);

extern void BMP_Blit(struct Bmp *src, struct Bmp *dst, unsigned int srcX, unsigned int srcY, int dstX, int dstY, unsigned int w, unsigned int h, unsigned short colorKey);
struct Strbuf;

extern struct Strbuf *MSGDATA_AllocString(struct MsgBank *,u32);

extern void PRINTSYS_PrintColor(struct Bmp *bmp, short x, short y, struct Strbuf *str, struct GfFont *font, unsigned short color);
struct BmpOamSys;

extern void BMP_OAM_DeleteSys(struct BmpOamSys *sys);

extern void BMP_OAM_UploadChars(struct BmpOam *bmpOam);

extern void BMP_OAM_Delete(struct BmpOam *bmpOam);





struct TcbTask;

extern struct TcbTask *GFL_USE_AddMainTask(void (*)(void), void *work, unsigned int priority);
struct TcbTask;

extern void TCB_DeleteTask(struct TcbTask *task);
struct Arrow;

extern void ARROW_Update(struct Arrow *arrow);

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

void RESEARCH_GRAPH_RestartNetwork(u32 graph);

void RESEARCH_GRAPH_OpenComm(u8 *graph);

int RESEARCH_GRAPH_GetCommKindOrStart(u8 *graph);

extern int GFL_USE_IsAnySeBusy(void);
struct CircleGraph;

extern void CircleGraph_SetEnabled(struct CircleGraph *graph, unsigned int enabled);

extern void CircleGraph_QueueDrawSlow(struct CircleGraph *graph);

extern void CircleGraph_QueueDrawMedium(struct CircleGraph *graph);

u32 RESEARCH_GRAPH_ExitOverlayBackgrounds();

void RESEARCH_GRAPH_DummyBg7();

void RESEARCH_GRAPH_ShowBackground7();

void RESEARCH_GRAPH_DummyBg3();

void RESEARCH_GRAPH_ShowBackground3();

void RESEARCH_GRAPH_DestroyLabels(int *p);

u32 RESEARCH_GRAPH_ReleaseEntryResources(u32 graph);

u32 RESEARCH_GRAPH_ReleaseCursorResources(u32 graph);

void RESEARCH_GRAPH_DeleteUnits(int *p);

void RESEARCH_GRAPH_DeleteActors(int *p);

void RESEARCH_GRAPH_DeleteBmps(int *p);

void RESEARCH_GRAPH_DeleteOamSys(u8 *graph);

void RESEARCH_GRAPH_DeleteOamObjects(int *p);

u32 RESEARCH_GRAPH_DeletePalAnm(u32 graph);

void RESEARCH_GRAPH_DestroyPaletteAnime(int *p);

void RESEARCH_GRAPH_RestorePaletteAnime(int *p);

void RESEARCH_GRAPH_UnregisterVBlank(u8 *graph);

void RESEARCH_GRAPH_ClearNotifyFlag(unsigned char *graph);

extern void CircleGraph_QueueErase(struct CircleGraph *graph);

extern void CircleGraph_HoldUpdate(struct CircleGraph *graph, unsigned int frames);

extern void CircleGraph_QueueDrawFast(struct CircleGraph *graph);

extern u8 CircleGraph_GetSliceKey(struct CircleGraph *graph, unsigned char index);
struct GraphTable;

extern u32 GRAPHTABLE_FindEntry(struct GraphTable *table, unsigned char key, unsigned char entryId);

extern u8 CircleGraph_FindSliceIndex(struct CircleGraph *graph, unsigned char key);

extern void CircleGraph_SetCenterDepth(struct CircleGraph *graph, int z);
struct CircleGraphInput;

extern void CircleGraph_SetSlices(struct CircleGraph *graph, struct CircleGraphInput *inputs, int count);

extern void CircleGraph_Update(struct CircleGraph *graph);

extern void CircleGraph_Draw(struct CircleGraph *graph);

extern unsigned GRAPHTABLE_GetEntryRed(struct GraphTable *table, unsigned int group, unsigned int entry);

extern unsigned GRAPHTABLE_GetEntryGreen(struct GraphTable *table, unsigned int group, unsigned int entry);

extern unsigned GRAPHTABLE_GetEntryBlue(struct GraphTable *table, unsigned int group, unsigned int entry);

extern void ARROW_Reset(struct Arrow *arrow);

extern u8 CircleGraph_GetPercentByKey(struct CircleGraph *graph, unsigned char key);

extern void CircleGraph_GetLabelPositionByKey(struct CircleGraph *graph, unsigned char key, int *px, int *py);

extern void ARROW_Layout(struct Arrow *arrow, int tipX, int tipY, int cornerX, int endY);

extern void ARROW_Start(struct Arrow *arrow);

extern u8 CircleGraph_GetPercentByIndex(struct CircleGraph *graph, unsigned char index);

extern void CircleGraph_GetLabelPositionByIndex(struct CircleGraph *graph, unsigned char index, int *px, int *py);
struct Percentage;

extern void PERCENTAGE_SetValue(struct Percentage *pct, unsigned int value);

extern void PERCENTAGE_SetPosition(struct Percentage *pct, unsigned int x, unsigned int y);

extern void PERCENTAGE_SetVisible(struct Percentage *pct, unsigned int visible);

u32 RESEARCH_GRAPH_ClampByte(s32 v);

extern void BgTextLabel_PrintText(struct BgTextLabel *label, void *text);

extern struct Strbuf *STRBUF_Create(u32 capacity, u32 heapId);

extern void STRBUF_Delete(struct Strbuf *strbuf);

extern void WORDSET_SetSlotNumber(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);

extern void WORDSET_SetSlotTag(struct WordSet *words, unsigned int slot, struct Strbuf *src, unsigned int grammarCase, unsigned int isPlural, unsigned int gender);

extern void WORDSET_CopyTaggedText(struct WordSet *words, struct Strbuf *dst, struct Strbuf *src);

extern void CLACT_SetActorAnimLoopCount(struct ClactActor *,unsigned);

extern u32 RESEARCH_COMMON_GetContext(u32 *p);

extern int CircleGraph_IsAnimating(struct CircleGraph *graph);
struct SymbolBitSave;

extern unsigned char *SYMBOL_SAVE_GetQuestionnaireBits(struct SymbolBitSave *save);

extern u32 SYMBOL_SAVE_ReadBitField(const u8 *, int);

extern u32 GRAPHTABLE_GetEntryId(struct GraphTable *table, unsigned int group, unsigned char entry);

extern struct PlayTime *GAME_DATA_GetPlayTime(struct GameData *gd);

extern u16 PLAYTIME_GetHours(const struct PlayTime *p);

extern u16 MISC_SAVEDATA_GetHalfword(const u16 *, int);

void RESEARCH_GRAPH_ClearLabels(void *p);

void RESEARCH_GRAPH_ClearUnits(void *p);

void RESEARCH_GRAPH_ClearActors(void *p);

void RESEARCH_GRAPH_ClearBmps(void *p);

void RESEARCH_GRAPH_ClearPalAnm(void *p);

void RESEARCH_GRAPH_ClearPaletteAnime(void *p);

extern struct WordSet *WORDSET_CreateDefault(unsigned short heapId);

extern u32 WORDSET_Delete(struct WordSet *p);

extern struct CircleGraph *CircleGraph_Create(u32 heapId);

extern u32 CircleGraph_Destroy(struct CircleGraph *graph);

extern void MI_CpuFill8(u32, u32, u32);

extern u32 MISC_SAVEDATA_GetTallyWord(u8 *p, int i);

extern u32 MISC_SAVEDATA_GetTallyValue(u8 *tally, u32 fieldId, u32 index);

extern int MISC_SAVEDATA_GetScoreValue(int tally, int fieldId, int index);
struct ArrowResources;

extern struct Arrow *ARROW_Create(unsigned int heapId, struct ArrowResources *resources);

extern u32 ARROW_Destroy(struct Arrow *arrow);
struct ClactUnit;
struct PercentageTemplate;

extern u32 PERCENTAGE_Create(unsigned int heapId, struct PercentageTemplate *tmpl, struct ClactUnit *unit);

extern u32 PERCENTAGE_Destroy(struct Percentage *pct);

extern void G3X_Init(void);

extern void G3X_InitMtxStack(void);

extern void G3X_SetEdgeColorTable(const void *);

void *RESEARCH_GRAPH_Create(void *p);

u32 RESEARCH_GRAPH_Destroy(void *graph);

void RESEARCH_GRAPH_Update(unsigned char *p);

u32 RESEARCH_GRAPH_GetVisible(void *p);

u32 RESEARCH_GRAPH_GetActive(void *p);

void RESEARCH_GRAPH_Init(unsigned char *p);

void RESEARCH_GRAPH_UpdateIntro(u32 graph);

void RESEARCH_GRAPH_HandleInput(u8 *p);

void RESEARCH_GRAPH_HandleInputAlt(u8 *p);

void RESEARCH_GRAPH_EnterDrawSlow(u8 *p);

void RESEARCH_GRAPH_StepAnimation(u8 *p);

void RESEARCH_GRAPH_EnterFadeIn(u32 graph);

void RESEARCH_GRAPH_EnterFadeOut(u32 graph);

void RESEARCH_GRAPH_EnterDrawMedium(char *p);

void RESEARCH_GRAPH_EnterDrawMediumAlt(char *p);

void RESEARCH_GRAPH_ExitFade(u32 graph);

void RESEARCH_GRAPH_AdvanceWhileActive(u32 graph);

void RESEARCH_GRAPH_Cleanup(u8 *graph);

void RESEARCH_GRAPH_SetStateChanged(void *p);

void RESEARCH_GRAPH_SetEntryHandled(u8 *graph, u32 handled);

void RESEARCH_GRAPH_SetActive(void *p, u32 v);

u32 RESEARCH_GRAPH_GetCount(void *p);

u32 RESEARCH_GRAPH_GetTransitionKind(u8 *graph);

void RESEARCH_GRAPH_IncTimer(void *p);

void RESEARCH_GRAPH_PushCommand(u8 *graph, u32 command);

void RESEARCH_GRAPH_ProcessCommand(u32 graph);

void RESEARCH_GRAPH_StartSubState(void *p, u32 v);

u32 RESEARCH_GRAPH_GetSubState(void *p);

void RESEARCH_GRAPH_IncSubState(void *p);

void RESEARCH_GRAPH_SelectPrev(u8 *p);

void RESEARCH_GRAPH_SelectNext(u8 *p);

u32 RESEARCH_GRAPH_SelectDirect(u32 graph, u32 index);

void RESEARCH_GRAPH_ApplySelection(u8 *graph, u32 index);

void RESEARCH_GRAPH_MoveGroupBackward(char *p);

void RESEARCH_GRAPH_MoveGroupForward(char *p);

u32 RESEARCH_GRAPH_MoveEntryForward(u32 graph);

u32 RESEARCH_GRAPH_MoveEntryBackward(u32 graph);

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

void RESEARCH_GRAPH_ClearEntryIndex(u8 *graph);

void RESEARCH_GRAPH_SyncArrow(u8 *p);

void RESEARCH_GRAPH_SetHighlightSelected(u32 graph);

void RESEARCH_GRAPH_SetHighlightA(u32 graph);

void RESEARCH_GRAPH_SetHighlightB(u32 graph);

void RESEARCH_GRAPH_SetHighlightC(u32 graph);

void RESEARCH_GRAPH_SetNormalA(u32 graph);

void RESEARCH_GRAPH_SetNormalB(u32 graph);

void RESEARCH_GRAPH_StartPaletteAnime(u32 *p);

void RESEARCH_GRAPH_SwapCenterPairs(void *p);

void RESEARCH_GRAPH_QuantizePosition(u32 input);

void RESEARCH_GRAPH_SetCenterDepth(void *p);

void RESEARCH_GRAPH_SetSlicesFromGraphA(u8 *p,int mode);

void RESEARCH_GRAPH_SetSlicesFromGraphB(u8 *p, u32 mode);

void RESEARCH_GRAPH_UpdateCircles(char *p);

void RESEARCH_GRAPH_DrawCircles(char *p);

void RESEARCH_GRAPH_DrawSliceColor(char *p);

void RESEARCH_GRAPH_LayoutArrow(char *p);

void RESEARCH_GRAPH_UpdatePercentages(char *p);

void RESEARCH_GRAPH_HideAllPercentages(char *p);

void RESEARCH_GRAPH_ShowPercent(u8 *graph, u32 index);

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

void RESEARCH_GRAPH_EnableOams(void *graph);

void RESEARCH_GRAPH_EnableOamsA(void *graph);

void RESEARCH_GRAPH_DisableOams(void *graph);

void RESEARCH_GRAPH_SetOamEnabled(u8 *p, u32 i, u32 j);

void RESEARCH_GRAPH_StartSlotPaletteAnime(char *p, int i);

void RESEARCH_GRAPH_StopSlotPaletteAnime(u8 *graph, u32 slot);

u32 RESEARCH_GRAPH_IsSlotPaletteAnimeRunning(u8 *graph, u32 slot);

void RESEARCH_GRAPH_UpdateSlotPalettes(int *p);

void RESEARCH_GRAPH_UpdatePaletteAnime(u8 *graph);

void RESEARCH_GRAPH_RequestFadeIn(char *p);

void RESEARCH_GRAPH_RequestFadeOut(char *p);

u32 RESEARCH_GRAPH_IsFadeDone(u8 *graph);

u32 RESEARCH_GRAPH_TransferPalettes(u32 unusedArg, u32 graph);

void RESEARCH_GRAPH_CheckQuestionnaireUpdated(char *p);

void RESEARCH_GRAPH_ClearUpdatedFlag(void *p);

void RESEARCH_GRAPH_TickTimer(void *p);

void RESEARCH_GRAPH_ResetTimer(void *p);

u32 RESEARCH_GRAPH_GetContext(u8 *graph);

u32 RESEARCH_GRAPH_GetAppResource(u8 *graph);

void RESEARCH_GRAPH_SetHeapId(void *p, u32 v);

u32 RESEARCH_GRAPH_GetOwner(void *p);

void RESEARCH_GRAPH_SetOwner(void *p, u32 v);

u32 RESEARCH_GRAPH_GetInputFlag(void *p);

void RESEARCH_GRAPH_SetGraphKind(void *p, u32 v);

u8 *RESEARCH_GRAPH_GetLeftCircle(void *p);

u8 *RESEARCH_GRAPH_GetRightCircle(void *p);

u32 RESEARCH_GRAPH_AreCirclesIdle(u32 graph);

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

u16 RESEARCH_GRAPH_GetSaveBits(u32 graph);

u32 RESEARCH_GRAPH_GetClactUnit(void *p, u32 i);

u32 RESEARCH_GRAPH_GetSharedHandle(void *p, u32 i);

u32 RESEARCH_GRAPH_GetMarkerActor(void *p, u32 i);

u32 RESEARCH_GRAPH_Alloc(u32 heapId);

void RESEARCH_GRAPH_InitFields(char *p);

u32 RESEARCH_GRAPH_Free(void *graph);

void RESEARCH_GRAPH_ClearCommandQueue(void *p);

void RESEARCH_GRAPH_CreateCommandQueue(u32 graph);

void RESEARCH_GRAPH_DestroyCommandQueue(u8 *graph);

void RESEARCH_GRAPH_ClearFont(void *p);

void RESEARCH_GRAPH_CreateFont(u32 graph);

void RESEARCH_GRAPH_DeleteFont(u8 *graph);

void RESEARCH_GRAPH_ClearMessages(void *p);

void RESEARCH_GRAPH_CreateMessages(MessageView *p);

void RESEARCH_GRAPH_DeleteMessages(int *p);

void RESEARCH_GRAPH_ClearWordSet(void *p);

void RESEARCH_GRAPH_CreateWordSet(u32 graph);

void RESEARCH_GRAPH_DeleteWordSet(u8 *graph);

void RESEARCH_GRAPH_ClearCircles(void *p);

void RESEARCH_GRAPH_CreateCircles(char *p);

void RESEARCH_GRAPH_DestroyCircles(char *p);

void RESEARCH_GRAPH_ClearGraphTable(u8 *graph);

void RESEARCH_GRAPH_BuildGraphTable(char *p);

void RESEARCH_GRAPH_InitTouchRects(u8 *p);

void RESEARCH_GRAPH_ClearArrow(void *p);

void RESEARCH_GRAPH_CreateArrow(char *p);

void RESEARCH_GRAPH_DestroyArrow(u8 *graph);

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

void *RESEARCH_GRAPH_Create(void *owner)
{
    void *graph;
    void *heapId;
    heapId = (void *)RESEARCH_COMMON_GetHeapId(owner);
    graph = (void *)RESEARCH_GRAPH_Alloc((uptr)heapId);
    RESEARCH_GRAPH_InitFields(graph);
    RESEARCH_GRAPH_SetHeapId(graph, (uptr)heapId);
    RESEARCH_GRAPH_SetOwner(graph, (uptr)owner);
    return graph;
}

u32 RESEARCH_GRAPH_Destroy(void *graph)
{
    RESEARCH_GRAPH_DestroyCommandQueue((u8 *)graph);
    return RESEARCH_GRAPH_Free(graph);
}

void RESEARCH_GRAPH_Update(unsigned char *graph)
{
    switch (((struct ResearchObjB *)graph)->state) {
    case 0: RESEARCH_GRAPH_Init(graph); break;
    case 1: RESEARCH_GRAPH_UpdateIntro((uptr)graph); break;
    case 2: RESEARCH_GRAPH_HandleInput(graph); break;
    case 3: RESEARCH_GRAPH_HandleInputAlt(graph); break;
    case 4: RESEARCH_GRAPH_EnterDrawSlow(graph); break;
    case 5: RESEARCH_GRAPH_StepAnimation(graph); break;
    case 6: RESEARCH_GRAPH_EnterFadeIn((uptr)graph); break;
    case 7: RESEARCH_GRAPH_EnterFadeOut((uptr)graph); break;
    case 8: RESEARCH_GRAPH_EnterDrawMedium((char *)graph); break;
    case 9: RESEARCH_GRAPH_EnterDrawMediumAlt((char *)graph); break;
    case 10: RESEARCH_GRAPH_ExitFade((uptr)graph); break;
    case 11: RESEARCH_GRAPH_AdvanceWhileActive((uptr)graph); break;
    case 12: RESEARCH_GRAPH_Cleanup((u8 *)graph); break;
    case 13: return;
    }
    RESEARCH_GRAPH_CheckQuestionnaireUpdated((char *)graph);
    RESEARCH_GRAPH_TickTimer(graph);
    if (((struct ResearchObjB *)graph)->drawSystem != 0) {
        CLACT_DrawSystem(((struct ResearchObjB *)graph)->drawSystem);
        RESEARCH_GRAPH_UpdateCircles((char *)graph);
        ARROW_Update(((struct ResearchObjB *)graph)->arrow);
        RESEARCH_GRAPH_UpdatePaletteAnime(graph);
        RESEARCH_GRAPH_UpdateSlotPalettes((int *)graph);
        RESEARCH_GRAPH_DrawCircles((char *)graph);
        RESEARCH_GRAPH_DrawSliceColor((char *)graph);
        *(volatile unsigned int *)0x04000540 = 0;
    }
    RESEARCH_GRAPH_IncTimer(graph);
    RESEARCH_GRAPH_ProcessCommand((uptr)graph);
}

u32 RESEARCH_GRAPH_GetVisible(void *graph)
{
    return ((struct ResearchObjB *)graph)->visible;
}

/*
 * Field getter, u32 at +0x3e4.
 *
 * Addresses are Black-image addresses.
 */
u32 RESEARCH_GRAPH_GetActive(void *graph)
{
    return ((struct ResearchObjB *)graph)->active;
}

void RESEARCH_GRAPH_Init(unsigned char *graph)
{
    int r;
    RESEARCH_GRAPH_CreateCommandQueue((uptr)graph);
    RESEARCH_GRAPH_CreateFont((uptr)graph);
    RESEARCH_GRAPH_CreateMessages((struct MessageView *)graph);
    RESEARCH_GRAPH_CreateWordSet((uptr)graph);
    RESEARCH_GRAPH_InitTouchRects(graph);
    RESEARCH_GRAPH_LayoutTouchRects(graph);
    RESEARCH_GRAPH_InitScreen();
    RESEARCH_GRAPH_InitOverlayBackgrounds((char *)graph);
    RESEARCH_GRAPH_LoadBackground6((char *)graph);
    RESEARCH_GRAPH_UpdateBackground7(graph);
    RESEARCH_GRAPH_LoadBackground2((char *)graph);
    RESEARCH_GRAPH_UpdateBackground3(graph);
    RESEARCH_GRAPH_CreateLabels((char *)graph);
    RESEARCH_GRAPH_RegisterEntryResources((char *)graph);
    RESEARCH_GRAPH_RegisterCursorResources((char *)graph);
    RESEARCH_GRAPH_CreateUnits(graph);
    RESEARCH_GRAPH_CreateActors(graph);
    RESEARCH_GRAPH_CreateBmps(graph);
    RESEARCH_GRAPH_DrawBmps(graph);
    RESEARCH_GRAPH_DrawBadge(graph);
    RESEARCH_GRAPH_CreateOamSys(graph);
    RESEARCH_GRAPH_CreateOamObjects(graph);
    RESEARCH_GRAPH_BuildGraphTable((char *)graph);
    RESEARCH_GRAPH_CreateCircles((char *)graph);
    RESEARCH_GRAPH_CreateArrow((char *)graph);
    RESEARCH_GRAPH_CreatePercentages((char *)graph);
    RESEARCH_GRAPH_CreatePalAnm(graph);
    RESEARCH_GRAPH_CreatePaletteAnime(graph);
    RESEARCH_GRAPH_BindPaletteAnime(graph);
    RESEARCH_GRAPH_RegisterVBlank((char *)graph);
    RESEARCH_GRAPH_RestartNetwork((uptr)graph);
    RESEARCH_GRAPH_PrintTitle((char *)graph);
    RESEARCH_GRAPH_PrintGroupLabel((char *)graph);
    RESEARCH_GRAPH_PrintKindLabel((char *)graph);
    RESEARCH_GRAPH_PrintSliceLabel((char *)graph);
    RESEARCH_GRAPH_PrintTimeLabel((char *)graph);
    RESEARCH_GRAPH_PrintTeamLabel((char *)graph);
    RESEARCH_GRAPH_SetTeamLabelVisible((char *)graph);
    RESEARCH_GRAPH_SetDetailLabelVisible((char *)graph);
    RESEARCH_GRAPH_LayoutActors((char *)graph);
    RESEARCH_GRAPH_LoadBackground((char *)graph);
    RESEARCH_GRAPH_SetTriangleActorVisible((char *)graph);
    RESEARCH_GRAPH_EnableOams(graph);
    RESEARCH_GRAPH_StartSlotPaletteAnime((char *)graph, 0);
    RESEARCH_GRAPH_StartSlotPaletteAnime((char *)graph, 7);
    RESEARCH_GRAPH_SyncArrow(graph);
    *(int *)&((struct ResearchObjB *)graph)->drawSystem = 1;
    RESEARCH_GRAPH_FadeIn();
    r = RESEARCH_GRAPH_GetTransitionKind(graph);
    RESEARCH_GRAPH_PushCommand(graph, 1);
    RESEARCH_GRAPH_PushCommand(graph, r);
    if (r == 3)
        RESEARCH_GRAPH_DrawIndexCursor((char *)graph);
    RESEARCH_GRAPH_SetStateChanged(graph);
}

#pragma thumb on

void RESEARCH_GRAPH_UpdateIntro(u32 graph)
{
    switch (RESEARCH_GRAPH_GetSubState((void *)graph)) {
    case 0:
        RESEARCH_GRAPH_OpenComm((u8 *)graph);
        RESEARCH_GRAPH_IncSubState((void *)graph);
        break;
    case 1:
        if (RESEARCH_GRAPH_GetCommKindOrStart((u8 *)graph) != 0) {
            RESEARCH_GRAPH_SetStateChanged((void *)graph);
        }
        break;
    }
}

void RESEARCH_GRAPH_HandleInput(u8 *graph)
{
    u32 keys;
    int hit;
    int sub;

    KEY_GetCont();
    keys = KEY_GetTrg();
    hit = TOUCHPANEL_HitTrg((TouchHitTable *)(graph + 0x2FE));
    sub = TOUCHPANEL_HitTrg(RESEARCH_COMMON_GetTouchRects(((struct ResearchObjB *)graph)->owner));
    if (*(int *)&((struct ResearchObjB *)graph)->entryShown != 0 && ((struct ResearchObjB *)graph)->updatedFlag != 0 && *(int *)&((struct ResearchObjB *)graph)->timerExpired != 0) {
        RESEARCH_GRAPH_SetStateChanged(graph);
        RESEARCH_GRAPH_PushCommand(graph, 8);
        RESEARCH_GRAPH_PushCommand(graph, 6);
        RESEARCH_GRAPH_PushCommand(graph, 7);
        RESEARCH_GRAPH_PushCommand(graph, 5);
        RESEARCH_GRAPH_PushCommand(graph, 2);
        return;
    }
    if (RESEARCH_GRAPH_GetInputFlag(graph) != 0 || sub == 0) {
        RESEARCH_GRAPH_SetEntryHandled(graph, 1);
        RESEARCH_GRAPH_StartPaletteAnime((u32 *)graph);
        GFL_USE_PlaySeDefaultVolume(0x551);
        RESEARCH_GRAPH_SetStateChanged(graph);
        RESEARCH_GRAPH_PushCommand(graph, 11);
        RESEARCH_GRAPH_PushCommand(graph, 10);
        RESEARCH_GRAPH_PushCommand(graph, 12);
        return;
    }
    if ((keys & 0x40) || (keys & 0x80) || (keys & 0x20) || (keys & 0x10) || (keys & 1)) {
        RESEARCH_GRAPH_DrawIndexCursor((char *)graph);
        RESEARCH_GRAPH_SyncArrow(graph);
        RESEARCH_GRAPH_SetStateChanged(graph);
        RESEARCH_GRAPH_PushCommand(graph, 3);
        return;
    }
    if (hit == 6 && *(int *)&((struct ResearchObjB *)graph)->entryShown == 0 && RESEARCH_GRAPH_GetGroupValue(graph) != 0) {
        ((struct ResearchObjB *)graph)->touchSelected = 1;
        RESEARCH_GRAPH_SetHighlightSelected((uptr)graph);
        RESEARCH_GRAPH_SetStateChanged(graph);
        RESEARCH_GRAPH_PushCommand(graph, 4);
        RESEARCH_GRAPH_PushCommand(graph, 6);
        RESEARCH_GRAPH_PushCommand(graph, 7);
        RESEARCH_GRAPH_PushCommand(graph, 5);
        RESEARCH_GRAPH_PushCommand(graph, 2);
    } else if (hit == 7) {
        if (*(int *)&((struct ResearchObjB *)graph)->entryShown == 0 && RESEARCH_GRAPH_GetGroupValue(graph) != 0) {
            ((struct ResearchObjB *)graph)->touchSelected = 1;
            RESEARCH_GRAPH_SetHighlightSelected((uptr)graph);
            RESEARCH_GRAPH_SetStateChanged(graph);
            RESEARCH_GRAPH_PushCommand(graph, 4);
            RESEARCH_GRAPH_PushCommand(graph, 6);
            RESEARCH_GRAPH_PushCommand(graph, 7);
            RESEARCH_GRAPH_PushCommand(graph, 5);
            RESEARCH_GRAPH_PushCommand(graph, 2);
        } else {
            GFL_USE_PlaySeDefaultVolume(0x557);
        }
    } else if (hit == 2) {
        if (*(int *)&((struct ResearchObjB *)graph)->entryShown == 0 && RESEARCH_GRAPH_GetGroupValue(graph) != 0) {
            ((struct ResearchObjB *)graph)->touchSelected = 1;
            RESEARCH_GRAPH_SetHighlightSelected((uptr)graph);
            RESEARCH_GRAPH_SetStateChanged(graph);
            RESEARCH_GRAPH_PushCommand(graph, 4);
            RESEARCH_GRAPH_PushCommand(graph, 6);
            RESEARCH_GRAPH_PushCommand(graph, 7);
            RESEARCH_GRAPH_PushCommand(graph, 5);
            RESEARCH_GRAPH_PushCommand(graph, 2);
        } else {
            RESEARCH_GRAPH_SelectDirect((uptr)graph, 0);
        }
    } else if (*(int *)&((struct ResearchObjB *)graph)->entryShown != 0 && RESEARCH_GRAPH_GetGroupValue(graph) != 0 && hit == 3) {
        RESEARCH_GRAPH_SelectDirect((uptr)graph, 1);
        RESEARCH_GRAPH_DrawIndexCursor((char *)graph);
        RESEARCH_GRAPH_SyncArrow(graph);
        RESEARCH_GRAPH_SetStateChanged(graph);
        RESEARCH_GRAPH_PushCommand(graph, 3);
    } else if (*(int *)&((struct ResearchObjB *)graph)->entryShown != 0 && RESEARCH_GRAPH_GetGroupValue(graph) != 0 && hit == 4) {
        RESEARCH_GRAPH_SelectDirect((uptr)graph, 2);
        RESEARCH_GRAPH_DrawIndexCursor((char *)graph);
        RESEARCH_GRAPH_SyncArrow(graph);
        RESEARCH_GRAPH_SetStateChanged(graph);
        RESEARCH_GRAPH_PushCommand(graph, 3);
    } else if (hit == 5) {
        RESEARCH_GRAPH_SelectDirect((uptr)graph, 3);
        RESEARCH_GRAPH_DrawIndexCursor((char *)graph);
        RESEARCH_GRAPH_SyncArrow(graph);
        RESEARCH_GRAPH_SetStateChanged(graph);
        RESEARCH_GRAPH_PushCommand(graph, 3);
    } else if (hit == 0) {
        RESEARCH_GRAPH_DrawIndexCursor((char *)graph);
        RESEARCH_GRAPH_SyncArrow(graph);
        RESEARCH_GRAPH_SetStateChanged(graph);
        RESEARCH_GRAPH_PushCommand(graph, 3);
        switch (*(int *)&((struct ResearchObjB *)graph)->cursorIndex) {
        case 0: RESEARCH_GRAPH_MoveGroupForward((char *)graph); break;
        case 1: RESEARCH_GRAPH_MoveEntryBackward((uptr)graph); break;
        case 3: RESEARCH_GRAPH_ToggleEntry((char *)graph); break;
        }
    } else if (hit == 1) {
        RESEARCH_GRAPH_DrawIndexCursor((char *)graph);
        RESEARCH_GRAPH_SyncArrow(graph);
        RESEARCH_GRAPH_SetStateChanged(graph);
        RESEARCH_GRAPH_PushCommand(graph, 3);
        switch (*(int *)&((struct ResearchObjB *)graph)->cursorIndex) {
        case 0: RESEARCH_GRAPH_MoveGroupBackward((char *)graph); break;
        case 1: RESEARCH_GRAPH_MoveEntryForward((uptr)graph); break;
        case 3: RESEARCH_GRAPH_ToggleEntry((char *)graph); break;
        }
    } else if (keys & 2) {
        RESEARCH_GRAPH_SetEntryHandled(graph, 0);
        RESEARCH_GRAPH_StartPaletteAnime((u32 *)graph);
        GFL_USE_PlaySeDefaultVolume(0x551);
        RESEARCH_GRAPH_SetStateChanged(graph);
        RESEARCH_GRAPH_PushCommand(graph, 11);
        RESEARCH_GRAPH_PushCommand(graph, 10);
        RESEARCH_GRAPH_PushCommand(graph, 12);
    }
}

void RESEARCH_GRAPH_HandleInputAlt(u8 *graph)
{
    u32 keys;
    int hit;
    int sub;

    KEY_GetCont();
    keys = KEY_GetTrg();
    hit = TOUCHPANEL_HitTrg((TouchHitTable *)(graph + 0x2FE));
    sub = TOUCHPANEL_HitTrg(RESEARCH_COMMON_GetTouchRects(((struct ResearchObjB *)graph)->owner));
    if (*(int *)&((struct ResearchObjB *)graph)->entryShown != 0 && ((struct ResearchObjB *)graph)->updatedFlag != 0 && *(int *)&((struct ResearchObjB *)graph)->timerExpired != 0) {
        RESEARCH_GRAPH_SetStateChanged(graph);
        RESEARCH_GRAPH_PushCommand(graph, 9);
        RESEARCH_GRAPH_PushCommand(graph, 6);
        RESEARCH_GRAPH_PushCommand(graph, 7);
        RESEARCH_GRAPH_PushCommand(graph, 5);
        RESEARCH_GRAPH_PushCommand(graph, 3);
        return;
    }
    if (RESEARCH_GRAPH_GetInputFlag(graph) != 0 || sub == 0) {
        RESEARCH_GRAPH_SetEntryHandled(graph, 1);
        RESEARCH_GRAPH_StartPaletteAnime((u32 *)graph);
        GFL_USE_PlaySeDefaultVolume(0x551);
        RESEARCH_GRAPH_SetStateChanged(graph);
        RESEARCH_GRAPH_PushCommand(graph, 11);
        RESEARCH_GRAPH_PushCommand(graph, 10);
        RESEARCH_GRAPH_PushCommand(graph, 12);
        return;
    }
    if (keys & 0x40) {
        RESEARCH_GRAPH_SelectPrev(graph);
    } else if (keys & 0x80) {
        RESEARCH_GRAPH_SelectNext(graph);
    } else if (hit == 6 && *(int *)&((struct ResearchObjB *)graph)->entryShown == 0 && RESEARCH_GRAPH_GetGroupValue(graph) != 0) {
        ((struct ResearchObjB *)graph)->touchSelected = 1;
        RESEARCH_GRAPH_SetHighlightSelected((uptr)graph);
        RESEARCH_GRAPH_SetStateChanged(graph);
        RESEARCH_GRAPH_PushCommand(graph, 4);
        RESEARCH_GRAPH_PushCommand(graph, 6);
        RESEARCH_GRAPH_PushCommand(graph, 7);
        RESEARCH_GRAPH_PushCommand(graph, 5);
        RESEARCH_GRAPH_PushCommand(graph, 2);
    } else if (hit == 7) {
        if (*(int *)&((struct ResearchObjB *)graph)->entryShown == 0 && RESEARCH_GRAPH_GetGroupValue(graph) != 0) {
            ((struct ResearchObjB *)graph)->touchSelected = 1;
            RESEARCH_GRAPH_SetHighlightSelected((uptr)graph);
            RESEARCH_GRAPH_SetStateChanged(graph);
            RESEARCH_GRAPH_PushCommand(graph, 4);
            RESEARCH_GRAPH_PushCommand(graph, 6);
            RESEARCH_GRAPH_PushCommand(graph, 7);
            RESEARCH_GRAPH_PushCommand(graph, 5);
            RESEARCH_GRAPH_PushCommand(graph, 2);
        } else {
            GFL_USE_PlaySeDefaultVolume(0x557);
        }
    } else if (hit == 2) {
        if (*(int *)&((struct ResearchObjB *)graph)->entryShown == 0 && RESEARCH_GRAPH_GetGroupValue(graph) != 0) {
            ((struct ResearchObjB *)graph)->touchSelected = 1;
            RESEARCH_GRAPH_SetHighlightSelected((uptr)graph);
            RESEARCH_GRAPH_SetStateChanged(graph);
            RESEARCH_GRAPH_PushCommand(graph, 4);
            RESEARCH_GRAPH_PushCommand(graph, 6);
            RESEARCH_GRAPH_PushCommand(graph, 7);
            RESEARCH_GRAPH_PushCommand(graph, 5);
            RESEARCH_GRAPH_PushCommand(graph, 2);
        } else {
            RESEARCH_GRAPH_SelectDirect((uptr)graph, 0);
        }
    } else if (*(int *)&((struct ResearchObjB *)graph)->entryShown != 0 && RESEARCH_GRAPH_GetGroupValue(graph) != 0 && hit == 3) {
        RESEARCH_GRAPH_SelectDirect((uptr)graph, 1);
    } else if (*(int *)&((struct ResearchObjB *)graph)->entryShown != 0 && RESEARCH_GRAPH_GetGroupValue(graph) != 0 && hit == 4) {
        RESEARCH_GRAPH_SelectDirect((uptr)graph, 2);
    } else if (hit == 5) {
        RESEARCH_GRAPH_SelectDirect((uptr)graph, 3);
    } else if ((keys & 0x20) || hit == 0) {
        switch (*(int *)&((struct ResearchObjB *)graph)->cursorIndex) {
        case 0: RESEARCH_GRAPH_MoveGroupForward((char *)graph); break;
        case 1: RESEARCH_GRAPH_MoveEntryBackward((uptr)graph); break;
        case 3: RESEARCH_GRAPH_ToggleEntry((char *)graph); break;
        }
    } else if ((keys & 0x10) || hit == 1) {
        switch (*(int *)&((struct ResearchObjB *)graph)->cursorIndex) {
        case 0: RESEARCH_GRAPH_MoveGroupBackward((char *)graph); break;
        case 1: RESEARCH_GRAPH_MoveEntryForward((uptr)graph); break;
        case 3: RESEARCH_GRAPH_ToggleEntry((char *)graph); break;
        }
    } else if ((keys & 1) && *(int *)&((struct ResearchObjB *)graph)->entryShown == 0 && RESEARCH_GRAPH_GetGroupValue(graph) != 0
               && (*(int *)&((struct ResearchObjB *)graph)->cursorIndex == 0 || *(int *)&((struct ResearchObjB *)graph)->cursorIndex == 4)) {
        ((struct ResearchObjB *)graph)->touchSelected = 0;
        RESEARCH_GRAPH_SetHighlightSelected((uptr)graph);
        RESEARCH_GRAPH_SetStateChanged(graph);
        RESEARCH_GRAPH_PushCommand(graph, 4);
        RESEARCH_GRAPH_PushCommand(graph, 6);
        RESEARCH_GRAPH_PushCommand(graph, 7);
        RESEARCH_GRAPH_PushCommand(graph, 5);
        RESEARCH_GRAPH_PushCommand(graph, 3);
    } else if (keys & 2) {
        RESEARCH_GRAPH_SetEntryHandled(graph, 0);
        RESEARCH_GRAPH_StartPaletteAnime((u32 *)graph);
        GFL_USE_PlaySeDefaultVolume(0x551);
        RESEARCH_GRAPH_SetStateChanged(graph);
        RESEARCH_GRAPH_PushCommand(graph, 11);
        RESEARCH_GRAPH_PushCommand(graph, 10);
        RESEARCH_GRAPH_PushCommand(graph, 12);
    }
}

void RESEARCH_GRAPH_EnterDrawSlow(u8 *graph)
{
    switch (RESEARCH_GRAPH_GetSubState(graph)) {
    case 0:
        RESEARCH_GRAPH_BuildGraphTable((char *)graph);
        RESEARCH_GRAPH_ClearUpdatedFlag(graph);
        RESEARCH_GRAPH_EnableOamsA(graph);
        RESEARCH_GRAPH_SetSlicesFromGraphA(graph, 0);
        RESEARCH_GRAPH_SetSlicesFromGraphA(graph, 1);
        CircleGraph_SetEnabled((struct CircleGraph *)(RESEARCH_GRAPH_GetLeftCircle(graph)), 1);
        CircleGraph_QueueDrawSlow((struct CircleGraph *)(RESEARCH_GRAPH_GetLeftCircle(graph)));
        RESEARCH_GRAPH_IncSubState(graph);
        break;
    case 1:
        if (GFL_USE_IsAnySeBusy() == 0) {
            if (((struct ResearchObjB *)graph)->stateTimer >= 0x78)
                RESEARCH_GRAPH_IncSubState(graph);
            else
                GFL_USE_PlaySeDefaultVolume(0x76B);
        }
        break;
    case 2:
        *(int *)&((struct ResearchObjB *)graph)->entryShown = 1;
        RESEARCH_GRAPH_SetIndex(graph, 1);
        RESEARCH_GRAPH_LayoutActors((char *)graph);
        RESEARCH_GRAPH_LayoutTouchRects(graph);
        RESEARCH_GRAPH_MoveToSelectedEntry((char *)graph);
        RESEARCH_GRAPH_DisableOams(graph);
        RESEARCH_GRAPH_LoadBackground((char *)graph);
        RESEARCH_GRAPH_PrintSliceLabel((char *)graph);
        RESEARCH_GRAPH_PrintTimeLabel((char *)graph);
        RESEARCH_GRAPH_SetDetailLabelVisible((char *)graph);
        RESEARCH_GRAPH_PrintTeamLabel((char *)graph);
        RESEARCH_GRAPH_LayoutArrow((char *)graph);
        RESEARCH_GRAPH_SetTriangleActorVisible((char *)graph);
        if (((struct ResearchObjB *)graph)->touchSelected == 0)
            RESEARCH_GRAPH_DrawIndexCursor((char *)graph);
        GFL_USE_PlaySeDefaultVolume(0x76C);
        RESEARCH_GRAPH_SetStateChanged(graph);
        break;
    }
}

void RESEARCH_GRAPH_StepAnimation(u8 *graph)
{
    switch (RESEARCH_GRAPH_GetSubState(graph)) {
    case 0:
        RESEARCH_GRAPH_UpdatePercentages((char *)graph);
        RESEARCH_GRAPH_IncSubState(graph);
        break;
    case 1:
        if (((struct ResearchObjB *)graph)->stateTimer % 10u == 0) {
            u8 index = graph[765];
            graph[765] = index + 1;
            RESEARCH_GRAPH_ShowPercent(graph, index);
        }
        if (graph[764] <= graph[765]) RESEARCH_GRAPH_SetStateChanged(graph);
        break;
    }
}

/*
 * Same two-case entry as RESEARCH_GRAPH_EnterFadeOut; mode 0 arms the +5 handle and
 * RESEARCH_GRAPH_RequestFadeIn().
 *
 * Addresses are Black-image addresses.
 */
void RESEARCH_GRAPH_EnterFadeIn(u32 graph)
{
    switch (RESEARCH_GRAPH_GetSubState((void *)graph)) {
    case 0:
    RESEARCH_GRAPH_StopSlotPaletteAnime((u8 *)graph, 5);
    RESEARCH_GRAPH_RequestFadeIn((char *)graph);
    RESEARCH_GRAPH_IncSubState((void *)graph);
    break;
    case 1:
    if (RESEARCH_GRAPH_IsFadeDone((u8 *)graph) != 0) {
    RESEARCH_GRAPH_SetStateChanged((void *)graph);
    }
    break;
    }
}

void RESEARCH_GRAPH_EnterFadeOut(u32 graph)
{
    switch (RESEARCH_GRAPH_GetSubState((void *)graph)) {
    case 0:
    RESEARCH_GRAPH_RequestFadeOut((char *)graph);
    RESEARCH_GRAPH_IncSubState((void *)graph);
    break;
    case 1:
    if (RESEARCH_GRAPH_IsFadeDone((u8 *)graph) != 0) {
    RESEARCH_GRAPH_SyncArrow((u8 *)graph);
    RESEARCH_GRAPH_SetStateChanged((void *)graph);
    }
    break;
    }
}

void RESEARCH_GRAPH_EnterDrawMedium(char *graph)
{
    switch (RESEARCH_GRAPH_GetSubState(graph)) {
    case 0:
        ((struct ResearchObjB *)graph)->detailMode = 1;
        RESEARCH_GRAPH_ClearUpdatedFlag(graph);
        RESEARCH_GRAPH_ResetTimer(graph);
        RESEARCH_GRAPH_BuildGraphTable(graph);
        RESEARCH_GRAPH_LoadBackground(graph);
        RESEARCH_GRAPH_PrintSliceLabel(graph);
        RESEARCH_GRAPH_SetDetailLabelVisible(graph);
        RESEARCH_GRAPH_SetTeamLabelVisible(graph);
        RESEARCH_GRAPH_LayoutArrow(graph);
        RESEARCH_GRAPH_LayoutActors(graph);
        RESEARCH_GRAPH_HideAllPercentages(graph);
        RESEARCH_GRAPH_SetSlicesFromGraphB((u8 *)graph, 0);
        RESEARCH_GRAPH_SetSlicesFromGraphB((u8 *)graph, 1);
        RESEARCH_GRAPH_SetCenterDepth(graph);
        CircleGraph_SetEnabled((struct CircleGraph *)(RESEARCH_GRAPH_GetRightCircle(graph)), 1);
        CircleGraph_QueueDrawMedium((struct CircleGraph *)(RESEARCH_GRAPH_GetRightCircle(graph)));
        RESEARCH_GRAPH_IncSubState(graph);
        break;
    case 1:
        if (GFL_USE_IsAnySeBusy() == 0) {
            if (((struct ResearchObjB *)graph)->stateTimer >= 0x3c) {
                RESEARCH_GRAPH_IncSubState(graph);
                return;
            }
            GFL_USE_PlaySeDefaultVolume(0x76b);
        }
        break;
    case 2:
        ((struct ResearchObjB *)graph)->detailMode = 0;
        RESEARCH_GRAPH_SwapCenterPairs(graph);
        CircleGraph_SetEnabled((struct CircleGraph *)(RESEARCH_GRAPH_GetRightCircle(graph)), 0);
        RESEARCH_GRAPH_LoadBackground(graph);
        RESEARCH_GRAPH_SetDetailLabelVisible(graph);
        RESEARCH_GRAPH_PrintSliceLabel(graph);
        RESEARCH_GRAPH_PrintTimeLabel(graph);
        RESEARCH_GRAPH_PrintTeamLabel(graph);
        RESEARCH_GRAPH_LayoutArrow(graph);
        RESEARCH_GRAPH_LayoutActors(graph);
        RESEARCH_GRAPH_LayoutMarkerActor(graph);
        RESEARCH_GRAPH_SetTriangleActorVisible(graph);
        GFL_USE_PlaySeDefaultVolume(0x76c);
        RESEARCH_GRAPH_SetStateChanged(graph);
        break;
    }
}

void RESEARCH_GRAPH_EnterDrawMediumAlt(char *graph)
{
    switch (RESEARCH_GRAPH_GetSubState(graph)) {
    case 0:
        ((struct ResearchObjB *)graph)->detailMode = 1;
        RESEARCH_GRAPH_ClearUpdatedFlag(graph);
        RESEARCH_GRAPH_ResetTimer(graph);
        RESEARCH_GRAPH_BuildGraphTable(graph);
        RESEARCH_GRAPH_DrawIndexCursorDim((u8 *)graph);
        RESEARCH_GRAPH_LoadBackground(graph);
        RESEARCH_GRAPH_PrintSliceLabel(graph);
        RESEARCH_GRAPH_SetDetailLabelVisible(graph);
        RESEARCH_GRAPH_SetTeamLabelVisible(graph);
        RESEARCH_GRAPH_LayoutArrow(graph);
        RESEARCH_GRAPH_LayoutActors(graph);
        RESEARCH_GRAPH_HideAllPercentages(graph);
        RESEARCH_GRAPH_SetSlicesFromGraphB((u8 *)graph, 0);
        RESEARCH_GRAPH_SetSlicesFromGraphB((u8 *)graph, 1);
        RESEARCH_GRAPH_SetCenterDepth(graph);
        CircleGraph_SetEnabled((struct CircleGraph *)(RESEARCH_GRAPH_GetRightCircle(graph)), 1);
        CircleGraph_QueueDrawMedium((struct CircleGraph *)(RESEARCH_GRAPH_GetRightCircle(graph)));
        RESEARCH_GRAPH_IncSubState(graph);
        break;
    case 1:
        if (GFL_USE_IsAnySeBusy() == 0) {
            if (((struct ResearchObjB *)graph)->stateTimer >= 0x3c) {
                RESEARCH_GRAPH_IncSubState(graph);
                return;
            }
            GFL_USE_PlaySeDefaultVolume(0x76b);
        }
        break;
    case 2:
        ((struct ResearchObjB *)graph)->detailMode = 0;
        RESEARCH_GRAPH_SwapCenterPairs(graph);
        CircleGraph_SetEnabled((struct CircleGraph *)(RESEARCH_GRAPH_GetRightCircle(graph)), 0);
        RESEARCH_GRAPH_LoadBackground(graph);
        RESEARCH_GRAPH_DrawIndexCursor(graph);
        RESEARCH_GRAPH_SetDetailLabelVisible(graph);
        RESEARCH_GRAPH_PrintSliceLabel(graph);
        RESEARCH_GRAPH_PrintTimeLabel(graph);
        RESEARCH_GRAPH_PrintTeamLabel(graph);
        RESEARCH_GRAPH_LayoutArrow(graph);
        RESEARCH_GRAPH_LayoutActors(graph);
        RESEARCH_GRAPH_LayoutMarkerActor(graph);
        RESEARCH_GRAPH_SetTriangleActorVisible(graph);
        GFL_USE_PlaySeDefaultVolume(0x76c);
        RESEARCH_GRAPH_SetStateChanged(graph);
        break;
    }
}

/*
 * Same two-case entry with RESEARCH_GRAPH_FadeOut() and the ARM9 query FADE_IsActive().
 *
 * Addresses are Black-image addresses.
 */
void RESEARCH_GRAPH_ExitFade(u32 graph)
{
    switch (RESEARCH_GRAPH_GetSubState((void *)graph)) {
    case 0:
    RESEARCH_GRAPH_FadeOut();
    RESEARCH_GRAPH_IncSubState((void *)graph);
    break;
    case 1:
    if (FADE_IsActive() == 0) {
    RESEARCH_GRAPH_SetStateChanged((void *)graph);
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
void RESEARCH_GRAPH_AdvanceWhileActive(u32 graph)
{
    if (RESEARCH_GRAPH_GetCount((void *)graph) < ((struct ResearchObjB *)graph)->stateTimer) {
    RESEARCH_GRAPH_SetStateChanged((void *)graph);
    }
}

void RESEARCH_GRAPH_Cleanup(u8 *graph)
{
    RESEARCH_GRAPH_RestorePaletteAnime((int *)graph);
    RESEARCH_GRAPH_DestroyPaletteAnime((int *)graph);
    RESEARCH_COMMON_StopPaletteAnime(*(u32 *)&((struct ResearchObjB *)graph)->owner);
    RESEARCH_COMMON_RestorePaletteAnime(*(u32 *)&((struct ResearchObjB *)graph)->owner);
    RESEARCH_GRAPH_UnregisterVBlank((u8 *)graph);
    RESEARCH_GRAPH_DestroyPercentages((int *)graph);
    RESEARCH_GRAPH_DestroyArrow(graph);
    RESEARCH_GRAPH_DestroyCircles((char *)graph);
    RESEARCH_GRAPH_DeletePalAnm((uptr)graph);
    RESEARCH_GRAPH_DeleteBmps((int *)graph);
    RESEARCH_GRAPH_DeleteOamObjects((int *)graph);
    RESEARCH_GRAPH_DeleteOamSys((u8 *)graph);
    RESEARCH_GRAPH_DeleteActors((int *)graph);
    RESEARCH_GRAPH_DeleteUnits((int *)graph);
    RESEARCH_GRAPH_ReleaseEntryResources((uptr)graph);
    RESEARCH_GRAPH_ReleaseCursorResources((uptr)graph);
    RESEARCH_GRAPH_DestroyLabels((int *)graph);
    RESEARCH_GRAPH_ShowBackground3(graph);
    RESEARCH_GRAPH_DummyBg3(graph);
    RESEARCH_GRAPH_ShowBackground7(graph);
    RESEARCH_GRAPH_DummyBg7(graph);
    RESEARCH_GRAPH_ExitOverlayBackgrounds(graph);
    RESEARCH_GRAPH_DeleteWordSet((u8 *)graph);
    RESEARCH_GRAPH_DeleteMessages((int *)graph);
    RESEARCH_GRAPH_DeleteFont((u8 *)graph);
    RESEARCH_GRAPH_SetActive((void *)graph, 0);
    RESEARCH_GRAPH_PushCommand((u8 *)graph, 13);
    RESEARCH_GRAPH_SetStateChanged((void *)graph);
    RESEARCH_GRAPH_ClearNotifyFlag((unsigned char *)graph);
    *(u32 *)&((struct ResearchObjB *)graph)->drawSystem = 0;
    ((struct ResearchObjB *)graph)->visible = 1;
}

void RESEARCH_GRAPH_SetStateChanged(void *graph)
{
    ((struct ResearchObjB *)graph)->stateChanged = 1;
}

/*
 * Tail-call veneer: forwards arg(s) (u32)(*(u32*)(a0)) to RESEARCH_COMMON_SetEntryHandled.
 *
 * Addresses are Black-image addresses.
 */
void RESEARCH_GRAPH_SetEntryHandled(u8 *graph, u32 handled)
{
    RESEARCH_COMMON_SetEntryHandled((struct ResearchCommon *)(*(u8 * *)&((struct ResearchObjB *)graph)->owner), handled);
}

void RESEARCH_GRAPH_SetActive(void *graph, u32 active)
{
    ((struct ResearchObjB *)graph)->active = active;
}

u32 RESEARCH_GRAPH_GetCount(void *graph)
{
    return ((struct ResearchObjB *)graph)->count;
}

/*
 * Classifies the record: 3 when the first query is busy and the second is
 * not, else 2.
 *
 * Addresses are Black-image addresses.
 */
u32 RESEARCH_GRAPH_GetTransitionKind(u8 *graph)
{
    u32 v = ((struct ResearchObjB *)graph)->ownerU;
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
void RESEARCH_GRAPH_IncTimer(void *graph)
{
    u32 *c = (u32 *)((char *)graph + 0x28);
    *c += 1;
}

/*
 * Tail-call veneer: forwards arg(s) (u32)(*(u32*)(a0 + 28)) to RingQueue_Push.
 *
 * Addresses are Black-image addresses.
 */
void RESEARCH_GRAPH_PushCommand(u8 *graph, u32 command)
{
    RingQueue_Push((struct RingQueue *)((((struct ResearchObjB *)graph)->commandQueue)), command);
}

void RESEARCH_GRAPH_ProcessCommand(u32 graph)
{
    if (((struct ResearchObjB *)graph)->stateChanged != 0) {
    if (RingQueue_IsEmpty((struct RingQueue *)(((struct ResearchObjB *)graph)->commandQueue)) == 0) {
    RESEARCH_GRAPH_StartSubState((void *)graph, RingQueue_Pop((struct RingQueue *)(((struct ResearchObjB *)graph)->commandQueue)));
    }
    }
}

/*
 * Set +0x20, clear +0x24, +0x28 and +0x3dc.
 *
 * Addresses are Black-image addresses.
 */
void RESEARCH_GRAPH_StartSubState(void *graph, u32 state)
{
    ((struct ResearchObjB *)graph)->state = state;
    ((struct ResearchObjB *)graph)->subState = 0;
    ((struct ResearchObjB *)graph)->stateTimer = 0;
    ((struct ResearchObjB *)graph)->stateChanged = 0;
}

u32 RESEARCH_GRAPH_GetSubState(void *graph)
{
    return ((struct ResearchObjB *)graph)->subState;
}

/*
 * Increment the u32 at +0x24.
 *
 * Addresses are Black-image addresses.
 */
void RESEARCH_GRAPH_IncSubState(void *graph)
{
    u32 *c = (u32 *)((char *)graph + 0x24);
    *c += 1;
}

void RESEARCH_GRAPH_SelectPrev(u8 *graph)
{
    int repeat=1;
    RESEARCH_GRAPH_DrawIndexCursorDim(graph);
    RESEARCH_GRAPH_CycleIndex((char *)graph,-1);
    do {
        u32 index=((struct ResearchObjB *)graph)->cursorIndex;
        if (index-1<=1) {
            if (((struct ResearchObjB *)graph)->entryShown==0 || RESEARCH_GRAPH_GetGroupValue(graph)==0) {
                RESEARCH_GRAPH_CycleIndex((char *)graph,-1);
            } else repeat=0;
        } else if (index==4) {
            if (((struct ResearchObjB *)graph)->entryShown==1 || RESEARCH_GRAPH_GetGroupValue(graph)==0) {
                RESEARCH_GRAPH_CycleIndex((char *)graph,-1);
            } else repeat=0;
        } else repeat=0;
    } while(repeat);
    RESEARCH_GRAPH_DrawIndexCursor((char *)graph);
    RESEARCH_GRAPH_LayoutActors((char *)graph);
    RESEARCH_GRAPH_LayoutMarkerActor((char *)graph);
    RESEARCH_GRAPH_StartSlotPaletteAnime((char *)graph,1);
    if (((struct ResearchObjB *)graph)->cursorIndex==4) RESEARCH_GRAPH_SetHighlightC((uptr)graph);
    GFL_USE_PlaySeDefaultVolume(1352);
    RESEARCH_GRAPH_LayoutTouchRects(graph);
}

void RESEARCH_GRAPH_SelectNext(u8 *graph)
{
    int repeat=1;
    RESEARCH_GRAPH_DrawIndexCursorDim(graph);
    RESEARCH_GRAPH_CycleIndex((char *)graph,1);
    do {
        u32 index=((struct ResearchObjB *)graph)->cursorIndex;
        if (index-1<=1) {
            if (((struct ResearchObjB *)graph)->entryShown==0 || RESEARCH_GRAPH_GetGroupValue(graph)==0) {
                RESEARCH_GRAPH_CycleIndex((char *)graph,1);
            } else repeat=0;
        } else if (index==4) {
            if (((struct ResearchObjB *)graph)->entryShown==1 || RESEARCH_GRAPH_GetGroupValue(graph)==0) {
                RESEARCH_GRAPH_CycleIndex((char *)graph,1);
            } else repeat=0;
        } else repeat=0;
    } while(repeat);
    RESEARCH_GRAPH_DrawIndexCursor((char *)graph);
    RESEARCH_GRAPH_LayoutActors((char *)graph);
    RESEARCH_GRAPH_LayoutMarkerActor((char *)graph);
    RESEARCH_GRAPH_StartSlotPaletteAnime((char *)graph,1);
    if (((struct ResearchObjB *)graph)->cursorIndex==4) RESEARCH_GRAPH_SetHighlightC((uptr)graph);
    GFL_USE_PlaySeDefaultVolume(1352);
    RESEARCH_GRAPH_LayoutTouchRects(graph);
}

u32 RESEARCH_GRAPH_SelectDirect(u32 graph, u32 index)
{
    RESEARCH_GRAPH_ApplySelection((u8 *)graph, index);
    RESEARCH_GRAPH_StartSlotPaletteAnime((char *)graph, 1);
    return GFL_USE_PlaySeDefaultVolume(1352);
}

void RESEARCH_GRAPH_ApplySelection(u8 *graph, u32 index)
{
    if ((u32)(index - 1) <= 1) {
    if (((struct ResearchObjB *)graph)->entryShown == 0) {
    return;
    }
    if (RESEARCH_GRAPH_GetGroupValue(graph) == 0) {
    return;
    }
    }
    RESEARCH_GRAPH_DrawIndexCursorDim(graph);
    RESEARCH_GRAPH_SetIndex(graph, index);
    RESEARCH_GRAPH_DrawIndexCursor((char *)graph);
    RESEARCH_GRAPH_LayoutActors((char *)graph);
    RESEARCH_GRAPH_LayoutMarkerActor((char *)graph);
    RESEARCH_GRAPH_LayoutTouchRects(graph);
}

/*
 * Per-frame step for the record's +0x3C8 sub-state; the tail is the
 * fixed-order call list that re-arms the sub-system (delta +1).
 *
 * Addresses are Black-image addresses.
 */
void RESEARCH_GRAPH_MoveGroupBackward(char *graph)
{
    if (((struct ResearchObjB *)graph)->entryShown != 0) {
        if (RESEARCH_GRAPH_GetGroupValue(graph) != 0) {
            CircleGraph_QueueErase((struct CircleGraph *)(RESEARCH_GRAPH_GetLeftCircle(graph)));
        }
    }
    RESEARCH_GRAPH_BuildGraphTable(graph);
    RESEARCH_GRAPH_ClearUpdatedFlag(graph);
    RESEARCH_GRAPH_CycleGroup(graph, 1);
    ((struct ResearchObjB *)graph)->entryShown = 0;
    RESEARCH_GRAPH_LoadBackground(graph);
    RESEARCH_GRAPH_DrawIndexCursor(graph);
    RESEARCH_GRAPH_PrintGroupLabel(graph);
    RESEARCH_GRAPH_PrintKindLabel(graph);
    RESEARCH_GRAPH_MoveToFirstEntry((char *)graph);
    RESEARCH_GRAPH_PrintTimeLabel(graph);
    RESEARCH_GRAPH_PrintTeamLabel(graph);
    RESEARCH_GRAPH_SetTeamLabelVisible(graph);
    RESEARCH_GRAPH_HideAllPercentages(graph);
    RESEARCH_GRAPH_SetTriangleActorVisible(graph);
    RESEARCH_GRAPH_SyncArrow((u8 *)graph);
    GFL_USE_PlaySeDefaultVolume(1352);
}

/*
 * Identical frame step to RESEARCH_GRAPH_MoveGroupBackward with the sub-state delta -1.
 *
 * Addresses are Black-image addresses.
 */
void RESEARCH_GRAPH_MoveGroupForward(char *graph)
{
    if (((struct ResearchObjB *)graph)->entryShown != 0) {
        if (RESEARCH_GRAPH_GetGroupValue(graph) != 0) {
            CircleGraph_QueueErase((struct CircleGraph *)(RESEARCH_GRAPH_GetLeftCircle(graph)));
        }
    }
    RESEARCH_GRAPH_BuildGraphTable(graph);
    RESEARCH_GRAPH_ClearUpdatedFlag(graph);
    RESEARCH_GRAPH_CycleGroup(graph, -1);
    ((struct ResearchObjB *)graph)->entryShown = 0;
    RESEARCH_GRAPH_LoadBackground(graph);
    RESEARCH_GRAPH_DrawIndexCursor(graph);
    RESEARCH_GRAPH_PrintGroupLabel(graph);
    RESEARCH_GRAPH_PrintKindLabel(graph);
    RESEARCH_GRAPH_MoveToFirstEntry((char *)graph);
    RESEARCH_GRAPH_PrintTimeLabel(graph);
    RESEARCH_GRAPH_PrintTeamLabel(graph);
    RESEARCH_GRAPH_SetTeamLabelVisible(graph);
    RESEARCH_GRAPH_HideAllPercentages(graph);
    RESEARCH_GRAPH_SetTriangleActorVisible(graph);
    RESEARCH_GRAPH_SyncArrow((u8 *)graph);
    GFL_USE_PlaySeDefaultVolume(1352);
}

u32 RESEARCH_GRAPH_MoveEntryForward(u32 graph)
{
    RESEARCH_GRAPH_StepEntry((u8 *)graph, 1);
    RESEARCH_GRAPH_PrintSliceLabel((char *)graph);
    RESEARCH_GRAPH_LayoutArrow((char *)graph);
    return GFL_USE_PlaySeDefaultVolume(1352);
}

u32 RESEARCH_GRAPH_MoveEntryBackward(u32 graph)
{
    RESEARCH_GRAPH_StepEntry((u8 *)graph, -1);
    RESEARCH_GRAPH_PrintSliceLabel((char *)graph);
    RESEARCH_GRAPH_LayoutArrow((char *)graph);
    return GFL_USE_PlaySeDefaultVolume(1352);
}

void RESEARCH_GRAPH_MoveToFirstEntry(char *graph)
{
    RESEARCH_GRAPH_ClearEntryIndex((u8 *)graph);
    RESEARCH_GRAPH_PrintSliceLabel(graph);
    RESEARCH_GRAPH_LayoutArrow(graph);
}

void RESEARCH_GRAPH_MoveToSelectedEntry(char *graph)
{
    RESEARCH_GRAPH_SetEntryFromSlice(graph);
    RESEARCH_GRAPH_PrintSliceLabel(graph);
    RESEARCH_GRAPH_LayoutArrow(graph);
}

void RESEARCH_GRAPH_ToggleEntry(char *graph)
{
    int flag = 0;
    u32 k;
    if (RESEARCH_GRAPH_AreCirclesIdle((uptr)graph) == 0) {
        return;
    }
    if (((struct ResearchObjB *)graph)->entryShown != 0 && RESEARCH_GRAPH_GetGroupValue(graph) != 0) {
        CircleGraph_QueueErase((struct CircleGraph *)(RESEARCH_GRAPH_GetLeftCircle(graph)));
        flag = 1;
    }
    switch (((struct ResearchObjB *)graph)->graphKind) {
    case 0:
        k = 1;
        break;
    case 1:
        k = 0;
        break;
    }
    RESEARCH_GRAPH_SetGraphKind(graph, k);
    RESEARCH_GRAPH_LoadBackground(graph);
    RESEARCH_GRAPH_DrawIndexCursor(graph);
    RESEARCH_GRAPH_PrintSliceLabel(graph);
    RESEARCH_GRAPH_PrintTimeLabel(graph);
    RESEARCH_GRAPH_PrintTeamLabel(graph);
    RESEARCH_GRAPH_SetTeamLabelVisible(graph);
    RESEARCH_GRAPH_SetDetailLabelVisible(graph);
    RESEARCH_GRAPH_SetTriangleActorVisible(graph);
    RESEARCH_GRAPH_SyncArrow((u8 *)graph);
    RESEARCH_GRAPH_LayoutArrow(graph);
    RESEARCH_GRAPH_HideAllPercentages(graph);
    if (((struct ResearchObjB *)graph)->entryShown != 0 && RESEARCH_GRAPH_GetGroupValue(graph) != 0) {
        RESEARCH_GRAPH_UpdatePercentages(graph);
        RESEARCH_GRAPH_ShowPercentages(graph);
    }
    if (((struct ResearchObjB *)graph)->entryShown != 0 && RESEARCH_GRAPH_GetGroupValue(graph) != 0) {
        if (flag != 0) {
            CircleGraph_HoldUpdate((struct CircleGraph *)(RESEARCH_GRAPH_GetLeftCircle(graph)), 0x14);
        }
        CircleGraph_QueueDrawFast((struct CircleGraph *)(RESEARCH_GRAPH_GetLeftCircle(graph)));
        CircleGraph_SetEnabled((struct CircleGraph *)(RESEARCH_GRAPH_GetLeftCircle(graph)), 1);
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

void RESEARCH_GRAPH_CycleIndex(char *graph, int delta)
{
    ((struct ResearchObjB *)graph)->cursorIndexSigned = (((struct ResearchObjB *)graph)->cursorIndexSigned + delta + 5) % 5;
}

/*
 * Field setter, u32 at +0x34.
 *
 * Addresses are Black-image addresses.
 */
void RESEARCH_GRAPH_SetIndex(void *graph, u32 index)
{
    ((struct ResearchObjB *)graph)->cursorIndex = index;
}

int RESEARCH_GRAPH_DrawIndexCursor(char *graph)
{
    switch (((struct ResearchObjB *)graph)->cursorIndexSigned) {
    case 0:
    case 2:
    case 3:
        BG_SYS_FillTileMap(2, d_021C3AC8[*(int *)(graph + 0x34)].x,
                      d_021C3AC8[*(int *)(graph + 0x34)].y,
                      d_021C3AC8[*(int *)(graph + 0x34)].w,
                      d_021C3AC8[*(int *)(graph + 0x34)].h, 0xa);
        break;
    case 1:
        BG_SYS_FillTileMap(2, 0xd, 4, 0x13, 4, 0xa);
        BG_SYS_FillTileMap(2, 0x10, 8, 0x10, 3, 0xa);
        break;
    case 4:
        RESEARCH_GRAPH_SetHighlightA((uptr)graph);
        break;
    }
    return BG_SYS_PushTile(2);
}

void RESEARCH_GRAPH_DrawIndexCursorDim(u8 *graph)
{
    switch (((struct ResearchObjB *)graph)->cursorIndex) {
    case 0:
    case 2:
    case 3:
        BG_SYS_FillTileMap(2, d_021C3AC8[*(u32 *)(graph + 52)].x,
            d_021C3AC8[*(u32 *)(graph + 52)].y,
            d_021C3AC8[*(u32 *)(graph + 52)].w,
            d_021C3AC8[*(u32 *)(graph + 52)].h, 6);
        break;
    case 1:
        BG_SYS_FillTileMap(2,13,4,19,4,6);
        BG_SYS_FillTileMap(2,16,8,16,3,6);
        break;
    case 4:
        RESEARCH_GRAPH_SetHighlightB((uptr)graph);
        break;
    }
    BG_SYS_PushTile(2);
}

void RESEARCH_GRAPH_CycleGroup(char *graph, int delta)
{
    ((struct ResearchObjB *)graph)->groupIndex = (u8)((((struct ResearchObjB *)graph)->groupIndex + delta + 3) % 3);
}

void RESEARCH_GRAPH_SetEntryFromSlice(char *graph)
{
    u8 *o = RESEARCH_GRAPH_GetLeftCircle(graph);

    u32 k = RESEARCH_GRAPH_GetGroupKey(graph);
    int v = CircleGraph_GetSliceKey((struct CircleGraph *)o, 0);
    ((struct ResearchObjB *)graph)->entryIndex = GRAPHTABLE_FindEntry((struct GraphTable *)(graph + 0x38), (u8)k, (u8)v);
}

/*
 * Prototypes: original loads r0/r1 and reads return at 021C11C8/11D0;
 * narrow argument truncations are explicit in the caller.
 */
void RESEARCH_GRAPH_StepEntry(u8 *graph, int step)
{
    u8 *object;
    int kind;
    int count;
    int index;
    object = RESEARCH_GRAPH_GetLeftCircle(graph);
    kind = RESEARCH_GRAPH_GetGroupKey(graph);
    count = RESEARCH_GRAPH_GetGroupCount(graph);
    index = RESEARCH_GRAPH_GetEntryKey(graph);
    index = CircleGraph_FindSliceIndex((struct CircleGraph *)object, index);

    index = (count + (index + step)) % count;
    index = CircleGraph_GetSliceKey((struct CircleGraph *)object, index);
    graph[697] = GRAPHTABLE_FindEntry((struct GraphTable *)(graph + 56), kind, index);
}

void RESEARCH_GRAPH_ClearEntryIndex(u8 *graph)
{
    ((struct ResearchObjB *)graph)->entryIndex = 0;
}

void RESEARCH_GRAPH_SyncArrow(u8 *graph)
{
    if (((struct ResearchObjB *)graph)->entryShown == 1 || ((struct ResearchObjB *)graph)->detailMode == 1 || RESEARCH_GRAPH_GetGroupValue(graph) == 0) {
        if (RESEARCH_GRAPH_IsSlotPaletteAnimeRunning(graph, 5) == 0) RESEARCH_GRAPH_SetNormalB((uptr)graph);
    } else {
        if (RESEARCH_GRAPH_IsSlotPaletteAnimeRunning(graph, 5) == 1) RESEARCH_GRAPH_SetNormalA((uptr)graph);
    }
}

void RESEARCH_GRAPH_SetHighlightSelected(u32 graph)
{
    BMP_OAM_SetPalette((struct BmpOam *)(((struct ResearchObjB *)graph)->oamObjectB), 0);
    RESEARCH_GRAPH_StopSlotPaletteAnime((u8 *)graph, 5);
    RESEARCH_GRAPH_StopSlotPaletteAnime((u8 *)graph, 6);
    RESEARCH_GRAPH_StartSlotPaletteAnime((char *)graph, 2);
}

void RESEARCH_GRAPH_SetHighlightA(u32 graph)
{
    BMP_OAM_SetPalette((struct BmpOam *)(((struct ResearchObjB *)graph)->oamObjectB), 0);
    RESEARCH_GRAPH_StartSlotPaletteAnime((char *)graph, 3);
}

void RESEARCH_GRAPH_SetHighlightB(u32 graph)
{
    BMP_OAM_SetPalette((struct BmpOam *)(((struct ResearchObjB *)graph)->oamObjectB), 1);
    RESEARCH_GRAPH_StopSlotPaletteAnime((u8 *)graph, 3);
}

void RESEARCH_GRAPH_SetHighlightC(u32 graph)
{
    BMP_OAM_SetPalette((struct BmpOam *)(((struct ResearchObjB *)graph)->oamObjectB), 0);
    RESEARCH_GRAPH_StartSlotPaletteAnime((char *)graph, 4);
}

void RESEARCH_GRAPH_SetNormalA(u32 graph)
{
    BMP_OAM_SetPalette((struct BmpOam *)(((struct ResearchObjB *)graph)->oamObjectB), 1);
    RESEARCH_GRAPH_StopSlotPaletteAnime((u8 *)graph, 5);
    RESEARCH_GRAPH_StartSlotPaletteAnime((char *)graph, 6);
}

void RESEARCH_GRAPH_SetNormalB(u32 graph)
{
    BMP_OAM_SetPalette((struct BmpOam *)(((struct ResearchObjB *)graph)->oamObjectB), 1);
    RESEARCH_GRAPH_StartSlotPaletteAnime((char *)graph, 5);
}

void RESEARCH_GRAPH_StartPaletteAnime(u32 *graph)
{
    RESEARCH_COMMON_StartPaletteAnime((struct ResearchCommon *)(*graph), 0);
}

/*
 * Swap the u32 pairs at +0x2bc and +0x2c4.
 *
 * Addresses are Black-image addresses.
 */
void RESEARCH_GRAPH_SwapCenterPairs(void *graph)
{
    int i;
    for (i = 0; i < 2; i++) {
        u32 t = *(u32 *)((char *)graph + i * 4 + 0x2bc);
        *(u32 *)((char *)graph + i * 4 + 0x2bc) = *(u32 *)((char *)graph + i * 4 + 0x2c4);
        *(u32 *)((char *)graph + i * 4 + 0x2c4) = t;
    }
}

void RESEARCH_GRAPH_QuantizePosition(u32 input)
{
    u32 quantY = (((struct GraphSliceInput *)input)->y + 62) / 3;
    u32 quantZ = (((struct GraphSliceInput *)input)->z + 62) / 3;
    ((struct GraphSliceInput *)input)->quantX = (((struct GraphSliceInput *)input)->x + 62) / 3;
    ((struct GraphSliceInput *)input)->quantY = quantY;
    ((struct GraphSliceInput *)input)->quantZ = quantZ;
}

void RESEARCH_GRAPH_SetCenterDepth(void *graph)
{
    CircleGraph_SetCenterDepth((struct CircleGraph *)(RESEARCH_GRAPH_GetLeftCircle(graph)), 0xFFFFE000);
    CircleGraph_SetCenterDepth((struct CircleGraph *)(RESEARCH_GRAPH_GetRightCircle(graph)), 0);
}

void RESEARCH_GRAPH_SetSlicesFromGraphA(u8 *graph,int mode)
{
    struct GraphSliceInput items[17];
    struct GraphEntryView *base;
    uptr object;
    int count;
    int i;
    object=*(u32 *)(graph+700+mode*4);
    count=RESEARCH_GRAPH_GetGroupCount(graph);
    base=(struct GraphEntryView *)(graph+60+graph[696]*212);
    for(i=0;i<count;i++) {
        struct GraphEntryView *q=(struct GraphEntryView *)((u8 *)base+8+i*12);
        struct GraphSliceInput *t=&items[i];
        t->id=q->id; t->x=q->x; t->y=q->y; t->z=q->z;
        RESEARCH_GRAPH_QuantizePosition((uptr)t);
        switch(mode) { case 0: t->value=q->valueA; break; case 1: t->value=q->valueB; break; }
    }
    CircleGraph_SetSlices((struct CircleGraph *)object,(struct CircleGraphInput *)items,count);
}

void RESEARCH_GRAPH_SetSlicesFromGraphB(u8 *graph, u32 mode)
{
    struct GraphSliceInput items[17];
    struct GraphEntryView *base;
    uptr object;
    int count;
    int i;
    object=*(u32 *)(graph+708+mode*4);
    count=RESEARCH_GRAPH_GetGroupCount(graph);
    base=(struct GraphEntryView *)(graph+60+graph[696]*212);
    for(i=0;i<count;i++) {
        struct GraphEntryView *q=(struct GraphEntryView *)((u8 *)base+8+i*12);
        struct GraphSliceInput *t=&items[i];
        t->id=q->id; t->x=q->x; t->y=q->y; t->z=q->z;
        RESEARCH_GRAPH_QuantizePosition((uptr)t);
        switch(mode) { case 0: t->value=q->valueA; break; case 1: t->value=q->valueB; break; }
    }
    CircleGraph_SetSlices((struct CircleGraph *)object,(struct CircleGraphInput *)items,count);
}

void RESEARCH_GRAPH_UpdateCircles(char *graph)
{
    int i;
    for (i = 0; i < 2; i++) {
        CircleGraph_Update((struct CircleGraph *)(*(u8 **)(graph + i * 4 + 0x2bc)));
        CircleGraph_Update((struct CircleGraph *)(*(u8 **)(graph + i * 4 + 0x2c4)));
    }
}

void RESEARCH_GRAPH_DrawCircles(char *graph)
{
    int i;
    for (i = 0; i < 2; i++) {
        CircleGraph_Draw((struct CircleGraph *)(*(u8 **)(graph + i * 4 + 0x2bc)));
        CircleGraph_Draw((struct CircleGraph *)(*(u8 **)(graph + i * 4 + 0x2c4)));
    }
}

void RESEARCH_GRAPH_DrawSliceColor(char *graph)
{
    unsigned r,g,b;
    void *color;
    if (((struct ResearchObjB *)graph)->entryShown==0 || ((struct ResearchObjB *)graph)->detailMode==1 || RESEARCH_GRAPH_GetGroupValue(graph)==0) return;
    color=graph+56;
    r=GRAPHTABLE_GetEntryRed(color,((struct ResearchObjB *)graph)->groupIndex,((struct ResearchObjB *)graph)->entryIndex);
    g=GRAPHTABLE_GetEntryGreen(color,((struct ResearchObjB *)graph)->groupIndex,((struct ResearchObjB *)graph)->entryIndex);
    b=GRAPHTABLE_GetEntryBlue(color,((struct ResearchObjB *)graph)->groupIndex,((struct ResearchObjB *)graph)->entryIndex);
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
void RESEARCH_GRAPH_LayoutArrow(char *graph)
{
    u8 *object;
    unsigned index;
    s32 x,y;
    ARROW_Reset((struct Arrow *)(*(unsigned *)&((struct ResearchObjB *)graph)->arrow));
    if (((struct ResearchObjB *)graph)->detailMode==1) return;
    if (((struct ResearchObjB *)graph)->entryShown==0) return;
    if (RESEARCH_GRAPH_GetGroupValue(graph)==0) return;
    object=RESEARCH_GRAPH_GetLeftCircle(graph);
    index=RESEARCH_GRAPH_GetEntryKey(graph);
    if (CircleGraph_GetPercentByKey((struct CircleGraph *)object,index)==0) return;
    if (((struct ResearchObjB *)graph)->entryShown!=0) {
        object=RESEARCH_GRAPH_GetLeftCircle(graph);
        index=RESEARCH_GRAPH_GetEntryKey(graph);
        CircleGraph_GetLabelPositionByKey((struct CircleGraph *)object,index,&x,&y);

        ARROW_Layout((struct Arrow *)(*(unsigned *)&((struct ResearchObjB *)graph)->arrow),104,34,x,y);
        ARROW_Start((struct Arrow *)(*(unsigned *)&((struct ResearchObjB *)graph)->arrow));
    }
}

/*
 * lever: unsigned output counter i; initialize before decrementing the signed reverse counter.
 * C11E8 forwards original r0/r1 to C1AB4's two-input record lookup.
 * C271C forwards original r1/r2 to C288C's two-field setter.
 */
void RESEARCH_GRAPH_UpdatePercentages(char *graph)
{
    int n,id;
    unsigned i;
    u8 *object;
    s32 x,y;
    uptr slot;
    n=RESEARCH_GRAPH_GetGroupCount(graph);
    object=RESEARCH_GRAPH_GetLeftCircle(graph);
    i=0;
    n--;
    for (;n>=0;n--) {
        id=CircleGraph_GetPercentByIndex((struct CircleGraph *)object,n);
        CircleGraph_GetLabelPositionByIndex((struct CircleGraph *)object,n,&x,&y);

        if (id>=10) {
            slot=*(unsigned *)(graph+i*4+0x2d4);
            PERCENTAGE_SetValue((struct Percentage *)slot,id);
            PERCENTAGE_SetPosition((struct Percentage *)slot,x,y);
            i++;
        }
    }
    ((struct ResearchObjB *)graph)->percentageCount=i;
}

void RESEARCH_GRAPH_HideAllPercentages(char *graph)
{
    int i;
    u8 z = 0;
    for (i = 0; i < 10; i++) {
        PERCENTAGE_SetVisible((struct Percentage *)(*(u32 *)(graph + i * 4 + 0x2d4)), z);
    }
    ((struct ResearchObjB *)graph)->percentageVisible = z;
}

/*
 * Tail-call veneer: forwards arg(s) (u32)(*(u32*)(a0 + (a1)*4 + 724)), 1 to PERCENTAGE_SetVisible.
 *
 * Addresses are Black-image addresses.
 */
void RESEARCH_GRAPH_ShowPercent(u8 *graph, u32 index)
{
    PERCENTAGE_SetVisible((struct Percentage *)((*(u32*)(graph + (index)*4 + 724))), 1);
}

void RESEARCH_GRAPH_ShowPercentages(char *graph)
{
    int i;
    int n;
    n = ((struct ResearchObjB *)graph)->percentageCount;
    for (i = 0; i < n; i++) {
        RESEARCH_GRAPH_ShowPercent((u8 *)graph, (u8)i);
    }
}

/*
 * lever: pool 021BF088 is 021C3AC8; dropping contested ov217 data hint resolves sole-ref evidence.
 */
void RESEARCH_GRAPH_LayoutTouchRects(u8 *graph)
{
    const struct CursorLayoutRow *row;
    u8 *q;
    row=(const struct CursorLayoutRow *)&d_021C3AC8[((struct ResearchObjB *)graph)->cursorIndex];
    q=graph+0x2fe;
    q[2]=RESEARCH_GRAPH_ClampByte(row->offsets[0]+row->offsets[4]-16);
    graph[0x2fe]=RESEARCH_GRAPH_ClampByte(row->offsets[1]+row->offsets[5]-16);
    q[3]=RESEARCH_GRAPH_ClampByte(q[2]+32);
    q[1]=RESEARCH_GRAPH_ClampByte(graph[0x2fe]+32);
    row=(const struct CursorLayoutRow *)&d_021C3AC8[((struct ResearchObjB *)graph)->cursorIndex];
    q=graph+0x302;
    q[2]=RESEARCH_GRAPH_ClampByte(row->offsets[0]+row->offsets[6]-16);
    graph[0x302]=RESEARCH_GRAPH_ClampByte(row->offsets[1]+row->offsets[7]-16);
    q[3]=RESEARCH_GRAPH_ClampByte(q[2]+32);
    q[1]=RESEARCH_GRAPH_ClampByte(graph[0x302]+32);
}

void RESEARCH_GRAPH_LoadBackground(char *graph)
{
    struct ArcFile *arc;
    void *file,*out;
    unsigned id;
    arc=ARC_TOOL_CreateHandle(192,((struct ResearchObjB *)graph)->heapId);
    if (((struct ResearchObjB *)graph)->detailMode!=0) id=8;
    else if (RESEARCH_GRAPH_GetGroupValue(graph)==0) id=6;
    else {
        id=6;
        if (((struct ResearchObjB *)graph)->entryShown!=0) id=7;
    }
    file=ARC_TOOL_LoadHandleMember((struct ArcHandle *)arc,id,((struct ResearchObjB *)graph)->heapId);
    NNS_G2dGetUnpackedScreenData(file,&out);
    BG_SYS_DrawTile(2,(uptr)out+12,0,0,32,32);
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
void RESEARCH_GRAPH_PrintTitle(char *graph)
{
    BgTextLabel_PrintMessage((struct BgTextLabel *)(((struct ResearchObjB *)graph)->titleLabel), d_021C3628[((struct ResearchObjB *)graph)->titleGroup]);
}

void RESEARCH_GRAPH_PrintGroupLabel(char *graph)
{
    u32 i = RESEARCH_GRAPH_GetGroupKey(graph);
    BgTextLabel_PrintMessage((struct BgTextLabel *)(((struct ResearchObjB *)graph)->groupLabel), d_021C36B8[i]);
}

void RESEARCH_GRAPH_PrintKindLabel(char *graph)
{
    u32 o = ((struct ResearchObjB *)graph)->kindLabel;
    u32 i = RESEARCH_GRAPH_GetGroupKey(graph);
    BgTextLabel_PrintMessage((struct BgTextLabel *)o, d_021C369A[i]);
}

void RESEARCH_GRAPH_PrintSliceLabel(char *graph)
{
    u32 t = ((struct ResearchObjB *)graph)->sliceLabel;
    u8 *o = RESEARCH_GRAPH_GetLeftCircle(graph);
    u32 k;
    u32 a, b, c;
    void *x, *y, *z;
    if (((struct ResearchObjB *)graph)->entryShown == 0 || ((struct ResearchObjB *)graph)->detailMode == 1) {
        BgTextLabel_SetVisible((struct BgTextLabel *)t, 0);
        return;
    }
    if (RESEARCH_GRAPH_GetGroupValue(graph) == 0) {
        BgTextLabel_SetVisible((struct BgTextLabel *)t, 0);
        return;
    }
    k = RESEARCH_GRAPH_GetEntryKey(graph);
    a = CircleGraph_FindSliceIndex((struct CircleGraph *)o, (u8)k);

    b = RESEARCH_GRAPH_GetEntryValue(graph);
    c = CircleGraph_GetPercentByKey((struct CircleGraph *)o, (u8)k);
    x = MSGDATA_AllocString(((struct ResearchObjB *)graph)->msgBankA, 0xd);
    y = MSGDATA_AllocString(((struct ResearchObjB *)graph)->msgBankB, k);
    z = STRBUF_Create(0x80, ((struct ResearchObjB *)graph)->heapId);
    WORDSET_SetSlotNumber(((struct ResearchObjB *)graph)->wordSet, 0, a + 1, 2, 1, 1);
    WORDSET_SetSlotTag(((struct ResearchObjB *)graph)->wordSet, 1, y, 0, 1, 2);
    WORDSET_SetSlotNumber(((struct ResearchObjB *)graph)->wordSet, 2, b, 5, 1, 1);
    WORDSET_SetSlotNumber(((struct ResearchObjB *)graph)->wordSet, 3, c, 3, 1, 1);
    WORDSET_CopyTaggedText(((struct ResearchObjB *)graph)->wordSet, z, x);
    BgTextLabel_PrintText((struct BgTextLabel *)t, z);
    BgTextLabel_SetVisible((struct BgTextLabel *)t, 1);
    STRBUF_Delete(x);
    STRBUF_Delete(z);
    STRBUF_Delete(y);
}

/*
 * EE0C: original stores sixth argument 2 at sp+4; preserve visibly supplied trailing input.
 */
void RESEARCH_GRAPH_PrintTimeLabel(char *graph)
{
    unsigned index;
    struct U16Vec *a,*b,*buf;
    if (((struct ResearchObjB *)graph)->entryShown==0 || RESEARCH_GRAPH_GetGroupValue(graph)==0) {
        BgTextLabel_SetVisible((struct BgTextLabel *)(((struct ResearchObjB *)graph)->timeLabel),0);
        return;
    }
    index=RESEARCH_GRAPH_GetEntryIdBySave((unsigned char *)graph);
    a=(struct U16Vec *)MSGDATA_AllocString(*(struct MsgBank * *)&((struct ResearchObjB *)graph)->msgBankA,14);
    b=(struct U16Vec *)MSGDATA_AllocString(*(struct MsgBank * *)&((struct ResearchObjB *)graph)->msgBankB,index);
    buf=(struct U16Vec *)STRBUF_Create(128,((struct ResearchObjB *)graph)->heapId);
    WORDSET_SetSlotTag(*(struct WordSet * *)&((struct ResearchObjB *)graph)->wordSet,0,(struct Strbuf *)b,0,1,2);
    WORDSET_CopyTaggedText(*(struct WordSet * *)&((struct ResearchObjB *)graph)->wordSet,(struct Strbuf *)buf,(struct Strbuf *)a);
    BgTextLabel_SetVisible((struct BgTextLabel *)(((struct ResearchObjB *)graph)->timeLabel),1);
    BgTextLabel_PrintText((struct BgTextLabel *)(((struct ResearchObjB *)graph)->timeLabel),buf);
    STRBUF_Delete((struct Strbuf *)a);
    STRBUF_Delete((struct Strbuf *)buf);
    STRBUF_Delete((struct Strbuf *)b);
}

void RESEARCH_GRAPH_PrintTeamLabel(char *graph)
{
    u32 k;
    u32 x;
    void *a, *b;
    void *c;
    if (((struct ResearchObjB *)graph)->entryShown != 0) {
        switch (((struct ResearchObjB *)graph)->graphKind) {
        case 0:
            k = 0xf;
            break;
        case 1:
            k = 0x11;
            break;
        }
    } else {
        switch (((struct ResearchObjB *)graph)->graphKind) {
        case 0:
            k = 0x10;
            break;
        case 1:
            k = 0x12;
            break;
        }
    }
    x = RESEARCH_GRAPH_GetGroupValue(graph);
    c = ((struct ResearchObjB *)graph)->wordSet;
    a = MSGDATA_AllocString(((struct ResearchObjB *)graph)->msgBankA, k);
    b = STRBUF_Create(0x80, ((struct ResearchObjB *)graph)->heapId);
    WORDSET_SetSlotNumber(c, 0, x, 6, 1, 1);
    WORDSET_CopyTaggedText(c, b, a);
    BgTextLabel_PrintText((struct BgTextLabel *)(((struct ResearchObjB *)graph)->teamLabel), b);
    STRBUF_Delete(a);
    STRBUF_Delete(b);
}

void RESEARCH_GRAPH_SetTeamLabelVisible(char *graph)
{
    if (RESEARCH_GRAPH_GetGroupValue(graph) == 0) {
        BgTextLabel_SetVisible((struct BgTextLabel *)(((struct ResearchObjB *)graph)->emptyLabel), 1);
    } else {
        BgTextLabel_SetVisible((struct BgTextLabel *)(((struct ResearchObjB *)graph)->emptyLabel), 0);
    }
}

void RESEARCH_GRAPH_SetDetailLabelVisible(char *graph)
{
    if (((struct ResearchObjB *)graph)->detailMode != 0) {
        BgTextLabel_SetVisible((struct BgTextLabel *)(((struct ResearchObjB *)graph)->detailLabel), 1);
    } else {
        BgTextLabel_SetVisible((struct BgTextLabel *)(((struct ResearchObjB *)graph)->detailLabel), 0);
    }
}

void RESEARCH_GRAPH_LayoutActors(char *graph)
{
    const struct CursorLayoutRow *row;
    struct Obj *a,*b;
    struct ResearchVec2 pos;
    row=(const struct CursorLayoutRow *)&d_021C3AC8[((struct ResearchObjB *)graph)->cursorIndex];
    a=(struct Obj *)RESEARCH_GRAPH_GetMarkerActor(graph,0);
    b=(struct Obj *)RESEARCH_GRAPH_GetMarkerActor(graph,1);
    if (((struct ResearchObjB *)graph)->detailMode==1 || ((struct ResearchObjB *)graph)->cursorIndex==2 || ((struct ResearchObjB *)graph)->cursorIndex==4) {
        CLACT_SetActorDrawEnable((struct ClactActor *)a,0);
        CLACT_SetActorDrawEnable((struct ClactActor *)b,0);
        return;
    }
    pos.x=row->offsets[0]+row->offsets[4];
    pos.y=row->offsets[1]+row->offsets[5];
    CLACT_AddActorSurfacePos((struct ClactActor *)a,(struct ClactVec2 *)(&pos),0);
    pos.x=row->offsets[0]+row->offsets[6];
    pos.y=row->offsets[1]+row->offsets[7];
    CLACT_AddActorSurfacePos((struct ClactActor *)b,(struct ClactVec2 *)(&pos),0);
    CLACT_SetActorDrawEnable((struct ClactActor *)a,1);
    CLACT_SetActorDrawEnable((struct ClactActor *)b,1);
    CLACT_SetActorAutoAnim((struct ClactActor *)a,1);
    CLACT_SetActorAutoAnim((struct ClactActor *)b,1);
}

void RESEARCH_GRAPH_SetTriangleActorVisible(char *graph)
{
    if (((struct ResearchObjB *)graph)->entryShown == 0 || RESEARCH_GRAPH_GetGroupValue(graph) == 0) {
        CLACT_SetActorDrawEnable((struct ClactActor *)((struct ResearchObjB *)graph)->triangleActor, 0);
    } else {
        CLACT_SetActorDrawEnable((struct ClactActor *)((struct ResearchObjB *)graph)->triangleActor, 1);
    }
}

void RESEARCH_GRAPH_LayoutMarkerActor(char *graph)
{
    struct Obj *obj;
    unsigned index;
    s32 x,y;
    struct ResearchVec2 pos;
    const u16 *table;
    obj=*(struct Obj * *)&((struct ResearchObjB *)graph)->markerActor;
    table=d_021C3850;
    if (((struct ResearchObjB *)graph)->entryShown==0) { CLACT_SetActorDrawEnable((struct ClactActor *)obj,0); return; }
    if (((struct ResearchObjB *)graph)->cursorIndex!=2) { CLACT_SetActorDrawEnable((struct ClactActor *)obj,0); return; }
    index=RESEARCH_GRAPH_GetEntryIdBySave((u8 *)graph);
    if (CircleGraph_GetPercentByKey((struct CircleGraph *)(RESEARCH_GRAPH_GetLeftCircle(graph)),index)==0) { CLACT_SetActorDrawEnable((struct ClactActor *)obj,0); return; }
    if (index==0) { CLACT_SetActorDrawEnable((struct ClactActor *)obj,0); return; }
    CircleGraph_GetLabelPositionByKey((struct CircleGraph *)(RESEARCH_GRAPH_GetLeftCircle(graph)),index,&x,&y);

    pos.x=x;
    pos.y=y;
    CLACT_AddActorSurfacePos((struct ClactActor *)obj,(struct ClactVec2 *)(&pos),table[12]);
    CLACT_SetActorDrawEnable((struct ClactActor *)obj,1);
    CLACT_SetActorAutoAnim((struct ClactActor *)obj,1);
    CLACT_SetActorAnimLoopCount((struct ClactActor *)obj,2);
}

void RESEARCH_GRAPH_EnableOams(void *graph)
{
    RESEARCH_GRAPH_SetOamEnabled((u8 *)graph, 1, 1);
}

/*
 * Tail-call veneer: forwards arg(s) a0, 0, 1 to RESEARCH_GRAPH_SetOamEnabled.
 *
 * Addresses are Black-image addresses.
 */
void RESEARCH_GRAPH_EnableOamsA(void *graph)
{
    RESEARCH_GRAPH_SetOamEnabled((u8 *)graph, 0, 1);
}

/*
 * Tail-call veneer: forwards arg(s) a0, 0, 0 to RESEARCH_GRAPH_SetOamEnabled.
 *
 * Addresses are Black-image addresses.
 */
void RESEARCH_GRAPH_DisableOams(void *graph)
{
    RESEARCH_GRAPH_SetOamEnabled((u8 *)graph, 0, 0);
}

void RESEARCH_GRAPH_SetOamEnabled(u8 *graph, u32 index, u32 enabled)
{
    BMP_OAM_SetEnabled((struct BmpOam *)(*(u32 *)(graph + index * 4 + 0x3a8)), enabled);
}

void RESEARCH_GRAPH_StartSlotPaletteAnime(char *graph, int slot)
{
    PALETTE_ANIME_Start((struct PaletteAnime *)(*(u32 *)(graph + slot * 4 + 0x324)), d_021C3A34[slot].mode, d_021C3A34[slot].color);
}

/*
 * Tail-call veneer: forwards arg(s) (u32)(*(u32*)(a0 + (a1)*4 + 804)), (u32)(a0 + (a1)*4) to PALETTE_ANIME_Stop.
 *
 * Addresses are Black-image addresses.
 */
void RESEARCH_GRAPH_StopSlotPaletteAnime(u8 *graph, u32 slot)
{
    PALETTE_ANIME_Stop((struct PaletteAnime *)((*(u32*)(graph + (slot)*4 + 804))));
}

/*
 * Tail-call veneer: forwards arg(s) (u32)(*(u32*)(a0 + (a1)*4 + 804)), (u32)(a0 + (a1)*4) to PALETTE_ANIME_IsRunning.
 *
 * Addresses are Black-image addresses.
 */
u32 RESEARCH_GRAPH_IsSlotPaletteAnimeRunning(u8 *graph, u32 slot)
{
    return PALETTE_ANIME_IsRunning((u32)(*(u32*)(graph + (slot)*4 + 804)), (uptr)(graph + (slot)*4));
}

void RESEARCH_GRAPH_UpdateSlotPalettes(int *graph)
{
    int i;
    for (i = 0; i < 8; i++)
        PALETTE_ANIME_Update((struct PaletteAnime *)(graph[i + 0xC9]));
}

/*
 * Tail-call veneer: forwards arg(s) (u32)(*(u32*)(a0)) to RESEARCH_COMMON_UpdatePaletteAnime.
 *
 * Addresses are Black-image addresses.
 */
void RESEARCH_GRAPH_UpdatePaletteAnime(u8 *graph)
{
    RESEARCH_COMMON_UpdatePaletteAnime((u32)(((struct ResearchObjB *)graph)->ownerU));
}

void RESEARCH_GRAPH_RequestFadeIn(char *graph)
{
    PALANM_RequestFade(*(struct PaletteFade * *)&((struct ResearchObjB *)graph)->palAnm,1,0xffff,3,0,7,0xffff,((struct ResearchObjB *)graph)->fadeParam);
    PALANM_RequestFade(*(struct PaletteFade * *)&((struct ResearchObjB *)graph)->palAnm,4,0xffff,3,0,7,0xffff,((struct ResearchObjB *)graph)->fadeParam);
}

void RESEARCH_GRAPH_RequestFadeOut(char *graph)
{
    PALANM_RequestFade(*(struct PaletteFade * *)&((struct ResearchObjB *)graph)->palAnm,1,0xffff,3,7,0,0xffff,((struct ResearchObjB *)graph)->fadeParam);
    PALANM_RequestFade(*(struct PaletteFade * *)&((struct ResearchObjB *)graph)->palAnm,4,0xffff,3,7,0,0xffff,((struct ResearchObjB *)graph)->fadeParam);
}

/*
 * Note: the record's +0x3B8 handle is idle.
 *            witness outside 021BF6A4..021BF6BC.  Bytes are exact and 24/24
 *            match the listing extent; file the TARGET first (OV-BRIEF rule
 *            10) and this promotes to EXACT with no source change.
 *
 * Addresses are Black-image addresses.
 */
u32 RESEARCH_GRAPH_IsFadeDone(u8 *graph)
{
    if (PALANM_GetFadeRequestBits((struct PaletteFade *)(((struct ResearchObjB *)graph)->palAnm)) == 0) {
    return 1;
    }
    return 0;
}

u32 RESEARCH_GRAPH_TransferPalettes(u32 unusedArg, u32 graph)
{
    BG_SYS_Update();
    CLACT_VBlankSystem();
    PALANM_TransferPalettes((struct PaletteFade *)((struct ResearchObjB *)graph)->palAnm);
}

void RESEARCH_GRAPH_CheckQuestionnaireUpdated(char *graph)
{
    if (GAME_BEACON_PopQuestionnaireUpdated() == 1) {
        u16 a = RESEARCH_GRAPH_GetGroupTotalA(graph);
        if (a != (u16)(u32)RESEARCH_GRAPH_GetSaveBits((uptr)graph)) {
            ((struct ResearchObjB *)graph)->updatedFlag = 1;
        }
    }
}

/*
 * Clear the u32 at +0x3d8.
 *
 * Addresses are Black-image addresses.
 */
void RESEARCH_GRAPH_ClearUpdatedFlag(void *graph)
{
    ((struct ResearchObjB *)graph)->updatedFlag = 0;
}

void RESEARCH_GRAPH_TickTimer(void *graph)
{
    if (((struct ResearchObjB *)graph)->elapsedTimer < 0xf0) {
        ((struct ResearchObjB *)graph)->elapsedTimer += 1;
    } else {
        ((struct ResearchObjB *)graph)->timerExpired = 1;
    }
}

void RESEARCH_GRAPH_ResetTimer(void *graph)
{
    ((struct ResearchObjB *)graph)->elapsedTimer = 0;
    ((struct ResearchObjB *)graph)->timerExpired = 0;
}

u32 RESEARCH_GRAPH_GetContext(u8 *graph)
{
    return RESEARCH_COMMON_GetContext((u32 *)(((struct ResearchObjB *)graph)->owner));
}

/*
 * Tail-call veneer: forwards arg(s) (u32)(*(u32*)(a0)) to RESEARCH_COMMON_GetAppResource.
 *
 * Addresses are Black-image addresses.
 */
u32 RESEARCH_GRAPH_GetAppResource(u8 *graph)
{
    return RESEARCH_COMMON_GetAppResource((void *)(((struct ResearchObjB *)graph)->ownerU));
}

void RESEARCH_GRAPH_SetHeapId(void *graph, u32 heapId)
{
    ((struct ResearchObjB *)graph)->heapId = heapId;
}

/*
 * Field getter, u32 at +0.
 *
 * Addresses are Black-image addresses.
 */
u32 RESEARCH_GRAPH_GetOwner(void *graph)
{
    return ((struct ResearchObjB *)graph)->ownerU;
}

void RESEARCH_GRAPH_SetOwner(void *graph, u32 owner)
{
    ((struct ResearchObjB *)graph)->ownerU = owner;
}

u32 RESEARCH_GRAPH_GetInputFlag(void *graph)
{
    return RESEARCH_COMMON_GetInputFlag((void *)RESEARCH_GRAPH_GetOwner(graph));
}

/*
 * Field setter, u32 at +0x2cc.
 *
 * Addresses are Black-image addresses.
 */
void RESEARCH_GRAPH_SetGraphKind(void *graph, u32 graphKind)
{
    ((struct ResearchObjB *)graph)->graphKind = graphKind;
}

u8 *RESEARCH_GRAPH_GetLeftCircle(void *graph)
{
    u32 i = ((struct ResearchObjB *)graph)->graphKind;
    return *(u8 **)((char *)graph + i * 4 + 0x2bc);

}

u8 *RESEARCH_GRAPH_GetRightCircle(void *graph)
{
    u32 i = ((struct ResearchObjB *)graph)->graphKind;
    return *(u8 **)((char *)graph + i * 4 + 0x2c4);

}

u32 RESEARCH_GRAPH_AreCirclesIdle(u32 graph)
{
    if (CircleGraph_IsAnimating((struct CircleGraph *)(*(u8 * *)&((struct ResearchObjB *)graph)->leftCircleA)) != 0 || CircleGraph_IsAnimating((struct CircleGraph *)(*(u8 * *)&((struct ResearchObjB *)graph)->leftCircleB)) != 0 || CircleGraph_IsAnimating((struct CircleGraph *)(*(u8 * *)&((struct ResearchObjB *)graph)->rightCircleA)) != 0 || CircleGraph_IsAnimating((struct CircleGraph *)(*(u8 * *)&((struct ResearchObjB *)graph)->rightCircleB)) != 0) {
    return 0;
    }
    return 1;
}

u32 RESEARCH_GRAPH_GetGroupKey(void *graph)
{
    u32 i = ((struct ResearchObjB *)graph)->groupIndex;
    return *(u8 *)((char *)graph + i * 0xd4 + 0x3c);
}

u32 RESEARCH_GRAPH_GetGroupCount(void *graph)
{
    u32 i = ((struct ResearchObjB *)graph)->groupIndex;
    return *(u8 *)((char *)graph + i * 0xd4 + 0x3d);
}

/*
 * Element field: u16 at +0x44 of a 12-byte sub-record of record 0xd4.
 *
 * Addresses are Black-image addresses.
 */
u32 RESEARCH_GRAPH_GetEntryKey(void *graph)
{
    u32 i = ((u8 *)graph)[0x2b8];
    u32 j = ((u8 *)graph)[0x2b9];
    return *(u16 *)((char *)graph + 0x44 + i * 0xd4 + j * 0xc);
}

u32 RESEARCH_GRAPH_GetGroupValue(void *graph)
{
    u32 r = 0;
    switch (((struct ResearchObjB *)graph)->graphKind) {
    case 0:
        r = RESEARCH_GRAPH_GetGroupTotalA(graph);
        break;
    case 1:
        r = RESEARCH_GRAPH_GetGroupTotalB(graph);
        break;
    }
    return r;
}

/*
 * Element field: u16 at +0x3e of record 0xd4 bytes, selected by the u8 at +0x2b8.
 *
 * Addresses are Black-image addresses.
 */
u32 RESEARCH_GRAPH_GetGroupTotalA(void *graph)
{
    u32 i = ((struct ResearchObjB *)graph)->groupIndex;
    return *(u16 *)((char *)graph + i * 0xd4 + 0x3e);
}

u32 RESEARCH_GRAPH_GetGroupTotalB(void *graph)
{
    u32 i = ((struct ResearchObjB *)graph)->groupIndex;
    return *(u32 *)((char *)graph + i * 0xd4 + 0x40);
}

u32 RESEARCH_GRAPH_GetEntryValue(char *graph)
{
    switch (((struct ResearchObjB *)graph)->graphKind) {
    case 0:
        return RESEARCH_GRAPH_GetEntryValueA(graph);
    case 1:
        return RESEARCH_GRAPH_GetEntryValueB(graph);
    }
    return 0;
}

/*
 * Element field: u16 at +0x4a of a 12-byte sub-record of record 0xd4.
 *
 * Addresses are Black-image addresses.
 */
u32 RESEARCH_GRAPH_GetEntryValueA(void *graph)
{
    u32 i = ((u8 *)graph)[0x2b8];
    u32 j = ((u8 *)graph)[0x2b9];
    return *(u16 *)((char *)graph + 0x4a + i * 0xd4 + j * 0xc);
}

/*
 * Element field: u32 at +0x4c of a 12-byte sub-record of record 0xd4.
 *
 * Addresses are Black-image addresses.
 */
u32 RESEARCH_GRAPH_GetEntryValueB(void *graph)
{
    u32 i = ((u8 *)graph)[0x2b8];
    u32 j = ((u8 *)graph)[0x2b9];
    return *(u32 *)((char *)graph + 0x4c + i * 0xd4 + j * 0xc);
}

/*
 * lever: pointer-typed lookup base keeps the original r4/r5 allocation; E44C full body reads only r0/r1 and forwards neither legacy trailing input.
 * F740 tail-forwards to C09B4's pointer getter; E394 tail-forwards to 071CC's returned save block.
 * E44C's full body reads only r0/r1 and has no forwarding calls; legacy two trailing inputs omitted.
 */
u8 RESEARCH_GRAPH_GetFirstSaveGroup(u8 *graph)
{
    u8 bytes[3];
    u8 a,b,c,j;
    void *base;
    int i;
    base=SYMBOL_SAVE_GetBitBlock(GAME_DATA_GetSaveControl((struct GameData *)RESEARCH_GRAPH_GetAppResource(graph)));
    for (i=0;i<3;i++) bytes[i]=MISC_SAVEDATA_GetStatusByte((sptr)base,i);
    b=bytes[1];
    c=bytes[2];
    a=bytes[0];
    for (j=0;j<10;j++) {
        if (a==d_021C363C[j] && b==d_021C3646[j] && c==d_021C3632[j]) return j;
    }
    return 0;
}

u32 RESEARCH_GRAPH_GetEntryIdBySave(u8 *graph)
{
    void *bits;
    u32 index;
    u16 n;
    bits = SYMBOL_SAVE_GetQuestionnaireBits(SYMBOL_SAVE_GetBitBlock(GAME_DATA_GetSaveControl((struct GameData *)RESEARCH_GRAPH_GetAppResource(graph))));
    index = RESEARCH_GRAPH_GetGroupKey(graph);
    if (index == 29) return RESEARCH_GRAPH_GetPlayTimeGroupId(graph);
    n = SYMBOL_SAVE_ReadBitField((const u8 *)bits, index);
    if (n == 0) return 0;
    n--;
    return (u8)GRAPHTABLE_GetEntryId((struct GraphTable *)(graph + 0x38), graph[0x2b8], n);
}

/*
 * extent: trailing 00 00 at 021BF9CA is two-byte alignment padding.
 * prototype: 02012FCC legacy trailing arguments omitted: full 12-byte body only reads r0, then returns its field at 0x6ac; no forwarding.
 * prototype: full 02012FCC body only reads r0, does not forward r1-r3; legacy trailing inputs omitted.
 */
u32 RESEARCH_GRAPH_GetPlayTimeGroupId(u8 *graph)
{
    u32 v = PLAYTIME_GetHours((const struct PlayTime *)GAME_DATA_GetPlayTime((struct GameData *)(RESEARCH_GRAPH_GetAppResource(graph))));
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
u16 RESEARCH_GRAPH_GetSaveBits(u32 graph)
{
    return MISC_SAVEDATA_GetHalfword((const u16 *)SYMBOL_SAVE_GetBitBlock(GAME_DATA_GetSaveControl((struct GameData *)RESEARCH_GRAPH_GetAppResource((u8 *)graph))), RESEARCH_GRAPH_GetGroupKey((void *)graph));
}

u32 RESEARCH_GRAPH_GetClactUnit(void *graph, u32 index)
{
    return *(u32 *)((char *)graph + index * 4 + 0x368);
}

u32 RESEARCH_GRAPH_GetSharedHandle(void *graph, u32 index)
{
    return *(u32 *)((char *)graph + index * 4 + 0x384);
}

u32 RESEARCH_GRAPH_GetMarkerActor(void *graph, u32 index)
{
    return *(u32 *)((char *)graph + index * 4 + 0x394);
}

u32 RESEARCH_GRAPH_Alloc(u32 heapId)
{
    return (uptr)GFL_HEAP_Alloc(heapId, 1000, 0, (const char *)0x21C400C, 4096);
}

void RESEARCH_GRAPH_InitFields(char *graph)
{
    int i;
    ((struct ResearchObjB *)graph)->state = 0;
    ((struct ResearchObjB *)graph)->subState = 0;
    ((struct ResearchObjB *)graph)->stateChanged = 0;
    ((struct ResearchObjB *)graph)->count = 0xf;
    ((struct ResearchObjB *)graph)->stateTimer = 0;
    ((struct ResearchObjB *)graph)->elapsedTimer = 0;
    ((struct ResearchObjB *)graph)->cursorIndex = 0;
    ((struct ResearchObjB *)graph)->drawSystem = 0;
    ((struct ResearchObjB *)graph)->entryShown = 0;
    ((struct ResearchObjB *)graph)->touchSelected = 0;
    ((struct ResearchObjB *)graph)->detailMode = 0;
    ((struct ResearchObjB *)graph)->timerExpired = 0;
    ((struct ResearchObjB *)graph)->updatedFlag = 0;
    ((struct ResearchObjB *)graph)->groupIndex = 0;
    ((struct ResearchObjB *)graph)->entryIndex = 0;
    ((struct ResearchObjB *)graph)->graphKind = 0;
    ((struct ResearchObjB *)graph)->fadeParamU = (uptr)GFL_USE_GetMainTaskList();
    ((struct ResearchObjB *)graph)->percentageCount = 0;
    ((struct ResearchObjB *)graph)->percentageVisible = 0;
    ((struct ResearchObjB *)graph)->active = 0;
    ((struct ResearchObjB *)graph)->visible = 0;
    for (i = 0; i < 7; i++) {
        *(u32 *)(graph + i * 4 + 0x368) = 0;
    }
    RESEARCH_GRAPH_ClearGraphTable((u8 *)graph);
    RESEARCH_GRAPH_ClearCommandQueue(graph);
    RESEARCH_GRAPH_ClearCircles(graph);
    RESEARCH_GRAPH_ClearArrow(graph);
    RESEARCH_GRAPH_ClearPercentages(graph);
    RESEARCH_GRAPH_ClearMessages(graph);
    RESEARCH_GRAPH_ClearWordSet(graph);
    RESEARCH_GRAPH_ClearFont(graph);
    RESEARCH_GRAPH_ClearLabels(graph);
    RESEARCH_GRAPH_ClearUnits(graph);
    RESEARCH_GRAPH_ClearActors(graph);
    RESEARCH_GRAPH_ClearBmps(graph);
    RESEARCH_GRAPH_ClearPalAnm(graph);
    RESEARCH_GRAPH_ClearPaletteAnime(graph);
}

u32 RESEARCH_GRAPH_Free(void *graph)
{
    return GFL_HEAP_Free(graph);
}

/*
 * Clear the u32 at +0x1c.
 *
 * Addresses are Black-image addresses.
 */
void RESEARCH_GRAPH_ClearCommandQueue(void *graph)
{
    ((struct ResearchObjB *)graph)->commandQueue = 0;
}

void RESEARCH_GRAPH_CreateCommandQueue(u32 graph)
{
    ((struct ResearchObjB *)graph)->commandQueue = RingQueue_Create(10, ((struct ResearchObjB *)graph)->heapId);
}

void RESEARCH_GRAPH_DestroyCommandQueue(u8 *graph)
{
    RingQueue_Destroy((void *)((u32)(((struct ResearchObjB *)graph)->commandQueue)));
}

/*
 * Clear the u32 at +8.
 *
 * Addresses are Black-image addresses.
 */
void RESEARCH_GRAPH_ClearFont(void *graph)
{
    ((struct ResearchObjB *)graph)->font = 0;
}

void RESEARCH_GRAPH_CreateFont(u32 graph)
{
    u8 s[4];
    ((struct ResearchObjB *)graph)->font = (uptr)GF_FONT_Create(23, 0, 0, 0, (u32)(((struct ResearchObjB *)graph)->heapId));
}

/*
 * Tail-call veneer: forwards arg(s) (u32)(*(u32*)(a0 + 8)) to GF_FONT_Delete.
 *
 * Addresses are Black-image addresses.
 */
void RESEARCH_GRAPH_DeleteFont(u8 *graph)
{
    GF_FONT_Delete((void *)((u32)(((struct ResearchObjB *)graph)->font)));
}

/*
 * Clear three u32 slots at +0xc.
 *
 * Addresses are Black-image addresses.
 */
void RESEARCH_GRAPH_ClearMessages(void *graph)
{
    int i;
    for (i = 0; i < 3; i++)
        *(u32 *)((char *)graph + i * 4 + 0xc) = 0;
}

void RESEARCH_GRAPH_CreateMessages(MessageView *graph)
{
    int i;
    for (i = 0; i < 3; i++) {
        graph->messages[i] = (uptr)MSGDATA_CreateFromArchive(0, 2, (u16)d_021C3650[i], (u16)graph->heapId);
    }
}

void RESEARCH_GRAPH_DeleteMessages(int *graph)
{
    int i;
    for (i = 0; i < 3; i++)
        MSGDATA_Delete((struct MsgBank *)graph[i + 3]);
}

void RESEARCH_GRAPH_ClearWordSet(void *graph)
{
    ((struct ResearchObjB *)graph)->wordSet = 0;
}

void RESEARCH_GRAPH_CreateWordSet(u32 graph)
{
    ((struct ResearchObjB *)graph)->wordSet = (void *)WORDSET_CreateDefault(((struct ResearchObjB *)graph)->heapId);
}

void RESEARCH_GRAPH_DeleteWordSet(u8 *graph)
{
    WORDSET_Delete((struct WordSet *)((uptr)(((struct ResearchObjB *)graph)->wordSet)));
}

/*
 * Clear two pairs of u32 slots at +0x2bc and +0x2c4.
 *
 * Addresses are Black-image addresses.
 */
void RESEARCH_GRAPH_ClearCircles(void *graph)
{
    int i;
    for (i = 0; i < 2; i++) {
        *(u32 *)((char *)graph + i * 4 + 0x2bc) = 0;
        *(u32 *)((char *)graph + i * 4 + 0x2c4) = 0;
    }
}

void RESEARCH_GRAPH_CreateCircles(char *graph)
{
    int i;
    for (i = 0; i < 2; i++) {
        *(u32 *)(graph + i * 4 + 0x2bc) = (uptr)CircleGraph_Create((unsigned int)(((struct ResearchObjB *)graph)->heapId));
        *(u32 *)(graph + i * 4 + 0x2c4) = (uptr)CircleGraph_Create((unsigned int)(((struct ResearchObjB *)graph)->heapId));
    }
}

void RESEARCH_GRAPH_DestroyCircles(char *graph)
{
    int i;
    for (i = 0; i < 2; i++) {
        CircleGraph_Destroy((void *)(*(u32 *)(graph + i * 4 + 0x2bc)));
        CircleGraph_Destroy((void *)(*(u32 *)(graph + i * 4 + 0x2c4)));
    }
}

/*
 * Tail-call veneer: forwards arg(s) (u32)(a0 + 56), 0, 640 to MI_CpuFill8.
 *
 * Addresses are Black-image addresses.
 */
void RESEARCH_GRAPH_ClearGraphTable(u8 *graph)
{
    MI_CpuFill8((uptr)(graph + 56), 0, 640);
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
void RESEARCH_GRAPH_BuildGraphTable(char *graph)
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
    h = SYMBOL_SAVE_GetBitBlock(GAME_DATA_GetSaveControl((struct GameData *)RESEARCH_GRAPH_GetAppResource((u8 *)graph)));
    first = RESEARCH_GRAPH_GetFirstSaveGroup((u8 *)graph);
    i = 0;
    grp[0] = MISC_SAVEDATA_GetStatusByte((sptr)h, 0);
    grp[1] = MISC_SAVEDATA_GetStatusByte((sptr)h, 1);
    grp[2] = MISC_SAVEDATA_GetStatusByte((sptr)h, 2);
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
            B[i][j] = MISC_SAVEDATA_GetScoreValue((sptr)h, g, j + 1);
        }
    }
    *(u8 *)(graph + 0x38) = first;
    for (k = 0; k < 3; k++) {
        char *q = graph + k * 0xd4;
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

void RESEARCH_GRAPH_InitTouchRects(u8 *graph)
{
    int i;
    for (i = 0; i < 9; i++) {
        graph[i * 4 + 0x300] = d_021C3758[i].x;
        graph[i * 4 + 0x301] = d_021C3758[i].y;
        graph[i * 4 + 0x2fe] = d_021C3758[i].w;
        graph[i * 4 + 0x2ff] = d_021C3758[i].h;
    }
}

/*
 * Clear the u32 at +0x2d0.
 *
 * Addresses are Black-image addresses.
 */
void RESEARCH_GRAPH_ClearArrow(void *graph)
{
    ((struct ResearchObjB *)graph)->arrow = 0;
}

void RESEARCH_GRAPH_CreateArrow(char *graph)
{
    struct ArrowCreateArgs args;
    args.charId = RESEARCH_GRAPH_GetClactUnit(graph, 0);
    args.paletteId = RESEARCH_GRAPH_GetClactUnit(graph, 1);
    args.cellId = RESEARCH_GRAPH_GetClactUnit(graph, 2);
    args.space = 0;
    args.animSeq[0] = 0;
    args.animSeq[1] = 1;
    args.animSeq[2] = 2;
    args.animSeq[3] = 3;
    ((struct ResearchObjB *)graph)->arrow = (void *)ARROW_Create(((struct ResearchObjB *)graph)->heapId, (struct ArrowResources *)(&args));
}

/*
 * Tail-call veneer: forwards arg(s) (u32)(*(u32*)(a0 + 720)), 720 to ARROW_Destroy.
 *
 * Addresses are Black-image addresses.
 */
void RESEARCH_GRAPH_DestroyArrow(u8 *graph)
{
    ARROW_Destroy((void *)(((struct ResearchObjB *)graph)->arrow));
}

/*
 * Clear ten u32 slots at +0x2d4.
 *
 * Addresses are Black-image addresses.
 */
void RESEARCH_GRAPH_ClearPercentages(void *graph)
{
    int i;
    for (i = 0; i < 10; i++)
        *(u32 *)((char *)graph + i * 4 + 0x2d4) = 0;
}

/*
 * lever: p + i * 4 + 0x2d4 keeps the indexed base before the call; p + 0x2d4 + i * 4 differed by 23 bytes.
 */
void RESEARCH_GRAPH_CreatePercentages(char *graph)
{
    struct PercentageCreateArgs args;
    int i;
    args.charIndex = RESEARCH_GRAPH_GetClactUnit(graph, 0);
    args.paletteIndex = RESEARCH_GRAPH_GetClactUnit(graph, 1);
    args.cellAnimIndex = RESEARCH_GRAPH_GetClactUnit(graph, 2);
    args.priority = 0;
    args.digitAnimSeq = 12;
    args.signAnimSeq = 13;
    for (i = 0; i < 10; i++) {
        *(u32 *)(graph + i * 4 + 0x2d4) = PERCENTAGE_Create(((struct ResearchObjB *)graph)->heapId, (struct PercentageTemplate *)(&args), (struct ClactUnit *)(RESEARCH_GRAPH_GetSharedHandle(graph, 3)));
        PERCENTAGE_SetVisible((struct Percentage *)(*(u32 *)(graph + i * 4 + 0x2d4)), 0);
    }
}

void RESEARCH_GRAPH_DestroyPercentages(int *graph)
{
    int i;
    for (i = 0; i < 10; i++)
        PERCENTAGE_Destroy((void *)graph[i + 0xB5]);
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

#include "../arm9/bg_sys_types.h"

struct ResearchGraphConfig { u8 bgLayer, winX, winY, winWidth, winHeight, textX, textY, palette, red, green, blue; u32 centered; };

struct GraphLabelEntry { u8 bgLayer, winX, winY, winWidth, winHeight, textX, textY, palette, red, green, blue; u32 messageIndex, messageMode, centered; };

struct ActorEntry { s16 x,y,z; u8 a,b; u32 sharedHandle, unitA, unitB, unitC; u16 space, pad; };

struct EntryUnit { int x,y,z,bank,index,px,py; u8 r,g,b,pad2; u32 arc,member,enabled; };

extern void BG_SYS_SetGraphicsMode(struct DispConfig *);

extern void BG_SYS_EnableBg0WithPriority(u32);

extern void BG_SYS_InitBgLayer(u32, const struct BgTemplate *, u32);

extern void BG_SYS_SetPlaneVisible(unsigned char which, unsigned char enable);

extern void G2x_SetBlendAlpha_(unsigned int *reg, unsigned int a, unsigned int b, unsigned int c, unsigned int d);

extern u32 BG_SYS_FreeLayerBuf();

extern void CLACT_ReleasePalette(u32 i);

extern struct ClactActor *CLACT_CreateActor(struct Unit *owner, unsigned int i, unsigned int j, unsigned int k, const struct ActorInitParam *position, unsigned short space, unsigned short heap);

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
void RESEARCH_GRAPH_InitOverlayBackgrounds(char *graph)
{
    BG_SYS_SetGraphicsMode(&d_021C366C);
    BG_SYS_EnableBg0WithPriority(2);
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
    G2x_SetBlendAlpha_((u32 *)REG_DB_BLDCNT_ADDR, 2, 1, 7, 15);
    G2x_SetBlendAlpha_((u32 *)REG_BLDCNT_ADDR, 4, 2, 16, 5);
    BMP_WIN_Init(((struct ResearchObjB *)graph)->heapId);
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

void RESEARCH_GRAPH_LoadBackground6(char *graph)
{
    void *out;
    void *h;
    void *blob;
    h = ARC_TOOL_CreateHandle(192, ((struct ResearchObjB *)graph)->heapId);
    blob = ARC_TOOL_LoadHandleMember((struct ArcHandle *)h, 13, ((struct ResearchObjB *)graph)->heapId);
    NNS_G2dGetUnpackedScreenData(blob, &out);
    BG_SYS_DrawTile(6, (uptr)((char *)out + 12), 0, 0, 32, 24);
    BG_SYS_PushTile(6);
    GFL_HEAP_Free((void *)((uptr)blob));
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
 * Tail-call veneer: forwards arg(s) 7, 1, 0 to BG_SYS_FreeTiles.
 *
 * Addresses are Black-image addresses.
 */
void RESEARCH_GRAPH_ShowBackground7()
{
    BG_SYS_FreeTiles(7, 1, 0);
}

/*
 * extent: trailing 00 00 at 021C016E is two-byte alignment padding.
 */
void RESEARCH_GRAPH_LoadBackground2(char *graph)
{
    void *out;
    void *h;
    void *blob;
    h = ARC_TOOL_CreateHandle(192, ((struct ResearchObjB *)graph)->heapId);
    blob = ARC_TOOL_LoadHandleMember((struct ArcHandle *)h, 7, ((struct ResearchObjB *)graph)->heapId);
    NNS_G2dGetUnpackedScreenData(blob, &out);
    BG_SYS_DrawTile(2, (uptr)((char *)out + 12), 0, 0, 32, 32);
    BG_SYS_PushTile(2);
    GFL_HEAP_Free((void *)((uptr)blob));
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
 * Tail-call veneer: forwards arg(s) 3, 1, 0 to BG_SYS_FreeTiles.
 *
 * Addresses are Black-image addresses.
 */
void RESEARCH_GRAPH_ShowBackground3(u32 graph, u32 unusedArg1, u32 unusedArg2)
{
    BG_SYS_FreeTiles(3, 1, 0);
}

/*
 * Clear nine u32 slots at +0x344.
 *
 * Addresses are Black-image addresses.
 */
void RESEARCH_GRAPH_ClearLabels(void *graph)
{
    int i;
    for (i = 0; i < 9; i++)
        *(u32 *)((char *)graph + i * 4 + 0x344) = 0;
}

/*
 * lever: direct indexed assignment computes and spills the destination before allocation; a handle temporary first gave 116 bytes and 47 differing bytes.
 * prototype: keep caller's visible second argument to 021C0F5C despite its legacy one-argument source (021C021C loads r1 before call).
 */
void RESEARCH_GRAPH_CreateLabels(char *graph)
{
    struct ResearchGraphConfig args;
    int i;
    for (i = 0; i < 9; i++) {
        uptr handle;
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
        *(u32 *)(graph + i * 4 + 0x344) = (uptr)BgTextLabel_Create((struct BgTextLabelConfig *)(&args), ((struct ResearchObjB *)graph)->font, *(u32 *)(graph + d_021C3B7C[i].messageIndex * 4 + 12), ((struct ResearchObjB *)graph)->heapId);
        handle = *(u32 *)(graph + i * 4 + 0x344);
        BgTextLabel_PrintMessage((struct BgTextLabel *)handle, d_021C3B7C[i].messageMode);
    }
}

/*
 * Addresses are Black-image addresses.
 */
void RESEARCH_GRAPH_DestroyLabels(int *graph)
{
    int i;
    for (i = 0; i < 9; i++) {
        BgTextLabel_Destroy((struct BgTextLabel *)graph[i + 0xD1]);
        graph[i + 0xD1] = 0;
    }
}

void RESEARCH_GRAPH_RegisterEntryResources(char *graph)
{
    u16 heap = ((struct ResearchObjB *)graph)->heapId;
    void *h = ARC_TOOL_CreateHandle(192, heap);
    int a = CLACT_RegisterCharacter((void *)((uptr)h), 15, 0, 1, heap);
    int b = CLACT_RegisterPalette((void *)h, 16, 1, 0, heap);
    int c = CLACT_RegisterCellAnim((void *)((uptr)h), 14, 17, heap);
    ((struct ResearchObjB *)graph)->clactUnits[4] = a;
    ((struct ResearchObjB *)graph)->clactUnits[5] = b;
    ((struct ResearchObjB *)graph)->clactUnits[6] = c;
    ARC_TOOL_DeleteHandle(h);
}

u32 RESEARCH_GRAPH_ReleaseEntryResources(u32 graph)
{
    CLACT_ReleaseCharacter(((struct ResearchObjB *)(((u8*)graph)))->clactUnits[4]);
    CLACT_ReleasePalette(((struct ResearchObjB *)(((u8*)graph)))->clactUnits[5]);
    return CLACT_ReleaseCellAnim(((struct ResearchObjB *)(((u8*)graph)))->clactUnits[6]);
}

void RESEARCH_GRAPH_RegisterCursorResources(char *graph)
{
    u16 heap = ((struct ResearchObjB *)graph)->heapId;
    void *h = ARC_TOOL_CreateHandle(192, heap);
    int a = CLACT_RegisterCharacter((void *)((uptr)h), 15, 0, 0, heap);
    int b = CLACT_RegisterPaletteEx((void *)((uptr)h), 16, 0, 192, 0, 3, heap);
    int c = CLACT_RegisterCellAnim((void *)((uptr)h), 14, 17, heap);
    int d;
    ARC_TOOL_DeleteHandle(h);
    h = ARC_TOOL_CreateHandle(83, heap);
    d = CLACT_RegisterPaletteEx((void *)((uptr)h), 31, 0, 128, 0, 2, heap);
    ARC_TOOL_DeleteHandle(h);
    ((struct ResearchObjB *)graph)->clactUnits[0] = a;
    ((struct ResearchObjB *)graph)->clactUnits[1] = b;
    ((struct ResearchObjB *)graph)->clactUnits[3] = d;
    ((struct ResearchObjB *)graph)->clactUnits[2] = c;
}

u32 RESEARCH_GRAPH_ReleaseCursorResources(u32 graph)
{
    CLACT_ReleaseCharacter(((struct ResearchObjB *)(((u8*)graph)))->clactUnits[0]);
    CLACT_ReleasePalette(((struct ResearchObjB *)(((u8*)graph)))->clactUnits[1]);
    CLACT_ReleasePalette(((struct ResearchObjB *)(((u8*)graph)))->clactUnits[3]);
    return CLACT_ReleaseCellAnim(((struct ResearchObjB *)(((u8*)graph)))->clactUnits[2]);
}

void RESEARCH_GRAPH_ClearUnits(void *graph)
{
    int i;
    for (i = 0; i < 4; i++)
        *(u32 *)((char *)graph + i * 4 + 0x384) = 0;
}

void RESEARCH_GRAPH_CreateUnits(u8 *graph)
{
    int i;
    for (i = 0; i < 4; i++)
        *(int *)(graph + i * 4 + 0x384) = (sptr)CLACT_CreateUnit(d_021C3620[i], d_021C3618[i], ((struct ResearchObjB *)graph)->heapId);
}

void RESEARCH_GRAPH_DeleteUnits(int *graph)
{
    int i;
    for (i = 0; i < 4; i++)
        CLACT_DeleteUnit((struct Unit *)graph[i + 0xE1]);
}

/*
 * Clear four u32 slots at +0x394.
 *
 * Addresses are Black-image addresses.
 */
void RESEARCH_GRAPH_ClearActors(void *graph)
{
    int i;
    for (i = 0; i < 4; i++)
        *(u32 *)((char *)graph + i * 4 + 0x394) = 0;
}

/*
 * prototype: 0204B294 result observed in r0 despite legacy matched void return.
 */
void RESEARCH_GRAPH_CreateActors(u8 *graph)
{
    struct Arg arg;
    const struct ActorEntry *q;
    u8 *dest;
    int i;
    uptr a; u32 b, c, d;
    for(i=0;i<4;i++) {
        q=&d_021C37FC[i];
        arg.x=q->x; arg.y=q->y; arg.z=q->z; arg.a=q->a; arg.b=q->b;
        a=RESEARCH_GRAPH_GetSharedHandle(graph,q->sharedHandle);
        b=RESEARCH_GRAPH_GetClactUnit(graph,q->unitA);
        c=RESEARCH_GRAPH_GetClactUnit(graph,q->unitB);
        d=RESEARCH_GRAPH_GetClactUnit(graph,q->unitC);
        dest=graph+i*4;
        *(u32 *)&((struct ResearchObjB *)dest)->markerActorA=(uptr)CLACT_CreateActor((void *)a,b,c,d,(struct ActorInitParam *)(&arg),q->space,((struct ResearchObjB *)graph)->heapId);
        CLACT_SetActorDrawEnable((struct ClactActor *)(*(struct Obj * *)&((struct ResearchObjB *)dest)->markerActorA),0);
    }
}

void RESEARCH_GRAPH_DeleteActors(int *graph)
{
    int i;
    for (i = 0; i < 4; i++)
        CLACT_DeleteActor((struct ClactActor *)graph[i + 0xE5]);
}

/*
 * Clear two u32 slots at +0x3b0.
 *
 * Addresses are Black-image addresses.
 */
void RESEARCH_GRAPH_ClearBmps(void *graph)
{
    int i;
    for (i = 0; i < 2; i++)
        *(u32 *)((char *)graph + i * 4 + 0x3b0) = 0;
}

void RESEARCH_GRAPH_CreateBmps(u8 *graph)
{
    int i;
    for (i = 0; i < 2; i++)
        *(int *)(graph + i * 4 + 0x3B0) = (sptr)BMP_Create(d_021C37A4[i].x, d_021C37A4[i].y, d_021C37A4[i].z, ((struct ResearchObjB *)graph)->heapId);
}

void RESEARCH_GRAPH_DrawBmps(u8 *graph)
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
            bmp=BMP_CreateFromArchive(q->arc,q->member,0,((struct ResearchObjB *)graph)->heapId);
            dest=graph+i*4;
            BMP_Blit(bmp,*(struct Bmp * *)&((struct ResearchObjB *)dest)->bmps[0],0,0,0,0,q->x<<3,q->y<<3,q->b);
            color=((q->r&31)<<10)|((q->g&31)<<5)|(q->b&31);
            text=MSGDATA_AllocString(*(struct MsgBank **)(graph+12+q->bank*4),q->index);
            PRINTSYS_PrintColor(((struct ResearchObjB *)dest)->bmps[0],q->px,q->py,text,(void *)((struct ResearchObjB *)graph)->font,color);
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

extern struct BmpOamSys *BMP_OAM_CreateSys(unsigned int heapId, void *clact);

struct GameComm;

extern struct GameComm *GAMESYSTEM_GetGameComm(struct GameSystem *gameSystem);

extern void GAME_COMM_RequestExitNoCallback(struct GameComm *comm);

extern u32 GAME_COMM_GetKind(struct GameComm *comm);

extern void GAME_COMM_SetNotifyFlag(struct GameComm *comm, unsigned int flag);

extern const struct Tab d_021C3C54;

extern const struct EntryUnit d_021C37D0;

extern const struct OamObjectRow d_021C377C[];

extern const struct PaletteAnimeBind d_021C3A28[];

void RESEARCH_GRAPH_DrawBadge(u8 *graph)
{
    struct Tab tab = d_021C3C54;
    int i;
    int j;
    struct Bmp *bmp;
    void *text;
    u16 color;
    u32 gb = (uptr)&d_021C37D0;
    bmp = BMP_CreateFromArchive(E->arc, E->member, 0, *(u16 *)(graph + 4));
    for (i = 0; i < 3; i++) {
        int y = i * 8;
        for (j = 0; j < 20; j++) {
            BMP_Blit(bmp, *(struct Bmp **)(graph + 0x3B4), (tab.rows[i].cells[j] % 3) * 8, (tab.rows[i].cells[j] / 3) * 8, j * 8, y, 8, 8, 0);
        }
    }
    BMP_Delete((struct Bmp *)bmp);
    color = ((E->r & 31) << 10) | ((E->g & 31) << 5) | (E->b & 31);
    text = MSGDATA_AllocString(*(struct MsgBank **)(graph + 12 + E->bank * 4), E->index);
    PRINTSYS_PrintColor(*(void **)(graph + 0x3B4), E->px, E->py, text, *(void **)(graph + 8), color);
    GFL_HEAP_Free(text);
}

void RESEARCH_GRAPH_DeleteBmps(int *graph)
{
    int i;
    for (i = 0; i < 2; i++)
        BMP_Delete((struct Bmp *)graph[i + 0xEC]);
}

void RESEARCH_GRAPH_CreateOamSys(u8 *graph)
{
    ((struct ResearchObjB *)graph)->oamSys = (uptr)BMP_OAM_CreateSys((unsigned int)(((struct ResearchObjB *)graph)->heapId), (void *)(((struct ResearchObjB *)graph)->units[2]));
}

void RESEARCH_GRAPH_DeleteOamSys(u8 *graph)
{
    BMP_OAM_DeleteSys((void *)((u32)(((struct ResearchObjB *)graph)->oamSys)));
}

/*
 * note 2026-10-05 (wave D9r lane 131): removed the 4 dead first assignments
 * (`sysOff=0x3B0;` before `sysOff=0x3A4;`; `outOff=0x3B0;` before
 * `outOff=0x3A8;` and 2 more). Game code has no line table, so these were
 * stand-ins. The plain single assignment gives EXACT in --lang c99 and
 * --lang c: the output bytes do not change. Older text in this header that
 * asks for the double assignment is superseded.
 */
void RESEARCH_GRAPH_CreateOamObjects(u8 *graph)
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
        dest=graph+i*4;
        param.bmp=((struct ResearchObjB *)dest)->bmps[0];
        q=&d_021C377C[i];
        param.x=q->x; param.y=q->y;
        param.animResId=RESEARCH_GRAPH_GetClactUnit(graph,q->clactUnitIndex);
        param.palette=q->palette;
        param.drawPriority=q->drawPriority; param.bgPriority=q->bgPriority;
        param.space=q->space; param.engine=q->engine;
        *(struct Grid **)(dest+outOff)=(struct Grid *)BMP_OAM_Create(*(struct BmpOamSys **)(graph+sysOff),(struct BmpOamParam *)(&param));
        BMP_OAM_SetEnabled((struct BmpOam *)(*(u8 **)(dest+callOff)),0);
        BMP_OAM_UploadChars((struct BmpOam *)(*(struct Obj **)(dest+uploadOff)));
    }
}

/*
 * Addresses are Black-image addresses.
 */
void RESEARCH_GRAPH_DeleteOamObjects(int *graph)
{
    int i;
    for (i = 0; i < 2; i++)
        BMP_OAM_Delete((struct BmpOam *)graph[i + 0xEA]);
}

/*
 * Clear the u32 at +0x3b8.
 *
 * Addresses are Black-image addresses.
 */
void RESEARCH_GRAPH_ClearPalAnm(void *graph)
{
    ((struct ResearchObjB *)graph)->palAnm = 0;
}

void RESEARCH_GRAPH_CreatePalAnm(u8 *graph)
{
    ((struct ResearchObjB *)graph)->palAnm = PALANM_Create(((struct ResearchObjB *)graph)->heapId);
    PALANM_AllocSlotBuffers(((struct ResearchObjB *)graph)->palAnm, 0, 512, ((struct ResearchObjB *)graph)->heapId);
    PALANM_AllocSlotBuffers(((struct ResearchObjB *)graph)->palAnm, 2, 512, ((struct ResearchObjB *)graph)->heapId);
    PALANM_CopyHwPaletteToSlot(((struct ResearchObjB *)graph)->palAnm, 0, 0, 512);
    PALANM_CopyHwPaletteToSlot(((struct ResearchObjB *)graph)->palAnm, 2, 0, 512);
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
u32 RESEARCH_GRAPH_DeletePalAnm(u32 graph)
{
    PALANM_FreeSlotBuffers((struct PaletteFade *)(((struct ResearchObjB *)(((u8*)graph)))->palAnm), 0);
    PALANM_FreeSlotBuffers((struct PaletteFade *)(((struct ResearchObjB *)(((u8*)graph)))->palAnm), 2);
    return PALANM_Delete((void *)(((struct ResearchObjB *)(((u8*)graph)))->palAnm));
}

void RESEARCH_GRAPH_ClearPaletteAnime(void *graph)
{
    int i;
    for (i = 0; i < 8; i++)
        *(u32 *)((char *)graph + i * 4 + 0x324) = 0;
}

void RESEARCH_GRAPH_CreatePaletteAnime(u8 *graph)
{
    int i;
    for (i = 0; i < 8; i++)
        *(int *)(graph + i * 4 + 0x324) = PALETTE_ANIME_Create(((struct ResearchObjB *)graph)->heapId);
}

void RESEARCH_GRAPH_DestroyPaletteAnime(int *graph)
{
    int i;
    for (i = 0; i < 8; i++)
        PALETTE_ANIME_Destroy((void *)graph[i + 0xC9]);
}

void RESEARCH_GRAPH_BindPaletteAnime(u8 *graph)
{
    int i;
    for (i = 0; i < 8; i++)
        PALETTE_ANIME_Bind((void *)(*(int *)(graph + i * 4 + 0x324)), (unsigned short *)d_021C3A28[i].palette, (unsigned short *)d_021C3A28[i].original, d_021C3A28[i].colorCount);
}

void RESEARCH_GRAPH_RestorePaletteAnime(int *graph)
{
    int i;
    for (i = 0; i < 8; i++)
        PALETTE_ANIME_Restore((struct PaletteAnime *)graph[i + 0xC9]);
}

/*
 * Reconstructed from the listing.
 *
 * Addresses are Black-image addresses.
 */
void RESEARCH_GRAPH_RestartNetwork(u32 graph)
{
    GFL_NET_RefreshWmIconAtTopRight(1, ((struct ResearchObjB *)(((u8*)graph + 0)))->heapId);
}

void RESEARCH_GRAPH_RegisterVBlank(char *graph)
{
    ((struct ResearchObjB *)graph)->vblankNode = (uptr)GFL_USE_AddMainTask((void (*)(void))RESEARCH_GRAPH_TransferPalettes, graph, (unsigned int)0);
}

/*
 * Tail-call veneer: forwards arg(s) (u32)(*(u32*)(a0 + 960)), 960 to TCB_DeleteTask.
 *
 * Addresses are Black-image addresses.
 */
void RESEARCH_GRAPH_UnregisterVBlank(u8 *graph)
{
    TCB_DeleteTask((struct TcbTask *)((u32)(((struct ResearchObjB *)graph)->vblankNode)));
}

u32 RESEARCH_GRAPH_ClampByte(s32 value)
{
    if (value < 0)
        return 0;
    if (value > 0xff)
        return 0xff;
    return (u8)value;
}

/*
 * Opens the +0x10 record (GAMESYSTEM_GetGameComm on the result of RESEARCH_GRAPH_GetContext),
 * tags it with 1, and releases it when GAME_COMM_GetKind reports state 2.
 * Closed by the generator's duplicate guard statement (O89).
 *
 * Addresses are Black-image addresses.
 */
void RESEARCH_GRAPH_OpenComm(u8 *graph)
{
    u32 comm = (uptr)GAMESYSTEM_GetGameComm((struct GameSystem *)RESEARCH_GRAPH_GetContext(graph));
    GAME_COMM_SetNotifyFlag((void *)comm, 1);
    if (GAME_COMM_GetKind((void *)comm) == 2) {
    GAME_COMM_RequestExitNoCallback((struct GameComm *)comm);
    }
}

int RESEARCH_GRAPH_GetCommKindOrStart(u8 *graph)
{
    uptr r;
    r = RESEARCH_GRAPH_GetContext(graph);
    switch (GAME_COMM_GetKind((void *)GAMESYSTEM_GetGameComm((struct GameSystem *)r))) {
    case 0:
        GAMESYSTEM_TryStartAutoComm((struct GameSystem *)r);
        return 1;
    default:
        return 1;
    case 2:
        return 0;
    }
}

void RESEARCH_GRAPH_ClearNotifyFlag(unsigned char *graph)
{
    GAME_COMM_SetNotifyFlag((void *)GAMESYSTEM_GetGameComm((struct GameSystem *)RESEARCH_GRAPH_GetContext(graph)), 0);
}
