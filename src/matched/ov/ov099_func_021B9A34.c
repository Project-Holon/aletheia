/*
 * function: func_021B9A34
 * address:  0x021B9A34
 * packet:   pkt_ov099_021BF2C4
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Blocker: callee 0x021C4948 (ov127) is unlabelled in the ov127 listing
 * ("ldr r3, =0x02082BCC; movs r1, #0; movs r2, #0x18; bx r3"); witness
 * bl from ov099 at 0x021B9A40. Seeding it (ov127 lane) makes this EXACT.
 *
 * symbols:
 *   func_02082BCC  0x02082BCC  arm
 *   func_021C4948  0x021C4948  thumb  ov127
 *   func_021C5704  0x021C5704  thumb  ov127
 */
extern void func_021C5704(void *p);
extern void func_021C4948(void *p);
extern void func_02082BCC(void *p, int v, int n);

typedef struct {
    void *f0;
    void *f4;
    char pad[0x14];
} Obj;

void func_021B9A34(Obj *p)
{
    func_021C5704(p->f4);
    func_021C4948(p->f0);
    func_02082BCC(p, 0, sizeof(Obj));
}
