/*
 * function: DWCi_EFFlFade
 * address:  0x021D55A4
 * packet:   pkt_ov016_021D55A4
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   <pending>
 *
 * symbols:
 *   G2x_SetBlendBrightness_          0x0207D658  arm
 *   DWCi_TSKlForm                    0x021D7680  arm
 *   bright_tbl                       0x021DAA6C  data
 *   MemEffect                        0x021DE67C  data
 *   taskFade                         0x021D566C  arm
 *
 * SDK: TwlDWC libdwcutil.TWL.HYB.a(effect.o), symbol DWCi_EFFlFade (name and prototype
 * from the vendor object DWARF). Callee of procInit/endScene1 (sceneoptmovconf*).
 *
 * blocker: DIFF. compiled 192 B vs original 200 B. The window-address ternary is a
 * branch in the original but a conditional load here, and the four locals land in a
 * different register set (orig kind=r6 frame=r5 prm=r4 one=r7; compiled kind=r5).
 * bright_tbl 0x021DAA6C has no witness outside this range (data, no pool referrer).
 */
typedef _Bool bool;

struct EFFPRM {
    void *f0;
    unsigned short f4;
    unsigned short f6;
    unsigned char f8;
    unsigned char f9;
    char fA;
    char fB;
};

struct MEMEFFECT {
    struct EFFPRM param[2];
};

extern void G2x_SetBlendBrightness_(unsigned long addr, int plane, int brightness);
extern void *DWCi_TSKlForm(int kind, void (*func)(void *, void *), void *work,
                           unsigned char prio);
extern struct MEMEFFECT *MemEffect;
extern unsigned char bright_tbl[4];

static void taskFade(void *task, void *work);

bool DWCi_EFFlFade(int kind, int lcd, int plane, int frame)
{
    signed char BRIGHT[4];
    struct EFFPRM *prm;
    unsigned long addr;
    int ok;

    BRIGHT[0] = bright_tbl[0];
    BRIGHT[1] = bright_tbl[1];
    BRIGHT[2] = bright_tbl[2];
    BRIGHT[3] = bright_tbl[3];
    if (lcd == 1)
        prm = &MemEffect->param[0];
    else
        prm = &MemEffect->param[1];
    if (prm->f9 != 0)
        return 0;
    if (lcd == 1)
        addr = 0x04001050;
    else
        addr = 0x04000050;
    G2x_SetBlendBrightness_(addr, plane, BRIGHT[kind]);
    ok = 1;
    prm->f0 = DWCi_TSKlForm(ok, taskFade, prm, 0xc8);
    prm->f4 = 0;
    prm->f8 = kind;
    prm->f6 = frame;
    prm->f9 = ok;
    return ok;
}
