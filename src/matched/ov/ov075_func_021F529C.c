/*
 * function: func_021F529C
 * address: 0x021F529C
 * packet: pkt_ov075_021F529C
 * region: ov075
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020122C0 0x020122C0 thumb
 *   func_020124E8 0x020124E8 thumb
 *   func_02082BCC 0x02082BCC arm
 *   func_021F5518 0x021F5518 thumb ov075
 */
typedef unsigned int u32;
typedef struct Vec { int x,y,z; } Vec;
extern void *func_020122C0(void *,void *,void *,u32);
extern void *func_020124E8(void *);
extern void func_02082BCC(void *,int,int);
extern int func_021F5518(void *,int *,void *);
void *func_021F529C(void *a,Vec *src,u32 b,u32 c) {
    void *h;
    char *w;
    h=func_020122C0(a,0,(void *)func_021F5518,0x30);
    w=func_020124E8(h);
    func_02082BCC(w,0,0x30);
    *(Vec *)(w+24)=*src;
    *(u32 *)(w+40)=b;
    *(u32 *)(w+44)=c;
    return h;
}
