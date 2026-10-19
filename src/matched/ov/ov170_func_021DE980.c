/*
 * function: BOX2_MAIN_StartHandMotionToBoxArrow
 * address:  0x021DE980
 * packet:   pkt_ov170_021DE980
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BOX2_SEQ_GetActorSurfacePos 0x021EC0B0 thumb
 *
 * Starts the held-item sprite (window 10) sliding back toward window 0 or 1:
 * direction bits and an eighth of the distance per frame, in 24.8 fixed point.
 */

typedef struct {
    unsigned short idx;
    unsigned short slot;
    int mode;
    int x;
    int y;
    int vx;
    int vy;
    unsigned int left : 1;
    unsigned int up : 1;
} Mover;

extern void BOX2_SEQ_GetActorSurfacePos(char *p, int i, short *a, short *b, unsigned short space);

#define FLAGS(o) (*(unsigned *)((char *)(o) + 0x18))
#define WORK(p) (*(char **)((p) + 0x2C))

void BOX2_MAIN_StartHandMotionToBoxArrow(unsigned char *p, int mode)
{
    Mover *o = *(Mover **)(WORK(p) + 0x60);
    short pos[2];
    short to[2];
    int d;
    BOX2_SEQ_GetActorSurfacePos(WORK(p), 10, &pos[1], &pos[0], 0);
    if (p[0x14] > p[0x17])
        BOX2_SEQ_GetActorSurfacePos(WORK(p), 0, &to[1], &to[0], 0);
    else
        BOX2_SEQ_GetActorSurfacePos(WORK(p), 1, &to[1], &to[0], 0);
    o->idx = 0xFF;
    o->slot = 0xFF;
    FLAGS(o) &= 3;
    o->mode = mode;
    {
        int tx = to[1];
        int px = pos[1];
        int ty;
        int py;
        if (px > tx) {
            o->left = 1;
            d = px - tx;
        } else {
            o->left = 0;
            d = tx - px;
        }
        o->vx = (d << 8) / 8;
        ty = to[0];
        py = pos[0];
        if (py > ty) {
            FLAGS(o) |= 2;
            d = py - ty;
        } else {
            FLAGS(o) &= ~2;
            d = ty - py;
        }
        o->vy = (d << 8) / 8;
        o->x = px << 8;
        o->y = py << 8;
    }
}
