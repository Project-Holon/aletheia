/*
 * function: func_021F2344
 * address:  0x021F2344
 * packet:   pkt_ov032_021F2344
 * region:   ov032
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021F2344 0x021F2344 thumb
 *   func_021F0208 0x021F0208 thumb ov032
 *   func_021F2544 0x021F2544 thumb ov032
 *   func_020310C4 0x020310C4 arm
 *   func_021F2674 0x021F2674 thumb ov032
 *   func_021F26D8 0x021F26D8 thumb ov032
 *   func_021F26F0 0x021F26F0 thumb ov032
 *   func_021F2714 0x021F2714 thumb ov032
 *   func_021F27B4 0x021F27B4 thumb ov032
 *   func_021F27CC 0x021F27CC thumb ov032
 *   func_02165888 0x02165888 thumb ov010
 */

extern void func_021F0208(char *, int);
extern void func_021F2544(char *);
extern void func_020310C4(int);
extern int func_021F2674(char *);
extern int func_021F26D8(char *);
extern int func_021F26F0(char *);
extern int func_021F2714(char *);
extern int func_021F27B4(char *);
extern int func_021F27CC(char *);
extern int func_02165888(int a0);

void func_021F2344(char *p, int a1)
{
    int f;

    if (*(int *)(p + 0x60) != a1) {
        int c;

        if (*(unsigned short *)(p + 0x72) != 0 && a1 == 0) {
            c = 1;
        } else {
            c = 0;
        }
        if (c == 0) {
            f = 1;
            *(int *)(p + 0x60) = a1;
            if (a1 != 0) {
                f = 0;
            }
            func_021F0208(p, f);
        }
    }
    if (*(unsigned short *)(p + 0x70) != 0) {
        if (a1 == 0) {
            func_021F2544(p);
            return;
        }
        return;
    }
    if (a1 != 0) {
        func_020310C4(*(int *)(p + 0xa0));
        switch (*(int *)(p + 0x68)) {
        case 0:
            *(int *)(p + 0x68) = func_021F2674(p);
            break;
        case 1:
            *(int *)(p + 0x68) = func_021F26D8(p);
            break;
        case 2:
            *(int *)(p + 0x68) = func_021F26F0(p);
            break;
        case 3:
            *(int *)(p + 0x68) = func_021F2714(p);
            break;
        case 4:
            *(int *)(p + 0x68) = func_021F27B4(p);
            break;
        case 5:
            *(int *)(p + 0x68) = func_021F27CC(p);
            break;
        case 6:
        case 7:
            break;
        }
        func_02165888(*(int *)(p + 0x38));
    }
}
