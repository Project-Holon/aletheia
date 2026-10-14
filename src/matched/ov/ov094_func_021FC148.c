/*
 * function: BTLV_EFFVM_CmdLoadClactFromPoke
 * address:  0x021FC148
 * packet:   pkt_ov094_021FC148
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   VM_GetU32  0x0201134C  thumb
 *   PALANM_GetPairedCodeForFirst  0x0202142C  thumb
 *   func_0206DF3C  0x0206DF3C  arm
 *   BTLV_EFFECT_GetMcss  0x021F8694  thumb  ov094
 *   BTLV_EFFECT_GetClact  0x021F86F0  thumb  ov094
 *   BTLV_EFFVM_ResolveSlotKey  0x021FCF2C  thumb  ov094
 *   BTLV_MCSS_GetSlotPosition  0x021FF3F4  thumb  ov094
 *   BTLV_CLACT_LoadActor  0x02201B20  thumb  ov094
 */
typedef unsigned short u16;
typedef short s16;

typedef struct {
    char pad[0xcc];
    int t[92];
    int f23c;
    char pad2[0x254 - 0x240];
    u16 f254;
} State;

typedef struct {
    int x;
    int y;
    int z;
} Pt;

struct Cursor;
extern unsigned int VM_GetU32(struct Cursor *p);
extern unsigned short PALANM_GetPairedCodeForFirst(int a0);
extern void func_0206DF3C(Pt *p, int *a, int *b);
extern int BTLV_EFFECT_GetMcss(void);
extern int BTLV_EFFECT_GetClact(void);
extern int BTLV_EFFVM_ResolveSlotKey(int a, int idx);
extern void BTLV_MCSS_GetSlotPosition(void *obj, void *out, int idx);
typedef unsigned int   u32;
extern int BTLV_CLACT_LoadActor(char *p, u32 archiveId, int a, u32 b, int c, int d, s16 x, s16 y, u32 e, u32 f);

int BTLV_EFFVM_CmdLoadClactFromPoke(struct Cursor *a, State *s)
{
    int idx = VM_GetU32(a);
    int q = BTLV_EFFVM_ResolveSlotKey((int)a, VM_GetU32(a));
    int dx = VM_GetU32(a);
    int dy = VM_GetU32(a);
    int p5 = VM_GetU32(a);
    int p6 = VM_GetU32(a);
    Pt pt;
    int o1;
    int o2;
    int m;

    BTLV_MCSS_GetSlotPosition((void *)BTLV_EFFECT_GetMcss(), &pt, q);
    pt.x += dx;
    pt.y += dy;
    func_0206DF3C(&pt, &o1, &o2);
    m = PALANM_GetPairedCodeForFirst(s->f254);
    m = (m == 0 || m > 0x19) ? 4 : m;
    m = (m == 0x19) ? 0x11 : m;
    m *= 2;
    s->t[idx] = (int)BTLV_CLACT_LoadActor((char *)BTLV_EFFECT_GetClact(), 0x5f, m + 0x81, m + 0x82, 0x81, 0x82, o1, o2, p5, p6);
    return s->f23c;
}
