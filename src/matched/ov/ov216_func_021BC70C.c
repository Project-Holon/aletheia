/*
 * function: func_021BC70C
 * address: 0x021BC70C
 * packet: pkt_ov216_021BC70C
 * region: ov216
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * blocker: ARM9 0202DE64 +0048 and0202DE68 +0054 lack matched starts.
 * Owner unit_0202DE5C.c defines both but omits them from function:.
 * the integrator owns the repair; singleton TU --suggest-split leaves this caller out.
 * Verified EXACT4 each with fixed flags, Thumb, no region, in assigned scratch:
 * void func_0202DE64(char *p,u16 value){*(u16 *)(p+36)=value;}
 * void func_0202DE68(char *p,u32 value){*(u32 *)(p+44)=value;}
 * lever: layer=i+4 is a named int reused by the byte store and calls,
 * keeping its full-word home at sp+18 before q's first definition.
 * Prototype: C5C4 layer is u8 here because this caller explicitly truncates.
 * symbols:
 *   func_021BCA38 0x021BCA38 thumb ov216
 *   func_0202DB0C 0x0202DB0C thumb
 *   func_0202DE5C 0x0202DE5C thumb
 *   func_0202DE64 0x0202DE64 thumb
 *   func_0202DE68 0x0202DE68 thumb
 *   func_020450F0 0x020450F0 arm
 *   func_021BC5C4 0x021BC5C4 thumb ov216
 *   func_021BC614 0x021BC614 thumb ov216
 *   func_0204B688 0x0204B688 arm
 *   func_0204B3DC 0x0204B3DC arm
 */
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
struct PmsDraw;struct Actor;struct Window;
struct Obj;
extern void *func_021BCA38(char *p);
extern struct PmsDraw *func_0202DB0C(u32,u32,u32,u32,u8,u8,u16);
extern void func_0202DE5C(struct PmsDraw *,u8);
extern void func_0202DE64(struct PmsDraw *,u16);
extern void func_0202DE68(struct PmsDraw *,u32);
extern u32 func_020450F0(u32,u32,u32,u32,u8,u8,u8);
extern void func_021BC5C4(struct Window *,u8,u8,u32,u8,u8,u8);
extern void *func_021BC614(void *,void *,void *,short,short,u8,u8,u8,u16);
extern void func_0204B688(struct Actor *,u32);
extern void func_0204B3DC(struct Obj *p, u32 v);
void func_021BC70C(char *p)
{
    void *manager;
    int i,j,layer;
    char *q;
    manager=func_021BCA38(*(void **)(p+80));
    *(struct PmsDraw **)(p+344)=func_0202DB0C((u32)manager,1,*(u32 *)(p+300),*(u32 *)(p+296),10,2,*(u16 *)p);
    func_0202DE5C(*(struct PmsDraw **)(p+344),4);
    func_0202DE64(*(struct PmsDraw **)(p+344),15812);
    func_0202DE68(*(struct PmsDraw **)(p+344),1);
    for(i=0;i<2;i++){
        layer=i+4;
        q=p+348+i*128;
        q[126]=(u8)layer;
        *(u32 *)(q+112)=func_020450F0((u8)layer,2,15,28,4,i,1);
        for(j=0;j<4;j++)func_021BC5C4((struct Window *)(q+j*16),layer,i,2,j*2+1,19,2);
        func_021BC5C4((struct Window *)(q+64),layer,i,2,9,19,2);
        func_021BC5C4((struct Window *)(q+80),layer,i,3,11,28,4);
        func_021BC5C4((struct Window *)(q+96),layer,i,4,19,27,4);
        *(void **)(q+120)=func_021BC614(p,manager,p+104+i*12,220,44,0,1,i,1);
        func_0204B688(*(struct Actor **)(q+120),0);
        func_0204B3DC(*(void **)(q+120),0);
        *(void **)(q+116)=func_021BC614(p,manager,p+92,200,80,6,0,i,1);
        func_0204B688(*(struct Actor **)(q+116),1);
        func_0204B3DC(*(void **)(q+116),0);
    }
}
