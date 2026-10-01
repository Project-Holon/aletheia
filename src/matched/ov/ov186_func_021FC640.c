/*
 * function: func_021FC640
 * address: 0x021FC640
 * packet: pkt_ov186_021FC640
 * region: ov186
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * volatile: hardware BLDCNT 04000050 and DISPCNT 04000000, read-modify-write at 021FC64A..021FC650.
 * symbols:
 *   func_0207D4B0 0x0207D4B0 arm
 *   func_0203FCA0 0x0203FCA0 arm
 *   func_020414AC 0x020414AC arm
 *   func_02040588 0x02040588 arm
 *   d_0220099C 0x0220099C data a4
 */
typedef struct BgTemplate {unsigned words[8];} BgTemplate;
typedef struct Record {unsigned id;BgTemplate template;unsigned type,enable;} Record;
extern const Record d_0220099C[];
extern void func_0207D4B0(unsigned,unsigned,unsigned);
extern void func_0203FCA0(unsigned char,const BgTemplate *,unsigned char);
extern void func_020414AC(unsigned char);
extern void func_02040588(unsigned char,unsigned char);
void func_021FC640(void)
{
    unsigned i,id;
    const Record *r;
    *(volatile unsigned short *)0x04000050=0;
    *(volatile unsigned *)0x04000000&=~0xe000;
    func_0207D4B0(1,0,0);
    for(i=0;i<7;i++){
        r=&d_0220099C[i];id=r->id;
        if(id<4){func_0203FCA0(id,&r->template,r->type);func_020414AC(id);}
        func_02040588(id,r->enable);
    }
}
