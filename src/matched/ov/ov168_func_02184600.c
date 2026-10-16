/*
 * function: MICTEST_SpawnSprite
 * address: 0x02184600
 * packet: pkt_ov168_02184600
 * region: ov168
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020056EC 0x020056EC thumb
 *   MICTEST_InitSpriteTask 0x02184680 thumb ov168
 */
typedef unsigned int   u32;
extern u32 func_020056EC(u32 range);
typedef unsigned short u16;
extern void MICTEST_InitSpriteTask(void *, void *, void *, u16, int, int, int, int, int);
int MICTEST_SpawnSprite(char *p, int unused, u16 x, int y, void *owner)
{
    void *sprite = 0;
    char *entry = 0;
    int i;
    int a;
    int b;
    int c;
    for (i = 0; i < 3; i++) {
        if (*(int *)(p + i * 0x30 + 0x7c) == 0) {
            entry = p + 0x50 + i * 0x30;
            sprite = *(void **)(p + (i + 4) * 4);
            break;
        }
    }
    if (entry) {
        a = func_020056EC(0x1001) + 0x1333;
        b = func_020056EC(61) + 60;
        c = func_020056EC(15) + 6;
        MICTEST_InitSpriteTask(owner, sprite, entry, x, y, a, b, c, 1);
        return 1;
    }
    return 0;
}
