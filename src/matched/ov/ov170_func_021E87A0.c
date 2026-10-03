/*
 * function: func_021E87A0
 * address:  0x021E87A0
 * packet:   pkt_ov170_021E87A0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021EF1D4 0x021EF1D4 thumb
 *   func_021EA808 0x021EA808 thumb
 *   func_020260F4 0x020260F4 thumb
 *   func_02025DE8 0x02025DE8 thumb
 *   func_020061E4 0x020061E4 thumb
 *   func_021DD1C4 0x021DD1C4 thumb
 *   func_021E8FC0 0x021E8FC0 thumb
 *   func_021E1ACC 0x021E1ACC thumb
 *   func_021E1A78 0x021E1A78 thumb
 *   func_021EE008 0x021EE008 thumb
 *   func_021EA798 0x021EA798 thumb
 *   func_021E8F50 0x021E8F50 thumb
 *   func_021E954C 0x021E954C thumb
 *   func_021E8FE0 0x021E8FE0 thumb
 *   func_021E8FD0 0x021E8FD0 thumb
 *   func_020260E0 0x020260E0 thumb
 *
 * List input for the box menu: a touch pick stores the slot and leaves,
 * otherwise the list result selects a page, a jump, or a cancel.
 */

extern int func_021EF1D4(unsigned *a, unsigned *b);
extern void func_021EA808(unsigned char *p);
typedef unsigned int   u32;
typedef unsigned char  u8;
struct Sound;
struct Struct_02025CD0;
extern void func_020260F4(struct Struct_02025CD0 *obj, u32 state);
extern int func_02025DE8(struct Sound *obj);
extern u8 func_020260E0(struct Sound *obj);
extern void func_020061E4(unsigned se);
extern void func_021DD1C4(unsigned char *p, int a);
extern int func_021E8FC0(unsigned char *p, int (*cb)(unsigned char *), int n);
extern int func_021E1ACC(unsigned char *p);
extern int func_021E1A78(unsigned char *p);
extern void func_021EE008(unsigned char *p, int a, int b);
extern int func_021EA798(unsigned char *p, int sel);
extern int func_021E8F50(unsigned char *p, int v);
extern int func_021E954C(unsigned char *p, int id, int lo, int arg);
extern int func_021E8FE0(unsigned char *p, int v);
extern int func_021E8FD0(unsigned char *p, int a);

#define WORK(p) (*(char **)((p) + 0x2C))
#define LIST(p) (*(void **)(WORK(p) + 0x70))
#define STATE(p) (*(int *)((p) + 0x28))
#define CUR(p) (*(unsigned char *)(WORK(p) + 0xA17F))

int func_021E87A0(unsigned char *p)
{
    unsigned x, y;
    unsigned r;

    if (func_021EF1D4(&x, &y) == 1) {
        *(unsigned *)(WORK(p) + 0xA184) = y;
        STATE(p) = 0x61;
        func_021EA808(p);
        func_020260F4(LIST(p), 0);
        return 0xF;
    }
    r = func_02025DE8(LIST(p));
    switch (r) {
    case 0:
        func_020061E4(0x548);
        func_021DD1C4(p, -1);
        return func_021E8FC0(p, func_021E1ACC, 0x61);
    case 5:
        func_020061E4(0x548);
        func_021DD1C4(p, 1);
        return func_021E8FC0(p, func_021E1A78, 0x61);
    case 1:
    case 2:
    case 3:
    case 4:
        CUR(p) = p[0x19] + r - 1;
        if (CUR(p) >= p[0x15])
            CUR(p) -= p[0x15];
        if (CUR(p) != p[0x14]) {
            func_021EE008(p, 0, 0);
            return func_021EA798(p, 1);
        }
        func_020061E4(0x548);
        func_021EE008(p, r - 1, 1);
        break;
    case 6:
    case (unsigned)-2:
        func_020061E4(0x551);
        return func_021E954C(p, 6, 9, func_021E8F50(p, 0x62));
    case (unsigned)-3:
        func_020061E4(0x548);
        return func_021E8FD0(p, func_021E8FE0(p, 0x61));
    case (unsigned)-8:
        if (func_020260E0(LIST(p)) == 1) {
            func_020061E4(0x548);
            func_021DD1C4(p, -1);
            return func_021E8FC0(p, func_021E1ACC, 0x61);
        }
        break;
    case (unsigned)-7:
        if (func_020260E0(LIST(p)) == 4) {
            func_020061E4(0x548);
            func_021DD1C4(p, 1);
            return func_021E8FC0(p, func_021E1A78, 0x61);
        }
        break;
    }
    return 0x61;
}
