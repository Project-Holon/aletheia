# btl_setup.c (arm9)

Two files, address order: `btl_setup_p01.c` (02012914..) and `btl_setup_p02.c` (02013528..,
the old p02, func_020136E0, func_02013734 and p03, merged in round 4).

Blocker p01|p02: the callee func_0201A920 and the helper func_02013284 are used with two
incompatible argument widths.

- p02 needs `func_0201A920(u16)` and `func_02013284(..., u16 h)`: with a u32 parameter,
  func_02013528 changes (the home store of r3 moves) and func_020136E0 loses its early ldrh.
- p01 needs `func_0201A920(u32)`: func_02013284 and func_0201333C pass a wide value without
  narrowing. With a u16 prototype the callers emit lsl/lsr. Making the callers' own parameters
  u16 changes the frame of func_02013284 (the image has `sub sp, #8`, so `h` is a full u32).
- An unprototyped (K&R) declaration breaks func_0201347C.

No single declaration reproduces both halves, so the original source most probably had them in
two files (the TU boundary guess here is weak). p03's `sub_0201A920` alias is the same function
under a second name.

Guess made in p02: `func_0203D1A4` returns u8 (the callers keep the result in a byte argument
with no narrowing).

Round 17 (L12): the __FILE__ anchors (layout/file_anchors.txt) put 0x02013090, 0x02013234 and 0x02013980 all in
btl_setup.c, so both parts are one TU. Plain concatenation also fails on duplicate names: typedef S, struct Obj
(rename the p02 ones), K&R func_020307B0 and func_020130DC in p01 versus typed in p02, and the func_0201A920 /
func_02013284 width conflict above. Not finished.
