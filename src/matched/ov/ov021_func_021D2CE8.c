/*
 * function: SCRCMD_GREETING_AdjustMessageIdByMisc
 * address:  0x021D2CE8
 * packet:   pkt_ov021_021D2CE8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * The 0x0C-random-plus-0x5A path returns through its own temporary (an
 * else arm with a local); a direct `return f() + 0x5a` merges into v. The
 * loop index reuses the second parameter's register: v is copied out and the
 * parameter becomes the index, which gives the image's r1/r2/r3 colouring
 * (a fresh int index rotates them by one).
 *
 * symbols:
 *   gGreetingMiscMessageIds     0x021DD718  data  a4
 *   func_020056EC  0x020056EC  thumb
 *   BEACON_GetBlock  0x0200C0F0  thumb
 *   BEACON_GetFlag  0x0200C234  thumb
 *   GAME_DATA_GetSaveControl  0x02012EBC  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct Big;
extern void *GAME_DATA_GetSaveControl(struct Big *p);
extern void *BEACON_GetBlock(void *p);
extern int BEACON_GetFlag(void *p);
extern u32 func_020056EC(u32 v);
extern u32 gGreetingMiscMessageIds[];

u32 SCRCMD_GREETING_AdjustMessageIdByMisc(void *a, int i)
{
    u32 v = i;
    void *h = BEACON_GetBlock(GAME_DATA_GetSaveControl(a));

    for (i = 0; i < 8; i++) {
        if (v == gGreetingMiscMessageIds[i]) {
            if (BEACON_GetFlag(h)) {
                return v;
            } else {
                u32 r = func_020056EC(0xc);
                return r + 0x5a;
            }
        }
    }
    return v;
}
