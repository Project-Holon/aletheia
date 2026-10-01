/*
 * function: func_021D92B0
 * address: 0x021D92B0
 * packet: pkt_ov131_021D92B0
 * region: ov131
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * proof: loop i starts at zero and tests i<10 after each byte increment;
 * i*20 <=180. Each other byte index is guarded <10 before *20.
 * prototype: 021D92EA loads r1 for 021D9428 despite its legacy one-input
 * source. Preserve this observed full-word argument in the caller extern.
 * symbols:
 *   func_021D9440 0x021D9440 thumb ov131
 *   func_021DBE2C 0x021DBE2C thumb ov131
 *   func_021D9428 0x021D9428 thumb ov131
 *   func_021D91F0 0x021D91F0 thumb ov131
 *   func_021DBCA4 0x021DBCA4 thumb ov131
 *   func_021DBCF4 0x021DBCF4 thumb ov131
 *   func_0201C6C4 0x0201C6C4 thumb
 *   func_0200616C 0x0200616C thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
extern s16 func_021D9440(u8 *,u32);
extern void func_021DBE2C(u8 *,s16,s16);
extern u32 func_021D9428(u8 *,u32);
extern void func_021D91F0(u8 *,u8 *,u8 *);
extern void func_021DBCA4(u8 *,int);
extern void func_021DBCF4(void *);
extern u32 func_0201C6C4(void *,void *);
extern void func_0200616C(void *,int);
void func_021D92B0(u8 *a,u8 *p)
{
    int changed;
    u8 *entries;
    u8 i;
    u32 value;
    u8 *entry;
    s16 y;
    changed=0;
    entries=p;
    entries+=0x70;
    for(i=0;i<10;i++) {
        if(*(u32 *)(p+12)==1) {
            y=func_021D9440(p,i);
            func_021DBE2C(*(u8 **)((p+i*20)+0x80),8,y);
            value=func_021D9428(p,i);
            if(value==65535) {
                *(u16 *)((p+i*20)+0x70)=value;
                func_021DBCA4(*(u8 **)((p+i*20)+0x80),0);
            } else if(value!=*(u16 *)((p+i*20)+0x70)) {
                changed=1;
                *(u16 *)((p+i*20)+0x70)=value;
                func_021D91F0(a,p,entries+i*20);
                func_021DBCA4(*(u8 **)((p+i*20)+0x80),1);
            }
        }
        entry=p+i*20;
        if(*(u32 *)(entry+0x78)==1 && func_0201C6C4(*(void **)(a+0x84),*(void **)(entry+0x7c))==0) {
            *(u32 *)(entry+0x78)=0;
            func_021DBCF4(*(void **)(entry+0x80));
        }
    }
    if(changed==1 && p[0x60]==0) {
        func_0200616C((void *)1605,1);
        p[0x60]=3;
    }
    if(*(u32 *)(p+0x68)==1) {
        if(p[0x58]<10) func_021D91F0(a,p,(p+0x70)+p[0x58]*20);
        if(p[0x5a]<10) func_021D91F0(a,p,(p+0x70)+p[0x5a]*20);
        p[0x5a]=p[0x58];
        *(u32 *)(p+0x68)=0;
    }
    *(u32 *)(p+12)=0;
}
