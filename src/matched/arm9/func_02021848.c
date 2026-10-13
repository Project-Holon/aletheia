/*
 * function: PALANM_RequestFadeOverwrite
 * address:  0x02021848
 * packet:   pkt_0202173C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Palette-animation engine (palanm.c). For each of the fourteen channels
 * whose bit is set in `mask`: narrow the colour to the channel's
 * width (PALANM_MaskColorBits, through the address of `col`, which is why all
 * four register parameters are pushed), initialise the channel's
 * animation sub-object at +0xC, mark the channel (PALANM_SetTransBit), run it
 * once (PALANM_ApplyFade, 0x10 for channels 0..3, 0x100 for 4..0xD) and
 * restore `col`. If any channel started, store the mask to a_big and, when the tick
 * is not registered yet (b_x), set b_x, a_mode = 1, clear the latch and
 * register PALANM_FadeTask with func_02030DA8 at priority -2. Returns 1 when
 * a channel started.
 *
 * Written fresh in wave 20 (lane palanm_fresh). The 33-byte residue of
 * earlier waves (the entry `str r3, [sp, #8]` sliding behind the stack
 * parameter copies) closes with the parameter types read from the callee:
 * `step` is narrow (s16 here; u16 and s8 give the same bytes), and b, c,
 * d are u8, u8, u16 both here and in the PALANM_SetFadeParam prototype (its own
 * matched body). The narrow step's home store is then emitted at the
 * front of the prologue
 * (docs/idioms/a-narrow-parameter-pins-its-home-store-to-the-front-of-the-prologue.md).
 * With u32 b, c, d in the prototype the same source is 236 bytes.
 * PALANM_SetFadeParam is declared with six parameters: the caller passes six and
 * the callee's seventh (never read) is whatever sits at [sp, #8].
 *
 * symbols:
 *   PALANM_CheckBit  0x02021930  thumb
 *   PALANM_SetTransBit  0x02021944  thumb
 *   PALANM_MaskColorBits  0x02021984  thumb
 *   PALANM_SetFadeParam  0x020219C4  thumb
 *   PALANM_FadeTask  0x02021A84  thumb
 *   PALANM_ApplyFade  0x02021BC8  thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed   short s16;
typedef signed   int   s32;
typedef signed   char  s8;

typedef struct {
    u16 *src;
    u16 *dst;
    u32 f8;
    u32 fc;
    u32 f10;
} PalAnmChan;

typedef struct {
    PalAnmChan ch[14];
    u16 a_mode : 2;
    u16 a_big  : 14;
    u16 b_lo : 14;
    u16 b_x  : 1;
    u16 b_hi : 1;
    u8  latch;
} PalAnmObj;

extern u8 PALANM_CheckBit(u32 val, int bit);
struct Chan02021984;
struct S02021944;
struct S02021A84;
extern void PALANM_SetTransBit(struct S02021944 *p, int a1);
extern void PALANM_MaskColorBits(s32 idx, struct Chan02021984 *c, u16 *pv);
struct S020219C4;
extern void PALANM_SetFadeParam(struct S020219C4 *s, u16 f0, s32 a, u8 b, u8 c, u16 d);
extern void PALANM_ApplyFade(u8 *p, u32 idx, u32 arg);
extern void PALANM_FadeTask(void *a, struct S02021A84 *p);
extern void func_02030DA8(void *ctx, void (*fn)(void *, PalAnmObj *), PalAnmObj *p, s32 pri);

int PALANM_RequestFadeOverwrite(PalAnmObj *p, u16 mask, u16 col, s16 step, u8 b, u8 c, u16 d, void *ctx)
{
    u16 keep = col;
    int ret = 0;
    u8 i;

    for (i = 0; i < 14; i++) {
        if (PALANM_CheckBit(mask, i) == 1) {
            PALANM_MaskColorBits(i, (struct Chan02021984 *)(&p->ch[i]), &col);
            PALANM_SetFadeParam((struct S020219C4 *)(&p->ch[i].fc), col, step, b, c, d);
            PALANM_SetTransBit((struct S02021944 *)p, i);
            if (i >= 4) {
                PALANM_ApplyFade((u8 *)p, i, 0x100);
            } else {
                PALANM_ApplyFade((u8 *)p, i, 0x10);
            }
            col = keep;
            ret = 1;
        }
    }
    if (ret == 1) {
        p->a_big = mask;
        if (p->b_x == 0) {
            p->b_x = 1;
            p->a_mode = 1;
            p->latch = 0;
            func_02030DA8(ctx, (void (*)(void *, PalAnmObj *))PALANM_FadeTask, p, -2);
        }
    }
    return ret;
}
