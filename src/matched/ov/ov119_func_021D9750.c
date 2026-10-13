/*
 * function: func_021D9750
 * address: 0x021D9750
 * packet: pkt_ov119_021D9750
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   MSGDATA_ReadString 0x02045CAC arm
 *   func_021E1024 0x021E1024 thumb ov119
 *   func_021E1030 0x021E1030 thumb ov119
 *   func_021D8E84 0x021D8E84 thumb ov119
 *   func_021D9670 0x021D9670 thumb ov119
 */
#include "../include/Obj00001.h"
typedef unsigned int   u32;
struct MsgBank;
extern void MSGDATA_ReadString(struct MsgBank *bank, u32 index, void *dest);
extern void func_021E1024(void *);
extern void func_021E1030(char *p);
extern void func_021D8E84(void *, int);
extern void func_021D9670(char *p);
void func_021D9750(char *p)
{
    MSGDATA_ReadString((struct MsgBank *)(*(int *)&((struct Obj00001 *)p)->f720), 6, (void *)(*(int *)&((struct Obj00001 *)p)->f738));
    func_021E1024(p);
    func_021E1030(p);
    func_021D8E84(p, (int)func_021D9670);
}
