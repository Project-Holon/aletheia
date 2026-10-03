/*
 * function: func_0217B1BC
 * address: 0x0217B1BC
 * packet: pkt_ov176_0217B1BC
 * region: ov176
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02082BCC 0x02082BCC arm
 *   func_0217B984 0x0217B984 thumb ov176
 *   func_0217BAF4 0x0217BAF4 thumb ov176
 *   func_0217BB3C 0x0217BB3C thumb ov176
 *   func_0217BA9C 0x0217BA9C thumb ov176
 *   func_021E8AA0 0x021E8AA0 thumb ov177
 *   func_0217B064 0x0217B064 thumb ov176
 *   func_0217B0C8 0x0217B0C8 thumb ov176
 */
typedef unsigned char u8;
typedef unsigned u32;
typedef struct {u32 w[10];} Init;
extern void func_02082BCC(void *,int,unsigned);
extern u8 *func_0217B984(Init *,u32);
extern void func_0217BAF4(int *);
extern int func_0217BB3C(int *);
extern void func_0217BA9C(int *);
extern void func_021E8AA0(int *,int);
extern void func_0217B064(void *,int *,char *);
extern void func_0217B0C8(int *,int *,int *);
void func_0217B1BC(int *a,int *state,int *p)
{
    Init config;
    switch(*state) {
    case 0:
        func_02082BCC(&config,0,40);
        config.w[1]=p[2];
        config.w[2]=p[3];
        config.w[3]=p[5];
        config.w[4]=p[8];
        config.w[5]=p[9];
        config.w[6]=((u32 *)p[10])[0];
        config.w[7]=((u32 *)p[10])[3];
        config.w[8]=((u32 *)p[10])[4];
        config.w[9]=((u32 *)p[10])[5];
        switch(((u32 *)p[10])[1]) {
        case 3: config.w[0]=0;break;
        case 4: config.w[0]=2;break;
        case 5: config.w[0]=3;break;
        case 6: config.w[0]=1;break;
        default: config.w[0]=0;break;
        }
        p[11]=(int)func_0217B984(&config,78);
        (*state)++;
        break;
    case 1:
        func_0217BAF4((int *)p[11]);
        switch(func_0217BB3C((int *)p[11])) {
        case 1: *state=3;break;
        case 2: ((int *)p[10])[2]=2;*state=2;break;
        case 3: ((int *)p[10])[2]=3;*state=2;break;
        case 4: ((int *)p[10])[2]=4;*state=2;break;
        }
        break;
    case 2:
        func_0217BA9C((int *)p[11]);
        func_021E8AA0(a,(int)func_0217B064);
        break;
    case 3:
        p[12]=1;
        func_0217BA9C((int *)p[11]);
        func_021E8AA0(a,(int)func_0217B0C8);
        break;
    }
}
