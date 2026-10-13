/*
 * function: func_021BFCEC
 * address: 0x021BFCEC
 * packet: pkt_ov099_021BFCEC
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021BFBBC 0x021BFBBC thumb ov099
 *   func_021BA858 0x021BA858 thumb ov099
 *   func_021BA8EC 0x021BA8EC thumb ov099
 *   BMP_MENU_DeleteYesNo 0x0201FEF4 thumb
 *   DWC_RAP_GetTargetFriendIndex 0x02156A3C thumb ov009
 *   func_021BA874 0x021BA874 thumb ov099
 *   func_021BAAB8 0x021BAAB8 thumb ov099
 *   func_021BAADC 0x021BAADC thumb ov099
 */
#include "../include/Obj04416.h"
typedef unsigned char u8;
extern void func_021BFBBC(char *);
typedef unsigned int   u32;
extern u32 func_021BA858(char *p);
extern void func_021BA8EC(char *);
extern void BMP_MENU_DeleteYesNo(u8 *o);
extern int DWC_RAP_GetTargetFriendIndex(void);
extern void func_021BA874(char *, int);
extern void func_021BAAB8(char *, int, int);
extern void func_021BAADC(char *, int, int);
int func_021BFCEC(char *p, int ret)
{
    int v;
    func_021BFBBC(p);
    v = func_021BA858(p);
    if (v == -1) {
        if (((struct Obj04416 *)p)->f1355) {
            func_021BA8EC(p);
            BMP_MENU_DeleteYesNo(((struct Obj04416 *)p)->f108);
            ((struct Obj04416 *)p)->f108 = 0;
            func_021BA874(p, DWC_RAP_GetTargetFriendIndex());
            func_021BAAB8(p, 0x10, 0);
            ((struct Obj04416 *)p)->f1E0 = 0x3c;
            ((struct Obj04416 *)p)->f1CC = 0x94;
        }
    } else if (v == 0) {
        ((struct Obj04416 *)p)->f1CC = 0x92;
    } else {
        func_021BAADC(p, 0x7b, 0);
        ((struct Obj04416 *)p)->f1CC = 0x10;
    }
    return ret;
}
