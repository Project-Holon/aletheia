/*
 * function: func_021E6308
 * address: 0x021E6308
 * packet: pkt_ov119_021E6308
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 */
typedef struct {
    char pad[0x1008];
    int h[2][3];
} Work;

struct Obj;
extern void CLACT_SetActorDrawEnable(struct Obj *p, unsigned int v);

void func_021E6308(Work *p, int a, int v)
{
    int i;
    for (i = 0; i < 3; i++) {
        if (p->h[a][i])
            CLACT_SetActorDrawEnable((struct Obj *)p->h[a][i], v);
    }
}
