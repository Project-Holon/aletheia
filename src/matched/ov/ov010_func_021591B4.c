/*
 * function: SCRIPT_WORK_RunCheckTask
 * address:  0x021591B4
 * packet:   pkt_ov010_021591B4
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * volatile: 0x021591F2 re-reads idx after the store at 0x021591EC.
 *
 * symbols:
 *   SCRIPT_WORK_IsCheckFlagSet  0x02159198  thumb  ov010
 *   gScriptCheckHandlers     0x021705F0  data  ov010
 */

typedef int (*Fn)(int *, int *);

struct S { int _0, _4, _8; int c; int idx; int n; };

extern int SCRIPT_WORK_IsCheckFlagSet(int);
extern Fn gScriptCheckHandlers[];

int SCRIPT_WORK_RunCheckTask(int a, int b, struct S *p)
{
    int *pc = &p->c;
    int *pi = &p->idx;
    do {
        Fn fn = gScriptCheckHandlers[p->idx];
        if (fn == 0)
            return 1;
        if (SCRIPT_WORK_IsCheckFlagSet(p->idx)) {
            if (fn((int *)p, pc)) {
                (*pi)++;
                p->c = 0;
            } else {
                return 0;
            }
        } else {
            (*pi)++;
            p->c = 0;
        }
    } while (*(volatile int *)&p->idx < p->n);
    return 1;
}

