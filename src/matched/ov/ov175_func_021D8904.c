/*
 * function: func_021D8904
 * address: 0x021D8904
 * packet: pkt_ov175_021D8904
 * region: ov175
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021E8738 0x021E8738 thumb ov177
 *   func_021E8AB4 0x021E8AB4 thumb ov177
 *   func_021E8AA0 0x021E8AA0 thumb ov177
 *   func_021E8844 0x021E8844 thumb ov177
 *   func_021E8AB8 0x021E8AB8 thumb ov177
 *   func_021E8AA8 0x021E8AA8 thumb ov177
 *   func_021E8AC0 0x021E8AC0 thumb ov177
 *   func_021D9F04 0x021D9F04 thumb ov175
 *   func_021D8BC4 0x021D8BC4 thumb ov175
 *   func_021D8CF0 0x021D8CF0 thumb ov175
 *   func_021D9064 0x021D9064 thumb ov175
 *   func_021DA5B0 0x021DA5B0 thumb ov175
 *   func_021DA6B8 0x021DA6B8 thumb ov175
 *   func_021DADAC 0x021DADAC thumb ov175
 *   func_021DA36C 0x021DA36C thumb ov175
 *   func_021DA384 0x021DA384 thumb ov175
 *   func_021DA390 0x021DA390 thumb ov175
 *   func_021DBC04 0x021DBC04 thumb ov175
 *   func_021DBDAC 0x021DBDAC thumb ov175
 *   func_02156E30 0x02156E30 thumb ov009
 *   func_02156F50 0x02156F50 thumb ov009
 *   func_02156ED0 0x02156ED0 thumb ov009
 *   func_0203064C 0x0203064C arm
 *   func_02082BCC 0x02082BCC arm
 *   func_02012EBC 0x02012EBC thumb
 *   func_0200ED48 0x0200ED48 thumb
 *   func_0200ED54 0x0200ED54 thumb
 *   func_02008530 0x02008530 thumb
 */
typedef unsigned long u32;
typedef struct { u32 w[20]; } Rec80;
typedef struct { Rec80 data; u32 last; } Rec84;
struct L0200ED54;
extern void func_021E8738(u32,u32,u32,u32);
extern void func_021E8AB4(u32,u32),func_021E8AA0(u32,void *),func_021E8AB8(u32),func_021E8AA8(u32);
extern int func_021E8844(u32);
extern void func_021E8AC0(int,int);
extern int func_021D9F04(char *,void *,void *);
extern void func_021D8BC4(void),func_021D8CF0(void),func_021D9064(void);
extern void func_0203064C(unsigned int,unsigned int,unsigned int);
extern void func_02156E30(int,int,int,int),func_02156F50(int),func_02156ED0(void);
extern void func_021DA5B0(char *,int,int,u32,u32 *,u32);
extern int func_021DA6B8(void *,u32 *);
extern u32 func_021DADAC(char *);
extern void func_021DA36C(char *),func_021DA384(char *);
extern int func_021DA390(char *);
extern void *func_02012EBC(void *),*func_0200ED48(void *);
struct Sub0200852CObj;
extern u32 func_02008530(const struct Sub0200852CObj *obj);
extern void func_0200ED54(struct L0200ED54 *,unsigned int);
extern void func_02082BCC(void *,int,unsigned);
extern void func_021DBC04(char *,unsigned,void *);
extern int func_021DBDAC(char *);
void func_021D8904(u32 sys,int *state,char *p)
{
    char *q=*(char **)(p+260);
    Rec84 rec;
    void *list;
    int v;
    switch(*state) {
    case 0:if(*(u32 *)(q+12)==2 && *(u32 *)(p+256)==0) func_021E8AA0(sys,func_021D8BC4);
        else {
            *(u32 *)(p+256)=0;
            func_0203064C(1,134,0x60000);
            func_02156E30(9,0x60000,1000,134);
            func_02156F50(134);*state=1;
        }break;
    case 1:func_021E8738(*(u32 *)(p+44),*(u32 *)(p+20),70,2);
        *state=13;func_021E8AB4(sys,2);break;
    case 2:func_021DA5B0(*(char **)(p+52),1,0,(*(u32 **)(q+8))[1],*(u32 **)(q+44),*(u32 *)(q+12)==2);
        *(u32 *)(p+248)=0;*(u32 *)(p+244)=0;*state=3;break;
    case 3:
        if(*(u32 *)(p+248)==0) {
            *(u32 *)(p+248)=func_021DA6B8(*(void **)(p+52),(u32 *)(p+244));
            if(*(u32 *)(p+248)!=0 && *(u32 *)(p+244)!=0)
                func_021E8AC0(**(int **)(q+8),**(int **)(q+44));
        }
        if(*(u32 *)(p+248)==1) {
            *(u32 *)(*(char **)(q+44)+20)=func_021DADAC(*(char **)(p+52));*state=4;
        }
        if(*(u32 *)(p+248)!=0) {
            switch(func_021D9F04(*(char **)(p+52),0,(void *)1)) {
            case 1:func_021DA36C(*(char **)(p+52));
            case 2:case 4:func_021E8AA0(sys,func_021D9064);func_02156ED0();break;
            }
        }break;
    case 4:func_02156ED0();
        if(*(u32 *)(q+12)==2)func_021E8AA0(sys,func_021D8BC4);
        else *state=5;break;
    case 5:list=func_0200ED48(func_02012EBC(**(void ***)(q+8)));
        func_0200ED54(list,func_02008530(*(void **)(q+24)));
        func_021DA384(*(char **)(p+52));*state=6;break;
    case 6:if(func_021DA390(*(char **)(p+52))) *state=7;
        switch(func_021D9F04(*(char **)(p+52),0,(void *)1)) {
        case 1:case 4:*state=7;break;
        case 2:func_021E8AA0(sys,func_021D9064);break;
        }break;
    case 7:if(**(u32 **)(q+32)==0) {
        func_02082BCC(&rec,0,84);
        rec.data=**(Rec80 **)(*(char **)(p+260)+36);
        rec.last=**(u32 **)(*(char **)(p+260)+40);
        func_021DBC04(*(char **)(p+52),3,&rec);*state=8;
        }break;
    case 8:v=func_021DBDAC(*(char **)(p+52));
        if(v==1) {
            **(u32 **)(*(char **)(p+260)+32)=1800;*state=9;
        }
        if(v!=0) {
            switch(func_021D9F04(*(char **)(p+52),0,0)) {
            case 1:func_021E8AA0(sys,func_021D8CF0);break;
            case 2:func_021E8AA0(sys,func_021D9064);break;
            }
        }break;
    case 9:func_021E8738(*(u32 *)(p+44),*(u32 *)(p+20),88,1);
        *state=13;func_021E8AB4(sys,10);break;
    case 10:*(u32 *)(q+4)=2;func_021E8AA8(sys);break;
    case 13:if(func_021E8844(*(u32 *)(p+44)))func_021E8AB8(sys);break;
    }
}
