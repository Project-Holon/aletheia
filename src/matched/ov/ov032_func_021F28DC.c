/*
 * function: func_021F28DC
 * address: 0x021F28DC
 * packet: pkt_ov032_021F28DC
 * region: ov032
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * note: two alignment padding bytes at 0x021F2906 follow the body.
 * symbols:
 *   GAME_BEACON_ACCESSOR_TableMarkLogsNew 0x02165940 thumb ov010
 *   GPOWER_FreePowerTable 0x02010F8C thumb
 *   func_020307B0 0x020307B0 arm
 */
#include "../include/Obj05123.h"
extern void GAME_BEACON_ACCESSOR_TableMarkLogsNew(unsigned char *p);
extern void GPOWER_FreePowerTable(void *);
typedef unsigned int   u32;
extern u32 func_020307B0(void *p);
void func_021F28DC(char *p)
{
    GAME_BEACON_ACCESSOR_TableMarkLogsNew(((struct Obj05123 *)p)->f38);
    GPOWER_FreePowerTable(((struct Obj05123 *)p)->f24);
    func_020307B0(((struct Obj05123 *)p)->f4C);
    func_020307B0(((struct Obj05123 *)p)->f44);
    func_020307B0(((struct Obj05123 *)p)->f40);
    func_020307B0(((struct Obj05123 *)p)->f38);
}
