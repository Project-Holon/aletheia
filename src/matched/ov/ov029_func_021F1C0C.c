/*
 * function: C_GEAR_CreateBarActors
 * address:  0x021F1C0C
 * packet:   pkt_ov029_021F1C0C
 * region:   ov029
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * symbols:
 *   CLACT_CreateActor  0x0204B294  arm
 *   CLACT_SetActorDrawEnable  0x0204B3DC  arm
 *   CLACT_SetActorVisible  0x0204BA20  arm
 */
#include "../include/Obj00709.h"

typedef struct {
    unsigned short x;
    unsigned short y;
    unsigned short z;
    unsigned char a;
    unsigned char b;
} S13Rec;

struct Obj;
extern struct Obj *CLACT_CreateActor(void *, unsigned int, unsigned int, unsigned int, const void *, unsigned short, unsigned short);
extern void CLACT_SetActorDrawEnable(struct Obj *, unsigned int);
typedef unsigned int   u32;
struct Actor;
extern void CLACT_SetActorVisible(struct Actor *a, u32 v);

void C_GEAR_CreateBarActors(char *p)
{
    S13Rec s;

    s.x = 0x68;
    s.y = 0xaa;
    s.z = 0x28;
    s.a = 0;
    s.b = 2;
    ((struct Obj00709 *)p)->f164 = (int)CLACT_CreateActor((void *)((struct Obj00709 *)p)->f34, ((struct Obj00709 *)p)->f2C, ((struct Obj00709 *)p)->f28,
                                        ((struct Obj00709 *)p)->f30, &s, 0, ((struct Obj00709 *)p)->fC);
    CLACT_SetActorDrawEnable((struct Obj *)((struct Obj00709 *)p)->f164, 0);
    CLACT_SetActorVisible((struct Actor *)(((struct Obj00709 *)p)->f164), 0);

    s.x = 0x68;
    s.y = 0xaa;
    s.z = 0x27;
    s.a = 0x14;
    s.b = 2;
    ((struct Obj00709 *)p)->f168 = (int)CLACT_CreateActor((void *)((struct Obj00709 *)p)->f34, ((struct Obj00709 *)p)->f2C, ((struct Obj00709 *)p)->f28,
                                        ((struct Obj00709 *)p)->f30, &s, 0, ((struct Obj00709 *)p)->fC);
    CLACT_SetActorDrawEnable((struct Obj *)((struct Obj00709 *)p)->f168, 0);
    CLACT_SetActorVisible((struct Actor *)(((struct Obj00709 *)p)->f168), 0);

    s.x = 0x22;
    s.y = 0xaa;
    s.z = 0x10;
    s.a = 0;
    s.b = 2;
    ((struct Obj00709 *)p)->f16C = (int)CLACT_CreateActor((void *)((struct Obj00709 *)p)->f34, ((struct Obj00709 *)p)->f2C, ((struct Obj00709 *)p)->f28,
                                        ((struct Obj00709 *)p)->f30, &s, 0, ((struct Obj00709 *)p)->fC);
    CLACT_SetActorDrawEnable((struct Obj *)((struct Obj00709 *)p)->f16C, 0);
    CLACT_SetActorVisible((struct Actor *)(((struct Obj00709 *)p)->f16C), 0);
}
