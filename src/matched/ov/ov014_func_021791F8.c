/*
 * function: func_021791F8
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
 * or when func_02179188's check fails, it sets the error state (10) and
 * calls the user callback at +0x1E64 of the work block with 0; otherwise it
 * sets state 1, calls func_02090DEC with the unlabelled leaf func_021791EC
 * and calls the user callback with 1.
 *
 * symbols:
 *   g_021797A8     0x021797A8  data   ov014  a4
 *   func_02178138  0x02178138  thumb  ov014
 *   func_0217814C  0x0217814C  thumb  ov014
 *   func_02179188  0x02179188  thumb  ov014
 *   func_021791EC  0x021791EC  thumb  ov014
 *   func_0208EAC8  0x0208EAC8  arm
 *   func_02090DEC  0x02090DEC  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef void (*Cb)(int);

extern u8 *g_021797A8;

extern void func_02178138(int state);
extern void func_0217814C(void);
extern void func_02179188(void);
extern void func_021791EC(void);
extern int func_0208EAC8(void (*f)(void));
extern void func_02090DEC(void (*f)(void), int a, int b, int c, int d);

void func_021791F8(u16 *arg)
{
    Cb cb;

    if (arg[1] != 0) {
        func_0217814C();
        func_02178138(10);
        cb = *(Cb *)(g_021797A8 + 0x1E64);
        if (cb != 0)
            cb(0);
        return;
    }
    if (func_0208EAC8(func_02179188) != 0) {
        func_0217814C();
        func_02178138(10);
        cb = *(Cb *)(g_021797A8 + 0x1E64);
        if (cb != 0)
            cb(0);
        return;
    }
    func_02178138(1);
    func_02090DEC(func_021791EC, 0xFFFF, 0x28, 5, 0x28);
    cb = *(Cb *)(g_021797A8 + 0x1E64);
    if (cb != 0)
        cb(1);
}
