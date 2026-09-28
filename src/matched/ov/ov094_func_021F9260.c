/*
 * function: func_021F9260
 * address:  0x021F9260
 * packet:   pkt_ov094_02200A84
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021F9220  0x021F9220  thumb  ov094
 */
typedef int fx32;

typedef struct {
    fx32 x, y, z;
} VecFx32;

typedef struct {
    int mode;               /* 0x00 */
    VecFx32 end;            /* 0x04 */
    VecFx32 start;          /* 0x10 */
    VecFx32 step;           /* 0x1c */
    int count;              /* 0x28 */
    int countReset;         /* 0x2c */
    int wait;               /* 0x30 */
    int waitReset;          /* 0x34 */
    int repeat;             /* 0x38 */
} Mover;

extern void func_021F9220(int *p, int *d, int *lim, int *flag);

int func_021F9260(Mover *m, VecFx32 *out)
{
    int ret = 1;

    switch (m->mode) {
    case 0:
        out->x = m->start.x;
        out->y = m->start.y;
        out->z = m->start.z;
        break;
    case 1:
    case 4:
        if (m->wait == 0) {
            m->wait = m->waitReset;
            func_021F9220(&out->x, &m->step.x, &m->start.x, &ret);
            func_021F9220(&out->y, &m->step.y, &m->start.y, &ret);
            func_021F9220(&out->z, &m->step.z, &m->start.z, &ret);
        } else {
            m->wait--;
            ret = 0;
        }
        break;
    case 2:
    case 3:
        if (m->wait == 0) {
            m->wait = m->waitReset;
            out->x += m->step.x;
            out->y += m->step.y;
            out->z += m->step.z;
            if (--m->count == 0) {
                m->repeat--;
                m->count = m->countReset;
                if (m->mode == 2 || (m->mode == 3 && (m->repeat & 1))) {
                    m->step.x *= -1;
                    m->step.y *= -1;
                    m->step.z *= -1;
                }
            }
        } else {
            m->wait--;
        }
        if (m->repeat != 0) {
            ret = 0;
        } else {
            out->x = m->end.x;
            out->y = m->end.y;
            out->z = m->end.z;
        }
        break;
    }
    return ret;
}
