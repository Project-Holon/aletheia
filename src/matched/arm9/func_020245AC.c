/*
 * function: PMSI_PARAM_ClearUnusedWords
 * address:  0x020245AC
 * packet:   pkt_020245AC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   PMSI_PARAM_GetWordCount  0x02024498  thumb
 */

typedef unsigned short u16;
typedef unsigned int   u32;

struct T {
    u16 f00;
    u16 f02;
    u16 f04;
    u16 f06;
};

extern u32 PMSI_PARAM_GetWordCount(u32 a0, u32 a1, u32 a2);

void PMSI_PARAM_ClearUnusedWords(struct T *p, u32 a1)
{
    u32 n = PMSI_PARAM_GetWordCount(p->f00, p->f02, a1);

    if (n < 2) {
        do {
            *(u16 *)((char *)p + n * 2 + 4) = 0xffff;
            n++;
        } while (n < 2);
    }
}
