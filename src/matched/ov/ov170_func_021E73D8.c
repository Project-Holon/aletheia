/*
 * function: func_021E73D8
 * address:  0x021E73D8
 * packet:   pkt_ov170_021E73D8
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021EBFEC 0x021EBFEC thumb
 *   func_021ED108 0x021ED108 thumb
 *   func_021EC000 0x021EC000 thumb
 *   func_021DD25C 0x021DD25C thumb
 *   func_021DD2B4 0x021DD2B4 thumb
 *   func_021DD2D0 0x021DD2D0 thumb
 *   func_021DD718 0x021DD718 thumb
 *   func_021DD8A8 0x021DD8A8 thumb
 *   func_021EC48C 0x021EC48C thumb
 *   func_021DEFEC 0x021DEFEC thumb
 *   func_021EA750 0x021EA750 thumb
 *   func_021EF68C 0x021EF68C thumb
 *   func_020260E4 0x020260E4 thumb
 *   func_020260F4 0x020260F4 thumb
 *   func_020061E4 0x020061E4 thumb
 *   func_021ED094 0x021ED094 thumb
 *   func_021EBFA8 0x021EBFA8 thumb
 *   func_021ED1C8 0x021ED1C8 thumb
 *   func_021E8F50 0x021E8F50 thumb
 *   func_021E8FC0 0x021E8FC0 thumb
 *   func_021E1988 0x021E1988 thumb
 *
 * Item swap on drop (template 021E6A60): moves the held item onto the
 * target slot, returns the target's old item to the source, and either
 * finishes or keeps the new item held.
 */

typedef struct {
    unsigned short idx;
    unsigned short slot;
} Entry;

extern unsigned int func_021EBFEC(char *p, int i);
extern void func_021ED108(char *w, int on);
extern void func_021EC000(char *w, int i, int v);
extern unsigned func_021DD25C(void ***p, unsigned short a, int box, unsigned id, unsigned v);
extern void func_021DD2B4(int a, int b, int c, int d, int e);
extern int func_021DD2D0(void ***p, int a, unsigned b);
extern int func_021DD718(void **pp, void *mon);
extern void func_021DD8A8(unsigned char *p, unsigned idx);
extern void func_021EC48C(unsigned char *p, int box, int pos, int win);
extern void func_021DEFEC(char *p, int b);
extern void func_021EA750(char *p);
extern void func_021EF68C(char *w);
typedef unsigned int   u32;
typedef unsigned char  u8;
struct Sound;
struct Struct_02025CD0;
extern void func_020260E4(struct Sound *obj, u8 sel);
extern void func_020260F4(struct Struct_02025CD0 *obj, u32 state);
extern void func_020061E4(unsigned se);
extern void func_021ED094(char *w, unsigned item);
extern void func_021EBFA8(char *w, int i, int v);
extern void func_021ED1C8(char *w);
extern int func_021E8F50(char *p, int v);
extern int func_021E8FC0(char *p, int a, int b);
extern int func_021E1988(unsigned char *p);

#define WORK(p) (*(char **)((p) + 0x2C))
#define OBJ(p) (*(void **)(WORK(p) + 0x70))
#define ITEM(p) (*(unsigned short *)(WORK(p) + 0xA16C))
#define WIN(p, i) (*(unsigned char *)(WORK(p) + (i) + 0x3DD2))

int func_021E73D8(unsigned char *p)
{
    Entry *o;
    unsigned short item;

    if (func_021EBFEC(WORK(p), 10) == 1)
        return 0x49;
    func_021ED108(WORK(p), 0);
    func_021EC000(WORK(p), 10, 0);
    o = *(Entry **)(WORK(p) + 0x60);
    item = func_021DD25C((void ***)p, o->idx, p[0x14], 6, 0);
    func_021DD2B4((int)p, o->idx, p[0x14], 6, ITEM(p));
    if (func_021DD718((void **)p, (void *)func_021DD2D0((void ***)p, p[0x14], o->idx)) == 1) {
        func_021DD8A8(p, o->idx);
        func_021EC48C(p, p[0x14], o->idx, WIN(p, o->idx));
    }
    func_021DEFEC((char *)p, o->idx);
    ITEM(p) = item;
    func_021DD2B4((int)p, p[0x16], p[0x17], 6, ITEM(p));
    if (p[0x17] == 0xFF || p[0x17] == p[0x14]) {
        if (func_021DD718((void **)p, (void *)func_021DD2D0((void ***)p, p[0x14], p[0x16])) == 1) {
            func_021DD8A8(p, p[0x16]);
            func_021EC48C(p, p[0x14], p[0x16], WIN(p, p[0x16]));
        }
    }
    if (ITEM(p) == 0) {
        p[0x16] = o->idx;
        func_021EA750((char *)p);
        func_021EF68C(WORK(p));
        func_020260E4(OBJ(p), p[0x16] - 0x1E);
        func_021DEFEC((char *)p, p[0x16]);
        func_020260F4(OBJ(p), 1);
        return 0x46;
    }
    func_020061E4(0x666);
    func_021ED094(WORK(p), ITEM(p));
    func_021ED108(WORK(p), 1);
    func_021EBFA8(WORK(p), 10, 1);
    func_021EC000(WORK(p), 10, 1);
    func_021ED1C8(WORK(p));
    return func_021E8FC0((char *)p, (int)func_021E1988, func_021E8F50((char *)p, 0x4A));
}
