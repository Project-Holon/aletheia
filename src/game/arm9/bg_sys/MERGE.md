# bg_sys (arm9)

Translation unit 0203EF5C..020432E4. Three files, address order:

- `bg_sys_p01.c`: 0203EF5C..0203F0A7, compiler 1.1p1.
- `bg_sys_p02.c`: func_0203F0A8, compiler 1.2 (a real compiler change inside the range, so a
  file boundary).
- `bg_sys_p03.c`: 0203F1FC..020432E3, compiler 1.1p1 (the old p03 and p04, merged in round 4).
  func_02040EE0 now takes (u8 x, u8 y, u8 code) and func_02040F84 takes (u8 x, u8 y, u8 w,
  u8 h) like the p04 callers expect; its two shifts are written `(u32)x >> 5` so the image's
  logical shift is kept for a u8 operand.

Blocker p01|p02|p03: the 1.2 compiler function sits between the two 1.1p1 parts. This is a
real boundary (compiler change), not a source-level one.
