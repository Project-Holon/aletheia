/*
 * function: func_021EF634
 * address:  0x021EF634
 * packet:   pkt_ov025_021EF634
 * region:   ov025
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * note:     Remainder of handed extent is rodata after return at 021EF75A.
 *           Caller explicitly supplies idx in r1 to func_021A21C8.
 * symbols:
 *   func_020056EC 0x020056EC thumb
 *   func_0204B908 0x0204B908 arm
 *   func_021A21B8 0x021A21B8 thumb ov021
 *   func_021A21C8 0x021A21C8 thumb ov021
 *   func_021A2630 0x021A2630 thumb ov021
 *   func_021A2638 0x021A2638 thumb ov021
 *   func_021A2654 0x021A2654 thumb ov021
 */

typedef unsigned short u16;
typedef unsigned int u32;
typedef signed short s16;

extern u32 func_020056EC(u32);
extern void func_0204B908(int, u16);
extern int *func_021A21B8(int *);
extern unsigned char *func_021A21C8(int *, int);
extern unsigned char *func_021A2630(unsigned char *);
extern u32 func_021A2638(unsigned char *);
extern void func_021A2654(int, unsigned short *);

void func_021EF634(int *a, int n, int idx)
{
    int i;
    unsigned char *obj;
    int r;
    int *e;
    int h;
    int s;
    int m;
    int x;
    int d;
    int y;
    s16 pt[2];

    func_021A21B8(a);
    for (i = 0; i < n; i++) {
        obj = func_021A21C8(a, idx);
        if (obj == 0) {
            return;
        }
        e = (int *)func_021A2630(obj);
        h = func_021A2638(obj);
        r = func_020056EC(0);
        s = func_020056EC(0);
        e[0] = 0;
        e[1] = r % 5 + 7;
        if (r % 2 == 0) {
            e[2] = 1;
        } else {
            e[2] = -1;
        }
        e[3] = 1;
        e[4] = r % 6 + 3;
        e[5] = s % 5 + 4;
        m = r % 20;
        pt[0] = r % 384 - 64;
        pt[1] = s % 256 - 8;
        func_021A2654((int)obj, (u16 *)pt);
        x = 50 - pt[0] / 3;
        d = 206 - pt[0] / 3;
        if (d < 0) {
            y = x - s % -d;
        } else {
            y = x + s % d;
        }
        if (x <= pt[1] && y >= pt[1]) {
            e[1] *= 2;
        } else {
            m = r % 4;
        }
        func_0204B908(h, m);
    }
}
