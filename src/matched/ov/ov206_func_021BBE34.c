/*
 * function: ZUKAN_INFO_SetSlotDrawEnable
 * address: 0x021BBE34
 * packet: pkt_ov206_021BBE34
 * region: ov206
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   ZUKAN_INFO_SetDrawEnable 0x021BBDA8 thumb ov206
 */
typedef struct S {
    char pad0[8];
    int f8;
    char pad0c[0xac - 0xc];
    void *last[2];
    int index;
} S;
typedef unsigned int   u32;
struct Obj;
extern void CLACT_SetActorDrawEnable(struct Obj *p, u32 v);
struct State;
extern void ZUKAN_INFO_SetDrawEnable(struct State *p, int v);
void ZUKAN_INFO_SetSlotDrawEnable(S *p, int v)
{
    CLACT_SetActorDrawEnable(p->last[p->index], v);
    if (p->f8 == 0)
        v = 0;
    ZUKAN_INFO_SetDrawEnable((struct State *)p, v);
}
