/*
 * function: func_021F1CD8
 * address:  0x021F1CD8
 * packet:   pkt_ov029_021F1CD8
 * region:   ov029
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_021F05B4  0x021F05B4  thumb  ov029
 *   func_02026C8C  0x02026C8C  thumb
 *   func_02026CA0  0x02026CA0  thumb
 *   func_02026C78  0x02026C78  thumb
 *   func_02165CD8  0x02165CD8  thumb  ov010
 *   func_020215BC  0x020215BC  thumb
 *   d_021F33CC     0x021F33CC  data  ov029  a4
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_021F05B4(char *p);
extern int func_02026C8C(void);
extern int func_02026CA0(int *p);
extern void *func_02026C78(int n);
extern u8 func_02165CD8(void *p);
extern void func_020215BC(int, void *, int, u16, u16);
extern const int d_021F33CC[];

void func_021F1CD8(char *p)
{
    int n;
    int cnt;
    int k;
    int tmp;
    void *e;

    cnt = 0;
    if (*(u8 *)(p + 0x45a) == 0) {
        return;
    }
    if (func_021F05B4(p) != 0) {
        return;
    }
    n = func_02026C8C();
    if (*(u8 *)(p + 0x450) == 0) {
        tmp = 0;
        if (func_02026CA0(&tmp) != 30) {
            *(u8 *)(p + 0x450) = 1;
        }
    }
    n--;
    for (k = 0; k < 30; k++) {
        if (cnt >= 10) {
            break;
        }
        if (n < 0) {
            func_020215BC(*(int *)(p + 0x210), p + 0x1f8, 3, d_021F33CC[cnt] * 2 + 0x60, 4);
            cnt++;
        } else {
            e = func_02026C78(n);
            if (e != 0) {
                func_020215BC(*(int *)(p + 0x210), (u32 *)(p + 0x1b8) + func_02165CD8(e), 3,
                              d_021F33CC[cnt] * 2 + 0x60, 4);
                cnt++;
            }
            n--;
        }
    }
}
