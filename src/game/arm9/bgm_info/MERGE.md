# bgm_info.c (arm9)

Translation unit 02005BC0..02006F20, 96 functions. Now two parts and one member.

Files, in address order:

- `bgm_info_p01.c`: 02005BC0..02006D3B, merged and verified (includes the unlabelled
  tail-call stub at 0x02005C18, taken from src/matched/arm9/unit_02005C18.c, which was
  in no part and no member).
- `bgm_info/func_02006D3C.c`: an 8-byte ARM linker veneer (`ldr pc, [pc, #-4]`).
  A veneer inside a range is a file boundary, so it stays a separate file.
- `bgm_info_p02.c`: 02006D44..02006F20, merged and verified.

p01 and p02 differ only by the veneer between them, so the TU cannot be one file.
