/*
 * function: func_021FB948
 * address: 0x021FB948
 * packet: pkt_ov132_021FB948
 * region: ov132
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0201134C 0x0201134C thumb
 *   func_021FB1F4 0x021FB1F4 thumb ov132
 *   func_021F9DA0 0x021F9DA0 thumb ov132
 *   func_021F9DA4 0x021F9DA4 thumb ov132
 *   func_02030734 0x02030734 arm
 *   func_021FADA0 0x021FADA0 thumb ov132
 *   func_021FBA14 0x021FBA14 thumb ov132
 *   d_021FDD00 0x021FDD00 data a4
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u32 func_0201134C(void *);
extern int func_021FB1F4(char *,int);
extern void *func_021F9DA0(char *p);
extern void *func_021F9DA4(char *p, u32 i);
extern void *func_02030734(u32,u32,int,const char *,u16);
extern void *func_021FADA0(char *,u32,u32,u32);
extern void func_021FBA14(int,int *);
extern const char d_021FDD00[];
int func_021FB948(int unused,char *p)
{
    char *owner,*q;
    int mask;
    u32 rate,start,delta,wait;
    u8 i;
    owner=*(char **)p;
    mask=func_021FB1F4(p,func_0201134C(*(void **)(p+4)));
    rate=func_0201134C(*(void **)(p+4));
    start=func_0201134C(*(void **)(p+4));
    delta=func_0201134C(*(void **)(p+4));
    wait=func_0201134C(*(void **)(p+4));
    func_021F9DA0(*(void **)(owner+52));
    for(i=0;i<4;i++) {
        if(mask&(1<<i)) {
            q=func_02030734(*(u16 *)owner,36,0,d_021FDD00,0x493);
            *(char **)(q+28)=owner;
            *(void **)(q+24)=func_021F9DA4(*(void **)(owner+52),i);
            *(void **)q=*(void **)(owner+52);
            *(u32 *)(q+4)=start;
            *(u32 *)(q+8)=start+delta;
            *(u16 *)(q+12)=rate;
            *(u16 *)(q+14)=0;
            *(void **)(q+32)=func_021FADA0(owner,(u32)func_021FBA14,(u32)q,10);
        }
    }
    if(wait==1) {*(u16 *)(p+20)=rate;return 1;}
    return 0;
}

