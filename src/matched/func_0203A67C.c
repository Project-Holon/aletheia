/*
 * function: func_0203A67C
 * address:  0x0203A67C
 * packet:   pkt_0203A574
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   g_020A7AE8     0x020A7AE8  data
 *   g_020A7AE8_arr 0x020A7AE8  data
 *   g_020A7AF8     0x020A7AF8  data
 *   g_020A7B08     0x020A7B08  data
 *   g_021469D8     0x021469D8  data
 *   func_02034714  0x02034714  arm
 *
 * net_command.c's command-record lookup.  The 16-bit command is split into
 * a group (the high byte, kept unshifted throughout: the original compares
 * the masked value, never a shifted one) and an index (the low byte).
 *
 * Group 0 is the static base table at 0x020A7AE8 -- a { void *list; int
 * listNum; } pair whose strings name it "_BaseTable" (the assert text at
 * 0x020A7B08 reads "_BaseTable.listNum > co...", 0x020A7AF8 is
 * "net_command.c", and the line number is 0x10D).  listNum is SIGNED: the
 * guard is `bgt`, not `bhi`.
 *
 * Any other group scans the four 0x10-byte records behind the pointer at
 * 0x021469D8, the _pCommandWork context src/matched/func_0203A494.c
 * allocates; the second assert string at 0x020A7B20 names those records
 * "_pCommandWork->aNetHugeRecv[index].used".
 *
 * TWO POOL WORDS FOR ONE ADDRESS.  The original spends two separate pool
 * entries on 0x020A7AE8 (at +0x78 and +0x88).  It is one object reached by
 * two declarations: the `.listNum` guard reads the struct, while the
 * returned pointer is the list base spelled as an array.  Collapsing them
 * into a single `&g_020A7AE8` makes the file 140 bytes, four short.
 *
 * DECLARATION ORDER.  `int i` must be declared BEFORE the two masks, and
 * the index must be `int`, not `u32`.  With the masks first the 3-register
 * rotation r2 -> ip -> r3 -> r2 appears and nothing else moves it (found by
 * tools/permuter.py: decl-order(lo<->i) ; decl-order(hi<->i)).
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203A67C.c \
 *       --func func_0203A67C --addr 0x0203A67C --cc 1.1p1 --arm
 */

typedef unsigned int u32;

struct BaseTable {
    void *list;
    int   listNum;
};

struct HugeRecv {
    u32 a;
    int count;
    u32 c;
    u32 key;
};

extern struct BaseTable g_020A7AE8;
extern void  *g_020A7AE8_arr[];
extern char   g_020A7AF8[];
extern char   g_020A7B08[];
extern struct HugeRecv *g_021469D8;
extern void func_02034714(char *file, int line, char *msg);

struct BaseTable *func_0203A67C(u32 cmd)
{
    int i;
    u32 hi = cmd & 0xff00;
    int lo = (int)(cmd & 0xff);

    if (hi == 0) {
        if (g_020A7AE8.listNum <= lo)
            func_02034714(g_020A7AF8, 0x10D, g_020A7B08);
        return (struct BaseTable *)g_020A7AE8_arr;
    }
    for (i = 0; i < 4; i++) {
        struct HugeRecv *r = g_021469D8 + i;
        if (hi == r->key) {
            if (r->count <= lo)
                return 0;
            return (struct BaseTable *)r;
        }
    }
    return 0;
}
