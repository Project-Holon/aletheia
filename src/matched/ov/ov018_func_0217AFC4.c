/*
 * function: INTRUDE_FIELD_FindRemotePlayerAhead
 * address:  0x0217AFC4
 * packet:   pkt_ov018_0217AFC4
 * region:   ov018
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELD_PLAYER_GetFormCode  0x021A3098  thumb  ov021
 *   FIELD_PLAYER_GetFrontGridPos  0x021A3460  thumb  ov021
 *   COMM_PLAYER_SearchGridPos  0x021679A4  thumb  ov010
 */

typedef short s16;

typedef unsigned char  u8;
extern unsigned int FIELD_PLAYER_GetFormCode(u8 *p);
typedef unsigned int   u32;
extern int FIELD_PLAYER_GetFrontGridPos(u32 a, u32 b, u32 c, u32 d);
extern int COMM_PLAYER_SearchGridPos(int, int, int, int, int *, int *);

int INTRUDE_FIELD_FindRemotePlayerAhead(int *a, u8 *b, int *out)
{
    int r;
    int idx;
    int hit;
    int ret;
    s16 v[3];

    ret = 0;
    hit = ret;
    if (a == 0 || a[2] == 0)
        return 0;
    r = FIELD_PLAYER_GetFormCode(b);
    if (r != 0 && r != 1)
        return ret;
    FIELD_PLAYER_GetFrontGridPos((u32)b, (u32)(v + 2), (u32)(v + 1), (u32)v);
    for (;;) {
        r = COMM_PLAYER_SearchGridPos(a[2], v[2], v[1], v[0], &idx, &hit);
        if (r != 1)
            break;
        if (*(int *)((char *)a + idx * 28 + 0x8c) == 0) {
            *out = idx;
            return 1;
        }
    }
    return 0;
}
