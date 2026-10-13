/*
 * unit:     no
 * function: func_0201034C
 * address:  0x0201034C
 * packet:   pkt_02010068
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GFL_USE_PollPowerExit  0x020053EC  thumb
 *   GFL_USE_UpdateSound  0x02005BC0  thumb
 *   PM_VOICE_StopFinished  0x020065FC  thumb
 */

int func_0201034C(void){ int t0 = GFL_USE_PollPowerExit(); int t1 = func_02034F5C((int)t0); int t2 = GFL_USE_UpdateSound((int)t1); int t3 = PM_VOICE_StopFinished((int)t2); return t3; }
