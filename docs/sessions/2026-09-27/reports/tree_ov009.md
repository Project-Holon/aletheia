# tree_ov009 report

Root candidate func_021A3248 (20504 B) is a phantom: its "body" is pointer words
(0x021A32E8, 0x021A3268, ...) and data bytes, the high-entropy blob idiom. No real
start inside it was identified; no seeds.

Tree root: func_021702A0 (DWCi_ProcessRecvMatchCommand, 4396 B ARM, dwc_match.o).
Every function in this tree is in `layout/symbols_sdk.txt` (TwlDWC libdwcmatch), so
all call sites already attest through the `sdk` class; matching went bottom up anyway.
The root has 33 open direct callees and well over 40 open functions in total.

## Filed: 38 EXACT, shard pkt_ov009_021702A0 (verified twice, second pass 0 rewritten)

0x02168454 0x0216848C 0x02168FF0 0x02169038 0x021690D0 0x0216B838 0x0216B880
0x0216B908 0x0216B9B0 0x0216BA08 0x0216BAF4 0x0216BBDC 0x0216BEA4 0x0216EB68
0x0216F014 0x0216F058 0x0216F20C 0x0216F6C0 0x0216FEF0 0x0216FF2C 0x02170168
0x02170200 0x021719A4 0x02171F68 0x02172E7C 0x02173B18 0x02173CFC 0x02173D28
0x02173D9C 0x02173EF8 0x021754FC 0x02175F4C 0x02175FE4 0x0217637C 0x021763AC
0x02176674 0x021767F4 0x02177748

Files: src/matched/ov009_func_<ADDR>.c. Most closed on the first draft. Levers that
closed the rest: OS_GetTick result bound to a local before the store (02173CFC);
`if (pid != 0 && pid != -1) return pid;` rather than the early-return form (02168FF0);
unsigned char field reads (021767F4); three scalar locals rather than a struct copy to
get the `ldm` (0216F058); declaration order for stack layout (0216FF2C); `p = msg + 1;
p[len] = 0; p += len;` (02170200).

## Near miss

0x021700C8 (DWCi_MakeMatchCommandControl): DIFF, 20 bytes, pure register rotation in
the 5-byte identifier copy. Pending as DIFF; notes in
docs/notes/pkt_ov009_021702A0.c.txt. Permuter seed 6001, no progress.

## Remaining open callees of the root (next lane)

0216FC34 0216F770 021861A8 021758C4 02174FE8 021736AC 02172BB8 02172254 02172124
021720D8 02171E34 02171C08 02171884 021713CC 0216B65C, then the root 021702A0.
Deeper open nodes that were seen: 02171FD4 02172E18 02173614 02176254 0218FD9C
0218482C 02184208 021843E8 0219ED4C 0219EF08 02176B34 02199FB4.

## Integrator

Nothing required. manifest --check is clean. No new idiom files.
