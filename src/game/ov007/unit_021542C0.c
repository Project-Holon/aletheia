/*
 * file:     unit_021542C0.c
 * unit:     yes
 * function: func_021542C0, func_021542CC
 * address:  0x021542C0
 * region:   ov007
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_020120F4  0x020120F4  thumb
 *   func_020122C0  0x020122C0  thumb
 *   func_02012138  0x02012138  thumb
 *   func_02026454  0x02026454  thumb
 *   func_02026400  0x02026400  thumb
 *   func_020124E8  0x020124E8  thumb
 *   func_02154310  0x02154310  thumb  ov007
 */
struct GameSystem;
struct GameComm;
struct GameEvent;
struct GameEventWork;
typedef struct BsubwayProcArgs {
    int value;
    int *resultPtr;
} BsubwayProcArgs;

typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

void *func_020120F4(const struct GameSystem *gameSystem);
struct GameEvent *func_020122C0(void *gameSystem, void *eventFileName, void *eventMain, u32 workSize);
u32 func_02012138(const struct GameSystem *gameSystem);
u32 func_02026454(void *gameComm);
void func_02026400(struct GameComm *gameComm);
void *func_020124E8(struct GameEvent *event);
u32 func_02154310(void *event, u32 *stage, u32 *work);
int func_021542C0(int gameSystem, BsubwayProcArgs *args);
void *func_021542CC(void *gameSystem, int value, int resultPtr);


int func_021542C0(int gameSystem, BsubwayProcArgs *args)
{
    return (int)func_021542CC((void *)gameSystem, args->value, (int)args->resultPtr);
}


void *func_021542CC(void *gameSystem, int value, int resultPtr)
{
    void *event;
    int *work;

    func_020120F4(gameSystem);
    event = func_020122C0(gameSystem, 0, func_02154310, 0x10);
    work = func_020124E8(event);
    work[0] = value;
    work[1] = (int)gameSystem;
    work[3] = resultPtr;
    if (func_02026454((void *)func_02012138(gameSystem)))
        func_02026400((struct GameComm *)func_02012138(gameSystem));
    return event;
}
