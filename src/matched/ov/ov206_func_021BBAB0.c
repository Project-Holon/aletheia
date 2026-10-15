/*
 * function: func_021BBAB0
 * address: 0x021BBAB0
 * packet: pkt_ov206_021BBAB0
 * region: ov206
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   ZUKAN_INFO_GetFormFlag 0x021BC0E4 thumb ov206
 *   func_021BC0B0 0x021BC0B0 thumb ov206
 *   CLACT_RegisterCharacter 0x0204A6C8 arm
 *   CLACT_CreateActor 0x0204B294 arm
 *   CLACT_SetActorDrawPriority 0x0204B800 arm
 *   CLACT_SetActorObjMode 0x0204B688 arm
 *   func_021BBC04 0x021BBC04 thumb ov206
 */
typedef unsigned short u16;
typedef unsigned char u8;
typedef short s16;
typedef unsigned int u32;
typedef enum { B_FALSE, B_TRUE } Bool;
struct Point {
    s16 x;
    s16 y;
    u16 f4;
    u8 f6;
    u8 f7;
};
typedef struct S {
    u16 id;
    char pad2[0x1a];
    int f1c;
    char pad20[4];
    u32 f24;
    char pad28[0x174 - 0x28];
    u32 a174[2];
    u32 f17c;
    u32 f180;
    u32 f184;
    u32 a188[2];
    char pad190[0x1b4 - 0x190];
    u32 f1b4;
    char pad1b8[0x1d8 - 0x1b8];
    u32 f1d8;
    u32 f1dc;
} S;
extern u32 ZUKAN_INFO_GetFormFlag(u32 a, u32 b);
extern int func_021BC0B0(int v);
typedef signed int     s32;
extern s32 CLACT_RegisterCharacter(void *a, u32 b, u32 c, u32 a3, u16 flags);
struct Obj;
extern struct Obj *CLACT_CreateActor(void *a, unsigned int b, unsigned int c, unsigned int d, const void *pt, u16 f, u16 g);
struct Actor;
struct Node;
extern void CLACT_SetActorDrawPriority(struct Node *node, u32 val);
extern void CLACT_SetActorObjMode(struct Actor *actor, u32 value);
extern void func_021BBC04(S *p);
void func_021BBAB0(S *p, u32 a, u32 b, u32 idx)
{
    u32 flag;
    u32 w;
    u32 v;
    Bool flag2;
    struct Point pt;

    flag = 0;
    if (p->f1c != 0)
        flag = 1;
    flag2 = p->f1c == 0 ? B_FALSE : B_TRUE;
    v = ZUKAN_INFO_GetFormFlag(a, b);
    if (v == 0xFFFF) {
        w = p->f1d8;
        p->a174[idx] = CLACT_RegisterCharacter((void *)w, func_021BC0B0(a), 1, flag, p->id);
    } else {
        p->a174[idx] = CLACT_RegisterCharacter((void *)p->f1dc, v, 1, flag, p->id);
    }
    pt.x = 0x78;
    pt.y = p->f1b4 + 0x58;
    pt.f4 = 0;
    pt.f6 = 1;
    pt.f7 = 0;
    if (a <= 0x1ED && v != 0xFFFF)
        p->a188[idx] = (u32)CLACT_CreateActor((void *)p->f24, p->a174[idx], p->f17c, p->f180, &pt, flag2, p->id);
    else
        p->a188[idx] = (u32)CLACT_CreateActor((void *)p->f24, p->a174[idx], p->f17c, p->f184, &pt, flag2, p->id);
    CLACT_SetActorDrawPriority((void *)p->a188[idx], 1);
    CLACT_SetActorObjMode((void *)p->a188[idx], 1);
    func_021BBC04(p);
}
