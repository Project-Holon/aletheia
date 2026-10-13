/*
 * function: GAME_BEACON_Setup
 * address:  0x020267BC
 * packet:   pkt_020266E0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * blocker:  02026D88 label
 *
 * symbols:
 *   GAME_BEACON_Work     0x02146940  data
 *   GAME_BEACON_BuildMyInfo  0x02026D88  thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;


extern u32 *GAME_BEACON_Work;

struct Rec;
extern void GAME_BEACON_BuildMyInfo(struct Rec *o, void *sys);
extern int func_02012FCC(int p0);
struct PlayTime;
extern u16 func_0200864C(const struct PlayTime *p);

void GAME_BEACON_Setup(u32 a0)
{
    u32 *p = GAME_BEACON_Work;

    *p++ = a0;
    GAME_BEACON_BuildMyInfo((struct Rec *)p, (void *)a0);
    *(u16 *)((char *)GAME_BEACON_Work + 0xbb0) =
        func_0200864C((const struct PlayTime *)func_02012FCC((int)((void *)a0)));
}
