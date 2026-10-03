/*
 * function: func_021E9C94
 * address:  0x021E9C94
 * packet:   pkt_ov170_021E9C94
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021DD16C 0x021DD16C thumb
 *   func_021EF5E8 0x021EF5E8 thumb
 *   func_021EF57C 0x021EF57C thumb
 *   func_021EBA5C 0x021EBA5C thumb
 *   func_021DD14C 0x021DD14C thumb
 *   func_021EF670 0x021EF670 thumb
 *   func_021E8FC0 0x021E8FC0 thumb
 *   func_021E00C4 0x021E00C4 thumb
 */

struct WinMgr;
extern void func_021DD16C(char *p, int dir);
extern int func_021EF5E8(struct WinMgr *mgr);
extern void func_021EF57C(struct WinMgr *mgr);
extern void func_021EBA5C(char *w, int v);
extern void func_021DD14C(char *p);
extern void func_021EF670(char *w);
extern void func_021E8FC0(char *p, int (*cb)(char *), int n);
extern int func_021E00C4(char *p);

#define WORK(p) (*(char **)((p) + 0x2C))

void func_021E9C94(char *p, int a, int n)
{
    func_021DD16C(p, 0);
    if (func_021EF5E8(*(struct WinMgr **)(WORK(p) + 0x74)) == 1) {
        func_021EF57C(*(struct WinMgr **)(WORK(p) + 0x74));
        func_021EBA5C(WORK(p), 0x18);
        func_021DD14C(p);
        if (a == 1)
            func_021EF670(WORK(p));
    }
    func_021E8FC0(p, func_021E00C4, n);
}
