/*
 * function: func_021FE1C4
 * address: 0x021FE1C4
 * packet: pkt_ov186_021FE1C4
 * region: ov186
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * lever: Initialize i before the second start=p+18 assignment to interleave movs with the pointer adds (four bytes out to EXACT).
 * abi: B404 third parameter is u16 because the original truncates the loaded heap word immediately before blx.
 * symbols:
 *   func_021FD940 0x021FD940 thumb ov186
 *   func_021FE2BC 0x021FE2BC thumb ov186
 *   func_021FE2F8 0x021FE2F8 thumb ov186
 *   func_0204B688 0x0204B688 arm
 *   func_0204B404 0x0204B404 arm
 *   func_021FD73C 0x021FD73C thumb ov186
 *   func_021FD964 0x021FD964 thumb ov186
 *   d_02200AD8 0x02200AD8 data a4
 */
typedef unsigned int u32;
typedef unsigned short u16;
typedef struct {int x,y;} Pair;
typedef struct {short x,y;} ShortPair;
extern const u32 d_02200AD8[];
extern void func_021FD940(char *,u16);
extern void func_021FE2BC(void *,void *,u16,u16,u16,u16,int);
extern int func_021FE2F8(char *,int *,int);
typedef unsigned char  u8;
struct Actor;
extern void func_0204B688(struct Actor *actor, u32 value);
extern void func_0204B404(void *,const ShortPair *,u16);
extern void func_021FD73C(int *,int);
extern void func_021FD964(void *unused, int *state, u8 *p);
void func_021FE1C4(int *task,int *state,char *p)
{
    Pair full;
    ShortPair pos;
    int i;
    switch(*state) {
    case 0: {
        char *start;
        int offset;
        func_021FD940(p,0);
        start=p;start=p+0x18;
        offset=0x228;offset=0x1f8;
        for(i=6;i<12;i++) {
            u16 angle;
            angle=*(u16 *)(p+i*32+0x2a)+*(int *)(p+0x228)/ *(int *)(p+i*32+0x2c);
            func_021FE2BC(start+i*32,(void *)d_02200AD8,15,1,angle,angle+0xf000,30);
            func_0204B688(*(void **)(p+i*4+offset),0);
        }
        *(int *)(p+0x228)=0;
        *state=1;
    }
    case 1: {
        char *start;
        int offset;
        offset=0x228;start=p;i=6;start=p+0x18;offset=0x1f8;
        for(;i<12;i++) {
            func_021FE2F8(start+i*32,(int *)&full,*(int *)(p+0x228));
            pos.x=full.x;pos.y=full.y;
            func_0204B404(*(void **)(p+i*4+offset),&pos,*(int *)(p+0xc));
        }
        if((*(int *)(p+0x228))++>60)*state=2;
        break;
    }
    case 2:func_021FD73C(task,(int)func_021FD964);break;
    }
}
