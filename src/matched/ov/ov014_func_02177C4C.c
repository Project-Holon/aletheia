/*
 * function: NET_WHPIPE_TaskConnectParent
 * address:  0x02177C4C
 * packet:   pkt_ov014_02177C4C
 * region:   ov014
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   g_pWhPipeWork     0x021797A4  data   a4
 *   g_ParentConnectModes     0x0217967C  data   a2
 *   func_02178E4C  0x02178E4C  thumb  ov014
 *   GFL_NET_GetInitParam  0x0203D798  arm
 *   func_02179024  0x02179024  thumb  ov014
 *   func_0208F1B4  0x0208F1B4  arm
 *   func_0217778C  0x0217778C  thumb  ov014
 *   func_02179288  0x02179288  thumb  ov014
 *   func_0217727C  0x0217727C  thumb  ov014
 */
#include "../include/Obj03088.h"
#include "../include/G_W.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern struct W *g_pWhPipeWork;
extern u16 g_ParentConnectModes[2];
extern int func_02178E4C(void);
extern void *GFL_NET_GetInitParam(void);
extern u16 func_02179024(void);
extern u16 func_0208F1B4(void);
extern void func_0217778C(void);
extern int func_02179288(int mode, u16 a, int b, u16 c);
extern void func_0217727C(u32 *p, u32 v);

void NET_WHPIPE_TaskConnectParent(u8 *p)
{
    u16 buf[2];
    u8 *st;
    int r6;

    int mode = func_02178E4C();

    buf[0] = g_ParentConnectModes[0];
    buf[1] = g_ParentConnectModes[1];
    if (mode == 7) {
        st = GFL_NET_GetInitParam();
        p[0xCEA] = 0;
        p[0xCEF] = 0;
        p[0xCE9] = 0;
        p[0xCE8] = 0;
        r6 = func_02179024();
        if (p[0xCE6] == 0xFF)
            p[0xCE6] = r6;
        else
            r6 = p[0xCE6];
        if (st[0x66] != 0)
            ((struct Obj03088 *)p)->fC68 = func_0208F1B4();
        func_0217778C();
        func_02179288(buf[st[0x64]], ((struct Obj03088 *)p)->fC68, r6, st[0x60] - 1);
        func_0217727C((u32 *)((u8 *)g_pWhPipeWork), 0);
    }
}
