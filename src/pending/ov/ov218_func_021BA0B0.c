/*
 * function: func_021BA0B0
 * address:  0x021BA0B0
 * packet:   pkt_021BA0B0
 * region:   ov218
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   DIFF
 *
 * symbols:
 *   func_021B61FC  0x021B61FC  thumb  ov090
 *   func_021B9924  0x021B9924  thumb  ov218
 *   func_021B9B78  0x021B9B78  thumb  ov218
 *   func_021B9C00  0x021B9C00  thumb  ov218
 *   func_021B9C88  0x021B9C88  thumb  ov218
 *   func_021B9898  0x021B9898  thumb  ov218
 *   func_0204E804  0x0204E804  arm
 *   func_02024004  0x02024004  thumb
 *   func_0201F048  0x0201F048  thumb
 *   func_021B6200  0x021B6200  thumb  ov218
 *   d_021BAC80     0x021BAC80  data   ov218  a4
 *
 * blocker: codegen, compiled 144 vs 136 bytes. Three call targets have no
 *   func_ label in any overlay window (0x02024004, 0x021B9C88, 0x021B6200),
 *   so they would cap at MATCH anyway; d_021BAC80 resolves sole-ref. The
 *   larger difference is block placement: the original puts the shared tail
 *   `func_021B6200(a); return 0;` directly after case 0 (so case 0 falls into
 *   it) and the unmatched/default path returns 0 without it; mwccarm keeps
 *   the tail at the end here and duplicates the `return 0` epilogues. Tried
 *   with and without an explicit `default: return 0;`.
 */

extern int func_021B61FC(int);
extern int func_021B9924(void);
extern int func_0204E804(void);
extern int func_02024004(int);
extern void func_0201F048(int, int, int);
extern int func_021B9B78(int, int);
extern int func_021B9C00(int);
extern int func_021B9C88(int);
extern int func_021B9898(int, int, int);
extern int func_021B6200(int);
extern int d_021BAC80[];

int func_021BA0B0(int a, char *b)
{
    switch (func_021B61FC(a)) {
    case 0:
        func_021B9924();
        break;
    case 1:
        if (func_0204E804() == 1)
            return 0;
        if (func_02024004(1) == 0)
            return 0;
        func_0201F048(*(int *)(*(int *)(b + 0x28) + 0x14), 0,
                      d_021BAC80[*(int *)(b + 0x30)]);
        func_021B9B78(*(int *)(b + 0x28), 0xea);
        break;
    case 2:
        if (func_021B9C00(*(int *)(b + 0x28)) == 0)
            return 0;
        break;
    case 3:
        *(int *)(b + 0x1c) = func_021B9898(*(int *)(b + 0x18),
                                           func_021B9C88(*(int *)(b + 0x28)),
                                           *(unsigned short *)(b));
        return 1;
    }
    func_021B6200(a);
    return 0;
}
