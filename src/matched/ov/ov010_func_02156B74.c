/*
 * function: MUSICAL_EVENT_ReceiveShowProgram
 * address:  0x02156B74
 * packet:   pkt_ov010_02156B74
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * 2026-10-05 (wave D9): EXACT. The callees 0x021FD954 and 0x021FD95C are the
 * two Thumb getters in ov132 (matched in ov132_func_021FD938.c); the symbols
 * lines now carry the ov132 token, which gave the witness.
 *
 * symbols:
 *   func_021FD954  0x021FD954  thumb  ov132
 *   func_021FD95C  0x021FD95C  thumb  ov132
 *   MUSICAL_PROGRAM_Create  0x02157028  thumb  ov010
 *   MUSICAL_PROGRAM_UnpackBonus  0x02157278  thumb  ov010
 *   MUSICAL_PROGRAM_UnpackPicks  0x021572A8  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Work {
    u8 pad00[0x14];
    u32 f14;            /* 0x14 */
    u8 pad18[0x24 - 0x18];
    void *f24;          /* 0x24 */
    void *f28;          /* 0x28 */
    u8 pad2C[0x38 - 0x2C];
    void *f38;          /* 0x38 */
    void *f3C;          /* 0x3C */
} Work;

struct Deal;
struct Src;
extern u32 func_021FD954(char *p);
extern u32 func_021FD95C(char *p);
extern struct Deal *MUSICAL_PROGRAM_Create(u32 heap, struct Src *src, u16 lim);
extern void MUSICAL_PROGRAM_UnpackBonus(u8 *p, u32 v);
extern void MUSICAL_PROGRAM_UnpackPicks(struct Deal *d, u32 v);

void MUSICAL_EVENT_ReceiveShowProgram(Work *w)
{
    u32 a;
    u32 b;

    a = func_021FD954(w->f28);
    b = func_021FD95C(w->f28);
    if (w->f38 == 0)
        w->f38 = MUSICAL_PROGRAM_Create(4, w->f24, 0);
    MUSICAL_PROGRAM_UnpackBonus(w->f38, a);
    MUSICAL_PROGRAM_UnpackPicks(w->f38, b);
}
