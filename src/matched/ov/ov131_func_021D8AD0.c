/*
 * function: func_021D8AD0
 * address: 0x021D8AD0
 * packet: pkt_ov131_021D8AD0
 * region: ov131
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: Narrow deltas are assigned to u8/s16 locals before forwarding;
 *   inline casts copy into the argument register before truncating.
 * proof: Position is initialized to -16 before the search, as 021D8B4C.
 *   Loop i is u8 bounded by 10. Navigation index keeps the original u8
 *   wrapping and single subtraction, without assuming a 0..9 input.
 *   Its 20-byte scaling is <=5100 and signed arithmetic fits int.
 *   021D9440 returns s16, so subtracting 128 or 8 fits int; outgoing
 *   deltas preserve the original u8 and s16 narrowing respectively.
 * symbols:
 *   func_020362DC 0x020362DC arm
 *   func_0203633C 0x0203633C arm
 *   func_0204B878 0x0204B878 arm
 *   func_0204B3DC 0x0204B3DC arm
 *   func_020061E4 0x020061E4 thumb
 *   func_021D5A9C 0x021D5A9C thumb ov131
 *   func_021D964C 0x021D964C thumb ov131
 *   func_021D9670 0x021D9670 thumb ov131
 *   func_021D9440 0x021D9440 thumb ov131
 *   func_021D8EA8 0x021D8EA8 thumb ov131
 *   func_021D949C 0x021D949C thumb ov131
 *   func_021D8F0C 0x021D8F0C thumb ov131
 *   func_021D8ED0 0x021D8ED0 thumb ov131
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
extern u32 func_020362DC(void);
extern unsigned int func_0203633C(void);
extern void func_0204B878(void *,u16);
extern void func_0204B3DC(void *,int);
extern void func_020061E4(int);
extern void func_021D5A9C(u8 *,int);
extern void func_021D964C(u8 *,u8 *);
extern void func_021D9670(u8 *,u8 *);
extern s16 func_021D9440(u8 *,u32);
extern void func_021D8EA8(u8 *,u8 *);
extern void func_021D949C(u8 *,u8 *);
extern void func_021D8F0C(void *,u8 *,int);
extern void func_021D8ED0(u8 *,u8 *,u32);
int func_021D8AD0(u8 *a,u8 *p)
{
    u8 i,index,narrowDelta;
    s16 shortDelta;
    int position;
    if(func_020362DC()==2) {
        func_021D5A9C(a,1);
        func_0204B878(*(void **)(a+0x194),9);
        func_0204B3DC(*(void **)(p+0x54),0);
        p[0x58]=255;
        p[0x59]=255;
        *(u32 *)(p+0x68)=1;
        func_021D964C(a,p);
        func_021D9670(a,p);
        a[0x1c]=0;
        func_020061E4(1361);
        return 1;
    }
    if(a[0x1c]==1) {
        if(func_020362DC()==1 || func_020362DC()==128 || func_020362DC()==64) {
            position=-16;
            *(int *)(p+0x5c)=0;
            *(int *)(p+0x64)=0;
            for(i=0;i<10;i++) {
                if(p[0x59]==*(u16 *)(p+0x70+i*20)) position=func_021D9440(p,i);
            }
            if(position < -4 || position >144) func_021D8EA8(a,p);
            func_021D964C(a,p);
            func_021D949C(a,p);
            func_020061E4(1352);
            a[0x1c]=0;
            return 1;
        }
    } else if(func_0203633C()==128) {
        index=p[0x58]+1;
        if(index>=10) index-=10;
        if(*(u16 *)(p+0x70+index*20)!=0xffff) {
            p[0x58]=index;
            *(u32 *)(p+0x68)=1;
            if(func_021D9440(p,p[0x58])>128) {
                narrowDelta=func_021D9440(p,p[0x58])-128;
                func_021D8F0C(a,p,narrowDelta);
            }
            func_021D8ED0(a,p,p[0x58]);
            func_021D964C(a,p);
            func_021D949C(a,p);
            func_020061E4(1352);
        }
        return 1;
    } else if(func_0203633C()==64) {
        index=p[0x58];
        if(index==0) index=9;
        else index-=1;
        if(*(u16 *)(p+0x70+index*20)!=0xffff) {
            p[0x58]=index;
            *(u32 *)(p+0x68)=1;
            if(func_021D9440(p,p[0x58])<8) {
                shortDelta=func_021D9440(p,p[0x58])-8;
                func_021D8F0C(a,p,shortDelta);
            }
            func_021D8ED0(a,p,p[0x58]);
            func_021D964C(a,p);
            func_021D949C(a,p);
            func_020061E4(1352);
        }
        return 1;
    }
    return 0;
}
