/*
 * function: WIH_StateInInitialize
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
 * behind gWihWork +0x40 with completion callback WIH_StateOutInitialize.  Anything
 * but WM_ERRCODE_OPERATING goes to the error setter.  The unlabelled
 * follower at 021791EC (`movs r0,#1; bx` tail call to WIH_ChangeSysState) is why
 * the extent runs long.
 *
 * symbols:
 *   gWihWork     0x021797A8  data   ov014  a4
 *   WIH_ChangeSysState  0x02178138  thumb  ov014
 *   WIH_SetError  0x0217814C  thumb  ov014
 *   WIH_StateOutInitialize  0x021791F8  thumb  ov014
 *   WM_Initialize  0x0208F370  arm
 *   WM_InitializeForListening  0x0208F380  arm
 */

typedef unsigned char u8;
typedef int BOOL;

extern u8 *gWihWork;

extern void WIH_ChangeSysState(int state);
extern void WIH_SetError(int err);
typedef unsigned short u16;
extern void WIH_StateOutInitialize(u16 *arg);
extern int WM_Initialize(void *buf, void (*cb)(void *), int dma);
extern int WM_InitializeForListening(void *buf, void (*cb)(void *), int dma, int x);

BOOL WIH_StateInInitialize(int a, int flag)
{
    int r;

    WIH_ChangeSysState(3);
    if (flag == 0)
        r = WM_Initialize(gWihWork + 0x40, (void (*)(void *))WIH_StateOutInitialize, 2);
    else
        r = WM_InitializeForListening(gWihWork + 0x40, (void (*)(void *))WIH_StateOutInitialize, 2, 0);
    if (r != 2) {
        WIH_SetError(r);
        WIH_ChangeSysState(10);
        return 0;
    }
    return 1;
}
