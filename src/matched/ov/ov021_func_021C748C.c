/*
 * function: func_021C748C
 * address:  0x021C748C
 * packet:   pkt_ov021_021C748C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   _ffltu         0x0209BE04  arm
 *   func_021C734C  0x021C734C  thumb  ov021
 *   func_0216D410  0x0216D410  thumb  ov010
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct {
    u32 w0;
    u32 w4;
    u16 h8;
    u16 ha;
    u8  bc;
    u8  pad;
    u16 he;
} Ctl;

extern u16 func_021C734C(float a, float b, float c);
extern void func_0216D410(u32 a, int b);

int func_021C748C(Ctl *o)
{
    u32 s;
    int k;

    s = o->w4;
    func_0216D410(s, func_021C734C((float)(u32)o->h8, (float)(u32)o->ha, (float)(u32)o->bc));
    o->h8 = o->h8 + 1;
    if (o->ha < o->h8) {
        switch (o->he) {
        default:
        case 0: k = 0; break;
        case 1: k = 1; break;
        case 2: k = 2; break;
        case 3: k = 3; break;
        }
        func_0216D410(s, k);
        return 1;
    }
    return 0;
}
