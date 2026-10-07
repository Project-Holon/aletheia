/*
 * file:     unit_021D551C_p03.c
 * unit:     yes
 * function: func_021D5790, func_021D57EC
 * address:  0x021D5790
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   DWCi_TSKlForm                    0x021D7680  arm
 *   MemEffect                        0x021DE67C  data
 *   DWCi_TSKlDelete                  0x021D7724  arm
 */
typedef _Bool bool;

struct EFFPRM_021D5790 {
    void          *task;
    short          count;
    unsigned short max;
    unsigned char  f8;
    unsigned char  f9;
    char           pad[2];
};

struct MEMEFFECT {
    struct EFFPRM_021D5790 param[2];
};

struct EFFPRM_021D57EC {
    char pad[4];
    short count;
    unsigned short max;
    unsigned char f8;
    unsigned char f9;
};

extern void *DWCi_TSKlForm(int kind, void (*func)(void *, void *), void *work,
                           unsigned char prio);
extern void DWCi_TSKlDelete(int kind, void *task);
bool DWCi_EFFlWait(int frame);
extern struct MEMEFFECT *MemEffect;


static void taskWait(void *task, void *work);


bool DWCi_EFFlWait(int frame)
{
    struct EFFPRM_021D5790 *prm = MemEffect->param;

    if (prm->f9 != 0)
        return 0;
    prm->task = DWCi_TSKlForm(1, taskWait, prm, 0xc8);
    prm->count = 0;
    prm->max = frame;
    prm->f9 = 1;
    return 1;
}


static void taskWait(void *task, void *work)
{
    struct EFFPRM_021D57EC *prm = work;

    prm->count++;
    if (prm->count < prm->max)
        return;
    prm->f9 = 0;
    DWCi_TSKlDelete(1, task);
}
