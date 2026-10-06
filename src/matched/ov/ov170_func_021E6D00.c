/*
 * function: func_021E6D00
 * address:  0x021E6D00
 * packet:   pkt_ov170_021E6D00
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021ED6E4 0x021ED6E4 thumb
 *   func_021EA728 0x021EA728 thumb
 *   func_021ECB60 0x021ECB60 thumb
 *   func_021EE038 0x021EE038 thumb
 *   func_020061E4 0x020061E4 thumb
 *   func_021DD25C 0x021DD25C thumb
 *   func_021DD2B4 0x021DD2B4 thumb
 *   func_021DD2D0 0x021DD2D0 thumb
 *   func_021DD718 0x021DD718 thumb
 *   func_021DD8A8 0x021DD8A8 thumb
 *   func_021EC48C 0x021EC48C thumb
 *   func_021DEFEC 0x021DEFEC thumb
 *   func_021ED094 0x021ED094 thumb
 *   func_021ED108 0x021ED108 thumb
 *   func_021EBFA8 0x021EBFA8 thumb
 *   func_021EC000 0x021EC000 thumb
 *   func_021ED1C8 0x021ED1C8 thumb
 *   func_021E8FC0 0x021E8FC0 thumb
 *   func_021E122C 0x021E122C thumb
 *
 * Twin of func_021E6A60 driven by the work fields: moves the held item from
 * slot 0xA16E to slot 0xA17E, swapping with what is there.
 */

typedef struct {
    unsigned short idx;
    unsigned short slot;
} Entry;

typedef struct {
    unsigned char lo : 4;
    unsigned char hi : 4;
} Nib;

extern void func_021ED6E4(char **p, int v);
extern void func_021EA728(void *p);
extern void func_021ECB60(char *w, int i, int f);
typedef unsigned int   u32;
extern void func_021EE038(char *p, int a, int b, int c);
extern void func_020061E4(unsigned se);
extern unsigned func_021DD25C(void ***p, unsigned short a, int box, unsigned id, unsigned v);
extern void func_021DD2B4(int a, int b, int c, int d, int e);
extern int func_021DD2D0(void ***p, int a, unsigned b);
extern int func_021DD718(void **pp, void *mon);
extern void func_021DD8A8(void **pp, u32 idx);
extern void func_021EC48C(unsigned char *p, int box, int pos, int win);
extern void func_021DEFEC(char *p, int b);
extern void func_021ED094(char *w, unsigned item);
extern void func_021ED108(char *w, int on);
extern void func_021EBFA8(char *w, int i, int v);
extern void func_021EC000(char *w, int i, int v);
extern void func_021ED1C8(char *w);
extern int func_021E8FC0(char *p, int a, int b);
extern int func_021E122C(unsigned char *p);

#define WORK(p) (*(char **)((p) + 0x2C))
#define OBJ(p) (*(void **)(WORK(p) + 0x70))
#define ITEM(p) (*(unsigned short *)(WORK(p) + 0xA16C))
#define WIN(p, i) (*(unsigned char *)(WORK(p) + (i) + 0x3DD2))
#define CUR(p) (*(unsigned short *)(WORK(p) + 0xA16E))
#define TGT(p) (*(unsigned char *)(WORK(p) + 0xA17E))
#define STATE(p) (*(int *)((p) + 0x28))
#define NIB(p) ((Nib *)((p) + 0x1C))

int func_021E6D00(unsigned char *p)
{
    unsigned short item;
    if (NIB(p)->lo == 0)
        NIB(p)->hi = 1;
    if (TGT(p) == CUR(p) && (p[0x17] == 0xFF || p[0x17] == p[0x14])) {
        ITEM(p) = 0;
        func_021EE038((char *)p, 0, 1, 1);
        return 0x40;
    }
    if (p[0x17] == p[0x14] || CUR(p) >= 0x1E)
        func_021ECB60(WORK(p), CUR(p), 1);
    func_021ECB60(WORK(p), TGT(p), 0);
    item = func_021DD25C((void ***)p, TGT(p), p[0x14], 6, 0);
    func_021DD2B4((int)p, TGT(p), p[0x14], 6, ITEM(p));
    if (func_021DD718((void **)p, (void *)func_021DD2D0((void ***)p, p[0x14], TGT(p))) == 1) {
        func_021DD8A8((void **)p, TGT(p));
        func_021EC48C(p, p[0x14], TGT(p), WIN(p, TGT(p)));
    }
    func_021DEFEC((char *)p, TGT(p));
    ITEM(p) = item;
    func_021DD2B4((int)p, CUR(p), p[0x17], 6, ITEM(p));
    if (func_021DD718((void **)p, (void *)func_021DD2D0((void ***)p, p[0x17], CUR(p))) == 1) {
        func_021DD8A8((void **)p, CUR(p));
        if (p[0x17] == 0xFF || p[0x17] == p[0x14])
            func_021EC48C(p, p[0x14], CUR(p), WIN(p, CUR(p)));
    }
    if (ITEM(p) == 0) {
        func_021EE038((char *)p, 0, 1, 1);
        return 0x40;
    }
    func_021EA728(p);
    (*(Entry **)(WORK(p) + 0x60))->idx = TGT(p);
    func_021ED094(WORK(p), ITEM(p));
    func_021ED108(WORK(p), 1);
    func_021EBFA8(WORK(p), 10, 1);
    func_021EC000(WORK(p), 10, 1);
    func_021ED1C8(WORK(p));
    func_020061E4(0x666);
    return func_021E8FC0((char *)p, (int)func_021E122C, 0x43);
}
