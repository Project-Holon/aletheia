/*
 * function: func_021E7E54
 * address: 0x021E7E54
 * packet: pkt_ov170_021E7E54
 * region: ov170
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02025DE8 0x02025DE8 thumb
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   func_021EA908 0x021EA908 thumb ov170
 *   func_021DD2B4 0x021DD2B4 thumb ov170
 *   func_021DF11C 0x021DF11C thumb ov170
 *   func_021E94AC 0x021E94AC thumb ov170
 *   func_021E8FD0 0x021E8FD0 thumb ov170
 */
#include "../include/Obj00000.h"
#include "../include/Obj23925.h"
#include "../include/Obj23926.h"
typedef unsigned char u8;
typedef unsigned int u32;
struct Sound;
extern int func_02025DE8(struct Sound *obj);
extern void GFL_USE_PlaySeDefaultVolume(unsigned);
extern void func_021EA908(int p, int bit);
extern void func_021DD2B4(int a, int b, int c, int d, int e);
extern void func_021DF11C(char *p, int b);
extern int func_021E94AC(u8 *, int, int);
extern int func_021E8FD0(char *p, int a);
int func_021E7E54(u8 *p)
{
    u8 mask;
    switch ((unsigned)func_02025DE8(((struct Obj23925 *)(*(u8 * *)&((struct Obj00000 *)p)->f2C))->f70)) {
    case 0:
        GFL_USE_PlaySeDefaultVolume(0x54c);
        func_021EA908((int)p, 0);
        break;
    case 1:
        GFL_USE_PlaySeDefaultVolume(0x54c);
        func_021EA908((int)p, 1);
        break;
    case 2:
        GFL_USE_PlaySeDefaultVolume(0x54c);
        func_021EA908((int)p, 2);
        break;
    case 3:
        GFL_USE_PlaySeDefaultVolume(0x54c);
        func_021EA908((int)p, 3);
        break;
    case 4:
        GFL_USE_PlaySeDefaultVolume(0x54c);
        func_021EA908((int)p, 4);
        break;
    case 5:
        GFL_USE_PlaySeDefaultVolume(0x54c);
        func_021EA908((int)p, 5);
        break;
    case 6:
        mask = ((struct Obj23926 *)(*(u8 * *)&((struct Obj00000 *)p)->f2C))->fA174;
        func_021DD2B4((int)p, p[22], p[20], 11, mask);
        func_021DF11C((char *)p, (unsigned)mask);
        GFL_USE_PlaySeDefaultVolume(0x54c);
        return func_021E94AC(p, 0, 87);
    case 7:
        GFL_USE_PlaySeDefaultVolume(0x551);
        return func_021E94AC(p, 1, 87);
    case (unsigned)-2:
        GFL_USE_PlaySeDefaultVolume(0x551);
        return func_021E94AC(p, 1, 87);
    case (unsigned)-3:
        GFL_USE_PlaySeDefaultVolume(0x548);
        return func_021E8FD0((char *)p, 88);
    case (unsigned)-4:
        GFL_USE_PlaySeDefaultVolume(0x548);
        break;
    }
    return 86;
}
