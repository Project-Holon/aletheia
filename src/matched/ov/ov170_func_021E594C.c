/*
 * function: func_021E594C
 * address:  0x021E594C
 * packet:   pkt_ov170_021E594C
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021EF57C 0x021EF57C thumb
 *   func_021ED55C 0x021ED55C thumb
 *   func_021EBA5C 0x021EBA5C thumb
 *   func_021DD14C 0x021DD14C thumb
 *   func_021E8FC0 0x021E8FC0 thumb
 *   func_021E0190 0x021E0190 thumb
 *   func_021EA8CC 0x021EA8CC thumb
 *   func_021ECB84 0x021ECB84 thumb
 *   func_021EC768 0x021EC768 thumb
 *   func_021EE3E4 0x021EE3E4 thumb
 *   func_021E0778 0x021E0778 thumb
 *   func_020061E4 0x020061E4 thumb
 *   func_021ED6E4 0x021ED6E4 thumb
 *   func_021EBBC8 0x021EBBC8 thumb
 *   func_021EBC58 0x021EBC58 thumb
 *   func_021EF3A0 0x021EF3A0 thumb
 *   func_021E01B0 0x021E01B0 thumb
 *   func_021EE520 0x021EE520 thumb
 *   func_021E066C 0x021E066C thumb
 *   func_020307B0 0x020307B0 arm
 *   func_021ED888 0x021ED888 thumb
 *   func_021EE038 0x021EE038 thumb
 *   func_021EE364 0x021EE364 thumb
 *
 * Five-step machine on the work word at 0xA194: fade out, confirm the
 * party slot (or back out to state 0x33), fade, swap, then reopen.
 */

extern void func_021EF57C(int mgr);
extern void func_021ED55C(unsigned char *p, int flag);
extern void func_021EBA5C(char *w, int v);
extern void func_021DD14C(unsigned char *p);
extern int func_021E8FC0(unsigned char *p, int (*cb)(unsigned char *), int n);
extern int func_021E0190(unsigned char *p);
extern int func_021EA8CC(unsigned char *p);
extern void func_021ECB84(char *w, unsigned i);
extern void func_021EC768(char *p, unsigned i, int flag);
extern void func_021EE3E4(unsigned char *p, unsigned idx);
extern int func_021E0778(unsigned char *p);
extern void func_020061E4(unsigned se);
extern void func_021ED6E4(unsigned char *p, int v);
extern void func_021EBBC8(unsigned char *p, int kind, int i);
extern void func_021EBC58(unsigned char *p, int sel, int kind, int i);
extern void func_021EF3A0(int mgr);
extern int func_021E01B0(unsigned char *p);
extern void func_021EE520(unsigned char *p, unsigned idx);
extern int func_021E066C(unsigned char *p);
extern void func_020307B0(void *ptr);
extern void func_021ED888(char *w, int a);
extern void func_021EE038(unsigned char *p, int a, int b, int c);
extern void func_021EE364(unsigned char *p, int idx, int v);

#define WORK(p) (*(char **)((p) + 0x2C))
#define MGR(p) (*(int *)(WORK(p) + 0x74))
#define STEP(p) (*(int *)(WORK(p) + 0xA194))
#define STATE(p) (*(int *)((p) + 0x28))

int func_021E594C(unsigned char *p)
{
    switch (STEP(p)) {
    case 0:
        func_021EF57C(MGR(p));
        func_021ED55C(p, 0);
        func_021EBA5C(WORK(p), 0x18);
        func_021DD14C(p);
        STEP(p)++;
        return func_021E8FC0(p, func_021E0190, 0x34);
    case 1:
        switch (func_021EA8CC(p)) {
        case 0:
            p[0x18] = 1;
            func_021ECB84(WORK(p), p[0x16]);
            func_021EC768(WORK(p), 0x24, 0);
            func_021ED55C(p, 1);
            func_021EE3E4(p, p[0x16] - 0x1E);
            STEP(p)++;
            return func_021E8FC0(p, func_021E0778, 0x34);
        case 1:
            func_020061E4(0x557);
            func_021ED6E4(p, 0);
            func_021EBBC8(p, 6, 0x18);
            STATE(p) = 0x33;
            STEP(p) = 0;
            return 6;
        case 2:
            func_020061E4(0x557);
            func_021ED6E4(p, 0);
            func_021EBC58(p, 0, 5, 0x18);
            STATE(p) = 0x33;
            STEP(p) = 0;
            return 6;
        }
        break;
    case 2:
        func_020061E4(0x669);
        func_021EF3A0(MGR(p));
        STEP(p)++;
        return func_021E8FC0(p, func_021E01B0, 0x34);
    case 3:
        func_021EE520(p, p[0x16] - 0x1E);
        STEP(p)++;
        return func_021E8FC0(p, func_021E066C, 0x34);
    case 4:
        func_020307B0(*(void **)(WORK(p) + 0x60));
        func_021ED888(WORK(p), 1);
        func_021EBC58(p, 0, 3, 0x1A);
        func_021EE038(p, 0, 1, 1);
        func_021EE364(p, 1, 0);
        STEP(p) = 0;
        return 0x35;
    }
    return 0x34;
}
