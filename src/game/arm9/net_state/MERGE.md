# net_state.c (arm9)

Translation unit 020353B0..0203E5F8, 413 functions, confidence weak (tools/tuboundary.py).

Adjacent parts and members were merged greedily (each merge verified EXACT):
75 parts + 87 members became 64 parts (net_state_p01.c..net_state_p64.c) + the
members listed here. Every remaining neighbour pair fails to merge for one of
these reasons:

- Globals with two views. g_021469BC (struct Sys * vs a Desc object),
  g_021469C8 (Notifier array vs a struct with handler/mode), g_021469D0 (the
  main net state: char *, u8 *, NetState, Net_02037478, Handle, Votes, HugeRecv,
  Entry, Peer, Sys ... one local struct per member), g_021469DC, g_021469E0,
  g_021469F0. A merge needs one canonical struct for each and casts removed from
  about 60 members; this is struct unification work, not a cast fix.
- Functions with two prototypes: func_0203D798 / func_0203D788 (return char *,
  void *, struct Oth *, struct Entry *), func_02036BD4, func_02039658,
  func_0203B52C, func_0203DC68 (same parameter, differently named local struct).
- Lifted members with int-typed arguments (func_02036254, func_02036270,
  func_0203660C, func_0203675C, func_02036B4C ...) that call functions whose
  prototype is known in the neighbouring part: each call needs a pointer cast.
- c99=DIFF: merging changes the code (shared strings or inlining), e.g. around
  func_020371AC, func_02037680/func_020377B8, func_02038380, func_02038524,
  func_0203B1D8, func_0203D210, func_0203D634, func_0203D5AC.
- Thumb members without a header (func_02038924, func_02039160) cannot join the
  ARM parts without a pragma.

Members left in this folder: func_02036270.c func_02037118.c func_020371AC.c func_02037E60.c func_02038380.c func_02038524.c func_02038924.c func_02039050.c func_020390BC.c func_02039160.c func_020398B4.c func_0203A53C.c func_0203A574.c func_0203A5E4.c func_0203AFCC.c func_0203B0C4.c func_0203B1D8.c func_0203B22C.c func_0203B5D4.c func_0203BA98.c func_0203C464.c func_0203D0FC.c func_0203D1E8.c func_0203D210.c func_0203D634.c func_0203D788.c func_0203DAC4.c func_0203DBB0.c func_0203DC04.c func_0203DC70.c func_0203E420.c func_0203E458.c sub_02039338.c sub_020393A8.c 

- `sub_020353B0.c` was missing from the restructured tree and was added back from src/matched (tools/gamefix.py); merge it into its neighbours.

- `sub_020353C8.c` was missing from the restructured tree and was added back from src/matched (tools/gamefix.py); merge it into its neighbours.

- `sub_020353F8.c` was missing from the restructured tree and was added back from src/matched (tools/gamefix.py); merge it into its neighbours.

- `sub_02035428.c` was missing from the restructured tree and was added back from src/matched (tools/gamefix.py); merge it into its neighbours.

- `sub_0203545C.c` was missing from the restructured tree and was added back from src/matched (tools/gamefix.py); merge it into its neighbours.

- `func_02035544.c` was missing from the restructured tree and was added back from src/matched (tools/gamefix.py); merge it into its neighbours.

- `unit_020355C4.c` was missing from the restructured tree and was added back from src/matched (tools/gamefix.py); merge it into its neighbours.

- `sub_02035660.c` was missing from the restructured tree and was added back from src/matched (tools/gamefix.py); merge it into its neighbours.
