/*
 * function: func_021F4C0C
 * address: 0x021F4C0C
 * packet: pkt_ov194_021F4C0C
 * region: ov194
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * Match lever: bind the entry id before binding its element pointer.
 * symbols:
 *   MI_CpuFill8 0x02082BCC arm
 *   BG_SYS_Create 0x0203F8F4 arm
 *   BMP_WIN_Init 0x02045088 arm
 *   func_0203FC28 0x0203FC28 arm
 *   BG_SYS_InitBgLayer 0x0203FCA0 arm
 *   func_020414AC 0x020414AC arm
 *   sub_02040588 0x02040588 arm
 *   d_021F55A4 0x021F55A4 data a4
 *   d_021F5600 0x021F5600 data a4
 */
typedef struct { unsigned words[4]; } Disp;
typedef struct { unsigned words[8]; } Bg;
typedef struct { unsigned id; Bg config; unsigned type, enabled; } Entry;
extern const Disp d_021F55A4;
extern const Entry d_021F5600[];
extern void MI_CpuFill8(void *, unsigned, unsigned);
extern void BG_SYS_Create(unsigned short);
extern void BMP_WIN_Init(unsigned short);
typedef unsigned int   u32;
struct DispConfig;
extern void func_0203FC28(struct DispConfig *cfg);
extern void BG_SYS_InitBgLayer(unsigned char, const Bg *, unsigned char);
extern void func_020414AC(unsigned char);
extern void sub_02040588(unsigned char which, unsigned char enable);
void func_021F4C0C(void *p, unsigned short heap)
{
    unsigned i = 0;
    unsigned id;
    const Entry *e;
    MI_CpuFill8(p, 0, 4);
    BG_SYS_Create(heap);
    BMP_WIN_Init(heap);
    func_0203FC28((struct DispConfig *)(&d_021F55A4));
    for (; i < 8; i++) {
        id = d_021F5600[i].id;
        e = &d_021F5600[i];
        BG_SYS_InitBgLayer(id, &e->config, e->type);
        func_020414AC(id);
        sub_02040588((unsigned char)id, (unsigned char)e->enabled);
    }
}
