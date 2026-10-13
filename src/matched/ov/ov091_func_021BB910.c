/*
 * function: PLIST_MESSAGE_StreamCallback
 * address:  0x021BB910
 * packet:   pkt_ov091_021BB910
 * region:   ov091
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   GFL_USE_SetBgmPlayerParam  0x02005DE4  thumb
 *   GFL_USE_PushBgm  0x02005E64  thumb
 *   GFL_USE_CancelChangeAndPlayBgm  0x02005D90  thumb
 *   func_020061E4  0x020061E4  thumb
 *   func_02005F38  0x02005F38  thumb
 *   GFL_USE_PopBgm  0x02005E9C  thumb
 *   func_02006238  0x02006238  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void GFL_USE_SetBgmPlayerParam(void *p);
extern int GFL_USE_PushBgm(void);
extern void GFL_USE_CancelChangeAndPlayBgm(int a, int b);
extern void func_020061E4(u32 a);
extern int func_02005F38(void);
extern int GFL_USE_PopBgm(void);
extern int func_02006238(void);

int PLIST_MESSAGE_StreamCallback(int k)
{
    switch (k) {
    case 2:
        GFL_USE_SetBgmPlayerParam((void *)1);
        GFL_USE_PushBgm();
        GFL_USE_CancelChangeAndPlayBgm(0x515, 0xffff);
        break;
    case 3:
        func_020061E4(0x56b);
        break;
    case 5:
        if (func_02005F38() == 0) {
            GFL_USE_PopBgm();
            GFL_USE_SetBgmPlayerParam(0);
            return 0;
        }
        return 1;
    case 6:
        return func_02006238();
    }
    return 0;
}
