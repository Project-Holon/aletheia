/*
 * function: func_0216B908
 * address:  0x0216B908
 * packet:   pkt_ov009_021702A0
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * DWC_GetAIDBitmap: the bitmap of every aid in the current node list.
 *
 * symbols:
 *   g_021AA878  0x021AA878  data
 *   func_0216C82C  0x0216C82C  arm  ov009
 *   func_0216B880  0x0216B880  arm  ov009
 *   func_0216BCD0  0x0216BCD0  arm  ov009
 */

extern char g_021AA878[];
extern int func_0216C82C(void);
extern int func_0216B880(unsigned char **out);
extern int func_0216BCD0(unsigned char *p, int n);

int func_0216B908(void)
{
    unsigned char *list;
    int n;

    if (*(int *)(g_021AA878 + 4) == 0 || func_0216C82C() == 0) {
        return 0;
    }
    n = func_0216B880(&list);
    return func_0216BCD0(list, n);
}
