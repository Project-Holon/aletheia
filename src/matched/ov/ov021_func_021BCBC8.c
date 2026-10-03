/*
 * function: func_021BCBC8
 * address:  0x021BCBC8
 * packet:   pkt_ov021_021BCBC8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_021BCB9C  0x021BCB9C  thumb  ov021
 *   _ffltu         0x0209BE04  arm
 *   _fdiv          0x0209CE10  arm
 *   _fmul          0x0209C77C  arm
 *   _ffix          0x0209C494  arm
 *   _fsub          0x0209CB8C  arm
 */

typedef unsigned short u16;
typedef unsigned int u32;

extern void func_021BCB9C(void *p, int keep);

void func_021BCBC8(char *p)
{
    int r6;
    int r5;

    switch (*(int *)(p + 0x3c)) {
    case 0:
    case 4:
    case 6:
        return;
    case 3:
    case 5:
        r6 = 5;
        r5 = 30;
        break;
    case 2:
        r6 = 6;
        r5 = (int)(20.0f * (1.0f - (float)(u32)*(u16 *)(p + 0x42) / 10.0f));
        break;
    case 1:
        r6 = 0;
        r5 = 0;
        break;
    }
    func_021BCB9C(p, r6);
    *(u16 *)(p + 0x42) = r5;
}
