# fade (arm9)

Translation unit 0204E5E8..0204E8C0, 8 functions. Parts fade_p01.c, fade_p02.c plus members func_0204E804.c, func_0204E824.c (in address order: p01, p02, func_0204E804, func_0204E824).

Blocked by one global (g_02146A7C) and a struct seen through different local views:
- struct S0204E638 (p02) lacks fields used by other members (unk1c);
- func_0204E804 defines struct Run0204E720 with its own field set (f0...);
- func_0204E824 uses an anonymous struct with unk00/unk08.
Unify into one struct by offsets (struct pass), then merge in address order.
