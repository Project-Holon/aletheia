/*
 * function: BOX2_MAIN_CompactParty
 * address: 0x021DD464
 * packet: pkt_ov170_021DD464
 * region: ov170
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BOX2_MAIN_GetMonAt 0x021DD2D0 thumb ov170
 *   BOX2_MAIN_WrapSlot 0x021DD684 thumb ov170
 *   BOX2_UI_DrawSlot 0x021EDAB0 thumb ov170
 *   BOX2_UI_DrawSlotByName 0x021EDB34 thumb ov170
 *   func_0200752C 0x0200752C thumb
 *   func_02007664 0x02007664 thumb
 */
extern int BOX2_MAIN_GetMonAt(void ***p, int a, unsigned b);
extern int BOX2_MAIN_WrapSlot(unsigned char *,unsigned);
typedef unsigned int   u32;
struct Sub02007454Entry;
extern int func_0200752C(void **save, u32 box, const struct Sub02007454Entry *src);
extern void func_02007664(void *,unsigned,unsigned);
extern void BOX2_UI_DrawSlot(char *p, int i);
extern void BOX2_UI_DrawSlotByName(char *p, int a);
void BOX2_MAIN_CompactParty(unsigned char *p,unsigned a,unsigned b,unsigned c)
{
    void *m;
    unsigned box;
    m = (void *)BOX2_MAIN_GetMonAt((void ***)p,a,b);
    box = BOX2_MAIN_WrapSlot(p,c);
    func_0200752C((*(void ***)p)[1],box,m);
    func_02007664((*(void ***)p)[1],a,b);
    BOX2_UI_DrawSlot((char *)p,a);
    BOX2_UI_DrawSlotByName((char *)p,a);
    BOX2_UI_DrawSlot((char *)p,box);
    BOX2_UI_DrawSlotByName((char *)p,box);
}
