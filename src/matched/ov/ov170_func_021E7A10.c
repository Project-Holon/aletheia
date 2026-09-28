/*
 * function: func_021E7A10
 * address:  0x021E7A10
 * packet:   pkt_ov170_021E7A10
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021EC000 0x021EC000 thumb
 *   func_021EF57C 0x021EF57C thumb
 *   func_021E8FC0 0x021E8FC0 thumb
 *   func_021E0190 0x021E0190 thumb
 *   func_021DD25C 0x021DD25C thumb
 *   func_021E95CC 0x021E95CC thumb
 *   func_021ED508 0x021ED508 thumb
 *   func_021ED888 0x021ED888 thumb
 *   func_0202136C 0x0202136C thumb
 *   func_021ECB20 0x021ECB20 thumb
 *   func_021ECB60 0x021ECB60 thumb
 *   func_021EF508 0x021EF508 thumb
 *   func_021EBAF8 0x021EBAF8 thumb
 *   func_021E8FE8 0x021E8FE8 thumb
 *   func_020061E4 0x020061E4 thumb
 *   func_021EBB1C 0x021EBB1C thumb ov170
 *   func_021E8F50 0x021E8F50 thumb
 *   func_021EBCB4 0x021EBCB4 thumb
 *   func_021EBD78 0x021EBD78 thumb
 *
 * Item menu "give": checks the slot, then asks to swap or confirms.  A
 * four-step machine on the work word at 0xA194 (template 021E3C88).
 */

typedef unsigned short u16;

extern void func_021EC000(char *w, int i, int v);
extern void func_021EF57C(int mgr);
extern int func_021E8FC0(unsigned char *p, int (*cb)(unsigned char *), int n);
extern int func_021E0190(unsigned char *p);
extern unsigned func_021DD25C(unsigned char *p, unsigned short a, int box, unsigned id, unsigned v);
extern int func_021E95CC(unsigned char *p, unsigned char v);
extern void func_021ED508(unsigned char *p, int a, int b);
extern void func_021ED888(char *w, int a);
extern unsigned func_0202136C(u16 v);
extern void func_021ECB20(unsigned char *p, int f, int c);
extern void func_021ECB60(char *w, int i, int f);
extern void func_021EF508(int mgr);
extern void func_021EBAF8(unsigned char *p, unsigned v, int i);
extern int func_021E8FE8(unsigned char *p, int sel);
extern void func_020061E4(unsigned se);
extern void func_021EBB1C(unsigned char *p, int i);
extern int func_021E8F50(unsigned char *p, int v);
extern void func_021EBCB4(unsigned char *p, int kind, int i);
extern void func_021EBD78(unsigned char *p, int b);

#define WORK(p) (*(char **)((p) + 0x2C))
#define MGR(p) (*(int *)(WORK(p) + 0x74))
#define STEP(p) (*(int *)(WORK(p) + 0xA194))
#define STATE(p) (*(int *)((p) + 0x28))
#define TOP(p) (*(char **)(p))

int func_021E7A10(unsigned char *p)
{
    switch (STEP(p)) {
    case 0: {
        unsigned item;
        if (*(int *)(TOP(p) + 0x24) == 4 && *(int *)(TOP(p) + 0x14) == 1) {
            func_021EC000(WORK(p), 4, 0);
            func_021EF57C(MGR(p));
            STEP(p) = 3;
            return func_021E8FC0(p, func_021E0190, 0x50);
        }
        if (func_021DD25C(p, p[0x16], p[0x14], 0x4C, 0) == 0) {
            item = func_021DD25C(p, p[0x16], p[0x14], 6, 0);
            if (item == 0)
                return func_021E95CC(p, 1);
            func_021EC000(WORK(p), 4, 0);
            func_021ED508(p, 0xE, 0);
            func_021ED888(WORK(p), 0);
            if (func_0202136C(item) == 1) {
                func_021EF57C(MGR(p));
                STEP(p) = 1;
                return func_021E8FC0(p, func_021E0190, 0x50);
            }
            if (p[0x16] < 0x1E)
                func_021ECB20(p, 1, 1);
            else
                func_021ECB20(p, 2, 1);
            func_021ECB60(WORK(p), p[0x16], 0);
            *(unsigned char *)(WORK(p) + 0xA170) = 1;
            func_021EF508(MGR(p));
            func_021EBAF8(p, item, 0x18);
            if (*(int *)(TOP(p) + 0x24) == 3)
                return func_021E8FE8(p, 2);
            return func_021E8FE8(p, 0);
        }
        func_021EC000(WORK(p), 4, 0);
        func_021EF57C(MGR(p));
        STEP(p) = 2;
        return func_021E8FC0(p, func_021E0190, 0x50);
    }
    case 1:
        func_020061E4(0x557);
        func_021EBB1C(p, 0x18);
        STATE(p) = 0xE;
        return func_021E8F50(p, 6);
    case 2:
        func_020061E4(0x557);
        func_021EBCB4(p, 5, 0x18);
        STATE(p) = 0xE;
        return func_021E8F50(p, 6);
    case 3:
        func_020061E4(0x557);
        func_021EBD78(p, 1);
        STATE(p) = 0x2B;
        return 6;
    }
    return 0x50;
}
