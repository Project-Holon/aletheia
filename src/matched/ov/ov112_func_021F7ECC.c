/*
 * unit: yes
 * function: func_021F7ECC, func_021F7FA8
 * address: 0x021F7ECC
 * packet: pkt_ov112_021F7ECC
 * region: ov112
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * extent: 220-byte lead, 7FA8 two-byte return stub; 7FAA zero alignment padding.
 * function_starts: 0x021F7FA8
 * symbols:
 *   func_021F4EA4 0x021F4EA4 thumb ov112
 *   func_021F4E8C 0x021F4E8C thumb ov112
 *   func_021F4EC4 0x021F4EC4 thumb ov112
 *   func_021F4EB4 0x021F4EB4 thumb ov112
 *   func_021F4E6C 0x021F4E6C thumb ov112
 *   func_020061F8 0x020061F8 thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef struct { int x,y,z; } Vec;
typedef struct { u16 count,pad; int index,a,b; } Tail;
typedef struct { short y,x; } Scale;
extern void func_021F4EA4(int,int,Vec *);
extern void func_021F4E8C(int,int,Vec *);
extern void func_021F4EC4(int,int,short *,short *);
extern void func_021F4EB4(int,int,short,short);
extern void func_021F4E6C(int,int,int);
extern void func_020061F8(int);
void func_021F7ECC(char *p,char *q)
{
    Tail *t=(Tail *)(q+0xf0);
    Vec v;
    Scale s;
    func_021F4EA4(*(int *)(p+0x10),*(int *)(q+0x84+t->index*4),&v);
    t->b+=164;
    v.x-=2867;
    v.y+=t->b;
    v.z=0xc8000;
    func_021F4E8C(*(int *)(p+0x10),*(int *)(q+0x84+t->index*4),&v);
    func_021F4EC4(*(int *)(p+0x10),*(int *)(q+0x84+t->index*4),&s.x,&s.y);
    s.x+=12;
    s.y+=12;
    func_021F4EB4(*(int *)(p+0x10),*(int *)(q+0x84+t->index*4),s.x,s.y);
    t->count++;
    if(t->count>=180) {
        func_021F4E6C(*(int *)(p+0x10),*(int *)(q+0x84+t->index*4),0);
        *(int *)(q+0x104)=0;
        *(u8 *)(p+0x43c)-=1;
        if(*(u8 *)(p+0x43c)==0) func_020061F8(2);
    }
}
void func_021F7FA8(void)
{
}
