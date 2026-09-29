/*
 * function: func_021C56CC
 * address:  0x021C56CC
 * packet:   pkt_021C56CC
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_02085710  0x02085710  arm
 *   func_021C56B4  0x021C56B4  arm  ov114
 *   func_02086028  0x02086028  arm
 *   func_02086078  0x02086078  arm
 *   g_021D3B68     0x021D3B68  data ov114
 *   g_021D3B84     0x021D3B84  data ov114
 */

typedef struct Ov114Global {
    char pad[0x10];
    int  f10;
    int  f14;
    int  f18;
} Ov114Global;

extern Ov114Global g_021D3B68;
extern char        g_021D3B84;

void func_02085710(void *p);
void func_021C56B4(void *p);
void func_02086028(void *p, int a);
void func_02086078(void *p, int a);

void func_021C56CC(void)
{
    func_02085710((char *)g_021D3B68.f18 + 0x1b8 + 0x800);
    func_021C56B4((void *)g_021D3B68.f18);
    g_021D3B68.f18 = 0;
    func_02086028(&g_021D3B84, 0);
    g_021D3B68.f14 = 3;
    g_021D3B68.f10 = 4;
    func_02086078(&g_021D3B84, 4);
}
