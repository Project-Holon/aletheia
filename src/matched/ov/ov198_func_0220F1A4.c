/*
 * function: func_0220F1A4
 * address: 0x0220F1A4
 * packet: pkt_ov198_0220F1A4
 * region: ov198
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_022110D4 0x022110D4 thumb ov198
 *   func_0220F158 0x0220F158 thumb ov198
 *   func_0220F138 0x0220F138 thumb ov198
 *   CLACT_AddActorAnimFrame 0x0204B8D4 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
extern int func_022110D4(u8 *,int);
extern int func_0220F158(char *);
extern void func_0220F138(void *,int);
typedef unsigned int   u32;
struct Obj;
extern void CLACT_AddActorAnimFrame(struct Obj *p, u32 arg);
void func_0220F1A4(u8 *p)
{
    u16 i;
    int j;
    for (i=0;i<6;i++) {
        j=func_022110D4(p,i);
        if (*(u16 *)(p+j*0x4c+8)) {
            int k=func_0220F158((char *)p+4+j*0x4c);
            func_0220F138(*(void **)(p+j*4+0x1ed8),k);
            CLACT_AddActorAnimFrame(*(void **)(p+j*4+0x1ed8),0x1000);
        }
    }
}
