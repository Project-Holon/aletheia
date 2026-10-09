# scrcmd_proc.c

Parts that stay separate after the greedy merge (tools in scratchpad ol010), and why:

- p01|p02: func_02159B10 is declared returning u16 in p02 (true definition returns unsigned int); the u16 return suppresses the zero-extension at each call, so using the real prototype or adding (u16) casts changes bytes (tested). Also p02 and p01 share struct Req.
- p02|p03 and p04|p05 : local struct views of the same globals differ (CCERR on void */int parameters of func_0215897C / func_020307B0 declared differently); needs a struct pass.
- p03|p04: c99=DIFF when func_0215C610 joins (inlining or pool change).
