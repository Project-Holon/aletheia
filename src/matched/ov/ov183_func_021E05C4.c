/*
 * function: func_021E05C4
 * address: 0x021E05C4
 * packet: pkt_ov183_021E05C4
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: 021E0616 alignment padding; next owned function starts 021E0618.
 * symbols:
 *   func_021FD15C 0x021FD15C thumb ov186
 *   func_021E0774 0x021E0774 thumb ov183
 *   func_021E0808 0x021E0808 thumb ov183
 *   PRINTSYS_QUE_Delete 0x0201C4C0 thumb
 *   func_021FD820 0x021FD820 thumb ov186
 *   BR_RES_ApplyBgSet 0x021FBDA4 thumb ov186
 *   BR_RES_ReleaseSprite 0x021FC0C8 thumb ov186
 *   func_020315D4 0x020315D4 arm
 */
extern void func_021FD15C(void *p, int a1);
struct PrintSys;
struct S020315D4;
extern void func_021E0774(char *p);
extern void func_021E0808(char *p);
extern void PRINTSYS_QUE_Delete(struct PrintSys *p);
extern void func_021FD820(char *r5);
extern void BR_RES_ApplyBgSet(int a, unsigned mode);
extern void BR_RES_ReleaseSprite(char *p, unsigned i);
extern void func_020315D4(struct S020315D4 *p);
int func_021E05C4(void *a, int unused, int *q, void **p)
{
    func_021FD15C((void *)((int)p[2]), q[2]);
    func_021E0774(p[1]);
    func_021E0808(p[0]);
    PRINTSYS_QUE_Delete(p[3]);
    func_021FD820(p[5]);
    BR_RES_ApplyBgSet(q[2], 29);
    BR_RES_ReleaseSprite((char *)q[2], 6);
    BR_RES_ReleaseSprite((char *)q[2], 12);
    BR_RES_ReleaseSprite((char *)q[2], 11);
    func_020315D4(a);
    return 1;
}
