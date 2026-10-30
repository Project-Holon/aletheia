# File boundaries (wave 16)

Earlier restructure waves split `src/game` into one file per original source file where a
`__FILE__` anchor (the file-name string an allocation passes, `layout/file_anchors.txt`) proved
a border. Functions with no anchor stayed with their neighbours, so about 65 files still held
several originals: `tools/namecheck.py` and a prefix scan found files that mix two or more module
prefixes. Wave 16 audited each one. This page records the method and the result.

## Evidence used for a border

1. `__FILE__` anchors: the strongest evidence; the string names the original file.
2. The module prefix (Game Freak names functions FILE_PREFIX_Verb). A run of one prefix is
   normally one file; a sub-prefix of the same module (FIELD_RAIL_WORK_* in field_rail.c) is the
   same file.
3. Statics: a static function or object used on both sides of a candidate border means there
   is no border there.
4. Data order: each object file's `.rodata`/`.data`/`.bss` follow the link order of the code
   files, so data whose owners interleave proves one file (two object files cannot interleave).
5. The assert-string and file-name pools: one empty assert string per translation unit.
6. Vendor object lists (`layout/symbols_sdk.txt`) for SDK, NitroSystem and DWC code.

A piece that is the head or tail of an existing original (contiguous addresses, same prefix)
was merged into it; two half-files that declared the same struct or function differently were
unified on the declaration that matches the definition and the real use.

## Result

Split (pieces named after their module; names with no anchor are listed in `docs/DEBT.tsv`):

- arm9: `vm.c` (net_err_proc exit callback, `gpower.c`, `vm.c`, `timezone.c`), `time_icon.c`
  (seven modules: `app_env.c`, `comm_history.c`, `time_icon.c`, `item_gfx.c`, `save_event.c`,
  `event_id.c`, `app_power.c`), `save_control.c` (`save_control.c`, `box_savedata.c`,
  `perapvoice.c`, `myitem_savedata.c`, on four anchors), `mail.c` (five), `particle.c`
  (`billboard_act.c`, `dma_channels.c`, `particle.c`), `shinka_check.c` (five: evolution,
  friendship, poke_tool healing and icons, the move table, the head of `printsys.c`),
  `ica_anime.c` (`ica_anime.c`, `gamesystem.c`), `app_taskmenu.c`, `playtime.c`, `wifilist.c`,
  `pokeparty.c`, `musical_dist_save.c`, `poke_regulation.c`, `bmp.c`, `iss_switch_sys.c`,
  `vman.c` (`gf_panic.c`), `g3d_light.c`, `nns_snd_system.c` (its G3D texture-matrix code moved
  to `nns_g3d_tex_mtx.c`), `pm_voice.c` (`snd_mic.c`), `bgwinfrm.c` (`pokegra.c` completed),
  `iss_dungeon_sys.c`, `iss_switch.c` (`zone_weather.c`), `net_device_table.c`
  (`fldmmdl_save.c`, `wm_icon_arc.c`), `net_err.c` (`wifi_friend.c`). Ten head and tail pieces
  were merged back into `field_sound_system.c`, `game_comm.c`, `app_keycursor.c`, `arc_util.c`,
  `arc_tool.c`, `printsys.c`, `net_err_proc.c`, `poke_tool.c`, `bg_sys.c` and `iss_switch_set.c`.
- ov010: `waza_oshie.c` (`text_texture.c`, the text-to-texture helpers ov020 and ov021 call),
  `calender.c` and `game_beacon_search.c` (seven files, among them `hidden_item.c`,
  `fld_faceup.c`, `beacon_view_event.c`, `game_beacon_set.c`), `scrcmd_musical.c`,
  `delivery_irc.c`, `musical_program.c`, `fld_btl_inst_tool.c` (`field_clock.c`),
  `scrcmd_trialhouse.c` (five).
- ov012 `union_main.c` (three, on the assert-string pool), ov013 the libVCT files (eight),
  ov014 `net_whpipe.c`.
- ov021: `fieldmap_func.c`, `event_comm_error_recovery.c`, `field_g3dobj.c`, `fldeff_ripple.c`,
  `enceff.c` (four), `scrcmd_misc.c`.
- ov093: `hand_tokusei.c` (its HAND_ITEM run moved to `hand_item.c`), `btl_adapter.c`
  (`btl_msg.c`), `btlv_core.c` (`hand_common.c` completed, `btl_dsi_overlay.c`,
  `btl_sickcont.c`, `btl_typepair.c`).
- ov110 `pmsiv_edit.c` (`pmsiv_tool.c`), ov118, ov123 (`pdwacc_state.c`, an accessor moved to
  `gsync_download.c`), ov125 (`gds_socket.c` completed), ov132 (`sta_act_effect.c` completed),
  ov135 (deposit, enter and input re-bordered), ov136 (`mailview.c` completed), ov217
  (`graph_table.c`).

Kept whole on evidence (the reason is in each file's header): ov011 `intrude_comm.c`, ov021
`fldmmdl_movecode.c` and `scrcmd_gimmick.c`, the ov025 and ov026 weather files (their tables are
one size-sorted run), ov056 `field_fk_demo.c`, ov093 `btl_pokeparam.c`, `btl_calc.c` and
`btl_action_word.c`, ov110 `pms_input.c`, ov112 `mus_shot_photo.c`, ov132 `sta_acting.c`, arm9
`dwc_ac_nintendospot.c` (one vendor object), and the SDK pairs `gx_load2d.c` (GX/GXS) and
`gx_bgcnt.c` (G2/G2S).

## Tool notes (tools/splitfile.py)

It can drop `typedef struct X X;` lines that a header only forward-declares, overwrite an
existing `<stem>_shared_types.h` with a self-include, put includes before the typedefs they
need, lose a `#pragma ... reset` between consecutive pragma regions, and miss externs made by
token pasting (FS_OVERLAY_ID). Check the pieces and headers after every split.

## Japanese file names (2026-10-30)

The Japanese cartridges pass the file name to every failed check, where the other languages pass
an empty string, so they have about 600 more `__FILE__` anchors than English. Anchors were
harvested from `black_ja` (`tools/fileanchors.py -e extract_black_ja -l build/black_ja/layout`),
paired to Black functions through the function pairs of `tools/white_map.py`, and compared with
the file names of `src/game`. 27 original names did not match; all but one are used by our code.

Renamed (the whole file has one anchor name):

- ov010 `irc_battle_task.c` to `event_colosseum_battle.c`
- ov012 `union_command.c` to `union_comm_command.c`, `union_scene.c` to `union_subproc.c`
- ov013 `vct_main.c` to `vchat.c`
- ov015 `ircnet.c` to `net_irc.c`
- ov021 `union_chat_log.c` to `union_chat.c`
- ov135 `worldtrade_server.c` to `worldtrade_upload.c`
- ov185 `br_pokesearch.c` to `br_musicallook_proc.c`

Split (anchors of two or more names in one file; the pieces follow the link order of the
file-name strings in the Japanese data):

- ov011 `intrude_comm.c`: `intrude_comm.c`, `intrude_battle.c` (from 0x02176454)
- ov012 `colosseum.c`: `colosseum_comm_command.c`, `colosseum.c` (from 0x02174F4C)
- ov018 `event_comm_common.c`: `intrude_message.c`, `event_comm_common.c` (0x0217F5A0),
  `event_comm_result.c` (0x021804F8), `event_comm_notarget.c` (0x021828B8),
  `event_comm_sleep.c` (0x02182A08)
- ov071 `monolith_tool.c`: `monolith_tool.c`, `monolith_mission_select.c` (0x021B730C),
  `monolith_title.c` (0x021B7C3C), `monolith_power.c` (0x021B8EE8)
- ov115 `wifilogin_disp.c`: `wifilogin_proc.c`, `wifilogin_disp.c` (from 0x021D4D38)
- ov125 `gds_rap.c`: `gds_rap.c`, `gds_rap_response.c` (from 0x021D732C)
- ov175 `wifibattlematch_net.c`: `wifibattlematch_core.c`, `wifibattlematch_net.c` (from 0x021D9DC8)
- ov176 `battle_championship_flow.c`: `battle_championship_core.c`, `battle_championship_flow.c`
  (from 0x0217B2E4)
- ov183 `br_codein.c`: `br_record_proc.c`, `br_bvrank_proc.c` (0x021DD37C), `br_codein.c`
  (0x021DF920), `br_codein_disp.c` (0x021E0840), `br_bvdelete_proc.c` (0x021E1C80)
- ov186 `br_proc_sys.c`: `br_core.c`, `br_proc_sys.c` (from 0x021F99CC)

A cut between two anchored functions of different files is placed at the start of the
Create/Init function group of the second file when unanchored functions sit between them
(evidence 2 and 3 above). The cuts of ov018 (event_comm_result to event_comm_notarget), ov071
(monolith_title to monolith_power) and ov183 (record to bvrank, codein_disp to bvdelete) cross
long unanchored runs and follow that rule; an unanchored original file between them cannot be
ruled out. Each piece keeps the declarations of the file it was cut from; function names keep
their prefixes.

The one name left, `ctalkmsgwin.c` (ov021), has no Japanese function that pairs with ours, so it
names no file yet.
