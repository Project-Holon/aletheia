/*
 * function: BOX2_MAIN_SceneApplyScroll
 * address: 0x021E066C
 * packet: pkt_ov170_021E066C
 * region: ov170
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BOX2_SEQ_AddActorSurfacePos 0x021EC08C thumb ov170
 *   BOX2_SEQ_GetActorSurfacePos 0x021EC0B0 thumb ov170
 *   BOX2_SEQ_RefreshHandSlot 0x021ECC1C thumb ov170
 */
typedef struct {
    unsigned char x, y, dx, dy;
    unsigned directionX:1;
    unsigned directionY:1;
    unsigned count:30;
} Motion;
extern void BOX2_SEQ_AddActorSurfacePos(char *p, int i, int a, int b, unsigned short c);
extern void BOX2_SEQ_GetActorSurfacePos(char *w, int i, short *x, short *y, unsigned short z);
extern void BOX2_SEQ_RefreshHandSlot(unsigned char *p);
#define WORK(p) (*(char **)((p) + 0x2C))
int BOX2_MAIN_SceneApplyScroll(char *p)
{
    Motion *m;
    short xy[2];
    m = *(Motion **)(WORK(p) + 0x60);
    if (m->count == 0) {
        BOX2_SEQ_AddActorSurfacePos(WORK(p), 4, m->x, m->y, 0);
        BOX2_SEQ_RefreshHandSlot((unsigned char *)p);
        return 0;
    }
    m->count--;
    BOX2_SEQ_GetActorSurfacePos(WORK(p), 4, &xy[1], &xy[0], 0);
    if (m->directionX == 0)
        xy[1] += m->dx;
    else
        xy[1] -= m->dx;
    if (m->directionY == 0)
        xy[0] += m->dy;
    else
        xy[0] -= m->dy;
    BOX2_SEQ_AddActorSurfacePos(WORK(p), 4, xy[1], xy[0], 0);
    BOX2_SEQ_RefreshHandSlot((unsigned char *)p);
    return 1;
}
