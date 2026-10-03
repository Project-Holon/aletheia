/*
 * function: func_021BB088
 * address: 0x021BB088
 * packet: pkt_ov225_021BB088
 * region: ov225
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * Lever: declare last before index for spill order; final flag update is
 * an if/else chain rather than a switch. 0202815C forwards pointer to 28164.
 * symbols:
 *   func_0202843C 0x0202843C thumb
 *   func_0204B3DC 0x0204B3DC arm
 *   func_021BB044 0x021BB044 thumb ov225
 *   func_0202815C 0x0202815C thumb
 *   func_02045EC0 0x02045EC0 arm
 *   func_0202804C 0x0202804C thumb
 *   func_02027FEC 0x02027FEC thumb
 *   func_02028178 0x02028178 thumb
 *   func_02045808 0x02045808 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned u32;
struct MsgBank; struct U16Vec;
struct Entry {void *resource;u16 tag,pad;u32 flags;};
extern void func_0202843C(u8 *);
extern void func_0204B3DC(void *,u32);
extern u16 func_021BB044(u16 **);
extern void func_0202815C(u8 *);
extern void *func_02045EC0(struct MsgBank *,u32);
extern u32 *func_0202804C(u32,u32,u32,u8,u8,u8,u32,u32,u16);
extern u32 func_02027FEC(u32,u32,u32,u8,u8,u16);
extern void func_02028178(u8 *);
extern void func_02045808(struct U16Vec *);
void func_021BB088(char *p)
{
    struct Entry e;
    u8 first,last,i;
    u16 index,end;
    first=0;
    index=(u16)(*(u16 *)(*(char **)p+0xc)-1);
    if (*(u16 *)(*(char **)p+0xc)==0) {
        if (*(u8 **)(p+0xc)) {
            func_0202843C(*(u8 **)(p+0xc));
            *(u32 *)(p+0x2c)=0;
        }
        index=*(u16 *)(*(char **)p+0xc);
        first=1;
        func_0204B3DC(*(void **)(p+0x60),0);
    }
    end=(u16)(func_021BB044((u16 **)p)+1);
    if (end>=*(u16 *)(*(char **)p+4)) end--;
    last=(u8)(first+end-index);
    for(i=last+1;i<=7;i++) {
        if (*(u8 **)(p+i*4+0xc)) {
            func_0202843C(*(u8 **)(p+i*4+0xc));
            *(u32 *)(p+i*4+0x2c)=0;
        }
        func_0204B3DC(*(void **)(p+i*4+0x60),0);
    }
    for(i=first;i<=last;i++) {
        if (*(u8 **)(p+i*4+0xc)) func_0202815C(*(u8 **)(p+i*4+0xc));
        e.resource=func_02045EC0(*(struct MsgBank **)(*(char **)(p+4)+0x20),*(u16 *)(*(char **)(*(char **)p+8)+index*8+2));
        if(i==0 || i==7) e.tag=0x3da3; else e.tag=0x39e3;
        e.flags=0;
        if(*(u32 *)(p+0x94))
            *(u32 **)(p+i*4+0xc)=func_0202804C(*(u32 *)(p+8),(u32)&e,2,(u8)(i*3),28,3,0,0,*(u16 *)(*(char **)(p+4)+4));
        else
            *(u32 *)(p+i*4+0xc)=func_02027FEC(*(u32 *)(p+8),(u32)&e,2,(u8)(i*3),28,*(u16 *)(*(char **)(p+4)+4));
        func_02028178(*(u8 **)(p+i*4+0xc));
        *(u32 *)(p+i*4+0x2c)=1;
        func_02045808(e.resource);
        if (*(u32 *)(*(char **)(*(char **)p+8)+index*8+4)==0)
            func_0204B3DC(*(void **)(p+i*4+0x60),0);
        else if (*(u32 *)(*(char **)(*(char **)p+8)+index*8+4)==1)
            func_0204B3DC(*(void **)(p+i*4+0x60),1);
        index++;
    }
    *(u32 *)(p+0x94)=1;
}
