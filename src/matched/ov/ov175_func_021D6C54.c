/*
 * function: func_021D6C54
 * address: 0x021D6C54
 * packet: pkt_ov175_021D6C54
 * region: ov175
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02012EBC 0x02012EBC thumb
 *   func_02009448 0x02009448 thumb
 *   func_020092EC 0x020092EC thumb
 *   func_021E8738 0x021E8738 thumb ov177
 *   func_02082BCC 0x02082BCC arm
 *   func_021DC738 0x021DC738 thumb ov175
 *   func_021DC77C 0x021DC77C thumb ov175
 *   func_021DC8A0 0x021DC8A0 thumb ov175
 *   func_021E8AA0 0x021E8AA0 thumb ov177
 *   func_021D9064 0x021D9064 thumb ov175
 *   func_021D905C 0x021D905C thumb ov175
 *   func_021D9F04 0x021D9F04 thumb ov175
 *   func_021E8844 0x021E8844 thumb ov177
 *   func_021DA044 0x021DA044 thumb ov175
 *   func_021DA054 0x021DA054 thumb ov175
 *   func_021D6DB8 0x021D6DB8 thumb ov175
 */
typedef unsigned int u32;
extern u32 func_02012EBC(u32);
extern u32 func_02009448(u32);
extern int func_020092EC(u32);
extern void func_021E8738(u32,u32,int,int);
extern void func_02082BCC(void *,int,u32);
extern void func_021DC738(char *,unsigned);
extern int func_021DC77C(char *);
extern void func_021DC8A0(char *,void *);
extern void func_021E8AA0(u32,void *);
extern void func_021D9064(void),func_021D905C(void),func_021D6DB8(void);
extern int func_021D9F04(char *,void *,void *);
extern int func_021E8844(u32);
extern void func_021DA044(char *);
extern int func_021DA054(char *);
void func_021D6C54(u32 sys,int *state,u32 *p)
{
    u32 *ctx=(u32 *)p[0x104/4];
    int r;
    switch(*state) {
    case 0:
        if(func_020092EC(func_02009448(func_02012EBC(*(u32 *)ctx[2])))) *state=1;
        else *state=5;
        break;
    case 1: func_021E8738(p[0x2c/4],p[5],0x36,2); *state=2; break;
    case 2: func_02082BCC((void *)ctx[0xc],0,8); func_021DC738((char *)p[0x34/4],87); *state=3; break;
    case 3:
        r=func_021DC77C((char *)p[0x34/4]);
        if(r==1) { func_021DC8A0((char *)p[0x34/4],(void *)((u32 *)p[0x104/4])[0xc]); *state=4; }
        else if(r==3) func_021E8AA0(sys,func_021D9064);
        else if(r!=0) {
            r=func_021D9F04((char *)p[0x34/4],(void *)1,0);
            switch(r) {case 1: case 2: func_021E8AA0(sys,func_021D9064); break;}
        }
        break;
    case 4: if(*(unsigned char *)(ctx[0xc]+6)) *state=7; else *state=5; break;
    case 5: func_021E8738(p[0x2c/4],p[5],0x37,1); *state=6; break;
    case 6: if(func_021E8844(p[0x2c/4])) func_021E8AA0(sys,func_021D905C); break;
    case 7: if(*(u32 *)ctx[8]==0) {func_021DA044((char *)p[0x34/4]); *state=8;} break;
    case 8:
        r=func_021DA054((char *)p[0x34/4]);
        if(r==1) { *(u32 *)((u32 *)p[0x104/4])[8]=0x708; *state=9; }
        if(r!=0) {
            r=func_021D9F04((char *)p[0x34/4],(void *)1,0);
            switch(r) {case 1: case 2: func_021E8AA0(sys,func_021D9064); break;}
        }
        break;
    case 9: func_021E8AA0(sys,func_021D6DB8); break;
    }
}
