# A dead stack parameter reassigned to a local's address keeps a callee-saved register

summary: When a stack-passed parameter is dead after its first use and the source reassigns it to the address of a local aggregate, the compiler keeps that address in a callee-saved register for the rest of the body. A fresh pointer local holding the same address is copy-propagated away and the address is rebuilt before each call.

Found in: docs/notes/pkt_0202E1F0.c.txt (0x0202E1F0, pms_draw.c, Thumb)

The image shows `push {r3-r7, lr}` with the workspace address promoted into r7
and passed to every later call from that register. Writing

```c
func_02024570(ws, w);
w = ws;
/* every later call passes w */
```

reproduces the frame and the promoted register; the same body with a separate
`struct Ws *p = ws;` local gives a 400-byte function against 412 with the
address recomputed by `add rN, sp, #k` at each use. The parameter reuse
took 0x0202E1F0 from 371 concrete bytes out to 21 (one r6/r7 swap remains).
