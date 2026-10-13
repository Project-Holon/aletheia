/*
 * function: BSUBWAY_RECORD_LIST_SetupBgLayers
 * address:  0x021B97F4
 * packet:   pkt_ov069_021B97F4
 * region:   ov069
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0203F8F4  0x0203F8F4  arm
 *   func_0203FC28  0x0203FC28  arm
 *   func_0203FCA0  0x0203FCA0  arm
 *   func_020414EC  0x020414EC  arm
 *   func_02040B94  0x02040B94  arm
 *   func_02040588  0x02040588  arm
 *   sRecordListDispConfig  0x021BA65C  data  a4
 *   sRecordListBgTemplates  0x021BA7A0  data  a4
 *   sRecordListBgIds  0x021BA60C  data  a4
 */

typedef unsigned char u8;
typedef unsigned int u32;

typedef struct A16 {
    u32 w[4];
} A16;

typedef struct B160 {
    u32 w[40];
} B160;

extern A16 sRecordListDispConfig;
extern B160 sRecordListBgTemplates;
extern u32 sRecordListBgIds[];

typedef unsigned short u16;
extern void func_0203F8F4(u16 heapId);
struct BgTemplate;
struct DispConfig;
extern void func_0203FC28(struct DispConfig *cfg);
extern void func_0203FCA0(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void func_020414EC(u8);
extern void func_02040B94(u8 layer, u32 size, u32 offset, u32 heapId);
extern void func_02040588(unsigned char which, unsigned char enable);

void BSUBWAY_RECORD_LIST_SetupBgLayers(void)
{
    A16 a;
    B160 b;
    u32 i;
    u32 id;

    func_0203F8F4(0x80);
    a = sRecordListDispConfig;
    func_0203FC28((struct DispConfig *)(&a));
    b = sRecordListBgTemplates;
    for (i = 0; i < 5; i++) {
        id = sRecordListBgIds[i];
        func_0203FCA0((u8)id, (const struct BgTemplate *)(&b.w[i * 8]), (int)0);
        func_020414EC(id);
        func_02040B94(id, 0x20, 0, 0x80);
        func_02040588(id, 1);
    }
    func_02040588(6, 0);
    func_02040588(7, 0);
    func_02040588(3, 0);
}
