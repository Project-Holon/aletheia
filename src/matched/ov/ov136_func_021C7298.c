/*
 * function: MB_SEQ_SetButtonsEnabled
 * address: 0x021C7298
 * packet: pkt_ov136_021C7298
 * region: ov136
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * volatile: hardware register write at 021C7302 (0x04000050).
 * symbols:
 *   MB_SEQ_SetActorObjMode 0x021C670C thumb ov136
 *   func_0207D63C 0x0207D63C arm
 */
typedef unsigned char  u8;
extern void MB_SEQ_SetActorObjMode(u8 *p, int i, int on);
extern void func_0207D63C(void *, int, int, int, int);
void MB_SEQ_SetButtonsEnabled(void *p, int v)
{
    if (v == 1) {
        MB_SEQ_SetActorObjMode(p, 0, 1);
        MB_SEQ_SetActorObjMode(p, 1, 1);
        MB_SEQ_SetActorObjMode(p, 3, 1);
        MB_SEQ_SetActorObjMode(p, 7, 1);
        func_0207D63C((void *)0x04000050, 4, 8, 4, 12);
    } else {
        MB_SEQ_SetActorObjMode(p, 0, 0);
        MB_SEQ_SetActorObjMode(p, 1, 0);
        MB_SEQ_SetActorObjMode(p, 3, 0);
        MB_SEQ_SetActorObjMode(p, 7, 0);
        *(volatile unsigned short *)0x04000050 = 0;
    }
}
