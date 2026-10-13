/*
 * function: MAP_MATRIX_Load
 * address:  0x02159B94
 * packet:   pkt_02159B94
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   ARC_TOOL_LoadMember  0x02048F60  arm
 *   MAP_MATRIX_SetupFromFile  0x02159D04  thumb  ov010
 *   func_020307B0  0x020307B0  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void *ARC_TOOL_LoadMember(u32 archive_id, u32 member, u32 heap);
extern int MAP_MATRIX_SetupFromFile();
extern u32 func_020307B0(void *p);

int MAP_MATRIX_Load(int a0, int a1, int a2, int a3)
{
    int t5;
    int t6;
    int t7;
    void *t4;

t5 = a0 + 0;
t7 = a2 + 0;
a0 = 9;
a2 = a3 + 0;
t6 = a1 + 0;
    t4 = ARC_TOOL_LoadMember(a0, a1, a2);
loc_02159BA4:
a0 = t5 + 0;
a2 = t6 + 0;
a3 = t7 + 0;
    a0 = MAP_MATRIX_SetupFromFile(a0, t4, a2, a3);
loc_02159BB2:
    a0 = func_020307B0(t4);
loc_02159BB8:
    return a0;}
