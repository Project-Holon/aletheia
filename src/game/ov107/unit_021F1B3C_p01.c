/*
 * file:     unit_021F1B3C_p01.c
 * unit:     yes
 * function: func_021F1B3C, func_021F1B64, func_021F1BE0, func_021F1C30
 * address:  0x021F1B3C
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
 *   mbc   0x021F6FA0  data
 *   g_021F6FA0  0x021F6FA0  data
 *   func_02087988  0x02087988  arm
 *   func_0208799C  0x0208799C  arm
 *   func_02082D44  0x02082D44  arm
 *   func_021F2EE8  0x021F2EE8  arm  ov107
 */
typedef unsigned long u32;

typedef void (*WMCallback)(u32, void *);

extern u32 OS_DisableInterrupts(void);
extern void OS_RestoreInterrupts(u32 enabled);
extern unsigned long func_02087988(void);
extern unsigned long func_0208799C(unsigned long state);
extern void func_02082D44(void *srcp, void *dstp, unsigned long size);
extern int func_021F2EE8(unsigned short child_aid);
void MB_CommSetChildStateCallback(WMCallback callback);
void *func_021F1B64(unsigned short child_aid);
int func_021F1BE0(unsigned short child_aid);
int func_021F1C30(unsigned short child_aid, int ack);
extern void *mbc;
extern char *g_021F6FA0;


void MB_CommSetChildStateCallback(WMCallback callback)
{
    u32 enabled;

    enabled = OS_DisableInterrupts();
    *(WMCallback *)((char *)mbc + 0x14E4) = callback;
    OS_RestoreInterrupts(enabled);
}


/*
 * sdk:      MB_CommGetChildUser (libmb.TWL.HYB.a(mb_parent.o))
 */
void *func_021F1B64(unsigned short child_aid)
{
    unsigned long enabled = func_02087988();

    if (g_021F6FA0 && func_021F2EE8(child_aid)) {
        func_02082D44(g_021F6FA0 + 0x1340 + (child_aid - 1) * 22, g_021F6FA0 + 0x1772, 0x16);
        func_0208799C(enabled);
        return g_021F6FA0 + 0x1772;
    }
    func_0208799C(enabled);
    return 0;
}


/*
 * sdk:      MB_CommIsBootable (libmb.TWL.HYB.a(mb_parent.o))
 */
int func_021F1BE0(unsigned short child_aid)
{
    if (g_021F6FA0 && func_021F2EE8(child_aid)) {
        if (((int *)(g_021F6FA0 + 0x14E8))[child_aid - 1] == 7)
            return 1;
    }
    return 0;
}


/*
 * sdk:      MB_CommResponseRequest (libmb.TWL.HYB.a(mb_parent.o))
 */
int func_021F1C30(unsigned short child_aid, int ack)
{
    unsigned short req;
    int state;
    unsigned long enabled;

    enabled = func_02087988();

    switch (ack) {
    case 0:
        state = 10;
        req = 4;
        break;
    case 1:
        state = 10;
        req = 3;
        break;
    case 2:
        state = 14;
        req = 2;
        break;
    case 3:
        state = 7;
        req = 5;
        break;
    default:
        func_0208799C(enabled);
        return 0;
    }
    if (g_021F6FA0 && func_021F2EE8(child_aid)) {
        if (state == ((int *)(g_021F6FA0 + 0x14E8))[child_aid - 1]) {
            *(unsigned short *)(g_021F6FA0 + 0x1754 + (child_aid - 1) * 2) = req;
            func_0208799C(enabled);
            return 1;
        }
    }
    func_0208799C(enabled);
    return 0;
}
