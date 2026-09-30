/*
 * function: func_021C0B54
 * address: 0x021C0B54
 * packet: pkt_ov110_021C0B54
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: MATCH
 * blocker: ARM9 Thumb 0x02024910 lacks an outside witness. Verified EXACT in blocker.log:
 *   void *func_02024910(char *p,int i) { return p+8+i*8; }
 * symbols:
 *   func_021C1718 0x021C1718 thumb ov110
 *   func_021C0C44 0x021C0C44 thumb ov110
 *   func_021C0D34 0x021C0D34 thumb ov110
 *   func_0204B3DC 0x0204B3DC arm
 *   func_020450F0 0x020450F0 arm
 *   func_02024910 0x02024910 thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;
extern void *func_021C1718(void *);
extern void *func_0202DB0C(void *,int,void *,void *,int,int,u16);
extern void *func_02024910(void *,int);
extern int func_02024464(void *,u16);
extern void func_0204B3DC(void *,int);
extern void *func_020450F0(int,int,u8,int,int,int,int);
extern void func_021C0C44(void *);
extern void func_021C0D34(void *,int);
void func_021C0B54(char *p) {
    int i;
    unsigned v;
    *(void **)(p+0x8c)=func_0202DB0C(func_021C1718(*(void **)(p+0x50)),0,*(void **)(p+0x5c),*(void **)(p+0x58),8,4,*(u16 *)(p+4));
    *(u8 *)(p+0x97)=0;
    for(i=0;i<20;i++) {
        if(!func_02024464(func_02024910(*(void **)(p+0x20),i),*(u16 *)(p+4))) break;
        (*(u8 *)(p+0x97))++;
    }
    v=*(u8 *)(p+0x97);
    *(u8 *)(p+0x98)=v;
    if(v<20) (*(u8 *)(p+0x98))++;
    func_0204B3DC(*(void **)(p+8),*(u8 *)(p+0x98)>3);
    for(i=0;i<4;i++) *(void **)(p+0x6c+i*4)=func_020450F0(2,2,i*6+2,25,4,9,1);
    func_021C0C44(p);
    func_021C0D34(p,1);
}
