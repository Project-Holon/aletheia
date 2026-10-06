/*
 * function: func_0216B838
 * address:  0x0216B838
 * packet:   pkt_ov009_021702A0
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * DWC_GetMyAID: this host's aid, or 0xff when none is valid.
 *
 * symbols:
 *   g_021AA878  0x021AA878  data
 *   func_0216C82C  0x0216C82C  arm  ov009
 *   func_021763AC  0x021763AC  arm  ov009
 */

extern char g_021AA878[];
extern int func_0216C82C(void);
extern char *func_021763AC(int pid);

unsigned char func_0216B838(void)
{
    unsigned char *node;

    if (*(char **)(g_021AA878 + 4) == 0 || func_0216C82C() == 0) {
        return 0xff;
    }
    node = (unsigned char *)func_021763AC(*(int *)(*(char **)(g_021AA878 + 4) + 0x64));
    if (node == 0) {
        return 0xff;
    }
    return node[0x16];
}
