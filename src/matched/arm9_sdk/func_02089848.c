/*
 * function: SND_Init
 * address:  0x02089848
 * packet:   pkt_02089848
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      SND_Init (snd_main.o)
 *
 * symbols:
 *   OS_InitMutex                 0x02086004  arm
 *   SND_CommandInit              0x020898A8  arm
 *   SND_AlarmInit                0x02089F88  arm
 *   _ZZ8SND_InitvE11initialized  0x02151450  data
 *   sSndMutex                    0x02151454  data
 */

typedef int BOOL;
typedef struct OSMutex OSMutex;

extern void OS_InitMutex(OSMutex *mutex);
extern void SND_CommandInit(void);
extern void SND_AlarmInit(void);

/* SND_Init's function-local static "initialized" */
extern BOOL _ZZ8SND_InitvE11initialized;
extern OSMutex sSndMutex;

void SND_Init(void)
{
    if (_ZZ8SND_InitvE11initialized) {
        return;
    }
    _ZZ8SND_InitvE11initialized = 1;
    OS_InitMutex(&sSndMutex);
    SND_CommandInit();
    SND_AlarmInit();
}
