/*
 * function: func_021D5C30
 * address: 0x021D5C30
 * packet: pkt_ov115_021D5C30
 * region: ov115
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: two zero padding bytes follow the return at 0x021D5C6E.
 * symbols:
 *   func_021D5B5C 0x021D5B5C thumb ov115
 *   TIME_ICON_Delete 0x0202F038 thumb
 *   func_020056BC 0x020056BC thumb
 *   TIME_ICON_Create 0x0202EE30 thumb
 */
#include "../include/Obj04466.h"
typedef unsigned char u8;
typedef unsigned short u16;
struct MsgBank;
extern void func_021D5B5C(char *p, struct MsgBank *a, int b);
extern void TIME_ICON_Delete(u8 *);
extern unsigned int func_020056BC(void);
extern u8 *TIME_ICON_Create(void *owner, void *a1, u8 a2, u8 a3, volatile u16 heap);
void func_021D5C30(u8 *p, unsigned int a, int b) {
    func_021D5B5C((char *)p, (struct MsgBank *)a, b);
    if (((struct Obj04466 *)p)->f80) {
        TIME_ICON_Delete(((struct Obj04466 *)p)->f80);
        ((struct Obj04466 *)p)->f80 = 0;
    }
    ((struct Obj04466 *)p)->f80 = TIME_ICON_Create((void *)func_020056BC(), ((struct Obj04466 *)p)->f2C, 15, 16, ((struct Obj04466 *)p)->f4C);
}
