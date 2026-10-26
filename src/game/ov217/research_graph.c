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
#include "../arm9/gfl_use.h"
#include "../sdk_ioreg.h"
#include "../arm9/palanm.h"
#include "../arm9/touchpanel.h"
#include "../arm9/bmp_oam.h"
struct ResearchGraphBg {
    unsigned int a;
    unsigned int b;
    unsigned int c;
    unsigned int d;
    unsigned char e;
    unsigned char f;
    unsigned char g;
    unsigned char h;
    unsigned int i;
    unsigned char j;
    unsigned char k;
    unsigned char l;
    unsigned char m;
    unsigned int n;
};
#include "research_shared_types.h"
#include "research_graph_table.h"


struct WordSet;

struct PlayTime;

struct ResearchObjB {
    struct ResearchCommon *owner;
    u16 heapId;
    u8 pad6[0x2];
    struct GfFont *font;
    struct MsgBank *msgBank[3];            /* 0x0C */
    struct WordSet *wordSet;
    struct RingQueue *commandQueue;
    u32 state;
    u32 subState;
    u32 stateTimer;
    u32 count;
    u32 elapsedTimer;
    union { u32 cursorIndex; int cursorIndexSigned; };
    struct GraphTable table;                /* 0x38: header[0] is the title group */
    u8 groupIndex;
    u8 entryIndex;
    u8 pad2BA[0x2];
    struct CircleGraph *leftCircle[2];      /* 0x2BC */
    struct CircleGraph *rightCircle[2];     /* 0x2C4 */
    u32 graphKind;
    struct Arrow *arrow;
    struct Percentage *percentage[10];      /* 0x2D4 */
    u8 percentageCount;
    u8 percentageVisible;
    u8 touchRects[0x26];                    /* 0x2FE: nine 4-byte rects */
    struct PaletteAnime *paletteAnime[8];   /* 0x324 */
    struct BgTextLabel *label[9];           /* 0x344: 1 title, 2 group, 3 kind, 4 slice, 5 time, 6 team, 7 empty, 8 detail */
    u32 clactUnits[7];
    struct Unit *units[4];
    struct ClactActor *actor[4];            /* 0x394: marker A, marker B, triangle, marker */
    struct BmpOamSys *oamSys;
    struct BmpOam *oamObject[2];
    struct Bmp *bmps[2];
    void * palAnm;
    union { void * fadeParam; u32 fadeParamU; };
    struct TcbTask *vblankNode;
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


struct CursorRect { u8 x, y, w, h; };

struct ArrowCreateArgs { u32 charId; u32 paletteId; u32 cellId; u16 space; u16 animSeq[4]; };

struct PercentageCreateArgs { u32 charIndex; u32 paletteIndex; u32 cellAnimIndex; u16 priority; u16 digitAnimSeq; u16 signAnimSeq; };
struct GameSystem;

#include "../arm9/gamesystem.h"

#include "../arm9/net.h"



#include "../arm9/gfl_heap_wrap.h"

#include "../arm9/nns_g2d_load.h"

#include "../arm9/bg_sys.h"



struct ResearchCommon;

#include "research_common.h"


extern void CLACT_DrawSystem();

#include "../arm9/key.h"



extern void GFL_USE_PlaySeDefaultVolume(u32 a);

#include "../arm9/fade.h"


struct RingQueue;

#include "queue.h"






#include "../arm9/game_beacon.h"

struct Actor;

extern void CLACT_SetActorDrawEnable(struct ClactActor *actor, unsigned int value);

extern void CLACT_SetActorAutoAnim(struct ClactActor *actor, unsigned int enable);

struct PaletteAnime;







#include "../arm9/gf_font.h"


#include "../arm9/msgdata.h"




#include "../arm9/bmp_win.h"




struct BgTextLabelConfig;
struct BgTextLabel;

#include "bg_font.h"



extern s32 CLACT_RegisterCharacter(void *a, u32 b, u32 c, u32 vram_mode, u16 flags);

extern s32 CLACT_RegisterPalette(void *a, u32 b, u32 c, u32 d, u16 g);

extern s32 CLACT_RegisterCellAnim(void *owner, u32 first, u32 second, u32 mode);

extern void CLACT_ReleaseCharacter(u32 i);

extern void CLACT_ReleaseCellAnim(u32 handle);

extern s32 CLACT_RegisterPaletteEx(void *a, u32 b, u32 c, u32 d, u16 e, u16 f, u16 g);

extern struct Unit *CLACT_CreateUnit(int count, u8 flag, u32 heapId);

extern u32 CLACT_DeleteUnit(struct Unit *bank);

extern void CLACT_DeleteActor(struct ClactActor *actor);





extern void CLACT_VBlankSystem(void);

struct GameData;
struct SaveControl;

#include "../arm9/game_data.h"

#include "../arm9/symbol_save.h"

#include "../arm9/misc_savedata.h"
struct BmpOam;


extern void CLACT_AddActorSurfacePos(struct ClactActor *p,const struct ClactVec2 *delta,u32 which);





#include "palette_anime.h"



struct TcbList;

extern struct TcbList *GFL_USE_GetMainTaskList(void);

#include "../arm9/bmp.h"


struct Strbuf;


/* The DS code was built against other parameter widths for PRINTSYS_PrintColor (the original prototypes); the header differs. The host build uses the header. */
#ifdef __MWERKS__
extern void PRINTSYS_PrintColor(struct Bmp *bmp, short x, short y, struct Strbuf *str, struct GfFont *font, unsigned short color);
#else
#include "../arm9/printsys.h"
#endif
struct BmpOamSys;








struct TcbTask;

struct TcbTask;

#include "../arm9/tcb_list.h"
struct Arrow;

#include "arrow.h"

void RESEARCH_GRAPH_InitOverlayBackgrounds(struct ResearchObjB *graph);

void RESEARCH_GRAPH_LoadBackground6(struct ResearchObjB *graph);

void RESEARCH_GRAPH_UpdateBackground7();

void RESEARCH_GRAPH_LoadBackground2(struct ResearchObjB *graph);

void RESEARCH_GRAPH_UpdateBackground3();

void RESEARCH_GRAPH_CreateLabels(struct ResearchObjB *graph);

void RESEARCH_GRAPH_RegisterEntryResources(struct ResearchObjB *graph);

void RESEARCH_GRAPH_RegisterCursorResources(struct ResearchObjB *graph);

void RESEARCH_GRAPH_CreateUnits(struct ResearchObjB *graph);

void RESEARCH_GRAPH_CreateActors(struct ResearchObjB *graph);

void RESEARCH_GRAPH_CreateBmps(struct ResearchObjB *graph);

void RESEARCH_GRAPH_DrawBmps(struct ResearchObjB *graph);

void RESEARCH_GRAPH_DrawBadge(struct ResearchObjB *graph);

void RESEARCH_GRAPH_CreateOamSys(struct ResearchObjB *graph);

void RESEARCH_GRAPH_CreateOamObjects(struct ResearchObjB *graph);

void RESEARCH_GRAPH_CreatePalAnm(struct ResearchObjB *graph);

void RESEARCH_GRAPH_CreatePaletteAnime(struct ResearchObjB *graph);

void RESEARCH_GRAPH_BindPaletteAnime(struct ResearchObjB *graph);

void RESEARCH_GRAPH_RegisterVBlank(struct ResearchObjB *graph);

void RESEARCH_GRAPH_RestartNetwork(struct ResearchObjB *graph);

void RESEARCH_GRAPH_OpenComm(struct ResearchObjB *graph);

int RESEARCH_GRAPH_GetCommKindOrStart(struct ResearchObjB *graph);

extern int GFL_USE_IsAnySeBusy(void);
struct CircleGraph;

#include "circle_graph.h"



void RESEARCH_GRAPH_ExitOverlayBackgrounds();

void RESEARCH_GRAPH_DummyBg7();

void RESEARCH_GRAPH_ShowBackground7();

void RESEARCH_GRAPH_DummyBg3();

void RESEARCH_GRAPH_ShowBackground3();

void RESEARCH_GRAPH_DestroyLabels(struct ResearchObjB *graph);

void RESEARCH_GRAPH_ReleaseEntryResources(struct ResearchObjB *graph);

void RESEARCH_GRAPH_ReleaseCursorResources(struct ResearchObjB *graph);

void RESEARCH_GRAPH_DeleteUnits(struct ResearchObjB *graph);

void RESEARCH_GRAPH_DeleteActors(struct ResearchObjB *graph);

void RESEARCH_GRAPH_DeleteBmps(struct ResearchObjB *graph);

void RESEARCH_GRAPH_DeleteOamSys(struct ResearchObjB *graph);

void RESEARCH_GRAPH_DeleteOamObjects(struct ResearchObjB *graph);

u32 RESEARCH_GRAPH_DeletePalAnm(struct ResearchObjB *graph);

void RESEARCH_GRAPH_DestroyPaletteAnime(struct ResearchObjB *graph);

void RESEARCH_GRAPH_RestorePaletteAnime(struct ResearchObjB *graph);

void RESEARCH_GRAPH_UnregisterVBlank(struct ResearchObjB *graph);

void RESEARCH_GRAPH_ClearNotifyFlag(struct ResearchObjB *graph);




struct GraphTable;

#include "graph_table.h"


struct CircleGraphInput;













struct Percentage;

#include "percentage.h"



u32 RESEARCH_GRAPH_ClampByte(s32 v);


#include "../arm9/strbuf.h"


#include "../arm9/wordset.h"



extern void CLACT_SetActorAnimLoopCount(struct ClactActor *,unsigned);


struct SymbolBitSave;





#include "../arm9/playtime.h"


void RESEARCH_GRAPH_ClearLabels(struct ResearchObjB *graph);

void RESEARCH_GRAPH_ClearUnits(struct ResearchObjB *graph);

void RESEARCH_GRAPH_ClearActors(struct ResearchObjB *graph);

void RESEARCH_GRAPH_ClearBmps(struct ResearchObjB *graph);

void RESEARCH_GRAPH_ClearPalAnm(struct ResearchObjB *graph);

void RESEARCH_GRAPH_ClearPaletteAnime(struct ResearchObjB *graph);





#include "../arm9/mi_memory.h"



struct ArrowResources;


struct ClactUnit;
struct PercentageTemplate;



#include "../arm9/g3x.h"



void *RESEARCH_GRAPH_Create(void *p);

u32 RESEARCH_GRAPH_Destroy(struct ResearchObjB *graph);

void RESEARCH_GRAPH_Update(struct ResearchObjB *graph);

u32 RESEARCH_GRAPH_GetVisible(struct ResearchObjB *graph);

u32 RESEARCH_GRAPH_GetActive(struct ResearchObjB *graph);

void RESEARCH_GRAPH_Init(struct ResearchObjB *graph);

void RESEARCH_GRAPH_UpdateIntro(struct ResearchObjB *graph);

void RESEARCH_GRAPH_HandleInput(struct ResearchObjB *graph);

void RESEARCH_GRAPH_HandleInputAlt(struct ResearchObjB *graph);

void RESEARCH_GRAPH_EnterDrawSlow(struct ResearchObjB *graph);

void RESEARCH_GRAPH_StepAnimation(struct ResearchObjB *graph);

void RESEARCH_GRAPH_EnterFadeIn(struct ResearchObjB *graph);

void RESEARCH_GRAPH_EnterFadeOut(struct ResearchObjB *graph);

void RESEARCH_GRAPH_EnterDrawMedium(struct ResearchObjB *graph);

void RESEARCH_GRAPH_EnterDrawMediumAlt(struct ResearchObjB *graph);

void RESEARCH_GRAPH_ExitFade(struct ResearchObjB *graph);

void RESEARCH_GRAPH_AdvanceWhileActive(struct ResearchObjB *graph);

void RESEARCH_GRAPH_Cleanup(struct ResearchObjB *graph);

void RESEARCH_GRAPH_SetStateChanged(struct ResearchObjB *graph);

void RESEARCH_GRAPH_SetEntryHandled(struct ResearchObjB *graph, u32 handled);

void RESEARCH_GRAPH_SetActive(struct ResearchObjB *graph, u32 active);

u32 RESEARCH_GRAPH_GetCount(struct ResearchObjB *graph);

u32 RESEARCH_GRAPH_GetTransitionKind(struct ResearchObjB *graph);

void RESEARCH_GRAPH_IncTimer(struct ResearchObjB *graph);

void RESEARCH_GRAPH_PushCommand(struct ResearchObjB *graph, u32 command);

void RESEARCH_GRAPH_ProcessCommand(struct ResearchObjB *graph);

void RESEARCH_GRAPH_StartSubState(struct ResearchObjB *graph, u32 state);

u32 RESEARCH_GRAPH_GetSubState(struct ResearchObjB *graph);

void RESEARCH_GRAPH_IncSubState(struct ResearchObjB *graph);

void RESEARCH_GRAPH_SelectPrev(struct ResearchObjB *graph);

void RESEARCH_GRAPH_SelectNext(struct ResearchObjB *graph);

void RESEARCH_GRAPH_SelectDirect(struct ResearchObjB *graph, u32 index);

void RESEARCH_GRAPH_ApplySelection(struct ResearchObjB *graph, u32 index);

void RESEARCH_GRAPH_MoveGroupBackward(struct ResearchObjB *graph);

void RESEARCH_GRAPH_MoveGroupForward(struct ResearchObjB *graph);

void RESEARCH_GRAPH_MoveEntryForward(struct ResearchObjB *graph);

void RESEARCH_GRAPH_MoveEntryBackward(struct ResearchObjB *graph);

void RESEARCH_GRAPH_MoveToFirstEntry(struct ResearchObjB *graph);

void RESEARCH_GRAPH_MoveToSelectedEntry(struct ResearchObjB *graph);

void RESEARCH_GRAPH_ToggleEntry(struct ResearchObjB *graph);

void RESEARCH_GRAPH_FadeIn(void);

void RESEARCH_GRAPH_FadeOut(void);

void RESEARCH_GRAPH_CycleIndex(struct ResearchObjB *graph, int delta);

void RESEARCH_GRAPH_SetIndex(struct ResearchObjB *graph, u32 index);

void RESEARCH_GRAPH_DrawIndexCursor(struct ResearchObjB *graph);

void RESEARCH_GRAPH_DrawIndexCursorDim(struct ResearchObjB *graph);

void RESEARCH_GRAPH_CycleGroup(struct ResearchObjB *graph, int delta);

void RESEARCH_GRAPH_SetEntryFromSlice(struct ResearchObjB *graph);

void RESEARCH_GRAPH_StepEntry(struct ResearchObjB *graph, int step);

void RESEARCH_GRAPH_ClearEntryIndex(struct ResearchObjB *graph);

void RESEARCH_GRAPH_SyncArrow(struct ResearchObjB *graph);

void RESEARCH_GRAPH_SetHighlightSelected(struct ResearchObjB *graph);

void RESEARCH_GRAPH_SetHighlightA(struct ResearchObjB *graph);

void RESEARCH_GRAPH_SetHighlightB(struct ResearchObjB *graph);

void RESEARCH_GRAPH_SetHighlightC(struct ResearchObjB *graph);

void RESEARCH_GRAPH_SetNormalA(struct ResearchObjB *graph);

void RESEARCH_GRAPH_SetNormalB(struct ResearchObjB *graph);

void RESEARCH_GRAPH_StartPaletteAnime(struct ResearchObjB *graph);

void RESEARCH_GRAPH_SwapCenterPairs(struct ResearchObjB *graph);

void RESEARCH_GRAPH_QuantizePosition(struct GraphSliceInput *input);

void RESEARCH_GRAPH_SetCenterDepth(struct ResearchObjB *graph);

void RESEARCH_GRAPH_SetSlicesFromGraphA(struct ResearchObjB *graph,int mode);

void RESEARCH_GRAPH_SetSlicesFromGraphB(struct ResearchObjB *graph, u32 mode);

void RESEARCH_GRAPH_UpdateCircles(struct ResearchObjB *graph);

void RESEARCH_GRAPH_DrawCircles(struct ResearchObjB *graph);

void RESEARCH_GRAPH_DrawSliceColor(struct ResearchObjB *graph);

void RESEARCH_GRAPH_LayoutArrow(struct ResearchObjB *graph);

void RESEARCH_GRAPH_UpdatePercentages(struct ResearchObjB *graph);

void RESEARCH_GRAPH_HideAllPercentages(struct ResearchObjB *graph);

void RESEARCH_GRAPH_ShowPercent(struct ResearchObjB *graph, u32 index);

void RESEARCH_GRAPH_ShowPercentages(struct ResearchObjB *graph);

void RESEARCH_GRAPH_LayoutTouchRects(struct ResearchObjB *graph);

void RESEARCH_GRAPH_LoadBackground(struct ResearchObjB *graph);

void RESEARCH_GRAPH_PrintTitle(struct ResearchObjB *graph);

void RESEARCH_GRAPH_PrintGroupLabel(struct ResearchObjB *graph);

void RESEARCH_GRAPH_PrintKindLabel(struct ResearchObjB *graph);

void RESEARCH_GRAPH_PrintSliceLabel(struct ResearchObjB *graph);

void RESEARCH_GRAPH_PrintTimeLabel(struct ResearchObjB *graph);

void RESEARCH_GRAPH_PrintTeamLabel(struct ResearchObjB *graph);

void RESEARCH_GRAPH_SetTeamLabelVisible(struct ResearchObjB *graph);

void RESEARCH_GRAPH_SetDetailLabelVisible(struct ResearchObjB *graph);

void RESEARCH_GRAPH_LayoutActors(struct ResearchObjB *graph);

void RESEARCH_GRAPH_SetTriangleActorVisible(struct ResearchObjB *graph);

void RESEARCH_GRAPH_LayoutMarkerActor(struct ResearchObjB *graph);

void RESEARCH_GRAPH_EnableOams(struct ResearchObjB *graph);

void RESEARCH_GRAPH_EnableOamsA(struct ResearchObjB *graph);

void RESEARCH_GRAPH_DisableOams(struct ResearchObjB *graph);

void RESEARCH_GRAPH_SetOamEnabled(struct ResearchObjB *graph, u32 index, u32 enabled);

void RESEARCH_GRAPH_StartSlotPaletteAnime(struct ResearchObjB *graph, int slot);

void RESEARCH_GRAPH_StopSlotPaletteAnime(struct ResearchObjB *graph, u32 slot);

u32 RESEARCH_GRAPH_IsSlotPaletteAnimeRunning(struct ResearchObjB *graph, u32 slot);

void RESEARCH_GRAPH_UpdateSlotPalettes(struct ResearchObjB *graph);

void RESEARCH_GRAPH_UpdatePaletteAnime(struct ResearchObjB *graph);

void RESEARCH_GRAPH_RequestFadeIn(struct ResearchObjB *graph);

void RESEARCH_GRAPH_RequestFadeOut(struct ResearchObjB *graph);

u32 RESEARCH_GRAPH_IsFadeDone(struct ResearchObjB *graph);

void RESEARCH_GRAPH_TransferPalettes(struct TcbTask *unusedArg, void *graphArg);

void RESEARCH_GRAPH_CheckQuestionnaireUpdated(struct ResearchObjB *graph);

void RESEARCH_GRAPH_ClearUpdatedFlag(struct ResearchObjB *graph);

void RESEARCH_GRAPH_TickTimer(struct ResearchObjB *graph);

void RESEARCH_GRAPH_ResetTimer(struct ResearchObjB *graph);

const struct Ctx *RESEARCH_GRAPH_GetContext(struct ResearchObjB *graph);

void *RESEARCH_GRAPH_GetAppResource(struct ResearchObjB *graph);

void RESEARCH_GRAPH_SetHeapId(struct ResearchObjB *graph, u32 heapId);

struct ResearchCommon *RESEARCH_GRAPH_GetOwner(struct ResearchObjB *graph);

void RESEARCH_GRAPH_SetOwner(struct ResearchObjB *graph, struct ResearchCommon *owner);

u32 RESEARCH_GRAPH_GetInputFlag(struct ResearchObjB *graph);

void RESEARCH_GRAPH_SetGraphKind(struct ResearchObjB *graph, u32 graphKind);

struct CircleGraph *RESEARCH_GRAPH_GetLeftCircle(struct ResearchObjB *graph);

struct CircleGraph *RESEARCH_GRAPH_GetRightCircle(struct ResearchObjB *graph);

u32 RESEARCH_GRAPH_AreCirclesIdle(struct ResearchObjB *graph);

u32 RESEARCH_GRAPH_GetGroupKey(struct ResearchObjB *graph);

u32 RESEARCH_GRAPH_GetGroupCount(struct ResearchObjB *graph);

u32 RESEARCH_GRAPH_GetEntryKey(struct ResearchObjB *graph);

u32 RESEARCH_GRAPH_GetGroupValue(struct ResearchObjB *graph);

u32 RESEARCH_GRAPH_GetGroupTotalA(struct ResearchObjB *graph);

u32 RESEARCH_GRAPH_GetGroupTotalB(struct ResearchObjB *graph);

u32 RESEARCH_GRAPH_GetEntryValue(struct ResearchObjB *graph);

u32 RESEARCH_GRAPH_GetEntryValueA(struct ResearchObjB *graph);

u32 RESEARCH_GRAPH_GetEntryValueB(struct ResearchObjB *graph);

u8 RESEARCH_GRAPH_GetFirstSaveGroup(struct ResearchObjB *graph);

u32 RESEARCH_GRAPH_GetEntryIdBySave(struct ResearchObjB *graph);

u32 RESEARCH_GRAPH_GetPlayTimeGroupId(struct ResearchObjB *graph);

u16 RESEARCH_GRAPH_GetSaveBits(struct ResearchObjB *graph);

u32 RESEARCH_GRAPH_GetClactUnit(struct ResearchObjB *graph, u32 index);

struct Unit *RESEARCH_GRAPH_GetSharedHandle(struct ResearchObjB *graph, u32 index);

struct ClactActor *RESEARCH_GRAPH_GetMarkerActor(struct ResearchObjB *graph, u32 index);

struct ResearchObjB *RESEARCH_GRAPH_Alloc(u32 heapId);

void RESEARCH_GRAPH_InitFields(struct ResearchObjB *graph);

u32 RESEARCH_GRAPH_Free(struct ResearchObjB *graph);

void RESEARCH_GRAPH_ClearCommandQueue(struct ResearchObjB *graph);

void RESEARCH_GRAPH_CreateCommandQueue(struct ResearchObjB *graph);

void RESEARCH_GRAPH_DestroyCommandQueue(struct ResearchObjB *graph);

void RESEARCH_GRAPH_ClearFont(struct ResearchObjB *graph);

void RESEARCH_GRAPH_CreateFont(struct ResearchObjB *graph);

void RESEARCH_GRAPH_DeleteFont(struct ResearchObjB *graph);

void RESEARCH_GRAPH_ClearMessages(struct ResearchObjB *graph);

void RESEARCH_GRAPH_CreateMessages(struct ResearchObjB *graph);

void RESEARCH_GRAPH_DeleteMessages(struct ResearchObjB *graph);

void RESEARCH_GRAPH_ClearWordSet(struct ResearchObjB *graph);

void RESEARCH_GRAPH_CreateWordSet(struct ResearchObjB *graph);

void RESEARCH_GRAPH_DeleteWordSet(struct ResearchObjB *graph);

void RESEARCH_GRAPH_ClearCircles(struct ResearchObjB *graph);

void RESEARCH_GRAPH_CreateCircles(struct ResearchObjB *graph);

void RESEARCH_GRAPH_DestroyCircles(struct ResearchObjB *graph);

void RESEARCH_GRAPH_ClearGraphTable(struct ResearchObjB *graph);

void RESEARCH_GRAPH_BuildGraphTable(struct ResearchObjB *graph);

void RESEARCH_GRAPH_InitTouchRects(struct ResearchObjB *graph);

void RESEARCH_GRAPH_ClearArrow(struct ResearchObjB *graph);

void RESEARCH_GRAPH_CreateArrow(struct ResearchObjB *graph);

void RESEARCH_GRAPH_DestroyArrow(struct ResearchObjB *graph);

void RESEARCH_GRAPH_ClearPercentages(struct ResearchObjB *graph);

void RESEARCH_GRAPH_CreatePercentages(struct ResearchObjB *graph);

void RESEARCH_GRAPH_DestroyPercentages(struct ResearchObjB *graph);

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

extern struct ResearchGraphBg d_021C386C;

extern u8 d_021C3900[];

extern u8 d_021C3994[];

extern const struct CursorRect d_021C3758[];

extern const u16 d_021C365C[];

void *RESEARCH_GRAPH_Create(void *owner)
{
    struct ResearchObjB *graph;
    u32 heapId;
    heapId = RESEARCH_COMMON_GetHeapId(owner);
    graph = RESEARCH_GRAPH_Alloc(heapId);
    RESEARCH_GRAPH_InitFields(graph);
    RESEARCH_GRAPH_SetHeapId(graph, heapId);
    RESEARCH_GRAPH_SetOwner(graph, owner);
    return graph;
}

u32 RESEARCH_GRAPH_Destroy(struct ResearchObjB *graph)
{
    RESEARCH_GRAPH_DestroyCommandQueue(graph);
    return RESEARCH_GRAPH_Free(graph);
}

void RESEARCH_GRAPH_Update(struct ResearchObjB *graph)
{
    switch (graph->state) {
    case 0: RESEARCH_GRAPH_Init(graph); break;
    case 1: RESEARCH_GRAPH_UpdateIntro(graph); break;
    case 2: RESEARCH_GRAPH_HandleInput(graph); break;
    case 3: RESEARCH_GRAPH_HandleInputAlt(graph); break;
    case 4: RESEARCH_GRAPH_EnterDrawSlow(graph); break;
    case 5: RESEARCH_GRAPH_StepAnimation(graph); break;
    case 6: RESEARCH_GRAPH_EnterFadeIn(graph); break;
    case 7: RESEARCH_GRAPH_EnterFadeOut(graph); break;
    case 8: RESEARCH_GRAPH_EnterDrawMedium(graph); break;
    case 9: RESEARCH_GRAPH_EnterDrawMediumAlt(graph); break;
    case 10: RESEARCH_GRAPH_ExitFade(graph); break;
    case 11: RESEARCH_GRAPH_AdvanceWhileActive(graph); break;
    case 12: RESEARCH_GRAPH_Cleanup(graph); break;
    case 13: return;
    }
    RESEARCH_GRAPH_CheckQuestionnaireUpdated(graph);
    RESEARCH_GRAPH_TickTimer(graph);
    if (graph->drawSystem != 0) {
        CLACT_DrawSystem(graph->drawSystem);
        RESEARCH_GRAPH_UpdateCircles(graph);
        ARROW_Update(graph->arrow);
        RESEARCH_GRAPH_UpdatePaletteAnime(graph);
        RESEARCH_GRAPH_UpdateSlotPalettes(graph);
        RESEARCH_GRAPH_DrawCircles(graph);
        RESEARCH_GRAPH_DrawSliceColor(graph);
        *(volatile unsigned int *)0x04000540 = 0;
    }
    RESEARCH_GRAPH_IncTimer(graph);
    RESEARCH_GRAPH_ProcessCommand(graph);
}

u32 RESEARCH_GRAPH_GetVisible(struct ResearchObjB *graph)
{
    return graph->visible;
}

/*
 * Field getter, u32 at +0x3e4.
 *
 * Addresses are Black-image addresses.
 */
u32 RESEARCH_GRAPH_GetActive(struct ResearchObjB *graph)
{
    return graph->active;
}

void RESEARCH_GRAPH_Init(struct ResearchObjB *graph)
{
    int r;
    RESEARCH_GRAPH_CreateCommandQueue(graph);
    RESEARCH_GRAPH_CreateFont(graph);
    RESEARCH_GRAPH_CreateMessages(graph);
    RESEARCH_GRAPH_CreateWordSet(graph);
    RESEARCH_GRAPH_InitTouchRects(graph);
    RESEARCH_GRAPH_LayoutTouchRects(graph);
    RESEARCH_GRAPH_InitScreen();
    RESEARCH_GRAPH_InitOverlayBackgrounds(graph);
    RESEARCH_GRAPH_LoadBackground6(graph);
    RESEARCH_GRAPH_UpdateBackground7(graph);
    RESEARCH_GRAPH_LoadBackground2(graph);
    RESEARCH_GRAPH_UpdateBackground3(graph);
    RESEARCH_GRAPH_CreateLabels(graph);
    RESEARCH_GRAPH_RegisterEntryResources(graph);
    RESEARCH_GRAPH_RegisterCursorResources(graph);
    RESEARCH_GRAPH_CreateUnits(graph);
    RESEARCH_GRAPH_CreateActors(graph);
    RESEARCH_GRAPH_CreateBmps(graph);
    RESEARCH_GRAPH_DrawBmps(graph);
    RESEARCH_GRAPH_DrawBadge(graph);
    RESEARCH_GRAPH_CreateOamSys(graph);
    RESEARCH_GRAPH_CreateOamObjects(graph);
    RESEARCH_GRAPH_BuildGraphTable(graph);
    RESEARCH_GRAPH_CreateCircles(graph);
    RESEARCH_GRAPH_CreateArrow(graph);
    RESEARCH_GRAPH_CreatePercentages(graph);
    RESEARCH_GRAPH_CreatePalAnm(graph);
    RESEARCH_GRAPH_CreatePaletteAnime(graph);
    RESEARCH_GRAPH_BindPaletteAnime(graph);
    RESEARCH_GRAPH_RegisterVBlank(graph);
    RESEARCH_GRAPH_RestartNetwork(graph);
    RESEARCH_GRAPH_PrintTitle(graph);
    RESEARCH_GRAPH_PrintGroupLabel(graph);
    RESEARCH_GRAPH_PrintKindLabel(graph);
    RESEARCH_GRAPH_PrintSliceLabel(graph);
    RESEARCH_GRAPH_PrintTimeLabel(graph);
    RESEARCH_GRAPH_PrintTeamLabel(graph);
    RESEARCH_GRAPH_SetTeamLabelVisible(graph);
    RESEARCH_GRAPH_SetDetailLabelVisible(graph);
    RESEARCH_GRAPH_LayoutActors(graph);
    RESEARCH_GRAPH_LoadBackground(graph);
    RESEARCH_GRAPH_SetTriangleActorVisible(graph);
    RESEARCH_GRAPH_EnableOams(graph);
    RESEARCH_GRAPH_StartSlotPaletteAnime(graph, 0);
    RESEARCH_GRAPH_StartSlotPaletteAnime(graph, 7);
    RESEARCH_GRAPH_SyncArrow(graph);
    *(int *)&graph->drawSystem = 1;
    RESEARCH_GRAPH_FadeIn();
    r = RESEARCH_GRAPH_GetTransitionKind(graph);
    RESEARCH_GRAPH_PushCommand(graph, 1);
    RESEARCH_GRAPH_PushCommand(graph, r);
    if (r == 3)
        RESEARCH_GRAPH_DrawIndexCursor(graph);
    RESEARCH_GRAPH_SetStateChanged(graph);
}

#pragma thumb on

void RESEARCH_GRAPH_UpdateIntro(struct ResearchObjB *graph)
{
    switch (RESEARCH_GRAPH_GetSubState(graph)) {
    case 0:
        RESEARCH_GRAPH_OpenComm(graph);
        RESEARCH_GRAPH_IncSubState(graph);
        break;
    case 1:
        if (RESEARCH_GRAPH_GetCommKindOrStart(graph) != 0) {
            RESEARCH_GRAPH_SetStateChanged(graph);
        }
        break;
    }
}

void RESEARCH_GRAPH_HandleInput(struct ResearchObjB *graph)
{
    u32 keys;
    int hit;
    int sub;

    KEY_GetCont();
    keys = KEY_GetTrg();
    hit = TOUCHPANEL_HitTrg((TouchHitTable *)graph->touchRects);
    sub = TOUCHPANEL_HitTrg(RESEARCH_COMMON_GetTouchRects(graph->owner));
    if (*(int *)&graph->entryShown != 0 && graph->updatedFlag != 0 && *(int *)&graph->timerExpired != 0) {
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
        RESEARCH_GRAPH_StartPaletteAnime(graph);
        GFL_USE_PlaySeDefaultVolume(0x551);
        RESEARCH_GRAPH_SetStateChanged(graph);
        RESEARCH_GRAPH_PushCommand(graph, 11);
        RESEARCH_GRAPH_PushCommand(graph, 10);
        RESEARCH_GRAPH_PushCommand(graph, 12);
        return;
    }
    if ((keys & 0x40) || (keys & 0x80) || (keys & 0x20) || (keys & 0x10) || (keys & 1)) {
        RESEARCH_GRAPH_DrawIndexCursor(graph);
        RESEARCH_GRAPH_SyncArrow(graph);
        RESEARCH_GRAPH_SetStateChanged(graph);
        RESEARCH_GRAPH_PushCommand(graph, 3);
        return;
    }
    if (hit == 6 && *(int *)&graph->entryShown == 0 && RESEARCH_GRAPH_GetGroupValue(graph) != 0) {
        graph->touchSelected = 1;
        RESEARCH_GRAPH_SetHighlightSelected(graph);
        RESEARCH_GRAPH_SetStateChanged(graph);
        RESEARCH_GRAPH_PushCommand(graph, 4);
        RESEARCH_GRAPH_PushCommand(graph, 6);
        RESEARCH_GRAPH_PushCommand(graph, 7);
        RESEARCH_GRAPH_PushCommand(graph, 5);
        RESEARCH_GRAPH_PushCommand(graph, 2);
    } else if (hit == 7) {
        if (*(int *)&graph->entryShown == 0 && RESEARCH_GRAPH_GetGroupValue(graph) != 0) {
            graph->touchSelected = 1;
            RESEARCH_GRAPH_SetHighlightSelected(graph);
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
        if (*(int *)&graph->entryShown == 0 && RESEARCH_GRAPH_GetGroupValue(graph) != 0) {
            graph->touchSelected = 1;
            RESEARCH_GRAPH_SetHighlightSelected(graph);
            RESEARCH_GRAPH_SetStateChanged(graph);
            RESEARCH_GRAPH_PushCommand(graph, 4);
            RESEARCH_GRAPH_PushCommand(graph, 6);
            RESEARCH_GRAPH_PushCommand(graph, 7);
            RESEARCH_GRAPH_PushCommand(graph, 5);
            RESEARCH_GRAPH_PushCommand(graph, 2);
        } else {
            RESEARCH_GRAPH_SelectDirect(graph, 0);
        }
    } else if (*(int *)&graph->entryShown != 0 && RESEARCH_GRAPH_GetGroupValue(graph) != 0 && hit == 3) {
        RESEARCH_GRAPH_SelectDirect(graph, 1);
        RESEARCH_GRAPH_DrawIndexCursor(graph);
        RESEARCH_GRAPH_SyncArrow(graph);
        RESEARCH_GRAPH_SetStateChanged(graph);
        RESEARCH_GRAPH_PushCommand(graph, 3);
    } else if (*(int *)&graph->entryShown != 0 && RESEARCH_GRAPH_GetGroupValue(graph) != 0 && hit == 4) {
        RESEARCH_GRAPH_SelectDirect(graph, 2);
        RESEARCH_GRAPH_DrawIndexCursor(graph);
        RESEARCH_GRAPH_SyncArrow(graph);
        RESEARCH_GRAPH_SetStateChanged(graph);
        RESEARCH_GRAPH_PushCommand(graph, 3);
    } else if (hit == 5) {
        RESEARCH_GRAPH_SelectDirect(graph, 3);
        RESEARCH_GRAPH_DrawIndexCursor(graph);
        RESEARCH_GRAPH_SyncArrow(graph);
        RESEARCH_GRAPH_SetStateChanged(graph);
        RESEARCH_GRAPH_PushCommand(graph, 3);
    } else if (hit == 0) {
        RESEARCH_GRAPH_DrawIndexCursor(graph);
        RESEARCH_GRAPH_SyncArrow(graph);
        RESEARCH_GRAPH_SetStateChanged(graph);
        RESEARCH_GRAPH_PushCommand(graph, 3);
        switch (*(int *)&graph->cursorIndex) {
        case 0: RESEARCH_GRAPH_MoveGroupForward(graph); break;
        case 1: RESEARCH_GRAPH_MoveEntryBackward(graph); break;
        case 3: RESEARCH_GRAPH_ToggleEntry(graph); break;
        }
    } else if (hit == 1) {
        RESEARCH_GRAPH_DrawIndexCursor(graph);
        RESEARCH_GRAPH_SyncArrow(graph);
        RESEARCH_GRAPH_SetStateChanged(graph);
        RESEARCH_GRAPH_PushCommand(graph, 3);
        switch (*(int *)&graph->cursorIndex) {
        case 0: RESEARCH_GRAPH_MoveGroupBackward(graph); break;
        case 1: RESEARCH_GRAPH_MoveEntryForward(graph); break;
        case 3: RESEARCH_GRAPH_ToggleEntry(graph); break;
        }
    } else if (keys & 2) {
        RESEARCH_GRAPH_SetEntryHandled(graph, 0);
        RESEARCH_GRAPH_StartPaletteAnime(graph);
        GFL_USE_PlaySeDefaultVolume(0x551);
        RESEARCH_GRAPH_SetStateChanged(graph);
        RESEARCH_GRAPH_PushCommand(graph, 11);
        RESEARCH_GRAPH_PushCommand(graph, 10);
        RESEARCH_GRAPH_PushCommand(graph, 12);
    }
}

void RESEARCH_GRAPH_HandleInputAlt(struct ResearchObjB *graph)
{
    u32 keys;
    int hit;
    int sub;

    KEY_GetCont();
    keys = KEY_GetTrg();
    hit = TOUCHPANEL_HitTrg((TouchHitTable *)graph->touchRects);
    sub = TOUCHPANEL_HitTrg(RESEARCH_COMMON_GetTouchRects(graph->owner));
    if (*(int *)&graph->entryShown != 0 && graph->updatedFlag != 0 && *(int *)&graph->timerExpired != 0) {
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
        RESEARCH_GRAPH_StartPaletteAnime(graph);
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
    } else if (hit == 6 && *(int *)&graph->entryShown == 0 && RESEARCH_GRAPH_GetGroupValue(graph) != 0) {
        graph->touchSelected = 1;
        RESEARCH_GRAPH_SetHighlightSelected(graph);
        RESEARCH_GRAPH_SetStateChanged(graph);
        RESEARCH_GRAPH_PushCommand(graph, 4);
        RESEARCH_GRAPH_PushCommand(graph, 6);
        RESEARCH_GRAPH_PushCommand(graph, 7);
        RESEARCH_GRAPH_PushCommand(graph, 5);
        RESEARCH_GRAPH_PushCommand(graph, 2);
    } else if (hit == 7) {
        if (*(int *)&graph->entryShown == 0 && RESEARCH_GRAPH_GetGroupValue(graph) != 0) {
            graph->touchSelected = 1;
            RESEARCH_GRAPH_SetHighlightSelected(graph);
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
        if (*(int *)&graph->entryShown == 0 && RESEARCH_GRAPH_GetGroupValue(graph) != 0) {
            graph->touchSelected = 1;
            RESEARCH_GRAPH_SetHighlightSelected(graph);
            RESEARCH_GRAPH_SetStateChanged(graph);
            RESEARCH_GRAPH_PushCommand(graph, 4);
            RESEARCH_GRAPH_PushCommand(graph, 6);
            RESEARCH_GRAPH_PushCommand(graph, 7);
            RESEARCH_GRAPH_PushCommand(graph, 5);
            RESEARCH_GRAPH_PushCommand(graph, 2);
        } else {
            RESEARCH_GRAPH_SelectDirect(graph, 0);
        }
    } else if (*(int *)&graph->entryShown != 0 && RESEARCH_GRAPH_GetGroupValue(graph) != 0 && hit == 3) {
        RESEARCH_GRAPH_SelectDirect(graph, 1);
    } else if (*(int *)&graph->entryShown != 0 && RESEARCH_GRAPH_GetGroupValue(graph) != 0 && hit == 4) {
        RESEARCH_GRAPH_SelectDirect(graph, 2);
    } else if (hit == 5) {
        RESEARCH_GRAPH_SelectDirect(graph, 3);
    } else if ((keys & 0x20) || hit == 0) {
        switch (*(int *)&graph->cursorIndex) {
        case 0: RESEARCH_GRAPH_MoveGroupForward(graph); break;
        case 1: RESEARCH_GRAPH_MoveEntryBackward(graph); break;
        case 3: RESEARCH_GRAPH_ToggleEntry(graph); break;
        }
    } else if ((keys & 0x10) || hit == 1) {
        switch (*(int *)&graph->cursorIndex) {
        case 0: RESEARCH_GRAPH_MoveGroupBackward(graph); break;
        case 1: RESEARCH_GRAPH_MoveEntryForward(graph); break;
        case 3: RESEARCH_GRAPH_ToggleEntry(graph); break;
        }
    } else if ((keys & 1) && *(int *)&graph->entryShown == 0 && RESEARCH_GRAPH_GetGroupValue(graph) != 0
               && (*(int *)&graph->cursorIndex == 0 || *(int *)&graph->cursorIndex == 4)) {
        graph->touchSelected = 0;
        RESEARCH_GRAPH_SetHighlightSelected(graph);
        RESEARCH_GRAPH_SetStateChanged(graph);
        RESEARCH_GRAPH_PushCommand(graph, 4);
        RESEARCH_GRAPH_PushCommand(graph, 6);
        RESEARCH_GRAPH_PushCommand(graph, 7);
        RESEARCH_GRAPH_PushCommand(graph, 5);
        RESEARCH_GRAPH_PushCommand(graph, 3);
    } else if (keys & 2) {
        RESEARCH_GRAPH_SetEntryHandled(graph, 0);
        RESEARCH_GRAPH_StartPaletteAnime(graph);
        GFL_USE_PlaySeDefaultVolume(0x551);
        RESEARCH_GRAPH_SetStateChanged(graph);
        RESEARCH_GRAPH_PushCommand(graph, 11);
        RESEARCH_GRAPH_PushCommand(graph, 10);
        RESEARCH_GRAPH_PushCommand(graph, 12);
    }
}

void RESEARCH_GRAPH_EnterDrawSlow(struct ResearchObjB *graph)
{
    switch (RESEARCH_GRAPH_GetSubState(graph)) {
    case 0:
        RESEARCH_GRAPH_BuildGraphTable(graph);
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
            if (graph->stateTimer >= 0x78)
                RESEARCH_GRAPH_IncSubState(graph);
            else
                GFL_USE_PlaySeDefaultVolume(0x76B);
        }
        break;
    case 2:
        *(int *)&graph->entryShown = 1;
        RESEARCH_GRAPH_SetIndex(graph, 1);
        RESEARCH_GRAPH_LayoutActors(graph);
        RESEARCH_GRAPH_LayoutTouchRects(graph);
        RESEARCH_GRAPH_MoveToSelectedEntry(graph);
        RESEARCH_GRAPH_DisableOams(graph);
        RESEARCH_GRAPH_LoadBackground(graph);
        RESEARCH_GRAPH_PrintSliceLabel(graph);
        RESEARCH_GRAPH_PrintTimeLabel(graph);
        RESEARCH_GRAPH_SetDetailLabelVisible(graph);
        RESEARCH_GRAPH_PrintTeamLabel(graph);
        RESEARCH_GRAPH_LayoutArrow(graph);
        RESEARCH_GRAPH_SetTriangleActorVisible(graph);
        if (graph->touchSelected == 0)
            RESEARCH_GRAPH_DrawIndexCursor(graph);
        GFL_USE_PlaySeDefaultVolume(0x76C);
        RESEARCH_GRAPH_SetStateChanged(graph);
        break;
    }
}

void RESEARCH_GRAPH_StepAnimation(struct ResearchObjB *graph)
{
    switch (RESEARCH_GRAPH_GetSubState(graph)) {
    case 0:
        RESEARCH_GRAPH_UpdatePercentages(graph);
        RESEARCH_GRAPH_IncSubState(graph);
        break;
    case 1:
        if (graph->stateTimer % 10u == 0) {
            u8 index = graph->percentageVisible;
            graph->percentageVisible = index + 1;
            RESEARCH_GRAPH_ShowPercent(graph, index);
        }
        if (graph->percentageCount <= graph->percentageVisible) RESEARCH_GRAPH_SetStateChanged(graph);
        break;
    }
}

/*
 * Same two-case entry as RESEARCH_GRAPH_EnterFadeOut; mode 0 arms the +5 handle and
 * RESEARCH_GRAPH_RequestFadeIn().
 *
 * Addresses are Black-image addresses.
 */
void RESEARCH_GRAPH_EnterFadeIn(struct ResearchObjB *graph)
{
    switch (RESEARCH_GRAPH_GetSubState(graph)) {
    case 0:
    RESEARCH_GRAPH_StopSlotPaletteAnime(graph, 5);
    RESEARCH_GRAPH_RequestFadeIn(graph);
    RESEARCH_GRAPH_IncSubState(graph);
    break;
    case 1:
    if (RESEARCH_GRAPH_IsFadeDone(graph) != 0) {
    RESEARCH_GRAPH_SetStateChanged(graph);
    }
    break;
    }
}

void RESEARCH_GRAPH_EnterFadeOut(struct ResearchObjB *graph)
{
    switch (RESEARCH_GRAPH_GetSubState(graph)) {
    case 0:
    RESEARCH_GRAPH_RequestFadeOut(graph);
    RESEARCH_GRAPH_IncSubState(graph);
    break;
    case 1:
    if (RESEARCH_GRAPH_IsFadeDone(graph) != 0) {
    RESEARCH_GRAPH_SyncArrow(graph);
    RESEARCH_GRAPH_SetStateChanged(graph);
    }
    break;
    }
}

void RESEARCH_GRAPH_EnterDrawMedium(struct ResearchObjB *graph)
{
    switch (RESEARCH_GRAPH_GetSubState(graph)) {
    case 0:
        graph->detailMode = 1;
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
        RESEARCH_GRAPH_SetSlicesFromGraphB(graph, 0);
        RESEARCH_GRAPH_SetSlicesFromGraphB(graph, 1);
        RESEARCH_GRAPH_SetCenterDepth(graph);
        CircleGraph_SetEnabled((struct CircleGraph *)(RESEARCH_GRAPH_GetRightCircle(graph)), 1);
        CircleGraph_QueueDrawMedium((struct CircleGraph *)(RESEARCH_GRAPH_GetRightCircle(graph)));
        RESEARCH_GRAPH_IncSubState(graph);
        break;
    case 1:
        if (GFL_USE_IsAnySeBusy() == 0) {
            if (graph->stateTimer >= 0x3c) {
                RESEARCH_GRAPH_IncSubState(graph);
                return;
            }
            GFL_USE_PlaySeDefaultVolume(0x76b);
        }
        break;
    case 2:
        graph->detailMode = 0;
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

void RESEARCH_GRAPH_EnterDrawMediumAlt(struct ResearchObjB *graph)
{
    switch (RESEARCH_GRAPH_GetSubState(graph)) {
    case 0:
        graph->detailMode = 1;
        RESEARCH_GRAPH_ClearUpdatedFlag(graph);
        RESEARCH_GRAPH_ResetTimer(graph);
        RESEARCH_GRAPH_BuildGraphTable(graph);
        RESEARCH_GRAPH_DrawIndexCursorDim(graph);
        RESEARCH_GRAPH_LoadBackground(graph);
        RESEARCH_GRAPH_PrintSliceLabel(graph);
        RESEARCH_GRAPH_SetDetailLabelVisible(graph);
        RESEARCH_GRAPH_SetTeamLabelVisible(graph);
        RESEARCH_GRAPH_LayoutArrow(graph);
        RESEARCH_GRAPH_LayoutActors(graph);
        RESEARCH_GRAPH_HideAllPercentages(graph);
        RESEARCH_GRAPH_SetSlicesFromGraphB(graph, 0);
        RESEARCH_GRAPH_SetSlicesFromGraphB(graph, 1);
        RESEARCH_GRAPH_SetCenterDepth(graph);
        CircleGraph_SetEnabled((struct CircleGraph *)(RESEARCH_GRAPH_GetRightCircle(graph)), 1);
        CircleGraph_QueueDrawMedium((struct CircleGraph *)(RESEARCH_GRAPH_GetRightCircle(graph)));
        RESEARCH_GRAPH_IncSubState(graph);
        break;
    case 1:
        if (GFL_USE_IsAnySeBusy() == 0) {
            if (graph->stateTimer >= 0x3c) {
                RESEARCH_GRAPH_IncSubState(graph);
                return;
            }
            GFL_USE_PlaySeDefaultVolume(0x76b);
        }
        break;
    case 2:
        graph->detailMode = 0;
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
void RESEARCH_GRAPH_ExitFade(struct ResearchObjB *graph)
{
    switch (RESEARCH_GRAPH_GetSubState(graph)) {
    case 0:
    RESEARCH_GRAPH_FadeOut();
    RESEARCH_GRAPH_IncSubState(graph);
    break;
    case 1:
    if (FADE_IsActive() == 0) {
    RESEARCH_GRAPH_SetStateChanged(graph);
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
void RESEARCH_GRAPH_AdvanceWhileActive(struct ResearchObjB *graph)
{
    if (RESEARCH_GRAPH_GetCount(graph) < graph->stateTimer) {
    RESEARCH_GRAPH_SetStateChanged(graph);
    }
}

void RESEARCH_GRAPH_Cleanup(struct ResearchObjB *graph)
{
    RESEARCH_GRAPH_RestorePaletteAnime(graph);
    RESEARCH_GRAPH_DestroyPaletteAnime(graph);
    RESEARCH_COMMON_StopPaletteAnime(graph->owner);
    RESEARCH_COMMON_RestorePaletteAnime(graph->owner);
    RESEARCH_GRAPH_UnregisterVBlank(graph);
    RESEARCH_GRAPH_DestroyPercentages(graph);
    RESEARCH_GRAPH_DestroyArrow(graph);
    RESEARCH_GRAPH_DestroyCircles(graph);
    RESEARCH_GRAPH_DeletePalAnm(graph);
    RESEARCH_GRAPH_DeleteBmps(graph);
    RESEARCH_GRAPH_DeleteOamObjects(graph);
    RESEARCH_GRAPH_DeleteOamSys(graph);
    RESEARCH_GRAPH_DeleteActors(graph);
    RESEARCH_GRAPH_DeleteUnits(graph);
    RESEARCH_GRAPH_ReleaseEntryResources(graph);
    RESEARCH_GRAPH_ReleaseCursorResources(graph);
    RESEARCH_GRAPH_DestroyLabels(graph);
    RESEARCH_GRAPH_ShowBackground3(graph);
    RESEARCH_GRAPH_DummyBg3(graph);
    RESEARCH_GRAPH_ShowBackground7(graph);
    RESEARCH_GRAPH_DummyBg7(graph);
    RESEARCH_GRAPH_ExitOverlayBackgrounds(graph);
    RESEARCH_GRAPH_DeleteWordSet(graph);
    RESEARCH_GRAPH_DeleteMessages(graph);
    RESEARCH_GRAPH_DeleteFont(graph);
    RESEARCH_GRAPH_SetActive(graph, 0);
    RESEARCH_GRAPH_PushCommand(graph, 13);
    RESEARCH_GRAPH_SetStateChanged(graph);
    RESEARCH_GRAPH_ClearNotifyFlag(graph);
    *(u32 *)&graph->drawSystem = 0;
    graph->visible = 1;
}

void RESEARCH_GRAPH_SetStateChanged(struct ResearchObjB *graph)
{
    graph->stateChanged = 1;
}

/*
 * Tail-call veneer: forwards arg(s) (u32)(*(u32*)(a0)) to RESEARCH_COMMON_SetEntryHandled.
 *
 * Addresses are Black-image addresses.
 */
void RESEARCH_GRAPH_SetEntryHandled(struct ResearchObjB *graph, u32 handled)
{
    RESEARCH_COMMON_SetEntryHandled((struct ResearchCommon *)(*(u8 * *)&graph->owner), handled);
}

void RESEARCH_GRAPH_SetActive(struct ResearchObjB *graph, u32 active)
{
    graph->active = active;
}

u32 RESEARCH_GRAPH_GetCount(struct ResearchObjB *graph)
{
    return graph->count;
}

/*
 * Classifies the record: 3 when the first query is busy and the second is
 * not, else 2.
 *
 * Addresses are Black-image addresses.
 */
u32 RESEARCH_GRAPH_GetTransitionKind(struct ResearchObjB *graph)
{
    struct ResearchCommon *v = graph->owner;
    u32 a = RESEARCH_COMMON_GetPreviousScreen(v);
    u32 b = RESEARCH_COMMON_GetEntryHandled(v);
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
void RESEARCH_GRAPH_IncTimer(struct ResearchObjB *graph)
{
    u32 *c = &graph->stateTimer;
    *c += 1;
}

/*
 * Tail-call veneer: forwards arg(s) (u32)(*(u32*)(a0 + 28)) to RingQueue_Push.
 *
 * Addresses are Black-image addresses.
 */
void RESEARCH_GRAPH_PushCommand(struct ResearchObjB *graph, u32 command)
{
    RingQueue_Push((struct RingQueue *)((graph->commandQueue)), command);
}

void RESEARCH_GRAPH_ProcessCommand(struct ResearchObjB *graph)
{
    if (graph->stateChanged != 0) {
    if (RingQueue_IsEmpty((struct RingQueue *)(graph->commandQueue)) == 0) {
    RESEARCH_GRAPH_StartSubState(graph, RingQueue_Pop((struct RingQueue *)(graph->commandQueue)));
    }
    }
}

/*
 * Set +0x20, clear +0x24, +0x28 and +0x3dc.
 *
 * Addresses are Black-image addresses.
 */
void RESEARCH_GRAPH_StartSubState(struct ResearchObjB *graph, u32 state)
{
    graph->state = state;
    graph->subState = 0;
    graph->stateTimer = 0;
    graph->stateChanged = 0;
}

u32 RESEARCH_GRAPH_GetSubState(struct ResearchObjB *graph)
{
    return graph->subState;
}

/*
 * Increment the u32 at +0x24.
 *
 * Addresses are Black-image addresses.
 */
void RESEARCH_GRAPH_IncSubState(struct ResearchObjB *graph)
{
    u32 *c = &graph->subState;
    *c += 1;
}

void RESEARCH_GRAPH_SelectPrev(struct ResearchObjB *graph)
{
    int repeat=1;
    RESEARCH_GRAPH_DrawIndexCursorDim(graph);
    RESEARCH_GRAPH_CycleIndex(graph,-1);
    do {
        u32 index=graph->cursorIndex;
        if (index-1<=1) {
            if (graph->entryShown==0 || RESEARCH_GRAPH_GetGroupValue(graph)==0) {
                RESEARCH_GRAPH_CycleIndex(graph,-1);
            } else repeat=0;
        } else if (index==4) {
            if (graph->entryShown==1 || RESEARCH_GRAPH_GetGroupValue(graph)==0) {
                RESEARCH_GRAPH_CycleIndex(graph,-1);
            } else repeat=0;
        } else repeat=0;
    } while(repeat);
    RESEARCH_GRAPH_DrawIndexCursor(graph);
    RESEARCH_GRAPH_LayoutActors(graph);
    RESEARCH_GRAPH_LayoutMarkerActor(graph);
    RESEARCH_GRAPH_StartSlotPaletteAnime(graph,1);
    if (graph->cursorIndex==4) RESEARCH_GRAPH_SetHighlightC(graph);
    GFL_USE_PlaySeDefaultVolume(1352);
    RESEARCH_GRAPH_LayoutTouchRects(graph);
}

void RESEARCH_GRAPH_SelectNext(struct ResearchObjB *graph)
{
    int repeat=1;
    RESEARCH_GRAPH_DrawIndexCursorDim(graph);
    RESEARCH_GRAPH_CycleIndex(graph,1);
    do {
        u32 index=graph->cursorIndex;
        if (index-1<=1) {
            if (graph->entryShown==0 || RESEARCH_GRAPH_GetGroupValue(graph)==0) {
                RESEARCH_GRAPH_CycleIndex(graph,1);
            } else repeat=0;
        } else if (index==4) {
            if (graph->entryShown==1 || RESEARCH_GRAPH_GetGroupValue(graph)==0) {
                RESEARCH_GRAPH_CycleIndex(graph,1);
            } else repeat=0;
        } else repeat=0;
    } while(repeat);
    RESEARCH_GRAPH_DrawIndexCursor(graph);
    RESEARCH_GRAPH_LayoutActors(graph);
    RESEARCH_GRAPH_LayoutMarkerActor(graph);
    RESEARCH_GRAPH_StartSlotPaletteAnime(graph,1);
    if (graph->cursorIndex==4) RESEARCH_GRAPH_SetHighlightC(graph);
    GFL_USE_PlaySeDefaultVolume(1352);
    RESEARCH_GRAPH_LayoutTouchRects(graph);
}

void RESEARCH_GRAPH_SelectDirect(struct ResearchObjB *graph, u32 index)
{
    RESEARCH_GRAPH_ApplySelection(graph, index);
    RESEARCH_GRAPH_StartSlotPaletteAnime(graph, 1);
    GFL_USE_PlaySeDefaultVolume(1352);
}

void RESEARCH_GRAPH_ApplySelection(struct ResearchObjB *graph, u32 index)
{
    if ((u32)(index - 1) <= 1) {
    if (graph->entryShown == 0) {
    return;
    }
    if (RESEARCH_GRAPH_GetGroupValue(graph) == 0) {
    return;
    }
    }
    RESEARCH_GRAPH_DrawIndexCursorDim(graph);
    RESEARCH_GRAPH_SetIndex(graph, index);
    RESEARCH_GRAPH_DrawIndexCursor(graph);
    RESEARCH_GRAPH_LayoutActors(graph);
    RESEARCH_GRAPH_LayoutMarkerActor(graph);
    RESEARCH_GRAPH_LayoutTouchRects(graph);
}

/*
 * Per-frame step for the record's +0x3C8 sub-state; the tail is the
 * fixed-order call list that re-arms the sub-system (delta +1).
 *
 * Addresses are Black-image addresses.
 */
void RESEARCH_GRAPH_MoveGroupBackward(struct ResearchObjB *graph)
{
    if (graph->entryShown != 0) {
        if (RESEARCH_GRAPH_GetGroupValue(graph) != 0) {
            CircleGraph_QueueErase((struct CircleGraph *)(RESEARCH_GRAPH_GetLeftCircle(graph)));
        }
    }
    RESEARCH_GRAPH_BuildGraphTable(graph);
    RESEARCH_GRAPH_ClearUpdatedFlag(graph);
    RESEARCH_GRAPH_CycleGroup(graph, 1);
    graph->entryShown = 0;
    RESEARCH_GRAPH_LoadBackground(graph);
    RESEARCH_GRAPH_DrawIndexCursor(graph);
    RESEARCH_GRAPH_PrintGroupLabel(graph);
    RESEARCH_GRAPH_PrintKindLabel(graph);
    RESEARCH_GRAPH_MoveToFirstEntry(graph);
    RESEARCH_GRAPH_PrintTimeLabel(graph);
    RESEARCH_GRAPH_PrintTeamLabel(graph);
    RESEARCH_GRAPH_SetTeamLabelVisible(graph);
    RESEARCH_GRAPH_HideAllPercentages(graph);
    RESEARCH_GRAPH_SetTriangleActorVisible(graph);
    RESEARCH_GRAPH_SyncArrow(graph);
    GFL_USE_PlaySeDefaultVolume(1352);
}

/*
 * Identical frame step to RESEARCH_GRAPH_MoveGroupBackward with the sub-state delta -1.
 *
 * Addresses are Black-image addresses.
 */
void RESEARCH_GRAPH_MoveGroupForward(struct ResearchObjB *graph)
{
    if (graph->entryShown != 0) {
        if (RESEARCH_GRAPH_GetGroupValue(graph) != 0) {
            CircleGraph_QueueErase((struct CircleGraph *)(RESEARCH_GRAPH_GetLeftCircle(graph)));
        }
    }
    RESEARCH_GRAPH_BuildGraphTable(graph);
    RESEARCH_GRAPH_ClearUpdatedFlag(graph);
    RESEARCH_GRAPH_CycleGroup(graph, -1);
    graph->entryShown = 0;
    RESEARCH_GRAPH_LoadBackground(graph);
    RESEARCH_GRAPH_DrawIndexCursor(graph);
    RESEARCH_GRAPH_PrintGroupLabel(graph);
    RESEARCH_GRAPH_PrintKindLabel(graph);
    RESEARCH_GRAPH_MoveToFirstEntry(graph);
    RESEARCH_GRAPH_PrintTimeLabel(graph);
    RESEARCH_GRAPH_PrintTeamLabel(graph);
    RESEARCH_GRAPH_SetTeamLabelVisible(graph);
    RESEARCH_GRAPH_HideAllPercentages(graph);
    RESEARCH_GRAPH_SetTriangleActorVisible(graph);
    RESEARCH_GRAPH_SyncArrow(graph);
    GFL_USE_PlaySeDefaultVolume(1352);
}

void RESEARCH_GRAPH_MoveEntryForward(struct ResearchObjB *graph)
{
    RESEARCH_GRAPH_StepEntry(graph, 1);
    RESEARCH_GRAPH_PrintSliceLabel(graph);
    RESEARCH_GRAPH_LayoutArrow(graph);
    GFL_USE_PlaySeDefaultVolume(1352);
}

void RESEARCH_GRAPH_MoveEntryBackward(struct ResearchObjB *graph)
{
    RESEARCH_GRAPH_StepEntry(graph, -1);
    RESEARCH_GRAPH_PrintSliceLabel(graph);
    RESEARCH_GRAPH_LayoutArrow(graph);
    GFL_USE_PlaySeDefaultVolume(1352);
}

void RESEARCH_GRAPH_MoveToFirstEntry(struct ResearchObjB *graph)
{
    RESEARCH_GRAPH_ClearEntryIndex(graph);
    RESEARCH_GRAPH_PrintSliceLabel(graph);
    RESEARCH_GRAPH_LayoutArrow(graph);
}

void RESEARCH_GRAPH_MoveToSelectedEntry(struct ResearchObjB *graph)
{
    RESEARCH_GRAPH_SetEntryFromSlice(graph);
    RESEARCH_GRAPH_PrintSliceLabel(graph);
    RESEARCH_GRAPH_LayoutArrow(graph);
}

void RESEARCH_GRAPH_ToggleEntry(struct ResearchObjB *graph)
{
    int flag = 0;
    u32 k;
    if (RESEARCH_GRAPH_AreCirclesIdle(graph) == 0) {
        return;
    }
    if (graph->entryShown != 0 && RESEARCH_GRAPH_GetGroupValue(graph) != 0) {
        CircleGraph_QueueErase((struct CircleGraph *)(RESEARCH_GRAPH_GetLeftCircle(graph)));
        flag = 1;
    }
    switch (graph->graphKind) {
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
    RESEARCH_GRAPH_SyncArrow(graph);
    RESEARCH_GRAPH_LayoutArrow(graph);
    RESEARCH_GRAPH_HideAllPercentages(graph);
    if (graph->entryShown != 0 && RESEARCH_GRAPH_GetGroupValue(graph) != 0) {
        RESEARCH_GRAPH_UpdatePercentages(graph);
        RESEARCH_GRAPH_ShowPercentages(graph);
    }
    if (graph->entryShown != 0 && RESEARCH_GRAPH_GetGroupValue(graph) != 0) {
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

void RESEARCH_GRAPH_CycleIndex(struct ResearchObjB *graph, int delta)
{
    graph->cursorIndexSigned = (graph->cursorIndexSigned + delta + 5) % 5;
}

/*
 * Field setter, u32 at +0x34.
 *
 * Addresses are Black-image addresses.
 */
void RESEARCH_GRAPH_SetIndex(struct ResearchObjB *graph, u32 index)
{
    graph->cursorIndex = index;
}

void RESEARCH_GRAPH_DrawIndexCursor(struct ResearchObjB *graph)
{
    switch (graph->cursorIndexSigned) {
    case 0:
    case 2:
    case 3:
        BG_SYS_FillTileMap(2, d_021C3AC8[graph->cursorIndexSigned].x,
                      d_021C3AC8[graph->cursorIndexSigned].y,
                      d_021C3AC8[graph->cursorIndexSigned].w,
                      d_021C3AC8[graph->cursorIndexSigned].h, 0xa);
        break;
    case 1:
        BG_SYS_FillTileMap(2, 0xd, 4, 0x13, 4, 0xa);
        BG_SYS_FillTileMap(2, 0x10, 8, 0x10, 3, 0xa);
        break;
    case 4:
        RESEARCH_GRAPH_SetHighlightA(graph);
        break;
    }
    BG_SYS_PushTile(2);
}

void RESEARCH_GRAPH_DrawIndexCursorDim(struct ResearchObjB *graph)
{
    switch (graph->cursorIndex) {
    case 0:
    case 2:
    case 3:
        BG_SYS_FillTileMap(2, d_021C3AC8[graph->cursorIndex].x,
            d_021C3AC8[graph->cursorIndex].y,
            d_021C3AC8[graph->cursorIndex].w,
            d_021C3AC8[graph->cursorIndex].h, 6);
        break;
    case 1:
        BG_SYS_FillTileMap(2,13,4,19,4,6);
        BG_SYS_FillTileMap(2,16,8,16,3,6);
        break;
    case 4:
        RESEARCH_GRAPH_SetHighlightB(graph);
        break;
    }
    BG_SYS_PushTile(2);
}

void RESEARCH_GRAPH_CycleGroup(struct ResearchObjB *graph, int delta)
{
    graph->groupIndex = (u8)((graph->groupIndex + delta + 3) % 3);
}

void RESEARCH_GRAPH_SetEntryFromSlice(struct ResearchObjB *graph)
{
    struct CircleGraph *o = RESEARCH_GRAPH_GetLeftCircle(graph);

    u32 k = RESEARCH_GRAPH_GetGroupKey(graph);
    int v = CircleGraph_GetSliceKey((struct CircleGraph *)o, 0);
    graph->entryIndex = GRAPHTABLE_FindEntry(&graph->table, (u8)k, (u8)v);
}

/*
 * Prototypes: original loads r0/r1 and reads return at 021C11C8/11D0;
 * narrow argument truncations are explicit in the caller.
 */
void RESEARCH_GRAPH_StepEntry(struct ResearchObjB *graph, int step)
{
    struct CircleGraph *object;
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
    graph->entryIndex = GRAPHTABLE_FindEntry(&graph->table, kind, index);
}

void RESEARCH_GRAPH_ClearEntryIndex(struct ResearchObjB *graph)
{
    graph->entryIndex = 0;
}

void RESEARCH_GRAPH_SyncArrow(struct ResearchObjB *graph)
{
    if (graph->entryShown == 1 || graph->detailMode == 1 || RESEARCH_GRAPH_GetGroupValue(graph) == 0) {
        if (RESEARCH_GRAPH_IsSlotPaletteAnimeRunning(graph, 5) == 0) RESEARCH_GRAPH_SetNormalB(graph);
    } else {
        if (RESEARCH_GRAPH_IsSlotPaletteAnimeRunning(graph, 5) == 1) RESEARCH_GRAPH_SetNormalA(graph);
    }
}

void RESEARCH_GRAPH_SetHighlightSelected(struct ResearchObjB *graph)
{
    BMP_OAM_SetPalette((struct BmpOam *)(graph->oamObject[1]), 0);
    RESEARCH_GRAPH_StopSlotPaletteAnime(graph, 5);
    RESEARCH_GRAPH_StopSlotPaletteAnime(graph, 6);
    RESEARCH_GRAPH_StartSlotPaletteAnime(graph, 2);
}

void RESEARCH_GRAPH_SetHighlightA(struct ResearchObjB *graph)
{
    BMP_OAM_SetPalette((struct BmpOam *)(graph->oamObject[1]), 0);
    RESEARCH_GRAPH_StartSlotPaletteAnime(graph, 3);
}

void RESEARCH_GRAPH_SetHighlightB(struct ResearchObjB *graph)
{
    BMP_OAM_SetPalette((struct BmpOam *)(graph->oamObject[1]), 1);
    RESEARCH_GRAPH_StopSlotPaletteAnime(graph, 3);
}

void RESEARCH_GRAPH_SetHighlightC(struct ResearchObjB *graph)
{
    BMP_OAM_SetPalette((struct BmpOam *)(graph->oamObject[1]), 0);
    RESEARCH_GRAPH_StartSlotPaletteAnime(graph, 4);
}

void RESEARCH_GRAPH_SetNormalA(struct ResearchObjB *graph)
{
    BMP_OAM_SetPalette((struct BmpOam *)(graph->oamObject[1]), 1);
    RESEARCH_GRAPH_StopSlotPaletteAnime(graph, 5);
    RESEARCH_GRAPH_StartSlotPaletteAnime(graph, 6);
}

void RESEARCH_GRAPH_SetNormalB(struct ResearchObjB *graph)
{
    BMP_OAM_SetPalette((struct BmpOam *)(graph->oamObject[1]), 1);
    RESEARCH_GRAPH_StartSlotPaletteAnime(graph, 5);
}

void RESEARCH_GRAPH_StartPaletteAnime(struct ResearchObjB *graph)
{
    RESEARCH_COMMON_StartPaletteAnime(graph->owner, 0);
}

/*
 * Swap the u32 pairs at +0x2bc and +0x2c4.
 *
 * Addresses are Black-image addresses.
 */
void RESEARCH_GRAPH_SwapCenterPairs(struct ResearchObjB *graph)
{
    int i;
    for (i = 0; i < 2; i++) {
        struct CircleGraph *t = graph->leftCircle[i];
        graph->leftCircle[i] = graph->rightCircle[i];
        graph->rightCircle[i] = t;
    }
}

void RESEARCH_GRAPH_QuantizePosition(struct GraphSliceInput *input)
{
    u32 quantY = (input->y + 62) / 3;
    u32 quantZ = (input->z + 62) / 3;
    input->quantX = (input->x + 62) / 3;
    input->quantY = quantY;
    input->quantZ = quantZ;
}

void RESEARCH_GRAPH_SetCenterDepth(struct ResearchObjB *graph)
{
    CircleGraph_SetCenterDepth((struct CircleGraph *)(RESEARCH_GRAPH_GetLeftCircle(graph)), 0xFFFFE000);
    CircleGraph_SetCenterDepth((struct CircleGraph *)(RESEARCH_GRAPH_GetRightCircle(graph)), 0);
}

void RESEARCH_GRAPH_SetSlicesFromGraphA(struct ResearchObjB *graph,int mode)
{
    struct GraphSliceInput items[17];
    struct GraphEntryView *base;
    uptr object;
    int count;
    int i;
    object=(uptr)graph->leftCircle[mode];
    count=RESEARCH_GRAPH_GetGroupCount(graph);
    base=(struct GraphEntryView *)&graph->table.groups[graph->groupIndex];
    for(i=0;i<count;i++) {
        struct GraphEntryView *q=(struct GraphEntryView *)((u8 *)base+8+i*12);
        struct GraphSliceInput *t=&items[i];
        t->id=q->id; t->x=q->x; t->y=q->y; t->z=q->z;
        RESEARCH_GRAPH_QuantizePosition(t);
        switch(mode) { case 0: t->value=q->valueA; break; case 1: t->value=q->valueB; break; }
    }
    CircleGraph_SetSlices((struct CircleGraph *)object,(struct CircleGraphInput *)items,count);
}

void RESEARCH_GRAPH_SetSlicesFromGraphB(struct ResearchObjB *graph, u32 mode)
{
    struct GraphSliceInput items[17];
    struct GraphEntryView *base;
    uptr object;
    int count;
    int i;
    object=(uptr)graph->rightCircle[mode];
    count=RESEARCH_GRAPH_GetGroupCount(graph);
    base=(struct GraphEntryView *)&graph->table.groups[graph->groupIndex];
    for(i=0;i<count;i++) {
        struct GraphEntryView *q=(struct GraphEntryView *)((u8 *)base+8+i*12);
        struct GraphSliceInput *t=&items[i];
        t->id=q->id; t->x=q->x; t->y=q->y; t->z=q->z;
        RESEARCH_GRAPH_QuantizePosition(t);
        switch(mode) { case 0: t->value=q->valueA; break; case 1: t->value=q->valueB; break; }
    }
    CircleGraph_SetSlices((struct CircleGraph *)object,(struct CircleGraphInput *)items,count);
}

void RESEARCH_GRAPH_UpdateCircles(struct ResearchObjB *graph)
{
    int i;
    for (i = 0; i < 2; i++) {
        CircleGraph_Update((struct CircleGraph *)(graph->leftCircle[i]));
        CircleGraph_Update((struct CircleGraph *)(graph->rightCircle[i]));
    }
}

void RESEARCH_GRAPH_DrawCircles(struct ResearchObjB *graph)
{
    int i;
    for (i = 0; i < 2; i++) {
        CircleGraph_Draw((struct CircleGraph *)(graph->leftCircle[i]));
        CircleGraph_Draw((struct CircleGraph *)(graph->rightCircle[i]));
    }
}

void RESEARCH_GRAPH_DrawSliceColor(struct ResearchObjB *graph)
{
    unsigned r,g,b;
    void *color;
    if (graph->entryShown==0 || graph->detailMode==1 || RESEARCH_GRAPH_GetGroupValue(graph)==0) return;
    color=&graph->table;
    r=GRAPHTABLE_GetEntryRed(color,graph->groupIndex,graph->entryIndex);
    g=GRAPHTABLE_GetEntryGreen(color,graph->groupIndex,graph->entryIndex);
    b=GRAPHTABLE_GetEntryBlue(color,graph->groupIndex,graph->entryIndex);
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
void RESEARCH_GRAPH_LayoutArrow(struct ResearchObjB *graph)
{
    struct CircleGraph *object;
    unsigned index;
    s32 x,y;
    ARROW_Reset(graph->arrow);
    if (graph->detailMode==1) return;
    if (graph->entryShown==0) return;
    if (RESEARCH_GRAPH_GetGroupValue(graph)==0) return;
    object=RESEARCH_GRAPH_GetLeftCircle(graph);
    index=RESEARCH_GRAPH_GetEntryKey(graph);
    if (CircleGraph_GetPercentByKey((struct CircleGraph *)object,index)==0) return;
    if (graph->entryShown!=0) {
        object=RESEARCH_GRAPH_GetLeftCircle(graph);
        index=RESEARCH_GRAPH_GetEntryKey(graph);
        CircleGraph_GetLabelPositionByKey((struct CircleGraph *)object,index,&x,&y);

        ARROW_Layout(graph->arrow,104,34,x,y);
        ARROW_Start(graph->arrow);
    }
}

/*
 * lever: unsigned output counter i; initialize before decrementing the signed reverse counter.
 * C11E8 forwards original r0/r1 to C1AB4's two-input record lookup.
 * C271C forwards original r1/r2 to C288C's two-field setter.
 */
void RESEARCH_GRAPH_UpdatePercentages(struct ResearchObjB *graph)
{
    int n,id;
    unsigned i;
    struct CircleGraph *object;
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
            slot=(uptr)graph->percentage[i];
            PERCENTAGE_SetValue((struct Percentage *)slot,id);
            PERCENTAGE_SetPosition((struct Percentage *)slot,x,y);
            i++;
        }
    }
    graph->percentageCount=i;
}

void RESEARCH_GRAPH_HideAllPercentages(struct ResearchObjB *graph)
{
    int i;
    u8 z = 0;
    for (i = 0; i < 10; i++) {
        PERCENTAGE_SetVisible((struct Percentage *)(graph->percentage[i]), z);
    }
    graph->percentageVisible = z;
}

/*
 * Tail-call veneer: forwards arg(s) (u32)(*(u32*)(a0 + (a1)*4 + 724)), 1 to PERCENTAGE_SetVisible.
 *
 * Addresses are Black-image addresses.
 */
void RESEARCH_GRAPH_ShowPercent(struct ResearchObjB *graph, u32 index)
{
    PERCENTAGE_SetVisible((struct Percentage *)((graph->percentage[index])), 1);
}

void RESEARCH_GRAPH_ShowPercentages(struct ResearchObjB *graph)
{
    int i;
    int n;
    n = graph->percentageCount;
    for (i = 0; i < n; i++) {
        RESEARCH_GRAPH_ShowPercent(graph, (u8)i);
    }
}

/*
 * lever: pool 021BF088 is 021C3AC8; dropping contested ov217 data hint resolves sole-ref evidence.
 */
void RESEARCH_GRAPH_LayoutTouchRects(struct ResearchObjB *graph)
{
    const struct CursorLayoutRow *row;
    u8 *q;
    row=(const struct CursorLayoutRow *)&d_021C3AC8[graph->cursorIndex];
    q=graph->touchRects;
    q[2]=RESEARCH_GRAPH_ClampByte(row->offsets[0]+row->offsets[4]-16);
    graph->touchRects[0]=RESEARCH_GRAPH_ClampByte(row->offsets[1]+row->offsets[5]-16);
    q[3]=RESEARCH_GRAPH_ClampByte(q[2]+32);
    q[1]=RESEARCH_GRAPH_ClampByte(graph->touchRects[0]+32);
    row=(const struct CursorLayoutRow *)&d_021C3AC8[graph->cursorIndex];
    q=&graph->touchRects[4];
    q[2]=RESEARCH_GRAPH_ClampByte(row->offsets[0]+row->offsets[6]-16);
    graph->touchRects[4]=RESEARCH_GRAPH_ClampByte(row->offsets[1]+row->offsets[7]-16);
    q[3]=RESEARCH_GRAPH_ClampByte(q[2]+32);
    q[1]=RESEARCH_GRAPH_ClampByte(graph->touchRects[4]+32);
}

void RESEARCH_GRAPH_LoadBackground(struct ResearchObjB *graph)
{
    struct ArcFile *arc;
    void *file,*out;
    unsigned id;
    arc=ARC_TOOL_CreateHandle(192,graph->heapId);
    if (graph->detailMode!=0) id=8;
    else if (RESEARCH_GRAPH_GetGroupValue(graph)==0) id=6;
    else {
        id=6;
        if (graph->entryShown!=0) id=7;
    }
    file=ARC_TOOL_LoadHandleMember((struct ArcHandle *)arc,id,graph->heapId);
    NNS_G2dGetUnpackedScreenData(file,&out);
    BG_SYS_DrawTile(2,(void *)((uptr)out+12),0,0,32,32);
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
void RESEARCH_GRAPH_PrintTitle(struct ResearchObjB *graph)
{
    BgTextLabel_PrintMessage((struct BgTextLabel *)(graph->label[1]), d_021C3628[graph->table.header[0]]);
}

void RESEARCH_GRAPH_PrintGroupLabel(struct ResearchObjB *graph)
{
    u32 i = RESEARCH_GRAPH_GetGroupKey(graph);
    BgTextLabel_PrintMessage((struct BgTextLabel *)(graph->label[2]), d_021C36B8[i]);
}

void RESEARCH_GRAPH_PrintKindLabel(struct ResearchObjB *graph)
{
    struct BgTextLabel *o = graph->label[3];
    u32 i = RESEARCH_GRAPH_GetGroupKey(graph);
    BgTextLabel_PrintMessage(o, d_021C369A[i]);
}

void RESEARCH_GRAPH_PrintSliceLabel(struct ResearchObjB *graph)
{
    struct BgTextLabel *t = graph->label[4];
    struct CircleGraph *o = RESEARCH_GRAPH_GetLeftCircle(graph);
    u32 k;
    u32 a, b, c;
    void *x, *y, *z;
    if (graph->entryShown == 0 || graph->detailMode == 1) {
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
    x = MSGDATA_AllocString(graph->msgBank[0], 0xd);
    y = MSGDATA_AllocString(graph->msgBank[2], k);
    z = STRBUF_Create(0x80, graph->heapId);
    WORDSET_SetSlotNumber(graph->wordSet, 0, a + 1, 2, 1, 1);
    WORDSET_SetSlotTag(graph->wordSet, 1, y, 0, 1, 2);
    WORDSET_SetSlotNumber(graph->wordSet, 2, b, 5, 1, 1);
    WORDSET_SetSlotNumber(graph->wordSet, 3, c, 3, 1, 1);
    WORDSET_CopyTaggedText(graph->wordSet, z, x);
    BgTextLabel_PrintText((struct BgTextLabel *)t, z);
    BgTextLabel_SetVisible((struct BgTextLabel *)t, 1);
    STRBUF_Delete(x);
    STRBUF_Delete(z);
    STRBUF_Delete(y);
}

/*
 * EE0C: original stores sixth argument 2 at sp+4; preserve visibly supplied trailing input.
 */
void RESEARCH_GRAPH_PrintTimeLabel(struct ResearchObjB *graph)
{
    unsigned index;
    struct U16Vec *a,*b,*buf;
    if (graph->entryShown==0 || RESEARCH_GRAPH_GetGroupValue(graph)==0) {
        BgTextLabel_SetVisible((struct BgTextLabel *)(graph->label[5]),0);
        return;
    }
    index=RESEARCH_GRAPH_GetEntryIdBySave(graph);
    a=(struct U16Vec *)MSGDATA_AllocString(*(struct MsgBank * *)&graph->msgBank[0],14);
    b=(struct U16Vec *)MSGDATA_AllocString(*(struct MsgBank * *)&graph->msgBank[2],index);
    buf=(struct U16Vec *)STRBUF_Create(128,graph->heapId);
    WORDSET_SetSlotTag(*(struct WordSet * *)&graph->wordSet,0,(struct Strbuf *)b,0,1,2);
    WORDSET_CopyTaggedText(*(struct WordSet * *)&graph->wordSet,(struct Strbuf *)buf,(struct Strbuf *)a);
    BgTextLabel_SetVisible((struct BgTextLabel *)(graph->label[5]),1);
    BgTextLabel_PrintText((struct BgTextLabel *)(graph->label[5]),buf);
    STRBUF_Delete((struct Strbuf *)a);
    STRBUF_Delete((struct Strbuf *)buf);
    STRBUF_Delete((struct Strbuf *)b);
}

void RESEARCH_GRAPH_PrintTeamLabel(struct ResearchObjB *graph)
{
    u32 k;
    u32 x;
    void *a, *b;
    void *c;
    if (graph->entryShown != 0) {
        switch (graph->graphKind) {
        case 0:
            k = 0xf;
            break;
        case 1:
            k = 0x11;
            break;
        }
    } else {
        switch (graph->graphKind) {
        case 0:
            k = 0x10;
            break;
        case 1:
            k = 0x12;
            break;
        }
    }
    x = RESEARCH_GRAPH_GetGroupValue(graph);
    c = graph->wordSet;
    a = MSGDATA_AllocString(graph->msgBank[0], k);
    b = STRBUF_Create(0x80, graph->heapId);
    WORDSET_SetSlotNumber(c, 0, x, 6, 1, 1);
    WORDSET_CopyTaggedText(c, b, a);
    BgTextLabel_PrintText((struct BgTextLabel *)(graph->label[6]), b);
    STRBUF_Delete(a);
    STRBUF_Delete(b);
}

void RESEARCH_GRAPH_SetTeamLabelVisible(struct ResearchObjB *graph)
{
    if (RESEARCH_GRAPH_GetGroupValue(graph) == 0) {
        BgTextLabel_SetVisible((struct BgTextLabel *)(graph->label[7]), 1);
    } else {
        BgTextLabel_SetVisible((struct BgTextLabel *)(graph->label[7]), 0);
    }
}

void RESEARCH_GRAPH_SetDetailLabelVisible(struct ResearchObjB *graph)
{
    if (graph->detailMode != 0) {
        BgTextLabel_SetVisible((struct BgTextLabel *)(graph->label[8]), 1);
    } else {
        BgTextLabel_SetVisible((struct BgTextLabel *)(graph->label[8]), 0);
    }
}

void RESEARCH_GRAPH_LayoutActors(struct ResearchObjB *graph)
{
    const struct CursorLayoutRow *row;
    struct Obj *a,*b;
    struct ResearchVec2 pos;
    row=(const struct CursorLayoutRow *)&d_021C3AC8[graph->cursorIndex];
    a=(struct Obj *)RESEARCH_GRAPH_GetMarkerActor(graph,0);
    b=(struct Obj *)RESEARCH_GRAPH_GetMarkerActor(graph,1);
    if (graph->detailMode==1 || graph->cursorIndex==2 || graph->cursorIndex==4) {
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

void RESEARCH_GRAPH_SetTriangleActorVisible(struct ResearchObjB *graph)
{
    if (graph->entryShown == 0 || RESEARCH_GRAPH_GetGroupValue(graph) == 0) {
        CLACT_SetActorDrawEnable((struct ClactActor *)graph->actor[2], 0);
    } else {
        CLACT_SetActorDrawEnable((struct ClactActor *)graph->actor[2], 1);
    }
}

void RESEARCH_GRAPH_LayoutMarkerActor(struct ResearchObjB *graph)
{
    struct Obj *obj;
    unsigned index;
    s32 x,y;
    struct ResearchVec2 pos;
    const u16 *table;
    obj=*(struct Obj * *)&graph->actor[3];
    table=d_021C3850;
    if (graph->entryShown==0) { CLACT_SetActorDrawEnable((struct ClactActor *)obj,0); return; }
    if (graph->cursorIndex!=2) { CLACT_SetActorDrawEnable((struct ClactActor *)obj,0); return; }
    index=RESEARCH_GRAPH_GetEntryIdBySave(graph);
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

void RESEARCH_GRAPH_EnableOams(struct ResearchObjB *graph)
{
    RESEARCH_GRAPH_SetOamEnabled(graph, 1, 1);
}

/*
 * Tail-call veneer: forwards arg(s) a0, 0, 1 to RESEARCH_GRAPH_SetOamEnabled.
 *
 * Addresses are Black-image addresses.
 */
void RESEARCH_GRAPH_EnableOamsA(struct ResearchObjB *graph)
{
    RESEARCH_GRAPH_SetOamEnabled(graph, 0, 1);
}

/*
 * Tail-call veneer: forwards arg(s) a0, 0, 0 to RESEARCH_GRAPH_SetOamEnabled.
 *
 * Addresses are Black-image addresses.
 */
void RESEARCH_GRAPH_DisableOams(struct ResearchObjB *graph)
{
    RESEARCH_GRAPH_SetOamEnabled(graph, 0, 0);
}

void RESEARCH_GRAPH_SetOamEnabled(struct ResearchObjB *graph, u32 index, u32 enabled)
{
    BMP_OAM_SetEnabled((struct BmpOam *)(graph->oamObject[index]), enabled);
}

void RESEARCH_GRAPH_StartSlotPaletteAnime(struct ResearchObjB *graph, int slot)
{
    PALETTE_ANIME_Start((struct PaletteAnime *)(graph->paletteAnime[slot]), d_021C3A34[slot].mode, d_021C3A34[slot].color);
}

/*
 * Tail-call veneer: forwards arg(s) (u32)(*(u32*)(a0 + (a1)*4 + 804)), (u32)(a0 + (a1)*4) to PALETTE_ANIME_Stop.
 *
 * Addresses are Black-image addresses.
 */
void RESEARCH_GRAPH_StopSlotPaletteAnime(struct ResearchObjB *graph, u32 slot)
{
    PALETTE_ANIME_Stop((struct PaletteAnime *)((graph->paletteAnime[slot])));
}

/*
 * Tail-call veneer: forwards arg(s) (u32)(*(u32*)(a0 + (a1)*4 + 804)), (u32)(a0 + (a1)*4) to PALETTE_ANIME_IsRunning.
 *
 * Addresses are Black-image addresses.
 */
u32 RESEARCH_GRAPH_IsSlotPaletteAnimeRunning(struct ResearchObjB *graph, u32 slot)
{
    return PALETTE_ANIME_IsRunning(graph->paletteAnime[slot], (uptr)((u32 *)graph + slot));
}

void RESEARCH_GRAPH_UpdateSlotPalettes(struct ResearchObjB *graph)
{
    int i;
    for (i = 0; i < 8; i++)
        PALETTE_ANIME_Update(graph->paletteAnime[i]);
}

/*
 * Tail-call veneer: forwards arg(s) (u32)(*(u32*)(a0)) to RESEARCH_COMMON_UpdatePaletteAnime.
 *
 * Addresses are Black-image addresses.
 */
void RESEARCH_GRAPH_UpdatePaletteAnime(struct ResearchObjB *graph)
{
    RESEARCH_COMMON_UpdatePaletteAnime(graph->owner);
}

void RESEARCH_GRAPH_RequestFadeIn(struct ResearchObjB *graph)
{
    PALANM_RequestFade(*(struct PaletteFade * *)&graph->palAnm,1,0xffff,3,0,7,0xffff,graph->fadeParam);
    PALANM_RequestFade(*(struct PaletteFade * *)&graph->palAnm,4,0xffff,3,0,7,0xffff,graph->fadeParam);
}

void RESEARCH_GRAPH_RequestFadeOut(struct ResearchObjB *graph)
{
    PALANM_RequestFade(*(struct PaletteFade * *)&graph->palAnm,1,0xffff,3,7,0,0xffff,graph->fadeParam);
    PALANM_RequestFade(*(struct PaletteFade * *)&graph->palAnm,4,0xffff,3,7,0,0xffff,graph->fadeParam);
}

/*
 * Note: the record's +0x3B8 handle is idle.
 *            witness outside 021BF6A4..021BF6BC.  Bytes are exact and 24/24
 *            match the listing extent; file the TARGET first (OV-BRIEF rule
 *            10) and this promotes to EXACT with no source change.
 *
 * Addresses are Black-image addresses.
 */
u32 RESEARCH_GRAPH_IsFadeDone(struct ResearchObjB *graph)
{
    if (PALANM_GetFadeRequestBits((struct PaletteFade *)(graph->palAnm)) == 0) {
    return 1;
    }
    return 0;
}

void RESEARCH_GRAPH_TransferPalettes(struct TcbTask *unusedArg, void *graphArg)
{
    struct ResearchObjB *graph = graphArg;
    BG_SYS_Update();
    CLACT_VBlankSystem();
    PALANM_TransferPalettes((struct PaletteFade *)graph->palAnm);
}

void RESEARCH_GRAPH_CheckQuestionnaireUpdated(struct ResearchObjB *graph)
{
    if (GAME_BEACON_PopQuestionnaireUpdated() == 1) {
        u16 a = RESEARCH_GRAPH_GetGroupTotalA(graph);
        if (a != (u16)(u32)RESEARCH_GRAPH_GetSaveBits(graph)) {
            graph->updatedFlag = 1;
        }
    }
}

/*
 * Clear the u32 at +0x3d8.
 *
 * Addresses are Black-image addresses.
 */
void RESEARCH_GRAPH_ClearUpdatedFlag(struct ResearchObjB *graph)
{
    graph->updatedFlag = 0;
}

void RESEARCH_GRAPH_TickTimer(struct ResearchObjB *graph)
{
    if (graph->elapsedTimer < 0xf0) {
        graph->elapsedTimer += 1;
    } else {
        graph->timerExpired = 1;
    }
}

void RESEARCH_GRAPH_ResetTimer(struct ResearchObjB *graph)
{
    graph->elapsedTimer = 0;
    graph->timerExpired = 0;
}

const struct Ctx *RESEARCH_GRAPH_GetContext(struct ResearchObjB *graph)
{
    return RESEARCH_COMMON_GetContext(graph->owner);
}

/*
 * Tail-call veneer: forwards arg(s) (u32)(*(u32*)(a0)) to RESEARCH_COMMON_GetAppResource.
 *
 * Addresses are Black-image addresses.
 */
void *RESEARCH_GRAPH_GetAppResource(struct ResearchObjB *graph)
{
    return RESEARCH_COMMON_GetAppResource(graph->owner);
}

void RESEARCH_GRAPH_SetHeapId(struct ResearchObjB *graph, u32 heapId)
{
    graph->heapId = heapId;
}

/*
 * Field getter, u32 at +0.
 *
 * Addresses are Black-image addresses.
 */
struct ResearchCommon *RESEARCH_GRAPH_GetOwner(struct ResearchObjB *graph)
{
    return graph->owner;
}

void RESEARCH_GRAPH_SetOwner(struct ResearchObjB *graph, struct ResearchCommon *owner)
{
    graph->owner = owner;
}

u32 RESEARCH_GRAPH_GetInputFlag(struct ResearchObjB *graph)
{
    return RESEARCH_COMMON_GetInputFlag(RESEARCH_GRAPH_GetOwner(graph));
}

/*
 * Field setter, u32 at +0x2cc.
 *
 * Addresses are Black-image addresses.
 */
void RESEARCH_GRAPH_SetGraphKind(struct ResearchObjB *graph, u32 graphKind)
{
    graph->graphKind = graphKind;
}

struct CircleGraph *RESEARCH_GRAPH_GetLeftCircle(struct ResearchObjB *graph)
{
    u32 i = graph->graphKind;
    return graph->leftCircle[i];

}

struct CircleGraph *RESEARCH_GRAPH_GetRightCircle(struct ResearchObjB *graph)
{
    u32 i = graph->graphKind;
    return graph->rightCircle[i];

}

u32 RESEARCH_GRAPH_AreCirclesIdle(struct ResearchObjB *graph)
{
    if (CircleGraph_IsAnimating((struct CircleGraph *)(*(u8 * *)&graph->leftCircle[0])) != 0 || CircleGraph_IsAnimating((struct CircleGraph *)(*(u8 * *)&graph->leftCircle[1])) != 0 || CircleGraph_IsAnimating((struct CircleGraph *)(*(u8 * *)&graph->rightCircle[0])) != 0 || CircleGraph_IsAnimating((struct CircleGraph *)(*(u8 * *)&graph->rightCircle[1])) != 0) {
    return 0;
    }
    return 1;
}

u32 RESEARCH_GRAPH_GetGroupKey(struct ResearchObjB *graph)
{
    u32 i = graph->groupIndex;
    return graph->table.groups[i].key;
}

u32 RESEARCH_GRAPH_GetGroupCount(struct ResearchObjB *graph)
{
    u32 i = graph->groupIndex;
    return graph->table.groups[i].entryCount;
}

/*
 * Element field: u16 at +0x44 of a 12-byte sub-record of record 0xd4.
 *
 * Addresses are Black-image addresses.
 */
u32 RESEARCH_GRAPH_GetEntryKey(struct ResearchObjB *graph)
{
    u32 i = graph->groupIndex;
    u32 j = graph->entryIndex;
    return graph->table.groups[i].entries[j].id;
}

u32 RESEARCH_GRAPH_GetGroupValue(struct ResearchObjB *graph)
{
    u32 r = 0;
    switch (graph->graphKind) {
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
u32 RESEARCH_GRAPH_GetGroupTotalA(struct ResearchObjB *graph)
{
    u32 i = graph->groupIndex;
    return graph->table.groups[i].valueA;
}

u32 RESEARCH_GRAPH_GetGroupTotalB(struct ResearchObjB *graph)
{
    u32 i = graph->groupIndex;
    return graph->table.groups[i].valueB;
}

u32 RESEARCH_GRAPH_GetEntryValue(struct ResearchObjB *graph)
{
    switch (graph->graphKind) {
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
u32 RESEARCH_GRAPH_GetEntryValueA(struct ResearchObjB *graph)
{
    u32 i = graph->groupIndex;
    u32 j = graph->entryIndex;
    return graph->table.groups[i].entries[j].valueA;
}

/*
 * Element field: u32 at +0x4c of a 12-byte sub-record of record 0xd4.
 *
 * Addresses are Black-image addresses.
 */
u32 RESEARCH_GRAPH_GetEntryValueB(struct ResearchObjB *graph)
{
    u32 i = graph->groupIndex;
    u32 j = graph->entryIndex;
    return graph->table.groups[i].entries[j].valueB;
}

/*
 * lever: pointer-typed lookup base keeps the original r4/r5 allocation; E44C full body reads only r0/r1 and forwards neither legacy trailing input.
 * F740 tail-forwards to C09B4's pointer getter; E394 tail-forwards to 071CC's returned save block.
 * E44C's full body reads only r0/r1 and has no forwarding calls; legacy two trailing inputs omitted.
 */
u8 RESEARCH_GRAPH_GetFirstSaveGroup(struct ResearchObjB *graph)
{
    u8 bytes[3];
    u8 a,b,c,j;
    void *base;
    int i;
    base=SYMBOL_SAVE_GetBitBlock(GAME_DATA_GetSaveControl((struct GameData *)RESEARCH_GRAPH_GetAppResource(graph)));
    for (i=0;i<3;i++) bytes[i]=MISC_SAVEDATA_GetStatusByte((void *)((sptr)base),i);
    b=bytes[1];
    c=bytes[2];
    a=bytes[0];
    for (j=0;j<10;j++) {
        if (a==d_021C363C[j] && b==d_021C3646[j] && c==d_021C3632[j]) return j;
    }
    return 0;
}

u32 RESEARCH_GRAPH_GetEntryIdBySave(struct ResearchObjB *graph)
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
    return (u8)GRAPHTABLE_GetEntryId(&graph->table, graph->groupIndex, n);
}

/*
 * extent: trailing 00 00 at 021BF9CA is two-byte alignment padding.
 * prototype: 02012FCC legacy trailing arguments omitted: full 12-byte body only reads r0, then returns its field at 0x6ac; no forwarding.
 * prototype: full 02012FCC body only reads r0, does not forward r1-r3; legacy trailing inputs omitted.
 */
u32 RESEARCH_GRAPH_GetPlayTimeGroupId(struct ResearchObjB *graph)
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
u16 RESEARCH_GRAPH_GetSaveBits(struct ResearchObjB *graph)
{
    return MISC_SAVEDATA_GetHalfword((const u16 *)SYMBOL_SAVE_GetBitBlock(GAME_DATA_GetSaveControl((struct GameData *)RESEARCH_GRAPH_GetAppResource(graph))), RESEARCH_GRAPH_GetGroupKey(graph));
}

u32 RESEARCH_GRAPH_GetClactUnit(struct ResearchObjB *graph, u32 index)
{
    return graph->clactUnits[index];
}

struct Unit *RESEARCH_GRAPH_GetSharedHandle(struct ResearchObjB *graph, u32 index)
{
    return graph->units[index];
}

struct ClactActor *RESEARCH_GRAPH_GetMarkerActor(struct ResearchObjB *graph, u32 index)
{
    return graph->actor[index];
}

struct ResearchObjB *RESEARCH_GRAPH_Alloc(u32 heapId)
{
    return GFL_HEAP_Alloc(heapId, sizeof(struct ResearchObjB), 0, (const char *)0x21C400C, 4096);
}

void RESEARCH_GRAPH_InitFields(struct ResearchObjB *graph)
{
    int i;
    graph->state = 0;
    graph->subState = 0;
    graph->stateChanged = 0;
    graph->count = 0xf;
    graph->stateTimer = 0;
    graph->elapsedTimer = 0;
    graph->cursorIndex = 0;
    graph->drawSystem = 0;
    graph->entryShown = 0;
    graph->touchSelected = 0;
    graph->detailMode = 0;
    graph->timerExpired = 0;
    graph->updatedFlag = 0;
    graph->groupIndex = 0;
    graph->entryIndex = 0;
    graph->graphKind = 0;
    graph->fadeParamU = (uptr)GFL_USE_GetMainTaskList();
    graph->percentageCount = 0;
    graph->percentageVisible = 0;
    graph->active = 0;
    graph->visible = 0;
    for (i = 0; i < 7; i++) {
        graph->clactUnits[i] = 0;
    }
    RESEARCH_GRAPH_ClearGraphTable(graph);
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

u32 RESEARCH_GRAPH_Free(struct ResearchObjB *graph)
{
    return GFL_HEAP_Free(graph);
}

/*
 * Clear the u32 at +0x1c.
 *
 * Addresses are Black-image addresses.
 */
void RESEARCH_GRAPH_ClearCommandQueue(struct ResearchObjB *graph)
{
    graph->commandQueue = 0;
}

void RESEARCH_GRAPH_CreateCommandQueue(struct ResearchObjB *graph)
{
    graph->commandQueue = RingQueue_Create(10, graph->heapId);
}

void RESEARCH_GRAPH_DestroyCommandQueue(struct ResearchObjB *graph)
{
    RingQueue_Destroy(graph->commandQueue);
}

/*
 * Clear the u32 at +8.
 *
 * Addresses are Black-image addresses.
 */
void RESEARCH_GRAPH_ClearFont(struct ResearchObjB *graph)
{
    graph->font = 0;
}

void RESEARCH_GRAPH_CreateFont(struct ResearchObjB *graph)
{
    u8 s[4];
    graph->font = GF_FONT_Create(23, 0, 0, 0, (u32)(graph->heapId));
}

/*
 * Tail-call veneer: forwards arg(s) (u32)(*(u32*)(a0 + 8)) to GF_FONT_Delete.
 *
 * Addresses are Black-image addresses.
 */
void RESEARCH_GRAPH_DeleteFont(struct ResearchObjB *graph)
{
    GF_FONT_Delete(graph->font);
}

/*
 * Clear three u32 slots at +0xc.
 *
 * Addresses are Black-image addresses.
 */
void RESEARCH_GRAPH_ClearMessages(struct ResearchObjB *graph)
{
    int i;
    for (i = 0; i < 3; i++)
        graph->msgBank[i] = 0;
}

void RESEARCH_GRAPH_CreateMessages(struct ResearchObjB *graph)
{
    int i;
    for (i = 0; i < 3; i++) {
        graph->msgBank[i] = MSGDATA_CreateFromArchive(0, 2, (u16)d_021C3650[i], (u16)graph->heapId);
    }
}

void RESEARCH_GRAPH_DeleteMessages(struct ResearchObjB *graph)
{
    int i;
    for (i = 0; i < 3; i++)
        MSGDATA_Delete(graph->msgBank[i]);
}

void RESEARCH_GRAPH_ClearWordSet(struct ResearchObjB *graph)
{
    graph->wordSet = 0;
}

void RESEARCH_GRAPH_CreateWordSet(struct ResearchObjB *graph)
{
    graph->wordSet = (void *)WORDSET_CreateDefault(graph->heapId);
}

void RESEARCH_GRAPH_DeleteWordSet(struct ResearchObjB *graph)
{
    WORDSET_Delete((struct WordSet *)((graph->wordSet)));
}

/*
 * Clear two pairs of u32 slots at +0x2bc and +0x2c4.
 *
 * Addresses are Black-image addresses.
 */
void RESEARCH_GRAPH_ClearCircles(struct ResearchObjB *graph)
{
    int i;
    for (i = 0; i < 2; i++) {
        graph->leftCircle[i] = 0;
        graph->rightCircle[i] = 0;
    }
}

void RESEARCH_GRAPH_CreateCircles(struct ResearchObjB *graph)
{
    int i;
    for (i = 0; i < 2; i++) {
        graph->leftCircle[i] = CircleGraph_Create((unsigned int)(graph->heapId));
        graph->rightCircle[i] = CircleGraph_Create((unsigned int)(graph->heapId));
    }
}

void RESEARCH_GRAPH_DestroyCircles(struct ResearchObjB *graph)
{
    int i;
    for (i = 0; i < 2; i++) {
        CircleGraph_Destroy((void *)(graph->leftCircle[i]));
        CircleGraph_Destroy((void *)(graph->rightCircle[i]));
    }
}

/*
 * Tail-call veneer: forwards arg(s) (u32)(a0 + 56), 0, 640 to MI_CpuFill8.
 *
 * Addresses are Black-image addresses.
 */
void RESEARCH_GRAPH_ClearGraphTable(struct ResearchObjB *graph)
{
    MI_CpuFill8(&graph->table, 0, 640);
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
void RESEARCH_GRAPH_BuildGraphTable(struct ResearchObjB *graph)
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
    h = SYMBOL_SAVE_GetBitBlock(GAME_DATA_GetSaveControl((struct GameData *)RESEARCH_GRAPH_GetAppResource(graph)));
    first = RESEARCH_GRAPH_GetFirstSaveGroup(graph);
    i = 0;
    grp[0] = MISC_SAVEDATA_GetStatusByte((void *)(h), 0);
    grp[1] = MISC_SAVEDATA_GetStatusByte((void *)(h), 1);
    grp[2] = MISC_SAVEDATA_GetStatusByte((void *)(h), 2);
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
            B[i][j] = MISC_SAVEDATA_GetScoreValue(h, g, j + 1);
        }
    }
    graph->table.header[0] = first;
    for (k = 0; k < 3; k++) {
        struct ResearchObjB *q = (struct ResearchObjB *)((struct GraphTableGroup *)graph + k);
        q->table.groups[0].key = grp[k];
        q->table.groups[0].entryCount = cnt[k];
        q->table.groups[0].valueA = va[k];
        q->table.groups[0].valueB = va[k] + vb[k];
        if (q->table.groups[0].valueB > 999999) {
            q->table.groups[0].valueB = 999999;
        }
        for (j = 0; j < 17; j++) {
            u16 s = sh[k][j];
            struct ResearchObjB *r = (struct ResearchObjB *)((struct GraphTableEntry *)q + j);
            u32 x;
            r->table.groups[0].entries[0].id = s;
            r->table.groups[0].entries[0].red = ((u8 *)&d_021C386C)[s];
            r->table.groups[0].entries[0].green = d_021C3900[s];
            r->table.groups[0].entries[0].blue = d_021C3994[s];
            x = A[k][j];
            r->table.groups[0].entries[0].valueA = x;
            r->table.groups[0].entries[0].valueB = x + B[k][j];
        }
    }
}

void RESEARCH_GRAPH_InitTouchRects(struct ResearchObjB *graph)
{
    int i;
    for (i = 0; i < 9; i++) {
        graph->touchRects[i * 4 + 2] = d_021C3758[i].x;
        graph->touchRects[i * 4 + 3] = d_021C3758[i].y;
        graph->touchRects[i * 4] = d_021C3758[i].w;
        graph->touchRects[i * 4 + 1] = d_021C3758[i].h;
    }
}

/*
 * Clear the u32 at +0x2d0.
 *
 * Addresses are Black-image addresses.
 */
void RESEARCH_GRAPH_ClearArrow(struct ResearchObjB *graph)
{
    graph->arrow = 0;
}

void RESEARCH_GRAPH_CreateArrow(struct ResearchObjB *graph)
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
    graph->arrow = (void *)ARROW_Create(graph->heapId, (struct ArrowResources *)(&args));
}

/*
 * Tail-call veneer: forwards arg(s) (u32)(*(u32*)(a0 + 720)), 720 to ARROW_Destroy.
 *
 * Addresses are Black-image addresses.
 */
void RESEARCH_GRAPH_DestroyArrow(struct ResearchObjB *graph)
{
    ARROW_Destroy((void *)(graph->arrow));
}

/*
 * Clear ten u32 slots at +0x2d4.
 *
 * Addresses are Black-image addresses.
 */
void RESEARCH_GRAPH_ClearPercentages(struct ResearchObjB *graph)
{
    int i;
    for (i = 0; i < 10; i++)
        graph->percentage[i] = 0;
}

/*
 * lever: p + i * 4 + 0x2d4 keeps the indexed base before the call; p + 0x2d4 + i * 4 differed by 23 bytes.
 */
void RESEARCH_GRAPH_CreatePercentages(struct ResearchObjB *graph)
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
        graph->percentage[i] = PERCENTAGE_Create(graph->heapId, (struct PercentageTemplate *)(&args), (struct ClactUnit *)(RESEARCH_GRAPH_GetSharedHandle(graph, 3)));
        PERCENTAGE_SetVisible((struct Percentage *)(graph->percentage[i]), 0);
    }
}

void RESEARCH_GRAPH_DestroyPercentages(struct ResearchObjB *graph)
{
    int i;
    for (i = 0; i < 10; i++)
        PERCENTAGE_Destroy(graph->percentage[i]);
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





#include "../arm9/g2.h"


extern void CLACT_ReleasePalette(u32 i);

extern struct ClactActor *CLACT_CreateActor(struct Unit *owner, unsigned int i, unsigned int j, unsigned int k, const struct ActorInitParam *position, unsigned short space, unsigned short heap);


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
void RESEARCH_GRAPH_InitOverlayBackgrounds(struct ResearchObjB *graph)
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
    BMP_WIN_Init(graph->heapId);
}

/*
 * Reconstructed from the listing (.inst decoded).
 *
 * Addresses are Black-image addresses.
 */
void RESEARCH_GRAPH_ExitOverlayBackgrounds()
{
    BMP_WIN_Exit();
    BG_SYS_FreeLayerBuf(0);
    BG_SYS_FreeLayerBuf(3);
    BG_SYS_FreeLayerBuf(2);
    BG_SYS_FreeLayerBuf(7);
    BG_SYS_FreeLayerBuf(6);
}

void RESEARCH_GRAPH_LoadBackground6(struct ResearchObjB *graph)
{
    void *out;
    void *h;
    void *blob;
    h = ARC_TOOL_CreateHandle(192, graph->heapId);
    blob = ARC_TOOL_LoadHandleMember((struct ArcHandle *)h, 13, graph->heapId);
    NNS_G2dGetUnpackedScreenData(blob, &out);
    BG_SYS_DrawTile(6, (void *)(((char *)out + 12)), 0, 0, 32, 24);
    BG_SYS_PushTile(6);
    GFL_HEAP_Free((void *)(blob));
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

void RESEARCH_GRAPH_UpdateBackground7()
{
    BG_SYS_Init(7, 0, 1, 0);
    BG_SYS_ClearSlot(7);
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
void RESEARCH_GRAPH_LoadBackground2(struct ResearchObjB *graph)
{
    void *out;
    void *h;
    void *blob;
    h = ARC_TOOL_CreateHandle(192, graph->heapId);
    blob = ARC_TOOL_LoadHandleMember((struct ArcHandle *)h, 7, graph->heapId);
    NNS_G2dGetUnpackedScreenData(blob, &out);
    BG_SYS_DrawTile(2, (void *)(((char *)out + 12)), 0, 0, 32, 32);
    BG_SYS_PushTile(2);
    GFL_HEAP_Free((void *)(blob));
    ARC_TOOL_DeleteHandle(h);
}

void RESEARCH_GRAPH_DummyBg3()
{
}

void RESEARCH_GRAPH_UpdateBackground3()
{
    BG_SYS_Init(3, 0, 1, 0);
    BG_SYS_ClearSlot(3);
}

/*
 * Tail-call veneer: forwards arg(s) 3, 1, 0 to BG_SYS_FreeTiles.
 *
 * Addresses are Black-image addresses.
 */
void RESEARCH_GRAPH_ShowBackground3(struct ResearchObjB *graph, u32 unusedArg1, u32 unusedArg2)
{
    BG_SYS_FreeTiles(3, 1, 0);
}

/*
 * Clear nine u32 slots at +0x344.
 *
 * Addresses are Black-image addresses.
 */
void RESEARCH_GRAPH_ClearLabels(struct ResearchObjB *graph)
{
    int i;
    for (i = 0; i < 9; i++)
        graph->label[i] = 0;
}

/*
 * lever: direct indexed assignment computes and spills the destination before allocation; a handle temporary first gave 116 bytes and 47 differing bytes.
 * prototype: keep caller's visible second argument to 021C0F5C despite its legacy one-argument source (021C021C loads r1 before call).
 */
void RESEARCH_GRAPH_CreateLabels(struct ResearchObjB *graph)
{
    struct ResearchGraphConfig args;
    int i;
    for (i = 0; i < 9; i++) {
        struct BgTextLabel *handle;
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
        graph->label[i] = BgTextLabel_Create((struct BgTextLabelConfig *)(&args), graph->font, graph->msgBank[d_021C3B7C[i].messageIndex], graph->heapId);
        handle = graph->label[i];
        BgTextLabel_PrintMessage(handle, d_021C3B7C[i].messageMode);
    }
}

/*
 * Addresses are Black-image addresses.
 */
void RESEARCH_GRAPH_DestroyLabels(struct ResearchObjB *graph)
{
    int i;
    for (i = 0; i < 9; i++) {
        BgTextLabel_Destroy(graph->label[i]);
        graph->label[i] = 0;
    }
}

void RESEARCH_GRAPH_RegisterEntryResources(struct ResearchObjB *graph)
{
    u16 heap = graph->heapId;
    void *h = ARC_TOOL_CreateHandle(192, heap);
    int a = CLACT_RegisterCharacter((void *)(h), 15, 0, 1, heap);
    int b = CLACT_RegisterPalette((void *)h, 16, 1, 0, heap);
    int c = CLACT_RegisterCellAnim((void *)(h), 14, 17, heap);
    graph->clactUnits[4] = a;
    graph->clactUnits[5] = b;
    graph->clactUnits[6] = c;
    ARC_TOOL_DeleteHandle(h);
}

void RESEARCH_GRAPH_ReleaseEntryResources(struct ResearchObjB *graph)
{
    CLACT_ReleaseCharacter(graph->clactUnits[4]);
    CLACT_ReleasePalette(graph->clactUnits[5]);
    CLACT_ReleaseCellAnim(graph->clactUnits[6]);
}

void RESEARCH_GRAPH_RegisterCursorResources(struct ResearchObjB *graph)
{
    u16 heap = graph->heapId;
    void *h = ARC_TOOL_CreateHandle(192, heap);
    int a = CLACT_RegisterCharacter((void *)(h), 15, 0, 0, heap);
    int b = CLACT_RegisterPaletteEx((void *)(h), 16, 0, 192, 0, 3, heap);
    int c = CLACT_RegisterCellAnim((void *)(h), 14, 17, heap);
    int d;
    ARC_TOOL_DeleteHandle(h);
    h = ARC_TOOL_CreateHandle(83, heap);
    d = CLACT_RegisterPaletteEx((void *)(h), 31, 0, 128, 0, 2, heap);
    ARC_TOOL_DeleteHandle(h);
    graph->clactUnits[0] = a;
    graph->clactUnits[1] = b;
    graph->clactUnits[3] = d;
    graph->clactUnits[2] = c;
}

void RESEARCH_GRAPH_ReleaseCursorResources(struct ResearchObjB *graph)
{
    CLACT_ReleaseCharacter(graph->clactUnits[0]);
    CLACT_ReleasePalette(graph->clactUnits[1]);
    CLACT_ReleasePalette(graph->clactUnits[3]);
    CLACT_ReleaseCellAnim(graph->clactUnits[2]);
}

void RESEARCH_GRAPH_ClearUnits(struct ResearchObjB *graph)
{
    int i;
    for (i = 0; i < 4; i++)
        graph->units[i] = 0;
}

void RESEARCH_GRAPH_CreateUnits(struct ResearchObjB *graph)
{
    int i;
    for (i = 0; i < 4; i++)
        graph->units[i] = CLACT_CreateUnit(d_021C3620[i], d_021C3618[i], graph->heapId);
}

void RESEARCH_GRAPH_DeleteUnits(struct ResearchObjB *graph)
{
    int i;
    for (i = 0; i < 4; i++)
        CLACT_DeleteUnit(graph->units[i]);
}

/*
 * Clear four u32 slots at +0x394.
 *
 * Addresses are Black-image addresses.
 */
void RESEARCH_GRAPH_ClearActors(struct ResearchObjB *graph)
{
    int i;
    for (i = 0; i < 4; i++)
        graph->actor[i] = 0;
}

/*
 * prototype: 0204B294 result observed in r0 despite legacy matched void return.
 */
void RESEARCH_GRAPH_CreateActors(struct ResearchObjB *graph)
{
    struct Arg arg;
    const struct ActorEntry *q;
    int i;
    struct Unit *a; u32 b, c, d;
    for(i=0;i<4;i++) {
        q=&d_021C37FC[i];
        arg.x=q->x; arg.y=q->y; arg.z=q->z; arg.a=q->a; arg.b=q->b;
        a=RESEARCH_GRAPH_GetSharedHandle(graph,q->sharedHandle);
        b=RESEARCH_GRAPH_GetClactUnit(graph,q->unitA);
        c=RESEARCH_GRAPH_GetClactUnit(graph,q->unitB);
        d=RESEARCH_GRAPH_GetClactUnit(graph,q->unitC);
        graph->actor[i]=CLACT_CreateActor(a,b,c,d,(struct ActorInitParam *)(&arg),q->space,graph->heapId);
        CLACT_SetActorDrawEnable(graph->actor[i],0);
    }
}

void RESEARCH_GRAPH_DeleteActors(struct ResearchObjB *graph)
{
    int i;
    for (i = 0; i < 4; i++)
        CLACT_DeleteActor(graph->actor[i]);
}

/*
 * Clear two u32 slots at +0x3b0.
 *
 * Addresses are Black-image addresses.
 */
void RESEARCH_GRAPH_ClearBmps(struct ResearchObjB *graph)
{
    int i;
    for (i = 0; i < 2; i++)
        graph->bmps[i] = 0;
}

void RESEARCH_GRAPH_CreateBmps(struct ResearchObjB *graph)
{
    int i;
    for (i = 0; i < 2; i++)
        graph->bmps[i] = BMP_Create(d_021C37A4[i].x, d_021C37A4[i].y, d_021C37A4[i].z, graph->heapId);
}

void RESEARCH_GRAPH_DrawBmps(struct ResearchObjB *graph)
{
    const struct EntryUnit *q;
    struct Bmp *bmp;
    void *text;
    u16 color;
    int i;
    for(i=0;i<2;i++) {
        q=&d_021C37A4[i];
        if(q->enabled) {
            bmp=BMP_CreateFromArchive(q->arc,q->member,0,graph->heapId);
            BMP_Blit(bmp,graph->bmps[i],0,0,0,0,q->x<<3,q->y<<3,q->b);
            color=((q->r&31)<<10)|((q->g&31)<<5)|(q->b&31);
            text=MSGDATA_AllocString(graph->msgBank[q->bank],q->index);
            PRINTSYS_PrintColor(graph->bmps[i],q->px,q->py,text,graph->font,color);
            GFL_HEAP_Free(text);
            BMP_Delete((struct Bmp *)bmp);
        }
    }
}


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
    u16 *palette;
    u16 *original;
    u8 colorCount;
    u8 pad[11];
};


struct GameComm;


#include "../arm9/game_comm.h"



#define E ((const struct EntryUnit *)gb)

extern const struct Tab d_021C3C54;

extern const struct EntryUnit d_021C37D0;

extern const struct OamObjectRow d_021C377C[];

extern const struct PaletteAnimeBind d_021C3A28[];

void RESEARCH_GRAPH_DrawBadge(struct ResearchObjB *graph)
{
    struct Tab tab = d_021C3C54;
    int i;
    int j;
    struct Bmp *bmp;
    void *text;
    u16 color;
    uptr gb = (uptr)&d_021C37D0;
    bmp = BMP_CreateFromArchive(E->arc, E->member, 0, graph->heapId);
    for (i = 0; i < 3; i++) {
        int y = i * 8;
        for (j = 0; j < 20; j++) {
            BMP_Blit(bmp, graph->bmps[1], (tab.rows[i].cells[j] % 3) * 8, (tab.rows[i].cells[j] / 3) * 8, j * 8, y, 8, 8, 0);
        }
    }
    BMP_Delete((struct Bmp *)bmp);
    color = ((E->r & 31) << 10) | ((E->g & 31) << 5) | (E->b & 31);
    text = MSGDATA_AllocString(graph->msgBank[E->bank], E->index);
    PRINTSYS_PrintColor(graph->bmps[1], E->px, E->py, text, graph->font, color);
    GFL_HEAP_Free(text);
}

void RESEARCH_GRAPH_DeleteBmps(struct ResearchObjB *graph)
{
    int i;
    for (i = 0; i < 2; i++)
        BMP_Delete(graph->bmps[i]);
}

void RESEARCH_GRAPH_CreateOamSys(struct ResearchObjB *graph)
{
    graph->oamSys = BMP_OAM_CreateSys((unsigned int)(graph->heapId), (void *)(graph->units[2]));
}

void RESEARCH_GRAPH_DeleteOamSys(struct ResearchObjB *graph)
{
    BMP_OAM_DeleteSys(graph->oamSys);
}

/*
 * note 2026-10-05 (wave D9r lane 131): removed the 4 dead first assignments
 * (`sysOff=0x3B0;` before `sysOff=0x3A4;`; `outOff=0x3B0;` before
 * `outOff=0x3A8;` and 2 more). Game code has no line table, so these were
 * stand-ins. The plain single assignment gives EXACT in --lang c99 and
 * --lang c: the output bytes do not change. Older text in this header that
 * asks for the double assignment is superseded.
 */
void RESEARCH_GRAPH_CreateOamObjects(struct ResearchObjB *graph)
{
    struct OamObjectParam param;
    int i;
    const struct OamObjectRow *q;
    for(i=0;i<2;i++) {
        param.bmp=graph->bmps[i];
        q=&d_021C377C[i];
        param.x=q->x; param.y=q->y;
        param.animResId=RESEARCH_GRAPH_GetClactUnit(graph,q->clactUnitIndex);
        param.palette=q->palette;
        param.drawPriority=q->drawPriority; param.bgPriority=q->bgPriority;
        param.space=q->space; param.engine=q->engine;
        graph->oamObject[i]=BMP_OAM_Create(graph->oamSys,(struct BmpOamParam *)(&param));
        BMP_OAM_SetEnabled(graph->oamObject[i],0);
        BMP_OAM_UploadChars(graph->oamObject[i]);
    }
}

/*
 * Addresses are Black-image addresses.
 */
void RESEARCH_GRAPH_DeleteOamObjects(struct ResearchObjB *graph)
{
    int i;
    for (i = 0; i < 2; i++)
        BMP_OAM_Delete(graph->oamObject[i]);
}

/*
 * Clear the u32 at +0x3b8.
 *
 * Addresses are Black-image addresses.
 */
void RESEARCH_GRAPH_ClearPalAnm(struct ResearchObjB *graph)
{
    graph->palAnm = 0;
}

void RESEARCH_GRAPH_CreatePalAnm(struct ResearchObjB *graph)
{
    graph->palAnm = PALANM_Create(graph->heapId);
    PALANM_AllocSlotBuffers(graph->palAnm, 0, 512, graph->heapId);
    PALANM_AllocSlotBuffers(graph->palAnm, 2, 512, graph->heapId);
    PALANM_CopyHwPaletteToSlot(graph->palAnm, 0, 0, 512);
    PALANM_CopyHwPaletteToSlot(graph->palAnm, 2, 0, 512);
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
u32 RESEARCH_GRAPH_DeletePalAnm(struct ResearchObjB *graph)
{
    PALANM_FreeSlotBuffers((struct PaletteFade *)(graph->palAnm), 0);
    PALANM_FreeSlotBuffers((struct PaletteFade *)(graph->palAnm), 2);
    return PALANM_Delete((void *)(graph->palAnm));
}

void RESEARCH_GRAPH_ClearPaletteAnime(struct ResearchObjB *graph)
{
    int i;
    for (i = 0; i < 8; i++)
        graph->paletteAnime[i] = 0;
}

void RESEARCH_GRAPH_CreatePaletteAnime(struct ResearchObjB *graph)
{
    int i;
    for (i = 0; i < 8; i++)
        graph->paletteAnime[i] = PALETTE_ANIME_Create(graph->heapId);
}

void RESEARCH_GRAPH_DestroyPaletteAnime(struct ResearchObjB *graph)
{
    int i;
    for (i = 0; i < 8; i++)
        PALETTE_ANIME_Destroy(graph->paletteAnime[i]);
}

void RESEARCH_GRAPH_BindPaletteAnime(struct ResearchObjB *graph)
{
    int i;
    for (i = 0; i < 8; i++)
        PALETTE_ANIME_Bind(graph->paletteAnime[i], d_021C3A28[i].palette, d_021C3A28[i].original, d_021C3A28[i].colorCount);
}

void RESEARCH_GRAPH_RestorePaletteAnime(struct ResearchObjB *graph)
{
    int i;
    for (i = 0; i < 8; i++)
        PALETTE_ANIME_Restore(graph->paletteAnime[i]);
}

/*
 * Reconstructed from the listing.
 *
 * Addresses are Black-image addresses.
 */
void RESEARCH_GRAPH_RestartNetwork(struct ResearchObjB *graph)
{
    GFL_NET_RefreshWmIconAtTopRight(1, graph->heapId);
}

void RESEARCH_GRAPH_RegisterVBlank(struct ResearchObjB *graph)
{
    graph->vblankNode = GFL_USE_AddMainTask(RESEARCH_GRAPH_TransferPalettes, graph, (unsigned int)0);
}

/*
 * Tail-call veneer: forwards arg(s) (u32)(*(u32*)(a0 + 960)), 960 to TCB_DeleteTask.
 *
 * Addresses are Black-image addresses.
 */
void RESEARCH_GRAPH_UnregisterVBlank(struct ResearchObjB *graph)
{
    TCB_DeleteTask(graph->vblankNode);
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
void RESEARCH_GRAPH_OpenComm(struct ResearchObjB *graph)
{
    struct GameComm *comm = GAMESYSTEM_GetGameComm((struct GameSystem *)RESEARCH_GRAPH_GetContext(graph));
    GAME_COMM_SetNotifyFlag(comm, 1);
    if (GAME_COMM_GetKind(comm) == 2) {
    GAME_COMM_RequestExitNoCallback(comm);
    }
}

int RESEARCH_GRAPH_GetCommKindOrStart(struct ResearchObjB *graph)
{
    struct GameSystem *r;
    r = (struct GameSystem *)RESEARCH_GRAPH_GetContext(graph);
    switch (GAME_COMM_GetKind(GAMESYSTEM_GetGameComm(r))) {
    case 0:
        GAMESYSTEM_TryStartAutoComm(r);
        return 1;
    default:
        return 1;
    case 2:
        return 0;
    }
}

void RESEARCH_GRAPH_ClearNotifyFlag(struct ResearchObjB *graph)
{
    GAME_COMM_SetNotifyFlag(GAMESYSTEM_GetGameComm((struct GameSystem *)RESEARCH_GRAPH_GetContext(graph)), 0);
}
