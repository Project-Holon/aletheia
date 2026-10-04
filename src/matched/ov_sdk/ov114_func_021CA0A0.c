/*
 * function: func_021CA0A0
 * address:  0x021CA0A0
 * packet:   pkt_ov114_021CA0A0
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * The ProgressCallback pointer 0x021C9B60 (DWCi_EncSessionProgressCallback) was the
 * last blocker; it now has a catalog row and a matched body (w3_tools, 2026-09-29).
 *
 * sdk:      DWCi_EncSessionProcess (dwc_encsession.o)
 *
 * symbols:
 *   func_021BF6C4  0x021BF6C4  arm  ov114
 *   func_021BF5B8  0x021BF5B8  arm  ov114
 *   func_021CA06C  0x021CA06C  arm  ov114
 *   func_021C9B64  0x021C9B64  arm  ov114
 *   func_021C9B60  0x021C9B60  arm  ov114
 *   g_021CF7AC     0x021CF7AC  data
 */

typedef struct {
    int state;
    int active;
    int result;
    char pad0[0x48];
    char *buf;
} Session;
extern Session g_021CF7AC;
extern int func_021BF6C4(char *url, int bufferlen, int buffer_clear, void (*progress)(void), void (*completed)(void), void *param);
extern int func_021BF5B8(void);
extern void func_021CA06C(void);
extern void func_021C9B64(char *buf, int len, int result);
extern void func_021C9B60(void);

int func_021CA0A0(void)
{
    switch (g_021CF7AC.state) {
    case 1:
        func_021CA06C();
        break;
    case 4:
        g_021CF7AC.result = func_021BF6C4(g_021CF7AC.buf, 0, 0, func_021C9B60, (void (*)(void))func_021C9B64, 0);
        if (g_021CF7AC.result >= 0) {
            g_021CF7AC.state = 5;
        } else {
            func_021CA06C();
        }
        break;
    case 5:
        if (func_021BF5B8() == 0) {
            func_021CA06C();
        }
        break;
    case 6:
        g_021CF7AC.result = func_021BF6C4(g_021CF7AC.buf, 0, 0, func_021C9B60, (void (*)(void))func_021C9B64, 0);
        if (g_021CF7AC.result >= 0) {
            g_021CF7AC.state = 7;
        } else {
            func_021CA06C();
        }
        break;
    case 7:
        if (func_021BF5B8() == 0) {
            func_021CA06C();
        }
        break;
    case 8:
        break;
    }
    return g_021CF7AC.state;
}
