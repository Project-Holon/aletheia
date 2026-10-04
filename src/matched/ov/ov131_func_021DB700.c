/*
 * function: func_021DB700
 * address: 0x021DB700
 * packet: pkt_ov131_021DB700
 * region: ov131
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: assign p[0] before pos.x to schedule its store before the stack address.
 * symbols:
 *   d_021DC2B8 0x021DC2B8 data a1
 *   func_0204B294 0x0204B294 arm
 *   func_0204B3DC 0x0204B3DC arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef struct {u16 x,y,z;u8 priority,flags;} ObjPos;
extern const u8 d_021DC2B8[][2];
struct Obj;
extern struct Obj *func_0204B294(void *owner, unsigned int i, unsigned int j, unsigned int k, const void *position, unsigned short space, unsigned short heap);
typedef unsigned int   u32;
struct Obj;
extern void func_0204B3DC(struct Obj *p, u32 v);
void func_021DB700(u8 *a,void *b,u8 *p,u8 i) {
    ObjPos pos;
    *(int *)(p+4)=0;
    p[0]=i;
    pos.x=d_021DC2B8[i][0]*8;
    pos.y=d_021DC2B8[i][1]*8;
    pos.priority=10;
    pos.flags=0;
    pos.z=p[0];
    *(void **)(p+8)=func_0204B294(*(void **)(a+372),(unsigned int)*(void **)(a+232),(unsigned int)*(void **)(a+176),(unsigned int)*(void **)(a+280),&pos,0,*(u16 *)a);
    func_0204B3DC(*(void **)(p+8),0);
    pos.x=d_021DC2B8[p[0]][0]*8+26;
    pos.y=d_021DC2B8[p[0]][1]*8+9;
    pos.priority=8;
    pos.flags=0;
    pos.z=0;
    *(void **)(p+12)=func_0204B294(*(void **)(a+372),(unsigned int)*(void **)(a+304),(unsigned int)*(void **)(a+164),(unsigned int)*(void **)(a+268),&pos,0,*(u16 *)a);
    func_0204B3DC(*(void **)(p+12),0);
}
