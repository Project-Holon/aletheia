/*
 * function: func_021E6718
 * address: 0x021E6718
 * packet: pkt_ov119_021E6718
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0204B294 0x0204B294 arm
 *   func_0204B92C 0x0204B92C arm
 *   func_0204B3DC 0x0204B3DC arm
 */
typedef unsigned short u16;
typedef unsigned char u8;
typedef struct { short x,y,z; u8 a,b; } Create;
struct Obj;
extern struct Obj *func_0204B294(void *,unsigned int,unsigned int,unsigned int,const void *,unsigned short,unsigned short);
extern void func_0204B92C(struct Obj *,unsigned int);
extern void func_0204B3DC(int,unsigned int);
void func_021E6718(char *p, int i) {
    Create c;
    if (!*(int *)(p+0x10bc+i*4)) {
        c.x=i*24+8; c.y=144; c.z=i+11; c.a=50; c.b=1;
        *(int *)(p+0x10bc+i*4)=(int)func_0204B294((void *)*(int *)(p+0x9c4),*(int *)(p+0x894),*(int *)(p+0x880),*(int *)(p+0x8b0),&c,1,*(u16 *)(p+0x5f4));
    }
    func_0204B92C((struct Obj *)*(int *)(p+0x10bc+i*4),1);
    func_0204B3DC(*(int *)(p+0x10bc+i*4),1);
}
