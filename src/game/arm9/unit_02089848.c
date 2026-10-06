/*
 * file:     unit_02089848.c
 * unit:     yes
 * function: func_02089848, func_02089880, func_02089894
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
 *   func_02086028    0x02086028  arm
 *   s_data_02151454  0x02151454  data
 *   func_02086078    0x02086078  arm
 */
typedef int BOOL;

typedef struct OSMutex OSMutex;

extern void OS_InitMutex(OSMutex *mutex);
extern void SND_CommandInit(void);
extern void SND_AlarmInit(void);
extern void func_02086028(void *arg);
extern void func_02086078(void *arg);
void func_02089848(void);
void func_02089880(void);
void func_02089894(void);
/* SND_Init's function-local static "initialized" */
extern BOOL _ZZ8SND_InitvE11initialized;
extern OSMutex sSndMutex;
extern void *s_data_02151454;


/*
 * sdk:      SND_Init (snd_main.o)
 */
void func_02089848(void)
{
    if (_ZZ8SND_InitvE11initialized) {
        return;
    }
    _ZZ8SND_InitvE11initialized = 1;
    OS_InitMutex(&sSndMutex);
    SND_CommandInit();
    SND_AlarmInit();
}


void func_02089880(void)
{
    func_02086028(&s_data_02151454);
}


void func_02089894(void)
{
    func_02086078(&s_data_02151454);
}
