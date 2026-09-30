/*
 * function: func_021E68F4
 * address: 0x021E68F4
 * packet: pkt_ov119_021E68F4
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0204B294 0x0204B294 arm
 *   func_0204B92C 0x0204B92C arm
 *   func_0204B3DC 0x0204B3DC arm
 *   func_0204B404 0x0204B404 arm
 *   d_021E7DEC 0x021E7DEC data a2
 */
typedef unsigned short u16;
typedef unsigned char u8;
typedef struct { short x,y,z; u8 a,b; } Create;
typedef struct { short x,y; } Pt;
typedef struct { Pt pos[6]; } Table;
extern const Table d_021E7DEC;
extern int func_0204B294(int,int,int,int,Create *,u16,u16);
extern void func_0204B92C(int,unsigned int);
extern void func_0204B3DC(int,unsigned int);
extern void func_0204B404(int,const Pt *,unsigned int);
void func_021E68F4(int p, int i) {
    Table t=d_021E7DEC;
    Create c;
    if(i==-1) {
        if(*(int *)(p+0xfd4)) func_0204B3DC(*(int *)(p+0xfd4),0);
    } else {
        if(!*(int *)(p+0xfd4)) {
            c.x=64;c.y=48;c.z=23;c.a=0;c.b=1;
            *(int *)(p+0xfd4)=func_0204B294(*(int *)(p+0x9c4),*(int *)(p+0x894),*(int *)(p+0x880),*(int *)(p+0x8b0),&c,1,*(u16 *)(p+0x5f4));
        }
        func_0204B92C(*(int *)(p+0xfd4),1);
        func_0204B3DC(*(int *)(p+0xfd4),1);
        func_0204B404(*(int *)(p+0xfd4),&t.pos[i],1);
    }
}
