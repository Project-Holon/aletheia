/*
 * function: CameraWaitBusy
 * address:  0x02702028
 * packet:   twl_sys
 * region:   twl
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT*
 *
 * symbols:
 *   data_02732FC8  0x02732FC8  data twl a2
 *   data_04000208  0x04000208  data twl a2
 *   func_020879E0  0x020879E0  arm twl a2
 *   func_02088688  0x02088688  arm twl a2
 */

typedef unsigned int u32;
typedef unsigned short u16;

extern u32 data_02732FC8[];
extern u16 data_04000208;
extern u32 func_020879E0(void);
extern void func_02088688(void);

void CameraWaitBusy(void) {
    if (data_02732FC8[0] == 0) {
        return;
    }
    do {
        u32 mode = func_020879E0();
        if (mode == 0x80 || data_04000208 == 0) {
            func_02088688();
        }
    } while (data_02732FC8[0] != 0);
}
