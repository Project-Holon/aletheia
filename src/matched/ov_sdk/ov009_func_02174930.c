/*
 * function: DWCi_RandomizeServers
 * address:  0x02174930
 * packet:   pkt_ov009_02174930
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_RandomizeServers (libdwcmatch.TWL.HYB.a dwc_match.o)
 *
 * symbols:
 *   func_02175F3C  0x02175F3C arm   ov009
 *   func_0219F068  0x0219F068 arm   ov009
 *   func_0219F058  0x0219F058 arm   ov009
 *   func_0219E120  0x0219E120 arm   ov009
 *   func_021685CC  0x021685CC arm   ov009
 *   _s32_div_f     0x0209C0A4 arm
 *   func_0219E084  0x0219E084 arm   ov009
 *   func_0219F078  0x0219F078 arm   ov009
 *   g_021A19C0     0x021A19C0 data
 *   g_021A21BC     0x021A21BC data
 */

struct DWCstMatchControl {
    char pad0[0x5e0];
    void *sb;
};

extern int func_02175F3C(void);
extern int func_0219F068(void *sb);
extern void *func_0219F058(void *sb, int index);
struct SBServer;
struct ServerBrowser;
extern int func_0219E120(struct SBServer *server, char *key, int idefault);
extern unsigned long func_021685CC(unsigned long max);
extern void func_0219E084(void *server, char *key, int value);
extern void func_0219F078(struct ServerBrowser *sb, int ascending, char *sortkey, int comparemode);
extern int g_021A19C0[6];
extern char g_021A21BC[];

void DWCi_RandomizeServers(void)
{
    unsigned long rand;
    int tmpEval;
    int maxEval;
    int sum;
    int i;
    unsigned long eval[6];
    void *server;

    maxEval = 0;
    sum = 0;
    if (func_0219F068(((struct DWCstMatchControl *)func_02175F3C())->sb) <= 1)
        return;
    for (i = 0; i < func_0219F068(((struct DWCstMatchControl *)func_02175F3C())->sb); i++) {
        server = func_0219F058(((struct DWCstMatchControl *)func_02175F3C())->sb, i);
        tmpEval = func_0219E120(server, g_021A21BC, -1);
        if (tmpEval > maxEval)
            maxEval = tmpEval;
        sum += g_021A19C0[i];
    }
    rand = func_021685CC(100);
    for (i = 0; i < func_0219F068(((struct DWCstMatchControl *)func_02175F3C())->sb); i++) {
        unsigned long prev;
        if (i == func_0219F068(((struct DWCstMatchControl *)func_02175F3C())->sb) - 1)
            break;
        prev = (i > 0) ? eval[i - 1] : 0;
        tmpEval = g_021A19C0[i] * 100 / sum;
        tmpEval += prev;
        eval[i] = tmpEval;
        if (rand < tmpEval)
            break;
    }
    if (maxEval < 0x7fffffff)
        maxEval++;
    server = func_0219F058(((struct DWCstMatchControl *)func_02175F3C())->sb, i);
    func_0219E084(server, g_021A21BC, maxEval);
    func_0219F078(((struct DWCstMatchControl *)func_02175F3C())->sb, 0, g_021A21BC, 0);
}
