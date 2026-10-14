/*
 * function: ZKND_TBAR_DeleteButtonList
 * address: 0x021BD208
 * packet: pkt_ov208_021BD208
 * region: ov208
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   ZKND_TBAR_DeleteButton 0x021BD74C thumb
 *   ZKND_TBAR_ReleaseButtonResources 0x021BD538 thumb
 *   func_020307B0 0x020307B0 arm
 */
typedef unsigned int u32;
struct Ov208Item { char b[0x38]; };
struct Ov208Mgr { int f0; u32 count; int f8; int fc; int f10; char f14[0x14]; struct Ov208Item items[1]; };
extern void ZKND_TBAR_DeleteButton(char *p);
extern void ZKND_TBAR_ReleaseButtonResources(char *p);
extern u32 func_020307B0(void *p);
void ZKND_TBAR_DeleteButtonList(struct Ov208Mgr *m)
{
    u32 i;
    for (i = 0; i < m->count; i++)
        ZKND_TBAR_DeleteButton((char *)(&m->items[i]));
    ZKND_TBAR_ReleaseButtonResources(m->f14);
    func_020307B0(m);
}
