/*
 * function: func_021F1888
 * address: 0x021F1888
 * packet: pkt_ov194_021F1888
 * region: ov194
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: Associate each indexed object address as p+index*4+12, preventing a hoisted p+12 spill in the final loop.
 * symbols:
 *   func_020490F4 0x020490F4 arm
 *   func_0204ABF0 0x0204ABF0 arm
 *   func_0204AF28 0x0204AF28 arm
 *   func_0204A6C8 0x0204A6C8 arm
 *   func_02049238 0x02049238 arm
 *   func_02082BCC 0x02082BCC arm
 *   func_0204B294 0x0204B294 arm
 *   func_0204B3DC 0x0204B3DC arm
 *   func_0204B92C 0x0204B92C arm
 */
typedef unsigned short u16;
extern void *func_020490F4(unsigned,u16);
extern int func_0204ABF0(void *,unsigned,unsigned,unsigned,u16);
extern int func_0204AF28(void *,unsigned,unsigned,unsigned);
extern int func_0204A6C8(void *,unsigned,unsigned,unsigned,u16);
extern void func_02049238(void *);
extern void func_02082BCC(void *,int,int);
struct Obj;
extern struct Obj *func_0204B294(void *owner, unsigned int i, unsigned int j, unsigned int k, const void *position, unsigned short space, unsigned short heap);
extern void func_0204B3DC(void *,unsigned);
struct Obj;
extern void func_0204B92C(struct Obj *,unsigned);
void func_021F1888(char *p,unsigned owner,u16 heap)
{
    short pos[4];
    void *handle;
    int i;
    int zero;
    handle=func_020490F4(118,heap);
    *(int *)p=func_0204ABF0(handle,9,0,0,heap);
    *(int *)(p+8)=func_0204AF28(handle,7,6,heap);
    *(int *)(p+4)=func_0204A6C8(handle,8,0,0,heap);
    func_02049238(handle);
    func_02082BCC(pos,0,8);
    pos[2]=0;
    zero=0;
    for(i=0;i<16;i++)
        *(void **)(p+i*4+12)=func_0204B294((void *)owner,*(unsigned *)(p+4),*(unsigned *)p,*(unsigned *)(p+8),pos,zero,heap);
    pos[2]=1;
    *(void **)(p+0x50)=func_0204B294((void *)owner,*(unsigned *)(p+4),*(unsigned *)p,*(unsigned *)(p+8),pos,zero,heap);
    func_0204B3DC(*(void **)(p+0x50),zero);
    for(i=18;i<20;i++) {
        pos[0]=-32;
        pos[1]=-32;
        pos[2]=i-15;
        *(void **)(p+i*4+12)=func_0204B294((void *)owner,*(unsigned *)(p+4),*(unsigned *)p,*(unsigned *)(p+8),pos,0,heap);
        func_0204B92C(*(void **)(p+i*4+12),1);
        func_0204B3DC(*(void **)(p+i*4+12),0);
    }
}
