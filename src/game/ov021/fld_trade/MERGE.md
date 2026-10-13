# fld_trade (ov021): 2 parts (was 3)

w11d (2026-10-10): old p02|p03 merged and EXACT. The trade work object is now one struct `TradeWork` (0x580 bytes)
defined by offset in the merged part: u32 words f0..f2C (f4 word set, f8 message bank, f14 window set, fc/f10 windows),
f30 data, TradeEnt ent[4] at 0x50 (0x2C bytes each: data, state, flag, mac), busy at 0x100, ent req at 0x104, TradeHq hq
at 0x130, TradeSub sub at 0x13C (busy/result/state/prev/timer at +0x2C8), f414 request bytes, callbacks f48C/f490,
TradeBuf buf at 0x494 (four 0x20-byte copies plus a mask), state byte x51E, flags x519..x526, macs[4] at 0x55A, x574,
x578. All u8 *p / u32 *p views and the U32() macro are gone. Notes on shape: func_021CE8F4 must index with
`(u8 *)p->macs + i * 6` for the first use (a local Mac pointer or a plain p->macs[i] is CSEd and grows); func_021CE6F0
takes `int i` (a u8 parameter adds a narrowing at the call in func_021CD6D0); TradeEnt starts with u32 data[8] so the
0x2C-byte struct copy in func_021CE3E8 is a word copy.

Remaining boundary p01 | p02 (0x021CD050): func_02030734. The p01 callers need the heap argument narrowed (prototype
u16 heap); func_021CD48C in p02 loads heap from the stack with ldr and passes it unnarrowed (a u16 parameter gives ldrh
twice, a u32 prototype adds nothing to p01 that stays EXACT). Tested both ways in w10b; looks like a real source boundary.

Round 18 (L17): retested. With a u32 prototype p01 loses its repeated per-use narrowing of `(u16)a`; with a u16 heap
parameter func_021CD48C loads heap with ldrh at each use (the original has one ldr into r6). func_021CD1C8 would
need u16 heap too. Boundary unchanged.

F08b (2026-10-12): merged text compiles after casting func_021CD1AC/func_021CD004/func_021CD038 arguments to the
other part's work type. With a u16 heap in func_02030734, func_021CD1C8 (u16 heap parameter) and everything before
func_021CD48C are EXACT; the only difference is the single call in func_021CD48C, which the target makes with
heap unnarrowed (r6 straight from `ldr r6,[sp,#0x28]`). With a u32 prototype instead, func_021CBFB0 computes
`(u16)a` once (CSE into r6, also with `a & 0xFFFF`) where the target narrows at each call. A u16 stack parameter
gives `add r4,sp,#N; ldrh`. A K&R redeclaration of func_02030734 (file or block scope) is rejected as a redeclaration.

F11 (2026-10-12): the boundary is a real source boundary. The site strings passed as the `file` argument of func_02030734
name the original source files: d_021DE59C "fld_trade.c", d_021DE5A8 "scrcmd_palpark.c", d_021DE5C0
"party_select_list.c" (all in p01), d_021DE5D4 "field_bb_color.c", d_021DE5E8 "comm_entry_menu.c" (both in p02).
func_021CD48C belongs to comm_entry_menu.c and func_021CBFB0 to fld_trade.c, so the two parts were different
translation units where func_02030734 (asm-only, no C definition) was declared with different heap parameter types
(u16 in fld_trade.c, unnarrowed in comm_entry_menu.c). Tested in F11 without result: u32 prototype with the u16
parameter or plain `a` in func_021CBFB0 (no narrowing), `heap & 0xFFFF`, `(u16)heap`, `heap % 65536` at the call,
u16 heap parameter (ldrh, add r4,sp), `register u16` copy (narrows at entry), optimization_level 1 on func_021CBFB0
(no CSE but scheduling differs, 24 bytes off). Keep the two parts.
