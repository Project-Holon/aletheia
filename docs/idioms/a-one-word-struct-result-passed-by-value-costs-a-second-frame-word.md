# A one-word struct result held in a local and passed by value costs a second frame word

summary: when the original opens `push {r4-r6, lr}; sub sp, #8` and never touches `[sp]`, and one callee returns a one-word struct that is then passed by value to another callee, `t = f(); g(..., t);` reserves both temporaries (8 bytes); `g(..., f())` reserves only one (`push {r3-r6, lr}; sub sp, #4`).

Found in: src/matched/ov/ov093_func_021CBFA0.c (0x021CBFA0)

Extends `an-unused-frame-word-is-a-callee-returning-a-one-word-struct.md`.
`func_021E8940` returns a bitfield word (`Word { u32 v; }`), and its result
is the third argument of `func_021CBFF8(int, int, Word)`. With the call
nested in the argument list the frame is `sub sp, #4` and the pushed set gains
r3; assigning to a local `Word t` first and passing `t` gives the original
`push {r4, r5, r6, lr}; sub sp, #8`, byte for byte.

Other spellings: `u32` return (no frame), `int` locals or arrays (optimised
away), a single nested call (one word only).
