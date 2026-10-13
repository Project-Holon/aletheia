/*
 * function: func_021C7A0C
 * address:  0x021C7A0C
 * packet:   pkt_ov016_021C7A0C
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      procWin1 (libdwcutil.TWL.HYB.a sceneseteditaddress.o)
 *
 * symbols:
 *   DWCi_WINlIsInit  0x021D157C  arm  ov016
 *   DWCi_ChangeScene  0x021C0E40  arm  ov016
 *   DWCi_GetParam2_  0x021C0EA0  arm  ov016
 *   sSceneSetEditAddressDefaultGetters     0x021DB4DC  data
 *   gMemSsea     0x021DE5E4  data
 *   func_021C7314  0x021C7314  arm  ov016
 *   func_021C77F4  0x021C77F4  arm  ov016
 */

#include "../include/G_MemSsea.h"

typedef struct GXOamAttr {
    unsigned int attr01;
    unsigned short attr2;
    unsigned short attr3;
} GXOamAttr;

typedef struct MemSsea MemSsea;

typedef struct FuncTable {
    void (*f[5])(char *);
} FuncTable;

extern int DWCi_WINlIsInit();
extern void DWCi_ChangeScene(unsigned int v);
extern void DWCi_GetParam2_(unsigned int *a, unsigned int *b);
extern void func_021C7314();
extern void func_021C77F4();
extern struct MemSsea *gMemSsea;
extern FuncTable sSceneSetEditAddressDefaultGetters;

void func_021C7A0C(void)
{
    FuncTable FUNC = sSceneSetEditAddressDefaultGetters;
    int prm;

    if (DWCi_WINlIsInit())
        return;
    if (gMemSsea->result == 0) {
        ((GXOamAttr *)gMemSsea->caret)->attr01 &= 0xC1FFFCFF;
        DWCi_ChangeScene((unsigned int)func_021C7314);
        return;
    }
    DWCi_GetParam2_((unsigned int *)(&prm), 0);
    FUNC.f[prm]((char *)gMemSsea + 8);
    DWCi_ChangeScene((unsigned int)func_021C77F4);
}
