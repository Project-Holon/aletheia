# scrcmd_proc (ov010)

Round 9 (lane w9c): 5 parts to 2. Old p02..p05 merged EXACT (casts at stand-in calls, func_0215897C called with void *).

Boundary left (p01|p02): func_02159B10 is declared returning u16 in p02 (true definition returns unsigned int); the u16 return suppresses the zero extension at each call, so the real prototype or (u16) casts change bytes (tested). Also p01 and p02 share struct Req.
