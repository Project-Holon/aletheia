/*
 * function: func_021E3340
 * address:  0x021E3340
 * packet:   pkt_ov170_021E3340
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021DD530 0x021DD530 thumb
 *   func_020260E0 0x020260E0 thumb
 *   func_020260E4 0x020260E4 thumb
 *   func_021EE3E4 0x021EE3E4 thumb
 *   func_021ED55C 0x021ED55C thumb
 *   func_021EA1E8 0x021EA1E8 thumb
 *   func_021EF770 0x021EF770 thumb
 *   func_021EE364 0x021EE364 thumb
 *   func_021DEFEC 0x021DEFEC thumb
 *   func_021DD25C 0x021DD25C thumb
 *   func_021EF45C 0x021EF45C thumb
 *   func_021DF040 0x021DF040 thumb
 *   func_021EE038 0x021EE038 thumb
 *   func_020061E4 0x020061E4 thumb
 *   func_021EBD1C 0x021EBD1C thumb
 *   func_021EBD78 0x021EBD78 thumb
 *   func_021EF670 0x021EF670 thumb
 *   func_021EF68C 0x021EF68C thumb
 *
 * Re-entry of the box menu: restores the cursor, redraws the box and picks
 * the message for the current mode.
 */

struct WinMgr;
extern void func_021DD530(unsigned char *p);
typedef unsigned char  u8;
struct Sound;
extern u8 func_020260E0(struct Sound *obj);
extern void func_020260E4(struct Sound *obj, u8 sel);
extern void func_021EE3E4(unsigned char *p, unsigned idx);
extern void func_021ED55C(unsigned char *p, int flag);
extern void func_021EA1E8(unsigned char *p);
extern int func_021EF770(struct WinMgr *mgr);
extern void func_021EE364(unsigned char *p, int idx, int v);
extern void func_021DEFEC(unsigned char *p, int b);
extern unsigned func_021DD25C(unsigned char *p, unsigned short a, int box, unsigned id, unsigned v);
extern int func_021EF45C(struct WinMgr *mgr);
extern void func_021DF040(unsigned char *p);
extern void func_021EE038(unsigned char *p, int a, int b, int c);
extern void func_020061E4(unsigned se);
extern void func_021EBD1C(unsigned char *p, int row, int b);
extern void func_021EBD78(unsigned char *p, int b);
extern void func_021EF670(char *w);
extern void func_021EF68C(char *w);

#define WORK(p) (*(char **)((p) + 0x2C))
#define OBJ(p) (*(void **)(WORK(p) + 0x70))
#define MGR(p) (*(struct WinMgr **)(WORK(p) + 0x74))
#define MODE(p) (*(unsigned char *)(WORK(p) + 0xA173))
#define STATE(p) (*(int *)((p) + 0x28))

typedef struct {
    unsigned char lo : 4;
    unsigned char hi : 4;
} Nib;

int func_021E3340(unsigned char *p)
{
    unsigned char sel;
    int arg;
    func_021DD530(p);
    p[0x18] = 0;
    p[0x17] = 0xFF;
    if (MODE(p) == 0) {
        sel = func_020260E0(OBJ(p));
    } else {
        func_020260E4(OBJ(p), p[0x16]);
        func_021EE3E4(p, p[0x16]);
        func_021ED55C(p, 1);
        sel = p[0x16];
    }
    *(int *)(WORK(p) + 0xA168) = sel;
    func_021EA1E8(p);
    if (func_021EF770(MGR(p)) == 1) {
        if (STATE(p) == 0x20) {
            func_021EE364(p, 4, sel);
            func_021DEFEC(p, sel);
            STATE(p) = 0x15;
            if (func_021DD25C(p, sel, p[0x14], 0xA9, 0))
                arg = 0;
            else
                arg = 2;
        } else if (sel < 0x1E && func_021DD25C(p, sel, p[0x14], 0xA9, 0)) {
            func_021DEFEC(p, sel);
            arg = 0;
        } else {
            func_021DF040(p);
            arg = 2;
        }
    } else if (func_021EF45C(MGR(p)) == 1) {
        if (STATE(p) == 0x15) {
            sel = func_020260E0(OBJ(p));
            if (sel > 0x20)
                sel = p[0x16];
            func_021EE364(p, 6, sel);
            func_021DEFEC(p, sel);
            STATE(p) = 0x20;
            if (func_021DD25C(p, sel, p[0x14], 0xA9, 0))
                arg = 0;
            else
                arg = 2;
        } else if (sel < 0x24 && func_021DD25C(p, sel, p[0x14], 0xA9, 0)) {
            func_021DEFEC(p, sel);
            arg = 0;
        } else {
            func_021DF040(p);
            arg = 2;
        }
    } else if (sel < 0x24 && func_021DD25C(p, sel, p[0x14], 0xA9, 0)) {
        func_021DEFEC(p, sel);
        arg = 0;
    } else {
        func_021DF040(p);
        arg = 2;
    }
    if (((Nib *)(p + 0x1C))->lo == 0) {
        ((Nib *)(p + 0x1C))->hi = 1;
        arg = p[0x21];
    }
    func_021EE038(p, 0, 1, arg);
    switch (MODE(p)) {
    case 2:
        func_020061E4(0x557);
        func_021ED55C(p, 0);
        func_021EBD1C(p, 2, 0x18);
        return 0x18;
    case 3:
        func_020061E4(0x557);
        func_021ED55C(p, 0);
        func_021EBD1C(p, 3, 0x18);
        return 0x18;
    case 4:
        func_020061E4(0x557);
        func_021ED55C(p, 0);
        func_021EBD1C(p, 4, 0x18);
        return 0x18;
    case 5:
        func_020061E4(0x557);
        func_021ED55C(p, 0);
        func_021EBD78(p, 0);
        return 0x18;
    }
    if (*(int *)(*(char **)p + 0x24) == 2) {
        if (func_021EF770(MGR(p)) == 1)
            func_021EF670(WORK(p));
        else
            func_021EF68C(WORK(p));
    }
    return STATE(p);
}
