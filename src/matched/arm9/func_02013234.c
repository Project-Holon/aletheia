/*
 * function: BTL_SETUP_CreateTrainerData
 * address:  0x02013234
 * packet:   pkt_02013234
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   sZonedataFile  0x020A729C  data
 *   PMSI_PARAM_ClearSentence  0x0202428C  thumb
 *   STRBUF_Create  0x020457B0  arm
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/BTL_SETUP_CreateTrainerData.c \
 *       --func BTL_SETUP_CreateTrainerData --addr 0x02013234 --cc 1.1p1 --thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed short s16;
typedef signed char s8;

struct Obj {
    u32  unk00;
    u8   pad04[0x10];
    void *unk14;
    u8   pad18[0x18];
};

struct U16Vec;
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern struct U16Vec *STRBUF_Create(u32 capacity, u32 heapId);
extern void  PMSI_PARAM_ClearSentence(void *p);
extern u8    sZonedataFile;

void *BTL_SETUP_CreateTrainerData(u32 heap)
{
    struct Obj *p;

    p = func_02030734(heap, 0x28, 1, (const char *)&sZonedataFile, 0xef);
    p->unk14 = STRBUF_Create(0x10, heap);
    p->unk00 = 0;
    PMSI_PARAM_ClearSentence(&p->pad18[0]);
    PMSI_PARAM_ClearSentence(&p->pad18[8]);
    return p;
}
