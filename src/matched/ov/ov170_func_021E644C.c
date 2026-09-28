/*
 * function: func_021E644C
 * address:  0x021E644C
 * packet:   pkt_ov170_021E644C
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021ED55C 0x021ED55C thumb
 *   func_021EF480 0x021EF480 thumb
 *   func_021DD14C 0x021DD14C thumb
 *   func_021DEFEC 0x021DEFEC thumb
 *   func_021EBA5C 0x021EBA5C thumb
 *   func_021ED6E4 0x021ED6E4 thumb
 *   func_021EF57C 0x021EF57C thumb
 *   func_021E8FC0 0x021E8FC0 thumb
 *   func_021E0ED4 0x021E0ED4 thumb
 *   func_021EF3D8 0x021EF3D8 thumb
 *   func_021EF35C 0x021EF35C thumb
 *   func_021EF36C 0x021EF36C thumb
 *   func_021EC5A0 0x021EC5A0 thumb
 *   func_020061E4 0x020061E4 thumb
 *   func_021E01B0 0x021E01B0 thumb
 *   func_021ECB20 0x021ECB20 thumb
 *   func_021ED888 0x021ED888 thumb
 *   func_021EE364 0x021EE364 thumb
 *   func_021ED544 0x021ED544 thumb
 *   func_02026124 0x02026124 thumb
 *   func_021EE038 0x021EE038 thumb
 *   func_021ED508 0x021ED508 thumb
 *   func_021EA458 0x021EA458 thumb
 *
 * Three-step machine on the work word at 0xA194: close the held view,
 * fade, then reopen the menu for the current nibble mode.
 */

typedef struct {
    unsigned char lo : 4;
    unsigned char hi : 4;
} Nib;

extern void func_021ED55C(unsigned char *p, int flag);
extern int func_021EF480(int a);
extern void func_021DD14C(unsigned char *p);
extern void func_021DEFEC(unsigned char *p, int b);
extern void func_021EBA5C(char *w, int v);
extern void func_021ED6E4(unsigned char *p, int v);
extern void func_021EF57C(int mgr);
extern int func_021E8FC0(unsigned char *p, int (*cb)(unsigned char *), int n);
extern int func_021E0ED4(unsigned char *p);
extern void func_021EF3D8(int a);
extern void func_021EF35C(int a);
extern void func_021EF36C(int a);
extern void func_021EC5A0(unsigned char *p, int flag);
extern void func_020061E4(unsigned se);
extern int func_021E01B0(unsigned char *p);
extern void func_021ECB20(unsigned char *p, int f, int c);
extern void func_021ED888(char *w, int a);
extern void func_021EE364(unsigned char *p, int idx, int v);
extern void func_021ED544(unsigned char *p, int b);
extern void func_02026124(void *obj, unsigned idx);
extern void func_021EE038(unsigned char *p, int a, int b, int c);
extern void func_021ED508(unsigned char *p, int a, int b);
extern int func_021EA458(unsigned char *p, unsigned i);

#define WORK(p) (*(char **)((p) + 0x2C))
#define OBJ(p) (*(void **)(WORK(p) + 0x70))
#define MGR(p) (*(int *)(WORK(p) + 0x74))
#define STEP(p) (*(int *)(WORK(p) + 0xA194))
#define NIB(p) ((Nib *)((p) + 0x1C))

int func_021E644C(unsigned char *p)
{
    switch (STEP(p)) {
    case 0:
        STEP(p)++;
        func_021ED55C(p, 0);
        if (func_021EF480(MGR(p)) == 1)
            p[0x1E] = 1;
        else
            p[0x1E] = 0;
        if (NIB(p)->lo == 1) {
            p[0x17] = 0xFF;
            *(unsigned short *)(WORK(p) + 0xA16C) = 0;
            func_021DD14C(p);
            func_021DEFEC(p, p[0x16]);
        } else {
            if (NIB(p)->lo == 2 && *(unsigned short *)(WORK(p) + 0xA16C) == 0) {
                p[0x17] = 0xFF;
                NIB(p)->lo = 1;
            }
            func_021EBA5C(WORK(p), 0x18);
            func_021DD14C(p);
            func_021ED6E4(p, 0);
            func_021EF57C(MGR(p));
            return func_021E8FC0(p, func_021E0ED4, 0x3F);
        }
    case 1:
        STEP(p)++;
        if (func_021EF480(MGR(p)) == 1) {
            func_021EF3D8(MGR(p));
        } else {
            func_021EF35C(MGR(p));
            func_021EF36C(MGR(p));
            func_021EC5A0(p, 0);
        }
        func_020061E4(0x669);
        return func_021E8FC0(p, func_021E01B0, 0x3F);
    case 2:
        STEP(p) = 0;
        func_021ECB20(p, 0x81, 1);
        func_021ECB20(p, 0x82, 1);
        func_021ED888(WORK(p), 1);
        func_021EE364(p, 6, p[0x16]);
        func_021ED544(p, 6);
        func_02026124(OBJ(p), 0x27);
        func_02026124(OBJ(p), 0x28);
        if (NIB(p)->lo == 1) {
            func_021EE038(p, 0, 1, 1);
            func_021ED508(p, 0xD, 1);
            return 0x40;
        }
        if (NIB(p)->lo == 2)
            func_021ED508(p, 0xD, 1);
        else
            func_021ED508(p, 0xE, 1);
        func_021EE038(p, 2, 1, 1);
        return func_021EA458(p, p[0x16]);
    }
    return 0x3F;
}
