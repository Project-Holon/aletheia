/*
 * function: func_021DCE48
 * address: 0x021DCE48
 * packet: pkt_ov183_021DCE48
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0204B3DC 0x0204B3DC arm
 *   func_0204B3B4 0x0204B3B4 arm
 *   func_0204A8D4 0x0204A8D4 arm
 *   func_0204ADA4 0x0204ADA4 arm
 *   func_0204AFD8 0x0204AFD8 arm
 *   func_021FC734 0x021FC734 thumb ov186
 *   func_021FBDA4 0x021FBDA4 thumb ov186
 *   func_020409B4 0x020409B4 arm
 */
typedef unsigned int   u32;
typedef unsigned char  u8;
struct Obj;
extern void func_0204B3DC(struct Obj *p, u32 v);
extern void func_0204B3B4(struct Obj *p);
extern void func_0204A8D4(u32 i);
extern void func_0204ADA4(u32 i);
extern void func_0204AFD8(u32 i);
extern void func_021FC734(u8 *p);
extern void func_021FBDA4(int a, unsigned mode);
extern void func_020409B4(u32 index);
void func_021DCE48(char *p,char *q)
{
    int i;
    char *slot;
    if(*(int *)(p+0xd4)) {
        for(i=0;i<12;i++) {
            slot=p+i*4;
            if(*(void **)(slot+0x80)) {
                func_0204B3DC(*(void **)(slot+0x80),0);
                func_0204B3B4(*(void **)(slot+0x80));
                *(int *)(slot+0x80)=0;
            }
            if(*(int *)(slot+0x50)!=-1) { func_0204A8D4(*(int *)(slot+0x50)); *(int *)(slot+0x50)=-1; }
        }
        if(*(int *)(p+0x48)!=-1) { func_0204ADA4(*(int *)(p+0x48)); *(int *)(p+0x48)=-1; }
        if(*(int *)(p+0x4c)!=-1) { func_0204AFD8(*(int *)(p+0x4c)); *(int *)(p+0x4c)=-1; }
        for(i=0;i<5;i++) {
            slot=p+i*4;
            if(*(void **)(slot+0x30)) { func_021FC734(*(void **)(slot+0x30)); *(int *)(slot+0x30)=0; }
        }
        func_021FBDA4(*(int *)(q+0x10),6);
        func_020409B4(1);
        *(int *)(p+0xd4)=0;
    }
}
