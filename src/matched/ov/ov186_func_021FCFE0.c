/*
 * function: func_021FCFE0,func_021FD094,func_021FD0A8
 * address: 0x021FCFE0
 * packet: pkt_ov186_021FCFE0
 * region: ov186
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * unit: yes
 * status: EXACT
 * followers: unlabelled store-free accessors 021FD094 and 021FD0A8 included; final 2-byte alignment outside TU length.
 * symbols:
 *   func_021FD860 0x021FD860 thumb ov186
 *   d_02200B0C 0x02200B0C data a4
 */
typedef unsigned short u16;
typedef unsigned int u32;
struct Pair { int x,y; };
extern const struct Pair d_02200B0C[];
extern void func_021FD860(int,int,const struct Pair *);
int func_021FCFE0(char *p,int step)
{
    int count,changed,half;
    count=*(u16 *)(p+0x44);
    changed=0;
    half=(count-1)/2+(count-1)%2;
    if(step>0) {
        if(half==*(u16 *)(p+0x40) && (u32)(*(u16 *)(p+0x42)+count)<*(u32 *)(p+4)) {
            *(u16 *)(p+0x42)+=(u16)step;changed=1;
        } else if((u32)(*(u16 *)(p+0x42)+*(u16 *)(p+0x40))<*(u32 *)(p+4)-1) {
            *(u16 *)(p+0x40)+=(u16)step;changed=1;
        }
    } else if(step<0) {
        if(half==*(u16 *)(p+0x40) && *(u16 *)(p+0x42)) {
            *(u16 *)(p+0x42)+=(u16)step;changed=1;
        } else if(*(u16 *)(p+0x40)) {
            *(u16 *)(p+0x40)+=(u16)step;changed=1;
        }
    }
    if(changed && *(int *)(p+0x1c)) func_021FD860(*(int *)(p+0x1c),5,&d_02200B0C[*(u16 *)(p+0x40)]);
    return changed;
}
int func_021FD094(char *p) { return *(u32 *)(p+4)>=*(u16 *)(p+0x44); }
int func_021FD0A8(char *p) { return *(u32 *)(p+4)>1; }
