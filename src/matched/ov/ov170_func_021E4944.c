/*
 * function: func_021E4944
 * address: 0x021E4944
 * packet: pkt_ov170_021E4944
 * region: ov170
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021DD530 0x021DD530 thumb ov170
 *   func_021EA1E8 0x021EA1E8 thumb ov170
 *   func_021EE3E4 0x021EE3E4 thumb ov170
 *   func_021EE038 0x021EE038 thumb ov170
 *   func_021EBC58 0x021EBC58 thumb ov170
 */
#include "../include/Obj00000.h"
#include "../include/Obj23901.h"
extern void func_020061E4(unsigned);
extern void func_021DD530(unsigned char *);
extern void func_021EA1E8(unsigned char *);
typedef unsigned char  u8;
struct Sound;
extern void func_020260E4(struct Sound *obj, u8 sel);
extern void func_021EE3E4(char **, unsigned);
extern void func_021EE038(char *, int, int, int);
extern void func_021EBC58(unsigned char *, int, int, int);
int func_021E4944(unsigned char *p)
{
    func_020061E4(0x667);
    func_021DD530(p);
    func_021EA1E8(p);
    func_020260E4(((struct Obj23901 *)(*(char * *)&((struct Obj00000 *)p)->f2C))->f70, 0x24);
    func_021EE3E4((char **)p, 0x24);
    func_021EE038((char *)p, 0, 0, 1);
    func_021EBC58(p, p[0x16], 1, 0x18);
    return 0x23;
}
