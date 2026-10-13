/*
 * file:     startmenu.c
 * unit:     yes
 * function: func_021B95A0, func_021B95CC, func_021B965C, func_021B9750, func_021B9874, func_021B98BC, func_021B9910, func_021B9928, func_021B9954, func_021B997C, func_021B99E0, func_021B99EC, func_021B9A14, func_021B9A1C, func_021B9BD4, func_021B9C08, func_021B9C2C, func_021B9DD0, func_021B9E54, func_021B9E7C, func_021B9EC4, func_021B9F68, func_021B9F70, func_021B9F94, func_021B9FE4, func_021BA014, func_021BA114, func_021BA1A0, func_021BA218, func_021BA230, func_021BA2C8, func_021BA338, func_021BA4A0, func_021BA540, func_021BA6B0, func_021BA7AC, func_021BA880, func_021BA990, func_021BA9B0, func_021BA9C8, func_021BA9D4, func_021BA9E8, func_021BAB20, func_021BAB64, func_021BAC24, func_021BAC64, func_021BAC74, func_021BACD8, func_021BAD08, func_021BB164, func_021BB184, func_021BB328, func_021BB380, func_021BB474, func_021BB484, func_021BB4B4, func_021BB544, func_021BB5C4, func_021BB5E0, func_021BB608, func_021BB798, func_021BB810, func_021BB840, func_021BB858, func_021BB890, func_021BB9DC, func_021BBA64, func_021BBB84, func_021BBBAC, func_021BBD10, func_021BBD80, func_021BBE3C, func_021BBE48, func_021BBF1C, func_021BBF98, func_021BBFA8, func_021BC024, func_021BC054, func_021BC080, func_021BC0AC, func_021BC0C8, func_021BC0E4, func_021BC0FC, func_021BC114, func_021BC12C, func_021BC230, func_021BC2FC, func_021BC3B8, func_021BC3E4, func_021BC430, func_021BC4A4, func_021BC4EC, func_021BC52C, func_021BC568, func_021BC62C, func_021BC734, func_021BC75C, func_021BC84C, func_021BC870, func_021BC8AC, func_021BC944, func_021BC9C0, func_021BC9E8, func_021BCCBC, func_021BCCCC, func_021BCCF4, func_021BCD64, func_021BCD88, func_021BCDB4, func_021BCDD0, func_021BCDEC, func_021BCE20, func_021BCE3C, func_021BCE70, func_021BCE80, func_021BCF18, func_021BCF44, func_021BCF6C, func_021BCFD4, func_021BCFEC, func_021BD04C, func_021BD078, func_021BD0C8, func_021BD0D8, func_021BD0F4, func_021BD10C, func_021BD118, func_021BD188, func_021BD1EC, func_021BD21C, func_021BD23C
 * address:  0x021B95A0
 * region:   ov088
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0203064C  0x0203064C  arm
 *   func_0203159C  0x0203159C  arm
 *   func_02082BCC  0x02082BCC  arm
 *   func_0204E720  0x0204E720  arm
 *   func_0204363C  0x0204363C  arm
 *   func_02040588  0x02040588  arm
 *   func_02043598  0x02043598  arm
 *   func_020434DC  0x020434DC  arm
 *   func_0201160C  0x0201160C  thumb
 *   func_020362DC  0x020362DC  arm
 *   func_0203630C  0x0203630C  arm
 *   func_02006984  0x02006984  thumb
 *   GFL_USE_FadeOutBgm  0x02005E30  thumb
 *   func_0204E804  0x0204E804  arm
 *   GFL_USE_PlayFanfare  0x02005DAC  thumb
 *   func_02006BD0  0x02006BD0  thumb
 *   GFL_USE_IsBgmFading  0x02005E50  thumb
 *   GFL_USE_CancelChangeAndStopBgm  0x02005D28  thumb
 *   func_020315D4  0x020315D4  arm
 *   func_020306F0  0x020306F0  arm
 *   PROCSYS_ReplaceGlobal  0x020312F8  arm
 *   d_021BD66C     0x021BD66C  data  a4
 *   d_021BD974     0x021BD974  data  a4
 *   d_02184904     0x02184904  data  a4  ov168
 *   ov088_id       0x00000058  data  a1
 *   ov168_id       0x000000A8  data  a1
 *   func_0207D534  0x0207D534  arm
 *   func_02043534  0x02043534  arm
 *   func_020435F4  0x020435F4  arm
 *   func_020433E0  0x020433E0  arm
 *   func_0203FC28  0x0203FC28  arm
 *   d_021BD508     0x021BD508  data  a4  ov088
 *   d_021BD420     0x021BD420  data  a4  ov088
 *   func_0204A648  0x0204A648  arm
 *   func_0203F8F4  0x0203F8F4  arm
 *   func_02045088  0x02045088  arm
 *   func_02046440  0x02046440  arm
 *   func_0201DD60  0x0201DD60  thumb
 *   func_0203101C  0x0203101C  arm
 *   func_020056A0  0x020056A0  thumb
 *   func_0204361C  0x0204361C  arm
 *   func_020310C4  0x020310C4  arm
 *   func_02030EAC  0x02030EAC  arm
 *   func_02031140  0x02031140  arm
 *   func_02046788  0x02046788  arm
 *   func_020450C8  0x020450C8  arm
 *   func_0203F9B4  0x0203F9B4  arm
 *   func_0203FCA0  0x0203FCA0  arm
 *   func_02049624  0x02049624  arm
 *   func_0204989C  0x0204989C  arm
 *   func_02049B40  0x02049B40  arm
 *   func_020409B4  0x020409B4  arm
 *   func_02040C14  0x02040C14  arm
 *   func_02041300  0x02041300  arm
 *   func_020450F0  0x020450F0  arm
 *   func_02045770  0x02045770  arm
 *   func_02043B5C  0x02043B5C  arm
 *   func_02045374  0x02045374  arm
 *   func_02045334  0x02045334  arm
 *   func_0201D7EC  0x0201D7EC  thumb
 *   func_0201C440  0x0201C440  thumb
 *   func_02045B38  0x02045B38  arm
 *   func_020457B0  0x020457B0  arm
 *   func_02045CAC  0x02045CAC  arm
 *   func_0201D304  0x0201D304  thumb
 *   func_0201C724  0x0201C724  thumb
 *   d_021BD470     0x021BD470  data  ov088  a4
 *   d_021BD490     0x021BD490  data  ov088  a4
 *   d_021BD430     0x021BD430  data  ov088  a4
 *   d_021BD450     0x021BD450  data  a4
 *   func_02041EE4  0x02041EE4  arm
 *   GPOWER_GetSpecialPowerId  0x020111E8  thumb
 *   func_02045808  0x02045808  arm
 *   func_02045C04  0x02045C04  arm
 *   func_0201C4C0  0x0201C4C0  thumb
 *   func_0201D83C  0x0201D83C  thumb
 *   func_020452E8  0x020452E8  arm
 *   func_02047CFC  0x02047CFC  arm
 *   func_02047E88  0x02047E88  arm
 *   func_020489F4  0x020489F4  arm
 *   func_02048A18  0x02048A18  arm
 *   func_020477A4  0x020477A4  arm
 *   _ll_mul        0x0209C054  arm
 *   FX_Div         0x0207C768  arm
 *   func_02048A24  0x02048A24  arm
 *   func_02011510  0x02011510  thumb
 *   func_02048BC4  0x02048BC4  arm
 *   func_02048C58  0x02048C58  arm
 *   func_0204044C  0x0204044C  arm
 *   FX_SinCosTable_  0x020A1B38  data
 *   d_021BD410     0x021BD410  data  ov088  a4
 *   d_021BD3EC     0x021BD3EC  data  ov088  a4
 *   d_021BD3F8     0x021BD3F8  data  ov088  a4
 *   d_021BD404     0x021BD404  data  ov088  a4
 *   d_021BD3DC     0x021BD3DC  data  a4
 *   ICA_ANIME_IncFrameNoLoop  0x020115C0  thumb
 *   func_02011B8C  0x02011B8C  thumb
 *   func_02048AD0  0x02048AD0  arm
 *   func_02047964  0x02047964  arm
 *   func_020479D8  0x020479D8  arm
 *   func_02047A60  0x02047A60  arm
 *   func_02047970  0x02047970  arm
 *   func_02047910  0x02047910  arm
 *   d_021BD538     0x021BD538  data  ov088  a4
 *   func_02011558  0x02011558  thumb
 *   func_02048AC4  0x02048AC4  arm
 *   func_02048C4C  0x02048C4C  arm
 *   func_020480E4  0x020480E4  arm
 *   func_02047E54  0x02047E54  arm
 *   func_020115EC  0x020115EC  thumb
 *   func_0204784C  0x0204784C  arm
 *   func_020490F4  0x020490F4  arm
 *   func_0204A48C  0x0204A48C  arm
 *   func_0204B100  0x0204B100  arm
 *   CLACT_SetUnitDefaultRenderer  0x0204B270  arm
 *   func_0204A6C8  0x0204A6C8  arm
 *   func_0204ABF0  0x0204ABF0  arm
 *   func_0204AF28  0x0204AF28  arm
 *   func_0204B294  0x0204B294  arm
 *   func_0204B92C  0x0204B92C  arm
 *   func_02049238  0x02049238  arm
 *   d_020A1448     0x020A1448  data  a4
 *   func_0204A600  0x0204A600  arm
 *   func_0204A8D4  0x0204A8D4  arm
 *   func_0204ADA4  0x0204ADA4  arm
 *   func_0204AFD8  0x0204AFD8  arm
 *   func_0204B1CC  0x0204B1CC  arm
 *   func_0204A5AC  0x0204A5AC  arm
 *   func_020070A4  0x020070A4  thumb
 *   func_02008730  0x02008730  thumb
 *   func_0200C0F0  0x0200C0F0  thumb
 *   func_02009210  0x02009210  thumb
 *   GAME_DATA_GetEventWorkFromSave  0x02012FE4  thumb
 *   d_021BD63C     0x021BD63C  data  ov088  a4
 *   GAME_BEACON_RegisterClearCallback  0x020274C8  thumb
 *   func_02030734  0x02030734  arm
 *   d_021BDA00     0x021BDA00  data  ov088  a1
 *   d_021DF538     0x021DF538  data  ov121  a4
 *   d_02213C4C     0x02213C4C  data  a4
 *   d_0209DEF0     0x0209DEF0  data  a4
 *   d_021D77AC     0x021D77AC  data  ov016  a4
 *   d_021F6D78     0x021F6D78  data  ov107  a4
 *   d_021BD574     0x021BD574  data  a4
 *   ov121_id       0x00000079  data
 *   ov199_id       0x000000C7  data
 *   ov016_id       0x00000010  data
 *   ov107_id       0x0000006B  data
 *   func_02009448  0x02009448  thumb
 *   func_020092EC  0x020092EC  thumb
 *   func_0200C2F0  0x0200C2F0  thumb
 *   func_0203D210  0x0203D210  arm
 *   func_020221A4  0x020221A4  thumb
 *   func_0201C4E4  0x0201C4E4  thumb
 *   func_0201C6C4  0x0201C6C4  thumb
 *   func_0201C6B4  0x0201C6B4  thumb
 *   BLINK_PALANM_Update  0x0202EA40  thumb
 *   func_020061E4  0x020061E4  thumb
 *   func_0203633C  0x0203633C  arm
 *   BLINK_PALANM_ResetPhase  0x0202EB04  thumb
 *   func_020090E0  0x020090E0  thumb
 *   func_0201FEBC  0x0201FEBC  thumb
 *   func_0202EB44  0x0202EB44  thumb
 *   func_0202EB0C  0x0202EB0C  thumb
 *   func_02040EBC  0x02040EBC  arm
 *   d_021BD784     0x021BD784  data  ov088  a4
 *   func_020419E4  0x020419E4  arm
 *   SDK_AUTOLOAD_DTCM_START 0x02FE0000 data
 *   BG_SYS_ClearGraphicsMemory  0x0204335C  arm
 *   d_021BD60C     0x021BD60C  data  ov088  a4
 *   d_021BD678     0x021BD678  data  a4
 *   d_021BD724     0x021BD724  data  a4
 *   d_021BD764     0x021BD764  data  a4
 *   d_021BD6C4     0x021BD6C4  data  a4
 *   d_021BD6E4     0x021BD6E4  data  a4
 *   d_021BD744     0x021BD744  data  a4
 *   d_021BD6A4     0x021BD6A4  data  a4
 *   d_021BD704     0x021BD704  data  a4
 *   func_020403F4  0x020403F4  arm
 *   func_02049B68  0x02049B68  arm
 *   func_02049658  0x02049658  arm
 *   func_020498F4  0x020498F4  arm
 *   func_0201F5BC  0x0201F5BC  thumb
 *   BLINK_PALANM_Create  0x0202E940  thumb
 *   BLINK_PALANM_LoadPalettes  0x0202E9AC  thumb
 *   func_0202EA20  0x0202EA20  thumb
 *   func_0201EC64  0x0201EC64  thumb
 *   func_02028590  0x02028590  thumb
 *   func_02028604  0x02028604  thumb
 *   func_0201ED04  0x0201ED04  thumb
 *   func_02045EC0  0x02045EC0  arm
 *   func_0201F02C  0x0201F02C  thumb
 *   func_0201F250  0x0201F250  thumb
 *   func_0201F158  0x0201F158  thumb
 *   func_0201EFA4  0x0201EFA4  thumb
 *   func_02008550  0x02008550  thumb
 *   ZONEDATA_Init  0x020139B0  thumb
 *   func_020142E8  0x020142E8  thumb
 *   func_02008854  0x02008854  thumb
 *   func_02008848  0x02008848  thumb
 *   func_0200890C  0x0200890C  thumb
 *   func_02013E4C  0x02013E4C  thumb
 *   ZONEDATA_Exit  0x02013A48  thumb
 *   func_02008748  0x02008748  thumb
 *   func_0200864C  0x0200864C  thumb
 *   func_02008650  0x02008650  thumb
 *   func_0200CA10  0x0200CA10  thumb
 *   func_0200D0AC  0x0200D0AC  thumb
 *   func_0200C258  0x0200C258  thumb
 *   d_021BD7C4     0x021BD7C4  data  a1
 *   func_0204B3DC  0x0204B3DC  arm
 *   d_021BD688     0x021BD688  data  a4
 *   d_021BD5DC     0x021BD5DC  data  a4
 *   d_021BD5E4     0x021BD5E4  data  a4
 *   d_021BD5D4     0x021BD5D4  data  a4
 *   func_0204B3B4  0x0204B3B4  arm
 *   BGWINFRM_Create  0x0202C9B4  thumb
 *   BGWINFRM_AddFrame  0x0202CA3C  thumb
 *   BGWINFRM_PutBmpWin  0x0202CEBC  thumb
 *   d_021BD5EC     0x021BD5EC  data  a4
 *   BGWINFRM_Delete  0x0202CA0C  thumb
 *   func_0207D63C  0x0207D63C  arm
 *   func_020071EC  0x020071EC  thumb
 *   func_0200C308  0x0200C308  thumb
 *   func_02049EF4  0x02049EF4  arm
 *   func_02082A60  0x02082A60  arm
 *   func_020307B0  0x020307B0  arm
 *   func_0204B454  0x0204B454  arm
 *   func_0204B404  0x0204B404  arm
 *   func_020410D0  0x020410D0  arm
 *   BGWINFRM_GetFrameBuffer  0x0202CF84  thumb
 *   func_02041B6C  0x02041B6C  arm
 *   func_020413B0  0x020413B0  arm
 *   _s32_div_f     0x0209C0A4  arm
 *   func_02041570  0x02041570  arm
 *   func_0201F73C  0x0201F73C  thumb
 *   func_02012FFC  0x02012FFC  thumb
 *   func_0201CCE4  0x0201CCE4  thumb
 *   func_02045730  0x02045730  arm
 *   func_0201F7A8  0x0201F7A8  thumb
 *   func_020286C4  0x020286C4  thumb
 *   func_0201CE30  0x0201CE30  thumb
 *   func_0201CE5C  0x0201CE5C  thumb
 *   func_0201CE38  0x0201CE38  thumb
 *   func_0201CE48  0x0201CE48  thumb
 *   func_0201FDA0  0x0201FDA0  thumb
 *   func_0202208C  0x0202208C  thumb
 *   func_020071E8  0x020071E8  thumb
 *   d_021BD818     0x021BD818  data  a4
 *   d_021BD824     0x021BD824  data  a4
 *   func_021BD25C  0x021BD25C  thumb  ov088
 *   func_02007220  0x02007220  thumb
 *   func_0200846C  0x0200846C  thumb
 *   CONFIG_Create  0x020082EC  thumb
 *   func_0216BFD4  0x0216BFD4  thumb  ov010
 *   PROCSYS_Create  0x02031324  arm
 *   func_02034AC4  0x02034AC4  arm
 *   func_02034A5C  0x02034A5C  arm
 *   GFL_USE_LoadWaveArcSet  0x02005A98  thumb
 *   PM_VOICE_Prepare  0x020069D4  thumb
 *   ov194_id       0x000000C2  data
 *   ov204_id       0x000000CC  data
 *   d_021F557C     0x021F557C  data  ov194  a4
 *   d_021F558C     0x021F558C  data  ov194  a4
 *   d_021BFD20     0x021BFD20  data  ov204  a4
 *   d_021BFD30     0x021BFD30  data  ov204  a4
 *   func_021BD2F4  0x021BD2F4  thumb  ov088
 *   PROCSYS_Main  0x02031330  arm
 *   PROCSYS_Push  0x02031348  arm
 *   d_021BFD24     0x021BFD24  data  ov204  a4
 *   d_021F5580     0x021F5580  data  ov194  a4
 *   func_02005B04  0x02005B04  thumb
 *   func_02008494  0x02008494  thumb
 *   func_0200873C  0x0200873C  thumb
 *   CONFIG_Copy  0x02008314  thumb
 *   func_0203133C  0x0203133C  arm
 *   func_02007210  0x02007210  thumb
 *   func_021DFC20  0x021DFC20  thumb  ov228
 *   func_021DFE90  0x021DFE90  thumb  ov228
 *   func_021DFEB0  0x021DFEB0  thumb  ov228
 *   func_021DFDB8  0x021DFDB8  thumb  ov228
 *   GAMESYSTEM_SetupInitWork  0x02011EEC  thumb
 *   func_0216C0C0  0x0216C0C0  thumb  ov010
 *   ov228_id       0x000000E4  data
 *   d_0209DF9C     0x0209DF9C  data  a4
 *   PROCSYS_PushGlobal  0x020312CC  arm
 *   CONFIG_SetBattleFlag  0x02008450  thumb
 *   d_021BD830     0x021BD830  data  a4
 *   CONFIG_GetBattleFlag  0x02008448  thumb
 *   func_0200C31C  0x0200C31C  thumb
 *   SAVE_CONTROL_Reload  0x020070C8  thumb
 *   CONFIG_ApplyAppliedFlag  0x02008414  thumb
 *   func_0200C324  0x0200C324  thumb
 *   func_020084E4  0x020084E4  thumb
 *   func_0200854C  0x0200854C  thumb
 *   func_02005728  0x02005728  thumb
 *   func_0200852C  0x0200852C  thumb
 *   func_0203F0A8  0x0203F0A8  arm
 *   func_02008558  0x02008558  thumb
 *   CONFIG_SetAppliedFlag  0x020083EC  thumb
 *   d_021BD8B8     0x021BD8B8  data  ov088  a4
 *   d_021BD848     0x021BD848  data  a4
 *   d_021BD858     0x021BD858  data  a4
 *   d_021BD878     0x021BD878  data  a4
 *   d_021BD898     0x021BD898  data  a4
 *   func_020414AC 0x020414AC arm
 *   func_0201C7A4  0x0201C7A4  thumb
 *   func_02035C08  0x02035C08  arm
 *   d_021BD83C     0x021BD83C  data  a1
 *   tbl_020A1B38   0x020A1B38  data
 *   func_02061CA4  0x02061CA4  arm
 *   d_021BD944     0x021BD944  data  a4
 *   d_021BD8F4     0x021BD8F4  data  a4
 *   d_021BD904     0x021BD904  data  a4
 *   d_021BD924     0x021BD924  data  a4
 *   TIME_ICON_Update  0x0202F0B0  thumb
 *   d_021BDA20     0x021BDA20  data  a4
 *   func_0202EE30  0x0202EE30  thumb
 *   func_02005654  0x02005654  thumb
 *   func_021DFF18  0x021DFF18  thumb  ov228
 *   func_02007230  0x02007230  thumb
 *   SAVE_CONTROL_LoadExtraSave  0x0200725C  thumb
 *   SAVE_CONTROL_EraseExtraSave  0x02007400  thumb
 *   func_020072A4  0x020072A4  thumb
 *   func_0200566C  0x0200566C  thumb
 *   func_02087BCC  0x02087BCC  arm
 *   d_021BD9B0     0x021BD9B0  data  a4
 *   d_021BD980     0x021BD980  data  a4
 *   d_021BD990     0x021BD990  data  a4
 *   func_020461E4  0x020461E4  arm
 *   func_020461D4  0x020461D4  arm
 *   func_02013080  0x02013080  thumb
 *   func_020351F8  0x020351F8  arm
 *   d_021BDA0C     0x021BDA0C  data  ov088  a4
 *   d_021BD3B9     0x021BD3B9  data  ov088  a1
 *   SAVE_CONTROL_StartSave  0x02007150  thumb
 *   func_02008764  0x02008764  thumb
 *   func_02007218  0x02007218  thumb
 *   func_02007214  0x02007214  thumb
 *   func_0200721C  0x0200721C  thumb
 *   BACKUP_SYSTEM_IsFlashBusy  0x02031E70  arm
 *   SAVE_CONTROL_MainSave  0x02007168  thumb
 *   func_021BD29C  0x021BD29C  thumb  ov088
 */

#define reg_G3X_DISP3DCNT (*(volatile u16 *)0x04000060)
#define REG_G3X_DISP3DCNT_GO_MASK  0x00002000
#define REG_G3X_DISP3DCNT_RO_MASK  0x00001000
#define REG_G3X_DISP3DCNT_AAE_MASK 0x00000010
#define REG_G3X_DISP3DCNT_ABE_MASK 0x00000008
#define REG_G3X_DISP3DCNT_ATE_MASK 0x00000004
struct Proc;
struct IcaAnime;
struct S020315D4;
struct DispConfig;
struct DispVram;
struct Tcbl;
struct Node;
struct S02031140;
struct Descriptor;
struct Cfg;
struct CharBuf;
struct GfFont;
struct MsgBank;
struct StrObj;
struct U16Vec;
struct PrintSys;
struct Rec;
struct G3dSys;
struct LightSet;
struct LightSlot;
struct IcaAnime;
struct Light;
struct Arg;
struct Ctx;
struct AnmCtl;
struct Bank;
struct ClactActor;
struct SaveControl;
struct MyStatus;
struct Sub02009210Obj;
struct Sub020071CCCtrl;
struct Sub02009448Obj;
struct Blk34;
struct Row;
struct CodeIn;
struct Sub020090B0Obj;
struct BgTemplate;
struct PalAnm;
struct WordSet;
struct PlayTime;
struct Sub02008828Obj;
struct Blk37;
struct Sub02008828Rec;
struct WinMgr;
struct Sub020071E4Ctrl;
struct Actor;
struct PtS;
struct Vec2;
struct Rec3;
typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed short s16;

typedef signed int     s32;

typedef unsigned char  u8;

typedef signed char s8;

#include "startmenu_types.h"

typedef struct BgTemplate {
    u32 w[8];
} BgTemplate;

typedef long long      s64;

typedef int            fx32;

typedef int            BOOL;

typedef struct { fx32 x, y, z; } VecFx32;

typedef struct {
    unsigned short x;
    unsigned short y;
    unsigned short animSeq;
    unsigned char priority;
    unsigned char palOffset;
} ClactInitData;

typedef int (*StateFn)(StartMenuWork *);

typedef struct {
    u32 flagMask;
    u32 msgId;
} NoticeEntry;

typedef unsigned long OsIrqWord;

typedef struct DispConfigBlock {
    u32 w[4];
} DispConfigBlock;

typedef struct BgTemplateBlock {
    u32 w[8];
} BgTemplateBlock;

/* VRAM bank configuration words. */
typedef struct DispVramBlock {
    u32 w[12];
} DispVramBlock;

struct WindowTemplateEntry {
    u8 bgId, x, y, width, height, palette;
};

typedef struct ClactResConfig {
    u32 w[7];
} ClactResConfig;

struct RowInfo {
    u16 frameId;
    u16 height;
};

typedef struct {
    s16 x;
    s16 y;
} SpritePos;


typedef struct YesNoWindowTemplate {
    unsigned char bgId;
    unsigned char x;
    unsigned char y;
    unsigned char palette;
    unsigned short tileOffset;
} YesNoWindowTemplate;

extern void func_0203064C(unsigned int a, unsigned int heap, unsigned int size);
extern void *func_0203159C(struct Proc *obj, u32 size, u32 heap);
extern void  func_02082BCC(void *p, int v, int n);
extern void func_0204E720(u32 a, s32 b, s32 c, s32 d);
extern void func_0204363C(u32 swap);
extern void func_02040588(u32 which, unsigned char enable);
extern void func_02043598(u32 mask, u32 enable);
extern void func_020434DC(u32 mask, u32 enable);
extern u32 func_0201160C(struct IcaAnime *p);
extern u32   func_020362DC(void);
extern unsigned int func_0203630C(void);
extern u32 func_02006984(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7);
extern void GFL_USE_FadeOutBgm(u32 a);
extern int  func_0204E804(void);
extern void GFL_USE_PlayFanfare(void *arg);
extern u32  func_02006BD0(u32 a);
extern int  GFL_USE_IsBgmFading(void);
extern void GFL_USE_CancelChangeAndStopBgm(void);
extern void func_020315D4(struct S020315D4 *a);
extern void func_020306F0(unsigned int a);
extern void PROCSYS_ReplaceGlobal(u32 a1, u32 a2, u32 a3);
extern void func_0207D534(volatile u16 *reg, int brightness);
extern void func_02043534(u32 planes);
extern void func_020435F4(u32 planes);
extern void func_020433E0(const struct DispVram *c);
extern void func_0203FC28(struct DispConfig *cfg);
extern void func_0204A648(void);
extern void func_0203F8F4(int);
extern void func_02045088(int);
extern void func_02046440(int, int, int, int, int, int, int);
extern void func_0201DD60(void);
extern void *func_0203101C(int, int, int, int);
extern void *func_020056A0(void *, void *, int);
extern void func_0204361C(void);
void func_020310C4(struct Tcbl *p);
extern void func_02030EAC(struct Node *n);
extern void func_02031140(struct S02031140 *p);
extern void func_02046788(void);
extern void func_020450C8(void);
extern void func_0203F9B4(void);
extern void func_0203FCA0(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void func_02049624(u32 a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g);
extern void func_0204989C(u32 a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g);
extern void func_02049B40(u32 a, u32 b, u32 c, u32 d, u32 e, u32 f);
extern void func_020409B4(u32 layer);
extern void func_02040C14(u32 layer, u32 value, u32 count, u32 index);
extern void func_02041300(u32 index, u32 a1, u8 a2, u8 a3, u8 a4, u8 a5, u32 a6);
extern u32 func_020450F0(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_02045374(struct Cfg *cfg);
extern void func_02045334(struct Descriptor *d);
extern struct GfFont *func_0201D7EC(int a0, int a1, int a2, int a3, u32 heapId);
extern u32 func_0201C440(void *p);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern u32 func_0201D304(struct StrObj *s, u32 a, u32 b);
extern void func_0201C724(void *owner, u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern void func_02041EE4(u32 index, u32 a, u32 b);
extern u32 GPOWER_GetSpecialPowerId(void);
extern void func_02045808(struct U16Vec *vec);
extern unsigned int func_02045C04(struct Rec *rec);
extern void func_0201C4C0(struct PrintSys *p);
extern u32 func_0201D83C(void *ptr);
extern u32 func_020452E8(struct Descriptor *d);
extern u32   func_02047CFC(u32 a, u32 b, u32 heap);
extern u16   func_02047E88(u32 a, const void *b);
extern u32 func_020489F4(u8 *a0, int i);
extern u32   func_02048A18(u32 a, u16 b);
extern u32 func_020477A4(struct G3dSys *sys, u32 idx);
extern fx32  FX_Div(fx32 numer, fx32 denom);
extern void *func_02048A24(int a, int s, int c, int d, int e, int f, int g, int h,
                           VecFx32 *pos, VecFx32 *up, VecFx32 *tgt, int heap);
extern void *func_02011510(u32 heap, u32 a1, u32 a2, u32 a3);
extern struct LightSlot *func_02048BC4(const struct LightSet *s, u32 heap);
extern void func_02048C58(struct LightSlot *slots);
extern void func_0204044C(u32 mode);
extern u32 ICA_ANIME_IncFrameNoLoop(struct IcaAnime *p, s32 v);
extern void func_02011B8C(void *, void *);
extern void func_02048AD0(struct Light *l);
extern void func_02047964(void);
extern void func_020479D8(void);
extern void func_02047A60(void *a0, struct Arg *a1);
extern void func_02047970(void);
extern int func_02047910(void *a, int idx, int amount);
extern void func_02011558(struct IcaAnime *p);
extern u32 func_02048AC4(void *ptr);
extern void func_02048C4C(int);
extern void func_020480E4(struct Ctx *c, u32 i);
extern void func_02047E54(struct Rec *p);
extern void func_020115EC(struct IcaAnime *p, s32 v);
extern u32 func_0204784C(struct AnmCtl *c, u16 idx, s32 *frame);
extern void *func_020490F4(unsigned int id, unsigned int heap);
extern void func_0204A48C(const struct Cfg *cfg, unsigned int arg, unsigned int heapId);
extern struct Bank *func_0204B100(int count, u8 flag, unsigned int heapId);
extern void CLACT_SetUnitDefaultRenderer(struct Bank *bank);
extern int func_0204A6C8(void *, int, int, int, int);
extern int func_0204ABF0(void *, int, int, int, int);
extern s32 func_0204AF28(void *owner, u32 first, u32 second, u32 mode);
extern int func_0204B294(int, int, int, int, ClactInitData *, int, int);
extern void func_0204B92C(struct ClactActor *p, u32 v);
extern void func_02049238(void *);
void func_0204A600(void);
extern void func_0204A8D4(u32 i);
extern void func_0204ADA4(u32 i);
extern void func_0204AFD8(u32 i);
extern u32 func_0204B1CC(struct Bank *bank);
extern void func_0204A5AC(void);
extern struct SaveControl *func_020070A4(void);
extern struct MyStatus *func_02008730(void *sys);
extern void *func_0200C0F0(void *sys);
extern struct Sub02009210Obj *func_02009210(void *sys);
extern void *GAME_DATA_GetEventWorkFromSave(struct Sub020071CCCtrl *a0);
extern void GAME_BEACON_RegisterClearCallback(void);
extern void func_021BC114(void);
extern void func_021BC0FC(void);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern struct Sub02009448Obj *func_02009448(void *sys);
extern u8 func_020092EC(const struct Sub02009210Obj *obj);
extern void func_0200C2F0(struct Blk34 *p, u32 i, u8 v);
extern u32 func_0203D210(void);
extern u32 func_020221A4(void);
extern u32 func_0201C4E4(struct PrintSys *ps);
extern u32 func_0201C6C4(struct PrintSys *p, void *v);
extern u32 func_0201C6B4(const struct PrintSys *p);
extern s32 BLINK_PALANM_Update(struct Row *p);
extern void func_020061E4(u32);
extern unsigned int func_0203633C(void);
extern void BLINK_PALANM_ResetPhase(struct CodeIn *p);
extern u8 func_020090E0(const struct Sub020090B0Obj *obj);
extern u32 func_0201FEBC(u8 *);
extern int func_0202EB44(void);
extern u32 func_0202EB0C(void);
extern void func_02040EBC(u32 a0, u32 a1);
extern void func_020419E4(void);
extern void BG_SYS_ClearGraphicsMemory(u32 keep);
extern void func_020403F4(u32 i);
extern void func_02049B68(void *a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern u32 func_02049658(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_020498F4(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_0201F5BC(u32 a, u32 b, u32 c, u32 d, u16 e);
extern struct CodeIn *BLINK_PALANM_Create(u16 a0, u16 a1, u32 a2, u16 heap);
extern void BLINK_PALANM_LoadPalettes(struct CodeIn *p, u8 *a1, u32 a2, u32 a3, u32 a4);
extern u32 func_0202EA20(struct PalAnm *p);
extern struct WordSet *func_0201EC64(u32 heap);
extern u32 func_02028590(u32, u32, u32, u32);
extern int func_02028604(int a0);
extern unsigned int func_0201ED04(struct WordSet *p);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void func_0201F02C(struct WordSet *p, u32 i, void *a);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void func_0201F158(struct WordSet *p, u32 i, u32 v);
extern void func_0201EFA4(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern u8 func_02008550(const struct MyStatus *obj);
extern void ZONEDATA_Init(u32 heap);
extern u32 func_020142E8(void *bitmap, s32 id);
extern struct Sub02008828Obj *func_02008854(void *sys);
extern u16 *func_02008848(void *);
extern void func_0200890C(void *sys, struct Sub02008828Rec *dest);
extern u32 func_02013E4C(u32 id);
extern void ZONEDATA_Exit(void);
extern struct PlayTime *func_02008748(void *sys);
extern u16 func_0200864C(const struct PlayTime *p);
extern u8 func_02008650(const struct PlayTime *p);
extern void *func_0200CA10(void *);
extern u32 func_0200D0AC(struct Blk37 *p, u32 heap);
extern u32 func_0200C258(struct Blk34 *p);
extern void func_0204B3DC(struct ClactActor *p, u32 v);
extern void func_0204B3B4(struct ClactActor *p);
extern struct WinMgr *BGWINFRM_Create(u32 a0, u32 a1, u32 heap);
extern void BGWINFRM_AddFrame(struct WinMgr *mgr, u32 idx, u32 bg, u32 w, u32 h);
extern void BGWINFRM_PutBmpWin(struct WinMgr *mgr, u32 idx, void *a);
extern void BGWINFRM_Delete(struct WinMgr *mgr);
extern void func_0207D63C(void *reg, int a, int b, int c, int d);
extern u8 func_020071EC(const struct Sub020071E4Ctrl *ctrl);
extern u8 func_0200C308(struct Blk34 *p, u32 i);
extern void *func_02049EF4(void *o, u32 a, u32 b, void **out, u16 e);
extern void func_02082A60(void *srcp, void *destp, unsigned long size);
extern u32 func_020307B0(void *p);
extern void func_0204B454(struct Actor *actor, struct PtS *out, u16 space);
extern void func_0204B404(struct ClactActor *p, const struct Vec2 *delta, u32 which);
extern void func_020410D0(u32 index, u32 a1, u32 a2, u32 a3, u8 a4, u32 a5, u8 a6, u8 a7, u8 a8, u8 a9);
extern u32 BGWINFRM_GetFrameBuffer(struct WinMgr *mgr, u32 idx);
extern void func_02041B6C(u32);
extern void func_020413B0(u32, u32, u8, u8, u8, u32);
extern void func_02041570(int channel, u16 val);
extern void func_0201F73C(void *a0, int a1, int a2, int a3);
extern signed char func_02012FFC(void);
extern u32 func_0201CCE4(u32 a0, u32 a1, u32 a2, u32 a3, u32 a5, u32 a6, u32 a7,
                         u32 a8, u16 a9, u16 a10);
extern u8 func_02045730(struct Descriptor *p);
extern void func_0201F7A8(void *desc, u32 kind);
extern void func_020286C4(struct Ctx *ctx, void *p, void *cell);
extern u32 func_0201CE30(void *p);
extern void func_0201CE5C(struct Rec *p, s32 v);
extern void func_0201CE38(void *);
extern void func_0201CE48(struct Rec3 *p);
extern void *func_0201FDA0(YesNoWindowTemplate *win, int base, int pal, int pos, int heap);
extern void func_0202208C(void *, unsigned, unsigned, unsigned, unsigned, unsigned, unsigned);
extern u32 func_020071E8(const struct Sub020071E4Ctrl *ctrl);
int func_021B95A0(struct Proc *a0);
void func_021B95CC(TitleDemoWork *work);
void func_021B965C(TitleDemoWork *work);
int func_021B9750(int a0, int a1, int a2, TitleDemoWork *work);
int func_021B9874(int a0, int a1, int a2, int *a3);
void func_021B98BC(void);
void func_021B9910(void);
void func_021B9928(TitleDemoWork *work);
void func_021B9954(void *task, TitleDemoCapture *capture);
void func_021B997C(TitleDemoCapture *capture, int heap);
void func_021B99E0(TitleDemoCapture *capture, int unused);
void func_021B99EC(TitleDemoCapture *capture);
void func_021B9A14(TitleDemoCapture *capture, unsigned short a, unsigned short b);
void func_021B9A1C(TitleDemoLogo *logo, u32 heap);
void func_021B9BD4(TitleDemoLogo *logo, int unused);
void func_021B9C08(TitleDemoLogo *logo);
void func_021B9C2C(TitleDemo3d *demo3d, u32 heap);
void func_021B9DD0(TitleDemo3d *demo3d, int unused);
void func_021B9E54(TitleDemo3d *demo3d);
void func_021B9E7C(TitleDemo3d *demo3d, int x);
void func_021B9EC4(TitleDemoSprites *sprites, int heap);
void func_021B9F68(TitleDemoSprites *sprites, int unused);
void func_021B9F70(TitleDemoSprites *sprites);
int func_021B9F94(struct Proc *a);
int func_021B9FE4(int a0, int a1, int a2, StartMenuWork *work);
int func_021BA014(int a0, int a1, int a2, StartMenuWork *work);
int func_021BA114(StartMenuWork *work);
int func_021BA1A0(StartMenuWork *work);
int func_021BA218(StartMenuWork *work);
int func_021BA230(StartMenuWork *work);
int func_021BA2C8(StartMenuWork *work);
int func_021BA338(StartMenuWork *work);
int func_021BA4A0(StartMenuWork *work);
int func_021BA540(StartMenuWork *work);
int func_021BA6B0(StartMenuWork *work);
int func_021BA7AC(StartMenuWork *work);
int func_021BA880(StartMenuWork *work);
int func_021BA984(StartMenuWork *work);
void func_021BA990(void);
void func_021BA9B0(StartMenuWork *work);
void func_021BA9C8(StartMenuWork *work);
void func_021BA9D4(void);
void func_021BA9E8(void);
void func_021BAB20(void);
void func_021BAB64(void);
void func_021BAC24(StartMenuWork *work);
void func_021BAC64(StartMenuWork *work);
void func_021BAC74(StartMenuWork *work);
void func_021BACD8(StartMenuWork *work);
void func_021BAD08(StartMenuWork *work);
void func_021BB164(StartMenuWork *work);
void func_021BB184(StartMenuWork *work);
void func_021BB328(StartMenuWork *work);
void func_021BB380(StartMenuWork *work);
void func_021BB474(StartMenuWork *work);
void func_021BB484(void);
void func_021BB4B4(StartMenuWork *work);
void func_021BB544(StartMenuWork *work);
void func_021BB5C4(StartMenuWork *work);
void func_021BB5E0(StartMenuWork *work, u32 idx, s16 y);
void func_021BB608(StartMenuWork *work);
void func_021BB798(StartMenuWork *work, u32 i, u32 arg);
void func_021BB810(StartMenuWork *work, u8 row, int y, int pal);
int func_021BB840(StartMenuWork *work, int y);
void func_021BB858(StartMenuWork *work, int d);
int func_021BB890(StartMenuWork *work, int d);
void func_021BB9DC(StartMenuWork *work, int flag);
void func_021BBA64(u8 x, u8 y, u8 w, u8 h, u8 bg);
void func_021BBB84(u8 x, u8 y, u8 w, u8 h, u8 bg);
void func_021BBBAC(StartMenuWork *work);
void func_021BBD10(StartMenuWork *work, int mode);
void func_021BBD80(StartMenuWork *work);
void func_021BBE3C(StartMenuWork *work);
void func_021BBE48(StartMenuWork *work);
void func_021BBF1C(StartMenuWork *work, u32 a1);
void func_021BBF98(StartMenuWork *work);
int func_021BBFA8(StartMenuWork *work);
void func_021BC024(StartMenuWork *work);
int func_021BC054(StartMenuWork *work, int v);
int func_021BC080(StartMenuWork *work, int v);
int func_021BC0AC(StartMenuWork *work, int v);
int func_021BC0C8(StartMenuWork *work);
void func_021BC0E4(void);
extern char d_021BD66C[];
extern char d_021BD974[];
extern char d_02184904[];
extern char ov088_id[];
extern char ov168_id[];
extern char d_021BD508[];
extern char d_021BD420[];
extern const BgTemplate d_021BD470;
extern const BgTemplate d_021BD490;
extern const BgTemplate d_021BD430;
extern const BgTemplate d_021BD450;
extern const s16 FX_SinCosTable_[];
extern const u32 d_021BD410[];
extern VecFx32 d_021BD3EC;
extern VecFx32 d_021BD3F8;
extern VecFx32 d_021BD404;
extern const u32 d_021BD3DC[];
extern char d_021BD538[];
extern char d_020A1448[];
extern StateFn d_021BD63C[];
extern char d_021BDA00[];
extern char d_021DF538[];
extern char d_02213C4C[];
extern char d_0209DEF0[];
extern char d_021D77AC[];
extern char d_021F6D78[];
extern char d_021BD574[];
extern char ov121_id[];
extern char ov199_id[];
extern char ov016_id[];
extern char ov107_id[];
extern const NoticeEntry d_021BD784[8];
extern char SDK_AUTOLOAD_DTCM_START[];
extern char d_021BD60C[];
extern DispConfigBlock d_021BD678;
extern BgTemplateBlock d_021BD724;
extern BgTemplateBlock d_021BD764;
extern BgTemplateBlock d_021BD6C4;
extern BgTemplateBlock d_021BD6E4;
extern BgTemplateBlock d_021BD744;
extern BgTemplateBlock d_021BD6A4;
extern BgTemplateBlock d_021BD704;
extern const struct WindowTemplateEntry d_021BD7C4[];
extern ClactResConfig d_021BD688;
extern char d_021BD5DC[];
extern char d_021BD5E4[];
extern char d_021BD5D4[];
extern const struct RowInfo d_021BD5EC[];
extern char d_021BD818[];

#define reg_G2_BLDCNT      (*(volatile u16 *)0x04000050)
#define reg_G2S_DB_BLDCNT  (*(volatile u16 *)0x04001050)
#define reg_GX_DISPCNT     (*(volatile u32 *)0x04000000)
#define reg_GXS_DB_DISPCNT (*(volatile u32 *)0x04001000)
struct Sub02008700Obj;
struct S020314B8;
struct Ctrl;
struct Sub020072A4Ctrl;
struct Sub02007168;
/* Three world coordinates (x, y, z) of the player. */
typedef struct LocationPos {
    u32 x, y, z;
} LocationPos;

/* Player location block of the save data: map, position and facing. */
typedef struct SaveLocation {
    u16 mapId;
    u16 pad02;
    LocationPos position;
    u32 spawnX, spawnY;
    s16 facing;
    s16 spawnFlags;
} SaveLocation;
typedef unsigned long long u64;
typedef enum { Z0 } Zero;

extern void func_02005B04(const u32 *arg);
extern void func_02008494(void *, void *);
extern struct Sub02008700Obj *func_0200873C(void *sys);
extern void CONFIG_Copy(void *, void *);
extern void func_0203133C(struct S020314B8 *p);
extern u8 func_02007210(const struct Sub020071E4Ctrl *ctrl);
extern int func_02034AC4(signed int overlayId);
extern void func_02034A5C(int overlayId);
extern void *func_021DFC20(u32 heap);
extern u8 func_021DFE90(u8 *p);
extern void func_021DFEB0(char *p, void *ctrl);
extern void func_021DFDB8(void *);
extern void *GAMESYSTEM_SetupInitWork(u32 a0, u16 a1, LocationPos *position, int a3);
extern int func_0216C0C0(int);
extern void PROCSYS_PushGlobal(u32 a0, u32 a1, u32 a2);
extern void CONFIG_SetBattleFlag(struct Config *config, int on);
extern unsigned int CONFIG_GetBattleFlag(const struct Config *config);
extern u8 func_0200C31C(struct Blk34 *p);
extern int SAVE_CONTROL_Reload(char *self);
extern u8 CONFIG_ApplyAppliedFlag(const struct Config *config);
extern void func_0200C324(struct Blk34 *p, u8 v);
extern void func_020084E4(u16 *out, struct U16Vec *vec);
extern void func_0200854C(int, int);
extern u32 func_02005728(u32 range);
extern void func_0200852C(struct MyStatus *obj, u32 value);
extern u32 func_0203F0A8(void);
extern void func_02008558(struct MyStatus *obj, u8 value);
extern void CONFIG_SetAppliedFlag(struct Config *config, unsigned int on);
extern void func_020414AC(int a);
extern void func_0201C7A4(void *x, s16 y, s16 z, void *s, void *w);
extern int func_02035C08(const void *p);
extern s32 func_02061CA4(void *p, u32 a, u32 b, s32 size);
extern void TIME_ICON_Update(u8 *p);
extern u8 *func_0202EE30(void *owner, void *a1, u8 a2, u8 a3, volatile u16 heap);
extern int func_02005654(int a, int b);
extern void func_021DFF18(u32 heap);
extern void *func_02007230(struct Sub020071E4Ctrl *ctrl);
extern u32 SAVE_CONTROL_LoadExtraSave(struct Ctrl *ctrl, u32 id, u8 heap);
extern void SAVE_CONTROL_EraseExtraSave(char *a0, u32 a1, u32 a2);
extern void func_020072A4(struct Sub020072A4Ctrl *ctrl, u32 id);
extern void func_0200566C(void);
extern void func_02087BCC(u32 parameter);
extern u8 func_020461E4(void);
extern void func_020461D4(u8);
extern signed char func_02013080(u32 idx);
extern void func_020351F8(u32 a, u32 b);
int SAVE_CONTROL_StartSave(int a0);
void func_02008764(void *);
u8 func_02007218(const struct Sub020071E4Ctrl *ctrl);
void func_02007214(void *, u32);
void func_0200721C(void *, u32);
extern int BACKUP_SYSTEM_IsFlashBusy(void);
extern u32 SAVE_CONTROL_MainSave(struct Sub02007168 *p);
int func_021BC2FC(struct S020315D4 *proc, int *seq, void *procWork, NewGameIntroWork *work);
int func_021BC3B8(struct Proc *a0);
int func_021BC3E4(void *proc, int *seq, int mode, NewGameIntroWork *work);
int func_021BC430(struct S020315D4 *proc, int seq, int mode, NewGameIntroWork *work);
void func_021BC4A4(struct MyStatus *myStatus, struct Strbuf *name, int gender);
int func_021BC4EC(struct Proc *proc, int seq, int *procWork);
int func_021BC52C(int proc, int seq, int procWork, ConfigPromptWork *work);
int func_021BC568(int proc, int seq, NewGameStartArg *startArg, ConfigPromptWork *work);
void func_021BC62C(ConfigPromptWork *work);
void func_021BC734(const void *bgTemplate, int bgId);
void func_021BC75C(ConfigPromptWork *work);
void func_021BC84C(ConfigPromptWork *work);
void func_021BC870(ConfigPromptWork *work);
int func_021BC8AC(ConfigPromptWork *work);
s32 func_021BC944(ConfigPromptWork *work);
int func_021BC9C0(struct Proc *proc);
int func_021BC9E8(int proc, int seq, int *variant, LogoScreenWork *work);
int func_021BCCBC(int proc);
int func_021BCCCC(struct Proc *proc);
int func_021BCCF4(int proc, int *seq, int procWork, SaveEraseWork *work);
int func_021BCD64(int proc);
void func_021BCD88(SaveEraseWork *work, int *seq);
void func_021BCDB4(SaveEraseWork *work, int *seq);
void func_021BCDD0(SaveEraseWork *work, int *seq);
void func_021BCDEC(SaveEraseWork *work, int *seq);
void func_021BCE20(SaveEraseWork *work, int *seq);
void func_021BCE3C(SaveEraseWork *work, int *seq);
void func_021BCE70(void);
void func_021BCE80(SaveEraseWork *work, int *seq);
void func_021BCF18(SaveEraseWork *work, int *seq);
void func_021BCF44(void);
void func_021BCF6C(void);
void func_021BCFD4(void);
void func_021BCFEC(SaveEraseWork *work);
void func_021BD04C(SaveEraseWork *work);
void func_021BD078(SaveEraseWork *work);
void func_021BD0C8(SaveEraseWork *work);
void func_021BD0D8(void);
void func_021BD0F4(SaveEraseWork *work);
void func_021BD10C(SaveEraseWork *work);
void func_021BD118(SaveEraseWork *work, u32 messageId);
int func_021BD188(SaveEraseWork *work);
void func_021BD1EC(SaveEraseWork *work);
void func_021BD21C(void);
void func_021BD23C(void);
extern u8 ov228_id[];
extern char d_0209DF9C[];
extern char d_021BD830[];
extern char d_021BD8B8[];
extern char d_021BD848[];
extern char d_021BD858[];
extern char d_021BD878[];
extern char d_021BD898[];
extern TouchHitTable d_021BD83C;
extern s16 tbl_020A1B38[];
extern const u8 d_021BD944[];
extern const u8 d_021BD8F4[];
extern const u8 d_021BD904[];
extern const u8 d_021BD924[];
extern void *d_021BDA20;
extern DispVramBlock d_021BD9B0;
extern DispConfigBlock d_021BD980;
extern BgTemplateBlock d_021BD990;
struct SaveControl;
struct ProcSys;
struct ProcData;
struct Config;
struct MyStatus;
struct WaveArcSet;
struct Strbuf;
extern struct SaveControlIntr *func_021BD25C(int heapId, struct SaveControl *saveControl);
extern void *func_02007220(struct SaveControl *saveControl);
extern struct MyStatus *func_0200846C(int heapId);
extern struct Config *CONFIG_Create(int heapId);
extern NameInArgs *func_0216BFD4(unsigned short heapId, int kind, short species, short traits, int maxLen, struct Strbuf *initialName, void *pokedex);
extern struct ProcSys *PROCSYS_Create(int heapId);
extern struct WaveArcSet *GFL_USE_LoadWaveArcSet(const u32 *ids, u32 count);
extern int PM_VOICE_Prepare(int a0, int a1, int a2, int a3, int a5, int a6, int a7, int a8);
extern u32 func_021BD2F4(struct SaveControlIntr *saveIntr);
extern unsigned int PROCSYS_Main(struct ProcSys *procSys);
extern void PROCSYS_Push(struct ProcSys *procSys, u32 overlayId, const struct ProcData *data, void *procWork);
int func_021BC12C(struct Proc *proc);
int func_021BC230(void *proc, int *seq, void *procWork, NewGameIntroWork *work);
extern const struct ProcData d_021BD824;
extern u8 ov194_id[];
extern u8 ov204_id[];
extern u32 d_021F557C;
extern u32 d_021F558C[];
extern u32 d_021BFD20;
extern u32 d_021BFD30[];
extern const struct ProcData d_021BFD24;
extern const struct ProcData d_021F5580;
extern void func_021BD29C(void *p);







int func_021B95A0(struct Proc *allocator)
{
    TitleDemoWork *work;

    func_0203064C(1, 0x16, 0x120000);
    work = func_0203159C(allocator, 0x98, 0x16);
    func_02082BCC(work, 0, 0x98);
    work->heapId = 0x16;
    return 1;
}






void func_021B95CC(TitleDemoWork *work)
{
    if (work->frameCount == 0x29A) {
        func_0204E720(12, 16, 0, 3);
        func_0204363C(1);
        func_02040588(6, 0);
        func_02043598(16, 0);
        func_020434DC(8, 0);
        work->phase = 1;
    }
    if (work->phase == 2 && func_0201160C((struct IcaAnime *)work->demo3d.anime) == 0x015F3000)
        func_021B9E7C(&work->demo3d, 0x14B5);
    work->frameCount += 1;
    if (work->frameCount > 0x1248) {
        work->result = 1;
        work->state = 5;
    }
}






void func_021B965C(TitleDemoWork *work)
{
    if ((func_020362DC() & 0xB) && work->phase == 1) {
        func_0204363C(0);
        func_02040588(6, 1);
        func_02040588(3, 1);
        func_02043598(0x10, 1);
        func_021B9E7C(&work->demo3d, 0x14B5);
        work->phase = 2;
        return;
    }
    if (func_020362DC() & 9) {
        work->result = 0;
        work->state = 4;
        work->fanfareHandle = (void *)func_02006984(0x283, 0, 0x40, 0, 0, 0, 0, 0);
        func_021B9E7C(&work->demo3d, 0x1389);
        func_0204363C(0);
        func_02040588(6, 1);
        func_02043598(0x10, 0);
        func_0204E720(0xC, 0x10, 0, 3);
        GFL_USE_FadeOutBgm(4);
        func_021B9A14(&work->capture, 8, 8);
        return;
    }
    if (func_0203630C() == 0x46) {
        work->result = 2;
        work->state = 5;
    } else if (func_0203630C() == 0xC80) {
        work->result = 3;
        work->state = 5;
    }
}






int func_021B9750(int unusedArg0, int unusedArg1, int unusedArg2, TitleDemoWork *work)
{
    switch (work->state) {
    case 0:
        func_021B98BC();
        func_021B9910();
        work->state = 1;
        break;
    case 1:
        func_021B997C(&work->capture, work->heapId);
        func_021B9A1C(&work->logo, work->heapId);
        func_021B9C2C(&work->demo3d, work->heapId);
        func_021B9EC4(&work->sprites, work->heapId);
        func_0204E720(3, 0x10, 0, 2);
        work->frameCount = 0;
        work->state = 2;
        GFL_USE_PlayFanfare((void *)0x3EF);
        break;
    case 2:
        if (func_0204E804() == 0) {
            work->state = 3;
        }
        func_021B9928(work);
        break;
    case 3:
        func_021B9928(work);
        func_021B965C(work);
        func_021B95CC(work);
        break;
    case 4:
        if (func_02006BD0((unsigned int)work->fanfareHandle) == 0) {
            work->state = 5;
        }
        func_021B9928(work);
        break;
    case 5:
        func_0204E720(3, 0, 0x10, 2);
        work->state = 6;
        func_021B9928(work);
        GFL_USE_FadeOutBgm(0x10);
        break;
    case 6:
        if (func_0204E804() == 0 && GFL_USE_IsBgmFading() == 0) {
            GFL_USE_CancelChangeAndStopBgm();
            work->state = 7;
        }
        func_021B9928(work);
        break;
    case 7:
        func_021B9F70(&work->sprites);
        func_021B9E54(&work->demo3d);
        func_021B9C08(&work->logo);
        func_021B99EC(&work->capture);
        return 1;
    case 8:
        return 1;
    }
    return 0;
}






int func_021B9874(int procCtx, int unusedArg1, int unusedArg2, int *procArgs)
{
    int target = procArgs[1];

    func_020315D4((struct S020315D4 *)procCtx);
    func_020306F0(0x16);
    if (target == 0) {
        PROCSYS_ReplaceGlobal((u32)ov088_id, (u32)d_021BD66C, 0);
    } else if (target == 2) {
        PROCSYS_ReplaceGlobal((u32)ov088_id, (u32)d_021BD974, 0);
    } else if (target == 3) {
        PROCSYS_ReplaceGlobal((u32)ov168_id, (u32)d_02184904, 0);
    }
    return 1;
}






void func_021B98BC(void)
{
    func_0207D534((volatile u16 *)0x0400006C, -16);
    func_0207D534((volatile u16 *)0x0400106C, -16);
    func_02043534(0);
    func_020435F4(0);
    *(u16 *)0x04000050 = 0;
    *(u16 *)0x04001050 = 0;
    *(u32 *)0x04000000 &= 0xFFFF1FFF;
    *(u32 *)0x04001000 &= 0xFFFF1FFF;
}






void func_021B9910(void)
{
    func_020433E0((const struct DispVram *)d_021BD508);
    func_0203FC28((struct DispConfig *)d_021BD420);
}






void func_021B9928(TitleDemoWork *work)
{
    func_021B99E0(&work->capture, work->heapId);
    func_021B9BD4(&work->logo, work->heapId);
    func_021B9DD0(&work->demo3d, work->heapId);
    func_021B9F68(&work->sprites, work->heapId);
}






void func_021B9954(void *task, TitleDemoCapture *capture)
{
    func_0204A648();
    *(volatile unsigned int *)0x04000064 = (short)capture->captureEva | (0xC0330000 | ((short)capture->captureEvb << 8));
}






void func_021B997C(TitleDemoCapture *capture, int heap)
{
    func_0203F8F4(heap);
    func_02045088(heap);
    func_02046440(0, 2, 0, 2, 0x1000, heap, 0);
    func_0201DD60();
    capture->taskList = (int)func_0203101C(heap, heap, 4, 0x20);
    capture->vblankTask = (int)func_020056A0((void *)func_021B9954, capture, 5);
    func_0204363C(0);
    func_0204361C();
    capture->captureEva = 12;
    capture->captureEvb = 4;
}











void func_021B99E0(TitleDemoCapture *capture, int unused)
{
    func_020310C4((struct Tcbl *)capture->taskList);
}











void func_021B99EC(TitleDemoCapture *capture)
{
    func_0204363C(1);
    func_0204361C();
    func_02030EAC((struct Node *)capture->vblankTask);
    func_02031140((struct S02031140 *)capture->taskList);
    func_02046788();
    func_020450C8();
    func_0203F9B4();
}










void func_021B9A14(TitleDemoCapture *capture, unsigned short a, unsigned short b)
{
    capture->captureEva = a;
    capture->captureEvb = b;
}











void func_021B9A1C(TitleDemoLogo *logo, u32 heap)
{
    int textWidth;

    func_0203FCA0(3, &d_021BD470, 0);
    func_0203FCA0(5, &d_021BD490, 0);
    func_0203FCA0(7, &d_021BD430, 0);
    func_0203FCA0(6, &d_021BD450, 0);
    func_02049624(0x1A, 9, 3, 0, 0, 1, heap);
    func_0204989C(0x1A, 10, 3, 0, 0, 1, heap);
    func_02049B40(0x1A, 8, 0, 0, 0, heap);
    func_020409B4(3);
    func_02040588(3, 1);
    func_02049624(0x1A, 0, 7, 0, 0x8000, 1, heap);
    func_0204989C(0x1A, 1, 7, 0, 0, 1, heap);
    func_02049B40(0x1A, 2, 4, 0, 0, heap);
    func_020409B4(7);
    func_02040588(7, 1);
    func_0204989C(0x1A, 3, 6, 0, 0, 1, heap);
    func_02040588(6, 1);
    func_02040C14(5, 0, 1, 0);
    func_02041300(5, 0, 0, 0, 0x20, 0x20, 0x11);
    logo->textWindow = func_020450F0(5, 0, 0x13, 0x20, 2, 0xA, 0);
    logo->textBitmap = (u32)func_02045770((struct Descriptor *)logo->textWindow);
    func_02043B5C((struct CharBuf *)logo->textBitmap, 0);
    func_02045374((struct Cfg *)logo->textWindow);
    func_02045334((struct Descriptor *)logo->textWindow);
    logo->windowDirty = 0;
    logo->textWindowCopy = logo->textWindow;
    func_020409B4(5);
    logo->font = (u32)func_0201D7EC(0x17, 0, 0, 0, heap);
    logo->printer = func_0201C440((void *)heap);
    logo->msgBank = (u32)func_02045B38(0, 2, 0xB5, heap);
    logo->titleText = (u32)func_020457B0(0x40, heap);
    func_02045CAC((struct MsgBank *)logo->msgBank, 1, (void *)logo->titleText);
    textWidth = func_0201D304((struct StrObj *)logo->titleText, logo->font, 0);
    func_0201C724((void *)logo->printer, logo->textBitmap, (s16)(0x80 - textWidth / 2), (s16)0, logo->titleText, logo->font, 0x440);
    logo->ready = 1;
}











void func_021B9BD4(TitleDemoLogo *logo, int unused)
{
    func_02040588(5, 0);
    func_02041EE4(6, 0, logo->bgScroll / 2);
    if (GPOWER_GetSpecialPowerId() == 0x15) {
        logo->bgScroll++;
    } else {
        logo->bgScroll--;
    }
}











void func_021B9C08(TitleDemoLogo *logo)
{
    func_02045808((struct U16Vec *)logo->titleText);
    func_02045C04((struct Rec *)logo->msgBank);
    func_0201C4C0((struct PrintSys *)logo->printer);
    func_0201D83C((void *)logo->font);
    func_020452E8((struct Descriptor *)logo->textWindow);
}











static inline void G3X_AntiAlias(BOOL enable)
{
    if (enable) {
        reg_G3X_DISP3DCNT = (u16)(reg_G3X_DISP3DCNT &
                                  ~(REG_G3X_DISP3DCNT_RO_MASK | REG_G3X_DISP3DCNT_GO_MASK) |
                                  REG_G3X_DISP3DCNT_AAE_MASK);
    } else {
        reg_G3X_DISP3DCNT &= (u16)~(REG_G3X_DISP3DCNT_AAE_MASK |
                                    REG_G3X_DISP3DCNT_RO_MASK | REG_G3X_DISP3DCNT_GO_MASK);
    }
}











static inline void G3X_AlphaTest(BOOL enable, int ref)
{
    if (enable) {
        reg_G3X_DISP3DCNT = (u16)(reg_G3X_DISP3DCNT &
                                  ~(REG_G3X_DISP3DCNT_RO_MASK | REG_G3X_DISP3DCNT_GO_MASK) |
                                  REG_G3X_DISP3DCNT_ATE_MASK);
        *(volatile u16 *)0x04000340 = (u16)ref;
    } else {
        reg_G3X_DISP3DCNT &= (u16)~(REG_G3X_DISP3DCNT_ATE_MASK |
                                    REG_G3X_DISP3DCNT_RO_MASK | REG_G3X_DISP3DCNT_GO_MASK);
    }
}











static inline void G3X_AlphaBlend(BOOL enable)
{
    if (enable) {
        reg_G3X_DISP3DCNT = (u16)(reg_G3X_DISP3DCNT &
                                  ~(REG_G3X_DISP3DCNT_RO_MASK | REG_G3X_DISP3DCNT_GO_MASK) |
                                  REG_G3X_DISP3DCNT_ABE_MASK);
    } else {
        reg_G3X_DISP3DCNT &= (u16)~(REG_G3X_DISP3DCNT_ABE_MASK |
                                    REG_G3X_DISP3DCNT_RO_MASK | REG_G3X_DISP3DCNT_GO_MASK);
    }
}











static inline fx32 FX_Mul(fx32 a, fx32 b)
{
    return (fx32)(((s64)a * b + 0x800LL) >> 12);
}











/*
 * Levers: the four ortho bounds bound to locals before the func_02048A24
 * call (inline in the argument list they evaluate in another order); the
 * sin/cos pair read as FX_SinCosTable_[0x2AA]/[0x2AB] (pool word base +
 * 0x540); d_021BD3DC without its ov088 token (contested hint).
 * volatile: 0x04000060 (DISP3DCNT) read-modify-written by the G3X_AntiAlias,
 *           G3X_AlphaTest and G3X_AlphaBlend inlines at 0x021B9D80-0x021B9D9C
 */
void func_021B9C2C(TitleDemo3d *demo3d, u32 heap)
{
    int base;
    fx32 sinValue;
    fx32 cosValue;
    fx32 scaledSin;
    fx32 top;
    fx32 bottom;
    fx32 left;
    fx32 right;

    demo3d->renderer = func_02047CFC(7, 3, heap);
    demo3d->modelId = func_02047E88(demo3d->renderer, d_021BD410);
    base = func_020489F4((u8 *)demo3d->renderer, demo3d->modelId);
    func_020477A4((struct G3dSys *)func_02048A18(demo3d->renderer, base), 0);
    func_020477A4((struct G3dSys *)func_02048A18(demo3d->renderer, base), 1);
    func_020477A4((struct G3dSys *)func_02048A18(demo3d->renderer, base + 1), 0);
    func_020477A4((struct G3dSys *)func_02048A18(demo3d->renderer, base + 2), 0);

    cosValue = FX_SinCosTable_[0x2AB];
    sinValue = FX_SinCosTable_[0x2AA];
    scaledSin = FX_Mul(sinValue, 0x19A);
    top = FX_Div(scaledSin, cosValue);
    bottom = -FX_Div(scaledSin, cosValue);
    right = FX_Div(FX_Mul(FX_Div(0x223, 0x1000), sinValue), cosValue);
    left = -FX_Div(FX_Mul(FX_Div(0x223, 0x1000), sinValue), cosValue);
    demo3d->camera = func_02048A24(1, top, bottom, left, right,
                           0x19A, 0x800000, 0x19A,
                           &d_021BD3EC, &d_021BD3F8, &d_021BD404, heap);
    demo3d->anime = (u32)func_02011510(heap, 0xA0, 0xE9, 0xA);
    demo3d->lightSet = (u32)func_02048BC4((const struct LightSet *)d_021BD3DC, heap);
    func_02048C58((struct LightSlot *)demo3d->lightSet);
    func_0204044C(1);
    G3X_AntiAlias(1);
    G3X_AlphaTest(0, 0);
    G3X_AlphaBlend(1);
}










void func_021B9DD0(TitleDemo3d *demo3d, int unused)
{
    int base;
    unsigned modelIndex;
    void *modelHandle;
    base = func_020489F4((void *)demo3d->renderer, demo3d->modelId);
    ICA_ANIME_IncFrameNoLoop((void *)demo3d->anime, 0x1000);
    func_02011B8C((void *)demo3d->camera, (void *)demo3d->anime);
    func_02048AD0((void *)demo3d->camera);
    func_02047964();
    func_020479D8();
    for (modelIndex = 0; modelIndex < 3; modelIndex++) {
        modelHandle = (void *)func_02048A18((u32)((void *)demo3d->renderer), (unsigned short)(base + modelIndex));
        func_02047A60(modelHandle, (struct Arg *)d_021BD538);
    }
    func_02047970();
    for (modelIndex = 0; modelIndex < 3; modelIndex++) {
        modelHandle = (void *)func_02048A18((u32)((void *)demo3d->renderer), (unsigned short)(base + modelIndex));
        func_02047910(modelHandle, 0, 0x1000);
        if (modelIndex == 0)
            func_02047910(modelHandle, 1, 0x1000);
    }
}










/*
 * note:     listing extent (40) runs 2 bytes past the compiled function (38);
 *           trailing alignment padding, no byte difference.
 */
void func_021B9E54(TitleDemo3d *demo3d)
{
    func_02011558((struct IcaAnime *)demo3d->anime);
    func_02048AC4((void *)demo3d->camera);
    func_02048C4C(demo3d->lightSet);
    func_020480E4((struct Ctx *)demo3d->renderer, demo3d->modelId);
    func_02047E54((struct Rec *)demo3d->renderer);
}










void func_021B9E7C(TitleDemo3d *demo3d, int frame)
{
    int frameValue;
    int base;
    unsigned modelIndex;
    void *modelHandle;
    frameValue = frame << 12;
    func_020115EC((void *)demo3d->anime, frameValue);
    base = func_020489F4((void *)demo3d->renderer, demo3d->modelId);
    for (modelIndex = 0; modelIndex < 3; modelIndex++) {
        modelHandle = (void *)func_02048A18((u32)((void *)demo3d->renderer), (unsigned short)(base + modelIndex));
        func_0204784C(modelHandle, 0, &frameValue);
        if (modelIndex == 0)
            func_0204784C(modelHandle, 1, &frameValue);
    }
}









void func_021B9EC4(TitleDemoSprites *sprites, int heap)
{
    ClactInitData initData;
    void *archive;
    archive = func_020490F4(0x1a, heap);
    func_0204A48C((const struct Cfg *)d_020A1448, (unsigned int)d_021BD508, heap);
    sprites->unit = (int)func_0204B100(0x40, 0, heap);
    CLACT_SetUnitDefaultRenderer((void *)sprites->unit);
    sprites->charRes = func_0204A6C8(archive, 5, 1, 1, heap);
    sprites->paletteRes = func_0204ABF0(archive, 4, 1, 0, heap);
    sprites->cellRes = func_0204AF28(archive, 6, 7, heap);
    initData.x = 0x80;
    initData.y = 0x60;
    initData.animSeq = 0;
    initData.palOffset = 0;
    initData.priority = 0;
    sprites->actor = func_0204B294(sprites->unit, sprites->charRes, sprites->paletteRes, sprites->cellRes, &initData, 1, heap);
    func_0204B92C((struct ClactActor *)sprites->actor, 1);
    func_02043598(0x10, 1);
    func_02049238(archive);
}









void func_021B9F68(TitleDemoSprites *sprites, int unused)
{
    func_0204A600();
}









void func_021B9F70(TitleDemoSprites *sprites)
{
    func_0204A8D4(sprites->charRes);
    func_0204ADA4(sprites->paletteRes);
    func_0204AFD8(sprites->cellRes);
    func_0204B1CC((struct Bank *)sprites->unit);
    func_0204A5AC();
}









int func_021B9F94(struct Proc *allocator)
{
    StartMenuWork *work;
    func_0203064C(1, 0xb, 0x80000);
    work = func_0203159C(allocator, 0x150, 0xb);
    func_02082BCC(work, 0, 0x150);
    work->saveData = (void *)func_020070A4();
    work->playerData = (void *)func_02008730(work->saveData);
    work->unlockData = (void *)func_0200C0F0(work->saveData);
    work->connectData = (void *)func_02009210(work->saveData);
    work->eventWork = (void *)GAME_DATA_GetEventWorkFromSave((struct Sub020071CCCtrl *)work->saveData);
    return 1;
}









int func_021B9FE4(int unusedArg0, int unusedArg1, int unusedArg2, StartMenuWork *work)
{
    int nextState = d_021BD63C[work->state](work);
    work->state = nextState;
    if (nextState == 12) {
        return 1;
    }
    func_020310C4((struct Tcbl *)(work->taskList));
    func_0204A600();
    return 0;
}









int func_021BA014(int procCtx, int unusedArg1, int unusedArg2, StartMenuWork *work)
{
    u8 selectedRow = work->selectedRow;
    u8 hasSave = work->connectResult;
    char *procArgs;

    func_020315D4((struct S020315D4 *)procCtx);
    func_020306F0(0xb);
    switch (selectedRow) {
    case 0:
        GAME_BEACON_RegisterClearCallback();
        if (hasSave == 0)
            func_021BC114();
        else
            func_021BC0FC();
        break;
    case 1:
        GAME_BEACON_RegisterClearCallback();
        func_021BC0E4();
        break;
    case 2:
        PROCSYS_ReplaceGlobal((int)ov121_id, (u32)d_021DF538, 0);
        break;
    case 3:
        procArgs = func_02030734(1, 0x14, 0, d_021BDA00, 0x200);
        func_02082BCC(procArgs, 0, 0x14);
        ((StartMenuOv199Args *)procArgs)->selection = 0;
        ((StartMenuOv199Args *)procArgs)->fromTitleMenu = 1;
        PROCSYS_ReplaceGlobal((int)ov199_id, (u32)d_02213C4C, (u32)procArgs);
        break;
    case 4:
        PROCSYS_ReplaceGlobal(-1, (u32)d_0209DEF0, 0);
        break;
    case 5:
        PROCSYS_ReplaceGlobal((int)ov016_id, (u32)d_021D77AC, 0);
        break;
    case 6:
        PROCSYS_ReplaceGlobal((int)ov168_id, (u32)d_02184904, 0);
        break;
    case 7:
        procArgs = func_02030734(1, 8, 1, d_021BDA00, 0x216);
        ((StartMenuOv107Args *)procArgs)->fromTitleMenu = 1;
        PROCSYS_ReplaceGlobal((int)ov107_id, (u32)d_021F6D78, (u32)procArgs);
        break;
    default:
        PROCSYS_ReplaceGlobal((int)ov088_id, (u32)d_021BD574, 0);
        break;
    }
    return 1;
}









int func_021BA114(StartMenuWork *work)
{
    unsigned short z;
    if (func_020092EC((const struct Sub02009210Obj *)func_02009448((void *)work->saveData)) == 1)
        func_0200C2F0((struct Blk34 *)work->unlockData, 2, 2);
    z = 0;
    func_02043534(0);
    func_020435F4(0);
    *(unsigned short *)0x04000050 = z;
    *(unsigned short *)0x04001050 = z;
    func_0204363C(1);
    func_021BA9D4();
    func_021BA9E8();
    func_021BAB64();
    func_021BAC74(work);
    func_021BB4B4(work);
    func_021BB544(work);
    func_021BAD08(work);
    func_021BB184(work);
    func_021BB380(work);
    func_021BB608(work);
    func_021BAC24(work);
    func_021BB484();
    func_021BA9B0(work);
    return 4;
}









int func_021BA1A0(StartMenuWork *work)
{
    unsigned s;
    s = work->subState;
    switch (s) {
    case 0:
        work->subState = s + 1;
    case 1:
        if (func_0203D210() != 0) {
            func_021BA9C8(work);
            func_021BAC64(work);
            func_021BB474(work);
            func_021BB328(work);
            func_021BB164(work);
            func_021BB5C4(work);
            func_021BACD8(work);
            func_021BAB20();
            *(unsigned short *)0x04000050 = 0;
            *(unsigned short *)0x04001050 = 0;
            func_02043534(0);
            func_020435F4(0);
            return 12;
        }
    }
    return 1;
}









int func_021BA218(StartMenuWork *work)
{
    if (func_020221A4() == 1) {
        return work->nextStateAfterFade;
    }
    return 2;
}









int func_021BA230(StartMenuWork *work)
{
    switch (work->selectAnimPhase) {
    case 0:
    case 2:
        if (work->selectAnimTimer == 0) {
            func_021BB810(work, work->rowIds[work->cursorIndex],
                          func_021BB840(work, work->cursorTileY), 3);
            work->selectAnimTimer = 4;
            work->selectAnimPhase = work->selectAnimPhase + 1;
        } else {
            work->selectAnimTimer -= 1;
        }
        break;
    case 1:
    case 3:
        if (work->selectAnimTimer == 0) {
            func_021BB810(work, work->rowIds[work->cursorIndex],
                          func_021BB840(work, work->cursorTileY), 1);
            work->selectAnimTimer = 4;
            work->selectAnimPhase = work->selectAnimPhase + 1;
        } else {
            work->selectAnimTimer -= 1;
        }
        break;
    case 4:
        return work->nextStateAfterAnim;
    }
    return 3;
}









/*
 * note:     listing extent (112) runs 2 bytes past the compiled function (110);
 *           trailing alignment padding, no byte difference.
 */
int func_021BA2C8(StartMenuWork *work)
{
    unsigned i;
    void *t;
    func_0201C4E4(work->printSys);
    for (i = 0; i < 14; i++) {
        t = work->printSys;
        if (work->windows[i].textPending != 0 && func_0201C6C4(t, func_02045770(work->windows[i].window)) == 0) {
            func_02045334(work->windows[i].window);
            work->windows[i].textPending = 0;
        }
    }
    if (func_0201C6B4(work->printSys) == 1) {
        if (func_021BC0C8(work) == 1)
            return 10;
        return func_021BC054(work, 5);
    }
    return 4;
}









int func_021BA338(StartMenuWork *work)
{
    BLINK_PALANM_Update(work->blinkPalAnm);
    if (func_020362DC() & 1) {
        func_020061E4(0x54c);
        switch (work->rowIds[work->cursorIndex]) {
        case 0:
            work->selectedRow = work->rowIds[work->cursorIndex];
            return func_021BC0AC(work, 7);
        case 1:
            return func_021BC0AC(work, 8);
        case 2:
            work->selectedRow = work->rowIds[work->cursorIndex];
            return func_021BC0AC(work, 11);
        case 3:
            func_0200C2F0((struct Blk34 *)(work->unlockData), 1, 2);
            work->selectedRow = work->rowIds[work->cursorIndex];
            return func_021BC0AC(work, 11);
        case 4:
            func_0200C2F0((struct Blk34 *)(work->unlockData), 2, 2);
            work->selectedRow = work->rowIds[work->cursorIndex];
            return func_021BC0AC(work, 11);
        case 7:
            func_0200C2F0((struct Blk34 *)(work->unlockData), 3, 2);
            work->selectedRow = work->rowIds[work->cursorIndex];
            return func_021BC0AC(work, 11);
        case 5:
            return func_021BC0AC(work, 9);
        case 6:
            work->selectedRow = work->rowIds[work->cursorIndex];
            return func_021BC0AC(work, 11);
        }
    }
    if (func_020362DC() & 2) {
        func_020061E4(0x551);
        work->selectedRow = 8;
        return func_021BC080(work, 1);
    }
    if (func_0203633C() & 0x40) {
        if (func_021BB890(work, -1) == 1) {
            func_020061E4(0x548);
            return 6;
        }
    }
    if (func_0203633C() & 0x80) {
        if (func_021BB890(work, 1) == 1) {
            func_020061E4(0x548);
            return 6;
        }
    }
    return 5;
}









int func_021BA4A0(StartMenuWork *work)
{
    if (work->scrollStep == 3) {
        work->scrollStep = 0;
        work->scrollSpeed = 0;
        BLINK_PALANM_ResetPhase((struct CodeIn *)(work->blinkPalAnm));
        func_021BB810(work, work->rowIds[work->cursorIndex],
                      func_021BB840(work, work->cursorTileY), 2);
        return 5;
    }
    work->scrollPixels += work->scrollSpeed;
    if (work->scrollPixels < 0)
        work->scrollPixels += 0x200;
    else if (work->scrollPixels >= 0x200)
        work->scrollPixels -= 0x200;
    func_02041EE4(1, 3, work->scrollPixels);
    func_02041EE4(2, 3, work->scrollPixels);
    func_021BB858(work, -work->scrollSpeed);
    work->scrollStep = work->scrollStep + 1;
    return 6;
}









/*
 * The two 0/-2 result tests are small switches: their compare chain puts
 * both bodies after a shared `b` to the tail, which the outer switch's
 * out-of-range `bhi` reuses. The countdown is `-= 1` (re-reads the byte).
 */
int func_021BA540(StartMenuWork *work)
{
    void *printSys;
    u32 menuResult;
    switch (work->subState) {
    case 0:
        func_020434DC(6, 0);
        func_021BB9DC(work, 0);
        if (func_020090E0(work->connectData) == 0) {
            work->connectResult = 1;
            work->subState = 0;
            return func_021BC080(work, 1);
        }
        work->delay = 8;
        work->subState = work->subState + 1;
        break;
    case 1:
        if (work->delay != 0) {
            work->delay -= 1;
            break;
        }
        func_021BBF1C(work, 0x1a);
        func_021BBD80(work);
        work->subState = work->subState + 1;
        break;
    case 2:
        if (func_021BBFA8(work) == 0) {
            func_021BC024(work);
            work->subState = work->subState + 1;
        }
        break;
    case 3:
        menuResult = func_0201FEBC(work->yesNoMenu);
        switch (menuResult) {
        case 0:
            if (func_0202EB44() == 0) {
                func_021BBF1C(work, 0x11);
                work->subState = 5;
            } else {
                work->connectResult = 0;
                work->subState = 4;
            }
            break;
        case (u32)-2:
            func_021BBF1C(work, 0x1b);
            work->subState = 7;
            break;
        }
        break;
    case 4:
        func_021BBE3C(work);
        func_021BBF98(work);
        work->subState = 0;
        return func_021BC080(work, 1);
    case 5:
        if (func_021BBFA8(work) == 0)
            work->subState = work->subState + 1;
        break;
    case 6:
        if (func_020362DC() & 3) {
            work->connectResult = 1;
            work->subState = 4;
        }
        break;
    case 7:
        if (func_021BBFA8(work) == 0) {
            func_021BC024(work);
            work->subState = work->subState + 1;
        }
        break;
    case 8:
        menuResult = func_0201FEBC(work->yesNoMenu);
        switch (menuResult) {
        case 0:
            work->connectResult = 1;
            work->subState = 4;
            break;
        case (u32)-2:
            func_021BBF1C(work, 0x1a);
            work->subState = 2;
            break;
        }
        break;
    }
    func_0201C4E4(work->printSys);
    printSys = work->printSys;
    if (work->descWindowOpen != 0 && func_0201C6C4(printSys, func_02045770(work->descWindow)) == 0) {
        func_02045334(work->descWindow);
        work->descWindowOpen = 0;
    }
    return 7;
}









int func_021BA6B0(StartMenuWork *work)
{
    void *printSys;
    switch (work->subState) {
    case 0:
        if (work->rowIds[0] == 1) {
            work->selectedRow = 1;
            work->subState = 0;
            return func_021BC080(work, 1);
        }
        func_021BBBAC(work);
        work->subState = work->subState + 1;
        break;
    case 1:
        if (func_0201C6B4(work->printSys) == 1)
            work->subState = work->subState + 1;
        break;
    case 2:
        if (func_020362DC() & 1) {
            func_020061E4(0x54c);
            func_021BBD10(work, 1);
            work->selectedRow = 1;
            work->subState = 0;
            return func_021BC080(work, 1);
        }
        if (func_020362DC() & 2) {
            func_020061E4(0x551);
            func_021BBD10(work, 0);
            func_021BB810(work, work->rowIds[work->cursorIndex],
                          func_021BB840(work, work->cursorTileY), 2);
            work->subState = 0;
            return 5;
        }
        break;
    }
    func_0201C4E4(work->printSys);
    printSys = work->printSys;
    if (work->descWindowOpen != 0 && func_0201C6C4(printSys, func_02045770(work->descWindow)) == 0) {
        func_02045334(work->descWindow);
        work->descWindowOpen = 0;
    }
    return 8;
}









int func_021BA7AC(StartMenuWork *work)
{
    void *printSys;
    if (func_0202EB0C() == 1) {
        switch (work->subState) {
        case 0:
            func_021BBE48(work);
            work->subState = work->subState + 1;
            break;
        case 1:
            if (func_0201C6B4(work->printSys) == 1)
                work->subState = work->subState + 1;
            break;
        case 2:
            if (func_020362DC() & 3) {
                func_020061E4(0x54c);
                func_021BBD10(work, 0);
                func_021BB810(work, work->rowIds[work->cursorIndex],
                              func_021BB840(work, work->cursorTileY), 2);
                work->subState = 0;
                return 5;
            }
            break;
        }
        func_0201C4E4(work->printSys);
        printSys = work->printSys;
        if (work->descWindowOpen != 0 && func_0201C6C4(printSys, func_02045770(work->descWindow)) == 0) {
            func_02045334(work->descWindow);
            work->descWindowOpen = 0;
        }
        return 9;
    }
    work->selectedRow = work->rowIds[work->cursorIndex];
    return 11;
}









/*
 * 0x021BA984 is an unlabelled tail-call stub (function_starts seed);
 * verified with tu over 0x021BA880..0x021BA990 (272 bytes).
 */
int func_021BA880(StartMenuWork *work)
{
    u32 i;
    switch (work->subState) {
    case 0:
        func_020434DC(0x1e, 0);
        func_02043598(0x17, 0);
        func_02040EBC(0, 0x7d8c);
        func_02040EBC(4, 0x7d8c);
        work->subState = work->subState + 1;
        return func_021BC054(work, 10);
    case 1:
        for (;;) {
            i = work->noticeIndex;
            if (i >= 8) {
                func_021BBF98(work);
                work->subState = 3;
                return func_021BC080(work, 10);
            }
            if ((d_021BD784[i].flagMask & work->saveStatus) == 0) {
                work->noticeIndex += 1;
                continue;
            }
            func_021BBF1C(work, d_021BD784[i].msgId);
            work->noticeIndex += 1;
            work->subState = work->subState + 1;
            break;
        }
        break;
    case 2:
        if (func_021BBFA8(work) == 0 && (func_020362DC() & 3)) {
            func_020061E4(0x547);
            work->subState = 1;
        }
        break;
    case 3:
        func_020434DC(0x1e, 1);
        func_02043598(0x17, 1);
        work->subState = 0;
        return func_021BC054(work, 5);
    }
    return 10;
}









int func_021BA984(StartMenuWork *work)
{
    return func_021BC080(work, 1);
}









/* HW_INTR_CHECK_BUF: the IRQ check word at DTCM + 0x3FF8. */
#define OSi_IRQ_CHECK_FLAG (*(volatile OsIrqWord *)((OsIrqWord)SDK_AUTOLOAD_DTCM_START + 0x3FF8))









void func_021BA990(void)
{
    func_020419E4();
    func_0204A648();
    OSi_IRQ_CHECK_FLAG |= 1;
}









void func_021BA9B0(StartMenuWork *work)
{
    work->vblankTask = (int)func_020056A0((void *)func_021BA990, work, 0);
}









void func_021BA9C8(StartMenuWork *work)
{
    func_02030EAC((struct Node *)work->vblankTask);
}








void func_021BA9D4(void)
{
    BG_SYS_ClearGraphicsMemory(0);
    func_020433E0((const struct DispVram *)d_021BD60C);
}








void func_021BA9E8(void)
{
    DispConfigBlock dispConfig;
    BgTemplateBlock bg0Template;
    BgTemplateBlock bg1Template;
    BgTemplateBlock bg2Template;
    BgTemplateBlock bg3Template;
    BgTemplateBlock bg4Template;
    BgTemplateBlock bg5Template;
    BgTemplateBlock bg6Template;

    func_0203F8F4(0xb);
    dispConfig = d_021BD678;
    func_0203FC28((struct DispConfig *)(&dispConfig));
    bg0Template = d_021BD724;
    func_0203FCA0(0, (const struct BgTemplate *)(&bg0Template), 0);
    bg1Template = d_021BD764;
    func_0203FCA0(1, (const struct BgTemplate *)(&bg1Template), 0);
    bg2Template = d_021BD6C4;
    func_0203FCA0(2, (const struct BgTemplate *)(&bg2Template), 0);
    bg3Template = d_021BD6E4;
    func_0203FCA0(3, (const struct BgTemplate *)(&bg3Template), 0);
    bg4Template = d_021BD744;
    func_0203FCA0(4, (const struct BgTemplate *)(&bg4Template), 0);
    bg5Template = d_021BD6A4;
    func_0203FCA0(5, (const struct BgTemplate *)(&bg5Template), 0);
    bg6Template = d_021BD704;
    func_0203FCA0(6, (const struct BgTemplate *)(&bg6Template), 0);
    func_020434DC(0xf, 1);
    func_02043598(7, 1);
}








/*
 * EXACT*: inferred extent runs two bytes long; the follower at 0x021BAB62 is
 * an unlabelled leaf (no lr save) that disasm.py did not label.
 */
void func_021BAB20(void)
{
    func_020434DC(0xf, 0);
    func_02043598(7, 0);
    func_020403F4(6);
    func_020403F4(5);
    func_020403F4(4);
    func_020403F4(3);
    func_020403F4(2);
    func_020403F4(1);
    func_020403F4(0);
    func_0203F9B4();
}








void func_021BAB64(void)
{
    void *archive;
    archive = func_020490F4(0x23, 0x800B);
    func_02049B68(archive, 4, 0, 0, 0xc0, 0xb);
    func_02049658(archive, 3, 2, 0, 0, 1, 0xb);
    func_020498F4(archive, 2, 3, 0, 0, 1, 0xb);
    func_02049B68(archive, 5, 4, 0, 0xc0, 0xb);
    func_02049658(archive, 1, 5, 0, 0, 1, 0xb);
    func_020498F4(archive, 0, 6, 0, 0, 1, 0xb);
    func_02049238(archive);
    func_0201F5BC(0, 1, 0xe, 0, 0xb);
    func_02049B40(0x17, 5, 0, 0x1e0, 0x20, 0xb);
    func_02049B40(0x17, 5, 4, 0x1e0, 0x20, 0xb);
}








void func_021BAC24(StartMenuWork *work)
{
    void *archive;
    archive = func_020490F4(0x23, 0x800B);
    work->blinkPalAnm = (void *)BLINK_PALANM_Create(0x20, 0x10, 2, 0xb);
    BLINK_PALANM_LoadPalettes((struct CodeIn *)(work->blinkPalAnm), archive, 4, 0x20, 0x30);
    func_02049238(archive);
}








void func_021BAC64(StartMenuWork *work)
{
    func_0202EA20((struct PalAnm *)(work->blinkPalAnm));
}








void func_021BAC74(StartMenuWork *work)
{
    work->msgBank = (void *)func_02045B38(0, 2, 0xb3, 0xb);
    work->font = (u32)func_0201D7EC(0x17, 0, 0, 0, 0xb);
    work->wordSet = (void *)func_0201EC64(0xb);
    work->printSys = (void *)func_0201C440((void *)0xb);
    work->stringBuf = (void *)func_020457B0(0x400, 0xb);
    work->taskList = (u32)func_0203101C(0xb, 0xb, 1, 4);
    work->msgBoxFrame = (void *)func_02028590(0xf, 1, 0, 0xb);
}








void func_021BACD8(StartMenuWork *work)
{
    func_02028604((int)work->msgBoxFrame);
    func_02031140((struct S02031140 *)work->taskList);
    func_02045808((struct U16Vec *)work->stringBuf);
    func_0201C4C0((struct PrintSys *)work->printSys);
    func_0201ED04((struct WordSet *)work->wordSet);
    func_0201D83C((void *)work->font);
    func_02045C04((struct Rec *)work->msgBank);
}








void func_021BAD08(StartMenuWork *work)
{
    u32 i;
    void *msgStr;
    void *zoneName;
    void *playerInfo;
    void *printSys;
    u16 locationBuf[14];

    func_02045088(11);
    for (i = 0; i < 14; i++) {
        work->windows[i].window = (void *)func_020450F0(d_021BD7C4[i].bgId, d_021BD7C4[i].x, d_021BD7C4[i].y,
                                       d_021BD7C4[i].width, d_021BD7C4[i].height, d_021BD7C4[i].palette, 1);
    }

    msgStr = func_02045EC0(work->msgBank, 0);
    printSys = work->printSys;
    func_0201C724(printSys, (u32)func_02045770(work->windows[0].window), 0, 4, (u32)msgStr, (u32)work->font, 0x440);
    work->windows[0].textPending = 1;
    func_02045808(msgStr);

    msgStr = func_02045EC0(work->msgBank, 12);
    func_0201F02C(work->wordSet, 0, work->playerData);
    func_0201F250(work->wordSet, work->stringBuf, msgStr);
    if (func_02008550(work->playerData) == 0) {
        printSys = work->printSys;
        func_0201C724(printSys, (u32)func_02045770(work->windows[1].window), 0, 0, (u32)work->stringBuf, (u32)work->font, 0xC80);
        work->windows[1].textPending = 1;
    } else {
        printSys = work->printSys;
        func_0201C724(printSys, (u32)func_02045770(work->windows[1].window), 0, 0, (u32)work->stringBuf, (u32)work->font, 0x14C0);
        work->windows[1].textPending = 1;
    }
    func_02045808(msgStr);

    msgStr = func_02045EC0(work->msgBank, 16);
    ZONEDATA_Init(0x800B);
    if (func_020142E8(work->eventWork, 0x966) == 1) {
        zoneName = (void *)func_02013E4C(func_02008848(func_02008854(work->saveData))[2]);
    } else {
        func_0200890C(work->saveData, (struct Sub02008828Rec *)locationBuf);
        zoneName = (void *)func_02013E4C(locationBuf[0]);
    }
    ZONEDATA_Exit();
    func_0201F158(work->wordSet, 0, (u32)zoneName);
    func_0201F250(work->wordSet, work->stringBuf, msgStr);
    printSys = work->printSys;
    func_0201C724(printSys, (u32)func_02045770(work->windows[2].window), 0, 0, (u32)work->stringBuf, (u32)work->font, 0x440);
    work->windows[2].textPending = 1;
    func_02045808(msgStr);

    msgStr = func_02045EC0(work->msgBank, 9);
    playerInfo = func_02008748(work->saveData);
    func_0201EFA4(work->wordSet, 0, func_0200864C(playerInfo), 3, 0, 1);
    func_0201EFA4(work->wordSet, 1, func_02008650(playerInfo), 2, 2, 1);
    func_0201F250(work->wordSet, work->stringBuf, msgStr);
    printSys = work->printSys;
    func_0201C724(printSys, (u32)func_02045770(work->windows[3].window), 0, 0, (u32)work->stringBuf, (u32)work->font, 0x440);
    work->windows[3].textPending = 1;
    func_02045808(msgStr);

    if (func_020142E8(work->eventWork, 0x962) == 1) {
        msgStr = func_02045EC0(work->msgBank, 10);
        func_0201EFA4(work->wordSet, 0, func_0200D0AC(func_0200CA10(work->saveData), 11), 3, 0, 1);
        func_0201F250(work->wordSet, work->stringBuf, msgStr);
        printSys = work->printSys;
        func_0201C724(printSys, (u32)func_02045770(work->windows[4].window), 0, 0, (u32)work->stringBuf, (u32)work->font, 0x440);
        work->windows[4].textPending = 1;
        func_02045808(msgStr);
    }

    msgStr = func_02045EC0(work->msgBank, 11);
    func_0201EFA4(work->wordSet, 0, func_0200C258(func_0200C0F0(work->saveData)), 2, 0, 1);
    func_0201F250(work->wordSet, work->stringBuf, msgStr);
    printSys = work->printSys;
    func_0201C724(printSys, (u32)func_02045770(work->windows[5].window), 0, 0, (u32)work->stringBuf, (u32)work->font, 0x440);
    work->windows[5].textPending = 1;
    func_02045808(msgStr);

    msgStr = func_02045EC0(work->msgBank, 1);
    {
        void *printSys = work->printSys;
        func_0201C724(printSys, (u32)func_02045770(work->windows[6].window), 0, 4, (u32)msgStr, (u32)work->font, 0x440);
    }
    work->windows[6].textPending = 1;
    func_02045808(msgStr);

    msgStr = func_02045EC0(work->msgBank, 2);
    {
        void *printSys = work->printSys;
        func_0201C724(printSys, (u32)func_02045770(work->windows[7].window), 0, 4, (u32)msgStr, (u32)work->font, 0x440);
    }
    work->windows[7].textPending = 1;
    func_02045808(msgStr);

    msgStr = func_02045EC0(work->msgBank, 4);
    {
        void *printSys = work->printSys;
        func_0201C724(printSys, (u32)func_02045770(work->windows[8].window), 0, 4, (u32)msgStr, (u32)work->font, 0x440);
    }
    work->windows[8].textPending = 1;
    func_02045808(msgStr);

    msgStr = func_02045EC0(work->msgBank, 5);
    {
        void *printSys = work->printSys;
        func_0201C724(printSys, (u32)func_02045770(work->windows[9].window), 0, 4, (u32)msgStr, (u32)work->font, 0x440);
    }
    work->windows[9].textPending = 1;
    func_02045808(msgStr);

    msgStr = func_02045EC0(work->msgBank, 3);
    {
        void *printSys = work->printSys;
        func_0201C724(printSys, (u32)func_02045770(work->windows[10].window), 0, 4, (u32)msgStr, (u32)work->font, 0x440);
    }
    work->windows[10].textPending = 1;
    func_02045808(msgStr);

    msgStr = func_02045EC0(work->msgBank, 7);
    {
        void *printSys = work->printSys;
        func_0201C724(printSys, (u32)func_02045770(work->windows[11].window), 0, 4, (u32)msgStr, (u32)work->font, 0x440);
    }
    work->windows[11].textPending = 1;
    func_02045808(msgStr);

    msgStr = func_02045EC0(work->msgBank, 6);
    {
        void *printSys = work->printSys;
        func_0201C724(printSys, (u32)func_02045770(work->windows[12].window), 0, 4, (u32)msgStr, (u32)work->font, 0x440);
    }
    work->windows[12].textPending = 1;
    func_02045808(msgStr);
}








/*
 * Releases the fourteen 8-byte-stride handles at +0x80 created by
 * func_021BAD08, then the shared resource.
 */
void func_021BB164(StartMenuWork *work)
{
    unsigned i;
    for (i = 0; i < 14; i++)
        func_020452E8(work->windows[i].window);
    func_020450C8();
}







void func_021BB184(StartMenuWork *work)
{
    ClactResConfig resConfig;
    void *archive;
    u32 i;

    resConfig = d_021BD688;
    func_0204A48C((const struct Cfg *)(&resConfig), (u32)d_021BD60C, 0xb);
    archive = func_020490F4(0x1f, 0x800b);
    if (func_02008550((const struct MyStatus *)work->playerData) == 0) {
        work->actorCharRes[0] = func_0204A6C8(archive, 5, 0, 0, 0xb);
        work->actorPaletteRes[0] = func_0204ABF0(archive, 4, 0, 0, 0xb);
        work->actorCellRes[0] = func_0204AF28(archive, 0, 1, 0xb);
    } else {
        work->actorCharRes[0] = func_0204A6C8(archive, 7, 0, 0, 0xb);
        work->actorPaletteRes[0] = func_0204ABF0(archive, 6, 0, 0, 0xb);
        work->actorCellRes[0] = func_0204AF28(archive, 2, 3, 0xb);
    }
    func_02049238(archive);
    archive = func_020490F4(0x23, 0x800b);
    work->actorCharRes[1] = func_0204A6C8(archive, 8, 1, 0, 0xb);
    work->actorPaletteRes[1] = func_0204ABF0(archive, 9, 0, 0x20, 0xb);
    work->actorCellRes[1] = func_0204AF28(archive, 0xa, 0xb, 0xb);
    work->actorCharRes[2] = func_0204A6C8(archive, 0xc, 1, 0, 0xb);
    work->actorPaletteRes[2] = func_0204ABF0(archive, 0xd, 0, 0x40, 0xb);
    work->actorCellRes[2] = func_0204AF28(archive, 0xe, 0xf, 0xb);
    func_02049238(archive);
    work->clactUnit = (void *)func_0204B100(6, 0, 0xb);
    work->rowActors[0] = (void *)func_0204B294((int)((void *)work->clactUnit), work->actorCharRes[0], work->actorPaletteRes[0], work->actorCellRes[0], (ClactInitData *)d_021BD5DC, 0, 0xb);
    func_0204B3DC((void *)work->rowActors[0], 0);
    for (i = 1; i <= 4; i++) {
        work->rowActors[i] = (void *)func_0204B294((int)((void *)work->clactUnit), work->actorCharRes[1], work->actorPaletteRes[1], work->actorCellRes[1], (ClactInitData *)d_021BD5E4, 0, 0xb);
        func_0204B92C((struct ClactActor *)work->rowActors[i], 1);
        func_0204B3DC((void *)work->rowActors[i], 0);
    }
    work->rowActors[5] = (void *)func_0204B294((int)((void *)work->clactUnit), work->actorCharRes[2], work->actorPaletteRes[2], work->actorCellRes[2], (ClactInitData *)d_021BD5D4, 0, 0xb);
    func_020434DC(0x10, 1);
    func_02043598(0x10, 1);
}







void func_021BB328(StartMenuWork *work)
{
    unsigned i;
    for (i = 0; i < 6; i++)
        func_0204B3B4(work->rowActors[i]);
    func_0204B1CC(work->clactUnit);
    for (i = 0; i < 3; i++)
        func_0204A8D4((u32)(work->actorCharRes[i]));
    for (i = 0; i < 3; i++)
        func_0204ADA4((u32)(work->actorPaletteRes[i]));
    for (i = 0; i < 3; i++)
        func_0204AFD8((u32)(work->actorCellRes[i]));
    func_0204A5AC();
}







/*
 * Builds an 8-window bgwinfrm manager at +0x118, initialises each window
 * from a 4-byte table (height from its halfword at +2), then binds the
 * thirteen resources at +0x80..+0xe0 (stride 8) to windows 0,0,0,0,0,0,1..7.
 */
void func_021BB380(StartMenuWork *work)
{
    u32 i;

    work->frameManager = BGWINFRM_Create(0, 8, 0xb);
    for (i = 0; i < 8; i++)
        BGWINFRM_AddFrame(work->frameManager, i, 1, 0x1a, d_021BD5EC[i].height);
    BGWINFRM_PutBmpWin(work->frameManager, 0, work->windows[0].window);
    BGWINFRM_PutBmpWin(work->frameManager, 0, work->windows[1].window);
    BGWINFRM_PutBmpWin(work->frameManager, 0, work->windows[2].window);
    BGWINFRM_PutBmpWin(work->frameManager, 0, work->windows[3].window);
    BGWINFRM_PutBmpWin(work->frameManager, 0, work->windows[4].window);
    BGWINFRM_PutBmpWin(work->frameManager, 0, work->windows[5].window);
    BGWINFRM_PutBmpWin(work->frameManager, 1, work->windows[6].window);
    BGWINFRM_PutBmpWin(work->frameManager, 2, work->windows[7].window);
    BGWINFRM_PutBmpWin(work->frameManager, 3, work->windows[8].window);
    BGWINFRM_PutBmpWin(work->frameManager, 4, work->windows[9].window);
    BGWINFRM_PutBmpWin(work->frameManager, 5, work->windows[10].window);
    BGWINFRM_PutBmpWin(work->frameManager, 6, work->windows[11].window);
    BGWINFRM_PutBmpWin(work->frameManager, 7, work->windows[12].window);
}







/*
 * Tail-calls the release of the handle kept at +0x118.
 */
void func_021BB474(StartMenuWork *work)
{
    BGWINFRM_Delete(work->frameManager);
}







void func_021BB484(void)
{
    func_0207D63C((void *)0x04000050, 4, 8, 16, 3);
    func_0207D63C((void *)0x04001050, 2, 4, 16, 3);
}





void func_021BB4B4(StartMenuWork *work)
{
    unsigned i = 0;
    if (func_020071EC(work->saveData) == 1) {
        work->rowIds[0] = 0;
        i++;
    }
    work->rowIds[i] = 1;
    (&work->rowIds[1])[i] = 2;
    i += 2;
    if (func_0200C308(work->unlockData, 1)) {
        work->rowIds[i] = 3;
        i++;
    }
    if (func_0200C308(work->unlockData, 2)) {
        work->rowIds[i] = 4;
        i++;
    }
    work->rowIds[i] = 5;
    (&work->rowIds[1])[i] = 6;
    i += 2;
    if (func_0200C308(work->unlockData, 3)) {
        work->rowIds[i] = 7;
        i++;
    }
    while (i < 8) {
        work->rowIds[i] = 8;
        i++;
    }
}





void func_021BB544(StartMenuWork *work)
{
    void *archive = func_020490F4(0x23, 0x800B);
    u32 i;
    for (i = 0; i < 8; i++) {
        u32 rowBytes = d_021BD5EC[i].height * 0x34;
        void *fileData;
        void *fileHandle;
        work->rowBuffers[i] = (void *)func_02030734(0xb, rowBytes, 0, d_021BDA00, 0x7e9);
        fileHandle = func_02049EF4(archive, d_021BD5EC[i].frameId, 1, &fileData, 0xb);
        func_02082A60((char *)fileData + 0xc, work->rowBuffers[i], rowBytes);
        func_020307B0(fileHandle);
    }
    func_02049238(archive);
}






/*
 * Frees the eight row buffers at +0xF8 allocated by func_021BB544.
 */
void func_021BB5C4(StartMenuWork *work)
{
    unsigned i;
    for (i = 0; i < 8; i++)
        func_020307B0(work->rowBuffers[i]);
}






void func_021BB5E0(StartMenuWork *work, u32 actorIndex, s16 y)
{
    SpritePos position;
    func_0204B454(work->rowActors[actorIndex], (struct PtS *)&position, 0);
    position.y = y;
    func_0204B404(work->rowActors[actorIndex], (const struct Vec2 *)(&position), 0);
}






/*
 * Lays out the up-to-eight menu rows listed at +0x120 (8 terminates),
 * stacking them by the heights in d_021BD5EC and positioning the row
 * sprites.  Row order is filled in by ov088_func_021BB4B4.c.
 */
void func_021BB608(StartMenuWork *work)
{
    u32 i;
    s8 tileY;
    u8 rowId;
    void *rowActor;

    i = 0;
    work->cursorIndex = 0;
    work->scrollPixels = 0;
    tileY = 2;
    work->cursorTileY = 2;
    for (i = 0; i < 8; i++) {
        if ((u8)work->rowIds[i] == 8)
            break;
        func_021BB798(work, (u8)work->rowIds[i], tileY);
        rowId = work->rowIds[i];
        if (rowId == 0) {
            rowActor = work->rowActors[0];
        } else if (rowId == 5) {
            func_021BB5E0(work, 5, tileY * 8 + d_021BD5EC[rowId].height * 8 / 2);
            rowActor = work->rowActors[5];
        } else if (rowId == 3) {
            if (func_0200C308(work->unlockData, 1) != 1)
                goto next;
            func_021BB5E0(work, 2, tileY * 8 + d_021BD5EC[(u8)work->rowIds[i]].height * 8 / 2);
            rowActor = work->rowActors[2];
        } else if (rowId == 4) {
            if (func_0200C308(work->unlockData, 2) != 1)
                goto next;
            func_021BB5E0(work, 3, tileY * 8 + d_021BD5EC[(u8)work->rowIds[i]].height * 8 / 2);
            rowActor = work->rowActors[3];
        } else if (rowId == 7) {
            if (func_0200C308(work->unlockData, 3) != 1)
                goto next;
            func_021BB5E0(work, 4, tileY * 8 + d_021BD5EC[(u8)work->rowIds[i]].height * 8 / 2);
            rowActor = work->rowActors[4];
        } else {
            goto next;
        }
        func_0204B3DC(rowActor, 1);
    next:
        tileY += (s8)d_021BD5EC[(u8)work->rowIds[i]].height;
    }
    func_021BB5E0(work, 0, 0x40);
    func_021BB810(work, (u8)work->rowIds[0], (s8)work->cursorTileY, 2);
}






void func_021BB798(StartMenuWork *work, u32 rowId, u32 tileY)
{
    u8 tileYByte = tileY;
    u16 rowHeight = d_021BD5EC[rowId].height;
    u32 frameBuffer;
    func_020410D0(2, 3, tileYByte, 0x1a, rowHeight, (u32)(work->rowBuffers[rowId]), 0, 0, 0x1a, rowHeight);
    frameBuffer = BGWINFRM_GetFrameBuffer(work->frameManager, rowId);
    func_020410D0(1, 3, tileYByte, 0x1a, rowHeight, (u32)((void *)frameBuffer), 0, 0, 0x1a, rowHeight);
    func_02041B6C(1);
    func_02041B6C(2);
}






/*
 * Redraws menu row `row` (height from the row table d_021BD5EC) at tile
 * row y on bg layer 2 with palette pal, then commits the layer.
 */
void func_021BB810(StartMenuWork *work, u8 row, int tileY, int palette)
{
    func_020413B0(2, 3, tileY, 0x1a, d_021BD5EC[row].height, palette);
    func_02041B6C(2);
}






int func_021BB840(StartMenuWork *work, int y)
{
    return (s8)(y + work->scrollPixels / 8);
}





/*
 * Shifts the six sprites at +0x1c..+0x30 vertically by d.
 */
void func_021BB858(StartMenuWork *work, int deltaY)
{
    u32 i;
    SpritePos position;
    for (i = 0; i < 6; i++) {
        func_0204B454((struct Actor *)work->rowActors[i], (struct PtS *)&position, 0);
        position.y += (s16)deltaY;
        func_0204B404((struct ClactActor *)(work->rowActors[i]), (const struct Vec2 *)(&position), 0);
    }
}






int func_021BB890(StartMenuWork *work, int d)
{
    u8 oldRowId;
    u16 rowHeight;
    s8 newTileY;
    u8 newRowId;
    s8 newIndex;
    u8 oldIndex;

    oldIndex = work->cursorIndex;
    oldRowId = work->rowIds[oldIndex];
    work->scrollStep = 0;
    if (d < 0) {
        if (oldIndex == 0)
            return 0;
        newIndex = oldIndex + d;
        rowHeight = d_021BD5EC[(u8)work->rowIds[newIndex]].height;
        newTileY = (s8)work->cursorTileY - rowHeight;
        func_021BB810(work, oldRowId, func_021BB840(work, (s8)work->cursorTileY), 1);
        if ((u8)work->rowIds[0] == 0) {
            if (newTileY < 2) {
                if (newIndex == 0) {
                    work->scrollSpeed = -(((rowHeight - ((s8)work->cursorTileY - 2)) / 3) * 8);
                    work->cursorTileY = 2;
                } else {
                    work->scrollSpeed = -((rowHeight / 3) * 8);
                }
            } else {
                work->cursorTileY = newTileY;
            }
        } else {
            work->cursorTileY = newTileY;
        }
    } else {
        if (oldIndex + d >= 8)
            return 0;
        if ((u8)work->rowIds[(oldIndex + d)] == 8)
            return 0;
        newRowId = work->rowIds[(s8)(oldIndex + d)];
        newTileY = (s8)work->cursorTileY + d_021BD5EC[oldRowId].height;
        func_021BB810(work, oldRowId, func_021BB840(work, (s8)work->cursorTileY), 1);
        if ((u8)work->rowIds[0] == 0) {
            if (newTileY == 0x18) {
                work->scrollSpeed = (d_021BD5EC[newRowId].height / 3) * 8;
            } else if (newTileY + d_021BD5EC[newRowId].height > 0x18) {
                work->scrollSpeed = (d_021BD5EC[newRowId].height / 3) * 8;
            } else {
                work->cursorTileY = newTileY;
            }
        } else {
            work->cursorTileY = newTileY;
        }
    }
    work->cursorIndex += (u8)d;
    return 1;
}





void func_021BB9DC(StartMenuWork *work, int flag)
{
    unsigned i;
    if (flag == 0) {
        for (i = 0; i <= 5; i++)
            func_0204B3DC(work->rowActors[i], flag);
        return;
    }
    func_0204B3DC(work->rowActors[0], 1);
    for (i = 0; i < 8; i++) {
        u8 rowId = work->rowIds[i];
        if (rowId == 8)
            return;
        if (rowId == 3) {
            if (func_0200C308(work->unlockData, 1) == 1)
                func_0204B3DC(work->rowActors[2], 1);
        } else if (rowId == 4) {
            if (func_0200C308(work->unlockData, 2) == 1)
                func_0204B3DC(work->rowActors[3], 1);
        } else if (rowId == 7) {
            if (func_0200C308(work->unlockData, 3) == 1)
                func_0204B3DC(work->rowActors[4], 1);
        } else if (rowId == 5) {
            func_0204B3DC(work->rowActors[5], 1);
        }
    }
}





void func_021BBA64(u8 x, u8 y, u8 w, u8 h, u8 bgLayer)
{
    u32 layer = *(u32 *)&bgLayer;

    func_02041300(layer, 1, x, y, 1, 1, 1);
    func_02041300(layer, 3, x + w - 1, y, 1, 1, 1);
    func_02041300(layer, 7, x, y + h - 1, 1, 1, 1);
    func_02041300(layer, 9, x + w - 1, y + h - 1, 1, 1, 1);
    func_02041300(layer, 2, x + 1, y, w - 2, 1, 1);
    func_02041300(layer, 8, x + 1, y + h - 1, w - 2, 1, 1);
    func_02041300(layer, 4, x, y + 1, 1, h - 2, 1);
    func_02041300(layer, 6, x + w - 1, y + 1, 1, h - 2, 1);
    func_02041300(layer, 5, x + 1, y + 1, w - 2, h - 2, 1);
    func_02041B6C(layer);
}



void func_021BBB84(u8 x, u8 y, u8 w, u8 h, u8 bg)
{
    func_02041300(*(u8 *)&bg, 0, x, y, w, h, 0);
    func_02041B6C(*(u8 *)&bg);
}




static inline void PrintMessageLine(StartMenuWork *work, u32 id, u32 pixelY, u16 color)
{
    u32 msgStr = (u32)func_02045EC0((struct MsgBank *)(work->msgBank), id);
    u32 printSys = (unsigned int)work->printSys;
    func_0201C724((void *)printSys, (u32)func_02045770((struct Descriptor *)work->descWindow), 0, pixelY, msgStr, work->font, color);
    work->descWindowOpen = 1;
    func_02045808((struct U16Vec *)msgStr);
}




/*
 * Four identical print blocks are one static inline helper: it loads
 * p+0x68 before the bitmap call and keeps 0x440 rematerialised per site.
 */
void func_021BBBAC(StartMenuWork *work)
{
    work->descWindow = (void *)func_020450F0(0, 2, 2, 0x1e, 0x14, 5, 1);
    PrintMessageLine(work, 0x16, 0, 0x14c0);
    PrintMessageLine(work, 0x17, 0x18, 0x440);
    PrintMessageLine(work, 0x18, 0x80, 0x440);
    PrintMessageLine(work, 0x19, 0x90, 0x440);

    func_02045374((struct Cfg *)(work->descWindow));
    func_02041B6C(0);
    func_021BBA64(0x20, 1, 0x20, 0x16, 2);
    func_02041EE4(1, 0, 0x100);
    func_02041EE4(1, 3, 0);
    func_02041EE4(2, 0, 0x100);
    func_02041EE4(2, 3, 0);
    func_021BB9DC(work, 0);
}




void func_021BBD10(StartMenuWork *work, int mode)
{
    func_020452E8(work->descWindow);
    if (mode != 1) {
        func_021BBB84(0x20, 1, 0x20, 0x16, 2);
        func_02041570(0, 0);
        func_02041EE4(1, 0, 0);
        func_02041EE4(1, 3, work->scrollPixels);
        func_02041EE4(2, 0, 0);
        func_02041EE4(2, 3, work->scrollPixels);
        if (work->rowIds[0] == 0)
            func_021BB9DC(work, 1);
    }
}




void func_021BBD80(StartMenuWork *work)
{
    work->descWindow = (void *)func_020450F0(4, 2, 3, 0x1e, 0x13, 5, 1);
    PrintMessageLine(work, 0x14, 0, 0x14c0);
    PrintMessageLine(work, 0x15, 0x18, 0x440);
    func_02045374((struct Cfg *)(work->descWindow));
    func_02041B6C(4);
    func_021BBA64(0, 1, 0x20, 0x16, 5);
}




/*
 * 0x021BBE3C is an unlabelled tail-call stub (function_starts seed).
 * Twin of func_021BBBAC (same PrintMessageLine inline).
 */
void func_021BBE3C(StartMenuWork *work)
{
    func_020452E8(work->descWindow);
}




void func_021BBE48(StartMenuWork *work)
{
    u32 noticeBank = (u32)func_02045B38(0, 2, 0xe8, 0x800b);
    u32 msgStr;
    u32 printSys;

    work->descWindow = (void *)func_020450F0(0, 2, 2, 0x1e, 0x14, 5, 1);
    msgStr = (u32)func_02045EC0((struct MsgBank *)noticeBank, 0x20);
    printSys = (unsigned int)work->printSys;
    func_0201C724((void *)printSys, (u32)func_02045770((struct Descriptor *)work->descWindow), 0, 0, msgStr, work->font, 0x440);
    work->descWindowOpen = 1;
    func_02045808((struct U16Vec *)msgStr);
    func_02045C04((struct Rec *)noticeBank);

    func_02045374((struct Cfg *)(work->descWindow));
    func_02041B6C(0);
    func_021BBA64(0x20, 1, 0x20, 0x16, 2);
    func_02041EE4(1, 0, 0x100);
    func_02041EE4(1, 3, 0);
    func_02041EE4(2, 0, 0x100);
    func_02041EE4(2, 3, 0);
    func_021BB9DC(work, 0);
}




void func_021BBF1C(StartMenuWork *work, u32 msgId)
{
    void *window;
    func_02045CAC((struct MsgBank *)(work->msgBank), msgId, (void *)(work->stringBuf));
    func_02043B5C((struct CharBuf *)func_02045770((struct Descriptor *)work->windows[13].window), 0xf);
    func_0201F73C(work->windows[13].window, 2, 1, 0xe);
    work->printJob = (void *)func_0201CCE4((u32)work->windows[13].window, 0, 0, (u32)work->stringBuf,
                                       work->font, func_02012FFC(),
                                       work->taskList, 0xa, 0xb, 0xf);
    work->printAdvanceLatched = 0;
    window = work->windows[13].window;
    func_02045334(window);
    func_02045374(window);
    func_02041B6C(func_02045730(window));
}




void func_021BBF98(StartMenuWork *work)
{
    func_0201F7A8(work->windows[13].window, 1);
}




int func_021BBFA8(StartMenuWork *work)
{
    if (work->printJob == 0)
        return 0;
    func_020286C4(work->msgBoxFrame, work->printJob, work->windows[13].window);
    switch (func_0201CE30(work->printJob)) {
    case 0:
        if (func_0203630C() & 3)
            func_0201CE5C(work->printJob, 0);
        work->printAdvanceLatched = 0;
        break;
    case 1:
        if (work->printAdvanceLatched == 0) {
            if (func_020362DC() & 3) {
                func_020061E4(0x547);
                func_0201CE38(work->printJob);
                work->printAdvanceLatched = 1;
            }
        }
        break;
    case 2:
        func_0201CE48(work->printJob);
        work->printJob = 0;
        work->printAdvanceLatched = 0;
        return 0;
    }
    return 1;
}




/*
 * note:     listing extent runs 2 bytes past the compiled function;
 *           trailing alignment padding, no byte difference.
 */
void func_021BC024(StartMenuWork *work)
{
    YesNoWindowTemplate windowTemplate;

    windowTemplate.bgId = 0;
    windowTemplate.x = 0x18;
    windowTemplate.y = 0xD;
    windowTemplate.palette = 0xF;
    windowTemplate.tileOffset = 0;
    work->yesNoMenu = func_0201FDA0(&windowTemplate, 1, 0xE, 0, 0xB);
}




int func_021BC054(StartMenuWork *work, int v)
{
    func_0202208C(0, 1, 1, 0, 6, 1, 0xb);
    work->nextStateAfterFade = v;
    return 2;
}




/*
 * EXACT*: extent runs long; the follower at 0x021BC0AC is an unlabelled leaf
 * (function_starts seed).
 */
int func_021BC080(StartMenuWork *work, int v)
{
    func_0202208C(0, 0, 0, 0, 6, 1, 0xb);
    work->nextStateAfterFade = v;
    return 2;
}




int func_021BC0AC(StartMenuWork *work, int v)
{
    work->selectAnimTimer = 0;
    work->selectAnimPhase = 0;
    work->nextStateAfterAnim = v;
    return 3;
}




int func_021BC0C8(StartMenuWork *work)
{
    int status = func_020071E8(work->saveData);
    work->saveStatus = status;
    return status != 0;
}




void func_021BC0E4(void)
{
    PROCSYS_ReplaceGlobal((u32)ov088_id, (u32)d_021BD818, 0);
}




void func_021BC0FC(void)
{
    PROCSYS_ReplaceGlobal((u32)ov088_id, (u32)&d_021BD824, 1);
}


void func_021BC114(void)
{
    PROCSYS_ReplaceGlobal((u32)ov088_id, (u32)&d_021BD824, 2);
}


/*
 * The ov194 id is held in a local (the original keeps it in r7 across the
 * copy loop and reuses it for the unload); the ov204 id is spelled
 * directly and reloaded from the pool for each call.
 */
int func_021BC12C(struct Proc *proc)
{
    u32 waveArcIds[30];
    struct SaveControl *saveControl;
    NewGameIntroWork *work;
    u32 nameInCount, introCount, i;
    u32 voiceHandle;
    void *nameInOverlayId;

    saveControl = func_020070A4();
    work = func_0203159C(proc, 0x5c, 1);
    work->saveIntr = func_021BD25C(1, saveControl);
    func_02007220(saveControl);
    work->myStatus = func_0200846C(1);
    work->config = CONFIG_Create(1);
    work->startArg.startMode = 0;
    work->startArg.config = work->config;
    work->startArg.myStatus = work->myStatus;
    work->nameInArgs = func_0216BFD4(1, 0, 0, 0, 7, 0, 0);
    work->procSys = PROCSYS_Create(1);

    nameInOverlayId = ov194_id;
    func_02034AC4((int)nameInOverlayId);
    nameInCount = d_021F557C;
    for (i = 0; i < nameInCount; i++)
        waveArcIds[i] = d_021F558C[i];
    func_02034A5C((int)nameInOverlayId);

    func_02034AC4((int)ov204_id);
    introCount = d_021BFD20;
    for (i = 0; i < introCount; i++)
        waveArcIds[nameInCount + i] = d_021BFD30[i];
    func_02034A5C((int)ov204_id);

    work->waveArcSet = GFL_USE_LoadWaveArcSet(waveArcIds, nameInCount + introCount);
    voiceHandle = PM_VOICE_Prepare(0x23c, 0, 0x40, 0, 0, 0, 0, 0);
    work->voiceHandle = voiceHandle;
    work->introParam.myStatus = work->myStatus;
    work->introParam.config = work->config;
    work->introParam.phase = 1;
    work->introParam.saveIntr = work->saveIntr;
    work->introParam.voiceHandle = voiceHandle;
    return 1;
}


/*
 * Case bodies are laid out in source order, and the original places
 * case 6 before case 5 (jump table at 0x021BC254).
 * Sequence: intro (ov204), name entry (ov194), intro again; the intro sets
 * retryNameEntry to send the player back to the name entry.
 */
int func_021BC230(void *proc, int *seq, void *procWork, NewGameIntroWork *work)
{
    int busy;

    func_021BD2F4(work->saveIntr);
    busy = PROCSYS_Main(work->procSys);
    switch (*seq) {
    case 0:
        PROCSYS_Push(work->procSys, (u32)ov204_id, &d_021BFD24, &work->introParam);
        *seq = 1;
        break;
    case 1:
        if (busy != 1)
            *seq = 2;
        break;
    case 2:
        work->nameInArgs->playerGender = func_02008550(work->startArg.myStatus);
        work->nameInArgs->saveIntr = work->saveIntr;
        PROCSYS_Push(work->procSys, (u32)ov194_id, &d_021F5580, work->nameInArgs);
        *seq = 3;
        break;
    case 3:
        if (busy != 1)
            *seq = 4;
        break;
    case 4:
        func_021BC4A4(work->myStatus, work->nameInArgs->name, func_02008550(work->myStatus));
        work->introParam.phase = 7;
        PROCSYS_Push(work->procSys, (u32)ov204_id, &d_021BFD24, &work->introParam);
        *seq = 6;
        break;
    case 6:
        if (busy != 1)
            *seq = 5;
        break;
    case 5:
        if (work->introParam.retryNameEntry == 0)
            *seq = 7;
        else
            *seq = 2;
        break;
    case 7:
        return 1;
    }
    return 0;
}










int func_021BC2FC(struct S020315D4 *proc, int *seq, void *procWork, NewGameIntroWork *work)
{
    void *saveControl = func_020070A4();
    void *ov228Work;
    void *gameSystemWork;
    LocationPos pos = {0, 0, 0};
    func_02005B04((const u32 *)work->waveArcSet);
    func_021BD29C(work->saveIntr);
    func_02008494(work->myStatus, func_02008730(saveControl));
    CONFIG_Copy(work->config, func_0200873C(saveControl));
    func_020307B0(work->myStatus);
    func_020307B0(work->config);
    func_0203133C((struct S020314B8 *)work->procSys);
    if (func_02007210(saveControl) == 1) {
        func_02034AC4((int)ov228_id);
        ov228Work = func_021DFC20(1);
        if (func_021DFE90(ov228Work) == 1)
            func_021DFEB0(ov228Work, saveControl);
        func_021DFDB8(ov228Work);
        func_02034A5C((int)ov228_id);
    }
    gameSystemWork = GAMESYSTEM_SetupInitWork(0, 0, &pos, 0);
    func_0216C0C0((int)work->nameInArgs);
    func_020315D4(proc);
    PROCSYS_ReplaceGlobal(-1, (u32)d_0209DF9C, (u32)gameSystemWork);
    return 1;
}








int func_021BC3B8(struct Proc *proc)
{
    NewGameIntroWork *work = func_0203159C(proc, 0x5c, 1);

    work->startArg.startMode = 1;
    work->startArg.config = (struct Config *)func_0200873C(func_020070A4());
    work->saveOptions = func_0200C0F0(func_020070A4());
    work->startArg.myStatus = 0;
    return 1;
}








int func_021BC3E4(void *proc, int *seq, int mode, NewGameIntroWork *work)
{
    switch (*seq) {
    case 0:
        if (mode == 0) {
            PROCSYS_PushGlobal(-1, (u32)d_021BD830, (u32)work);
        } else if (mode == 1) {
            CONFIG_SetBattleFlag(work->startArg.config, 0);
        } else if (mode == 2) {
            CONFIG_SetBattleFlag(work->startArg.config, 1);
        }
        *seq = *seq + 1;
        break;
    case 1:
        return 1;
    }
    return 1;
}








int func_021BC430(struct S020315D4 *proc, int seq, int mode, NewGameIntroWork *work)
{
    SaveLocation location;
    void *saveControl;
    u32 battleFlag;
    u8 savedOption;

    saveControl = func_020070A4();
    battleFlag = CONFIG_GetBattleFlag(work->startArg.config);
    savedOption = func_0200C31C(work->saveOptions);
    SAVE_CONTROL_Reload(saveControl);
    CONFIG_ApplyAppliedFlag((const struct Config *)func_0200873C(saveControl));
    func_0200890C(saveControl, (struct Sub02008828Rec *)(&location));
    PROCSYS_ReplaceGlobal(-1, (u32)d_0209DF9C, (u32)GAMESYSTEM_SetupInitWork(1, location.mapId, &location.position, location.facing));
    CONFIG_SetBattleFlag(work->startArg.config, battleFlag);
    func_0200C324(work->saveOptions, savedOption);
    func_020315D4(proc);
    return 1;
}








void func_021BC4A4(struct MyStatus *myStatus, struct Strbuf *name, int gender)
{
    u64 tick;
    u32 currentValue;
    func_020084E4((u16 *)myStatus, (struct U16Vec *)name);
    func_0200854C((int)myStatus, gender);
    func_0200852C(myStatus, func_02005728(-1));
    tick = func_0203F0A8();
    currentValue = func_02008550(myStatus);
    func_02008558(myStatus, (u8)((u32)((tick * 8) >> 32) + currentValue * 8));
}








/*
 * EXACT*: inferred extent runs two bytes long; the follower is an unlabelled
 * padding pair.
 */
int func_021BC4EC(struct Proc *proc, int seq, int *procWork)
{
    ConfigPromptWork *work;
    func_0203064C(1, 0x39, 0x80000);
    work = func_0203159C(proc, 0x1c, 0x39);
    if (*procWork == 0)
        work->question = 0;
    else
        work->question = 2;
    work->pulsePhase = 0;
    func_021BC62C(work);
    func_021BC75C(work);
    return 1;
}







int func_021BC52C(int proc, int seq, int procWork, ConfigPromptWork *work)
{
    func_021BC84C(work);
    func_0201D83C(work->font);
    func_020450C8();
    func_020403F4(3);
    func_020403F4(1);
    func_020403F4(5);
    func_0203F9B4();
    func_020315D4((struct S020315D4 *)proc);
    func_020306F0(0x39);
    return 1;
}

int func_021BC568(int proc, int seq, NewGameStartArg *startArg, ConfigPromptWork *work)
{
    int choice;

    switch (work->question) {
    case 0:
        choice = func_021BC8AC(work);
        if (choice != 0) {
            if (choice == 1)
                CONFIG_SetAppliedFlag(startArg->config, 0);
            else
                CONFIG_SetAppliedFlag(startArg->config, 1);
            func_021BC84C(work);
            work->question = 1;
            func_021BC75C(work);
        }
        break;
    case 1:
        choice = func_021BC8AC(work);
        if (choice != 0) {
            if (choice == 1)
                func_0200854C((int)startArg->myStatus, 0);
            else
                func_0200854C((int)startArg->myStatus, 1);
            func_021BC84C(work);
            work->question = 2;
            func_021BC75C(work);
        }
        break;
    case 2:
        choice = func_021BC8AC(work);
        if (choice != 0) {
            if (choice == 1)
                CONFIG_SetBattleFlag(startArg->config, 1);
            else
                CONFIG_SetBattleFlag(startArg->config, 0);
            func_0202208C(0, 0, 0, 0, 0xc, 1, 0x39);
            work->question = 3;
        }
        break;
    case 3:
        if (func_020221A4() == 1)
            return 1;
        break;
    }
    func_021BC944(work);
    return 0;
}

/*
 * The POWCNT clear is spelled `& ~0x8000` (the SDK display-select inline):
 * the original pools 0xFFFF7FFF, where `&= 0x7FFF` derives the mask from
 * the -16 already in a register.  The four ov088 data hints were contested
 * or unwitnessed with the ov088 token; without it they resolve as sole-ref.
 */
void func_021BC62C(ConfigPromptWork *work)
{
    func_0207D534((volatile u16 *)0x0400006C, -16);
    func_0207D534((volatile u16 *)0x0400106C, -16);
    func_02043534(0);
    func_020435F4(0);
    func_020433E0((const struct DispVram *)d_021BD8B8);
    func_0203F8F4(0x39);
    func_0203FC28((struct DispConfig *)d_021BD848);
    *(u16 *)0x04000304 = (u16)(*(u16 *)0x04000304 & ~0x8000);
    func_021BC734(d_021BD858, 3);
    func_021BC734(d_021BD878, 1);
    func_021BC734(d_021BD898, 5);
    func_02045088(0x39);
    func_02049B40(0x17, 5, 0, 0, 0x20, 0x39);
    func_02049B40(0x17, 5, 4, 0, 0x20, 0x39);
    work->font = func_0201D7EC(0x17, 0, 0, 0, 0x39);
    func_0201F5BC(1, 1, 3, 0, 0x39);
    func_0201F5BC(1, 0x1f, 4, 0, 0x39);
    func_0201F5BC(5, 1, 1, 0, 0x39);
    *(u16 *)0x05000000 = 0x7D8C;
    *(u16 *)0x05000400 = 0x7D8C;
    func_0204E720(3, 0x10, 0, 0);
}

void func_021BC734(const void *bgTemplate, int bgId)
{
    func_0203FCA0(bgId, bgTemplate, 0);
    func_02040588(bgId, 1);
    func_020414AC(bgId);
    func_020409B4(bgId);
}

void func_021BC75C(ConfigPromptWork *work)
{
    u32 msgArc;
    u32 text;
    u8 i;

    msgArc = (u32)func_02045B38(0, 2, 0xab, 0x39);
    work->selectedChoice = 0;
    work->questionWin = (void *)func_020450F0((int)5, (int)1, (u8)0x13, (int)0x1d, (int)4, (int)0, (int)1);
    func_02045374((struct Cfg *)work->questionWin);
    func_02043B5C((struct CharBuf *)((u32)func_02045770((struct Descriptor *)work->questionWin)), 0xf);
    text = (u32)func_02045EC0((struct MsgBank *)msgArc, work->question);
    func_0201F73C(work->questionWin, 0, 1, 1);
    func_0201C7A4((void *)((u32)func_02045770((struct Descriptor *)work->questionWin)), 2, 2, (void *)text, work->font);
    func_02045808((struct U16Vec *)text);
    func_02045334((struct Descriptor *)work->questionWin);
    for (i = 0; i < 2; i++) {
        work->choiceWin[i] = (void *)func_020450F0((int)1, (int)6, (u8)(i * 4 + 0xc), (int)0x14, (int)2, (int)0, (int)1);
        func_02045374((struct Cfg *)work->choiceWin[i]);
        func_02043B5C((struct CharBuf *)((u32)func_02045770((struct Descriptor *)work->choiceWin[i])), 0xf);
        text = (u32)func_02045EC0((struct MsgBank *)msgArc, i + 5 + work->question * 2);
        func_0201C7A4((void *)((u32)func_02045770((struct Descriptor *)work->choiceWin[i])), 2, 2, (void *)text, work->font);
        func_02045808((struct U16Vec *)text);
        func_02045334((struct Descriptor *)work->choiceWin[i]);
    }
    func_02045C04((struct Rec *)msgArc);
    func_021BC870(work);
}

void func_021BC84C(ConfigPromptWork *work)
{
    u8 i;

    func_020452E8(work->questionWin);
    for (i = 0; i < 2; i++)
        func_020452E8(work->choiceWin[i]);
}

void func_021BC870(ConfigPromptWork *work)
{
    unsigned char i;

    for (i = 0; i < 2; i++) {
        if (i == work->selectedChoice)
            func_0201F73C(work->choiceWin[i], 0, 1, 3);
        else
            func_0201F73C(work->choiceWin[i], 0, 31, 4);
    }
}

int func_021BC8AC(ConfigPromptWork *work)
{
    int result;
    u32 keys;
    int touched;
    TouchHitTable hitTable;

    if ((func_020362DC() & 0x40) || (func_020362DC() & 0x80)) {
        if (work->selectedChoice == 0)
            work->selectedChoice = 1;
        else
            work->selectedChoice = 0;
        func_021BC870(work);
        func_020061E4(0x548);
    }
    keys = func_020362DC();
    result = 1;
    if (keys & result) {
        func_020061E4(0x54C);
        if (work->selectedChoice != 0)
            result = 2;
        return result;
    }
    hitTable = d_021BD83C;
    touched = func_02035C08(&hitTable);
    if (touched != -1) {
        func_020061E4(0x54C);
        return touched == 0 ? 1 : 2;
    }
    return 0;
}

s32 func_021BC944(ConfigPromptWork *work)
{
    s32 nextPhase = work->pulsePhase + 0x400;
    s32 sineValue;
    s16 halfSine;
    u32 blue, green, red;

    if (nextPhase >= 0x10000)
        work->pulsePhase = work->pulsePhase - 0xFC00;
    else
        work->pulsePhase = nextPhase;
    sineValue = tbl_020A1B38[(work->pulsePhase >> 4) * 2 + 1] + 0x1000;
    halfSine = sineValue / 2;
    blue = (u8)(0x1d + (-(halfSine * 8) >> 12));
    red = (u8)(0x19 + (halfSine * -0x14 >> 12));
    green = (u8)(0x1e + (halfSine * -0xf >> 12));
    work->pulseColor = red | (green << 5) | (blue << 10);
    return func_02061CA4((void *)0xf, 0x6c, (u32)(&work->pulseColor), 2);
}

int func_021BC9C0(struct Proc *proc)
{
    func_0203064C(1, 0x16, 0x70000);
    func_02082BCC(func_0203159C(proc, 8, 0x16), 0, 8);
    return 1;
}

static inline void GX_SetVisibleWnd(int window)
{
    reg_GX_DISPCNT = reg_GX_DISPCNT & ~0xE000 | (window << 13);
}







static inline void GXS_SetVisibleWnd(int window)
{
    reg_GXS_DB_DISPCNT = reg_GXS_DB_DISPCNT & ~0xE000 | (window << 13);
}







/*
 * Case 1's fade call takes its zero from an enum local set at the top of
 * the arm: the enum is not folded, so the zero stays in r5 (the register
 * the stack-argument zeros use) through to `adds r2, r5, #0`. A literal 0,
 * an int local set to 0, and int-typed func_02049624 parameters all give
 * `movs r2, #0` scheduled after r0/r1 (6 bytes out); the permuter (300,
 * --types) found nothing.
 * volatile: DISPCNT 0x04000000 and DB_DISPCNT 0x04001000 read-modify-written by the SDK inlines GX_SetVisibleWnd/GXS_SetVisibleWnd (0x021BCA3A, 0x021BCA46)
 */
int func_021BC9E8(int proc, int seq, int *variant, LogoScreenWork *work)
{
    Zero zero;

    switch (work->state) {
    case 0:
        func_02043534(0);
        func_020435F4(0);
        reg_G2_BLDCNT = 0;
        reg_G2S_DB_BLDCNT = 0;
        GX_SetVisibleWnd(0);
        GXS_SetVisibleWnd(0);
        func_020433E0((const struct DispVram *)d_021BD944);
        func_0203F8F4(0x16);
        func_0203FC28((struct DispConfig *)d_021BD8F4);
        func_0203FCA0(1, (const struct BgTemplate *)d_021BD904, 0);
        func_0203FCA0(5, (const struct BgTemplate *)d_021BD924, 0);
        if (*variant == 1) {
            func_0207D534((volatile u16 *)0x0400006C, -16);
            func_0207D534((volatile u16 *)0x0400106C, -16);
            work->state = 7;
        } else {
            func_0207D534((volatile u16 *)0x0400006C, 16);
            func_0207D534((volatile u16 *)0x0400106C, 16);
            work->state = 1;
        }
        break;
    case 1:
        zero = Z0;
        func_02049624(0x1a, 0xc, 1, 0, 0, 1, 0x16);
        func_0204989C(0x1a, 0xd, 1, 0, 0, 1, 0x16);
        func_02049B40(0x1a, 0xb, 0, 0, 0, 0x16);
        func_02049624(0x1a, 0xc, 5, 0, 0, 1, 0x16);
        func_0204989C(0x1a, 0xe, 5, 0, 0, 1, 0x16);
        func_02049B40(0x1a, 0xb, 4, 0, 0, 0x16);
        func_02040588(1, 1);
        func_02040588(5, 1);
        func_0204363C(1);
        func_0204361C();
        func_0204E720(0xc, 0x10, zero, 2);
        work->state = 2;
        break;
    case 2:
        if (func_0204E804() == 0) {
            work->state = 3;
            work->timer = 0;
        }
        break;
    case 3:
        if (++work->timer > 0x5a)
            work->state = 4;
        if (func_020362DC() & 0xb)
            work->state = 4;
        break;
    case 4:
        func_0204E720(3, 0, 0x10, 2);
        work->state = 5;
        break;
    case 5:
        if (func_0204E804() == 0) {
            work->state = 6;
            work->timer = 0;
        }
        break;
    case 6:
        if (++work->timer > 0x1e) {
            work->state = 7;
            work->timer = 0;
        }
        break;
    case 7:
        func_02049624(0xa4, 1, 1, 0, 0x8000, 0, 0x16);
        func_0204989C(0xa4, 2, 1, 0, 0, 0, 0x16);
        func_02049B40(0xa4, 0, 0, 0, 0, 0x16);
        func_02049624(0xa4, 3, 5, 0, 0x8000, 0, 0x16);
        func_0204989C(0xa4, 4, 5, 0, 0, 0, 0x16);
        func_02049B40(0xa4, 0, 4, 0, 0, 0x16);
        func_020409B4(1);
        func_020409B4(5);
        func_02040588(1, 1);
        func_02040588(5, 1);
        func_0204363C(1);
        func_0204361C();
        func_0204E720(3, 0x10, 0, 2);
        work->state = 8;
        break;
    case 8:
        if (func_0204E804() == 0)
            work->state = 9;
        break;
    case 9:
        if (++work->timer > 0x5a) {
            work->state = 10;
            work->timer = 0;
        }
        break;
    case 10:
        func_0204E720(3, 0, 0x10, 2);
        work->state = 0xb;
        break;
    case 11:
        if (func_0204E804() == 0)
            work->state = 0xc;
        break;
    case 12:
        if (++work->timer > 0x1e)
            work->state = 0xd;
        break;
    case 13:
        func_0203F9B4();
        return 1;
    }
    return 0;
}







int func_021BCCBC(int proc)
{
    func_020315D4((struct S020315D4 *)proc);
    func_020306F0(0x16);
    return 1;
}

int func_021BCCCC(struct Proc *proc)
{
    func_0203064C(1, 0x81, 0x30000);
    func_02082BCC(func_0203159C(proc, 0x2c, 0x81), 0, 0x2c);
    return 1;
}

/*
 * EXACT*: the extent runs two bytes long (trailing padding pair).
 */
int func_021BCCF4(int proc, int *seq, int procWork, SaveEraseWork *work)
{
    switch (*seq) {
    case 0:
        func_021BCD88(work, seq);
        break;
    case 1:
        func_021BCDB4(work, seq);
        break;
    case 2:
        func_021BCDD0(work, seq);
        break;
    case 3:
        func_021BCDEC(work, seq);
        break;
    case 4:
        func_021BCE20(work, seq);
        break;
    case 5:
        func_021BCE3C(work, seq);
        break;
    case 6:
        func_021BCE80(work, seq);
        break;
    case 7:
        func_021BCF18(work, seq);
        break;
    case 8:
        return 1;
    }
    return 0;
}

int func_021BCD64(int proc)
{
    func_020315D4((struct S020315D4 *)proc);
    func_020306F0(0x81);
    PROCSYS_ReplaceGlobal((u32)ov088_id, (u32)d_021BD574, 0);
    return 1;
}

void func_021BCD88(SaveEraseWork *work, int *seq)
{
    func_021BCF44();
    func_021BCF6C();
    func_021BCFEC(work);
    func_021BD078(work);
    func_021BD0F4(work);
    func_021BD21C();
    *seq = 1;
}

void func_021BCDB4(SaveEraseWork *work, int *seq)
{
    if (func_020221A4() == 1) {
        func_021BD118(work, 0);
        *seq = 2;
    }
}

void func_021BCDD0(SaveEraseWork *work, int *seq)
{
    if (func_021BD188(work) == 0) {
        func_021BD1EC(work);
        *seq = 3;
    }
}

void func_021BCDEC(SaveEraseWork *work, int *seq)
{
    int result = func_0201FEBC(work->yesNoMenu);

    if (result == 0)
        goto answeredYes;
    if (result == -2)
        goto cancelled;
    return;
answeredYes:
    func_021BD118(work, 1);
    *seq = 4;
    return;
cancelled:
    func_021BD23C();
    *seq = 7;
}

void func_021BCE20(SaveEraseWork *work, int *seq)
{
    if (func_021BD188(work) == 0) {
        func_021BD1EC(work);
        *seq = 5;
    }
}

/*
 * EXACT*: the extent runs 20 bytes long; the follower at 0x021BCE70 is an
 * unlabelled tail-call stub (ldr r0,[pc]; ldr r3,[pc]; ldr r0,[r0]; bx r3).
 * The switch value is unsigned so that case 0xFFFFFFFE sorts after case 0.
 */
void func_021BCE3C(SaveEraseWork *work, int *seq)
{
    unsigned result = func_0201FEBC(work->yesNoMenu);
    switch (result) {
    case 0:
        func_021BD118(work, 2);
        *seq = 6;
        break;
    case 0xFFFFFFFE:
        func_021BD23C();
        *seq = 7;
        break;
    }
}

void func_021BCE70(void)
{
    TIME_ICON_Update(d_021BDA20);
}

void func_021BCE80(SaveEraseWork *work, int *seq)
{
    void *saveControl;
    u32 slot;

    if (func_021BD188(work) == 0) {
        d_021BDA20 = func_0202EE30(0, work->window, 0xf, 0x10, 0x81);
        func_020409B4(func_02045730(work->window));
        func_02005654((int)func_021BCE70, 0);
        saveControl = func_020070A4();
        func_02034AC4((u32)ov228_id);
        func_021DFF18(0x81);
        func_02034A5C((u32)ov228_id);
        func_02007230(saveControl);
        for (slot = 0; slot < 9; slot++) {
            if (SAVE_CONTROL_LoadExtraSave(saveControl, slot, 0x81) == 1)
                SAVE_CONTROL_EraseExtraSave(saveControl, slot, 0x81);
            func_020072A4(saveControl, slot);
        }
        func_0200566C();
        func_02087BCC(0);
    }
}

void func_021BCF18(SaveEraseWork *work, int *seq)
{
    if (func_020221A4() == 1) {
        func_021BD10C(work);
        func_021BD0C8(work);
        func_021BD04C(work);
        func_021BCFD4();
        *seq = 8;
    }
}

void func_021BCF44(void)
{
    DispVramBlock vramBanks = d_021BD9B0;

    BG_SYS_ClearGraphicsMemory(0);
    func_020433E0((const struct DispVram *)(&vramBanks));
}

void func_021BCF6C(void)
{
    DispConfigBlock dispConfig;
    BgTemplateBlock bgTemplate;

    func_0203F8F4(0x81);
    dispConfig = d_021BD980;
    func_0203FC28((struct DispConfig *)(&dispConfig));
    bgTemplate = d_021BD990;
    func_0203FCA0(0, (const struct BgTemplate *)(&bgTemplate), 0);
    func_020434DC(1, 1);
    func_02040EBC(0, 0x7D8C);
    func_02040EBC(4, 0x7D8C);
}

void func_021BCFD4(void)
{
    func_020434DC(1, 0);
    func_020403F4(0);
    func_0203F9B4();
}

void func_021BCFEC(SaveEraseWork *work)
{
    work->savedAppliedFlag = func_020461E4();
    func_020461D4(0);
    work->msgBank = func_02045B38(0, 2, 1, 0x81);
    work->font = func_0201D7EC(0x17, 0, 0, 0, 0x81);
    work->stringBuf = func_020457B0(0x400, 0x81);
    work->taskList = func_0203101C(0x81, 0x81, 1, 4);
    work->msgBoxFrame = (void *)func_02028590(0xf, 1, 0, 0x81);
}

void func_021BD04C(SaveEraseWork *work)
{
    func_02028604((int)work->msgBoxFrame);
    func_02031140(work->taskList);
    func_02045808(work->stringBuf);
    func_0201D83C(work->font);
    func_02045C04(work->msgBank);
    func_020461D4(work->savedAppliedFlag);
}

void func_021BD078(SaveEraseWork *work)
{
    int heapId = 0x81;
    int width = 0x1e;
    func_02045088(0x81);
    work->window = (void *)func_020450F0(0, 1, 0x13, width, 4, 0xf, 1);
    func_0201F5BC(0, 1, 0xe, 0, heapId);
    func_02049B40(0x17, 5, 0, width << 4, 0x20, heapId);
}

void func_021BD0C8(SaveEraseWork *work)
{
    func_020452E8(work->window);
    func_020450C8();
}

void func_021BD0D8(void)
{
    func_020419E4();
    *(volatile unsigned int *)((char *)&SDK_AUTOLOAD_DTCM_START + 0x3FF8) |= 1;
}

void func_021BD0F4(SaveEraseWork *work)
{
    work->vblankTask = func_020056A0(func_021BD0D8, work, 0);
}

void func_021BD10C(SaveEraseWork *work)
{
    func_02030EAC((struct Node *)work->vblankTask);
}

void func_021BD118(SaveEraseWork *work, u32 messageId)
{
    void *window;

    func_02045CAC((struct MsgBank *)work->msgBank, messageId, work->stringBuf);
    func_02043B5C((struct CharBuf *)((int)func_02045770((struct Descriptor *)work->window)), 15);
    func_0201F73C(work->window, 2, 1, 14);
    work->printJob = (void *)func_0201CCE4((u32)work->window, 0, 0, (u32)work->stringBuf, (u32)work->font, func_02013080(0), (u32)work->taskList, 10, 0x81, 15);
    work->printAdvanceLatched = 0;
    window = work->window;
    func_02045334((struct Descriptor *)window);
    func_02045374((struct Cfg *)window);
    func_02041B6C(func_02045730((struct Descriptor *)window));
}

int func_021BD188(SaveEraseWork *work)
{
    func_020310C4(work->taskList);
    func_020286C4(work->msgBoxFrame, work->printJob, work->window);
    switch (func_0201CE30(work->printJob)) {
    case 0:
        work->printAdvanceLatched = 0;
        break;
    case 1:
        if (work->printAdvanceLatched == 0) {
            if (func_020362DC() & 3) {
                func_020061E4(0x547);
                func_0201CE38(work->printJob);
                work->printAdvanceLatched = 1;
            }
        }
        break;
    case 2:
        func_0201CE48(work->printJob);
        work->printAdvanceLatched = 0;
        return 0;
    }
    return 1;
}

void func_021BD1EC(SaveEraseWork *work)
{
    YesNoWindowTemplate windowTemplate;
    windowTemplate.bgId = 0;
    windowTemplate.x = 0x18;
    windowTemplate.y = 0x0D;
    windowTemplate.palette = 0x0F;
    windowTemplate.tileOffset = 0;
    work->yesNoMenu = func_0201FDA0(&windowTemplate, 1, 0x0E, 1, 0x81);
}

void func_021BD21C(void)
{
    func_0202208C(0, 1, 1, 0, 6, 1, 0x81);
}

void func_021BD23C(void)
{
    func_0202208C(0, 0, 0, 0, 6, 1, 0x81);
}
