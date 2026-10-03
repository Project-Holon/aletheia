/*
 * function: func_021FD760
 * address: 0x021FD760
 * packet: pkt_ov186_021FD760
 * region: ov186
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: signed FC124 index avoids caching unsigned FBE54 index+9; zero counter before res spill.
 * prototype: B294 returns live r0 and receives full-width heap without truncation.
 * symbols:
 *   func_02030734 0x02030734 arm
 *   func_02082BCC 0x02082BCC arm
 *   func_021FD6D8 0x021FD6D8 thumb ov186
 *   func_021FD964 0x021FD964 thumb ov186
 *   func_021FBE54 0x021FBE54 thumb ov186
 *   func_021FC124 0x021FC124 thumb ov186
 *   func_02034714 0x02034714 arm
 *   func_0204B294 0x0204B294 arm
 *   func_0204B3DC 0x0204B3DC arm
 *   func_0204B688 0x0204B688 arm
 *   d_02200D5C 0x02200D5C data a4
 *   d_02200D68 0x02200D68 data a4
 */
typedef struct { int x,y; } Pair;
typedef struct { int x,y,z; } Triple;
typedef struct { char pad[0xC];int index;int task;char *resources;char pad18[0x1E0];int handles[12]; } Handles;
typedef unsigned short u16;
typedef unsigned int   u32;
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void func_02082BCC(void *,int,unsigned),func_02034714(const char *,int,const char *);
extern int func_021FD6D8(char *,void (*)(void),int),func_021FC124(char *,int,Triple *);
extern void func_021FD964(void),func_021FBE54(char *,unsigned,unsigned);
extern int func_0204B294(unsigned,unsigned,unsigned,unsigned,Pair *,unsigned short,int);
extern void func_0204B3DC(int,int),func_0204B688(int,int);
extern const char d_02200D5C[],d_02200D68[];
char *func_021FD760(unsigned owner,char *resources,int index,int heap)
{
    Triple triple;
    Pair pair;
    unsigned short res;
    char *p;
    int i;
    p=func_02030734(heap,0x264,0,d_02200D5C,0x7CA);
    func_02082BCC(p,0,0x264);
    ((Handles *)p)->resources=resources;((Handles *)p)->index=index;
    ((Handles *)p)->task=func_021FD6D8(p,func_021FD964,heap);
    func_021FBE54(((Handles *)p)->resources,index+9,heap);
    func_02082BCC(&pair,0,8);
    if(!func_021FC124(((Handles *)p)->resources,index+9,&triple)) func_02034714(d_02200D68,0,d_02200D68);
    i=0;
    res=index;
    for(;i<12;i++) {
        ((Handles *)p)->handles[i]=func_0204B294(owner,triple.y,triple.z,triple.x,&pair,res,heap);
        func_0204B3DC(((Handles *)p)->handles[i],0);
        func_0204B688(((Handles *)p)->handles[i],1);
    }
    return p;
}
