/*
 * function: func_021BB480
 * address: 0x021BB480
 * packet: pkt_ov206_021BB480
 * region: ov206
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021BB92C 0x021BB92C thumb ov206
 *   func_0204B3B4 0x0204B3B4 arm
 *   func_0204A8D4 0x0204A8D4 arm
 *   func_0204AFD8 0x0204AFD8 arm
 *   func_0204ADA4 0x0204ADA4 arm
 */
extern void func_021BB92C(char *,int);
struct Obj;
extern void func_0204B3B4(struct Obj *p);
typedef unsigned int   u32;
extern void func_0204A8D4(u32 i);
extern void func_0204AFD8(u32 i);
extern void func_0204ADA4(u32 i);
void func_021BB480(char *p)
{
    unsigned char i;
    for(i=0;i<2;i++) func_021BB92C(p,i);
    if(*(int *)(p+0xe4)) {
        for(i=0;i<17;i++) {
            char *slot=p+i*4;
            func_0204B3B4((struct Obj *)(*(int *)(slot+0x12c)));
            func_0204A8D4(*(int *)(slot+0xe8));
        }
        *(int *)(p+0xe4)=0;
    }
    func_0204AFD8(*(int *)(p+0xcc));
    func_0204ADA4(*(int *)(p+0xc8));
}
