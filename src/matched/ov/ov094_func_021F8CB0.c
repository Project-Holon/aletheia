/*
 * function: func_021F8CB0
 * address:  0x021F8CB0
 * packet:   pkt_ov094_021F8CB0
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   d_0220AF20 0x0220AF20 data ov094 a4
 *   func_021F94F8 0x021F94F8 thumb ov094
 *   func_021FFF38 0x021FFF38 thumb ov094
 *   func_021FF924 0x021FF924 thumb ov094
 *   func_021FFBBC 0x021FFBBC thumb ov094
 *   func_021F9858 0x021F9858 thumb ov094
 *   func_021F9948 0x021F9948 thumb ov094
 *   func_021FFCB0 0x021FFCB0 thumb ov094
 *   func_022001DC 0x022001DC thumb ov094
 *   func_021F89BC 0x021F89BC thumb ov094
 */
typedef unsigned short u16;
typedef unsigned int u32;
extern char *d_0220AF20;
extern void func_021F94F8(void *, int, u32, u16, void *);
extern int func_021FFF38(void *, int);
extern void func_021FF924(void *, int, int, int, int, int, int);
extern void func_021FFBBC(void *, int, int, int, int, int, int);
extern void func_021F9858(void *, int, int, int, int, int, int, int, int);
extern void func_021F9948(void *, int, int, int, int, int, int, int, int, int);
extern int func_021FFCB0(void *, int);
extern void func_022001DC(void *, int, int *);
extern void func_021F89BC(void *);
#define FIELD(k) (*(void **)(d_0220AF20 + (k)))
#define READY (*(int *)(d_0220AF20 + 0x1e8))

void func_021F8CB0(void *h, int *p)
{
    switch (p[1]) {
    case 0:
        func_021F94F8(FIELD(0x188), p[0], 0xff, 0x253, 0);
        READY = 1;
        p[1]++;
        break;
    case 1:
        if (READY == 0) {
            if (func_021FFF38(FIELD(0x190), p[0]) & 1) {
                func_021F94F8(FIELD(0x188), p[0], 0xff, 0x264, 0);
                READY = 1;
            }
            p[1]++;
        }
        break;
    case 2:
        if (READY == 0) {
            func_021FF924(FIELD(0x190), p[0], 0, 16, 0, 0, 0);
            func_021FFBBC(FIELD(0x190), p[0], 1, 8, 8, 1, 0);
            func_021F9858(FIELD(0x188), 0x5aa, 1, 14, -500, 127, 0, 0, 0);
            func_021F9948(FIELD(0x188), 1, 0, 1, 127, 0, 30, 10, 0, 0);
            p[1]++;
        }
        break;
    case 3:
        if (func_021FFCB0(FIELD(0x190), p[0]) == 0) {
            func_022001DC(FIELD(0x190), p[0], &p[2]);
            p[1]++;
        }
        break;
    case 4:
        func_021FFBBC(FIELD(0x190), p[0], 1, 0, 8, 1, 0);
        p[1]++;
        break;
    case 5:
        if (func_021FFCB0(FIELD(0x190), p[0]) == 0) {
            func_021F9858(FIELD(0x188), 0x560, 1, 14, 0, 0, 0, 0, 0);
            func_021FF924(FIELD(0x190), p[0], 0, 31, 0, 0, 0);
            if (func_021FFF38(FIELD(0x190), p[0]) & 1) {
                func_021F94F8(FIELD(0x188), p[0], 0xff, 0x265, 0);
                READY = 1;
            }
            p[1]++;
        }
        break;
    case 6:
        if (READY == 0) {
            func_021F94F8(FIELD(0x188), p[0], 0xff, 0x254, 0);
            READY = 1;
            p[1]++;
        }
        break;
    case 7:
        if (READY == 0)
            func_021F89BC(h);
        break;
    }
}
