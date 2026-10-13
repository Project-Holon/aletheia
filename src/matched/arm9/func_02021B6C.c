/*
 * function: PALANM_StepFadeWait
 * address:  0x02021B6C
 * packet:   pkt_02021B6C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   PALANM_CheckBit   0x02021930  thumb
 *   PALANM_ApplyFade   0x02021BC8  thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u8 PALANM_CheckBit(u32 val, int bit);
extern void PALANM_ApplyFade(u8 *p, u32 idx, u32 arg);

struct S02021B6C {
    u8 pad0[0xe];
    u16 cap : 6;
    u16 padE : 10;
    u16 pad10[1];
    u16 pad12a : 5;
    u16 cur : 6;
    u16 pad12b : 5;
};

struct S02021B6C_hdr {
    u16 pad118a : 2;
    u16 flags118 : 14;
};

void PALANM_StepFadeWait(u8 *p, u32 idx, u32 arg)
{
    struct S02021B6C_hdr *hdr = (struct S02021B6C_hdr *)(p + 0x118);

    if (PALANM_CheckBit(hdr->flags118, idx) == 0) {
        return;
    }

    {
        struct S02021B6C *s = (struct S02021B6C *)(p + idx * 0x14);

        if (s->cur < s->cap) {
            s->cur = s->cur + 1;
        } else {
            s->cur = 0;
            PALANM_ApplyFade(p, idx, arg);
        }
    }
}
