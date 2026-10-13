/*
 * function: DWCi_TSKlForm
 * address:  0x021D7680
 * packet:   pkt_ov016_021D7680
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   formTask                     0x021D7694  arm
*/

typedef struct TCB TCB;

extern TCB *formTask(int kind, void (*func)(void *, void *), void *work, unsigned char prio, unsigned char alloc);

TCB *DWCi_TSKlForm(int kind, void (*func)(void *, void *), void *work, unsigned char prio)
{
    return formTask(kind, func, work, prio, 0);
}
