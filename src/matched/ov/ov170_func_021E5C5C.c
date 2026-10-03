/*
 * function: func_021E5C5C
 * address:  0x021E5C5C
 * packet:   pkt_ov170_021E5C5C
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021EE544 0x021EE544 thumb
 *   func_021ED888 0x021ED888 thumb
 *   func_021EBA5C 0x021EBA5C thumb
 *   func_021DD14C 0x021DD14C thumb
 *   func_021E8FC0 0x021E8FC0 thumb
 *   func_021E066C 0x021E066C thumb
 *   func_020307B0 0x020307B0 arm
 *   func_020061E4 0x020061E4 thumb
 *   func_021EF36C 0x021EF36C thumb
 *   func_021E01B0 0x021E01B0 thumb
 *   func_021EA1C0 0x021EA1C0 thumb
 *   func_021E087C 0x021E087C thumb
 *   func_021EC000 0x021EC000 thumb
 *   func_021ED6E4 0x021ED6E4 thumb
 *   func_021E09E0 0x021E09E0 thumb
 *   func_021DD530 0x021DD530 thumb
 *   func_021EA1E8 0x021EA1E8 thumb
 *   func_021DF040 0x021DF040 thumb
 *   func_021ECB20 0x021ECB20 thumb
 *   func_021EE038 0x021EE038 thumb
 *   func_021EE364 0x021EE364 thumb
 *   func_021DEFEC 0x021DEFEC thumb
 *
 * Eight-step machine on the work word at 0xA194 for the party swap:
 * fade, take the slot (from the held box slot at 0xA17E if any), fade
 * back and restore the box view.
 */

struct WinMgr;
extern void func_021EE544(unsigned char *p, unsigned i);
extern void func_021ED888(char *w, int a);
extern void func_021EBA5C(char *w, int v);
extern void func_021DD14C(unsigned char *p);
extern int func_021E8FC0(unsigned char *p, int (*cb)(unsigned char *), int n);
extern int func_021E066C(unsigned char *p);
extern void func_020307B0(void *ptr);
extern void func_020061E4(unsigned se);
extern void func_021EF36C(struct WinMgr *mgr);
extern int func_021E01B0(unsigned char *p);
extern void func_021EA1C0(void *p);
extern int func_021E087C(unsigned char *p);
extern void func_021EC000(char *w, int i, int v);
extern void func_021ED6E4(unsigned char *p, int v);
extern int func_021E09E0(unsigned char *p);
extern void func_021DD530(unsigned char *p);
extern void func_021EA1E8(unsigned char *p);
extern void func_021DF040(unsigned char *p);
extern void func_021ECB20(unsigned char *p, int f, int c);
extern void func_021EE038(unsigned char *p, int a, int b, int c);
extern void func_021EE364(unsigned char *p, int idx, int v);
extern void func_021DEFEC(unsigned char *p, int b);

#define WORK(p) (*(char **)((p) + 0x2C))
#define MGR(p) (*(struct WinMgr **)(WORK(p) + 0x74))
#define STEP(p) (*(int *)(WORK(p) + 0xA194))
#define HELD(p) (*(unsigned char *)(WORK(p) + 0xA17E))

int func_021E5C5C(unsigned char *p)
{
    switch (STEP(p)) {
    case 0:
        if (HELD(p) == 0xFF) {
            func_021EE544(p, p[0x16]);
            STEP(p) = 1;
        } else {
            func_021EE544(p, HELD(p));
            STEP(p) = 4;
        }
        func_021ED888(WORK(p), 0);
        func_021EBA5C(WORK(p), 0x18);
        func_021DD14C(p);
        return func_021E8FC0(p, func_021E066C, 0x36);
    case 1:
        func_020307B0(*(void **)(WORK(p) + 0x60));
        func_020061E4(0x669);
        func_021EF36C(MGR(p));
        STEP(p) = 2;
        return func_021E8FC0(p, func_021E01B0, 0x36);
    case 2:
        func_021EA1C0(p);
        STEP(p) = 6;
        return func_021E8FC0(p, func_021E087C, 0x36);
    case 3:
        func_020061E4(0x669);
        func_021EC000(WORK(p), 4, 0);
        func_021EF36C(MGR(p));
        STEP(p) = 7;
        return func_021E8FC0(p, func_021E01B0, 0x36);
    case 4:
        func_020307B0(*(void **)(WORK(p) + 0x60));
        func_021EA1C0(p);
        func_021ED6E4(p, 0);
        STEP(p) = 5;
        return func_021E8FC0(p, func_021E09E0, 0x36);
    case 5:
        func_021DD530(p);
        func_021EA1E8(p);
        func_021DF040(p);
        func_021ECB20(p, 1, 1);
        func_021ECB20(p, 2, 0);
        STEP(p) = 3;
        break;
    case 6:
        func_021EA1E8(p);
    case 7:
        p[0x18] = 0;
        func_021ED6E4(p, 0);
        func_021EE038(p, 0, 0, 1);
        func_021EE364(p, 0, p[0x16] - 0x1E);
        func_021DEFEC(p, p[0x16]);
        STEP(p) = 0;
        return 0x31;
    }
    return 0x36;
}
