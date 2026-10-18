/*
 * function: MICTEST_UpdateSpriteTask
 * address: 0x02184780
 * packet: pkt_ov168_02184780
 * region: ov168
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: two-byte alignment padding at 0x02184816.
 * blocker: ARM9 0x0203F5FC has no outside code witness.
 * Verified blocker C copied from GURU2_MAIN_UpdateRecordPosition.c;
 * S13/blocker_0203F5FC-r1.log reports EXACT, 64 bytes:
 *   symbols: FX_SinCosTable_ 0x020A1B38 data a2
 *   typedef unsigned short u16;
 *   extern const short FX_SinCosTable_[];
 *   int GF_STANDARD_Get_F5FC(u16 angle) {
 *       if (angle >= 360) return 0;
 *       return FX_SinCosTable_[((angle * 65535 / 360) >> 4) * 2];
 *   }
 * symbols:
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   VEC_Add 0x0207C9D0 arm
 *   GF_STANDARD_Get_F5FC 0x0203F5FC arm
 *   CLACT_SetActorPosAxis 0x0204B550 arm
 *   func_02030EAC 0x02030EAC arm
 */
typedef signed short s16;
typedef unsigned short u16;
struct Obj;
extern void CLACT_SetActorDrawEnable(struct Obj *p, unsigned int v);
extern void VEC_Add(void *, void *, void *);
typedef unsigned int   u32;
extern int GF_STANDARD_Get_F5FC(u32 x);
struct Actor;
extern void CLACT_SetActorPosAxis(struct Actor *actor, signed short value, u32 axis);
struct Node;
extern void func_02030EAC(struct Node *n);
void MICTEST_UpdateSpriteTask(void *task, int *p)
{
    s16 x;
    s16 y;
    int angle;
    if (p[1] != 0) {
        p[1]--;
        if (p[1] == 0)
            CLACT_SetActorDrawEnable((void *)p[0], 1);
        return;
    }
    VEC_Add(p + 2, p + 5, p + 2);
    x = p[2] >> 12;
    y = p[3] >> 12;
    p[8] += p[9];
    while (p[8] > 0x168000)
        p[8] -= 0x168000;
    angle = GF_STANDARD_Get_F5FC((u16)(p[8] >> 12));
    x += (s16)((p[10] * angle) >> 12);
    CLACT_SetActorPosAxis((void *)p[0], x, 0);
    CLACT_SetActorPosAxis((void *)p[0], y, 1);
    if (y < -16) {
        CLACT_SetActorDrawEnable((void *)p[0], 0);
        func_02030EAC(task);
        p[11] = 0;
    }
}
