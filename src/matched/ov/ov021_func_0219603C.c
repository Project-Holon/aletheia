/*
 * function: IRCBATTLEMENU_InitBgLayers
 * address:  0x0219603C
 * packet:   pkt_ov021_0219603C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0203FCA0  0x0203FCA0  arm
 *   func_020414AC  0x020414AC  arm
 *   func_020409B4  0x020409B4  arm
 *   func_02040588  0x02040588  arm
 *   func_02040C14  0x02040C14  arm
 *   func_02041300  0x02041300  arm
 *   sBgTemplateMain0     0x021D40A0  data  ov021  a4
 *   sBgTemplateMain1     0x021D40C0  data  ov021  a4
 *   sBgTemplateSub0     0x021D40E0  data  ov021  a4
 *   sBgTemplateSub1     0x021D4100  data  ov021  a4
 *   sBgTemplateSub2     0x021D4120  data  ov021  a4
 *   sBgTemplateSub3     0x021D4140  data  ov021  a4
 */

typedef struct { int w[8]; } B32;

extern const B32 sBgTemplateMain0;
extern const B32 sBgTemplateMain1;
extern const B32 sBgTemplateSub0;
extern const B32 sBgTemplateSub1;
extern const B32 sBgTemplateSub2;
extern const B32 sBgTemplateSub3;
struct BgTemplate;
extern void func_0203FCA0(unsigned int bgId, const struct BgTemplate *tmpl, unsigned int type);
extern void func_020414AC(int);
typedef unsigned int   u32;
extern void func_020409B4(u32 index);
extern void func_02040588(unsigned char which, unsigned char enable);
extern void func_02040C14(u32 layer, u32 value, u32 count, u32 index);
extern void func_02041300(int, int, int, int, int, int, int);

void IRCBATTLEMENU_InitBgLayers(void *a0)
{
    B32 t0;
    B32 t1;
    B32 t4;
    B32 t5;
    B32 t6;
    B32 t7;

    t0 = sBgTemplateMain0;
    func_0203FCA0(0, (const struct BgTemplate *)(&t0), 0);
    func_020414AC(0);
    func_020409B4(0);
    func_02040588(0, 1);

    t1 = sBgTemplateMain1;
    func_0203FCA0(1, (const struct BgTemplate *)(&t1), 0);
    func_020414AC(1);
    func_020409B4(1);
    func_02040588(1, 1);

    t4 = sBgTemplateSub0;
    func_0203FCA0(4, (const struct BgTemplate *)(&t4), 0);
    func_02040588(4, 1);
    func_020409B4(4);

    t5 = sBgTemplateSub1;
    func_0203FCA0(5, (const struct BgTemplate *)(&t5), 0);
    func_02040588(5, 1);
    func_02040C14(5, 0, 1, 0);
    func_02041300(5, 0, 0, 0, 0x20, 0x20, 0x11);
    func_020409B4(5);

    t6 = sBgTemplateSub2;
    func_0203FCA0(6, (const struct BgTemplate *)(&t6), 0);
    func_02040588(6, 1);
    func_020409B4(6);

    t7 = sBgTemplateSub3;
    func_0203FCA0(7, (const struct BgTemplate *)(&t7), 0);
    func_02040588(7, 1);
    func_020409B4(7);
}
