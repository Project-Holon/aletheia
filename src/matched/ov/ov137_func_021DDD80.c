/*
 * function: func_021DDD80
 * address: 0x021DDD80
 * packet: pkt_ov137_021DDD80
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
 *   func_021DCBC4 0x021DCBC4 thumb ov137
 *   UNION_APP_GetMemberEntry 0x02184180 thumb ov022
 *   func_0201F02C 0x0201F02C thumb
 */
#include "../include/Obj04538.h"
#include "../include/Obj14215.h"
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int   u32;
typedef unsigned char  u8;
struct WordSet;
extern int func_021DE354(void *p);
extern unsigned func_021DE7F4(void);
extern void GFL_USE_PlaySeDefaultVolume(u32 a);
extern void func_021DD924(char *);
extern u32 BMP_MENU_ProcessYesNo(u8 *p);
extern void *func_021DCF50(u8 *p);
extern void UNION_APP_Open(u8 *p);
extern void func_021DCBC4(void *p, u32 a, const void *b, u32 c);
extern char *UNION_APP_GetMemberEntry(unsigned char *p, int i);
extern void func_0201F02C(struct WordSet *p, u32 i, void *a);
int func_021DDD80(char *p, int state) {
    char *q = *(char * *)&((struct Obj04538 *)p)->f10;
    unsigned result;
    if (((struct Obj14215 *)q)->f2C != func_021DE354(p) || ((struct Obj14215 *)q)->f30 != 0) {
        if (func_021DE7F4() & 0xc3) GFL_USE_PlaySeDefaultVolume(0x54c);
        func_021DD924(p);
        return state;
    }
    result = BMP_MENU_ProcessYesNo(((struct Obj04538 *)p)->fE8);
    if (result != -1) {
        if (result == -2) {
            ((struct Obj04538 *)p)->f118 = 0;
            UNION_APP_Open(func_021DCF50((u8 *)p));
        } else {
            ((struct Obj04538 *)p)->f118 = 0xd;
            func_021DCBC4(((struct Obj04538 *)p)->f10, 0x2802, 0, 0);
            func_0201F02C(((struct Obj04538 *)p)->f3C, 0, UNION_APP_GetMemberEntry(func_021DCF50((u8 *)p), 0));
        }
        ((struct Obj04538 *)p)->fE8 = 0;
    }
    func_021DD924(p);
    return state;
}
