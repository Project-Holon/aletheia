/*
 * function: WEATHER_TASK_FreeParticles
 * address:  0x021A2924
 * packet:   pkt_ov021_021A2924
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020307B0  0x020307B0  arm
 *   WEATHER_TASK_DestroyParticleActor  0x021A2C10  thumb  ov021
 *   WEATHER_TASK_ClearParticle  0x021A2BB8  thumb  ov021
 *   WEATHER_TASK_StopSe  0x021A25CC  thumb  ov021
 */

typedef struct {
    char pad0[2];
    unsigned short n;
} Hdr;

typedef struct {
    char pad0[0x20];
    Hdr *hdr;
    char pad24[0x18];
    void *f3c;
} Obj;

unsigned int func_020307B0(void *p);
typedef unsigned char  u8;
void WEATHER_TASK_DestroyParticleActor(u8 *p);
typedef unsigned int   u32;
void WEATHER_TASK_ClearParticle(u32 a);
void WEATHER_TASK_StopSe(u8 *p);

void WEATHER_TASK_FreeParticles(Obj *o)
{
    int i;

    if (o->f3c != 0) {
        func_020307B0(o->f3c);
        o->f3c = 0;
    }
    if (o->hdr->n != 0) {
        for (i = 0; i < 0x20; i++) {
            WEATHER_TASK_DestroyParticleActor((u8 *)((char *)o + 0x74 + i * 0x38));
            WEATHER_TASK_ClearParticle((u32)((char *)o + 0x74 + i * 0x38));
        }
    }
    WEATHER_TASK_StopSe((u8 *)o);
}
