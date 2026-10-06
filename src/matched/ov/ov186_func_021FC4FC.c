/*
 * function: func_021FC4FC
 * address: 0x021FC4FC
 * packet: pkt_ov186_021FC4FC
 * region: ov186
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02082BCC 0x02082BCC arm
 *   func_0203F8F4 0x0203F8F4 arm
 *   func_02045088 0x02045088 arm
 *   func_0203FC28 0x0203FC28 arm
 *   func_0203FCA0 0x0203FCA0 arm
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
extern void func_02082BCC(void *,int,int);
extern void func_0203F8F4(unsigned);
extern void func_02045088(unsigned);
extern void func_0203FC28(DispConfig *);
typedef unsigned int   u32;
extern void func_0203FCA0(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void func_020414AC(unsigned char);
extern void func_02040588(unsigned char,unsigned char);
void func_021FC4FC(void *p,unsigned heap)
{
    unsigned i;
    const Record *r;
    unsigned id;
    func_02082BCC(p,0,4);
    func_0203F8F4(heap);
    func_02045088(heap);
    func_0203FC28(&d_02200900);
    for(i=0;i<7;i++){
        r=&d_0220099C[i];id=r->id;
        func_0203FCA0((unsigned char)id,&r->template,(unsigned char)r->type);
        func_020414AC(id);
        func_02040588(id,r->enable);
    }
}
