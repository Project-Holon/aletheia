/*
 * function: func_021CDDA0
 * address: 0x021CDDA0
 * packet: pkt_ov093_021CDDA0
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * blocker: ov094 0x021F8524 unlabelled Thumb tail wrapper, owner Ilias;
 * unresolved THM_CALL at +0x14. Region hint ov094 does not supply a witness.
 * symbols:
 *   func_021F8524 0x021F8524 thumb ov094
  * note 2026-10-05 (D8 lane16): re-verified MATCH. Callee 0x021F8524 is an ov094 Thumb wrapper (pool-based tail), other overlay, not filed here (ov094 owner Ilias). Integrator: seed label.
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int func_021F8524(int);
struct Flags { u8 pad[0x1b2]; u8 low:4; u8 flag:1; u8 high:3; };
int func_021CDDA0(u8 *p) { if(p[0x1a7]!=2) { if(*(u16 *)(p+0xe6)) return func_021F8524(0); return 0; } return ((struct Flags *)p)->flag; }
