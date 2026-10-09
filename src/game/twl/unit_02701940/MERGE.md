# unit_02701940.c (twl)

Parts: p01 (02701940..02701FD8), p02 (02701FD8..02702080).

An empty `asm void f(void) {}` stand-in lays out 0 bytes, so the status of its file says EXACT or EXACT* without any code being compared. Merging a part that holds such a stand-in with the next part moves the next part's code and the merged TU is DIFF. The boundary stays until the stand-in is written as real C (or asm with a body) that lays out the original bytes.

- p01|p02: func_02701AA0 (CameraPxiCallback, libcamera camera_api.o, 1336 bytes) is an empty stand-in. SDK source is in sdk/TwlSDK (camera_api.c); the extern list in src/matched/twl_sdk/func_02701AA0.c names OS_DisableInterrupts, OS_RestoreInterrupts, func_02701FE8, func_027001F0, data_02733FC8.

