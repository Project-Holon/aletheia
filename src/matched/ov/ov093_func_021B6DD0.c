/*
 * function: BTL_MAIN_TaskSetupMulti
 * address: 0x021B6DD0
 * packet: pkt_ov093_021B6DD0
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: the boolean passed narrow is an int local; t declared after desc puts t at sp+0x1c.
 * note 2026-10-05 (wave D9r lane 131): removed the dead first assignment
 * (`desc = p;` before `desc = p + 0xc8;`). Game code has no line table, so
 * these were stand-ins. The plain single assignment gives EXACT in --lang
 * c99 and --lang c: the output bytes do not change. Older text in this
 * header that asks for the double assignment is superseded.
 *
 * symbols:
 *   BTL_MAIN_IsClientUsed 0x021B8B9C thumb ov093
 *   BTL_MAIN_CountClientTrainers 0x021B8B78 thumb ov093
 *   BTL_TRAINER_SLOT_InitPlayer 0x021B9E38 thumb ov093
 *   BTL_TRAINER_SLOT_InitFromData 0x021B9E7C thumb ov093
 *   BTL_MAIN_InitTrainerSlot 0x021B6954 thumb ov093
 *   BTL_REC_InitReader 0x021EE644 thumb ov093
 *   BTL_CLIENT_AttachRemoteLink 0x021CD938 thumb ov093
 *   BTL_MAIN_IsCommCompetitor 0x021B6818 thumb ov093
 *   BTL_MAIN_SetupOwnClient 0x021B6848 thumb ov093
 *   BTL_SIDE_Init 0x021B93E0 thumb ov093
 *   BTL_SIDE_SetupClientParty 0x021B9460 thumb ov093
 *   BTL_SERVER_Create 0x021BA9C8 thumb ov093
 *   BTL_MAIN_InitFirstTwoTrainerSlots 0x021B69FC thumb ov093
 *   BTL_CLIENT_Create 0x021CD6F0 thumb ov093
 *   BTL_MAIN_StartRecordPlayback 0x021B6A3C thumb ov093
 *   BTL_MAIN_CreateViewCore 0x021B6A70 thumb ov093
 *   BTL_CLIENT_GetNetChannel 0x021CD978 thumb ov093
 *   BTL_SERVER_SetClientAdapter 0x021BAA94 thumb ov093
 *   BTL_SERVER_Restart 0x021BAB40 thumb ov093
 *   BTL_MAIN_StepClientsSolo 0x021B83F4 thumb ov093
 */
#include "../include/Obj00886.h"
#include "../include/Obj02772.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Copy24;
extern unsigned int BTL_MAIN_IsCommCompetitor(unsigned int *p);
struct T;
extern void BTL_MAIN_SetupOwnClient(u8 *, struct T *);
extern void BTL_SIDE_Init(char *, u32, u32);
extern void BTL_SIDE_SetupClientParty(char *a, char *b, u8 c);
struct A;
struct B;
struct Copy24;
struct QB;
extern u8 *BTL_SERVER_Create(void *a, struct Copy24 *b, void *c, int d, u16 heap);
extern void BTL_MAIN_InitFirstTwoTrainerSlots(int, char *);
extern u8 *BTL_CLIENT_Create(u8 *a, u8 *b, int c, int d, u16 idx, u16 kind, u8 e, int f, int g, struct Copy24 *h, u16 heap);
extern void BTL_MAIN_StartRecordPlayback(unsigned char *p, unsigned char *q);
extern void BTL_MAIN_CreateViewCore(unsigned char *p, unsigned char *q, int r);
extern u32 BTL_CLIENT_GetNetChannel(struct QB *p);
extern void BTL_SERVER_SetClientAdapter(char *p, int b, u8 c, u8 d);
extern void BTL_SERVER_Restart(char *p);
extern int BTL_MAIN_StepClientsSolo(int a);
extern int BTL_MAIN_IsClientUsed(unsigned char *p, unsigned char k);
extern unsigned int BTL_MAIN_CountClientTrainers(unsigned char *p, int k);
extern void BTL_TRAINER_SLOT_InitPlayer(char *p, int a, int b);
extern void BTL_TRAINER_SLOT_InitFromData(struct A *p, struct B *src);
extern void BTL_MAIN_InitTrainerSlot(int a, int b);
extern void BTL_REC_InitReader(void *, int, int);
extern void BTL_CLIENT_AttachRemoteLink(u8 *p, void *a);
int BTL_MAIN_TaskSetupMulti(int unused, u8 *p)
{
    u8 *q;
    int i;
    u8 k;
    int b;
    u8 *desc;
    u8 *table;
    int t;
    q = *(u8 * *)&((struct Obj00886 *)p)->f0;
    t = (int)BTL_MAIN_IsCommCompetitor((unsigned int *)q);
    p[0x46c] = 0;
    p[0x46b] = 2;
    p[0x428] = 0;
    p[0x42a] = 0;
    p[0x429] = 1;
    p[0x42b] = 1;
    switch (q[0x22]) {
    case 0: break;
    case 1: case 2: case 3:
        p[0x42a] = 2;
        p[0x42b] = 3;
        p[0x46b] = 4;
        break;
    case 4:
        p[0x42b] = 3;
        p[0x46b] = 3;
        break;
    }
    BTL_MAIN_SetupOwnClient(p, (struct T *)q);
    BTL_SIDE_Init((char *)p + 0xc8, (u32)p, 0);
    BTL_SIDE_Init((char *)p + 0x1b0, (u32)p, 1);
    for (i = 0; i < 4; i++) {
        if (BTL_MAIN_IsClientUsed(p, i)) {
            BTL_SIDE_SetupClientParty((char *)(p + 0xc8), (char *)p, i);
            BTL_SIDE_SetupClientParty((char *)(p + 0x1b0), (char *)p, i);
        }
    }
    if (!q[0x23]) {
        BTL_TRAINER_SLOT_InitPlayer((char *)((int)(p + 0x20)), ((struct Obj00886 *)p)->f468, ((struct Obj00886 *)p)->fC0);
        BTL_TRAINER_SLOT_InitFromData((struct A *)((int)(p + 0x48)), (struct B *)(((struct Obj02772 *)q)->f4C));
        if (BTL_MAIN_IsClientUsed(p, 2)) BTL_TRAINER_SLOT_InitFromData((struct A *)((int)(p + 0x70)), (struct B *)(((struct Obj02772 *)q)->f50));
        if (BTL_MAIN_IsClientUsed(p, 3)) BTL_TRAINER_SLOT_InitFromData((struct A *)((int)(p + 0x98)), (struct B *)(((struct Obj02772 *)q)->f54));
    } else {
        for (i = 0; i < 4; i++) {
            if (BTL_MAIN_IsClientUsed(p, i)) BTL_MAIN_InitTrainerSlot((int)p, (u8)i);
        }
    }
    ((struct Obj00886 *)p)->f8 = (int)BTL_SERVER_Create(p, (struct Copy24 *)(p + 0x3f0), p + 0x1b0, t, ((struct Obj00886 *)p)->f468);
    p[0x46e] = 1;
    table = p + 0x3f0;
    desc = p + 0xc8;
    for (i = 0; i < 4; i++) {
        if (BTL_MAIN_IsClientUsed(p, i)) {
            k = BTL_MAIN_CountClientTrainers(p, (unsigned char)i);
            b = 0;
            if (i != 0) b = 1;
            *(int *)(p + i * 4 + 0x10) = (int)BTL_CLIENT_Create(p, desc, 0, ((struct Obj02772 *)q)->f1C, i, (u8)k, b, t, (u8)q[0x23], (struct Copy24 *)table, ((struct Obj00886 *)p)->f468);
        }
    }
    if (q[0x23]) {
        BTL_REC_InitReader(p + 0x2c8, ((struct Obj02772 *)q)->f94, ((struct Obj02772 *)q)->f98);
        for (i = 0; i < 4; i++) {
            if (BTL_MAIN_IsClientUsed(p, i)) BTL_CLIENT_AttachRemoteLink((u8 *)(*(int *)(p + i * 4 + 0x10)), p + 0x2c8);
        }
    }
    BTL_MAIN_CreateViewCore(p, q, t);
    for (i = 0; i < 4; i++) {
        if (BTL_MAIN_IsClientUsed(p, i)) {
            k = BTL_MAIN_CountClientTrainers(p, (unsigned char)i);
            BTL_SERVER_SetClientAdapter((char *)(((struct Obj00886 *)p)->f8), BTL_CLIENT_GetNetChannel((struct QB *)(*(int *)(p + i * 4 + 0x10))), i, k);
        }
    }
    BTL_SERVER_Restart((char *)(((struct Obj00886 *)p)->f8));
    ((struct Obj00886 *)p)->f464 = (u32)BTL_MAIN_StepClientsSolo;
    return 1;
}
