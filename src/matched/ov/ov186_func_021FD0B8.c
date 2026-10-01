/*
 * function: func_021FD0B8
 * address: 0x021FD0B8
 * packet: pkt_ov186_021FD0B8
 * region: ov186
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: accessor at 021FD110 filed separately, then two zero alignment bytes.
 * symbols:
 *   func_02035C08 0x02035C08 arm
 *   func_02035D20 0x02035D20 arm
 *   func_021FD860 0x021FD860 thumb ov186
 *   func_020061E4 0x020061E4 thumb
 */
typedef struct {int x,y;} Pair;
extern int func_02035C08(const void *);
extern void func_02035D20(int *,int *),func_021FD860(int,int,Pair *),func_020061E4(int);
void func_021FD0B8(char *p)
{
    int x,y;
    Pair pair;
    int result;
    *(int *)(p+0x48)=-1;
    result=func_02035C08(p+0x5C);
    if(result!=-1) {
        if(*(int *)(p+0x20)) {
            func_02035D20(&x,&y);pair.x=x;pair.y=y;
            func_021FD860(*(int *)(p+0x20),1,&pair);
        }
        func_020061E4(0x703);
        *(int *)(p+0x48)=((int *)(*(int *)(p)+(result+*(unsigned short *)(p+0x42))*8))[1];
    }
}
