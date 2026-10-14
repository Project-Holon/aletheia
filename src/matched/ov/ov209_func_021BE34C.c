/*
 * function: ZUKAN_LIST_ScrollActorsBy
 * address: 0x021BE34C
 * packet: pkt_ov209_021BE34C
 * region: ov209
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * prototype: D934 index is unsigned; original i+16 has no signed CSE spill. Signed halfword coordinates match the caller's ldrsh/truncation and BE29C.
 * symbols:
 *   ZUKAN_LIST_GetActorVisible 0x021BD8F4 thumb ov209
 *   ZUKAN_LIST_GetActorPos 0x021BD958 thumb ov209
 *   ZUKAN_LIST_AddActorPos 0x021BD934 thumb ov209
 *   ZUKAN_LIST_SetActorVisible 0x021BD8D8 thumb ov209
 */
typedef unsigned short u16;
extern unsigned int ZUKAN_LIST_GetActorVisible(char *p, unsigned int idx);
typedef signed short   s16;
typedef unsigned int   u32;
extern void ZUKAN_LIST_GetActorPos(char *p, u32 idx, s16 *x, s16 *y, u16 space);
extern void ZUKAN_LIST_AddActorPos(char *p, int idx, short a, short b, unsigned short c);
extern void ZUKAN_LIST_SetActorVisible(char *p, u32 idx, u32 value);
void ZUKAN_LIST_ScrollActorsBy(char *p, int delta)
{
    unsigned i;
    short pos[2];
    for (i = 10; i < 26; i++) {
        if (ZUKAN_LIST_GetActorVisible((char *)p, i) != 0) {
            ZUKAN_LIST_GetActorPos(p, i, &pos[1], &pos[0], 0);
            ZUKAN_LIST_AddActorPos(p, (unsigned)i, (short)pos[1], (short)(pos[0] + delta), 0);
            if (pos[0] + delta <= -16 || pos[0] + delta >= 200)
                ZUKAN_LIST_SetActorVisible(p, i, 0);
        }
    }
    for (i = 26; i < 42; i++) {
        if (ZUKAN_LIST_GetActorVisible((char *)p, i) != 0) {
            ZUKAN_LIST_GetActorPos(p, i, &pos[1], &pos[0], 1);
            ZUKAN_LIST_AddActorPos(p, (unsigned)i, (short)pos[1], (short)(pos[0] + delta), 1);
            ZUKAN_LIST_AddActorPos(p, (unsigned)(i + 16), (short)pos[1], (short)(pos[0] + delta), 1);
            if (pos[0] + delta <= -16 || pos[0] + delta >= 200) {
                ZUKAN_LIST_SetActorVisible(p, i, 0);
                ZUKAN_LIST_SetActorVisible(p, i + 16, 0);
            }
        }
    }
}
