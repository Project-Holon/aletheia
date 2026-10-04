/*
 * function: func_021E67E0
 * address: 0x021E67E0
 * packet: pkt_ov119_021E67E0
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0204B294 0x0204B294 arm
 *   func_0204B92C 0x0204B92C arm
 *   func_0204B3DC 0x0204B3DC arm
 *   func_0204B878 0x0204B878 arm
 */
typedef unsigned short u16;
typedef unsigned char u8;
typedef struct { short x,y,z; u8 a,b; } Create;
typedef struct {
    char pad0[0x5f4];
    u16 heap;
    char pad1[0x884-0x5f6];
    int g884;
    char pad2[0x898-0x888];
    int g898;
    char pad3[0x8b4-0x89c];
    int g8b4;
    char pad4[0x9c4-0x8b8];
    int g9c4;
    char pad5[0x10ac-0x9c8];
    int slot[8];
} Work;
extern int func_0204B294(int,int,int,int,Create *,u16,u16);
struct Obj;
extern void func_0204B92C(struct Obj *,unsigned int);
extern void func_0204B3DC(int,unsigned int);
extern void func_0204B878(int,u16);
void func_021E67E0(Work *p, int z, int i) {
    Create c;
    c.x=i*206+8; c.y=160; c.z=4; c.a=1; c.b=0;
    if (!p->slot[i*2]) {
        p->slot[i*2]=func_0204B294(p->g9c4,p->g898,p->g884,p->g8b4,&c,0,p->heap);
        func_0204B92C((struct Obj *)p->slot[i*2],1);
        func_0204B3DC(p->slot[i*2],1);
    } else {
        func_0204B3DC(p->slot[i*2],1);
    }
    if (!p->slot[i*2+1]) {
        c.a=0; c.z=z;
        p->slot[i*2+1]=func_0204B294(p->g9c4,p->g898,p->g884,p->g8b4,&c,0,p->heap);
        func_0204B92C((struct Obj *)p->slot[i*2+1],1);
        func_0204B3DC(p->slot[i*2+1],1);
    } else {
        func_0204B878(p->slot[i*2+1],z);
    }
}
