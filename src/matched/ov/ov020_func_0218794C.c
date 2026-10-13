/*
 * function: EL_SCOREBOARD_LoadSeasonGraphics
 * address:  0x0218794C
 * packet:   pkt_ov020_0218794C
 * region:   ov020
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_020490F4  0x020490F4  arm
 *   ARC_TOOL_LoadHandleMember  0x02049250  arm
 *   func_02062A98  0x02062A98  arm
 *   func_02040E78  0x02040E78  arm
 *   func_020307B0  0x020307B0  arm
 *   func_02062A4C  0x02062A4C  arm
 *   func_02040B1C  0x02040B1C  arm
 *   func_02062B30  0x02062B30  arm
 *   func_020409E0  0x020409E0  arm
 *   ARC_TOOL_DeleteHandle  0x02049238  arm
 */

void *func_020490F4(unsigned int id, unsigned int heap);
typedef unsigned int   u32;
struct ArcFile;
void *ARC_TOOL_LoadHandleMember(struct ArcFile *arc, u32 member, u32 heap);
typedef signed int     s32;
struct NitroFileHeader;
s32 func_02062A98(struct NitroFileHeader *file, void **out);
void func_02040E78(u32 r7, void *r6, u32 r5, u32 r4);
u32 func_020307B0(void *p);
s32 func_02062A4C(struct NitroFileHeader *file, void **out);
void func_02040B1C(int index, const void *src, u32 size, u32 tile);
int func_02062B30(void *file, void **out);
void func_020409E0(u32 index, const void *src, u32 mode, u32 offset);
void ARC_TOOL_DeleteHandle(void *x);

void EL_SCOREBOARD_LoadSeasonGraphics(int sel, int b)
{
    int *l_c;
    int *l_8;
    int *l_4;
    void *x;
    void *v;
    int i0, i1, i2;

    switch (sel) {
    default:
    case 0:
        i0 = 0; i1 = 1; i2 = 2;
        break;
    case 1:
        i0 = 3; i1 = 4; i2 = 5;
        break;
    case 2:
        i0 = 6; i1 = 7; i2 = 8;
        break;
    case 3:
        i0 = 9; i1 = 10; i2 = 11;
        break;
    }
    x = func_020490F4(0x97, b);
    v = ARC_TOOL_LoadHandleMember(x, i0, b);
    func_02062A98(v, (void **)(&l_c));
    func_02040E78(3, (void *)l_c[3], 0x20, 0);
    func_020307B0(v);
    v = ARC_TOOL_LoadHandleMember(x, i1, b);
    func_02062A4C(v, (void **)(&l_8));
    func_02040B1C(3, (const void *)l_8[5], l_8[4], 0);
    func_020307B0(v);
    v = ARC_TOOL_LoadHandleMember(x, i2, b);
    func_02062B30(v, (void **)(&l_4));
    func_020409E0(3, l_4 + 3, l_4[2], 0);
    func_020307B0(v);
    ARC_TOOL_DeleteHandle(x);
}
