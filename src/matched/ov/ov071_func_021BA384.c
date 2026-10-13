/*
 * function: MONOLITH_TOOL_ExitInfoScreen
 * address: 0x021BA384
 * packet: pkt_ov071_021BA384
 * region: ov071
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0201C6B4 0x0201C6B4 thumb
 *   func_02043534 0x02043534 arm
 *   func_020315D4 0x020315D4 arm
 *   MONOLITH_TOOL_DeleteInfoWindows 0x021BA4D4 thumb ov071
 *   MONOLITH_TOOL_HideInfoBgs 0x021BA400 thumb ov071
 */
#include "../include/Obj20762.h"
#include "../include/Obj20763.h"

typedef unsigned int u32;
struct PrintSys;
struct S020315D4;
extern u32 func_0201C6B4(const struct PrintSys *);
extern void func_02043534(unsigned int);
extern void func_020315D4(struct S020315D4 *);
extern void MONOLITH_TOOL_DeleteInfoWindows(void **);
extern void MONOLITH_TOOL_HideInfoBgs(void);

int MONOLITH_TOOL_ExitInfoScreen(void *a, void *b, char *c, void **d)
{
    if (func_0201C6B4(((struct Obj20763 *)(*(char * *)&((struct Obj20762 *)c)->f4))->f8) == 0) return 0;
    func_02043534(8);
    MONOLITH_TOOL_DeleteInfoWindows(d);
    MONOLITH_TOOL_HideInfoBgs();
    func_020315D4(a);
    return 1;
}
