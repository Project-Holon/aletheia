/*
 * function: func_021BEBEC
 * address: 0x021BEBEC
 * packet: pkt_ov204_021BEBEC
 * region: ov204
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020490F4 0x020490F4 arm
 *   func_02008550 0x02008550 thumb
 *   func_0204A6C8 0x0204A6C8 arm
 *   func_0204ABF0 0x0204ABF0 arm
 *   func_0204AF28 0x0204AF28 arm
 *   func_02049238 0x02049238 arm
 *   func_021BDD78 0x021BDD78 thumb ov204
 *   func_0204B294 0x0204B294 arm
 *   func_0204B3DC 0x0204B3DC arm
 *   init 0x021BFFCC data a2
 */
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct {u16 v[12];} Init;
extern const Init init;
extern void *func_020490F4(u32,u16);
extern int func_02008550(void *);
extern void *func_0204A6C8(void *,u32,u32,u32,u32);
extern void *func_0204ABF0(void *,u32,u32,u32,u32);
extern void *func_0204AF28(void *,u32,u32,u32);
extern void func_02049238(void *);
extern void *func_021BDD78(void *);
extern void *func_0204B294(void *,void *,void *,void *,void *,u32,u32);
extern void func_0204B3DC(void *,u32);
int func_021BEBEC(char *p)
{
    Init local;
    void *arc;
    u32 i;
    char *row;
    arc=func_020490F4(170,*(u16 *)p);
    if(func_02008550(**(void ***)(p+4))==0){
        *(void **)(p+0x10b4)=func_0204A6C8(arc,6,0,0,*(u16 *)p);
        *(void **)(p+0x10c0)=func_0204ABF0(arc,7,0,0,*(u16 *)p);
        *(void **)(p+0x10cc)=func_0204AF28(arc,5,4,*(u16 *)p);
    }else{
        *(void **)(p+0x10b4)=func_0204A6C8(arc,10,0,0,*(u16 *)p);
        *(void **)(p+0x10c0)=func_0204ABF0(arc,11,0,0,*(u16 *)p);
        *(void **)(p+0x10cc)=func_0204AF28(arc,9,8,*(u16 *)p);
    }
    *(void **)(p+0x10b8)=func_0204A6C8(arc,17,0,0,*(u16 *)p);
    *(void **)(p+0x10c4)=func_0204ABF0(arc,18,0,32,*(u16 *)p);
    *(void **)(p+0x10d0)=func_0204AF28(arc,16,15,*(u16 *)p);
    *(void **)(p+0x10bc)=func_0204A6C8(arc,21,0,0,*(u16 *)p);
    *(void **)(p+0x10c8)=func_0204ABF0(arc,22,0,64,*(u16 *)p);
    *(void **)(p+0x10d4)=func_0204AF28(arc,20,19,*(u16 *)p);
    func_02049238(arc);
    local=init;
    for(i=0;i<3;i++){
        row=p+i*4;
        *(void **)(row+0x10a8)=func_0204B294(func_021BDD78(*(void **)(p+20)),*(void **)(row+0x10b4),*(void **)(row+0x10c0),*(void **)(row+0x10cc),(char *)&local+i*8,0,*(u16 *)p);
        func_0204B3DC(*(void **)(row+0x10a8),0);
    }
    return 1;
}
