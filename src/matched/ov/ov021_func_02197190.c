/*
 * function: IRCBATTLEMENU_CreateKindMenuActors
 * address:  0x02197190
 * packet:   pkt_ov021_02197190
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   sKindMenuActorPosX     0x021D3FA0  data   a1
 *   sKindMenuActorPosY     0x021D3F8C  data   a1
 *   sKindMenuActorAnim     0x021D3F94  data   a1
 *   IRCBATTLEMENU_DeleteMenuActors  0x02197058  thumb  ov021
 *   CLACT_CreateActor  0x0204B294  arm
 *   CLACT_SetActorAutoAnim  0x0204B92C  arm
 *   CLACT_SetActorDrawEnable  0x0204B3DC  arm
 *   CLACT_SetActorObjMode  0x0204B688  arm
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct { u16 a, b, c; u8 d, e; } Rect;
typedef struct { u8 v[3]; } B3;

typedef struct {
    int f0;
    int f4;
    int f8;
    int fC;
    int f10;
    int f14;
    int f18;
    int f1C;
    int f20;
    int f24;
    int arr[3];
} Sub;

typedef struct {
    u8 pad0[0x10];
    u16 f10;
    u8 pad12[0x26C - 0x12];
    Sub sub;
} Obj;

extern const B3 sKindMenuActorPosX;
extern const B3 sKindMenuActorPosY;
extern const B3 sKindMenuActorAnim;
extern void IRCBATTLEMENU_DeleteMenuActors(Obj *);
struct Obj;
extern struct Obj *CLACT_CreateActor(void *, unsigned int, unsigned int, unsigned int, const void *, unsigned short, unsigned short);
extern void CLACT_SetActorAutoAnim(struct Obj *p, unsigned int v);
extern void CLACT_SetActorDrawEnable(struct Obj *, unsigned int);
struct Actor;
extern void CLACT_SetActorObjMode(struct Actor *actor, u32 value);

void IRCBATTLEMENU_CreateKindMenuActors(Obj *p)
{
    B3 x0 = sKindMenuActorPosX;
    B3 x1 = sKindMenuActorPosY;
    B3 x2 = sKindMenuActorAnim;
    Rect r;
    int i;

    IRCBATTLEMENU_DeleteMenuActors(p);
    for (i = 0; i < 3; i++) {
        r.a = x0.v[i];
        r.b = x1.v[i];
        r.c = x2.v[i];
        r.d = 0;
        r.e = 1;
        p->sub.arr[i] = (int)CLACT_CreateActor((void *)p->sub.f0, p->sub.f10, p->sub.f8, p->sub.f18, &r, 1, p->f10);
        CLACT_SetActorAutoAnim((struct Obj *)p->sub.arr[i], 0);
        CLACT_SetActorDrawEnable((struct Obj *)p->sub.arr[i], 1);
        CLACT_SetActorObjMode((struct Actor *)p->sub.arr[i], 1);
    }
}
