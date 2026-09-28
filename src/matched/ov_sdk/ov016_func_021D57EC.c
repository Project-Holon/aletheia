/*
 * function: taskWait
 * address:  0x021D57EC
 * packet:   pkt_ov016_021D57EC
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      taskWait (effect.o), TwlDWC libdwcutil.TWL.HYB.a
 *
 * symbols:
 *   DWCi_TSKlDelete                  0x021D7724  arm
 */
struct EFFPRM {
    char pad[4];
    short count;
    unsigned short max;
    unsigned char f8;
    unsigned char f9;
};

extern void DWCi_TSKlDelete(int kind, void *task);

static void taskWait(void *task, void *work)
{
    struct EFFPRM *prm = work;

    prm->count++;
    if (prm->count < prm->max)
        return;
    prm->f9 = 0;
    DWCi_TSKlDelete(1, task);
}
