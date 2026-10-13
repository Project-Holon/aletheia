/*
 * function: TOWNMAP_TownSetShown
 * address:  0x021BAA30
 * packet:   pkt_ov072_021BAA30
 * region:   ov072
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   TOWNMAP_TownGetField  0x021BA774  thumb  ov072
 *   TOWNMAP_TownSetFrame  0x021BADBC  thumb  ov072
 *   CLACT_SetActorDrawEnable  0x0204B3DC  arm
 */

typedef unsigned char u8;

typedef struct {
    int obj;
    int f4;
    int f8[10];
    u8 f30;
    u8 f31;
    u8 f32;
    int f34;
    int f38;
    int f3c;
    int f40;
} W;

extern int TOWNMAP_TownGetField(char *p, int i);
extern void TOWNMAP_TownSetFrame(char *p, int v);
struct Obj;
extern void CLACT_SetActorDrawEnable(struct Obj *obj, unsigned int on);

void TOWNMAP_TownSetShown(W *p, int a)
{
    if (p->obj == 0 || p->f32 == 0xff) {
        return;
    }
    if (p->f40 != 0) {
        CLACT_SetActorDrawEnable((struct Obj *)p->obj, 0);
        return;
    }
    if (TOWNMAP_TownGetField((char *)p, 11) == 4 || TOWNMAP_TownGetField((char *)p, 11) == 5) {
        TOWNMAP_TownSetFrame((char *)p, p->f30);
        CLACT_SetActorDrawEnable((struct Obj *)p->obj, 1);
    } else {
        CLACT_SetActorDrawEnable((struct Obj *)p->obj, a);
    }
}
