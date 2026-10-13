/*
 * function: OEKAKI_CreateActors
 * address:  0x02184D30
 * packet:   pkt_ov023_02184D30
 * region:   ov023
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   CLACT_CreateActor  0x0204B294  arm
 *   CLACT_SetActorAutoAnim  0x0204B92C  arm
 *   CLACT_SetActorAnimSeq  0x0204B878  arm
 *   CLACT_SetActorDrawEnable  0x0204B3DC  arm
 *   CLACT_SetActorBgPriority  0x0204B84C  arm
 *   CLACT_SetActorDrawPriority  0x0204B800  arm
 *   BG_SYS_SetMainPlaneVisible  0x020434DC  arm
 *   BG_SYS_SetSubPlaneVisible  0x02043598  arm
 *   gOekakiButtonLayout     0x02186BEC  data  ov023  a2
 *
 * The three indexed runs must be struct array members (index on the base,
 * member offset after it); the extents of a60/a98 are padding to the next
 * member, not evidence. The unsigned 0x100000u keeps the `movs #1; lsls #20`
 * add apart from the `+ 0x20`: a plain int constant folds both into one
 * pool word.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef signed short   s16;
typedef unsigned int   u32;

typedef struct Pos {
    s16 x;
    s16 y;
    s16 z;
    u8 a;
    u8 b;
} Pos;

typedef struct Ent {
    u16 x;
    u16 y;
    u16 anim;
} Ent;

extern const Ent gOekakiButtonLayout[];

typedef struct Work {
    u8  pad00[0x38];
    u32 f38, f3C, f40, f44, f48, f4C, f50, f54, f58, f5C;
    u32 a60[14];
    u32 a98[14];
    u32 aD0[12];
    u32 f100;
} Work;

struct Obj;
extern struct Obj *CLACT_CreateActor(void *owner, unsigned int i, unsigned int j, unsigned int k, const void *position, unsigned short space, unsigned short heap);
extern void CLACT_SetActorAutoAnim(struct Obj *p, u32 v);
struct Node;
extern void CLACT_SetActorAnimSeq(struct Obj *p, u16 value);
extern void CLACT_SetActorDrawEnable(struct Obj *p, unsigned int v);
extern void CLACT_SetActorBgPriority(u32, int);
extern void CLACT_SetActorDrawPriority(struct Node *node, u32 val);
extern void BG_SYS_SetMainPlaneVisible(u32 mask, u32 enable);
extern void BG_SYS_SetSubPlaneVisible(u32 mask, u32 enable);

void OEKAKI_CreateActors(Work *p)
{
    Pos pos;
    int i;
    int j;

    pos.x = 0;
    pos.y = 0;
    pos.z = 0;
    pos.a = 1;
    pos.b = 1;
    for (i = 0; i < 5; i++) {
        pos.x = i * 0x28 + 0x18;
        pos.y = 0x40;
        p->a60[i] = (u32)CLACT_CreateActor((void *)p->f38, p->f40, p->f3C, p->f44, &pos, 0, 0x28);
        CLACT_SetActorAutoAnim((struct Obj *)p->a60[i], 1);
        CLACT_SetActorAnimSeq((struct Obj *)p->a60[i], i);
        CLACT_SetActorDrawEnable((struct Obj *)p->a60[i], 0);
    }
    for (j = 0; j < 12; j++) {
        pos.x = gOekakiButtonLayout[j].x;
        pos.y = gOekakiButtonLayout[j].y;
        p->aD0[j] = (u32)CLACT_CreateActor((void *)p->f38, p->f40, p->f3C, p->f44, &pos, 0, 0x28);
        CLACT_SetActorAutoAnim((struct Obj *)p->aD0[j], 1);
        CLACT_SetActorAnimSeq((struct Obj *)p->aD0[j], gOekakiButtonLayout[j].anim);
        if (j >= 8) {
            CLACT_SetActorBgPriority(p->aD0[j], 2);
        }
    }
    CLACT_SetActorAnimSeq((struct Obj *)p->aD0[0], 6);
    for (i = 0; i < 5; i++) {
        pos.x = 0x18;
        pos.y = i * 0x20 + 0x20 + 0x100000u;
        p->a98[i] = (u32)CLACT_CreateActor((void *)p->f38, p->f58, p->f54, p->f5C, &pos, 1, 0x28);
        CLACT_SetActorAutoAnim((struct Obj *)p->a98[i], 1);
        CLACT_SetActorAnimSeq((struct Obj *)p->a98[i], i);
        CLACT_SetActorDrawPriority((struct Node *)p->a98[i], 1);
        CLACT_SetActorDrawEnable((struct Obj *)p->a98[i], 0);
    }
    pos.x = 0xD4;
    pos.y = 0xA0;
    p->f100 = (u32)CLACT_CreateActor((void *)p->f38, p->f4C, p->f48, p->f50, &pos, 0, 0x28);
    CLACT_SetActorAutoAnim((struct Obj *)p->f100, 1);
    CLACT_SetActorAnimSeq((struct Obj *)p->f100, 1);
    CLACT_SetActorDrawEnable((struct Obj *)p->f100, 1);
    BG_SYS_SetMainPlaneVisible(0x10, 1);
    BG_SYS_SetSubPlaneVisible(0x10, 1);
}
