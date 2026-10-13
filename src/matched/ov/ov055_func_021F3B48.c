/*
 * function: CROWD_FindPersonAtSpawn
 * address:  0x021F3B48
 * packet:   pkt_ov055_021F3B48
 * region:   ov055
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * The switch lists case 3 before case 2: the original lays the dx = 1 arm
 * out ahead of the dx = -1 arm.
 *
 * symbols:
 *   FLDMMDL_GetGridNowX  0x0216D83C  thumb  ov010
 *   FLDMMDL_GetGridNowZ  0x0216D86C  thumb  ov010
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef short          s16;

typedef struct Entry {
    u8 active;
    u8 f1;
    u8 kind;
    u8 f3;
    u8 pad4[8];
    void *obj;
    u8 pad10[8];
} Entry;

typedef struct Table {
    u8 hdr[8];
    Entry e[32];
} Table;

extern int FLDMMDL_GetGridNowX(void *p);
extern int FLDMMDL_GetGridNowZ(void *p);

Entry *CROWD_FindPersonAtSpawn(Table *t, int x, int y, unsigned int dir, int unused, int *out)
{
    int dx;
    int dy;
    int i;
    s16 ex;
    s16 ey;
    int px;
    int py;

    switch (dir) {
    case 0:
        dx = 0;
        dy = -1;
        break;
    case 1:
        dx = 0;
        dy = 1;
        break;
    case 3:
        dx = 1;
        dy = 0;
        break;
    case 2:
        dx = -1;
        dy = 0;
        break;
    }
    *out = 0;
    for (i = 0; i < 32; i++) {
        if (t->e[i].active != 0 && t->e[i].kind == 1) {
            px = FLDMMDL_GetGridNowX(t->e[i].obj);
            py = FLDMMDL_GetGridNowZ(t->e[i].obj);
            ex = px - x;
            ey = py - y;
            if (ex != 0) {
                ex = ex / (ex < 0 ? -ex : ex);
            }
            if (ey != 0) {
                ey = ey / (ey < 0 ? -ey : ey);
            }
            if (ex == 0 && ey == 0) {
                *out = 1;
                return &t->e[i];
            }
            if (ex == dx && ey == dy) {
                return &t->e[i];
            }
        }
    }
    return 0;
}
