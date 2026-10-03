/*
 * function: func_021D6614
 * address: 0x021D6614
 * packet: pkt_ov131_021D6614
 * region: ov131
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D7460 0x021D7460 thumb ov131
 *   func_021D6F54 0x021D6F54 thumb ov131
 *   func_021D79A8 0x021D79A8 thumb ov131
 *   func_02015EB0 0x02015EB0 thumb
 *   func_02015EA0 0x02015EA0 thumb
 *   func_02015C78 0x02015C78 thumb
 *   func_02015D30 0x02015D30 thumb
 *   func_02048AFC 0x02048AFC arm
 *   func_02048AD0 0x02048AD0 arm
 *   d_020A1B38 0x020A1B38 data a2
 *   d_021DC234 0x021DC234 data a4
 *   d_021DC228 0x021DC228 data a4
 *   d_021DC198 0x021DC198 data a4
 *   d_021DC210 0x021DC210 data a4
 *   d_021DC170 0x021DC170 data a4
 *   d_021DC178 0x021DC178 data a4
 *   d_021DC168 0x021DC168 data a4
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef short s16;
typedef struct {int x,y,z;} Vec;
typedef struct {int v[2];} Pair;
extern void func_021D7460(u8 *,u8 *);
extern void func_021D6F54(u8 *,u8 *);
extern void func_021D79A8(void *,u8 *,int);
extern void func_02015EB0(void *);
extern void func_02015EA0(void *);
extern void func_02015C78(void *,Vec *);
extern void func_02015D30(void *,Vec *);
extern void func_02048AFC(void *,const Vec *);
struct Light;
extern void func_02048AD0(struct Light *l);
extern const s16 d_020A1B38[];
extern const Vec d_021DC234,d_021DC228,d_021DC198,d_021DC210;
extern const Pair d_021DC170,d_021DC178,d_021DC168;
void func_021D6614(u8 *a,u8 *p) {
    u32 st=*(u32 *)(p+8);
    if(st==0 || st==2) {
        func_021D7460(a,p);
        func_021D6F54(a,p);
        return;
    }
    if(st==3) {
        Vec v48=d_021DC234;
        Vec v3c=d_021DC228;
        Vec v30={0,0,0};
        u8 c;
        p[0x9b]=p[0x9b]+1;
        if(p[0x9b]>5 && *(u32 *)(p+0xc)==0) {
            func_02015EB0(*(void **)p);
            func_02015EA0(*(void **)(p+4));
            *(u32 *)(p+0xc)=1;
        }
        c=p[0x9b];
        if(c>=10) {
            func_021D79A8(a,p,0);
            *(u32 *)(p+8)=0;
        } else {
            u16 ang;
            v48.x=c*0x19000/10-0x42000;
            ang=(p[0x9b]<<15)/10;
            v30.y=d_020A1B38[(ang>>4)*2]<<5;
            if(*(u32 *)(p+0x10)==1) v30.y=0;
            func_021D79A8(a,p,v30.y);
        }
        func_02015C78(*(void **)p,&v30);
        func_02015C78(*(void **)(p+4),&v30);
        func_02015D30(*(void **)p,&v3c);
        func_02048AFC(*(void **)(a+0x70),&v48);
        func_02048AD0(*(void **)(a+0x70));
    } else if(st==1) {
        Vec v24=d_021DC198;
        Vec v18=d_021DC210;
        u8 c;
        p[0x9b]=p[0x9b]+1;
        c=p[0x9b];
        if(c<3) {
            Pair t1=d_021DC170;
            Pair t2=d_021DC178;
            Pair t3=d_021DC168;
            u8 k=c-1;
            v18.x=t1.v[k];
            v18.y=t2.v[k];
            v24.x=t3.v[k];
            func_02048AFC(*(void **)(a+0x70),&v24);
            func_02048AD0(*(void **)(a+0x70));
            func_02015D30(*(void **)p,&v18);
        } else {
            func_02015EA0(*(void **)p);
            func_02015EB0(*(void **)(p+4));
            func_02015D30(*(void **)(p+4),&v18);
            func_02048AFC(*(void **)(a+0x70),&v24);
            func_02048AD0(*(void **)(a+0x70));
            *(u32 *)(p+0xc)=0;
            *(u32 *)(p+8)=2;
            *(u32 *)(p+0x6c)=0;
        }
    }
}
