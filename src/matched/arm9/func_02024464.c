/*
 * function: PMSI_PARAM_IsComplete
 * address:  0x02024464
 * packet:   pkt_02024464
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

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;


struct T {
    u16 f00;
    u16 f02;
    u16 f04;
};

extern u32 PMSI_PARAM_GetWordCount(u32 a0, u32 a1, u32 a2);

int PMSI_PARAM_IsComplete(struct T *p, u32 a1)
{
    u32 n = PMSI_PARAM_GetWordCount(p->f00, p->f02, a1);
    u32 i;

    for (i = 0; i < n; i++) {
        if (*(u16 *)((char *)p + i * 2 + 4) == 0xffff) {
            return 0;
        }
    }
    return 1;
}
