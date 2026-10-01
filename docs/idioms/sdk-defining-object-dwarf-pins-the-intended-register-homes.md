# An SDK defining object's DWARF pins the intended register homes and exposes hidden temporaries

summary: when the target is a function of a vendor `.a` and the residue is
register colour / spill identity, the DWARF of the *defining object* states the
exact home of every local (`totalRecvbyte r8`, `endFlag r14`, `i r12`,
`tmpbuf [fb+16]`, ...). Read it before spending a wave on declaration and
qualifier permutations: it separates a real source-shape lever from a
front-end allocator tie, and it names temporaries the C shape would otherwise
miss.

Found in: `src/pending/ov_sdk/ov114_func_021BC740.c` (0x021BC740, ov114,
`NHTTPi_RecvProxyConnectHeader`, libnhttp.TWL.HYB.a(nhttp_thread.o)), 142 B
residue. The extracted DWARF is `scratch/lt28/sdkobj_021BC740.txt`.

The pinned homes were `endFlag r14` (lr), `i r12` (ip), `recvbyte r11` (fp),
`totalRecvbyte r8`, `connectFlag [fb+8]`, `tmpbuf [fb+16]`, and the
callee-saved pointer set `r7/r6/r5/r4`; `threadInfo_p` was `r0` (spilled), and
there was a `char *commBuf_p` local that the prior source did not declare.
`tmp_p`, which the prior near-miss used as its key lever, does not exist in
the DWARF. This is the same front-end tie
`a-spilled-pointer-parameter-tie-is-the-front-ends-not-a-source-shape.md`
describes: rewriting to the DWARF shape (no `tmp_p`, non-volatile `endFlag`,
named `commBuf_p`) moved the whole frame instead of converging (`456 B / 346`
diff; `commBuf_p` alone `166 B`), while the non-DWARF 142 B approximation
stayed the closest. So the DWARF tells you *that* it is an allocator tie and
*what* the object really homed, in one read; do not infer a source lever from
it.
