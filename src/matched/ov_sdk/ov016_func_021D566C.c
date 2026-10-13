/*
 * function: func_021D566C
 * address:  0x021D566C
 * packet:   pkt_ov016_021D566C
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      taskFade (libdwcutil.TWL.HYB.a(effect.o))
 *
 * symbols:
 *   FX_DivS32 0x0207C958 arm
 *   DWCi_WindowG2x_ChangeBlendBrightness_ 0x0207D6C0 arm
 *   DWCi_TSKlDelete 0x021D7724 arm ov016
 *   sEffectTable2 0x021DAA68 data
 *   sEffectTable1 0x021DAA64 data
 *   g_021DE67C 0x021DE67C data
 */

#include "../include/G_MEMEFFECT.h"

typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned long u32;

typedef struct {
    char pad0[4];
    s16 count;
    u16 max;
    u8 index;
    u8 active;
} Prm;

typedef struct { u8 b[4]; } U4;
typedef struct { s8 b[4]; } S4;

extern U4 sEffectTable2;
extern S4 sEffectTable1;
extern struct MEMEFFECT *g_021DE67C;

extern long FX_DivS32(long a, long b);
extern void DWCi_WindowG2x_ChangeBlendBrightness_(u32 addr, int brightness);
extern void DWCi_TSKlDelete(int kind, void *task);

void func_021D566C(void *task, void *work)
{
    U4 TABLE = sEffectTable2;
    S4 BRIGHT = sEffectTable1;
    Prm *prm = (Prm *)work;
    int value;

    prm->count++;
    value = FX_DivS32(prm->count * 16, prm->max);
    if (TABLE.b[prm->index] & 1)
        value = 16 - value;
    if (TABLE.b[prm->index] & 0x10)
        value = -value;
    if (prm == ((Prm *)g_021DE67C))
        DWCi_WindowG2x_ChangeBlendBrightness_(0x04001050, value);
    else
        DWCi_WindowG2x_ChangeBlendBrightness_(0x04000050, value);
    if (prm->count < prm->max)
        return;
    if (prm == ((Prm *)g_021DE67C))
        DWCi_WindowG2x_ChangeBlendBrightness_(0x04001050, BRIGHT.b[prm->index]);
    else
        DWCi_WindowG2x_ChangeBlendBrightness_(0x04000050, BRIGHT.b[prm->index]);
    prm->active = 0;
    DWCi_TSKlDelete(1, task);
}
