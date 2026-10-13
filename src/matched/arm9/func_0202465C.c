/*
 * unit:     no
 * function: PMSI_PARAM_Validate
 * address:  0x0202465C
 * packet:   pkt_020245D4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   PMSI_PARAM_GetSentenceCount  0x02024584  thumb
 *   PMSI_PARAM_GetWordCount  0x02024498  thumb
 *   PMSI_PARAM_ValidateWord  0x020246C8  thumb
 */

typedef unsigned short u16;
typedef unsigned int   u32;

struct T {
    u16 f00;
    u16 f02;
    u16 f04;
    u16 f06;
};

typedef unsigned char  u8;
extern u8 PMSI_PARAM_GetSentenceCount(u32 i);
extern u32 PMSI_PARAM_GetWordCount(u32 a0, u32 a1, u32 a2);
extern u32 PMSI_PARAM_ValidateWord(u16 *p, u32 a1, u32 a2);

u32 PMSI_PARAM_Validate(struct T *p, u32 a1, u32 a2)
{
    u32 ok = 1;
    u32 n;
    u32 i;

    if (p->f00 >= 7 || p->f02 >= (u32)PMSI_PARAM_GetSentenceCount(p->f00)) {
        ok = 0;
        p->f00 = 0;
        p->f02 = 0;
    }

    n = PMSI_PARAM_GetWordCount(p->f00, p->f02, (u16)((a2 & 0x7FFF) | 0x8000));
    if (n > 2) {
        n = 2;
    }
    for (i = 0; i < n; i++) {
        if (PMSI_PARAM_ValidateWord(&p->f04 + i, a1, 1) == 0) {
            ok = 0;
        }
    }
    return ok;
}
