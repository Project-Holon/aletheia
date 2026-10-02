/*
 * function: func_021E7CD0
 * address: 0x021E7CD0
 * packet: pkt_ov177_021E7CD0
 * region: ov177
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 */
typedef struct { char pad[0x68]; void *obj[5]; } Work;
extern void func_0204B3B4(void *);
void func_021E7CD0(Work *p)
{
    int i;
    for (i = 0; i < 5; i++) {
        if (p->obj[i] != 0) {
            func_0204B3B4(p->obj[i]);
            p->obj[i] = 0;
        }
    }
}
