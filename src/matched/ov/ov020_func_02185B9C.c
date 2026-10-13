/*
 * function: EVENT_MAPCHANGE_ApplyZoneTableEntry
 * address:  0x02185B9C
 * packet:   pkt_ov020_02185B9C
 * region:   ov020
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GAME_DATA_GetFieldSave  0x02012EC4  thumb
 *   func_0200B37C  0x0200B37C  thumb
 *   func_0200B394  0x0200B394  thumb
 *   func_020490F4  0x020490F4  arm
 *   ARC_TOOL_LoadHandleMember  0x02049250  arm
 *   ARC_TOOL_GetHandleMemberSize  0x020493D4  arm
 *   func_020307B0  0x020307B0  arm
 *   ARC_TOOL_DeleteHandle  0x02049238  arm
 */

typedef unsigned short u16;

typedef struct { int id; u16 v; u16 pad; } Ent;

typedef signed int     s32;
typedef unsigned char  u8;
struct Big;
struct Rec94;
struct Struct_0200B37C;
u8 *GAME_DATA_GetFieldSave(struct Big *p);
void func_0200B37C(struct Struct_0200B37C *p);
s32 *func_0200B394(struct Rec94 *p, s32 value);
void *func_020490F4(unsigned int id, unsigned int heap);
typedef unsigned int   u32;
struct ArcFile;
void *ARC_TOOL_LoadHandleMember(struct ArcFile *arc, u32 member, u32 heap);
u32 ARC_TOOL_GetHandleMemberSize(struct ArcFile *arc, u32 member);
u32 func_020307B0(void *p);
void ARC_TOOL_DeleteHandle(void *h);

void EVENT_MAPCHANGE_ApplyZoneTableEntry(int a0, int id)
{
    unsigned n, i;
    int r0 = (int)GAME_DATA_GetFieldSave((struct Big *)a0);
    void *h;
    int c = 0x8001;
    Ent *e;

    func_0200B37C((struct Struct_0200B37C *)r0);
    h = func_020490F4(0x65, c);
    e = ARC_TOOL_LoadHandleMember(h, 0, c);
    n = ARC_TOOL_GetHandleMemberSize(h, 0) >> 3;
    for (i = 0; i < n; i++) {
        if (id == e[i].id) {
            func_0200B394((struct Rec94 *)r0, e[i].v);
            break;
        }
    }
    func_020307B0(e);
    ARC_TOOL_DeleteHandle(h);
}
