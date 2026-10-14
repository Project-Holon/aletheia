/*
 * function: BTLV_INPUT_UpdateButtonActors
 * address:  0x022064CC
 * packet:   pkt_ov094_022064CC
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * The table parameter is `__restrict`: with it the scheduler hoists the y
 * load above the x store in cases 2..5 (e[1] vs pos.x) but not in cases 0/1
 * (e[0] vs pos.x, same offset), which is the original's mixed schedule.
 *
 * symbols:
 *   CLACT_SetActorDrawEnable  0x0204B3DC  arm  arm9
 *   CLACT_AddActorSurfacePos  0x0204B404  arm  arm9
 */

typedef unsigned char u8;
typedef signed char s8;
typedef unsigned int u32;
typedef short s16;
typedef struct Point { s16 x, y; } Point;
typedef struct { void *h; int x; } Slot;
typedef struct {
    char p0[0x68];
    u32 b0 : 5;
    u32 sel : 4;
    u32 rest : 23;
    char p6c[0x180 - 0x6c];
    Slot slots[6];
    char p1b0[0x274 - 0x1b0];
    u8 *f274;
} W;
struct Obj;
extern void CLACT_SetActorDrawEnable(struct Obj *p, u32 v);
struct Vec2;
extern void CLACT_AddActorSurfacePos(struct Obj *p, const struct Vec2 *delta, u32 which);

void BTLV_INPUT_UpdateButtonActors(W *p, u8 (* __restrict tab)[4], s8 (*rows)[12])
{
    Point pos;
    u8 *e;
    int k;
    int i;

    for (i = 0; i < 6; i++) {
        k = rows[p->sel][i];
        if (k >= 0) {
            e = tab[k];
            switch (i) {
            case 0:
                pos.x = e[2];
                pos.y = e[0];
                break;
            case 1:
                pos.x = e[3];
                pos.y = e[0];
                break;
            case 2:
                pos.x = e[2];
                pos.y = e[1];
                break;
            case 3:
                pos.x = e[3];
                pos.y = e[1];
                break;
            case 4:
                pos.x = e[2];
                pos.y = e[1];
                break;
            case 5:
                pos.x = e[3];
                pos.y = e[1];
                break;
            }
            CLACT_SetActorDrawEnable(p->slots[i].h, *p->f274);
            CLACT_AddActorSurfacePos(p->slots[i].h, (const struct Vec2 *)(&pos), 1);
        } else {
            CLACT_SetActorDrawEnable(p->slots[i].h, 0);
        }
    }
}
