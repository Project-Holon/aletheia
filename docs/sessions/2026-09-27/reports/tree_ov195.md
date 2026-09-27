# tree_ov195 report

Tree: root ov195 func_022040E0. Real extent 0x022040E0..0x02204C24 (2884 B): the listed func_02204BB2 is its shared tail, reached by Thumb long `bl`, not a function. The tree has about 75 open functions, well past the 40 cap. The root is not attempted. It needs func_02205C74 (->func_022063E0, a subtree with 1764/976/480 B functions), func_02205D50, func_0220602C and func_0220878C first.

EXACT, filed (33), each shard verified twice (second pass 0 rewritten):
02204DE0 02204EB0 02204F78 02204F90(unlabelled) 02205010 02205070 022051FC 02205340 02205360 02205384 0220549C 02205530 022055BC 02205620 022056E8 02205844(u) 02205854 022058F8 02205A10 02205A1C 02205A28 02205A34 02205AC0 02205BD8(u) 02205BDC 02205C6C(u) 022060C8 022063AC 02206768 022067B0 022067FC 0220682C 022086BC. Shards pkt_<addr> in layout/matched/ov195/.
Levers: direct drafts. 02205620 closed with a shared `r` and an else arm (not an early return). 02205BDC closed with `const` on the arm9 s16 table. 02205854 needed a 4-arg func_0207DC44. 02205A34/02205AC0 closed with `(int)i` (permuter seed 6401; new idiom file).

MATCH (pending): ov195_func_0220609C.c. All bytes are right; 0x02016020 (arm9 Thumb leaf `str r1,[r0,#0x30]; bx lr`) has no label.

Remaining for next lane (open, ov195): root 022040E0; 02204C24; 02205C74; 02206108 (->022060C8 done, 02206274); 02206274; 022063E0 (->0220685C 02206A5C 02206E2C 022081A4 02208478); 02205D50 (->02206264u 02206604 0220672Cu 022067BC); 02206604 (->022076A0 02208430); 022067BC (->022081A4); 0220602C (->02206664 ->02207510 02208570); 0220871C (->0220887C 02208AB0 ->022086C8); 0220878C (->022089A4 02208A48u 02208C10u 02208C18u 02208C28u 02208C30u).

Seeds: 0x02016020 (arm9, site 0x022060AE); 0x02204F90, 0x02205844, 0x02205BD8, 0x02205C6C (EXACT unlabelled ov195 leaves); 0x02015C78/F0C/F14/F1C, 0x02015EE8/F50, 0x0201600C (arm9 unlabelled callees of 02206274/02205D50). Co-resident overlay at 0x021B6xxx is ov067 (hint used on 0x021B6DC0).

Integrator: seed the addresses above; regenerate the idiom index; ov172/ov175 untouched.
