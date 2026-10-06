/*
 * function: func_021C7B34
 * address:  0x021C7B34
 * packet:   pkt_ov016_021C7B34
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      isCorrect (libdwcutil.TWL.HYB.a(sceneseteditaddr))
 *
 * symbols:
 *   func_021CFE18 0x021CFE18 arm ov016
 *   func_021C0EA0 0x021C0EA0 arm ov016
 *   func_020588D0 0x020588D0 arm
 *   g_021DA5CC 0x021DA5CC data
 *   g_021DE5E4 0x021DE5E4 data
 */

typedef unsigned char u8;

typedef struct {
    char pad0[8];
    char addr[4][3];
} MemSsea;

typedef struct { char c[4]; } Val;

extern Val g_021DA5CC;
extern MemSsea *g_021DE5E4;

extern void func_021CFE18(char *adr, u8 *buf);
extern void func_021C0EA0(unsigned int *a, unsigned int *b);
extern int func_020588D0(u8 *address);

int func_021C7B34(void)
{
    Val VAL = g_021DA5CC;
    u8 *c;
    int prm;
    int i;
    int j;
    u8 buf[4];
    int b;

    for (i = 0; i < 4; i++) {
        c = (u8 *)g_021DE5E4->addr[i];
        if (c[0] == ' ')
            continue;
        for (j = 0; j < 3; j++) {
            if (c[j] > (u8)VAL.c[j])
                return 0;
            if (c[j] < (u8)VAL.c[j])
                break;
        }
    }
    func_021CFE18(g_021DE5E4->addr[0], buf);
    b = 0;
    func_021C0EA0((unsigned int *)((void **)&prm), 0);
    if (prm == 1) {
        for (i = 0; i < 4; i++) {
            for (j = 0; j < 8; j++) {
                if (b != 0) {
                    if (buf[i] & (1 << (7 - j)))
                        return 0;
                } else {
                    if ((buf[i] & (1 << (7 - j))) == 0)
                        b = 1;
                }
            }
        }
        return 1;
    }
    if (func_020588D0(buf))
        b = 1;
    return b;
}
