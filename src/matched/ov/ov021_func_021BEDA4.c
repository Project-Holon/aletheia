/*
 * function: EVENT_FIELDMAP_CONTROL_CreateFadeInEventEffect8
 * address:  0x021BEDA4
 * packet:   pkt_ov021_021BEDA4
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
 *   EVENT_FIELDMAP_CONTROL_GetFadeKind  0x021BEA6C  thumb  ov021
 *   EVENT_FIELDMAP_CONTROL_RunWipeInEffect8  0x021BF4A4  thumb  ov021
 */

typedef struct {
    int f0;
    int f4;
    int f8;
    int fC;
} Ent;

typedef unsigned int   u32;
struct Desc;
int EVENT_FIELDMAP_CONTROL_RunWipeInEffect8(int a, int *s, int *q);
struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
struct Obj;
void *func_020124E8(struct Obj *p);
int EVENT_FIELDMAP_CONTROL_GetFadeKind(int x);

int EVENT_FIELDMAP_CONTROL_CreateFadeInEventEffect8(int a, int b)
{
    int h = (int)func_020122C0((void *)a, 0, EVENT_FIELDMAP_CONTROL_RunWipeInEffect8, 0x2c);
    Ent *e = func_020124E8((struct Obj *)h);
    e->f0 = a;
    e->f4 = b;
    e->f8 = 8;
    e->fC = EVENT_FIELDMAP_CONTROL_GetFadeKind(8);
    return h;
}
