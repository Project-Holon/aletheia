/*
 * function: func_021DDBE8
 * address: 0x021DDBE8
 * packet: pkt_ov137_021DDBE8
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021DE354 0x021DE354 thumb ov137
 *   func_021DE7F4 0x021DE7F4 thumb ov137
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   func_021DD924 0x021DD924 thumb ov137
 *   BMP_MENU_ProcessYesNo 0x0201FEBC thumb
 *   func_021DCF50 0x021DCF50 thumb ov137
 *   UNION_APP_Open 0x02184134 thumb ov022
 *   GFL_NET_SYSTEM_GetCurrentAid 0x02039338 arm
 */
#include "../include/Obj05426.h"
#include "../include/Obj14212.h"
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int   u32;
typedef unsigned char  u8;
extern int func_021DE354(void *p);
extern unsigned func_021DE7F4(void);
extern void GFL_USE_PlaySeDefaultVolume(u32 a);
extern void func_021DD924(char *);
extern u32 BMP_MENU_ProcessYesNo(u8 *p);
extern void *func_021DCF50(u8 *p);
extern void UNION_APP_Open(u8 *p);
extern u16 GFL_NET_SYSTEM_GetCurrentAid(void);
int func_021DDBE8(char *p, int state) {
    char *q = *(char * *)&((struct Obj05426 *)p)->f10;
    unsigned result;
    if (((struct Obj14212 *)q)->f2C != func_021DE354(p) || ((struct Obj14212 *)q)->f30 != 0) {
        if (func_021DE7F4() & 0xc3) GFL_USE_PlaySeDefaultVolume(0x548);
        func_021DD924(p);
        return state;
    }
    result = BMP_MENU_ProcessYesNo(((struct Obj05426 *)p)->fE8);
    if (result != -1) {
        if (result == -2) {
            UNION_APP_Open(func_021DCF50((u8 *)p));
            ((struct Obj05426 *)p)->f118 = 0;
        } else {
            if (GFL_NET_SYSTEM_GetCurrentAid() == 0) {
                ((struct Obj05426 *)p)->f118 = 0x18;
                ((struct Obj05426 *)p)->f4812 = func_021DE354(p);
            }
        }
        ((struct Obj05426 *)p)->fE8 = 0;
    }
    func_021DD924(p);
    return state;
}
