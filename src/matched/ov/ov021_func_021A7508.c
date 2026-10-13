/*
 * function: FIELD_GROUND_ANIME_AnmEntryInit
 * address:  0x021A7508
 * packet:   pkt_ov021_021A7508
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02030734  0x02030734  arm
 *   _FieldGroundAnimeFileName  0x021DDF7C  data  a4
 */

typedef unsigned int u32;

typedef struct {
    u32 f0;
    void *f4;
    u32 f8;
} S;

typedef unsigned short u16;
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern char _FieldGroundAnimeFileName[];

void FIELD_GROUND_ANIME_AnmEntryInit(S *s, u32 b, int heap)
{
    s->f4 = func_02030734(heap, 0x80, 1, _FieldGroundAnimeFileName, 0x206);
    s->f8 = b;
}
