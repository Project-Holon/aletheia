/*
 * function: func_021C4E6C
 * address:  0x021C4E6C
 * packet:   pkt_ov021_021C4E6C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Same HSV-to-RGB shape as arm9 func_02011B8C: three 4.12 channels from
 * func_02011638, wrapped into [0,360), rescaled to 0..65535, handed to
 * func_020520FC.
 *
 * symbols:
 *   _fdiv          0x0209CE10  arm
 *   _fflt          0x0209BDBC  arm
 *   _ffixu         0x0209C4C8  arm
 *   _fls           0x0209BC74  arm
 *   _fmul          0x0209C77C  arm
 *   _fadd          0x0209C95C  arm
 *   func_02011638  0x02011638  thumb
 *   func_0207ADC4  0x0207ADC4  arm
 *   func_020520FC  0x020520FC  arm
 */

typedef unsigned short u16;
typedef unsigned int   u32;
typedef int            s32;

extern int func_02011638(void *ctx, s32 *hsv);
extern void func_0207ADC4(void *p);
extern void func_020520FC(u16 h, u16 s, u16 v, void *out);

void func_021C4E6C(char *p)
{
    s32 hsv[3];
    u16 ch;
    u16 cs;
    u16 cv;
    float h;
    float s;
    float v;

    if (*(void **)(p + 0x10) == 0) {
        return;
    }
    if (func_02011638(*(void **)(p + 0x10), hsv) != 1) {
        return;
    }

    h = hsv[0] / 4096.0f;
    s = hsv[1] / 4096.0f;
    v = hsv[2] / 4096.0f;

    while (h < 0.0f) {
        h += 360.0f;
    }
    while (s < 0.0f) {
        s += 360.0f;
    }
    while (v < 0.0f) {
        v += 360.0f;
    }

    ch = (u16)(u32)(65535.0f * (h / 360.0f));
    cs = (u16)(u32)(65535.0f * (s / 360.0f));
    cv = (u16)(u32)(65535.0f * (v / 360.0f));
    func_0207ADC4(*(char **)(p + 0x14) + 0x18);
    func_020520FC(ch, cs, cv, *(char **)(p + 0x14) + 0x18);
}
