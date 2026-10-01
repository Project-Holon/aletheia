/*
 * function: func_021FCE60
 * address: 0x021FCE60
 * packet: pkt_ov186_021FCE60
 * region: ov186
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: bitmap array field retains per-access base additions.
 * symbols:
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_021FCF54 0x021FCF54 thumb ov186
 *   func_02045334 0x02045334 arm
 */
typedef struct { char pad[0x8C];int bitmap[1]; } View;
extern int func_02045770(int);
extern void func_02043B5C(int,int),func_02045334(int);
extern void func_021FCF54(int,int,int,int,unsigned short,unsigned short,unsigned short,unsigned short);
void func_021FCE60(char *p,int start)
{
    int i,height;
    func_02043B5C(func_02045770(*(int *)(p+0x38)),0);
    for(i=start;i<start+*(unsigned short *)(p+0x44);i++) {
        if((unsigned)i<*(unsigned *)(p+4) && ((View *)p)->bitmap[i]) {
            height=*(unsigned char *)(p+0xE);
            func_021FCF54(((View *)p)->bitmap[i],func_02045770(*(int *)(p+0x38)),0,0,0,(i-start)*height,*(unsigned char *)(p+0xA),height);
        }
    }
    func_02045334(*(int *)(p+0x38));
}
