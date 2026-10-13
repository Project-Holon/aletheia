/*
 * function: func_020090B4
 * address:  0x020090B4
 * packet:   pkt_020090B4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   MI_CpuFill8  0x02082BCC  arm
 *   MI_CpuCopy8  0x02082D44  arm
 */

int func_020090B4(int a0, int a1, int a2, int a3){ int t0, t1, t2; t0 = func_020090B0(); t1 = MI_CpuFill8((int)((a0 + 0) + 0), (int)0, (int)(t0 + 0)); t2 = MI_CpuCopy8((int)0x20A7174, (int)((a0 + 0) + 0), (int)0x24); return t2; }
