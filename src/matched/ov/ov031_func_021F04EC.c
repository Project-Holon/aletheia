/*
 * function: UNION_SUBDISP_CreateActors
 * address:  0x021F04EC
 * packet:   pkt_ov031_021F04EC
 * region:   ov031
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   CLACT_CreateActor  0x0204B294  arm
 *   CLACT_SetActorDrawEnable  0x0204B3DC  arm
 *   sUnionSubdispButtonActorParam     0x021F1048  data  a4
 */

typedef unsigned char u8;
typedef unsigned short u16;

typedef struct { u16 a, b, c, d; } Rect;

struct Obj;
extern struct Obj *CLACT_CreateActor(void *, unsigned int, unsigned int, unsigned int, const void *, unsigned short, unsigned short);
extern void CLACT_SetActorDrawEnable(struct Obj *, unsigned int);
extern const Rect sUnionSubdispButtonActorParam;

void UNION_SUBDISP_CreateActors(int *p, void *h)
{
    Rect r;
    int i;

    r = sUnionSubdispButtonActorParam;
    for (i = 0; i <= 4; i++) {
        r.a = i * 0x30 + 0x20;
        r.c = i;
        p[6 + i] = (int)CLACT_CreateActor((void *)p[5], p[2], p[3], p[4], &r, 1, 0x15);
    }
    r.c = 5;
    r.a = 0xF4;
    r.b = 0x9C;
    p[0xB] = (int)CLACT_CreateActor((void *)p[5], p[2], p[3], p[4], &r, 1, 0x15);
    CLACT_SetActorDrawEnable((struct Obj *)p[0xB], 0);
}
