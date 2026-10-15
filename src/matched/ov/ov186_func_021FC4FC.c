/*
 * function: BR_GRAPHIC_InitBgWindows
 * address: 0x021FC4FC
 * packet: pkt_ov186_021FC4FC
 * region: ov186
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   MI_CpuFill8 0x02082BCC arm
 *   BG_SYS_Create 0x0203F8F4 arm
 *   BMP_WIN_Init 0x02045088 arm
 *   func_0203FC28 0x0203FC28 arm
 *   BG_SYS_InitBgLayer 0x0203FCA0 arm
 *   func_020414AC 0x020414AC arm
 *   func_02040588 0x02040588 arm
 *   d_02200900 0x02200900 data a4
 *   d_0220099C 0x0220099C data a4
 */
typedef struct BgTemplate { unsigned words[8]; } BgTemplate;
typedef struct Record {unsigned id;BgTemplate template;unsigned type,enable;} Record;
typedef struct DispConfig {unsigned words[4];} DispConfig;
extern const Record d_0220099C[];
extern DispConfig d_02200900;
extern void MI_CpuFill8(void *,int,int);
extern void BG_SYS_Create(unsigned);
extern void BMP_WIN_Init(unsigned);
extern void func_0203FC28(DispConfig *);
typedef unsigned int   u32;
extern void BG_SYS_InitBgLayer(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void func_020414AC(unsigned char);
extern void func_02040588(unsigned char,unsigned char);
void BR_GRAPHIC_InitBgWindows(void *p,unsigned heap)
{
    unsigned i;
    const Record *r;
    unsigned id;
    MI_CpuFill8(p,0,4);
    BG_SYS_Create(heap);
    BMP_WIN_Init(heap);
    func_0203FC28(&d_02200900);
    for(i=0;i<7;i++){
        r=&d_0220099C[i];id=r->id;
        BG_SYS_InitBgLayer((unsigned char)id,&r->template,(unsigned char)r->type);
        func_020414AC(id);
        func_02040588(id,r->enable);
    }
}
