# namein_graphic: blockers (lane 051)

23 files reduced to 4 parts (p01 021F1440, p02 021F1D58, p03 021F2F8C, p04 021F3B18). Three
boundaries stay. All three have the same shape: a callee has narrow parameters (or a narrow
return type) in its definition, and the caller passes wide values with no narrowing code. A
prototype-style declaration makes the caller narrow (lsls/lsrs), a K&R definition makes the
callee narrow on entry; the image has neither. Possibly these are separate original TUs.

- p01 | p02: func_021F1E28(u8 *, int, u16 b, u16 c, int, u8 *, int) is called from func_021F1440
  with word values for b and c. Caller-side narrowing adds 4 bytes to func_021F1440.
- p02 | p03: func_021F26F0(char *, char *, void *, void *, u16 heap) is called from func_021F3008
  with a full-word heap argument (the same value is forwarded to word parameters elsewhere).
- p03 | p04: func_021F32FC is defined as returning void * (word load) and read in p04 as
  `u16 value = func_021F32FC(p + 0xfc)`; a u16 return type in the definition changes the
  callee, a cast at the call changes the caller.
