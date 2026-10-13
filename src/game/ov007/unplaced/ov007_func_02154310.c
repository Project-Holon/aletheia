/*
 * function: func_02154310
 * address:  0x02154310
 * packet:   pkt_ov007_02154310
 * region:   ov007
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Stage machine on *mode, same family as ov004 func_02154390; the task
 * callback func_021542CC installs.  Second argument to func_020120B4 is
 * pooled 0x74 (116), a linker overlay id; the third lies in ov116.
 *
 * symbols:
 *   func_0201210C  0x0201210C  thumb
 *   func_02012138  0x02012138  thumb
 *   func_02026454  0x02026454  thumb
 *   func_020144DC  0x020144DC  thumb
 *   func_02012374  0x02012374  thumb
 *   func_020120B4  0x020120B4  thumb
 *   func_020120F0  0x020120F0  thumb
 *   func_020145CC  0x020145CC  thumb
 *   func_021BE8D4  0x021BE8D4  thumb  ov021
 *   func_021BE92C  0x021BE92C  thumb  ov021
 *   ov116_id       0x00000074  data   a1
 *   d_021D83A4     0x021D83A4  data   ov116  a4
 */

typedef unsigned int u32;
typedef unsigned short u16;

struct GameSystem;
struct GameEvent;
struct ProcHandle;
extern void *func_0201210C(const struct GameSystem *gameSystem);
extern u32   func_02012138(const struct GameSystem *gameSystem);
typedef unsigned char  u8;
extern u32 func_02026454(void *gameComm);
extern int func_020144DC(int gameSystem, int fieldMap);
extern void func_02012374(struct GameEvent *event, struct GameEvent **callee);
extern void func_020120B4(struct ProcHandle *gameSystem, u32 overlayId, void *procData, void *procArgs);
extern u32 func_020120F0(const struct GameSystem *gameSystem);
extern void *func_020145CC(void *gameSystem);
extern int func_021BE8D4(void *gameSystem, int fieldMap, int sel, int d);
extern int func_021BE92C(void *gameSystem, int fieldMap, int sel, int d, int e, u8 f, u8 g);

extern char ov116_id[];
extern char d_021D83A4[];

u32 func_02154310(void *event, u32 *stage, u32 *work)
{
    u32 gameSystem = work[1];
    void *fieldMap = func_0201210C((void *)gameSystem);

    switch (*stage) {
    case 0:
        if (func_02026454((void *)((int)func_02012138((const struct GameSystem *)gameSystem))) == 0)
            (*stage)++;
        break;
    case 1:
        func_02012374(event, (struct GameEvent **)func_021BE8D4((void *)gameSystem, (int)fieldMap, 0, 0));
        (*stage)++;
        break;
    case 2:
        func_02012374(event, (struct GameEvent **)func_020144DC(gameSystem, (int)fieldMap));
        (*stage)++;
        break;
    case 3:
        func_020120B4((struct ProcHandle *)gameSystem, (u32)ov116_id, d_021D83A4, work);
        (*stage)++;
        break;
    case 4:
        if (func_020120F0((const struct GameSystem *)gameSystem) == 0) {
            if (work[2] == 0)
                *(u16 *)work[3] = 1;
            else
                *(u16 *)work[3] = 0;
            (*stage)++;
        }
        break;
    case 5:
        func_02012374(event, func_020145CC((void *)gameSystem));
        (*stage)++;
        break;
    case 6:
        func_02012374(event, (struct GameEvent **)func_021BE92C((void *)gameSystem, (int)fieldMap, 0, 0, 1, 0, 0));
        (*stage)++;
        break;
    case 7:
        return 1;
    }
    return 0;
}
