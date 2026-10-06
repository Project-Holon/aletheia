/*
 * unit: yes
 * function: func_021F4990, func_021F4AA4
 * address: 0x021F4990
 * packet: pkt_ov112_021F4990
 * region: ov112
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * extent: 276-byte lead plus 4AA4 two-byte return stub; 4AA6 is zero alignment padding.
 * function_starts: 0x021F4AA4
 * lever: bitfield dirty clear retains the hoisted mask; named offset.x keeps trig load order.
 * symbols:
 *   func_021F4F60 0x021F4F60 thumb ov112
 *   func_021F4AC8 0x021F4AC8 thumb ov112
 *   func_0204F638 0x0204F638 arm
 *   func_0204F684 0x0204F684 arm
 *   func_0204F7C4 0x0204F7C4 arm
 *   FX_SinCosTable_ 0x020A1B38 data a2
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef short s16;
typedef union {
    u16 value;
    struct { u16 active:1, dirty:1, rotate:1, rest:13; } bits;
} Flags;
typedef struct { Flags flags; u16 angle; u32 id,index,type; int x,y,z; s16 a,b; u8 *data; } Entry;
typedef struct { u32 pad; u8 *board; Entry *entries; u8 *table; u16 count; } Object;
typedef struct { int x,y; } Offset;
typedef struct { u8 x,y; s16 b,a; } Scale;
struct Trip { u32 a,b,c; };
struct Manager0204F684;
extern void func_021F4F60(u8 *,Offset *);
extern void func_021F4AC8(u8 *p, u8 *a, u8 *b);
extern void func_0204F638(u8 *,int,struct Trip *);
extern void func_0204F684(struct Manager0204F684 *,int,const s16 *,const s16 *);
extern void func_0204F7C4(u8 *,int,u16 *);
extern s16 FX_SinCosTable_[];
void func_021F4990(Object *p)
{
    int i;
    Entry *e;
    Offset offset;
    Scale scale;
    struct Trip v;
    int x,y,s,c,ox;
    for(i=0;i<p->count;i++) {
        e=&p->entries[i];
        if(e->flags.bits.active==1 && e->flags.bits.dirty==1) {
            if(e->flags.bits.rotate==1) {
                func_021F4F60(e->data,&offset);
                if(e->a<0) offset.x *= -1;
                ox=offset.x;
                s=FX_SinCosTable_[(e->angle>>4)*2];
                c=FX_SinCosTable_[(e->angle>>4)*2+1];
                x=ox*c-offset.y*s;
                y=ox*s+offset.y*c;
            } else { x=0; y=0; }
            v.a=(e->x-x)/16;
            v.b=(0xC0000-(e->y-y))/16;
            v.c=e->z;
            func_0204F638(p->board,e->index,&v);
            func_021F4AC8((u8 *)e,&scale.y,&scale.x);
            scale.a=e->a*scale.y;
            scale.b=e->b*scale.x;
            func_0204F684((struct Manager0204F684 *)p->board,e->index,&scale.a,&scale.b);
            func_0204F7C4(p->board,e->index,&e->angle);
            p->entries[i].flags.bits.dirty=0;
        }
    }
}
void func_021F4AA4(void *a0)
{
}
