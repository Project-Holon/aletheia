/*
 * function: MAP_REPLACE_Create
 * address:  0x02159D84
 * packet:   pkt_ov010_02159D84
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02030734  0x02030734  arm
 *   func_020490F4  0x020490F4  arm
 *   ARC_TOOL_GetHandleMemberSize  0x020493D4  arm
 *   MAP_REPLACE_SetupFlags  0x02159E8C  thumb  ov010
 *   d_021728BC  0x021728BC  data
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Obj {
    u16 f00;
    u16 pad02;
    void *f04;
    u32 f08;
    u8 f0c[1];
} Obj;

struct ArcFile;
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void *func_020490F4(unsigned int id, unsigned int heap);
extern u32 ARC_TOOL_GetHandleMemberSize(struct ArcFile *arc, u32 member);
extern void MAP_REPLACE_SetupFlags(u8 *out, int obj);
extern const char d_021728BC[];

Obj *MAP_REPLACE_Create(int a, int b)
{
    Obj *p = func_02030734(a, 0x2c, 1, d_021728BC, 0x77);
    p->f00 = a;
    p->f04 = func_020490F4(10, a);
    p->f08 = ((u32)ARC_TOOL_GetHandleMemberSize(p->f04, 0) << 16) >> 20;
    MAP_REPLACE_SetupFlags(p->f0c, b);
    return p;
}
