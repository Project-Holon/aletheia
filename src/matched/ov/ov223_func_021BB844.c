/*
 * function: func_021BB844
 * address: 0x021BB844
 * packet: pkt_ov223_021BB844
 * region: ov223
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * lever: a full-word copy tmp=(u32)p+i*2; q=tmp reverses the q/next spill homes; once-only bounded search found it, fixed-one validated it.
 * volatile: original 021BB858 and 021BB862 independently reload p+0x870 in the transition helper's two arms.
 * symbols:
 *   func_021BB520 0x021BB520 thumb ov223
 *   func_02061CA4 0x02061CA4 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Colors {u16 b2,g2,r2,b1,g1,r1;};
enum Offset {OffsetZero=0};
extern void func_021BB520(int,u16 *,u16 *,u16 *);
extern int func_02061CA4(void *,u32,u32,int);
void func_021BB844(char *p)
{
    int active=0;
    enum Offset which;
    u8 i;
    u8 weight;
    struct Colors colors;
    u32 q;
    int next;
    u16 red,green,blue;
    u32 tmp;
    if(*(int *)(p+0x86c)!=1) goto done;
    {
        if(*(volatile u8 *)(p+0x870)==16) *(int *)(p+0x86c)=0;
        else {++*(volatile u8 *)(p+0x870);active=1;}
    }
    if(active) {
        which=0x870;
        i=0;
        which+=1;
        for(;i<128;i++) {
            weight=*(u8 *)(p+0x870);
            next=*(u16 *)(p+(*(u8 *)(p+which))*256+i*2+0x26a);
            tmp=(u32)p+i*2;
            q=tmp;
            func_021BB520(*(u16 *)(q+0x66a),&colors.r1,&colors.g1,&colors.b1);
            func_021BB520(next,&colors.r2,&colors.g2,&colors.b2);
            blue=(colors.b1*(16-weight)+colors.b2*weight)/16;
            red=(colors.r1*(16-weight)+colors.r2*weight)/16;
            green=(colors.g1*(16-weight)+colors.g2*weight)/16;
            *(u16 *)(q+0x76a)=red|(green<<5)|(blue<<10);
        }
        func_02061CA4((void *)31,256,(u32)(p+0x76a),256);
    }
done:;
}
