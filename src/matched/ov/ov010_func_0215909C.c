/*
 * function: SCRIPT_WORK_BackupLocalWork
 * address: 0x0215909C
 * packet: pkt_ov010_0215909C
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   SCRIPT_WORK_GetLocalWork 0x02158FD0 thumb ov010
 *   func_02082A60 0x02082A60 arm
 *   func_02030734 0x02030734 arm
 *   sScriptWorkFileName 0x0217289C data a1
 */
#include "../include/Obj18755.h"
typedef unsigned short u16;
typedef unsigned char u8;
extern void *SCRIPT_WORK_GetLocalWork(void *, unsigned int);
extern void func_02082A60(const void *, void *, unsigned int);
extern void *func_02030734(unsigned int, unsigned int, int, const char *, u16);
extern const char sScriptWorkFileName[];
void *SCRIPT_WORK_BackupLocalWork(u8 *a)
{
    void *p = func_02030734(((struct Obj18755 *)a)->fC, 0x7e, 1, sScriptWorkFileName, 0x21b);
    func_02082A60(SCRIPT_WORK_GetLocalWork(a, 0x8020), p, 0x7e);
    return p;
}
