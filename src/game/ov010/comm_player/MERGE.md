# comm_player (ov010)

Round 13 (lane w13d): 11 parts -> 2. Canonical struct CommPlayer (p01 and p02 views of the object at +0x668 etc.), Date/Time/A, BattleMon/FacGroup/FacDraw/Blk, Res/Work and call-site fixes (stand-in calls without result, argument casts) merged p02..p11.

Left: p01|p02. func_02167BB4 takes `u16 v` in p01 (the callee itself does not truncate) while func_02167BFC in p02 passes the u32 `arg` untruncated; one TU cannot hold both, so this is a real file boundary (compiler change tested both ways: u32 callee is DIFF, u16 prototype adds lsls/lsrs in the caller).

Parts: comm_player_p01.c, comm_player_p02.c
