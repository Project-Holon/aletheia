/*
 * function: BTLV_INPUT_PaletteFlashTaskMain
 * address:  0x022048A4
 * packet:   pkt_ov094_022048A4
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   d_0220A3B4     0x0220A3B4  data   ov094  a4
 *   CLACT_GetActorSurfacePos  0x0204B454  arm
 *   CLACT_AddActorSurfacePos  0x0204B404  arm
 *   BTLV_INPUT_DeleteTask  0x0220687C  thumb  ov094
 */
typedef short s16;
typedef unsigned int u32;

typedef struct Main {
    unsigned char pad00[0x68];
    u32 f68;
} Main;

typedef struct Ctx {
    Main *main;
    int f4;
} Ctx;

extern const int d_0220A3B4[][2];
struct Actor;
struct PtS;
typedef unsigned short u16;
extern void CLACT_GetActorSurfacePos(struct Actor *actor, struct PtS *out, u16 space);
struct Obj;
struct Vec2;
extern void CLACT_AddActorSurfacePos(struct Obj *p, const struct Vec2 *delta, u32 which);
extern void BTLV_INPUT_DeleteTask(char *p, void *q);

void BTLV_INPUT_PaletteFlashTaskMain(int a0, Ctx *c)
{
    int k;
    int changed = 0;
    int target;
    char *p;
    int j;
    s16 v[2];

    for (k = 0; k < 2; k++) {
        target = d_0220A3B4[k][c->f4];
        if (k == 0) {
            p = (char *)c->main + 0x47 * 4;
        } else {
            if (((c->main->f68 << 17) >> 31) == 0) {
                break;
            }
            p = (char *)c->main + 0x53 * 4;
        }
        for (j = 0; j < 6; j++) {
            CLACT_GetActorSurfacePos(*(void **)(p + j * 8), (struct PtS *)v, 1);
            if (v[1] > target) {
                v[1] = v[1] - 4;
                changed = 1;
            } else if (v[1] < target) {
                v[1] = v[1] + 4;
                changed = 1;
            }
            CLACT_AddActorSurfacePos(*(void **)(p + j * 8), (const struct Vec2 *)v, 1);
        }
    }
    if (changed == 0) {
        BTLV_INPUT_DeleteTask((char *)c->main, (void *)a0);
    }
}
