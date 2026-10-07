/*
 * file:     unit_021F1B3C_p02.c
 * unit:     yes
 * function: func_021F1D0C, func_021F1D58
 * address:  0x021F1D0C
 * region:   ov107
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   g_021F6FA0  0x021F6FA0  data
 *   func_021F2EE8  0x021F2EE8  arm  ov107
 *   func_021F1D58  0x021F1D58  arm  ov107
 *   mbc   0x021F6FA0  data
 */
typedef unsigned short u16;

typedef void (*WMCallback)(u16 child, int state, void *arg);

extern int func_021F2EE8(unsigned short child_aid);
extern void func_021F1D58(unsigned short child, int state, void *arg);
void func_021F1D0C(unsigned short child, int state, void *arg);
void MBi_CommChangeParentStateCallbackOnly(u16 child, int state, void *arg);
extern char *g_021F6FA0;
extern void *mbc;


/*
 * sdk:      MBi_CommChangeParentState (libmb.TWL.HYB.a(mb_parent.o))
 */
void func_021F1D0C(unsigned short child, int state, void *arg)
{
    if (func_021F2EE8(child))
        ((int *)(g_021F6FA0 + 0x14E8))[child - 1] = state;
    func_021F1D58(child, state, arg);
}


void MBi_CommChangeParentStateCallbackOnly(u16 child, int state, void *arg)
{
    WMCallback callback = *(WMCallback *)((char *)mbc + 0x14E4);

    if (callback)
        callback(child, state, arg);
}
