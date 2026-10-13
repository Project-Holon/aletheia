/*
 * function: func_0220EA68
 * address: 0x0220EA68
 * packet: pkt_ov198_0220EA68
 * region: ov198
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   func_0220EAF0 0x0220EAF0 thumb ov198
 *   func_0220EBCC 0x0220EBCC thumb ov198
 *   func_0220EC2C 0x0220EC2C thumb ov198
 *   func_0220ECCC 0x0220ECCC thumb ov198
 *   func_0220ED54 0x0220ED54 thumb ov198
 *   func_0220EFD8 0x0220EFD8 thumb ov198
 *   func_0220EE44 0x0220EE44 thumb ov198
 *   func_0220EECC 0x0220EECC thumb ov198
 */
typedef unsigned int   u32;
struct Obj;
extern void CLACT_SetActorDrawEnable(struct Obj *p, u32 v);
extern void func_0220EAF0(void *);
extern void func_0220EBCC(void *);
typedef unsigned char  u8;
extern void func_0220EC2C(u8 *p);
extern void func_0220ECCC(u8 *p);
extern void func_0220ED54(u8 *p);
extern void func_0220EFD8(u8 *p);
extern void func_0220EE44(u8 *p);
extern void func_0220EECC(u8 *p);
void func_0220EA68(char *p,unsigned mode)
{
    unsigned i;
    for(i=0;i<41;i++)CLACT_SetActorDrawEnable(*(void **)(p+i*4+0x1ebc),0);
    switch(mode){
    case 0: case 8: func_0220EAF0(p);return;
    case 1: func_0220EBCC(p);return;
    case 2: func_0220EC2C((u8 *)p);return;
    case 3: func_0220ECCC((u8 *)p);return;
    case 4: func_0220ED54((u8 *)p);return;
    case 5: func_0220EFD8((u8 *)p);return;
    case 6: func_0220EE44((u8 *)p);return;
    case 7: func_0220EECC((u8 *)p);return;
    }
}
