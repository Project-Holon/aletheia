/*
 * function: FIELD_EVENT_CHECK_CreateLedgeJumpTask
 * address:  0x0218B3DC
 * packet:   pkt_ov021_0218B3DC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   FIELD_EVENT_CHECK_LedgeJumpTaskMain  0x0218B32C  thumb  ov021
 */

typedef struct {
    int f0;
    short f4;
    short f6;
    int f8;
    int fC;
} Ent;

typedef unsigned int   u32;
struct Desc;
int FIELD_EVENT_CHECK_LedgeJumpTaskMain(void *unused, int *st, char *ctx);
struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
struct Obj;
void *func_020124E8(struct Obj *p);

int FIELD_EVENT_CHECK_CreateLedgeJumpTask(int unused, int a, int b, int c, int d)
{
    int h = (int)func_020122C0((void *)a, 0, FIELD_EVENT_CHECK_LedgeJumpTaskMain, 0x10);
    Ent *e = func_020124E8((struct Obj *)h);
    e->f8 = a;
    e->fC = b;
    e->f4 = c;
    e->f6 = d;
    return h;
}
