/*
 * function: BSUBWAY_RECORD_LIST_CreateActors
 * address:  0x021B9B44
 * packet:   pkt_ov069_021B9B44
 * region:   ov069
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Creates four sprites from a const 6-word template table (x, y, z, then
 * three resource-slot indices).  The table must be `const`: a non-const
 * table lets the stores into the stack record alias it, and the index loads
 * are then scheduled after the stack-argument stores (42 bytes of DIFF).
 * Twin: ov111_func_021C75E4.
 *
 * symbols:
 *   CLACT_CreateActor  0x0204B294  arm
 *   CLACT_SetActorAutoAnim  0x0204B92C  arm
 *   sActorTemplates  0x021BA6BC  data  a4
 */

typedef unsigned char u8;
typedef short s16;

typedef struct Ent {
    int a, b, c;
    int d, e, f;
} Ent;

typedef struct Rec {
    s16 a, b, c;
    u8 d, e;
} Rec;

typedef struct WorkObj {
    unsigned char pad000[0x11C];
    int f11C;
    int f120;
    int slot[4];
    int arr[1];
} Obj;

extern const Ent sActorTemplates[];

struct Obj;
extern struct Obj *CLACT_CreateActor(void *owner, unsigned int i, unsigned int j, unsigned int k, const void *position, unsigned short space, unsigned short heap);
extern void CLACT_SetActorAutoAnim(struct Obj *, unsigned int);

void BSUBWAY_RECORD_LIST_CreateActors(Obj *o)
{
    int i;
    Rec r;

    for (i = 0; i < 4; i++) {
        r.a = sActorTemplates[i].a;
        r.b = sActorTemplates[i].b;
        r.c = sActorTemplates[i].c;
        r.e = 0;
        r.d = 0;
        o->slot[i] = (int)CLACT_CreateActor((void *)o->f11C, o->arr[sActorTemplates[i].d], o->arr[sActorTemplates[i].e], o->arr[sActorTemplates[i].f], &r, 0, 0x80);
        CLACT_SetActorAutoAnim((struct Obj *)o->slot[i], 1);
    }
}
