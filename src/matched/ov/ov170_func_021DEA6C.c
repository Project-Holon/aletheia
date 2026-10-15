/*
 * function: BOX2_MAIN_CheckSceneMode
 * address: 0x021DEA6C
 * packet: pkt_ov170_021DEA6C
 * region: ov170
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: final two bytes are zero alignment padding.
 * symbols:
 *   BOX2_SEQ_MoveActorToSlot 0x021ED164 thumb ov170
 *   BOX2_SEQ_MoveActorToSlotB 0x021ED198 thumb ov170
 *   BOX2_SEQ_MoveActor 0x021ED14C thumb ov170
 *   BOX2_SEQ_LayoutHandSlots 0x021ED310 thumb ov170
 */
typedef struct {
    unsigned short index;
    unsigned short pad;
    int value, x, y, dx, dy;
    unsigned dirX:1;
    unsigned dirY:1;
    unsigned count:30;
} Motion;
extern void BOX2_SEQ_MoveActorToSlot(char *w, int i, int v);
extern void BOX2_SEQ_MoveActorToSlotB(char *w, int i, int v);
extern void BOX2_SEQ_MoveActor(int a, int b, int c);
extern void BOX2_SEQ_LayoutHandSlots(char *w);
#define WORK(p) (*(char **)((p) + 0x2C))
int BOX2_MAIN_CheckSceneMode(char *p, int a)
{
    Motion *m;
    m = *(Motion **)(WORK(p) + 0x60);
    if (m->count == 8) {
        if (m->index != 255) {
            if (a == 1)
                BOX2_SEQ_MoveActorToSlot(WORK(p), m->index, m->value);
            else
                BOX2_SEQ_MoveActorToSlotB(WORK(p), m->index, m->value);
        }
        BOX2_SEQ_LayoutHandSlots(WORK(p));
        return 0;
    }
    if (m->dirX == 0)
        m->x += m->dx;
    else
        m->x -= m->dx;
    if (m->dirY == 0)
        m->y += m->dy;
    else
        m->y -= m->dy;
    BOX2_SEQ_MoveActor((int)WORK(p), (short)(m->x >> 8), (short)(m->y >> 8));
    BOX2_SEQ_LayoutHandSlots(WORK(p));
    m->count++;
    return 1;
}
