/*
 * function: func_021E0A40
 * address: 0x021E0A40
 * packet: pkt_ov170_021E0A40
 * region: ov170
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021ED108 0x021ED108 thumb ov170
 *   func_021EBFA8 0x021EBFA8 thumb ov170
 *   func_021EC000 0x021EC000 thumb ov170
 *   func_021E066C 0x021E066C thumb ov170
 *   func_021EF5C4 0x021EF5C4 thumb ov170
 *   func_021ED2F4 0x021ED2F4 thumb ov170
 */
struct WinMgr;
extern void func_021ED108(char *w, int on);
extern void func_021EBFA8(char *w, int i, int v);
extern void func_021EC000(char *w, int i, int v);
extern int func_021E066C(char *p);
extern int func_021EF5C4(struct WinMgr *mgr);
extern void func_021ED2F4(char *w);
#define WORK(p) (*(char **)((p) + 0x2C))
int func_021E0A40(char *p)
{
    char *s;
    int a;
    int b;
    s = WORK(p) + 0x58;
    switch (*(unsigned short *)(s + 12)) {
    case 0:
        if (*(unsigned short *)(WORK(p) + 0xA16C)) {
            func_021ED108(WORK(p), 1);
            func_021EBFA8(WORK(p), 10, 1);
            func_021EC000(WORK(p), 10, 1);
        }
        (*(unsigned short *)(s + 12))++;
    case 1:
        a = func_021E066C(p);
        b = func_021EF5C4(*(struct WinMgr **)(WORK(p) + 0x74));
        if (a == 0 && b == 0) {
            if (*(unsigned short *)(WORK(p) + 0xA16C)) {
                func_021ED108(WORK(p), 0);
                func_021ED2F4(WORK(p));
            }
            *(unsigned short *)(s + 12) = 0;
            return 0;
        }
        break;
    }
    return 1;
}
