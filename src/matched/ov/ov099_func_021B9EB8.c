/*
 * function: WIFICLUBACTOR_CreateClactActors
 * address:  0x021B9EB8
 * packet:   pkt_ov099_021B9EB8
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   CLACT_CreateActor  0x0204B294  arm
 *   CLACT_SetActorDrawEnable  0x0204B3DC  arm
 *   CLACT_SetActorAutoAnim  0x0204B92C  arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    u32 f0;
    u32 f4;
    u32 f8;
    u32 fc;
    u32 f10;
    u32 f14;
    u32 f18;
} Obj;

typedef struct {
    u16 a, b, c;
    u8 d, e;
} Rec;

struct Obj;
extern struct Obj *CLACT_CreateActor(void *a, unsigned int b, unsigned int c, unsigned int d, const void *e, u16 f, u16 g);
extern void CLACT_SetActorDrawEnable(struct Obj *p, unsigned int v);
extern void CLACT_SetActorAutoAnim(struct Obj *a, u32 b);

void WIFICLUBACTOR_CreateClactActors(Obj *o, int a)
{
    Rec r;

    r.a = 1;
    r.b = 1;
    r.c = 0;
    r.d = 0;
    r.e = 0;
    o->f14 = (u32)CLACT_CreateActor((void *)o->f0, o->f8, o->fc, o->f10, &r, 0, a);
    r.c = 2;
    r.d = 0xfe;
    r.e = 3;
    o->f18 = (u32)CLACT_CreateActor((void *)o->f0, o->f8, o->fc, o->f10, &r, 0, a);
    CLACT_SetActorDrawEnable((struct Obj *)o->f14, 0);
    CLACT_SetActorDrawEnable((struct Obj *)o->f18, 0);
    CLACT_SetActorAutoAnim((struct Obj *)o->f14, 1);
    CLACT_SetActorAutoAnim((struct Obj *)o->f18, 1);
}
