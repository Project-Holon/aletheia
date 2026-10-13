/*
 * function: MUSICAL_EVENT_GetProgramBestCategory
 * address:  0x02156908
 * packet:   pkt_ov010_02156908
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   MUSICAL_PROGRAM_GetBestCategory  0x021572C0  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef short s16;

typedef struct Work {
    u8 pad00[0x38];
    void *f38;          /* 0x38 */
} Work;

struct Deal;
extern u8 MUSICAL_PROGRAM_GetBestCategory(struct Deal *d);

u8 MUSICAL_EVENT_GetProgramBestCategory(Work *w)
{
    return MUSICAL_PROGRAM_GetBestCategory(w->f38);
}
