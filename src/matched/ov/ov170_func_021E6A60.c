/*
 * function: func_021E6A60
 * address:  0x021E6A60
 * packet:   pkt_ov170_021E6A60
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021ED6E4 0x021ED6E4 thumb
 *   func_021EA750 0x021EA750 thumb
 *   func_021ECB60 0x021ECB60 thumb
 *   func_020260E4 0x020260E4 thumb
 *   func_021EE038 0x021EE038 thumb
 *   func_0202136C 0x0202136C thumb
 *   func_020061E4 0x020061E4 thumb
 *   func_021EBB28 0x021EBB28 thumb
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
 * Drop of a held item onto a slot: put it back when dropped where it was
 * picked up, otherwise swap the two slots' items.
 */

typedef struct {
    unsigned short idx;
    unsigned short slot;
} Entry;

typedef struct {
    unsigned char lo : 4;
    unsigned char hi : 4;
} Nib;

extern void func_021ED6E4(unsigned char *p, int v);
extern void func_021EA750(unsigned char *p);
extern void func_021ECB60(char *w, int i, int f);
typedef unsigned char  u8;
struct Sound;
extern void func_020260E4(struct Sound *obj, u8 sel);
extern void func_021EE038(unsigned char *p, int a, int b, int c);
extern unsigned func_0202136C(unsigned short v);
extern void func_020061E4(unsigned se);
extern void func_021EBB28(unsigned char *p, int b);
extern unsigned func_021DD25C(unsigned char *p, unsigned short a, int box, unsigned id, unsigned v);
extern void func_021DD2B4(unsigned char *p, int a, int b, int c, int d);
extern void *func_021DD2D0(unsigned char *p, int a, unsigned b);
extern int func_021DD718(unsigned char *p, void *mon);
extern void func_021DD8A8(unsigned char *p, unsigned idx);
extern void func_021EC48C(unsigned char *p, int box, int pos, int win);
extern void func_021DEFEC(unsigned char *p, int b);
extern void func_021ED094(char *w, unsigned item);
extern void func_021ED108(char *w, int on);
extern void func_021EBFA8(char *w, int i, int v);
extern void func_021EC000(char *w, int i, int v);
extern void func_021ED1C8(char *w);
extern int func_021E8FC0(unsigned char *p, int (*cb)(unsigned char *), int n);
extern int func_021E122C(unsigned char *p);

#define WORK(p) (*(char **)((p) + 0x2C))
#define OBJ(p) (*(void **)(WORK(p) + 0x70))
#define ITEM(p) (*(unsigned short *)(WORK(p) + 0xA16C))
#define WIN(p, i) (*(unsigned char *)(WORK(p) + (i) + 0x3DD2))
#define STATE(p) (*(int *)((p) + 0x28))
#define NIB(p) ((Nib *)((p) + 0x1C))

int func_021E6A60(unsigned char *p)
{
    Entry *o;
    if (NIB(p)->lo == 0)
        NIB(p)->hi = 1;
    func_021ED6E4(p, 0);
    o = *(Entry **)(WORK(p) + 0x60);
    if (o->idx == p[0x16] && (p[0x17] == 0xFF || p[0x17] == p[0x14])) {
        unsigned short from = o->slot;
        func_021EA750(p);
        func_021ECB60(WORK(p), p[0x16], 0);
        func_020260E4(OBJ(p), p[0x16]);
        func_021EE038(p, 0, 1, 1);
        if (func_0202136C(ITEM(p)) == 1 && from != p[0x16]) {
            func_020061E4(0x557);
            func_021EBB28(p, 0x18);
            STATE(p) = 0x44;
            return 6;
        }
        return 0x40;
    } else {
        unsigned short item;
        if (p[0x17] == p[0x14] || p[0x16] >= 0x1E)
            func_021ECB60(WORK(p), p[0x16], 1);
        func_021ECB60(WORK(p), o->idx, 0);
        item = func_021DD25C(p, o->idx, p[0x14], 6, 0);
        func_021DD2B4(p, o->idx, p[0x14], 6, ITEM(p));
        if (func_021DD718(p, func_021DD2D0(p, p[0x14], o->idx)) == 1) {
            func_021DD8A8(p, o->idx);
            func_021EC48C(p, p[0x14], o->idx, WIN(p, o->idx));
        }
        func_021DEFEC(p, o->idx);
        func_020260E4(OBJ(p), o->idx);
        ITEM(p) = item;
        func_021DD2B4(p, p[0x16], p[0x17], 6, ITEM(p));
        if (func_021DD718(p, func_021DD2D0(p, p[0x17], p[0x16])) == 1) {
            func_021DD8A8(p, p[0x16]);
            if (p[0x17] == 0xFF || p[0x17] == p[0x14])
                func_021EC48C(p, p[0x14], p[0x16], WIN(p, p[0x16]));
        }
        if (ITEM(p) == 0) {
            p[0x16] = o->idx;
            func_021EA750(p);
            func_021EE038(p, 0, 1, 1);
            return 0x40;
        }
        func_021ED094(WORK(p), ITEM(p));
        func_021ED108(WORK(p), 1);
        func_021EBFA8(WORK(p), 10, 1);
        func_021EC000(WORK(p), 10, 1);
        func_021ED1C8(WORK(p));
        func_020061E4(0x666);
        return func_021E8FC0(p, func_021E122C, 0x43);
    }
}
