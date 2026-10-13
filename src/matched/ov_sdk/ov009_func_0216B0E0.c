/*
 * function: DWC_LoginAsync
 * address:  0x0216B0E0
 * packet:   pkt_ov009_0216B0E0
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWC_LoginAsync (libdwcmatch.TWL.HYB.a(dwc_main.o))
 *
 * symbols:
 *   func_02059F38  0x02059F38  arm
 *   MIi_CpuClear16 0x02082A48  arm
 *   func_021686E0  0x021686E0  arm  ov009
 *   MIi_CpuCopy16  0x02082A60  arm
 *   func_0205CA20  0x0205CA20  arm
 *   func_0216A3B8  0x0216A3B8  arm  ov009
 *   DWCi_SetState  0x0216BC84  arm  ov009
 *   func_0217C750  0x0217C750  arm  ov009
 *   g_021AA878     0x021AA878  data
 */

#include "../include/G_DwcGlobal.h"

typedef unsigned short u16;
typedef unsigned long u32;

typedef struct {
    char pad0[0x24];
    int state;
    char pad28[8];
    u16 ingamesn[0x1a];
    char pad64[4];
    char *gamename;
    char pad6c[4];
    void (*callback)(int, int, void *);
    void *param;
} Ctl;

extern struct DwcGlobal g_021AA878;

extern int func_02059F38(void);
extern void MIi_CpuClear16(u16 data, void *destp, u32 size);
extern int func_021686E0(unsigned short *p);
extern void MIi_CpuCopy16(void *srcp, void *destp, u32 size);
extern int func_0205CA20(void);
extern void func_0216A3B8(int error, int errorCode);
extern void DWCi_SetState(int state);
extern void func_0217C750(char *gamename);

int DWC_LoginAsync(u16 *ingamesn, int reserved, void (*callback)(int, int, void *), void *param)
{
    u32 len;

    if (!ingamesn)
        return 0;
    if (func_02059F38() || ((Ctl *)g_021AA878.st)->state != 0)
        return 0;
    ((Ctl *)g_021AA878.st)->callback = callback;
    ((Ctl *)g_021AA878.st)->param = param;
    if (!ingamesn || ingamesn[0] == 0) {
        len = 0;
    } else {
        MIi_CpuClear16(0, ((Ctl *)g_021AA878.st)->ingamesn, 0x34);
        len = (u32)func_021686E0(ingamesn) > 25 ? 25 : (u32)func_021686E0(ingamesn);
        MIi_CpuCopy16(ingamesn, ((Ctl *)g_021AA878.st)->ingamesn, len * 2);
    }
    ((Ctl *)g_021AA878.st)->ingamesn[len] = 0;
    if (func_0205CA20() != 4) {
        func_0216A3B8(2, -60010);
        return 0;
    }
    DWCi_SetState(1);
    func_0217C750(((Ctl *)g_021AA878.st)->gamename);
    return 1;
}
