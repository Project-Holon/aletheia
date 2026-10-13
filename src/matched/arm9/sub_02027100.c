/*
 * function: GAME_BEACON_SetQuestionnaire
 * address:  0x02027100
 * packet:   pkt_020266E0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GAME_BEACON_Work   0x02146940  data
 *   MI_CpuCopy8  0x02082D44  arm
 */

typedef unsigned char u8;
typedef unsigned int  u32;

extern void *GAME_BEACON_Work;
extern void MI_CpuCopy8(const void *src, void *dest, u32 size);

struct Sub {
    u8 pad[0x50];
    u8 field_50[10];
    u8 pad2[4];
    u8 field_5E;
};

struct Struct_02027100 {
    u32 header;
    struct Sub sub;
};

void GAME_BEACON_SetQuestionnaire(const void *src)
{
    struct Struct_02027100 *ptr = *(struct Struct_02027100 **)&GAME_BEACON_Work;
    struct Sub *sub = &ptr->sub;

    MI_CpuCopy8(src, sub->field_50, 10);
    sub->field_5E = 1;
}
