/*
 * function: func_021F5950
 * address:  0x021F5950
 * packet:   pkt_ov078_021F5950
 * region:   ov078
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * One step of the ripple over the 33 x 25 grid func_021F5698 /
 * func_021F5AFC allocate (0x19E0 bytes); the vertex list is drawn by
 * func_021F5800.
 * Levers: period/next are u16 (ldrh); each neighbour coordinate is a
 * temporary (x = col - 1, ...) so the +-1 is not folded into the load
 * offset; the element pointer p is a named local declared before col/row
 * (without it row takes r0 and the quotient is never moved to r1).
 *
 * Addresses are Black-image addresses.
 */

typedef short s16;
typedef unsigned short u16;

typedef struct {
    s16 x, y, z;
} VecFx16;

typedef struct {
    VecFx16 v[825];
    s16 vel[825];
    s16 wait;
    s16 count;
    u16 period;
    u16 next;
    int height;
} Grid;

int func_021F5950(Grid *w)
{
    s16 z[825];
    int i;
    VecFx16 *p;
    int col;
    int row;
    int a;
    int b;
    int c;
    int d;
    int x;
    int y;
    s16 diff;

    for (i = 0; i < 825; i++)
        z[i] = w->v[i].z;
    if (w->count > 0) {
        if (w->wait == 0) {
            w->v[412].z = w->height;
            w->wait = w->period;
            w->count--;
        } else {
            w->wait--;
        }
        if (w->count <= 0) {
            if (w->next == 0) {
                w->wait = 6;
                return 1;
            }
            w->wait = w->next;
        }
    } else {
        w->wait--;
        if (w->wait <= 0) {
            w->wait = 6;
            return 1;
        }
    }
    for (i = 0; i < 825; i++) {
        col = i % 33;
        row = i / 33;
        x = col - 1;
        a = (x >= 0) ? z[x + row * 33] : 0;
        x = col + 1;
        b = (x < 33) ? z[x + row * 33] : 0;
        y = row - 1;
        c = (y >= 0) ? z[col + y * 33] : 0;
        y = row + 1;
        d = (y < 25) ? z[col + y * 33] : 0;
        p = &w->v[i];
        diff = (a + b + c + d) / 4 - p->z;
        w->vel[i] += diff;
        p->z += w->vel[i];
        if (p->z > 0x1000)
            p->z = 0x1000;
        if (p->z < -0x1000)
            p->z = -0x1000;
        if (col == 0 || col == 32 || row == 0 || row == 24)
            p->z = 0;
    }
    return 0;
}
