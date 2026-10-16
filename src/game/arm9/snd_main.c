/*
 * file:     snd_main.c
 * unit:     yes
 * function: SND_Init, SNDi_LockMutex, SNDi_UnlockMutex
 * address:  0x02089848
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   OS_InitMutex                 0x02086004  arm
 *   SND_CommandInit              0x020898A8  arm
 *   SND_AlarmInit                0x02089F88  arm
 *   _ZZ8SND_InitvE11initialized  0x02151450  data
 *   sSndMutex                    0x02151454  data
 *   OS_LockMutex    0x02086028  arm
 *   s_data_02151454  0x02151454  data
 *   OS_UnlockMutex    0x02086078  arm
 */
typedef int BOOL;

typedef struct OSMutex OSMutex;

extern void OS_InitMutex(OSMutex *mutex);
extern void SND_CommandInit(void);
extern void SND_AlarmInit(void);
extern void OS_LockMutex(void *arg);
extern void OS_UnlockMutex(void *arg);
void SND_Init(void);
void SNDi_LockMutex(void);
void SNDi_UnlockMutex(void);
/* SND_Init's function-local static "initialized" */
extern BOOL _ZZ8SND_InitvE11initialized;
extern OSMutex sSndMutex;


/*
 * sdk:      SND_Init (snd_main.o)
 */
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


void SNDi_LockMutex(void)
{
    OS_LockMutex(&sSndMutex);
}


void SNDi_UnlockMutex(void)
{
    OS_UnlockMutex(&sSndMutex);
}
