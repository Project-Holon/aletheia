/*
 * function: func_021F6AF0
 * address: 0x021F6AF0
 * packet: pkt_ov112_021F6AF0
 * region: ov112
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 */
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
typedef struct { u32 a,b,c,d,e,f,g; } Entry;
typedef struct { u16 heap,n; void *p; Entry entries[5]; } Object;
void func_021F6AF0(Object *o,u16 n)
{
    u8 i;
    o->n=n;
    for(i=0;i<5;i++) if(o->entries[i].a==1) o->entries[i].b=1;
}
