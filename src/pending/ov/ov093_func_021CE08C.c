/*
 * function: func_021CE08C
 * address: 0x021CE08C
 * packet: pkt_ov093_021CE08C
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: MATCH
 * blocker: unlabelled ov094 Thumb wrapper 0x021F8524 lacks an outside code-start witness; ov094 is Ilias-owned.
 * symbols:
 *   func_021F8524 0x021F8524 thumb ov094
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int func_021F8524(int);
int func_021CE08C(u8 *p) { if(*(u16 *)(p+0xe4)!=0) { if(p[0x1ad]==0) { if(func_021F8524(1)) p[0x1ad]=1; } return p[0x1ad]; } return 0; }
