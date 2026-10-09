# unit_021F36C0 (ov056): 2 parts left

Two tail stubs at 0x021F3D44 and 0x021F3D54 were added as hidden functions at the start of p02
(func_021F3D44 calls func_02047A60 with f1c and a+0x20; func_021F3D54 tail-calls it). The gap is closed.

- p01 | p02: func_021F3D60 (p02) has a u16 heap parameter and passes it straight to the stack slot
  of func_021F4040 (no narrowing). p01 (func_021F3734) calls it with an unnarrowed heap. A typed
  prototype adds lsls/lsrs at the call; with no declaration mwcc rejects the later prototyped
  definition ("redeclared"); a K&R definition narrows inside the callee (DIFF). Not mergeable.
  Also func_02082BCC (p01, unsigned args) and MI_CpuFill8 (p02) are one address under two names.
