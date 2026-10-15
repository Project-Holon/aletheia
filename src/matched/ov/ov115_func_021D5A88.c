/*
 * function: WIFILOGIN_MSG_Run
 * address: 0x021D5A88
 * packet: pkt_ov115_021D5A88
 * region: ov115
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * trailing: two-byte alignment padding, no follower.
 * symbols:
 *   TCBL_Main 0x020310C4 arm
 *   PRINTSYS_QUE_Main 0x0201C4E4 thumb
 */
#include "../include/Obj13852.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
struct PrintSys;
struct Tcbl;
extern void TCBL_Main(struct Tcbl *p);
extern u32 PRINTSYS_QUE_Main(struct PrintSys *);
void WIFILOGIN_MSG_Run(u8 *p) { TCBL_Main(((struct Obj13852 *)p)->f44); PRINTSYS_QUE_Main(*(struct PrintSys * *)&((struct Obj13852 *)p)->f48); }
