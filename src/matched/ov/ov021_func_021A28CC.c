/*
 * function: WEATHER_TASK_AllocParticles
 * address:  0x021A28CC
 * packet:   pkt_ov021_021A28CC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02030734  0x02030734  arm
 *   WEATHER_TASK_CreateParticleActor  0x021A2BD4  thumb  ov021
 *   gWeatherTaskFileName     0x021DDE80  data  a4
 */

typedef struct {
    char pad0[2];
    unsigned short n;
    char pad4[0x24];
    int f28;
} Hdr;

typedef struct {
    int f0;
    char pad4[0x18];
    int pad1c;
    Hdr *hdr;
    char pad24[4];
    char sub[0x14];
    int f3c;
} Obj;

extern int gWeatherTaskFileName;

void *func_02030734(unsigned int a, unsigned int b, int c, const char *d, unsigned short e);
void WEATHER_TASK_CreateParticleActor(void *p, void *o, void *s, int a, int b);

void WEATHER_TASK_AllocParticles(Obj *o, int heap)
{
    int i;

    o->f3c = (int)func_02030734(heap, o->hdr->f28, 1, (const char *)&gWeatherTaskFileName, 0x874);
    if (o->hdr->n != 0) {
        for (i = 0; i < 0x20; i++) {
            WEATHER_TASK_CreateParticleActor((char *)o + 0x74 + i * 0x38, o, o->sub, o->f0, heap);
        }
    }
}
