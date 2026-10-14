/*
 * function: GURU2_MAIN_CenterActorTask
 * address: 0x021E121C
 * packet: pkt_ov137_021E121C
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   gGuru2CountSeTable 0x021E203C data a4
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   CLACT_AddActorAnimFrame 0x0204B8D4 arm
 *   CLACT_IsActorAnimActive 0x0204B98C arm
 *   CLACT_DeleteActor 0x0204B3B4 arm
 *   func_020307B0 0x020307B0 arm
 *   func_02030EAC 0x02030EAC arm
 */
typedef unsigned int u32;
typedef struct { int v[4]; } Table;
struct Actor;
extern const Table gGuru2CountSeTable;
struct Node;
extern void GFL_USE_PlaySeDefaultVolume(u32 a);
struct Obj;
extern void CLACT_AddActorAnimFrame(struct Obj *p, u32 arg);
extern u32 CLACT_IsActorAnimActive(struct Actor *);
extern void CLACT_DeleteActor(struct Obj *p);
extern u32 func_020307B0(void *p);
extern void func_02030EAC(struct Node *n);
void GURU2_MAIN_CenterActorTask(void *task, int *p)
{
    switch (p[0]) {
    case 0:
        if (p[3] < 4) {
            Table sounds = gGuru2CountSeTable;
            p[1]--;
            if (p[1] <= 0) {
                p[1] = 30;
                GFL_USE_PlaySeDefaultVolume(sounds.v[p[3]]);
                p[3]++;
            }
        }
        CLACT_AddActorAnimFrame((struct Obj *)p[5], 0x1800);
        if (CLACT_IsActorAnimActive((struct Actor *)p[5]) == 0) p[0]++;
        break;
    case 1:
        CLACT_DeleteActor((struct Obj *)p[5]);
        func_020307B0(p);
        func_02030EAC(task);
        break;
    }
}
