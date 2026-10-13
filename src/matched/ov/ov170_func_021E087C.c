/*
 * function: func_021E087C
 * address:  0x021E087C
 * packet:   pkt_ov170_021E087C
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021EF770 0x021EF770 thumb
 *   func_021DE158 0x021DE158 thumb
 *   func_021EE008 0x021EE008 thumb
 *   func_021EF75C 0x021EF75C thumb
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   func_021DD210 0x021DD210 thumb
 *   func_021EC35C 0x021EC35C thumb
 *   func_021DEDCC 0x021DEDCC thumb
 *   func_021DEC98 0x021DEC98 thumb
 *   func_021ED544 0x021ED544 thumb
 *   func_021E00C4 0x021E00C4 thumb
 *   func_021E0128 0x021E0128 thumb
 *   func_021DD930 0x021DD930 thumb
 *   func_021DE66C 0x021DE66C thumb
 *   func_021ED6E4 0x021ED6E4 thumb
 *   func_021E01E0 0x021E01E0 thumb
 *   func_021EF35C 0x021EF35C thumb
 *   func_021EF36C 0x021EF36C thumb
 *   func_021E01B0 0x021E01B0 thumb
 *
 * Drop callback while carrying a Pokemon (block at work + 0x58, template
 * func_021DFA30): changes box if the cursor sits on another box, then
 * settles the carried icon; returns 0 once the drop is finished.
 */

typedef struct {
    unsigned char pad[8];
    void *moves;
    unsigned short state;
    unsigned short timer;
} Blk;

struct WinMgr;
extern int func_021EF770(struct WinMgr *mgr);
extern int func_021DE158(unsigned char *p, unsigned a, unsigned b);
extern void func_021EE008(char *p, int a, int b);
extern void func_021EF75C(struct WinMgr *mgr);
extern void GFL_USE_PlaySeDefaultVolume(unsigned se);
extern int func_021DD210(unsigned char *p, unsigned a, unsigned b);
extern void func_021EC35C(char **p, int box);
extern int func_021DEDCC(char *p, int box);
extern void func_021DEC98(char *p, void *a, int dir);
extern void func_021ED544(char *p, int b);
extern int func_021E00C4(char *p);
extern int func_021E0128(char *p);
extern int func_021DD930(unsigned char *p);
extern void func_021DE66C(unsigned char *p, void *e);
extern void func_021ED6E4(char **p, int v);
extern int func_021E01E0(char *p);
extern void func_021EF35C(struct WinMgr *mgr);
extern void func_021EF36C(struct WinMgr *mgr);
extern int func_021E01B0(unsigned char *p);

#define WORK(p) (*(char **)((p) + 0x2C))
#define MGR(p) (*(struct WinMgr **)(WORK(p) + 0x74))
#define HELD(p) (*(unsigned char *)(WORK(p) + 0xA17E))

int func_021E087C(unsigned char *p)
{
    Blk *b = (Blk *)(WORK(p) + 0x58);
    int r;

    switch (b->state) {
    case 0:
        if (p[0x16] >= 0x1E && func_021EF770(MGR(p)) == 1) {
            if (HELD(p) < 0x1E || HELD(p) == 0xFF || func_021DE158(p, p[0x16], HELD(p)) == 0) {
                func_021EE008((char *)p, 0, 0);
                func_021EF75C(MGR(p));
                GFL_USE_PlaySeDefaultVolume(0x669);
                b->state = 5;
                break;
            }
        }
        if (p[0x16] < 0x1E && p[0x14] != p[0x17]) {
            if (HELD(p) == 0xFF || func_021DE158(p, p[0x16], HELD(p)) == 0) {
                r = func_021DD210(p, p[0x14], p[0x17]);
                p[0x14] = p[0x17];
                func_021EC35C((char **)p, p[0x14]);
                func_021DEC98((char *)p, (void *)func_021DEDCC((char *)p, p[0x14]), r);
                if (r == 0)
                    b->state = 2;
                else
                    b->state = 3;
                break;
            }
        }
    case 1:
        func_021ED544((char *)p, 7);
        func_021DE158(p, p[0x16], HELD(p));
        b->state = 4;
        break;
    case 2:
        if (func_021E00C4((char *)p) == 0)
            b->state = 1;
        break;
    case 3:
        if (func_021E0128((char *)p) == 0)
            b->state = 1;
        break;
    case 4:
        if (func_021DD930(p) == 0) {
            func_021DE66C(p, b->moves);
            func_021ED544((char *)p, 6);
            func_021ED6E4((char **)p, 0);
            GFL_USE_PlaySeDefaultVolume(0x667);
            b->state = 0;
            return 0;
        }
        break;
    case 5:
        if (func_021E01E0((char *)p) == 0) {
            func_021EF35C(MGR(p));
            func_021EF36C(MGR(p));
            GFL_USE_PlaySeDefaultVolume(0x669);
            b->state = 6;
        }
        break;
    case 6:
        if (func_021E01B0(p) == 0)
            b->state = 1;
        break;
    }
    return 1;
}
