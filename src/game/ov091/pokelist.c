/*
 * file:     pokelist.c
 * unit:     yes
 * function: func_021B6240, func_021B6534, func_021B65B8, func_021B660C, func_021B6818, func_021B68F0, func_021B6B24, func_021B6D64, func_021B6D90, func_021B6F0C, func_021B6F28, func_021B6FEC, func_021B7034, func_021B7040, func_021B7078, func_021B709C, func_021B71B0, func_021B71E4, func_021B7268, func_021B7298, func_021B7624, func_021B7698, func_021B7B98, func_021B7CC4, func_021B8180, func_021B83D8, func_021B8418, func_021B8508, func_021B86D8, func_021B8758, func_021B892C, func_021B8A8C, func_021B8AC4, func_021B8DB4, func_021B8F68, func_021B8FC4, func_021B9020, func_021B907C, func_021B90F8, func_021B916C, func_021B9750, func_021B9788, func_021B97D4, func_021B9804, func_021B981C, func_021B9968, func_021B999C, func_021B99E4, func_021B9A84, func_021B9AA0, func_021B9AB4, func_021B9AC8, func_021B9BF4, func_021B9C1C, func_021B9C64, func_021B9CB0, func_021B9CF4, func_021B9D58, func_021B9DC0, func_021B9E20, func_021B9E3C, func_021B9E44, func_021B9EB0, func_021B9EC0, func_021B9F34, func_021B9F44, func_021BA004, func_021BA0A8, func_021BA288, func_021BA318, func_021BA3A4, func_021BA454, func_021BA4E4, func_021BA4F8, func_021BA5B4, func_021BA5E0, func_021BA60C, func_021BA624, func_021BA65C, func_021BA670, func_021BA688
 * address:  0x021B6240
 * region:   ov091
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
 *   func_02030734  0x02030734  arm
 *   func_0201A920  0x0201A920  thumb
 *   func_0201A954  0x0201A954  thumb
 *   func_020173F0  0x020173F0  thumb
 *   func_02017E40  0x02017E40  thumb
 *   func_0201A98C  0x0201A98C  thumb
 *   func_020307B0  0x020307B0  arm
 *   func_0203630C  0x0203630C  arm
 *   func_0201A354  0x0201A354  thumb
 *   func_02005728  0x02005728  thumb
 *   POKE_REGULATION_FindValidOrder  0x0201A59C  thumb
 *   func_020355D8  0x020355D8  arm
 *   d_021BED0C     0x021BED0C  data  a1
 *   d_021BEA78     0x021BEA78  data  a2
 *   d_021BEA84     0x021BEA84  data  a2
 *   d_021BEA90     0x021BEA90  data  a2
 *   d_021BEA9C     0x021BEA9C  data  a2
 *   func_020315D4  0x020315D4  arm
 *   func_020306F0  0x020306F0  arm
 *   d_021BED80     0x021BED80  data  a1
 *   func_0201AA18  0x0201AA18  thumb
 *   func_020355C4  0x020355C4  arm
 *   func_020212B0  0x020212B0  thumb
 *   func_0201AB28  0x0201AB28  thumb
 *   func_021BA6A0  0x021BA6A0  thumb  ov091
 *   func_021BA81C  0x021BA81C  thumb  ov091
 *   func_021BB43C  0x021BB43C  thumb  ov091
 *   func_02027F60  0x02027F60  thumb
 *   func_021B9A84  0x021B9A84  thumb  ov091
 *   func_021BCCCC  0x021BCCCC  thumb  ov091
 *   func_020056A0  0x020056A0  thumb
 *   func_021BB594  0x021BB594  thumb  ov091
 *   func_021BBA8C  0x021BBA8C  thumb  ov091
 *   func_02041B6C  0x02041B6C  arm
 *   func_0203D34C  0x0203D34C  arm
 *   func_02030EAC  0x02030EAC  arm
 *   func_021BBE44  0x021BBE44  thumb  ov091
 *   func_021BBAE0  0x021BBAE0  thumb  ov091
 *   func_021BB5FC  0x021BB5FC  thumb  ov091
 *   func_020452E8  0x020452E8  arm
 *   func_021BA890  0x021BA890  thumb  ov091
 *   func_02027FD8  0x02027FD8  thumb
 *   func_021BCD80  0x021BCD80  thumb  ov091
 *   func_0202208C  0x0202208C  thumb
 *   func_020221A4  0x020221A4  thumb
 *   func_021B981C  0x021B981C  thumb  ov091
 *   func_021B9020  0x021B9020  thumb  ov091
 *   func_021B9750  0x021B9750  thumb  ov091
 *   func_021B97D4  0x021B97D4  thumb  ov091
 *   func_021BB30C  0x021BB30C  thumb  ov091
 *   func_020061E4  0x020061E4  thumb
 *   func_021BB358  0x021BB358  thumb  ov091
 *   func_021B6184  0x021B6184  thumb  ov090
 *   func_021BB714  0x021BB714  thumb  ov091
 *   func_021BB7E8  0x021BB7E8  thumb  ov091
 *   func_021BBA68  0x021BBA68  thumb  ov091
 *   func_021BC6CC  0x021BC6CC  thumb  ov091
 *   func_021BD8B0  0x021BD8B0  thumb  ov091
 *   func_021BD9C8  0x021BD9C8  thumb  ov091
 *   func_021BD8E4  0x021BD8E4  thumb  ov091
 *   func_021B61E8  0x021B61E8  thumb  ov090
 *   func_021B61FC  0x021B61FC  thumb  ov090
 *   func_0204B98C  0x0204B98C  arm
 *   func_021BA8CC  0x021BA8CC  thumb  ov091
 *   func_021BB644  0x021BB644  thumb  ov091
 *   func_021BCDE8  0x021BCDE8  thumb  ov091
 *   func_021BBE50  0x021BBE50  thumb  ov091
 *   func_0201C4E4  0x0201C4E4  thumb
 *   func_0204A600  0x0204A600  arm
 *   func_02082A60  0x02082A60  arm
 *   func_02061CA4  0x02061CA4  arm
 *   d_021BEBFC     0x021BEBFC  data  a1
 *   d_021BEC04     0x021BEC04  data  a1
 *   d_020A1B38     0x020A1B38  data  a2
 *   func_0204A648  0x0204A648  arm
 *   BG_SYS_ClearMainPlanes  0x020434CC  arm
 *   BG_SYS_ClearSubPlanes  0x02043588  arm
 *   func_0202223C  0x0202223C  thumb
 *   WIPE_ResetWndMask  0x02022224  thumb
 *   func_020433E0  0x020433E0  arm
 *   func_0203F8F4  0x0203F8F4  arm
 *   func_02045088  0x02045088  arm
 *   func_0203FC28  0x0203FC28  arm
 *   func_0207D63C  0x0207D63C  arm
 *   func_02040618  0x02040618  arm
 *   func_0204A48C  0x0204A48C  arm
 *   func_020434DC  0x020434DC  arm
 *   func_02043598  0x02043598  arm
 *   func_02061C30  0x02061C30  arm
 *   d_021BEC3C     0x021BEC3C  data  a4
 *   d_021BEAEC     0x021BEAEC  data  a4
 *   d_021BEAFC     0x021BEAFC  data  a4
 *   d_021BEB1C     0x021BEB1C  data  a4
 *   d_021BEB3C     0x021BEB3C  data  a4
 *   d_021BEB5C     0x021BEB5C  data  a4
 *   d_021BEB9C     0x021BEB9C  data  a4
 *   d_021BEBBC     0x021BEBBC  data  a4
 *   d_021BEBDC     0x021BEBDC  data  a4
 *   d_020A1448     0x020A1448  data  a4
 *   func_0207D4B0 0x0207D4B0 arm
 *   d_021BEB7C 0x021BEB7C data a4
 *   func_02046440  0x02046440  arm
 *   func_02048A24  0x02048A24  arm
 *   func_02048AD0  0x02048AD0  arm
 *   func_02050B80  0x02050B80  arm
 *   d_021BEAB8     0x021BEAB8  data  a4
 *   d_021BEAD0     0x021BEAD0  data  a4
 *   d_021BEAC4     0x021BEAC4  data  a4
 *   func_0204A5AC  0x0204A5AC  arm
 *   func_020403F4  0x020403F4  arm
 *   func_020450C8  0x020450C8  arm
 *   func_0203F9B4  0x0203F9B4  arm
 *   func_02050ED4 0x02050ED4 arm
 *   func_02048AC4 0x02048AC4 arm
 *   func_02046788 0x02046788 arm
 *   func_0203FCA0 0x0203FCA0 arm
 *   func_02040588 0x02040588 arm
 *   func_020414AC 0x020414AC arm
 *   func_020409B4 0x020409B4 arm
 *   func_0204B100  0x0204B100  arm
 *   CLACT_SetUnitDefaultRenderer  0x0204B270  arm
 *   func_0204B294  0x0204B294  arm
 *   func_0204B3DC  0x0204B3DC  arm
 *   func_0204B92C  0x0204B92C  arm
 *   func_0204B3B4 0x0204B3B4 arm
 *   func_0204B1CC 0x0204B1CC arm
 *   func_0201D7EC  0x0201D7EC  thumb
 *   func_02045B38  0x02045B38  arm
 *   func_02049B40  0x02049B40  arm
 *   func_0201C450  0x0201C450  thumb
 *   func_0201DD68  0x0201DD68  thumb
 *   func_0201C6EC 0x0201C6EC thumb
 *   func_0201C4C0 0x0201C4C0 thumb
 *   func_02045C04 0x02045C04 arm
 *   func_0201D83C 0x0201D83C thumb
 *   func_020490F4  0x020490F4  arm
 *   func_02049B68  0x02049B68  arm
 *   func_02049658  0x02049658  arm
 *   func_020498F4  0x020498F4  arm
 *   func_02049EF4  0x02049EF4  arm
 *   func_0204AC18  0x0204AC18  arm
 *   func_0204A6C8  0x0204A6C8  arm
 *   func_0204AF28  0x0204AF28  arm
 *   func_02049238  0x02049238  arm
 *   func_0204ACEC  0x0204ACEC  arm
 *   func_0201BC3C  0x0201BC3C  thumb
 *   func_0201BC40  0x0201BC40  thumb
 *   func_0201BCB4  0x0201BCB4  thumb
 *   func_020275E4  0x020275E4  thumb
 *   func_02027624  0x02027624  thumb
 *   func_02027628  0x02027628  thumb
 *   func_02027630  0x02027630  thumb
 *   func_020413B0  0x020413B0  arm
 *   func_02027758  0x02027758  thumb
 *   func_0202775C  0x0202775C  thumb
 *   func_02027760  0x02027760  thumb
 *   func_02027764  0x02027764  thumb
 *   func_02027614  0x02027614  thumb
 *   func_02027618  0x02027618  thumb
 *   func_0202761C  0x0202761C  thumb
 *   func_02027620  0x02027620  thumb
 *   func_02027694  0x02027694  thumb
 *   func_02027698  0x02027698  thumb
 *   func_0202769C  0x0202769C  thumb
 *   func_020276A0  0x020276A0  thumb
 *   func_020276B4  0x020276B4  thumb
 *   func_020276B8  0x020276B8  thumb
 *   func_020276BC  0x020276BC  thumb
 *   func_020276C0  0x020276C0  thumb
 *   func_0204ADA4  0x0204ADA4  arm
 *   func_0204A8D4  0x0204A8D4  arm
 *   func_0204AFD8  0x0204AFD8  arm
 *   func_021BBDEC 0x021BBDEC thumb ov091
 *   func_021BC1B4 0x021BC1B4 thumb ov091
 *   func_021BC1D0 0x021BC1D0 thumb ov091
 *   func_021BC2C8 0x021BC2C8 thumb ov091
 *   func_021BA65C 0x021BA65C thumb ov091
 *   func_021BB7A4 0x021BB7A4 thumb ov091
 *   func_021BAFA0 0x021BAFA0 thumb ov091
 *   func_021BDC5C 0x021BDC5C thumb ov091
 *   func_021BDCA0 0x021BDCA0 thumb ov091
 *   func_021B9F34 0x021B9F34 thumb ov091
 *   func_021BA004 0x021BA004 thumb ov091
 *   func_021B9E20 0x021B9E20 thumb ov091
 *   func_02017E1C 0x02017E1C thumb
 *   func_0202136C 0x0202136C thumb
 *   func_02009050 0x02009050 thumb
 *   func_0200902C 0x0200902C thumb
 *   func_021B907C 0x021B907C thumb ov091
 *   func_021BC17C 0x021BC17C thumb ov091
 *   func_021BDD78 0x021BDD78 thumb ov091
 *   func_021BC350 0x021BC350 thumb ov091
 *   func_021BE2B4 0x021BE2B4 thumb ov091
 *   func_021BB200 0x021BB200 thumb ov091
 *   func_021BB2C0 0x021BB2C0 thumb ov091
 *   func_021BA670 0x021BA670 thumb ov091
 *   func_021BDCC0 0x021BDCC0 thumb ov091
 *   func_021BDD58 0x021BDD58 thumb ov091
 *   func_021BC30C 0x021BC30C thumb ov091
 *   func_021B9BF4 0x021B9BF4 thumb ov091
 *   func_021B9788 0x021B9788 thumb ov091
 *   func_021BA624 0x021BA624 thumb ov091
 *   func_021BB97C 0x021BB97C thumb ov091
 *   func_021BB99C 0x021BB99C thumb ov091
 *   func_021BB9AC 0x021BB9AC thumb ov091
 *   func_021BB9BC 0x021BB9BC thumb ov091
 *   func_021BB9CC 0x021BB9CC thumb ov091
 *   func_021BB98C 0x021BB98C thumb ov091
 *   func_021BC24C 0x021BC24C thumb ov091
 *   func_021BC288 0x021BC288 thumb ov091
 *   func_021BDBF8 0x021BDBF8 thumb ov091
 *   func_021BDC3C 0x021BDC3C thumb ov091
 *   func_021B9AC8 0x021B9AC8 thumb ov091
 *   func_021BA5B4 0x021BA5B4 thumb ov091
 *   func_021BA60C 0x021BA60C thumb ov091
 *   func_021B9E3C 0x021B9E3C thumb ov091
 *   func_021BA4E4 0x021BA4E4 thumb ov091
 *   func_021BA098 0x021BA098 thumb ov091
 *   func_021B9EB0 0x021B9EB0 thumb ov091
 *   func_021BD4EC  0x021BD4EC  thumb  ov091
 *   func_021BB468  0x021BB468  thumb  ov091
 *   func_021BC228  0x021BC228  thumb  ov091
 *   func_021BBAF8  0x021BBAF8  thumb  ov091
 *   func_021F6744  0x021F6744  thumb  ov112
 *   func_021B9AB4  0x021B9AB4  thumb  ov091
 *   func_021BBE5C  0x021BBE5C  thumb  ov091
 *   func_021B8F68  0x021B8F68  thumb  ov091
 *   func_02041300  0x02041300  arm
 *   func_021BBE68  0x021BBE68  thumb  ov091
 *   func_0204B878  0x0204B878  arm
 *   func_021B9968  0x021B9968  thumb  ov091
 *   func_021BB464  0x021BB464  thumb  ov091
 *   func_021BA288  0x021BA288  thumb  ov091
 *   _u32_div_f     0x0209C2B0  arm
 *   POKE_REGULATION_CheckSelection  0x02019E54  thumb
 *   func_021BB9EC  0x021BB9EC  thumb  ov091
 *   func_021B8DB4 0x021B8DB4 thumb ov091
 *   func_020362DC  0x020362DC  arm
 *   func_0203633C  0x0203633C  arm
 *   func_0204B3F4  0x0204B3F4  arm
 *   func_021B9AA0  0x021B9AA0  thumb  ov091
 *   func_021BB3C4  0x021BB3C4  thumb  ov091
 *   d_021BEAB0     0x021BEAB0  data  a1
 *   d_021BEAAA     0x021BEAAA  data  a1
 *   func_02035C08  0x02035C08  arm
 *   d_021BEC2C     0x021BEC2C  data  ov091  a1
 *   func_0204B404  0x0204B404  arm
 *   func_0204B84C  0x0204B84C  arm
 *   func_0207D658  0x0207D658  arm
 *   func_02041570  0x02041570  arm
 *   func_021B8418 0x021B8418 thumb ov091
 *   func_0215EA14 0x0215EA14 thumb ov010
 *   func_02013E04 0x02013E04 thumb
 *   d_021BEC0C 0x021BEC0C data a4
 *   d_021BEC1C 0x021BEC1C data a4
 *   func_021B7B98 0x021B7B98 thumb ov091
 *   func_021B8180 0x021B8180 thumb ov091
 *   func_02035C60 0x02035C60 arm
 *   func_0201AB8C 0x0201AB8C thumb
 *   func_0202130C 0x0202130C thumb
 *   func_020188AC 0x020188AC thumb
 *   func_0201B2B0 0x0201B2B0 thumb
 *   func_02045EC0  0x02045EC0  arm
 *   func_02045770  0x02045770  arm
 *   func_0201C724  0x0201C724  thumb
 *   func_02045808  0x02045808  arm
 *   func_0201C7D0  0x0201C7D0  thumb
 *   func_020457B0  0x020457B0  arm
 *   func_0201F250  0x0201F250  thumb
 *   func_02009020  0x02009020  thumb
 *   func_02008F08  0x02008F08  thumb
 *   func_0200903C  0x0200903C  thumb
 *   func_0201808C 0x0201808C thumb
 *   POKE_TOOL_FindMoveSlot 0x02018238 thumb
 *   func_020181F4 0x020181F4 thumb
 *   POKE_TOOL_ReplaceMoveSlot 0x020182A0 thumb
 *   NATSUKI_Calc 0x0201B7A0 thumb
 *   func_02007FB8 0x02007FB8 thumb
 *   func_02007F1C 0x02007F1C thumb
 *   func_02007E50 0x02007E50 thumb
 *   func_020410D0 0x020410D0 arm
 *   func_0204B034 0x0204B034 arm
 *   func_0204B258 0x0204B258 arm
 *   func_0204B09C 0x0204B09C arm
 *   func_020450F0 0x020450F0 arm
 *   d_021BED18 0x021BED18 data ov091 a1
 *   d_021BEC74 0x021BEC74 data ov091 a1
 *   d_021BEC75 0x021BEC75 data ov091 a1
 *   d_021BEC6C 0x021BEC6C data ov091 a1
 *   d_021BEC6D 0x021BEC6D data ov091 a1
 *   func_0204B084 0x0204B084 arm
 *   func_0201C6C4  0x0201C6C4  thumb
 *   func_02045334  0x02045334  arm
 *   func_02045374  0x02045374  arm
 *   func_02045730  0x02045730  arm
 *   POKE_TOOL_GetStatusCondition  0x02017F90  thumb
 *   CLACT_GetActorAnimFrame  0x0204B8F4  arm
 *   POKE_TOOL_GetBoxParam  0x020185F4  thumb
 *   func_0201BA68  0x0201BA68  thumb
 *   POKE_TOOL_GetIconPalette  0x0201BBE8  thumb
 *   func_0204B6F4  0x0204B6F4  arm
 *   func_0201EC64  0x0201EC64  thumb
 *   func_0201EEF4  0x0201EEF4  thumb
 *   func_0201EFA4  0x0201EFA4  thumb
 *   func_0201ED04  0x0201ED04  thumb
 *   POKE_TOOL_CalcLevel  0x02018430  thumb
 *   func_0202D01C  0x0202D01C  thumb
 *   func_02043AF4  0x02043AF4  arm
 *   g_020A7370     0x020A7370  data
 *   func_0201EE0C  0x0201EE0C  thumb
 *   BMP_WIN_SetPosX 0x02045780 arm
 *   func_02043B5C  0x02043B5C  arm
 *   POKE_REGULATION_CheckPokemon 0x02019DA4 thumb
 *   func_0202D034 0x0202D034 thumb
 *   CLACT_GetSurfacePos 0x0204B0C8 arm
 *   func_0201F5BC  0x0201F5BC  thumb
 *   TCBL_Create   0x0203101C  arm
 *   func_02028590  0x02028590  thumb
 *   func_0201C440  0x0201C440  thumb
 *   d_021BED28     0x021BED28  data  ov091  a1
 *   func_0202F038  0x0202F038  thumb
 *   func_0201CE48  0x0201CE48  thumb
 *   func_02028604  0x02028604  thumb
 *   func_02031140  0x02031140  arm
 *   func_020310C4 0x020310C4 arm
 *   func_020286C4 0x020286C4 thumb
 *   func_02028484 0x02028484 thumb
 *   APP_KEYCURSOR_Animate 0x0202865C thumb
 *   func_0202EE8C 0x0202EE8C thumb
 *   func_0201F73C  0x0201F73C  thumb
 *   func_0201F7A8 0x0201F7A8 thumb
 *   func_02028470  0x02028470  thumb
 *   func_02012FFC  0x02012FFC  thumb
 *   func_0201CD10  0x0201CD10  thumb
 *   GFL_USE_SetBgmPlayerParam  0x02005DE4  thumb
 *   GFL_USE_PushBgm  0x02005E64  thumb
 *   GFL_USE_CancelChangeAndPlayBgm  0x02005D90  thumb
 *   func_02005F38  0x02005F38  thumb
 *   GFL_USE_PopBgm  0x02005E9C  thumb
 *   func_02006238  0x02006238  thumb
 *   func_0201EF40 0x0201EF40 thumb
 *   func_0201EF4C 0x0201EF4C thumb
 *   func_0201EF34 0x0201EF34 thumb
 *   func_0201F140 0x0201F140 thumb
 *   APP_KEYCURSOR_DrawMark 0x02028618 thumb
 *   func_02049DB4  0x02049DB4  arm
 *   d_021BED38     0x021BED38  data  ov091  a1
 *   func_02027778  0x02027778  thumb
 *   d_021BEC80     0x021BEC80  data  a4
 *   func_02027858 0x02027858 thumb
 *   func_02027974  0x02027974  thumb
 *   func_020279E8 0x020279E8 thumb
 *   func_02027A04 0x02027A04 thumb
 *   d_021BEC8C     0x021BEC8C  data  ov091  a4
 *   APP_TASKMENU_WIN_Create  0x02027FEC  thumb
 *   func_02028148  0x02028148  thumb
 *   func_02028178  0x02028178  thumb
 *   APP_TASKMENU_WIN_SetActive  0x02028218  thumb
 *   APP_TASKMENU_WIN_SetDecide  0x0202822C  thumb
 *   func_02020F34 0x02020F34 thumb
 *   func_02021014 0x02021014 thumb
 *   func_02020FE4 0x02020FE4 thumb
 *   func_02019CF8 0x02019CF8 thumb
 *   func_02017988 0x02017988 thumb
 *   func_02019D00  0x02019D00  thumb
 *   GAME_BEACON_SetPokeLevelUp 0x02027268 thumb
 *   d_021BECE4 0x021BECE4 data ov091 a2
 *   func_020456F8 0x020456F8 arm
 *   func_0201D304 0x0201D304 thumb
 *   POKE_TOOL_GetLevelUpMove 0x02018328 thumb
 *   func_02049BDC 0x02049BDC arm
 *   func_0204ABF0 0x0204ABF0 arm
 *   func_0202762C 0x0202762C thumb
 *   func_02045924 0x02045924 arm
 *   d_021BED48 0x021BED48 data ov091 a1
 *   func_021B7034 0x021B7034 thumb ov091
 *   func_021B6F28 0x021B6F28 thumb ov091
 *   func_021B7040 0x021B7040 thumb ov091
 *   func_021B6F0C 0x021B6F0C thumb ov091
 *   func_02051614 0x02051614 arm
 *   PARTICLE_UpdateAllSystems 0x02051574 arm
 *   func_02047964 0x02047964 arm
 *   func_020479D8 0x020479D8 arm
 *   PARTICLE_DrawAllSystems 0x02051534 arm
 *   func_02047970 0x02047970 arm
 *   func_02006BD0 0x02006BD0 thumb
 *   func_0205121C 0x0205121C arm
 *   GFL_NET_AllocAligned 0x0203D7C8 arm
 *   func_02050C04 0x02050C04 arm
 *   func_02051230 0x02051230 arm
 *   PARTICLE_StartEffect 0x020515B4 arm
 *   d_021BED58 0x021BED58 data ov091 a4
 *   _fflt 0x0209BDBC arm
 *   _fadd 0x0209C95C arm
 *   _fsub 0x0209CB8C arm
 *   _ffix 0x0209C494 arm
 *   func_02050DB8 0x02050DB8 arm
 *   GFL_NET_FreeAligned 0x0203D7FC arm
 *   func_0200CDE0 0x0200CDE0 thumb
 *   func_02011400  0x02011400  thumb
 *   func_0203F4CC  0x0203F4CC  arm
 *   WAZA_TOOL_GetMaxPP 0x0201C158 thumb
 *   POKE_TOOL_IsPPRestorable 0x0201B920 thumb
 *   func_02018584 0x02018584 thumb
 *   func_020185C4 0x020185C4 thumb
 *   POKE_TOOL_RestorePP 0x0201B970 thumb
 *   func_021BEA48 0x021BEA48 thumb ov091
 *   func_021BB0C4  0x021BB0C4  thumb
 *   func_021BB1A0  0x021BB1A0  thumb
 *   func_021BB3D4  0x021BB3D4  thumb
 *   func_021BB3FC  0x021BB3FC  thumb
 *   func_021BB440  0x021BB440  thumb
 *   func_021BB4A0  0x021BB4A0  thumb
 *   func_021BB860  0x021BB860  thumb
 *   func_021BB8FC  0x021BB8FC  thumb
 *   func_021BBB40  0x021BBB40  thumb
 *   func_021BBBA0  0x021BBBA0  thumb
 *   func_021BBBD8  0x021BBBD8  thumb
 *   func_021BBBE4  0x021BBBE4  thumb
 *   func_021BC6C0  0x021BC6C0  thumb
 */

#define reg_GX_DISPCNT (*(volatile u32 *)0x04000000)
#define reg_GXS_DB_DISPCNT (*(volatile u32 *)0x04001000)
#define reg_G2_WIN0H  (*(volatile u16 *)0x04000040)
#define reg_G2_WIN0V  (*(volatile u16 *)0x04000044)
#define reg_G2_WININ  (*(volatile u16 *)0x04000048)
#define reg_G2_WINOUT (*(volatile u16 *)0x0400004A)
#define reg_G2_BLDCNT (*(volatile u16 *)0x04000050)
#define reg_GX_POWCNT (*(volatile u16 *)0x04000304)
struct Party;
struct PartyMon;
struct Obj0203159C;
struct S020315D4;
struct TaskMenu;
struct Descriptor;
struct Node;
struct TaskMenuState;
struct Actor;
struct PrintSys;
struct S;
struct Pal;
struct Cfg;
struct DispConfig;
struct DispVram;
struct Light;
struct BgTemplate;
struct Bank;
struct Obj;
struct GfFont;
struct MsgBank;
struct Rec;
struct Sub02008F80Obj;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef unsigned long long u64;

#include "pokelist_types.h"

typedef struct {
    u16 v[5];
} PokelistNickname;

typedef struct {
    u8 b0;
    u8 b1;
    u8 b2;
    u8 b3;
    u8 b4;
    u8 b5;
    u16 h6;
    u8 pad8[0xa8 - 8];
    u16 ha8;
} S;

typedef struct {
    void *list;
    u16 *t;
    u8 b;
} E;

typedef struct {
    void *party;
    u8 pad04[0x14 - 4];
    S *s;
    u8 pad18[0x34 - 0x18];
    int v34;
    u8 pad38[0x3c - 0x38];
    int v3c;
    u8 pad40[0x44 - 0x40];
    u16 h44;
    u8 pad46[0x49 - 0x46];
    u8 b49[6];
    u8 pad4f[0x60 - 0x4f];
    u16 h60;
    u8 pad62[0x64 - 0x62];
    int v64;
    E e[3];
    int v8c;
    int v90;
    u8 b94;
} Q_021B6240;

typedef struct {
    u16 heap;
    u8 pad[0x280 - 2];
    Q_021B6240 *q;
} P_021B6240;

typedef signed int     s32;

typedef struct {
    u8 pad0[0x14];
    void *v14;
    u8 pad18[0x68 - 0x18];
    struct {
        void *a;
        void *b;
        u8 pad[4];
    } e[3];
} Q_021B6534;

typedef struct {
    u8 pad[640];
    Q_021B6534 *q;
} P_021B6534;

typedef struct {
    u8 pad0[0x60];
    u16 v60;
    u8 pad62[0x90 - 0x62];
    u32 v90;
} Q_021B65B8;

typedef struct {
    u8 pad[640];
    Q_021B65B8 *q;
} P_021B65B8;


typedef signed char s8;

typedef short s16;

typedef int BOOL;

typedef struct {
    u8 top;
    u8 bottom;
    u8 left;
    u8 right;
} PokelistRect;

typedef struct {
    PokelistRect r[4];
} PokelistButtonRects;

typedef struct {
    s16 x;
    s16 y;
} PokelistPos;

typedef struct {
    int v[4];
} PokelistMenuItems;

struct Pal {
    u8 pad0[0x10];
    u32 mode;
    u8 pad1[0x2c];
    u16 src[3][16];
    u16 dst[3][16];
    u8 step;
    u8 pad2;
    u16 phase;
};

typedef struct {
    u32 w[12];
} PokelistVramBanks;

typedef struct {
    u32 w[7];
} PokelistClactConfig;

typedef enum { GX_DISP_SELECT_SUB_MAIN = 0, GX_DISP_SELECT_MAIN_SUB = 1 } GXDispSelect;

typedef struct {
    u16 x;
    u16 y;
    u16 animNo;
    u8 priority;
    u8 drawArea;
} PokelistActorTemplate;

extern void func_0203064C(u32 a, u32 b, u32 c);
extern void *func_0203159C(struct Obj0203159C *obj, u32 size, u32 heap);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern struct Party *func_0201A920(u32 heap);
extern void func_0201A954(struct Party *p, s32 capacity);
extern void *func_020173F0(u16 species, u16 level, u64 id, u16 heap);
extern void func_02017E40(void *p, u32 id, u32 v);
extern u32 func_0201A98C(struct Party *p, const struct PartyMon *src);
extern u32 func_020307B0(void *p);
extern u32 func_0203630C(void);
extern void *func_0201A354(int a, int b);
extern u32 func_02005728(u32 range);
extern int POKE_REGULATION_FindValidOrder(void *a0, void *a1, void *a2);
extern void func_020355D8(int a);
extern void func_020315D4(struct S020315D4 *p);
extern void func_020306F0(u32 heap);
extern u32 func_0201AA18(void *);
extern u8 func_020355C4(void);
extern u16 func_020212B0(u16 id);
extern void *func_0201AB28(void *p, u32 idx);
extern struct PlistPlate *func_021BA6A0(PokelistWork *work, int k, void *mon);
extern struct PlistPlate *func_021BA81C(PokelistWork *work, int k);
extern struct TaskMenu *func_02027F60(u16 a0, u16 a1, void *fontMain, void *printSys, u16 heap);
extern void func_021BCCCC(PokelistWork *work);
extern int func_020056A0(void (*cb)(void *, PokelistWork *), PokelistWork *work, int pri);
extern u32 *func_021BB594(PokelistWork *work);
extern u32 *func_021BBA8C(PokelistWork *work);
extern void func_02041B6C(u32 id);
extern void func_0203D34C(u32 a, u32 b);
extern void func_02030EAC(struct Node *n);
extern void func_021BBE44(int x);
extern void func_021BBAE0(PokelistWork *work, unsigned char *b);
extern void func_021BB5FC(PokelistWork *work, int *s);
extern u32 func_020452E8(struct Descriptor *d);
extern u32 func_02027FD8(struct TaskMenuState *s);
extern void func_021BCD80(PokelistWork *work);
extern void func_0202208C(void *p1, u32 p2, u32 p3, u32 p4, u32 p5, u32 p6, u32 p7);
extern u32 func_020221A4(void);
extern void func_021BB30C(PokelistWork *work, struct PlistPlate *s);
extern void func_020061E4(u32 id);
extern int func_021BB358(PokelistWork *work, struct S *s);
extern u32 func_021B6184(PokelistArg *arg, u8 b, u16 a);
extern void func_021BB714(PokelistWork *work, u32 *s, u32 k);
extern void func_021BB7E8(PokelistWork *work, u32 *s, u32 x);
extern void func_021BBA68(PokelistWork *work, u8 *s);
extern void func_021BC6CC(PokelistWork *work);
extern void func_021BD8B0(PokelistWork *work);
extern void func_021BD9C8(PokelistWork *work);
extern void func_021BD8E4(PokelistWork *work);
extern void func_021B61E8(PokelistArg *arg, int b);
extern int func_021B61FC(PokelistArg *arg, int a);
extern u32 func_0204B98C(struct Actor *a);
extern void func_021BA8CC(PokelistWork *work, struct PlistPlate *s);
extern void func_021BB644(PokelistWork *work, u8 *s);
extern void func_021BCDE8(PokelistWork *work);
extern void func_021BBE50(int x);
extern u32 func_0201C4E4(struct PrintSys *ps);
extern void func_0204A600(void);
extern void func_02082A60(void *src, void *dst, u32 size);
extern s32 func_02061CA4(void *p, u32 a, u32 b, s32 size);
extern void func_0204A648(void);
extern void BG_SYS_ClearMainPlanes(void);
extern void BG_SYS_ClearSubPlanes(void);
extern void func_0202223C(u32 a, u32 color);
extern void WIPE_ResetWndMask(int a);
extern void func_020433E0(const struct DispVram *c);
extern void func_0203F8F4(u16 heapId);
extern void func_02045088(u16 heapId);
extern void func_0203FC28(struct DispConfig *cfg);
extern void func_02040618(u32 layer, u32 a, u32 b);
extern void func_0204A48C(const struct Cfg *cfg, u32 arg, u32 heapId);
extern void func_020434DC(u32 mask, u32 enable);
extern void func_02043598(u32 mask, u32 enable);
extern void func_02061C30(void);
extern void func_0207D4B0(int,int,int);
extern void func_02046440(int, int, int, int, int, int, int);
extern int func_02048A24(int, int, int, int, int, int, int, int, void *, void *, void *, int);
extern void func_02048AD0(struct Light *l);
extern void func_02050B80(u32 heap);
extern void func_0204A5AC(void);
extern void func_020403F4(u32 i);
extern void func_020450C8(void);
extern void func_0203F9B4(void);
extern void func_02050ED4(void);
extern unsigned int func_02048AC4(void *ptr);
extern void func_02046788(void);
extern void func_0203FCA0(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void func_02040588(u32 which, unsigned char enable);
extern void func_020414AC(unsigned);
extern void func_020409B4(u32 index);
extern struct Bank *func_0204B100(int count, u8 flag, u32 heapId);
extern void CLACT_SetUnitDefaultRenderer(struct Bank *bank);
extern struct Obj *func_0204B294(void *owner, unsigned int i, unsigned int j, unsigned int k, const void *position, unsigned short space, unsigned short heap);
extern void func_0204B3DC(struct Obj *p, unsigned int v);
extern void func_0204B92C(struct Obj *p, u32 v);
extern void func_0204B3B4(struct Obj *p);
extern u32 func_0204B1CC(struct Bank *bank);
extern struct GfFont *func_0201D7EC(int a0, int a1, int a2, int a3, u32 heapId);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern void func_02049B40(u32 h, u32 a, u32 c, u32 d, u32 e, u16 heap);
extern void *func_0201C450(u16 n, u32 heap);
extern void func_0201DD68(void);
extern void func_0201C6EC(struct PrintSys *p);
extern void func_0201C4C0(struct PrintSys *p);
extern unsigned int func_02045C04(struct Rec *rec);
extern u32 func_0201D83C(void *ptr);
extern void *func_020490F4(u32 id, u32 heap);
extern void func_02049B68(void *a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern u32 func_02049658(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_020498F4(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void *func_02049EF4(void *h, u32 a1, u32 a2, void **out, u16 heap);
extern s32 func_0204AC18(void *a, u32 b, u32 c, u32 d, u16 e, u16 f, u16 g);
extern s32 func_0204A6C8(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern s32 func_0204AF28(void *owner, u32 first, u32 second, u32 mode);
extern void func_02049238(void *h);
extern int func_0204ACEC(void *a0, u32 a1, u32 a2, u32 a3, u16 a4);
extern int func_0201BC3C(void);
extern int func_0201BC40(void);
extern int func_0201BCB4(void);
extern u32 func_020275E4(void);
extern u32 func_02027624(void);
extern u32 func_02027628(void);
extern u32 func_02027630(void);
extern void func_020413B0(u8 index, u8 x0, u8 y0, u8 w, u8 h, u8 pal);
extern int func_02027758(void);
extern int func_0202775C(int a);
extern int func_02027760(int a);
extern int func_02027764(int a);
extern u32 func_02027614(void);
extern u32 func_02027618(void);
extern u32 func_0202761C(u32 a);
extern u32 func_02027620(u32 a);
extern u32 func_02027694(void);
extern u32 func_02027698(void);
extern u32 func_0202769C(u32 a);
extern u32 func_020276A0(u32 a);
extern u32 func_020276B4(void);
extern u32 func_020276B8(void);
extern u32 func_020276BC(u32 a);
extern u32 func_020276C0(u32 a);
extern void func_0204ADA4(u32 i);
extern void func_0204A8D4(u32 i);
extern void func_0204AFD8(u32 i);
extern u32 func_02017E1C(void *,u32,u32);
extern u32 func_0202136C(u16);
extern struct Sub02008F80Obj *func_02009050(struct Sub02008F80Obj *arr, u32 unused, int i, u32 heap);
extern void func_0200902C(struct Sub02008F80Obj *arr, u32 unused, int i);
extern int func_021BC17C(PokelistWork *work, int id);
extern int func_021BDD78(void *a, u32 id, int slot, u32 heap);
extern int func_021BC350(PokelistWork *work,int);
extern int func_021BE2B4(void *mon, u16 item, u16 moveSlot, u16 arg, int heap);
extern int func_021BDCC0(PokelistWork *work, u32 a1);
extern void func_021BDD58(PokelistWork *work, void *m);
extern void func_021BC30C(PokelistWork *work);
extern void func_021BB97C(PokelistWork *work, u32 s);
extern void func_021BB99C(PokelistWork *work, int b, int c, int d);
extern void func_021BB9AC(PokelistWork *work, int b, int c, int d);
extern void func_021BB9BC(PokelistWork *work, u32 b, u32 c, int d);
extern void func_021BB9CC(PokelistWork *work, int b, int c, int d);
extern void func_021BB98C(PokelistWork *work, u32 s);
extern void func_021BDC3C(PokelistWork *work, void *m);
extern int func_021BBDEC(PokelistWork *work, int unused, int id, int r3, u8 a4, int a5);
extern int func_021BC1B4(PokelistWork *work, void *id);
extern int func_021BC1D0(PokelistWork *work);
extern void func_021BC2C8(PokelistWork *work);
extern void func_021BB7A4(PokelistWork *work, u32 *s);
extern void func_021BDCA0(PokelistWork *work, void *m);
extern void func_021BD4EC(PokelistWork *work);
extern int func_021BC228(PokelistWork *work, int id);
extern int func_021F6744(void *p);
extern void func_02041300(u32 index, u32 a1, u8 a2, u8 a3, u8 a4, u8 a5, u8 a6);
extern void func_021BBE68(int h, int f);
extern void func_0204B878(struct Obj *p, u16 value);
extern int  POKE_REGULATION_CheckSelection(u32 a0, u32 a1, u32 a2);
extern void func_021BB9EC(PokelistWork *work, int b, int c, int d, unsigned char e);
extern u32  func_020362DC(void);
extern unsigned int func_0203633C(void);
extern u32 func_0204B3F4(struct Obj *p);
extern void func_0207D658(u32 addr, int plane, int brightness);
extern void func_02041570(int channel, u16 val);
extern u32 func_02013E04(u32 id);
extern int func_02035C60(void);
extern u32 func_0202130C(u32 id);
extern u32 func_020188AC(void *p, int v);
extern int   func_02009020(void *obj, int v);
extern void *func_02008F08(int a0);
extern void func_0200903C(struct Sub02008F80Obj *arr, u32 unused, int i, const struct Sub02008F80Obj *src);
extern u32 func_0201808C(void *,u32);
extern u32 POKE_TOOL_FindMoveSlot(void *,u16);
extern void func_020181F4(void *,u16,u32);
extern void POKE_TOOL_ReplaceMoveSlot(void *,u16,u32);
extern void NATSUKI_Calc(void *, int, int, int);
extern int func_02035C08(const void *rects);
extern void func_0204B404(struct Obj *actor, const PokelistPos *delta, u32 which);
extern void func_0204B84C(struct Obj *actor, int animNo);
extern int func_0215EA14(int moveIndex, const u8 *param);
extern u32 func_0201AB8C(void *party, u32 i, u32 j, u32 heap);
extern u32 func_0201B2B0(void *party, void *mon, u32 mode, u32 param, u8 season, u32 *out, u16 heap);
extern void *func_02045EC0(void *msgBank, u32 index);
extern void *func_02045770(struct Descriptor *window);
extern void func_0201C724(void *printSys, void *bmp, s16 x, s16 y, void *text, void *font, u16 color);
extern void func_02045808(void *vec);
extern void func_0201C7D0(void *bmp, s16 x, s16 y, void *text, void *font, u16 color);
extern void *func_020457B0(u32 capacity, u32 heapId);
extern void func_0201F250(void *wordSet, void *dst, void *src);
extern u32 func_02007FB8(void *bag, u16 itemId, u16 heapId);
extern u32 func_02007F1C(void *bag, u16 itemId, u16 count, u16 heapId);
extern u32 func_02007E50(void *bag, u16 itemId, u16 count, u16 heapId);
extern void func_0207D63C(u32 r, int a, int b, int c, int d);
extern const PokelistMenuItems d_021BEC0C, d_021BEC1C;
extern PokelistButtonRects d_021BEC2C;
extern void func_021BAFA0(PokelistWork *work, struct PlistPlate *plate, int selected);
extern void func_021BB0C4(PokelistWork *work, const struct PlistPlate *plate, int slideX);
extern void func_021BB1A0(PokelistWork *work, struct PlistPlate *plate, int slideX);
extern void func_021BB200(PokelistWork *work, struct PlistPlate *plate, void *mon, int slideX);
extern void func_021BB2C0(PokelistWork *work, struct PlistPlate *plate);
extern int func_021BB3C4(PokelistWork *work, struct PlistPlate *plate);
extern void func_021BB3D4(PokelistWork *work, struct PlistPlate *plate, PokelistPos *out);
extern void func_021BB3FC(PokelistWork *work, struct PlistPlate *plate, PokelistRect *out);
extern int func_021BB43C(struct PlistPlate *plate);
extern void func_021BB440(PokelistWork *work, struct PlistPlate *plate, int labelState);
extern unsigned short func_021BB464(PokelistWork *work, struct PlistPlate *plate);
extern int func_021BB468(PokelistWork *work, struct PlistPlate *plate);
extern int func_021BB4A0(PokelistWork *work, struct PlistPlate *plate);
extern void func_021BB860(PokelistWork *work, u32 *msg, u32 messageId, u32 waitForKey);
extern int func_021BB8FC(PokelistWork *work, u32 msg);
extern void func_021BBB40(PokelistWork *work, u32 menu);
extern void func_021BBAF8(PokelistWork *work, u32 menu, int *items);
extern void func_021BBBA0(PokelistWork *work, u32 menu);
extern void func_021BBBD8(PokelistWork *work, u32 menu);
extern unsigned int func_021BBBE4(PokelistWork *work, u32 menu);
extern void func_021BBE5C(int button, int active);
extern void func_021BC24C(PokelistWork *work, void *mon, int itemId);
extern void func_021BC288(PokelistWork *work, void *mon, int itemId);
extern void func_021BC6C0(PokelistWork *work);
extern int func_021BDBF8(PokelistWork *work, void *mon);
extern int func_021BDC5C(PokelistWork *work, void *mon);
extern void func_021BA890(PokelistWork *work, struct PlistPlate *plate);
int func_021B6240(struct Obj0203159C *a0, int *seq, PokelistArg *arg, PokelistWork *work);
int func_021B6534(int a0, int a1, int a2, PokelistWork *work);
int func_021B65B8(int a0, int a1, int a2, PokelistWork *work);
int func_021B660C(PokelistWork *work);
int func_021B6818(PokelistWork *work);
int func_021B68F0(PokelistWork *work);
void func_021B6B24(PokelistWork *work);
void func_021B6D64(void *tcb, PokelistWork *work);
void func_021B6D90(PokelistWork *work);
void func_021B6F0C(PokelistWork *work);
void func_021B6F28(PokelistWork *work);
void func_021B6FEC(PokelistWork *work);
void func_021B7034(PokelistWork *work);
void func_021B7040(PokelistWork *work);
void func_021B7078(const void *p, unsigned id,unsigned type);
void func_021B709C(PokelistWork *work);
void func_021B71B0(PokelistWork *work);
void func_021B71E4(PokelistWork *work);
void func_021B7268(PokelistWork *work);
void func_021B7298(PokelistWork *work);
void func_021B7624(PokelistWork *work);
void func_021B7698(PokelistWork *work);
void func_021B7B98(PokelistWork *work);
void func_021B7CC4(PokelistWork *work);
void func_021B8180(PokelistWork *work);
void func_021B83D8(PokelistWork *work);
void func_021B8418(PokelistWork *work);
void func_021B8508(PokelistWork *work);
void func_021B86D8(PokelistWork *work);
void func_021B8758(PokelistWork *work);
void func_021B892C(PokelistWork *work);
void func_021B8A8C(PokelistWork *work);
void func_021B8AC4(PokelistWork *work);
void func_021B8DB4(PokelistWork *work);
void func_021B8F68(PokelistWork *work, int plateIndex);
void func_021B8FC4(PokelistWork *work, int plateIndex);
void func_021B9020(PokelistWork *work);
void func_021B907C(PokelistWork *work);
void func_021B90F8(PokelistWork *work);
void func_021B916C(PokelistWork *work);
void func_021B9750(PokelistWork *work);
void func_021B9788(PokelistWork *work, int messageId, int waitForKey, PokelistFn onDone);
void func_021B97D4(PokelistWork *work);
void func_021B9804(PokelistWork *work, PokelistMenuFn onChoice);
void func_021B981C(PokelistWork *work);
void func_021B9968(PokelistWork *work);
void func_021B999C(PokelistWork *work);
int func_021B99E4(void *mon, int moveSlot);
int func_021B9A84(PokelistWork *work);
int func_021B9AA0(PokelistWork *work);
int func_021B9AB4(PokelistWork *work);
int func_021B9AC8(PokelistWork *work, void *mon, u8 partySlot);
u32 func_021B9BF4(PokelistWork *work, void *mon, u32 param);
void func_021B9C1C(PokelistWork *work, struct Descriptor *window, u32 messageId, int x, s16 y, u16 color);
void func_021B9C64(PokelistWork *work, struct Descriptor *window, u32 messageId, u32 x, s16 y, u16 color);
void func_021B9CB0(PokelistWork *work, struct Descriptor *window, u32 messageId, u32 x, s16 y, u16 color);
void func_021B9CF4(PokelistWork *work, struct Descriptor *window, void *wordSet, u32 messageId, s16 x, s16 y, u16 color);
void func_021B9D58(PokelistWork *work, struct Descriptor *window, void *wordSet, u32 messageId, s16 x, s16 y, u16 color);
void func_021B9DC0(PokelistWork *work, struct Descriptor *window, void *wordSet, u32 messageId, s16 x, s16 y, u16 color);
void func_021B9E20(PokelistWork *work);
void func_021B9E3C(PokelistWork *work);
void func_021B9E44(PokelistWork *work);
void func_021B9EB0(PokelistWork *work);
void func_021B9EC0(PokelistWork *work, int choice);
void func_021B9F34(PokelistWork *work);
void func_021B9F44(PokelistWork *work, int choice);
void func_021BA004(PokelistWork *work);
void func_021BA098(PokelistWork *work);
void func_021BA0A8(PokelistWork *work, int choice);
void func_021BA288(PokelistWork *work);
void func_021BA318(PokelistWork *work);
void func_021BA394(PokelistWork *work);
void func_021BA3A4(PokelistWork *work, int choice);
void func_021BA444(PokelistWork *work);
void func_021BA454(PokelistWork *work, int choice);
void func_021BA4E4(PokelistWork *work);
void func_021BA4F8(PokelistWork *work);
u32 func_021BA5B4(PokelistWork *work, void *mon);
void func_021BA5E0(PokelistWork *work, void *mon, u32 slot);
void func_021BA60C(PokelistWork *work, void *mon);
void func_021BA624(PokelistWork *work, void *mon, u16 itemId);
u32 func_021BA65C(PokelistWork *work, u16 itemId);
u32 func_021BA670(PokelistWork *work, u16 itemId);
u32 func_021BA688(PokelistWork *work, u16 itemId);
extern const char d_021BED0C[];
extern const PokelistNickname d_021BEA78;
extern const PokelistNickname d_021BEA84;
extern const u16 d_021BEA90[];
extern const u16 d_021BEA9C[];
extern u8 d_021BED80;
extern const PokelistBlend d_021BEBFC;
extern const PokelistBlend d_021BEC04;
extern s16 d_020A1B38[];
extern PokelistVramBanks d_021BEC3C;
extern PokelistClactConfig d_020A1448;
extern char d_021BEAEC[];
extern char d_021BEAFC[];
extern char d_021BEB1C[];
extern char d_021BEB3C[];
extern char d_021BEB5C[];
extern char d_021BEB9C[];
extern char d_021BEBBC[];
extern char d_021BEBDC[];
extern char d_021BEB7C[];
extern char d_021BEAB8[];
extern char d_021BEAD0[];
extern char d_021BEAC4[];
extern const u8 d_021BEAB0[];
extern const u8 d_021BEAAA[];










/*
 * Byte-correct; the one wildcard is the arm9 call to 0x0201A354 (+0x10E).
 *   data run, the integrator's) has no witness outside this range. Verified C for it
 *   (from src/pending/ov/ov021_func_021B57CC.c, match.py one --thumb, EXACT,
 *   16 bytes):
 *     extern int func_02048F60();  (symbols: func_02048F60 0x02048F60 arm)
 *     int func_0201A354(int a, int b) { return func_02048F60(0x69, a, b); }
 *   Levers: the four 10-byte stack copies declared b, d, c, a (reverse of
 *   their frame order); t[4] spelled `k + 0xff11` (pool word, then +0xee
 *   for t[5]); `k = 0` before the b49 clear loop, which stores k.
 */
int func_021B6240(struct Obj0203159C *a0, int *seq, PokelistArg *arg, PokelistWork *work)
{
    PokelistNickname b;
    PokelistNickname d;
    PokelistNickname c;
    PokelistNickname a;
    u8 i;
    u8 k;
    void *mon;
    PokelistRegulation *regulation;
    u16 *t;

    switch (*seq) {
    case 0:
        func_0203064C(1, 0x17, 0x30000);
        work = func_0203159C(a0, 0x284, 0x17);
        work->heapId = 0x17;
        if (arg == 0) {
            arg = func_02030734(0x17, 0x98, 1, d_021BED0C, 0x52);
            arg->party = func_0201A920(0x17);
            arg->selectedIndex = 0;
            func_0201A954(arg->party, 6);
            a = d_021BEA78;
            for (i = 0; i < 6; i++) {
                mon = func_020173F0(d_021BEA90[i], d_021BEA9C[i], 0xffffffff, 0x17);
                b = a;
                func_02017E40(mon, 0x8e, (u32)&b);
                func_02017E40(mon, 0x9a, 0);
                func_0201A98C(arg->party, mon);
                func_020307B0(mon);
            }
            arg->mode = 0;
            if (func_0203630C() & 0x100) {
                regulation = func_0201A354(0xf, 0x17);
                arg->regulation = regulation;
                regulation->minPartySize = 1;
                regulation->maxPartySize = 6;
                regulation->level = 1;
                regulation->levelRange = 0;
                regulation->mustPoke = 0;
                regulation->levelTotal = 0xc8;
                k = 0;
                for (i = 0; i < 6; i++)
                    arg->slotOrder[i] = 0;
                arg->mode = 0x16;
                for (k = 0; k < 3; k++) {
                    c = d_021BEA84;
                    arg->entries[k].party = func_0201A920(0x17);
                    for (i = 0; i < 6; i++) {
                        mon = func_020173F0(func_02005728(0xfa), 0x64, 0xffffffff, 0x17);
                        d = c;
                        func_02017E40(mon, 0x8e, (u32)&d);
                        func_02017E40(mon, 0x9a, 0);
                        func_02017E40(mon, 6, func_02005728(2));
                        func_0201A98C(arg->entries[k].party, mon);
                        func_020307B0(mon);
                    }
                    t = func_02030734(0x17, 0xc, 0, d_021BED0C, 0xae);
                    t[0] = 0x3077;
                    t[1] = 0x308c;
                    t[2] = 0x3044;
                    t[3] = 0x3084;
                    t[4] = k + 0xff11;
                    t[5] = 0xffff;
                    arg->entries[k].name = t;
                    arg->entries[k].gender = func_02005728(2);
                }
                arg->battleKind = 2;
                arg->timerShown = 1;
                arg->timerRunning = 1;
                arg->timeLeft = 0xff;
                arg->timerExpired = 0;
                POKE_REGULATION_FindValidOrder(regulation, arg->party, 0);
            } else if (func_0203630C() & 0x400) {
                arg->mode = 5;
                arg->itemId = 0x2c;
            } else if (func_0203630C() & 0x800) {
                arg->mode = 0x19;
            }
            func_020355D8(1);
        }
        work->arg = arg;
        *seq = 1;
    case 1:
        if (func_021B660C(work) == 1)
            return 1;
        break;
    }
    return 0;
}








int func_021B6534(int a0, int a1, int a2, PokelistWork *work)
{
    u8 i;

    if (func_021B6818(work) == 0)
        return 0;
    if (a2 == 0) {
        for (i = 0; i < 3; i++) {
            if (work->arg->entries[i].party != 0)
                func_020307B0(work->arg->entries[i].party);
            if (work->arg->entries[i].name != 0)
                func_020307B0(work->arg->entries[i].name);
        }
        if (work->arg->regulation != 0)
            func_020307B0(work->arg->regulation);
        func_020307B0(work->arg->party);
        func_020307B0(work->arg);
    }
    func_020315D4((struct S020315D4 *)a0);
    func_020306F0(0x17);
    return 1;
}








int func_021B65B8(int a0, int a1, int a2, PokelistWork *work)
{
    PokelistArg *arg;

    if (a2 == 0) {
        arg = work->arg;
        if (arg->timerRunning == 1 && arg->timeLeft != 0) {
            d_021BED80++;
            if (d_021BED80 > 0x3c) {
                d_021BED80 = 0;
                arg->timeLeft = arg->timeLeft - 1;
            }
        }
    }
    if (func_021B68F0(work) == 1)
        return 1;
    return 0;
}








/*
 * The 0x160 table is indexed as `work + i * 4 + 0x160` (base plus scaled
 * index, then the field offset) and the list lookup goes through a temp:
 * that is what puts the row address after func_0201AB28 and keeps the
 * three 0x160 offsets as spilled loop invariants.
 */
int func_021B660C(PokelistWork *work)
{
    u8 n;
    u8 i;
    PokelistArg *arg;
    int e;

    n = func_0201AA18(work->arg->party);
    work->touchMode = func_020355C4();
    work->menuChoice = 0x17;
    work->phase = 0;
    work->inputStage = 0;
    work->selectedSlot = 0;
    work->selectedMon = 0;
    work->swapSourceSlot = 9;
    work->healSourceSlot = 9;
    work->switchButtonEnabled = 0;
    work->fadeMode = 0;
    work->selectedCount = 0;
    work->fadeStep = 0;
    work->fadePhase = 0;
    work->reservedCounter = 0;
    work->waitFrames = 0;
    work->phaseCallback = 0;
    work->descriptor = 0;
    work->pressedButtonActor = 0;
    work->commandButtons[0] = 0;
    work->commandButtons[1] = 0;
    work->selectionConfirmed = 0;
    work->evolveCheckKind = 0;
    work->touchDragState = 0;
    work->reservedWord = 0;
    work->arg->closeRequested = 0;
    work->allowDisabledSelect = 1;
    work->healSoundPending = 0;
    for (i = 0; i < 0x17; i++)
        (&work->charRes[0])[i] = -1;
    work->restoreMode19 = work->arg->mode == 0x19 ? 1 : 0;
    arg = work->arg;
    if (arg->mode == 0x18) {
        arg->mode = 3;
        work->restoreMode18 = 1;
    } else {
        work->restoreMode18 = 0;
    }
    arg = work->arg;
    if (arg->mode == 0x1a) {
        arg->mode = 1;
        work->restoreMode1A = 1;
    } else {
        work->restoreMode1A = 0;
    }
    arg = work->arg;
    if (arg->mode == 6 && arg->moveId == 0)
        work->arg->moveId = func_020212B0(arg->itemId);
    func_021B6D90(work);
    func_021B7298(work);
    func_021B71E4(work);
    for (i = 0; i < 6; i++) {
        if (i < n) {
            e = (int)func_0201AB28(work->arg->party, i);
            work->plates[i] = func_021BA6A0(work, i, (void *)e);
        } else
            work->plates[i] = func_021BA81C(work, i);
        if (func_021BB43C(work->plates[i]) <= 5)
            work->selectedCount++;
    }
    work->taskMenu = (int)func_02027F60(0, 1, work->fontMain, work->printSys, work->heapId);
    func_021B709C(work);
    if (func_021B9A84(work) == 1)
        func_021BCCCC(work);
    work->updateTask = func_020056A0(func_021B6D64, work, 8);
    work->messageWindow = (int)func_021BB594(work);
    work->contextMenu = (int)func_021BBA8C(work);
    func_021B7698(work);
    func_02041B6C(3);
    func_02041B6C(2);
    func_02041B6C(7);
    func_0203D34C(1, work->heapId);
    return 1;
}








int func_021B6818(PokelistWork *work)
{
    u8 i;

    func_02030EAC((struct Node *)work->updateTask);
    if (func_021B9A84(work) == 1) {
        func_021BBE44(work->commandButtons[0]);
        func_021BBE44(work->commandButtons[1]);
        work->commandButtons[0] = 0;
        work->commandButtons[1] = 0;
    }
    func_021BBAE0(work, (unsigned char *)work->contextMenu);
    func_021BB5FC(work, (int *)work->messageWindow);
    if (work->descriptor != 0)
        func_020452E8((struct Descriptor *)work->descriptor);
    for (i = 0; i < 6; i++)
        func_021BA890(work, work->plates[i]);
    func_02027FD8((struct TaskMenuState *)work->taskMenu);
    func_021B7268(work);
    if (func_021B9A84(work) == 1)
        func_021BCD80(work);
    func_021B71B0(work);
    func_021B7624(work);
    func_021B6FEC(work);
    if (work->restoreMode18 == 1)
        work->arg->mode = 0x18;
    if (work->restoreMode19 == 1)
        work->arg->mode = 0x19;
    if (work->restoreMode1A == 1)
        work->arg->mode = 0x1a;
    func_020355D8(work->touchMode);
    return 1;
}








/*
 * Case 20 is written before case 19: case 19's fallback repeats case 20's
 * body and mwcc tail-merges it into the earlier copy, which puts case 20's
 * code first in the original.
 */
int func_021B68F0(PokelistWork *work)
{
    u8 i;
    PokelistFn fn;

    switch (work->phase) {
    case 0:
        func_0202208C((void *)2, 1, 1, 0, 6, 1, work->heapId);
        work->phase = 1;
        break;
    case 1:
        if (func_020221A4() == 1)
            work->phase = work->nextPhase;
        break;
    case 2:
    case 3:
    case 4:
        func_021B83D8(work);
        break;
    case 5:
        func_021B981C(work);
        break;
    case 6:
        func_021B9020(work);
        break;
    case 7:
        func_021B9750(work);
        break;
    case 9:
        func_021B97D4(work);
        break;
    case 10:
        func_021BB30C(work, work->plates[work->selectedSlot]);
        if (work->healSoundPending == 1) {
            work->healSoundPending = 0;
            func_020061E4(0x56f);
        }
        work->phase = 0xb;
    case 11:
        if (func_021BB358(work, (struct S *)(work->plates[work->selectedSlot])) == 1) {
            fn = work->phaseCallback;
            if (fn != 0)
                fn(work);
            else
                work->phase = 0x15;
        }
        break;
    case 12:
        work->waitFrames++;
        if (work->waitFrames > 0x10) {
            if (work->restoreMode1A == 1) {
                if (func_021B6184(work->arg, 0, 0) == 1) {
                    work->phase = 0x11;
                    func_021BBE44(work->commandButtons[0]);
                    func_021BBE44(work->commandButtons[1]);
                    work->commandButtons[0] = 0;
                    work->commandButtons[1] = 0;
                    func_021BB714(work, (u32 *)work->messageWindow, 0);
                    func_021BB7E8(work, (u32 *)work->messageWindow, 0xb0);
                    func_021BBA68(work, (u8 *)work->messageWindow);
                }
            } else {
                work->phase = 0x13;
            }
        }
        break;
    case 13:
        func_021BC6CC(work);
        break;
    case 14:
        func_021BD8B0(work);
        break;
    case 15:
        func_021BD9C8(work);
        break;
    case 16:
        func_021BD8E4(work);
        break;
    case 17:
        func_021B61E8(work->arg, 2);
        work->phase = 0x12;
        break;
    case 18:
        if (func_021B61FC(work->arg, 2) == 1)
            work->phase = 0x13;
        break;
    case 20:
        func_0202208C(0, 0, 0, 0, 6, 1, work->heapId);
        work->phase = 0x15;
        break;
    case 19:
        if (work->pressedButtonActor == 0 || func_0204B98C((struct Actor *)work->pressedButtonActor) == 0) {
            func_0202208C(0, 0, 0, 0, 6, 1, work->heapId);
            work->phase = 0x15;
        }
        break;
    case 21:
        if (func_020221A4() == 1)
            return 1;
        break;
    }
    for (i = 0; i < 6; i++)
        func_021BA8CC(work, work->plates[i]);
    func_021BB644(work, (u8 *)work->messageWindow);
    func_021B6B24(work);
    if (func_021B9A84(work) == 1) {
        func_021BCDE8(work);
        func_021BBE50(work->commandButtons[0]);
        func_021BBE50(work->commandButtons[1]);
    }
    func_0201C4E4((struct PrintSys *)work->printSys);
    func_0204A600();
    return 0;
}








/*
 * Palette fade (u8 step countdown at +0x100, brighten src[3][16] into dst, skipping
 * columns 2..4, then a sine blend of dst[i][2..4] between two 3-colour tables, then
 * func_02061CA4(15, 0xc0, dst, 0x60)).
 * note: final push 2026-10-05 G9L1, EXACT in c99 and c. Four source facts closed the draft
 * (182 B off): (1) the phase update stores in each if/else arm (work->phase = work->phase - 0xfc00
 * or work->phase = t), so the 0x102 offset stays live in r1 and v sits in r3; (2) each blended
 * channel is clamped into a shared int t (`...; r = t;`) and assigned to a u8 local, which
 * puts the byte truncation at the join as in the image; (3) the blend deltas are written
 * red first (ar, br, dr, then green, then blue); the scheduler still emits green first, but
 * the red values are born first and take the registers the image shows; (4) f is declared
 * after the counters, and b is u16 while a is int. Earlier notes: hi and lo are two PokelistBlend
 * locals, each delta is read three times (clamp), tried-and-failed forms in git history.
 * Callee 02061CA4 matches its 4-parameter definition.
 */
void func_021B6B24(PokelistWork *work)
{
    u8 i;
    u8 i2;
    u8 j;
    u8 j2;
    u8 k;
    int f;
    PokelistBlend hi;
    PokelistBlend lo;

    func_02082A60(work->palSrc, work->palDst, 0x60);
    if (work->fadeStep != 0) {
        work->fadeStep--;
        k = work->fadeStep;
        if (k > 6) {
            k = 12 - k;
        }
        for (i = 0; i < 3; i++) {
            for (j = 0; j < 16; j++) {
                if (j >= 2 && j <= 4) {
                    continue;
                }
                {
                    u16 c = work->palSrc[i][j];
                    u8 g = (c & 0x3e0) >> 5;
                    u8 b = (c & 0x7c00) >> 10;
                    u8 r = c & 0x1f;
                    int t;
                    t = r + k * 2;
                    if (t > 31) t = 31;
                    r = t;
                    t = g + k * 2;
                    if (t > 31) t = 31;
                    g = t;
                    t = b + k * 2;
                    if (t > 31) t = 31;
                    b = t;
                    work->palDst[i][j] = r | (g << 5) | (b << 10);
                }
            }
        }
    }
    hi = d_021BEBFC;
    lo = d_021BEC04;
    if (work->fadeMode == 0) {
        int t = work->fadePhase + 0x400;
        if (t >= 0x10000) {
            work->fadePhase = work->fadePhase - 0xfc00;
        } else {
            work->fadePhase = t;
        }
    } else {
        work->fadePhase = 0xc000;
    }
    f = (d_020A1B38[(work->fadePhase >> 4) * 2] + 0x1000) / 2;
    for (i2 = 0; i2 < 3; i2++) {
        for (j2 = 0; j2 < 3; j2++) {
            int a = hi.v[j2];
            u16 b = lo.v[j2];
            u8 ar = a & 0x1f;
            u8 br = b & 0x1f;
            s8 dr = ((br - ar) * f) >> 12;
            u8 ag = (a & 0x3e0) >> 5;
            u8 bg = (b & 0x3e0) >> 5;
            s8 dg = ((bg - ag) * f) >> 12;
            u8 ab = (a & 0x7c00) >> 10;
            u8 bb = (b & 0x7c00) >> 10;
            s8 db = ((bb - ab) * f) >> 12;
            u8 r, g, bl;
            int t;
            if (ar + dr > 31) t = 31; else if (ar + dr < 0) t = 0; else t = ar + dr;
            r = t;
            if (ag + dg > 31) t = 31; else if (ag + dg < 0) t = 0; else t = ag + dg;
            g = t;
            if (ab + db > 31) t = 31; else if (ab + db < 0) t = 0; else t = ab + db;
            bl = t;
            work->palDst[i2][j2 + 2] = r | (g << 5) | (bl << 10);
        }
    }
    func_02061CA4((void *)15, 0xc0, (u32)work->palDst, 0x60);
}








static inline void GX_SetVisibleWnd(int window)
{
    reg_GX_DISPCNT = reg_GX_DISPCNT & ~0xE000 | (window << 13);
}








void func_021B6D64(void *tcb, PokelistWork *work)
{
    if (work->fadeMode == 1)
        GX_SetVisibleWnd(1);
    else
        GX_SetVisibleWnd(0);
    func_0204A648();
}






static inline void GX_SetVisiblePlane(int plane)
{
    reg_GX_DISPCNT = (u32)((reg_GX_DISPCNT & ~0x1f00) | (plane << 8));
}






static inline void GXS_SetVisiblePlane(int plane)
{
    reg_GXS_DB_DISPCNT = (u32)((reg_GXS_DB_DISPCNT & ~0x1f00) | (plane << 8));
}






static inline void GX_SetDispSelect(GXDispSelect sel)
{
    reg_GX_POWCNT = (u16)((reg_GX_POWCNT & ~0x8000) | (sel << 15));
}






void func_021B6D90(PokelistWork *work)
{
    PokelistVramBanks a;
    PokelistClactConfig b;

    a = d_021BEC3C;
    if (func_021B9A84(work) == 1) {
        a.w[6] = 8;
        a.w[8] = 0;
    } else {
        a.w[6] = 0x100;
    }
    BG_SYS_ClearMainPlanes();
    BG_SYS_ClearSubPlanes();
    GX_SetVisiblePlane(0);
    GXS_SetVisiblePlane(0);
    func_0202223C(0, 0);
    func_0202223C(1, 0);
    WIPE_ResetWndMask(0);
    WIPE_ResetWndMask(1);
    GX_SetDispSelect(GX_DISP_SELECT_SUB_MAIN);
    func_020433E0((const struct DispVram *)(&a));
    func_0203F8F4(work->heapId);
    func_02045088(work->heapId);
    func_0203FC28((struct DispConfig *)d_021BEAEC);
    func_021B7078(d_021BEBDC, 3, 0);
    func_021B7078(d_021BEBBC, 2, 0);
    func_021B7078(d_021BEB9C, 1, 0);
    func_021B7078(d_021BEB5C, 7, 0);
    func_021B7078(d_021BEB3C, 6, 0);
    func_021B7078(d_021BEB1C, 5, 0);
    func_021B7078(d_021BEAFC, 4, 0);
    func_021B6F0C(work);
    func_0207D63C(0x04000050, 0x14, 8, 0x10, 10);
    func_0207D63C(0x04001050, 4, 8, 0x10, 10);
    func_02040618(2, 0, 0x80);
    func_02040618(1, 0, 0x80);
    b = d_020A1448;
    func_0204A48C((const struct Cfg *)(&b), (u32)(&a), work->heapId);
    func_020434DC(0x10, 1);
    func_02043598(0x10, 1);
    func_02061C30();
}




void func_021B6F0C(PokelistWork *work) { func_0207D4B0(1,0,0); func_021B7078(d_021BEB7C,0,0); }





void func_021B6F28(PokelistWork *work)
{
    int r;

    func_0207D4B0(1, 0, 1);
    func_02046440(0, 1, 0, 1, 0, work->heapId, 0);
    *(volatile u16 *)0x04000008 = *(volatile u16 *)0x04000008 & ~3;
    *(volatile u16 *)0x04000060 = (*(volatile u16 *)0x04000060 & ~0x3000) | 0x20;
    *(volatile u16 *)0x04000060 = (*(volatile u16 *)0x04000060 & ~0x3000) | 0x10;
    *(volatile u16 *)0x04000060 = (*(volatile u16 *)0x04000060 & ~0x3000) | 8;
    r = func_02048A24(2, 0, 0x50D7, 0, 0x6BCA, 0x1000, 0x80000, 0, d_021BEAB8, d_021BEAD0, d_021BEAC4, work->heapId);
    work->light = r;
    func_02048AD0((struct Light *)r);
    func_0207D63C(0x04000050, 4, 0x1e, 0x10, 10);
    func_02050B80(work->heapId);
}





/*
 * `ldr ip,[pc,#4]; ldr r0,[pc,#4]; bx ip; .word 0x02061B5C; .word 0x02146B80`,
 * no witness outside this range.  Leaf C tried (DIFF only, the two loads and
 * the two pool words come out swapped, 8 bytes):
 *   extern void func_02061B5C(void *); extern char d_02146B80[];
 *   void func_02061C30(void) { func_02061B5C(d_02146B80); }
 *   (`return func_02061B5C((int)d_02146B80)` with int types: same DIFF)
 */
void func_021B6FEC(PokelistWork *work)
{
    func_02061C30();
    func_0204A5AC();
    func_021B7034(work);
    func_020403F4(3);
    func_020403F4(2);
    func_020403F4(1);
    func_020403F4(7);
    func_020403F4(6);
    func_020403F4(5);
    func_020403F4(4);
    func_020450C8();
    func_0203F9B4();
}




void func_021B7034(PokelistWork *work)
{
    func_020403F4(0);
}



void func_021B7040(PokelistWork *work) { func_02050ED4(); func_02048AC4((void *)(work->light)); func_02046788(); func_020403F4(0); func_0207D63C(0x04000050,20,8,16,10); }



void func_021B7078(const void *work, unsigned id,unsigned type) { func_0203FCA0(id,work,type); func_02040588(id,1); func_020414AC(id); func_020409B4(id); }




void func_021B709C(PokelistWork *work)
{
    PokelistActorTemplate cursorTemplate;
    PokelistActorTemplate buttonTemplate;
    struct Obj *x;
    struct Bank *bank;

    bank = func_0204B100(10, 8, work->heapId);
    work->clactUnit = bank;
    CLACT_SetUnitDefaultRenderer(bank);
    cursorTemplate.x = 0;
    cursorTemplate.y = 0;
    cursorTemplate.animNo = 0;
    cursorTemplate.priority = 10;
    cursorTemplate.drawArea = 3;
    work->cursorActor = func_0204B294(work->clactUnit, work->palRes[0],
                                        work->charRes[0], work->cellRes[0], &cursorTemplate, 0, work->heapId);
    work->swapMarkerActor = func_0204B294(work->clactUnit, work->palRes[0],
                                        work->charRes[0], work->cellRes[0], &cursorTemplate, 0, work->heapId);
    func_0204B92C(work->cursorActor, 1);
    func_0204B92C(work->swapMarkerActor, 1);
    func_0204B3DC(work->cursorActor, 0);
    func_0204B3DC(work->swapMarkerActor, 0);
    buttonTemplate.x = 0xe0;
    buttonTemplate.y = 0xa8;
    buttonTemplate.animNo = 1;
    buttonTemplate.priority = 0;
    buttonTemplate.drawArea = 0;
    x = func_0204B294(work->clactUnit, work->palRes[2],
                      work->charRes[1], work->cellRes[2], &buttonTemplate, 0, work->heapId);
    work->backButtonActor = x;
    func_0204B92C(x, 1);
    buttonTemplate.x = 0xc4;
    buttonTemplate.animNo = 0;
    x = func_0204B294(work->clactUnit, work->palRes[2],
                      work->charRes[1], work->cellRes[2], &buttonTemplate, 0, work->heapId);
    work->switchButtonActor = x;
    func_0204B92C(x, 1);
}


void func_021B71B0(PokelistWork *work) { func_0204B3B4(work->backButtonActor); func_0204B3B4(work->switchButtonActor); func_0204B3B4(work->cursorActor); func_0204B3B4(work->swapMarkerActor); func_0204B1CC(work->clactUnit); }



void func_021B71E4(PokelistWork *work)
{
    work->fontMain = func_0201D7EC(0x17, 0, 0, 0, work->heapId);
    work->fontSub = func_0201D7EC(0x17, 3, 0, 0, work->heapId);
    work->msgBank = func_02045B38(0, 2, 0x9d, work->heapId);
    func_02049B40(0x17, 5, 0, 0x1c0, 0x20, work->heapId);
    func_02049B40(0x17, 5, 4, 0x1c0, 0x20, work->heapId);
    work->printSys = func_0201C450(0x1800, work->heapId);
    func_0201DD68();
}


void func_021B7268(PokelistWork *work) { func_0201C6EC((struct PrintSys *)(work->printSys)); func_0201C4C0((struct PrintSys *)(work->printSys)); func_02045C04((struct Rec *)(work->msgBank)); func_0201D83C(work->fontSub); func_0201D83C(work->fontMain); }



/*
 * Graphics setup: loads BG/char/screen/palette data from archive 0x4c, the
 * 0x07 archive and the func_020275E4 archive into work's handle table
 * (work+0x178..0x1d0), then copies palette RAM 0x050000C0 back to work+0x40.
 * The second-archive loads still pass the first (closed) handle to
 * func_02049B68/02049658/020498F4, as the original does.  The 0x158 store
 * goes through a local: stored directly, the allocator rematerialises the
 * shared 0xc0 offset base instead of reloading its [sp+0xc] spill slot.
 */
void func_021B7298(PokelistWork *work)
{
    void *h;
    void *h2;
    void *t;

    h = func_020490F4(0x4c, work->heapId);
    func_02049B68(h, 6, 0, 0, 0, work->heapId);
    func_02049B68(h, 0, 0, 0x1a0, 0x20, work->heapId);
    func_02049658(h, 0xf, 3, 0, 0, 0, work->heapId);
    func_020498F4(h, 0x14, 3, 0, 0, 0, work->heapId);
    func_02049658(h, 0xc, 2, 0, 0, 0, work->heapId);
    t = func_02049EF4(h, 0x12, 0, &work->paletteData, work->heapId);
    work->paletteFile = t;
    func_02049B68(h, 5, 4, 0, 0, work->heapId);
    func_02049658(h, 0xe, 7, 0, 0, 0, work->heapId);
    func_020498F4(h, 0x13, 7, 0, 0, 0, work->heapId);
    work->charRes[0] = func_0204AC18(h, 4, 0, 0, 0, 3, work->heapId);
    work->palRes[0] = func_0204A6C8(h, 0xb, 0, 0, work->heapId);
    work->palRes[1] = func_0204A6C8(h, 8, 0, 0, work->heapId);
    work->cellRes[0] = func_0204AF28(h, 0x17, 0x1a, work->heapId);
    work->cellRes[1] = func_0204AF28(h, 0x16, 0x19, work->heapId);
    func_02049238(h);

    h2 = func_020490F4(7, work->heapId);
    work->charRes[6] = func_0204ACEC(h2, func_0201BC3C(), 0, 0xc0, work->heapId);
    work->cellRes[7] = func_0204AF28(h2, func_0201BC40(), func_0201BCB4(), work->heapId);
    func_02049238(h2);

    h2 = func_020490F4(func_020275E4(), work->heapId);
    func_02049B68(h, func_02027624(), 0, 0x160, 0x20, work->heapId);
    func_02049658(h, func_02027628(), 1, 0, 0, 0, work->heapId);
    func_020498F4(h, func_02027630(), 1, 0, 0, 0, work->heapId);
    func_020413B0(1, 0, 0, 0x40, 0x20, 0xb);
    work->charRes[5] = func_0204AC18(h2, func_02027758(), 0, 0xa0, 0, 1, work->heapId);
    work->palRes[6] = func_0204A6C8(h2, func_0202775C(2), 0, 0, work->heapId);
    work->cellRes[6] = func_0204AF28(h2, func_02027760(2), func_02027764(2), work->heapId);
    work->charRes[1] = func_0204AC18(h2, func_02027614(), 0, 0x120, 0, 3, work->heapId);
    work->palRes[2] = func_0204A6C8(h2, func_02027618(), 0, 0, work->heapId);
    work->cellRes[2] = func_0204AF28(h2, func_0202761C(2), func_02027620(2), work->heapId);
    work->charRes[2] = func_0204AC18(h2, func_02027694(), 0, 0x60, 0, 1, work->heapId);
    work->palRes[3] = func_0204A6C8(h2, func_02027698(), 0, 0, work->heapId);
    work->cellRes[3] = func_0204AF28(h2, func_0202769C(2), func_020276A0(2), work->heapId);
    work->charRes[4] = func_0204AC18(h2, func_020276B4(), 0, 0x80, 0, 1, work->heapId);
    work->palRes[5] = func_0204A6C8(h2, func_020276B8(), 0, 0, work->heapId);
    work->cellRes[5] = func_0204AF28(h2, func_020276BC(2), func_020276C0(2), work->heapId);
    func_02049238(h2);
    func_02082A60((void *)0x050000C0, (u8 *)work->palSrc, 0x60);
}



void func_021B7624(PokelistWork *work)
{
    u8 i;

    func_020307B0(work->paletteFile);
    for (i = 0; i < 8; i++) {
        if ((&work->charRes[0])[i] != -1)
            func_0204ADA4((&work->charRes[0])[i]);
    }
    for (i = 8; i < 15; i++) {
        if ((&work->charRes[0])[i] != -1)
            func_0204A8D4((&work->charRes[0])[i]);
    }
    for (i = 15; i < 23; i++) {
        if ((&work->charRes[0])[i] != -1)
            func_0204AFD8((&work->charRes[0])[i]);
    }
}

#undef W



/*
 * lever: one named offset shared across the case 7/8 branch join.
 */
void func_021B7698(PokelistWork *work)
{
    u32 old;
    int r,id,off;
    switch ((u32)work->arg->mode) {
    case 1:
        work->commandButtons[0]=func_021BBDEC(work,work->contextMenu,0,0x16,0x15,0);
        func_021B7B98(work); work->nextPhase=2; return;
    case 22: case 23:
        work->commandButtons[0]=func_021BBDEC(work,work->contextMenu,0,0xc,0x15,0);
        work->commandButtons[1]=func_021BBDEC(work,work->contextMenu,1,0x16,0x15,1);
        func_021B7B98(work); work->nextPhase=2; return;
    case 0: case 6: case 9: case 14: case 16: case 18: case 21: case 25:
        func_021B7B98(work); work->nextPhase=2; return;
    case 3:
        work->switchButtonEnabled=0; func_021B7B98(work); work->nextPhase=2; return;
    case 5:
        if (func_021BC1B4(work,(void *)work->arg->itemId)==1) {
            r=func_021BC1D0(work);
            if (r != -1) {
                work->selectedSlot=r; work->selectedMon=(u32)func_0201AB28(work->arg->party,r);
                func_021BC350(work,0);
                func_021BE2B4((void *)work->selectedMon,work->arg->itemId,(int)0,work->arg->itemUseParam,(u16)(work->heapId));
                func_021BB2C0(work,work->plates[work->selectedSlot]);
                work->healSoundPending=1; work->nextPhase=work->phase; work->phase=0;
                func_021BA670(work,work->arg->itemId); return;
            }
            func_021BC2C8(work); work->nextPhase=work->phase; work->phase=0; return;
        }
        if (func_021BA65C(work,work->arg->itemId) != 0) {
            func_021B7B98(work); work->nextPhase=2; return;
        }
        work->arg->exitCode=10;
        func_021BB7A4(work,(u32 *)work->messageWindow); func_021BB97C(work,work->messageWindow);
        func_021BB9AC(work,work->messageWindow,(u32)0,(u16)work->arg->itemId);
        func_021B9788(work,0xb3,1,func_021B9E3C);
        func_021BB98C(work,work->messageWindow); work->nextPhase=work->phase; work->phase=0; return;
    case 7: case 8:
        work->selectedSlot=work->arg->selectedIndex; work->selectedMon=(u32)func_0201AB28(work->arg->party,work->arg->selectedIndex);
        if (work->arg->moveSlot < 4) {
            old=func_02017E1C((void *)work->selectedMon,work->arg->moveSlot+0x36,0);
            off=0x150;
            func_021BB97C(work,(*(int *)((u8 *)work + off))); func_021BB99C(work,(*(int *)((u8 *)work + off)),0,work->selectedMon);
            func_021BB9CC(work,(u32)(*(int *)((u8 *)work + off)),(u32)1,(u16)old);
            func_021B9788(work,0x28,1,func_021BA004);
        } else {
            off=0x150;
            func_021BB97C(work,(*(int *)((u8 *)work + off))); func_021BB9CC(work,(u32)(*(int *)((u8 *)work + off)),(u32)1,(u16)work->arg->moveId);
            func_021B9788(work,0x23,0,func_021B9F34);
        }
        func_021BB98C(work,(*(int *)((u8 *)work + off)));
        work->nextPhase=7; work->phase=0; work->switchButtonEnabled=0;
        func_021BAFA0(work,work->plates[work->selectedSlot],1); return;
    case 10:
        work->selectedSlot=work->arg->selectedIndex; work->selectedMon=(u32)func_0201AB28(work->arg->party,work->arg->selectedIndex);
        if (work->arg->itemId == 0) {
            work->arg->mode=0; func_021B7B98(work); work->nextPhase=2;
        } else {
            old=func_02017E1C((void *)work->selectedMon,6,0);
            if (old == 0) {
                func_021BA624(work,(void *)work->selectedMon,work->arg->itemId);
                func_021BB2C0(work,work->plates[work->selectedSlot]);
                func_021BB97C(work,work->messageWindow); func_021BB99C(work,work->messageWindow,0,work->selectedMon);
                func_021BB9AC(work,work->messageWindow,(u32)1,(u16)work->arg->itemId);
                func_021BC24C(work,(void *)work->selectedMon,(u16)work->arg->itemId);
                func_021BC288(work,(void *)work->selectedMon,work->arg->itemId);
                if (func_021BDBF8(work,(void *)work->selectedMon)==1) {
                    func_021BDC3C(work,(void *)work->selectedMon); func_021B9788(work,0x56,1,func_021BA4E4); work->evolveCheckKind=1;
                } else func_021B9788(work,0x56,1,func_021B9E20);
                func_021BB98C(work,work->messageWindow); work->arg->mode=0;
            } else {
                func_021BB97C(work,work->messageWindow); func_021BB99C(work,work->messageWindow,0,work->selectedMon);
                func_021BB9BC(work,work->messageWindow,1,(u16)old);
                func_021B9788(work,0x3a,0,func_021BA098); func_021BB98C(work,work->messageWindow);
            }
        }
        work->nextPhase=7; work->phase=0; work->switchButtonEnabled=1;
        func_021BAFA0(work,work->plates[work->selectedSlot],1); return;
    case 11: case 12:
        work->selectedSlot=work->arg->selectedIndex; work->selectedMon=(u32)func_0201AB28(work->arg->party,work->arg->selectedIndex);
        old=func_02017E1C((void *)work->selectedMon,6,0);
        func_021BB97C(work,work->messageWindow);
        if (old == 0) {
            id=0x56;
            func_021BB99C(work,work->messageWindow,0,work->selectedMon);
            func_021BB9AC(work,work->messageWindow,(u32)1,(u16)work->arg->itemId);
        } else {
            id=0x40;
            func_021BB99C(work,work->messageWindow,0,work->selectedMon);
            func_021BB9AC(work,work->messageWindow,(u32)1,(u16)old);
            func_021BB9AC(work,work->messageWindow,(u32)2,(u16)work->arg->itemId);
        }
        func_021BA624(work,(void *)work->selectedMon,work->arg->itemId);
        func_021BB2C0(work,work->plates[work->selectedSlot]);
        func_021BC24C(work,(void *)work->selectedMon,(u16)work->arg->itemId);
        func_021BC288(work,(void *)work->selectedMon,work->arg->itemId);
        if (func_021BDC5C(work,(void *)work->selectedMon)==1) {
            func_021BDCA0(work,(void *)work->selectedMon); func_021B9788(work,id,1,func_021BA4E4); work->evolveCheckKind=2;
        } else if (work->arg->mode==11) func_021B9788(work,id,1,func_021B9E3C);
        else func_021B9788(work,id,1,func_021B9E20);
        func_021BB98C(work,work->messageWindow);
        if (work->arg->mode==11) work->arg->exitCode=10; else work->arg->mode=0;
        work->nextPhase=7; work->phase=0; work->switchButtonEnabled=1;
        break;
    }
}



/*
 * EXACT*: the listing extent's last two bytes (0x021B7CC2) are alignment
 * padding before the next function, not a follower.
 */
void func_021B7B98(PokelistWork *work)
{
    func_020409B4(0);
    switch (work->arg->mode) {
    case 0:
        func_021BB714(work, (u32 *)work->messageWindow, 0);
        func_021BB7E8(work, (u32 *)work->messageWindow, 9);
        work->switchButtonEnabled = 1;
        break;
    case 1:
        func_021BD4EC(work);
        func_0204B3DC(work->backButtonActor, 0);
        work->switchButtonEnabled = 0;
        break;
    case 22:
    case 23:
        work->switchButtonEnabled = 0;
        break;
    case 5:
    case 16:
        func_021BB714(work, (u32 *)work->messageWindow, 0);
        func_021BB7E8(work, (u32 *)work->messageWindow, 0xd);
        work->switchButtonEnabled = 0;
        work->allowDisabledSelect = 0;
        break;
    case 9:
    case 14:
        func_021BB714(work, (u32 *)work->messageWindow, 0);
        func_021BB7E8(work, (u32 *)work->messageWindow, 0xc);
        work->switchButtonEnabled = 0;
        work->allowDisabledSelect = 0;
        break;
    case 6:
        func_021BB714(work, (u32 *)work->messageWindow, 0);
        func_021BB7E8(work, (u32 *)work->messageWindow, 0xe);
        work->switchButtonEnabled = 0;
        work->allowDisabledSelect = 0;
        break;
    case 18:
        func_021BB714(work, (u32 *)work->messageWindow, 0);
        func_021BB7E8(work, (u32 *)work->messageWindow, 0x10);
        work->switchButtonEnabled = 0;
        break;
    case 3:
    case 25:
        func_021BB714(work, (u32 *)work->messageWindow, 0);
        func_021BB7E8(work, (u32 *)work->messageWindow, 9);
        work->switchButtonEnabled = 0;
        break;
    case 21:
        func_021BB714(work, (u32 *)work->messageWindow, 0);
        func_021BB7E8(work, (u32 *)work->messageWindow, 0xa3);
        func_0204B3DC(work->backButtonActor, 0);
        work->switchButtonEnabled = 0;
        break;
    }
    func_021B8418(work);
}


#undef W

#undef W


void func_021B7CC4(PokelistWork *work)
{
    u32 old,buf;
    int r;
    if (work->arg->closeRequested == 1) { work->phase=0x13; return; }
    switch ((u32)work->arg->mode) {
    case 0: case 1: case 18: case 21: case 22: case 23: case 25:
        func_021B907C(work); func_020409B4(0); func_021B8180(work); return;
    case 5:
        if (func_021BC17C(work,work->arg->itemId) == 1) {
            func_021B907C(work); func_021B8180(work); return;
        }
        if (func_021BDD78((void *)work->selectedMon,(u16)work->arg->itemId,0,(u16)(work->heapId)) == 1) {
            r=func_021BC350(work,0);
            func_021BE2B4((void *)work->selectedMon,work->arg->itemId,(int)0,work->arg->itemUseParam,(u16)(work->heapId));
            if (r == 2) func_021BB200(work,work->plates[work->selectedSlot],(void *)work->selectedMon,0);
            else if (r == 19 || r == 13) {
                func_021BB200(work,work->plates[work->selectedSlot],(void *)work->selectedMon,0);
                func_020061E4(0x56f);
            } else {
                func_021BB2C0(work,work->plates[work->selectedSlot]);
                func_020061E4(0x56f);
            }
            func_021BA670(work,work->arg->itemId); return;
        }
        if (work->arg->itemId==0x1d2 && func_021BDCC0(work,work->selectedMon)==1) {
            func_021BDD58(work,(void *)work->selectedMon); work->arg->exitCode=10; work->phase=14; work->evolveCheckKind=3; return;
        }
        func_021BC30C(work); return;
    case 16:
        if (func_021B9BF4(work,(void *)work->selectedMon,work->arg->itemId) != 0) {
            func_021BA670(work,work->arg->itemId); work->phase=19; work->arg->selectedIndex=work->selectedSlot; work->arg->exitCode=8;
        } else func_021B9788(work,0x51,1,func_021B9E3C);
        return;
    case 9:
        old=func_02017E1C((void *)work->selectedMon,6,0);
        if (old == 0) {
            if (func_0202136C(work->arg->itemId) == 1) {
                work->phase=19; work->arg->selectedIndex=work->selectedSlot; work->arg->exitCode=6; return;
            }
            work->arg->exitCode=10;
            func_021BA624(work,(void *)work->selectedMon,work->arg->itemId);
            func_021BB2C0(work,work->plates[work->selectedSlot]);
            func_021BB97C(work,work->messageWindow);
            func_021BB99C(work,work->messageWindow,0,work->selectedMon);
            func_021BB9AC(work,work->messageWindow,1,work->arg->itemId);
            func_021BC24C(work,(void *)work->selectedMon,(u16)work->arg->itemId);
            func_021BC288(work,(void *)work->selectedMon,work->arg->itemId);
            if (func_021BDBF8(work,(void *)work->selectedMon) == 1) {
                func_021BDC3C(work,(void *)work->selectedMon);
                func_021B9788(work,0x56,1,func_021BA4E4); work->evolveCheckKind=1;
            } else func_021B9788(work,0x56,1,func_021B9E3C);
            func_021BB98C(work,work->messageWindow); return;
        }
        if (func_0202136C(old)==1) {
            work->arg->exitCode=10; func_021B9788(work,0x39,1,func_021B9E3C); return;
        }
        func_021BB97C(work,work->messageWindow);
        func_021BB99C(work,work->messageWindow,0,work->selectedMon);
        func_021BB9BC(work,work->messageWindow,1,(u16)old);
        func_021B9788(work,0x3a,0,func_021BA098);
        func_021BB98C(work,work->messageWindow); return;
    case 14:
        if (func_02017E1C((void *)work->selectedMon,6,0) == 0) {
            buf=(u32)func_02009050(work->arg->mailBox,0,work->arg->mailSlot,work->heapId);
            func_02017E40((void *)work->selectedMon,0xa7,buf); func_020307B0((void *)buf);
            func_02017E40((void *)work->selectedMon,6,work->arg->itemId);
            func_0200902C(work->arg->mailBox,0,work->arg->mailSlot);
            func_021B9788(work,0x62,1,func_021B9E3C);
        } else func_021B9788(work,0x63,1,func_021B9E3C);
        return;
    case 6:
        switch ((u32)func_021B9AC8(work,(void *)work->selectedMon,work->arg->selectedIndex)) {
        case 0:
            work->arg->exitCode=10;
            func_021BB97C(work,work->messageWindow); func_021BB99C(work,work->messageWindow,0,work->selectedMon);
            func_021BB9CC(work,work->messageWindow,1,work->arg->moveId);
            func_021B9788(work,0x29,1,func_021B9E3C); func_021BB98C(work,work->messageWindow);
            func_021BA5B4(work,(void *)work->selectedMon); func_021BA60C(work,(void *)work->selectedMon); return;
        case 1:
            func_021BB97C(work,work->messageWindow); func_021BB99C(work,work->messageWindow,0,work->selectedMon);
            func_021BB9CC(work,work->messageWindow,1,work->arg->moveId);
            func_021B9788(work,0x20,0,func_021B9EB0); func_021BB98C(work,work->messageWindow); return;
        case 2:
            work->arg->exitCode=10;
            func_021BB97C(work,work->messageWindow); func_021BB99C(work,work->messageWindow,0,work->selectedMon);
            func_021BB9CC(work,work->messageWindow,1,work->arg->moveId);
            func_021B9788(work,0x2a,1,func_021B9E3C); func_021BB98C(work,work->messageWindow); return;
        case 3:
            work->arg->exitCode=10;
            func_021BB97C(work,work->messageWindow); func_021BB99C(work,work->messageWindow,0,work->selectedMon);
            func_021BB9CC(work,work->messageWindow,1,work->arg->moveId);
            func_021B9788(work,0x2b,1,func_021B9E3C); func_021BB98C(work,work->messageWindow); return;
        }
        return;
    case 3:
        work->phase=19; work->arg->selectedIndex=work->selectedSlot; work->arg->exitCode=0; return;
    default:
        func_021B907C(work); func_021B8180(work); return;
    }
}


#undef W

#undef W




/*
 * EXACT*: the extent's last two bytes (0x021B83D6) are alignment padding.
 * func_021BBAF8 is declared with a third argument: this caller loads
 * `add r2, sp, #0` (the 32-byte buf) before the bl.  The switch value is
 * signed (bgt/blt compare tree).
 */
void func_021B8180(PokelistWork *work)
{
    int buf[8];

    func_020409B4(0);
    switch (work->arg->mode) {
    case 0:
        if (func_021BB468(work, work->plates[work->selectedSlot]) == 1) {
            buf[1] = 3;
            buf[2] = 6;
            buf[0] = 0;
            buf[3] = 0x10;
        } else {
            buf[1] = 1;
            buf[2] = 3;
            buf[3] = 4;
            buf[0] = 0;
            buf[4] = 6;
            buf[5] = 0x10;
            if (func_0202136C(func_02017E1C((void *)work->selectedMon, 6, 0)) == 1) {
                buf[3] = 5;
            }
        }
        func_021BB97C(work, work->messageWindow);
        func_021BB99C(work, work->messageWindow, 0, work->selectedMon);
        func_021BB714(work, (u32 *)work->messageWindow, 2);
        func_021BB7E8(work, (u32 *)work->messageWindow, 0x12);
        func_021BB98C(work, work->messageWindow);
        break;
    case 1:
    case 22:
    case 23:
        if (func_021BB468(work, work->plates[work->selectedSlot]) == 1) {
            buf[0] = 0;
            buf[1] = 6;
            buf[2] = 0x10;
        } else {
            buf[0] = 8;
            buf[1] = 0;
            buf[2] = 6;
            buf[3] = 0x10;
        }
        func_021BB97C(work, work->messageWindow);
        func_021BB99C(work, work->messageWindow, 0, work->selectedMon);
        func_021BB714(work, (u32 *)work->messageWindow, 2);
        func_021BB7E8(work, (u32 *)work->messageWindow, 0x12);
        func_021BB98C(work, work->messageWindow);
        break;
    case 5:
        buf[0] = 2;
        buf[1] = 6;
        buf[2] = 0x10;
        func_021BB97C(work, work->messageWindow);
        func_021BB99C(work, work->messageWindow, 0, work->selectedMon);
        func_021BB714(work, (u32 *)work->messageWindow, 2);
        func_021BB7E8(work, (u32 *)work->messageWindow, func_021BC228(work, work->arg->itemId));
        func_021BB98C(work, work->messageWindow);
        break;
    case 18:
        if (func_021BB468(work, work->plates[work->selectedSlot]) == 1) {
            buf[1] = 6;
            buf[0] = 0;
            buf[2] = 0x10;
        } else {
            buf[0] = 7;
            buf[2] = 6;
            buf[1] = 0;
            buf[3] = 0x10;
        }
        func_021BB97C(work, work->messageWindow);
        func_021BB99C(work, work->messageWindow, 0, work->selectedMon);
        func_021BB714(work, (u32 *)work->messageWindow, 2);
        func_021BB7E8(work, (u32 *)work->messageWindow, 0x12);
        func_021BB98C(work, work->messageWindow);
        break;
    case 21:
        if (func_021BB468(work, work->plates[work->selectedSlot]) == 1) {
            buf[0] = 0xb;
            buf[2] = 6;
            buf[3] = 0x10;
            buf[1] = 0;
            func_021BB714(work, (u32 *)work->messageWindow, 2);
            func_021BB7E8(work, (u32 *)work->messageWindow, 0xa2);
        } else {
            buf[1] = 6;
            buf[2] = 0x10;
            buf[0] = 0;
            func_021BB97C(work, work->messageWindow);
            func_021BB99C(work, work->messageWindow, 0, work->selectedMon);
            func_021BB714(work, (u32 *)work->messageWindow, 2);
            func_021BB7E8(work, (u32 *)work->messageWindow, 0x12);
            func_021BB98C(work, work->messageWindow);
        }
        break;
    case 25:
        if (func_021F6744((void *)work->selectedMon) == 1) {
            buf[0] = 0xb;
            buf[1] = 0;
            buf[2] = 6;
            buf[3] = 0x10;
        } else {
            buf[0] = 0;
            buf[1] = 6;
            buf[2] = 0x10;
        }
        func_021BB97C(work, work->messageWindow);
        func_021BB99C(work, work->messageWindow, 0, work->selectedMon);
        func_021BB714(work, (u32 *)work->messageWindow, 2);
        func_021BB7E8(work, (u32 *)work->messageWindow, 0x12);
        func_021BB98C(work, work->messageWindow);
        break;
    default:
        buf[0] = 0;
        buf[1] = 6;
        buf[2] = 0x10;
        break;
    }
    func_021BBAF8(work, work->contextMenu, buf);
}



void func_021B83D8(PokelistWork *work)
{
    switch (work->inputStage) {
    case 0:
        work->inputStage = 1;
        work->command = 4;
        break;
    case 1:
        func_021B8A8C(work);
        break;
    case 2:
        if (work->phase == 3) {
            func_021B86D8(work);
        } else if (work->phase == 4) {
            func_021B8758(work);
        } else {
            func_021B8508(work);
        }
        break;
    }
}


#undef W

#undef W




/*
 * The extent's last two bytes are alignment padding (00 00), not a follower.
 */
void func_021B8418(PokelistWork *work)
{
    work->selectedSlot = work->arg->selectedIndex;
    work->inputStage = 0;
    work->menuChoice = 0x17;
    if (func_021B9A84(work) == 1) {
        func_021BBE5C(work->commandButtons[0], 0);
        func_021BBE5C(work->commandButtons[1], 0);
    }
    if (work->touchMode == 0) {
        if (work->selectedSlot <= 5) {
            func_021B8F68(work, work->selectedSlot);
            func_021BAFA0(work, work->plates[work->selectedSlot], 1);
        } else {
            func_021BBE5C(work->commandButtons[(u8)(work->selectedSlot - 6)], 1);
        }
    } else {
        func_0204B3DC(work->cursorActor, 0);
        if (work->selectedSlot <= 5) {
            if (work->phase == 3) {
                func_021BAFA0(work, work->plates[work->selectedSlot], 1);
            } else {
                func_021BAFA0(work, work->plates[work->selectedSlot], 0);
            }
        } else {
            func_021BBE5C(work->commandButtons[(u8)(work->selectedSlot - 6)], 0);
        }
    }
    func_0204B3DC(work->switchButtonActor, work->switchButtonEnabled);
    if (func_021B9A84(work) == 1 || func_021B9AB4(work) == 0) {
        func_0204B3DC(work->backButtonActor, 0);
    } else {
        func_0204B3DC(work->backButtonActor, 1);
    }
}


#undef W

#undef W




/*
 * Case bodies are laid out 3, 0, 1, 2: case 3 is written first.
 */
void func_021B8508(PokelistWork *work)
{
    u8 i;
    u8 k;
    int n;

    func_021BB7A4(work, (u32 *)work->messageWindow);
    if (func_021B9A84(work) == 1) {
        func_02041300(0, 0, 0, 0x15, 0x20, 3, 0x10);
        for (i = 0; i < 6; i++) {
            work->arg->slotOrder[i] = 0;
        }
        for (k = 0; k < 6; k++) {
            n = func_021BB43C(work->plates[k]);
            if (n <= 5) {
                work->arg->slotOrder[n] = k + 1;
            }
        }
    }
    switch (work->command) {
    case 3:
        func_0204B3DC(work->cursorActor, 0);
        work->selectedMon = (int)func_0201AB28(work->arg->party, work->selectedSlot);
        work->arg->selectedIndex = work->selectedSlot;
        func_020061E4(0x54c);
        func_021B7CC4(work);
        return;
    case 0:
        if (func_021B9A84(work) == 1) {
            func_021B892C(work);
            return;
        }
        work->phase = 0x13;
        work->arg->selectedIndex = 6;
        work->arg->exitCode = 0;
        func_020061E4(0x54c);
        return;
    case 1:
        if (work->selectedSlot <= 5) {
            func_021BAFA0(work, work->plates[work->selectedSlot], 0);
            func_0204B3DC(work->cursorActor, 0);
        }
        if (func_021B9A84(work) == 1) {
            func_021BBE5C(work->commandButtons[0], 0);
            func_021BBE68(work->commandButtons[1], 1);
            work->phase = 0xc;
            work->selectedSlot = 7;
        } else {
            work->phase = 0x13;
            work->pressedButtonActor = work->backButtonActor;
            func_0204B878(work->pressedButtonActor, 9);
        }
        work->arg->selectedIndex = 7;
        work->arg->exitCode = 0;
        func_020061E4(0x551);
        return;
    case 2:
        if (work->selectedSlot <= 5) {
            func_021BAFA0(work, work->plates[work->selectedSlot], 0);
            func_0204B3DC(work->cursorActor, 0);
        }
        work->phase = 0x13;
        work->arg->selectedIndex = 8;
        work->arg->exitCode = 0;
        func_020061E4(0x556);
        work->pressedButtonActor = work->switchButtonActor;
        func_0204B878(work->pressedButtonActor, 8);
        return;
    }
}


#undef W

#undef W




void func_021B86D8(PokelistWork *work)
{
    func_021BB7A4(work, (u32 *)work->messageWindow);
    if (work->command == 3 && work->selectedSlot == work->swapSourceSlot) {
        work->command = 1;
    }
    if (work->command != 1) {
        if (work->command == 3) {
            func_021B9968(work);
        }
    } else {
        work->selectedMon = 0;
        work->phase = 2;
        func_021B8F68(work, work->selectedSlot);
        func_021BAFA0(work, work->plates[work->swapSourceSlot], 0);
        func_0204B3DC(work->swapMarkerActor, 0);
        work->swapSourceSlot = 9;
        work->arg->selectedIndex = work->selectedSlot;
        func_021B7B98(work);
        func_020061E4(0x551);
    }
}


#undef W

#undef W




void func_021B8758(PokelistWork *work)
{
    u32 a, b;
    void *o;
    u32 c, d, e;

    func_021BB7A4(work, (u32 *)work->messageWindow);
    if (work->command == 3) {
        work->selectedMon = (u32)func_0201AB28(work->arg->party, work->selectedSlot);
        a = func_02017E1C((void *)work->selectedMon, 0xa0, 0);
        b = func_02017E1C((void *)work->selectedMon, 0xa1, 0);
        if (work->selectedSlot == work->healSourceSlot || a == 0 || b == a) {
            func_021B9788(work, 0x64, 1, func_021B9E20);
            func_021B8F68(work, work->selectedSlot);
            func_021BAFA0(work, work->plates[work->healSourceSlot], 0);
            func_021BAFA0(work, work->plates[work->selectedSlot], 0);
            func_0204B3DC(work->swapMarkerActor, 0);
            work->arg->selectedIndex = work->selectedSlot;
            return;
        }
        func_021BB2C0(work, work->plates[work->selectedSlot]);
        work->selectedMon = (u32)func_0201AB28(work->arg->party, work->selectedSlot);
        work->phase = 10;
        work->cursorState = func_021BB464(work, work->plates[work->selectedSlot]);
        work->phaseCallback = (PokelistFn)func_021BA288;
        func_021B8F68(work, work->selectedSlot);
        func_021BAFA0(work, work->plates[work->healSourceSlot], 0);
        func_0204B3DC(work->swapMarkerActor, 0);
        o = func_0201AB28(work->arg->party, work->healSourceSlot);
        c = func_02017E1C(o, 0xa1, 0);
        d = func_02017E1C(o, 0xa0, 0);
        e = c / 5;
        if (a + e > b) {
            func_02017E40(o, 0xa0, d - (b - a));
        } else {
            func_02017E40(o, 0xa0, d - e);
        }
        work->arg->selectedIndex = work->selectedSlot;
        work->selectedSlot = work->healSourceSlot;
        func_021BB2C0(work, work->plates[work->selectedSlot]);
        func_020061E4(0x56f);
        return;
    }
    work->selectedMon = 0;
    work->phase = 2;
    func_021B8F68(work, work->selectedSlot);
    func_021BAFA0(work, work->plates[work->healSourceSlot], 0);
    func_0204B3DC(work->swapMarkerActor, 0);
    work->healSourceSlot = 9;
    work->arg->selectedIndex = work->selectedSlot;
    func_021B7B98(work);
    func_020061E4(0x551);
}


#undef W

#undef W




/*
 * The six-byte buffer is a block-scope initialised array
 * (an-initialised-local-array-takes-its-address-before-the-stores.md):
 * six assignments sink `add r7, sp, #4` below the stores.
 */
void func_021B892C(PokelistWork *work)
{
    PokelistRegulation *rule;
    u8 i;
    int n;
    int r;

    rule = work->arg->regulation;
    if (work->selectedSlot != 6) {
        if (work->selectedSlot <= 5) {
            func_021BAFA0(work, work->plates[work->selectedSlot], 0);
            func_0204B3DC(work->cursorActor, 0);
        }
        work->selectedSlot = 6;
    }
    work->arg->selectedIndex = 6;
    {
        u8 buf[6] = {0, 0, 0, 0, 0, 0};
        for (i = 0; i < 6; i++) {
            n = func_021BB43C(work->plates[i]);
            if (n <= 5) {
                buf[n] = i + 1;
            }
        }
        r = POKE_REGULATION_CheckSelection((u32)rule, (u32)work->arg->party, (u32)buf);
    }
    if (rule->minPartySize > work->selectedCount) {
        func_021B9788(work, rule->minPartySize + 0x56, 1, func_021B9E20);
        func_020061E4(0x557);
        return;
    }
    if (rule->maxPartySize < work->selectedCount) {
        func_021B9788(work, rule->maxPartySize + 0x5c, 1, func_021B9E20);
        func_020061E4(0x557);
        return;
    }
    if (r == 1) {
        func_021BB97C(work, work->messageWindow);
        func_021BB9EC(work, work->messageWindow, 0, rule->levelTotal, 3);
        func_021B9788(work, 0x92, 1, func_021B9E20);
        func_020061E4(0x557);
        func_021BB98C(work, work->messageWindow);
        return;
    }
    if (r == 7) {
        func_021B9788(work, 0x94, 1, func_021B9E20);
        func_020061E4(0x557);
        return;
    }
    func_021BBE5C(work->commandButtons[1], 0);
    func_021BBE68(work->commandButtons[0], 1);
    work->phase = 0xc;
    work->arg->selectedIndex = 6;
    work->arg->exitCode = 0;
    work->selectionConfirmed = 1;
    func_020061E4(0x54c);
}


void func_021B8A8C(PokelistWork *work) { func_021B8AC4(work); if(work->command==4) func_021B8DB4(work); if(work->command!=4) work->inputStage=2; if(work->arg->closeRequested==1) { work->inputStage=2; work->command=1; } }


#undef W

#undef W




/*
 * The two byte tables resolve as sole-ref only without an overlay token
 * (with `ov091` the hint is reported contested).  The spilled locals sit
 * up @0, done @4, old @8, trg @0xc: declared trg, old, done, up.
 */
void func_021B8AC4(PokelistWork *work)
{
    u32 trg;
    int old;
    int done;
    u32 up;
    u32 rep;
    int dir;
    int max;
    u8 cnt;
    int n;

    trg = func_020362DC();
    rep = func_0203633C();
    if (work->touchMode == 1 && func_0204B3F4(work->cursorActor) == 0) {
        if (trg != 0 && (trg & 0x402) == 0) {
            if (work->selectedSlot <= 5) {
                func_021B8F68(work, work->selectedSlot);
                func_021BAFA0(work, work->plates[work->selectedSlot], 1);
            } else {
                func_021BBE5C(work->commandButtons[(u8)(work->selectedSlot - 6)], 1);
                func_0204B3DC(work->cursorActor, 0);
            }
            func_020061E4(0x548);
            work->touchMode = 0;
        }
    } else {
        dir = 0;
        if (trg != 0) {
            work->touchMode = 0;
        }
        up = rep & 0x40;
        if (up) {
            dir = -2;
        } else if (rep & 0x80) {
            dir = 2;
        } else if (rep & 0x20) {
            dir = -1;
        } else if (rep & 0x10) {
            dir = 1;
        } else if (trg & 1) {
            if (work->selectedSlot == 6) {
                work->command = 0;
            } else if (work->selectedSlot == 7) {
                work->command = 1;
            } else if (work->allowDisabledSelect == 0 && func_021BB468(work, work->plates[work->selectedSlot]) == 1) {
                func_020061E4(0x557);
            } else {
                work->command = 3;
            }
        }
        if (dir != 0) {
            old = work->selectedSlot;
            done = 0;
            if (func_021B9A84(work) == 1) {
                if (func_021B9AA0(work) == 1) {
                    max = 7;
                } else {
                    max = 6;
                }
            } else {
                max = 5;
            }
            if ((u32)(work->selectedSlot - 6) <= 1 && (rep & 0xc0)) {
                cnt = func_0201AA18(work->arg->party);
                if (up) {
                    if (work->selectedSlot == 7 || func_021B9AA0(work) == 0) {
                        work->selectedSlot = d_021BEAB0[cnt - 1];
                    } else {
                        work->selectedSlot = d_021BEAAA[cnt - 1];
                    }
                } else {
                    if (work->selectedSlot == 7 || func_021B9AA0(work) == 0) {
                        if (cnt > 1) {
                            work->selectedSlot = 1;
                        } else {
                            work->selectedSlot = 0;
                        }
                    } else {
                        work->selectedSlot = 0;
                    }
                }
            } else {
                do {
                    n = work->selectedSlot + dir;
                    if (n > max) {
                        if (max == 6 && dir > 1 && old != 6) {
                            work->selectedSlot = max;
                        } else {
                            work->selectedSlot = n - (max + 1);
                        }
                    } else if (n < 0) {
                        if (max == 6 && dir < 1) {
                            work->selectedSlot = max;
                        } else {
                            work->selectedSlot = dir + (work->selectedSlot + (max + 1));
                        }
                    } else {
                        work->selectedSlot += dir;
                    }
                    if (work->selectedSlot > 5 || func_021BB3C4(work, work->plates[work->selectedSlot]) == 1) {
                        done = 1;
                    }
                } while (done == 0);
            }
            if (old != work->selectedSlot) {
                if (work->selectedSlot <= 5) {
                    func_021B8F68(work, work->selectedSlot);
                    func_021BAFA0(work, work->plates[work->selectedSlot], 1);
                } else {
                    func_021BBE5C(work->commandButtons[(u8)(work->selectedSlot - 6)], 1);
                    func_0204B3DC(work->cursorActor, 0);
                }
                if (old <= 5) {
                    func_021BAFA0(work, work->plates[old], 0);
                } else {
                    func_021BBE5C(work->commandButtons[(u8)(old - 6)], 0);
                }
                work->fadeStep = 0xc;
            }
            func_020061E4(0x548);
        }
    }
    if (trg & 2) {
        if (func_021B9A84(work) == 0 || func_021B9AA0(work) == 1) {
            if (func_021B9AB4(work) == 1) {
                work->command = 1;
                work->pressedButtonActor = work->backButtonActor;
                func_0204B878(work->pressedButtonActor, 9);
                work->touchMode = 0;
            }
        }
    } else if ((trg & 0x400) && work->switchButtonEnabled == 1) {
        work->command = 2;
        work->pressedButtonActor = work->switchButtonActor;
        func_0204B878(work->pressedButtonActor, 8);
        work->touchMode = 0;
    }
}

void func_021B8DB4(PokelistWork *work)
{
    PokelistRect rects[7];
    PokelistButtonRects buttonRects;
    u8 plateOfRect[6];
    u8 i;
    u8 count;
    int hit;
    int oldSlot;
    int buttonHit;

    count = 0;
    for (i = 0; i < 6; i++) {
        if (func_021BB3C4(work, work->plates[i]) == 1) {
            plateOfRect[count] = i;
            func_021BB3FC(work, work->plates[i], &rects[count]);
            count++;
        }
    }
    rects[count].top = 0xff;
    hit = func_02035C08(rects);
    if (hit != -1) {
        if (work->allowDisabledSelect == 0 && hit <= 5 && func_021BB468(work, work->plates[hit]) == 1) {
            func_020061E4(0x557);
        } else {
            work->command = 3;
            oldSlot = work->selectedSlot;
            work->selectedSlot = plateOfRect[hit];
            if (oldSlot <= 5) {
                func_021BAFA0(work, work->plates[oldSlot], 0);
            } else {
                func_021BBE5C(work->commandButtons[(u8)(oldSlot - 6)], 0);
            }
            if (work->selectedSlot <= 5) {
                func_021BAFA0(work, work->plates[work->selectedSlot], 1);
            } else {
                func_021BBE5C(work->commandButtons[(u8)(work->selectedSlot - 6)], 1);
                func_0204B3DC(work->cursorActor, 0);
            }
            work->fadeStep = 0xc;
        }
        work->touchMode = 1;
    }
    if (hit == -1) {
        buttonRects = d_021BEC2C;
        if (func_021B9A84(work) == 1) {
            if (func_021B9AA0(work) == 1) {
                buttonRects.r[1].top = 0xa8;
                buttonRects.r[1].bottom = 0xc0;
                buttonRects.r[1].left = 0xb0;
                buttonRects.r[1].right = 0xff;
                buttonRects.r[0].top = 0xa8;
                buttonRects.r[0].bottom = 0xc0;
                buttonRects.r[0].left = 0x60;
                buttonRects.r[0].right = 0xb0;
            } else {
                buttonRects.r[0].top = 0xa8;
                buttonRects.r[0].bottom = 0xc0;
                buttonRects.r[0].left = 0xb0;
                buttonRects.r[0].right = 0xff;
            }
        } else {
            if (func_021B9AB4(work) == 1) {
                buttonRects.r[1].top = 0xa8;
                buttonRects.r[1].bottom = 0xc0;
                buttonRects.r[1].left = 0xe0;
                buttonRects.r[1].right = 0xf8;
            }
            if (work->switchButtonEnabled == 1) {
                buttonRects.r[2].top = 0xa8;
                buttonRects.r[2].bottom = 0xc0;
                buttonRects.r[2].left = 0xc8;
                buttonRects.r[2].right = 0xe0;
            }
        }
        buttonHit = func_02035C08(&buttonRects);
        if (buttonHit != -1) {
            work->command = buttonHit;
            work->touchMode = 1;
        }
    }
}

void func_021B8F68(PokelistWork *work, int plateIndex)
{
    PokelistPos pos;

    func_021BB3D4(work, work->plates[plateIndex], &pos);
    func_0204B404(work->cursorActor, &pos, 0);
    func_0204B3DC(work->cursorActor, 1);
    func_0204B84C(work->cursorActor, 3);
    if (plateIndex == 0) {
        func_0204B878(work->cursorActor, 0);
    } else {
        func_0204B878(work->cursorActor, 1);
    }
}

void func_021B8FC4(PokelistWork *work, int plateIndex)
{
    PokelistPos pos;

    func_021BB3D4(work, work->plates[plateIndex], &pos);
    func_0204B404(work->swapMarkerActor, &pos, 0);
    func_0204B3DC(work->swapMarkerActor, 1);
    func_0204B84C(work->swapMarkerActor, 2);
    if (plateIndex == 0) {
        func_0204B878(work->swapMarkerActor, 2);
    } else {
        func_0204B878(work->swapMarkerActor, 3);
    }
}

void func_021B9020(PokelistWork *work)
{
    int choice;

    switch (work->inputStage) {
    case 0:
        func_021B907C(work);
        work->inputStage = 1;
        break;
    case 1:
        func_021BBBD8(work, work->contextMenu);
        choice = func_021BBBE4(work, work->contextMenu);
        if (choice != 0x17) {
            work->menuChoice = choice;
            work->inputStage = 2;
        }
        if (work->arg->closeRequested == 1) {
            work->inputStage = 2;
        }
        break;
    case 2:
        func_021B90F8(work);
        func_021B916C(work);
        break;
    }
}

static inline void G2_SetBlendBrightness(int plane, int brightness)
{
    func_0207D658((u32)&reg_G2_BLDCNT, plane, brightness);
}

static inline void G2_SetWnd0Position(int x1, int y1, int x2, int y2)
{
    reg_G2_WIN0H = (u16)(((x1 << 8) & 0xff00) | ((x2 << 0) & 0x00ff));
    reg_G2_WIN0V = (u16)(((y1 << 8) & 0xff00) | ((y2 << 0) & 0x00ff));
}

static inline void G2_SetWnd0InsidePlane(int wnd, BOOL effect)
{
    u32 tmp;
    tmp = ((reg_G2_WININ & ~0x3f) | ((u32)wnd << 0));
    if (effect) {
        tmp |= (0x20 << 0);
    }
    reg_G2_WININ = (u16)tmp;
}

static inline void G2_SetWndOutsidePlane(int wnd, BOOL effect)
{
    u32 tmp;
    tmp = ((reg_G2_WINOUT & ~0x3f) | ((u32)wnd << 0));
    if (effect) {
        tmp |= (0x20 << 0);
    }
    reg_G2_WINOUT = (u16)tmp;
}

/*
 * volatile: WININ 0x04000048 and WINOUT 0x0400004A read-modify-written by the SDK inlines G2_SetWnd0InsidePlane/G2_SetWndOutsidePlane; WIN0H/WIN0V/BLDCNT hardware registers
 */
void func_021B907C(PokelistWork *work)
{
    work->phase = 6;
    work->inputStage = 0;
    G2_SetBlendBrightness(0x1e, 8);
    G2_SetWnd0Position(0xe0, 0xa8, 0xf8, 0xc0);
    G2_SetWnd0InsidePlane(0x1f, 0);
    G2_SetWndOutsidePlane(0x1f, 1);
    work->fadeMode = 1;
    func_0204B3DC(work->switchButtonActor, 0);
    func_0204B3DC(work->backButtonActor, 0);
    func_02041B6C(0);
    func_020355D8(work->touchMode);
}

void func_021B90F8(PokelistWork *work)
{
    func_021BBBA0(work, work->contextMenu);
    func_021BB7A4(work, (u32 *)work->messageWindow);
    if (func_021B9A84(work) == 1 || func_021B9AB4(work) == 0) {
        func_0204B3DC(work->backButtonActor, 0);
    } else {
        func_0204B3DC(work->backButtonActor, 1);
    }
    if (work->menuChoice != 4 && work->menuChoice != 5) {
        func_0207D63C(0x04000050, 0x14, 8, 0x10, 0xa);
        work->fadeMode = 0;
    }
    func_02041570(0, 0);
    work->touchMode = func_020355C4();
}

void func_021B916C(PokelistWork *work)
{
    struct {
        u32 maxHp;
        PokelistMenuItems itemsForChoice5;
        PokelistMenuItems itemsForChoice4;
    } local;
    u32 monValue;
    int result, level;
    u32 lastSelected;
    u8 i;
    PokelistRegulation *rule;

    if (work->arg->closeRequested == 1) {
        work->phase = 19;
        return;
    }
    switch (work->menuChoice) {
    case 6:
        func_021B8F68(work, work->selectedSlot);
        work->selectedMon = 0;
        work->phase = 2;
        func_021B7B98(work);
        return;
    case 3:
        func_021B8F68(work, work->selectedSlot);
        func_021B8FC4(work, work->selectedSlot);
        work->swapSourceSlot = work->selectedSlot;
        work->phase = 3;
        work->selectedMon = 0;
        work->switchButtonEnabled = 0;
        func_021BB714(work, (u32 *)work->messageWindow, 0);
        func_021BB7E8(work, (u32 *)work->messageWindow, 11);
        func_021B8418(work);
        return;
    case 4:
        local.itemsForChoice4 = d_021BEC0C;
        func_021B907C(work);
        func_021BB714(work, (u32 *)work->messageWindow, 2);
        func_021BB7E8(work, (u32 *)work->messageWindow, 19);
        func_021BBAF8(work, work->contextMenu, local.itemsForChoice4.v);
        func_020409B4(0);
        return;
    case 5:
        local.itemsForChoice5 = d_021BEC1C;
        func_021B907C(work);
        func_021BB714(work, (u32 *)work->messageWindow, 2);
        func_021BB7E8(work, (u32 *)work->messageWindow, 19);
        func_021BBAF8(work, work->contextMenu, local.itemsForChoice5.v);
        func_020409B4(0);
        return;
    case 0:
        work->phase = 19;
        work->arg->selectedIndex = work->selectedSlot;
        work->arg->exitCode = 1;
        return;
    case 20:
        rule = work->arg->regulation;
        lastSelected = 0;
        result = func_021BB4A0(work, work->plates[work->selectedSlot]);
        if (result == 0) {
            func_021BB440(work, work->plates[work->selectedSlot], work->selectedCount);
            work->selectedCount = work->selectedCount + 1;
            func_021B7B98(work);
            if (work->selectedCount == rule->maxPartySize) {
                lastSelected = 1;
            }
            work->phase = 2;
        } else if (result == 2) {
            func_021B9788(work, 0x90, 1, func_021B9E20);
            func_020061E4(0x557);
        } else if (result == 3) {
            func_021B9788(work, 0x91, 1, func_021B9E20);
            func_020061E4(0x557);
        } else if (result == 4) {
            func_021B9788(work, rule->maxPartySize + 0x5c, 1, func_021B9E20);
            func_020061E4(0x557);
        }
        work->selectedMon = 0;
        if (lastSelected == 1) {
            func_021BAFA0(work, work->plates[work->selectedSlot], 0);
            work->selectedSlot = 6;
            if (work->touchMode == 0) {
                func_021BBE5C(work->commandButtons[(u8)(work->selectedSlot - 6)], 1);
                func_0204B3DC(work->cursorActor, 0);
                return;
            }
        } else if (work->touchMode == 0) {
            func_021B8F68(work, work->selectedSlot);
        }
        return;
    case 21:
        level = func_021BB43C(work->plates[work->selectedSlot]);
        for (i = 0; i < 6; i++) {
            result = func_021BB43C(work->plates[i]);
            if (result <= 5 && result > level) {
                func_021BB440(work, work->plates[i], result - 1);
            }
        }
        func_021BB440(work, work->plates[work->selectedSlot], 6);
        work->selectedCount = work->selectedCount - 1;
        if (work->touchMode == 0) {
            func_021B8F68(work, work->selectedSlot);
        }
        work->selectedMon = 0;
        work->phase = 2;
        func_021B7B98(work);
        return;
    case 10:
        monValue = func_02017E1C((void *)work->selectedMon, 6, 0);
        func_021BC24C(work, (void *)work->selectedMon, 0);
        func_021BC288(work, (void *)work->selectedMon, 0);
        if (monValue == 0) {
            func_021BB97C(work, work->messageWindow);
            func_021BB99C(work, work->messageWindow, 0, work->selectedMon);
            func_021B9788(work, 0x3d, 1, func_021B9E20);
            func_021BB98C(work, work->messageWindow);
            return;
        }
        if (func_021BA65C(work, monValue) == 999) {
            func_021B9788(work, 0x3f, 1, func_021B9E20);
            return;
        }
        func_021BA624(work, (void *)work->selectedMon, 0);
        func_021BB2C0(work, work->plates[work->selectedSlot]);
        func_021BB97C(work, work->messageWindow);
        func_021BB99C(work, work->messageWindow, 0, work->selectedMon);
        func_021BB9AC(work, work->messageWindow, 1, (u16)monValue);
        if (func_021BDC5C(work, (void *)work->selectedMon) == 1) {
            func_021BDCA0(work, (void *)work->selectedMon);
            func_021B9788(work, 0x3e, 1, func_021BA4E4);
            work->evolveCheckKind = 2;
        } else {
            func_021B9788(work, 0x3e, 1, func_021B9E20);
        }
        func_021BB98C(work, work->messageWindow);
        return;
    case 11:
        work->phase = 19;
        work->arg->selectedIndex = work->selectedSlot;
        work->arg->exitCode = 0;
        return;
    case 9:
        work->phase = 19;
        work->arg->selectedIndex = work->selectedSlot;
        work->arg->exitCode = 3;
        return;
    case 12:
        work->phase = 19;
        work->arg->selectedIndex = work->selectedSlot;
        work->arg->exitCode = 7;
        return;
    case 13:
        func_021B9788(work, 0x17, 0, func_021BA394);
        return;
    case 7:
        work->phase = 19;
        work->arg->selectedIndex = work->selectedSlot;
        work->arg->exitCode = 0;
        return;
    case 16:
    case 17:
    case 18:
    case 19:
        if (work->arg->mode == 5) {
            if (func_021BDD78((void *)work->selectedMon, work->arg->itemId, (u16)(work->menuChoice - 16), work->heapId) == 1) {
                monValue = func_02017E1C((void *)work->selectedMon, work->menuChoice + 0x26, 0);
                func_020409B4(0);
                func_021BC350(work, monValue);
                func_021BE2B4((void *)work->selectedMon, work->arg->itemId, (u16)(work->menuChoice - 16), work->arg->itemUseParam, work->heapId);
                func_021BB2C0(work, work->plates[work->selectedSlot]);
                func_021BA670(work, work->arg->itemId);
                func_020061E4(0x56f);
            } else {
                func_021BC30C(work);
            }
            return;
        }
        result = func_021B99E4((void *)work->selectedMon, (u8)(work->menuChoice - 16));
        if ((u32)(result - 22) <= 1) {
            if (func_02013E04(work->arg->itemUseParam) == 0) {
                func_021B9788(work, 0x50, 1, func_021B9E20);
                return;
            }
            local.maxHp = func_02017E1C((void *)work->selectedMon, 0xa1, 0);
            monValue = func_02017E1C((void *)work->selectedMon, 0xa0, 0);
            if (monValue > local.maxHp / 5) {
                func_021B8F68(work, work->selectedSlot);
                func_021B8FC4(work, work->selectedSlot);
                work->healSourceSlot = work->selectedSlot;
                work->phase = 4;
                work->selectedMon = 0;
                work->switchButtonEnabled = 0;
                func_021BB714(work, (u32 *)work->messageWindow, 0);
                func_021BB7E8(work, (u32 *)work->messageWindow, 17);
                func_021B8418(work);
            } else {
                func_021B9788(work, 0x6b, 1, func_021B9E20);
            }
            return;
        }
        switch (func_0215EA14(result - 11, work->arg->fieldMoveParam)) {
        case 0:
            work->phase = 19;
            work->arg->selectedIndex = work->selectedSlot;
            work->arg->exitCode = result;
            return;
        case 1:
            func_021B9788(work, 0x50, 1, func_021B9E20);
            return;
        case 2:
            func_021B9788(work, 0x38, 1, func_021B9E20);
            return;
        case 3:
            func_021B9788(work, 0x9f, 1, func_021B9E20);
            return;
        case 4:
            func_021B9788(work, 0x4f, 1, func_021B9E20);
            return;
        }
        return;
    default:
        func_021B8F68(work, work->selectedSlot);
        work->selectedMon = 0;
        work->phase = 2;
        func_021B7B98(work);
        return;
    }
}

void func_021B9750(PokelistWork *work)
{
    if (func_021BB8FC(work, work->messageWindow) == 1) {
        if (func_020362DC() & 1) {
            work->touchMode = 0;
        }
        if (func_02035C60() == 1) {
            work->touchMode = 1;
        }
        work->messageDoneCallback(work);
    }
}

void func_021B9788(PokelistWork *work, int messageId, int waitForKey, PokelistFn onDone)
{
    work->phase = 7;
    work->messageWaitKey = waitForKey;
    work->messageDoneCallback = onDone;
    func_021BB714(work, (u32 *)work->messageWindow, 3);
    func_021BB860(work, (u32 *)work->messageWindow, messageId, waitForKey);
    func_0204B3DC(work->backButtonActor, 0);
    func_0204B3DC(work->switchButtonActor, 0);
}

void func_021B97D4(PokelistWork *work)
{
    int choice;

    func_021BBBD8(work, work->contextMenu);
    choice = func_021BBBE4(work, work->contextMenu);
    if (choice != 0x17) {
        work->menuChoiceCallback(work, choice);
        func_021BBBA0(work, work->contextMenu);
    }
}

/*
 * func_021B9804 is an unlabelled tail-call stub inside the extent.
 */
void func_021B9804(PokelistWork *work, PokelistMenuFn onChoice)
{
    work->phase = 9;
    work->menuChoiceCallback = onChoice;
    func_021BBB40(work, work->contextMenu);
}

void func_021B981C(PokelistWork *work)
{
    switch (work->inputStage) {
    case 3:
        func_021BB1A0(work, work->plates[work->selectedSlot], work->swapAnimStep);
        func_021BB1A0(work, work->plates[work->swapSourceSlot], work->swapAnimStep);
        work->swapAnimStep++;
        func_021BB0C4(work, work->plates[work->selectedSlot], work->swapAnimStep);
        func_021BB0C4(work, work->plates[work->swapSourceSlot], work->swapAnimStep);
        if (work->swapAnimStep >= 16) {
            func_0201AB8C(work->arg->party, work->selectedSlot, work->swapSourceSlot, work->heapId);
            func_021BB200(work, work->plates[work->selectedSlot], func_0201AB28(work->arg->party, work->selectedSlot), work->swapAnimStep);
            func_021BB200(work, work->plates[work->swapSourceSlot], func_0201AB28(work->arg->party, work->swapSourceSlot), work->swapAnimStep);
            work->inputStage = 4;
            func_020061E4(0x642);
        }
        break;
    case 4:
        func_021BB1A0(work, work->plates[work->selectedSlot], work->swapAnimStep);
        func_021BB1A0(work, work->plates[work->swapSourceSlot], work->swapAnimStep);
        work->swapAnimStep--;
        func_021BB0C4(work, work->plates[work->selectedSlot], work->swapAnimStep);
        func_021BB0C4(work, work->plates[work->swapSourceSlot], work->swapAnimStep);
        if (work->swapAnimStep == 0)
            func_021B999C(work);
        break;
    }
}

void func_021B9968(PokelistWork *work)
{
    work->phase = 5;
    work->inputStage = 3;
    work->swapAnimStep = 0;
    func_020061E4(0x641);
    func_0204B3DC(work->cursorActor, 0);
    func_0204B3DC(work->swapMarkerActor, 0);
}

void func_021B999C(PokelistWork *work)
{
    work->selectedMon = 0;
    work->phase = 2;
    func_021B8F68(work, work->selectedSlot);
    func_021BAFA0(work, work->plates[work->swapSourceSlot], 0);
    func_0204B3DC(work->swapMarkerActor, 0);
    work->swapSourceSlot = 9;
    work->arg->selectedIndex = work->selectedSlot;
    func_021B7B98(work);
}

int func_021B99E4(void *mon, int moveSlot)
{
    switch (func_02017E1C(mon, moveSlot + 0x36, 0)) {
    case 0xf:
        return 0xb;
    case 0x13:
        return 0xf;
    case 0x39:
        return 0xc;
    case 0x46:
        return 0xe;
    case 0x7f:
        return 0xd;
    case 0x94:
        return 0x10;
    case 0x64:
        return 0x11;
    case 0x5b:
        return 0x12;
    case 0xe6:
        return 0x13;
    case 0x1c0:
        return 0x14;
    case 0x123:
        return 0x15;
    case 0xd0:
        return 0x16;
    case 0x87:
        return 0x17;
    }
    return 0;
}

int func_021B9A84(PokelistWork *work)
{
    u32 mode = work->arg->mode;
    if (mode == 1 || mode == 22 || mode == 23)
        return 1;
    return 0;
}

int func_021B9AA0(PokelistWork *work)
{
    if (work->arg->mode != 1)
        return 1;
    return 0;
}

int func_021B9AB4(PokelistWork *work)
{
    return work->arg->mode != 21;
}

int func_021B9AC8(PokelistWork *work, void *mon, u8 partySlot)
{
    int hasEmptySlot = 0;
    u8 i;
    u32 moveA, moveB, moveC;
    u32 moveId;
    if (work->restoreMode18 == 1) {
        moveA = work->arg->moveId;
        if (moveA == 0xfffe) {
            moveA = 0x152;
            moveB = moveA - 0x1f;
            moveC = moveA - 0x1e;
        } else if (moveA == 0xfffd) {
            moveA = 0x280;
            moveA = moveA - 0x78;
            moveB = 0x280;
            moveB = moveB - 0x79;
            moveC = 0x280 - 0x7a;
        } else {
            moveB = moveA;
            moveC = moveA;
        }
        for (i = 0; i < 4; i++) {
            moveId = func_02017E1C(mon, i + 0x36, 0);
            if (moveId == moveA || moveId == moveB || moveId == moveC)
                return 3;
            if (moveId == 0)
                hasEmptySlot = 1;
        }
        if ((work->arg->learnableFlags & (1 << partySlot)) != 0) {
            if (hasEmptySlot == 1)
                return 0;
            return 1;
        } else
            return 2;
    } else {
        for (i = 0; i < 4; i++) {
            moveId = func_02017E1C(mon, i + 0x36, 0);
            if (moveId == work->arg->moveId)
                return 3;
            if (moveId == 0)
                hasEmptySlot = 1;
        }
        if (work->arg->itemId != 0) {
            u32 machineIndex = func_0202130C(work->arg->itemId);
            if (machineIndex != 0xff && func_020188AC(mon, machineIndex) == 1) {
                int result = 0;
                if (hasEmptySlot != 1)
                    result = 1;
                return result;
            } else
                return 2;
        } else {
            int result = 0;
            if (hasEmptySlot != 1)
                result = 1;
            return result;
        }
    }
}

u32 func_021B9BF4(PokelistWork *work, void *mon, u32 param)
{
    PokelistArg *arg = work->arg;
    return func_0201B2B0(arg->party, mon, 3, param, arg->season, 0, work->heapId);
}

void func_021B9C1C(PokelistWork *work, struct Descriptor *window, u32 messageId, int x, s16 y, u16 color)
{
    void *text;
    text = func_02045EC0(work->msgBank, messageId);
    func_0201C724(work->printSys, func_02045770(window), (s16)x, (s16)y, text, work->fontMain, color);
    func_02045808(text);
}

void func_021B9C64(PokelistWork *work, struct Descriptor *window, u32 messageId, u32 x, s16 y, u16 color)
{
    void *text = func_02045EC0(work->msgBank, messageId);
    func_0201C724(work->printSys, func_02045770(window), (s16)x, (s16)y, text, work->fontSub, color);
    func_02045808(text);
}

void func_021B9CB0(PokelistWork *work, struct Descriptor *window, u32 messageId, u32 x, s16 y, u16 color)
{
    void *text = func_02045EC0(work->msgBank, messageId);
    func_0201C7D0(func_02045770(window), x, y, text, work->fontSub, color);
    func_02045808(text);
}

void func_021B9CF4(PokelistWork *work, struct Descriptor *window, void *wordSet, u32 messageId, s16 x, s16 y, u16 color)
{
    void *expanded = func_020457B0(16, work->heapId);
    void *text = func_02045EC0(work->msgBank, messageId);
    func_0201F250(wordSet, expanded, text);
    func_0201C724(work->printSys, func_02045770(window), x, y, expanded, work->fontMain, color);
    func_02045808(text);
    func_02045808(expanded);
}

void func_021B9D58(PokelistWork *work, struct Descriptor *window, void *wordSet, u32 messageId, s16 x, s16 y, u16 color)
{
    void *expanded = func_020457B0(16, work->heapId);
    void *text = func_02045EC0(work->msgBank, messageId);
    func_0201F250(wordSet, expanded, text);
    func_0201C724(work->printSys, func_02045770(window), x, y, expanded, work->fontSub, color);
    func_02045808(text);
    func_02045808(expanded);
}

void func_021B9DC0(PokelistWork *work, struct Descriptor *window, void *wordSet, u32 messageId, s16 x, s16 y, u16 color)
{
    void *expanded = func_020457B0(16, work->heapId);
    void *text = func_02045EC0(work->msgBank, messageId);
    func_0201F250(wordSet, expanded, text);
    func_0201C7D0(func_02045770(window), x, y, expanded, work->fontSub, color);
    func_02045808(text);
    func_02045808(expanded);
}

void func_021B9E20(PokelistWork *work)
{
    func_021BB7A4(work, (u32 *)work->messageWindow);
    work->phase = 2;
    func_021B7B98(work);
}

void func_021B9E3C(PokelistWork *work)
{
    work->phase = 19;
}

void func_021B9E44(PokelistWork *work)
{
    if (func_021BA65C(work, work->arg->itemId)) {
        func_021BB7A4(work, (u32 *)work->messageWindow);
        work->phase = 2;
        func_021B7B98(work);
        return;
    }
    func_021BB7A4(work, (u32 *)work->messageWindow);
    func_021BB97C(work, work->messageWindow);
    func_021BB9AC(work, work->messageWindow, 0, work->arg->itemId);
    func_021B9788(work, 0xb3, 1, func_021B9E3C);
    func_021BB98C(work, work->messageWindow);
}

void func_021B9EB0(PokelistWork *work)
{
    func_021B9804(work, func_021B9EC0);
}

void func_021B9EC0(PokelistWork *work, int choice)
{
    func_021BB7A4(work, (u32 *)work->messageWindow);
    if (choice == 14) {
        PokelistArg *arg = work->arg;
        if (arg->mode == 5 || arg->mode == 8) {
            arg->exitCode = 5;
        } else {
            arg->exitCode = 4;
        }
        func_021B9788(work, 0x27, 1, func_021B9E3C);
        return;
    }
    func_021BB97C(work, work->messageWindow);
    func_021BB9CC(work, work->messageWindow, 1, work->arg->moveId);
    func_021B9788(work, 0x23, 0, func_021B9F34);
    func_021BB98C(work, work->messageWindow);
}

void func_021B9F34(PokelistWork *work)
{
    func_021B9804(work, func_021B9F44);
}

void func_021B9F44(PokelistWork *work, int choice)
{
    func_021BB7A4(work, (u32 *)work->messageWindow);
    if (choice == 14) {
        work->arg->exitCode = 10;
        func_021BB97C(work, work->messageWindow);
        func_021BB99C(work, work->messageWindow, 0, work->selectedMon);
        func_021BB9CC(work, work->messageWindow, 1, work->arg->moveId);
        if (work->arg->mode == 5 || work->arg->mode == 8) {
            func_021B9788(work, 0x26, 1, func_021BC6C0);
        } else {
            func_021B9788(work, 0x26, 1, func_021B9E3C);
        }
        func_021BB98C(work, work->messageWindow);
        return;
    }
    func_021BB97C(work, work->messageWindow);
    func_021BB99C(work, work->messageWindow, 0, work->selectedMon);
    func_021BB9CC(work, work->messageWindow, 1, work->arg->moveId);
    func_021B9788(work, 0x20, 0, func_021B9EB0);
    func_021BB98C(work, work->messageWindow);
}

void func_021BA004(PokelistWork *work)
{
    func_021BB7A4(work, (u32 *)work->messageWindow);
    func_021BB97C(work, work->messageWindow);
    func_021BB99C(work, work->messageWindow, 0, work->selectedMon);
    func_021BB9CC(work, work->messageWindow, 1, work->arg->moveId);
    if (work->arg->mode == 5 || work->arg->mode == 8) {
        func_021B9788(work, 0x29, 1, func_021BC6C0);
    } else {
        func_021B9788(work, 0x29, 1, func_021B9E3C);
        func_021BA60C(work, (void *)work->selectedMon);
        work->arg->exitCode = 10;
    }
    func_021BB98C(work, work->messageWindow);
    func_021BA5E0(work, (void *)work->selectedMon, work->arg->moveSlot);
}

void func_021BA098(PokelistWork *work)
{
    func_021B9804(work, func_021BA0A8);
}

void func_021BA0A8(PokelistWork *work, int choice)
{
    u32 heldItem;
    int evolveKindOne, evolveKindTwo;
    if (choice == 0xe) {
        heldItem = func_02017E1C((void *)work->selectedMon, 6, 0);
        if (func_021BA65C(work, heldItem) == 0x3e7) {
            if (work->arg->mode == 0xa) {
                work->arg->mode = 0;
                func_021BB7A4(work, (u32 *)work->messageWindow);
                func_021B9788(work, 0x3f, 1, func_021B9E20);
            } else {
                work->phase = 0x13;
                func_021BB7A4(work, (u32 *)work->messageWindow);
                func_021B9788(work, 0x3f, 1, func_021B9E3C);
            }
        } else if (func_0202136C(work->arg->itemId) == 1) {
            work->arg->selectedIndex = work->selectedSlot;
            work->phase = 0x13;
            work->arg->exitCode = 6;
        } else {
            func_021BB7A4(work, (u32 *)work->messageWindow);
            func_021BA624(work, (void *)work->selectedMon, work->arg->itemId);
            func_021BB2C0(work, work->plates[work->selectedSlot]);
            func_021BC24C(work, (void *)work->selectedMon, (u16)(work->arg->itemId));
            func_021BC288(work, (void *)work->selectedMon, work->arg->itemId);
            evolveKindOne = func_021BDBF8(work, (void *)work->selectedMon);
            evolveKindTwo = func_021BDC5C(work, (void *)work->selectedMon);
            func_021BB97C(work, work->messageWindow);
            func_021BB9AC(work, work->messageWindow, 1, (u16)heldItem);
            func_021BB9AC(work, work->messageWindow, 2, (u16)(work->arg->itemId));
            if (work->arg->mode == 0xa) {
                work->arg->mode = 0;
                if (evolveKindOne == 1) {
                    func_021BDC3C(work, (void *)work->selectedMon);
                    func_021B9788(work, 0x40, 1, func_021BA4E4);
                    work->evolveCheckKind = 1;
                } else if (evolveKindTwo == 1) {
                    func_021BDCA0(work, (void *)work->selectedMon);
                    func_021B9788(work, 0x40, 1, func_021BA4E4);
                    work->evolveCheckKind = 2;
                } else {
                    func_021B9788(work, 0x40, 1, func_021B9E20);
                }
            } else {
                work->arg->exitCode = 0xa;
                if (evolveKindOne == 1) {
                    func_021BDC3C(work, (void *)work->selectedMon);
                    func_021B9788(work, 0x40, 1, func_021BA4E4);
                    work->evolveCheckKind = 1;
                } else if (evolveKindTwo == 1) {
                    func_021BDCA0(work, (void *)work->selectedMon);
                    func_021B9788(work, 0x40, 1, func_021BA4E4);
                    work->evolveCheckKind = 2;
                } else {
                    func_021B9788(work, 0x40, 1, func_021B9E3C);
                }
            }
            func_021BB98C(work, work->messageWindow);
        }
    } else {
        if (work->arg->mode == 0xa) {
            work->arg->mode = 0;
            func_021BB7A4(work, (u32 *)work->messageWindow);
            work->phase = 2;
            func_021B7B98(work);
        } else
            work->phase = 0x13;
    }
}

void func_021BA288(PokelistWork *work)
{
    void *sourceMon;
    void *targetMon;
    u32 sourceMaxHp, targetHp, targetMaxHp, newHp;
    sourceMon = func_0201AB28(work->arg->party, work->healSourceSlot);
    func_02017E1C(sourceMon, 0xa0, 0);
    sourceMaxHp = func_02017E1C(sourceMon, 0xa1, 0);
    targetMon = func_0201AB28(work->arg->party, work->arg->selectedIndex);
    targetHp = func_02017E1C((void *)work->selectedMon, 0xa0, 0);
    targetMaxHp = func_02017E1C((void *)work->selectedMon, 0xa1, 0);
    work->selectedSlot = work->arg->selectedIndex;
    newHp = targetHp + sourceMaxHp / 5;
    if (newHp > targetMaxHp) {
        func_02017E40(targetMon, 0xa0, targetMaxHp);
    } else {
        func_02017E40(targetMon, 0xa0, newHp);
    }
    work->phaseCallback = func_021BA318;
    work->phase = 10;
    work->healSoundPending = 1;
}

void func_021BA318(PokelistWork *work)
{
    u16 hpNow;
    u16 hpBefore;
    hpNow = func_021BB464(work, work->plates[work->arg->selectedIndex]);
    work->selectedSlot = work->arg->selectedIndex;
    func_021BB97C(work, work->messageWindow);
    func_021BB99C(work, work->messageWindow, 0, work->selectedMon);
    hpBefore = work->cursorState;
    if (hpBefore) {
        func_021BB9EC(work, work->messageWindow, 1, (u16)(hpNow - hpBefore), 3);
        func_021B9788(work, 0x2c, 1, func_021B9E20);
    }
    func_021BB98C(work, work->messageWindow);
}

void func_021BA394(PokelistWork *work)
{
    func_021B9804(work, func_021BA3A4);
}

void func_021BA3A4(PokelistWork *work, int choice)
{
    int mailSlot;
    void *mail;
    func_021BB7A4(work, (u32 *)work->messageWindow);
    if (choice == 14) {
        mailSlot = func_02009020(work->arg->mailBox, 0);
        if (mailSlot >= 0) {
            mail = func_02008F08(work->heapId);
            func_02017E1C((void *)work->selectedMon, 0xa7, (u32)mail);
            func_0200903C(work->arg->mailBox, 0, mailSlot, mail);
            func_020307B0(mail);
            func_02017E40((void *)work->selectedMon, 6, 0);
            func_021BB2C0(work, work->plates[work->selectedSlot]);
            func_021B9788(work, 0x1a, 1, func_021B9E20);
        } else {
            func_021B9788(work, 0x1e, 1, func_021B9E20);
        }
        return;
    }
    func_021B9788(work, 0x1b, 0, func_021BA444);
}

void func_021BA444(PokelistWork *work)
{
    func_021B9804(work, func_021BA454);
}

void func_021BA454(PokelistWork *work, int choice)
{
    func_021BB7A4(work, (u32 *)work->messageWindow);
    if (choice == 0xe) {
        int heldItem = func_02017E1C((void *)work->selectedMon, 6, 0);
        if (func_021BA65C(work, heldItem) == 0x3e7) {
            func_021B9788(work, 0x3f, 1, func_021B9E20);
            return;
        }
        func_021BA688(work, heldItem);
        func_02017E40((void *)work->selectedMon, 6, 0);
        func_021BB2C0(work, work->plates[work->selectedSlot]);
        func_021B9788(work, 0x1f, 1, func_021B9E20);
    } else {
        func_021BB7A4(work, (u32 *)work->messageWindow);
        work->phase = 2;
        func_021B7B98(work);
    }
}

void func_021BA4E4(PokelistWork *work)
{
    func_021BB7A4(work, (u32 *)work->messageWindow);
    work->phase = 14;
}

void func_021BA4F8(PokelistWork *work)
{
    u8 i;
    u8 j;
    PokelistRegulation *rules;
    int phase;
    if (work->touchDragState != 0)
        return;
    phase = work->phase;
    if (phase == 0x13)
        return;
    if (phase == 0x15)
        return;
    if (phase == 0)
        return;
    if (phase == 1)
        return;
    if (phase == 6)
        func_021B90F8(work);
    work->touchDragState = 1;
    if (work->reservedWord == 1)
        work->phase = 0x11;
    else
        work->phase = 0x14;
    work->arg->selectedIndex = 6;
    work->arg->exitCode = 0;
    if (work->selectionConfirmed != 0)
        return;
    for (i = 0; i < 6; i++)
        work->arg->slotOrder[i] = 0;
    rules = work->arg->regulation;
    if (POKE_REGULATION_FindValidOrder(rules, work->arg->party, work->arg->slotOrder) != 0)
        return;
    for (i = 0; i < 6; i++)
        work->arg->slotOrder[i] = 0;
    for (j = 0; j < rules->minPartySize; j++)
        work->arg->slotOrder[j] = j + 1;
}

u32 func_021BA5B4(PokelistWork *work, void *mon)
{
    PokelistArg *arg = work->arg;
    if (arg->mode == 5 || arg->mode == 8)
        return func_0201808C(mon, arg->moveId);
    else
        return POKE_TOOL_FindMoveSlot(mon, arg->moveId);
}

/*
 * Verified blocker C (one --thumb, no region, EXACT, 8 bytes):
 * typedef unsigned char u8; typedef unsigned short u16;
 * extern void POKE_TOOL_ReplaceBoxMoveSlot(void *,u16,u8);
 * void POKE_TOOL_ReplaceMoveSlot(void *p,u16 move,u8 slot) { POKE_TOOL_ReplaceBoxMoveSlot(p,move,slot); }
 * Extent ends with two bytes alignment padding.
 *
 * 2026-10-05 (D8 lane 15): 020182A0 now filed EXACT as src/matched/arm9/POKE_TOOL_ReplaceMoveSlot.c.
 * Re-run after the integrator regenerates the layout; expected EXACT.
 */
void func_021BA5E0(PokelistWork *work, void *mon, u32 slot)
{
    PokelistArg *arg = work->arg;
    if (arg->mode == 5 || arg->mode == 8)
        func_020181F4(mon, arg->moveId, slot);
    else
        POKE_TOOL_ReplaceMoveSlot(mon, arg->moveId, slot);
}

void func_021BA60C(PokelistWork *work, void *mon)
{
    NATSUKI_Calc(mon, 7, work->arg->itemUseParam, work->heapId);
}

void func_021BA624(PokelistWork *work, void *mon, u16 itemId)
{
    u32 oldItem = func_02017E1C(mon, 6, 0);
    if (oldItem)
        func_021BA688(work, oldItem);
    func_02017E40(mon, 6, itemId);
    if (itemId)
        func_021BA670(work, itemId);
}

u32 func_021BA65C(PokelistWork *work, u16 itemId)
{
    return func_02007FB8(work->arg->bag, itemId, work->heapId);
}

u32 func_021BA670(PokelistWork *work, u16 itemId)
{
    return func_02007F1C(work->arg->bag, itemId, 1, work->heapId);
}

u32 func_021BA688(PokelistWork *work, u16 itemId)
{
    return func_02007E50(work->arg->bag, itemId, 1, work->heapId);
}
