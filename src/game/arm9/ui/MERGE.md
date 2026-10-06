# ui (arm9)

Merge status: 6 files remain.

- `ui_p01.c`: func_02034E24, func_02034EF8, func_02034F5C, func_02034F74, func_02034F84, func_02034FA0 (compiler dsi/1.1p1, flags -O4,p, lang c99, isa arm)
- `ui_p02.c`: func_02034FB8, func_02034FD4, func_02034FE8, func_02035004, func_02035010, func_02035034, func_02035040 (compiler dsi/1.1p1, flags -O4,p, lang c99, isa arm)
- `ui_p03.c`: func_02035064 (compiler 1.1p1, flags -O4,p, lang c99, isa arm)
- `ui_p04.c`: func_02035080, func_0203508C, func_02035100, func_02035108, func_02035120 (compiler dsi/1.1p1, flags -O4,p, lang c99, isa arm)
- `ui_p05.c`: func_02035138, func_0203515C, func_0203516C, func_02035188, func_020351A0, func_020351BC, func_020351D0, func_020351EC, func_020351F8, func_0203521C, func_02035224 (compiler dsi/1.1p1, flags -O4,p, lang c99, isa arm)
- `ui_p06.c`: func_0203524C, func_02035268, func_02035284, func_020352AC, func_020352DC (compiler dsi/1.1p1, flags -O4,p, lang c99, isa arm)

Blockers between adjacent files:
- `ui_p01.c` | `ui_p02.c`: one global (the UiCtx object at 0x021469BC, named g_/d_/unk_021469BC) is viewed as u8*, char*, u32[], void*, struct Obj021469BC, struct IconState and struct UiCtx by different members; func_02034FA0 has two prototypes (unsigned char *, unsigned char) vs (void *, u32). Offsets agree (fn at 0x24, arg at 0x30, flags at 0x38, f3f at 0x3f); the struct pass must give one UiCtx and cast-free calls. Also c99=DIFF at some boundaries (func_02034FB8 side and ui_p06|p07 side).
- `ui_p02.c` | `ui_p03.c`: settings differ (dsi/1.1p1/-O4,p/c99/arm vs 1.1p1/-O4,p/c99/arm); never merged across a settings change.
- `ui_p03.c` | `ui_p04.c`: settings differ (1.1p1/-O4,p/c99/arm vs dsi/1.1p1/-O4,p/c99/arm); never merged across a settings change.
- `ui_p04.c` | `ui_p05.c`: one global (the UiCtx object at 0x021469BC, named g_/d_/unk_021469BC) is viewed as u8*, char*, u32[], void*, struct Obj021469BC, struct IconState and struct UiCtx by different members; func_02034FA0 has two prototypes (unsigned char *, unsigned char) vs (void *, u32). Offsets agree (fn at 0x24, arg at 0x30, flags at 0x38, f3f at 0x3f); the struct pass must give one UiCtx and cast-free calls. Also c99=DIFF at some boundaries (func_02034FB8 side and ui_p06|p07 side).
- `ui_p05.c` | `ui_p06.c`: one global (the UiCtx object at 0x021469BC, named g_/d_/unk_021469BC) is viewed as u8*, char*, u32[], void*, struct Obj021469BC, struct IconState and struct UiCtx by different members; func_02034FA0 has two prototypes (unsigned char *, unsigned char) vs (void *, u32). Offsets agree (fn at 0x24, arg at 0x30, flags at 0x38, f3f at 0x3f); the struct pass must give one UiCtx and cast-free calls. Also c99=DIFF at some boundaries (func_02034FB8 side and ui_p06|p07 side).
