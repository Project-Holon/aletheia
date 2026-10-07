/*
 * file:     game_beacon_search_p04.c
 * unit:     yes
 * function: func_02165078, func_02165094
 * address:  0x02165078
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0202708C  0x0202708C  thumb
 *   func_0216513C  0x0216513C  thumb  ov010
 *   func_021650CC  0x021650CC  thumb  ov010
 *   func_02027060   0x02027060  thumb
 *   func_02026FB8   0x02026FB8  thumb
 *   g_02146940      0x02146940  data
 *   func_021650BC   0x021650BC  thumb  ov010
 */
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

extern int func_0202708C();
extern int func_0216513C();
extern int func_021650CC();
extern u32 func_02027060(u32 a);
extern void func_02026FB8(void *);
extern void func_021650BC(void *a0, unsigned a1);
int func_02165078(int a0);
void func_02165094(void *a0);
extern char *g_02146940;


int func_02165078(int a0)
{
    int t4;

t4 = a0 + 0;
    a0 = func_0202708C(a0);
loc_02165080:
    if (a0 == 0) goto loc_0216508C;
loc_02165084:
a0 = t4 + 0;
    a0 = func_0216513C(a0);
loc_0216508A:
    return a0;
loc_0216508C:
a0 = t4 + 0;
    a0 = func_021650CC(a0);
loc_02165092:
    return a0;}


/*
 * Test the id against the overlay's table and, when it takes,
 * re-submit the record at the shared globals pointer.
 */
void func_02165094(void *a0)
{
    if (func_02027060(0x2)) {
        func_021650BC(g_02146940 + 4, (unsigned int)a0);
        func_02026FB8(g_02146940 + 4);
    }
}
