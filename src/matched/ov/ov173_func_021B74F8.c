/*
 * function: func_021B74F8
 * address: 0x021B74F8
 * packet: pkt_ov173_021B74F8
 * region: ov173
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02006238 0x02006238 thumb
 *   func_020061E4 0x020061E4 thumb
 *   GFL_USE_SetBgmPlayerParam 0x02005DE4 thumb
 *   GFL_USE_PushBgm 0x02005E64 thumb
 *   GFL_USE_CancelChangeAndPlayBgm 0x02005D90 thumb
 *   func_02005F38 0x02005F38 thumb
 *   GFL_USE_PopBgm 0x02005E9C thumb
 */
extern int func_02006238(void);
extern void func_020061E4(unsigned int);
extern void GFL_USE_SetBgmPlayerParam(void *p);
extern int GFL_USE_PushBgm(void);
extern void GFL_USE_CancelChangeAndPlayBgm(unsigned int, unsigned int);
extern int func_02005F38(void);
extern int GFL_USE_PopBgm(void);
int func_021B74F8(unsigned int state)
{
    switch (state) {
    case 1: return func_02006238();
    case 2: return func_02006238();
    case 3: func_020061E4(0x56b); break;
    case 4:
        GFL_USE_SetBgmPlayerParam((void *)1);
        GFL_USE_PushBgm();
        GFL_USE_CancelChangeAndPlayBgm(0x515, 0xffff);
        break;
    case 5:
        if (func_02005F38() == 0) {
            GFL_USE_PopBgm();
            GFL_USE_SetBgmPlayerParam(0);
        } else {
            return 1;
        }
        break;
    }
    return 0;
}
