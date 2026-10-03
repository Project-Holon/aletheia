/*
 * function: func_021DE208
 * address: 0x021DE208
 * packet: pkt_ov119_021DE208
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020362DC 0x020362DC arm
 *   func_020355D8 0x020355D8 arm
 */

typedef unsigned int u32;
extern u32 func_020362DC(void);
typedef unsigned char  u8;
extern void func_020355D8(u8 v);
static inline int poll(void)
{
    int v=func_020362DC();
    if(v) func_020355D8(0);
    return v;
}
int func_021DE208(char *p)
{
    int changed=0;
    int v;
    if(poll()==16) { *(int *)(p+0x10a0)=(*(int *)(p+0x10a0)+3)%6; changed=1; }
    if(poll()==32) {
        *(int *)(p+0x10a0)=(*(int *)(p+0x10a0)-3)%6;
        if(*(int *)(p+0x10a0)<0) *(int *)(p+0x10a0)+=6;
        changed=1;
    }
    if(poll()==64) {
        v=*(int *)(p+0x10a0);
        if(v==0 || v==3) *(int *)(p+0x10a0)+=3;
        *(int *)(p+0x10a0)-=1; changed=1;
    }
    if(poll()==128) {
        v=*(int *)(p+0x10a0);
        if(v==2 || v==5) *(int *)(p+0x10a0)-=3;
        *(int *)(p+0x10a0)+=1; changed=1;
    }
    return changed;
}
