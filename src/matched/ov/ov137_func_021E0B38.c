/*
 * function: func_021E0B38
 * address: 0x021E0B38
 * packet: pkt_ov137_021E0B38
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 */
typedef struct { int x,y,z; } Vec;
void func_021E0B38(char *p,char *q,int amount)
{
    int n;
    *(short *)(q+4)=0;
    *(short *)(q+6)=0;
    *(short *)(q+8)=0;
    *(Vec *)(q+0x18)=*(Vec *)(*(char **)(q+0x78)+0x44);
    *(int *)(q+0x18)-=*(int *)(*(char **)(q+0x78)+0x50);
    *(int *)(q+0x1c)-=*(int *)(*(char **)(q+0x78)+0x54)+amount;
    *(int *)(q+0x20)-=*(int *)(*(char **)(q+0x78)+0x58);
    *(int *)(q+0x1c)+=0x2000;
    n=*(int *)(*(char **)(q+0x78)+0x54)+amount;
    if (n<0) n=-n;
    n/=128;
    if (n>0x800) n=0x800;
    *(int *)(q+0xc)=0x1000-n;
    *(int *)(q+0x10)=0x1000-n;
    *(int *)(q+0x14)=0x1000-n;
}
