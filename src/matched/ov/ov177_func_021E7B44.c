/*
 * function: func_021E7B44
 * address: 0x021E7B44
 * packet: pkt_ov177_021E7B44
 * region: ov177
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 */
typedef struct { void *pad0; void *res[8]; } Work;
struct Descriptor;
extern void func_020456F8(struct Descriptor *d);
extern void func_020452E8(struct Descriptor *d);
void func_021E7B44(Work *p)
{
    int i;
    for (i = 0; i < 8; i++) {
        if (p->res[i] != 0) {
            func_020456F8(p->res[i]);
            func_020452E8(p->res[i]);
        }
    }
}
