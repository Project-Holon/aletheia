/*
 * function: WEATHER_TASK_ShiftParticles
 * address:  0x021A2564
 * packet:   pkt_ov021_021A2564
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   WEATHER_TASK_GetParticleActorPtr  0x021A2C28  thumb  ov021
 *   CLACT_GetActorPos  0x0204B53C  arm
 *   CLACT_SetActorPos  0x0204B528  arm
 */

typedef struct { short x, y; } Pt;
typedef struct { char pad[0x774]; int *list; } Obj;

typedef unsigned int   u32;
typedef unsigned char  u8;
u32 WEATHER_TASK_GetParticleActorPtr(u8 *p);
struct Actor;
struct Pt;
void CLACT_GetActorPos(const struct Actor *actor, struct Pt *out);
void CLACT_SetActorPos(struct Actor *actor, const struct Pt *src);

void WEATHER_TASK_ShiftParticles(Obj *obj, int px, int py)
{
    int *p = obj->list;
    int h;
    int y;
    int x;
    Pt pt;

    if (p != 0) {
        x = (short)px;
        y = (short)py;
        do {
            h = WEATHER_TASK_GetParticleActorPtr((u8 *)((int)p));
            CLACT_GetActorPos((const struct Actor *)h, (struct Pt *)(&pt));
            pt.x = pt.x - x;
            pt.y = pt.y - y;
            CLACT_SetActorPos((struct Actor *)h, (const struct Pt *)(&pt));
            p = (int *)p[0x34 / 4];
        } while (p != obj->list);
    }
}
