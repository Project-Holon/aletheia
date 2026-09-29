/*
 * function: func_02194614
 * address:  0x02194614
 * packet:   pkt_ov009_02194614
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      ClosePendingCallbacks (gstats.o)
 *
 * Byte-correct (224/224); the connerror\ninitializer copies from the vendor template @14079 at 0x021A1A54 in ov009 data,\nattested by the `template` class (unique in ov009).\nA struct copy from an extern spelling was tried: one copy instead of two, DIFF.
 *
 * symbols:
 *   func_02184200 0x02184200  arm
 *   func_02193EB8 0x02193EB8  arm
 *   func_0219451C 0x0219451C  arm
 *   func_021841B0 0x021841B0  arm
 *   g_021ADFE0   0x021ADFE0  data
 *   @14079       0x021A1A54  data
 *   g_021A5800   0x021A5800  data
 *   g_021A57C8   0x021A57C8  data
 */

extern int func_02184200(void *array);
extern void func_02193EB8(char *buf, int len);
extern void func_0219451C(int reqindex, int success, long modified, char *data, int length);
extern void func_021841B0(void *array);
extern int g_021ADFE0[];
extern char *g_021A57C8;
extern char g_021A5800[];

void func_02194614(void)
{
    int i;

    if (g_021ADFE0[5] == 0)
        return;
    for (i = func_02184200((void *)g_021ADFE0[5]) - 1; i >= 0; i--) {
        char connerror[16] = {0x13, 0x1d, 0x01, 0x04, 0, 0, 0, 0x28, 0x1f, 0x06, 0x45, 0x34, 0x3f, 0x01, 0x1b, 0};
        g_021A57C8 = g_021A5800;
        func_02193EB8(connerror, 15);
        func_0219451C(i, 0, 0, connerror, 0);
    }
    func_021841B0((void *)g_021ADFE0[5]);
    g_021ADFE0[5] = 0;
}
