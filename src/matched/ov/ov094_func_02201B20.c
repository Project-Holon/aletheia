/*
 * function: func_02201B20
 * address: 0x02201B20
 * packet: pkt_ov094_02201B20
 * region: ov094
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   d_0220A368 0x0220A368 data a4
 *   func_020490F4 0x020490F4 arm
 *   func_0204A6C8 0x0204A6C8 arm
 *   func_0204ACEC 0x0204ACEC arm
 *   func_0204AF28 0x0204AF28 arm
 *   func_021F86E0 0x021F86E0 thumb ov094
 *   func_0204AEF4 0x0204AEF4 arm
 *   func_02021640 0x02021640 thumb
 *   func_0204B294 0x0204B294 arm
 *   func_0204B324 0x0204B324 arm
 *   func_0204B92C 0x0204B92C arm
 *   func_02049238 0x02049238 arm
 */
typedef unsigned short u16;
typedef unsigned int u32;
typedef short s16;
typedef struct Config { s16 x, y; u32 rest[2]; u32 a, b, last; } Config;
extern const Config d_0220A368;
extern void *func_020490F4(unsigned int id, unsigned int heap);
extern int func_0204A6C8(u32, int, int, int, u16);
extern int func_0204ACEC(u32, u32, u32, u16, u16);
extern int func_0204AF28(u32, int, int, u16);
extern void *func_021F86E0(void);
extern u32 func_0204AEF4(int, int);
extern void func_02021640(void *, u32, u32, u32, u32, u32, u16);
extern u32 func_0204B294(u32, u32, u32, u32, Config *, u16, u16);
extern u32 func_0204B324(u32, u32, u32, u32, Config *, u16, u16);
extern void func_0204B92C(u32, int);
extern void func_02049238(u32);
int func_02201B20(char *p, u32 archiveId, int a, u32 b, int c, int d, s16 x, s16 y, u32 e, u32 f)
{
    Config cfg = d_0220A368;
    void *archive = func_020490F4(archiveId, (*(u16 *)(p + 0x80) & 0x7fff) | 0x8000);
    int i, off;
    void *slots;
    u32 pal;
    for (i = 0; i < 7; i++) {
        if (*(u32 *)(p + i * 16 + 8) == 0) break;
    }
    off = i * 16;
    *(int *)(p + 12 + off) = func_0204A6C8(archive, a, 0, 0, *(u16 *)(p + 0x80));
    *(int *)(p + 16 + off) = func_0204ACEC(archive, b, 0, i * 32 + 0x140, *(u16 *)(p + 0x80));
    *(int *)(p + 20 + off) = func_0204AF28(archive, c, d, *(u16 *)(p + 0x80));
    slots = func_021F86E0();
    pal = func_0204AEF4(*(int *)(p + 16 + off), 0);
    func_02021640(slots, archiveId, b, *(u16 *)(p + 0x80), 2, 32, (pal & 0x3ff) >> 1);
    cfg.x = x;
    cfg.y = y;
    if (e == 0 && f == 0) {
        *(u32 *)(p + 8 + off) = func_0204B294(*(u32 *)(p + 4), *(u32 *)(p + 12 + off), *(u32 *)(p + 16 + off), *(u32 *)(p + 20 + off), &cfg, 0, *(u16 *)(p + 0x80));
    } else {
        cfg.a = e;
        cfg.b = f;
        *(u32 *)(p + 8 + off) = func_0204B324(*(u32 *)(p + 4), *(u32 *)(p + 12 + off), *(u32 *)(p + 16 + off), *(u32 *)(p + 20 + off), &cfg, 0, *(u16 *)(p + 0x80));
    }
    func_0204B92C(*(u32 *)(p + 8 + off), 1);
    func_02049238(archive);
    return i;
}
