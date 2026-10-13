/*
 * function: func_021791A0
 * address:  0x021791A0
 * packet:   pkt_ov014_021791A0
 * region:   ov014
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * The DWC copy of WH_Initialize's WM start: WM_Initialize (0208F370) or, when
 * the flag is set, WM_InitializeForListening (0208F380), on the work block
 * behind g_021797A8 +0x40 with completion callback func_021791F8.  Anything
 * but WM_ERRCODE_OPERATING goes to the error setter.  The unlabelled
 * follower at 021791EC (`movs r0,#1; bx` tail call to func_02178138) is why
 * the extent runs long.
 *
 * symbols:
 *   g_021797A8     0x021797A8  data   ov014  a4
 *   func_02178138  0x02178138  thumb  ov014
 *   func_0217814C  0x0217814C  thumb  ov014
 *   func_021791F8  0x021791F8  thumb  ov014
 *   WM_Initialize  0x0208F370  arm
 *   WM_InitializeForListening  0x0208F380  arm
 */

typedef unsigned char u8;
typedef int BOOL;

extern u8 *g_021797A8;

extern void func_02178138(int state);
extern void func_0217814C(int err);
typedef unsigned short u16;
extern void func_021791F8(u16 *arg);
extern int WM_Initialize(void *buf, void (*cb)(void *), int dma);
extern int WM_InitializeForListening(void *buf, void (*cb)(void *), int dma, int x);

BOOL func_021791A0(int a, int flag)
{
    int r;

    func_02178138(3);
    if (flag == 0)
        r = WM_Initialize(g_021797A8 + 0x40, (void (*)(void *))func_021791F8, 2);
    else
        r = WM_InitializeForListening(g_021797A8 + 0x40, (void (*)(void *))func_021791F8, 2, 0);
    if (r != 2) {
        func_0217814C(r);
        func_02178138(10);
        return 0;
    }
    return 1;
}
