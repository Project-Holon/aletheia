/*
 * function: func_021CE08C
 * address: 0x021CE08C
 * packet: pkt_ov093_021CE08C
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * blocker: unlabelled ov094 Thumb wrapper 0x021F8524 lacks an outside code-start witness; ov094 is integrator-owned.
 * symbols:
 *   func_021F8524 0x021F8524 thumb ov094
  * note 2026-10-05 (D8 lane16): re-verified MATCH. Same blocker as 021CDDA0: ov094 0x021F8524 needs a label/witness.
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int func_021F8524(int);
int func_021CE08C(u8 *p) { if(*(u16 *)(p+0xe4)!=0) { if(p[0x1ad]==0) { if(func_021F8524(1)) p[0x1ad]=1; } return p[0x1ad]; } return 0; }
