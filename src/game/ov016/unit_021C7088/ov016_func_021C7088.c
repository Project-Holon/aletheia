/*
 * function: DWCi_SceneSetEditAddress
 * address:  0x021C7088
 * packet:   pkt_ov016_021C7088
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_SceneSetEditAddress (libdwcutil.TWL.HYB.a sceneseteditaddr)
 * symbols:
 *   DWCi_HEAPlAllocEx                0x021D6414  arm
 *   DWCi_GetParam2_                  0x021C0EA0  arm
 *   memcmp                           0x020923F0  arm
 *   MI_CpuFill8                      0x02082BCC  arm
 *   initGraphics                     0x021C71F0  arm   ov016
 *   DWCi_HLlLoad                     0x021BD674  arm
 *   DWCi_COMMENTlDispEx              0x021BD060  arm
 *   DWCi_CMNlStep                    0x021BD214  arm
 *   DWCi_FNTlFormBgEx                0x021D5A58  arm
 *   DWCi_CEINlSetExObj               0x021D5368  arm
 *   dispCaret                        0x021C7960  arm   ov016
 *   drawAddress                      0x021C78A0  arm   ov016
 *   DWCi_ChangeScene                 0x021C0E40  arm
 *   g_021DB4C8                       0x021DB4C8  data
 *   g_021DA5E0                       0x021DA5E0  data
 *   g_021DE5E4                       0x021DE5E4  data
 *   g_021DB4F0                       0x021DB4F0  data
 *   procInit                         0x021C72AC  arm   ov016
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;

struct MEMSSEA {
    void *font;
    u16 *oam;
    char text[12];
    u8 state;
};
struct FuncTab {
    void (*f[5])(char *);
};
struct MsgTab {
    u8 m[5];
};

extern const struct FuncTab g_021DB4C8;
extern const struct MsgTab g_021DA5E0;
extern struct MEMSSEA *g_021DE5E4;
extern char g_021DB4F0[];

extern void *DWCi_HEAPlAllocEx(u32 size, int alignment);
extern void DWCi_GetParam2_(void **param2, void **param3);
extern int memcmp(const void *a, const void *b, u32 n);
extern void MI_CpuFill8(void *dstp, u8 data, u32 size);
extern void DWCi_HLlLoad(int idx);
extern int DWCi_COMMENTlDispEx(int messageId, int n, int num);
extern void DWCi_CMNlStep(int step);
extern void *DWCi_FNTlFormBgEx(int lcd, int font);
extern u16 *DWCi_CEINlSetExObj(int lcd, int idx);
extern void DWCi_ChangeScene(void (*scene)());

static void initGraphics(void);
static void dispCaret(void);
static void drawAddress(void);
static void procInit(void);

void DWCi_SceneSetEditAddress(void)
{
    struct FuncTab FUNC = g_021DB4C8;
    struct MsgTab MSG = g_021DA5E0;
    int prm;
    struct MEMSSEA *p;

    g_021DE5E4 = DWCi_HEAPlAllocEx(0x18, 4);
    DWCi_GetParam2_((void **)&prm, 0);
    FUNC.f[prm](g_021DE5E4->text);
    p = g_021DE5E4;
    if (memcmp(p->text, g_021DB4F0, 3) != 0) {
        p->state = 3;
    } else {
        MI_CpuFill8(p->text, 0, 12);
        g_021DE5E4->state = 0;
    }
    initGraphics();
    DWCi_HLlLoad(prm + 0xb);
    DWCi_COMMENTlDispEx(MSG.m[prm], -1, 0);
    DWCi_CMNlStep(2);
    g_021DE5E4->font = DWCi_FNTlFormBgEx(0, 0);
    g_021DE5E4->oam = DWCi_CEINlSetExObj(0, 0x3f);
    g_021DE5E4->oam[2] = (g_021DE5E4->oam[2] & ~0xc00) | 0xc00;
    dispCaret();
    drawAddress();
    DWCi_ChangeScene(procInit);
}
