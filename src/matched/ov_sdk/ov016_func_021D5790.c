/*
 * function: DWCi_EFFlWait
 * address:  0x021D5790
 * packet:   pkt_ov016_021D5790
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_EFFlWait (effect.o), TwlDWC libdwcutil.TWL.HYB.a
 *
 * symbols:
 *   DWCi_TSKlForm                    0x021D7680  arm
 *   MemEffect                        0x021DE67C  data
 *   taskWait                         0x021D57EC  arm
 */
typedef _Bool bool;

struct EFFPRM {
    void          *task;
    short          count;
    unsigned short max;
    unsigned char  f8;
    unsigned char  f9;
    char           pad[2];
};

struct MEMEFFECT {
    struct EFFPRM param[2];
};

extern struct MEMEFFECT *MemEffect;
extern void *DWCi_TSKlForm(int kind, void (*func)(void *, void *), void *work,
                           unsigned char prio);

static void taskWait(void *task, void *work);

bool DWCi_EFFlWait(int frame)
{
    struct EFFPRM *prm = MemEffect->param;

    if (prm->f9 != 0)
        return 0;
    prm->task = DWCi_TSKlForm(1, taskWait, prm, 0xc8);
    prm->count = 0;
    prm->max = frame;
    prm->f9 = 1;
    return 1;
}
