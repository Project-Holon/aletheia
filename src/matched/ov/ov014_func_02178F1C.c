/*
 * function: WIH_StateInMeasureChannel
 * address:  0x02178F1C
 * packet:   pkt_ov014_02178F1C
 * region:   ov014
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   WIH_ChangeSysState  0x02178138  thumb  ov014
 *   WIH_SetError  0x0217814C  thumb  ov014
 *   WIH_StateOutMeasureChannel  0x02178F8C  thumb  ov014
 *   func_02179010  0x02179010  thumb  ov014
 *   func_0208EE60  0x0208EE60  arm
 */

typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;

void WIH_ChangeSysState(int a);
void WIH_SetError(int a);
void WIH_StateOutMeasureChannel(u8 *m);
int func_02179010(void *cb, int n);
u16 func_0208EE60(void);

int WIH_StateInMeasureChannel(u16 n)
{
    u32 m = func_0208EE60();

    if (m == 0x8000) {
        WIH_SetError(3);
        WIH_ChangeSysState(9);
        return 3;
    }
    if (m == 0) {
        WIH_SetError(0x16);
        WIH_ChangeSysState(9);
        return 0x18;
    }
    if (!((1 << (n - 1)) & m)) {
        do {
            n = n + 1;
            if (n > 0x10)
                return 0x18;
        } while (!((1 << (n - 1)) & m));
    }
    return (u16)func_02179010((void *)WIH_StateOutMeasureChannel, n);
}
