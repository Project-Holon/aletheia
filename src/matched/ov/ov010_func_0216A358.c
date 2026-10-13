/*
 * function: FORMCHANGE_RevertShayminAtNight
 * address: 0x0216A358
 * packet: pkt_ov010_0216A358
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   TIMEZONE_GetZoneLightLevel 0x02011400 thumb
 *   FORMCHANGE_RevertShayminAndRegister 0x0216A390 thumb ov010
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u8 TIMEZONE_GetZoneLightLevel(int row, int col);
extern void FORMCHANGE_RevertShayminAndRegister(int,int);
int FORMCHANGE_RevertShayminAtNight(int a,int b,u32 *p,int c) { u32 hi; u32 lo; int result; hi=TIMEZONE_GetZoneLightLevel(c,3); lo=TIMEZONE_GetZoneLightLevel(c,0); result=0; if (!(*p < hi && *p >= lo)) { FORMCHANGE_RevertShayminAndRegister(a,b); result=1; } return result; }
