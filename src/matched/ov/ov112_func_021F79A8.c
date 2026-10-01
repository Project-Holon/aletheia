/*
 * unit: yes
 * function: func_021F79A8, func_021F7A80, func_021F7A94
 * address: 0x021F79A8
 * packet: pkt_ov112_021F79A8
 * region: ov112
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * extent: Thumb followers7A80 (18 code+2 zero padding7A92) and7A94 (BX LR+2 zero padding7A96), parent-cleared.
 * ABI: 514C retains caller's explicitly loaded r1 halfword although its own legacy body ignores that input.
 * symbols:
 *   func_021F4F10 0x021F4F10 thumb ov112
 *   func_021F514C 0x021F514C thumb ov112
 *   func_0200616C 0x0200616C thumb
 *   func_021F7AEC 0x021F7AEC thumb ov112
 *   func_021F7C90 0x021F7C90 thumb ov112
 *   func_021F7E2C 0x021F7E2C thumb ov112
 *   func_021F7FA8 0x021F7FA8 thumb ov112
 *   func_021F7A98 0x021F7A98 thumb ov112
 *   func_021F7BA8 0x021F7BA8 thumb ov112
 *   func_021F7D30 0x021F7D30 thumb ov112
 *   func_021F7ECC 0x021F7ECC thumb ov112
 *   func_021F7FAC 0x021F7FAC thumb ov112
 *   d_021F832C 0x021F832C data a4
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u32 func_021F4F10(u8 *);
extern u8 func_021F514C(void *,u32);
extern void func_0200616C(void *,int);
extern void *d_021F832C[];
extern void func_021F7AEC(char *,char *);
extern void func_021F7C90(char *,char *);
extern void func_021F7E2C(char *,char *);
extern void func_021F7FA8(char *,char *);
extern void func_021F7A98(char *,char *);
extern void func_021F7BA8(u8 *,u8 *);
extern void func_021F7D30(char *,char *);
extern void func_021F7ECC(char *,char *);
extern void func_021F7FAC(char *,char *);
void func_021F7A94(char *,char *);
void func_021F79A8(char *p,char *q,int index)
{
    u32 v;
    if(*(int *)(q+132+index*4)==0 || *(int *)(q+260)!=0) return;
    v=func_021F514C((void *)func_021F4F10((u8 *)*(void **)(p+16)),**(u16 **)(q+168+index*4));
    *(u16 *)(q+240)=0;
    *(int *)(q+244)=index;
    *(int *)(q+248)=0;
    func_0200616C(d_021F832C[v],2);
    *(u8 *)(p+1084)+=1;
    switch(v) {
    case 0: func_021F7A94(p,q); *(void (**)(char *,char *))(q+260)=func_021F7A98; break;
    case 1: func_021F7AEC(p,q); *(void (**)(u8 *,u8 *))(q+260)=func_021F7BA8; break;
    case 2: func_021F7C90(p,q); *(void (**)(char *,char *))(q+260)=func_021F7D30; break;
    case 3: func_021F7E2C(p,q); *(void (**)(char *,char *))(q+260)=func_021F7ECC; break;
    case 4: func_021F7FA8(p,q); *(void (**)(char *,char *))(q+260)=func_021F7FAC; break;
    }
}
int func_021F7A80(char *p,char *q)
{
    if(*(int *)(q+260)!=0) return 1;
    return 0;
}
void func_021F7A94(char *p,char *q)
{
}
