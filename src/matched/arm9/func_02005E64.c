/*
 * function: GFL_USE_PushBgm
 * address:  0x02005E64
 * packet:   pkt_02005E64
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GFL_USE_FlushBgmChange  0x02005FBC  thumb
 *   NNS_SndHandleSetTrackPause  0x02072FA8  arm
 *   NNS_SndHandleSetTrackModDepth  0x02073058  arm
 *   NNS_SndHandleSetTrackModSpeed  0x02073078  arm
 */

int GFL_USE_PushBgm(void){ int t0, t1, t2, t3, t4, t5, t6, t7; t0 = GFL_USE_FlushBgmChange(); t1 = func_0200590C((int)t0); t2 = NNS_SndHandleSetTrackPause((int)t1, (int)(0xFFFF + 0), (int)0); t3 = func_0200590C((int)t2); t4 = NNS_SndHandleSetTrackModDepth((int)t3, (int)(0xFFFF + 0), (int)0); t5 = func_0200590C((int)t4); t6 = NNS_SndHandleSetTrackModSpeed((int)t5, (int)(0xFFFF + 0), (int)0x10); t7 = func_02005A00((int)t6); return t7; }
