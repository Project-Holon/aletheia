/*
 * function: WIH_StateOutInitialize
 * address:  0x021791F8
 * packet:   pkt_ov014_021791F8
 * region:   ov014
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * WM_Initialize completion callback of the DWC WH copy: on an error result,
 * or when WIH_IndicateHandler's check fails, it sets the error state (10) and
 * calls the user callback at +0x1E64 of the work block with 0; otherwise it
 * sets state 1, calls WM_SetLifeTime with the unlabelled leaf DWCi_MOV_WH_StateOutSetLifeTime
 * and calls the user callback with 1.
 *
 * symbols:
 *   gWihWork     0x021797A8  data   ov014  a4
 *   WIH_ChangeSysState  0x02178138  thumb  ov014
 *   WIH_SetError  0x0217814C  thumb  ov014
 *   WIH_IndicateHandler  0x02179188  thumb  ov014
 *   DWCi_MOV_WH_StateOutSetLifeTime  0x021791EC  thumb  ov014
 *   WM_SetIndCallback  0x0208EAC8  arm
 *   WM_SetLifeTime  0x02090DEC  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef void (*Cb)(int);

extern u8 *gWihWork;

extern void WIH_ChangeSysState(int state);
extern void WIH_SetError(int err);
extern void WIH_IndicateHandler(u8 *p);
extern void DWCi_MOV_WH_StateOutSetLifeTime(void);
extern int WM_SetIndCallback(void (*f)(void));
extern void WM_SetLifeTime(void (*f)(void), int a, int b, int c, int d);

void WIH_StateOutInitialize(u16 *arg)
{
    Cb cb;

    int r;

    if (arg[1] != 0) {
        WIH_SetError(arg[1]);
        WIH_ChangeSysState(10);
        cb = *(Cb *)(gWihWork + 0x1E64);
        if (cb != 0)
            cb(0);
        return;
    }
    r = WM_SetIndCallback((void (*)(void))WIH_IndicateHandler);
    if (r != 0) {
        WIH_SetError(r);
        WIH_ChangeSysState(10);
        cb = *(Cb *)(gWihWork + 0x1E64);
        if (cb != 0)
            cb(0);
        return;
    }
    WIH_ChangeSysState(1);
    WM_SetLifeTime(DWCi_MOV_WH_StateOutSetLifeTime, 0xFFFF, 0x28, 5, 0x28);
    cb = *(Cb *)(gWihWork + 0x1E64);
    if (cb != 0)
        cb(1);
}
