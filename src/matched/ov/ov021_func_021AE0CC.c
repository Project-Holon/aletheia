/*
 * function: EVENT_TRAINER_EYE_Check
 * address:  0x021AE0CC
 * packet:   pkt_ov021_021AE0CC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   EVENT_TRAINER_EYE_FindTrainer  0x021AE1FC  thumb  ov021
 *   EVENT_POKE_STATUS_GetRecordField2  0x0215A4C8  thumb  ov010
 *   FIELDMAP_GetGameSystem  0x02188C80  thumb  ov021
 *   FIELD_EVENT_CHECK_CountAlivePartyMembers  0x0218B6AC  thumb  ov021
 *   EVENT_TRAINER_EYE_CreateScriptWork  0x021AE930  thumb  ov021
 *   EVENT_POKE_STATUS_SetTrainerRecord  0x0215A438  thumb  ov010
 *   EVENT_TRAINER_EYE_FindPartner  0x021AE8D4  thumb  ov021
 *   EVENT_TRAINER_EYE_FillHit  0x021AE8B4  thumb  ov021
 */

typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct Rec {
    u32 f0;
    u32 f4;
    u32 f8;
    u32 fc;
    u32 f10;
    u32 f14;
} Rec;

extern int EVENT_TRAINER_EYE_FindTrainer(int a, void *b, int c);
extern int EVENT_POKE_STATUS_GetRecordField2(int a0);
extern void *FIELDMAP_GetGameSystem(void *p);
extern int FIELD_EVENT_CHECK_CountAlivePartyMembers(void *ctx);
extern int EVENT_TRAINER_EYE_CreateScriptWork(int a, u32 b);
extern void EVENT_POKE_STATUS_SetTrainerRecord(int a, int b, Rec *src);
extern u32 EVENT_TRAINER_EYE_FindPartner(u32 a, u16 b);
struct S;
extern void EVENT_TRAINER_EYE_FillHit(struct S *s, u32 a, u32 b, u32 c);

int EVENT_TRAINER_EYE_Check(int a)
{
    Rec b;
    Rec c;
    u32 kind;
    u32 n;
    int z = 0;
    int ret = 0;

    if (EVENT_TRAINER_EYE_FindTrainer(a, 0, (int)(&b)) == 1) {
        kind = (u32)EVENT_POKE_STATUS_GetRecordField2((u16)b.f10);
        n = FIELD_EVENT_CHECK_CountAlivePartyMembers(FIELDMAP_GetGameSystem((void *)a));
        if (kind == 0) {
            if (n < 2 || EVENT_TRAINER_EYE_FindTrainer(a, (void *)b.f0, (int)(&c)) == 0) {
                ret = EVENT_TRAINER_EYE_CreateScriptWork(a, b.f0);
                b.f14 = 0;
                EVENT_POKE_STATUS_SetTrainerRecord(ret, 0, &b);
            } else {
                ret = EVENT_TRAINER_EYE_CreateScriptWork(a, b.f0);
                b.f14 = 2;
                EVENT_POKE_STATUS_SetTrainerRecord(ret, z, &b);
                c.f14 = 2;
                EVENT_POKE_STATUS_SetTrainerRecord(ret, 1, &c);
            }
        } else if (kind == 1) {
            if (n >= 2) {
                EVENT_TRAINER_EYE_FillHit((struct S *)(&c), EVENT_TRAINER_EYE_FindPartner(b.f0, b.f10), b.f4, (u16)b.f8);
                ret = EVENT_TRAINER_EYE_CreateScriptWork(a, b.f0);
                b.f14 = 1;
                EVENT_POKE_STATUS_SetTrainerRecord(ret, z, &b);
                c.f14 = 1;
                EVENT_POKE_STATUS_SetTrainerRecord(ret, 1, &c);
            }
        } else if (kind == 2 || kind == 3) {
            if (n >= 3) {
                ret = EVENT_TRAINER_EYE_CreateScriptWork(a, b.f0);
                b.f14 = z;
                EVENT_POKE_STATUS_SetTrainerRecord(ret, z, &b);
            }
        }
    }
    return ret;
}
