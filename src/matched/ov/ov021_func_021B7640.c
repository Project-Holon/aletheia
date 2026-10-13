/*
 * function: PDW_POSTMAN_CreateReceivableList
 * address:  0x021B7640
 * packet:   pkt_ov021_021B7640
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GAME_DATA_GetMyItem  0x0201292C  thumb
 *   func_02030734  0x02030734  arm
 *   func_02009310  0x02009310  thumb
 *   func_02009330  0x02009330  thumb
 *   func_02007E3C  0x02007E3C  thumb
 *   sPdwPostmanFileName     0x021DE288  data   ov021  a1
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct Pair {
    u16 a;
    u16 b;
} Pair;

struct BigObj;
struct Sub02009210Obj;
extern void *GAME_DATA_GetMyItem(const struct BigObj *p);
extern void *func_02030734(u32 heap, u32 size, int a, const char *file, u16 line);
extern u16 func_02009310(const struct Sub02009210Obj *obj, int i);
extern u8 func_02009330(const struct Sub02009210Obj *obj, int i);
extern int func_02007E3C(void *a, u32 b, u32 c, u32 d);
extern u8 sPdwPostmanFileName[];

Pair *PDW_POSTMAN_CreateReceivableList(u32 a, u32 b, u32 c, int *d)
{
    Pair *buf;
    void *h;
    int n;
    int i;
    u16 x;
    u16 y;

    h = GAME_DATA_GetMyItem((const struct BigObj *)a);
    buf = func_02030734(b, 0x50, 1, (const char *)sPdwPostmanFileName, 0x14d);
    i = 0;
    n = 0;
    for (; i < 0x14; i++) {
        x = func_02009310((const struct Sub02009210Obj *)c, i);
        y = func_02009330((const struct Sub02009210Obj *)c, i);
        if (x != 0 && func_02007E3C(h, x, y, b) == 1) {
            buf[n].a = x;
            buf[n].b = y;
            n++;
        }
    }
    *d = n;
    return buf;
}
