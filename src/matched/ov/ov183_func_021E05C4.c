/*
 * function: BR_CODEIN_ProfileScreenDestroy
 * address: 0x021E05C4
 * packet: pkt_ov183_021E05C4
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: 021E0616 alignment padding; next owned function starts 021E0618.
 * symbols:
 *   BR_UTIL_DeleteTextWin 0x021FD15C thumb ov186
 *   BR_CODEIN_ProfileDestroy 0x021E0774 thumb ov183
 *   BR_CODEIN_ProfileDestroyObject 0x021E0808 thumb ov183
 *   PRINTSYS_QUE_Delete 0x0201C4C0 thumb
 *   BR_UTIL_DeleteHandles 0x021FD820 thumb ov186
 *   BR_RES_ApplyBgSet 0x021FBDA4 thumb ov186
 *   BR_RES_ReleaseSprite 0x021FC0C8 thumb ov186
 *   func_020315D4 0x020315D4 arm
 */
extern void BR_UTIL_DeleteTextWin(void *p, int a1);
struct PrintSys;
struct Proc;
extern void BR_CODEIN_ProfileDestroy(char *p);
extern void BR_CODEIN_ProfileDestroyObject(char *p);
extern void PRINTSYS_QUE_Delete(struct PrintSys *p);
extern void BR_UTIL_DeleteHandles(char *r5);
extern void BR_RES_ApplyBgSet(int a, unsigned mode);
extern void BR_RES_ReleaseSprite(char *p, unsigned i);
extern void func_020315D4(struct Proc *p);
int BR_CODEIN_ProfileScreenDestroy(void *a, int unused, int *q, void **p)
{
    BR_UTIL_DeleteTextWin((void *)((int)p[2]), q[2]);
    BR_CODEIN_ProfileDestroy(p[1]);
    BR_CODEIN_ProfileDestroyObject(p[0]);
    PRINTSYS_QUE_Delete(p[3]);
    BR_UTIL_DeleteHandles(p[5]);
    BR_RES_ApplyBgSet(q[2], 29);
    BR_RES_ReleaseSprite((char *)q[2], 6);
    BR_RES_ReleaseSprite((char *)q[2], 12);
    BR_RES_ReleaseSprite((char *)q[2], 11);
    func_020315D4(a);
    return 1;
}
