/*
 * function: func_0215A438
 * address:  0x0215A438
 * packet:   pkt_ov010_0215A438
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   SCRIPT_SYS_GetEventScriptWork  0x021589D0  thumb  ov010
 *   SCRIPT_WORK_GetTrainerEntry  0x02159124  thumb  ov010
 */

typedef struct {
    int w[6];
} S24;

extern int SCRIPT_SYS_GetEventScriptWork(int);
extern char *SCRIPT_WORK_GetTrainerEntry(char *p, int i);

void func_0215A438(int a, int b, S24 *src)
{
    int *q = (int *)SCRIPT_WORK_GetTrainerEntry((char *)SCRIPT_SYS_GetEventScriptWork(a), b);

    *(S24 *)q = *src;
    q[6] = 0;
}
