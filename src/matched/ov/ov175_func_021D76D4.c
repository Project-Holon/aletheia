/*
 * function: func_021D76D4
 * address: 0x021D76D4
 * packet: pkt_ov175_021D76D4
 * region: ov175
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D965C 0x021D965C thumb
 *   func_021D97E4 0x021D97E4 thumb
 *   func_021D9874 0x021D9874 thumb
 *   func_021D97B8 0x021D97B8 thumb
 *   func_021D98CC 0x021D98CC thumb
 *   func_021D98E4 0x021D98E4 thumb
 *   func_021D9A08 0x021D9A08 thumb
 *   func_021D99F4 0x021D99F4 thumb
 *   func_021D98D8 0x021D98D8 thumb
 *   func_021D98B8 0x021D98B8 thumb
 *   func_021D9A50 0x021D9A50 thumb
 *   func_0201AA50 0x0201AA50 thumb
 *   func_0200AE14 0x0200AE14 thumb
 *   func_0201A090 0x0201A090 thumb
 *   func_021DCB58 0x021DCB58 thumb
 *   func_021DCC28 0x021DCC28 thumb
 *   func_0201AA18 0x0201AA18 thumb
 *   func_021DBC04 0x021DBC04 thumb
 *   func_021DBDAC 0x021DBDAC thumb
 *   func_02012EBC 0x02012EBC thumb
 *   func_0200BAC8 0x0200BAC8 thumb
 *   func_0200B358 0x0200B358 thumb
 *   func_0200B204 0x0200B204 thumb
 *   func_0200BAF4 0x0200BAF4 thumb
 *   func_0200BBC8 0x0200BBC8 thumb
 *   func_0200B110 0x0200B110 thumb
 *   func_0200B2A4 0x0200B2A4 thumb
 *   func_020307B0 0x020307B0 arm
 *   func_02012DAC 0x02012DAC thumb
 *   func_02012DD0 0x02012DD0 thumb
 *   func_02082BCC 0x02082BCC arm
 *   func_021DD020 0x021DD020 thumb
 *   func_021DC8B4 0x021DC8B4 thumb
 *   func_021DC908 0x021DC908 thumb
 *   func_021D9F04 0x021D9F04 thumb
 *   func_021E8738 0x021E8738 thumb ov177
 *   func_021E8AA0 0x021E8AA0 thumb ov177
 *   func_021E8AB4 0x021E8AB4 thumb ov177
 *   func_021E8AB8 0x021E8AB8 thumb ov177
 *   func_021E8844 0x021E8844 thumb ov177
 *   func_021D9064 0x021D9064 thumb
 *   func_021D7BE4 0x021D7BE4 thumb
 *   func_021D8EC8 0x021D8EC8 thumb
 */
typedef unsigned int u32;
typedef struct { unsigned char a,b,c,d; u32 id; } Request;
typedef struct {char pad[0x48];u32 slots[6];} SlotView;
extern void func_021D965C(char *);
extern void func_021D97E4(char *,unsigned);
extern void func_021D9874(char *);
extern unsigned func_021D97B8(char *);
extern int func_021D98CC(char *);
extern void func_021D98E4(char *,unsigned);
extern int func_021D9A08(char *);
extern void func_021D99F4(char *);
extern int func_021D98D8(char *);
extern void func_021D98B8(char *);
extern void func_021D9A50(char *,char *);
extern int func_0201AA50(void *);
extern int func_0200AE14(unsigned);
extern int func_0201A090(int,void *,unsigned *);
extern void func_021DCB58(char *,void *,int);
extern int func_021DCC28(char *,void *);
extern int func_0201AA18(void *);
extern void func_021DBC04(char *,int,void *);
extern int func_021DBDAC(char *);
extern unsigned func_02012EBC(unsigned);
extern void * func_0200BAC8(void *);
extern unsigned func_0200B358(unsigned);
extern unsigned func_0200B204(unsigned,int);
extern unsigned func_0200BAF4(void *,unsigned);
extern void func_0200BBC8(void *,unsigned);
extern void func_0200B110(unsigned,int,int);
extern void func_0200B2A4(int,int);
extern void func_020307B0(void *);
extern int func_02012DAC(int);
extern int func_02012DD0(unsigned char *);
extern void func_02082BCC(void *,int,unsigned);
extern unsigned func_021DD020(char *);
extern void func_021DC8B4(char *,void *,unsigned);
extern int func_021DC908(char *);
extern int func_021D9F04(char *,void *,void *);
extern void func_021E8738(unsigned,unsigned,int,int);
extern void func_021E8AA0(unsigned,void *);
extern void func_021E8AB4(unsigned,unsigned);
extern void func_021E8AB8(unsigned);
extern int func_021E8844(unsigned);
extern void func_021D9064(void);
extern void func_021D7BE4(void);
extern void func_021D8EC8(void);
#define W(k) (*(u32 *)(p+(k)))
void func_021D76D4(u32 sys,int *state,char *p)
{
    u32 *ctx=(u32 *)W(0x104);
    int r,i,n,empty;
    char *rec;
    void *box;
    u32 saved,tmp,out;
    Request request;
    switch(*state) {
    case 0: func_021D965C(p); func_021D97E4(p,2); func_021D9874(p); *state=1; break;
    case 1: r=1; r &= func_021D97B8(p); r &= func_021D98CC(p); if(r) *state=2; break;
    case 2: func_021E8738(W(0x2c),W(0x14),0x41,1); func_021E8AB4(sys,3); *state=30; break;
    case 3: func_021D98E4(p,2); *state=4; break;
    case 4: r=func_021D9A08(p); if(r!=-1) {func_021D99F4(p); switch(r) {case 0:*state=12;break;case 1:*state=5;break;}} break;
    case 5: func_021E8738(W(0x2c),W(0x14),0x44,1); func_021E8AB4(sys,6); *state=30; break;
    case 6: func_021D98E4(p,0); *state=7; break;
    case 7: r=func_021D9A08(p); if(r!=-1) {func_021D99F4(p); switch(r) {case 0:*state=8;break;case 1:*state=2;break;}} break;
    case 8: func_021E8738(W(0x2c),W(0x14),0x45,1); func_021E8AB4(sys,9); *state=30; break;
    case 9: func_021D98E4(p,0); *state=10; break;
    case 10: r=func_021D9A08(p); if(r!=-1) {func_021D99F4(p); switch(r) {case 0:*state=11;break;case 1:*state=2;break;}} break;
    case 11: if(func_021D98D8(p)) {func_021D98B8(p); *state=29;} break;
    case 12:
        rec=(char *)ctx[5]; func_021D9A50(rec,p);
        if(func_0201AA50(rec+0xd4)==0) *state=14;
        else {out=0; if(func_0201A090(func_0200AE14(W(0x108)),rec+0xd4,&out)==0) *state=15; else *state=13;}
        break;
    case 13: func_021E8738(W(0x2c),W(0x14),0x49,1); func_021E8AB4(sys,29); *state=30; break;
    case 14: func_021E8738(W(0x2c),W(0x14),0x61,1); func_021E8AB4(sys,29); *state=30; break;
    case 15: if(func_021D98D8(p)) {func_021D98B8(p); *state=16;} break;
    case 16: func_021E8738(W(0x2c),W(0x14),0x46,2); func_021E8AB4(sys,17); *state=30; break;
    case 17:
        func_021DCB58((char *)W(0x34),(void *)(ctx[5]+0xd4),1);
        func_02082BCC(p+0x44,0,0x9c); *state=18; break;
    case 18:
        r=func_021DCC28((char *)W(0x34),p+0x44);
        if(r==1) {
            n=func_0201AA18((void *)(ctx[5]+0xd4)); empty=0;
            for(i=0;i<n;i++) if(((SlotView *)p)->slots[i]==0) empty++;
            if(*(unsigned char *)(p+0x44)==0 && empty==n) *state=20; else *state=19;
        } else if(r==3) func_021E8AA0(sys,func_021D9064);
        switch(func_021D9F04((char *)W(0x34),0,0)) {case 1:*state=0;break;case 2:func_021E8AA0(sys,func_021D9064);break;}
        break;
    case 19: func_021E8738(W(0x2c),W(0x14),0x47,1); func_021E8AB4(sys,29); *state=30; break;
    case 20: if(*(u32 *)ctx[8]==0) {func_021DBC04((char *)W(0x34),0,(void *)(ctx[5]+0xd4));*state=21;} break;
    case 21:
        r=func_021DBDAC((char *)W(0x34));
        if(r==1) {*(u32 *)((u32 *)W(0x104))[8]=0x708; *state=22;}
        if(r!=0) switch(func_021D9F04((char *)W(0x34),0,0)) {case 1:*state=0;break;case 2:func_021E8AA0(sys,func_021D9064);break;}
        break;
    case 22:
        saved=func_02012EBC(*(u32 *)ctx[2]); box=func_0200BAC8((void *)saved);
        tmp=func_0200B204(func_0200B358(saved),0);
        saved=func_0200BAF4(box,0x8056); func_0200BBC8(box,1);
        func_0200B110(W(0x108),10,2); func_0200B2A4(tmp,saved); func_020307B0((void *)saved);
        *state=23; break;
    case 23: func_02012DAC(*(u32 *)ctx[2]); *state=24; break;
    case 24: r=func_02012DD0((unsigned char *)*(u32 *)ctx[2]); if(r==2) *state=25; else if(r==3) *state=29; break;
    case 25:
        func_02082BCC(&request,0,8); request.b=2; request.id=func_021DD020((char *)W(0x34));
        ((unsigned char *)((u32 *)W(0x104))[12])[5]=2;
        func_021DC8B4((char *)W(0x34),&request,87); *state=26; break;
    case 26:
        r=func_021DC908((char *)W(0x34)); if(r==1) *state=27; else if(r==3) func_021E8AA0(sys,func_021D9064);
        switch(func_021D9F04((char *)W(0x34),0,0)) {case 1:*state=0;break;case 2:func_021E8AA0(sys,func_021D9064);break;} break;
    case 27: func_021D97E4(p,0); func_021E8738(W(0x2c),W(0x14),0x48,1); func_021E8AB4(sys,28); *state=30; break;
    case 28: func_021E8AA0(sys,func_021D7BE4); break;
    case 29: ctx[1]=0; func_021E8AA0(sys,func_021D8EC8); break;
    case 30: if(func_021E8844(W(0x2c))) func_021E8AB8(sys); break;
    }
}
