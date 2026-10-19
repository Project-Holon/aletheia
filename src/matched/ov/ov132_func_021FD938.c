/*
 * unit: yes
 * function: STA_NET_BeginKind5Phase, STA_NET_SetState18Value, STA_NET_GetPairA, STA_NET_GetPairB
 * The larger indexed follower at 021FD964 is parked separately at DIFF.
 * address: 0x021FD938
 * packet: pkt_ov132_021FD938
 * region: ov132
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   MUS_COMM_FUNC_SetTimingSync 0x021FCDEC thumb ov132
 */
#include "../include/Obj14143.h"
#include "../include/Obj23302.h"
#include "../include/Obj23303.h"
#include "../include/Obj23304.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void MUS_COMM_FUNC_SetTimingSync(int,int);
void STA_NET_BeginKind5Phase(char *p) {MUS_COMM_FUNC_SetTimingSync((int)p,0x42);((struct Obj23302 *)p)->f4C=12;}
void STA_NET_SetState18Value(char *p,u32 value){((struct Obj14143 *)p)->f4C=18;((struct Obj14143 *)p)->f120=value;}
u32 STA_NET_GetPairA(char *p){return ((struct Obj23303 *)p)->f144;}
u32 STA_NET_GetPairB(char *p){return ((struct Obj23304 *)p)->f148;}
