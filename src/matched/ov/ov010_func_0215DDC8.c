/*
 * function: func_0215DDC8
 * address:  0x0215DDC8
 * packet:   pkt_ov010_0215DDC8
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Allocate the 0x38-byte link work, clear its first two words, attach
 * it to the save handle and load overlays 132 and 112.
 *
 * The call to arm9 0x02012F74 (the +0x6A8 setter beside GAME_DATA_GetExternalWork)
 * resolves since seeds_2 labelled and matched it (src/matched/unit_02012F68.c).
 *
 * symbols:
 *   func_02030734  0x02030734  arm
 *   GAME_DATA_SetExternalWork  0x02012F74  thumb
 *   func_02034AC4  0x02034AC4  arm
 *   ov132_id       0x00000084  data
 *   ov112_id       0x00000070  data
 *   d_02172914     0x02172914  data  a1
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef short s16;

typedef struct Work {
    u32 f00;
    u32 f04;
} Work;

extern u8 ov132_id[];
extern u8 ov112_id[];
extern const char d_02172914[];

typedef signed int     s32;
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void GAME_DATA_SetExternalWork(void *h, void *w);
extern int func_02034AC4(s32 handle);

void func_0215DDC8(void *unused, void *h)
{
    Work *w = func_02030734(4, 0x38, 1, d_02172914, 0x413);

    w->f00 = 0;
    w->f04 = 0;
    GAME_DATA_SetExternalWork(h, w);
    func_02034AC4((u32)ov132_id);
    func_02034AC4((u32)ov112_id);
}
