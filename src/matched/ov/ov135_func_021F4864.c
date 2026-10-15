/*
 * function: WORLDTRADE_VBlankTask
 * address:  0x021F4864
 * packet:   pkt_021F4864
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   CLACT_VBlankSystem  0x0204A648  arm  arm9
 *   BG_SYS_Update  0x020419E4  arm  arm9
 */

typedef signed char s8;
typedef signed short s16;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;

typedef void (*Cb)(void *p);

typedef struct {
    u8 pad0[0xEBC];
    Cb once;
    Cb every;
} Work;

extern void BG_SYS_Update(void);
extern void CLACT_VBlankSystem(void);

void WORLDTRADE_VBlankTask(void *unused, Work *p)
{
    BG_SYS_Update();
    CLACT_VBlankSystem();
    if (p->once != 0) {
        p->once(p);
        p->once = 0;
    }
    if (p->every != 0) {
        p->every(p);
    }
}
