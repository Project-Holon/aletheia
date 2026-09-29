/*
 * function: func_021F0C44
 * address:  0x021F0C44
 * packet:   pkt_ov033_021F0C44
 * region:   ov033
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02030D28 0x02030D28 arm
 *   func_02021ED8 0x02021ED8 thumb
 *   func_0202173C 0x0202173C thumb
 *   func_0204B95C 0x0204B95C arm
 *   func_0204B974 0x0204B974 arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef signed   short s16;
typedef unsigned int   u32;

extern void func_02030D28(void *);
extern u32 func_02021ED8(void *);
extern int func_0202173C(void *p, u16 mask, u16 col, s16 step, u8 b, u8 c, u16 d, void *ctx);
extern void func_0204B95C(void *);
extern void func_0204B974(void *);

void func_021F0C44(char *p)
{
    u16 m;
    u8 i;

    func_02030D28(*(void **)(p + 0xB4));
    if (*(int *)(p + 0xC0) == 0 || func_02021ED8(*(void **)(p + 0xBC)) != 0)
        return;
    switch (*(int *)(p + 0xC0)) {
    case 1:
        if (*(int *)(p + 0xC4) != 0) {
            m = 0;
            for (i = 0; i < 3; i++)
                m |= (u16)(1 << i);
            func_0202173C(*(void **)(p + 0xBC), 2, m, 0, 0, 0, 0, *(void **)(p + 0xB4));
            m = 0;
            for (i = 0; i < 4; i++)
                m |= (u16)(1 << i);
            func_0202173C(*(void **)(p + 0xBC), 8, m, 0, 0, 0, 0, *(void **)(p + 0xB4));
            *(int *)(p + 0xC4) = 0;
            for (i = 0; i < 4; i++)
                func_0204B95C(*(void **)(p + i * 12 + 0x38));
        }
        break;
    case 2:
        if (*(int *)(p + 0xC4) != 1) {
            m = 0;
            for (i = 0; i < 3; i++)
                m |= (u16)(1 << i);
            func_0202173C(*(void **)(p + 0xBC), 2, m, 0, 8, 8, 0, *(void **)(p + 0xB4));
            m = 0;
            for (i = 0; i < 4; i++)
                m |= (u16)(1 << i);
            func_0202173C(*(void **)(p + 0xBC), 8, m, 0, 8, 8, 0, *(void **)(p + 0xB4));
            *(int *)(p + 0xC4) = 1;
            for (i = 0; i < 4; i++)
                func_0204B974(*(void **)(p + i * 12 + 0x38));
        }
        break;
    }
    *(int *)(p + 0xC0) = 0;
}
