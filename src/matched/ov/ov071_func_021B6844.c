/*
 * function: MONOLITH_TOOL_InitActors
 * address:  0x021B6844
 * packet:   pkt_ov071_021B6844
 * region:   ov071
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   gClActorInitParam     0x020A1448  data  a4
 *   d_021BA7D4     0x021BA7D4  data  a4
 *   CLACT_InitSystem  0x0204A48C  arm
 *   CLACT_CreateUnit  0x0204B100  arm
 *   CLACT_SetUnitDefaultRenderer  0x0204B270  arm
 *   ACTOR_TOOL_Create  0x02025318  thumb
 *   BMP_OAM_CreateSys  0x02025538  thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;

struct S6844 {
    int w0, w4;
    u8 b8, b9, ba, bb;
    int wc;
    u16 h10, h12, h14, h16;
    int w18;
};

extern struct S6844 gClActorInitParam;
extern char d_021BA7D4;

struct W6844 {
    int w0;
    u8 *unk_04;
    int pad_08[3];
    void *unk_14;
    int pad_18[5];
    void *unk_2c;
};

typedef unsigned int   u32;
struct Bank;
struct Cfg;
void MONOLITH_TOOL_InitActors(struct W6844 *p)
{
    struct S6844 s;
    void CLACT_InitSystem(const struct Cfg *cfg, u32 arg, u32 heapId);
    struct Bank *CLACT_CreateUnit(int count, u8 flag, u32 heapId);
    void CLACT_SetUnitDefaultRenderer(struct Bank *bank);
    u8 *ACTOR_TOOL_Create(u32 a0, u8 a1, u8 a2);
    void *BMP_OAM_CreateSys(unsigned int a0, void *a1);

    s = gClActorInitParam;
    s.b8 = 4;
    s.b9 = 0x7c;
    s.ba = 4;
    s.bb = 0x7c;
    s.h10 = 0x60;
    s.h14 = 0x40;
    CLACT_InitSystem((const struct Cfg *)(&s), (u32)(&d_021BA7D4), 0x61);
    p->unk_14 = CLACT_CreateUnit(0x60, 0, 0x61);
    CLACT_SetUnitDefaultRenderer(p->unk_14);
    p->unk_04 = ACTOR_TOOL_Create(0x61, 0x10, 0x10);
    p->unk_2c = BMP_OAM_CreateSys(0x61, p->unk_14);
}
