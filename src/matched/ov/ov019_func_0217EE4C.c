/*
 * function: UNION_MSG_CheckLanguageVersion
 * address:  0x0217EE4C
 * packet:   pkt_ov019_0217EE4C
 * region:   ov019
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   GAME_DATA_GetMyStatus  0x02012944  thumb
 *   func_0200856C  0x0200856C  thumb
 *   func_02008570  0x02008570  thumb
 */

typedef unsigned char  u8;
struct Sub0200852CObj;
extern u8 *GAME_DATA_GetMyStatus(void *p);
extern u8 func_0200856C(const struct Sub0200852CObj *obj);
extern u8 func_02008570(const struct Sub0200852CObj *obj);

int UNION_MSG_CheckLanguageVersion(int **p, int x, int y)
{
    int v = (int)GAME_DATA_GetMyStatus((void *)((*p)[2]));
    int a = func_0200856C((const struct Sub0200852CObj *)v);
    int b = func_02008570((const struct Sub0200852CObj *)v);

    if (x == 0)
        return 15;
    if (a != x) {
        if (y == 0)
            return 13;
        return 12;
    }
    if (y == 0 || b == y)
        return 15;
    return 14;
}
